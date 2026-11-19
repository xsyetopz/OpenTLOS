#include "spyro/source/DragonStatue.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Game.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDProp.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_DragonStatueEnd;
extern s32 GS_DragonStatueFall;
extern s32 GS_DragonStatueRumble;
extern s32 GS_DragonStatueStart;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

#if 0 // DRAFT: function call 'MKRand_Int(long *, int, int)' does not match
void DragonStatue::EmitDust() {
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;
    f64 sp58;                                       /* compiler-managed */
    f64 sp50;
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;                                       /* compiler-managed */
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 spC;
    f32 sp8;
    f32 temp_f0_122;
    f32 temp_f2_227;
    f32 temp_f3_124;
    f32 var_f4_130;
    f32 var_f5_197;
    f64 temp_f1_121;
    f64 temp_f1_136;
    f64 temp_f1_142;
    f64 temp_f1_146;
    s32 temp_r3_165;
    s32 var_r0_175;
    s32 var_r30_102;

    sp28 = 1.0f;
    var_r30_102 = 0;
    sp20 = 1.0f;
    sp24 = 0.0f;
    sp48 = (f64) sp28;
    sp40 = (f64) sp20;
loop_22:
    if (var_r30_102 < (s32) (this->unkFC + MKRand_Int(&gViewSeed, -1, 1))) {
        sp40 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        unksp44 = 0.0f;
        temp_f1_121 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f0_122 = (f32) 0.0f;
        temp_f3_124 = (f32) temp_f1_121;
        sp48 = (f32) temp_f1_121;
        var_f4_130 = (temp_f3_124 * temp_f3_124) + ((sp40 * sp40) + (temp_f0_122 * temp_f0_122));
        if (var_f4_130 > 0.000001f) {
            if (var_f4_130 > 0.0f) {
                temp_f1_136 = __frsqrte(var_f4_130);
                temp_f1_142 = 0.5 * temp_f1_136 * -(((f64) var_f4_130 * (temp_f1_136 * temp_f1_136)) - 3.0);
                temp_f1_146 = 0.5 * temp_f1_142 * -(((f64) var_f4_130 * (temp_f1_142 * temp_f1_142)) - 3.0);
                var_f4_130 = (f32) ((f64) var_f4_130 * (0.5 * temp_f1_146 * -(((f64) var_f4_130 * (temp_f1_146 * temp_f1_146)) - 3.0)));
            } else if (var_f4_130 < M2C_BITWISE(f32, 0.0)) {
                var_f4_130 = __float_nan;
            } else {
                sp8 = var_f4_130;
                temp_r3_165 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_165) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_175 = 1;
                    } else {
                        var_r0_175 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_175 = 5;
                    } else {
                        var_r0_175 = 3;
                    }
                    break;
                default:
                    var_r0_175 = 4;
                    break;
                }
                if (var_r0_175 == 1) {
                    var_f4_130 = __float_nan;
                }
            }
            var_f5_197 = 1.0f / var_f4_130;
        } else {
            var_f5_197 = 0.0f;
        }
        sp40 *= var_f5_197;
        unksp44 *= var_f5_197;
        sp48 *= var_f5_197;
        sp50 = (f64) sp40;
        sp58 = (f64) sp48;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        temp_f2_227 = (f32) sp58 * (100.0f * MKRand_Float(&gViewSeed, 5.0f, 12.0f));
        sp60 = (f64) sp40;
        sp58 = temp_f2_227;
        sp68 = (f64) sp48;
        unksp64 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
        sp68 = (f32) sp68 * 100.0f;
        spC = MKRand_Float(&gViewSeed, 2.0f, 5.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp30 = sp10;
        sp18 = this->unkE0 + sp58;
        sp38 = (f64) sp18;
        gb.EmitDust(*((MKVector3 *) &sp30), *((MKVector3 *) &sp60), spC, 0.0f);
        var_r30_102 += 1;
        goto loop_22;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp74'
void DragonStatue::EmitCrudAboveStatue() {
    f64 sp78;                                       /* compiler-managed */
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f28_332;
    f32 temp_f28_356;
    f32 temp_f29_327;
    f32 temp_f29_361;
    s32 var_r30_312;

    var_r30_312 = 0;
loop_2:
    if (var_r30_312 < (s32) (this->unkF8 * 2)) {
        sp70 = this->unkD8;
        sp78 = M2C_FIELD(this, f64 *, 0xE0);
        unksp74 += 325.0f;
        temp_f29_327 = MKRand_Float(&gViewSeed, -2500.0f, 2500.0f);
        temp_f28_332 = MKRand_Float(&gViewSeed, 400.0f, 600.0f);
        sp10 = MKRand_Float(&gViewSeed, -2500.0f, 2500.0f);
        sp14 = temp_f28_332;
        sp18 = temp_f29_327;
        sp50 = (f64) sp10;
        sp58 = (f64) sp18;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp78 = (f32) sp78 + (f32) sp58;
        temp_f28_356 = MKRand_Float(&gViewSeed, -4.0f, 4.0f);
        temp_f29_361 = MKRand_Float(&gViewSeed, -2.0f, 0.5f);
        sp30 = MKRand_Float(&gViewSeed, -4.0f, 4.0f);
        sp34 = temp_f29_361;
        sp38 = temp_f28_356;
        sp40 = (f64) sp30;
        sp48 = (f64) sp38;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp60 = sp20;
        sp28 = (f32) sp48 * 100.0f;
        sp68 = (f64) sp28;
        sp8 = MKRand_Float(&gViewSeed, 0.25f, 0.5f);
        gb.EmitCrud(*((MKVector3 *) &sp70), *((MKVector3 *) &sp60), sp8);
        var_r30_312 += 1;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void DragonStatue::EmitCrudAbovePlayer() {
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    M2C_UNK sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f27_457;
    f32 temp_f27_494;
    f32 temp_f28_462;
    f32 temp_f28_499;
    s32 var_r29_437;
    void *temp_r4_445;

    var_r29_437 = 0;
loop_2:
    if (var_r29_437 < (s32) this->unkF8) {
        temp_r4_445 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *), 0xC)(gb.unk0), void **, 8);
        sp80 = M2C_FIELD(temp_r4_445, f64 *, 0x30);
        sp88 = M2C_FIELD(temp_r4_445, f64 *, 0x38);
        unksp84 += 200.0f;
        temp_f27_457 = MKRand_Float(&gViewSeed, -10.0f, 10.0f);
        temp_f28_462 = MKRand_Float(&gViewSeed, 4.0f, 6.0f);
        MKVector(MKRand_Float(&gViewSeed, -10.0f, 10.0f), temp_f28_462, temp_f27_457);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp60 = sp10;
        sp18 = sp58 * 100.0f;
        sp68 = (f64) sp18;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp88 = (f32) sp88 + (f32) sp68;
        temp_f27_494 = MKRand_Float(&gViewSeed, -4.0f, 4.0f);
        temp_f28_499 = MKRand_Float(&gViewSeed, -2.0f, 0.5f);
        sp30 = MKRand_Float(&gViewSeed, -4.0f, 4.0f);
        sp34 = temp_f28_499;
        sp38 = temp_f27_494;
        sp40 = (f64) sp30;
        sp48 = (f64) sp38;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp70 = sp20;
        sp28 = (f32) sp48 * 100.0f;
        sp78 = (f64) sp28;
        sp8 = MKRand_Float(&gViewSeed, 0.25f, 0.5f);
        gb.EmitCrud(*((MKVector3 *) &sp80), *((MKVector3 *) &sp70), sp8);
        var_r29_437 += 1;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkspC'
void DragonStatue::SnapDown() {
    f64 sp10;
    f64 sp8;
    f32 temp_f1_567;
    f64 temp_f2_565;

    temp_f2_565 = M2C_FIELD(this, f64 *, 0xE0);
    sp8 = this->unkD8;
    temp_f1_567 = unkspC;
    sp10 = temp_f2_565;
    unkspC = temp_f1_567 - 6600.0f;
    M2C_FIELD(this->__vptr, M2C_UNK (**)(f64 *, f32, f64), 0x38)(&sp8, temp_f1_567, temp_f2_565);
    this->unk100 = 1;
}
#endif

u8 DragonStatue::IsUp() {
    return (u8) (this->unk100 == 0);
}

u8 DragonStatue::IsDown() {
    return (u8) (this->unk100 == 1);
}

#if 0 // DRAFT: expression syntax error
void DragonStatue::Message(MKMessage *arg0) {
    s8 spE5;
    s8 spE4;
    f32 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    s32 spBC;
    s32 spB8;
    f64 spB0;
    f64 spA8;
    M2C_UNK sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_764;
    s32 temp_r0_674;
    void *temp_r3_749;

    this->unk104.Message(arg0);
    this->unk12C.Message(arg0);
    if ((s32) arg0->unk0 != 0xB5) {

    } else {
        spBC = 0;
        sp88 = this->unkD8;
        sp90 = M2C_FIELD(this, f64 *, 0xE0);
        MKVector(0.7f, 0.7f, 0.7f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp30 = spA0 * 10.0f;
        spB8 = 0x419;
        spD0 = sp28;
        spD8 = (f64) sp30;
        spE5 = 1;
        spC0 = sp88;
        spC8 = sp90;
        spE4 = 1;
        spE0 = 6000.0f;
        spA8 = sp28;
        spB0 = (f64) sp30;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, f64, f64, f64, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &spB8, 0x419, sp90, sp88, (f64) sp30, sp28);
        this->unkA0 = gb.unk30C + 0.2f;
        temp_r0_674 = this->unk100;
        if (temp_r0_674 == 0) {
            this->unk100 = 3;
            this->unk90.Send(NULL);
            KDSound_Play3d(GS_DragonStatueStart, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        } else if (temp_r0_674 == 1) {
            this->unk100 = 2;
            this->unk98.Send(NULL);
            KDSound_Play3d(GS_DragonStatueStart, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            sp18 = -this->unkB8;
            sp1C = -this->unkBC;
            sp20 = -this->unkC0;
            M2C_FIELD(this, f32 *, 0xB8) = (f64) sp18;
            M2C_FIELD(this, f32 *, 0xC0) = (f64) sp20;
            sp78 = (f64) sp18;
            sp8 = -this->unkC8;
            spC = -this->unkCC;
            sp10 = -this->unkD0;
            M2C_FIELD(this, f32 *, 0xC8) = (f64) sp8;
            M2C_FIELD(this, f32 *, 0xD0) = (f64) sp10;
            sp80 = (f64) sp20;
            sp68 = (f64) sp8;
            this->unkE8 = -this->unkE8;
            sp70 = (f64) sp10;
            this->unkF0 = -this->unkF0;
            this->unkEC = 0.0f;
            this->unkA8 = 0.0f;
            this->unkAC = 2000.0f;
            this->unkB0 = 0.0f;
            temp_r3_749 = this->unk8;
            sp48 = M2C_FIELD(temp_r3_749, f64 *, 0x30);
            sp50 = M2C_FIELD(temp_r3_749, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_f1_764 = (f32) sp50 + this->unkB0;
            sp58 = sp38;
            sp40 = temp_f1_764;
            sp60 = (f64) sp40;
            SetPos(sp58, temp_f1_764, (f32) sp50, (f64) sp10, (f64) sp8, (f64) sp20, (f64) sp18);
            this->unkA8 = 0.0f;
            this->unkAC = 0.0f;
            this->unkB0 = 0.0f;
        }
    }
    KDProp::Message(arg0);
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void DragonStatue::Deinit() {
    KDProp::Deinit();
    KDSound_Stop(&this->unk104);
    KDSound_Stop(&this->unk12C);
}
#endif

void DragonStatue::Draw() {
    if ((s32) this->unk100 != 1) {
        KDProp::Draw();
    }
}

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void DragonStatue::Update() {
    Frustum *temp_r31_1928;
    f32 temp_f0_1002;
    f32 temp_f0_1404;
    f32 temp_f0_1408;
    f32 temp_f0_1476;
    f32 temp_f0_930;
    f32 temp_f0_934;
    f32 temp_f1_1001;
    f32 temp_f1_1387;
    f32 temp_f1_1406;
    f32 temp_f1_1466;
    f32 temp_f1_1475;
    f32 temp_f1_1812;
    f32 temp_f1_915;
    f32 temp_f1_932;
    f32 temp_f1_992;
    f32 temp_f2_1405;
    f32 temp_f2_1811;
    f32 temp_f2_931;
    f32 temp_f4_1410;
    f32 temp_f4_1814;
    f32 temp_f4_1938;
    f32 temp_f4_936;
    f32 temp_f5_1413;
    f32 temp_f5_939;
    f32 var_f0_1748;
    f32 var_f0_919;
    f32 var_f1_2044;
    f32 var_f30_892;
    f32 var_f31_1957;
    f32 var_f4_1074;
    f32 var_f4_1171;
    f32 var_f4_1274;
    f32 var_f4_1548;
    f32 var_f4_1645;
    f32 var_f5_1819;
    f64 temp_f1_1077;
    f64 temp_f1_1083;
    f64 temp_f1_1087;
    f64 temp_f1_1174;
    f64 temp_f1_1180;
    f64 temp_f1_1184;
    f64 temp_f1_1277;
    f64 temp_f1_1283;
    f64 temp_f1_1287;
    f64 temp_f1_1551;
    f64 temp_f1_1557;
    f64 temp_f1_1561;
    f64 temp_f1_1648;
    f64 temp_f1_1654;
    f64 temp_f1_1658;
    f64 temp_f1_1941;
    f64 temp_f1_1947;
    f64 temp_f1_1951;
    f64 temp_f2_1048;
    f64 temp_f2_1522;
    f64 temp_f2_1751;
    f64 temp_f2_1757;
    f64 temp_f2_1761;
    f64 temp_f2_1822;
    f64 temp_f2_1828;
    f64 temp_f2_1832;
    f64 temp_f2_2047;
    f64 temp_f2_2053;
    f64 temp_f2_2057;
    f64 temp_f3_1047;
    f64 temp_f3_1521;
    s32 temp_r0_847;
    s32 temp_r0_866;
    s32 temp_r0_880;
    s32 temp_r0_927;
    s32 temp_r3_1106;
    s32 temp_r3_1203;
    s32 temp_r3_1306;
    s32 temp_r3_1580;
    s32 temp_r3_1677;
    s32 temp_r3_1780;
    s32 temp_r3_1851;
    s32 temp_r3_1970;
    s32 temp_r3_2076;
    s32 var_r0_1116;
    s32 var_r0_1213;
    s32 var_r0_1316;
    s32 var_r0_1590;
    s32 var_r0_1687;
    s32 var_r0_1790;
    s32 var_r0_1861;
    s32 var_r0_1980;
    s32 var_r0_2086;
    u8 var_r6_846;
    u8 var_r6_865;
    void *temp_r3_1045;
    void *temp_r3_1249;
    void *temp_r3_1372;
    void *temp_r3_1451;
    void *temp_r3_1519;
    void *temp_r3_1723;
    void *temp_r3_2010;
    void *temp_r3_977;
    void *temp_r4_1044;
    void *temp_r4_1518;
    arg_sp8 = 1;
    var_r6_846 = 0;
    temp_r0_847 = this->unk100;
    if ((temp_r0_847 == 3) || (temp_r0_847 == 2)) {
        var_r6_846 = 1;
    }
    this->unk104.Update(GS_DragonStatueRumble, 1U, var_r6_846, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    arg_sp8 = 1;
    var_r6_865 = 0;
    temp_r0_866 = this->unk100;
    if ((temp_r0_866 == 3) || (temp_r0_866 == 2)) {
        var_r6_865 = 1;
    }
    this->unk12C.Update(GS_DragonStatueFall, 1U, var_r6_865, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_r0_880 = this->unk100;
    if ((temp_r0_880 == 3) || (temp_r0_880 == 2)) {
        if (this->unk154 < 2.0f) {
            if (temp_r0_880 == 3) {
                var_f30_892 = 100.0f;
            } else {
                var_f30_892 = 50.0f;
            }
            ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay3D(0.5f, 0.05f, 0.05f, this->unk8 + 0x30, var_f30_892, 0, 4.0f, 0U);
        }
        temp_f1_915 = this->unk154;
        if (temp_f1_915 > 2.5f) {
            var_f0_919 = 0.0f;
        } else {
            var_f0_919 = temp_f1_915 + gUpdateTimeDelta;
        }
        this->unk154 = var_f0_919;
    }
    temp_r0_927 = this->unk100;
    if (temp_r0_927 == 3) {
        temp_f0_930 = this->unkA8;
        temp_f2_931 = this->unkAC;
        temp_f1_932 = this->unkB8;
        temp_f0_934 = this->unkBC;
        temp_f4_936 = this->unkB0;
        temp_f5_939 = this->unkC0;
        if (((temp_f4_936 * temp_f4_936) + ((temp_f0_930 * temp_f0_930) + (temp_f2_931 * temp_f2_931))) < ((temp_f5_939 * temp_f5_939) + ((temp_f1_932 * temp_f1_932) + (temp_f0_934 * temp_f0_934)))) {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_sp258 = arg_sp58;
            arg_sp60 = this->unkD0 * gUpdateTimeDelta;
            arg_sp260 = (f64) arg_sp60;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
            this->unkB0 += (f32) arg_sp260;
        } else {
            M2C_FIELD(this, f32 *, 0xA8) = (f64) M2C_FIELD(this, f32 *, 0xB8);
            M2C_FIELD(this, f32 *, 0xB0) = (f64) M2C_FIELD(this, f32 *, 0xC0);
        }
        temp_r3_977 = this->unk8;
        arg_sp238 = M2C_FIELD(temp_r3_977, f64 *, 0x30);
        arg_sp240 = M2C_FIELD(temp_r3_977, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_f1_992 = (f32) arg_sp240 + this->unkB0;
        arg_sp248 = arg_sp108;
        arg_sp110 = temp_f1_992;
        arg_sp250 = (f64) arg_sp110;
        SetPos(arg_sp248, temp_f1_992, (f32) arg_sp240);
        temp_f1_1001 = this->unkEC;
        temp_f0_1002 = this->unkE8;
        if (temp_f1_1001 < temp_f0_1002) {
            this->unkEC = temp_f1_1001 + this->unkF0;
        } else {
            this->unkEC = temp_f0_1002;
        }
        this->unkF4 += this->unkEC * gUpdateTimeDelta;
        M2C_STRUCT_COPY((s32) &arg_sp32C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        arg_sp330.SetRotateAroundAxis(up, this->unkF4);
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp330));
        temp_r4_1044 = this->unk8;
        temp_r3_1045 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *), 0xC)(gb.unk0), void **, 8);
        temp_f3_1047 = M2C_FIELD(temp_r3_1045, f64 *, 0x30);
        temp_f2_1048 = M2C_FIELD(temp_r3_1045, f64 *, 0x38);
        arg_sp288 = M2C_FIELD(temp_r4_1044, f64 *, 0x30);
        arg_sp298 = temp_f3_1047;
        arg_sp2A0 = temp_f2_1048;
        arg_sp290 = M2C_FIELD(temp_r4_1044, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp228 = arg_spF8;
        arg_sp100 = (f32) arg_sp290 - this->unkE0;
        arg_sp230 = (f64) arg_sp100;
        var_f4_1074 = ((f32) arg_sp230 * (f32) arg_sp230) + (((f32) arg_sp228 * (f32) arg_sp228) + (arg_sp22C * arg_sp22C));
        if (var_f4_1074 > 0.0f) {
            temp_f1_1077 = __frsqrte(var_f4_1074);
            temp_f1_1083 = 0.5 * temp_f1_1077 * -(((f64) var_f4_1074 * (temp_f1_1077 * temp_f1_1077)) - 3.0);
            temp_f1_1087 = 0.5 * temp_f1_1083 * -(((f64) var_f4_1074 * (temp_f1_1083 * temp_f1_1083)) - 3.0);
            var_f4_1074 = (f32) ((f64) var_f4_1074 * (0.5 * temp_f1_1087 * -(((f64) var_f4_1074 * (temp_f1_1087 * temp_f1_1087)) - 3.0)));
        } else if (var_f4_1074 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1074 = __float_nan;
        } else {
            arg_sp30 = var_f4_1074;
            temp_r3_1106 = M2C_BITWISE(s32, arg_sp30) & 0x7F800000;
            switch (temp_r3_1106) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp30) & 0x7FFFFF) {
                    var_r0_1116 = 1;
                } else {
                    var_r0_1116 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp30) & 0x7FFFFF) {
                    var_r0_1116 = 5;
                } else {
                    var_r0_1116 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1116 = 4;
                break;
            }
            if (var_r0_1116 == 1) {
                var_f4_1074 = __float_nan;
            }
        }
        if (var_f4_1074 < 4600.0f) {
            EmitDust();
        }
        arg_sp28C = arg_sp29C;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (gb.unk30C == this->unkA0) {
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_sp218 = arg_spE8;
            arg_spF0 = (f32) arg_sp290 - (f32) arg_sp2A0;
            arg_sp220 = (f64) arg_spF0;
            var_f4_1171 = ((f32) arg_sp220 * (f32) arg_sp220) + (((f32) arg_sp218 * (f32) arg_sp218) + (arg_sp21C * arg_sp21C));
            if (var_f4_1171 > 0.0f) {
                temp_f1_1174 = __frsqrte(var_f4_1171);
                temp_f1_1180 = 0.5 * temp_f1_1174 * -(((f64) var_f4_1171 * (temp_f1_1174 * temp_f1_1174)) - 3.0);
                temp_f1_1184 = 0.5 * temp_f1_1180 * -(((f64) var_f4_1171 * (temp_f1_1180 * temp_f1_1180)) - 3.0);
                var_f4_1171 = (f32) ((f64) var_f4_1171 * (0.5 * temp_f1_1184 * -(((f64) var_f4_1171 * (temp_f1_1184 * temp_f1_1184)) - 3.0)));
            } else if (var_f4_1171 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1171 = __float_nan;
            } else {
                arg_sp2C = var_f4_1171;
                temp_r3_1203 = M2C_BITWISE(s32, arg_sp2C) & 0x7F800000;
                switch (temp_r3_1203) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp2C) & 0x7FFFFF) {
                        var_r0_1213 = 1;
                    } else {
                        var_r0_1213 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp2C) & 0x7FFFFF) {
                        var_r0_1213 = 5;
                    } else {
                        var_r0_1213 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_1213 = 4;
                    break;
                }
                if (var_r0_1213 == 1) {
                    var_f4_1171 = __float_nan;
                }
            }
            if (var_f4_1171 < 2500.0f) {
                EmitCrudAbovePlayer();
            } else {
                EmitCrudAboveStatue();
            }
            this->unkA0 = gb.unk30C + 0.2f;
        }
        temp_r3_1249 = this->unk8;
        arg_sp1F8 = M2C_FIELD(temp_r3_1249, f64 *, 0x30);
        arg_sp200 = M2C_FIELD(temp_r3_1249, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp208 = arg_spD8;
        arg_spE0 = this->unkE0 - (f32) arg_sp200;
        arg_sp210 = (f64) arg_spE0;
        var_f4_1274 = ((f32) arg_sp210 * (f32) arg_sp210) + (((f32) arg_sp208 * (f32) arg_sp208) + (arg_sp20C * arg_sp20C));
        if (var_f4_1274 > 0.0f) {
            temp_f1_1277 = __frsqrte(var_f4_1274);
            temp_f1_1283 = 0.5 * temp_f1_1277 * -(((f64) var_f4_1274 * (temp_f1_1277 * temp_f1_1277)) - 3.0);
            temp_f1_1287 = 0.5 * temp_f1_1283 * -(((f64) var_f4_1274 * (temp_f1_1283 * temp_f1_1283)) - 3.0);
            var_f4_1274 = (f32) ((f64) var_f4_1274 * (0.5 * temp_f1_1287 * -(((f64) var_f4_1274 * (temp_f1_1287 * temp_f1_1287)) - 3.0)));
        } else if (var_f4_1274 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1274 = __float_nan;
        } else {
            arg_sp28 = var_f4_1274;
            temp_r3_1306 = M2C_BITWISE(s32, arg_sp28) & 0x7F800000;
            switch (temp_r3_1306) {                 /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, arg_sp28) & 0x7FFFFF) {
                    var_r0_1316 = 1;
                } else {
                    var_r0_1316 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, arg_sp28) & 0x7FFFFF) {
                    var_r0_1316 = 5;
                } else {
                    var_r0_1316 = 3;
                }
                break;
            default:                                /* switch 3 */
                var_r0_1316 = 4;
                break;
            }
            if (var_r0_1316 == 1) {
                var_f4_1274 = __float_nan;
            }
        }
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (var_f4_1274 == 4600.0f) {
            arg_sp40 = 0;
            arg_sp3C = 0x41A;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp3C);
            this->unk100 = 1;
            this->unk94.Send(NULL);
            KDSound_Play3d(GS_DragonStatueEnd, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            this->unk154 = 0.0f;
            this->unkA8 = 0.0f;
            this->unkAC = -2000.0f;
            this->unkB0 = 0.0f;
            temp_r3_1372 = this->unk8;
            arg_sp1D8 = M2C_FIELD(temp_r3_1372, f64 *, 0x30);
            arg_sp1E0 = M2C_FIELD(temp_r3_1372, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_f1_1387 = (f32) arg_sp1E0 + this->unkB0;
            arg_sp1E8 = arg_spC8;
            arg_spD0 = temp_f1_1387;
            arg_sp1F0 = (f64) arg_spD0;
            SetPos(arg_sp1E8, temp_f1_1387, (f32) arg_sp1E0);
            this->unkA8 = 0.0f;
            this->unkAC = 0.0f;
            this->unkB0 = 0.0f;
        }
    } else if (temp_r0_927 == 2) {
        temp_f0_1404 = this->unkA8;
        temp_f2_1405 = this->unkAC;
        temp_f1_1406 = this->unkB8;
        temp_f0_1408 = this->unkBC;
        temp_f4_1410 = this->unkB0;
        temp_f5_1413 = this->unkC0;
        if (((temp_f4_1410 * temp_f4_1410) + ((temp_f0_1404 * temp_f0_1404) + (temp_f2_1405 * temp_f2_1405))) < ((temp_f5_1413 * temp_f5_1413) + ((temp_f1_1406 * temp_f1_1406) + (temp_f0_1408 * temp_f0_1408)))) {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_sp1C8 = arg_sp48;
            arg_sp50 = this->unkD0 * gUpdateTimeDelta;
            arg_sp1D0 = (f64) arg_sp50;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
            this->unkB0 += (f32) arg_sp1D0;
        } else {
            M2C_FIELD(this, f32 *, 0xA8) = (f64) M2C_FIELD(this, f32 *, 0xB8);
            M2C_FIELD(this, f32 *, 0xB0) = (f64) M2C_FIELD(this, f32 *, 0xC0);
        }
        temp_r3_1451 = this->unk8;
        arg_sp1A8 = M2C_FIELD(temp_r3_1451, f64 *, 0x30);
        arg_sp1B0 = M2C_FIELD(temp_r3_1451, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_f1_1466 = (f32) arg_sp1B0 + this->unkB0;
        arg_sp1B8 = arg_spB8;
        arg_spC0 = temp_f1_1466;
        arg_sp1C0 = (f64) arg_spC0;
        SetPos(arg_sp1B8, temp_f1_1466, (f32) arg_sp1B0);
        temp_f1_1475 = this->unkEC;
        temp_f0_1476 = this->unkE8;
        if (temp_f1_1475 > temp_f0_1476) {
            this->unkEC = temp_f1_1475 + this->unkF0;
        } else {
            this->unkEC = temp_f0_1476;
        }
        this->unkF4 += this->unkEC * gUpdateTimeDelta;
        M2C_STRUCT_COPY((s32) &arg_sp2EC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        arg_sp2F0.SetRotateAroundAxis(up, this->unkF4);
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp2F0));
        temp_r4_1518 = this->unk8;
        temp_r3_1519 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *), 0xC)(gb.unk0), void **, 8);
        temp_f3_1521 = M2C_FIELD(temp_r3_1519, f64 *, 0x30);
        temp_f2_1522 = M2C_FIELD(temp_r3_1519, f64 *, 0x38);
        arg_sp268 = M2C_FIELD(temp_r4_1518, f64 *, 0x30);
        arg_sp278 = temp_f3_1521;
        arg_sp280 = temp_f2_1522;
        arg_sp270 = M2C_FIELD(temp_r4_1518, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp198 = arg_spA8;
        arg_spB0 = (f32) arg_sp270 - this->unkE0;
        arg_sp1A0 = (f64) arg_spB0;
        var_f4_1548 = ((f32) arg_sp1A0 * (f32) arg_sp1A0) + (((f32) arg_sp198 * (f32) arg_sp198) + (arg_sp19C * arg_sp19C));
        if (var_f4_1548 > 0.0f) {
            temp_f1_1551 = __frsqrte(var_f4_1548);
            temp_f1_1557 = 0.5 * temp_f1_1551 * -(((f64) var_f4_1548 * (temp_f1_1551 * temp_f1_1551)) - 3.0);
            temp_f1_1561 = 0.5 * temp_f1_1557 * -(((f64) var_f4_1548 * (temp_f1_1557 * temp_f1_1557)) - 3.0);
            var_f4_1548 = (f32) ((f64) var_f4_1548 * (0.5 * temp_f1_1561 * -(((f64) var_f4_1548 * (temp_f1_1561 * temp_f1_1561)) - 3.0)));
        } else if (var_f4_1548 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1548 = __float_nan;
        } else {
            arg_sp24 = var_f4_1548;
            temp_r3_1580 = M2C_BITWISE(s32, arg_sp24) & 0x7F800000;
            switch (temp_r3_1580) {                 /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, arg_sp24) & 0x7FFFFF) {
                    var_r0_1590 = 1;
                } else {
                    var_r0_1590 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, arg_sp24) & 0x7FFFFF) {
                    var_r0_1590 = 5;
                } else {
                    var_r0_1590 = 3;
                }
                break;
            default:                                /* switch 4 */
                var_r0_1590 = 4;
                break;
            }
            if (var_r0_1590 == 1) {
                var_f4_1548 = __float_nan;
            }
        }
        if (var_f4_1548 < 4900.0f) {
            EmitDust();
        }
        arg_sp26C = arg_sp27C;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (gb.unk30C == this->unkA0) {
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_sp188 = arg_sp98;
            arg_spA0 = (f32) arg_sp270 - (f32) arg_sp280;
            arg_sp190 = (f64) arg_spA0;
            var_f4_1645 = ((f32) arg_sp190 * (f32) arg_sp190) + (((f32) arg_sp188 * (f32) arg_sp188) + (arg_sp18C * arg_sp18C));
            if (var_f4_1645 > 0.0f) {
                temp_f1_1648 = __frsqrte(var_f4_1645);
                temp_f1_1654 = 0.5 * temp_f1_1648 * -(((f64) var_f4_1645 * (temp_f1_1648 * temp_f1_1648)) - 3.0);
                temp_f1_1658 = 0.5 * temp_f1_1654 * -(((f64) var_f4_1645 * (temp_f1_1654 * temp_f1_1654)) - 3.0);
                var_f4_1645 = (f32) ((f64) var_f4_1645 * (0.5 * temp_f1_1658 * -(((f64) var_f4_1645 * (temp_f1_1658 * temp_f1_1658)) - 3.0)));
            } else if (var_f4_1645 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1645 = __float_nan;
            } else {
                arg_sp20 = var_f4_1645;
                temp_r3_1677 = M2C_BITWISE(s32, arg_sp20) & 0x7F800000;
                switch (temp_r3_1677) {             /* switch 5; irregular */
                case 0x7F800000:                    /* switch 5 */
                    if (M2C_BITWISE(s32, arg_sp20) & 0x7FFFFF) {
                        var_r0_1687 = 1;
                    } else {
                        var_r0_1687 = 2;
                    }
                    break;
                case 0x0:                           /* switch 5 */
                    if (M2C_BITWISE(s32, arg_sp20) & 0x7FFFFF) {
                        var_r0_1687 = 5;
                    } else {
                        var_r0_1687 = 3;
                    }
                    break;
                default:                            /* switch 5 */
                    var_r0_1687 = 4;
                    break;
                }
                if (var_r0_1687 == 1) {
                    var_f4_1645 = __float_nan;
                }
            }
            if (var_f4_1645 < 2500.0f) {
                EmitCrudAbovePlayer();
            } else {
                EmitCrudAboveStatue();
            }
            this->unkA0 = gb.unk30C + 0.2f;
        }
        temp_r3_1723 = this->unk8;
        arg_sp168 = M2C_FIELD(temp_r3_1723, f64 *, 0x30);
        arg_sp170 = M2C_FIELD(temp_r3_1723, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp178 = arg_sp88;
        arg_sp90 = this->unkE0 - (f32) arg_sp170;
        arg_sp180 = (f64) arg_sp90;
        var_f0_1748 = ((f32) arg_sp180 * (f32) arg_sp180) + (((f32) arg_sp178 * (f32) arg_sp178) + (arg_sp17C * arg_sp17C));
        if (var_f0_1748 > 0.0f) {
            temp_f2_1751 = __frsqrte(var_f0_1748);
            temp_f2_1757 = 0.5 * temp_f2_1751 * -(((f64) var_f0_1748 * (temp_f2_1751 * temp_f2_1751)) - 3.0);
            temp_f2_1761 = 0.5 * temp_f2_1757 * -(((f64) var_f0_1748 * (temp_f2_1757 * temp_f2_1757)) - 3.0);
            var_f0_1748 = (f32) ((f64) var_f0_1748 * (0.5 * temp_f2_1761 * -(((f64) var_f0_1748 * (temp_f2_1761 * temp_f2_1761)) - 3.0)));
        } else if (var_f0_1748 < M2C_BITWISE(f32, 0.0)) {
            var_f0_1748 = __float_nan;
        } else {
            arg_sp1C = var_f0_1748;
            temp_r3_1780 = M2C_BITWISE(s32, arg_sp1C) & 0x7F800000;
            switch (temp_r3_1780) {                 /* switch 6; irregular */
            case 0x7F800000:                        /* switch 6 */
                if (M2C_BITWISE(s32, arg_sp1C) & 0x7FFFFF) {
                    var_r0_1790 = 1;
                } else {
                    var_r0_1790 = 2;
                }
                break;
            case 0x0:                               /* switch 6 */
                if (M2C_BITWISE(s32, arg_sp1C) & 0x7FFFFF) {
                    var_r0_1790 = 5;
                } else {
                    var_r0_1790 = 3;
                }
                break;
            default:                                /* switch 6 */
                var_r0_1790 = 4;
                break;
            }
            if (var_r0_1790 == 1) {
                var_f0_1748 = __float_nan;
            }
        }
        temp_f2_1811 = this->unkA8;
        temp_f1_1812 = this->unkAC;
        temp_f4_1814 = this->unkB0;
        var_f5_1819 = (temp_f4_1814 * temp_f4_1814) + ((temp_f2_1811 * temp_f2_1811) + (temp_f1_1812 * temp_f1_1812));
        if (var_f5_1819 > 0.0f) {
            temp_f2_1822 = __frsqrte(var_f5_1819);
            temp_f2_1828 = 0.5 * temp_f2_1822 * -(((f64) var_f5_1819 * (temp_f2_1822 * temp_f2_1822)) - 3.0);
            temp_f2_1832 = 0.5 * temp_f2_1828 * -(((f64) var_f5_1819 * (temp_f2_1828 * temp_f2_1828)) - 3.0);
            var_f5_1819 = (f32) ((f64) var_f5_1819 * (0.5 * temp_f2_1832 * -(((f64) var_f5_1819 * (temp_f2_1832 * temp_f2_1832)) - 3.0)));
        } else if (var_f5_1819 < M2C_BITWISE(f32, 0.0)) {
            var_f5_1819 = __float_nan;
        } else {
            arg_sp18 = var_f5_1819;
            temp_r3_1851 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
            switch (temp_r3_1851) {                 /* switch 7; irregular */
            case 0x7F800000:                        /* switch 7 */
                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                    var_r0_1861 = 1;
                } else {
                    var_r0_1861 = 2;
                }
                break;
            case 0x0:                               /* switch 7 */
                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                    var_r0_1861 = 5;
                } else {
                    var_r0_1861 = 3;
                }
                break;
            default:                                /* switch 7 */
                var_r0_1861 = 4;
                break;
            }
            if (var_r0_1861 == 1) {
                var_f5_1819 = __float_nan;
            }
        }
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (var_f0_1748 == var_f5_1819) {
            SetPos(this->unkD8);
            arg_sp38 = 0;
            arg_sp34 = 0x41A;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp34);
            this->unk100 = 0;
            this->unk9C.Send(NULL);
            KDSound_Play3d(GS_DragonStatueEnd, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            this->unk154 = 0.0f;
            this->unkA8 = 0.0f;
            this->unkAC = 0.0f;
            this->unkB0 = 0.0f;
        }
    } else {
        temp_r31_1928 = M2C_FIELD(&gb, void **, 0x3B8) + 0xB0;
        arg_sp128.GetRadius();
        temp_f4_1938 = (arg_sp130 * arg_sp130) + ((arg_sp128 * arg_sp128) + (arg_sp12C * arg_sp12C));
        if (temp_f4_1938 > 0.0f) {
            temp_f1_1941 = __frsqrte(temp_f4_1938);
            temp_f1_1947 = 0.5 * temp_f1_1941 * -(((f64) temp_f4_1938 * (temp_f1_1941 * temp_f1_1941)) - 3.0);
            temp_f1_1951 = 0.5 * temp_f1_1947 * -(((f64) temp_f4_1938 * (temp_f1_1947 * temp_f1_1947)) - 3.0);
            var_f31_1957 = (f32) ((f64) temp_f4_1938 * (0.5 * temp_f1_1951 * -(((f64) temp_f4_1938 * (temp_f1_1951 * temp_f1_1951)) - 3.0)));
        } else if (temp_f4_1938 < M2C_BITWISE(f32, 0.0)) {
            var_f31_1957 = __float_nan;
        } else {
            arg_sp14 = temp_f4_1938;
            temp_r3_1970 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
            switch (temp_r3_1970) {                 /* switch 8; irregular */
            case 0x7F800000:                        /* switch 8 */
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                    var_r0_1980 = 1;
                } else {
                    var_r0_1980 = 2;
                }
                break;
            case 0x0:                               /* switch 8 */
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                    var_r0_1980 = 5;
                } else {
                    var_r0_1980 = 3;
                }
                break;
            default:                                /* switch 8 */
                var_r0_1980 = 4;
                break;
            }
            if (var_r0_1980 == 1) {
                var_f31_1957 = __float_nan;
            } else {
                var_f31_1957 = temp_f4_1938;
            }
        }
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_r3_2010 = this->unk8;
        arg_sp80 = up.unk8 * var_f31_1957;
        arg_sp138 = arg_sp78;
        arg_sp148 = M2C_FIELD(temp_r3_2010, f64 *, 0x30);
        arg_sp140 = (f64) arg_sp80;
        arg_sp150 = M2C_FIELD(temp_r3_2010, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp158 = arg_sp68;
        arg_sp70 = (f32) arg_sp150 + (f32) arg_sp140;
        arg_sp160 = (f64) arg_sp70;
        arg_sp118.GetRadius();
        var_f1_2044 = (arg_sp120 * arg_sp120) + ((arg_sp118 * arg_sp118) + (arg_sp11C * arg_sp11C));
        if (var_f1_2044 > 0.0f) {
            temp_f2_2047 = __frsqrte(var_f1_2044);
            temp_f2_2053 = 0.5 * temp_f2_2047 * -(((f64) var_f1_2044 * (temp_f2_2047 * temp_f2_2047)) - 3.0);
            temp_f2_2057 = 0.5 * temp_f2_2053 * -(((f64) var_f1_2044 * (temp_f2_2053 * temp_f2_2053)) - 3.0);
            var_f1_2044 = (f32) ((f64) var_f1_2044 * (0.5 * temp_f2_2057 * -(((f64) var_f1_2044 * (temp_f2_2057 * temp_f2_2057)) - 3.0)));
        } else if (var_f1_2044 < M2C_BITWISE(f32, 0.0)) {
            var_f1_2044 = __float_nan;
        } else {
            arg_sp10 = var_f1_2044;
            temp_r3_2076 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_2076) {                 /* switch 9; irregular */
            case 0x7F800000:                        /* switch 9 */
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_2086 = 1;
                } else {
                    var_r0_2086 = 2;
                }
                break;
            case 0x0:                               /* switch 9 */
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_2086 = 5;
                } else {
                    var_r0_2086 = 3;
                }
                break;
            default:                                /* switch 9 */
                var_r0_2086 = 4;
                break;
            }
            if (var_r0_2086 == 1) {
                var_f1_2044 = __float_nan;
            }
        }
        if (temp_r31_1928->IsVisible(*((MKVector3 *) &arg_sp158), var_f1_2044) == 0) {
            M2C_STRUCT_COPY((s32) &arg_sp2AC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
            arg_sp2B0.SetRotateAroundAxis(up, 0.0f);
            MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp2B0));
        }
    }
    KDProp::Update();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 DragonStatue::LoadLine(MKIniLine *arg0) {
    if (KDProp::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (this->unk90.LoadLine(arg0, "OnStartDown") != 0) {
        return 1U;
    }
    if (this->unk94.LoadLine(arg0, "OnDown") != 0) {
        return 1U;
    }
    if (this->unk98.LoadLine(arg0, "OnStartUp") != 0) {
        return 1U;
    }
    if (this->unk9C.LoadLine(arg0, "OnUp") != 0) {
        return 1U;
    }
    if (arg0->LoadVector3("MoveSpeed", (MKVector3 *) &this->unkB8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadVector3("MoveAccelleration", (MKVector3 *) &this->unkC8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("AmountOfCrud", &this->unkF8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("AmountOfDust", &this->unkFC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("AngularSpeed", &this->unkE8, 0) != 0) {
        return 1U;
    }
    return (u8) (arg0->LoadFloat("AngularAcceleration", &this->unkF0, 0) != 0);
}
#endif

void DragonStatue::LoadDone() {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_2295;
    f64 temp_f1_2294;
    void *temp_r3_2293;

    KDProp::LoadDone();
    temp_r3_2293 = this->unk8;
    temp_f1_2294 = M2C_FIELD(temp_r3_2293, f64 *, 0x30);
    temp_f0_2295 = M2C_FIELD(temp_r3_2293, f64 *, 0x38);
    sp8 = temp_f1_2294;
    this->unkD8 = temp_f1_2294;
    sp10 = temp_f0_2295;
    M2C_FIELD(this, f64 *, 0xE0) = temp_f0_2295;
}

#if 0 // DRAFT: undefined identifier 'zero'
void DragonStatue::Init() {
    KDProp::Init();
    this->unkD8 = M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xE0) = (f64) M2C_FIELD(&zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0xB8) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(&zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0xA8) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xB0) = (f64) M2C_FIELD(&zero, f64 *, 8);
    this->unkE8 = 0.0f;
    this->unkEC = 0.0f;
    this->unkF0 = 0.0f;
    this->unkF4 = 0.0f;
    this->unkF8 = 0;
    this->unkFC = 0;
    this->unk100 = 0;
    this->unk104.Init(0.25f, 0.25f);
    this->unk12C.Init(0.25f, 0.25f);
    this->unk154 = 0.0f;
}
#endif
