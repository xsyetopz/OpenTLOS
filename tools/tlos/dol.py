"""Read-only access to GameCube/Wii DOL executables by virtual address."""

import struct


class Dol:
    """A loaded DOL image addressable by virtual address."""

    def __init__(self, path: str):
        data = open(path, "rb").read()
        offsets = struct.unpack_from(">18I", data, 0x00)
        addrs = struct.unpack_from(">18I", data, 0x48)
        sizes = struct.unpack_from(">18I", data, 0x90)
        self.segments = [
            (addrs[i], data[offsets[i]:offsets[i] + sizes[i]])
            for i in range(18) if sizes[i]
        ]
        # DOL slots 0-6 are text, 7-17 data.
        self.data_ranges = [(addrs[i], addrs[i] + sizes[i]) for i in range(7, 18) if sizes[i]]

    def read(self, addr: int, size: int) -> bytes:
        """Returns `size` bytes at `addr`, or raises KeyError outside initialized segments."""
        for base, blob in self.segments:
            if base <= addr and addr + size <= base + len(blob):
                return blob[addr - base:addr - base + size]
        raise KeyError(f"0x{addr:08X}+0x{size:X} outside initialized segments")

    def words(self, addr: int, size: int) -> tuple:
        """Returns the big-endian 32-bit words of a range."""
        return struct.unpack(f">{size // 4}I", self.read(addr, size & ~3))

    def cstring(self, addr: int, limit: int = 256):
        """Returns the printable NUL-terminated ASCII string at `addr`, or None."""
        try:
            blob = self.read(addr, 1)
        except KeyError:
            return None
        out = bytearray()
        while len(out) < limit:
            try:
                byte = self.read(addr + len(out), 1)[0]
            except KeyError:
                return None
            if byte == 0:
                break
            if not (0x20 <= byte < 0x7F or byte in (9, 10, 13)):
                return None
            out.append(byte)
        return out.decode("ascii") if len(out) >= 4 else None
