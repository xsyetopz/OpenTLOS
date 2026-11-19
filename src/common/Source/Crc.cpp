static bool crcTableComputed;
static unsigned int crcTable[256];

static void Crc_MakeTable(void);
unsigned int Crc_Update(unsigned int crc, const void* buf, int len);

int Crc_Calculate(const void* buf, int len) {
    return Crc_Update(0xFFFFFFFF, buf, len) ^ 0xFFFFFFFF;
}

unsigned int Crc_Update(unsigned int crc, const void* buf, int len) {
    unsigned int c = crc;
    if (!crcTableComputed) {
        Crc_MakeTable();
    }
    const unsigned char* p = (const unsigned char*)buf;
    for (int n = 0; n < len; n++) {
        c = (c >> 8) ^ crcTable[(c ^ p[n]) & 0xFF];
    }
    return c;
}

static void Crc_MakeTable(void) {
    for (int n = 0; n < 256; n++) {
        unsigned int c = (unsigned int)n;
        for (int k = 0; k < 8; k++) {
            if (c & 1) {
                c = 0xEDB88320 ^ (c >> 1);
            } else {
                c = c >> 1;
            }
        }
        crcTable[n] = c;
    }
    crcTableComputed = true;
}
