f32 MKFont_GetHeight(MKFont *arg0) {
    void *temp_r3;

    temp_r3 = M2C_FIELD(arg0, void **, 0);
    temp_r3 = M2C_FIELD(temp_r3, void **, 0);
    return M2C_FIELD(temp_r3, f32 *, 0x24);
}
