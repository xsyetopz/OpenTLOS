s32 MKLevelChunk::Update_Ready() {
    s32 var_r31;

    var_r31 = 0;
    if ((strlen((const char *) ((s8 *) this + 0x104)) != 0) || (M2C_FIELD(this, u32 *, 0x13C) & 0x20)) {
        if (M2C_FIELD(this, u32 *, 0x13C) & 0x100) {
            var_r31 = 0xC;
            M2C_FIELD(this, u32 *, 0x13C) |= 0x40;
            M2C_FIELD(this, u32 *, 0x13C) |= 0x80;
        } else {
            M2C_FIELD(this, u32 *, 0x13C) |= 0x400;
            var_r31 = 0xA;
            this->unk4 = 0;
        }
    }
    return var_r31;
}
