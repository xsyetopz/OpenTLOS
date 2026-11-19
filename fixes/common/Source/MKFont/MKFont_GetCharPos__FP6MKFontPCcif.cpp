extern "C" f64 fmod(f64, f64);

MKVector3 MKFont_GetCharPos(MKFont *arg1, const char *arg2, int arg3, float farg0) {
    MKVector3 result;
    f32 sp8;
    f32 temp_f31_915;
    f32 temp_f30_920;
    f32 temp_f29_921;
    const char *var_r31_909;
    const char *var_r4_927;
    s8 temp_r5_993;
    u8 temp_r0_932;
    u8 var_r3_933;
    s32 glyph;
    void *temp_r3_917;

    M2C_FIELD(&result, f64 *, 0) = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(&result, f64 *, 8) = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    var_r31_909 = arg2;
    temp_f31_915 = MKFontInternal_CalcHeightAndScale(arg1, farg0, &sp8);
    temp_r3_917 = M2C_FIELD(arg1, void **, 0);
    temp_r3_917 = M2C_FIELD(temp_r3_917, void **, 0);
    temp_f30_920 = M2C_FIELD(temp_r3_917, f32 *, 8) * sp8;
    temp_f29_921 = M2C_FIELD(temp_r3_917, f32 *, 0xC) * sp8;
    temp_r5_993 = (s8) (u8) *var_r31_909;
    while ((temp_r5_993 != 0) && ((u32) (var_r31_909 - arg2) < (u32) arg3)) {
        glyph = 0;
        if (temp_r5_993 == 0x3C) {
            var_r4_927 = var_r31_909 + 1;
            temp_r0_932 = (u8) *var_r4_927;
            var_r3_933 = 0;
            if (((s8) temp_r0_932 == 0x20) || ((s8) temp_r0_932 == 9) || ((s8) temp_r0_932 == 0xA)) {
                var_r3_933 = 1;
            }
            while (var_r3_933 != 0) {
                var_r4_927 += 1;
                temp_r0_932 = (u8) *var_r4_927;
                var_r3_933 = 0;
                if (((s8) temp_r0_932 == 0x20) || ((s8) temp_r0_932 == 9) || ((s8) temp_r0_932 == 0xA)) {
                    var_r3_933 = 1;
                }
            }
            glyph = 1;
        } else if (temp_r5_993 == 0x20) {
            result.unk0 = result.unk0 + temp_f29_921;
        } else if (temp_r5_993 == 0xA) {
            result.unk0 = 0.0f;
            result.unk4 = result.unk4 + temp_f31_915;
        } else if (temp_r5_993 == 0x9) {
            result.unk0 = (result.unk0 + gFontTabWidth) - (f32) fmod((f64) result.unk0, (f64) gFontTabWidth);
        } else {
            glyph = 1;
        }
        if (glyph != 0) {
            result.unk0 = result.unk0 + ((sp8 * *(f32 *) ((u8 *) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg1, void **, 0), void **, 0), void **, 0x28) + (((s8) temp_r5_993 << 5) + 0x18))) + temp_f30_920);
        }
        var_r31_909 += 1;
        temp_r5_993 = (s8) (u8) *var_r31_909;
    }
    return result;
}
