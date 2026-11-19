u8 MKLevelChunk::IsReady() {
    s32 temp_r0;
    u8 var_r31;

    var_r31 = 0;
    temp_r0 = M2C_FIELD(this, s32 *, 0x90);
    if (((temp_r0 == 9) || (temp_r0 == 0xC)) && (strlen((const char *) ((s8 *) this + 0x104)) == 0)) {
        var_r31 = 1;
    }
    return var_r31;
}
