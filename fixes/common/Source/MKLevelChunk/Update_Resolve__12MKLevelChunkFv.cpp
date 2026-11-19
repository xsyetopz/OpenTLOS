s32 MKLevelChunk::Update_Resolve() {
    s32 var_r31;

    var_r31 = 0;
    if ((u8) this->ResolveAllProps() != 0) {
        var_r31 = 7;
        M2C_FIELD(this, u32 *, 0x13C) |= 0x200000;
        if (M2C_FIELD(this, u32 *, 0x13C) & 0x20000) {
            M2C_FIELD(this, MKIni **, 0x8C)->Deinit();
            M2C_FIELD(this, u32 *, 0x13C) &= 0xFFFDFFFF;
        }
    }
    return var_r31;
}
