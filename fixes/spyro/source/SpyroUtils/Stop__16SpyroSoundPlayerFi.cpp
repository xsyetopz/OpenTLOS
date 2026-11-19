void SpyroSoundPlayer::Stop(int arg0) {
    s32 offset;

    if (arg0 >= 0) {
        if (arg0 >= 0xD) {
            return;
        }
        offset = arg0 * 0x58;
        M2C_FIELD(this, s32 *, offset + 0x28) = 2;
        KDSound_Stop((int *) ((s8 *) this + offset));
    }
}
