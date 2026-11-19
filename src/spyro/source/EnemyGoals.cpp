#include "spyro/source/EnemyGoals.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDeathFX.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/ExplosiveBarrelPath.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/Lever.h"
#include "spyro/source/SB2.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern s32 gViewSeed;
extern void **gb;
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_FrozenInfo_0x10'
static struct _struct_FrozenInfo_0x10 FrozenInfo[6] = {
    { 5, 0, 0x960, 0x992 },
    { 1, 4, 0x25B, 0x27C },
    { 1, 3, 0x2C1, 0x2DA },
    { 0x10, 0x3C, 0x325, 0x348 },
    { 0x10, 0x3D, 0x393, 0x3A2 },
    { 2, 0x28, 0x4B0, 0x4BF },
};
#endif
#if 0 // DRAFT: undefined identifier 'unk93C'
static M2C_UNK fVanguardAngles;                     /* unable to generate initializer: unknown type */

void EnemyGoal_Summon::Terminate() {
    this->unk14 = 3;
    this->unkC->unk110.unk93C->unk28 = 3;
    this->unk10 = NULL;
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk520'
u8 EnemyGoal_Summon::Update() {
    Character *temp_r3_38;

    ActivateIfInactive();
    if (this->unkC->unk110.unk520->CheckEvent(0x14) != 0) {
        temp_r3_38 = this->unkC;
        temp_r3_38->unk110.unk93C->TrySpawnItems(temp_r3_38->unk110.unk928->unkF4 - 2, 0U);
    }
    if ((this->unkC->HasAnimFinished() != 0) || ((u8) this->unk18 == 0)) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk760'
void EnemyGoal_Summon::Activate() {
    f64 sp10;
    f64 sp8;
    Character *temp_r3_78;
    Character *temp_r3_89;
    u8 var_r31_87;
    void *temp_r5_80;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    temp_r3_78 = this->unkC;
    temp_r5_80 = temp_r3_78->unk8;
    sp8 = M2C_FIELD(temp_r5_80, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r5_80, f64 *, 0x38);
    temp_r3_78->unk110.unk760.Update(*((MKVector3 *) &sp8));
    var_r31_87 = 0;
    this->unk18 = 0;
    temp_r3_89 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_89, u8 *, 0x8B8) == 2) || (temp_r3_89->unk110.unk760.unk40.Get() != NULL)) {
        var_r31_87 = 1;
    }
    if (var_r31_87 != 0) {
        if (PositionSpawnPoints_Vanguard(0U) != 0) {
            this->unkC->SetAnim((AnimSequenceType) 1, 0xB, 0, 0.15f, 4U, 0U);
            this->unkC->unk110.unk93C->FunctionOn();
            this->unk18 = 1;
        }
    } else {
        this->unkC->unk110.unk93C->FunctionOff();
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void NPCGoal_Rescue::Terminate() {
    f64 sp10;
    f64 sp8;
    MKProp *temp_r4_146;
    MKProp *temp_r4_153;
    MKProp *temp_r6_169;
    SpawnerObject **temp_r3_154;
    u32 temp_r3_147;
    void *temp_r4_173;
    void *temp_r7_175;

    this->unk8 = 1;
    if ((u8) this->unk15 == 0) {
        temp_r4_146 = this->unkC;
        temp_r3_147 = M2C_FIELD(temp_r4_146, u32 *, 0xA44);
        if (temp_r3_147 != 0U) {
            ((EventMessage *) (temp_r3_147 + 8))->Send(temp_r4_146);
        }
    }
    temp_r4_153 = this->unkC;
    temp_r3_154 = M2C_FIELD(temp_r4_153, SpawnerObject ***, 0xA48);
    if (temp_r3_154 != NULL) {
        ((SpawnerObject *) (*temp_r3_154))->DespawnItem(temp_r4_153, 1U);
    } else {
        M2C_FIELD(temp_r4_153->__vptr, M2C_UNK (**)(MKProp *, M2C_UNK), 0x4C)(temp_r4_153, 1);
    }
    temp_r6_169 = this->unkC;
    temp_r4_173 = M2C_FIELD(temp_r6_169, void **, 0xA38);
    temp_r7_175 = temp_r6_169->unk8;
    sp8 = M2C_FIELD(temp_r7_175, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r7_175, f64 *, 0x38);
    ((EnemyDeathFX *) (M2C_FIELD(&gb, EnemyDeathFX **, 0x98)))->Trigger(temp_r4_173 + 0x108, *((MKVector3 *) &sp8), M2C_FIELD(M2C_FIELD(temp_r4_173, void **, 0x1C), f32 *, 0xC) / 200.0f, 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp20'
u8 NPCGoal_Rescue::Update() {
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;                                       /* compiler-managed */
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp18;
    f32 spC;
    f32 sp8;
    AnimSequence *temp_r4_522;
    AnimSequence *temp_r4_535;
    AnimSequence *temp_r4_559;
    AnimSequence *temp_r4_569;
    MKProp *temp_r29_516;
    MKProp *temp_r29_563;
    MKProp *temp_r3_457;
    MKProp *temp_r3_534;
    MKProp *temp_r3_558;
    MKProp *temp_r4_311;
    MKProp *temp_r4_444;
    MKProp *temp_r4_590;
    MKProp *temp_r5_545;
    f32 temp_f2_319;
    f32 temp_f3_312;
    f32 temp_f4_315;
    f32 var_f4_242;
    f32 var_f4_357;
    f32 var_f5_229;
    f32 var_f5_370;
    f64 temp_f1_209;
    f64 temp_f1_247;
    f64 temp_f1_253;
    f64 temp_f1_257;
    f64 temp_f1_336;
    f64 temp_f1_375;
    f64 temp_f1_381;
    f64 temp_f1_385;
    s32 temp_r3_276;
    s32 temp_r3_404;
    s32 var_r0_286;
    s32 var_r0_414;
    u32 temp_r3_591;
    u32 temp_r4_547;
    u8 var_r30_517;
    u8 var_r30_564;
    u8 var_r3_499;
    u8 var_r4_493;
    void *temp_r3_216;
    void *temp_r3_344;
    void *temp_r4_207;
    void *temp_r4_333;
    void *temp_r5_494;

    ActivateIfInactive();
    temp_r4_207 = this->unkC->unk8;
    temp_f1_209 = M2C_FIELD(temp_r4_207, f64 *, 0x30);
    sp50 = temp_f1_209;
    sp58 = M2C_FIELD(temp_r4_207, f64 *, 0x38);
    temp_r3_216 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **, void *, f64), 0xC)(M2C_FIELD(&gb, void ***, 0), temp_r4_207, temp_f1_209), void **, 8);
    sp60 = M2C_FIELD(temp_r3_216, f64 *, 0x30);
    sp68 = M2C_FIELD(temp_r3_216, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    var_f5_229 = 0.0f;
    sp80 = sp20;
    sp28 = (f32) sp68 - (f32) sp58;
    unksp84 = 0.0f;
    sp88 = (f64) sp28;
    var_f4_242 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + (0.0f * 0.0f));
    if (var_f4_242 > 0.000001f) {
        if (var_f4_242 > 0.0f) {
            temp_f1_247 = __frsqrte(var_f4_242);
            temp_f1_253 = 0.5 * temp_f1_247 * -(((f64) var_f4_242 * (temp_f1_247 * temp_f1_247)) - 3.0);
            temp_f1_257 = 0.5 * temp_f1_253 * -(((f64) var_f4_242 * (temp_f1_253 * temp_f1_253)) - 3.0);
            var_f4_242 = (f32) ((f64) var_f4_242 * (0.5 * temp_f1_257 * -(((f64) var_f4_242 * (temp_f1_257 * temp_f1_257)) - 3.0)));
        } else if (var_f4_242 < M2C_BITWISE(f32, 0.0)) {
            var_f4_242 = __float_nan;
        } else {
            spC = var_f4_242;
            temp_r3_276 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_276) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_286 = 1;
                } else {
                    var_r0_286 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_286 = 5;
                } else {
                    var_r0_286 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_286 = 4;
                break;
            }
            if (var_r0_286 == 1) {
                var_f4_242 = __float_nan;
            }
        }
        var_f5_229 = 1.0f / var_f4_242;
    }
    temp_r4_311 = this->unkC;
    temp_f3_312 = unksp84 * var_f5_229;
    temp_f4_315 = (f32) sp80 * var_f5_229;
    temp_f2_319 = (f32) sp88 * var_f5_229;
    sp80 = temp_f4_315;
    unksp84 = temp_f3_312;
    sp88 = temp_f2_319;
    if (((u8) this->unk14 == 0) && (((M2C_FIELD(temp_r4_311, f32 *, 0xC8) * temp_f2_319) + ((M2C_FIELD(temp_r4_311, f32 *, 0xC0) * temp_f4_315) + (M2C_FIELD(temp_r4_311, f32 *, 0xC4) * temp_f3_312))) < 0.95f)) {
        temp_r4_333 = temp_r4_311->unk8;
        temp_f1_336 = M2C_FIELD(temp_r4_333, f64 *, 0x30);
        sp30 = temp_f1_336;
        sp38 = M2C_FIELD(temp_r4_333, f64 *, 0x38);
        temp_r3_344 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **, void *, f64), 0xC)(M2C_FIELD(&gb, void ***, 0), temp_r4_333, temp_f1_336), void **, 8);
        sp40 = M2C_FIELD(temp_r3_344, f64 *, 0x30);
        sp48 = M2C_FIELD(temp_r3_344, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        var_f4_357 = 0.0f;
        sp70 = sp10;
        sp18 = (f32) sp48 - (f32) sp38;
        unksp74 = 0.0f;
        sp78 = (f64) sp18;
        var_f5_370 = ((f32) sp78 * (f32) sp78) + (((f32) sp70 * (f32) sp70) + (0.0f * 0.0f));
        if (var_f5_370 > 0.000001f) {
            if (var_f5_370 > 0.0f) {
                temp_f1_375 = __frsqrte(var_f5_370);
                temp_f1_381 = 0.5 * temp_f1_375 * -(((f64) var_f5_370 * (temp_f1_375 * temp_f1_375)) - 3.0);
                temp_f1_385 = 0.5 * temp_f1_381 * -(((f64) var_f5_370 * (temp_f1_381 * temp_f1_381)) - 3.0);
                var_f5_370 = (f32) ((f64) var_f5_370 * (0.5 * temp_f1_385 * -(((f64) var_f5_370 * (temp_f1_385 * temp_f1_385)) - 3.0)));
            } else if (var_f5_370 < M2C_BITWISE(f32, 0.0)) {
                var_f5_370 = __float_nan;
            } else {
                sp8 = var_f5_370;
                temp_r3_404 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_404) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_414 = 1;
                    } else {
                        var_r0_414 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_414 = 5;
                    } else {
                        var_r0_414 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_414 = 4;
                    break;
                }
                if (var_r0_414 == 1) {
                    var_f5_370 = __float_nan;
                }
            }
            var_f4_357 = 1.0f / var_f5_370;
        }
        temp_r4_444 = this->unkC;
        sp70 = (f32) sp70 * var_f4_357;
        unksp74 *= var_f4_357;
        sp78 = (f32) sp78 * var_f4_357;
        M2C_FIELD(temp_r4_444, f64 *, 0xE0) = (f64) sp70;
        M2C_FIELD(temp_r4_444, f64 *, 0xE8) = (f64) sp78;
        M2C_FIELD(temp_r4_444, u8 *, 0x6B5) = (u8) (M2C_FIELD(temp_r4_444, u8 *, 0x6B5) | 0x40);
    }
    temp_r3_457 = this->unkC;
    if ((s32) M2C_FIELD(temp_r3_457, AnimSequence **, 0xA50)->unk6C == 4) {
        if (temp_r3_457->HasAnimFinished() != 0) {
            this->unkC->SetAnim((AnimSequenceType) 0x11, 0, 0, 0.15f, 0U, 0U);
        }
    } else if ((u8) this->unk14 != 0) {
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (M2C_FIELD(&gb, f32 *, 0x30C) == this->unk10) {
            this->unk8 = 2;
        }
    } else if (temp_r3_457->HasAnimFinished() == 0) {
        var_r4_493 = 0;
        temp_r5_494 = M2C_FIELD(this->unkC, void **, 0x630);
        if (((u32) M2C_FIELD(temp_r5_494, u32 *, 0x2C) >> 1U) & 1) {
            var_r3_499 = 0;
            if ((M2C_FIELD(temp_r5_494, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_494, s32 *, 0x44) > 1)) {
                var_r3_499 = 1;
            }
            if (var_r3_499 != 0) {
                var_r4_493 = 1;
            }
        }
        if (var_r4_493 != 0) {
            goto block_55;
        }
    } else {
block_55:
        temp_r29_516 = this->unkC;
        var_r30_517 = 0;
        if (temp_r29_516->HasAnimFinished() != 0) {
            temp_r4_522 = M2C_FIELD(temp_r29_516, AnimSequence **, 0xA50);
            if ((temp_r4_522 != NULL) && ((u32) temp_r4_522->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_516, void **, 0x630), u32 *, 0x20))) {
                var_r30_517 = 1;
            }
        }
        if ((var_r30_517 != 0) && (temp_r3_534 = this->unkC, temp_r4_535 = M2C_FIELD(temp_r3_534, AnimSequence **, 0xA50), (((u32) temp_r4_535->unk20 == 0U) == 0))) {
            temp_r3_534->SetAnim(temp_r4_535, temp_r4_535 + 0x20, 0.15f, 0U);
        } else {
            temp_r5_545 = this->unkC;
            temp_r4_547 = M2C_FIELD(temp_r5_545, AnimSequence **, 0xA50)->unk40;
            if ((temp_r4_547 != 0) && ((u32) M2C_FIELD(M2C_FIELD(temp_r5_545, void **, 0x630), u32 *, 0x20) != temp_r4_547)) {
                M2C_FIELD(temp_r5_545, f32 *, 0x68C) = 0.0f;
                temp_r3_558 = this->unkC;
                temp_r4_559 = M2C_FIELD(temp_r3_558, AnimSequence **, 0xA50);
                temp_r3_558->SetAnim(temp_r4_559, (AnimTransition *) &temp_r4_559->unk40, 0.15f, 0U);
            }
        }
        temp_r29_563 = this->unkC;
        var_r30_564 = 0;
        if (temp_r29_563->HasAnimFinished() != 0) {
            temp_r4_569 = M2C_FIELD(temp_r29_563, AnimSequence **, 0xA50);
            if ((temp_r4_569 != NULL) && ((u32) temp_r4_569->unk40 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_563, void **, 0x630), u32 *, 0x20))) {
                var_r30_564 = 1;
            }
        }
        if (var_r30_564 != 0) {
            this->unk10 = M2C_FIELD(&gb, f32 *, 0x30C) + 3.0f;
            this->unk14 = 1;
            this->unk15 = 1;
            temp_r4_590 = this->unkC;
            temp_r3_591 = M2C_FIELD(temp_r4_590, u32 *, 0xA44);
            if (temp_r3_591 != 0U) {
                ((EventMessage *) (temp_r3_591 + 8))->Send(temp_r4_590);
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'SetMovementType'
void NPCGoal_Rescue::Activate() {
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    MKProp *temp_r3_627;
    MKProp *temp_r3_742;
    MKProp *temp_r4_620;
    f32 temp_f5_750;
    f32 temp_f6_743;
    f32 temp_f7_746;
    f32 var_f4_660;
    f32 var_f5_673;
    f64 temp_f1_640;
    f64 temp_f1_678;
    f64 temp_f1_684;
    f64 temp_f1_688;
    s32 temp_r3_707;
    s32 var_r0_717;
    void *temp_r3_647;
    void *temp_r4_638;
    void *temp_r5_760;

    this->unk8 = 0;
    this->unk10 = 0.0f;
    this->unkC->SetMovementType((CharacterMoveType) 0);
    temp_r4_620 = this->unkC;
    M2C_FIELD(temp_r4_620, f32 *, 0x68C) = (f32) M2C_FIELD(M2C_FIELD(temp_r4_620, void **, 0xA38), f32 *, 0x158);
    this->unk14 = 0;
    this->unk15 = 0;
    temp_r3_627 = this->unkC;
    if (M2C_FIELD(temp_r3_627->__vptr, u8 (**)(MKProp *, MKProp *), 0x148)(temp_r3_627, temp_r4_620) != 0) {
        temp_r4_638 = this->unkC->unk8;
        temp_f1_640 = M2C_FIELD(temp_r4_638, f64 *, 0x30);
        sp50 = temp_f1_640;
        sp58 = M2C_FIELD(temp_r4_638, f64 *, 0x38);
        temp_r3_647 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, void *, f64), 0xC)(gb, temp_r4_638, temp_f1_640), void **, 8);
        sp60 = M2C_FIELD(temp_r3_647, f64 *, 0x30);
        sp68 = M2C_FIELD(temp_r3_647, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        var_f4_660 = 0.0f;
        sp80 = sp30;
        sp38 = (f32) sp68 - (f32) sp58;
        unksp84 = 0.0f;
        sp88 = (f64) sp38;
        var_f5_673 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + (0.0f * 0.0f));
        if (var_f5_673 > 0.000001f) {
            if (var_f5_673 > 0.0f) {
                temp_f1_678 = __frsqrte(var_f5_673);
                temp_f1_684 = 0.5 * temp_f1_678 * -(((f64) var_f5_673 * (temp_f1_678 * temp_f1_678)) - 3.0);
                temp_f1_688 = 0.5 * temp_f1_684 * -(((f64) var_f5_673 * (temp_f1_684 * temp_f1_684)) - 3.0);
                var_f5_673 = (f32) ((f64) var_f5_673 * (0.5 * temp_f1_688 * -(((f64) var_f5_673 * (temp_f1_688 * temp_f1_688)) - 3.0)));
            } else if (var_f5_673 < M2C_BITWISE(f32, 0.0)) {
                var_f5_673 = __float_nan;
            } else {
                sp8 = var_f5_673;
                temp_r3_707 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_707) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_717 = 1;
                    } else {
                        var_r0_717 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_717 = 5;
                    } else {
                        var_r0_717 = 3;
                    }
                    break;
                default:
                    var_r0_717 = 4;
                    break;
                }
                if (var_r0_717 == 1) {
                    var_f5_673 = __float_nan;
                }
            }
            var_f4_660 = 1.0f / var_f5_673;
        }
        temp_r3_742 = this->unkC;
        temp_f6_743 = unksp84 * var_f4_660;
        temp_f7_746 = (f32) sp80 * var_f4_660;
        temp_f5_750 = (f32) sp88 * var_f4_660;
        sp80 = temp_f7_746;
        unksp84 = temp_f6_743;
        sp88 = temp_f5_750;
        if (((M2C_FIELD(temp_r3_742, f32 *, 0xC8) * temp_f5_750) + ((M2C_FIELD(temp_r3_742, f32 *, 0xC0) * temp_f7_746) + (M2C_FIELD(temp_r3_742, f32 *, 0xC4) * temp_f6_743))) < 0.95f) {
            temp_r5_760 = temp_r3_742->unk8;
            sp10 = -M2C_FIELD(temp_r5_760, f32 *, 0x20);
            sp14 = -M2C_FIELD(temp_r5_760, f32 *, 0x24);
            sp18 = -M2C_FIELD(temp_r5_760, f32 *, 0x28);
            sp40 = (f64) sp10;
            sp48 = (f64) sp18;
            sp20 = (up.unk4 * (f32) sp48) - (up.unk8 * unksp44);
            sp24 = (up.unk8 * (f32) sp40) - (up.unk0 * (f32) sp48);
            sp28 = (up.unk0 * unksp44) - (up.unk4 * (f32) sp40);
            sp70 = (f64) sp20;
            sp78 = (f64) sp28;
            if ((((f32) sp78 * temp_f5_750) + (((f32) sp70 * temp_f7_746) + (unksp74 * temp_f6_743))) > 0.0f) {
                temp_r3_742->SetAnim((AnimSequenceType) 4, 0x15, 0, 0.15f, 0U, 0U);
                return;
            }
            temp_r3_742->SetAnim((AnimSequenceType) 4, 0x14, 0, 0.15f, 0U, 0U);
            return;
        }
        temp_r3_742->SetAnim((AnimSequenceType) 4, 0x14, 0, 0.15f, 0U, 0U);
        return;
    }
    this->unkC->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 0U, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk93C'
s32 EnemyGoal_Summon::PositionSpawnPoints_Vanguard(bool arg0) {
    M2C_UNK sp230;
    s8 sp228;
    s32 sp224;
    s32 sp220;
    s32 sp21C;
    f32 sp218;
    s32 sp214;
    s8 sp213;
    s8 sp212;
    s16 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    AITargetData sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    M2C_UNK spF8;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    MKVector3 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    Character *temp_r3_1048;
    Character *temp_r3_1166;
    Character *temp_r6_876;
    SpawnPointObject *temp_r3_1214;
    SpawnPointObject *temp_r3_1291;
    SpawnerObject *temp_r3_878;
    f32 temp_f1_1178;
    f32 temp_f22_1062;
    f32 temp_f25_956;
    f64 temp_f1_960;
    s32 temp_r30_895;
    s32 temp_r3_894;
    s32 var_r21_1005;
    s32 var_r21_1058;
    s32 var_r24_1007;
    s32 var_r24_1056;
    s32 var_r24_1270;
    s32 var_r25_1039;
    s32 var_r26_1037;
    s32 var_r27_877;
    s32 var_r28_893;
    s32 var_r29_1003;
    u32 *temp_r5_881;
    u32 *var_r4_882;
    void *temp_r3_1025;
    void *temp_r3_1276;
    void *temp_r3_1279;
    void *temp_r3_1284;
    void *temp_r3_967;
    void *temp_r4_1293;
    void *temp_r4_958;
    void *temp_r5_1215;
    void *temp_r6_1314;

    temp_r6_876 = this->unkC;
    var_r27_877 = 0;
    temp_r3_878 = temp_r6_876->unk110.unk93C;
    if (temp_r3_878 != NULL) {
        temp_r5_881 = temp_r3_878->unk44;
        var_r4_882 = temp_r5_881;
loop_3:
        if ((u32) *var_r4_882 != 0) {
            var_r4_882 += 4;
            goto loop_3;
        }
        var_r28_893 = 0;
        temp_r3_894 = temp_r6_876->unk110.unk928->unkF4;
        temp_r30_895 = (s32) (var_r4_882 - temp_r5_881) / 4;
        switch (temp_r3_894) {
        case 3:
            var_r28_893 = 0x10000000;
            break;
        case 6:
            var_r28_893 = 0x40000000;
            break;
        case 9:
            var_r28_893 = 0x08000000;
            break;
        case 12:
            var_r28_893 = 0x20000000;
            break;
        case 15:
            var_r28_893 = 0x40000000;
            break;
        }
        if ((void *) this->unk10 == NULL) {
            sp148.GetDir();
            sp1C8 = M2C_BITWISE(f64, sp148);
            sp1D0 = (f64) sp148.unk8;
            sp90 = (up.unk0 * unksp1CC) - (up.unk4 * (f32) sp1C8);
            sp8C = (up.unk8 * (f32) sp1C8) - (up.unk0 * (f32) sp1D0);
            sp88 = (up.unk4 * (f32) sp1D0) - (up.unk8 * unksp1CC);
            sp1C0 = (f64) sp90;
            sp1B8 = (f64) sp88;
            temp_f25_956 = KDMath_GetYaw(*((MKVector3 *) &sp1C8));
            temp_r4_958 = this->unkC->unk8;
            temp_f1_960 = M2C_FIELD(temp_r4_958, f64 *, 0x30);
            sp118 = temp_f1_960;
            sp120 = M2C_FIELD(temp_r4_958, f64 *, 0x38);
            temp_r3_967 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, void *, f64), 0xC)(gb, temp_r4_958, temp_f1_960), void **, 8);
            sp128 = M2C_FIELD(temp_r3_967, f64 *, 0x30);
            sp130 = M2C_FIELD(temp_r3_967, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp138 = sp78;
            sp80 = (f32) sp130 - (f32) sp120;
            sp140 = (f64) sp80;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            sp148.unk40 = sp68;
            sp70 = (f32) sp140 * 0.5f;
            sp148.unk40.unk8 = (f64) sp70;
            spF8.GetPos();
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            var_r29_1003 = 0;
            var_r21_1005 = 0;
            var_r24_1007 = 0;
            sp108 = sp18;
            sp20 = sp100 + M2C_BITWISE(f32, sp148.unk40.unk8);
            sp1A8 = sp18;
            sp110 = (f64) sp20;
            sp1B0 = (f64) sp20;
            do {
                KDMath_GetDirection(temp_f25_956 + *(&fVanguardAngles + var_r24_1007));
                temp_r3_1025 = &sp230 + var_r21_1005;
                var_r29_1003 += 1;
                M2C_FIELD(temp_r3_1025, f64 *, 0) = spE8;
                var_r21_1005 += 0x10;
                var_r24_1007 += 4;
                M2C_FIELD(temp_r3_1025, f64 *, 8) = spF0;
            } while (var_r29_1003 < 5);
            var_r26_1037 = 0;
            var_r25_1039 = 0;
loop_26:
            if (var_r25_1039 < 4) {
                if (var_r26_1037 >= temp_r30_895) {

                } else {
                    temp_r3_1048 = this->unkC;
                    var_r24_1056 = 0;
                    var_r21_1058 = 0;
                    temp_f22_1062 = (175.0f * (f32) (var_r25_1039 + 1)) + 10.0f + M2C_FIELD(temp_r3_1048->__vptr, f32 (**)(Character *), 0x100)(temp_r3_1048);
loop_23:
                    if ((var_r24_1056 < 5) && (var_r26_1037 < temp_r30_895)) {
                        spC8.operator*(temp_f22_1062);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        sp58 = 0.0f;
                        sp5C = 500.0f;
                        sp10 = (f32) sp1B0 + spC8.unk8;
                        sp60 = 0.0f;
                        sp198 = sp8;
                        spB8 = (f64) sp58;
                        spD8 = sp8;
                        spE0 = (f64) sp10;
                        sp1A0 = (f64) sp10;
                        spC0 = (f64) sp60;
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        sp1D8 = 0.0f;
                        sp148.unk30 = sp48;
                        sp50 = (f32) sp1A0 + (f32) spC0;
                        sp1DC = 0.0f;
                        sp148.unk38 = (f64) sp50;
                        sp1E0 = 0.0f;
                        sp1E8 = 0.0f;
                        sp1EC = 0.0f;
                        sp1F0 = 0.0f;
                        sp1F8 = 0.0f;
                        sp1FC = 0.0f;
                        sp200 = 0.0f;
                        sp204 = 1.0f;
                        sp208 = 0.0f;
                        sp20C = 0.0f;
                        sp210 = 0;
                        sp212 = 0;
                        sp213 = 0;
                        sp214 = 0;
                        sp218 = 3.4028235e38f;
                        sp21C = 0;
                        sp220 = 0;
                        sp224 = -1;
                        sp228 = 0;
                        if ((MKCollision_GetGroundPoint(*((MKVector3 *) &sp148.unk30), 1000.0f, (MKCollisionResult *) &sp1D8, M2C_FIELD(this->unkC->unk110.unk460, s32 *, 0x18), 2, NULL, (MKCollisionMode) 6) != 0) && ((f32) fabs(sp1DC - unksp19C) < 100.0f)) {
                            unksp19C = sp1DC;
                            sp148.unk30 = sp198;
                            sp148.unk38 = sp1A0;
                            sp148.unk34 += 185.0f;
                            if (MKCollision_SphereCollide(*((MKVector3 *) &sp148.unk30), 175.0f, (MKCollisionResult *) &sp1D8, 1, (MKCollisionMode) 7, M2C_FIELD(this->unkC->unk110.unk460, s32 *, 0x18)) == 0) {
                                temp_r3_1166 = this->unkC;
                                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
                                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                                temp_f1_1178 = M2C_FIELD((&sp230 + var_r21_1058), f32 *, 8) * (1.0f + M2C_FIELD(temp_r3_1166->__vptr, f32 (**)(Character *), 0x100)(temp_r3_1166));
                                spA8 = sp38;
                                sp40 = temp_f1_1178;
                                spB0 = (f64) sp40;
                                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                                sp148.unk20 = sp28;
                                sp30 = (f32) sp1B0 + (f32) spB0;
                                sp148.unk28 = (f64) sp30;
                                unksp16C += 175.0f;
                                if (MKCollision_RayCollide(*((MKVector3 *) &sp148.unk30), *((MKVector3 *) &sp148.unk20), (MKCollisionResult *) &sp1D8, (MKCollisionMode) 7, M2C_FIELD(this->unkC->unk110.unk460, s32 *, 0x18)) == 0) {
                                    var_r27_877 += 1;
                                    if (arg0 == 0) {
                                        temp_r3_1214 = this->unkC->unk110.unk93C->GetSpawnPoint(var_r26_1037);
                                        temp_r5_1215 = temp_r3_1214->unk4;
                                        var_r26_1037 += 1;
                                        M2C_FIELD(temp_r5_1215, s32 *, 4) = (s32) (M2C_FIELD(temp_r5_1215, s32 *, 4) | (var_r28_893 | 0x200));
                                        temp_r3_1214->unk40 = (f32) sp198;
                                        temp_r3_1214->unk44 = unksp19C;
                                        temp_r3_1214->unk48 = (f32) sp1A0;
                                        temp_r3_1214->unk4C = 1.0f;
                                        temp_r3_1214->unk30 = (f32) sp1C8;
                                        temp_r3_1214->unk34 = unksp1CC;
                                        temp_r3_1214->unk38 = (f32) sp1D0;
                                        temp_r3_1214->unk3C = 0.0f;
                                        temp_r3_1214->unk20 = up.unk0;
                                        temp_r3_1214->unk24 = up.unk4;
                                        temp_r3_1214->unk28 = up.unk8;
                                        temp_r3_1214->unk2C = 0.0f;
                                        temp_r3_1214->unk10 = (f32) sp1B8;
                                        temp_r3_1214->unk14 = unksp1BC;
                                        temp_r3_1214->unk18 = (f32) sp1C0;
                                        temp_r3_1214->unk1C = 0.0f;
                                    }
                                }
                            }
                        }
                        var_r24_1056 += 1;
                        var_r21_1058 += 0x10;
                        goto loop_23;
                    }
                    var_r25_1039 += 1;
                    goto loop_26;
                }
            }
        } else {
            var_r24_1270 = 0;
loop_34:
            if (var_r24_1270 < temp_r30_895) {
                if (arg0 == 0) {
                    temp_r3_1276 = M2C_FIELD(this->unk10, void **, 0x54);
                    if (temp_r3_1276 != NULL) {
                        temp_r3_1279 = M2C_FIELD(temp_r3_1276, void **, 0x18);
                        temp_r3_1284 = M2C_FIELD(temp_r3_1279, s32 *, 0x24) + (var_r24_1270 * M2C_FIELD(temp_r3_1279, s32 *, 0x1C));
                        sp148.unk10 = M2C_FIELD(temp_r3_1284, f64 *, 0);
                        sp148.unk18 = M2C_FIELD(temp_r3_1284, f64 *, 8);
                        temp_r3_1291 = this->unkC->unk110.unk93C->GetSpawnPoint(var_r24_1270);
                        temp_r4_1293 = temp_r3_1291->unk4;
                        M2C_FIELD(temp_r4_1293, s32 *, 4) = (s32) (M2C_FIELD(temp_r4_1293, s32 *, 4) | (var_r28_893 | 0x200));
                        ((Matrix *) (temp_r3_1291 + 0x10))->SetIdentity();
                        temp_r3_1291->unk40 = (f32) sp148.unk10;
                        temp_r3_1291->unk44 = unksp15C;
                        temp_r3_1291->unk48 = (f32) sp148.unk18;
                        temp_r3_1291->unk4C = 1.0f;
                        temp_r6_1314 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, f32), 0xC)(gb, (f32) sp148.unk18), void **, 8);
                        sp98 = M2C_FIELD(temp_r6_1314, f64 *, 0x30);
                        spA0 = M2C_FIELD(temp_r6_1314, f64 *, 0x38);
                        temp_r3_1291->unk10.SetLookAt(*((MKVector3 *) &sp148.unk10), *((MKVector3 *) &sp98));
                    }
                }
                var_r27_877 += 1;
                var_r24_1270 += 1;
                goto loop_34;
            }
        }
    }
    return var_r27_877;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk57C'
void EnemyGoal_ReceiveOrders::Terminate() {
    this->unkC->unk110.unk57C = 0.0f;
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk940'
u8 EnemyGoal_ReceiveOrders::Update() {
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;                                       /* compiler-managed */
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp8;
    Character *temp_r29_1378;
    Character *temp_r3_1399;
    Character *temp_r4_1405;
    Character *temp_r4_1515;
    f32 var_f3_1504;
    f32 var_f4_1437;
    f64 temp_f1_1443;
    f64 temp_f1_1449;
    f64 temp_f1_1453;
    s32 temp_r3_1472;
    s32 var_r0_1482;
    u32 *temp_r4_1384;
    u8 var_r30_1379;
    void *temp_r3_1408;
    void *temp_r4_1407;

    ActivateIfInactive();
    temp_r29_1378 = this->unkC;
    var_r30_1379 = 0;
    if (temp_r29_1378->HasAnimFinished() != 0) {
        temp_r4_1384 = temp_r29_1378->unk110.unk940;
        if ((temp_r4_1384 != NULL) && ((u32) *temp_r4_1384 == (u32) temp_r29_1378->unk110.unk520->unk20)) {
            var_r30_1379 = 1;
        }
    }
    if (var_r30_1379 != 0) {
        this->unk8 = 2;
        temp_r3_1399 = this->unkC;
        temp_r3_1399->unk110.unk9FA &= ~1;
    } else {
        temp_r4_1405 = this->unkC;
        temp_r4_1407 = temp_r4_1405->unk8;
        temp_r3_1408 = M2C_FIELD(temp_r4_1405->unk110.unk924, void **, 8);
        sp20 = M2C_FIELD(temp_r4_1407, f64 *, 0x30);
        sp30 = M2C_FIELD(temp_r3_1408, f64 *, 0x30);
        sp28 = M2C_FIELD(temp_r4_1407, f64 *, 0x38);
        sp38 = M2C_FIELD(temp_r3_1408, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp40 = sp10;
        sp18 = (f32) sp38 - (f32) sp28;
        sp48 = (f64) sp18;
        var_f4_1437 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (unksp44 * unksp44));
        if (var_f4_1437 > 0.000001f) {
            if (var_f4_1437 > 0.0f) {
                temp_f1_1443 = __frsqrte(var_f4_1437);
                temp_f1_1449 = 0.5 * temp_f1_1443 * -(((f64) var_f4_1437 * (temp_f1_1443 * temp_f1_1443)) - 3.0);
                temp_f1_1453 = 0.5 * temp_f1_1449 * -(((f64) var_f4_1437 * (temp_f1_1449 * temp_f1_1449)) - 3.0);
                var_f4_1437 = (f32) ((f64) var_f4_1437 * (0.5 * temp_f1_1453 * -(((f64) var_f4_1437 * (temp_f1_1453 * temp_f1_1453)) - 3.0)));
            } else if (var_f4_1437 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1437 = __float_nan;
            } else {
                sp8 = var_f4_1437;
                temp_r3_1472 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1472) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1482 = 1;
                    } else {
                        var_r0_1482 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1482 = 5;
                    } else {
                        var_r0_1482 = 3;
                    }
                    break;
                default:
                    var_r0_1482 = 4;
                    break;
                }
                if (var_r0_1482 == 1) {
                    var_f4_1437 = __float_nan;
                }
            }
            var_f3_1504 = 1.0f / var_f4_1437;
        } else {
            var_f3_1504 = 0.0f;
        }
        temp_r4_1515 = this->unkC;
        sp40 = (f32) sp40 * var_f3_1504;
        unksp44 *= var_f3_1504;
        sp48 = (f32) sp48 * var_f3_1504;
        M2C_FIELD(temp_r4_1515, f64 *, 0xE0) = (f64) sp40;
        M2C_FIELD(temp_r4_1515, f64 *, 0xE8) = (f64) sp48;
        temp_r4_1515->unk110.unk5A5 |= 0x40;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void EnemyGoal_ReceiveOrders::Activate() {
    Character *temp_r3_1557;
    Character *temp_r4_1579;
    u32 *temp_r5_1559;
    u8 var_r6_1558;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    this->unkC->SetAnim((AnimSequenceType) 1, 0x38, 0, 0.15f, 0U, 0U);
    temp_r3_1557 = this->unkC;
    var_r6_1558 = 0;
    temp_r5_1559 = temp_r3_1557->unk110.unk940;
    if ((temp_r5_1559 != NULL) && ((u32) *temp_r5_1559 == (u32) temp_r3_1557->unk110.unk520->unk20)) {
        var_r6_1558 = 1;
    }
    if (var_r6_1558 == 0) {
        temp_r3_1557->SetAnim((AnimSequenceType) 1, 2, 0, 0.15f, 0U, 0U);
    }
    temp_r4_1579 = this->unkC;
    temp_r4_1579->unk110.unk57C = temp_r4_1579->unk110.unk928->unk154;
}
#endif

void EnemyGoal_GiveOrders::Terminate() {
    this->unk8 = 1;
}

u64 EnemyGoal_GiveOrders::GetOderMask(int arg0) {
    if ((u32) arg0 <= 0xFU) {
        switch (arg0) {
        case 0:
        case 1:
        case 4:
        case 7:
        case 10:
        case 13:
            break;
        case 2:
            break;
        case 3:
            break;
        case 5:
            break;
        case 6:
            break;
        case 8:
            break;
        case 9:
            break;
        case 11:
            break;
        case 12:
            break;
        case 14:
            break;
        case 15:
            break;
        }
    }
    return 0U;
}

#if 0 // DRAFT: undefined identifier 'unk520'
u8 EnemyGoal_GiveOrders::Update() {
    f32 sp44;
    s8 sp40;
    u32 sp3C;
    s32 sp38;
    Enemy *sp30;
    s32 sp2C;
    s32 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp8;
    Enemy *temp_r11_1686;
    Enemy *temp_r29_1713;
    Enemy *temp_r3_1663;
    Enemy *temp_r3_1734;
    Enemy *temp_r3_1740;
    Enemy *temp_r4_1758;
    u32 *temp_r4_1719;
    u64 temp_ret_1685;
    u8 var_r30_1714;
    u8 var_r30_1741;
    void *temp_r10_1690;

    temp_r3_1663 = this->unkC;
    if (temp_r3_1663->IsDead() == 0) {
        this->unkC->SelectTarget();
    }
    ActivateIfInactive();
    if (this->unkC->unk110.unk520->CheckEvent(0xC) != 0) {
        temp_ret_1685 = GetOderMask(this->unkC->unk110.unk928->unkF4);
        temp_r11_1686 = this->unkC;
        temp_r10_1690 = temp_r11_1686->unk8;
        sp3C = (u32) temp_ret_1685;
        sp38 = temp_ret_1685;
        sp18 = M2C_FIELD(temp_r10_1690, f64 *, 0x30);
        sp20 = M2C_FIELD(temp_r10_1690, f64 *, 0x38);
        sp2C = 0;
        sp28 = 0x74;
        sp30 = temp_r11_1686;
        sp40 = 0;
        sp44 = 0.0f;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, M2C_UNK, void *, f32), 0x94)(gMK, &sp28, 8, 0, &sp18, 1, 0, temp_r10_1690, this->unk10);
    }
    temp_r29_1713 = this->unkC;
    var_r30_1714 = 0;
    if (temp_r29_1713->HasAnimFinished() != 0) {
        temp_r4_1719 = temp_r29_1713->unk110.unk940;
        if ((temp_r4_1719 != NULL) && ((u32) *temp_r4_1719 == (u32) temp_r29_1713->unk110.unk520->unk20)) {
            var_r30_1714 = 1;
        }
    }
    if (var_r30_1714 != 0) {
        this->unk8 = 2;
        temp_r3_1734 = this->unkC;
        temp_r3_1734->unk110.unk9FB |= 0x80;
    } else {
        temp_r3_1740 = this->unkC;
        var_r30_1741 = 0;
        if (((u8) M2C_FIELD(temp_r3_1740, u8 *, 0x8B8) == 2) || (temp_r3_1740->unk110.unk760.unk40.Get() != NULL)) {
            var_r30_1741 = 1;
        }
        if (var_r30_1741 != 0) {
            sp8.GetDir();
            temp_r4_1758 = this->unkC;
            M2C_FIELD(temp_r4_1758, f64 *, 0xE0) = sp8;
            M2C_FIELD(temp_r4_1758, f64 *, 0xE8) = sp10;
            temp_r4_1758->unk110.unk5A5 |= 0x40;
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk530'
void EnemyGoal_GiveOrders::Activate() {
    Enemy *temp_r4_1806;
    SB2 *temp_r3_1796;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    this->unkC->unk110.unk530->GraphFollowingOff();
    temp_r3_1796 = this->unkC->unk110.unk530;
    temp_r3_1796->unk464 &= ~0x40;
    this->unkC->SetAnim((AnimSequenceType) 1, 0x37, 0, 0.15f, 0U, 0U);
    temp_r4_1806 = this->unkC;
    temp_r4_1806->unk110.unk57C = temp_r4_1806->unk110.unk928->unk154;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9B8'
void EnemyGoal_Frozen::Terminate() {
    Enemy *temp_r3_1826;

    temp_r3_1826 = this->unkC;
    if (temp_r3_1826->unk110.unk9B8 > 0.0f) {
        temp_r3_1826->ThawIfFrozen();
    }
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk760'
u8 EnemyGoal_Frozen::Update() {
    Enemy *temp_r3_1866;
    Enemy *temp_r3_1880;
    u8 var_r31_1867;

    ActivateIfInactive();
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    if (this->unkC->WasHit() != 0) {
        this->unk8 = 2;
    } else {
        temp_r3_1866 = this->unkC;
        var_r31_1867 = 0;
        if (((u8) M2C_FIELD(temp_r3_1866, u8 *, 0x8B8) == 2) || (temp_r3_1866->unk110.unk760.unk40.Get() != NULL)) {
            var_r31_1867 = 1;
        }
        if (var_r31_1867 != 0) {
            temp_r3_1880 = this->unkC;
            if ((((u8) temp_r3_1880->unk110.unk9F8 >> 5U) & 1) || ((temp_r3_1880->unk110.unk760.GetDist() < 1000.0f) && (((u8) M2C_FIELD(this->unkC, u8 *, 0x8B9) >> 4U) & 1))) {
                this->unk8 = 2;
            }
        } else if (((u8) this->unkC->unk110.unk9F8 >> 5U) & 1) {
            this->unk8 = 2;
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: function call 'MKRand_Int(long *, int, int)' does not match
void EnemyGoal_Frozen::Activate() {
    Enemy *temp_r3_1926;
    s32 temp_r3_1937;
    struct _struct_FrozenInfo_0x10 *temp_r5_1953;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    temp_r3_1926 = this->unkC;
    temp_r3_1926->TryFreeze(1, 0, 0.0f);
    temp_r3_1937 = MKRand_Int(&gViewSeed, 0, 5);
    this->unkC->SetAnim((AnimSequenceType) FrozenInfo[temp_r3_1937].unk0, FrozenInfo[temp_r3_1937].unk4, 0, 0.15f, 0U, 0U);
    temp_r5_1953 = &FrozenInfo[temp_r3_1937];
    this->unkC->unk110.unk520->SetCurrentFrame(MKRand_Int(&gViewSeed, temp_r5_1953->unk8, temp_r5_1953->unkC));
    this->unkC->unk110.unk520->unk38 = 0.0f;
}
#endif

#if 0 // DRAFT: expression syntax error
void EnemyGoal_SpawnFromEnemyGenerator::CheckPassedThroughDoor() {
    EnemyGeneratorDoor sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    Enemy *temp_r3_1993;
    Enemy *temp_r3_2038;
    u8 temp_r3_1982;

    temp_r3_1982 = this->unk14;
    if (((temp_r3_1982 >> 7U) & 1) && !((temp_r3_1982 >> 5U) & 1)) {
        sp28.GetDoorDir();
        sp28.unk10.GetDoorPos();
        temp_r3_1993 = this->unkC;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp18 = sp8;
        sp10 = temp_r3_1993->unk110.unk480 - M2C_BITWISE(f32, sp28.unk18);
        sp20 = (f64) sp10;
        temp_r3_1993->GetCollisionRadius(&temp_r3_1993->unk110.unk478, (f32) sp28.unk8, (f32) sp20, (f64) sp10);
        this->unk14 = (this->unk14 & ~0x20) | (((u32) M2C_ERROR(/* unknown instruction: mfcr $r3 */) >> 0x19U) & 0x20);
        if (((u8) this->unk14 >> 5U) & 1) {
            this->unkC->SetInvulnerableToMeleeAttacks(1U, 0U);
            this->unkC->SetInvulnerableToBreathAttacks(1U, 0U);
            temp_r3_2038 = this->unkC;
            temp_r3_2038->unk110.unk9F1 &= ~0x80;
        }
    }
}
#endif

void EnemyGoal_SpawnFromEnemyGenerator::TryCloseDoor() {
    u8 temp_r3_2061;

    temp_r3_2061 = this->unk14;
    if (((temp_r3_2061 >> 7U) & 1) && ((temp_r3_2061 >> 5U) & 1) && !((temp_r3_2061 >> 6U) & 1)) {
        this->unk10->Close();
        this->unk14 |= 0x40;
    }
}

#if 0 // DRAFT: expression syntax error
void EnemyGoal_SpawnFromEnemyGenerator::TryOpenDoor() {
    f32 sp8;
    Enemy *temp_r3_2096;
    f32 temp_f2_2104;
    f32 temp_f3_2102;
    f32 temp_f4_2103;
    f32 temp_f5_2109;
    f32 temp_f6_2101;
    f32 temp_f7_2110;

    if (!(((u8) this->unk14 >> 7U) & 1)) {
        sp8.GetDoorPos();
        temp_r3_2096 = this->unkC;
        temp_f6_2101 = temp_r3_2096->unk110.unk47C - spC;
        temp_f3_2102 = temp_r3_2096->unk110.unk488;
        temp_f4_2103 = M2C_FIELD(temp_r3_2096, f32 *, 0x588) - sp8;
        temp_f2_2104 = temp_r3_2096->unk110.unk48C;
        temp_f5_2109 = temp_r3_2096->unk110.unk480 - sp10;
        temp_f7_2110 = temp_r3_2096->unk110.unk490;
        if (((temp_f5_2109 * temp_f5_2109) + ((temp_f4_2103 * temp_f4_2103) + (temp_f6_2101 * temp_f6_2101))) < ((temp_f7_2110 * temp_f7_2110) + ((temp_f3_2102 * temp_f3_2102) + (temp_f2_2104 * temp_f2_2104)))) {
            this->unk10->Open();
            this->unk14 |= 0x80;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk488'
void EnemyGoal_SpawnFromEnemyGenerator::Terminate() {
    f64 sp10;
    f64 sp8;
    Enemy *temp_r3_2145;
    Enemy *temp_r3_2160;
    Enemy *temp_r3_2175;
    Enemy *temp_r4_2193;
    SB2 *temp_r3_2150;
    void *temp_r5_2178;

    temp_r3_2145 = this->unkC;
    temp_r3_2145->unk110.unk488 = 0.0f;
    temp_r3_2145->unk110.unk48C = 0.0f;
    temp_r3_2145->unk110.unk490 = 0.0f;
    temp_r3_2150 = this->unkC->unk110.unk530;
    temp_r3_2150->unk464 &= ~0x80;
    this->unkC->unk110.unk530->SeekOff();
    this->unkC->unk110.unk530->PathFollowingOff();
    temp_r3_2160 = this->unkC;
    temp_r3_2160->unk110.unk46C &= 0xFFFFDFFF;
    if (!(((u8) this->unk14 >> 6U) & 1)) {
        this->unk10->Close();
    }
    if (this->unkC->unk110.unk6F0.GetPathSegment() == 0) {
        temp_r3_2175 = this->unkC;
        temp_r5_2178 = temp_r3_2175->unk8;
        sp8 = M2C_FIELD(temp_r5_2178, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r5_2178, f64 *, 0x38);
        temp_r3_2175->SetupEnemyRegion(*((MKVector3 *) &sp8), 1000.0f);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    temp_r4_2193 = this->unkC;
    temp_r4_2193->unk110.unk9F1 &= ~0x80;
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk984'
u8 EnemyGoal_SpawnFromEnemyGenerator::Update() {
    EnemyGeneratorDoor sp48;
    f64 sp40;
    f64 sp38;
    M2C_UNK sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    Enemy *temp_r3_2240;
    Enemy *temp_r3_2277;
    Enemy *temp_r3_2299;
    Enemy *temp_r3_2318;
    Enemy *temp_r3_2327;
    Enemy *temp_r3_2349;
    Enemy *temp_r3_2362;
    Enemy *temp_r3_2370;
    f32 temp_f31_2249;
    f32 temp_f31_2339;
    f64 temp_f1_2236;
    u8 var_r30_2300;
    u8 var_r30_2347;
    void *temp_r5_2281;

    ActivateIfInactive();
    TryOpenDoor();
    TryCloseDoor();
    CheckPassedThroughDoor();
    if (((KDSplinePathSegment *) this->unkC->unk110.unk984 == NULL) && ((s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(this->unk10, void **, 0), void **, 0x50), s32 *, 4) > 0)) {
        sp48.GetDoorPos();
        temp_f1_2236 = M2C_BITWISE(f64, sp48);
        sp48.unk10 = temp_f1_2236;
        sp48.unk18 = sp48.unk8;
        temp_r3_2240 = this->unkC;
        temp_f31_2249 = (2.0f * temp_r3_2240->GetCollisionRadius(temp_f1_2236)) + 200.0f;
        sp28.GetDir();
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp38 = sp8;
        sp10 = sp30 * temp_f31_2249;
        sp40 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp48.unk18 = M2C_BITWISE(f32, sp48.unk18) + (f32) sp40;
        this->unkC->unk110.unk7B0.Set(*((MKVector3 *) &sp48.unk10), 0U);
    }
    temp_r3_2277 = this->unkC;
    if ((KDSplinePathSegment *) temp_r3_2277->unk110.unk984 == NULL) {
        temp_r5_2281 = temp_r3_2277->unk8;
        sp18 = M2C_FIELD(temp_r5_2281, f64 *, 0x30);
        sp20 = M2C_FIELD(temp_r5_2281, f64 *, 0x38);
        temp_r3_2277->unk110.unk7B0.Update(*((MKVector3 *) &sp18));
    }
    if (((u8) this->unk14 >> 5U) & 1) {
        this->unkC->TryChangeEnemyRegion();
    }
    if (((u8) this->unk14 >> 5U) & 1) {
        temp_r3_2299 = this->unkC;
        var_r30_2300 = 0;
        if (((u8) M2C_FIELD(temp_r3_2299, u8 *, 0x8B8) == 2) || (temp_r3_2299->unk110.unk760.unk40.Get() != NULL)) {
            var_r30_2300 = 1;
        }
        if ((var_r30_2300 == 0) || !(((u8) M2C_FIELD(this->unkC, u8 *, 0x8B9) >> 6U) & 1)) {
            goto block_13;
        }
        goto block_18;
    }
block_13:
    temp_r3_2318 = this->unkC;
    if ((((KDSplinePathSegment *) temp_r3_2318->unk110.unk984 != NULL) && (temp_r3_2318->unk110.unk530->PathFollowingHasLooped() != 0)) || ((temp_r3_2327 = this->unkC, (((KDSplinePathSegment *) temp_r3_2327->unk110.unk984 == NULL) != 0)) && (((u8) this->unk14 >> 5U) & 1) && (temp_f31_2339 = M2C_FIELD(temp_r3_2327->__vptr, f32 (**)(), 0x100)(), M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((this->unkC->unk110.unk7B0.GetDist() == temp_f31_2339) != 0)))) {
block_18:
        var_r30_2347 = 0;
        this->unk8 = 2;
        temp_r3_2349 = this->unkC;
        if (((u8) M2C_FIELD(temp_r3_2349, u8 *, 0x8B8) == 2) || (temp_r3_2349->unk110.unk760.unk40.Get() != NULL)) {
            var_r30_2347 = 1;
        }
        if (var_r30_2347 != 0) {
            temp_r3_2362 = this->unkC;
            if (((u8) M2C_FIELD(temp_r3_2362, u8 *, 0x8B9) >> 6U) & 1) {
                temp_r3_2362->unk110.unk9F8 |= 0x40;
                temp_r3_2370 = this->unkC;
                temp_r3_2370->unk110.unk9F8 |= 0x20;
            }
        }
        return this->unk8;
    }
    this->unkC->unk110.unk8D8.Update();
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9F9'
void EnemyGoal_SpawnFromEnemyGenerator::Activate() {
    EnemyGeneratorDoor spA0;
    f64 sp98;
    f64 sp90;
    M2C_UNK sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp50;
    f32 sp48;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp8;
    Enemy *temp_r3_2414;
    Enemy *temp_r3_2418;
    Enemy *temp_r3_2427;
    Enemy *temp_r3_2555;
    Enemy *temp_r3_2594;
    Enemy *temp_r3_2643;
    Enemy *temp_r4_2607;
    Enemy *temp_r4_2620;
    KDSplinePathSegment *temp_r4_2428;
    SB2 *temp_r3_2423;
    f32 temp_f1_2576;
    f32 temp_f2_2556;
    f32 var_f4_2468;
    f32 var_f5_2484;
    f64 temp_f1_2489;
    f64 temp_f1_2495;
    f64 temp_f1_2499;
    s32 temp_r3_2518;
    s32 var_r0_2528;
    void *temp_r5_2596;

    this->unk8 = 0;
    this->unk14 &= ~0x80;
    this->unk14 &= ~0x40;
    this->unk14 &= ~0x20;
    temp_r3_2414 = this->unkC;
    temp_r3_2414->unk110.unk9F9 &= ~0x10;
    temp_r3_2418 = this->unkC;
    temp_r3_2418->unk110.unk46C |= 0x2000;
    temp_r3_2423 = this->unkC->unk110.unk530;
    temp_r3_2423->unk464 |= 0x80;
    temp_r3_2427 = this->unkC;
    temp_r4_2428 = temp_r3_2427->unk110.unk984;
    if (temp_r4_2428 != NULL) {
        temp_r3_2427->unk110.unk530->PathFollowingOn(temp_r4_2428, 0U, 0U, 0U, 0U, 50.0f);
        this->unkC->unk110.unk58C = 1.0f;
        this->unkC->unk110.unk8D8.Set(6U, 0xA, 0, 0);
    } else {
        spA0.GetDoorPos();
        spA0.unk20 = M2C_BITWISE(f64, spA0);
        spA0.unk28 = spA0.unk8;
        sp80.GetSpawnPos();
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp30 = sp40;
        var_f4_2468 = 0.0f;
        unksp34 = 0.0f;
        sp48 = M2C_BITWISE(f32, spA0.unk28) - sp88;
        sp90 = sp30;
        sp98 = (f64) sp48;
        sp38 = (f64) sp48;
        var_f5_2484 = ((f32) sp98 * (f32) sp98) + (((f32) sp90 * (f32) sp90) + (unksp94 * unksp94));
        if (var_f5_2484 > 1e-12f) {
            if (var_f5_2484 > 0.0f) {
                temp_f1_2489 = __frsqrte(var_f5_2484);
                temp_f1_2495 = 0.5 * temp_f1_2489 * -(((f64) var_f5_2484 * (temp_f1_2489 * temp_f1_2489)) - 3.0);
                temp_f1_2499 = 0.5 * temp_f1_2495 * -(((f64) var_f5_2484 * (temp_f1_2495 * temp_f1_2495)) - 3.0);
                var_f5_2484 = (f32) ((f64) var_f5_2484 * (0.5 * temp_f1_2499 * -(((f64) var_f5_2484 * (temp_f1_2499 * temp_f1_2499)) - 3.0)));
            } else if (var_f5_2484 < M2C_BITWISE(f32, 0.0)) {
                var_f5_2484 = __float_nan;
            } else {
                sp8 = var_f5_2484;
                temp_r3_2518 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_2518) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2528 = 1;
                    } else {
                        var_r0_2528 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2528 = 5;
                    } else {
                        var_r0_2528 = 3;
                    }
                    break;
                default:
                    var_r0_2528 = 4;
                    break;
                }
                if (var_r0_2528 == 1) {
                    var_f5_2484 = __float_nan;
                }
            }
            var_f4_2468 = 1.0f / var_f5_2484;
        }
        temp_r3_2555 = this->unkC;
        temp_f2_2556 = (f32) sp90 * var_f4_2468;
        sp28 = (f32) sp98 * var_f4_2468;
        sp20 = temp_f2_2556;
        sp24 = unksp94 * var_f4_2468;
        spA0.unk18 = (f64) sp28;
        spA0.unk10 = (f64) sp20;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_f1_2576 = M2C_BITWISE(f32, spA0.unk18) * ((2.0f * temp_r3_2555->GetCollisionRadius((f64) sp20, temp_f2_2556)) + 200.0f);
        sp70 = sp10;
        sp18 = temp_f1_2576;
        sp78 = (f64) sp18;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spA0.unk28 = M2C_BITWISE(f32, spA0.unk28) + (f32) sp78;
        this->unkC->unk110.unk7B0.Set(*((MKVector3 *) &spA0.unk20), 0U);
        temp_r3_2594 = this->unkC;
        temp_r5_2596 = temp_r3_2594->unk8;
        sp60 = M2C_FIELD(temp_r5_2596, f64 *, 0x30);
        sp68 = M2C_FIELD(temp_r5_2596, f64 *, 0x38);
        temp_r3_2594->unk110.unk7B0.Update(*((MKVector3 *) &sp60));
        sp50.GetDir();
        temp_r4_2607 = this->unkC;
        M2C_FIELD(temp_r4_2607, f64 *, 0xE0) = sp50;
        M2C_FIELD(temp_r4_2607, f64 *, 0xE8) = sp58;
        M2C_FIELD(temp_r4_2607, f64 *, 0xC0) = (f64) M2C_FIELD(temp_r4_2607, f64 *, 0xE0);
        M2C_FIELD(temp_r4_2607, f64 *, 0xC8) = (f64) M2C_FIELD(temp_r4_2607, f64 *, 0xE8);
        temp_r4_2607->unk110.unk5A5 |= 0x40;
        temp_r4_2620 = this->unkC;
        temp_r4_2620->unk110.unk530->SeekOn(&temp_r4_2620->unk110.unk7B0);
        this->unkC->unk110.unk58C = 0.0f;
        this->unkC->unk110.unk8D8.Set(0xFU, 0xA, 0, 0);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 0U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 0U);
    temp_r3_2643 = this->unkC;
    temp_r3_2643->unk110.unk9F1 |= 0x80;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk940'
void EnemyGoal_SpawnIdle::TriggerExit() {
    Enemy *temp_r3_2664;
    u32 *temp_r4_2677;
    u32 *temp_r5_2665;
    u8 var_r6_2662;

    var_r6_2662 = 0;
    temp_r3_2664 = this->unkC;
    temp_r5_2665 = temp_r3_2664->unk110.unk940;
    if ((temp_r5_2665 != NULL) && ((u32) M2C_FIELD(temp_r5_2665, u32 *, 0x40) == (u32) temp_r3_2664->unk110.unk520->unk20)) {
        var_r6_2662 = 1;
    }
    if (var_r6_2662 == 0) {
        temp_r4_2677 = temp_r3_2664->unk110.unk940;
        temp_r3_2664->SetAnim((AnimSequence *) temp_r4_2677, (AnimTransition *) (temp_r4_2677 + 0x40), 0.15f, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk530'
void EnemyGoal_SpawnIdle::Terminate() {
    Enemy *temp_r6_2714;
    SB2 *temp_r3_2710;

    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    if ((u8) this->unk10 != 0) {
        temp_r3_2710 = this->unkC->unk110.unk530;
        temp_r3_2710->unk464 |= 0x80;
        temp_r6_2714 = this->unkC;
        temp_r6_2714->unk110.unk530->GraphFollowingOn(temp_r6_2714->unk110.unk970, temp_r6_2714->unk110.unk974, (GraphFollowBehaviours) temp_r6_2714->unk110.unk980, &temp_r6_2714->unk110.unk760);
    }
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk940'
u8 EnemyGoal_SpawnIdle::Update() {
    Enemy *temp_r29_2743;
    Enemy *temp_r29_2770;
    Enemy *temp_r3_2761;
    u32 *temp_r4_2749;
    u32 *temp_r4_2764;
    u32 *temp_r4_2776;
    u8 var_r30_2744;
    u8 var_r30_2771;

    ActivateIfInactive();
    if ((u8) this->unk11 != 0) {
        temp_r29_2743 = this->unkC;
        var_r30_2744 = 0;
        if (temp_r29_2743->HasAnimFinished() != 0) {
            temp_r4_2749 = temp_r29_2743->unk110.unk940;
            if ((temp_r4_2749 != NULL) && ((u32) *temp_r4_2749 == (u32) temp_r29_2743->unk110.unk520->unk20)) {
                var_r30_2744 = 1;
            }
        }
        if (var_r30_2744 != 0) {
            temp_r3_2761 = this->unkC;
            temp_r4_2764 = temp_r3_2761->unk110.unk940;
            temp_r3_2761->SetAnim((AnimSequence *) temp_r4_2764, (AnimTransition *) (temp_r4_2764 + 0x20), 0.15f, 0U);
            this->unk11 = 0;
        }
    }
    temp_r29_2770 = this->unkC;
    var_r30_2771 = 0;
    if (temp_r29_2770->HasAnimFinished() != 0) {
        temp_r4_2776 = temp_r29_2770->unk110.unk940;
        if ((temp_r4_2776 != NULL) && ((u32) M2C_FIELD(temp_r4_2776, u32 *, 0x40) == (u32) temp_r29_2770->unk110.unk520->unk20)) {
            var_r30_2771 = 1;
        }
    }
    if (var_r30_2771 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void EnemyGoal_SpawnIdle::Activate() {
    CharacterGraphNode *temp_r0_2847;
    Enemy *temp_r4_2840;
    Enemy *temp_r4_2851;
    SB2 *temp_r3_2841;
    SB2 *temp_r3_2858;
    u32 *temp_r3_2823;
    u8 var_r4_2822;

    this->unk8 = 0;
    this->unk10 = 0;
    this->unkC->StopMovement(1U);
    this->unkC->SetAnim((AnimSequenceType) 0xF, 0x74, 0, 0.15f, 0U, 0U);
    var_r4_2822 = 0;
    temp_r3_2823 = this->unkC->unk110.unk940;
    if ((temp_r3_2823 != NULL) && ((u32) M2C_FIELD(temp_r3_2823, u32 *, 0x20) != 0U)) {
        var_r4_2822 = 1;
    }
    this->unk11 = var_r4_2822;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 0U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 0U);
    temp_r4_2840 = this->unkC;
    temp_r3_2841 = temp_r4_2840->unk110.unk530;
    if ((temp_r3_2841 != NULL) && (temp_r3_2841->unk460 & 0x4000)) {
        temp_r0_2847 = temp_r3_2841->unk448;
        if (temp_r0_2847 != NULL) {
            temp_r4_2840->unk110.unk970 = temp_r0_2847;
            temp_r4_2851 = this->unkC;
            temp_r4_2851->unk110.unk974 = temp_r4_2851->unk110.unk530->unk44C;
        }
        temp_r3_2858 = this->unkC->unk110.unk530;
        temp_r3_2858->unk464 &= ~0x80;
        this->unkC->unk110.unk530->GraphFollowingOff();
        this->unk10 = 1;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void EnemyGoal_Spawn::Terminate() {
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    this->unk8 = 1;
}
#endif

u8 EnemyGoal_Spawn::Update() {
    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void EnemyGoal_Spawn::Activate() {
    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    this->unkC->SetAnim((AnimSequenceType) 0xF, this->unk10, 0, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    PropFlagsSet((u32 *) &this->unkC->unk10, 0x40000U);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 0U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 0U);
}
#endif

void EnemyGoal_Spawn::Reset() {
    this->unk8 = 1;
    this->unk10 = 0x64;
}

void EnemyGoal_Kong::Terminate() {
    MKProp *temp_r4_2991;

    this->unk8 = 1;
    RemoveAllSubgoals();
    temp_r4_2991 = this->unkC;
    M2C_FIELD(temp_r4_2991, f32 *, 0x5E4) = (f32) M2C_FIELD(M2C_FIELD(temp_r4_2991, void **, 0x5D8), f32 *, 8);
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EnemyGoal_Kong::Update() {
    MKProp *temp_r3_3091;
    u8 temp_r31_3025;
    u8 temp_r3_3014;
    ActivateIfInactive();
    temp_r3_3014 = this->unk8;
    if (temp_r3_3014 == 3) {
        return temp_r3_3014;
    }
    temp_r31_3025 = IsActive(0x27);
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        if (temp_r31_3025 != 0) {
            arg_sp60.SetIdentity();
            arg_sp40.GetStandDir();
            arg_sp6C = 0.0f;
            arg_sp14 = (up.unk8 * arg_sp40) - (up.unk0 * arg_sp48);
            arg_sp18 = (up.unk0 * arg_sp44) - (up.unk4 * arg_sp40);
            arg_sp10 = (up.unk4 * arg_sp48) - (up.unk8 * arg_sp44);
            arg_sp58 = (f64) arg_sp18;
            arg_sp50 = (f64) arg_sp10;
            arg_sp60 = (f32) arg_sp50;
            arg_sp64 = arg_sp54;
            arg_sp68 = (f32) arg_sp58;
            arg_sp30.GetStandDir();
            arg_sp80 = arg_sp30;
            arg_sp84 = arg_sp34;
            arg_sp88 = arg_sp38;
            arg_sp8C = 0.0f;
            arg_sp20.GetStandPos();
            arg_sp90 = arg_sp20;
            arg_sp94 = arg_sp24;
            arg_sp98 = arg_sp28;
            arg_sp9C = 1.0f;
            temp_r3_3091 = this->unkC;
            M2C_FIELD(temp_r3_3091->__vptr, M2C_UNK (**)(MKProp *, f32 *, f32, f32, f32), 0x5C)(temp_r3_3091, &arg_sp60, arg_sp28, arg_sp24, arg_sp20);
        }
        this->unk8 = 1;
        ActivateIfInactive();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
void EnemyGoal_Kong::Activate() {
    f64 sp130;                                      /* compiler-managed */
    f64 sp128;                                      /* compiler-managed */
    M2C_UNK sp118;
    f64 sp110;                                      /* compiler-managed */
    f64 sp108;                                      /* compiler-managed */
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;                                       /* compiler-managed */
    M2C_UNK spE8;
    M2C_UNK spD8;
    f64 spD0;                                       /* compiler-managed */
    f64 spC8;                                       /* compiler-managed */
    f32 spB8;
    ExplosiveBarrelPath sp98;
    f64 sp90;
    f64 sp88;
    M2C_UNK sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    Goal<Enemy> *temp_r4_3337;
    Goal<Enemy> *temp_r5_3347;
    Goal<Enemy> *temp_r7_3209;
    MKProp *temp_r4_3137;
    void *temp_r3_3138;
    void *temp_r3_3171;
    void *temp_r3_3241;

    this->unk8 = 0;
    RemoveAllSubgoals();
    ((AITargetData *) (this->unkC + 0x8C0))->SetDefaults();
    if ((ExplosiveBarrelPath *) this->unk28 == NULL) {
        this->unk8 = 3;
        return;
    }
    sp118.GetStandPos();
    temp_r4_3137 = this->unkC;
    temp_r3_3138 = temp_r4_3137->unk8;
    sp128 = M2C_FIELD(temp_r3_3138, f64 *, 0x30);
    sp130 = M2C_FIELD(temp_r3_3138, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp58 = sp8;
    sp10 = (f32) sp130 - sp120;
    sp68 = sp8;
    sp60 = (f64) sp10;
    sp70 = (f64) sp10;
    if (!((((f32) sp60 * (f32) sp60) + (((f32) sp58 * (f32) sp58) + (unksp5C * unksp5C))) < 2500.0f)) {
        spE8.GetStandPos();
        temp_r3_3171 = this->unkC->unk8;
        spF8 = M2C_FIELD(temp_r3_3171, f64 *, 0x30);
        sp100 = M2C_FIELD(temp_r3_3171, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp108 = sp28;
        sp30 = (f32) sp100 - spF0;
        sp110 = (f64) sp30;
        sp108.MagSquared();
        spD8.GetStandPos();
        ((AITargetData *) (this->unkC + 0x8C0))->Set(*((MKVector3 *) &spD8), 0U);
        ((AITargetData *) (this->unkC + 0x8C0))->SetInsideRegion(1U);
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
        temp_r7_3209 = this->unk2C;
        M2C_FIELD(temp_r7_3209, void **, 0x10) = (void *) (this->unkC + 0x8C0);
        M2C_FIELD(temp_r7_3209, f32 *, 0x18) = 50.0f;
        M2C_FIELD(temp_r7_3209, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r7_3209, u8 *, 0x30) & ~0x80);
        M2C_FIELD(temp_r7_3209, s32 *, 0x20) = 2;
        M2C_FIELD(temp_r7_3209, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r7_3209, s32 *, 0x28) = -1;
        M2C_FIELD(temp_r7_3209, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r7_3209, u8 *, 0x30) | 0x40);
        M2C_FIELD(temp_r7_3209, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r7_3209, u8 *, 0x30) | 0x20);
        M2C_FIELD(temp_r7_3209, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r7_3209, u8 *, 0x30) & ~0x10);
        return;
    }
    M2C_FIELD(temp_r4_3137, f32 *, 0x5E4) = 0.0f;
    spB8.GetStandDir();
    temp_r3_3241 = this->unkC->unk8;
    sp18 = -M2C_FIELD(temp_r3_3241, f32 *, 0x20);
    sp1C = -M2C_FIELD(temp_r3_3241, f32 *, 0x24);
    sp20 = -M2C_FIELD(temp_r3_3241, f32 *, 0x28);
    spC8 = (f64) sp18;
    spD0 = (f64) sp20;
    if ((((f32) spD0 * spC0) + (((f32) spC8 * spB8) + (unkspCC * spBC))) < 0.95f) {
        sp78.GetStandDir();
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp88 = sp48;
        sp50 = sp80 * 500.0f;
        sp90 = (f64) sp50;
        sp98.GetStandPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp98.unk10 = sp38;
        sp40 = M2C_BITWISE(f32, sp98.unk8) + (f32) sp90;
        sp98.unk18 = (f64) sp40;
        ((AITargetData *) (this->unkC + 0x8C0))->Set(*((MKVector3 *) &sp98.unk10), 0U);
        ((AITargetData *) (this->unkC + 0x8C0))->SetInsideRegion(1U);
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
        M2C_FIELD(this->unk34, void **, 0x10) = (void *) (this->unkC + 0x8C0);
        return;
    }
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (M2C_FIELD(&gb, f32 *, 0x30C) == this->unk20) {
        this->unk20 = M2C_FIELD(&gb, f32 *, 0x30C) + 3.0f;
        this->unk24 = this->unk28->SpawnBarrel(this->unkC);
        if ((s32) this->unk24 >= 0) {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk38);
            temp_r4_3337 = this->unk38;
            M2C_FIELD(temp_r4_3337, ExplosiveBarrelPath **, 0x10) = (ExplosiveBarrelPath *) this->unk28;
            M2C_FIELD(temp_r4_3337, s32 *, 0x14) = (s32) this->unk24;
            this->unk24 = -1;
            return;
        }
    }
    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
    temp_r5_3347 = this->unk30;
    M2C_FIELD(temp_r5_3347, s32 *, 0x10) = 0;
    M2C_FIELD(temp_r5_3347, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r5_3347, s32 *, 0x18) = 0xA;
    M2C_FIELD(temp_r5_3347, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r5_3347, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r5_3347, u8 *, 0x20) & ~0x40);
}
#endif

void EnemyGoal_Kong::SetParams(ExplosiveBarrelPath *arg0) {
    this->unk28 = arg0;
}

void EnemyGoal_Kong::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk28 = NULL;
    this->unk24 = -1;
    this->unk20 = 0.0f;
}

void EnemyGoal_Kong::Deinit() {
    Goal<Enemy> *temp_r3_3421;
    Goal<Enemy> *temp_r3_3426;
    Goal<Enemy> *temp_r3_3431;
    Goal<Enemy> *temp_r3_3436;
    MKHeap *temp_r3_3452;
    void *temp_r31_3449;

    temp_r3_3421 = this->unk2C;
    temp_r3_3421->Deinit();
    temp_r3_3426 = this->unk30;
    temp_r3_3426->Deinit();
    temp_r3_3431 = this->unk34;
    temp_r3_3431->Deinit();
    temp_r3_3436 = this->unk38;
    temp_r3_3436->Deinit();
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    temp_r31_3449 = this->unk1C;
    if (temp_r31_3449 != NULL) {
        temp_r3_3452 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_3452 != NULL) {
            ((MKHeap *) (temp_r3_3452->Current()))->Free(temp_r31_3449, NULL, 0);
        } else {
            free(temp_r31_3449);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void EnemyGoal_Kong::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_3631;
    Goal<Enemy> *temp_r4_3642;
    Goal<Enemy> *temp_r5_3606;
    Goal<Enemy> *temp_r5_3622;
    MKHeap *temp_r3_3579;
    void *var_r3_3586;

    if ((u8) this->unk9 == 0) {
        operator new(0x34U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x24U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_3579 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_3579 != NULL) {
            var_r3_3586 = ((MKHeap *) (temp_r3_3579->Current()))->Alloc(4, NULL, 0);
        } else {
            var_r3_3586 = malloc(4);
        }
        this->unk1C = var_r3_3586;
        this->unk10 = 1;
    }
    this->unk8 = 1;
    this->unkC = (MKProp *) arg0;
    this->unk4 = 0x48;
    if ((MKProp *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r5_3606 = this->unk2C;
    M2C_FIELD(temp_r5_3606, s8 *, 8) = 1;
    M2C_FIELD(temp_r5_3606, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r5_3606, s32 *, 4) = 0x21;
    if ((Enemy *) M2C_FIELD(temp_r5_3606, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r5_3606, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r5_3606, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r5_3606, u8 *, 0x30) & ~0x10);
    temp_r5_3622 = this->unk30;
    M2C_FIELD(temp_r5_3622, s8 *, 8) = 1;
    M2C_FIELD(temp_r5_3622, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r5_3622, s32 *, 4) = 0;
    if ((Enemy *) M2C_FIELD(temp_r5_3622, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r5_3622, s8 *, 9) = 1;
    }
    temp_r4_3631 = this->unk34;
    M2C_FIELD(temp_r4_3631, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3631, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3631, s32 *, 4) = 0x27;
    if ((Enemy *) M2C_FIELD(temp_r4_3631, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3631, s8 *, 9) = 1;
    }
    temp_r4_3642 = this->unk38;
    M2C_FIELD(temp_r4_3642, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3642, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3642, s32 *, 4) = 0x49;
    if ((Enemy *) M2C_FIELD(temp_r4_3642, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3642, s8 *, 9) = 1;
    }
}
#endif

void EnemyGoal_PushBarrel::Terminate() {
    s32 temp_r4_3668;

    temp_r4_3668 = this->unk14;
    if (temp_r4_3668 != -1) {
        this->unk10->PushBarrel(temp_r4_3668);
        this->unk14 = -1;
    }
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unk520'
u8 EnemyGoal_PushBarrel::Update() {
    ExplosiveBarrelPath *temp_r3_3703;
    s32 temp_r4_3700;

    ActivateIfInactive();
    if (this->unkC->unk110.unk520->CheckEvent(0xE) != 0) {
        temp_r4_3700 = this->unk14;
        if (temp_r4_3700 >= 0) {
            temp_r3_3703 = this->unk10;
            if (temp_r3_3703 != NULL) {
                temp_r3_3703->PushBarrel(temp_r4_3700);
                this->unk14 = -1;
            }
        }
    }
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void EnemyGoal_PushBarrel::Activate() {
    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    this->unkC->SetAnim((AnimSequenceType) 0x12, 0xC9, 0, 0.15f, 0U, 0U);
}
#endif

void EnemyGoal_OperateLever::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: undefined identifier '__vptr'
u8 EnemyGoal_OperateLever::Update() {
    Enemy *temp_r3_3875;
    u8 temp_r31_3809;
    u8 temp_r3_3798;
    ActivateIfInactive();
    if (this->unk24.Get() != NULL) {
        checked_cast<Lever *, MKProp>(M2C_FIELD(this->unk24.Get()->__vptr, MKProp *(**)(), 8)());
    } else {
        this->unk8 = 3;
    }
    temp_r3_3798 = this->unk8;
    if (temp_r3_3798 == 3) {
        return temp_r3_3798;
    }
    temp_r31_3809 = IsActive(0x21);
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        if (temp_r31_3809 != 0) {
            arg_sp60.SetIdentity();
            arg_sp40.GetStandDir();
            arg_sp6C = 0.0f;
            arg_sp14 = (up.unk8 * arg_sp40) - (up.unk0 * arg_sp48);
            arg_sp18 = (up.unk0 * arg_sp44) - (up.unk4 * arg_sp40);
            arg_sp10 = (up.unk4 * arg_sp48) - (up.unk8 * arg_sp44);
            arg_sp58 = (f64) arg_sp18;
            arg_sp50 = (f64) arg_sp10;
            arg_sp60 = (f32) arg_sp50;
            arg_sp64 = arg_sp54;
            arg_sp68 = (f32) arg_sp58;
            arg_sp30.GetStandDir();
            arg_sp80 = arg_sp30;
            arg_sp84 = arg_sp34;
            arg_sp88 = arg_sp38;
            arg_sp8C = 0.0f;
            arg_sp20.GetStandPos();
            arg_sp90 = arg_sp20;
            arg_sp94 = arg_sp24;
            arg_sp98 = arg_sp28;
            arg_sp9C = 1.0f;
            temp_r3_3875 = this->unkC;
            temp_r3_3875->Teleport(&arg_sp60, arg_sp28, arg_sp24, arg_sp20);
        }
        this->unk8 = 1;
        ActivateIfInactive();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal use of abstract class ('Lever::pure_slot16()')
void EnemyGoal_OperateLever::Activate() {
    f64 spF0;
    f64 spE8;
    M2C_UNK spD8;
    M2C_UNK spC8;
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;                                       /* compiler-managed */
    f32 spA8;
    Lever sp88;
    f64 sp80;
    f64 sp78;
    M2C_UNK sp68;
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
    Lever *var_r29_3913;
    f32 temp_r5_4123;
    s32 temp_r7_3982;
    void *temp_r3_3936;
    void *temp_r3_4012;

    this->unk8 = 0;
    RemoveAllSubgoals();
    this->unkC->unk110.unk7B0.SetDefaults();
    var_r29_3913 = NULL;
    if (this->unk24.Get() != NULL) {
        var_r29_3913 = checked_cast<Lever *, MKProp>(M2C_FIELD(this->unk24.Get()->__vptr, MKProp *(**)(), 8)());
    }
    if (var_r29_3913 == NULL) {
        this->unk8 = 3;
        return;
    }
    spD8.GetStandPos();
    temp_r3_3936 = this->unkC->unk8;
    spE8 = M2C_FIELD(temp_r3_3936, f64 *, 0x30);
    spF0 = M2C_FIELD(temp_r3_3936, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp48 = sp8;
    sp10 = (f32) spF0 - spE0;
    sp58 = sp8;
    sp50 = (f64) sp10;
    sp60 = (f64) sp10;
    if (!((((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (unksp4C * unksp4C))) < 2500.0f)) {
        spC8.GetStandPos();
        this->unkC->unk110.unk7B0.Set(*((MKVector3 *) &spC8), 0U);
        this->unkC->unk110.unk7B0.SetInsideRegion(1U);
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24.unk8);
        temp_r7_3982 = this->unk24.unk8;
        M2C_FIELD(temp_r7_3982, AITargetData **, 0x10) = &this->unkC->unk110.unk7B0;
        M2C_FIELD(temp_r7_3982, f32 *, 0x18) = 50.0f;
        M2C_FIELD(temp_r7_3982, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r7_3982, u8 *, 0x30) & ~0x80);
        M2C_FIELD(temp_r7_3982, s32 *, 0x20) = 2;
        M2C_FIELD(temp_r7_3982, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r7_3982, s32 *, 0x28) = -1;
        M2C_FIELD(temp_r7_3982, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r7_3982, u8 *, 0x30) | 0x40);
        M2C_FIELD(temp_r7_3982, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r7_3982, u8 *, 0x30) | 0x20);
        M2C_FIELD(temp_r7_3982, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r7_3982, u8 *, 0x30) & ~0x10);
        return;
    }
    spA8.GetStandDir();
    temp_r3_4012 = this->unkC->unk8;
    sp18 = -M2C_FIELD(temp_r3_4012, f32 *, 0x20);
    sp1C = -M2C_FIELD(temp_r3_4012, f32 *, 0x24);
    sp20 = -M2C_FIELD(temp_r3_4012, f32 *, 0x28);
    spB8 = (f64) sp18;
    spC0 = (f64) sp20;
    if ((((f32) spC0 * spB0) + (((f32) spB8 * spA8) + (unkspBC * spAC))) < 0.95f) {
        sp68.GetStandDir();
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp78 = sp38;
        sp40 = sp70 * 500.0f;
        sp80 = (f64) sp40;
        sp88.GetStandPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp88.unk10 = sp28;
        sp30 = M2C_BITWISE(f32, sp88.unk8) + (f32) sp80;
        sp88.unk18 = (f64) sp30;
        this->unkC->unk110.unk7B0.Set(*((MKVector3 *) &sp88.unk10), 0U);
        this->unkC->unk110.unk7B0.SetInsideRegion(1U);
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
        M2C_FIELD(this->unk34, AITargetData **, 0x10) = &this->unkC->unk110.unk7B0;
        return;
    }
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if ((M2C_FIELD(&gb, f32 *, 0x30C) == this->unk20) && ((u8) this->unk3C == 0) && ((s32) var_r29_3913->unkD0 == 0)) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk38);
        this->unk38->SetParams(var_r29_3913);
        this->unk20 = M2C_FIELD(&gb, f32 *, 0x30C) + 5.0f;
        this->unk3C = 1;
        return;
    }
    if ((u8) this->unk3C != 0) {
        this->unk8 = 2;
        return;
    }
    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, M2C_BITWISE(Goal<Enemy> *, this->unk24.unkC));
    temp_r5_4123 = this->unk24.unkC;
    M2C_FIELD(temp_r5_4123, s32 *, 0x10) = 0;
    M2C_FIELD(temp_r5_4123, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r5_4123, s32 *, 0x18) = 0xA;
    M2C_FIELD(temp_r5_4123, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r5_4123, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r5_4123, u8 *, 0x20) & ~0x40);
}
#endif

#if 0 // DRAFT: undefined identifier 'P10Targetable'
void EnemyGoal_OperateLever::SetParams(Lever *arg0) {
    this->unk24.Set(checked_cast<P10Targetable, 5Lever>__FP5Lever(arg0));
}
#endif

#if 0 // DRAFT: ambiguous access to overloaded function
void EnemyGoal_OperateLever::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk24.Set(NULL);
    this->unk3C = 0;
    this->unk20 = 0.0f;
}
#endif

#if 0 // DRAFT: pointer/array required
void EnemyGoal_OperateLever::Deinit() {
    Goal<Enemy> *temp_r3_4207;
    Goal<Enemy> *temp_r3_4212;
    MKHeap *temp_r3_4228;
    f32 temp_r3_4202;
    s32 temp_r3_4197;
    void *temp_r31_4225;

    temp_r3_4197 = this->unk24.unk8;
    M2C_FIELD(*temp_r3_4197, M2C_UNK (**)(s32), 0xC)(temp_r3_4197);
    temp_r3_4202 = this->unk24.unkC;
    M2C_FIELD(*temp_r3_4202, M2C_UNK (**)(f32), 0xC)(temp_r3_4202);
    temp_r3_4207 = this->unk34;
    temp_r3_4207->Deinit();
    temp_r3_4212 = this->unk38;
    temp_r3_4212->Deinit();
    operator delete((void *) this->unk24.unk8);
    operator delete(M2C_BITWISE(void *, this->unk24.unkC));
    operator delete(this->unk34);
    operator delete(this->unk38);
    temp_r31_4225 = this->unk1C;
    if (temp_r31_4225 != NULL) {
        temp_r3_4228 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_4228 != NULL) {
            ((MKHeap *) (temp_r3_4228->Current()))->Free(temp_r31_4225, NULL, 0);
        } else {
            free(temp_r31_4225);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}
#endif

#if 0 // DRAFT: pointer/array required
void EnemyGoal_OperateLever::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_4407;
    Goal<Enemy> *temp_r4_4418;
    MKHeap *temp_r3_4355;
    f32 temp_r5_4398;
    s32 temp_r5_4382;
    void *var_r3_4362;

    if ((u8) this->unk9 == 0) {
        operator new(0x34U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24.unk8 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x24U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24.unkC = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_4355 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_4355 != NULL) {
            var_r3_4362 = ((MKHeap *) (temp_r3_4355->Current()))->Alloc(4, NULL, 0);
        } else {
            var_r3_4362 = malloc(4);
        }
        this->unk1C = var_r3_4362;
        this->unk10 = 1;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x47;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r5_4382 = this->unk24.unk8;
    M2C_FIELD(temp_r5_4382, s8 *, 8) = 1;
    M2C_FIELD(temp_r5_4382, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r5_4382, s32 *, 4) = 0x21;
    if ((Enemy *) M2C_FIELD(temp_r5_4382, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r5_4382, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r5_4382, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r5_4382, u8 *, 0x30) & ~0x10);
    temp_r5_4398 = this->unk24.unkC;
    M2C_FIELD(temp_r5_4398, s8 *, 8) = 1;
    M2C_FIELD(temp_r5_4398, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r5_4398, s32 *, 4) = 0;
    if ((Enemy *) M2C_FIELD(temp_r5_4398, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r5_4398, s8 *, 9) = 1;
    }
    temp_r4_4407 = this->unk34;
    M2C_FIELD(temp_r4_4407, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_4407, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_4407, s32 *, 4) = 0x27;
    if ((Enemy *) M2C_FIELD(temp_r4_4407, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_4407, s8 *, 9) = 1;
    }
    temp_r4_4418 = this->unk38;
    M2C_FIELD(temp_r4_4418, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_4418, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_4418, s32 *, 4) = 0x46;
    if ((Enemy *) M2C_FIELD(temp_r4_4418, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_4418, s8 *, 9) = 1;
    }
    this->unk3C = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'P5Lever'
void EnemyGoal_PullLever::Terminate() {
    if (this->unk10.Get() != NULL) {
        ((Lever *) (checked_cast<P5Lever))->Release(6MKProp>__FP6MKProp(M2C_FIELD(this->unk10.Get()->__vptr, MKProp *(**)(), 8)()));
    }
    this->unk8 = 1;
}
#endif

u8 EnemyGoal_PullLever::Update() {
    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void EnemyGoal_PullLever::Activate() {
    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    this->unkC->SetAnim((AnimSequenceType) 0x12, 0xC8, 0, 0.15f, 0U, 0U);
    if (this->unk10.Get() != NULL) {
        ((Lever *) (checked_cast<P5Lever))->Pull(6MKProp>__FP6MKProp(M2C_FIELD(this->unk10.Get()->__vptr, MKProp *(**)(), 8)()));
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'P10Targetable'
void EnemyGoal_PullLever::SetParams(Lever *arg0) {
    this->unk10.Set(checked_cast<P10Targetable, 5Lever>__FP5Lever(arg0));
}
#endif

#if 0 // DRAFT: expression syntax error
u8 EnemyGoal_Turn::Update() {
    f64 sp50;
    f64 sp48;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    AITargetData *temp_r3_4562;
    Enemy *temp_r5_4595;
    u8 var_r31_4566;
    void *temp_r3_4585;
    void *temp_r3_4609;

    ActivateIfInactive();
    temp_r3_4562 = this->unk10;
    if (temp_r3_4562 != NULL) {
        var_r31_4566 = 0;
        if (((u8) M2C_FIELD(temp_r3_4562, u8 *, 0x48) == 2) || (temp_r3_4562->unk40.Get() != NULL)) {
            var_r31_4566 = 1;
        }
        if (var_r31_4566 == 0) {
            goto block_5;
        }
        temp_r3_4585 = this->unkC->unk8;
        sp48 = M2C_FIELD(temp_r3_4585, f64 *, 0x30);
        sp50 = M2C_FIELD(temp_r3_4585, f64 *, 0x38);
        this->unk10->Update(*((MKVector3 *) &sp48));
        sp38.GetDir();
        temp_r5_4595 = this->unkC;
        M2C_FIELD(temp_r5_4595, f64 *, 0xE0) = sp38;
        M2C_FIELD(temp_r5_4595, f64 *, 0xE8) = sp40;
        temp_r5_4595->unk110.unk5A5 |= 0x40;
        sp18.GetDir();
        temp_r3_4609 = this->unkC->unk8;
        sp8 = -M2C_FIELD(temp_r3_4609, f32 *, 0x20);
        spC = -M2C_FIELD(temp_r3_4609, f32 *, 0x24);
        sp10 = -M2C_FIELD(temp_r3_4609, f32 *, 0x28);
        sp28 = (f64) sp8;
        sp30 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if ((((f32) sp30 * sp20) + (((f32) sp28 * sp18) + (unksp2C * sp1C))) == 0.95f) {
            this->unk8 = 2;
        }
    } else {
block_5:
        this->unk8 = 3;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'up'
void EnemyGoal_Turn::Activate() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    AITargetData *temp_r3_4656;
    Enemy *temp_r3_4742;
    Enemy *temp_r3_4763;
    u8 var_r31_4653;
    void *temp_r5_4680;

    var_r31_4653 = 0;
    this->unk8 = 0;
    temp_r3_4656 = this->unk10;
    if (temp_r3_4656 != NULL) {
        if (((u8) M2C_FIELD(temp_r3_4656, u8 *, 0x48) == 2) || (temp_r3_4656->unk40.Get() != NULL)) {
            var_r31_4653 = 1;
        }
        if (var_r31_4653 == 0) {
            goto block_5;
        }
        temp_r5_4680 = this->unkC->unk8;
        sp8 = -M2C_FIELD(temp_r5_4680, f32 *, 0x20);
        spC = -M2C_FIELD(temp_r5_4680, f32 *, 0x24);
        sp10 = -M2C_FIELD(temp_r5_4680, f32 *, 0x28);
        sp48 = (f64) sp8;
        sp50 = (f64) sp10;
        sp38 = M2C_FIELD(temp_r5_4680, f64 *, 0x30);
        sp40 = M2C_FIELD(temp_r5_4680, f64 *, 0x38);
        sp18 = (up.unk4 * (f32) sp50) - (up.unk8 * unksp4C);
        sp1C = (up.unk8 * (f32) sp48) - (up.unk0 * (f32) sp50);
        sp20 = (up.unk0 * unksp4C) - (up.unk4 * (f32) sp48);
        sp58 = (f64) sp18;
        sp60 = (f64) sp20;
        this->unk10->Update(*((MKVector3 *) &sp38));
        sp28.GetDir();
        if ((((f32) sp60 * sp30) + (((f32) sp58 * sp28) + (unksp5C * sp2C))) > 0.0f) {
            this->unkC->SetAnim((AnimSequenceType) 4, 0x15, 0, 0.15f, 0U, 0U);
            temp_r3_4742 = this->unkC;
            if ((u32 *) temp_r3_4742->unk110.unk940 == NULL) {
                temp_r3_4742->SetAnim((AnimSequenceType) 1, 0xA, 0, 0.15f, 0U, 0U);
            }
        } else {
            this->unkC->SetAnim((AnimSequenceType) 4, 0x14, 0, 0.15f, 0U, 0U);
            temp_r3_4763 = this->unkC;
            if ((u32 *) temp_r3_4763->unk110.unk940 == NULL) {
                temp_r3_4763->SetAnim((AnimSequenceType) 1, 0xA, 0, 0.15f, 0U, 0U);
            }
        }
        this->unkC->StopMovement(1U);
        this->unkC->SetIdleMovementSpeed(1U);
        return;
    }
block_5:
    this->unk8 = 3;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk940'
u8 EnemyGoal_Hide::Update() {
    Character *temp_r30_4798;
    Character *temp_r3_4816;
    s32 temp_r4_4828;
    u32 *temp_r4_4804;
    u32 *temp_r4_4819;
    u8 var_r31_4799;

    ActivateIfInactive();
    temp_r30_4798 = this->unkC;
    var_r31_4799 = 0;
    if (temp_r30_4798->HasAnimFinished() != 0) {
        temp_r4_4804 = temp_r30_4798->unk110.unk940;
        if ((temp_r4_4804 != NULL) && ((u32) *temp_r4_4804 == (u32) temp_r30_4798->unk110.unk520->unk20)) {
            var_r31_4799 = 1;
        }
    }
    if (var_r31_4799 != 0) {
        temp_r3_4816 = this->unkC;
        temp_r4_4819 = temp_r3_4816->unk110.unk940;
        temp_r3_4816->SetAnim((AnimSequence *) temp_r4_4819, (AnimTransition *) (temp_r4_4819 + 0x20), 0.15f, 0U);
    } else if (this->unkC->HasAnimFinished() != 0) {
        temp_r4_4828 = this->unk10;
        if ((temp_r4_4828 != 0) && ((s32) this->unkC->unk110.unk520->unk44 >= temp_r4_4828)) {
            this->unk8 = 2;
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void EnemyGoal_Hide::Activate() {
    this->unk8 = 0;
    this->unkC->SetAnim((AnimSequenceType) 1, 0xC, this->unk14 != 0, 0.15f, 0U, 0U);
    this->unkC->StopMovement(1U);
    this->unkC->SetIdleMovementSpeed(0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9F8'
void EnemyGoal_Alert::Terminate() {
    Character *temp_r5_4883;

    temp_r5_4883 = this->unkC;
    temp_r5_4883->unk110.unk9F8 &= ~0x20;
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk520'
u8 EnemyGoal_Alert::Update() {
    f64 sp28;
    f64 sp20;
    f64 sp10;
    Character *spC;
    s32 sp8;
    AITargetData *temp_r3_4935;
    Character *temp_r4_4908;
    Character *temp_r4_4963;
    Character *temp_r4_4977;
    u8 var_r30_4939;
    void *temp_r3_4929;
    void *temp_r3_4953;

    ActivateIfInactive();
    if (this->unkC->unk110.unk520->CheckEvent(6) != 0) {
        temp_r4_4908 = this->unkC;
        temp_r4_4908->unk110.unk57C = temp_r4_4908->unk110.unk928->unk160;
    }
    if (((void *) this->unk14 != NULL) && (this->unkC->unk110.unk520->CheckEvent(0xC) != 0)) {
        spC = NULL;
        sp8 = 0x168;
        spC = this->unkC;
        temp_r3_4929 = this->unk14;
        M2C_FIELD(M2C_FIELD(temp_r3_4929, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_4929, &sp8);
    }
    temp_r3_4935 = this->unk10;
    if (temp_r3_4935 != NULL) {
        var_r30_4939 = 0;
        if (((u8) M2C_FIELD(temp_r3_4935, u8 *, 0x48) == 2) || (temp_r3_4935->unk40.Get() != NULL)) {
            var_r30_4939 = 1;
        }
        if (var_r30_4939 != 0) {
            temp_r3_4953 = this->unkC->unk8;
            sp20 = M2C_FIELD(temp_r3_4953, f64 *, 0x30);
            sp28 = M2C_FIELD(temp_r3_4953, f64 *, 0x38);
            this->unk10->Update(*((MKVector3 *) &sp20));
            sp10.GetDir();
            temp_r4_4963 = this->unkC;
            M2C_FIELD(temp_r4_4963, f64 *, 0xE0) = sp10;
            M2C_FIELD(temp_r4_4963, f64 *, 0xE8) = sp18;
            temp_r4_4963->unk110.unk5A5 |= 0x40;
        }
    }
    if (this->unkC->HasAnimFinished() != 0) {
        temp_r4_4977 = this->unkC;
        temp_r4_4977->unk110.unk9F8 |= 0x40;
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk940'
void EnemyGoal_Alert::Activate() {
    Character *temp_r3_5056;
    Character *temp_r5_5003;
    u32 *temp_r3_5004;

    this->unk8 = 0;
    temp_r5_5003 = this->unkC;
    temp_r3_5004 = temp_r5_5003->unk110.unk940;
    if ((temp_r3_5004 != NULL) && ((s32) M2C_FIELD(temp_r3_5004, s32 *, 0x6C) == 1) && ((s32) M2C_FIELD(temp_r3_5004, s32 *, 0x68) == 0xA6)) {
        temp_r5_5003->SetAnim((AnimSequenceType) 1, 0xA7, 0, 0.15f, 0U, 0U);
    } else if (!(((u8) temp_r5_5003->unk110.unk9F1 >> 5U) & 1)) {
        if (((void *) this->unk14 != NULL) && (temp_r5_5003->unk110.unk928->GetAnimSequence(1, 8, temp_r5_5003->unk110.unk9D4, NULL) != NULL)) {
            this->unkC->SetAnim((AnimSequenceType) 1, 8, 0, 0.15f, 0U, 0U);
        } else {
            this->unkC->SetAnim((AnimSequenceType) 1, 2, 0, 0.15f, 0U, 0U);
        }
        temp_r3_5056 = this->unkC;
        temp_r3_5056->unk110.unk9F1 |= 0x20;
    } else if (M2C_FIELD(temp_r5_5003->__vptr, u8 (**)(Character *), 0x188)(temp_r5_5003) != 0) {
        this->unkC->SetAnim((AnimSequenceType) 1, 0xFA, 0, 0.15f, 0U, 0U);
    } else {
        this->unkC->SetAnim((AnimSequenceType) 1, 0xA, 0, 0.15f, 0U, 0U);
    }
    this->unkC->StopMovement(1U);
    this->unkC->SetIdleMovementSpeed(1U);
    this->unkC->unk110.unk57C = this->unk18;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5E8'
void EnemyGoal_AttackIdle::Terminate() {
    this->unkC->unk110.unk5E8 = 0;
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk760'
u8 EnemyGoal_AttackIdle::Update() {
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp8;
    Enemy *temp_r3_5125;
    Enemy *temp_r3_5147;
    Enemy *temp_r3_5187;
    Enemy *temp_r3_5205;
    Enemy *temp_r3_5234;
    Enemy *temp_r4_5159;
    Enemy *temp_r4_5273;
    Enemy *temp_r5_5142;
    Enemy *temp_r5_5177;
    MKAnimScript *temp_r5_5251;
    s32 temp_r4_5277;
    u8 var_r30_5126;
    u8 var_r30_5188;
    u8 var_r3_5256;
    u8 var_r4_5250;
    void *temp_r5_5148;

    ActivateIfInactive();
    temp_r3_5125 = this->unkC;
    var_r30_5126 = 0;
    if (((u8) M2C_FIELD(temp_r3_5125, u8 *, 0x8B8) == 2) || (temp_r3_5125->unk110.unk760.unk40.Get() != NULL)) {
        var_r30_5126 = 1;
    }
    if (var_r30_5126 != 0) {
        this->unkC->SetIdleMovementSpeed(1U);
        temp_r5_5142 = this->unkC;
        temp_r5_5142->unk110.unk57C = temp_r5_5142->unk110.unk928->unk154;
        temp_r3_5147 = this->unkC;
        temp_r5_5148 = temp_r3_5147->unk8;
        sp28 = M2C_FIELD(temp_r5_5148, f64 *, 0x30);
        sp30 = M2C_FIELD(temp_r5_5148, f64 *, 0x38);
        temp_r3_5147->unk110.unk760.Update(*((MKVector3 *) &sp28));
        sp18.GetDir();
        temp_r4_5159 = this->unkC;
        M2C_FIELD(temp_r4_5159, f64 *, 0xE0) = sp18;
        M2C_FIELD(temp_r4_5159, f64 *, 0xE8) = sp20;
        temp_r4_5159->unk110.unk5A5 |= 0x40;
        if (this->unkC->unk110.unk760.unk40.Get() != NULL) {
            temp_r5_5177 = this->unkC;
            M2C_FIELD(this->unkC->unk110.unk760.unk40.Get()->__vptr, M2C_UNK (**)(M2C_UNK *, M2C_UNK *), 0x28)(&temp_r5_5177->unk110.unk478, &temp_r5_5177->unk110.unk5F0);
        }
    }
    if (((u8) this->unk18 >> 7U) & 1) {
        temp_r3_5187 = this->unkC;
        var_r30_5188 = 0;
        if (((u8) M2C_FIELD(temp_r3_5187, u8 *, 0x8B8) == 2) || (temp_r3_5187->unk110.unk760.unk40.Get() != NULL)) {
            var_r30_5188 = 1;
        }
        if ((var_r30_5188 == 0) || (sp8.GetDir(), temp_r3_5205 = this->unkC, ((((temp_r3_5205->unkC8 * sp10) + ((temp_r3_5205->unkC0 * sp8) + (temp_r3_5205->unkC4 * spC))) > 0.95f) != 0))) {
            this->unk8 = 2;
        }
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (M2C_FIELD(&gb, f32 *, 0x30C) == this->unkC->unk110.unk96C) {
            this->unk8 = 2;
        }
    } else {
        temp_r3_5234 = this->unkC;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (M2C_FIELD(&gb, f32 *, 0x30C) == temp_r3_5234->unk110.unk96C) {
            this->unk8 = 2;
        } else if (temp_r3_5234->HasAnimFinished() == 0) {
            var_r4_5250 = 0;
            temp_r5_5251 = this->unkC->unk110.unk520;
            if (((u32) temp_r5_5251->unk2C >> 1U) & 1) {
                var_r3_5256 = 0;
                if ((temp_r5_5251->unk38 > 0.0f) || ((s32) temp_r5_5251->unk44 > 1)) {
                    var_r3_5256 = 1;
                }
                if (var_r3_5256 != 0) {
                    var_r4_5250 = 1;
                }
            }
            if (var_r4_5250 != 0) {
                goto block_25;
            }
        } else {
block_25:
            temp_r4_5273 = this->unkC;
            temp_r4_5273->unk110.unk9DC += 1;
            temp_r4_5277 = this->unk10;
            if ((temp_r4_5277 != 0) && ((s32) this->unkC->unk110.unk9DC >= temp_r4_5277)) {
                this->unk8 = 2;
            } else {
                this->unkC->SetAnim((AnimSequenceType) 1, this->unk14, 0, 0.15f, 0U, 0U);
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9F8'
void EnemyGoal_AttackIdle::Activate() {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Enemy *temp_r3_5339;
    Enemy *temp_r3_5374;
    Enemy *temp_r3_5408;
    Enemy *temp_r4_5388;
    Enemy *temp_r5_5315;
    Enemy *temp_r5_5362;
    EnemyDescriptor *temp_r3_5389;
    u8 var_r30_5340;
    u8 var_r30_5375;
    void *temp_r5_5396;
    void *temp_r6_5431;

    this->unk8 = 0;
    temp_r5_5315 = this->unkC;
    if ((((u8) temp_r5_5315->unk110.unk9F8 >> 1U) & 1) && (temp_r5_5315->unk110.unk928->GetAnimSequence(1, 4, temp_r5_5315->unk110.unk9D4, NULL) != NULL)) {
        this->unk14 = 4;
        this->unkC->SetHitTarget(0U);
    }
    this->unkC->unk110.unk9DC = 0;
    this->unkC->StopMovement(1U);
    temp_r3_5339 = this->unkC;
    var_r30_5340 = 0;
    if (((u8) M2C_FIELD(temp_r3_5339, u8 *, 0x8B8) == 2) || (temp_r3_5339->unk110.unk760.unk40.Get() != NULL)) {
        var_r30_5340 = 1;
    }
    if ((var_r30_5340 != 0) && (this->unkC->unk110.unk760.unk40.Get() != NULL)) {
        temp_r5_5362 = this->unkC;
        if (M2C_FIELD(this->unkC->unk110.unk760.unk40.Get()->__vptr, u8 (**)(M2C_UNK *, M2C_UNK *), 0x28)(&temp_r5_5362->unk110.unk478, &temp_r5_5362->unk110.unk5F0) != 0) {
            this->unkC->unk110.unk5E8 = 1;
        }
    }
    temp_r3_5374 = this->unkC;
    var_r30_5375 = 0;
    if (((u8) M2C_FIELD(temp_r3_5374, u8 *, 0x8B8) == 2) || (temp_r3_5374->unk110.unk760.unk40.Get() != NULL)) {
        var_r30_5375 = 1;
    }
    if (var_r30_5375 != 0) {
        temp_r4_5388 = this->unkC;
        temp_r3_5389 = temp_r4_5388->unk110.unk928;
        if (((void *) temp_r3_5389->unk290 != NULL) && ((void *) temp_r3_5389->unk294 != NULL)) {
            temp_r5_5396 = temp_r4_5388->unk8;
            sp58 = M2C_FIELD(temp_r5_5396, f64 *, 0x30);
            sp60 = M2C_FIELD(temp_r5_5396, f64 *, 0x38);
            temp_r4_5388->unk110.unk760.Update(*((MKVector3 *) &sp58));
            sp48.GetDir();
            temp_r3_5408 = this->unkC;
            if (((temp_r3_5408->unkC8 * sp50) + ((temp_r3_5408->unkC0 * sp48) + (temp_r3_5408->unkC4 * sp4C))) < 0.95f) {
                this->unk18 |= 0x80;
                temp_r6_5431 = this->unkC->unk8;
                sp8 = -M2C_FIELD(temp_r6_5431, f32 *, 0x20);
                spC = -M2C_FIELD(temp_r6_5431, f32 *, 0x24);
                sp10 = -M2C_FIELD(temp_r6_5431, f32 *, 0x28);
                sp38 = (f64) sp8;
                sp40 = (f64) sp10;
                sp18 = (up.unk4 * (f32) sp40) - (up.unk8 * unksp3C);
                sp1C = (up.unk8 * (f32) sp38) - (up.unk0 * (f32) sp40);
                sp20 = (up.unk0 * unksp3C) - (up.unk4 * (f32) sp38);
                sp68 = (f64) sp18;
                sp70 = (f64) sp20;
                sp28.GetDir();
                if ((((f32) sp70 * sp30) + (((f32) sp68 * sp28) + (unksp6C * sp2C))) > 0.0f) {
                    this->unkC->SetAnim((AnimSequenceType) 4, 0x15, 0, 0.15f, 0U, 0U);
                    return;
                }
                this->unkC->SetAnim((AnimSequenceType) 4, 0x14, 0, 0.15f, 0U, 0U);
                return;
            }
        }
    }
    this->unkC->SetAnim((AnimSequenceType) 1, this->unk14, 0, 0.15f, 0U, 0U);
}
#endif

void EnemyGoal_AttackIdle::Reset() {
    this->unk8 = 1;
    this->unk10 = 0;
    this->unk14 = 0xA;
    this->unk18 &= ~0x80;
}

void EnemyGoal_Sleep::Terminate() {
    this->unkC->StopMovement(1U);
    this->unk8 = 1;
}

u8 EnemyGoal_Sleep::Update() {
    ActivateIfInactive();
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier 'SetIdleMovementSpeed'
void EnemyGoal_Sleep::Activate() {
    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    this->unkC->SetIdleMovementSpeed(0U);
    this->unkC->SetAnim((AnimSequenceType) 1, 0xA6, 0, 0.15f, 0U, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9DC'
void EnemyGoal_Idle::Terminate() {
    this->unkC->StopMovement(1U);
    this->unkC->unk110.unk9DC = 0;
    this->unkC->unk110.unk5E8 = 0;
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: expression syntax error
u8 EnemyGoal_Idle::Update() {
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp8;
    AITargetData *temp_r3_5628;
    AITargetData *temp_r3_5686;
    Character *temp_r29_5723;
    Character *temp_r3_5703;
    Character *temp_r3_5741;
    Character *temp_r4_5656;
    Character *temp_r4_5777;
    Character *temp_r5_5674;
    MKAnimScript *temp_r5_5755;
    s32 temp_r4_5785;
    u32 *temp_r4_5729;
    u32 *temp_r4_5744;
    u8 temp_r3_5683;
    u8 var_r30_5632;
    u8 var_r30_5687;
    u8 var_r30_5724;
    u8 var_r3_5760;
    u8 var_r4_5754;
    void *temp_r3_5646;

    temp_r3_5628 = this->unk10;
    if (temp_r3_5628 != NULL) {
        var_r30_5632 = 0;
        if (((u8) M2C_FIELD(temp_r3_5628, u8 *, 0x48) == 2) || (temp_r3_5628->unk40.Get() != NULL)) {
            var_r30_5632 = 1;
        }
        if (var_r30_5632 != 0) {
            temp_r3_5646 = this->unkC->unk8;
            sp28 = M2C_FIELD(temp_r3_5646, f64 *, 0x30);
            sp30 = M2C_FIELD(temp_r3_5646, f64 *, 0x38);
            this->unk10->Update(*((MKVector3 *) &sp28));
            sp18.GetDir();
            temp_r4_5656 = this->unkC;
            M2C_FIELD(temp_r4_5656, f64 *, 0xE0) = sp18;
            M2C_FIELD(temp_r4_5656, f64 *, 0xE8) = sp20;
            temp_r4_5656->unk110.unk5A5 |= 0x40;
            if (this->unk10->unk40.Get() != NULL) {
                temp_r5_5674 = this->unkC;
                M2C_FIELD(this->unk10->unk40.Get()->__vptr, M2C_UNK (**)(M2C_UNK *, M2C_UNK *), 0x28)(&temp_r5_5674->unk110.unk478, &temp_r5_5674->unk110.unk5F0);
            }
        }
    }
    ActivateIfInactive();
    temp_r3_5683 = this->unk20;
    if ((temp_r3_5683 >> 5U) & 1) {
        temp_r3_5686 = this->unk10;
        var_r30_5687 = 0;
        if (((u8) M2C_FIELD(temp_r3_5686, u8 *, 0x48) == 2) || (temp_r3_5686->unk40.Get() != NULL)) {
            var_r30_5687 = 1;
        }
        if ((var_r30_5687 == 0) || (sp8.GetDir(), temp_r3_5703 = this->unkC, ((((temp_r3_5703->unkC8 * sp10) + ((temp_r3_5703->unkC0 * sp8) + (temp_r3_5703->unkC4 * spC))) > 0.95f) != 0))) {
            this->unk8 = 2;
        }
    } else if ((temp_r3_5683 >> 7U) & 1) {
        temp_r29_5723 = this->unkC;
        var_r30_5724 = 0;
        if (temp_r29_5723->HasAnimFinished() != 0) {
            temp_r4_5729 = temp_r29_5723->unk110.unk940;
            if ((temp_r4_5729 != NULL) && ((u32) *temp_r4_5729 == (u32) temp_r29_5723->unk110.unk520->unk20)) {
                var_r30_5724 = 1;
            }
        }
        if (var_r30_5724 != 0) {
            temp_r3_5741 = this->unkC;
            temp_r4_5744 = temp_r3_5741->unk110.unk940;
            temp_r3_5741->SetAnim((AnimSequence *) temp_r4_5744, (AnimTransition *) (temp_r4_5744 + 0x20), 0.15f, 0U);
        } else {
            goto block_21;
        }
    } else {
block_21:
        if (this->unkC->HasAnimFinished() == 0) {
            var_r4_5754 = 0;
            temp_r5_5755 = this->unkC->unk110.unk520;
            if (((u32) temp_r5_5755->unk2C >> 1U) & 1) {
                var_r3_5760 = 0;
                if ((temp_r5_5755->unk38 > 0.0f) || ((s32) temp_r5_5755->unk44 > 1)) {
                    var_r3_5760 = 1;
                }
                if (var_r3_5760 != 0) {
                    var_r4_5754 = 1;
                }
            }
            if (var_r4_5754 != 0) {
                goto block_29;
            }
        } else {
block_29:
            temp_r4_5777 = this->unkC;
            temp_r4_5777->unk110.unk9DC += 1;
            temp_r4_5785 = this->unk14;
            if ((temp_r4_5785 != 0) && ((s32) this->unkC->unk110.unk9DC >= temp_r4_5785)) {
                this->unk8 = 2;
            } else {
                this->unkC->SetAnim((AnimSequenceType) 1, this->unk18, (((u8) this->unk20 >> 7U) & 1) != 0, 0.15f, 4U, 0U);
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9DC'
void EnemyGoal_Idle::Activate() {
    f64 sp60;
    f64 sp58;
    f32 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    AITargetData *temp_r3_5842;
    AITargetData *temp_r3_5873;
    Character *temp_r3_5900;
    Character *temp_r5_5853;
    EnemyDescriptor *temp_r3_5890;
    s32 var_r4_5997;
    u32 *temp_r3_5998;
    u8 var_r30_5877;
    void *temp_r5_5923;

    this->unk8 = 0;
    this->unkC->unk110.unk9DC = 0;
    this->unkC->StopMovement(1U);
    if ((AITargetData *) this->unk10 == NULL) {
        this->unkC->SetIdleMovementSpeed(0U);
    } else {
        this->unkC->SetIdleMovementSpeed(1U);
    }
    this->unkC->SetMovementType((CharacterMoveType) this->unk1C);
    temp_r3_5842 = this->unk10;
    if ((temp_r3_5842 != NULL) && (temp_r3_5842->unk40.Get() != NULL) && (temp_r5_5853 = this->unkC, ((M2C_FIELD(this->unk10->unk40.Get()->__vptr, u8 (**)(M2C_UNK *, M2C_UNK *), 0x28)(&temp_r5_5853->unk110.unk478, &temp_r5_5853->unk110.unk5F0) == 0) == 0))) {
        this->unkC->unk110.unk5E8 = 1;
    } else {
        this->unkC->unk110.unk5E8 = 0;
    }
    if (((u8) this->unk20 >> 6U) & 1) {
        temp_r3_5873 = this->unk10;
        if (temp_r3_5873 != NULL) {
            var_r30_5877 = 0;
            if (((u8) M2C_FIELD(temp_r3_5873, u8 *, 0x48) == 2) || (temp_r3_5873->unk40.Get() != NULL)) {
                var_r30_5877 = 1;
            }
            if (var_r30_5877 != 0) {
                temp_r3_5890 = this->unkC->unk110.unk928;
                if (((void *) temp_r3_5890->unk290 != NULL) && ((void *) temp_r3_5890->unk294 != NULL)) {
                    sp48.GetDir();
                    temp_r3_5900 = this->unkC;
                    if (((temp_r3_5900->unkC8 * sp50) + ((temp_r3_5900->unkC0 * sp48) + (temp_r3_5900->unkC4 * sp4C))) < 0.95f) {
                        this->unk20 |= 0x20;
                        temp_r5_5923 = this->unkC->unk8;
                        sp8 = -M2C_FIELD(temp_r5_5923, f32 *, 0x20);
                        spC = -M2C_FIELD(temp_r5_5923, f32 *, 0x24);
                        sp10 = -M2C_FIELD(temp_r5_5923, f32 *, 0x28);
                        sp38 = (f64) sp8;
                        sp40 = (f64) sp10;
                        sp18 = (up.unk4 * (f32) sp40) - (up.unk8 * unksp3C);
                        sp1C = (up.unk8 * (f32) sp38) - (up.unk0 * (f32) sp40);
                        sp20 = (up.unk0 * unksp3C) - (up.unk4 * (f32) sp38);
                        sp58 = (f64) sp18;
                        sp60 = (f64) sp20;
                        sp28.GetDir();
                        if ((((f32) sp60 * sp30) + (((f32) sp58 * sp28) + (unksp5C * sp2C))) > 0.0f) {
                            this->unkC->SetAnim((AnimSequenceType) 4, 0x15, 0, 0.15f, 0U, 0U);
                            return;
                        }
                        this->unkC->SetAnim((AnimSequenceType) 4, 0x14, 0, 0.15f, 0U, 0U);
                        return;
                    }
                }
            }
            goto block_20;
        }
    }
block_20:
    this->unkC->SetAnim((AnimSequenceType) 1, this->unk18, 0, 0.15f, 0U, 0U);
    var_r4_5997 = 0;
    temp_r3_5998 = this->unkC->unk110.unk940;
    if ((temp_r3_5998 != NULL) && ((u32) M2C_FIELD(temp_r3_5998, u32 *, 0x20) != 0U)) {
        var_r4_5997 = 1;
    }
    this->unk20 = (this->unk20 & ~0x80) | ((var_r4_5997 << 7) & 0x80);
}
#endif

void EnemyGoal_Idle::Reset() {
    this->unk8 = 1;
    this->unk10 = NULL;
    this->unk14 = 0;
    this->unk18 = 1;
    this->unk20 &= ~0x80;
    this->unk20 &= ~0x40;
    this->unk20 &= ~0x20;
    this->unk1C = 0;
}

void EnemyGoals_cpp::__sinit() {
    f32 temp_f0_6150;
    f64 temp_f1_6131;
    f64 temp_f1_6139;
    f64 temp_f3_6119;
    f64 temp_f4_6128;
    f64 temp_f4_6136;
    f64 temp_f8_6121;

    temp_f3_6119 = __frsqrte(2014000.0);
    temp_f8_6121 = __frsqrte(380000.0);
    temp_f4_6128 = 0.5 * temp_f3_6119 * -((2014000.0 * (temp_f3_6119 * temp_f3_6119)) - 3.0);
    temp_f1_6131 = 0.5 * temp_f8_6121 * -((380000.0 * (temp_f8_6121 * temp_f8_6121)) - 3.0);
    temp_f4_6136 = 0.5 * temp_f4_6128 * -((2014000.0 * (temp_f4_6128 * temp_f4_6128)) - 3.0);
    temp_f1_6139 = 0.5 * temp_f1_6131 * -((380000.0 * (temp_f1_6131 * temp_f1_6131)) - 3.0);
    temp_f0_6150 = (f32) (380000.0 * (0.5 * temp_f1_6139 * -((380000.0 * (temp_f1_6139 * temp_f1_6139)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_6136 * -((2014000.0 * (temp_f4_6136 * temp_f4_6136)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_6150;
}
