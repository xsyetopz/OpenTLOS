#include "spyro/source/CharacterZapFX.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/SpyroUtils.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
static u8 lit_749 = 1;

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HeroInterface'
void CharacterZapFX::Enable(bool arg0, float arg1, bool arg2) {
    u8 var_r31_48;

    this->unk14 = arg0;
    this->unk15 = arg0;
    SetDataActive(arg0);
    this->unk16 = arg2;
    if (arg0 != 0) {
        this->unk20 = arg1;
        if (((u8) this->unk16 != 0) && (gb.unk0->GetHeroType() == 0) && (EventCamera_GetCurrent() == NULL)) {
            if ((void *) gb.unkC != NULL) {
                var_r31_48 = 0;
                if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
                    var_r31_48 = 1;
                }
                if (var_r31_48 == 0) {
                    goto block_10;
                }
            } else {
block_10:
                gb.GetSpyro();
                ((SpyroSoundPlayer *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x6F8))->FadeIn(0xB, -1);
            }
        }
    } else if (((u8) this->unk16 != 0) && (gb.unk0->GetHeroType() == 0)) {
        gb.GetSpyro();
        ((SpyroSoundPlayer *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x6F8))->FadeOut(0xB);
    }
}
#endif

#if 0 // DRAFT: type mismatch
void CharacterZapFX::Deinit() {
    MKHeap *temp_r0_113;
    MKHeap *temp_r0_132;
    MKHeap *temp_r3_135;
    MKHeap *var_r31_109;
    MKHeap *var_r3_110;
    MKHeap *var_r4_108;
    MKModel *temp_r3_150;
    u32 temp_r0_118;

    var_r4_108 = this->unk48;
    var_r31_109 = var_r4_108;
    var_r3_110 = var_r4_108;
loop_3:
    temp_r0_118 = M2C_FIELD(var_r3_110, u32 *, -4);
    var_r3_110 -= 4;
    if (temp_r0_118 != 0U) {
        temp_r0_113 = var_r3_110->unk0;
        if (temp_r0_113 < var_r31_109) {
            var_r31_109 = temp_r0_113;
        }
        goto loop_3;
    }
    if (var_r3_110 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_132 = var_r4_108->unk0;
        if (temp_r0_132 != NULL) {
            if (temp_r0_132 < var_r31_109) {
                var_r31_109 = temp_r0_132;
            }
            var_r4_108 += 4;
            goto loop_9;
        }
        temp_r3_135 = var_r3_110->Current();
        if (temp_r3_135 != NULL) {
            ((MKHeap *) (temp_r3_135->Current()))->Free(var_r31_109, NULL, 0);
        } else {
            free(var_r31_109);
        }
    }
    this->unk48 = NULL;
    temp_r3_150 = this->unk4C;
    if (temp_r3_150 != NULL) {
        MKModel_Destroy(temp_r3_150);
    }
    CharacterBodyFX::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8C'
void CharacterZapFX::Draw() {
    MKHeap *temp_r3_224;
    MKHeap *temp_r3_364;
    MKHeap *var_r31_193;
    f32 temp_f5_226;
    f32 temp_f7_227;
    f32 temp_f9_231;
    f32 var_f28_279;
    f32 var_f3_345;
    f64 temp_f1_284;
    f64 temp_f1_290;
    f64 temp_f1_294;
    s32 temp_r27_397;
    s32 temp_r3_313;
    s32 var_r0_323;
    if ((u8) this->unk14 != 0) {
        var_r31_193 = this->unk48;
loop_23:
        if ((var_r31_193 != NULL) && ((MKHeap *) var_r31_193->unk0 != NULL)) {
            M2C_STRUCT_COPY((s32) &arg_sp8C + 4, MKModel_GetWorldMatrix(this->unkC) - 4 + 4, 0x40);
            arg_spC0 = 0.0f;
            arg_spC4 = 0.0f;
            arg_spC8 = 0.0f;
            arg_spCC = 1.0f;
            temp_r3_224 = var_r31_193->unk0;
            temp_f5_226 = M2C_BITWISE(f32, temp_r3_224->unkC);
            temp_f7_227 = M2C_BITWISE(f32, temp_r3_224->unk8);
            temp_f9_231 = temp_r3_224->unk10;
            arg_sp28 = 0.0f + ((temp_f9_231 * arg_spB0) + ((temp_f7_227 * arg_sp90) + (temp_f5_226 * arg_spA0)));
            arg_sp2C = 0.0f + ((temp_f9_231 * arg_spB4) + ((temp_f7_227 * arg_sp94) + (temp_f5_226 * arg_spA4)));
            arg_sp30 = 0.0f + ((temp_f9_231 * arg_spB8) + ((temp_f7_227 * arg_sp98) + (temp_f5_226 * arg_spA8)));
            arg_sp78 = (f64) arg_sp28;
            arg_sp80 = (f64) arg_sp30;
            arg_sp48 = (f64) arg_sp28;
            arg_sp50 = (f64) arg_sp30;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_sp68 = arg_sp18;
            arg_sp20 = M2C_FIELD((temp_r3_224->unk4 + 8), f32 *, 8) - temp_r3_224->unk0->unk10;
            arg_sp70 = (f64) arg_sp20;
            arg_sp38 = arg_sp18;
            arg_sp40 = (f64) arg_sp20;
            var_f28_279 = ((f32) arg_sp70 * (f32) arg_sp70) + (((f32) arg_sp68 * (f32) arg_sp68) + (arg_sp6C * arg_sp6C));
            if (var_f28_279 > 0.000001f) {
                if (var_f28_279 > 0.0f) {
                    temp_f1_284 = __frsqrte(var_f28_279);
                    temp_f1_290 = 0.5 * temp_f1_284 * -(((f64) var_f28_279 * (temp_f1_284 * temp_f1_284)) - 3.0);
                    temp_f1_294 = 0.5 * temp_f1_290 * -(((f64) var_f28_279 * (temp_f1_290 * temp_f1_290)) - 3.0);
                    var_f28_279 = (f32) ((f64) var_f28_279 * (0.5 * temp_f1_294 * -(((f64) var_f28_279 * (temp_f1_294 * temp_f1_294)) - 3.0)));
                } else if (var_f28_279 < M2C_BITWISE(f32, 0.0)) {
                    var_f28_279 = __float_nan;
                } else {
                    arg_sp10 = var_f28_279;
                    temp_r3_313 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                    switch (temp_r3_313) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_323 = 1;
                        } else {
                            var_r0_323 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_323 = 5;
                        } else {
                            var_r0_323 = 3;
                        }
                        break;
                    default:
                        var_r0_323 = 4;
                        break;
                    }
                    if (var_r0_323 == 1) {
                        var_f28_279 = __float_nan;
                    }
                }
                var_f3_345 = 1.0f / var_f28_279;
            } else {
                var_f3_345 = 0.0f;
                var_f28_279 = 0.0f;
            }
            arg_sp68 = (f32) arg_sp68 * var_f3_345;
            arg_sp6C *= var_f3_345;
            arg_sp70 = (f32) arg_sp70 * var_f3_345;
            temp_r3_364 = var_r31_193->unk0->unk0;
            arg_sp58 = M2C_FIELD(temp_r3_364, f64 *, 8);
            arg_sp60 = M2C_FIELD(temp_r3_364, f64 *, 0x10);
            M2C_STRUCT_COPY((s32) &arg_sp8C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp90, *((MKVector3 *) &arg_sp68), (MKVector3 *) &arg_sp78);
            temp_r27_397 = (s32) ((1.0f - (var_r31_193->unk0->unk18 / 0.5f)) * (f32) (this->unk50 - 1));
            arg_sp90.Scale3x3((Matrix *) &arg_sp90, var_f28_279 / 100.0f);
            arg_spC0 = (f32) arg_sp58;
            arg_spC4 = arg_sp5C;
            arg_spC8 = (f32) arg_sp60;
            arg_spCC = 1.0f;
            MKModel_SetWorldMatrix(this->unk4C, *((Matrix *) &arg_sp90));
            MKModel_EnableOnlySubObject(this->unk4C, (SubObjectType) 0, temp_r27_397, 1U, 1U);
            MKModel_Draw(this->unk4C, NULL);
            var_r31_193 += 4;
            goto loop_23;
        }
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void CharacterZapFX::SpawnZap() {
    MKVector3 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r30_470;
    MKHeap *temp_r3_468;
    f32 temp_f1_488;
    f32 temp_f1_546;
    f32 temp_f1_603;
    f32 temp_f29_484;
    f32 temp_f29_520;
    f32 temp_f29_572;
    f32 temp_f30_479;
    f32 temp_f30_515;
    f32 temp_f30_577;

    if ((CharacterBodyFXData *) this->unk8 != NULL) {
        temp_r3_468 = this->unk48 - 4;
        this->unk48 = temp_r3_468;
        temp_r30_470 = temp_r3_468->unk0;
        if (temp_r30_470 != NULL) {
            temp_r30_470->unk18 = 0.5f;
            temp_f30_479 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f29_484 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f1_488 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp18 = temp_f30_479;
            sp10 = temp_f1_488;
            sp14 = temp_f29_484;
            spE8 = (f64) sp18;
            spE0 = (f64) sp10;
            Normalise(spF0);
            M2C_FIELD(temp_r30_470, f64 *, 8) = M2C_BITWISE(f64, spF0);
            M2C_FIELD(temp_r30_470, f64 *, 0x10) = (f64) spF0.unk8;
            temp_r30_470->unk0 = GetRandomNode(NULL);
            temp_r30_470->unk4 = GetRandomNode((CBFXNode *) temp_r30_470->unk0);
            temp_f30_515 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f29_520 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
            sp70 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp74 = temp_f29_520;
            sp78 = temp_f30_515;
            spC0 = (f64) sp70;
            spC8 = (f64) sp78;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            spD0 = sp60;
            sp68 = (f32) spC8 * 500.0f;
            spD8 = (f64) sp68;
            temp_f1_546 = MKRand_Float(&gViewSeed, 5.0f, 7.0f);
            sp50 = 1.0f;
            sp54 = 1.0f;
            spC = temp_f1_546;
            sp58 = 0.4f;
            sp5C = 1.0f;
            spB0 = (f64) sp50;
            spB8 = (f64) sp58;
            gb.unk74->Emit(*((MKVector3 *) &temp_r30_470->unk0->unk8), *((MKVector3 *) &spD0), spC, *((MKVector4 *) &spB0), -1979.9999f);
            temp_f29_572 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f30_577 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
            sp40 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp44 = temp_f30_577;
            sp48 = temp_f29_572;
            sp90 = (f64) sp40;
            sp98 = (f64) sp48;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            spA0 = sp30;
            sp38 = (f32) sp98 * 500.0f;
            spA8 = (f64) sp38;
            temp_f1_603 = MKRand_Float(&gViewSeed, 5.0f, 7.0f);
            sp20 = 1.0f;
            sp24 = 1.0f;
            sp8 = temp_f1_603;
            sp28 = 0.4f;
            sp2C = 1.0f;
            sp80 = (f64) sp20;
            sp88 = (f64) sp28;
            gb.unk74->Emit(*(temp_r30_470->unk4 + 8), *((MKVector3 *) &spA0), sp8, *((MKVector4 *) &sp80), -1979.9999f);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp10C'
void CharacterZapFX::Update() {
    MKHeap *temp_r3_688;
    MKHeap *temp_r3_700;
    MKHeap *temp_r4_691;
    MKHeap *var_r5_675;
    f32 temp_f1_856;
    f32 temp_f29_743;
    f32 temp_f29_909;
    f32 temp_f29_932;
    f32 temp_f30_738;
    f32 temp_f30_914;
    f32 temp_f30_937;
    f32 var_f4_763;
    f32 var_f7_830;
    f64 temp_f1_769;
    f64 temp_f1_775;
    f64 temp_f1_779;
    s32 temp_r3_798;
    s32 var_r0_808;
    u8 var_r30_1010;
    u8 var_r31_1071;
    CharacterBodyFX::Update();
    M2C_STRUCT_COPY((s32) &arg_sp10C + 4, MKModel_GetWorldMatrix(this->unkC) - 4 + 4, 0x40);
    if (((u8) this->unk15 != 0) && ((u8) this->unk14 != 0)) {
        var_r5_675 = this->unk48;
loop_6:
        if (var_r5_675 != NULL) {
            temp_r3_700 = var_r5_675->unk0;
            if (temp_r3_700 != NULL) {
                temp_r3_700->unk18 -= gUpdateTimeDelta;
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (var_r5_675->unk0->unk18 == 0.0f) {
                    temp_r3_688 = this->unk48;
                    this->unk48 = (MKHeap *) &temp_r3_688->unk4;
                    temp_r4_691 = temp_r3_688->unk0;
                    temp_r3_688->unk0 = var_r5_675->unk0;
                    var_r5_675->unk0 = temp_r4_691;
                }
                var_r5_675 += 4;
                goto loop_6;
            }
        }
        this->unk18 -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk18 == 0.0f) {
            this->unk18 = 0.1f;
            SpawnZap();
        }
        this->unk1C -= gUpdateTimeDelta;
        this->unk17 = 0;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((this->unk1C == 0.0f) && (GetRandomNode(NULL) != NULL)) {
            temp_f30_738 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f29_743 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
            arg_sp78 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            arg_sp7C = temp_f29_743;
            arg_sp80 = temp_f30_738;
            arg_spF8 = (f64) arg_sp78;
            arg_sp100 = (f64) arg_sp80;
            var_f4_763 = ((f32) arg_sp100 * (f32) arg_sp100) + (((f32) arg_spF8 * (f32) arg_spF8) + (arg_spFC * arg_spFC));
            if (var_f4_763 > 0.000001f) {
                if (var_f4_763 > 0.0f) {
                    temp_f1_769 = __frsqrte(var_f4_763);
                    temp_f1_775 = 0.5 * temp_f1_769 * -(((f64) var_f4_763 * (temp_f1_769 * temp_f1_769)) - 3.0);
                    temp_f1_779 = 0.5 * temp_f1_775 * -(((f64) var_f4_763 * (temp_f1_775 * temp_f1_775)) - 3.0);
                    var_f4_763 = (f32) ((f64) var_f4_763 * (0.5 * temp_f1_779 * -(((f64) var_f4_763 * (temp_f1_779 * temp_f1_779)) - 3.0)));
                } else if (var_f4_763 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_763 = __float_nan;
                } else {
                    arg_sp10 = var_f4_763;
                    temp_r3_798 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                    switch (temp_r3_798) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_808 = 1;
                        } else {
                            var_r0_808 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_808 = 5;
                        } else {
                            var_r0_808 = 3;
                        }
                        break;
                    default:
                        var_r0_808 = 4;
                        break;
                    }
                    if (var_r0_808 == 1) {
                        var_f4_763 = __float_nan;
                    }
                }
                var_f7_830 = 1.0f / var_f4_763;
            } else {
                var_f7_830 = 0.0f;
            }
            arg_sp48 = 1.0f;
            arg_sp4C = 1.0f;
            arg_sp50 = 0.2f;
            arg_sp54 = 1.0f;
            arg_spF8 = (f32) arg_spF8 * var_f7_830;
            arg_spFC *= var_f7_830;
            arg_sp100 = (f32) arg_sp100 * var_f7_830;
            arg_spC8 = (f64) arg_sp48;
            arg_spD0 = (f64) arg_sp50;
            temp_f1_856 = MKRand_Float(&gViewSeed, 1.0f, 1.5f);
            arg_sp68 = 0.0f;
            arg_sp6C = 75.0f;
            arg_sp70 = 0.0f;
            arg_spD8 = (f64) arg_sp68;
            arg_sp14 = temp_f1_856;
            arg_spE0 = (f64) arg_sp70;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spE8 = arg_sp58;
            arg_sp60 = arg_sp148 + (f32) arg_spE0;
            arg_spF0 = (f64) arg_sp60;
            gb.unk94->Trigger(*((MKVector3 *) &arg_spE8), *((MKVector3 *) &arg_spF8), arg_sp14, lit_749, (MKVector4) &arg_spC8);
            this->unk1C = 0.5f;
            this->unk17 = 1;
        }
        this->unk24 -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk24 == 0.0f) {
            this->unk24 = 0.1f;
            temp_f29_909 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f30_914 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            arg_sp38 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            arg_sp3C = temp_f30_914;
            arg_sp40 = temp_f29_909;
            this->unk28 = (f64) arg_sp38;
            arg_spB8 = (f64) arg_sp38;
            arg_spC0 = (f64) arg_sp40;
            this->unk30 = (f64) arg_sp40;
            temp_f29_932 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f30_937 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f30_937, temp_f29_932);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            this->unk38 = arg_sp28;
            arg_sp30 = arg_spA0 * 5.0f;
            arg_spA8 = arg_sp28;
            arg_spB0 = (f64) arg_sp30;
            this->unk40 = (f64) arg_sp30;
        } else {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_sp88 = arg_sp18;
            arg_sp20 = (f32) M2C_FIELD(this, f64 *, 0x40) * gUpdateTimeDelta;
            arg_sp90 = (f64) arg_sp20;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_FIELD(this, f64 *, 0x30) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x30) + (f32) arg_sp90);
        }
    }
    this->unk20 -= gUpdateTimeDelta;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (this->unk20 == 0.0f) {
        if (((u8) this->unk16 != 0) && (gb.unk0->GetHeroType() == 0)) {
            if ((u8) this->unk15 == 0) {
                var_r30_1010 = 0;
                if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
                    var_r30_1010 = 1;
                }
                if ((var_r30_1010 != 0) || (EventCamera_GetCurrent() != NULL)) {
                    goto block_46;
                }
            } else {
block_46:
                gb.GetSpyro();
                ((SpyroSoundPlayer *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x6F8))->FadeOut(0xB);
            }
        }
        this->unk15 = 0;
        this->unk14 = 0;
        SetDataActive(0U);
        return;
    }
    if (((u8) this->unk16 != 0) && ((u8) this->unk15 != 0) && (gb.unk0->GetHeroType() == 0) && (EventCamera_GetCurrent() == NULL)) {
        if ((void *) gb.unkC != NULL) {
            var_r31_1071 = 0;
            if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
                var_r31_1071 = 1;
            }
            if (var_r31_1071 == 0) {
                goto block_58;
            }
        } else {
block_58:
            gb.GetSpyro();
            ((SpyroSoundPlayer *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x6F8))->FadeIn(0xB, -1);
        }
    }
}
#endif

void CharacterZapFX::InitData(CharacterBodyFXData *arg0, MKModel *arg1, CBFXNode *arg2) {
    CharacterBodyFX::InitData(arg0, arg1, arg2);
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void CharacterZapFX::Init() {
    MKHeap *temp_r3_1131;
    MKHeap *temp_r3_1153;
    MKHeap *temp_r4_1159;
    MKHeap *var_r3_1138;
    MKHeap *var_r5_1147;
    s32 var_ctr_1151;

    CharacterBodyFX::Init();
    temp_r3_1131 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1131 != NULL) {
        var_r3_1138 = ((MKHeap *) (temp_r3_1131->Current()))->Alloc(0x2D8, NULL, 0);
    } else {
        var_r3_1138 = malloc(0x2D8);
    }
    this->unk48 = var_r3_1138;
    var_r5_1147 = this->unk48;
    this->unk48 = var_r5_1147 + 0x280;
    M2C_FIELD(var_r5_1147, s32 *, 0x280) = 0;
    var_ctr_1151 = 0x14;
    do {
        temp_r3_1153 = this->unk48;
        this->unk48 = (MKHeap *) &temp_r3_1153->unk4;
        temp_r3_1153->unk4 = (s32) var_r5_1147;
        var_r5_1147 += 0x20;
        var_ctr_1151 -= 1;
    } while (var_ctr_1151 != 0);
    temp_r4_1159 = this->unk48;
    this->unk48 = (MKHeap *) &temp_r4_1159->unk4;
    temp_r4_1159->unk4 = 0;
    this->unk18 = 0.0f;
    this->unk1C = 0.0f;
    this->unk24 = 0.0f;
    M2C_FIELD(this, f32 *, 0x28) = 0.0f;
    M2C_FIELD(this, f32 *, 0x2C) = 0.0f;
    M2C_FIELD(this, f32 *, 0x30) = 0.0f;
    M2C_FIELD(this, f32 *, 0x38) = 1.0f;
    M2C_FIELD(this, f32 *, 0x3C) = 1.0f;
    M2C_FIELD(this, f32 *, 0x40) = 0.0f;
    this->unk15 = 0;
    this->unk14 = 0;
    this->unk17 = 0;
    this->unk4C = MKModel_Create("Fx0024_ArchAnim", NULL, 2, NULL);
    this->unk50 = MKModel_GetNmbrOfSubObjects(this->unk4C, (SubObjectType) 0);
}
#endif

void CharacterZapFX_cpp::__sinit() {
    f32 temp_f0_1231;
    f64 temp_f1_1212;
    f64 temp_f1_1220;
    f64 temp_f3_1200;
    f64 temp_f4_1209;
    f64 temp_f4_1217;
    f64 temp_f8_1202;

    temp_f3_1200 = __frsqrte(2014000.0);
    temp_f8_1202 = __frsqrte(380000.0);
    temp_f4_1209 = 0.5 * temp_f3_1200 * -((2014000.0 * (temp_f3_1200 * temp_f3_1200)) - 3.0);
    temp_f1_1212 = 0.5 * temp_f8_1202 * -((380000.0 * (temp_f8_1202 * temp_f8_1202)) - 3.0);
    temp_f4_1217 = 0.5 * temp_f4_1209 * -((2014000.0 * (temp_f4_1209 * temp_f4_1209)) - 3.0);
    temp_f1_1220 = 0.5 * temp_f1_1212 * -((380000.0 * (temp_f1_1212 * temp_f1_1212)) - 3.0);
    temp_f0_1231 = (f32) (380000.0 * (0.5 * temp_f1_1220 * -((380000.0 * (temp_f1_1220 * temp_f1_1220)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1217 * -((2014000.0 * (temp_f4_1217 * temp_f4_1217)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_1231;
}
