#include "spyro/source/EarthBreathFX.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/EarthBombFX.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/FuryFXEarth.h"
#include "spyro/source/FuryFXEarth2.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/ShotgunWarpFX.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(MKVector3 **);                         /* extern */
MKVector3 **malloc(M2C_UNK);                        /* extern */
extern s32 GS_SpyroBreathRumble1;
extern s32 GS_SpyroBreathRumble2;
extern s32 GS_SpyroBreathRumble3;
extern s32 GS_SpyroEarthAttack1;
extern s32 GS_SpyroEarthAttack2;
extern s32 GS_SpyroEarthAttack3;
extern s32 GS_SpyroEarthAttack4;
extern s32 GS_SpyroEarthBlast1;
extern s32 GS_SpyroEarthBlast2;
extern s32 GS_SpyroEarthBlast3;
extern s32 GS_SpyroEarthBlast4;
extern M2C_UNK gEmptyPtrListDL;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

static s32 lit_777 = 0;
static u8 lit_778 = 1;

#if 0 // DRAFT: illegal explicit conversion from 'float' to
u8 EarthBreathFX::ShootEarthBomb(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, bool arg3) {
    s8 sp220;
    s32 sp21C;
    s32 sp218;
    s32 sp214;
    f32 sp210;
    s32 sp20C;
    s8 sp20B;
    s8 sp20A;
    s16 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F4;
    f32 sp1F0;
    f32 sp1E8;
    f32 sp1E4;
    f32 sp1E0;
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    s8 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    s32 sp1B4;
    s32 sp1B0;
    f64 sp1A8;                                      /* compiler-managed */
    f64 sp1A0;                                      /* compiler-managed */
    f64 sp198;
    f64 sp190;
    M2C_UNK sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    MKVector3 sp130;
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
    MKVector3 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    EarthBombFX *temp_r3_68;
    TargetManager ***var_r28_221;
    TargetManager **temp_r31_418;
    TargetManager **var_r29_218;
    f32 temp_f1_574;
    f32 temp_f2_396;
    f32 temp_f2_445;
    f32 var_f0_284;
    f32 var_f28_216;
    f32 var_f29_115;
    f32 var_f30_113;
    f32 var_f4_351;
    f64 temp_f0_266;
    f64 temp_f0_448;
    f64 temp_f0_524;
    f64 temp_f0_567;
    f64 temp_f1_260;
    f64 temp_f2_290;
    f64 temp_f2_296;
    f64 temp_f2_300;
    s32 temp_r0_120;
    s32 temp_r3_118;
    s32 temp_r3_319;
    s32 var_r0_136;
    s32 var_r0_329;
    s32 var_r0_368;
    u8 var_r0_400;
    u8 var_r3_126;
    void *temp_r3_259;
    void *temp_r4_122;

    temp_r3_68 = checked_cast<EarthBombFX *, MKProp>(((MKPropDescriptor *) (M2C_BITWISE(MKPropDescriptor *, this->unk150.unk38)))->CreateInstance());
    if (temp_r3_68 != NULL) {
        M2C_FIELD(temp_r3_68->__vptr, M2C_UNK (**)(), 0x30)();
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            sp1B4 = 0;
            MKVector(1.0f, 1.0f, 1.0f);
            sp10 = sp150 * 5.49408334e-315;
            sp1B0 = 0x417;
            sp1B8 = sp10;
            sp18 = sp158 * 50.0f;
            sp1C8 = 1;
            sp1C0 = (f64) sp18;
            sp160 = sp10;
            sp168 = (f64) sp18;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp1B0, sp10);
        }
        var_f30_113 = 2000.0f;
        var_f29_115 = 1.0f;
        temp_r3_118 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
        temp_r0_120 = *(&GameData::gameData[0x70] + (temp_r3_118 + 0x7C));
        temp_r4_122 = &GameData::gameData[0x70] + (temp_r3_118 + 0x64);
        if (temp_r0_120 == 3) {
            var_r3_126 = 0;
            if (((s32) M2C_FIELD(temp_r4_122, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_122, s32 *, 4) == 3)) {
                var_r3_126 = 1;
            }
            var_r0_136 = var_r3_126 != 0;
        } else {
            var_r0_136 = *(temp_r4_122 + (temp_r0_120 * 4));
        }
        switch (var_r0_136) {                       /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            var_f30_113 = 1000.0f;
            var_f29_115 = 0.5f;
            this->unkA0 = 1000.0f;
            KDSound_Play3d(GS_SpyroEarthAttack1, &arg0, 0U, -1, 0.0f, 0U);
            break;
        case 1:                                     /* switch 1 */
            var_f30_113 = 1100.0f;
            var_f29_115 = 0.7f;
            this->unkA0 = 1100.0f;
            KDSound_Play3d(GS_SpyroEarthAttack2, &arg0, 0U, -1, 0.0f, 0U);
            break;
        case 2:                                     /* switch 1 */
            var_f30_113 = 1300.0f;
            var_f29_115 = 0.85f;
            this->unkA0 = 1300.0f;
            KDSound_Play3d(GS_SpyroEarthAttack3, &arg0, 0U, -1, 0.0f, 0U);
            break;
        case 3:                                     /* switch 1 */
            var_f30_113 = 1500.0f;
            var_f29_115 = 0.85f;
            this->unkA0 = 1500.0f;
            KDSound_Play3d(GS_SpyroEarthAttack4, &arg0, 0U, -1, 0.0f, 0U);
            break;
        }
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.0f, 0.4f, 0.04f, 0, 4.0f, 0U);
        var_f28_216 = 3.4028235e38f;
        var_r29_218 = NULL;
        var_r28_221 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
loop_57:
        if (var_r28_221 != NULL) {
            temp_r31_418 = *var_r28_221;
            if (temp_r31_418 != NULL) {
                if (((*temp_r31_418)->unk8.unk0(temp_r31_418) != NULL) && (M2C_FIELD(*temp_r31_418, u8 (**)(TargetManager **), 0x18)(temp_r31_418) != 0) && ((((u32 (*)(TargetManager **)) (*temp_r31_418)->unk8.unk4)(temp_r31_418) == 0U) || (((Character *) (((Character *(*)(TargetManager **)) (*temp_r31_418)->unk8.unk4)(temp_r31_418)))->IsActive() != 0))) {
                    temp_r3_259 = M2C_FIELD((*temp_r31_418)->unk8.unk0(temp_r31_418), void **, 8);
                    temp_f1_260 = M2C_FIELD(temp_r3_259, f64 *, 0x30);
                    sp140 = temp_f1_260;
                    sp148 = M2C_FIELD(temp_r3_259, f64 *, 0x38);
                    temp_f0_266 = temp_f1_260 - M2C_FIELD(&arg0, f64 *, 0);
                    spA0 = temp_f0_266;
                    sp1A0 = temp_f0_266;
                    spA8 = (f32) sp148 - arg0.unk8;
                    sp1A8 = (f64) spA8;
                    var_f0_284 = ((f32) sp1A8 * (f32) sp1A8) + (((f32) sp1A0 * (f32) sp1A0) + (unksp1A4 * unksp1A4));
                    if (var_f0_284 > 0.000001f) {
                        if (var_f0_284 > 0.0f) {
                            temp_f2_290 = __frsqrte(var_f0_284);
                            temp_f2_296 = 0.5 * temp_f2_290 * -(((f64) var_f0_284 * (temp_f2_290 * temp_f2_290)) - 3.0);
                            temp_f2_300 = 0.5 * temp_f2_296 * -(((f64) var_f0_284 * (temp_f2_296 * temp_f2_296)) - 3.0);
                            var_f0_284 = (f32) ((f64) var_f0_284 * (0.5 * temp_f2_300 * -(((f64) var_f0_284 * (temp_f2_300 * temp_f2_300)) - 3.0)));
                        } else if (var_f0_284 < M2C_BITWISE(f32, 0.0)) {
                            var_f0_284 = __float_nan;
                        } else {
                            sp8 = var_f0_284;
                            temp_r3_319 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_319) {  /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_329 = 1;
                                } else {
                                    var_r0_329 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_329 = 5;
                                } else {
                                    var_r0_329 = 3;
                                }
                                break;
                            default:                /* switch 2 */
                                var_r0_329 = 4;
                                break;
                            }
                            if (var_r0_329 == 1) {
                                var_f0_284 = __float_nan;
                            }
                        }
                        var_f4_351 = 1.0f / var_f0_284;
                    } else {
                        var_f4_351 = 0.0f;
                        var_f0_284 = 0.0f;
                    }
                    sp1A0 = (f32) sp1A0 * var_f4_351;
                    unksp1A4 *= var_f4_351;
                    sp1A8 = (f32) sp1A8 * var_f4_351;
                    if (arg3 != 0) {
                        var_r0_368 = 1;
                    } else {
                        var_r0_368 = var_f0_284 >= (0.5f * this->unkA0);
                    }
                    if ((var_r0_368 != 0) && (var_f0_284 <= this->unkA0) && (var_f0_284 < var_f28_216)) {
                        temp_f2_396 = (sp1A8 * arg1.unk8) + ((sp1A0 * arg1.unk0) + (unksp1A4 * arg1.unk4));
                        if (arg3 != 0) {
                            var_r0_400 = temp_f2_396 > 0.2f;
                        } else {
                            var_r0_400 = temp_f2_396 > 0.8f;
                        }
                        if (var_r0_400 != 0) {
                            var_f28_216 = var_f0_284;
                            var_r29_218 = temp_r31_418;
                        }
                    }
                }
                var_r28_221 += 4;
                goto loop_57;
            }
        }
        if ((var_r29_218 != NULL) && (M2C_FIELD(*var_r29_218, u8 (**)(TargetManager **, MKVector3 *, M2C_UNK *), 0x2C)(var_r29_218, &arg0, &sp180) != 0)) {
            Tools_CalculateVelocity(sp130, arg0, var_f30_113, -1960.0f);
            sp190 = M2C_BITWISE(f64, sp130);
            sp198 = (f64) sp130.unk8;
        } else {
            temp_f2_445 = this->unkA0;
            temp_f0_448 = (f64) M2C_FIELD(&arg1, f32 *, 0) * (f64) temp_f2_445;
            sp90 = temp_f0_448;
            sp120 = temp_f0_448;
            sp98 = arg1.unk8 * temp_f2_445;
            sp128 = (f64) sp98;
            sp80 = M2C_FIELD(&arg0, f64 *, 0) + temp_f0_448;
            sp58 = 0.0f;
            sp50 = 0.0f;
            sp54 = -500.0f;
            sp88 = arg0.unk8 + (f32) sp128;
            sp170 = sp80;
            spE0 = (f64) sp50;
            sp178 = (f64) sp88;
            sp1D0 = 0.0f;
            sp1D4 = 0.0f;
            sp1D8 = 0.0f;
            sp1E0 = 0.0f;
            sp1E4 = 0.0f;
            sp1E8 = 0.0f;
            sp1F0 = 0.0f;
            sp1F4 = 0.0f;
            sp1F8 = 0.0f;
            sp1FC = 1.0f;
            sp200 = 0.0f;
            sp204 = 0.0f;
            sp208 = 0;
            sp20A = 0;
            sp20B = 0;
            sp20C = 0;
            sp210 = 3.4028235e38f;
            sp214 = 0;
            sp218 = 0;
            sp21C = -1;
            sp220 = 0;
            spE8 = (f64) sp58;
            sp40 = sp170 + spE0;
            sp78 = 0.0f;
            sp70 = 0.0f;
            sp74 = 500.0f;
            sp48 = (f32) sp178 + (f32) spE8;
            sp100 = (f64) sp70;
            spF0 = sp40;
            spF8 = (f64) sp48;
            sp108 = (f64) sp78;
            temp_f0_524 = sp170 + sp100;
            sp60 = temp_f0_524;
            sp110 = temp_f0_524;
            sp68 = (f32) sp178 + (f32) sp108;
            sp118 = (f64) sp68;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp110), *((MKVector3 *) &spF0), (MKCollisionResult *) &sp1D0, (MKCollisionMode) 4, 0x0C000000) != 0) {
                sp170 = (f64) sp1D0;
                sp178 = (f64) sp1D8;
            }
            Tools_CalculateVelocity(spD0, arg0, var_f30_113, -1960.0f);
            sp190 = M2C_BITWISE(f64, spD0);
            sp198 = (f64) spD0.unk8;
        }
        sp28 = 0.0f;
        sp20 = 0.0f;
        sp24 = 0.0f;
        spB8 = (f64) sp28;
        spB0 = (f64) sp20;
        temp_f0_567 = sp190 + M2C_FIELD(&arg2, f64 *, 0);
        sp30 = temp_f0_567;
        temp_f1_574 = (f32) sp198 + arg2.unk8;
        spC0 = temp_f0_567;
        sp38 = temp_f1_574;
        spC8 = (f64) sp38;
        temp_r3_68->Fire(arg0, *((MKVector3 *) &spC0), var_f29_115, M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **, f32, f32), 0xC)(M2C_FIELD(&gb, void ***, 0), temp_f1_574, (f32) sp198), *((MKVector3 *) &spB0));
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.0f, 0.4f, 0.04f, 0, 4.0f, 0U);
        return 1U;
    }
    return 0U;
}
#endif

void EarthBreathFX::ResetFury() {
    this->unkC0->ResetFury();
    this->unkC4->ResetFury();
}

#if 0 // DRAFT: illegal explicit conversion from 'MKModel *' to
void EarthBreathFX::DrawShotgunMuzzelFlash() {
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f3_689;
    f32 temp_f3_694;
    f32 var_f2_670;

    if (!(M2C_BITWISE(f32, this->unk128) <= 0.0f)) {
        M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) &this->unk14C + 4, 0x40);
        var_f2_670 = M2C_BITWISE(f32, this->unk128);
        if (var_f2_670 < 0.25f) {

        } else {
            var_f2_670 = 0.25f;
        }
        if (var_f2_670 > 0.0f) {

        } else {
            var_f2_670 = 0.0f;
        }
        temp_f3_689 = var_f2_670 / 0.25f;
        temp_f3_694 = 3.0f * temp_f3_689;
        sp18 = temp_f3_694;
        sp10 = temp_f3_694;
        sp14 = (3.0f * (1.0f - temp_f3_689)) + 2.0f;
        sp28 = (f64) sp18;
        sp20 = (f64) sp10;
        sp30.Scale3x3(&sp30, *((MKVector3 *) &sp20));
        MKModel_SetWorldMatrix(M2C_FIELD(this, MKModel **, 0x140), sp30);
        MKModel_Draw(M2C_FIELD(this, MKModel **, 0x140), NULL);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
s32 EarthBreathFX::ShootShotgun(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2) {
    Matrix sp260;
    M2C_UNK sp25C;
    s8 sp250;
    f64 sp248;
    f64 sp240;
    s32 sp23C;
    s32 sp238;
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
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
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
    f64 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    ManagedLight *temp_r3_1227;
    ManagedLight *temp_r3_1240;
    ManagedLight *temp_r3_1259;
    ManagedLight *temp_r4_1206;
    f32 temp_f19_1027;
    f32 temp_f19_1072;
    f32 temp_f20_994;
    f32 temp_f21_1022;
    f32 temp_f21_1077;
    f32 temp_f21_1142;
    f32 temp_f29_988;
    f32 temp_f31_992;
    f32 var_f23_763;
    f64 temp_f0_1009;
    f64 temp_f0_1041;
    f64 temp_f0_1052;
    f64 temp_f0_1091;
    f64 temp_f0_1102;
    f64 temp_f0_1113;
    f64 temp_f0_1124;
    s32 temp_cr0_eq_896;
    s32 temp_cr0_eq_927;
    s32 temp_r0_769;
    s32 var_r24_987;
    s32 var_r31_766;
    u8 var_r24_900;
    u8 var_r24_931;
    u8 var_r29_768;
    u8 var_r30_767;
    void *temp_r3_1233;
    void *temp_r3_1243;
    void *temp_r3_1267;

    this->unkD0.unk50 = 0;
    this->unkB0 = 1;
    var_f23_763 = 1.125f;
    this->unkAC = 0.0f;
    var_r31_766 = 0;
    var_r30_767 = 0;
    var_r29_768 = 0;
    temp_r0_769 = this->unkD0.unk3C;
    switch (temp_r0_769) {                          /* irregular */
    case 0:
        var_r31_766 = GS_SpyroEarthBlast1;
        var_f23_763 = 0.22500001f;
        var_r30_767 = 0;
        this->unkBC = 0.65f;
        var_r29_768 = 0;
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.8f, 0.8f, 0.065f, 0, 4.0f, 0U);
        break;
    case 1:
        var_r31_766 = GS_SpyroEarthBlast2;
        var_f23_763 = 0.39374998f;
        var_r30_767 = 1;
        this->unkBC = 0.48749998f;
        var_r29_768 = 0;
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(1.0f, 1.0f, 0.08f, 0, 4.0f, 0U);
        KDSound_Play3d(GS_SpyroBreathRumble1, &arg0, 0U, -1, 0.0f, 0U);
        break;
    case 2:
        var_r31_766 = GS_SpyroEarthBlast3;
        var_f23_763 = 0.5625f;
        var_r30_767 = 1;
        this->unkBC = 0.325f;
        var_r29_768 = 0;
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(1.0f, 1.0f, 0.11f, 0, 4.0f, 0U);
        KDSound_Play3d(GS_SpyroBreathRumble2, &arg0, 0U, -1, 0.0f, 0U);
        M2C_FIELD(this, s8 *, 0x198) = 1;
        this->unk194 = 0.125f;
        break;
    case 3:
        var_r31_766 = GS_SpyroEarthBlast4;
        var_r30_767 = 1;
        var_r29_768 = 1;
        var_f23_763 = 0.73125f;
        this->unkBC = 0.1625f;
        if (this->unkA8 <= 0.0f) {
            ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(1.0f, 1.0f, 0.15f, 0, 4.0f, 0U);
            this->unkA8 = 0.75f;
        }
        temp_cr0_eq_896 = (void *) M2C_FIELD(&gb, void **, 0xC) == NULL;
        if (temp_cr0_eq_896 == 0) {
            if (temp_cr0_eq_896 == 0) {
                var_r24_900 = 0;
                if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
                    var_r24_900 = 1;
                }
                if (var_r24_900 == 0) {
                    goto block_19;
                }
            }
        } else {
block_19:
            KDSound_Play3d(GS_SpyroBreathRumble3, &arg0, 0U, -1, 0.0f, 0U);
        }
        break;
    }
    temp_cr0_eq_927 = (void *) M2C_FIELD(&gb, void **, 0xC) == NULL;
    if (temp_cr0_eq_927 == 0) {
        if (temp_cr0_eq_927 == 0) {
            var_r24_931 = 0;
            if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
                var_r24_931 = 1;
            }
            if (var_r24_931 == 0) {
                goto block_27;
            }
        }
    } else {
block_27:
        KDSound_Play3d(var_r31_766, &arg0, 0U, -1, 0.0f, 0U);
        this->unk128 = 0.25f;
    }
    M2C_STRUCT_COPY((s32) &this->unk14C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp110 = 0.0f;
    sp108 = 0.0f;
    sp10C = 1.0f;
    sp220 = (f64) sp110;
    sp218 = (f64) sp108;
    KDMath_BuildMatrixFromUp((Matrix *) &this->unk150, arg1, *((MKVector3 *) &sp218));
    this->unk150.unk28 = arg0.unk0;
    var_r24_987 = 0;
    temp_f29_988 = arg0.unk8;
    this->unk150.unk2C = arg0.unk4;
    this->unk150.unk30 = temp_f29_988;
    temp_f31_992 = arg1.unk8;
    this->unk150.unk34 = 1.0f;
    temp_f20_994 = arg2.unk8;
    do {
        spF8 = M2C_FIELD(&arg1, f64 *, 0) * 5.49408334e-315;
        sp100 = temp_f31_992 * 50.0f;
        sp1F8 = spF8;
        sp200 = (f64) sp100;
        temp_f0_1009 = (f64) M2C_FIELD(&arg0, f32 *, 0) + sp1F8;
        spE8 = temp_f0_1009;
        sp208 = temp_f0_1009;
        spF0 = temp_f29_988 + (f32) sp200;
        sp210 = (f64) spF0;
        temp_f21_1022 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f19_1027 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        spD8 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        spDC = temp_f19_1027;
        spE0 = temp_f21_1022;
        sp1C8 = (f64) spD8;
        sp1D0 = (f64) spE0;
        temp_f0_1041 = sp1C8 * 5.222099017e-315;
        spC8 = temp_f0_1041;
        sp1D8 = temp_f0_1041;
        spD0 = (f32) sp1D0 * 0.5f;
        sp1E0 = (f64) spD0;
        temp_f0_1052 = M2C_FIELD(&arg1, f64 *, 0) + temp_f0_1041;
        spB8 = temp_f0_1052;
        sp1E8 = temp_f0_1052;
        spC0 = temp_f31_992 + (f32) sp1E0;
        sp1F0 = (f64) spC0;
        SpawnSeedBullet(*((MKVector3 *) &sp208), *((MKVector3 *) &sp1E8), arg2, var_f23_763, var_r29_768);
        temp_f19_1072 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f21_1077 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        spA8 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        spAC = temp_f21_1077;
        spB0 = temp_f19_1072;
        sp178 = (f64) spA8;
        sp180 = (f64) spB0;
        temp_f0_1091 = sp178 * 5.222099017e-315;
        sp98 = temp_f0_1091;
        sp188 = temp_f0_1091;
        spA0 = (f32) sp180 * 0.5f;
        sp190 = (f64) spA0;
        temp_f0_1102 = M2C_FIELD(&arg1, f64 *, 0) + temp_f0_1091;
        sp88 = temp_f0_1102;
        sp198 = temp_f0_1102;
        sp90 = temp_f31_992 + (f32) sp190;
        sp1A0 = (f64) sp90;
        temp_f0_1113 = temp_f0_1102 * 5.739719183e-315;
        sp78 = temp_f0_1113;
        sp1A8 = temp_f0_1113;
        sp80 = (f32) sp1A0 * 3050.0f;
        sp1B0 = (f64) sp80;
        temp_f0_1124 = sp1A8 + M2C_FIELD(&arg2, f64 *, 0);
        sp68 = temp_f0_1124;
        sp1B8 = temp_f0_1124;
        sp70 = (f32) sp1B0 + temp_f20_994;
        sp1C0 = (f64) sp70;
        sp10 = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
        temp_f21_1142 = MKRand_Float(&gViewSeed, 0.0f, 0.5f);
        sp5C = MKRand_Float(&gViewSeed, 0.6f, 1.0f);
        sp58 = 0.1f;
        sp60 = temp_f21_1142;
        sp64 = 1.0f;
        sp168 = (f64) sp58;
        sp170 = (f64) sp60;
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(arg0, *((MKVector3 *) &sp1B8), sp10, *((MKVector4 *) &sp168), -800.0f);
        var_r24_987 += 1;
    } while (var_r24_987 < 0x14);
    M2C_STRUCT_COPY((s32) &sp25C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp50 = 0.0f;
    sp48 = 0.0f;
    sp4C = 1.0f;
    sp230 = (f64) sp50;
    sp228 = (f64) sp48;
    KDMath_BuildMatrixFromFwd(&sp260, arg1, (MKVector3 *) &sp228);
    sp260.unk30 = arg0.unk0;
    sp260.unk34 = arg0.unk4;
    sp260.unk38 = arg0.unk8;
    sp260.unk3C = 1.0f;
    if (var_r30_767 != 0) {
        ((ShotgunWarpFX *) (&gb + 0x130))->StartWarp(&sp260);
    }
    temp_r4_1206 = this->unkB8;
    if (temp_r4_1206 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1206, 1U);
        MKVector(0.0f, 200.0f, 0.0f);
        sp38 = (f64) M2C_FIELD(&arg0, f32 *, 0) + sp148;
        temp_r3_1227 = this->unkB8;
        sp158 = sp38;
        sp40 = arg0.unk8 + sp150;
        temp_r3_1227->unk10 = sp38;
        temp_r3_1227->unk18 = (f64) sp40;
        temp_r3_1233 = temp_r3_1227->unk3C;
        sp160 = (f64) sp40;
        if (temp_r3_1233 != NULL) {
            M2C_FIELD(temp_r3_1233, f64 *, 0x10) = sp38;
            M2C_FIELD(temp_r3_1233, f64 *, 0x18) = (f64) sp40;
        }
        temp_r3_1240 = this->unkB8;
        temp_r3_1240->unk38 = 1000.0f;
        temp_r3_1243 = temp_r3_1240->unk3C;
        if (temp_r3_1243 != NULL) {
            M2C_FIELD(temp_r3_1243, f32 *, 0x20) = 1000.0f;
            M2C_FIELD(temp_r3_1243, f32 *, 0x24) = 1000000.0f;
            M2C_FIELD(temp_r3_1243, f32 *, 0x28) = 0.001f;
            M2C_FIELD(temp_r3_1243, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1243, f32 *, 0x24));
        }
        sp28 = 0.0f;
        temp_r3_1259 = this->unkB8;
        sp2C = 1.0f;
        sp30 = 0.0f;
        sp34 = 1.0f;
        temp_r3_1259->unk20 = (f64) sp28;
        temp_r3_1259->unk28 = (f64) sp30;
        temp_r3_1267 = temp_r3_1259->unk3C;
        sp138 = (f64) sp28;
        sp140 = (f64) sp30;
        if (temp_r3_1267 != NULL) {
            M2C_FIELD(temp_r3_1267, f64 *, 0) = (f64) sp28;
            M2C_FIELD(temp_r3_1267, f64 *, 8) = (f64) sp30;
        }
    }
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        sp23C = 0;
        MKVector(1.0f, 1.0f, 1.0f);
        sp18 = sp118 * 5.49408334e-315;
        sp238 = 0x417;
        sp240 = sp18;
        sp20 = sp120 * 50.0f;
        sp250 = 1;
        sp248 = (f64) sp20;
        sp128 = sp18;
        sp130 = (f64) sp20;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp238, sp18);
    }
    return 1;
}
#endif

#if 0 // DRAFT: illegal type
s32 EarthBreathFX::Trigger(MKProp *arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3, int arg4, bool arg5) {
    s32 temp_r30_1383;
    s32 temp_r31_1386;
    s32 temp_r4_1384;
    s32 var_r24_1421;
    s32 var_r6_1402;
    u8 var_r3_1467;
    u8 var_r4_1392;
    u8 var_r4_1411;
    void *temp_r4_1473;
    void *temp_r5_1388;

    M2C_FIELD(this, f64 *, 0x130) = (f64) M2C_FIELD(&arg2, f64 *, 0);
    this->unk130 = M2C_FIELD(&arg2, f64 *, 8);
    switch (arg4) {                                 /* irregular */
    case 0:
        if (this->unkBC <= 0.0f) {
            temp_r30_1383 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
            temp_r4_1384 = temp_r30_1383 << 5;
            temp_r31_1386 = *(&GameData::gameData[0x70] + (temp_r4_1384 + 0x7C));
            temp_r5_1388 = &GameData::gameData[0x70] + (temp_r4_1384 + 0x64);
            if (temp_r31_1386 == 3) {
                var_r4_1392 = 0;
                if (((s32) M2C_FIELD(temp_r5_1388, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_1388, s32 *, 4) == 3)) {
                    var_r4_1392 = 1;
                }
                var_r6_1402 = var_r4_1392 != 0;
            } else {
                var_r6_1402 = *(temp_r5_1388 + (temp_r31_1386 * 4));
            }
            if (temp_r31_1386 == 3) {
                var_r4_1411 = 0;
                if (((s32) M2C_FIELD(temp_r5_1388, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_1388, s32 *, 4) == 3)) {
                    var_r4_1411 = 1;
                }
                var_r24_1421 = var_r4_1411 != 0;
            } else {
                var_r24_1421 = *(temp_r5_1388 + (temp_r31_1386 * 4));
            }
            this->unkD0.Init(arg0, ((GameStats *) &GameData::gameData[0x70])->GetBreathAttackDamage(temp_r30_1383, temp_r31_1386, var_r6_1402), temp_r31_1386, var_r24_1421, temp_r30_1383, temp_r30_1383, 0, -1);
            return ShootShotgun(arg1, arg2, arg3);
        }
        return 0;
    case 1:
        if ((this->unk150.unk3C <= 0.0f) && (ShootEarthBomb(arg1, arg2, arg3, arg5) != 0)) {
            this->unk150.unk3C = 1.0f;
            return 1;
        }
    case 2:
    default:
        return 0;
    case 3:
        var_r3_1467 = 0;
        temp_r4_1473 = &GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x64);
        if (((s32) M2C_FIELD(temp_r4_1473, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_1473, s32 *, 4) == 3)) {
            var_r3_1467 = 1;
        }
        if (var_r3_1467 == 0) {
            return this->unkC0->Trigger(arg1, 0U);
        }
        this->unkC0->Trigger(arg1, 1U);
        return this->unkC4->Trigger(arg1);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp3C'
void EarthBreathFX::DrawSeedBullets() {
    Matrix sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f64 sp40;                                       /* compiler-managed */
    f64 sp38;                                       /* compiler-managed */
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    MKVector3 **var_r31_1534;
    MKVector3 *temp_r3_1673;
    MKVector3 *temp_r3_1691;
    MKVector3 *temp_r6_1649;
    f32 temp_f25_1659;
    f32 var_f26_1625;
    f32 var_f3_1619;
    f32 var_f4_1552;
    f64 temp_f1_1558;
    f64 temp_f1_1564;
    f64 temp_f1_1568;
    s32 temp_r3_1587;
    s32 var_r0_1597;

    var_r31_1534 = this->unkC8;
loop_28:
    if (var_r31_1534 != NULL) {
        temp_r3_1691 = *var_r31_1534;
        if (temp_r3_1691 != NULL) {
            sp38 = M2C_FIELD(temp_r3_1691, f64 *, 0x10);
            sp40 = M2C_FIELD(temp_r3_1691, f64 *, 0x18);
            var_f4_1552 = ((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + (unksp3C * unksp3C));
            if (var_f4_1552 > 0.000001f) {
                if (var_f4_1552 > 0.0f) {
                    temp_f1_1558 = __frsqrte(var_f4_1552);
                    temp_f1_1564 = 0.5 * temp_f1_1558 * -(((f64) var_f4_1552 * (temp_f1_1558 * temp_f1_1558)) - 3.0);
                    temp_f1_1568 = 0.5 * temp_f1_1564 * -(((f64) var_f4_1552 * (temp_f1_1564 * temp_f1_1564)) - 3.0);
                    var_f4_1552 = (f32) ((f64) var_f4_1552 * (0.5 * temp_f1_1568 * -(((f64) var_f4_1552 * (temp_f1_1568 * temp_f1_1568)) - 3.0)));
                } else if (var_f4_1552 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1552 = __float_nan;
                } else {
                    sp10 = var_f4_1552;
                    temp_r3_1587 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_1587) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1597 = 1;
                        } else {
                            var_r0_1597 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1597 = 5;
                        } else {
                            var_r0_1597 = 3;
                        }
                        break;
                    default:
                        var_r0_1597 = 4;
                        break;
                    }
                    if (var_r0_1597 == 1) {
                        var_f4_1552 = __float_nan;
                    }
                }
                var_f3_1619 = 1.0f / var_f4_1552;
            } else {
                var_f3_1619 = 0.0f;
                var_f4_1552 = 0.0f;
            }
            var_f26_1625 = var_f4_1552 / 1000.0f;
            sp38 = (f32) sp38 * var_f3_1619;
            unksp3C *= var_f3_1619;
            sp40 = (f32) sp40 * var_f3_1619;
            if (var_f26_1625 < 2.0f) {

            } else {
                var_f26_1625 = 2.0f;
            }
            if (var_f26_1625 > 0.0f) {

            } else {
                var_f26_1625 = 0.0f;
            }
            temp_r6_1649 = *var_r31_1534;
            sp48 = 0.0f;
            sp4C = 1.0f;
            sp50 = 0.0f;
            temp_f25_1659 = 2.0f * (M2C_FIELD(temp_r6_1649, f32 *, 0x20) / M2C_FIELD(temp_r6_1649, f32 *, 0x24));
            KDMath_BuildMatrixFromFwd(&sp60, *((MKVector3 *) &sp38), (MKVector3 *) &sp48);
            sp18 = temp_f25_1659;
            sp1C = temp_f25_1659;
            sp20 = 2.0f * var_f26_1625;
            sp28 = (f64) sp18;
            sp30 = (f64) sp20;
            sp60.Scale3x3(&sp60, *((MKVector3 *) &sp28));
            temp_r3_1673 = *var_r31_1534;
            sp60.unk30 = temp_r3_1673->unk0;
            sp60.unk34 = temp_r3_1673->unk4;
            sp60.unk38 = temp_r3_1673->unk8;
            sp60.unk3C = 1.0f;
            MKModel_SetWorldMatrix(this->unk128, sp60);
            MKModel_Draw(this->unk128, NULL);
            var_r31_1534 += 4;
            goto loop_28;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void EarthBreathFX::UpdateSeedBullets() {
    f64 sp180;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    MKVector3 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    MKProp *var_r3_1840;
    MKVector3 **temp_r3_2149;
    MKVector3 **var_r29_1748;
    MKVector3 *temp_r3_1759;
    MKVector3 *temp_r3_1789;
    MKVector3 *temp_r3_1802;
    MKVector3 *temp_r3_1873;
    MKVector3 *temp_r3_1892;
    MKVector3 *temp_r3_1898;
    MKVector3 *temp_r3_1906;
    MKVector3 *temp_r3_2029;
    MKVector3 *temp_r3_2049;
    MKVector3 *temp_r3_2141;
    MKVector3 *temp_r3_2161;
    MKVector3 *temp_r4_1932;
    MKVector3 *temp_r4_2152;
    MKVector3 *temp_r5_1858;
    f32 temp_f0_1935;
    f32 temp_f1_1875;
    f32 temp_f1_2041;
    f32 temp_f1_2120;
    f32 temp_f21_2077;
    f32 temp_f22_2082;
    f32 temp_f29_1776;
    f32 temp_f2_1876;
    f32 temp_f2_1934;
    f32 temp_f3_1936;
    f32 var_f0_1877;
    f32 var_f0_1941;
    f32 var_f3_2008;
    f64 temp_f0_1782;
    f64 temp_f0_1806;
    f64 temp_f0_1817;
    f64 temp_f0_2064;
    f64 temp_f0_2096;
    f64 temp_f0_2108;
    f64 temp_f1_1859;
    f64 temp_f2_1947;
    f64 temp_f2_1953;
    f64 temp_f2_1957;
    s32 temp_r3_1976;
    s32 var_r0_1986;
    s32 var_r26_2058;
    u8 var_r28_1755;

    var_r29_1748 = this->unkC8;
loop_54:
    if (var_r29_1748 != NULL) {
        temp_r3_2161 = *var_r29_1748;
        if (temp_r3_2161 != NULL) {
            var_r28_1755 = 0;
            M2C_FIELD(temp_r3_2161, f32 *, 0x20) = (f32) (M2C_FIELD(temp_r3_2161, f32 *, 0x20) - gUpdateTimeDelta);
            temp_r3_1759 = *var_r29_1748;
            if (M2C_FIELD(temp_r3_1759, f32 *, 0x20) <= 0.0f) {
                var_r28_1755 = 1;
            } else if (((u8) M2C_FIELD(temp_r3_1759, u8 *, 0x28) == 0) || ((u8) M2C_FIELD(temp_r3_1759, u8 *, 0x29) == 0)) {
                temp_f29_1776 = gUpdateTimeDelta;
                MKVector(0.0f, -2000.0f, 0.0f);
                temp_f0_1782 = sp140 * (f64) temp_f29_1776;
                sp30 = temp_f0_1782;
                sp150 = temp_f0_1782;
                temp_r3_1789 = *var_r29_1748 + 0x10;
                sp38 = sp148 * temp_f29_1776;
                sp158 = (f64) sp38;
                M2C_FIELD(temp_r3_1789, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_1789, f64 *, 0) + temp_f0_1782);
                temp_r3_1789->unk8 += (f32) sp158;
                temp_r3_1802 = *var_r29_1748;
                temp_f0_1806 = *(temp_r3_1802 + 0x10) * (f64) gUpdateTimeDelta;
                spA0 = temp_f0_1806;
                sp130 = temp_f0_1806;
                spA8 = M2C_FIELD(temp_r3_1802, f32 *, 0x18) * gUpdateTimeDelta;
                sp138 = (f64) spA8;
                temp_f0_1817 = M2C_FIELD(temp_r3_1802, f64 *, 0) + temp_f0_1806;
                sp90 = temp_f0_1817;
                sp160 = temp_f0_1817;
                sp98 = temp_r3_1802->unk8 + (f32) sp138;
                sp168 = (f64) sp98;
                if (MKCollision_RayCollide(*temp_r3_1802, *((MKVector3 *) &sp160), (MKCollisionResult *) &sp170, (MKCollisionMode) 7, 0) != 0) {
                    if ((sp1C0 != 0) && (sp1B8 != NULL) && (var_r3_1840 = sp1B8->unk8, ((var_r3_1840 == NULL) == 0))) {

                    } else {
                        var_r3_1840 = NULL;
                    }
                    if (var_r3_1840 != NULL) {
                        M2C_FIELD(this, f64 *, 0xE0) = sp170;
                        M2C_FIELD(this, f64 *, 0xE8) = sp178;
                        this->unkD0.unk50 = 0;
                        this->unkD0.unk30 = sp1B8;
                        temp_r5_1858 = *var_r29_1748;
                        temp_f1_1859 = M2C_FIELD(temp_r5_1858, f64 *, 0x10);
                        M2C_FIELD(this, f64 *, 0xF0) = temp_f1_1859;
                        M2C_FIELD(this, f64 *, 0xF8) = (f64) M2C_FIELD(temp_r5_1858, f32 *, 0x18);
                        M2C_FIELD(var_r3_1840->__vptr, M2C_UNK (**)(BreathHitMessage *, MKVector3 *, f64), 0x2C)(&this->unkD0, temp_r5_1858, temp_f1_1859);
                        if ((u8) this->unkD0.unk50 != 0) {
                            var_r28_1755 = 1;
                        }
                    } else {
                        temp_r3_1873 = *var_r29_1748;
                        temp_f1_1875 = M2C_FIELD(temp_r3_1873, f32 *, 0x20);
                        temp_f2_1876 = M2C_FIELD(temp_r3_1873, f32 *, 0x24);
                        var_f0_1877 = (0.5f * temp_f1_1875) + temp_f1_1875;
                        if (var_f0_1877 < temp_f2_1876) {

                        } else {
                            var_f0_1877 = temp_f2_1876;
                        }
                        if (var_f0_1877 > 0.0f) {

                        } else {
                            var_f0_1877 = 0.0f;
                        }
                        M2C_FIELD(temp_r3_1873, f32 *, 0x20) = var_f0_1877;
                        temp_r3_1892 = *var_r29_1748;
                        if ((u8) M2C_FIELD(temp_r3_1892, u8 *, 0x28) != 0) {
                            M2C_FIELD(temp_r3_1892, u8 *, 0x29) = 1U;
                            temp_r3_1898 = *var_r29_1748;
                            M2C_FIELD(temp_r3_1898, f64 *, 0) = sp170;
                            M2C_FIELD(temp_r3_1898, f32 *, 8) = sp178;
                        }
                    }
                    if (var_r28_1755 == 0) {
                        temp_r3_1906 = *var_r29_1748;
                        if (((u8) M2C_FIELD(temp_r3_1906, u8 *, 0x28) == 0) || ((u8) M2C_FIELD(temp_r3_1906, u8 *, 0x29) == 0)) {
                            sp110.operator*(5.0f);
                            sp20 = sp170 + M2C_BITWISE(f64, sp110);
                            sp160 = sp20;
                            sp28 = (f32) sp178 + sp110.unk8;
                            sp120 = sp20;
                            sp168 = (f64) sp28;
                            temp_r4_1932 = *var_r29_1748;
                            sp128 = (f64) sp28;
                            temp_f2_1934 = (f32) M2C_FIELD(temp_r4_1932, f64 *, 0x10);
                            temp_f0_1935 = M2C_FIELD(temp_r4_1932, f32 *, 0x14);
                            temp_f3_1936 = M2C_FIELD(temp_r4_1932, f32 *, 0x18);
                            var_f0_1941 = (temp_f3_1936 * temp_f3_1936) + ((temp_f2_1934 * temp_f2_1934) + (temp_f0_1935 * temp_f0_1935));
                            if (var_f0_1941 > 0.000001f) {
                                if (var_f0_1941 > 0.0f) {
                                    temp_f2_1947 = __frsqrte(var_f0_1941);
                                    temp_f2_1953 = 0.5 * temp_f2_1947 * -(((f64) var_f0_1941 * (temp_f2_1947 * temp_f2_1947)) - 3.0);
                                    temp_f2_1957 = 0.5 * temp_f2_1953 * -(((f64) var_f0_1941 * (temp_f2_1953 * temp_f2_1953)) - 3.0);
                                    var_f0_1941 = (f32) ((f64) var_f0_1941 * (0.5 * temp_f2_1957 * -(((f64) var_f0_1941 * (temp_f2_1957 * temp_f2_1957)) - 3.0)));
                                } else if (var_f0_1941 < M2C_BITWISE(f32, 0.0)) {
                                    var_f0_1941 = __float_nan;
                                } else {
                                    sp8 = var_f0_1941;
                                    temp_r3_1976 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                                    switch (temp_r3_1976) { /* irregular */
                                    case 0x7F800000:
                                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                            var_r0_1986 = 1;
                                        } else {
                                            var_r0_1986 = 2;
                                        }
                                        break;
                                    case 0x0:
                                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                            var_r0_1986 = 5;
                                        } else {
                                            var_r0_1986 = 3;
                                        }
                                        break;
                                    default:
                                        var_r0_1986 = 4;
                                        break;
                                    }
                                    if (var_r0_1986 == 1) {
                                        var_f0_1941 = __float_nan;
                                    }
                                }
                                var_f3_2008 = 1.0f / var_f0_1941;
                            } else {
                                var_f3_2008 = 0.0f;
                                var_f0_1941 = 0.0f;
                            }
                            M2C_FIELD(temp_r4_1932, f64 *, 0x10) = (f32) ((f32) M2C_FIELD(temp_r4_1932, f64 *, 0x10) * var_f3_2008);
                            M2C_FIELD(temp_r4_1932, f32 *, 0x14) = (f32) (M2C_FIELD(temp_r4_1932, f32 *, 0x14) * var_f3_2008);
                            M2C_FIELD(temp_r4_1932, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r4_1932, f32 *, 0x18) * var_f3_2008);
                            if (var_f0_1941 < 1000.0f) {
                                var_r28_1755 = 1;
                            } else {
                                temp_r3_2029 = *var_r29_1748;
                                sp10 = *(temp_r3_2029 + 0x10) + sp180;
                                M2C_FIELD(temp_r3_2029, f64 *, 0x10) = sp10;
                                temp_f1_2041 = 0.75f * var_f0_1941;
                                sp18 = M2C_FIELD(temp_r3_2029, f32 *, 0x18) + sp188;
                                sp100 = sp10;
                                M2C_FIELD(temp_r3_2029, f32 *, 0x18) = (f64) sp18;
                                sp108 = (f64) sp18;
                                temp_r3_2049 = *var_r29_1748 + 0x10;
                                M2C_FIELD(temp_r3_2049, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_2049, f64 *, 0) * (f64) temp_f1_2041);
                                temp_r3_2049->unk8 *= temp_f1_2041;
                            }
                        }
                        var_r26_2058 = 0;
                        do {
                            temp_f0_2064 = sp180 * 5.28426686e-315;
                            sp70 = temp_f0_2064;
                            spC0 = temp_f0_2064;
                            sp78 = sp188 * 1.5f;
                            spC8 = (f64) sp78;
                            temp_f21_2077 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            temp_f22_2082 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            sp80 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            sp84 = temp_f22_2082;
                            sp88 = temp_f21_2077;
                            spD0 = (f64) sp80;
                            spD8 = (f64) sp88;
                            temp_f0_2096 = (f64) sp80 + temp_f0_2064;
                            sp60 = temp_f0_2096;
                            spE0 = temp_f0_2096;
                            sp68 = (f32) spD8 + (f32) spC8;
                            spE8 = (f64) sp68;
                            temp_f0_2108 = temp_f0_2096 * 5.56078426e-315;
                            sp50 = temp_f0_2108;
                            spF0 = temp_f0_2108;
                            sp58 = (f32) spE8 * 150.0f;
                            spF8 = (f64) sp58;
                            temp_f1_2120 = MKRand_Float(&gViewSeed, 2.0f, 3.0f);
                            sp40 = 0.0f;
                            sp44 = 1.0f;
                            spC = temp_f1_2120;
                            sp48 = 0.5f;
                            sp4C = 1.0f;
                            spB0 = (f64) sp40;
                            spB8 = (f64) sp48;
                            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &sp160), *((MKVector3 *) &spF0), spC, *((MKVector4 *) &spB0), -800.0f);
                            var_r26_2058 += 1;
                        } while (var_r26_2058 < 3);
                    }
                }
                temp_r3_2141 = *var_r29_1748;
                M2C_FIELD(temp_r3_2141, f64 *, 0) = sp160;
                M2C_FIELD(temp_r3_2141, f32 *, 8) = sp168;
            }
            if (var_r28_1755 != 0) {
                temp_r3_2149 = this->unkC8;
                this->unkC8 = temp_r3_2149 + 4;
                temp_r4_2152 = *temp_r3_2149;
                *temp_r3_2149 = *var_r29_1748;
                *var_r29_1748 = temp_r4_2152;
            }
            var_r29_1748 += 4;
            goto loop_54;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void *EarthBreathFX::SpawnSeedBullet(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, float arg3, bool arg4) {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKVector3 **temp_r8_2203;
    f64 temp_f0_2235;
    f64 temp_f0_2247;
    void *temp_r31_2216;

    temp_r8_2203 = this->unkC8;
    if ((void *) M2C_FIELD(temp_r8_2203, void **, -4) == NULL) {
        return NULL;
    }
    this->unkC8 = temp_r8_2203 - 4;
    temp_r31_2216 = M2C_FIELD(temp_r8_2203, void **, -4);
    if (temp_r31_2216 != NULL) {
        M2C_FIELD(temp_r31_2216, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r31_2216, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        MKVector(0.0f, 200.0f, 0.0f);
        sp38.operator*(3500.0f);
        temp_f0_2235 = sp38 + sp28;
        sp8 = temp_f0_2235;
        sp48 = temp_f0_2235;
        sp10 = sp38.unk8 + sp30;
        sp50 = (f64) sp10;
        temp_f0_2247 = sp48 + M2C_FIELD(&arg2, f64 *, 0);
        sp18 = temp_f0_2247;
        M2C_FIELD(temp_r31_2216, f64 *, 0x10) = temp_f0_2247;
        sp58 = temp_f0_2247;
        sp20 = (f32) sp50 + arg2.unk8;
        M2C_FIELD(temp_r31_2216, f64 *, 0x18) = (f64) sp20;
        M2C_FIELD(temp_r31_2216, f32 *, 0x20) = arg3;
        M2C_FIELD(temp_r31_2216, f32 *, 0x24) = arg3;
        M2C_FIELD(temp_r31_2216, u8 *, 0x28) = arg4;
        sp60 = (f64) sp20;
        M2C_FIELD(temp_r31_2216, s8 *, 0x29) = 0;
    }
    return temp_r31_2216;
}
#endif

#if 0 // DRAFT: type mismatch
void EarthBreathFX::Deinit() {
    MKHeap *temp_r3_2316;
    MKMaterial *temp_r3_2284;
    MKVector3 **var_r31_2290;
    MKVector3 **var_r3_2291;
    MKVector3 **var_r4_2289;
    MKVector3 *temp_r0_2294;
    MKVector3 *temp_r0_2313;
    ManagedLight *temp_r4_2335;
    u32 temp_r0_2299;

    temp_r3_2284 = this->unkB4;
    if (temp_r3_2284 != NULL) {
        MKMaterial_Destroy(temp_r3_2284);
    }
    var_r4_2289 = this->unkC8;
    var_r31_2290 = var_r4_2289;
    var_r3_2291 = var_r4_2289;
loop_5:
    temp_r0_2299 = M2C_FIELD(var_r3_2291, u32 *, -4);
    var_r3_2291 -= 4;
    if (temp_r0_2299 != 0U) {
        temp_r0_2294 = *var_r3_2291;
        if (temp_r0_2294 < var_r31_2290) {
            var_r31_2290 = (MKVector3 **) temp_r0_2294;
        }
        goto loop_5;
    }
    if (var_r3_2291 != &gEmptyPtrListDL) {
loop_11:
        temp_r0_2313 = *var_r4_2289;
        if (temp_r0_2313 != NULL) {
            if (temp_r0_2313 < var_r31_2290) {
                var_r31_2290 = (MKVector3 **) temp_r0_2313;
            }
            var_r4_2289 += 4;
            goto loop_11;
        }
        temp_r3_2316 = ((MKHeap *) var_r3_2291)->Current();
        if (temp_r3_2316 != NULL) {
            ((MKHeap *) (temp_r3_2316->Current()))->Free(var_r31_2290, NULL, 0);
        } else {
            free(var_r31_2290);
        }
    }
    this->unkC8 = NULL;
    MKModel_Destroy(this->unk128);
    MKModel_Destroy(M2C_FIELD(this, MKModel **, 0x140));
    temp_r4_2335 = this->unkB8;
    if (temp_r4_2335 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_2335);
    }
    BaseBreathFX::Deinit();
}
#endif

void EarthBreathFX::Draw() {
    DrawSeedBullets();
    DrawShotgunMuzzelFlash();
}

#if 0 // DRAFT: illegal explicit conversion from 'MKModel *' to
void EarthBreathFX::Update() {
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r3_2473;
    ManagedLight *temp_r4_2416;
    ManagedLight *temp_r4_2431;
    f32 temp_f3_2396;
    f32 var_f1_2453;
    void *temp_r3_2446;
    void *temp_r3_2482;

    BaseBreathFX::Update();
    this->unkBC -= gUpdateTimeDelta;
    this->unk128 = M2C_BITWISE(f32, this->unk128) - gUpdateTimeDelta;
    this->unk150.unk3C -= gUpdateTimeDelta;
    this->unk194 -= gUpdateTimeDelta;
    temp_f3_2396 = this->unkA8;
    if (temp_f3_2396 > 0.0f) {
        if (this->unkAC >= 0.25f) {
            this->unkA8 = 0.0f;
        } else {
            this->unkA8 = temp_f3_2396 - gUpdateTimeDelta;
        }
        this->unkAC += gUpdateTimeDelta;
    }
    temp_r4_2416 = this->unkB8;
    if (temp_r4_2416 != NULL) {
        if (M2C_BITWISE(f32, this->unk128) > 0.0f) {
            sp58.operator*(5000.0f);
            sp68.operator*(gUpdateTimeDelta);
            temp_r4_2431 = this->unkB8;
            sp18 = temp_r4_2431->unk10 + M2C_BITWISE(f64, sp68);
            temp_r4_2431->unk10 = sp18;
            sp20 = M2C_FIELD(temp_r4_2431, f32 *, 0x18) + sp68.unk8;
            sp78 = sp18;
            temp_r4_2431->unk18 = (f64) sp20;
            temp_r3_2446 = temp_r4_2431->unk3C;
            sp80 = (f64) sp20;
            if (temp_r3_2446 != NULL) {
                M2C_FIELD(temp_r3_2446, f64 *, 0x10) = sp18;
                M2C_FIELD(temp_r3_2446, f64 *, 0x18) = (f64) sp20;
            }
            var_f1_2453 = M2C_BITWISE(f32, this->unk128);
            if (var_f1_2453 < 0.25f) {

            } else {
                var_f1_2453 = 0.25f;
            }
            if (var_f1_2453 > 0.0f) {

            } else {
                var_f1_2453 = 0.0f;
            }
            sp8 = 0.0f;
            temp_r3_2473 = this->unkB8;
            sp10 = 0.0f;
            sp14 = 1.0f;
            spC = var_f1_2453 / 0.25f;
            sp50 = (f64) sp10;
            temp_r3_2473->unk20 = (f64) sp8;
            temp_r3_2473->unk28 = (f64) sp10;
            temp_r3_2482 = temp_r3_2473->unk3C;
            sp48 = (f64) sp8;
            if (temp_r3_2482 != NULL) {
                M2C_FIELD(temp_r3_2482, f64 *, 0) = (f64) sp8;
                M2C_FIELD(temp_r3_2482, f64 *, 8) = (f64) sp10;
            }
        } else {
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_2416, 0U);
        }
    }
    if (((u8) M2C_FIELD(this, u8 *, 0x198) != 0) && (this->unk194 <= 0.0f)) {
        sp30 = 0.0f;
        sp98 = M2C_FIELD(this, f64 *, 0x180);
        spA0 = M2C_FIELD(this, f64 *, 0x188);
        sp28 = 0.0f;
        sp2C = 0.0f;
        sp88 = M2C_FIELD(this, f64 *, 0x160);
        sp90 = M2C_FIELD(this, f64 *, 0x168);
        sp38 = (f64) sp28;
        sp40 = (f64) sp30;
        ShootShotgun(*((MKVector3 *) &sp98), *((MKVector3 *) &sp88), *((MKVector3 *) &sp38));
        M2C_FIELD(this, u8 *, 0x198) = 0U;
    }
    UpdateSeedBullets();
    this->unkB0 = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void EarthBreathFX::Resolve() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r4_2583;

    MKProp::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 0.0f;
    spC = 0.5f;
    sp10 = 0.0f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    this->unkB8 = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 1000.0f, lit_777, lit_778);
    temp_r4_2583 = this->unkB8;
    if (temp_r4_2583 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_2583, 0U);
    }
    this->unk150.unk38 = M2C_BITWISE(f32, checked_cast<EarthBombFXDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, s8 *), 0x5C)(gMK, "EarthBombFX")));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void EarthBreathFX::Init() {
    EarthBombFX *temp_r3_2717;
    MKHeap *temp_r3_2627;
    MKMaterial *temp_r3_2620;
    MKVector3 **temp_r3_2649;
    MKVector3 **temp_r4_2655;
    MKVector3 **var_r3_2634;
    MKVector3 **var_r5_2643;
    s32 var_ctr_2647;
    s32 var_r29_2710;

    BaseBreathFX::Init();
    this->unkB0 = 0;
    temp_r3_2620 = MKMaterial_Create("fx_348");
    this->unkB4 = temp_r3_2620;
    this->unkB8 = NULL;
    this->unkA8 = 0.0f;
    this->unkAC = 0.0f;
    temp_r3_2627 = ((MKHeap *) temp_r3_2620)->Current();
    if (temp_r3_2627 != NULL) {
        var_r3_2634 = ((MKHeap *) (temp_r3_2627->Current()))->Alloc(0x28A8, NULL, 0);
    } else {
        var_r3_2634 = malloc(0x28A8);
    }
    this->unkC8 = var_r3_2634;
    var_r5_2643 = this->unkC8;
    this->unkC8 = var_r5_2643 + 0x2580;
    M2C_FIELD(var_r5_2643, s32 *, 0x2580) = 0;
    var_ctr_2647 = 0xC8;
    do {
        temp_r3_2649 = this->unkC8;
        this->unkC8 = temp_r3_2649 + 4;
        M2C_FIELD(temp_r3_2649, MKVector3 ***, 4) = var_r5_2643;
        var_r5_2643 += 0x30;
        var_ctr_2647 -= 1;
    } while (var_ctr_2647 != 0);
    temp_r4_2655 = this->unkC8;
    this->unkC8 = temp_r4_2655 + 4;
    M2C_FIELD(temp_r4_2655, MKVector3 ***, 4) = NULL;
    this->unkBC = 0.0f;
    this->unk128 = MKModel_Create("FX0018_EarthShot", NULL, 2, NULL);
    this->unkC0 = checked_cast<FuryFXEarth *, MKProp>(((MKSceneManager *) gMK)->CreateProp("FuryFXEarth"));
    this->unkC4 = checked_cast<FuryFXEarth2 *, MKProp>(((MKSceneManager *) gMK)->CreateProp("FuryFXEarth2"));
    this->unk128 = 0.0f;
    M2C_STRUCT_COPY((s32) &this->unk14C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    M2C_FIELD(this, MKModel **, 0x140) = MKModel_Create("Fx0022_EarthShot_Flash", NULL, 2, NULL);
    var_r29_2710 = 0;
    this->unk150.unk3C = 0.0f;
    this->unk150.unk38 = 0.0f;
    do {
        temp_r3_2717 = checked_cast<EarthBombFX *, MKProp>(((MKSceneManager *) gMK)->CreateProp("EarthBombFX"));
        if (temp_r3_2717 != NULL) {
            M2C_FIELD(temp_r3_2717->__vptr, M2C_UNK (**)(), 0x34)();
        }
        var_r29_2710 += 1;
    } while (var_r29_2710 < 8);
    M2C_FIELD(this, s8 *, 0x198) = 0;
    this->unk194 = 0.0f;
}
#endif
