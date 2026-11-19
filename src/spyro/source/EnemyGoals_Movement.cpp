#include "spyro/source/EnemyGoals_Movement.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Character.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/SB2.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

void EnemyGoal_Jump::Terminate() {
    Character *temp_r4_25;
    Character *temp_r4_32;
    Character *temp_r4_40;
    Character *temp_r4_44;
    Character *temp_r7_36;

    temp_r4_25 = this->unkC;
    temp_r4_25->unkA0 = 0.0f;
    temp_r4_25->unkA4 = 0.0f;
    temp_r4_25->unkA8 = 0.0f;
    temp_r4_32 = this->unkC;
    temp_r4_32->unk588.unkC = 0.0f;
    temp_r4_32->unk598 = 0.0f;
    temp_r4_32->unk59C = 0.0f;
    temp_r7_36 = this->unkC;
    temp_r7_36->unk5E4 = M2C_FIELD(temp_r7_36->unk5D8, f32 *, 8);
    temp_r4_40 = this->unkC;
    temp_r4_40->unk6B5 &= ~2;
    temp_r4_44 = this->unkC;
    temp_r4_44->unk6B5 |= 0x20;
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unk8C0'
u8 EnemyGoal_Jump::Update() {
    M2C_UNK sp98;
    f64 sp90;
    f64 sp88;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    MKVector3 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    AnimSequence *temp_r4_145;
    AnimSequence *temp_r4_156;
    AnimSequence *temp_r4_285;
    AnimSequence *temp_r4_75;
    Character *temp_r29_150;
    Character *temp_r29_69;
    Character *temp_r3_111;
    Character *temp_r3_117;
    Character *temp_r3_144;
    Character *temp_r3_196;
    Character *temp_r3_268;
    Character *temp_r3_276;
    Character *temp_r3_280;
    Character *temp_r3_284;
    Character *temp_r4_65;
    Character *temp_r5_91;
    Character *temp_r6_172;
    Character *temp_r7_210;
    Character *temp_r7_272;
    f32 temp_f30_102;
    f32 temp_f31_100;
    f32 temp_f31_181;
    f64 temp_f0_121;
    f64 temp_f0_191;
    u8 temp_r4_214;
    u8 var_r30_151;
    u8 var_r30_70;
    void **var_r0_220;
    void **var_r0_234;
    void **var_r3_248;
    void *temp_r3_217;
    void *temp_r3_231;
    void *temp_r3_245;

    ActivateIfInactive();
    temp_r4_65 = this->unkC;
    temp_r4_65->unk8C0.Update(*((MKVector3 *) &temp_r4_65->unk588));
    temp_r29_69 = this->unkC;
    var_r30_70 = 0;
    if (temp_r29_69->HasAnimFinished() != 0) {
        temp_r4_75 = temp_r29_69->unkA50;
        if ((temp_r4_75 != NULL) && ((u32) temp_r4_75->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_69, void **, 0x630), u32 *, 0x20))) {
            var_r30_70 = 1;
        }
    }
    if (var_r30_70 != 0) {
        ((AITargetData *) &sp98)->GetPos();
        temp_r5_91 = this->unkC;
        temp_f31_100 = this->unk14;
        temp_f30_102 = ((sp9C - temp_r5_91->unk588.unk0) + this->unk18) - M2C_FIELD(temp_r5_91->unk5D8, f32 *, 8);
        ((AITargetData *) &sp78)->GetDir();
        sp28 = sp78 * (f64) temp_f31_100;
        temp_r3_111 = this->unkC;
        sp88 = sp28;
        sp30 = sp80 * temp_f31_100;
        M2C_FIELD(temp_r3_111, f64 *, 0x598) = sp28;
        M2C_FIELD(temp_r3_111, f64 *, 0x5A0) = (f64) sp30;
        temp_r3_117 = this->unkC;
        sp90 = (f64) sp30;
        temp_f0_121 = M2C_FIELD(temp_r3_117, f64 *, 0xD0) * (f64) temp_f30_102;
        sp18 = temp_f0_121;
        sp68 = temp_f0_121;
        sp20 = temp_r3_117->unkD8 * temp_f30_102;
        sp70 = (f64) sp20;
        M2C_FIELD(temp_r3_117, f64 *, 0x598) = (f64) (M2C_FIELD(temp_r3_117, f64 *, 0x598) + temp_f0_121);
        temp_r3_117->unk59C += (f32) sp70;
        this->unkC->unk110.unk16C = 0;
        temp_r3_144 = this->unkC;
        temp_r4_145 = temp_r3_144->unkA50;
        ((Enemy *) temp_r3_144)->SetAnim(temp_r4_145, (AnimTransition *) &temp_r4_145->unk20, 0.15f, 0U);
    } else {
        temp_r29_150 = this->unkC;
        var_r30_151 = 0;
        if (temp_r29_150->HasAnimFinished() != 0) {
            temp_r4_156 = temp_r29_150->unkA50;
            if ((temp_r4_156 != NULL) && ((u32) temp_r4_156->unk40 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_150, void **, 0x630), u32 *, 0x20))) {
                var_r30_151 = 1;
            }
        }
        if (var_r30_151 != 0) {
            this->unk8 = 2;
        } else {
            temp_r6_172 = this->unkC;
            if ((u32) M2C_FIELD(M2C_FIELD(temp_r6_172, void **, 0x630), u32 *, 0x20) == (u32) temp_r6_172->unkA50->unk20) {
                temp_f31_181 = this->unk1C;
                sp38.operator*(M2C_FIELD(temp_r6_172->unk5D8, f32 *, 8));
                sp48.operator*(gUpdateTimeDelta);
                temp_f0_191 = sp48 * (f64) temp_f31_181;
                sp8 = temp_f0_191;
                temp_r3_196 = this->unkC;
                sp58 = temp_f0_191;
                sp10 = sp48.unk8 * temp_f31_181;
                sp60 = (f64) sp10;
                M2C_FIELD(temp_r3_196, f64 *, 0xA0) = (f64) (M2C_FIELD(temp_r3_196, f64 *, 0xA0) + temp_f0_191);
                temp_r3_196->unkA8 += (f32) sp60;
                temp_r7_210 = this->unkC;
                if ((s32) temp_r7_210->unk110.unk16C > 0) {
                    temp_r4_214 = temp_r7_210->unk110.unk58;
                    if ((temp_r4_214 != 0) && (temp_r3_217 = temp_r7_210->unk110.unk50, ((temp_r3_217 == NULL) == 0)) && (var_r0_220 = M2C_FIELD(temp_r3_217, void ***, 8), ((var_r0_220 == NULL) == 0))) {

                    } else {
                        var_r0_220 = NULL;
                    }
                    if (var_r0_220 != NULL) {
                        if ((temp_r4_214 != 0) && (temp_r3_231 = temp_r7_210->unk110.unk50, ((temp_r3_231 == NULL) == 0)) && (var_r0_234 = M2C_FIELD(temp_r3_231, void ***, 8), ((var_r0_234 == NULL) == 0))) {

                        } else {
                            var_r0_234 = NULL;
                        }
                        if (var_r0_234 != NULL) {
                            if ((temp_r4_214 != 0) && (temp_r3_245 = temp_r7_210->unk110.unk50, ((temp_r3_245 == NULL) == 0)) && (var_r3_248 = M2C_FIELD(temp_r3_245, void ***, 8), ((var_r3_248 == NULL) == 0))) {

                            } else {
                                var_r3_248 = NULL;
                            }
                            if (!(M2C_FIELD(*var_r3_248, s32 *, 0xC) & 0x4C)) {
                                goto block_32;
                            }
                        }
                    } else {
block_32:
                        temp_r7_210->unkA0 = 0.0f;
                        temp_r7_210->unkA4 = 0.0f;
                        temp_r7_210->unkA8 = 0.0f;
                        temp_r3_268 = this->unkC;
                        temp_r3_268->unk588.unkC = 0.0f;
                        temp_r3_268->unk598 = 0.0f;
                        temp_r3_268->unk59C = 0.0f;
                        temp_r7_272 = this->unkC;
                        temp_r7_272->unk5E4 = M2C_FIELD(temp_r7_272->unk5D8, f32 *, 8);
                        temp_r3_276 = this->unkC;
                        temp_r3_276->unk6B5 &= ~2;
                        temp_r3_280 = this->unkC;
                        temp_r3_280->unk6B5 |= 0x20;
                        temp_r3_284 = this->unkC;
                        temp_r4_285 = temp_r3_284->unkA50;
                        ((Enemy *) temp_r3_284)->SetAnim(temp_r4_285, (AnimTransition *) &temp_r4_285->unk40, 0.15f, 0U);
                    }
                }
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8C0'
void EnemyGoal_Jump::Activate() {
    f64 sp8;
    Character *temp_r3_328;
    Character *temp_r3_336;
    Character *temp_r4_346;
    Character *temp_r4_354;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetWalkMovementSpeed(1U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 9, 0, 0, 0.15f, 0U, 0U);
    temp_r3_328 = this->unkC;
    temp_r3_328->unk6B5 &= ~0x20;
    temp_r3_336 = this->unkC;
    temp_r3_336->unk6B5 |= 2;
    this->unkC->unk5E4 = 0.0f;
    this->unkC->unk8C0.Set(*this->unk10, 0U);
    temp_r4_346 = this->unkC;
    temp_r4_346->unk8C0.Update(*((MKVector3 *) &temp_r4_346->unk588));
    ((AITargetData *) &sp8)->GetDir();
    temp_r4_354 = this->unkC;
    M2C_FIELD(temp_r4_354, f64 *, 0xE0) = sp8;
    M2C_FIELD(temp_r4_354, f64 *, 0xE8) = sp10;
    temp_r4_354->unk6B5 |= 0x40;
}
#endif

void EnemyGoal_Panic::Terminate() {
    MKProp *temp_r3_389;
    MKProp *temp_r4_385;
    void *temp_r3_381;

    temp_r3_381 = M2C_FIELD(this->unkC, void **, 0x640);
    M2C_FIELD(temp_r3_381, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_381, u8 *, 0x464) & ~0x80);
    temp_r4_385 = this->unkC;
    M2C_FIELD(temp_r4_385, f32 *, 0x698) = (f32) M2C_FIELD(M2C_FIELD(temp_r4_385, void **, 0xA38), f32 *, 0x168);
    temp_r3_389 = this->unkC;
    M2C_FIELD(temp_r3_389, f32 *, 0x598) = 0.0f;
    M2C_FIELD(temp_r3_389, f32 *, 0x59C) = 0.0f;
    M2C_FIELD(temp_r3_389, f32 *, 0x5A0) = 0.0f;
    ((SB2 *) (M2C_FIELD(this->unkC, SB2 **, 0x640)))->WanderOff();
    ((SB2 *) (M2C_FIELD(this->unkC, SB2 **, 0x640)))->ObstacleAvoidanceOff();
    ((SB2 *) (M2C_FIELD(this->unkC, SB2 **, 0x640)))->WallAvoidanceOff();
    ((SB2 *) (M2C_FIELD(this->unkC, SB2 **, 0x640)))->ContainmentOff();
    this->unk8 = 1;
}

#if 0 // DRAFT: illegal type
u8 EnemyGoal_Panic::Update() {
    BreathHitMessage sp10;
    s32 sp8;
    void *temp_r3_435;

    ActivateIfInactive();
    if (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk24) {
        this->unk8 = 2;
    } else {
        temp_r3_435 = M2C_FIELD(this->unkC, void **, 0xA08);
        if ((temp_r3_435 != NULL) && ((s32) M2C_FIELD(temp_r3_435, s32 *, 0x20) == 1)) {
            sp10.unk4 = 0;
            sp8 = -1;
            sp10.Init(this->unkC, 1, 0, 1, 0, 0, 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, void *, M2C_UNK, f32), 0x94)(gMK, &sp10, 8, 1, this->unkC->unk8 + 0x30, 1, 200.0f);
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal type
void EnemyGoal_Panic::Activate() {
    MKProp *temp_r4_532;
    MKProp *temp_r5_490;
    SB2 *temp_r3_515;
    s32 temp_r3_534;

    this->unk8 = 0;
    temp_r5_490 = this->unkC;
    M2C_FIELD(temp_r5_490, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r5_490, u8 *, 0xB09) & ~2);
    this->unk24 = M2C_FIELD(&gb, f32 *, 0x30C) + 3.0f;
    ((Enemy *) this->unkC)->SetRunMovementSpeed(1U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 6, 0x11, 0, 0.15f, 0U, 0U);
    ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 0);
    M2C_FIELD(this->unkC, f32 *, 0x698) = 0.1f;
    temp_r3_515 = M2C_FIELD(this->unkC, SB2 **, 0x640);
    temp_r3_515->unk464 |= 0x80;
    ((SB2 *) (M2C_FIELD(this->unkC, SB2 **, 0x640)))->WanderOn();
    ((SB2 *) (M2C_FIELD(this->unkC, SB2 **, 0x640)))->ObstacleAvoidanceOn(NULL);
    ((SB2 *) (M2C_FIELD(this->unkC, SB2 **, 0x640)))->WallAvoidanceOn();
    ((SB2 *) (M2C_FIELD(this->unkC, SB2 **, 0x640)))->ContainmentOn();
    temp_r4_532 = this->unkC;
    temp_r3_534 = M2C_FIELD(M2C_FIELD(temp_r4_532, void **, 0xA38), s32 *, 0x1C8);
    if ((temp_r3_534 != 0) && ((s32) M2C_FIELD(temp_r4_532, s32 *, 0x7C8) == 4)) {
        KDSound_Play3d(temp_r3_534, temp_r4_532->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void EnemyGoal_MoveAwayFromHero::Terminate() {
    this->unkC->unkA54 = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
    this->unk8 = 1;
    RemoveAllSubgoals();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EnemyGoal_MoveAwayFromHero::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void EnemyGoal_MoveAwayFromHero::Activate() {
    Enemy *temp_r3_608;
    Enemy *temp_r3_618;
    Enemy *temp_r3_635;
    Goal<Enemy> *temp_r3_649;
    Goal<Enemy> *temp_r4_625;
    Goal<Enemy> *temp_r4_642;
    f32 temp_f0_626;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_608 = this->unkC;
    if (temp_r3_608->CanMoveAwayBack() != 0) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
        temp_r3_618 = this->unkC;
        temp_r4_625 = this->unk24;
        temp_f0_626 = 200.0f + temp_r3_618->GetCollisionRadius();
        M2C_FIELD(temp_r4_625, f32 **, 0x10) = &this->unkC->unk838.unk28;
        M2C_FIELD(temp_r4_625, f32 *, 0x14) = temp_f0_626;
        return;
    }
    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk20);
    temp_r3_635 = this->unkC;
    if (temp_r3_635->CanMoveAwayLeft() != 0) {
        temp_r4_642 = this->unk20;
        M2C_FIELD(temp_r4_642, s8 *, 0x14) = 1;
        M2C_FIELD(temp_r4_642, s32 *, 0x10) = 0;
        return;
    }
    temp_r3_649 = this->unk20;
    M2C_FIELD(temp_r3_649, s8 *, 0x14) = 0;
    M2C_FIELD(temp_r3_649, s32 *, 0x10) = 0;
}
#endif

void EnemyGoal_MoveAwayFromHero::Deinit() {
    Goal<Enemy> *temp_r3_669;
    Goal<Enemy> *temp_r3_674;
    MKHeap *temp_r3_686;
    void *temp_r31_683;

    temp_r3_669 = this->unk20;
    temp_r3_669->Deinit();
    temp_r3_674 = this->unk24;
    temp_r3_674->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk24);
    temp_r31_683 = this->unk1C;
    if (temp_r31_683 != NULL) {
        temp_r3_686 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_686 != NULL) {
            ((MKHeap *) (temp_r3_686->Current()))->Free(temp_r31_683, NULL, 0);
        } else {
            free(temp_r31_683);
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
void EnemyGoal_MoveAwayFromHero::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_800;
    Goal<Enemy> *temp_r4_811;
    MKHeap *temp_r3_773;
    void *var_r3_780;

    if ((u8) this->unk9 == 0) {
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_773 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_773 != NULL) {
            var_r3_780 = ((MKHeap *) (temp_r3_773->Current()))->Alloc(4, NULL, 0);
        } else {
            var_r3_780 = malloc(4);
        }
        this->unk1C = var_r3_780;
        this->unk10 = 1;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x28;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_800 = this->unk20;
    M2C_FIELD(temp_r4_800, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_800, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_800, s32 *, 4) = 0x20;
    if ((Enemy *) M2C_FIELD(temp_r4_800, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_800, s8 *, 9) = 1;
    }
    temp_r4_811 = this->unk24;
    M2C_FIELD(temp_r4_811, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_811, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_811, s32 *, 4) = 0x1F;
    if ((Enemy *) M2C_FIELD(temp_r4_811, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_811, s8 *, 9) = 1;
    }
}
#endif

void EnemyGoal_PatrolMode::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EnemyGoal_PatrolMode::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        Activate();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void EnemyGoal_PatrolMode::Activate() {
    Enemy *temp_r3_884;
    Enemy *temp_r3_905;
    Goal<Enemy> *temp_r5_955;
    Goal<Enemy> *temp_r5_973;
    Goal<Enemy> *temp_r6_924;
    f32 temp_f1_921;
    s32 temp_r3_972;
    u32 temp_r30_971;
    void *temp_r3_890;
    void *temp_r3_900;
    void *temp_r4_906;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_884 = this->unkC;
    M2C_FIELD(temp_r3_884, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_884, u8 *, 0xB08) & ~0x40);
    temp_r3_890 = this->unkC->unkA2C;
    if ((temp_r3_890 != NULL) && (M2C_FIELD(temp_r3_890, s32 *, 4) & 0x8000)) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk20);
        temp_r3_900 = this->unkC->unkA2C;
        M2C_FIELD(temp_r3_900, s32 *, 4) = (s32) (M2C_FIELD(temp_r3_900, s32 *, 4) & 0xFFFF7FFF);
    }
    temp_r3_905 = this->unkC;
    temp_r4_906 = temp_r3_905->unkA2C;
    if ((temp_r4_906 != NULL) && (M2C_FIELD(temp_r4_906, s32 *, 4) & 2)) {
        if (temp_r3_905->HasWaypoints() != 0) {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
            temp_f1_921 = MKRand_Float(&gViewSeed, 5.0f, 10.0f);
            temp_r6_924 = this->unk28;
            M2C_FIELD(temp_r6_924, s32 *, 0x10) = (s32) M2C_FIELD(this->unkC->unkA2C, s32 *, 0x18);
            M2C_FIELD(temp_r6_924, f32 *, 0x14) = temp_f1_921;
            M2C_FIELD(temp_r6_924, s32 *, 0x18) = 1;
            M2C_FIELD(temp_r6_924, s32 *, 0x20) = 5;
            M2C_FIELD(temp_r6_924, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r6_924, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_924, u8 *, 0x24) & ~0x20);
            M2C_FIELD(temp_r6_924, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_924, u8 *, 0x24) & ~0x10);
            M2C_FIELD(temp_r6_924, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_924, u8 *, 0x24) & ~8);
            M2C_FIELD(temp_r6_924, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_924, u8 *, 0x24) | 4);
        } else {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
            temp_r5_955 = this->unk2C;
            M2C_FIELD(temp_r5_955, f32 *, 0x10) = MKRand_Float(&gViewSeed, 5.0f, 10.0f);
            M2C_FIELD(temp_r5_955, s32 *, 0x14) = 1;
            M2C_FIELD(temp_r5_955, s32 *, 0x1C) = 5;
            M2C_FIELD(temp_r5_955, s32 *, 0x18) = 0;
        }
    }
    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
    temp_r30_971 = this->unkC->unk680;
    temp_r3_972 = MKRand_Int(&gViewSeed, 1, 3);
    temp_r5_973 = this->unk24;
    M2C_FIELD(temp_r5_973, s32 *, 0x10) = 0;
    M2C_FIELD(temp_r5_973, s32 *, 0x14) = temp_r3_972;
    M2C_FIELD(temp_r5_973, s32 *, 0x18) = 1;
    M2C_FIELD(temp_r5_973, u32 *, 0x1C) = temp_r30_971;
    M2C_FIELD(temp_r5_973, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r5_973, u8 *, 0x20) & ~0x40);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_PatrolMode::Deinit() {
    Goal<Enemy> *temp_r3_1003;
    Goal<Enemy> *temp_r3_1008;
    Goal<Enemy> *temp_r3_1019;
    Goal<Enemy> *temp_r3_998;
    MKHeap *temp_r3_1032;
    void *temp_r31_1029;

    temp_r3_998 = this->unk24;
    temp_r3_998->Deinit();
    temp_r3_1003 = this->unk28;
    temp_r3_1003->Deinit();
    temp_r3_1008 = this->unk2C;
    temp_r3_1008->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    temp_r3_1019 = this->unk20;
    if (temp_r3_1019 != NULL) {
        M2C_FIELD(temp_r3_1019->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk20);
    }
    temp_r31_1029 = this->unk1C;
    if (temp_r31_1029 != NULL) {
        temp_r3_1032 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1032 != NULL) {
            ((MKHeap *) (temp_r3_1032->Current()))->Free(temp_r31_1029, NULL, 0);
        } else {
            free(temp_r31_1029);
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
void EnemyGoal_PatrolMode::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_1196;
    Goal<Enemy> *temp_r4_1207;
    Goal<Enemy> *temp_r4_1218;
    Goal<Enemy> *temp_r4_1229;
    MKHeap *temp_r3_1169;
    void *var_r3_1176;

    if ((u8) this->unk9 == 0) {
        this->unk20 = NULL;
        if (arg0->CanSleepOnGround() != 0) {
            operator new(0x10U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        operator new(0x24U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x20U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_1169 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1169 != NULL) {
            var_r3_1176 = ((MKHeap *) (temp_r3_1169->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_1176 = malloc(8);
        }
        this->unk1C = var_r3_1176;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x53;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_1196 = this->unk24;
    M2C_FIELD(temp_r4_1196, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1196, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1196, s32 *, 4) = 0;
    if ((Enemy *) M2C_FIELD(temp_r4_1196, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1196, s8 *, 9) = 1;
    }
    temp_r4_1207 = this->unk28;
    M2C_FIELD(temp_r4_1207, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1207, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1207, s32 *, 4) = 0x22;
    if ((Enemy *) M2C_FIELD(temp_r4_1207, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1207, s8 *, 9) = 1;
    }
    temp_r4_1218 = this->unk2C;
    M2C_FIELD(temp_r4_1218, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1218, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1218, s32 *, 4) = 0x23;
    if ((Enemy *) M2C_FIELD(temp_r4_1218, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1218, s8 *, 9) = 1;
    }
    temp_r4_1229 = this->unk20;
    if (temp_r4_1229 != NULL) {
        M2C_FIELD(temp_r4_1229, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_1229, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_1229, s32 *, 4) = 7;
        if ((Enemy *) M2C_FIELD(temp_r4_1229, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_1229, s8 *, 9) = 1;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA38'
void EnemyGoal_MoveToTarget::Terminate() {
    Character *temp_r3_1264;
    Character *temp_r4_1308;
    Character *temp_r5_1260;
    void *temp_r3_1269;
    void *temp_r3_1296;

    this->unk10 = NULL;
    temp_r5_1260 = this->unkC;
    temp_r5_1260->unk690 = temp_r5_1260->unkA38->unk168;
    temp_r3_1264 = this->unkC;
    temp_r3_1264->unk588.unkC = 0.0f;
    temp_r3_1264->unk598 = 0.0f;
    temp_r3_1264->unk59C = 0.0f;
    temp_r3_1269 = this->unkC->unk638;
    M2C_FIELD(temp_r3_1269, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1269, u8 *, 0x464) & ~0x80);
    ((SB2 *) this->unkC->unk638)->SeekOff();
    ((SB2 *) this->unkC->unk638)->ArriveOff();
    ((SB2 *) this->unkC->unk638)->PursuitOff();
    ((SB2 *) this->unkC->unk638)->RandomPursuitOff();
    ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    ((SB2 *) this->unkC->unk638)->WallAvoidanceOff();
    ((SB2 *) this->unkC->unk638)->HazardAvoidanceOff();
    temp_r3_1296 = this->unkC->unk638;
    M2C_FIELD(temp_r3_1296, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1296, u8 *, 0x464) & ~0x40);
    ((SB2 *) this->unkC->unk638)->ContainmentOff();
    if (((u8) this->unk30 >> 4U) & 1) {
        temp_r4_1308 = this->unkC;
        temp_r4_1308->unk720 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        temp_r4_1308->unk728 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    }
    this->unkC->unk6F8 = 0;
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA38'
u8 EnemyGoal_MoveToTarget::Update() {
    AITargetData sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    u8 sp14;
    void *sp10;
    u8 spC;
    void *sp8;
    AITargetData *temp_r3_1337;
    AITargetData *temp_r3_1351;
    AITargetData *temp_r4_1496;
    Character *temp_r3_1386;
    Character *temp_r3_1400;
    Character *temp_r3_1422;
    Character *temp_r3_1465;
    Character *temp_r5_1580;
    f32 temp_f30_1427;
    f32 temp_f31_1473;
    f64 temp_f0_1444;
    s32 temp_r4_1412;
    u8 temp_r3_1368;
    u8 var_r30_1355;
    u8 var_r30_1401;
    u8 var_r3_1413;
    void *temp_r5_1342;
    void *temp_r5_1515;
    void *var_r3_1489;

    temp_r3_1337 = this->unk10;
    if (temp_r3_1337 != NULL) {
        temp_r5_1342 = this->unkC->unk8;
        sp48.unk10 = M2C_FIELD(temp_r5_1342, f64 *, 0x30);
        sp48.unk18 = M2C_FIELD(temp_r5_1342, f64 *, 0x38);
        temp_r3_1337->Update(*((MKVector3 *) &sp48.unk10));
    }
    UpdateStuckness();
    temp_r3_1351 = this->unk10;
    if (temp_r3_1351 != NULL) {
        var_r30_1355 = 0;
        if (((u8) M2C_FIELD(temp_r3_1351, u8 *, 0x48) == 2) || (temp_r3_1351->unk40.Get() != NULL)) {
            var_r30_1355 = 1;
        }
        if ((var_r30_1355 == 0) || (temp_r3_1368 = M2C_FIELD(this->unk10, u8 *, 0x49), ((((temp_r3_1368 >> 6U) & 1) == 0) != 0)) || ((temp_r3_1368 >> 5U) & 1)) {
            goto block_9;
        }
        temp_r3_1400 = this->unkC;
        var_r30_1401 = 0;
        if (((u8) temp_r3_1400->unkA38->unk17E == 0) || (temp_r3_1400->HasAnimFinished() != 0)) {
            var_r30_1401 = 1;
        }
        temp_r4_1412 = this->unk28;
        var_r3_1413 = var_r30_1401;
        if (temp_r4_1412 >= 0) {
            var_r3_1413 = ((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(temp_r4_1412);
        }
        if (var_r3_1413 != 0) {
            temp_r3_1422 = this->unkC;
            temp_f30_1427 = M2C_FIELD(temp_r3_1422->__vptr, f32 (**)(Character *), 0x100)(temp_r3_1422);
            sp30 = 0.0f;
            sp28 = 0.0f;
            sp2C = 50.0f + temp_f30_1427;
            sp40 = (f64) sp30;
            sp38 = (f64) sp28;
            sp48.GetPos();
            temp_f0_1444 = sp48.unk0 + sp38;
            sp18 = temp_f0_1444;
            sp48.unk20 = temp_f0_1444;
            sp20 = sp48.unk8 + (f32) sp40;
            sp48.unk28 = (f64) sp20;
            if (this->unk10->GetDist() <= this->unk18) {
                this->unk8 = 2;
                return this->unk8;
            }
            temp_r3_1465 = this->unkC;
            temp_f31_1473 = (2.0f * M2C_FIELD(temp_r3_1465->__vptr, f32 (**)(Character *), 0x100)(temp_r3_1465)) + this->unk18;
            if (this->unk10->GetDist() <= temp_f31_1473) {
                if (this->unk10->unk40.Get() != NULL) {
                    var_r3_1489 = M2C_FIELD(this->unk10->unk40.Get()->__vptr, void *(**)(), 0x34)();
                } else {
                    var_r3_1489 = NULL;
                }
                if (var_r3_1489 == NULL) {
                    temp_r4_1496 = this->unk14;
                    if (temp_r4_1496 != NULL) {
                        if (temp_r4_1496->unk40.Get() != NULL) {
                            var_r3_1489 = M2C_FIELD(this->unk14->unk40.Get()->__vptr, void *(**)(), 0x34)();
                        } else {
                            var_r3_1489 = NULL;
                        }
                    }
                }
                temp_r5_1515 = this->unkC->unk634;
                sp10 = temp_r5_1515;
                if (temp_r5_1515 != NULL) {
                    sp14 = M2C_FIELD(temp_r5_1515, u8 *, 4);
                    M2C_FIELD(temp_r5_1515, u8 *, 4) = 0U;
                }
                sp8 = var_r3_1489;
                if (var_r3_1489 != NULL) {
                    spC = M2C_FIELD(var_r3_1489, u8 *, 4);
                    M2C_FIELD(var_r3_1489, u8 *, 4) = 0U;
                }
                if (MKCollision_SphereCollide(*((MKVector3 *) &sp48.unk20), temp_f30_1427, NULL, 0, (MKCollisionMode) 7, 0x04000000) != 0) {
                    this->unk8 = 3;
                    if (sp8 != NULL) {
                        M2C_FIELD(sp8, u8 *, 4) = spC;
                    }
                    if (sp10 != NULL) {
                        M2C_FIELD(sp10, u8 *, 4) = sp14;
                        return this->unk8;
                    }
                    /* Duplicate return node #45. Try simplifying control flow for better match */
                    return this->unk8;
                }
                if (sp8 != NULL) {
                    M2C_FIELD(sp8, u8 *, 4) = spC;
                }
                if (sp10 != NULL) {
                    M2C_FIELD(sp10, u8 *, 4) = sp14;
                }
                goto block_42;
            }
            goto block_42;
        }
        goto block_42;
    }
block_9:
    ((SB2 *) this->unkC->unk638)->SeekOff();
    ((SB2 *) this->unkC->unk638)->ArriveOff();
    ((SB2 *) this->unkC->unk638)->PursuitOff();
    ((SB2 *) this->unkC->unk638)->RandomPursuitOff();
    temp_r3_1386 = this->unkC;
    if (((u8) temp_r3_1386->unkA38->unk17E == 0) || (temp_r3_1386->HasAnimFinished() != 0)) {
        this->unk8 = 3;
        return this->unk8;
    }
block_42:
    ActivateIfInactive();
    if (this->unk10->unk40.Get() != NULL) {
        temp_r5_1580 = this->unkC;
        M2C_FIELD(this->unk10->unk40.Get()->__vptr, M2C_UNK (**)(M2C_UNK *, M2C_UNK *), 0x28)(&temp_r5_1580->unk588, &temp_r5_1580->unk700);
    }
    this->unkC->unk9E8.Update();
    this->unk10->SetIsNew(0U);
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'fabs'
void EnemyGoal_MoveToTarget::UpdateStuckness() {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    Character *temp_r4_1616;
    f32 temp_f1_1643;
    f32 temp_f5_1621;
    f32 temp_f5_1634;
    f32 temp_f6_1626;
    f32 var_f0_1670;
    f64 temp_f2_1618;
    f64 temp_f8_1619;
    s32 temp_r0_1650;
    u8 var_r3_1617;

    temp_r4_1616 = this->unkC;
    var_r3_1617 = 0;
    temp_f2_1618 = temp_r4_1616->unk100;
    temp_f8_1619 = temp_r4_1616->unk108;
    sp8 = temp_f2_1618;
    temp_f5_1621 = temp_r4_1616->unkC4;
    (*(f32 *) ((u8 *) &sp8 + 0x4)) = 0.0f;
    temp_f6_1626 = temp_r4_1616->unkC0;
    sp18 = temp_f2_1618;
    sp20 = temp_f8_1619;
    temp_f5_1634 = temp_r4_1616->unkC8;
    sp10 = temp_f8_1619;
    temp_f1_1643 = (f32) fabs(((f32) sp20 * temp_f5_1634) + (((f32) sp18 * temp_f6_1626) + ((*(f32 *) ((u8 *) &sp18 + 0x4)) * temp_f5_1621)));
    if ((((temp_r4_1616->unk98 * temp_f5_1634) + ((temp_r4_1616->unk90 * temp_f6_1626) + (temp_r4_1616->unk94 * temp_f5_1621))) > 20.0f) && (temp_f1_1643 < 10.0f)) {
        var_r3_1617 = 1;
    }
    temp_r0_1650 = this->unk2C;
    switch (temp_r0_1650) {                         /* irregular */
    case 0:
        if (var_r3_1617 != 0) {
            if (((u8) this->unk30 >> 6U) & 1) {
                var_f0_1670 = 0.5f;
            } else {
                var_f0_1670 = 3.0f;
            }
            this->unk1C = M2C_FIELD(&gb, f32 *, 0x30C) + var_f0_1670;
            this->unk2C = 1;
            return;
        }
        return;
    case 1:
        if (var_r3_1617 != 0) {
            if (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk1C) {
                this->unk2C = 2;
                this->unk1C = M2C_FIELD(&gb, f32 *, 0x30C) + 3.0f;
                return;
            }
        } else {
            this->unk2C = 0;
            return;
        }
        break;
    case 2:
        if ((var_r3_1617 == 0) || (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk1C)) {
            ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOn(this->unk14);
            ((SB2 *) this->unkC->unk638)->WallAvoidanceOn();
            this->unk2C = 0;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void EnemyGoal_MoveToTarget::Activate() {
    Character *temp_r4_1813;
    Character *temp_r5_1769;
    Character *temp_r5_1878;
    Character *temp_r6_1796;
    Character *temp_r6_1805;
    s32 temp_r0_1745;
    s32 temp_r0_1857;
    s32 var_r6_1852;
    s32 var_r7_1845;
    u32 temp_r0_1843;
    void *temp_r3_1741;
    void *temp_r3_1818;
    void *temp_r4_1771;

    this->unk8 = 0;
    temp_r3_1741 = this->unkC->unk638;
    M2C_FIELD(temp_r3_1741, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1741, u8 *, 0x464) | 0x80);
    temp_r0_1745 = this->unk20;
    switch (temp_r0_1745) {                         /* irregular */
    case 0:
        ((SB2 *) this->unkC->unk638)->SeekOn(this->unk10);
        break;
    case 2:
        ((SB2 *) this->unkC->unk638)->ArriveOn(this->unk10);
        break;
    case 3:
        temp_r5_1769 = this->unkC;
        temp_r4_1771 = temp_r5_1769->unkA20;
        if (((u8) temp_r5_1769->unkA38->unk17C != 0) && ((temp_r4_1771 == NULL) || !(M2C_FIELD(temp_r4_1771, s32 *, 0x38) & 0x40))) {
            temp_r5_1769->unk690 = 0.25f;
            ((SB2 *) this->unkC->unk638)->RandomPursuitOn(this->unk10);
        } else {
            ((SB2 *) temp_r5_1769->unk638)->PursuitOn(this->unk10);
        }
        break;
    }
    if (((u8) this->unk30 >> 7U) & 1) {
        temp_r6_1796 = this->unkC;
        temp_r6_1796->unkA38->GetAnimSequence(6, this->unk24, temp_r6_1796->unkAE4, NULL);
    } else {
        temp_r6_1805 = this->unkC;
        temp_r6_1805->unkA38->GetAnimSequence(5, this->unk24, temp_r6_1805->unkAE4, NULL);
    }
    temp_r4_1813 = this->unkC;
    if ((u8) temp_r4_1813->unkA38->unk17E != 0) {
        temp_r3_1818 = temp_r4_1813->unk638;
        M2C_FIELD(temp_r3_1818, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1818, u8 *, 0x464) | 0x40);
    }
    if (((u8) this->unk30 >> 5U) & 1) {
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOn(this->unk14);
        ((SB2 *) this->unkC->unk638)->WallAvoidanceOn();
    }
    if (((u8) this->unk30 >> 6U) & 1) {
        ((SB2 *) this->unkC->unk638)->ContainmentOn();
    }
    temp_r0_1843 = ((u8) this->unk30 >> 7U) & 1;
    if (temp_r0_1843 != 0) {
        var_r7_1845 = this->unk24;
    } else {
        var_r7_1845 = 0;
    }
    if (temp_r0_1843 != 0) {
        var_r6_1852 = 0;
    } else {
        var_r6_1852 = this->unk24;
    }
    temp_r0_1857 = 0 - temp_r0_1843;
    this->unkC->unk9E8.Set((4 & ((temp_r0_1857 - temp_r0_1857) - !M2C_CARRY)) | 0xB, 0xA, var_r6_1852, var_r7_1845);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    if (this->unk10->unk40.Get() != NULL) {
        temp_r5_1878 = this->unkC;
        if (M2C_FIELD(this->unk10->unk40.Get()->__vptr, u8 (**)(M2C_UNK *, M2C_UNK *), 0x28)(&temp_r5_1878->unk588, &temp_r5_1878->unk700) != 0) {
            this->unkC->unk6F8 = 1;
        }
    }
    this->unk2C = 0;
}
#endif

void EnemyGoal_Land::Terminate() {
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}

#if 0 // DRAFT: illegal operand
u8 EnemyGoal_Land::Update() {
    Enemy *temp_r30_1933;
    EnemyDescriptor *temp_r4_1939;
    u8 var_r31_1934;

    ActivateIfInactive();
    temp_r30_1933 = this->unkC;
    var_r31_1934 = 0;
    if (((Character *) temp_r30_1933)->HasAnimFinished() != 0) {
        temp_r4_1939 = temp_r30_1933->unkA38;
        if ((temp_r4_1939 != NULL) && ((s8 *) temp_r4_1939->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r30_1933, void **, 0x630), u32 *, 0x20))) {
            var_r31_1934 = 1;
        }
    }
    if (var_r31_1934 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void EnemyGoal_Land::Activate() {
    Enemy *temp_r3_1980;
    EnemyDescriptor *temp_r5_1982;

    this->unk8 = 0;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    temp_r3_1980 = this->unkC;
    temp_r5_1982 = temp_r3_1980->unkA38;
    if (((s32) this->unk14 != (s32) temp_r5_1982->unk6C) || ((s32) this->unk10 != M2C_BITWISE(s32, temp_r5_1982->unk68))) {
        temp_r3_1980->SetAnim((AnimSequenceType) this->unk14, this->unk10, 0, 0.15f, 0U, 0U);
    }
}

void EnemyGoal_Wander::Terminate() {
    Character *temp_r3_2021;
    void *temp_r3_2017;
    void *temp_r4_2040;

    temp_r3_2017 = this->unkC->unk638;
    M2C_FIELD(temp_r3_2017, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2017, u8 *, 0x464) & ~0x80);
    temp_r3_2021 = this->unkC;
    temp_r3_2021->unk588.unkC = 0.0f;
    temp_r3_2021->unk598 = 0.0f;
    temp_r3_2021->unk59C = 0.0f;
    ((SB2 *) this->unkC->unk638)->WanderOff();
    ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    ((SB2 *) this->unkC->unk638)->WallAvoidanceOff();
    ((SB2 *) this->unkC->unk638)->ContainmentOff();
    temp_r4_2040 = this->unkC->unk638;
    M2C_FIELD(temp_r4_2040, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r4_2040, u8 *, 0x464) & ~0x40);
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unk9E8'
u8 EnemyGoal_Wander::Update() {
    ActivateIfInactive();
    this->unkC->unk9E8.Update();
    if ((this->unk10 > 0.0f) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unkC->unkA78)) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9E8'
void EnemyGoal_Wander::Activate() {
    s32 temp_r6_2116;
    void *temp_r3_2099;

    this->unk8 = 0;
    temp_r3_2099 = this->unkC->unk638;
    M2C_FIELD(temp_r3_2099, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2099, u8 *, 0x464) | 0x80);
    ((SB2 *) this->unkC->unk638)->WanderOn();
    ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOn(NULL);
    ((SB2 *) this->unkC->unk638)->WallAvoidanceOn();
    ((SB2 *) this->unkC->unk638)->ContainmentOn();
    temp_r6_2116 = this->unk18;
    this->unkC->unk9E8.Set(3U, 1, temp_r6_2116, temp_r6_2116);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    this->unkC->unkA78 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk10;
}
#endif

void EnemyGoal_Wander::Reset() {
    this->unk8 = 1;
    this->unk10 = 0.0f;
}

#if 0 // DRAFT: undefined identifier 'unkB09'
void EnemyGoal_FollowPath::Terminate() {
    Character *temp_r3_2190;
    Character *temp_r3_2195;
    Character *temp_r4_2183;
    u8 temp_r3_2184;
    void *temp_r3_2161;
    void *temp_r3_2179;

    temp_r3_2161 = this->unkC->unk638;
    M2C_FIELD(temp_r3_2161, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2161, u8 *, 0x464) & ~0x80);
    this->unkC->StopMovement(0U);
    ((SB2 *) this->unkC->unk638)->PathFollowingOff();
    if (((u8) this->unk24 >> 2U) & 1) {
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    }
    temp_r3_2179 = this->unkC->unk638;
    M2C_FIELD(temp_r3_2179, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2179, u8 *, 0x464) & ~0x40);
    temp_r4_2183 = this->unkC;
    temp_r3_2184 = temp_r4_2183->unkB09;
    if ((temp_r3_2184 >> 4U) & 1) {
        temp_r4_2183->unkB09 = temp_r3_2184 & ~0x10;
        temp_r3_2190 = this->unkC;
        M2C_FIELD(temp_r3_2190, f64 *, 0x5B8) = (f64) M2C_FIELD(temp_r3_2190, f64 *, 0x588);
        M2C_FIELD(temp_r3_2190, f64 *, 0x5C0) = (f64) M2C_FIELD(temp_r3_2190, f64 *, 0x590);
        temp_r3_2195 = this->unkC;
        ((Enemy *) temp_r3_2195)->SetupEnemyRegion(*((MKVector3 *) &temp_r3_2195->unk588), 1000.0f);
    }
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9E8'
u8 EnemyGoal_FollowPath::Update() {
    AnimSequence *temp_r4_2250;
    Character *temp_r27_2244;
    Character *temp_r4_2291;
    f32 temp_f1_2268;
    s32 temp_r31_2230;
    u8 var_r28_2245;
    u8 var_r30_2231;
    void *temp_r3_2314;

    ActivateIfInactive();
    if ((KDSplinePathSegment *) this->unk10 == NULL) {
        return this->unk8;
    }
    this->unkC->unk9E8.Update();
    temp_r31_2230 = ((SB2 *) this->unkC->unk638)->PathFollowingHasLooped();
    var_r30_2231 = 0;
    if ((((u8) this->unk24 >> 5U) & 1) && (((SB2 *) this->unkC->unk638)->PathFollowingHasReachedNextPoint() != 0)) {
        var_r30_2231 = 1;
    }
    if (((u8) this->unk24 >> 6U) & 1) {
        temp_r27_2244 = this->unkC;
        var_r28_2245 = 0;
        if (temp_r27_2244->HasAnimFinished() != 0) {
            temp_r4_2250 = temp_r27_2244->unkA50;
            if ((temp_r4_2250 != NULL) && ((u32) temp_r4_2250->unk40 == (u32) M2C_FIELD(M2C_FIELD(temp_r27_2244, void **, 0x630), u32 *, 0x20))) {
                var_r28_2245 = 1;
            }
        }
        if (var_r28_2245 != 0) {
            this->unk8 = 2;
        }
    }
    if (!(((u8) this->unk24 >> 6U) & 1) && (((temp_f1_2268 = this->unk14, ((temp_f1_2268 <= 0.0f) != 0)) && ((u8) temp_r31_2230 != 0)) || ((temp_f1_2268 > 0.0f) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unkC->unkA78)) || (var_r30_2231 != 0))) {
        temp_r4_2291 = this->unkC;
        if ((u32) temp_r4_2291->unkA50->unk40 != 0) {
            temp_r4_2291->unk9E8.SetExitingAnim();
            this->unk24 |= 0x40;
            ((SB2 *) this->unkC->unk638)->PathFollowingOff();
            ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
            ((SB2 *) this->unkC->unk638)->WallAvoidanceOff();
            temp_r3_2314 = this->unkC->unk638;
            M2C_FIELD(temp_r3_2314, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2314, u8 *, 0x464) & ~0x80);
            this->unkC->StopMovement(0U);
        } else {
            this->unk8 = 2;
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA38'
void EnemyGoal_FollowPath::Activate() {
    Character *temp_r29_2368;
    Character *temp_r5_2357;
    EnemyDescriptor *temp_r4_2371;
    s32 temp_r30_2367;
    u8 temp_r0_2396;
    void *temp_r3_2353;
    void *temp_r3_2362;

    this->unk8 = 0;
    if ((KDSplinePathSegment *) this->unk10 == NULL) {
        this->unk8 = 2;
        return;
    }
    temp_r3_2353 = this->unkC->unk638;
    M2C_FIELD(temp_r3_2353, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2353, u8 *, 0x464) | 0x80);
    temp_r5_2357 = this->unkC;
    if ((u8) temp_r5_2357->unkA38->unk17E != 0) {
        temp_r3_2362 = temp_r5_2357->unk638;
        M2C_FIELD(temp_r3_2362, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2362, u8 *, 0x464) | 0x40);
    }
    temp_r30_2367 = this->unk1C;
    temp_r29_2368 = this->unkC;
    temp_r4_2371 = temp_r29_2368->unkA38;
    temp_r29_2368->unk9E8.Set(temp_r4_2371->unk20C | EnemyMovementType_GetMask(this->unk20), temp_r4_2371->unk210, temp_r30_2367, temp_r30_2367);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    this->unkC->unkA78 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk14;
    temp_r0_2396 = this->unk24;
    ((SB2 *) this->unkC->unk638)->PathFollowingOn(this->unk10, ((u32) M2C_ERROR(/* unknown instruction: mfcr $r5 */) >> 0x1EU) & 1, (temp_r0_2396 >> 5U) & 1, (temp_r0_2396 >> 4U) & 1, (temp_r0_2396 >> 3U) & 1, 0.0f);
    if (((u8) this->unk24 >> 2U) & 1) {
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOn(NULL);
    }
}
#endif

void EnemyGoal_FollowPath::Reset() {
    this->unk8 = 1;
    this->unk14 = 0.0f;
    this->unk18 = 1;
    this->unk1C = 0;
    this->unk24 &= ~0x80;
    this->unk24 &= ~0x40;
    this->unk24 &= ~0x20;
    this->unk24 &= ~0x10;
    this->unk24 &= ~8;
    this->unk10 = NULL;
}

#if 0 // DRAFT: undefined identifier 'sp30'
u8 EnemyGoal_Strafe::Update() {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    M2C_UNK sp8;
    Character *temp_r3_2475;
    Character *temp_r3_2542;
    Character *temp_r3_2551;
    Character *temp_r4_2495;
    f64 temp_f0_2480;
    u8 var_r29_2515;
    u8 var_r30_2459;
    void *temp_r3_2455;

    ActivateIfInactive();
    temp_r3_2455 = this->unk10;
    if (temp_r3_2455 != NULL) {
        var_r30_2459 = 0;
        if (((u8) M2C_FIELD(temp_r3_2455, u8 *, 0x48) == 2) || (((TargetContext *) (((u8 *) temp_r3_2455) + 0x40))->Get() != NULL)) {
            var_r30_2459 = 1;
        }
        if (var_r30_2459 == 0) {
            this->unk8 = 3;
        } else {
            goto block_6;
        }
    } else {
block_6:
        temp_r3_2475 = this->unkC;
        temp_f0_2480 = M2C_FIELD(temp_r3_2475, f64 *, 0x588) + M2C_FIELD(temp_r3_2475, f64 *, 0x90);
        sp18 = temp_f0_2480;
        sp38 = temp_f0_2480;
        sp20 = temp_r3_2475->unk588.unk4 + temp_r3_2475->unk98;
        sp40 = (f64) sp20;
        if ((void *) this->unk10 != NULL) {
            ((AITargetData *) &sp28)->GetDir();
            temp_r4_2495 = this->unkC;
            M2C_FIELD(temp_r4_2495, f64 *, 0xE0) = sp28;
            M2C_FIELD(temp_r4_2495, f64 *, 0xE8) = sp30;
            temp_r4_2495->unk6B5 |= 0x40;
        }
        if (this->unkC->HasAnimFinished() != 0) {
            this->unk8 = 2;
        } else {
            var_r29_2515 = 0;
            if (this->unkC->unk800.IsPointWithin(*((MKVector3 *) &sp38)) != 0) {
                ((EnemyRegion *) &sp8)->GetRegionPos();
                if ((f32) fabs(spC - (*(f32 *) ((u8 *) &sp38 + 0x4))) <= 500.0f) {
                    var_r29_2515 = 1;
                }
            }
            if ((var_r29_2515 == 0) || (this->unkC->unk838.IsPointWithin(*((MKVector3 *) &sp38)) != 0) || (temp_r3_2542 = this->unkC, ((M2C_FIELD(temp_r3_2542->__vptr, u8 (**)(Character *, f64 *), 0x1C0)(temp_r3_2542, &sp38) == 0) == 0))) {
                temp_r3_2551 = this->unkC;
                temp_r3_2551->unk90 = 0.0f;
                temp_r3_2551->unk94 = 0.0f;
                temp_r3_2551->unk98 = 0.0f;
                this->unkC->StopMovement(1U);
                this->unk8 = 2;
            }
        }
    }
    return this->unk8;
}
#endif

void EnemyGoal_Strafe::Activate() {
    Character *temp_r4_2602;
    s32 var_r5_2586;

    this->unk8 = 0;
    ((Enemy *) this->unkC)->SetWalkMovementSpeed(1U);
    var_r5_2586 = 0x1A;
    if ((u8) this->unk14 != 0) {
        var_r5_2586 = 0x19;
    }
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 7, var_r5_2586, 0, 0.15f, 4U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    if ((void *) this->unk10 == NULL) {
        temp_r4_2602 = this->unkC;
        M2C_FIELD(temp_r4_2602, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r4_2602, f64 *, 0xC0);
        M2C_FIELD(temp_r4_2602, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r4_2602, f64 *, 0xC8);
        temp_r4_2602->unk6B5 |= 0x40;
    }
}

void EnemyGoal_BackupFromTarget::Terminate() {
    M2C_FIELD(this->unkC, s8 *, 0x6F8) = 0;
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier '__vptr'
u8 EnemyGoal_BackupFromTarget::Update() {
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    AITargetData *temp_r3_2639;
    Enemy *temp_r3_2703;
    Enemy *temp_r3_2736;
    Enemy *temp_r3_2749;
    Enemy *temp_r3_2757;
    Enemy *temp_r4_2668;
    Enemy *temp_r4_2721;
    Enemy *temp_r5_2696;
    f64 temp_f0_2708;
    u8 var_r30_2643;

    ActivateIfInactive();
    temp_r3_2639 = this->unk10;
    if (temp_r3_2639 != NULL) {
        var_r30_2643 = 0;
        if (((u8) M2C_FIELD(temp_r3_2639, u8 *, 0x48) == 2) || (temp_r3_2639->unk40.Get() != NULL)) {
            var_r30_2643 = 1;
        }
        if ((var_r30_2643 == 0) || ((((u8) M2C_FIELD(this->unk10, u8 *, 0x49) >> 6U) & 1) && (this->unkC->IsInsideEnemyRegion() == 0)) || ((((u8) M2C_FIELD(this->unk10, u8 *, 0x49) >> 6U) & 1) && (temp_r4_2668 = this->unkC, ((((EnemyRegion *) &temp_r4_2668->unk800.unk28)->IsPointWithin(*((MKVector3 *) &temp_r4_2668->unk588)) == 0) == 0))) || (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk18)) {
            goto block_10;
        }
        if (this->unk10->unk40.Get() != NULL) {
            temp_r5_2696 = this->unkC;
            M2C_FIELD(this->unk10->unk40.Get()->__vptr, M2C_UNK (**)(M2C_UNK *, u8 *), 0x28)(&temp_r5_2696->unk588, &temp_r5_2696->unk6C0.unk38);
        }
        temp_r3_2703 = this->unkC;
        temp_f0_2708 = M2C_FIELD(temp_r3_2703, f64 *, 0x588) + M2C_FIELD(temp_r3_2703, f64 *, 0x90);
        sp8 = temp_f0_2708;
        sp28 = temp_f0_2708;
        sp10 = temp_r3_2703->unk588.unk4 + temp_r3_2703->unk98;
        sp30 = (f64) sp10;
        ((AITargetData *) &sp18)->GetDir();
        temp_r4_2721 = this->unkC;
        M2C_FIELD(temp_r4_2721, f64 *, 0xE0) = sp18;
        M2C_FIELD(temp_r4_2721, f64 *, 0xE8) = sp20;
        temp_r4_2721->unk6B5 |= 0x40;
        if ((this->unk10->GetDist() >= this->unk14) && ((temp_r3_2736 = this->unkC, (((u8) M2C_FIELD(temp_r3_2736->unkA20, u8 *, 0x17E) == 0) != 0)) || (((Character *) temp_r3_2736)->HasAnimFinished() != 0))) {
            this->unk8 = 2;
        } else {
            temp_r3_2749 = this->unkC;
            if (temp_r3_2749->CheckForCliff(sp28) != 0) {
                temp_r3_2757 = this->unkC;
                temp_r3_2757->unk90 = 0.0f;
                temp_r3_2757->unk94 = 0.0f;
                temp_r3_2757->unk98 = 0.0f;
                ((Character *) this->unkC)->StopMovement(1U);
                this->unk8 = 2;
            }
        }
    } else {
block_10:
        this->unk8 = 3;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_BackupFromTarget::Activate() {
    AITargetData *temp_r3_2800;
    Enemy *temp_r5_2811;

    this->unk8 = 0;
    this->unkC->SetWalkMovementSpeed(1U);
    this->unkC->SetAnim((AnimSequenceType) 5, 0xF, 0, 0.15f, 0U, 0U);
    ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 0);
    temp_r3_2800 = this->unk10;
    if ((temp_r3_2800 != NULL) && (temp_r3_2800->unk40.Get() != NULL)) {
        temp_r5_2811 = this->unkC;
        if (M2C_FIELD(this->unk10->unk40.Get()->__vptr, u8 (**)(M2C_UNK *, u8 *), 0x28)(&temp_r5_2811->unk588, &temp_r5_2811->unk6C0.unk38) != 0) {
            M2C_FIELD(this->unkC, s8 *, 0x6F8) = 1;
        }
    }
    this->unk18 = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
}
#endif
