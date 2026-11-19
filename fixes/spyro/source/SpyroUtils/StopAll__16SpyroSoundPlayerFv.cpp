void SpyroSoundPlayer::StopAll() {
    s32 count;
    s32 offset;

    count = 0;
    offset = 0;
    do {
        M2C_FIELD(this, s32 *, offset + 0x28) = 2;
        KDSound_Stop((int *) ((s8 *) this + offset));
        count += 1;
        offset += 0x58;
    } while (count < 0xD);
}
