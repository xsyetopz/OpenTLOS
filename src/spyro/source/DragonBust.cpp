#include "spyro/source/DragonBust.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/FloorSwitch.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/ManagedLight.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

f64 fmod(f32, f64);                                 /* extern */
extern s32 GS_StatueLightBurst;
extern s32 GS_StatueMoveLP;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern MKMaterial *gRenderState;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
static M2C_UNK lit_690;                                /* unable to generate initializer: unknown type */
static DragonBust states__10DragonBust;             /* type too large by 0x88; unable to generate initializer: not enough data */

static s32 lit_709 = 0;
static u8 lit_710 = 1;

#if 0 // DRAFT: expression syntax error
static s8 lit_stringBase0[0x3D] = {
    0x70,
    0x5F,
    0x53,
    0x6B,
    0x75,
    0x6C,
    0x6C,
    0x57,
    0x68,
    0x69,
    0x74,
    0x65,
    0,
    0x41,
    0x63,
    0x74,
    0x69,
    0x76,
    0x61,
    0x74,
    0x6F,
    0x72,
    0x50,
    0x72,
    0x6F,
    0x70,
    0x49,
    0x44,
    0,
    0x46,
    0x78,
    0x30,
    0x30,
    0x32,
    0x30,
    0x5F,
    0x65,
    0x61,
    0x72,
    0x74,
    0x68,
    0x73,
    0x68,
    0x6F,
    0x63,
    0x6B,
    0,
    0x46,
    0x58,
    0x5F,
    0x49,
    0x63,
    0x65,
    0x46,
    0x75,
    0x72,
    0x79,
    0x4D,
    0x61,
    0x74,
    0,
}; /* const */

void DragonBust::Deinit() {
    ManagedLight *temp_r4_58;

    this->unkC8.Deinit();
    MKMaterial_Destroy(this->unk124);
    KDSound_Stop(&this->unk130);
    temp_r4_58 = this->unk118;
    if (temp_r4_58 != NULL) {
        gb.unk80->FreeManagedLight(temp_r4_58);
    }
    MKMaterial_Destroy(this->unk120);
    MKModel_Destroy(this->unk11C);
    GameProp::Deinit();
}
#endif

#if 0 // DRAFT: expression syntax error
void DragonBust::Draw() {
    GameProp::Draw();
    if (this->unkC8.GetState() == 3) {
        gRenderState = this->unk120;
        MKModel_Draw(this->unk11C, NULL);
        gRenderState = NULL;
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void DragonBust::Message(MKMessage *arg0) {
    void *temp_r3_126;

    if ((this->unkC8.GetState() < 2) && ((s32) arg0->unk0 == 0x12)) {
        temp_r3_126 = checked_cast<CollisionObjectCollideMsg *, MKMessage>(arg0);
        if ((u32) M2C_FIELD(temp_r3_126, u32 *, 0xC) != 0U) {
            gb.GetSpyro();
            if ((u32) M2C_FIELD(temp_r3_126, u32 *, 0xC) == (u32) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u32 *, 0x27C)) {
                SetState((DragonBust::State) 1);
            }
        }
    }
    this->unk130.Message(arg0);
    GameProp::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'one'
void DragonBust::ActivatingBUpdate() {
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;                                       /* compiler-managed */
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;                                       /* compiler-managed */
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;                                       /* compiler-managed */
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
    f32 temp_f0_260;
    f32 temp_f1_175;
    f32 temp_f1_183;
    f32 temp_f1_202;
    f32 temp_f1_220;
    f32 temp_f1_292;
    f32 temp_f3_179;
    f32 var_f0_185;
    f32 var_f0_204;
    f32 var_f0_223;
    f32 var_f3_488;
    f32 var_f4_319;
    f32 var_f4_421;
    f32 var_f6_386;
    f64 temp_f1_325;
    f64 temp_f1_331;
    f64 temp_f1_335;
    f64 temp_f1_427;
    f64 temp_f1_433;
    f64 temp_f1_437;
    f64 temp_f3_246;
    f64 temp_f4_245;
    s32 temp_r3_354;
    s32 temp_r3_456;
    s32 var_r0_364;
    s32 var_r0_466;
    s32 var_r29_500;
    void *temp_r3_243;

    temp_f1_175 = 1.0f + _table_sinf(0.5f * (6.2831855f * (f32) fmod(this->unkE4, 2.0)));
    sp88 = M2C_FIELD(&one, f64 *, 0);
    temp_f3_179 = 0.5f * temp_f1_175;
    sp90 = M2C_FIELD(&one, f64 *, 8);
    temp_f1_183 = this->unk108;
    var_f0_185 = (temp_f3_179 * ((f32) sp88 - temp_f1_183)) + temp_f1_183;
    if (var_f0_185 < 1.0f) {

    } else {
        var_f0_185 = 1.0f;
    }
    if (var_f0_185 > 0.0f) {

    } else {
        var_f0_185 = 0.0f;
    }
    sp88 = var_f0_185;
    temp_f1_202 = this->unk108;
    var_f0_204 = (temp_f3_179 * ((f32) var_f0_185 - temp_f1_202)) + temp_f1_202;
    if (var_f0_204 < 1.0f) {

    } else {
        var_f0_204 = 1.0f;
    }
    if (var_f0_204 > 0.0f) {

    } else {
        var_f0_204 = 0.0f;
    }
    unksp8C = var_f0_204;
    temp_f1_220 = this->unk108;
    var_f0_223 = (temp_f3_179 * (sp88 - temp_f1_220)) + temp_f1_220;
    if (var_f0_223 < 1.0f) {

    } else {
        var_f0_223 = 1.0f;
    }
    if (var_f0_223 > 0.0f) {

    } else {
        var_f0_223 = 0.0f;
    }
    sp90 = var_f0_223;
    unksp94 = this->unk114;
    MKModel_SetColor(this->unk4, *((MKVector4 *) &sp88));
    temp_r3_243 = this->unk8;
    temp_f4_245 = M2C_FIELD(temp_r3_243, f64 *, 0x30);
    temp_f3_246 = M2C_FIELD(temp_r3_243, f64 *, 0x38);
    sp68 = temp_f4_245;
    sp70 = temp_f3_246;
    sp78 = temp_f4_245;
    sp80 = temp_f3_246;
    sp38 = temp_f4_245;
    sp40 = temp_f3_246;
    temp_f0_260 = (150.0f * _table_sinf((5.0f * this->unkE4) + 1.5707964f)) + (f32) sp80;
    sp80 = temp_f0_260;
    sp78 = (150.0f * _table_sinf(5.0f * this->unkE4)) + (f32) sp78;
    unksp7C += (150.0f * _table_sinf(5.0f * (0.5f * this->unkE4))) + 150.0f;
    sp70 = -((150.0f * _table_sinf((5.0f * this->unkE4) + 1.5707964f)) - (f32) sp70);
    temp_f1_292 = _table_sinf(5.0f * this->unkE4);
    sp28 = -sp78;
    sp2C = -unksp7C;
    sp30 = -temp_f0_260;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    sp68 = -((150.0f * temp_f1_292) - (f32) sp68);
    unksp6C = unksp7C;
    var_f4_319 = ((f32) sp60 * (f32) sp60) + (((f32) sp58 * (f32) sp58) + (unksp5C * unksp5C));
    if (var_f4_319 > 0.000001f) {
        if (var_f4_319 > 0.0f) {
            temp_f1_325 = __frsqrte(var_f4_319);
            temp_f1_331 = 0.5 * temp_f1_325 * -(((f64) var_f4_319 * (temp_f1_325 * temp_f1_325)) - 3.0);
            temp_f1_335 = 0.5 * temp_f1_331 * -(((f64) var_f4_319 * (temp_f1_331 * temp_f1_331)) - 3.0);
            var_f4_319 = (f32) ((f64) var_f4_319 * (0.5 * temp_f1_335 * -(((f64) var_f4_319 * (temp_f1_335 * temp_f1_335)) - 3.0)));
        } else if (var_f4_319 < M2C_BITWISE(f32, 0.0)) {
            var_f4_319 = __float_nan;
        } else {
            spC = var_f4_319;
            temp_r3_354 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_354) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_364 = 1;
                } else {
                    var_r0_364 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_364 = 5;
                } else {
                    var_r0_364 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_364 = 4;
                break;
            }
            if (var_r0_364 == 1) {
                var_f4_319 = __float_nan;
            }
        }
        var_f6_386 = 1.0f / var_f4_319;
    } else {
        var_f6_386 = 0.0f;
    }
    sp18 = -sp78;
    sp1C = -unksp7C;
    sp20 = -sp80;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp58 = (f32) sp58 * var_f6_386;
    unksp5C *= var_f6_386;
    sp60 = (f32) sp60 * var_f6_386;
    var_f4_421 = ((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (unksp4C * unksp4C));
    if (var_f4_421 > 0.000001f) {
        if (var_f4_421 > 0.0f) {
            temp_f1_427 = __frsqrte(var_f4_421);
            temp_f1_433 = 0.5 * temp_f1_427 * -(((f64) var_f4_421 * (temp_f1_427 * temp_f1_427)) - 3.0);
            temp_f1_437 = 0.5 * temp_f1_433 * -(((f64) var_f4_421 * (temp_f1_433 * temp_f1_433)) - 3.0);
            var_f4_421 = (f32) ((f64) var_f4_421 * (0.5 * temp_f1_437 * -(((f64) var_f4_421 * (temp_f1_437 * temp_f1_437)) - 3.0)));
        } else if (var_f4_421 < M2C_BITWISE(f32, 0.0)) {
            var_f4_421 = __float_nan;
        } else {
            sp8 = var_f4_421;
            temp_r3_456 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_456) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_466 = 1;
                } else {
                    var_r0_466 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_466 = 5;
                } else {
                    var_r0_466 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_466 = 4;
                break;
            }
            if (var_r0_466 == 1) {
                var_f4_421 = __float_nan;
            }
        }
        var_f3_488 = 1.0f / var_f4_421;
    } else {
        var_f3_488 = 0.0f;
    }
    var_r29_500 = 0;
    sp48 = (f32) sp48 * var_f3_488;
    unksp4C *= var_f3_488;
    sp50 = (f32) sp50 * var_f3_488;
    do {
        sp14 = MKRand_Float(&gViewSeed, 0.4f, 1.0f);
        gb.EmitFairyDandruf(*((MKVector3 *) &sp78), *((MKVector3 *) &sp58), sp14, *((MKVector4 *) &sp88));
        sp10 = MKRand_Float(&gViewSeed, 0.4f, 1.0f);
        gb.EmitFairyDandruf(*((MKVector3 *) &sp68), *((MKVector3 *) &sp48), sp10, *((MKVector4 *) &sp88));
        var_r29_500 += 1;
    } while (var_r29_500 < 3);
    this->unkE4 += gUpdateTimeDelta;
    if (this->unkE4 > 1.5f) {
        SetState((DragonBust::State) 5);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void DragonBust::ActivatingBEnter() {
    s32 spC;
    s32 sp8;
    ManagedLight *temp_r4_558;
    void *temp_r3_570;

    temp_r4_558 = this->unk118;
    if (temp_r4_558 != NULL) {
        gb.unk80->FreeManagedLight(temp_r4_558);
    }
    this->unk158 = 0;
    temp_r3_570 = this->unk128;
    spC = 0;
    sp8 = 0x50;
    M2C_FIELD(M2C_FIELD(temp_r3_570, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_570, &sp8, 0);
    this->unkE4 = 0.5f;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp40'
void DragonBust::ActivatingAUpdate() {
    ManagedLight *temp_r3_631;
    f32 temp_f1_623;
    f32 temp_f1_627;
    f32 temp_f2_663;
    f32 temp_f4_615;
    f32 temp_f6_620;
    f32 temp_f7_616;
    f32 var_f5_600;
    void *temp_r3_635;
    void *temp_r3_674;
    var_f5_600 = this->unkE4 * 0.5f;
    if (var_f5_600 < 2.0f) {

    } else {
        var_f5_600 = 2.0f;
    }
    if (var_f5_600 > 0.0f) {

    } else {
        var_f5_600 = 0.0f;
    }
    temp_f4_615 = this->unk108;
    temp_f7_616 = 1.0f - var_f5_600;
    temp_f6_620 = (temp_f7_616 * 400.0f) + 100.0f;
    arg_sp40 = (temp_f7_616 * (1.0f - temp_f4_615)) + temp_f4_615;
    temp_f1_623 = this->unk10C;
    arg_sp48 = (temp_f7_616 * (1.0f - temp_f1_623)) + temp_f1_623;
    temp_f1_627 = this->unk110;
    arg_sp44 = (temp_f7_616 * (1.0f - temp_f1_627)) + temp_f1_627;
    temp_r3_631 = this->unk118;
    if (temp_r3_631 != NULL) {
        temp_r3_631->unk38 = temp_f6_620;
        temp_r3_635 = temp_r3_631->unk3C;
        if (temp_r3_635 != NULL) {
            M2C_FIELD(temp_r3_635, f32 *, 0x20) = temp_f6_620;
            M2C_FIELD(temp_r3_635, f32 *, 0x24) = (f32) (temp_f6_620 * temp_f6_620);
            M2C_FIELD(temp_r3_635, f32 *, 0x28) = (f32) (1.0f / temp_f6_620);
            M2C_FIELD(temp_r3_635, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_635, f32 *, 0x24));
        }
    }
    M2C_STRUCT_COPY((s32) &arg_sp4C + 4, (s32) (&identity - 4) + 4, 0x40);
    temp_f2_663 = 5.0f * var_f5_600;
    arg_sp18 = temp_f2_663;
    arg_sp10 = temp_f2_663;
    arg_sp14 = 10.0f * temp_f7_616;
    arg_sp38 = (f64) arg_sp18;
    arg_sp30 = (f64) arg_sp10;
    arg_sp50.Scale3x3((Matrix *) &arg_sp50, *((MKVector3 *) &arg_sp30));
    temp_r3_674 = this->unk8;
    arg_sp20 = M2C_FIELD(temp_r3_674, f64 *, 0x30);
    arg_sp28 = M2C_FIELD(temp_r3_674, f64 *, 0x38);
    arg_sp80 = (f32) arg_sp20;
    arg_sp84 = arg_sp24;
    arg_sp88 = (f32) arg_sp28;
    arg_sp8C = 1.0f;
    MKModel_SetWorldMatrix(this->unk11C, *((Matrix *) &arg_sp50));
    MKModel_SetColor(this->unk4, *((MKVector4 *) &arg_sp40));
    this->unkE4 -= gUpdateTimeDelta;
    if (this->unkE4 < 0.0f) {
        SetState((DragonBust::State) 4);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp5C'
void DragonBust::ActivatingAEnter() {
    ManagedLight *temp_r3_791;
    ManagedLight *temp_r3_804;
    ManagedLight *temp_r4_766;
    void *temp_r3_743;
    void *temp_r3_797;
    void *temp_r3_807;
    M2C_STRUCT_COPY((s32) &arg_sp5C + 4, (s32) (&identity - 4) + 4, 0x40);
    this->unk158 = 0;
    arg_sp60.Scale3x3((Matrix *) &arg_sp60, zero);
    temp_r3_743 = this->unk8;
    arg_sp50 = M2C_FIELD(temp_r3_743, f64 *, 0x30);
    arg_sp58 = M2C_FIELD(temp_r3_743, f64 *, 0x38);
    arg_sp90 = (f32) arg_sp50;
    arg_sp94 = arg_sp54;
    arg_sp98 = (f32) arg_sp58;
    arg_sp9C = 1.0f;
    KDSound_Play3d(GS_StatueLightBurst, temp_r3_743 + 0x30, 0U, -1, 0.0f, 0U);
    MKModel_SetWorldMatrix(this->unk11C, *((Matrix *) &arg_sp60));
    temp_r4_766 = this->unk118;
    if (temp_r4_766 != NULL) {
        gb.unk80->EnableLight(temp_r4_766, 1U);
        arg_sp20.operator*(150.0f);
        arg_sp30.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_r3_791 = this->unk118;
        arg_sp40 = arg_sp10;
        arg_sp18 = arg_sp38 + arg_sp28;
        temp_r3_791->unk10 = arg_sp10;
        temp_r3_791->unk18 = (f64) arg_sp18;
        temp_r3_797 = temp_r3_791->unk3C;
        arg_sp48 = (f64) arg_sp18;
        if (temp_r3_797 != NULL) {
            M2C_FIELD(temp_r3_797, f64 *, 0x10) = arg_sp10;
            M2C_FIELD(temp_r3_797, f64 *, 0x18) = (f64) arg_sp18;
        }
        temp_r3_804 = this->unk118;
        temp_r3_804->unk38 = 500.0f;
        temp_r3_807 = temp_r3_804->unk3C;
        if (temp_r3_807 != NULL) {
            M2C_FIELD(temp_r3_807, f32 *, 0x20) = 500.0f;
            M2C_FIELD(temp_r3_807, f32 *, 0x24) = 250000.0f;
            M2C_FIELD(temp_r3_807, f32 *, 0x28) = 0.002f;
            M2C_FIELD(temp_r3_807, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_807, f32 *, 0x24));
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp28'
void DragonBust::SlidingIntoPlaceUpdate() {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_f1_879;
    f32 temp_f3_862;
    void *temp_r4_859;

    this->unk158 = 1;
    if (this->unk104 > 0.0f) {
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
        sp38 = sp28;
        sp30 = this->unk100 * 100.0f;
        sp40 = (f64) sp30;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */);
        temp_r4_859 = this->unk8;
        temp_f3_862 = (f32) sp40 * gUpdateTimeDelta;
        sp48 = sp18;
        sp20 = temp_f3_862;
        sp58 = M2C_FIELD(temp_r4_859, f64 *, 0x30);
        sp50 = (f64) sp20;
        sp60 = M2C_FIELD(temp_r4_859, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_f1_879 = (f32) sp60 + (f32) sp50;
        sp68 = sp8;
        sp10 = temp_f1_879;
        sp70 = (f64) sp10;
        M2C_FIELD(this->__vptr, M2C_UNK (**)(f64 *, f32, f32, f32, f32), 0x38)(&sp68, temp_f1_879, (f32) sp60, temp_f3_862, gUpdateTimeDelta);
        this->unk104 -= gUpdateTimeDelta;
        return;
    }
    SetState((DragonBust::State) 3);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp10'
void DragonBust::SlidingIntoPlaceEnter() {
    f64 sp38;
    f64 sp30;                                       /* compiler-managed */
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp8;
    f32 var_f3_1002;
    f32 var_f4_936;
    f64 temp_f1_942;
    f64 temp_f1_948;
    f64 temp_f1_952;
    s32 temp_r4_971;
    s32 var_r5_918;
    void *temp_r4_909;

    temp_r4_909 = this->unk8;
    sp20 = M2C_FIELD(temp_r4_909, f64 *, 0x30);
    sp28 = M2C_FIELD(temp_r4_909, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    var_r5_918 = 1;
    sp30 = sp10;
    sp18 = this->unkF0 - (f32) sp28;
    sp38 = (f64) sp18;
    this->unk158 = 1;
    var_f4_936 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + (unksp34 * unksp34));
    if (var_f4_936 > 0.000001f) {
        if (var_f4_936 > 0.0f) {
            temp_f1_942 = __frsqrte(var_f4_936);
            temp_f1_948 = 0.5 * temp_f1_942 * -(((f64) var_f4_936 * (temp_f1_942 * temp_f1_942)) - 3.0);
            temp_f1_952 = 0.5 * temp_f1_948 * -(((f64) var_f4_936 * (temp_f1_948 * temp_f1_948)) - 3.0);
            var_f4_936 = (f32) ((f64) var_f4_936 * (0.5 * temp_f1_952 * -(((f64) var_f4_936 * (temp_f1_952 * temp_f1_952)) - 3.0)));
        } else if (var_f4_936 < M2C_BITWISE(f32, 0.0)) {
            var_f4_936 = __float_nan;
        } else {
            sp8 = var_f4_936;
            temp_r4_971 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r4_971) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {

                } else {
                    var_r5_918 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r5_918 = 5;
                } else {
                    var_r5_918 = 3;
                }
                break;
            default:
                var_r5_918 = 4;
                break;
            }
            if (var_r5_918 == 1) {
                var_f4_936 = __float_nan;
            }
        }
        var_f3_1002 = 1.0f / var_f4_936;
    } else {
        var_f3_1002 = 0.0f;
        var_f4_936 = 0.0f;
    }
    this->unk104 = var_f4_936 / 100.0f;
    sp30 = (f32) sp30 * var_f3_1002;
    unksp34 *= var_f3_1002;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void DragonBust::SlideUpdate() {
    f64 sp188;                                      /* compiler-managed */
    f64 sp180;                                      /* compiler-managed */
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
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f32 spA8;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f1_1156;
    f32 temp_f27_1192;
    f32 temp_f2_1154;
    f32 temp_f2_1176;
    f32 temp_f4_1180;
    f32 temp_f5_1171;
    f32 var_f28_1076;
    f32 var_f3_1143;
    f64 temp_f1_1082;
    f64 temp_f1_1088;
    f64 temp_f1_1092;
    s32 temp_r3_1111;
    s32 var_r0_1121;
    void *temp_r3_1047;
    void *temp_r3_1195;
    void *temp_r3_1253;
    void *temp_r3_1315;
    void *temp_r4_1046;
    void *temp_r4_1165;

    temp_r4_1046 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, GameGlobals *), 0xC)(gb.unk0, &gb), void **, 8);
    temp_r3_1047 = this->unk8;
    sp150 = M2C_FIELD(temp_r4_1046, f64 *, 0x30);
    sp160 = M2C_FIELD(temp_r3_1047, f64 *, 0x30);
    sp158 = M2C_FIELD(temp_r4_1046, f64 *, 0x38);
    sp168 = M2C_FIELD(temp_r3_1047, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp180 = spA0;
    spA8 = (f32) sp168 - (f32) sp158;
    sp188 = (f64) spA8;
    var_f28_1076 = ((f32) sp188 * (f32) sp188) + (((f32) sp180 * (f32) sp180) + (unksp184 * unksp184));
    if (var_f28_1076 > 0.000001f) {
        if (var_f28_1076 > 0.0f) {
            temp_f1_1082 = __frsqrte(var_f28_1076);
            temp_f1_1088 = 0.5 * temp_f1_1082 * -(((f64) var_f28_1076 * (temp_f1_1082 * temp_f1_1082)) - 3.0);
            temp_f1_1092 = 0.5 * temp_f1_1088 * -(((f64) var_f28_1076 * (temp_f1_1088 * temp_f1_1088)) - 3.0);
            var_f28_1076 = (f32) ((f64) var_f28_1076 * (0.5 * temp_f1_1092 * -(((f64) var_f28_1076 * (temp_f1_1092 * temp_f1_1092)) - 3.0)));
        } else if (var_f28_1076 < M2C_BITWISE(f32, 0.0)) {
            var_f28_1076 = __float_nan;
        } else {
            sp8 = var_f28_1076;
            temp_r3_1111 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1111) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1121 = 1;
                } else {
                    var_r0_1121 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1121 = 5;
                } else {
                    var_r0_1121 = 3;
                }
                break;
            default:
                var_r0_1121 = 4;
                break;
            }
            if (var_r0_1121 == 1) {
                var_f28_1076 = __float_nan;
            }
        }
        var_f3_1143 = 1.0f / var_f28_1076;
    } else {
        var_f3_1143 = 0.0f;
        var_f28_1076 = 0.0f;
    }
    temp_f2_1154 = (f32) sp180 * var_f3_1143;
    temp_f1_1156 = unksp184 * var_f3_1143;
    sp180 = temp_f2_1154;
    unksp184 = temp_f1_1156;
    sp188 = (f32) sp188 * var_f3_1143;
    temp_r4_1165 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, f32, f32), 0xC)(gb.unk0, temp_f1_1156, temp_f2_1154), void **, 8);
    temp_f5_1171 = -M2C_FIELD(temp_r4_1165, f32 *, 0x20);
    temp_f2_1176 = this->unkF8;
    sp90 = temp_f5_1171;
    sp94 = -M2C_FIELD(temp_r4_1165, f32 *, 0x24);
    temp_f4_1180 = this->unk100;
    sp98 = -M2C_FIELD(temp_r4_1165, f32 *, 0x28);
    sp140 = (f64) sp90;
    sp148 = (f64) sp98;
    temp_f27_1192 = (temp_f4_1180 * (f32) sp148) + ((temp_f2_1176 * (f32) sp140) + (this->unkFC * unksp144));
    temp_r3_1195 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, void *, f32, f32, f32, f32, f32), 0xC)(gb.unk0, temp_r4_1165, (f32) sp140, temp_f2_1176, (f32) sp148, temp_f4_1180, temp_f5_1171), void **, 8);
    sp80 = -M2C_FIELD(temp_r3_1195, f32 *, 0x20);
    sp84 = -M2C_FIELD(temp_r3_1195, f32 *, 0x24);
    sp88 = -M2C_FIELD(temp_r3_1195, f32 *, 0x28);
    sp130 = (f64) sp80;
    sp138 = (f64) sp88;
    this->unk158 = 0;
    if ((temp_f27_1192 > 0.7f) && (((sp188 * (f32) sp138) + ((temp_f2_1154 * (f32) sp130) + (temp_f1_1156 * unksp134))) > 0.85f)) {
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        spF0 = sp70;
        sp78 = this->unk100 * 100.0f;
        spF8 = (f64) sp78;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
        sp100 = sp60;
        sp68 = (f32) spF8 * temp_f27_1192;
        sp108 = (f64) sp68;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_r3_1253 = this->unk8;
        sp110 = sp50;
        sp58 = (f32) sp108 * gUpdateTimeDelta;
        sp120 = M2C_FIELD(temp_r3_1253, f64 *, 0x30);
        sp118 = (f64) sp58;
        sp128 = M2C_FIELD(temp_r3_1253, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp170 = sp40;
        sp48 = (f32) sp128 + (f32) sp118;
        sp178 = (f64) sp48;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        spD0 = sp30;
        sp38 = up.unk8 * 50.0f;
        spD8 = (f64) sp38;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spE0 = sp20;
        sp28 = (f32) sp178 + (f32) spD8;
        spE8 = (f64) sp28;
        Tools_GetFloor(*((MKVector3 *) &spE0), M2C_ERROR(/* unknown instruction: ps_mr $f1, $f30 */), &unksp174);
        this->unk158 = 1;
        SetPos(sp170);
    }
    temp_r3_1315 = this->unk8;
    spB0 = M2C_FIELD(temp_r3_1315, f64 *, 0x30);
    spB8 = M2C_FIELD(temp_r3_1315, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    spC0 = sp10;
    sp18 = this->unkF0 - (f32) spB8;
    spC8 = (f64) sp18;
    if ((((f32) spC8 * (f32) spC8) + (((f32) spC0 * (f32) spC0) + (unkspC4 * unkspC4))) < 22500.0f) {
        this->unk104 = var_f28_1076 / 100.0f;
        SetState((DragonBust::State) 2);
        return;
    }
    SetState((DragonBust::State) 0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void DragonBust::IdleUpdate() {
    if ((u8) this->unk12C != 0) {
        SetState((DragonBust::State) 5);
    }
}
#endif

#if 0 // DRAFT: function call 'checked_cast(void *)' does not match
void DragonBust::IdleEnter() {
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    f64 temp_f0_1409;
    f64 temp_f1_1408;
    void *temp_r3_1407;
    void *temp_r3_1413;
    void *temp_r3_1439;

    if ((void *) this->unk128 == NULL) {
        this->unk128 = checked_cast<FloorSwitch *, MKProp>(this->unkE0->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        temp_r3_1407 = M2C_FIELD(this->unk128, void **, 8);
        temp_f1_1408 = M2C_FIELD(temp_r3_1407, f64 *, 0x30);
        temp_f0_1409 = M2C_FIELD(temp_r3_1407, f64 *, 0x38);
        sp78 = temp_f1_1408;
        this->unkE8 = temp_f1_1408;
        M2C_FIELD(this, f64 *, 0xF0) = temp_f0_1409;
        temp_r3_1413 = this->unk8;
        sp80 = temp_f0_1409;
        sp48 = M2C_FIELD(temp_r3_1413, f64 *, 0x30);
        sp50 = M2C_FIELD(temp_r3_1413, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp58 = sp8;
        sp10 = this->unkF0 - (f32) sp50;
        sp60 = (f64) sp10;
        Normalise(sp68);
        M2C_FIELD(this, f64 *, 0xF8) = M2C_BITWISE(f64, sp68);
        M2C_FIELD(this, f64 *, 0x100) = (f64) sp68.unk8;
        temp_r3_1439 = this->unk8;
        sp28 = M2C_FIELD(temp_r3_1439, f64 *, 0x30);
        sp30 = M2C_FIELD(temp_r3_1439, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp38 = sp18;
        sp20 = this->unkF0 - (f32) sp30;
        sp40 = (f64) sp20;
        if ((((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + (unksp3C * unksp3C))) < 1.0f) {
            this->unk12C = 1;
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'DragonBust::State'
void DragonBust::SetState(DragonBust::State arg1) {
    this->unkC8.SetState(this, (s32) arg1, 0U);
}
#endif

#if 0 // DRAFT: expression syntax error
void DragonBust::Update() {
    s32 sp8;

    this->unkC8.Update(this, 0);
    sp8 = 1;
    this->unk130.Update(GS_StatueMoveLP, 1U, this->unk158, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    this->unk158 = 0;
    GameProp::Update();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void DragonBust::Reset() {
    this->unk12C = 0;
    SetState((DragonBust::State) 0);
    this->unk158 = 0;
    GameProp::Reset();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void DragonBust::LoadDone() {
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
    ManagedLight *temp_r4_1604;

    GameProp::LoadDone();
    this->unk124 = MKMaterial_Create(lit_stringBase0);
    sp20 = 0.0f;
    M2C_FIELD(this, f64 *, 0x108) = (f64) M2C_FIELD(&loadInfo, f64 *, 0x70);
    M2C_FIELD(this, f64 *, 0x110) = (f64) M2C_FIELD(&loadInfo, f64 *, 0x78);
    sp30 = 0.0f;
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
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
    this->unk118 = gb.unk80->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 500.0f, lit_709, lit_710);
    temp_r4_1604 = this->unk118;
    if (temp_r4_1604 != NULL) {
        gb.unk80->EnableLight(temp_r4_1604, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 DragonBust::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1627;

    var_r31_1627 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadInt(&lit_stringBase0[0xD], (s32 *) &this->unkE0, 0) != 0)) {
        var_r31_1627 = 1;
    }
    return var_r31_1627;
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__28KDStateMachine'
void DragonBust::Init() {
    Init__28KDStateMachine<10DragonBust>FPQ228KDStateMachine<10DragonBust>5StateP28KDStateMachine<10DragonBust>((KDStateMachine<DragonBust> *) &this->unkC8, (KDStateMachine<DragonBust>::State *) &states, NULL);
    this->unkDC = 0;
    this->unkE0 = (MKSceneManager *)-1;
    this->unkE4 = 1.0f;
    this->unkE8 = M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xF0) = (f64) M2C_FIELD(&zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0xF8) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x100) = (f64) M2C_FIELD(&zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x108) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x110) = (f64) M2C_FIELD(&zero, f64 *, 8);
    this->unk118 = NULL;
    this->unk11C = MKModel_Create(&lit_stringBase0[0x1D], NULL, 2, NULL);
    this->unk120 = MKMaterial_Create(&lit_stringBase0[0x2F]);
    this->unk124 = NULL;
    this->unk128 = NULL;
    this->unk12C = 0;
    this->unk130.Init(0.25f, 0.5f);
    this->unk158 = 0;
    GameProp::Init();
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FloorSwitch *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: undefined identifier '__ptmf_null'
void DragonBust_cpp::__sinit() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f1_1931;
    f64 temp_f1_1950;
    f64 temp_f3_1914;
    f64 temp_f3_1934;
    f64 temp_f4_1929;
    f64 temp_f4_1948;
    f64 temp_f8_1916;
    void *temp_r3_1923;

    temp_f3_1914 = __frsqrte(2014000.0);
    temp_f8_1916 = __frsqrte(380000.0);
    temp_r3_1923 = &lit_690 + 0x6C;
    temp_f4_1929 = 0.5 * temp_f3_1914 * -((2014000.0 * (temp_f3_1914 * temp_f3_1914)) - 3.0);
    temp_f1_1931 = 0.5 * temp_f8_1916 * -((380000.0 * (temp_f8_1916 * temp_f8_1916)) - 3.0);
    temp_f3_1934 = temp_f4_1929 * temp_f4_1929;
    M2C_FIELD(&lit_690, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_690, s32 *, 0);
    M2C_FIELD(&lit_690, s32 *, 0x70) = (s32) M2C_FIELD(&lit_690, s32 *, 4);
    M2C_FIELD(&lit_690, s32 *, 0x74) = (s32) M2C_FIELD(&lit_690, s32 *, 8);
    temp_f4_1948 = 0.5 * temp_f4_1929 * -((2014000.0 * temp_f3_1934) - 3.0);
    temp_f1_1950 = 0.5 * temp_f1_1931 * -((380000.0 * (temp_f1_1931 * temp_f1_1931)) - 3.0);
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_1923, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_1923, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_1923, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_1923, s32 *, 0x18) = (s32) M2C_FIELD(&lit_690, s32 *, 0xC);
    M2C_FIELD(temp_r3_1923, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_690, s32 *, 0x10);
    M2C_FIELD(temp_r3_1923, s32 *, 0x20) = (s32) M2C_FIELD(&lit_690, s32 *, 0x14);
    M2C_FIELD(temp_r3_1923, s32 *, 0x24) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_1923, s32 *, 0x28) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_1923, s32 *, 0x2C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_1923, s32 *, 0x30) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_1923, s32 *, 0x34) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_1923, s32 *, 0x38) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_1923, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_690, s32 *, 0x18);
    M2C_FIELD(temp_r3_1923, s32 *, 0x40) = (s32) M2C_FIELD(&lit_690, s32 *, 0x1C);
    M2C_FIELD(temp_r3_1923, s32 *, 0x44) = (s32) M2C_FIELD(&lit_690, s32 *, 0x20);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1948 * -((2014000.0 * (temp_f4_1948 * temp_f4_1948)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_1950 * -((380000.0 * (temp_f1_1950 * temp_f1_1950)) - 3.0)));
    M2C_FIELD(temp_r3_1923, s32 *, 0x48) = (s32) M2C_FIELD(&lit_690, s32 *, 0x24);
    M2C_FIELD(temp_r3_1923, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_690, s32 *, 0x28);
    M2C_FIELD(temp_r3_1923, s32 *, 0x50) = (s32) M2C_FIELD(&lit_690, s32 *, 0x2C);
    M2C_FIELD(temp_r3_1923, s32 *, 0x54) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_1923, s32 *, 0x58) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_1923, s32 *, 0x5C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_1923, s32 *, 0x60) = (s32) M2C_FIELD(&lit_690, s32 *, 0x30);
    M2C_FIELD(temp_r3_1923, s32 *, 0x64) = (s32) M2C_FIELD(&lit_690, s32 *, 0x34);
    M2C_FIELD(temp_r3_1923, s32 *, 0x68) = (s32) M2C_FIELD(&lit_690, s32 *, 0x38);
    M2C_FIELD(temp_r3_1923, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_690, s32 *, 0x3C);
    M2C_FIELD(temp_r3_1923, s32 *, 0x70) = (s32) M2C_FIELD(&lit_690, s32 *, 0x40);
    M2C_FIELD(temp_r3_1923, s32 *, 0x74) = (s32) M2C_FIELD(&lit_690, s32 *, 0x44);
    M2C_FIELD(temp_r3_1923, s32 *, 0x78) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_1923, s32 *, 0x7C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_1923, s32 *, 0x80) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_1923, s32 *, 0x84) = (s32) M2C_FIELD(&lit_690, s32 *, 0x48);
    M2C_FIELD(temp_r3_1923, s32 *, 0x88) = (s32) M2C_FIELD(&lit_690, s32 *, 0x4C);
    M2C_FIELD(temp_r3_1923, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_690, s32 *, 0x50);
    M2C_FIELD(temp_r3_1923, s32 *, 0x90) = (s32) M2C_FIELD(&lit_690, s32 *, 0x54);
    M2C_FIELD(temp_r3_1923, s32 *, 0x94) = (s32) M2C_FIELD(&lit_690, s32 *, 0x58);
    M2C_FIELD(temp_r3_1923, s32 *, 0x98) = (s32) M2C_FIELD(&lit_690, s32 *, 0x5C);
    M2C_FIELD(temp_r3_1923, s32 *, 0x9C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_1923, s32 *, 0xA0) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_1923, s32 *, 0xA4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_1923, s32 *, 0xA8) = (s32) M2C_FIELD(&lit_690, s32 *, 0x60);
    M2C_FIELD(temp_r3_1923, s32 *, 0xAC) = (s32) M2C_FIELD(&lit_690, s32 *, 0x64);
    M2C_FIELD(temp_r3_1923, s32 *, 0xB0) = (s32) M2C_FIELD(&lit_690, s32 *, 0x68);
    M2C_FIELD(temp_r3_1923, s32 *, 0xB4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_1923, s32 *, 0xB8) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_1923, s32 *, 0xBC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_1923, s32 *, 0xC0) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_1923, s32 *, 0xC4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_1923, s32 *, 0xC8) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_1923, s32 *, 0xCC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_1923, s32 *, 0xD0) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_1923, s32 *, 0xD4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
}
#endif
