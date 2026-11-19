void Hud_DrawBarVert(const MKVector2 &arg0, const MKVector2 &arg1, const MKVector2 &arg2, const MKVector2 &arg3, const MKVector2 &arg4, const MKVector4 &arg5, const MKVector4 &arg6, const MKVector4 &arg7, float arg8, float arg9, float arg10, bool arg11) {
    MKVector4 spColor;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f23_1796;
    f32 temp_f28_1756;
    f32 temp_f28_1919;
    f32 temp_f29_1734;
    f32 temp_f29_1791;
    f32 temp_f29_1951;
    f32 temp_f2_1917;
    f32 temp_f3_1923;
    f32 temp_f5_1730;
    f32 temp_f6_1728;
    f32 var_f0_1760;
    f32 var_f0_1769;
    f32 var_f0_1853;
    f32 var_f0_1864;
    f32 var_f0_1895;
    f32 var_f0_1906;
    f32 var_f26_1754;
    f32 var_f27_1755;
    f32 var_f2_1943;
    f32 var_f2_2009;
    f32 var_f4_1742;
    f32 var_f4_1920;
    f32 var_f4_2004;
    f32 var_f5_1960;
    f32 var_f5_2026;

    temp_f6_1728 = arg4.unk4;
    temp_f5_1730 = arg3.unk4;
    temp_f29_1734 = 0.6f * arg8;
    if (temp_f6_1728 > temp_f5_1730) {
        var_f4_1742 = temp_f29_1734;
    } else {
        var_f4_1742 = -temp_f29_1734;
    }
    var_f26_1754 = (0.5f * var_f4_1742) + (temp_f6_1728 - temp_f5_1730);
    var_f27_1755 = arg0.unk4 + temp_f5_1730;
    temp_f28_1756 = -((0.5f * temp_f29_1734) - (arg0.unk0 + arg3.unk0));
    if (arg11) {
        if (temp_f6_1728 > temp_f5_1730) {
            var_f0_1760 = temp_f29_1734;
        } else {
            var_f0_1760 = -temp_f29_1734;
        }
        var_f26_1754 += 0.5f * var_f0_1760;
        if (temp_f6_1728 > temp_f5_1730) {
            var_f0_1769 = -temp_f29_1734;
        } else {
            var_f0_1769 = temp_f29_1734;
        }
        var_f27_1755 += 0.5f * var_f0_1769;
    }
    MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
    MKPrimitive(0xC, 3);
    MKBegin(4);
    MKSetColorV(arg6);
    MKSetPositionF(temp_f28_1756, var_f27_1755, 0.0f);
    temp_f29_1791 = temp_f28_1756 + temp_f29_1734;
    MKSetPositionF(temp_f29_1791, var_f27_1755, 0.0f);
    temp_f23_1796 = var_f27_1755 + var_f26_1754;
    MKSetPositionF(temp_f28_1756, temp_f23_1796, 0.0f);
    MKSetPositionF(temp_f29_1791, temp_f23_1796, 0.0f);
    MKEnd();
    MKEndPrimitive();
    if (arg9 != arg10) {
        MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
        MKPrimitive(0xC, 3);
        MKBegin(4);
        /* ps_add of arg6 and arg7 per lane, then ps_muls0 by 0.5f (@1438) */
        spColor.unk0 = (arg6.unk0 + arg7.unk0) * 0.5f;
        spColor.unk4 = (arg6.unk4 + arg7.unk4) * 0.5f;
        spColor.unk8 = (arg6.unk8 + arg7.unk8) * 0.5f;
        spColor.unkC = (arg6.unkC + arg7.unkC) * 0.5f;
        MKSetColorV(spColor);
        MKSetPositionF(temp_f28_1756, var_f27_1755, 0.0f);
        MKSetPositionF(temp_f29_1791, var_f27_1755, 0.0f);
        if (arg9 > arg10) {
            var_f0_1853 = arg9;
        } else {
            var_f0_1853 = arg10;
        }
        MKSetPositionF(temp_f28_1756, (var_f26_1754 * var_f0_1853) + var_f27_1755, 0.0f);
        if (arg9 > arg10) {
            var_f0_1864 = arg9;
        } else {
            var_f0_1864 = arg10;
        }
        MKSetPositionF(temp_f29_1791, (var_f26_1754 * var_f0_1864) + var_f27_1755, 0.0f);
        MKEnd();
        MKEndPrimitive();
    }
    MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
    MKPrimitive(0xC, 3);
    MKBegin(4);
    MKSetColorV(arg7);
    MKSetPositionF(temp_f28_1756, var_f27_1755, 0.0f);
    MKSetPositionF(temp_f29_1791, var_f27_1755, 0.0f);
    if (arg9 < arg10) {
        var_f0_1895 = arg9;
    } else {
        var_f0_1895 = arg10;
    }
    MKSetPositionF(temp_f28_1756, (var_f26_1754 * var_f0_1895) + var_f27_1755, 0.0f);
    if (arg9 < arg10) {
        var_f0_1906 = arg9;
    } else {
        var_f0_1906 = arg10;
    }
    MKSetPositionF(temp_f29_1791, (var_f26_1754 * var_f0_1906) + var_f27_1755, 0.0f);
    MKEnd();
    MKEndPrimitive();
    temp_f2_1917 = arg1.unk4;
    temp_f28_1919 = arg2.unk4 - temp_f2_1917;
    var_f4_1920 = 0.5f;
    sp50 = 0.0f;
    temp_f3_1923 = 0.5f * temp_f28_1919;
    sp98 = sp50;
    sp54 = temp_f3_1923;
    sp9C = sp54;
    sp48 = arg1.unk0 + sp98;
    sp4C = temp_f2_1917 + sp9C;
    spA0 = sp48;
    spA4 = sp4C;
    if (temp_f28_1919 > 0.0f) {
        var_f4_1920 = 1.0f;
    }
    var_f2_1943 = 0.0f;
    if (temp_f28_1919 > 0.0f) {
        var_f2_1943 = 0.5f;
    }
    sp30 = arg8;
    temp_f29_1951 = 0.5f * arg8;
    sp34 = temp_f29_1951;
    sp80 = sp30;
    sp84 = sp34;
    if (temp_f28_1919 > 0.0f) {
        var_f5_1960 = arg8;
    } else {
        var_f5_1960 = -arg8;
    }
    sp40 = spA0;
    sp88 = sp40;
    sp44 = (0.25f * var_f5_1960) + (spA4 + temp_f3_1923);
    sp8C = sp44;
    sp38 = arg0.unk0 + sp88;
    sp3C = arg0.unk4 + sp8C;
    sp90 = sp38;
    sp94 = sp3C;
    Hud_DrawIcon(0, 3, *((MKVector2 *) &sp90), *((MKVector2 *) &sp80), arg5, 0.0f, var_f2_1943, 1.0f, var_f4_1920, 0U, 0U, Matrix::identity);
    if (arg11) {
        if (temp_f28_1919 > 0.0f) {
            var_f4_2004 = 0.5f;
        } else {
            var_f4_2004 = 1.0f;
        }
        var_f2_2009 = 0.0f;
        if (temp_f28_1919 > 0.0f) {

        } else {
            var_f2_2009 = 0.5f;
        }
        sp18 = arg8;
        sp1C = temp_f29_1951;
        sp68 = sp18;
        sp6C = sp1C;
        if (temp_f28_1919 > 0.0f) {
            var_f5_2026 = -arg8;
        } else {
            var_f5_2026 = arg8;
        }
        sp28 = spA0;
        sp2C = (0.25f * var_f5_2026) + arg1.unk4;
        sp70 = sp28;
        sp74 = sp2C;
        sp20 = arg0.unk0 + sp70;
        sp24 = arg0.unk4 + sp74;
        sp78 = sp20;
        sp7C = sp24;
        Hud_DrawIcon(0, 3, *((MKVector2 *) &sp78), *((MKVector2 *) &sp68), arg5, 0.0f, var_f2_2009, 1.0f, var_f4_2004, 0U, 0U, Matrix::identity);
    }
    sp8 = arg8;
    spC = temp_f28_1919;
    sp10 = arg0.unk0 + spA0;
    sp14 = arg0.unk4 + spA4;
    sp58 = sp8;
    sp5C = spC;
    sp60 = sp10;
    sp64 = sp14;
    Hud_DrawIcon(0, 3, *((MKVector2 *) &sp60), *((MKVector2 *) &sp58), arg5, 0.0f, 0.5f, 1.0f, 0.5f, 0U, 0U, Matrix::identity);
}
