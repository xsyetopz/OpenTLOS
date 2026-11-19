u8 DynamiteExplosion::UpdateElec(DynamiteExplosion::Explosion *arg1) {
    f64 sp150;
    f64 sp148;
    MKVector3 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    MKVector3 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_116;
    f32 temp_f1_124;
    f32 temp_f1_252;
    f32 temp_f1_80;
    f32 temp_f30_78;
    f32 temp_f31_231;
    f32 var_f0_60;
    f32 var_f3_199;
    f32 var_f3_327;
    f32 var_f4_132;
    f32 var_f4_260;
    f64 temp_f0_346;
    f64 temp_f0_356;
    f64 temp_f1_138;
    f64 temp_f1_144;
    f64 temp_f1_148;
    f64 temp_f1_266;
    f64 temp_f1_272;
    f64 temp_f1_276;
    s32 temp_r0_54;
    s32 temp_r3_167;
    s32 temp_r3_295;
    s32 var_r0_177;
    s32 var_r0_305;

    M2C_FIELD(arg1, f32 *, 0x10) = (f32) (M2C_FIELD(arg1, f32 *, 0x10) - gUpdateTimeDelta);
    temp_r0_54 = M2C_FIELD(arg1, s32 *, 0x18);
    if (temp_r0_54 != 1) {
        if (temp_r0_54 < 1) {

        }
        goto block_51;
    }
    var_f0_60 = M2C_FIELD(arg1, f32 *, 0x10);
    if (var_f0_60 < 1.0f) {

    } else {
        var_f0_60 = 1.0f;
    }
    if (var_f0_60 > 0.0f) {

    } else {
        var_f0_60 = 0.0f;
    }
    M2C_FIELD(arg1, f32 *, 0x10) = var_f0_60;
    temp_f30_78 = M2C_FIELD(arg1, f32 *, 0x10);
    temp_f1_80 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
    sp90 = -1.0f;
    sp80 = 1.0f;
    sp88 = -1.0f;
    sp8C = 0.0f;
    sp78 = 1.0f;
    sp7C = 1.0f;
    sp98 = 1.0f;
    sp9C = (0.2f * temp_f1_80) + 0.1f;
    spA0 = (0.75f * temp_f1_80) + 0.25f;
    spA4 = 1.0f;
    sp128 = (f64) sp88;
    sp130 = (f64) sp90;
    sp118 = (f64) sp78;
    sp120 = (f64) sp80;
    temp_f1_116 = M2C_FIELD(arg1, f32 *, 0x14) * MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f);
    sp108 = (f64) sp98;
    sp110 = (f64) spA0;
    sp10 = temp_f30_78 * temp_f1_116;
    sp138 = KDRand_Vector(*((MKVector3 *) &sp128), *((MKVector3 *) &sp118));
    temp_f1_124 = sp138.unk0;
    var_f4_132 = (sp138.unk8 * sp138.unk8) + ((temp_f1_124 * temp_f1_124) + (sp138.unk4 * sp138.unk4));
    if (var_f4_132 > 1e-12f) {
        if (var_f4_132 > 0.0f) {
            temp_f1_138 = __frsqrte(var_f4_132);
            temp_f1_144 = 0.5 * temp_f1_138 * -(((f64) var_f4_132 * (temp_f1_138 * temp_f1_138)) - 3.0);
            temp_f1_148 = 0.5 * temp_f1_144 * -(((f64) var_f4_132 * (temp_f1_144 * temp_f1_144)) - 3.0);
            var_f4_132 = (f32) ((f64) var_f4_132 * (0.5 * temp_f1_148 * -(((f64) var_f4_132 * (temp_f1_148 * temp_f1_148)) - 3.0)));
        } else if (var_f4_132 < M2C_BITWISE(f32, 0.0)) {
            var_f4_132 = __float_nan;
        } else {
            spC = var_f4_132;
            temp_r3_167 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_167) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_177 = 1;
                } else {
                    var_r0_177 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_177 = 5;
                } else {
                    var_r0_177 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_177 = 4;
                break;
            }
            if (var_r0_177 == 1) {
                var_f4_132 = __float_nan;
            }
        }
        var_f3_199 = 1.0f / var_f4_132;
    } else {
        var_f3_199 = 0.0f;
    }
    sp68 = sp138.unk0 * var_f3_199;
    sp6C = sp138.unk4 * var_f3_199;
    sp70 = sp138.unk8 * var_f3_199;
    sp148 = (f64) sp68;
    sp150 = (f64) sp70;
    ((ZapArcFX *) gb.unk94)->Trigger(*((MKVector3 *) arg1), *((MKVector3 *) &sp148), sp10, lit_1149, *((MKVector4 *) &sp108));
    temp_f31_231 = MKRand_Float((int *) &gViewSeed, 2000.0f, 3000.0f);
    sp60 = -1.0f;
    sp50 = 1.0f;
    sp58 = -1.0f;
    sp5C = 0.0f;
    sp48 = 1.0f;
    sp4C = 1.0f;
    spB8 = (f64) sp58;
    spC0 = (f64) sp60;
    spA8 = (f64) sp48;
    spB0 = (f64) sp50;
    spC8 = KDRand_Vector(*((MKVector3 *) &spB8), *((MKVector3 *) &spA8));
    temp_f1_252 = spC8.unk0;
    var_f4_260 = (spC8.unk8 * spC8.unk8) + ((temp_f1_252 * temp_f1_252) + (spC8.unk4 * spC8.unk4));
    if (var_f4_260 > 1e-12f) {
        if (var_f4_260 > 0.0f) {
            temp_f1_266 = __frsqrte(var_f4_260);
            temp_f1_272 = 0.5 * temp_f1_266 * -(((f64) var_f4_260 * (temp_f1_266 * temp_f1_266)) - 3.0);
            temp_f1_276 = 0.5 * temp_f1_272 * -(((f64) var_f4_260 * (temp_f1_272 * temp_f1_272)) - 3.0);
            var_f4_260 = (f32) ((f64) var_f4_260 * (0.5 * temp_f1_276 * -(((f64) var_f4_260 * (temp_f1_276 * temp_f1_276)) - 3.0)));
        } else if (var_f4_260 < M2C_BITWISE(f32, 0.0)) {
            var_f4_260 = __float_nan;
        } else {
            sp8 = var_f4_260;
            temp_r3_295 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_295) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_305 = 1;
                } else {
                    var_r0_305 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_305 = 5;
                } else {
                    var_r0_305 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_305 = 4;
                break;
            }
            if (var_r0_305 == 1) {
                var_f4_260 = __float_nan;
            }
        }
        var_f3_327 = 1.0f / var_f4_260;
    } else {
        var_f3_327 = 0.0f;
    }
    sp18 = spC8.unk0 * var_f3_327;
    sp1C = spC8.unk4 * var_f3_327;
    sp20 = spC8.unk8 * var_f3_327;
    spD8 = (f64) sp18;
    spE0 = (f64) sp20;
    temp_f0_346 = spD8 * (f64) temp_f31_231;
    sp38 = temp_f0_346;
    spE8 = temp_f0_346;
    sp40 = (f32) spE0 * temp_f31_231;
    spF0 = (f64) sp40;
    temp_f0_356 = temp_f0_346 * (f64) temp_f30_78;
    sp28 = temp_f0_356;
    spF8 = temp_f0_356;
    sp30 = (f32) spF0 * temp_f30_78;
    sp100 = (f64) sp30;
    ((ElectricSparks *) gb.unk230)->Emit(*((MKVector3 *) arg1), *((MKVector3 *) &spF8), temp_f30_78 * (M2C_FIELD(arg1, f32 *, 0x14) * MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f)), 1U);
    if (M2C_FIELD(arg1, f32 *, 0x10) <= 0.0f) {
        return 0U;
    }
block_51:
    return 1U;
}
