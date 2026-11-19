#include "spyro/source/EarthBreathWhirlWinds.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Character.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/Game.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/WindFX.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern s32 GS_SpyroFuryEarthTornadoLP;
extern M2C_UNK gEmptyPtrListDL;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'Upgrade'
void EarthBreathWhirlWinds::SpawnWhirlWind(const MKVector3 &arg0, const MKVector3 &arg1, Upgrade arg2, bool arg3, float arg4) {
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    KDSoundFader *temp_r31_58;
    MKHeap *temp_r8_47;
    Matrix *temp_r3_198;
    f32 temp_f1_89;
    f32 var_f3_164;
    f32 var_f4_97;
    f64 *temp_r3_248;
    f64 temp_f1_103;
    f64 temp_f1_109;
    f64 temp_f1_113;
    s32 temp_r3_132;
    s32 var_r0_142;

    temp_r8_47 = this->unk4C;
    if ((KDSoundFader *) M2C_FIELD(temp_r8_47, KDSoundFader **, -4) != NULL) {
        this->unk4C = temp_r8_47 - 4;
        temp_r31_58 = M2C_FIELD(temp_r8_47, KDSoundFader **, -4);
        if (temp_r31_58 != NULL) {
            sp48 = 0.0f;
            sp38 = -1.0f;
            sp28 = 1.0f;
            sp40 = 0.0f;
            sp44 = 1.0f;
            sp30 = -1.0f;
            sp34 = 0.0f;
            sp20 = 1.0f;
            sp24 = 0.0f;
            sp90 = (f64) sp40;
            sp98 = (f64) sp48;
            sp60 = (f64) sp30;
            sp68 = (f64) sp38;
            sp50 = (f64) sp20;
            sp58 = (f64) sp28;
            KDRand_Vector(sp70, *((MKVector3 *) &sp60));
            temp_f1_89 = M2C_BITWISE(f32, sp70);
            var_f4_97 = (sp70.unk8 * sp70.unk8) + ((temp_f1_89 * temp_f1_89) + (sp70.unk4 * sp70.unk4));
            if (var_f4_97 > 1e-12f) {
                if (var_f4_97 > 0.0f) {
                    temp_f1_103 = __frsqrte(var_f4_97);
                    temp_f1_109 = 0.5 * temp_f1_103 * -(((f64) var_f4_97 * (temp_f1_103 * temp_f1_103)) - 3.0);
                    temp_f1_113 = 0.5 * temp_f1_109 * -(((f64) var_f4_97 * (temp_f1_109 * temp_f1_109)) - 3.0);
                    var_f4_97 = (f32) ((f64) var_f4_97 * (0.5 * temp_f1_113 * -(((f64) var_f4_97 * (temp_f1_113 * temp_f1_113)) - 3.0)));
                } else if (var_f4_97 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_97 = __float_nan;
                } else {
                    sp8 = var_f4_97;
                    temp_r3_132 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_132) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_142 = 1;
                        } else {
                            var_r0_142 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_142 = 5;
                        } else {
                            var_r0_142 = 3;
                        }
                        break;
                    default:
                        var_r0_142 = 4;
                        break;
                    }
                    if (var_r0_142 == 1) {
                        var_f4_97 = __float_nan;
                    }
                }
                var_f3_164 = 1.0f / var_f4_97;
            } else {
                var_f3_164 = 0.0f;
            }
            sp10 = M2C_BITWISE(f32, sp70) * var_f3_164;
            sp14 = sp70.unk4 * var_f3_164;
            sp18 = sp70.unk8 * var_f3_164;
            sp80 = (f64) sp10;
            sp88 = (f64) sp18;
            M2C_STRUCT_COPY(temp_r31_58 + 0x9C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            KDMath_BuildMatrixFromFwd(temp_r31_58 + 0xA0, *((MKVector3 *) &sp80), (MKVector3 *) &sp90);
            temp_r3_198 = temp_r31_58 + 0xA0;
            temp_r3_198->Scale3x3(temp_r3_198, arg1);
            M2C_FIELD(temp_r31_58, f32 *, 0xD0) = (f32) arg0.unk0;
            M2C_FIELD(temp_r31_58, f32 *, 0xD4) = (f32) arg0.unk4;
            M2C_FIELD(temp_r31_58, f32 *, 0xD8) = (f32) arg0.unk8;
            M2C_FIELD(temp_r31_58, f32 *, 0xDC) = 1.0f;
            M2C_FIELD(temp_r31_58, f32 *, 0xF4) = 0.5f;
            M2C_FIELD(temp_r31_58, s32 *, 0x100) = 1;
            M2C_FIELD(temp_r31_58, f32 *, 0xF8) = 1.0f;
            M2C_FIELD(temp_r31_58, f64 *, 0xE0) = sp80;
            M2C_FIELD(temp_r31_58, f64 *, 0xE8) = sp88;
            M2C_FIELD(temp_r31_58, f32 *, 0xFC) = 0.0f;
            M2C_FIELD(temp_r31_58, s32 *, 0x104) = (s32) arg2;
            temp_r31_58->Init(1.0f, 1.0f);
            M2C_FIELD(temp_r31_58, f64 *, 0x50) = (f64) M2C_FIELD(&arg0, f32 *, 0);
            M2C_FIELD(temp_r31_58, f64 *, 0x58) = (f64) M2C_FIELD(&arg0, f32 *, 8);
            temp_r31_58->unk48 = 50.0f * arg1.unk0;
            temp_r31_58->unk4C = 50.0f * arg1.unk4;
            M2C_STRUCT_COPY((s32) &temp_r31_58->unk5C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_r3_248 = &temp_r31_58->unk60;
            temp_r3_248->RotateYaw((Matrix *) temp_r3_248, 0.3926991f);
            M2C_FIELD(temp_r31_58, u8 *, 0x108) = arg3;
            M2C_FIELD(temp_r31_58, f32 *, 0xF0) = arg4;
        }
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void EarthBreathWhirlWinds::Deinit() {
    MKHeap *temp_r0_291;
    MKHeap *temp_r0_310;
    MKHeap *temp_r3_282;
    MKHeap *temp_r3_313;
    MKHeap *var_r31_274;
    MKHeap *var_r31_287;
    MKHeap *var_r3_288;
    MKHeap *var_r4_286;
    u32 temp_r0_296;

    MKModel_Destroy(this->unk50);
    var_r31_274 = this->unk4C;
loop_2:
    if (var_r31_274 != NULL) {
        temp_r3_282 = var_r31_274->unk0;
        if (temp_r3_282 != NULL) {
            KDSound_Stop((s32 *) temp_r3_282);
            var_r31_274 += 4;
            goto loop_2;
        }
    }
    var_r4_286 = this->unk4C;
    var_r31_287 = var_r4_286;
    var_r3_288 = var_r4_286;
loop_7:
    temp_r0_296 = M2C_FIELD(var_r3_288, u32 *, -4);
    var_r3_288 -= 4;
    if (temp_r0_296 != 0U) {
        temp_r0_291 = var_r3_288->unk0;
        if (temp_r0_291 < var_r31_287) {
            var_r31_287 = temp_r0_291;
        }
        goto loop_7;
    }
    if (var_r3_288 != &gEmptyPtrListDL) {
loop_13:
        temp_r0_310 = var_r4_286->unk0;
        if (temp_r0_310 != NULL) {
            if (temp_r0_310 < var_r31_287) {
                var_r31_287 = temp_r0_310;
            }
            var_r4_286 += 4;
            goto loop_13;
        }
        temp_r3_313 = var_r3_288->Current();
        if (temp_r3_313 != NULL) {
            ((MKHeap *) (temp_r3_313->Current()))->Free(var_r31_287, NULL, 0);
        } else {
            free(var_r31_287);
        }
    }
    this->unk4C = NULL;
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA0'
void EarthBreathWhirlWinds::Draw() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r31_401;
    MKHeap *var_r30_348;
    MKModel **temp_r4_371;
    MKProp *temp_r3_382;
    MKProp *temp_r3_390;
    void *temp_r5_372;

    var_r30_348 = this->unk4C;
loop_2:
    if (var_r30_348 != NULL) {
        temp_r31_401 = var_r30_348->unk0;
        if (temp_r31_401 != NULL) {
            MKModel_SetWorldMatrix(this->unk50, temp_r31_401->unkA0);
            sp18 = 1.0f;
            sp1C = 1.0f;
            sp20 = 1.0f;
            sp24 = temp_r31_401->unkF8;
            sp38 = (f64) sp18;
            sp40 = (f64) sp20;
            MKModel_SetColor(this->unk50, *((MKVector4 *) &sp38));
            MKModel_Draw(this->unk50, NULL);
            temp_r4_371 = &temp_r31_401->unk9C;
            temp_r5_372 = this->unk54 + 0x5C;
            M2C_STRUCT_COPY((s32) temp_r5_372 + 4, (s32) temp_r4_371 + 4, 0x40);
            sp8 = 1.0f;
            temp_r3_382 = this->unk54;
            spC = 1.0f;
            sp10 = 1.0f;
            sp14 = temp_r31_401->unkF8;
            M2C_FIELD(temp_r3_382, f64 *, 0x50) = (f64) sp8;
            M2C_FIELD(temp_r3_382, f64 *, 0x58) = (f64) sp10;
            temp_r3_390 = this->unk54;
            sp28 = (f64) sp8;
            sp30 = (f64) sp10;
            temp_r3_390->Draw(temp_r4_371 + 0x40, temp_r5_372 + 0x40, (f64) sp8);
            var_r30_348 += 4;
            goto loop_2;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'Message'
void EarthBreathWhirlWinds::Message(MKMessage *arg0) {
    MKHeap *temp_r3_432;
    MKHeap *var_r31_423;

    var_r31_423 = this->unk4C;
loop_2:
    if (var_r31_423 != NULL) {
        temp_r3_432 = var_r31_423->unk0;
        if (temp_r3_432 != NULL) {
            temp_r3_432->Message(arg0);
            var_r31_423 += 4;
            goto loop_2;
        }
    }
    MKProp::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EarthBreathWhirlWinds::Update() {
    f32 sp310;
    f64 sp308;
    f64 sp300;
    s32 sp2F8;
    s32 sp2F4;
    s32 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    MKVector3 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    MKVector3 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    M2C_UNK sp210;
    MKVector3 sp200;
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
    MKVector3 sp190;
    MKVector3 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f32 spD8;
    f32 spC8;
    f32 spB8;
    f32 spA8;
    f32 sp98;
    f32 sp88;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 sp8;
    Character *temp_r22_876;
    MKHeap *temp_r29_962;
    MKHeap *temp_r3_781;
    MKHeap *temp_r4_784;
    MKHeap *var_r26_485;
    MKProp *temp_r3_968;
    TargetManager ***var_r23_865;
    TargetManager **temp_r24_954;
    f32 *temp_r28_496;
    f32 temp_f21_1013;
    f32 var_f0_536;
    f32 var_f0_751;
    f32 var_f28_838;
    f64 temp_f1_939;
    s32 temp_cr0_eq_889;
    s32 temp_r0_508;
    s32 temp_r0_522;
    s32 temp_r0_837;
    s32 temp_r5_937;
    s32 var_r24_666;
    u8 var_r27_490;
    u8 var_r6_501;
    void *temp_r22_983;
    void *temp_r30_487;
    void *temp_r3_902;
    void *temp_r3_972;

    this->unk58 -= gUpdateTimeDelta;
    var_r26_485 = this->unk4C;
    temp_r30_487 = checked_cast<EarthBreathWhirlWindsDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r27_490 = 0;
loop_59:
    if ((var_r26_485 == NULL) || (temp_r29_962 = var_r26_485->unk0, ((temp_r29_962 == NULL) != 0))) {
        if (var_r27_490 != 0) {
            temp_r3_968 = this->unk54;
            temp_r3_972 = M2C_FIELD(temp_r3_968->__vptr, void *(**)(MKProp *), 0x3C)(temp_r3_968);
            if (temp_r3_972 != NULL) {
                sp48 = 1.0f;
                temp_r22_983 = M2C_FIELD(temp_r3_972, void **, 0x2C);
                sp58 = -1.0f;
                sp40 = 1.0f;
                sp44 = 0.5f;
                sp50 = -1.0f;
                sp54 = 0.0f;
                sp160 = (f64) sp40;
                sp168 = (f64) sp48;
                sp170 = (f64) sp50;
                sp178 = (f64) sp58;
                KDRand_Vector(sp180, *((MKVector3 *) &sp170));
                Normalise(sp190);
                M2C_FIELD(temp_r3_972, f64 *, 0) = M2C_BITWISE(f64, sp190);
                M2C_FIELD(temp_r3_972, f64 *, 8) = (f64) sp190.unk8;
                M2C_FIELD(temp_r3_972, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_972, f32 *, 0x28) = 0.0f;
                temp_f21_1013 = MKRand_Float(&gViewSeed, 100.0f, 500.0f);
                sp20 = -(f32) M2C_FIELD(temp_r3_972, f64 *, 0);
                sp24 = -M2C_FIELD(temp_r3_972, f32 *, 4);
                sp28 = -(f32) M2C_FIELD(temp_r3_972, f64 *, 8);
                sp140 = (f64) sp20;
                sp148 = (f64) sp28;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f21 */);
                M2C_FIELD(temp_r22_983, f64 *, 0) = sp30;
                sp38 = (f32) sp148 * temp_f21_1013;
                sp150 = sp30;
                sp158 = (f64) sp38;
                M2C_FIELD(temp_r22_983, f64 *, 8) = (f64) sp38;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f20 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r26, 0x0, qr0 */);
                M2C_FIELD(temp_r3_972, f64 *, 8) = (f32) ((f32) M2C_FIELD(temp_r3_972, f64 *, 8) * MKRand_Float(&gViewSeed, 100.0f, 200.0f));
                M2C_FIELD(temp_r22_983, f32 *, 0x18) = MKRand_Float(&gViewSeed, 2.5f, 3.5f);
                M2C_FIELD(temp_r22_983, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r22_983, f32 *, 0x14) = (f32) M2C_FIELD(this->unk54, f32 *, 0xF4);
            }
        }
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk58 == 0.0f) {
            this->unk58 = 0.1f;
        }
    } else {
        temp_r28_496 = &temp_r29_962->unkA0.unk30;
        var_r27_490 = 1;
        var_r6_501 = 0;
        temp_r29_962->unkF4 = M2C_BITWISE(f32, temp_r29_962->unkF4) - gUpdateTimeDelta;
        temp_r29_962->unkFC -= gUpdateTimeDelta;
        sp8 = 1;
        temp_r0_508 = temp_r29_962->unk100;
        if ((temp_r0_508 == 1) || (temp_r0_508 == 2)) {
            var_r6_501 = 1;
        }
        temp_r29_962->Update(GS_SpyroFuryEarthTornadoLP, 1U, var_r6_501, NULL, (MKVector3 *) temp_r28_496, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        temp_r0_522 = temp_r29_962->unk100;
        switch (temp_r0_522) {                      /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            break;
        case 1:                                     /* switch 1 */
            var_f0_536 = M2C_BITWISE(f32, temp_r29_962->unkF4);
            if (var_f0_536 < 0.5f) {

            } else {
                var_f0_536 = 0.5f;
            }
            if (var_f0_536 > 0.0f) {

            } else {
                var_f0_536 = 0.0f;
            }
            temp_r29_962->unkF4 = var_f0_536;
            temp_r29_962->unkF8 = 1.0f - (M2C_BITWISE(f32, temp_r29_962->unkF4) / 1.5f);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_BITWISE(f32, temp_r29_962->unkF4) == 0.0f) {
                temp_r29_962->unk100 = 2;
                temp_r29_962->unkF4 = temp_r29_962->unkF0;
            }
        default:                                    /* switch 1 */
block_34:
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f22 */);
            sp1B0 = spC0;
            spC8 = temp_r29_962->unkE8 * 50.0f;
            sp1B8 = (f64) spC8;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            sp1C0 = spB0;
            spB8 = (f32) sp1B8 * gUpdateTimeDelta;
            sp1C8 = (f64) spB8;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp2C0 = spA0;
            spA8 = temp_r29_962->unkA0.unk38 + (f32) sp1C8;
            temp_r29_962->unkA0.unk30 = (f32) sp2C0;
            sp2C8 = (f64) spA8;
            temp_r29_962->unkA0.unk34 = unksp2C4;
            temp_r29_962->unkA0.unk38 = (f32) sp2C8;
            temp_r29_962->unkA0.unk3C = 1.0f;
            M2C_FIELD(temp_r29_962, f64 *, 0x50) = spA0;
            M2C_FIELD(temp_r29_962, f64 *, 0x58) = (f64) spA8;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_r29_962->unkFC == 0.0f) {
                temp_r0_837 = temp_r29_962->unk104;
                var_f28_838 = 500.0f;
                switch (temp_r0_837) {              /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    break;
                case 1:                             /* switch 2 */
                    var_f28_838 = 700.0f;
                    break;
                case 2:                             /* switch 2 */
                    var_f28_838 = 1000.0f;
                    break;
                case 3:                             /* switch 2 */
                    var_f28_838 = 1500.0f;
                    break;
                }
                temp_r29_962->unkFC = 0.5f;
                var_r23_865 = gb.unk20->Begin();
loop_56:
                if (var_r23_865 != NULL) {
                    temp_r24_954 = *var_r23_865;
                    if (temp_r24_954 != NULL) {
                        temp_r22_876 = ((Character *(*)(TargetManager **)) (*temp_r24_954)->unk8.unk4)(temp_r24_954);
                        if (((*temp_r24_954)->unk8.unk0(temp_r24_954) != NULL) && (M2C_FIELD(*temp_r24_954, u8 (**)(TargetManager **), 0x18)(temp_r24_954) != 0) && ((temp_cr0_eq_889 = temp_r22_876 == NULL, (temp_cr0_eq_889 != 0)) || ((temp_cr0_eq_889 == 0) && (temp_r22_876->IsActive() != 0)))) {
                            temp_r3_902 = M2C_FIELD((*temp_r24_954)->unk8.unk0(temp_r24_954), void **, 8);
                            sp1A0 = M2C_FIELD(temp_r3_902, f64 *, 0x30);
                            sp1A8 = M2C_FIELD(temp_r3_902, f64 *, 0x38);
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                            sp2B0 = sp90;
                            sp98 = (f32) sp1A8 - temp_r29_962->unkA0.unk38;
                            sp2B8 = (f64) sp98;
                            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                            if (((((f32) sp2B8 * (f32) sp2B8) + (((f32) sp2B0 * (f32) sp2B0) + (unksp2B4 * unksp2B4))) == (var_f28_838 * var_f28_838)) && (temp_r22_876 != NULL)) {
                                sp2F4 = 0;
                                temp_r5_937 = temp_r29_962->unk104;
                                sp2F0 = 0xA4;
                                temp_f1_939 = (f64) M2C_FIELD(temp_r29_962, f32 *, 0xD0);
                                sp300 = temp_f1_939;
                                sp308 = (f64) M2C_FIELD(temp_r29_962, f32 *, 0xD8);
                                sp310 = var_f28_838;
                                sp2F8 = temp_r5_937;
                                temp_r22_876->Message(&sp2F0, temp_r5_937, temp_f1_939);
                            }
                        }
                        var_r23_865 += 4;
                        goto loop_56;
                    }
                }
            }
            var_r26_485 += 4;
            goto loop_59;
        case 2:                                     /* switch 1 */
            sp138 = -1.0f;
            sp128 = 1.0f;
            sp130 = -1.0f;
            sp134 = 1.0f;
            sp120 = 1.0f;
            sp124 = 2.0f;
            sp280 = (f64) sp130;
            sp288 = (f64) sp138;
            sp270 = (f64) sp120;
            sp278 = (f64) sp128;
            KDRand_Vector(sp290, *((MKVector3 *) &sp280));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            sp2A0 = sp110;
            sp118 = sp290.unk8 * 200.0f;
            sp2A8 = (f64) sp118;
            sp18 = MKRand_Float(&gViewSeed, 0.2f, 0.4f);
            gb.EmitCrud(*((MKVector3 *) temp_r28_496), *((MKVector3 *) &sp2A0), sp18);
            sp108 = -1.0f;
            spF8 = 1.0f;
            sp100 = -1.0f;
            sp104 = 1.0f;
            spF0 = 1.0f;
            spF4 = 2.0f;
            sp240 = (f64) sp100;
            sp248 = (f64) sp108;
            sp230 = (f64) spF0;
            sp238 = (f64) spF8;
            KDRand_Vector(sp250, *((MKVector3 *) &sp240));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
            sp260 = spE0;
            spE8 = sp250.unk8 * 200.0f;
            sp268 = (f64) spE8;
            sp14 = MKRand_Float(&gViewSeed, 0.2f, 0.4f);
            gb.EmitSmallRocks(*((MKVector3 *) temp_r28_496), *((MKVector3 *) &sp260), sp14);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if ((this->unk58 == 0.0f) && ((u8) temp_r29_962->unk108 != 0)) {
                var_r24_666 = 0;
                do {
                    MKVector(0.0f, 25.0f, 0.0f);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    sp68 = 1.0f;
                    sp78 = -1.0f;
                    sp88 = temp_r29_962->unkA0.unk38 + sp218;
                    sp60 = 1.0f;
                    sp64 = 1.0f;
                    sp70 = -1.0f;
                    sp74 = 0.0f;
                    sp220 = sp80;
                    sp228 = (f64) sp88;
                    sp2E0 = sp80;
                    sp2E8 = (f64) sp88;
                    sp1E0 = (f64) sp60;
                    sp1E8 = (f64) sp68;
                    sp1F0 = (f64) sp70;
                    sp1F8 = (f64) sp78;
                    KDRand_Vector(sp200, *((MKVector3 *) &sp1F0));
                    sp2D0 = M2C_BITWISE(f64, sp200);
                    sp2D8 = (f64) sp200.unk8;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
                    sp1D0 = spD0;
                    spD8 = (f32) sp2D8 * 220.0f;
                    sp1D8 = (f64) spD8;
                    sp10 = MKRand_Int(&gViewSeed, 0, 3);
                    ((FallingLeaves *) (M2C_FIELD(temp_r30_487, FallingLeaves **, 0x60)))->Emit(*((MKVector3 *) &sp2E0), *((MKVector3 *) &sp1D0), 2.0f, sp10, 1U);
                    var_r24_666 += 1;
                } while (var_r24_666 < 5);
            }
            ((FallingLeaves *) (M2C_FIELD(temp_r30_487, FallingLeaves **, 0x60)))->ApplyWind((WindFX *) &temp_r29_962->unk30);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_BITWISE(f32, temp_r29_962->unkF4) == 0.0f) {
                temp_r29_962->unk100 = 3;
                temp_r29_962->unkF4 = 1.5f;
            }
            goto block_34;
        case 3:                                     /* switch 1 */
            var_f0_751 = M2C_BITWISE(f32, temp_r29_962->unkF4);
            if (var_f0_751 < 1.5f) {

            } else {
                var_f0_751 = 1.5f;
            }
            if (var_f0_751 > 0.0f) {

            } else {
                var_f0_751 = 0.0f;
            }
            temp_r29_962->unkF4 = var_f0_751;
            temp_r29_962->unkF8 = M2C_BITWISE(f32, temp_r29_962->unkF4) / 1.5f;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_BITWISE(f32, temp_r29_962->unkF4) == 0.0f) {
                temp_r29_962->unk100 = 0;
                temp_r29_962->unkF4 = 0.0f;
                KDSound_Stop((s32 *) temp_r29_962);
                temp_r3_781 = this->unk4C;
                this->unk4C = (MKHeap *) &temp_r3_781->unk4;
                temp_r4_784 = temp_r3_781->unk0;
                temp_r3_781->unk0 = var_r26_485->unk0;
                var_r26_485->unk0 = temp_r4_784;
            }
            goto block_34;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void EarthBreathWhirlWinds::Init() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r30_1162;
    MKHeap *temp_r3_1111;
    MKHeap *temp_r3_1133;
    MKHeap *temp_r3_1160;
    MKHeap *temp_r5_1139;
    MKHeap *var_r3_1118;
    MKHeap *var_r5_1127;
    s32 *temp_r3_1202;
    s32 var_ctr_1131;

    MKProp::Init();
    temp_r3_1111 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1111 != NULL) {
        var_r3_1118 = ((MKHeap *) (temp_r3_1111->Current()))->Alloc(0xCF8, NULL, 0);
    } else {
        var_r3_1118 = malloc(0xCF8);
    }
    this->unk4C = var_r3_1118;
    var_r5_1127 = this->unk4C;
    this->unk4C = var_r5_1127 + 0xCC0;
    M2C_FIELD(var_r5_1127, s32 *, 0xCC0) = 0;
    var_ctr_1131 = 0xC;
    do {
        temp_r3_1133 = this->unk4C;
        this->unk4C = (MKHeap *) &temp_r3_1133->unk4;
        temp_r3_1133->unk4 = (s32) var_r5_1127;
        var_r5_1127 += 0x110;
        var_ctr_1131 -= 1;
    } while (var_ctr_1131 != 0);
    temp_r5_1139 = this->unk4C;
    this->unk4C = (MKHeap *) &temp_r5_1139->unk4;
    temp_r5_1139->unk4 = 0;
    gMK->CreatePropDeferred("WhirlWindDustPS", &this->unk54);
    this->unk50 = MKModel_Create("FX0043_Whirlwind", NULL, 2, NULL);
loop_8:
    if ((u32) M2C_FIELD(this->unk4C, u32 *, -4) != 0U) {
        temp_r3_1160 = this->unk4C - 4;
        this->unk4C = temp_r3_1160;
        temp_r30_1162 = temp_r3_1160->unk0;
        if (temp_r30_1162 != NULL) {
            sp10 = 0.0f;
            sp20 = 0.0f;
            sp8 = 0.0f;
            spC = 1.0f;
            sp18 = 0.0f;
            sp1C = 0.0f;
            sp28 = (f64) sp8;
            sp30 = (f64) sp10;
            sp38 = (f64) sp18;
            sp40 = (f64) sp20;
            temp_r30_1162->unk30.Init(1, 1.0f, *((MKVector3 *) &sp38), *((MKVector3 *) &sp28));
            temp_r30_1162->unk48 = 400.0f;
            M2C_FIELD(temp_r30_1162, f32 *, 0x4C) = 800.0f;
            M2C_STRUCT_COPY((s32) &temp_r30_1162->unk5C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_r3_1202 = &temp_r30_1162->unk60;
            temp_r3_1202->RotateYaw((Matrix *) temp_r3_1202, 1.5707964f);
            temp_r30_1162->unk40 = 50.0f;
        }
        goto loop_8;
    }
loop_11:
    if ((MKHeap *) this->unk4C->unk0 != NULL) {
        this->unk4C = (MKHeap *) &this->unk4C->unk4;
        goto loop_11;
    }
    this->unk58 = 0.0f;
}
#endif

#if 0 // DRAFT: function call 'checked_cast(void *)' does not match
void EarthBreathWhirlWindsDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = checked_cast<FallingLeaves *, MKProp>(gMK->CreateProp("FallingGlowLeaves"));
}
#endif
