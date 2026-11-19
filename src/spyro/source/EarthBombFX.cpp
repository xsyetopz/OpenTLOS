#include "spyro/source/EarthBombFX.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EarthBreathWhirlWinds.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/ExplosionWarpFX.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/HeatDistortPS.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_SpyroEarthAttack5LP;
extern s32 GS_SpyroEarthAttackImpact1;
extern s32 GS_SpyroEarthAttackImpact2;
extern s32 GS_SpyroEarthAttackImpact3;
extern s32 GS_SpyroEarthAttackImpact4;
extern void **gMK;
extern s32 gRenderState;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;

static s32 lit_728 = 0;
static u8 lit_729 = 1;

#if 0 // DRAFT: undefined identifier 'arg_sp1C'
void EarthBombFX::Fire(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3, const MKVector3 &arg4) {
    ManagedLight *temp_r4_97;
    f32 temp_f31_159;
    f64 temp_f1_176;
    s32 temp_r30_111;
    s32 temp_r31_114;
    s32 temp_r4_112;
    s32 var_r26_149;
    s32 var_r6_130;
    u8 var_r4_120;
    u8 var_r4_139;
    void *temp_r3_186;
    void *temp_r5_116;
    M2C_STRUCT_COPY((s32) &arg_sp1C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    arg_sp20.Scale3x3((Matrix *) &arg_sp20, 2.0f);
    arg_sp50 = arg0.unk0;
    arg_sp54 = arg0.unk4;
    arg_sp58 = arg0.unk8;
    arg_sp5C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp20));
    this->unkE0 = 1;
    this->unk118 = arg3;
    this->unkF8 = 0.0f;
    this->unkFC = 0.0f;
    this->unk120 = arg2;
    this->unkC8 = 10.0f;
    temp_r4_97 = this->unk100;
    if (temp_r4_97 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_97, 1U);
    }
    this->unk11C = 10000.0f;
    temp_r30_111 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
    temp_r4_112 = temp_r30_111 << 5;
    temp_r31_114 = *(&GameData::gameData[0x70] + (temp_r4_112 + 0x7C));
    temp_r5_116 = &GameData::gameData[0x70] + (temp_r4_112 + 0x64);
    if (temp_r31_114 == 3) {
        var_r4_120 = 0;
        if (((s32) M2C_FIELD(temp_r5_116, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_116, s32 *, 4) == 3)) {
            var_r4_120 = 1;
        }
        var_r6_130 = var_r4_120 != 0;
    } else {
        var_r6_130 = *(temp_r5_116 + (temp_r31_114 * 4));
    }
    if (temp_r31_114 == 3) {
        var_r4_139 = 0;
        if (((s32) M2C_FIELD(temp_r5_116, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_116, s32 *, 4) == 3)) {
            var_r4_139 = 1;
        }
        var_r26_149 = var_r4_139 != 0;
    } else {
        var_r26_149 = *(temp_r5_116 + (temp_r31_114 * 4));
    }
    temp_f31_159 = ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetBreathAttackDamage(temp_r30_111, temp_r31_114, var_r6_130);
    this->unk128.Init(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), temp_f31_159, temp_r31_114, var_r26_149, temp_r30_111, temp_r30_111, 0, -1);
    temp_f1_176 = M2C_FIELD(&arg1, f64 *, 0);
    this->unkD0 = temp_f1_176;
    this->unkD8 = M2C_FIELD(&arg1, f64 *, 8);
    temp_r3_186 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **, f64), 0x34)(M2C_FIELD(&gb, void ***, 0), temp_f1_176);
    arg_sp10 = temp_r3_186;
    if (temp_r3_186 != NULL) {
        arg_sp14 = M2C_FIELD(temp_r3_186, u8 *, 4);
        M2C_FIELD(temp_r3_186, u8 *, 4) = 0U;
    }
    arg_sp60 = 0.0f;
    arg_sp64 = 0.0f;
    arg_sp68 = 0.0f;
    arg_sp70 = 0.0f;
    arg_sp74 = 0.0f;
    arg_sp78 = 0.0f;
    arg_sp80 = 0.0f;
    arg_sp84 = 0.0f;
    arg_sp88 = 0.0f;
    arg_sp8C = 1.0f;
    arg_sp90 = 0.0f;
    arg_sp94 = 0.0f;
    arg_sp98 = 0;
    arg_sp98 = 0;
    (s8) arg_sp98 = 0;
    arg_sp9C = 0;
    arg_spA0 = 3.4028235e38f;
    arg_spA4 = 0;
    arg_spA8 = NULL;
    arg_spAC = -1;
    arg_spB0 = 0;
    if (MKCollision_SphereCollide(arg0, 50.0f, (MKCollisionResult *) &arg_sp60, 1, (MKCollisionMode) 7, 0) != 0) {
        Explode(MKVector3::up, *((MKVector3 *) &arg_sp60), arg_spA8);
    }
    if (arg_sp10 != NULL) {
        M2C_FIELD(arg_sp10, u8 *, 4) = arg_sp14;
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void EarthBombFX::Deinit() {
    ManagedLight *temp_r4_261;

    temp_r4_261 = this->unk100;
    if (temp_r4_261 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_261, 0U);
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(this->unk100);
    }
    KDSound_Stop(&this->unk180);
    GameProp::Deinit();
}
#endif

#if 0 // DRAFT: ')' expected
void EarthBombFX::Draw() {
    if ((u8) this->unkE0 != 0) {
        gRenderState = M2C_FIELD(checked_cast<EarthBombFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xEC);
        GameProp::Draw();
        gRenderState = 0;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'BreathHitMessage *' to
void EarthBombFX::Explode(const MKVector3 &arg0, const MKVector3 &arg1, MKCollisionInfo *arg2) {
    MKProp *temp_r3_366;
    MKVector3 *temp_r27_547;
    ManagedLight *temp_r4_521;
    f32 temp_f0_664;
    f32 temp_f19_549;
    f32 temp_f20_554;
    f32 temp_f20_596;
    f32 temp_f2_1073;
    f32 temp_f4_1032;
    f32 var_f0_760;
    f32 var_f23_378;
    f32 var_f24_374;
    f32 var_f25_372;
    f32 var_f26_377;
    f32 var_f27_375;
    f32 var_f4_810;
    f64 temp_f1_361;
    f64 temp_f1_815;
    f64 temp_f1_821;
    f64 temp_f1_825;
    f64 temp_f2_504;
    s32 temp_r0_373;
    s32 temp_r3_844;
    s32 var_r0_854;
    s32 var_r26_539;
    s32 var_r27_687;
    void *temp_r26_634;
    void *temp_r28_535;
    void *temp_r3_625;
    void *temp_r3_629;
    void *temp_r4_766;
    void *temp_r4_990;
    this->unkE0 = 0;
    if ((arg2 != NULL) && ((MKProp *) arg2->unk8 != NULL)) {
        this->unk128.unk50 = 0;
        temp_f1_361 = M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(this, f64 *, 0x138) = temp_f1_361;
        M2C_FIELD(this, f64 *, 0x140) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        this->unk128.unk30 = arg2;
        temp_r3_366 = arg2->unk8;
        temp_r3_366->Message(&this->unk128, temp_f1_361);
    }
    var_f25_372 = 1.0f;
    temp_r0_373 = this->unk128.unk3C;
    var_f24_374 = M2C_ERROR(/* unknown instruction: ps_mr $f24, $f25 */);
    var_f27_375 = 0.5f;
    var_f26_377 = 30.0f;
    var_f23_378 = 2.0f;
    switch (temp_r0_373) {                          /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        KDSound_Play3d(GS_SpyroEarthAttackImpact1, &arg1, 0U, -1, 0.0f, 0U);
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.5f, 0.3f, 0.3f, &arg1, 100.0f, 0, 4.0f, 0U);
        var_f25_372 = 1.0f;
        var_f27_375 = 0.5f;
        var_f24_374 = M2C_ERROR(/* unknown instruction: ps_mr $f24, $f25 */);
        var_f26_377 = 8.0f;
        var_f23_378 = 2.0f;
        break;
    case 1:                                         /* switch 1 */
        KDSound_Play3d(GS_SpyroEarthAttackImpact2, &arg1, 0U, -1, 0.0f, 0U);
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.7f, 0.5f, 0.3f, &arg1, 100.0f, 0, 4.0f, 0U);
        var_f27_375 = 1.0f;
        var_f26_377 = 15.0f;
        var_f25_372 = 1.5f;
        var_f24_374 = 2.0f;
        var_f23_378 = 4.0f;
        break;
    case 2:                                         /* switch 1 */
        KDSound_Play3d(GS_SpyroEarthAttackImpact3, &arg1, 0U, -1, 0.0f, 0U);
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.9f, 0.8f, 0.3f, &arg1, 100.0f, 0, 4.0f, 0U);
        /* fallthrough */
    case 3:                                         /* switch 1 */
        KDSound_Play3d(GS_SpyroEarthAttackImpact4, &arg1, 0U, -1, 0.0f, 0U);
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(1.0f, 1.0f, 0.3f, &arg1, 100.0f, 0, 4.0f, 0U);
        var_f27_375 = 2.5f;
        var_f26_377 = 30.0f;
        var_f25_372 = 3.0f;
        var_f24_374 = 3.5f;
        var_f23_378 = 6.0f;
        break;
    }
    temp_f2_504 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk128.unk50 = 0;
    this->unk128.unk30 = NULL;
    arg_sp370 = temp_f2_504;
    arg_sp378 = M2C_FIELD(&arg1, f64 *, 8);
    M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32, f64), 0x94)(gMK, &this->unk128, 0, 1, &arg_sp370, 1, 750.0f, temp_f2_504);
    temp_r4_521 = this->unk100;
    if (temp_r4_521 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_521, 0U);
    }
    temp_r28_535 = checked_cast<EarthBombFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r26_539 = 0;
loop_18:
    if ((f32) var_r26_539 < (30.0f * var_f25_372)) {
        temp_r27_547 = this->unk8 + 0x30;
        temp_f19_549 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f20_554 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        arg_sp170 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        arg_sp174 = temp_f20_554;
        arg_sp178 = temp_f19_549;
        arg_sp2E0 = (f64) arg_sp170;
        arg_sp2E8 = (f64) arg_sp178;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        arg_sp2F0 = arg_sp160;
        arg_sp168 = (f32) arg_sp2E8 * 1000.0f;
        arg_sp2F8 = (f64) arg_sp168;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
        arg_sp300 = arg_sp150;
        arg_sp158 = (f32) arg_sp2F8 * var_f25_372;
        arg_sp308 = (f64) arg_sp158;
        arg_sp18 = MKRand_Float(&gViewSeed, 25.0f, 35.0f);
        temp_f20_596 = MKRand_Float(&gViewSeed, 0.0f, 0.2f);
        arg_sp140 = MKRand_Float(&gViewSeed, 0.0f, 0.2f);
        arg_sp144 = 1.0f;
        arg_sp148 = temp_f20_596;
        arg_sp14C = 1.0f;
        arg_sp2D0 = (f64) arg_sp140;
        arg_sp2D8 = (f64) arg_sp148;
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*temp_r27_547, *((MKVector3 *) &arg_sp300), arg_sp18, *((MKVector4 *) &arg_sp2D0), -980.0f);
        var_r26_539 += 1;
        goto loop_18;
    }
    temp_r3_625 = M2C_FIELD(temp_r28_535, void **, 0xE8);
    temp_r3_629 = M2C_FIELD(M2C_FIELD(temp_r3_625, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_625);
    if (temp_r3_629 != NULL) {
        temp_r26_634 = M2C_FIELD(temp_r3_629, void **, 0x2C);
        MKVector(0.0f, 100.0f, 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(temp_r3_629, f64 *, 0) = arg_sp80;
        arg_sp88 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + arg_sp2B8;
        arg_sp2C0 = arg_sp80;
        M2C_FIELD(temp_r3_629, f64 *, 8) = (f64) arg_sp88;
        M2C_FIELD(temp_r3_629, f32 *, 0x20) = 0.0f;
        arg_sp2C8 = (f64) arg_sp88;
        M2C_FIELD(temp_r3_629, f32 *, 0x28) = 0.0f;
        temp_f0_664 = 3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        arg_sp78 = 0.0f;
        arg_sp70 = 0.0f;
        arg_sp74 = 0.0f;
        M2C_FIELD(temp_r3_629, f32 *, 0x24) = (f32) (2.0f * temp_f0_664);
        M2C_FIELD(temp_r26_634, f64 *, 0) = (f64) arg_sp70;
        M2C_FIELD(temp_r26_634, f64 *, 8) = (f64) arg_sp78;
        arg_sp2A0 = (f64) arg_sp70;
        arg_sp2A8 = (f64) arg_sp78;
        M2C_FIELD(temp_r26_634, f32 *, 0x18) = var_f26_377;
        M2C_FIELD(temp_r26_634, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r26_634, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r28_535, void **, 0xE8), f32 *, 0xF4);
    }
    var_r27_687 = 0;
    do {
        MKVector(0.0f, 100.0f, 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp48 = 1.0f;
        arg_sp58 = -1.0f;
        arg_sp68 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + arg_sp288;
        arg_sp40 = 1.0f;
        arg_sp44 = 1.0f;
        arg_sp50 = -1.0f;
        arg_sp54 = 0.25f;
        arg_sp290 = arg_sp60;
        arg_sp298 = (f64) arg_sp68;
        arg_sp360 = arg_sp60;
        arg_sp368 = (f64) arg_sp68;
        arg_sp250 = (f64) arg_sp40;
        arg_sp258 = (f64) arg_sp48;
        arg_sp260 = (f64) arg_sp50;
        arg_sp268 = (f64) arg_sp58;
        KDRand_Vector(*((MKVector3 *) &arg_sp270), *((MKVector3 *) &arg_sp260));
        arg_sp350 = arg_sp270;
        arg_sp358 = arg_sp278;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        arg_sp240 = arg_sp130;
        arg_sp138 = (f32) arg_sp358 * 300.0f;
        arg_sp248 = (f64) arg_sp138;
        arg_sp14 = MKRand_Int(&gViewSeed, 0, 3);
        ((FallingLeaves *) (M2C_FIELD(temp_r28_535, FallingLeaves **, 0xE4)))->Emit(*((MKVector3 *) &arg_sp360), *((MKVector3 *) &arg_sp240), 2.0f, arg_sp14, 1U);
        var_r27_687 += 1;
    } while (var_r27_687 < 5);
    var_f0_760 = 0.0f;
    arg_sp120 = 0.0f;
    temp_r4_766 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    arg_sp124 = 200.0f;
    arg_sp128 = 0.0f;
    arg_sp210 = (f64) arg_sp120;
    arg_sp340 = M2C_FIELD(temp_r4_766, f64 *, 0x30);
    arg_sp348 = M2C_FIELD(temp_r4_766, f64 *, 0x38);
    arg_sp218 = (f64) arg_sp128;
    M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
    arg_sp220 = arg_sp110;
    arg_sp118 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) arg_sp218;
    arg_sp228 = (f64) arg_sp118;
    M2C_ERROR(/* unknown instruction: ps_sub $f1, $f2, $f1 */);
    arg_sp230 = arg_sp100;
    arg_sp108 = (f32) arg_sp228 - (f32) arg_sp348;
    arg_sp238 = (f64) arg_sp108;
    var_f4_810 = ((f32) arg_sp238 * (f32) arg_sp238) + (((f32) arg_sp230 * (f32) arg_sp230) + (arg_sp234 * arg_sp234));
    if (var_f4_810 > 1e-12f) {
        if (var_f4_810 > 0.0f) {
            temp_f1_815 = __frsqrte(var_f4_810);
            temp_f1_821 = 0.5 * temp_f1_815 * -(((f64) var_f4_810 * (temp_f1_815 * temp_f1_815)) - 3.0);
            temp_f1_825 = 0.5 * temp_f1_821 * -(((f64) var_f4_810 * (temp_f1_821 * temp_f1_821)) - 3.0);
            var_f4_810 = (f32) ((f64) var_f4_810 * (0.5 * temp_f1_825 * -(((f64) var_f4_810 * (temp_f1_825 * temp_f1_825)) - 3.0)));
        } else if (var_f4_810 < M2C_BITWISE(f32, 0.0)) {
            var_f4_810 = __float_nan;
        } else {
            arg_sp10 = var_f4_810;
            temp_r3_844 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_844) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_854 = 1;
                } else {
                    var_r0_854 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_854 = 5;
                } else {
                    var_r0_854 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_854 = 4;
                break;
            }
            if (var_r0_854 == 1) {
                var_f4_810 = __float_nan;
            }
        }
        var_f0_760 = 1.0f / var_f4_810;
    }
    arg_spF4 = arg_sp234 * var_f0_760;
    arg_spF0 = (f32) arg_sp230 * var_f0_760;
    arg_spF8 = (f32) arg_sp238 * var_f0_760;
    arg_sp330 = (f64) arg_spF0;
    arg_sp338 = (f64) arg_spF8;
    M2C_STRUCT_COPY((s32) &arg_sp39C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    arg_spE8 = 0.0f;
    arg_spE0 = 0.0f;
    arg_spE4 = 1.0f;
    arg_sp328 = (f64) arg_spE8;
    arg_sp320 = (f64) arg_spE0;
    KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp3A0, *((MKVector3 *) &arg_sp330), (MKVector3 *) &arg_sp320);
    arg_sp3A0.Scale3x3((Matrix *) &arg_sp3A0, var_f27_375);
    MKVector(0.0f, 100.0f * var_f27_375, 0.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp200 = arg_sp30;
    arg_sp38 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + arg_sp1F8;
    arg_sp208 = (f64) arg_sp38;
    arg_sp3D0 = (f32) arg_sp200;
    arg_sp3D4 = arg_sp204;
    arg_sp3D8 = (f32) arg_sp208;
    arg_sp3DC = 1.0f;
    ((ExplosionWarpFX *) ((ExplosionWarpFX *) (&gb + 0x1C0)))->StartWarp((Matrix *) &arg_sp3A0);
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        arg_sp384 = 0;
        MKVector(1.0f, 1.0f, 1.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        arg_sp380 = 0x417;
        arg_sp388 = arg_sp20;
        arg_sp28 = arg_sp1D8 * 250.0f;
        arg_sp398 = 1;
        arg_sp390 = (f64) arg_sp28;
        arg_sp1E0 = arg_sp20;
        arg_sp1E8 = (f64) arg_sp28;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp380, arg_sp20);
    }
    temp_r4_990 = this->unk8;
    arg_spB0 = 0.0f;
    arg_spB4 = -1000.0f;
    arg_spB8 = 0.0f;
    arg_sp310 = M2C_FIELD(temp_r4_990, f64 *, 0x30);
    arg_sp318 = M2C_FIELD(temp_r4_990, f64 *, 0x38);
    arg_sp3E0 = 0.0f;
    arg_sp3E4 = 0.0f;
    arg_sp3E8 = 0.0f;
    arg_sp3F0 = 0.0f;
    arg_sp3F4 = 0.0f;
    arg_sp3F8 = 0.0f;
    arg_sp400 = 0.0f;
    arg_sp404 = 0.0f;
    arg_sp408 = 0.0f;
    arg_sp40C = 1.0f;
    arg_sp410 = 0.0f;
    arg_sp414 = 0.0f;
    arg_sp418 = 0;
    arg_sp418 = 0;
    (s8) arg_sp418 = 0;
    arg_sp41C = 0;
    arg_sp420 = 3.4028235e38f;
    arg_sp424 = 0;
    arg_sp428 = 0;
    arg_sp42C = -1;
    arg_sp430 = 0;
    arg_sp190 = (f64) arg_spB0;
    arg_sp198 = (f64) arg_spB8;
    M2C_ERROR(/* unknown instruction: psq_lx $f5, $zero, $r5, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
    arg_spD8 = 0.0f;
    temp_f4_1032 = (f32) M2C_FIELD(temp_r4_990, f64 *, 0x38);
    arg_spD0 = 0.0f;
    arg_spD4 = 100.0f;
    arg_spA8 = temp_f4_1032 + (f32) arg_sp198;
    arg_sp1B0 = (f64) arg_spD0;
    arg_sp1A0 = arg_spA0;
    arg_sp1A8 = (f64) arg_spA8;
    arg_sp1B8 = (f64) arg_spD8;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
    arg_sp1C0 = arg_spC0;
    arg_spC8 = temp_f4_1032 + (f32) arg_sp1B8;
    arg_sp1C8 = (f64) arg_spC8;
    if (MKCollision_RayCollide(*((MKVector3 *) &arg_sp1C0), *((MKVector3 *) &arg_sp1A0), (MKCollisionResult *) &arg_sp3E0, (MKCollisionMode) 4, 0x0C000000) == 0) {
        arg_sp310 = (f64) arg_sp3E0;
        arg_sp318 = (f64) arg_sp3E8;
    }
    temp_f2_1073 = 2.0f * var_f24_374;
    arg_sp98 = temp_f2_1073;
    arg_sp90 = temp_f2_1073;
    arg_sp94 = temp_f2_1073;
    arg_sp188 = (f64) arg_sp98;
    arg_sp180 = (f64) arg_sp90;
    ((EarthBreathWhirlWinds *) (M2C_FIELD(&gb, EarthBreathWhirlWinds **, 0x2C8)))->SpawnWhirlWind(*((MKVector3 *) &arg_sp310), *((MKVector3 *) &arg_sp180), (Upgrade) this->unk128.unk3C, 1U, var_f23_378);
    Disable();
}
#endif

#if 0 // DRAFT: expression syntax error
void EarthBombFX::Message(MKMessage *arg0) {
    this->unk180.Message(arg0);
    GameProp::Message(arg0);
}
#endif

#if 0 // DRAFT: expression syntax error
void EarthBombFX::Update() {
    u8 sp388;
    s32 sp384;
    MKCollisionInfo *sp380;
    s32 sp37C;
    f32 sp378;
    s32 sp374;
    s8 sp373;
    s8 sp372;
    s16 sp370;
    f32 sp36C;
    f32 sp368;
    f32 sp364;
    f32 sp360;
    f32 sp35C;
    f32 sp358;
    f32 sp350;
    f32 sp34C;
    f32 sp348;
    f32 sp340;
    f32 sp33C;
    f32 sp338;
    f64 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    MKVector3 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    MKVector3 sp248;
    f64 sp240;
    f64 sp238;
    M2C_UNK sp228;
    f64 sp220;
    f64 sp218;
    MKVector3 sp208;
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
    MKVector4 sp1A8;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp180;
    f32 sp170;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
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
    f32 spB0;
    f32 spA0;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    s32 sp14;
    f32 sp10;
    s32 sp8;
    MKProp *var_r28_1472;
    ManagedLight *temp_r3_1591;
    ManagedLight *temp_r3_1720;
    ManagedLight *temp_r3_1737;
    f32 temp_f0_1738;
    f32 temp_f1_1590;
    f32 temp_f1_1620;
    f32 temp_f2_1192;
    f32 temp_f30_1288;
    f32 temp_f30_1355;
    f32 temp_f31_1350;
    f32 temp_f4_1612;
    f32 temp_f5_1201;
    f32 var_f4_1374;
    f32 var_f4_1441;
    f32 var_f6_1185;
    f32 var_f8_1604;
    f64 temp_f0_1270;
    f64 temp_f1_1380;
    f64 temp_f1_1386;
    f64 temp_f1_1390;
    f64 temp_f2_1269;
    s32 temp_r3_1409;
    s32 var_r0_1419;
    u8 var_r30_1316;
    void *temp_r31_1166;
    void *temp_r3_1596;
    void *temp_r3_1725;
    void *temp_r3_1740;
    void *temp_r5_1265;

    temp_r31_1166 = checked_cast<EarthBombFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = 1;
    this->unk180.Update(GS_SpyroEarthAttack5LP, 1U, this->unkE0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if ((u8) this->unkE0 != 0) {
        var_f6_1185 = 0.5f * (0.85f * gUpdateTimeDelta);
        if (var_f6_1185 < 1.0f) {

        } else {
            var_f6_1185 = 1.0f;
        }
        temp_f2_1192 = this->unkC8;
        sp1A0 = -1.0f;
        temp_f5_1201 = (var_f6_1185 * (150.0f - temp_f2_1192)) + temp_f2_1192;
        sp190 = 1.0f;
        sp198 = -1.0f;
        sp19C = -1.0f;
        sp188 = 1.0f;
        sp18C = 1.0f;
        this->unkC8 = (var_f6_1185 * (150.0f - temp_f5_1201)) + temp_f5_1201;
        sp288 = (f64) sp198;
        sp290 = (f64) sp1A0;
        sp278 = (f64) sp188;
        sp280 = (f64) sp190;
        KDRand_Vector(sp298, *((MKVector3 *) &sp288));
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp2A8 = sp178;
        sp180 = sp298.unk8 * 50.0f;
        sp2B0 = (f64) sp180;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp2B8 = sp168;
        sp170 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) sp2B0;
        sp2C0 = (f64) sp170;
        sp15C = MKRand_Float(&gViewSeed, 100.0f, 200.0f);
        sp158 = 0.0f;
        sp160 = 0.0f;
        sp268 = (f64) sp158;
        sp270 = (f64) sp160;
        ((HeatDistortPS *) ((HeatDistortPS *) (&gb + 0x240)))->Emit(*((MKVector3 *) &sp2B8), *((MKVector3 *) &sp268), 3.0f, 1.0f);
        temp_r5_1265 = this->unk8;
        temp_f2_1269 = M2C_FIELD(temp_r5_1265, f64 *, 0x30);
        temp_f0_1270 = M2C_FIELD(temp_r5_1265, f64 *, 0x38);
        sp328 = temp_f2_1269;
        sp330 = temp_f0_1270;
        sp318 = temp_f2_1269;
        sp320 = temp_f0_1270;
        sp248.operator*(gUpdateTimeDelta);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp258 = spA8;
        temp_f30_1288 = gUpdateTimeDelta;
        spB0 = (f32) sp330 + sp248.unk8;
        sp318 = spA8;
        sp260 = (f64) spB0;
        sp320 = (f64) spB0;
        MKVector(0.0f, -1960.0f, 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp238 = sp98;
        spA0 = sp230 * temp_f30_1288;
        sp240 = (f64) spA0;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r29, $r0, 0x0, qr0 */);
        var_r30_1316 = 0;
        M2C_FIELD(this, f32 *, 0xD8) = (f32) (M2C_FIELD(this, f32 *, 0xD8) + (f32) sp240);
        sp338 = 0.0f;
        sp33C = 0.0f;
        sp340 = 0.0f;
        sp348 = 0.0f;
        sp34C = 0.0f;
        sp350 = 0.0f;
        sp358 = 0.0f;
        sp35C = 0.0f;
        sp360 = 0.0f;
        sp364 = 1.0f;
        sp368 = 0.0f;
        sp36C = 0.0f;
        sp370 = 0;
        sp372 = 0;
        sp373 = 0;
        sp374 = 0;
        sp378 = 3.4028235e38f;
        sp37C = 0;
        sp380 = NULL;
        sp384 = -1;
        sp388 = 0;
        sp308 = sp318;
        sp310 = (f64) spB0;
        temp_f31_1350 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f30_1355 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp148 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp14C = temp_f30_1355;
        sp150 = temp_f31_1350;
        sp218 = (f64) sp148;
        sp220 = (f64) sp150;
        var_f4_1374 = ((f32) sp220 * (f32) sp220) + (((f32) sp218 * (f32) sp218) + (unksp21C * unksp21C));
        if (var_f4_1374 > 1e-12f) {
            if (var_f4_1374 > 0.0f) {
                temp_f1_1380 = __frsqrte(var_f4_1374);
                temp_f1_1386 = 0.5 * temp_f1_1380 * -(((f64) var_f4_1374 * (temp_f1_1380 * temp_f1_1380)) - 3.0);
                temp_f1_1390 = 0.5 * temp_f1_1386 * -(((f64) var_f4_1374 * (temp_f1_1386 * temp_f1_1386)) - 3.0);
                var_f4_1374 = (f32) ((f64) var_f4_1374 * (0.5 * temp_f1_1390 * -(((f64) var_f4_1374 * (temp_f1_1390 * temp_f1_1390)) - 3.0)));
            } else if (var_f4_1374 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1374 = __float_nan;
            } else {
                sp10 = var_f4_1374;
                temp_r3_1409 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1409) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1419 = 1;
                    } else {
                        var_r0_1419 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1419 = 5;
                    } else {
                        var_r0_1419 = 3;
                    }
                    break;
                default:
                    var_r0_1419 = 4;
                    break;
                }
                if (var_r0_1419 == 1) {
                    var_f4_1374 = __float_nan;
                }
            }
            var_f4_1441 = 1.0f / var_f4_1374;
        } else {
            var_f4_1441 = 0.0f;
        }
        sp13C = unksp21C * var_f4_1441;
        sp138 = (f32) sp218 * var_f4_1441;
        sp140 = (f32) sp220 * var_f4_1441;
        sp2F8 = (f64) sp138;
        sp300 = (f64) sp140;
        if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp328), *((MKVector3 *) &sp318), 40.0f, (MKCollisionResult *) &sp338, (MKCollisionMode) 7, 0) != 0) {
            if ((sp388 != 0) && (sp380 != NULL) && (var_r28_1472 = sp380->unk8, ((var_r28_1472 == NULL) == 0))) {

            } else {
                var_r28_1472 = NULL;
            }
            if ((var_r28_1472 != NULL) && (var_r28_1472 != M2C_FIELD(*gb, u32 (**)(void **), 0xC)(gb))) {
                var_r30_1316 = 1;
            } else if (var_r28_1472 == NULL) {
                var_r30_1316 = 1;
                sp2F8 = (f64) sp348;
                sp300 = (f64) sp350;
            }
            sp308 = (f64) sp338;
            sp310 = (f64) sp340;
        }
        if (var_r30_1316 != 0) {
            Explode(*((MKVector3 *) &sp2F8), *((MKVector3 *) &sp308), sp380);
        } else {
            MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp318));
            this->unkFC += gUpdateTimeDelta;
            if (this->unkFC > 4.0f) {
                Explode(*((MKVector3 *) &sp2F8), *((MKVector3 *) &sp318), NULL);
            }
        }
        sp80 = 1.0f;
        sp90 = -1.0f;
        sp78 = 1.0f;
        sp7C = 0.0f;
        sp88 = -1.0f;
        sp8C = 0.0f;
        sp2E8 = sp318;
        sp2F0 = sp320;
        sp1E8 = (f64) sp78;
        sp1F0 = (f64) sp80;
        sp1F8 = (f64) sp88;
        sp200 = (f64) sp90;
        KDRand_Vector(sp208, *((MKVector3 *) &sp1F8));
        sp2D8 = M2C_BITWISE(f64, sp208);
        sp2E0 = (f64) sp208.unk8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp1D8 = sp128;
        sp130 = (f32) sp2E0 * 20.0f;
        sp1E0 = (f64) sp130;
        sp14 = MKRand_Int(&gViewSeed, 0, 3);
        ((FallingLeaves *) (M2C_FIELD(temp_r31_1166, FallingLeaves **, 0xE4)))->Emit(*((MKVector3 *) &sp2E8), *((MKVector3 *) &sp1D8), 2.0f, sp14, 0U);
        if ((ManagedLight *) this->unk100 != NULL) {
            temp_f1_1590 = MKRand_Float(&gViewSeed, 0.2f, 0.6f);
            temp_r3_1591 = this->unk100;
            temp_r3_1591->unk10 = sp318;
            temp_r3_1591->unk18 = sp320;
            temp_r3_1596 = temp_r3_1591->unk3C;
            if (temp_r3_1596 != NULL) {
                M2C_FIELD(temp_r3_1596, f64 *, 0x10) = sp318;
                M2C_FIELD(temp_r3_1596, f64 *, 0x18) = sp320;
            }
            var_f8_1604 = 0.1f;
            if (1.0f > 0.1f) {

            } else {
                var_f8_1604 = 1.0f;
            }
            temp_f4_1612 = this->unk11C;
            sp108 = 0.0f;
            temp_f1_1620 = (var_f8_1604 * (1000.0f - temp_f4_1612)) + temp_f4_1612;
            sp10C = 1.0f;
            sp110 = 0.0f;
            sp114 = 1.0f;
            this->unk11C = (var_f8_1604 * (1000.0f - temp_f1_1620)) + temp_f1_1620;
            sp118 = 0.5f;
            sp11C = 1.0f;
            sp120 = 0.0f;
            sp124 = 1.0f;
            sp1B8 = (f64) sp108;
            sp1C0 = (f64) sp110;
            sp1C8 = (f64) sp118;
            sp1D0 = (f64) sp120;
            if ((0.5f * (temp_f1_1590 * 1.0f)) < 1.0f) {

            }
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f4 */);
            spD8 = sp68;
            spE0 = sp70;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            spC8 = sp58;
            spD0 = sp60;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
            spB8 = sp48;
            spC0 = sp50;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f3 */);
            spF8 = sp38;
            sp100 = sp40;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            spE8 = sp28;
            spF0 = sp30;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
            sp2C8 = sp18;
            sp2D0 = sp20;
            KDMath_Smooth<MKVector4>(sp1A8, this->unk108, 0.5f, 1.0f);
            M2C_FIELD(this, f64 *, 0x108) = M2C_BITWISE(f64, sp1A8);
            M2C_FIELD(this, f64 *, 0x110) = (f64) sp1A8.unk8;
            temp_r3_1720 = this->unk100;
            temp_r3_1720->unk20 = M2C_FIELD(this, f64 *, 0x108);
            temp_r3_1720->unk28 = M2C_FIELD(this, f64 *, 0x110);
            temp_r3_1725 = temp_r3_1720->unk3C;
            if (temp_r3_1725 != NULL) {
                M2C_FIELD(temp_r3_1725, f64 *, 0) = (f64) M2C_FIELD(this, f64 *, 0x108);
                M2C_FIELD(temp_r3_1725, f64 *, 8) = (f64) M2C_FIELD(this, f64 *, 0x110);
            }
            temp_r3_1737 = this->unk100;
            temp_f0_1738 = (this->unkC8 / 50.0f) * this->unk11C;
            temp_r3_1737->unk38 = temp_f0_1738;
            temp_r3_1740 = temp_r3_1737->unk3C;
            if (temp_r3_1740 != NULL) {
                M2C_FIELD(temp_r3_1740, f32 *, 0x20) = temp_f0_1738;
                M2C_FIELD(temp_r3_1740, f32 *, 0x24) = (f32) (temp_f0_1738 * temp_f0_1738);
                M2C_FIELD(temp_r3_1740, f32 *, 0x28) = (f32) (1.0f / temp_f0_1738);
                M2C_FIELD(temp_r3_1740, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1740, f32 *, 0x24));
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void EarthBombFX::Resolve() {
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
    ManagedLight *temp_r4_1894;

    KDPropEx::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 0.0f;
    spC = 1.0f;
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
    this->unk100 = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 1000.0f, lit_728, lit_729);
    temp_r4_1894 = this->unk100;
    if (temp_r4_1894 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1894, 0U);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void EarthBombFX::Init() {
    GameProp::Init();
    this->unkE0 = 0;
    this->unkF8 = 0.0f;
    this->unkFC = 0.0f;
    this->unkC8 = 0.0f;
    this->unk100 = NULL;
    this->unk108.unk0 = 1.0f;
    this->unk108.unk4 = 1.0f;
    this->unk108.unk8 = 0.0f;
    this->unk108.unkC = 1.0f;
    this->unk118 = NULL;
    this->unk11C = 1000.0f;
    this->unk180.Init(0.25f, 0.25f);
}
#endif

void EarthBombFXDescriptor::Deinit() {
    MKMaterial_Destroy(this->unkEC);
    KDPropExDescriptor::Deinit();
}

#if 0 // DRAFT: expression syntax error
void EarthBombFXDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unkE4 = checked_cast<FallingLeaves *, MKProp>(gMK->CreateProp("FallingGlowLeaves"));
    this->unkE8 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("EarthBeamBlastPS"));
    this->unkEC = MKMaterial_Create("fx_EarthBomb");
}
#endif
