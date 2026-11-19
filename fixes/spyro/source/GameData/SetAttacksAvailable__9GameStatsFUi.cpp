void GameStats::SetAttacksAvailable(unsigned int arg0) {
    s32 offset;
    s32 i;
    s32 ctr;

    i = 0;
    ctr = 0x10;
    do {
        if (arg0 & (1 << i)) {
            offset = (i * 8) & 0x60;
            *(s32 *) ((s8 *) this + offset + 0x60) = *(s32 *) ((s8 *) this + offset + 0x60) | (1 << (i & 3));
        }
        i += 1;
        ctr -= 1;
    } while (ctr != 0);
}
