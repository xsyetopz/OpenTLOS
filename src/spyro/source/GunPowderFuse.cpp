#include "spyro/source/GunPowderFuse.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
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
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "common/gc/System_GC.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/BurnPoint.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/ClusterBomb.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FireBombFX.h"
#include "spyro/source/FlyingBurningBits.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/LiquidFX.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/ShapedTrailFX.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SparksPS.h"
#include "spyro/source/SplineProp.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/Tools.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

M2C_UNK __destroy_arr(u8 *, BurnPoint *(*)(BurnPoint *, s16), M2C_UNK, M2C_UNK); /* extern */
s32 stricmp(s32, M2C_UNK *);                        /* extern */
extern s32 GS_GunpowderBurnLP;
extern f32 *KDSpline_PositionMixer;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
static s32 lit_743 = 2;
static u8 lit_744 = 0;

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to 'double'
void GunPowderFuse::EmitBurn(float arg0) {
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f32 spEC;
    KDUniformSpline spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    f64 spB0;
    f64 spA8;
    MKVector3 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f28_141;
    f32 temp_f29_135;
    f32 temp_f29_88;
    f32 temp_f2_128;
    f32 temp_f2_140;
    f32 temp_f2_198;
    f32 temp_f31_170;
    f32 temp_f3_105;
    f32 temp_f3_116;
    f64 temp_f0_174;
    f64 temp_f0_185;

    sp8 = 0.0f;
    spD8.GetMeasure(arg0, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
    spF8 = M2C_BITWISE(f64, spD8);
    sp100 = (f64) spD8.unk8;
    temp_f29_88 = 100.0f * (this->unkB4 / 20.0f);
    spB8 = KDRand_UnitVectorXZ();
    sp28 = spB8 * (f64) temp_f29_88;
    spD8.unk10 = sp28;
    sp30 = spB8.unk8 * temp_f29_88;
    spC8 = sp28;
    spF0 = (f64) sp30;
    temp_f3_105 = this->unkB4;
    spD0 = (f64) sp30;
    spEC = 100.0f * MKRand_Float((int *) &gViewSeed, temp_f3_105 / 10.0f, temp_f3_105 / 3.3333f);
    temp_f3_116 = this->unkB4;
    sp10 = MKRand_Float((int *) &gViewSeed, temp_f3_116 / 40.0f, temp_f3_116 / 20.0f);
    gb.EmitDust(*((MKVector3 *) &spF8), *((MKVector3 *) &spD8.unk10), sp10, 0.0f);
    temp_f2_128 = this->unkB4;
    temp_f29_135 = MKRand_Float((int *) &gViewSeed, -temp_f2_128 / 10.0f, temp_f2_128 / 10.0f);
    temp_f2_140 = this->unkB4;
    temp_f28_141 = MKRand_Float((int *) &gViewSeed, 0.0f, this->unkB4);
    sp88 = MKVector(MKRand_Float((int *) &gViewSeed, -temp_f2_140 / 10.0f, temp_f2_140 / 10.0f), temp_f28_141, temp_f29_135);
    sp98 = Normalise(sp88);
    sp18 = sp98 * 5.634608575e-315;
    spD8.unk10 = sp18;
    sp20 = sp98.unk8 * 500.0f;
    spA8 = sp18;
    spF0 = (f64) sp20;
    spB0 = (f64) sp20;
    temp_f31_170 = this->unkB4;
    sp58 = KDRand_UnitVectorXZ();
    temp_f0_174 = sp58 * (f64) temp_f31_170;
    sp48 = temp_f0_174;
    sp68 = temp_f0_174;
    sp50 = sp58.unk8 * temp_f31_170;
    sp70 = (f64) sp50;
    temp_f0_185 = spF8 + temp_f0_174;
    sp38 = temp_f0_185;
    sp78 = temp_f0_185;
    sp40 = (f32) sp100 + (f32) sp70;
    sp80 = (f64) sp40;
    temp_f2_198 = this->unkB4;
    spC = MKRand_Float((int *) &gViewSeed, temp_f2_198 / 6.6666f, temp_f2_198 / 3.3333f);
    ((SparksPS *) gb.unk84)->Emit(*((MKVector3 *) &sp78), *((MKVector3 *) &spD8.unk10), spC);
}
#endif

BurnPoint *GunPowderFuse::GetFirst() {
    s32 i;
    u8 *p;
    f32 f;
    f32 a;
    f32 best;
    s32 bestIdx;

    best = 1.0f;
    bestIdx = -1;
    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        f = M2C_FIELD(p, f32 *, 0xCC);
        if ((f <= 1.0f) && (f >= 0.0f)) {
            if (f < 0.0f) {
                a = -f;
            } else {
                a = f;
            }
            if (a < best) {
                best = f;
                bestIdx = i;
            }
        }
    }
    if (bestIdx != -1) {
        return (BurnPoint *) ((u8 *) this + (bestIdx * 0x3C) + 0xC4);
    }
    return NULL;
}

BurnPoint *GunPowderFuse::GetNextPositive(BurnPoint *arg0) {
    s32 i;
    s32 idx;
    s32 best;
    u8 *p;
    f32 lo;
    f32 f;
    f32 diff;
    f32 a;
    f32 bestAbs;

    if (arg0 != NULL) {
        lo = M2C_FIELD(arg0, f32 *, 0x8);
    } else {
        lo = 0.0f;
    }
    bestAbs = 1.0f;
    best = -1;
    idx = 0;
    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C, idx++) {
        f = M2C_FIELD(p, f32 *, 0xCC);
        if ((f <= 1.0f) && (f >= 0.0f) && (M2C_FIELD(p, f32 *, 0xD0) == 1.0f) && (f > lo)) {
            diff = f - M2C_FIELD(arg0, f32 *, 0x8);
            if (diff < 0.0f) {
                a = -diff;
            } else {
                a = diff;
            }
            if ((a < bestAbs) && ((BurnPoint *) (p + 0xC4) != arg0)) {
                bestAbs = a;
                best = idx;
            }
        }
    }
    if (best != -1) {
        return (BurnPoint *) (((u8 *) this) + (best * 0x3C) + 0xC4);
    }
    return NULL;
}

void GunPowderFuse::UpdatePartners() {
    s32 i;
    u8 *p;
    f32 f;

    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        f = M2C_FIELD(p, f32 *, 0xCC);
        if ((f <= 1.0f) && (f >= 0.0f)) {
            M2C_FIELD(p, s32 *, 0xD4) = GetPartner((BurnPoint *) (p + 0xC4));
        }
    }
}

s32 GunPowderFuse::GetPartner(BurnPoint *arg0) {
    s32 i;
    s32 idx;
    s32 best;
    u8 *p;
    f32 f;
    f32 diff;
    f32 a;
    f32 bestAbs;

    bestAbs = 1.0f;
    if (M2C_FIELD(arg0, f32 *, 0xC) == 1.0f) {
        best = 0x64;
        idx = 0;
        p = (u8 *) this;
        for (i = 0; i < 8; i++, p += 0x3C, idx++) {
            f = M2C_FIELD(p, f32 *, 0xCC);
            if ((f <= 1.0f) && (f >= 0.0f) && (M2C_FIELD(p, f32 *, 0xD0) == -1.0f)) {
                if (f > M2C_FIELD(arg0, f32 *, 0x8)) {
                    diff = f - M2C_FIELD(arg0, f32 *, 0x8);
                    if (diff < 0.0f) {
                        a = -diff;
                    } else {
                        a = diff;
                    }
                    if ((a < bestAbs) && ((BurnPoint *) (p + 0xC4) != arg0)) {
                        bestAbs = a;
                        best = idx;
                    }
                }
            }
        }
    } else {
        best = -0x64;
        idx = 0;
        p = (u8 *) this;
        for (i = 0; i < 8; i++, p += 0x3C, idx++) {
            f = M2C_FIELD(p, f32 *, 0xCC);
            if ((f <= 1.0f) && (f >= 0.0f) && (M2C_FIELD(p, f32 *, 0xD0) == 1.0f)) {
                if (f < M2C_FIELD(arg0, f32 *, 0x8)) {
                    diff = f - M2C_FIELD(arg0, f32 *, 0x8);
                    if (diff < 0.0f) {
                        a = -diff;
                    } else {
                        a = diff;
                    }
                    if ((a < bestAbs) && ((BurnPoint *) (p + 0xC4) != arg0)) {
                        bestAbs = a;
                        best = idx;
                    }
                }
            }
        }
    }
    return best;
}

u8 GunPowderFuse::IsBurnable(float arg0) {
    BurnPoint *bp;

    if (IsBurntOut() != 0) {
        return 0;
    }
    bp = GetFirst();
    if (bp == NULL) {
        return 1;
    }
    while (bp != NULL) {
        if (M2C_FIELD(bp, f32 *, 0xC) == 1.0f) {
            if (arg0 > M2C_FIELD(bp, f32 *, 0x8)) {
                s32 t = M2C_FIELD(bp, s32 *, 0x10);
                if (t == 100) {
                    if (arg0 < 1.0f) {
                        return 1;
                    }
                } else if (arg0 < M2C_FIELD(this, f32 *, (t * 0x3C) + 0xCC)) {
                    return 1;
                }
                bp = GetNextPositive(bp);
            } else {
                return 0;
            }
        } else {
            if ((arg0 > 0.0f) && (arg0 < M2C_FIELD(bp, f32 *, 0x8))) {
                return 1;
            }
            bp = GetNextPositive(bp);
        }
    }
    return 0;
}

u8 GunPowderFuse::TooClose(float arg0) {
    s32 i;
    u8 *p;
    f32 f;
    f32 d;

    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        f = M2C_FIELD(p, f32 *, 0xCC);
        if ((f <= 1.0f) && (f >= 0.0f)) {
            d = f - arg0;
            if (d < 0.0f) {
                d = -d;
            }
            if (d < (2.0f * this->unk2A8)) {
                return 1;
            }
        }
    }
    return 0;
}

u8 GunPowderFuse::HasAvailableBurnPoints() {
    s32 i;
    s32 n;
    u8 *p;
    f32 f;

    n = 0;
    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        f = M2C_FIELD(p, f32 *, 0xCC);
        if (!(f <= 1.0f) || !(f >= 0.0f)) {
            n += 1;
        }
        if (n == 2) {
            return 1;
        }
    }
    return 0;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
void GunPowderFuse::Draw() {
    Matrix sp350;
    M2C_UNK sp34C;
    f32 sp340;
    f32 sp33C;
    f32 sp338;
    f64 sp330;
    KDSplinePathSegment sp2E8;
    MKVector3 sp2D8;
    MKVector3 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
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
    f64 sp238;
    MKVector3 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp208;
    MKVector3 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1D8;
    MKVector3 sp1C8;
    MKVector3 sp1B8;
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
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f64 sp128;
    f32 sp120;
    f64 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    BurnPoint *var_r28_1093;
    f32 temp_f0_1397;
    f32 temp_f0_891;
    f32 temp_f18_1504;
    f32 temp_f18_762;
    f32 temp_f18_998;
    f32 temp_f1_789;
    f32 temp_f1_890;
    f32 temp_f20_748;
    f32 temp_f21_746;
    f32 temp_f22_744;
    f32 temp_f24_1094;
    f32 temp_f25_1096;
    f32 temp_f26_1007;
    f32 temp_f26_1097;
    f32 temp_f27_1049;
    f32 temp_f29_720;
    f32 temp_f2_1296;
    f32 temp_f2_790;
    f32 temp_f30_1555;
    f32 temp_f31_1513;
    f32 temp_f3_1379;
    f32 temp_f3_873;
    f32 temp_f4_1377;
    f32 temp_f4_871;
    f32 temp_f5_1380;
    f32 temp_f5_874;
    f32 var_f1_1132;
    f32 var_f1_1275;
    f32 var_f27_1111;
    f32 var_f28_1106;
    f32 var_f2_1129;
    f32 var_f2_1370;
    f32 var_f2_1473;
    f32 var_f2_864;
    f32 var_f2_967;
    f32 var_f4_1303;
    f32 var_f4_1406;
    f32 var_f4_797;
    f32 var_f4_900;
    f64 temp_f0_1009;
    f64 temp_f0_1020;
    f64 temp_f0_1051;
    f64 temp_f0_1062;
    f64 temp_f0_1515;
    f64 temp_f0_1526;
    f64 temp_f0_1557;
    f64 temp_f0_1568;
    f64 temp_f1_1309;
    f64 temp_f1_1315;
    f64 temp_f1_1319;
    f64 temp_f1_1412;
    f64 temp_f1_1418;
    f64 temp_f1_1422;
    f64 temp_f1_803;
    f64 temp_f1_809;
    f64 temp_f1_813;
    f64 temp_f1_906;
    f64 temp_f1_912;
    f64 temp_f1_916;
    s32 temp_r0_1105;
    s32 temp_r0_1137;
    s32 temp_r3_1338;
    s32 temp_r3_1441;
    s32 temp_r3_832;
    s32 temp_r3_935;
    s32 var_r0_1348;
    s32 var_r0_1451;
    s32 var_r0_842;
    s32 var_r0_945;
    s32 var_r29_1176;
    s32 var_r29_745;
    s32 var_r30_1162;

    if (IsBurntOut() == 0) {
        M2C_STRUCT_COPY((s32) &sp34C + 4, (s32) &this->unk4C + 4, 0x40);
        sp338 = 1.0f;
        sp33C = 1.0f;
        temp_f29_720 = 1.0f / (f32) this->unk2B4;
        sp340 = 1.0f;
        sp350.Scale3x3(&sp350, *((MKVector3 *) &sp338));
        if (IsBurning() == 0) {
            MKMaterial_SetMaterial(this->unk2A4);
            MKPrimitive(0xC, 0x10);
            MKSetMatrix(sp350);
            MKBegin((this->unk2B4 + 1) * 2);
            temp_f22_744 = MKVector3::up.unk4;
            var_r29_745 = 0;
            temp_f21_746 = MKVector3::up.unk8;
            temp_f20_748 = MKVector3::up.unk0;
loop_44:
            if (var_r29_745 < (s32) (this->unk2B4 + 1)) {
                sp2D8 = GetPos();
                temp_f18_762 = (f32) var_r29_745 * temp_f29_720;
                sp2E8.GetPosition(temp_f18_762);
                sp78 = sp2E8.unk0 - M2C_BITWISE(f64, sp2D8);
                sp2E8.unk30.unk10 = sp78;
                sp2E8.unk10 = sp78;
                sp80 = sp2E8.unk8 - sp2D8.unk8;
                sp2E8.unk44 = M2C_BITWISE(f32, sp2E8.unk44) + 1.0f;
                sp2E8.unk18 = (f64) sp80;
                sp330 = (f64) sp80;
                sp2C8 = this->unkB0->GetVelocity(temp_f18_762);
                sp2E8.unk30 = M2C_BITWISE(f64, sp2C8);
                temp_f1_789 = M2C_BITWISE(f32, sp2E8.unk30);
                temp_f2_790 = M2C_BITWISE(f32, sp2E8.unk30.unk4);
                sp2E8.unk30.unk8 = (f64) sp2C8.unk8;
                var_f4_797 = (sp2E8.unk30.unk8 * sp2E8.unk30.unk8) + ((temp_f1_789 * temp_f1_789) + (temp_f2_790 * temp_f2_790));
                if (var_f4_797 > 0.000001f) {
                    if (var_f4_797 > 0.0f) {
                        temp_f1_803 = __frsqrte(var_f4_797);
                        temp_f1_809 = 0.5 * temp_f1_803 * -(((f64) var_f4_797 * (temp_f1_803 * temp_f1_803)) - 3.0);
                        temp_f1_813 = 0.5 * temp_f1_809 * -(((f64) var_f4_797 * (temp_f1_809 * temp_f1_809)) - 3.0);
                        var_f4_797 = (f32) ((f64) var_f4_797 * (0.5 * temp_f1_813 * -(((f64) var_f4_797 * (temp_f1_813 * temp_f1_813)) - 3.0)));
                    } else if (var_f4_797 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_797 = __float_nan;
                    } else {
                        sp1C = var_f4_797;
                        temp_r3_832 = M2C_BITWISE(s32, sp1C) & 0x7F800000;
                        switch (temp_r3_832) {      /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                                var_r0_842 = 1;
                            } else {
                                var_r0_842 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                                var_r0_842 = 5;
                            } else {
                                var_r0_842 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_842 = 4;
                            break;
                        }
                        if (var_r0_842 == 1) {
                            var_f4_797 = __float_nan;
                        }
                    }
                    var_f2_864 = 1.0f / var_f4_797;
                } else {
                    var_f2_864 = 0.0f;
                }
                temp_f4_871 = M2C_BITWISE(f32, sp2E8.unk30.unk4) * var_f2_864;
                temp_f3_873 = sp2E8.unk30.unk8 * var_f2_864;
                temp_f5_874 = M2C_BITWISE(f32, sp2E8.unk30) * var_f2_864;
                sp2E8.unk30.unk4 = temp_f4_871;
                sp2E8.unk30 = temp_f5_874;
                sp2E8.unk30.unk8 = temp_f3_873;
                sp68 = (temp_f22_744 * temp_f3_873) - (temp_f21_746 * temp_f4_871);
                sp6C = (temp_f21_746 * temp_f5_874) - (temp_f20_748 * temp_f3_873);
                sp70 = (temp_f20_748 * temp_f4_871) - (temp_f22_744 * temp_f5_874);
                sp2E8.unk20 = (f64) sp68;
                temp_f1_890 = M2C_BITWISE(f32, sp2E8.unk20);
                temp_f0_891 = M2C_BITWISE(f32, sp2E8.unk24);
                sp2E8.unk28 = (f64) sp70;
                sp2B8 = (f64) sp68;
                sp2C0 = (f64) sp70;
                var_f4_900 = ((f32) sp2E8.unk28 * (f32) sp2E8.unk28) + ((temp_f1_890 * temp_f1_890) + (temp_f0_891 * temp_f0_891));
                if (var_f4_900 > 0.000001f) {
                    if (var_f4_900 > 0.0f) {
                        temp_f1_906 = __frsqrte(var_f4_900);
                        temp_f1_912 = 0.5 * temp_f1_906 * -(((f64) var_f4_900 * (temp_f1_906 * temp_f1_906)) - 3.0);
                        temp_f1_916 = 0.5 * temp_f1_912 * -(((f64) var_f4_900 * (temp_f1_912 * temp_f1_912)) - 3.0);
                        var_f4_900 = (f32) ((f64) var_f4_900 * (0.5 * temp_f1_916 * -(((f64) var_f4_900 * (temp_f1_916 * temp_f1_916)) - 3.0)));
                    } else if (var_f4_900 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_900 = __float_nan;
                    } else {
                        sp18 = var_f4_900;
                        temp_r3_935 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                        switch (temp_r3_935) {      /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_945 = 1;
                            } else {
                                var_r0_945 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_945 = 5;
                            } else {
                                var_r0_945 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_945 = 4;
                            break;
                        }
                        if (var_r0_945 == 1) {
                            var_f4_900 = __float_nan;
                        }
                    }
                    var_f2_967 = 1.0f / var_f4_900;
                } else {
                    var_f2_967 = 0.0f;
                }
                sp138 = 1.0f;
                sp13C = 1.0f;
                sp140 = 1.0f;
                sp144 = 1.0f;
                sp2E8.unk20 = M2C_BITWISE(f32, sp2E8.unk20) * var_f2_967;
                temp_f18_998 = 4.0f * ((f32) var_r29_745 / (f32) this->unk2B4);
                sp2E8.unk24 = M2C_BITWISE(f32, sp2E8.unk24) * var_f2_967;
                sp2E8.unk28 = (f32) sp2E8.unk28 * var_f2_967;
                sp2A8 = (f64) sp138;
                sp2B0 = (f64) sp140;
                MKSetColorV(*((MKVector4 *) &sp2A8));
                MKSetTexCoord1F(temp_f18_998, 0.95f);
                temp_f26_1007 = this->unkB4;
                temp_f0_1009 = (f64) sp2E8.unk20 * (f64) temp_f26_1007;
                sp128 = temp_f0_1009;
                sp288 = temp_f0_1009;
                sp130 = sp2E8.unk28 * temp_f26_1007;
                sp290 = (f64) sp130;
                temp_f0_1020 = M2C_BITWISE(f64, sp2E8.unk30.unk10) + temp_f0_1009;
                sp118 = temp_f0_1020;
                sp298 = temp_f0_1020;
                sp120 = (f32) sp330 + (f32) sp290;
                sp2A0 = (f64) sp120;
                MKSetPositionV(*((MKVector3 *) &sp298));
                MKRand_Float((int *) &gViewSeed, 0.0f, 30.000002f);
                sp108 = 1.0f;
                sp10C = 1.0f;
                sp110 = 1.0f;
                sp114 = 1.0f;
                sp278 = (f64) sp108;
                sp280 = (f64) sp110;
                MKSetColorV(*((MKVector4 *) &sp278));
                MKSetTexCoord1F(temp_f18_998, 0.05f);
                temp_f27_1049 = this->unkB4;
                temp_f0_1051 = (f64) sp2E8.unk20 * (f64) temp_f27_1049;
                spF8 = temp_f0_1051;
                sp258 = temp_f0_1051;
                sp100 = sp2E8.unk28 * temp_f27_1049;
                sp260 = (f64) sp100;
                temp_f0_1062 = M2C_BITWISE(f64, sp2E8.unk30.unk10) - temp_f0_1051;
                spE8 = temp_f0_1062;
                sp268 = temp_f0_1062;
                spF0 = (f32) sp330 - (f32) sp260;
                sp270 = (f64) spF0;
                MKSetPositionV(*((MKVector3 *) &sp268));
                var_r29_745 += 1;
                goto loop_44;
            }
            MKEnd();
            MKEndPrimitive();
            return;
        }
        MKMaterial_SetMaterial(this->unk2A4);
        var_r28_1093 = GetFirst();
        temp_f24_1094 = MKVector3::up.unk4;
        temp_f25_1096 = MKVector3::up.unk8;
        temp_f26_1097 = MKVector3::up.unk0;
loop_116:
        if (var_r28_1093 != NULL) {
            if (var_r28_1093->unkC == 1.0f) {
                temp_r0_1105 = var_r28_1093->unk10;
                var_f28_1106 = var_r28_1093->unk8;
                if (temp_r0_1105 != 0x64) {
                    var_f27_1111 = *(this + ((temp_r0_1105 * 0x3C) + 0xCC));
                } else {
                    var_f27_1111 = 1.0f;
                }
                var_r28_1093 = GetNextPositive(var_r28_1093);
            } else {
                var_f28_1106 = 0.0f;
                var_f27_1111 = var_r28_1093->unk8;
                var_r28_1093 = GetNextPositive(var_r28_1093);
            }
            var_f2_1129 = var_f27_1111 - var_f28_1106;
            if (var_f2_1129 < 0.0f) {
                var_f1_1132 = -var_f2_1129;
            } else {
                var_f1_1132 = var_f2_1129;
            }
            temp_r0_1137 = this->unk2B4;
            if ((s32) ((f32) temp_r0_1137 * var_f1_1132) != 0) {
                if (var_f2_1129 < 0.0f) {
                    var_f2_1129 = -var_f2_1129;
                }
                var_r30_1162 = (s32) ((f32) temp_r0_1137 * var_f2_1129);
            } else {
                var_r30_1162 = 1;
            }
            MKPrimitive(0xC, 0x10);
            MKSetMatrix(sp350);
            MKBegin((var_r30_1162 + 1) * 2);
            var_r29_1176 = 0;
loop_114:
            if (var_r29_1176 < (s32) (var_r30_1162 + 1)) {
                if (var_r29_1176 == 0) {
                    sp228 = GetPos();
                    ((KDSplinePathSegment *) &sp238)->GetPosition(var_f28_1106);
                    sp58 = sp238 - M2C_BITWISE(f64, sp228);
                    sp248 = sp58;
                    sp60 = sp240 - sp228.unk8;
                    sp2E8.unk30.unk10 = sp58;
                    sp250 = (f64) sp60;
                    sp330 = (f64) sp60;
                } else if (var_r29_1176 == var_r30_1162) {
                    sp1F8 = GetPos();
                    ((KDSplinePathSegment *) &sp208)->GetPosition(var_f27_1111);
                    sp48 = sp208 - M2C_BITWISE(f64, sp1F8);
                    sp218 = sp48;
                    sp50 = sp210 - sp1F8.unk8;
                    sp2E8.unk30.unk10 = sp48;
                    sp220 = (f64) sp50;
                    sp330 = (f64) sp50;
                } else {
                    sp1C8 = GetPos();
                    sp20 = ((f32) var_r29_1176 * temp_f29_720) + var_f28_1106;
                    ((KDSplinePathSegment *) &sp1D8)->GetPosition(Clamp<float>(0.0f, sp20, 1.0f));
                    sp38 = sp1D8 - M2C_BITWISE(f64, sp1C8);
                    sp1E8 = sp38;
                    sp40 = sp1E0 - sp1C8.unk8;
                    sp2E8.unk30.unk10 = sp38;
                    sp1F0 = (f64) sp40;
                    sp330 = (f64) sp40;
                }
                sp2E8.unk44 = M2C_BITWISE(f32, sp2E8.unk44) + 1.0f;
                var_f1_1275 = ((f32) var_r29_1176 * temp_f29_720) + var_f28_1106;
                if (var_f1_1275 < 1.0f) {

                } else {
                    var_f1_1275 = 1.0f;
                }
                if (var_f1_1275 > 0.0f) {

                } else {
                    var_f1_1275 = 0.0f;
                }
                sp1B8 = this->unkB0->GetVelocity(var_f1_1275);
                sp2E8.unk30 = M2C_BITWISE(f64, sp1B8);
                temp_f2_1296 = M2C_BITWISE(f32, sp2E8.unk30.unk4);
                sp2E8.unk30.unk8 = (f64) sp1B8.unk8;
                var_f4_1303 = ((f32) sp2E8.unk30.unk8 * (f32) sp2E8.unk30.unk8) + (((f32) sp2E8.unk30 * (f32) sp2E8.unk30) + (temp_f2_1296 * temp_f2_1296));
                if (var_f4_1303 > 0.000001f) {
                    if (var_f4_1303 > 0.0f) {
                        temp_f1_1309 = __frsqrte(var_f4_1303);
                        temp_f1_1315 = 0.5 * temp_f1_1309 * -(((f64) var_f4_1303 * (temp_f1_1309 * temp_f1_1309)) - 3.0);
                        temp_f1_1319 = 0.5 * temp_f1_1315 * -(((f64) var_f4_1303 * (temp_f1_1315 * temp_f1_1315)) - 3.0);
                        var_f4_1303 = (f32) ((f64) var_f4_1303 * (0.5 * temp_f1_1319 * -(((f64) var_f4_1303 * (temp_f1_1319 * temp_f1_1319)) - 3.0)));
                    } else if (var_f4_1303 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_1303 = __float_nan;
                    } else {
                        sp14 = var_f4_1303;
                        temp_r3_1338 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                        switch (temp_r3_1338) {     /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_1348 = 1;
                            } else {
                                var_r0_1348 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_1348 = 5;
                            } else {
                                var_r0_1348 = 3;
                            }
                            break;
                        default:                    /* switch 3 */
                            var_r0_1348 = 4;
                            break;
                        }
                        if (var_r0_1348 == 1) {
                            var_f4_1303 = __float_nan;
                        }
                    }
                    var_f2_1370 = 1.0f / var_f4_1303;
                } else {
                    var_f2_1370 = 0.0f;
                }
                temp_f4_1377 = M2C_BITWISE(f32, sp2E8.unk30.unk4) * var_f2_1370;
                temp_f3_1379 = (f32) sp2E8.unk30.unk8 * var_f2_1370;
                temp_f5_1380 = (f32) sp2E8.unk30 * var_f2_1370;
                sp2E8.unk30.unk4 = temp_f4_1377;
                sp2E8.unk30 = temp_f5_1380;
                sp2E8.unk30.unk8 = temp_f3_1379;
                sp28 = (temp_f24_1094 * temp_f3_1379) - (temp_f25_1096 * temp_f4_1377);
                sp2C = (temp_f25_1096 * temp_f5_1380) - (temp_f26_1097 * temp_f3_1379);
                sp30 = (temp_f26_1097 * temp_f4_1377) - (temp_f24_1094 * temp_f5_1380);
                sp2E8.unk20 = (f64) sp28;
                temp_f0_1397 = M2C_BITWISE(f32, sp2E8.unk24);
                sp2E8.unk28 = (f64) sp30;
                sp1A8 = (f64) sp28;
                sp1B0 = (f64) sp30;
                var_f4_1406 = ((f32) sp2E8.unk28 * (f32) sp2E8.unk28) + (((f32) sp2E8.unk20 * (f32) sp2E8.unk20) + (temp_f0_1397 * temp_f0_1397));
                if (var_f4_1406 > 0.000001f) {
                    if (var_f4_1406 > 0.0f) {
                        temp_f1_1412 = __frsqrte(var_f4_1406);
                        temp_f1_1418 = 0.5 * temp_f1_1412 * -(((f64) var_f4_1406 * (temp_f1_1412 * temp_f1_1412)) - 3.0);
                        temp_f1_1422 = 0.5 * temp_f1_1418 * -(((f64) var_f4_1406 * (temp_f1_1418 * temp_f1_1418)) - 3.0);
                        var_f4_1406 = (f32) ((f64) var_f4_1406 * (0.5 * temp_f1_1422 * -(((f64) var_f4_1406 * (temp_f1_1422 * temp_f1_1422)) - 3.0)));
                    } else if (var_f4_1406 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_1406 = __float_nan;
                    } else {
                        sp10 = var_f4_1406;
                        temp_r3_1441 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                        switch (temp_r3_1441) {     /* switch 4; irregular */
                        case 0x7F800000:            /* switch 4 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_1451 = 1;
                            } else {
                                var_r0_1451 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 4 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_1451 = 5;
                            } else {
                                var_r0_1451 = 3;
                            }
                            break;
                        default:                    /* switch 4 */
                            var_r0_1451 = 4;
                            break;
                        }
                        if (var_r0_1451 == 1) {
                            var_f4_1406 = __float_nan;
                        }
                    }
                    var_f2_1473 = 1.0f / var_f4_1406;
                } else {
                    var_f2_1473 = 0.0f;
                }
                spD8 = 1.0f;
                spDC = 1.0f;
                spE0 = 1.0f;
                spE4 = 1.0f;
                sp2E8.unk20 = (f32) sp2E8.unk20 * var_f2_1473;
                temp_f18_1504 = 4.0f * ((f32) var_r29_1176 / (f32) this->unk2B4);
                sp2E8.unk24 = M2C_BITWISE(f32, sp2E8.unk24) * var_f2_1473;
                sp2E8.unk28 = (f32) sp2E8.unk28 * var_f2_1473;
                sp198 = (f64) spD8;
                sp1A0 = (f64) spE0;
                MKSetColorV(*((MKVector4 *) &sp198));
                MKSetTexCoord1F(temp_f18_1504, 0.95f);
                temp_f31_1513 = this->unkB4;
                temp_f0_1515 = (f64) sp2E8.unk20 * (f64) temp_f31_1513;
                spC8 = temp_f0_1515;
                sp178 = temp_f0_1515;
                spD0 = sp2E8.unk28 * temp_f31_1513;
                sp180 = (f64) spD0;
                temp_f0_1526 = sp2E8.unk30.unk10 + temp_f0_1515;
                spB8 = temp_f0_1526;
                sp188 = temp_f0_1526;
                spC0 = (f32) sp330 + (f32) sp180;
                sp190 = (f64) spC0;
                MKSetPositionV(*((MKVector3 *) &sp188));
                MKRand_Float((int *) &gViewSeed, 0.0f, 30.000002f);
                spA8 = 1.0f;
                spAC = 1.0f;
                spB0 = 1.0f;
                spB4 = 1.0f;
                sp168 = (f64) spA8;
                sp170 = (f64) spB0;
                MKSetColorV(*((MKVector4 *) &sp168));
                MKSetTexCoord1F(temp_f18_1504, 0.05f);
                temp_f30_1555 = this->unkB4;
                temp_f0_1557 = (f64) sp2E8.unk20 * (f64) temp_f30_1555;
                sp98 = temp_f0_1557;
                sp148 = temp_f0_1557;
                spA0 = sp2E8.unk28 * temp_f30_1555;
                sp150 = (f64) spA0;
                temp_f0_1568 = sp2E8.unk30.unk10 - temp_f0_1557;
                sp88 = temp_f0_1568;
                sp158 = temp_f0_1568;
                sp90 = (f32) sp330 - (f32) sp150;
                sp160 = (f64) sp90;
                MKSetPositionV(*((MKVector3 *) &sp158));
                var_r29_1176 += 1;
                goto loop_114;
            }
            MKEnd();
            MKEndPrimitive();
            goto loop_116;
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to 'double'
void *GunPowderFuse::Update() {
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
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
    KDUniformSpline spD0;
    f64 spC0;
    f64 spB0;
    f64 spA0;
    f64 sp90;
    f64 sp80;
    f64 sp70;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    MKVector3 *temp_r8_2249;
    f32 temp_f1_1735;
    f32 temp_f1_1966;
    f32 temp_f1_2031;
    f32 temp_f1_2095;
    f32 temp_f1_2158;
    f32 temp_f2_1786;
    f32 temp_f2_1811;
    f32 temp_f3_1724;
    f32 temp_f3_1792;
    f32 temp_f3_1813;
    f32 temp_f3_1904;
    f32 temp_f3_1915;
    f32 temp_f4_1720;
    f32 temp_f4_1788;
    f32 temp_f4_1809;
    f32 temp_f4_1912;
    f32 temp_f5_1716;
    f32 temp_f5_1796;
    f32 temp_f5_1908;
    f32 temp_f9_1793;
    s32 temp_r0_2021;
    s32 var_r25_1871;
    s32 var_r25_2245;
    s32 var_r28_1872;
    s32 var_r28_1962;
    s32 var_r30_1960;
    s32 var_r30_2246;
    void *temp_r28_2248;
    void *temp_r31_1874;
    void *temp_r31_1965;
    void *temp_r3_1665;
    void *temp_r3_1692;
    void *temp_r3_1753;
    void *temp_r3_1795;
    void *temp_r3_2009;
    void *temp_r4_2000;
    void *temp_r4_2065;
    void *temp_r4_2076;
    void *temp_r4_2129;
    void *temp_r4_2140;
    void *temp_r4_2227;
    void *var_r26_1868;
    void *var_r27_1857;
    void *var_r28_1747;
    void *var_r4_1844;
    void *var_r4_1941;

    MKProp::Update();
    if (IsBurntOut() == 0) {
        temp_r3_1665 = (void *) (gb.unk0->GetEffects());
        if (temp_r3_1665 != NULL) {
            gb.GetSpyro();
            if (((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x3D3) != 0) && ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x158) == 0) && ((s32) *(&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x7C)) == 0)) {
                temp_r3_1692 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
                sp170 = M2C_FIELD(temp_r3_1692, f64 *, 0x30);
                sp178 = M2C_FIELD(temp_r3_1692, f64 *, 0x38);
                Tools_GetClosestSplineTime(&this->unkB0->unk30, *((MKVector3 *) &sp170), this->unk2B4);
                sp2C = 0.0f;
                spD0.GetMeasure(M2C_ERROR(/* Read from unset register $f1 */), (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                sp160 = M2C_BITWISE(f64, spD0);
                sp168 = (f64) spD0.unk8;
                temp_f5_1716 = (*(f32 *) ((u8 *) &sp170 + 0x4)) - (*(f32 *) ((u8 *) &sp160 + 0x4));
                temp_f4_1720 = (f32) sp170 - (f32) sp160;
                temp_f3_1724 = (f32) sp178 - (f32) sp168;
                if (((temp_f3_1724 * temp_f3_1724) + ((temp_f4_1720 * temp_f4_1720) + (temp_f5_1716 * temp_f5_1716))) < 1000000.0f) {
                    temp_f1_1735 = ((BaseBreathFX *) (M2C_FIELD(M2C_FIELD(temp_r3_1665, void **, 4), BaseBreathFX **, 0x14)))->SplineCollide(this->unkB0, this->unkB4);
                    if (temp_f1_1735 != -1.0f) {
                        Burn(temp_f1_1735);
                    }
                }
            }
            var_r28_1747 = checked_cast<FireBombFX *, MKProp>(M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r3_1665, void **, 4), BaseBreathFX **, 0x14), void **, 0x26C), MKProp **, 0x28));
loop_15:
            if (var_r28_1747 != NULL) {
                if ((u8) M2C_FIELD(var_r28_1747, u8 *, 0xE0) != 0) {
                    temp_r3_1753 = M2C_FIELD(var_r28_1747, void **, 8);
                    sp150 = M2C_FIELD(temp_r3_1753, f64 *, 0x30);
                    sp158 = M2C_FIELD(temp_r3_1753, f64 *, 0x38);
                    Tools_GetClosestSplineTime(&this->unkB0->unk30, *((MKVector3 *) &sp150), this->unk2B4);
                    sp28 = 0.0f;
                    ((KDUniformSpline *) &spC0)->GetMeasure(M2C_ERROR(/* Read from unset register $f1 */), (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                    sp140 = spC0;
                    sp148 = spC8;
                    temp_f2_1786 = (*(f32 *) ((u8 *) &sp150 + 0x4)) - (*(f32 *) ((u8 *) &sp140 + 0x4));
                    temp_f4_1788 = (f32) sp150 - (f32) sp140;
                    temp_f3_1792 = (f32) sp158 - (f32) sp148;
                    temp_f9_1793 = M2C_FIELD(var_r28_1747, f32 *, 0x128);
                    temp_r3_1795 = M2C_FIELD(gb.unk0->GetProp(spC0), void **, 8);
                    temp_f5_1796 = 500.0f * temp_f9_1793;
                    sp130 = M2C_FIELD(temp_r3_1795, f64 *, 0x30);
                    sp138 = M2C_FIELD(temp_r3_1795, f64 *, 0x38);
                    if (((temp_f3_1792 * temp_f3_1792) + ((temp_f4_1788 * temp_f4_1788) + (temp_f2_1786 * temp_f2_1786))) < (temp_f5_1796 * temp_f5_1796)) {
                        temp_f4_1809 = (*(f32 *) ((u8 *) &sp150 + 0x4)) - (*(f32 *) ((u8 *) &sp130 + 0x4));
                        temp_f2_1811 = (f32) sp150 - (f32) sp130;
                        temp_f3_1813 = (f32) sp158 - (f32) sp138;
                        if (((temp_f3_1813 * temp_f3_1813) + ((temp_f2_1811 * temp_f2_1811) + (temp_f4_1809 * temp_f4_1809))) > 10000.0f) {
                            Tools_TestFloor(*((MKVector3 *) &sp150), NULL, 200.0f * temp_f9_1793, (MKCollisionMode) 4);
                            if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                                Tools_GetClosestSplineTime(&this->unkB0->unk30, *((MKVector3 *) &sp150), this->unk2B4);
                                Burn(M2C_ERROR(/* Read from unset register $f1 */));
                            }
                        }
                    }
                }
                var_r28_1747 = checked_cast<FireBombFX *, MKProp>(M2C_FIELD(var_r28_1747, MKProp **, 0x38));
                goto loop_15;
            }
        }
        var_r4_1844 = (void *) (*LiquidFXDescriptor::pFirstDesc);
loop_18:
        if ((var_r4_1844 != NULL) && !(M2C_FIELD(M2C_FIELD(var_r4_1844, void **, 0xE8), s32 *, 0x138) & 2)) {
            var_r4_1844 = M2C_FIELD(var_r4_1844, void **, 0xF0);
            goto loop_18;
        }
        var_r27_1857 = var_r4_1844;
loop_36:
        if (var_r27_1857 != NULL) {
            if (stricmp(M2C_FIELD(var_r27_1857, s32 *, 0), "MoltenMetalFX") == 0) {
                var_r26_1868 = checked_cast<LiquidFX *, MKProp>(M2C_FIELD(var_r27_1857, MKProp **, 0x28));
loop_30:
                if (var_r26_1868 != NULL) {
                    var_r25_1871 = 0;
                    var_r28_1872 = 0;
                    do {
                        temp_r31_1874 = ((u8 *) var_r26_1868) + var_r28_1872;
                        if (((u8) M2C_FIELD(temp_r31_1874, u8 *, 0x159) != 0) && ((u8) M2C_FIELD(temp_r31_1874, u8 *, 0x158) != 0)) {
                            sp120 = M2C_FIELD(temp_r31_1874, f64 *, 0xC8);
                            sp128 = M2C_FIELD(temp_r31_1874, f64 *, 0xD0);
                            Tools_GetClosestSplineTime(&this->unkB0->unk30, *((MKVector3 *) &sp120), this->unk2B4);
                            sp24 = 0.0f;
                            ((KDUniformSpline *) &spB0)->GetMeasure(M2C_ERROR(/* Read from unset register $f1 */), (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                            sp110 = spB0;
                            sp118 = spB8;
                            temp_f3_1904 = (*(f32 *) ((u8 *) &sp120 + 0x4)) - (*(f32 *) ((u8 *) &sp110 + 0x4));
                            temp_f5_1908 = (f32) sp120 - (f32) sp110;
                            temp_f4_1912 = (f32) sp128 - (f32) sp118;
                            temp_f3_1915 = 150.0f * M2C_FIELD(temp_r31_1874, f32 *, 0xF8);
                            if (((temp_f4_1912 * temp_f4_1912) + ((temp_f5_1908 * temp_f5_1908) + (temp_f3_1904 * temp_f3_1904))) < (temp_f3_1915 * temp_f3_1915)) {
                                Tools_GetClosestSplineTime(&this->unkB0->unk30, *((MKVector3 *) &sp120), this->unk2B4);
                                Burn(M2C_ERROR(/* Read from unset register $f1 */));
                            }
                        }
                        var_r25_1871 += 1;
                        var_r28_1872 += 0xA0;
                    } while (var_r25_1871 < 0x64);
                    var_r26_1868 = checked_cast<LiquidFX *, MKProp>(M2C_FIELD(var_r26_1868, MKProp **, 0x38));
                    goto loop_30;
                }
            }
            var_r4_1941 = M2C_FIELD(var_r27_1857, void **, 0xF0);
loop_33:
            if ((var_r4_1941 != NULL) && !(M2C_FIELD(M2C_FIELD(var_r4_1941, void **, 0xE8), s32 *, 0x138) & 2)) {
                var_r4_1941 = M2C_FIELD(var_r4_1941, void **, 0xF0);
                goto loop_33;
            }
            var_r27_1857 = var_r4_1941;
            goto loop_36;
        }
        sp4C = 0;
        var_r30_1960 = 0;
        var_r28_1962 = 0;
        sp48 = 0x162;
        do {
            temp_r31_1965 = this + var_r28_1962;
            temp_f1_1966 = M2C_FIELD(temp_r31_1965, f32 *, 0xCC);
            if ((temp_f1_1966 <= 1.0f) && (temp_f1_1966 >= 0.0f)) {
                M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, void *, M2C_UNK, f32), 0x94)(gMK, &sp48, 0, 0, M2C_FIELD(temp_r31_1965, void **, 0xC4), 1, 100.0f);
                EmitBurn(M2C_FIELD(temp_r31_1965, f32 *, 0xCC));
                if ((void *) M2C_FIELD(temp_r31_1965, void **, 0xC4) != NULL) {
                    sp18 = 0.0f;
                    ((KDUniformSpline *) &spA0)->GetMeasure(M2C_FIELD(temp_r31_1965, f32 *, 0xCC), (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                    temp_r4_2000 = M2C_FIELD(temp_r31_1965, void **, 0xC4);
                    M2C_FIELD(temp_r4_2000, f64 *, 0) = spA0;
                    M2C_FIELD(temp_r4_2000, f64 *, 8) = spA8;
                    temp_r3_2009 = M2C_FIELD(temp_r31_1965, void **, 0xC4);
                    M2C_FIELD(temp_r3_2009, f32 *, 0x2C) = (f32) (M2C_FIELD(temp_r3_2009, f32 *, 0x2C) + MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f));
                }
                M2C_FIELD(temp_r31_1965, f32 *, 0xCC) = (f32) ((M2C_FIELD(temp_r31_1965, f32 *, 0xD0) * (this->unk2A8 * gUpdateTimeDelta)) + M2C_FIELD(temp_r31_1965, f32 *, 0xCC));
                temp_r0_2021 = M2C_FIELD(temp_r31_1965, s32 *, 0xD4);
                if ((temp_r0_2021 != 0x64) && (temp_r0_2021 != -0x64)) {
                    if (M2C_FIELD(temp_r31_1965, f32 *, 0xD0) == 1.0f) {
                        temp_f1_2031 = M2C_FIELD(temp_r31_1965, f32 *, 0xCC);
                        if (temp_f1_2031 > *(this + ((temp_r0_2021 * 0x3C) + 0xCC))) {
                            sp20 = 0.0f;
                            ((KDUniformSpline *) &sp90)->GetMeasure(temp_f1_2031, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                            sp100 = sp90;
                            sp108 = sp98;
                            sp44 = 0;
                            sp40 = 0x162;
                            M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32), 0x94)(gMK, &sp40, 2, 1, &sp100, 1, 4.0f * this->unkB4);
                            temp_r4_2065 = M2C_FIELD(temp_r31_1965, void **, 0xC4);
                            if (temp_r4_2065 != NULL) {
                                M2C_FIELD(temp_r4_2065, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2065, u8 *, 0x31) & ~0x40);
                            }
                            temp_r4_2076 = *(this + ((M2C_FIELD(temp_r31_1965, s32 *, 0xD4) * 0x3C) + 0xC4));
                            if (temp_r4_2076 != NULL) {
                                M2C_FIELD(temp_r4_2076, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2076, u8 *, 0x31) & ~0x40);
                            }
                            M2C_FIELD(temp_r31_1965, f32 *, 0xCC) = 100.0f;
                            *(this + ((M2C_FIELD(temp_r31_1965, s32 *, 0xD4) * 0x3C) + 0xCC)) = 100.0f;
                            UpdatePartners();
                        }
                    } else {
                        temp_f1_2095 = M2C_FIELD(temp_r31_1965, f32 *, 0xCC);
                        if (temp_f1_2095 < *(this + ((temp_r0_2021 * 0x3C) + 0xCC))) {
                            sp1C = 0.0f;
                            ((KDUniformSpline *) &sp80)->GetMeasure(temp_f1_2095, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                            spF0 = sp80;
                            spF8 = sp88;
                            sp3C = 0;
                            sp38 = 0x162;
                            M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32), 0x94)(gMK, &sp38, 2, 1, &spF0, 1, 4.0f * this->unkB4);
                            temp_r4_2129 = M2C_FIELD(temp_r31_1965, void **, 0xC4);
                            if (temp_r4_2129 != NULL) {
                                M2C_FIELD(temp_r4_2129, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2129, u8 *, 0x31) & ~0x40);
                            }
                            temp_r4_2140 = *(this + ((M2C_FIELD(temp_r31_1965, s32 *, 0xD4) * 0x3C) + 0xC4));
                            if (temp_r4_2140 != NULL) {
                                M2C_FIELD(temp_r4_2140, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2140, u8 *, 0x31) & ~0x40);
                            }
                            M2C_FIELD(temp_r31_1965, f32 *, 0xCC) = 100.0f;
                            *(this + ((M2C_FIELD(temp_r31_1965, s32 *, 0xD4) * 0x3C) + 0xCC)) = 100.0f;
                            UpdatePartners();
                        }
                    }
                } else {
                    temp_f1_2158 = M2C_FIELD(temp_r31_1965, f32 *, 0xCC);
                    if ((temp_f1_2158 > 1.0f) || (temp_f1_2158 < 0.0f)) {
                        sp58 = 0.0f;
                        sp50 = 0.0f;
                        sp54 = 0.0f;
                        spE8 = (f64) sp58;
                        spD0.unk10 = (f64) sp50;
                        if (M2C_FIELD(temp_r31_1965, f32 *, 0xCC) > 1.0f) {
                            this->unk2B9 = 1;
                            sp14 = 0.0f;
                            ((KDUniformSpline *) &sp70)->GetMeasure(1.0f, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                            spD0.unk10 = sp70;
                            spE8 = sp78;
                        }
                        if (M2C_FIELD(temp_r31_1965, f32 *, 0xCC) < 0.0f) {
                            this->unk2B8 = 1;
                            sp10 = 0.0f;
                            ((KDUniformSpline *) &sp60)->GetMeasure(0.0f, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                            spD0.unk10 = sp60;
                            spE8 = sp68;
                        }
                        sp34 = 0;
                        sp30 = 0x162;
                        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32), 0x94)(gMK, &sp30, 2, 1, &spD0.unk10, 1, 4.0f * this->unkB4);
                        temp_r4_2227 = M2C_FIELD(temp_r31_1965, void **, 0xC4);
                        if (temp_r4_2227 != NULL) {
                            M2C_FIELD(temp_r4_2227, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2227, u8 *, 0x31) & ~0x40);
                        }
                        M2C_FIELD(temp_r31_1965, f32 *, 0xCC) = 100.0f;
                        UpdatePartners();
                    }
                }
            }
            var_r30_1960 += 1;
            var_r28_1962 += 0x3C;
        } while (var_r30_1960 < 8);
    }
    var_r25_2245 = 0;
    var_r30_2246 = 0;
    do {
        temp_r28_2248 = this + var_r30_2246;
        temp_r8_2249 = M2C_FIELD(temp_r28_2248, MKVector3 **, 0xC4);
        if (temp_r8_2249 != NULL) {
            sp8 = 1;
            ((KDSoundFader *) (((u8 *) temp_r28_2248) + 0xD8))->Update(GS_GunpowderBurnLP, 1U, ((u8) M2C_FIELD(temp_r8_2249, u8 *, 0x31) >> 6U) & 1, NULL, temp_r8_2249, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        } else if (KDSound_IsVoicePlaying(M2C_FIELD(temp_r28_2248, s32 *, 0xD8)) != 0) {
            KDSound_Stop(((u8 *) temp_r28_2248) + 0xD8);
        }
        var_r25_2245 += 1;
        var_r30_2246 += 0x3C;
    } while (var_r25_2245 < 8);
}
#endif

u8 GunPowderFuse::IsBurntOut() {
    s32 i;
    u8 *p;
    f32 f;
    u8 r;

    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        f = M2C_FIELD(p, f32 *, 0xCC);
        if ((f <= 1.0f) && (f >= 0.0f)) {
            return 0;
        }
    }
    r = 0;
    if ((this->unk2B8 != 0) || (this->unk2B9 != 0)) {
        r = 1;
    }
    return r;
}

u8 GunPowderFuse::IsBurning() {
    s32 i;
    u8 *p;
    f32 f;

    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        f = M2C_FIELD(p, f32 *, 0xCC);
        if ((f <= 1.0f) && (f >= 0.0f)) {
            return 1;
        }
    }
    return 0;
}

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to 'double'
void GunPowderFuse::Burn(float arg0) {
    f64 sp30;
    KDUniformSpline sp18;
    s32 sp10;
    s32 spC;
    f32 sp8;
    f32 temp_f1_2395;
    s32 var_r28_2390;
    s32 var_r29_2388;
    s32 var_r30_2392;
    void *temp_r3_2394;
    void *temp_r3_2407;
    void *temp_r4_2414;
    void *temp_r4_2431;

    if ((HasAvailableBurnPoints() != 0) && (TooClose(arg0) == 0) && (IsBurnable(arg0) != 0)) {
        if ((arg0 > this->unk2B0) && ((u8) this->unk2BA == 0)) {
            this->unkC0.Send(NULL);
            this->unk2BA = 1;
        }
        var_r29_2388 = 0;
        var_r28_2390 = 0;
        var_r30_2392 = 0;
loop_7:
        temp_r3_2394 = this + var_r30_2392;
        temp_f1_2395 = M2C_FIELD(temp_r3_2394, f32 *, 0xCC);
        if (!(temp_f1_2395 <= 1.0f) || !(temp_f1_2395 >= 0.0f)) {
            if (var_r29_2388 != 0) {
                temp_r3_2407 = this + var_r30_2392;
                M2C_FIELD(temp_r3_2407, f32 *, 0xD0) = -1.0f;
                M2C_FIELD(temp_r3_2407, f32 *, 0xCC) = (f32) (-0.00001f + arg0);
                M2C_FIELD(temp_r3_2407, f32 *, 0xC8) = (f32) M2C_FIELD(temp_r3_2407, f32 *, 0xCC);
                temp_r4_2414 = M2C_FIELD(temp_r3_2407, void **, 0xC4);
                if (temp_r4_2414 != NULL) {
                    M2C_FIELD(temp_r4_2414, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2414, u8 *, 0x31) | 0x40);
                }
                UpdatePartners();
                return;
            }
            M2C_FIELD(temp_r3_2394, f32 *, 0xD0) = 1.0f;
            M2C_FIELD(temp_r3_2394, f32 *, 0xCC) = (f32) (0.00001f + arg0);
            M2C_FIELD(temp_r3_2394, f32 *, 0xC8) = (f32) M2C_FIELD(temp_r3_2394, f32 *, 0xCC);
            temp_r4_2431 = M2C_FIELD(temp_r3_2394, void **, 0xC4);
            if (temp_r4_2431 != NULL) {
                M2C_FIELD(temp_r4_2431, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2431, u8 *, 0x31) | 0x40);
            }
            sp8 = 0.0f;
            sp18.GetMeasure(arg0, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
            sp18.unk10 = M2C_BITWISE(f64, sp18);
            sp30 = (f64) sp18.unk8;
            sp10 = 0;
            spC = 0x162;
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, u8 *, M2C_UNK, f32), 0x94)(gMK, &spC, 2, 1, &sp18.unk10, 1, 4.0f * this->unkB4);
            var_r29_2388 += 1;
            goto block_16;
        }
block_16:
        var_r28_2390 += 1;
        var_r30_2392 += 0x3C;
        if (var_r28_2390 >= 8) {

        } else {
            goto loop_7;
        }
    }
}
#endif

void GunPowderFuse::Message(MKMessage *arg0) {
    MKVector3 *sp10;
    s32 spC;
    s32 sp8;
    s32 var_r30_2498;
    s32 var_r31_2499;
    u32 temp_r3_2514;

    var_r30_2498 = 0;
    var_r31_2499 = 0;
    do {
        ((KDSoundPlayer *) (this + (var_r31_2499 + 0xD8)))->Message(arg0);
        var_r30_2498 += 1;
        var_r31_2499 += 0x3C;
    } while (var_r30_2498 < 8);
    if ((s32) arg0->unk0 != 0x162) {

    } else {
        temp_r3_2514 = arg0->unk4;
        if (temp_r3_2514 != 0) {
            spC = 0;
            sp8 = 0x5B;
            sp10 = NULL;
            M2C_FIELD(M2C_FIELD(temp_r3_2514, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK), 0x2C)(&sp8, 0);
            Tools_GetClosestSplineTime(&this->unkB0->unk30, *sp10, this->unk2B4);
            Burn(M2C_ERROR(/* Read from unset register $f1 */));
        }
    }
    MKProp::Message(arg0);
}

f32 GunPowderFuse::Resolve() {
    MKVector3 pos;
    MKVector4 col;
    f32 radius;
    Corona *temp;
    u8 *p;
    s32 i;

    MKProp::Resolve();
    this->unk2A4 = (MKMaterial *) (MKMaterial_Create("FX_GunPowderFuse"));
    this->unk2A8 /= this->unkB0->unk30.unk8;
    this->unk2AC = 2.0f * (this->unkB4 / this->unkB0->unk30.unk8);
    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        pos.unk0 = 0.0f;
        pos.unk4 = 0.0f;
        pos.unk8 = 0.0f;
        col.unk0 = 1.0f;
        col.unk4 = 1.0f;
        col.unk8 = 1.0f;
        col.unkC = 1.0f;
        radius = this->unkB4 / 20.0f;
        M2C_FIELD(p, Corona **, 0xC4) = (Corona *) ((Coronas *) gb.unk64)->Alloc(pos, col, radius, lit_743, lit_744);
        temp = M2C_FIELD(p, Corona **, 0xC4);
        if (temp != NULL) {
            M2C_FIELD(temp, u8 *, 0x31) = (u8) (M2C_FIELD(temp, u8 *, 0x31) & ~0x40);
        }
    }
    this->unk2B0 = -((this->unk2A8 * this->unk2B0) - 1.0f);
}

s32 GunPowderFuse::LoadLine(MKIniLine *arg0) {
    if (SplineProp::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("Width", &this->unkB4, 0) != 0) {
        this->unkB4 *= 100.0f;
        return 1U;
    }
    if (arg0->LoadFloat("BurnSpeed", &this->unk2A8, 0) != 0) {
        this->unk2A8 *= 100.0f;
        return 1U;
    }
    if (arg0->LoadFloat("NumSecondsBeforeBurnEnd", &this->unk2B0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("Subdivisions", (int *) &this->unk2B4, 0) != 0) {
        return 1U;
    }
    return (u8) (this->unkC0.LoadLine(arg0, "OnNumSecondsBeforeBurnEnd") != 0);
}

void GunPowderFuse::Deinit() {
    Corona *temp_r4;
    s32 i;
    u8 *p;

    if (this->unk2A4 != NULL) {
        MKMaterial_Destroy(this->unk2A4);
    }
    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        KDSound_Stop((int *) (p + 0xD8));
        temp_r4 = M2C_FIELD(p, Corona **, 0xC4);
        if (temp_r4 != NULL) {
            ((Coronas *) gb.unk64)->Free(temp_r4);
        }
    }
    SplineProp::Deinit();
}

void GunPowderFuse::Init() {
    s32 var_r29_2789;
    s32 var_r31_2787;
    void *temp_r4_2798;

    SplineProp::Init();
    var_r31_2787 = 0;
    this->unkB4 = 5.0f;
    var_r29_2789 = 0;
    this->unk2A8 = 20.0f;
    this->unk2B8 = 0;
    this->unk2B9 = 0;
    this->unk2BA = 0;
    this->unk2AC = 0.0f;
    do {
        temp_r4_2798 = this + var_r31_2787;
        M2C_FIELD(temp_r4_2798, f32 *, 0xCC) = 100.0f;
        M2C_FIELD(temp_r4_2798, f32 *, 0xC8) = 0.0f;
        M2C_FIELD(temp_r4_2798, s32 *, 0xC4) = 0;
        ((KDSoundFader *) (((u8 *) temp_r4_2798) + 0xD8))->Init(0.25f, 0.25f);
        var_r29_2789 += 1;
        var_r31_2787 += 0x3C;
    } while (var_r29_2789 < 8);
    this->unk2A4 = NULL;
}

void GunPowderFuse_cpp::__sinit() {
    f32 temp_f0_2858;
    f64 temp_f1_2839;
    f64 temp_f1_2847;
    f64 temp_f3_2827;
    f64 temp_f4_2836;
    f64 temp_f4_2844;
    f64 temp_f8_2829;

    temp_f3_2827 = __frsqrte(2014000.0);
    temp_f8_2829 = __frsqrte(380000.0);
    temp_f4_2836 = 0.5 * temp_f3_2827 * -((2014000.0 * (temp_f3_2827 * temp_f3_2827)) - 3.0);
    temp_f1_2839 = 0.5 * temp_f8_2829 * -((380000.0 * (temp_f8_2829 * temp_f8_2829)) - 3.0);
    temp_f4_2844 = 0.5 * temp_f4_2836 * -((2014000.0 * (temp_f4_2836 * temp_f4_2836)) - 3.0);
    temp_f1_2847 = 0.5 * temp_f1_2839 * -((380000.0 * (temp_f1_2839 * temp_f1_2839)) - 3.0);
    temp_f0_2858 = (f32) (380000.0 * (0.5 * temp_f1_2847 * -((380000.0 * (temp_f1_2847 * temp_f1_2847)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_2844 * -((2014000.0 * (temp_f4_2844 * temp_f4_2844)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_2858;
}
