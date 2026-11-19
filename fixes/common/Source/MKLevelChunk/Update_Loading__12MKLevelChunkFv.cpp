s32 MKLevelChunk::Update_Loading() {
    s32 var_r31;

    var_r31 = 0;
    M2C_FIELD(this, u32 *, 0x13C) &= 0xFFFBFFFF;
    if (MKPackage_QIsLoaded(this->unk10, NULL, NULL) != 0) {
        M2C_FIELD(this, u32 *, 0x13C) |= 0x80000;
        if ((strlen((const char *) ((s8 *) this + 0x104)) != 0) || (M2C_FIELD(this, u32 *, 0x13C) & 0x20)) {
            var_r31 = 0xA;
        } else if ((u8) this->InitChunk() != 0) {
            ((MKSceneManager *) gMK)->BeginChunkLoad(M2C_FIELD(this, MKIni **, 0x8C));
            var_r31 = 5;
        }
    }
    return var_r31;
}
