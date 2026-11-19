#include "spyro/source/DragonStatue.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern s32 GS_DragonStatueEnd;
extern s32 GS_DragonStatueFall;
extern s32 GS_DragonStatueRumble;
extern s32 GS_DragonStatueStart;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

#if 0 // DRAFT: undefined identifier '__float_nan'
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
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_122;
    f32 temp_f2_219;
    f32 temp_f3_124;
    f32 var_f4_130;
    f32 var_f5_197;
    f64 temp_f0_222;
    f64 temp_f0_251;
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
    if (var_r30_102 < (s32) (this->unkFC + MKRand_Int((int *) &gViewSeed, -1, 1))) {
        sp40 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        (*(f32 *) ((u8 *) &sp38 + 0xc)) = 0.0f;
        temp_f1_121 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
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
        (*(f32 *) ((u8 *) &sp38 + 0xc)) *= var_f5_197;
        sp48 *= var_f5_197;
        sp50 = (f64) sp40;
        sp58 = (f64) sp48;
        temp_f2_219 = 100.0f * MKRand_Float((int *) &gViewSeed, 5.0f, 12.0f);
        temp_f0_222 = sp50 * (f64) temp_f2_219;
        sp50 = temp_f0_222;
        sp60 = (f64) sp40;
        sp58 = (f32) sp58 * temp_f2_219;
        sp68 = (f64) sp48;
        (*(f32 *) ((u8 *) &sp60 + 0x4)) = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        sp60 *= 5.53552857e-315;
        sp68 = (f32) sp68 * 100.0f;
        spC = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
        temp_f0_251 = this->unkD8 + temp_f0_222;
        sp10 = temp_f0_251;
        sp30 = temp_f0_251;
        sp18 = this->unkE0 + sp58;
        sp38 = (f64) sp18;
        gb.EmitDust(*((MKVector3 *) &sp30), *((MKVector3 *) &sp60), spC, 0.0f);
        var_r30_102 += 1;
        goto loop_22;
    }
}
#endif

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
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f28_332;
    f32 temp_f28_356;
    f32 temp_f29_327;
    f32 temp_f29_361;
    f64 temp_f0_375;
    s32 var_r30_312;

    var_r30_312 = 0;
loop_2:
    if (var_r30_312 < (s32) (this->unkF8 * 2)) {
        sp70 = this->unkD8;
        sp78 = M2C_FIELD(this, f64 *, 0xE0);
        (*(f32 *) ((u8 *) &sp70 + 0x4)) += 325.0f;
        temp_f29_327 = MKRand_Float((int *) &gViewSeed, -2500.0f, 2500.0f);
        temp_f28_332 = MKRand_Float((int *) &gViewSeed, 400.0f, 600.0f);
        sp10 = MKRand_Float((int *) &gViewSeed, -2500.0f, 2500.0f);
        sp14 = temp_f28_332;
        sp18 = temp_f29_327;
        sp50 = (f64) sp10;
        sp58 = (f64) sp18;
        sp70 += sp50;
        sp78 = (f32) sp78 + (f32) sp58;
        temp_f28_356 = MKRand_Float((int *) &gViewSeed, -4.0f, 4.0f);
        temp_f29_361 = MKRand_Float((int *) &gViewSeed, -2.0f, 0.5f);
        sp30 = MKRand_Float((int *) &gViewSeed, -4.0f, 4.0f);
        sp34 = temp_f29_361;
        sp38 = temp_f28_356;
        sp40 = (f64) sp30;
        sp48 = (f64) sp38;
        temp_f0_375 = sp40 * 5.53552857e-315;
        sp20 = temp_f0_375;
        sp60 = temp_f0_375;
        sp28 = (f32) sp48 * 100.0f;
        sp68 = (f64) sp28;
        sp8 = MKRand_Float((int *) &gViewSeed, 0.25f, 0.5f);
        gb.EmitCrud(*((MKVector3 *) &sp70), *((MKVector3 *) &sp60), sp8);
        var_r30_312 += 1;
        goto loop_2;
    }
}

#if 0 // DRAFT: undefined identifier 'MKVector'
void DragonStatue::EmitCrudAbovePlayer() {
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f27_457;
    f32 temp_f27_494;
    f32 temp_f28_462;
    f32 temp_f28_499;
    f64 temp_f0_473;
    f64 temp_f0_513;
    s32 var_r29_437;
    void *temp_r4_445;

    var_r29_437 = 0;
loop_2:
    if (var_r29_437 < (s32) this->unkF8) {
        temp_r4_445 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
        sp80 = M2C_FIELD(temp_r4_445, f64 *, 0x30);
        sp88 = M2C_FIELD(temp_r4_445, f64 *, 0x38);
        (*(f32 *) ((u8 *) &sp80 + 0x4)) += 200.0f;
        temp_f27_457 = MKRand_Float((int *) &gViewSeed, -10.0f, 10.0f);
        temp_f28_462 = MKRand_Float((int *) &gViewSeed, 4.0f, 6.0f);
        MKVector(MKRand_Float((int *) &gViewSeed, -10.0f, 10.0f), temp_f28_462, temp_f27_457);
        temp_f0_473 = sp50 * 5.53552857e-315;
        sp10 = temp_f0_473;
        sp60 = temp_f0_473;
        sp18 = sp58 * 100.0f;
        sp68 = (f64) sp18;
        sp80 += temp_f0_473;
        sp88 = (f32) sp88 + (f32) sp68;
        temp_f27_494 = MKRand_Float((int *) &gViewSeed, -4.0f, 4.0f);
        temp_f28_499 = MKRand_Float((int *) &gViewSeed, -2.0f, 0.5f);
        sp30 = MKRand_Float((int *) &gViewSeed, -4.0f, 4.0f);
        sp34 = temp_f28_499;
        sp38 = temp_f27_494;
        sp40 = (f64) sp30;
        sp48 = (f64) sp38;
        temp_f0_513 = sp40 * 5.53552857e-315;
        sp20 = temp_f0_513;
        sp70 = temp_f0_513;
        sp28 = (f32) sp48 * 100.0f;
        sp78 = (f64) sp28;
        sp8 = MKRand_Float((int *) &gViewSeed, 0.25f, 0.5f);
        gb.EmitCrud(*((MKVector3 *) &sp80), *((MKVector3 *) &sp70), sp8);
        var_r29_437 += 1;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void DragonStatue::SnapDown() {
    f64 sp10;
    f64 sp8;
    f32 temp_f1_567;
    f64 temp_f2_565;

    temp_f2_565 = M2C_FIELD(this, f64 *, 0xE0);
    sp8 = this->unkD8;
    temp_f1_567 = (*(f32 *) ((u8 *) &sp8 + 0x4));
    sp10 = temp_f2_565;
    (*(f32 *) ((u8 *) &sp8 + 0x4)) = temp_f1_567 - 6600.0f;
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

#if 0 // DRAFT: undefined identifier 'MKVector'
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
    f64 sp98;
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
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_764;
    f64 temp_f0_757;
    f64 temp_f1_750;
    s32 temp_r0_674;
    void *temp_r3_749;

    ((KDSoundPlayer *) &this->unk104)->Message(arg0);
    ((KDSoundPlayer *) &this->unk12C)->Message(arg0);
    if ((s32) arg0->unk0 != 0xB5) {

    } else {
        spBC = 0;
        sp88 = this->unkD8;
        sp90 = M2C_FIELD(this, f64 *, 0xE0);
        MKVector(0.7f, 0.7f, 0.7f);
        sp28 = sp98 * 5.398241246e-315;
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
            KDSound_Play3d(GS_DragonStatueStart, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
        } else if (temp_r0_674 == 1) {
            this->unk100 = 2;
            this->unk98.Send(NULL);
            KDSound_Play3d(GS_DragonStatueStart, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
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
            temp_f1_750 = M2C_FIELD(temp_r3_749, f64 *, 0x30);
            sp48 = temp_f1_750;
            sp50 = M2C_FIELD(temp_r3_749, f64 *, 0x38);
            temp_f0_757 = temp_f1_750 + (f64) M2C_FIELD(this, f32 *, 0xA8);
            sp38 = temp_f0_757;
            temp_f1_764 = (f32) sp50 + this->unkB0;
            sp58 = temp_f0_757;
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

void DragonStatue::Deinit() {
    KDProp::Deinit();
    KDSound_Stop((int *) &this->unk104);
    KDSound_Stop((int *) &this->unk12C);
}

void DragonStatue::Draw() {
    if ((s32) this->unk100 != 1) {
        KDProp::Draw();
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void DragonStatue::Update() {
    Matrix sp330;
    Matrix sp2F0;
    Matrix sp2B0;
    M2C_UNK sp2AC;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    MKCollisionInfo sp128;
    MKCollisionInfo sp118;
    f32 sp110;
    f64 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    Frustum *temp_r31_1928;
    f32 temp_f0_1002;
    f32 temp_f0_1404;
    f32 temp_f0_1408;
    f32 temp_f0_1476;
    f32 temp_f0_1931;
    f32 temp_f0_2037;
    f32 temp_f0_930;
    f32 temp_f0_934;
    f32 temp_f1_1001;
    f32 temp_f1_1387;
    f32 temp_f1_1406;
    f32 temp_f1_1466;
    f32 temp_f1_1475;
    f32 temp_f1_1812;
    f32 temp_f1_1930;
    f32 temp_f1_2036;
    f32 temp_f1_915;
    f32 temp_f1_932;
    f32 temp_f1_992;
    f32 temp_f2_1405;
    f32 temp_f2_1811;
    f32 temp_f2_931;
    f32 temp_f3_1933;
    f32 temp_f3_2039;
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
    f64 temp_f0_1380;
    f64 temp_f0_1426;
    f64 temp_f0_1459;
    f64 temp_f0_1731;
    f64 temp_f0_2023;
    f64 temp_f0_952;
    f64 temp_f0_985;
    f64 temp_f1_1046;
    f64 temp_f1_1077;
    f64 temp_f1_1083;
    f64 temp_f1_1087;
    f64 temp_f1_1174;
    f64 temp_f1_1180;
    f64 temp_f1_1184;
    f64 temp_f1_1277;
    f64 temp_f1_1283;
    f64 temp_f1_1287;
    f64 temp_f1_1373;
    f64 temp_f1_1452;
    f64 temp_f1_1520;
    f64 temp_f1_1551;
    f64 temp_f1_1557;
    f64 temp_f1_1561;
    f64 temp_f1_1648;
    f64 temp_f1_1654;
    f64 temp_f1_1658;
    f64 temp_f1_1941;
    f64 temp_f1_1947;
    f64 temp_f1_1951;
    f64 temp_f1_2013;
    f64 temp_f1_978;
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

    sp8 = 1;
    var_r6_846 = 0;
    temp_r0_847 = this->unk100;
    if ((temp_r0_847 == 3) || (temp_r0_847 == 2)) {
        var_r6_846 = 1;
    }
    ((KDSoundFader *) &this->unk104)->Update(GS_DragonStatueRumble, 1U, var_r6_846, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    sp8 = 1;
    var_r6_865 = 0;
    temp_r0_866 = this->unk100;
    if ((temp_r0_866 == 3) || (temp_r0_866 == 2)) {
        var_r6_865 = 1;
    }
    ((KDSoundFader *) &this->unk12C)->Update(GS_DragonStatueFall, 1U, var_r6_865, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_r0_880 = this->unk100;
    if ((temp_r0_880 == 3) || (temp_r0_880 == 2)) {
        if (this->unk154 < 2.0f) {
            if (temp_r0_880 == 3) {
                var_f30_892 = 100.0f;
            } else {
                var_f30_892 = 50.0f;
            }
            ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.5f, 0.05f, 0.05f, ((u8 *) this->unk8) + 0x30, var_f30_892, 0, 4.0f, 0U);
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
            temp_f0_952 = M2C_FIELD(this, f64 *, 0xC8) * (f64) gUpdateTimeDelta;
            sp58 = temp_f0_952;
            sp258 = temp_f0_952;
            sp60 = this->unkD0 * gUpdateTimeDelta;
            sp260 = (f64) sp60;
            M2C_FIELD(this, f32 *, 0xA8) = (f64) ((f64) M2C_FIELD(this, f32 *, 0xA8) + temp_f0_952);
            this->unkB0 += (f32) sp260;
        } else {
            M2C_FIELD(this, f32 *, 0xA8) = (f64) M2C_FIELD(this, f32 *, 0xB8);
            M2C_FIELD(this, f32 *, 0xB0) = (f64) M2C_FIELD(this, f32 *, 0xC0);
        }
        temp_r3_977 = this->unk8;
        temp_f1_978 = M2C_FIELD(temp_r3_977, f64 *, 0x30);
        sp238 = temp_f1_978;
        sp240 = M2C_FIELD(temp_r3_977, f64 *, 0x38);
        temp_f0_985 = temp_f1_978 + (f64) M2C_FIELD(this, f32 *, 0xA8);
        sp108 = temp_f0_985;
        temp_f1_992 = (f32) sp240 + this->unkB0;
        sp248 = temp_f0_985;
        sp110 = temp_f1_992;
        sp250 = (f64) sp110;
        SetPos(sp248, temp_f1_992, (f32) sp240);
        temp_f1_1001 = this->unkEC;
        temp_f0_1002 = this->unkE8;
        if (temp_f1_1001 < temp_f0_1002) {
            this->unkEC = temp_f1_1001 + this->unkF0;
        } else {
            this->unkEC = temp_f0_1002;
        }
        this->unkF4 += this->unkEC * gUpdateTimeDelta;
        M2C_STRUCT_COPY((s32) &sp2F0.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        sp330.SetRotateAroundAxis(MKVector3::up, this->unkF4);
        MKModel_SetWorldMatrix(this->unk4, sp330);
        temp_r4_1044 = this->unk8;
        temp_r3_1045 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
        temp_f1_1046 = M2C_FIELD(temp_r4_1044, f64 *, 0x30);
        temp_f3_1047 = M2C_FIELD(temp_r3_1045, f64 *, 0x30);
        temp_f2_1048 = M2C_FIELD(temp_r3_1045, f64 *, 0x38);
        sp288 = temp_f1_1046;
        sp298 = temp_f3_1047;
        sp2A0 = temp_f2_1048;
        sp290 = M2C_FIELD(temp_r4_1044, f64 *, 0x38);
        spF8 = temp_f1_1046 - this->unkD8;
        sp228 = spF8;
        sp100 = (f32) sp290 - this->unkE0;
        sp230 = (f64) sp100;
        var_f4_1074 = ((f32) sp230 * (f32) sp230) + (((f32) sp228 * (f32) sp228) + ((*(f32 *) ((u8 *) &sp228 + 0x4)) * (*(f32 *) ((u8 *) &sp228 + 0x4))));
        if (var_f4_1074 > 0.0f) {
            temp_f1_1077 = __frsqrte(var_f4_1074);
            temp_f1_1083 = 0.5 * temp_f1_1077 * -(((f64) var_f4_1074 * (temp_f1_1077 * temp_f1_1077)) - 3.0);
            temp_f1_1087 = 0.5 * temp_f1_1083 * -(((f64) var_f4_1074 * (temp_f1_1083 * temp_f1_1083)) - 3.0);
            var_f4_1074 = (f32) ((f64) var_f4_1074 * (0.5 * temp_f1_1087 * -(((f64) var_f4_1074 * (temp_f1_1087 * temp_f1_1087)) - 3.0)));
        } else if (var_f4_1074 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1074 = __float_nan;
        } else {
            sp30 = var_f4_1074;
            temp_r3_1106 = M2C_BITWISE(s32, sp30) & 0x7F800000;
            switch (temp_r3_1106) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp30) & 0x7FFFFF) {
                    var_r0_1116 = 1;
                } else {
                    var_r0_1116 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp30) & 0x7FFFFF) {
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
        (*(f32 *) ((u8 *) &sp288 + 0x4)) = (*(f32 *) ((u8 *) &sp298 + 0x4));
        if (gb.unk30C >= this->unkA0) {
            spE8 = sp288 - sp298;
            sp218 = spE8;
            spF0 = (f32) sp290 - (f32) sp2A0;
            sp220 = (f64) spF0;
            var_f4_1171 = ((f32) sp220 * (f32) sp220) + (((f32) sp218 * (f32) sp218) + ((*(f32 *) ((u8 *) &sp218 + 0x4)) * (*(f32 *) ((u8 *) &sp218 + 0x4))));
            if (var_f4_1171 > 0.0f) {
                temp_f1_1174 = __frsqrte(var_f4_1171);
                temp_f1_1180 = 0.5 * temp_f1_1174 * -(((f64) var_f4_1171 * (temp_f1_1174 * temp_f1_1174)) - 3.0);
                temp_f1_1184 = 0.5 * temp_f1_1180 * -(((f64) var_f4_1171 * (temp_f1_1180 * temp_f1_1180)) - 3.0);
                var_f4_1171 = (f32) ((f64) var_f4_1171 * (0.5 * temp_f1_1184 * -(((f64) var_f4_1171 * (temp_f1_1184 * temp_f1_1184)) - 3.0)));
            } else if (var_f4_1171 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1171 = __float_nan;
            } else {
                sp2C = var_f4_1171;
                temp_r3_1203 = M2C_BITWISE(s32, sp2C) & 0x7F800000;
                switch (temp_r3_1203) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp2C) & 0x7FFFFF) {
                        var_r0_1213 = 1;
                    } else {
                        var_r0_1213 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp2C) & 0x7FFFFF) {
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
        sp1F8 = M2C_FIELD(temp_r3_1249, f64 *, 0x30);
        sp200 = M2C_FIELD(temp_r3_1249, f64 *, 0x38);
        spD8 = this->unkD8 - sp1F8;
        sp208 = spD8;
        spE0 = this->unkE0 - (f32) sp200;
        sp210 = (f64) spE0;
        var_f4_1274 = ((f32) sp210 * (f32) sp210) + (((f32) sp208 * (f32) sp208) + ((*(f32 *) ((u8 *) &sp208 + 0x4)) * (*(f32 *) ((u8 *) &sp208 + 0x4))));
        if (var_f4_1274 > 0.0f) {
            temp_f1_1277 = __frsqrte(var_f4_1274);
            temp_f1_1283 = 0.5 * temp_f1_1277 * -(((f64) var_f4_1274 * (temp_f1_1277 * temp_f1_1277)) - 3.0);
            temp_f1_1287 = 0.5 * temp_f1_1283 * -(((f64) var_f4_1274 * (temp_f1_1283 * temp_f1_1283)) - 3.0);
            var_f4_1274 = (f32) ((f64) var_f4_1274 * (0.5 * temp_f1_1287 * -(((f64) var_f4_1274 * (temp_f1_1287 * temp_f1_1287)) - 3.0)));
        } else if (var_f4_1274 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1274 = __float_nan;
        } else {
            sp28 = var_f4_1274;
            temp_r3_1306 = M2C_BITWISE(s32, sp28) & 0x7F800000;
            switch (temp_r3_1306) {                 /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, sp28) & 0x7FFFFF) {
                    var_r0_1316 = 1;
                } else {
                    var_r0_1316 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, sp28) & 0x7FFFFF) {
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
        if (var_f4_1274 >= 4600.0f) {
            sp40 = 0;
            sp3C = 0x41A;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp3C);
            this->unk100 = 1;
            this->unk94.Send(NULL);
            KDSound_Play3d(GS_DragonStatueEnd, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
            this->unk154 = 0.0f;
            this->unkA8 = 0.0f;
            this->unkAC = -2000.0f;
            this->unkB0 = 0.0f;
            temp_r3_1372 = this->unk8;
            temp_f1_1373 = M2C_FIELD(temp_r3_1372, f64 *, 0x30);
            sp1D8 = temp_f1_1373;
            sp1E0 = M2C_FIELD(temp_r3_1372, f64 *, 0x38);
            temp_f0_1380 = temp_f1_1373 + (f64) M2C_FIELD(this, f32 *, 0xA8);
            spC8 = temp_f0_1380;
            temp_f1_1387 = (f32) sp1E0 + this->unkB0;
            sp1E8 = temp_f0_1380;
            spD0 = temp_f1_1387;
            sp1F0 = (f64) spD0;
            SetPos(sp1E8, temp_f1_1387, (f32) sp1E0);
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
            temp_f0_1426 = M2C_FIELD(this, f64 *, 0xC8) * (f64) gUpdateTimeDelta;
            sp48 = temp_f0_1426;
            sp1C8 = temp_f0_1426;
            sp50 = this->unkD0 * gUpdateTimeDelta;
            sp1D0 = (f64) sp50;
            M2C_FIELD(this, f32 *, 0xA8) = (f64) ((f64) M2C_FIELD(this, f32 *, 0xA8) + temp_f0_1426);
            this->unkB0 += (f32) sp1D0;
        } else {
            M2C_FIELD(this, f32 *, 0xA8) = (f64) M2C_FIELD(this, f32 *, 0xB8);
            M2C_FIELD(this, f32 *, 0xB0) = (f64) M2C_FIELD(this, f32 *, 0xC0);
        }
        temp_r3_1451 = this->unk8;
        temp_f1_1452 = M2C_FIELD(temp_r3_1451, f64 *, 0x30);
        sp1A8 = temp_f1_1452;
        sp1B0 = M2C_FIELD(temp_r3_1451, f64 *, 0x38);
        temp_f0_1459 = temp_f1_1452 + (f64) M2C_FIELD(this, f32 *, 0xA8);
        spB8 = temp_f0_1459;
        temp_f1_1466 = (f32) sp1B0 + this->unkB0;
        sp1B8 = temp_f0_1459;
        spC0 = temp_f1_1466;
        sp1C0 = (f64) spC0;
        SetPos(sp1B8, temp_f1_1466, (f32) sp1B0);
        temp_f1_1475 = this->unkEC;
        temp_f0_1476 = this->unkE8;
        if (temp_f1_1475 > temp_f0_1476) {
            this->unkEC = temp_f1_1475 + this->unkF0;
        } else {
            this->unkEC = temp_f0_1476;
        }
        this->unkF4 += this->unkEC * gUpdateTimeDelta;
        M2C_STRUCT_COPY((s32) &sp2B0.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        sp2F0.SetRotateAroundAxis(MKVector3::up, this->unkF4);
        MKModel_SetWorldMatrix(this->unk4, sp2F0);
        temp_r4_1518 = this->unk8;
        temp_r3_1519 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
        temp_f1_1520 = M2C_FIELD(temp_r4_1518, f64 *, 0x30);
        temp_f3_1521 = M2C_FIELD(temp_r3_1519, f64 *, 0x30);
        temp_f2_1522 = M2C_FIELD(temp_r3_1519, f64 *, 0x38);
        sp268 = temp_f1_1520;
        sp278 = temp_f3_1521;
        sp280 = temp_f2_1522;
        sp270 = M2C_FIELD(temp_r4_1518, f64 *, 0x38);
        spA8 = temp_f1_1520 - this->unkD8;
        sp198 = spA8;
        spB0 = (f32) sp270 - this->unkE0;
        sp1A0 = (f64) spB0;
        var_f4_1548 = ((f32) sp1A0 * (f32) sp1A0) + (((f32) sp198 * (f32) sp198) + ((*(f32 *) ((u8 *) &sp198 + 0x4)) * (*(f32 *) ((u8 *) &sp198 + 0x4))));
        if (var_f4_1548 > 0.0f) {
            temp_f1_1551 = __frsqrte(var_f4_1548);
            temp_f1_1557 = 0.5 * temp_f1_1551 * -(((f64) var_f4_1548 * (temp_f1_1551 * temp_f1_1551)) - 3.0);
            temp_f1_1561 = 0.5 * temp_f1_1557 * -(((f64) var_f4_1548 * (temp_f1_1557 * temp_f1_1557)) - 3.0);
            var_f4_1548 = (f32) ((f64) var_f4_1548 * (0.5 * temp_f1_1561 * -(((f64) var_f4_1548 * (temp_f1_1561 * temp_f1_1561)) - 3.0)));
        } else if (var_f4_1548 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1548 = __float_nan;
        } else {
            sp24 = var_f4_1548;
            temp_r3_1580 = M2C_BITWISE(s32, sp24) & 0x7F800000;
            switch (temp_r3_1580) {                 /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, sp24) & 0x7FFFFF) {
                    var_r0_1590 = 1;
                } else {
                    var_r0_1590 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, sp24) & 0x7FFFFF) {
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
        (*(f32 *) ((u8 *) &sp268 + 0x4)) = (*(f32 *) ((u8 *) &sp278 + 0x4));
        if (gb.unk30C >= this->unkA0) {
            sp98 = sp268 - sp278;
            sp188 = sp98;
            spA0 = (f32) sp270 - (f32) sp280;
            sp190 = (f64) spA0;
            var_f4_1645 = ((f32) sp190 * (f32) sp190) + (((f32) sp188 * (f32) sp188) + ((*(f32 *) ((u8 *) &sp188 + 0x4)) * (*(f32 *) ((u8 *) &sp188 + 0x4))));
            if (var_f4_1645 > 0.0f) {
                temp_f1_1648 = __frsqrte(var_f4_1645);
                temp_f1_1654 = 0.5 * temp_f1_1648 * -(((f64) var_f4_1645 * (temp_f1_1648 * temp_f1_1648)) - 3.0);
                temp_f1_1658 = 0.5 * temp_f1_1654 * -(((f64) var_f4_1645 * (temp_f1_1654 * temp_f1_1654)) - 3.0);
                var_f4_1645 = (f32) ((f64) var_f4_1645 * (0.5 * temp_f1_1658 * -(((f64) var_f4_1645 * (temp_f1_1658 * temp_f1_1658)) - 3.0)));
            } else if (var_f4_1645 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1645 = __float_nan;
            } else {
                sp20 = var_f4_1645;
                temp_r3_1677 = M2C_BITWISE(s32, sp20) & 0x7F800000;
                switch (temp_r3_1677) {             /* switch 5; irregular */
                case 0x7F800000:                    /* switch 5 */
                    if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
                        var_r0_1687 = 1;
                    } else {
                        var_r0_1687 = 2;
                    }
                    break;
                case 0x0:                           /* switch 5 */
                    if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
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
        sp168 = M2C_FIELD(temp_r3_1723, f64 *, 0x30);
        sp170 = M2C_FIELD(temp_r3_1723, f64 *, 0x38);
        temp_f0_1731 = this->unkD8 - sp168;
        sp88 = temp_f0_1731;
        sp178 = temp_f0_1731;
        sp90 = this->unkE0 - (f32) sp170;
        sp180 = (f64) sp90;
        var_f0_1748 = ((f32) sp180 * (f32) sp180) + (((f32) sp178 * (f32) sp178) + ((*(f32 *) ((u8 *) &sp178 + 0x4)) * (*(f32 *) ((u8 *) &sp178 + 0x4))));
        if (var_f0_1748 > 0.0f) {
            temp_f2_1751 = __frsqrte(var_f0_1748);
            temp_f2_1757 = 0.5 * temp_f2_1751 * -(((f64) var_f0_1748 * (temp_f2_1751 * temp_f2_1751)) - 3.0);
            temp_f2_1761 = 0.5 * temp_f2_1757 * -(((f64) var_f0_1748 * (temp_f2_1757 * temp_f2_1757)) - 3.0);
            var_f0_1748 = (f32) ((f64) var_f0_1748 * (0.5 * temp_f2_1761 * -(((f64) var_f0_1748 * (temp_f2_1761 * temp_f2_1761)) - 3.0)));
        } else if (var_f0_1748 < M2C_BITWISE(f32, 0.0)) {
            var_f0_1748 = __float_nan;
        } else {
            sp1C = var_f0_1748;
            temp_r3_1780 = M2C_BITWISE(s32, sp1C) & 0x7F800000;
            switch (temp_r3_1780) {                 /* switch 6; irregular */
            case 0x7F800000:                        /* switch 6 */
                if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                    var_r0_1790 = 1;
                } else {
                    var_r0_1790 = 2;
                }
                break;
            case 0x0:                               /* switch 6 */
                if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
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
            sp18 = var_f5_1819;
            temp_r3_1851 = M2C_BITWISE(s32, sp18) & 0x7F800000;
            switch (temp_r3_1851) {                 /* switch 7; irregular */
            case 0x7F800000:                        /* switch 7 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                    var_r0_1861 = 1;
                } else {
                    var_r0_1861 = 2;
                }
                break;
            case 0x0:                               /* switch 7 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
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
        if (var_f0_1748 <= var_f5_1819) {
            SetPos(this->unkD8);
            sp38 = 0;
            sp34 = 0x41A;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp34);
            this->unk100 = 0;
            this->unk9C.Send(NULL);
            KDSound_Play3d(GS_DragonStatueEnd, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
            this->unk154 = 0.0f;
            this->unkA8 = 0.0f;
            this->unkAC = 0.0f;
            this->unkB0 = 0.0f;
        }
    } else {
        temp_r31_1928 = M2C_FIELD(&gb, void **, 0x3B8) + 0xB0;
        sp128.GetRadius();
        temp_f1_1930 = M2C_BITWISE(f32, sp128);
        temp_f0_1931 = M2C_BITWISE(f32, sp128.unk4);
        temp_f3_1933 = M2C_BITWISE(f32, sp128.unk8);
        temp_f4_1938 = (temp_f3_1933 * temp_f3_1933) + ((temp_f1_1930 * temp_f1_1930) + (temp_f0_1931 * temp_f0_1931));
        if (temp_f4_1938 > 0.0f) {
            temp_f1_1941 = __frsqrte(temp_f4_1938);
            temp_f1_1947 = 0.5 * temp_f1_1941 * -(((f64) temp_f4_1938 * (temp_f1_1941 * temp_f1_1941)) - 3.0);
            temp_f1_1951 = 0.5 * temp_f1_1947 * -(((f64) temp_f4_1938 * (temp_f1_1947 * temp_f1_1947)) - 3.0);
            var_f31_1957 = (f32) ((f64) temp_f4_1938 * (0.5 * temp_f1_1951 * -(((f64) temp_f4_1938 * (temp_f1_1951 * temp_f1_1951)) - 3.0)));
        } else if (temp_f4_1938 < M2C_BITWISE(f32, 0.0)) {
            var_f31_1957 = __float_nan;
        } else {
            sp14 = temp_f4_1938;
            temp_r3_1970 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_1970) {                 /* switch 8; irregular */
            case 0x7F800000:                        /* switch 8 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_1980 = 1;
                } else {
                    var_r0_1980 = 2;
                }
                break;
            case 0x0:                               /* switch 8 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
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
        sp78 = M2C_FIELD(&MKVector3::up, f64 *, 0) * (f64) var_f31_1957;
        temp_r3_2010 = this->unk8;
        temp_f1_2013 = M2C_FIELD(temp_r3_2010, f64 *, 0x30);
        sp80 = MKVector3::up.unk8 * var_f31_1957;
        sp138 = sp78;
        sp148 = temp_f1_2013;
        sp140 = (f64) sp80;
        sp150 = M2C_FIELD(temp_r3_2010, f64 *, 0x38);
        temp_f0_2023 = temp_f1_2013 + sp138;
        sp68 = temp_f0_2023;
        sp158 = temp_f0_2023;
        sp70 = (f32) sp150 + (f32) sp140;
        sp160 = (f64) sp70;
        sp118.GetRadius();
        temp_f1_2036 = M2C_BITWISE(f32, sp118);
        temp_f0_2037 = M2C_BITWISE(f32, sp118.unk4);
        temp_f3_2039 = M2C_BITWISE(f32, sp118.unk8);
        var_f1_2044 = (temp_f3_2039 * temp_f3_2039) + ((temp_f1_2036 * temp_f1_2036) + (temp_f0_2037 * temp_f0_2037));
        if (var_f1_2044 > 0.0f) {
            temp_f2_2047 = __frsqrte(var_f1_2044);
            temp_f2_2053 = 0.5 * temp_f2_2047 * -(((f64) var_f1_2044 * (temp_f2_2047 * temp_f2_2047)) - 3.0);
            temp_f2_2057 = 0.5 * temp_f2_2053 * -(((f64) var_f1_2044 * (temp_f2_2053 * temp_f2_2053)) - 3.0);
            var_f1_2044 = (f32) ((f64) var_f1_2044 * (0.5 * temp_f2_2057 * -(((f64) var_f1_2044 * (temp_f2_2057 * temp_f2_2057)) - 3.0)));
        } else if (var_f1_2044 < M2C_BITWISE(f32, 0.0)) {
            var_f1_2044 = __float_nan;
        } else {
            sp10 = var_f1_2044;
            temp_r3_2076 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_2076) {                 /* switch 9; irregular */
            case 0x7F800000:                        /* switch 9 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_2086 = 1;
                } else {
                    var_r0_2086 = 2;
                }
                break;
            case 0x0:                               /* switch 9 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
        if (temp_r31_1928->IsVisible(*((MKVector3 *) &sp158), var_f1_2044) == 0) {
            M2C_STRUCT_COPY((s32) &sp2AC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
            sp2B0.SetRotateAroundAxis(MKVector3::up, 0.0f);
            MKModel_SetWorldMatrix(this->unk4, sp2B0);
        }
    }
    KDProp::Update();
}
#endif

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
    if (arg0->LoadInt("AmountOfCrud", (int *) &this->unkF8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("AmountOfDust", (int *) &this->unkFC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("AngularSpeed", &this->unkE8, 0) != 0) {
        return 1U;
    }
    return (u8) (arg0->LoadFloat("AngularAcceleration", &this->unkF0, 0) != 0);
}

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

void DragonStatue::Init() {
    KDProp::Init();
    this->unkD8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xE0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0xB8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0xA8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xB0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkE8 = 0.0f;
    this->unkEC = 0.0f;
    this->unkF0 = 0.0f;
    this->unkF4 = 0.0f;
    this->unkF8 = 0;
    this->unkFC = 0;
    this->unk100 = 0;
    ((KDSoundFader *) &this->unk104)->Init(0.25f, 0.25f);
    ((KDSoundFader *) &this->unk12C)->Init(0.25f, 0.25f);
    this->unk154 = 0.0f;
}
