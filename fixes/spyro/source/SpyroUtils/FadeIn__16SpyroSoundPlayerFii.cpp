void SpyroSoundPlayer::FadeIn(int arg0, int arg1) {
    s32 offset;
    s32 slot;
    s32 kind;
    s8 *base;
    s32 var;
    u8 flag;

    var = arg1;
    if (arg0 >= 0) {
        if (arg0 >= 0xD) {
            return;
        }
        offset = arg0 * 0x58;
        flag = 0;
        M2C_FIELD(this, s32 *, offset + 0x28) = 0;
        if (var == -1) {
            slot = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
            kind = M2C_FIELD(GameData::gameData, s32 *, 0x70 + slot + 0x7C);
            base = (s8 *) GameData::gameData + 0x70 + slot + 0x64;
            if (kind == 3) {
                if ((M2C_FIELD(base, s32 *, 0) == 3) && (M2C_FIELD(base, s32 *, 4) == 3)) {
                    flag = 1;
                }
                var = flag != 0;
            } else {
                var = M2C_FIELD(base, s32 *, kind * 4);
            }
        }
        M2C_FIELD(this, s32 *, offset + 0x2C) = DetermineGameSound(arg0, var);
    }
}
