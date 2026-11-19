void GameStats::SetEverything(void) {
    s32 offset;
    s32 row;
    s32 bit;
    s32 count;
    s32 base;

    row = 0;
    this->unkF8 = -1;
    base = 0;
    this->unkF9 = 0xFF;
    do {
        offset = base + 0x60;
        bit = 0;
        count = 4;
        do {
            *(s32 *) ((s8 *) this + offset) = *(s32 *) ((s8 *) this + offset) | (1 << bit);
            bit += 1;
            count -= 1;
        } while (count != 0);
        row += 1;
        base += 0x20;
    } while (row < 4);
}
