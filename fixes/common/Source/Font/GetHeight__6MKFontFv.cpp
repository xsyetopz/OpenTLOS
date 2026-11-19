f32 MKFont::GetHeight() {
    return M2C_FIELD(*(s8 **) *(s8 **) this, f32 *, 0x24);
}
