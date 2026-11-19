void MKFont::ResetFontStack(MKFont *arg0, unsigned int arg1) {
    s32 off = 0;
    u32 i = 0;
    while (i < (u32) M2C_FIELD(&gMKDefaults, u32 *, 0xB0)) {
        M2C_FIELD(*(s8 **) MKFont::currentFontStack + off, s32 *, 0) = 0;
        M2C_FIELD(*(s8 **) MKFont::currentFontStack + off, s32 *, 4) = 0;
        M2C_FIELD(*(s8 **) MKFont::currentFontStack + off, s32 *, 8) = 0;
        M2C_FIELD(*(s8 **) MKFont::currentFontStack + off, s32 *, 0xC) = M2C_FIELD(&gMKDefaults, s32 *, 0xAC);
        M2C_FIELD(*(s8 **) MKFont::currentFontStack + off, s32 *, 0x10) = 0;
        i += 1;
        off += 0x14;
    }
    *(s32 *) MKFont::currentFont = 0;
    if (arg0 != NULL) {
        M2C_FIELD(*(s8 **) MKFont::currentFontStack, MKFont **, 0) = arg0;
        M2C_FIELD(*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14, s32 *, 4) = 0;
    }
}
