#include "spyro/source/EnemyGoals_Hit.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Character.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/Game.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Spyro.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "spyro/source/GameConsole.h"
#include "spyro/source/InGame.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
f64 pow(f64, f32);                                  /* extern */
extern M2C_UNK lit_961;
extern s32 GS_EnemyHitWall;
extern s32 GS_EnemyKnockedUp;
extern s32 GS_EnemyPopUp;
extern s32 GS_EnemySlideGround;
extern s32 GS_Rumble5;
extern s32 GS_SpyroEarthFurySquish;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
static f32 fInitialKnockupForce = 550.0f;
static f32 fKnockupGravityMultiplier = 2.0f;
static f32 fInitialKnockdownForce = 1500.0f;
static s32 lit_1067 = 0;
static s32 lit_1069 = 2;

#if 0 // DRAFT: undefined identifier 'unkB0A'
void EnemyGoal_HitSquished::Terminate() {
    Character *temp_r3_17;

    temp_r3_17 = this->unkC;
    temp_r3_17->unkB0A &= ~0x10;
    this->unkC->SetMovementType((CharacterMoveType) this->unk18);
    M2C_FIELD(this->unkC->unk630, f32 *, 0x38) = 1.0f;
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkAC8'
u8 EnemyGoal_HitSquished::Update() {
    Matrix sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Character *temp_r3_146;
    f32 temp_f30_136;
    f32 temp_f31_110;
    f32 temp_f3_139;
    f32 var_f0_56;
    s32 temp_r0_71;

    ActivateIfInactive();
    var_f0_56 = this->unk14 - gUpdateTimeDelta;
    if (var_f0_56 < 4.0f) {

    } else {
        var_f0_56 = 4.0f;
    }
    if (var_f0_56 > 0.0f) {

    } else {
        var_f0_56 = 0.0f;
    }
    this->unk14 = var_f0_56;
    temp_r0_71 = this->unk10;
    switch (temp_r0_71) {                           /* irregular */
    case 0:
        if (this->unk14 <= 0.0f) {
            if (this->unkC->unkAC8 <= 0.0f) {
                this->unk8 = 2;
            } else {
                this->unk14 = 0.75f;
                this->unk10 = 1;
                KDSound_Play3d(GS_EnemyPopUp, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
        break;
    case 1:
        temp_f31_110 = this->unk14 / 0.75f;
        M2C_STRUCT_COPY((s32) &sp30.unkC + 4, MKModel_GetWorldMatrix(this->unkC->unk4) - 4 + 4, 0x40);
        sp30.NormaliseScale();
        temp_f30_136 = (0.25f * (temp_f31_110 * _table_sinf((35.0f * this->unk14) + 1.5707964f))) + 1.0f;
        temp_f3_139 = temp_f31_110 * _table_sinf(25.0f * this->unk14);
        sp18 = temp_f30_136;
        sp10 = temp_f30_136;
        temp_r3_146 = this->unkC;
        sp14 = (0.5f * temp_f3_139) + 1.0f;
        sp28 = (f64) sp18;
        temp_r3_146->unk730 = (f64) sp10;
        temp_r3_146->unk738 = (f64) sp18;
        sp20 = (f64) sp10;
        if (this->unk14 <= 0.0f) {
            this->unk8 = 2;
        }
        break;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkB0A'
void EnemyGoal_HitSquished::Activate() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Character *temp_r3_219;
    Character *temp_r4_187;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    temp_r4_187 = this->unkC;
    temp_r4_187->unkB0A |= 0x10;
    this->unk10 = 0;
    this->unk14 = 4.0f;
    KDSound_Play3d(GS_SpyroEarthFurySquish, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    this->unk18 = this->unkC->unk688;
    this->unkC->SetMovementType((CharacterMoveType) 0);
    sp8 = 1.5f;
    M2C_FIELD(this->unkC->unk630, f32 *, 0x38) = 0.0f;
    spC = 0.1f;
    temp_r3_219 = this->unkC;
    sp10 = 1.5f;
    temp_r3_219->unk730 = (f64) sp8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    temp_r3_219->unk738 = (f64) sp10;
}
#endif

void EnemyGoal_Hit::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
u8 EnemyGoal_Hit::Update() {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 sp8;
    Enemy *temp_r3_266;
    Enemy *temp_r3_281;
    f64 temp_f0_301;
    f64 temp_f1_291;
    s32 var_r6_307;
    void *temp_r4_288;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    sp8 = 0;
    temp_r3_266 = this->unkC;
    if (((temp_r3_266->unkAC8 <= 0.0f) || ((u8) temp_r3_266->unkA38->unk121 != 0)) && (temp_r3_266->InWaterVolume(temp_r3_266->unk588, &sp8) != 0)) {
        temp_r3_281 = this->unkC;
        sp20 = M2C_FIELD(temp_r3_281, f64 *, 0xC0) * 5.398241246e-315;
        temp_r4_288 = temp_r3_281->unk8;
        temp_f1_291 = M2C_FIELD(temp_r4_288, f64 *, 0x30);
        sp28 = temp_r3_281->unkC8 * 10.0f;
        sp30 = sp20;
        sp40 = temp_f1_291;
        sp38 = (f64) sp28;
        sp48 = M2C_FIELD(temp_r4_288, f64 *, 0x38);
        temp_f0_301 = temp_f1_291 + sp30;
        sp10 = temp_f0_301;
        var_r6_307 = 0x4000;
        sp50 = temp_f0_301;
        sp18 = (f32) sp48 + (f32) sp38;
        sp58 = (f64) sp18;
        if (sp8 & 1) {
            var_r6_307 = 0x800;
        }
        temp_r3_281->AddDamage(0.0f, 1U, *((MKVector3 *) &sp50), var_r6_307, 0, 0U, 0U, NULL, 0.0f, 1.0f);
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void EnemyGoal_Hit::Activate() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    EAPManager *temp_r3_379;
    Enemy *temp_r3_360;
    Enemy *temp_r3_366;
    Enemy *temp_r3_370;
    Enemy *temp_r3_374;
    Enemy *temp_r3_439;
    Enemy *temp_r3_472;
    Enemy *temp_r3_499;
    Enemy *temp_r3_523;
    Enemy *temp_r3_547;
    Enemy *temp_r3_571;
    Enemy *temp_r3_608;
    Enemy *temp_r3_625;
    Enemy *temp_r4_484;
    Enemy *temp_r4_508;
    Enemy *temp_r4_532;
    Enemy *temp_r4_556;
    Enemy *temp_r4_593;
    Enemy *temp_r5_388;
    Enemy *temp_r6_450;
    SB2 *temp_r3_353;
    s32 var_r31_389;

    this->unk8 = 0;
    this->unkC->unk6C0.unk38 = 0;
    temp_r3_353 = this->unkC->unk640;
    if (temp_r3_353 != NULL) {
        temp_r3_353->unk464 &= ~0x80;
    }
    temp_r3_360 = this->unkC;
    temp_r3_360->unkB08 &= ~8;
    temp_r3_366 = this->unkC;
    temp_r3_366->unkB08 |= 0x40;
    temp_r3_370 = this->unkC;
    temp_r3_370->unkB09 &= ~2;
    temp_r3_374 = this->unkC;
    temp_r3_374->unkB08 &= ~0x10;
    temp_r3_379 = this->unkC->unkA5C;
    if (temp_r3_379 != NULL) {
        temp_r3_379->unk10 |= 0x40;
    }
    RemoveAllSubgoals();
    temp_r5_388 = this->unkC;
    var_r31_389 = temp_r5_388->unk938;
    if (var_r31_389 < 4) {
        if (var_r31_389 != 1) {
            if (var_r31_389 < 1) {
                if (var_r31_389 < 0) {
                    goto block_14;
                }
            } else {
                goto block_12;
            }
        } else {
            goto block_14;
        }
    } else {
        if (var_r31_389 < 0xA) {
            if (var_r31_389 < 8) {

            } else {
block_12:
                if (temp_r5_388->unkA38->GetAnimSequence(2, 0x2A, temp_r5_388->unkAE4, NULL) == NULL) {
                    var_r31_389 = 1;
                }
            }
        }
block_14:
        if ((s32) this->unkC->unk688 == 2) {
            var_r31_389 = 0;
        }
    }
    if ((u32) var_r31_389 <= 0xCU) {
        switch (var_r31_389) {
        case 0:
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk20);
            M2C_FIELD(this->unk20, s8 *, 0x10) = (s8) (this->unkC->unk638 != NULL);
            temp_r3_439 = this->unkC;
            temp_r3_439->unk6B4 |= 1;
            break;
        case 4:
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
            break;
        case 5:
            temp_r6_450 = this->unkC;
            if (temp_r6_450->unkA38->GetAnimSequence(2, 0x31, temp_r6_450->unkAE4, NULL) != NULL) {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
            } else {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
            }
            break;
        case 1:
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
            temp_r3_472 = this->unkC;
            temp_r3_472->unk6B4 |= 1;
            break;
        case 2:
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
            temp_r4_484 = this->unkC;
            if (temp_r4_484->unkAC8 > 0.0f) {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
            } else {
                temp_r4_484->unkB08 |= 8;
            }
            temp_r3_499 = this->unkC;
            temp_r3_499->unk6B4 |= 1;
            break;
        case 3:
        case 10:
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
            temp_r4_508 = this->unkC;
            if (temp_r4_508->unkAC8 > 0.0f) {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
            } else {
                temp_r4_508->unkB08 |= 8;
            }
            temp_r3_523 = this->unkC;
            temp_r3_523->unk6B4 |= 1;
            break;
        case 8:
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk38);
            temp_r4_532 = this->unkC;
            if (temp_r4_532->unkAC8 > 0.0f) {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
            } else {
                temp_r4_532->unkB08 |= 8;
            }
            temp_r3_547 = this->unkC;
            temp_r3_547->unk6B4 |= 1;
            break;
        case 6:
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk40);
            temp_r4_556 = this->unkC;
            if (temp_r4_556->unkAC8 > 0.0f) {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
            } else {
                temp_r4_556->unkB08 |= 8;
            }
            temp_r3_571 = this->unkC;
            temp_r3_571->unk6B4 |= 1;
            break;
        case 7:
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk48);
            break;
        case 9:
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk3C);
            if (!(((u8) this->unkC->unkB0A >> 1U) & 1)) {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
            }
            temp_r4_593 = this->unkC;
            if (temp_r4_593->unkAC8 > 0.0f) {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
            } else {
                temp_r4_593->unkB08 |= 8;
            }
            temp_r3_608 = this->unkC;
            temp_r3_608->unk6B4 |= 1;
            break;
        case 11:
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk4C);
            break;
        case 12:
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk50);
            break;
        }
    }
    if (var_r31_389 != 9) {
        temp_r3_625 = this->unkC;
        temp_r3_625->unkB0A &= ~2;
    }
    sp10 = 0.0f;
    sp8 = 0.0f;
    spC = -500.0f;
    sp20 = (f64) sp10;
    sp18 = (f64) sp8;
    this->unkC->DisableCurrentProjectile(1U, *((MKVector3 *) &sp18));
}
#endif

#if 0 // DRAFT: ')' expected
void EnemyGoal_Hit::Deinit() {
    Goal<Enemy> *temp_r3_659;
    Goal<Enemy> *temp_r3_664;
    Goal<Enemy> *temp_r3_669;
    Goal<Enemy> *temp_r3_674;
    Goal<Enemy> *temp_r3_679;
    Goal<Enemy> *temp_r3_684;
    Goal<Enemy> *temp_r3_689;
    Goal<Enemy> *temp_r3_694;
    Goal<Enemy> *temp_r3_699;
    Goal<Enemy> *temp_r3_704;
    Goal<Enemy> *temp_r3_709;
    Goal<Enemy> *temp_r3_714;
    Goal<Enemy> *temp_r3_719;
    MKHeap *temp_r3_755;
    void *temp_r31_752;

    temp_r3_659 = this->unk20;
    temp_r3_659->Deinit();
    temp_r3_664 = this->unk24;
    temp_r3_664->Deinit();
    temp_r3_669 = this->unk28;
    temp_r3_669->Deinit();
    temp_r3_674 = this->unk2C;
    temp_r3_674->Deinit();
    temp_r3_679 = this->unk30;
    temp_r3_679->Deinit();
    temp_r3_684 = this->unk34;
    temp_r3_684->Deinit();
    temp_r3_689 = this->unk38;
    temp_r3_689->Deinit();
    temp_r3_694 = this->unk40;
    temp_r3_694->Deinit();
    temp_r3_699 = this->unk44;
    temp_r3_699->Deinit();
    temp_r3_704 = this->unk48;
    temp_r3_704->Deinit();
    temp_r3_709 = this->unk3C;
    temp_r3_709->Deinit();
    temp_r3_714 = this->unk4C;
    temp_r3_714->Deinit();
    temp_r3_719 = this->unk50;
    temp_r3_719->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    ((EnemyGoal_HitKnockdown *) this->unk34)->~EnemyGoal_HitKnockdown(1);
    ((EnemyGoal_HitKnockdownSlide *) this->unk38)->~EnemyGoal_HitKnockdownSlide(1);
    operator delete(this->unk40);
    operator delete(this->unk44);
    operator delete(this->unk48);
    operator delete(this->unk3C);
    operator delete(this->unk4C);
    operator delete(this->unk50);
    temp_r31_752 = this->unk1C;
    if (temp_r31_752 != NULL) {
        temp_r3_755 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_755 != NULL) {
            ((MKHeap *) (temp_r3_755->Current()))->Free(temp_r31_752, NULL, 0);
        } else {
            free(temp_r31_752);
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
void EnemyGoal_Hit::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_1157;
    Goal<Enemy> *temp_r4_1168;
    Goal<Enemy> *temp_r4_1179;
    Goal<Enemy> *temp_r4_1190;
    Goal<Enemy> *temp_r4_1201;
    Goal<Enemy> *temp_r4_1212;
    Goal<Enemy> *temp_r4_1223;
    Goal<Enemy> *temp_r4_1234;
    Goal<Enemy> *temp_r4_1245;
    Goal<Enemy> *temp_r4_1256;
    Goal<Enemy> *temp_r4_1267;
    Goal<Enemy> *temp_r4_1278;
    Goal<Enemy> *temp_r4_1289;
    MKHeap *temp_r3_1130;
    void *var_r3_1137;

    if ((u8) this->unk9 == 0) {
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x44U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x3CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk40 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk44 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk48 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk3C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk4C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk50 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_1130 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1130 != NULL) {
            var_r3_1137 = ((MKHeap *) (temp_r3_1130->Current()))->Alloc(0xC, NULL, 0);
        } else {
            var_r3_1137 = malloc(0xC);
        }
        this->unk1C = var_r3_1137;
        this->unk10 = 3;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x59;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_1157 = this->unk20;
    M2C_FIELD(temp_r4_1157, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1157, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1157, s32 *, 4) = 8;
    if ((Enemy *) M2C_FIELD(temp_r4_1157, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1157, s8 *, 9) = 1;
    }
    temp_r4_1168 = this->unk24;
    M2C_FIELD(temp_r4_1168, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1168, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1168, s32 *, 4) = 0xF;
    if ((Enemy *) M2C_FIELD(temp_r4_1168, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1168, s8 *, 9) = 1;
    }
    temp_r4_1179 = this->unk28;
    M2C_FIELD(temp_r4_1179, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1179, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1179, s32 *, 4) = 0x10;
    if ((Enemy *) M2C_FIELD(temp_r4_1179, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1179, s8 *, 9) = 1;
    }
    temp_r4_1190 = this->unk2C;
    M2C_FIELD(temp_r4_1190, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1190, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1190, s32 *, 4) = 0xA;
    if ((Enemy *) M2C_FIELD(temp_r4_1190, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1190, s8 *, 9) = 1;
    }
    temp_r4_1201 = this->unk30;
    M2C_FIELD(temp_r4_1201, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1201, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1201, s32 *, 4) = 0xB;
    if ((Enemy *) M2C_FIELD(temp_r4_1201, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1201, s8 *, 9) = 1;
    }
    temp_r4_1212 = this->unk34;
    M2C_FIELD(temp_r4_1212, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1212, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1212, s32 *, 4) = 0xC;
    if ((Enemy *) M2C_FIELD(temp_r4_1212, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1212, s8 *, 9) = 1;
    }
    temp_r4_1223 = this->unk38;
    M2C_FIELD(temp_r4_1223, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1223, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1223, s32 *, 4) = 0xD;
    if ((Enemy *) M2C_FIELD(temp_r4_1223, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1223, s8 *, 9) = 1;
    }
    temp_r4_1234 = this->unk40;
    M2C_FIELD(temp_r4_1234, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1234, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1234, s32 *, 4) = 0x11;
    if ((Enemy *) M2C_FIELD(temp_r4_1234, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1234, s8 *, 9) = 1;
    }
    temp_r4_1245 = this->unk44;
    M2C_FIELD(temp_r4_1245, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1245, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1245, s32 *, 4) = 0xE;
    if ((Enemy *) M2C_FIELD(temp_r4_1245, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1245, s8 *, 9) = 1;
    }
    temp_r4_1256 = this->unk48;
    M2C_FIELD(temp_r4_1256, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1256, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1256, s32 *, 4) = 0x12;
    if ((Enemy *) M2C_FIELD(temp_r4_1256, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1256, s8 *, 9) = 1;
    }
    temp_r4_1267 = this->unk3C;
    M2C_FIELD(temp_r4_1267, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1267, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1267, s32 *, 4) = 0x13;
    if ((Enemy *) M2C_FIELD(temp_r4_1267, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1267, s8 *, 9) = 1;
    }
    temp_r4_1278 = this->unk4C;
    M2C_FIELD(temp_r4_1278, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1278, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1278, s32 *, 4) = 0x14;
    if ((Enemy *) M2C_FIELD(temp_r4_1278, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1278, s8 *, 9) = 1;
    }
    temp_r4_1289 = this->unk50;
    M2C_FIELD(temp_r4_1289, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1289, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1289, s32 *, 4) = 0x15;
    if ((Enemy *) M2C_FIELD(temp_r4_1289, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1289, s8 *, 9) = 1;
    }
}
#endif

void EnemyGoal_HitFrozen::Terminate() {
    Enemy *temp_r3_1316;
    Enemy *temp_r3_1322;

    temp_r3_1316 = this->unkC;
    if (temp_r3_1316->unkAC8 > 0.0f) {
        temp_r3_1316->ThawIfFrozen();
    }
    temp_r3_1322 = this->unkC;
    temp_r3_1322->DefrostBall();
    M2C_FIELD(this->unkC->unk630, f32 *, 0x38) = (f32) this->unk10;
    this->unk8 = 1;
}

u8 EnemyGoal_HitFrozen::Update() {
    Enemy *temp_r3_1357;
    Enemy *temp_r3_1362;

    ActivateIfInactive();
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    temp_r3_1357 = this->unkC;
    temp_r3_1357->UpdateFrozenBallMovement();
    temp_r3_1362 = this->unkC;
    if ((temp_r3_1362->unkAAC <= 0.0f) || (temp_r3_1362->unkAC8 <= 0.0f)) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_HitFrozen::Activate() {
    Enemy *temp_r3_1397;

    this->unk8 = 0;
    ((Character *) this->unkC)->StopMovement(1U);
    temp_r3_1397 = this->unkC;
    if (temp_r3_1397->unkAC8 > 0.0f) {
        M2C_FIELD(temp_r3_1397->__vptr, M2C_UNK (**)(), 0x1D4)();
    }
    this->unk10 = M2C_FIELD(this->unkC->unk630, f32 *, 0x38);
    M2C_FIELD(this->unkC->unk630, f32 *, 0x38) = 0.0f;
}
#endif

void EnemyGoal_HitArmourDestroyed::Terminate() {
    Enemy *temp_r3_1432;

    this->unk8 = 1;
    temp_r3_1432 = this->unkC;
    if ((s32) temp_r3_1432->unkA50->unk68 == 0x2F) {
        temp_r3_1432->Armour_Destroy();
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
}

u8 EnemyGoal_HitArmourDestroyed::Update() {
    ActivateIfInactive();
    if (((Character *) this->unkC)->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

void EnemyGoal_HitArmourDestroyed::Activate() {
    Enemy *temp_r3_1529;
    Enemy *temp_r6_1491;

    this->unk8 = 0;
    temp_r6_1491 = this->unkC;
    if (temp_r6_1491->unkA38->GetAnimSequence(2, 0x2F, temp_r6_1491->unkAE4, NULL) != NULL) {
        this->unkC->SetInvulnerableToMeleeAttacks(1U, 0U);
        this->unkC->SetInvulnerableToBreathAttacks(1U, 0U);
        this->unkC->SetAnim((AnimSequenceType) 2, 0x2F, 0, 0.15f, 0U, 0U);
    } else {
        this->unkC->SetAnim((AnimSequenceType) 2, 0x28, 0, 0.15f, 0U, 0U);
        this->unkC->Armour_Destroy();
    }
    ((Character *) this->unkC)->StopMovement(1U);
    temp_r3_1529 = this->unkC;
    if ((s32) temp_r3_1529->unk688 != 2) {
        ((Character *) temp_r3_1529)->SetMovementType((CharacterMoveType) 0);
    }
}

void EnemyGoal_HitStand::Terminate() {
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unkC->EnableBlurFX(0U);
    this->unk8 = 1;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
u8 EnemyGoal_HitStand::Update() {
    MKVector3 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Enemy *temp_r3_1582;
    Enemy *temp_r3_1600;
    Enemy *temp_r3_1612;
    Enemy *temp_r3_1621;
    f64 temp_f1_1604;

    ActivateIfInactive();
    temp_r3_1582 = this->unkC;
    if ((temp_r3_1582->unkAC8 <= 0.0f) || (((Character *) temp_r3_1582)->HasAnimFinished() != 0)) {
        this->unk8 = 2;
    }
    if (GetPushOutWallNormal(this->unkC, &sp28) != 0) {
        temp_r3_1600 = this->unkC;
        temp_f1_1604 = temp_r3_1600->GetCollisionHeight();
        sp8 = M2C_BITWISE(f64, sp28) * temp_f1_1604;
        temp_r3_1612 = this->unkC;
        sp18 = sp8;
        sp10 = sp28.unk8 * (f32) temp_f1_1604;
        M2C_FIELD(temp_r3_1612, f64 *, 0xA0) = sp8;
        sp20 = (f64) sp10;
        M2C_FIELD(temp_r3_1612, f64 *, 0xA8) = (f64) sp10;
    } else {
        temp_r3_1621 = this->unkC;
        temp_r3_1621->unkA0 = 0.0f;
        temp_r3_1621->unkA8 = 0.0f;
    }
    return this->unk8;
}
#endif

void EnemyGoal_HitStand::Activate() {
    this->unk8 = 0;
    this->unkC->SetAnim((AnimSequenceType) 2, 0x2B, 0, 0.15f, 0U, 0U);
    ((Character *) this->unkC)->StopMovement(1U);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unkC->EnableBlurFX(1U);
}

#if 0 // DRAFT: undefined identifier 'spC'
void EnemyGoal_HitFall::Terminate() {
    M2C_UNK sp8;
    Enemy *temp_r3_1686;
    Enemy *temp_r3_1690;
    Enemy *temp_r3_1698;
    Enemy *temp_r3_1702;
    Enemy *temp_r3_1713;
    Enemy *temp_r5_1694;

    temp_r3_1686 = this->unkC;
    temp_r3_1686->unk6B5 |= 0x20;
    temp_r3_1690 = this->unkC;
    temp_r3_1690->unkA0 = 0.0f;
    temp_r3_1690->unkA4 = 0.0f;
    temp_r3_1690->unkA8 = 0.0f;
    temp_r5_1694 = this->unkC;
    temp_r5_1694->unk5E4 = M2C_FIELD(temp_r5_1694->unk5D8, f32 *, 8);
    temp_r3_1698 = this->unkC;
    temp_r3_1698->unk6B5 &= ~2;
    temp_r3_1702 = this->unkC;
    temp_r3_1702->unk6B5 &= ~1;
    if (this->unkC->unkAC8 > 0.0f) {
        ((EnemyRegion *) &sp8)->GetRegionPos();
        temp_r3_1713 = this->unkC;
        if ((f32) fabs(spC - temp_r3_1713->unk588.unk4) > 100.0f) {
            temp_r3_1713->SetupEnemyRegion(temp_r3_1713->unk588, 1000.0f);
        }
    }
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
u8 EnemyGoal_HitFall::Update() {
    s32 sp8;
    AnimSequence *temp_r4_1750;
    AnimSequence *temp_r4_1766;
    AnimSequence *temp_r4_1773;
    AnimSequence *temp_r4_1782;
    AnimSequence *temp_r4_1807;
    AnimSequence *temp_r4_1820;
    Enemy *temp_r29_1744;
    Enemy *temp_r29_1780;
    Enemy *temp_r3_1762;
    Enemy *temp_r3_1835;
    Enemy *temp_r3_1850;
    Enemy *temp_r3_1860;
    u32 var_r4_1862;
    u8 var_r30_1745;
    u8 var_r30_1816;
    u8 var_r5_1781;

    ActivateIfInactive();
    temp_r29_1744 = this->unkC;
    var_r30_1745 = 0;
    if (((Character *) temp_r29_1744)->HasAnimFinished() != 0) {
        temp_r4_1750 = temp_r29_1744->unkA50;
        if ((temp_r4_1750 != NULL) && ((u32) temp_r4_1750->unk0 == (u32) M2C_FIELD(temp_r29_1744->unk630, u32 *, 0x20))) {
            var_r30_1745 = 1;
        }
    }
    if (var_r30_1745 != 0) {
        temp_r3_1762 = this->unkC;
        if ((s32) temp_r3_1762->unk110.unk16C > 0) {
            temp_r4_1766 = temp_r3_1762->unkA50;
            temp_r3_1762->SetAnim(temp_r4_1766, (AnimTransition *) &temp_r4_1766->unk40, 0.15f, 0U);
        } else {
            temp_r4_1773 = temp_r3_1762->unkA50;
            temp_r3_1762->SetAnim(temp_r4_1773, (AnimTransition *) &temp_r4_1773->unk20, 0.15f, 0U);
        }
    } else {
        temp_r29_1780 = this->unkC;
        var_r5_1781 = 0;
        temp_r4_1782 = temp_r29_1780->unkA50;
        if ((temp_r4_1782 != NULL) && ((u32) temp_r4_1782->unk20 == (u32) M2C_FIELD(temp_r29_1780->unk630, u32 *, 0x20))) {
            var_r5_1781 = 1;
        }
        if (var_r5_1781 != 0) {
            if ((temp_r29_1780->unkAB0 - temp_r29_1780->unk588.unk4) > 1500.0f) {
                this->unk8 = 2;
            } else if ((s32) temp_r29_1780->unk110.unk16C > 0) {
                temp_r4_1807 = temp_r29_1780->unkA50;
                temp_r29_1780->SetAnim(temp_r4_1807, (AnimTransition *) &temp_r4_1807->unk40, 0.15f, 0U);
            }
        } else {
            var_r30_1816 = 0;
            if (((Character *) temp_r29_1780)->HasAnimFinished() != 0) {
                temp_r4_1820 = temp_r29_1780->unkA50;
                if ((temp_r4_1820 != NULL) && ((u32) temp_r4_1820->unk40 == (u32) M2C_FIELD(temp_r29_1780->unk630, u32 *, 0x20))) {
                    var_r30_1816 = 1;
                }
            }
            if (var_r30_1816 != 0) {
                this->unk8 = 2;
            }
        }
    }
    temp_r3_1835 = this->unkC;
    if ((((u8) temp_r3_1835->unkB09 >> 2U) & 1) && ((temp_r3_1835->unkAB0 - temp_r3_1835->unk588.unk4) > 4000.0f)) {
        this->unk8 = 2;
    }
    sp8 = 0;
    temp_r3_1850 = this->unkC;
    if (((u8) temp_r3_1850->unkA38->unk121 != 0) && (temp_r3_1850->InWaterVolume(temp_r3_1850->unk588, &sp8) != 0)) {
        temp_r3_1860 = this->unkC;
        var_r4_1862 = 0x4000;
        temp_r3_1860->unkB08 &= ~8;
        if (sp8 & 1) {
            var_r4_1862 = 0x800;
        }
        this->unkC->DoDeathFx(var_r4_1862);
    }
    return this->unk8;
}
#endif

void EnemyGoal_HitFall::Activate() {
    AnimSequence *temp_r5_1900;
    AnimSequence *temp_r5_1919;
    Enemy *temp_r3_1953;
    Enemy *temp_r3_1958;
    Enemy *temp_r3_1962;
    Enemy *temp_r4_1903;
    Enemy *temp_r4_1907;
    Enemy *temp_r4_1918;
    Enemy *temp_r6_1893;
    u8 var_r7_1898;
    void *temp_r3_1896;

    temp_r6_1893 = this->unkC;
    temp_r3_1896 = temp_r6_1893->unkA38->GetAnimSequence(2, 0x30, temp_r6_1893->unkAE4, NULL);
    var_r7_1898 = 0;
    temp_r5_1900 = this->unkC->unkA50;
    this->unk8 = 0;
    temp_r4_1903 = this->unkC;
    temp_r4_1903->unk6B5 &= ~0x20;
    temp_r4_1907 = this->unkC;
    temp_r4_1907->unk6B5 |= 1;
    if ((temp_r5_1900 != NULL) && ((s32) temp_r5_1900->unk6C == 2) && ((s32) temp_r5_1900->unk68 == 0x2A)) {
        temp_r4_1918 = this->unkC;
        temp_r5_1919 = temp_r4_1918->unkA50;
        if ((temp_r5_1919 != NULL) && ((u32) temp_r5_1919->unk20 == (u32) M2C_FIELD(temp_r4_1918->unk630, u32 *, 0x20))) {
            var_r7_1898 = 1;
        }
        if (var_r7_1898 == 0) {
            goto block_7;
        }
    } else {
block_7:
        if (temp_r3_1896 != NULL) {
            this->unkC->SetAnim((AnimSequenceType) 2, 0x30, 0, 0.15f, 0U, 0U);
        } else {
            this->unkC->SetAnim((AnimSequenceType) 2, 0x2A, 0, 0.15f, 0U, 0U);
        }
    }
    temp_r3_1953 = this->unkC;
    temp_r3_1953->unkA0 = 0.0f;
    temp_r3_1953->unkA4 = 0.0f;
    temp_r3_1953->unkA8 = 0.0f;
    temp_r3_1958 = this->unkC;
    temp_r3_1958->unk598 = 0.0f;
    temp_r3_1958->unk59C = 0.0f;
    temp_r3_1958->unk5A0 = 0.0f;
    temp_r3_1962 = this->unkC;
    if ((s32) temp_r3_1962->unk688 != 2) {
        ((Character *) temp_r3_1962)->SetMovementType((CharacterMoveType) 0);
    }
}

void EnemyGoal_HitAirCombo::Terminate() {
    Enemy *temp_r3_1986;
    Enemy *temp_r3_1990;
    Enemy *temp_r3_1998;
    Enemy *temp_r4_1994;
    Enemy *temp_r5_2005;

    temp_r3_1986 = this->unkC;
    temp_r3_1986->unk6B5 |= 4;
    temp_r3_1990 = this->unkC;
    temp_r3_1990->unk6B5 &= ~2;
    temp_r4_1994 = this->unkC;
    temp_r4_1994->unk5E4 = M2C_FIELD(temp_r4_1994->unk5D8, f32 *, 8);
    temp_r3_1998 = this->unkC;
    if ((u8) temp_r3_1998->unkA38->unk123 != 0) {
        temp_r3_1998->SnapToDirOfHitSource();
        temp_r5_2005 = this->unkC;
        M2C_FIELD(temp_r5_2005, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(temp_r5_2005, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        M2C_FIELD(temp_r5_2005, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r5_2005, f64 *, 0xF0);
        M2C_FIELD(temp_r5_2005, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r5_2005, f64 *, 0xF8);
        temp_r5_2005->unk6B5 |= 0x40;
    }
    this->unkC->EnableBlurFX(0U);
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unkA64'
u8 EnemyGoal_HitAirCombo::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Enemy *temp_r3_2041;
    Enemy *temp_r3_2103;
    Enemy *temp_r3_2124;
    Enemy *temp_r4_2114;
    Enemy *temp_r5_2090;
    Enemy *temp_r7_2149;
    f32 temp_f1_2045;
    f32 temp_f3_2043;
    f32 temp_f4_2048;
    f32 temp_f5_2050;
    f32 temp_f6_2046;
    f32 temp_f7_2044;
    s32 var_r0_2173;
    u32 temp_r0_2088;
    u32 temp_r6_2136;
    u8 temp_r3_2133;
    u8 temp_r4_2066;
    u8 var_r3_2156;
    u8 var_r4_2150;
    void *temp_r5_2151;

    ActivateIfInactive();
    temp_r3_2041 = this->unkC;
    temp_f3_2043 = temp_r3_2041->unkC8;
    temp_f7_2044 = temp_r3_2041->unkD0;
    temp_f1_2045 = temp_r3_2041->unkD8;
    temp_f6_2046 = temp_r3_2041->unkC4;
    temp_f4_2048 = temp_r3_2041->unkC0;
    temp_f5_2050 = temp_r3_2041->unkD4;
    spC = (temp_f1_2045 * temp_f4_2048) - (temp_f7_2044 * temp_f3_2043);
    sp8 = (temp_f5_2050 * temp_f3_2043) - (temp_f1_2045 * temp_f6_2046);
    sp10 = (temp_f7_2044 * temp_f6_2046) - (temp_f5_2050 * temp_f4_2048);
    M2C_FIELD(temp_r3_2041, f64 *, 0xE0) = (f64) sp8;
    M2C_FIELD(temp_r3_2041, f64 *, 0xE8) = (f64) sp10;
    sp18 = (f64) sp8;
    temp_r3_2041->unk6B5 |= 0x40;
    temp_r4_2066 = this->unk14;
    sp20 = (f64) sp10;
    if (!((temp_r4_2066 >> 6U) & 1) && (((u8) this->unkC->unkB0A >> 6U) & 1)) {
        this->unk14 = temp_r4_2066 | 0x40;
        this->unkC->unkA64 = gb.unk30C + 0.75f;
        this->unkC->unkAF4 = 0;
    }
    temp_r0_2088 = ((u8) this->unk14 >> 6U) & 1;
    if ((temp_r0_2088 != 0) && (temp_r5_2090 = this->unkC, ((gb.unk30C >= temp_r5_2090->unkA64) != 0))) {
        temp_r5_2090->unk6B5 |= 4;
        temp_r3_2103 = this->unkC;
        temp_r3_2103->unkB0A &= ~0x40;
        this->unk14 &= ~0x40;
    } else if (temp_r0_2088 != 0) {
        temp_r4_2114 = this->unkC;
        if (temp_r4_2114->unk59C <= 0.0f) {
            temp_r4_2114->unk6B5 &= ~4;
            temp_r3_2124 = this->unkC;
            temp_r3_2124->unk598 = 0.0f;
            temp_r3_2124->unk59C = 0.0f;
            temp_r3_2124->unk5A0 = 0.0f;
        }
    }
    this->unk10 -= gUpdateTimeDelta;
    temp_r3_2133 = this->unk14;
    if (!((temp_r3_2133 >> 6U) & 1)) {
        temp_r6_2136 = (temp_r3_2133 >> 5U) & 1;
        if (((temp_r6_2136 != 0) || (this->unkC->unk68C != 0.0f)) && !(this->unk10 <= 0.0f)) {
            temp_r7_2149 = this->unkC;
            var_r4_2150 = 0;
            temp_r5_2151 = temp_r7_2149->unk630;
            if (((u32) M2C_FIELD(temp_r5_2151, u32 *, 0x2C) >> 1U) & 1) {
                var_r3_2156 = 0;
                if ((M2C_FIELD(temp_r5_2151, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_2151, s32 *, 0x44) > 1)) {
                    var_r3_2156 = 1;
                }
                if (var_r3_2156 != 0) {
                    var_r4_2150 = 1;
                }
            }
            if (var_r4_2150 != 0) {
                var_r0_2173 = 3;
                if (temp_r6_2136 != 0) {
                    var_r0_2173 = 0xA;
                }
                if ((s32) temp_r7_2149->unkAF4 >= var_r0_2173) {
                    goto block_23;
                }
            }
        } else {
block_23:
            this->unk8 = 2;
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HeroInterface'
void EnemyGoal_HitAirCombo::Activate() {
    s8 spD0;
    s32 spCC;
    s32 spC8;
    s32 spC4;
    f32 spC0;
    s32 spBC;
    s8 spBB;
    s8 spBA;
    s16 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    s32 spC;
    f32 sp8;
    AnimSequence *temp_r4_2205;
    Enemy *temp_r3_2204;
    Enemy *temp_r3_2228;
    Enemy *temp_r3_2235;
    Enemy *temp_r3_2239;
    Enemy *temp_r3_2249;
    Enemy *temp_r3_2355;
    Enemy *temp_r3_2364;
    Enemy *temp_r3_2421;
    Enemy *temp_r3_2432;
    Enemy *temp_r3_2477;
    Enemy *temp_r4_2304;
    Enemy *temp_r4_2400;
    Enemy *temp_r4_2405;
    Enemy *temp_r4_2448;
    Enemy *temp_r4_2464;
    Enemy *temp_r5_2339;
    Enemy *temp_r6_2243;
    f32 var_f2_2408;
    f64 temp_f0_2319;
    f64 temp_f3_2310;
    f64 temp_f4_2308;
    s32 temp_r3_2450;
    s32 temp_r3_2466;
    s32 var_r30_2478;
    void *temp_r3_2306;
    void *temp_r4_2341;

    this->unk8 = 0;
    this->unk14 &= ~0x20;
    temp_r3_2204 = this->unkC;
    temp_r4_2205 = temp_r3_2204->unkA50;
    if ((temp_r4_2205 != NULL) && ((s32) temp_r4_2205->unk6C == 2) && ((s32) temp_r4_2205->unk68 == 0x2A)) {
        temp_r3_2204->SetAnim(temp_r4_2205, (AnimTransition *) &temp_r4_2205->unk20, 0.15f, 0U);
    } else {
        temp_r3_2204->SetAnim((AnimSequenceType) 2, 0x2A, 1, 0.15f, 0U, 0U);
    }
    temp_r3_2228 = this->unkC;
    temp_r3_2228->unkB0A &= ~0x40;
    temp_r3_2235 = this->unkC;
    temp_r3_2235->unk6B5 |= 4;
    temp_r3_2239 = this->unkC;
    temp_r3_2239->unk6B5 |= 2;
    temp_r6_2243 = this->unkC;
    temp_r6_2243->unkA0 = 0.0f;
    temp_r6_2243->unkA4 = M2C_FIELD(temp_r6_2243->unk5D8, f32 *, 8);
    temp_r6_2243->unkA8 = 0.0f;
    temp_r3_2249 = this->unkC;
    if ((s32) temp_r3_2249->unkAF4 == 0) {
        this->unk14 &= ~0x80;
        if (this->unkC->unk930 & 0x47F0) {
            this->unk14 |= 0x80;
        }
    } else if (!(((u8) this->unk14 >> 7U) & 1) && (temp_r3_2249->unk930 & 0x47F0)) {
        temp_r3_2249->unkAF4 = 0;
        this->unk14 |= 0x80;
    }
    sp80 = 0.0f;
    sp84 = 0.0f;
    sp88 = 0.0f;
    sp90 = 0.0f;
    sp94 = 0.0f;
    sp28 = 0.0f;
    sp98 = 0.0f;
    spA0 = 0.0f;
    spA4 = 0.0f;
    spA8 = 0.0f;
    spAC = 1.0f;
    spB0 = 0.0f;
    spB4 = 0.0f;
    spB8 = 0;
    spBA = 0;
    spBB = 0;
    spBC = 0;
    spC0 = 3.4028235e38f;
    spC4 = 0;
    spC8 = 0;
    spCC = -1;
    spD0 = 0;
    temp_r4_2304 = this->unkC;
    sp20 = 0.0f;
    temp_r3_2306 = temp_r4_2304->unk8;
    temp_f4_2308 = M2C_FIELD(temp_r3_2306, f64 *, 0x30);
    temp_f3_2310 = M2C_FIELD(temp_r3_2306, f64 *, 0x38);
    sp24 = temp_r4_2304->unkA38->unk16C;
    sp50 = temp_f4_2308;
    sp40 = (f64) sp20;
    sp48 = (f64) sp28;
    sp58 = temp_f3_2310;
    temp_f0_2319 = sp50 - sp40;
    sp10 = temp_f0_2319;
    sp70 = temp_f4_2308;
    sp60 = temp_f0_2319;
    sp18 = (f32) sp58 - (f32) sp48;
    sp78 = temp_f3_2310;
    sp68 = (f64) sp18;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp70), *((MKVector3 *) &sp60), (MKCollisionResult *) &sp80, (MKCollisionMode) 7, 0x0C000000) != 0) {
        temp_r5_2339 = this->unkC;
        temp_r4_2341 = temp_r5_2339->unk8;
        sp30 = M2C_FIELD(temp_r4_2341, f64 *, 0x30);
        sp38 = M2C_FIELD(temp_r4_2341, f64 *, 0x38);
        temp_r5_2339->unk598 = 0.0f;
        temp_r5_2339->unk59C = temp_r5_2339->unkA38->unk16C - ((*(f32 *) ((u8 *) &sp30 + 0x4)) - sp84);
        temp_r5_2339->unk5A0 = 0.0f;
        temp_r3_2355 = this->unkC;
        if (temp_r3_2355->unk930 & 0x47F0) {
            temp_r3_2355->unk59C += 250.0f;
        }
    }
    temp_r3_2364 = this->unkC;
    if (temp_r3_2364->unk930 & 0x200) {
        temp_r3_2364->unk59C *= 0.5f;
    }
    if ((gb.unk0->GetHeroType() == 0) && ((gb.GetSpyro(), ((((KDStateMachine<Spyro> *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x7C))->GetState() == 2) == 0)) || (gb.GetSpyro(), ((((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->IsInMelee() == 0) != 0)) || !(this->unkC->unk930 & 0x100F))) {
        temp_r4_2400 = this->unkC;
        temp_r4_2400->unkAF4 += 1;
    }
    temp_r4_2405 = this->unkC;
    var_f2_2408 = 1.0f;
    temp_r4_2405->unk5E4 = 0.5f * M2C_FIELD(temp_r4_2405->unk5D8, f32 *, 8);
    if (this->unkC->unk930 & 0x47F0) {
        var_f2_2408 = -1.0f;
    }
    this->unk10 = 1.0f;
    temp_r3_2421 = this->unkC;
    sp8 = temp_r3_2421->unk68C;
    spC = (M2C_BITWISE(s32, sp8) & 0x80000000) | 0x3F800000;
    temp_r3_2421->unk68C = var_f2_2408 * (21.99115f * M2C_BITWISE(f32, spC));
    temp_r3_2432 = this->unkC;
    if ((temp_r3_2432->unk930 & 4) && ((s32) temp_r3_2432->unk93C == 1)) {
        temp_r3_2432->unk68C = 0.0f;
        this->unkC->SnapToDirOfHitSource();
        this->unk14 |= 0x20;
    }
    temp_r4_2448 = this->unkC;
    temp_r3_2450 = temp_r4_2448->unkA38->unk1C4;
    if (temp_r3_2450 != 0) {
        KDSound_Play3d(temp_r3_2450, temp_r4_2448->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    }
    this->unkC->EnableBlurFX(1U);
    temp_r4_2464 = this->unkC;
    temp_r3_2466 = temp_r4_2464->unkA38->unk1C0;
    if (temp_r3_2466 != 0) {
        KDSound_Play3d(temp_r3_2466, temp_r4_2464->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    }
    temp_r3_2477 = this->unkC;
    var_r30_2478 = 1;
    if ((temp_r3_2477->unk930 & 2) && ((s32) temp_r3_2477->unk93C == 1)) {
        var_r30_2478 = 0;
    }
    if ((temp_r3_2477->unkAC8 > 0.0f) && ((s32) temp_r3_2477->unkAF4 < 3)) {
        this->unkC->SpawnGems(MKRand_Int(&gViewSeed, 0, 4), var_r30_2478, 1U);
    }
    this->unk14 &= ~0x40;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA1C'
void EnemyGoal_HitKnockdownSlide::Terminate() {
    Character *temp_r3_2525;
    Character *temp_r3_2529;
    Character *temp_r3_2573;
    Character *temp_r3_2579;
    Character *temp_r4_2535;
    Character *temp_r4_2564;
    Character *temp_r4_2584;

    temp_r3_2525 = this->unkC;
    temp_r3_2525->unk6B5 &= ~2;
    temp_r3_2529 = this->unkC;
    temp_r3_2529->unk6B5 &= ~1;
    this->unkC->StopMovement(1U);
    temp_r4_2535 = this->unkC;
loop_2:
    if ((u32) *temp_r4_2535->unkA1C != 0U) {
        temp_r4_2535->unkA1C += 4;
        goto loop_2;
    }
    ((Enemy *) this->unkC)->SetInvulnerableToMeleeAttacks(0U, 1U);
    ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(0U, 1U);
    ((Enemy *) this->unkC)->EnableBlurFX(0U);
    this->unk38 &= ~0x80;
    this->unk38 &= ~0x40;
    temp_r4_2564 = this->unkC;
    if ((s32) temp_r4_2564->unkA58 == (s32) this->unk10) {
        temp_r4_2564->unkA58 = 0;
    }
    KDSound_Stop(&this->unk10);
    temp_r3_2573 = this->unkC;
    if (temp_r3_2573->unkAC8 > 0.0f) {
        ((Enemy *) temp_r3_2573)->ThawIfFrozen();
        temp_r3_2579 = this->unkC;
        ((Enemy *) temp_r3_2579)->SetupEnemyRegion(temp_r3_2579->unk588, 1000.0f);
    }
    temp_r4_2584 = this->unkC;
    if (temp_r4_2584->unkAC8 <= 0.0f) {
        temp_r4_2584->unkB08 |= 8;
    }
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA1C'
u8 EnemyGoal_HitKnockdownSlide::Update() {
    s8 sp66;
    s8 sp65;
    s8 sp64;
    s32 sp60;
    u32 **sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    f32 sp4C;
    f32 sp48;
    f64 sp40;
    f64 sp38;
    Character *sp30;
    s32 sp2C;
    s32 sp28;
    f64 sp20;                                       /* compiler-managed */
    f64 sp18;                                       /* compiler-managed */
    f32 sp10;
    s32 sp8;
    AnimSequence *temp_r4_2684;
    AnimSequence *temp_r4_2727;
    AnimSequence *temp_r4_2742;
    Character *temp_r28_2721;
    Character *temp_r3_2739;
    Character *temp_r3_2839;
    Character *temp_r6_2613;
    Character *temp_r9_2658;
    f32 temp_f3_2847;
    f32 temp_f4_2840;
    f32 temp_f5_2843;
    f32 var_f3_2833;
    f32 var_f4_2757;
    f64 temp_f1_2665;
    f64 temp_f1_2772;
    f64 temp_f1_2778;
    f64 temp_f1_2782;
    f64 temp_f2_2664;
    s32 temp_r3_2618;
    s32 temp_r3_2762;
    s32 temp_r3_2801;
    s32 var_r0_2811;
    u32 **temp_r7_2662;
    u8 temp_r4_2746;
    u8 var_r29_2722;
    u8 var_r31_2614;
    u8 var_r5_2685;
    void *temp_r3_2636;
    void *var_r3_2628;
    void *var_r3_2639;

    ActivateIfInactive();
    temp_r6_2613 = this->unkC;
    var_r31_2614 = 0;
    temp_r3_2618 = temp_r6_2613->unk110.unk170.unk164;
    sp18 = M2C_FIELD(temp_r6_2613, f64 *, 0x598);
    (*(f32 *) ((u8 *) &sp10 + 0xc)) = 0.0f;
    sp20 = M2C_FIELD(temp_r6_2613, f64 *, 0x5A0);
    if (temp_r3_2618 > 0) {
        if (temp_r3_2618 != 0) {
            var_r3_2628 = &temp_r6_2613->unk110.unk170 + ((temp_r3_2618 - 1) * 0x58);
        } else {
            var_r3_2628 = NULL;
        }
        if (((u8) M2C_FIELD(var_r3_2628, u8 *, 0x50) != 0) && (temp_r3_2636 = M2C_FIELD(var_r3_2628, void **, 0x48), ((temp_r3_2636 == NULL) == 0)) && (var_r3_2639 = M2C_FIELD(temp_r3_2636, void **, 8), ((var_r3_2639 == NULL) == 0))) {

        } else {
            var_r3_2639 = NULL;
        }
        if ((var_r3_2639 != NULL) && (M2C_FIELD(M2C_FIELD(var_r3_2639, void **, 0), s32 *, 0xC) & 8)) {
            sp2C = 0;
            temp_r9_2658 = this->unkC;
            sp28 = 4;
            temp_r7_2662 = &temp_r9_2658->unkA1C;
            sp30 = temp_r9_2658;
            temp_f2_2664 = M2C_FIELD(temp_r9_2658, f64 *, 0x588);
            temp_f1_2665 = M2C_FIELD(temp_r9_2658, f64 *, 0x590);
            sp38 = temp_f2_2664;
            sp40 = temp_f1_2665;
            sp48 = 1.0f;
            sp64 = 0;
            sp50 = 1;
            sp58 = 0x4000;
            sp65 = 0;
            sp66 = 0;
            sp54 = -1;
            sp5C = temp_r7_2662;
            sp60 = 0;
            sp4C = 1.0f;
            M2C_FIELD(M2C_FIELD(var_r3_2639, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK, u32 **, M2C_UNK, Character *, f64, f64), 0x2C)(&sp28, 0x4000, 1, temp_r7_2662, 0, temp_r9_2658, temp_f1_2665, temp_f2_2664);
        } else {
            temp_r4_2684 = temp_r6_2613->unkA50;
            var_r5_2685 = 0;
            if ((temp_r4_2684 != NULL) && ((u32) temp_r4_2684->unk40 == (u32) M2C_FIELD(temp_r6_2613->unk630, u32 *, 0x20))) {
                var_r5_2685 = 1;
            }
            if (var_r5_2685 != 0) {
                temp_r6_2613->unk598 = 0.0f;
                this->unkC->unk5A0 = 0.0f;
                this->unk38 &= ~0x80;
                if (!(((u8) this->unk38 >> 6U) & 1)) {
                    KDSound_Play3d(GS_EnemyHitWall, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                    this->unk38 |= 0x40;
                }
            }
        }
    }
    temp_r28_2721 = this->unkC;
    var_r29_2722 = 0;
    if (temp_r28_2721->HasAnimFinished() != 0) {
        temp_r4_2727 = temp_r28_2721->unkA50;
        if ((temp_r4_2727 != NULL) && ((u32) temp_r4_2727->unk0 == (u32) M2C_FIELD(temp_r28_2721->unk630, u32 *, 0x20))) {
            var_r29_2722 = 1;
        }
    }
    if (var_r29_2722 != 0) {
        temp_r3_2739 = this->unkC;
        temp_r4_2742 = temp_r3_2739->unkA50;
        ((Enemy *) temp_r3_2739)->SetAnim(temp_r4_2742, (AnimTransition *) &temp_r4_2742->unk40, 0.15f, 0U);
    }
    temp_r4_2746 = this->unk38;
    if (!((temp_r4_2746 >> 6U) & 1) && (var_f4_2757 = ((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + ((*(f32 *) ((u8 *) &sp10 + 0xc)) * (*(f32 *) ((u8 *) &sp10 + 0xc)))), ((var_f4_2757 > 0.001f) != 0))) {
        temp_r3_2762 = this->unkC->unk110.unk16C;
        this->unk38 = (temp_r4_2746 & ~0x80) | (((u32) (-temp_r3_2762 & ~temp_r3_2762) >> 0x18U) & 0x80);
        if (var_f4_2757 > 0.000001f) {
            if (var_f4_2757 > 0.0f) {
                temp_f1_2772 = __frsqrte(var_f4_2757);
                temp_f1_2778 = 0.5 * temp_f1_2772 * -(((f64) var_f4_2757 * (temp_f1_2772 * temp_f1_2772)) - 3.0);
                temp_f1_2782 = 0.5 * temp_f1_2778 * -(((f64) var_f4_2757 * (temp_f1_2778 * temp_f1_2778)) - 3.0);
                var_f4_2757 = (f32) ((f64) var_f4_2757 * (0.5 * temp_f1_2782 * -(((f64) var_f4_2757 * (temp_f1_2782 * temp_f1_2782)) - 3.0)));
            } else if (var_f4_2757 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2757 = __float_nan;
            } else {
                sp10 = var_f4_2757;
                temp_r3_2801 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_2801) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2811 = 1;
                    } else {
                        var_r0_2811 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2811 = 5;
                    } else {
                        var_r0_2811 = 3;
                    }
                    break;
                default:
                    var_r0_2811 = 4;
                    break;
                }
                if (var_r0_2811 == 1) {
                    var_f4_2757 = __float_nan;
                }
            }
            var_f3_2833 = 1.0f / var_f4_2757;
        } else {
            var_f3_2833 = 0.0f;
        }
        temp_r3_2839 = this->unkC;
        temp_f4_2840 = (*(f32 *) ((u8 *) &sp10 + 0xc)) * var_f3_2833;
        temp_f5_2843 = (f32) sp18 * var_f3_2833;
        temp_f3_2847 = (f32) sp20 * var_f3_2833;
        sp18 = temp_f5_2843;
        (*(f32 *) ((u8 *) &sp10 + 0xc)) = temp_f4_2840;
        sp20 = temp_f3_2847;
        if (((temp_r3_2839->unkC8 * temp_f3_2847) + ((temp_r3_2839->unkC0 * temp_f5_2843) + (temp_r3_2839->unkC4 * temp_f4_2840))) >= 0.0f) {
            temp_r3_2839->unkA0 = 0.0f;
            var_r31_2614 = 1;
            temp_r3_2839->unkA8 = 0.0f;
        }
    } else {
        var_r31_2614 = 1;
        this->unk38 &= ~0x80;
    }
    sp8 = 1;
    ((KDSoundFader *) &this->unk10)->Update(GS_EnemySlideGround, 1U, ((u8) this->unk38 >> 7U) & 1, (MKProp *) this->unkC, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if (((u8) this->unk38 >> 7U) & 1) {
        this->unkC->unkA58 = this->unk10;
    }
    if (var_r31_2614 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA38'
void EnemyGoal_HitKnockdownSlide::Activate() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Character *temp_r3_2916;
    Character *temp_r3_2920;
    Character *temp_r3_3039;
    Character *temp_r3_3044;
    Character *temp_r4_3070;
    Character *temp_r5_2927;
    Character *temp_r5_2942;
    Character *temp_r5_3024;
    f32 temp_f2_3006;
    f32 temp_f30_3011;
    f32 temp_f31_3009;
    f32 var_f30_2978;
    s32 temp_r0_2963;
    s32 temp_r3_2943;
    s32 var_r4_2955;
    s32 var_r6_2961;
    s32 var_r7_2968;
    void *var_r3_2950;

    this->unk8 = 0;
    temp_r3_2916 = this->unkC;
    temp_r3_2916->unk6B5 |= 1;
    temp_r3_2920 = this->unkC;
    if ((u8) M2C_FIELD(temp_r3_2920->unkA38, u8 *, 0x123) != 0) {
        ((Enemy *) temp_r3_2920)->SnapToDirOfHitSource();
        temp_r5_2927 = this->unkC;
        M2C_FIELD(temp_r5_2927, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(temp_r5_2927, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        M2C_FIELD(temp_r5_2927, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r5_2927, f64 *, 0xF0);
        M2C_FIELD(temp_r5_2927, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r5_2927, f64 *, 0xF8);
        temp_r5_2927->unk6B5 |= 0x40;
    }
    temp_r5_2942 = this->unkC;
    temp_r3_2943 = temp_r5_2942->unk110.unk16C;
    if (temp_r3_2943 > 0) {
        if (temp_r3_2943 != 0) {
            var_r3_2950 = temp_r5_2942 + ((temp_r3_2943 - 1) * 0x58) + 0x118;
        } else {
            var_r3_2950 = NULL;
        }
        var_r4_2955 = M2C_FIELD(var_r3_2950, s32 *, 0x44);
    } else {
        var_r4_2955 = 0;
    }
    var_r6_2961 = lit_1069;
    temp_r0_2963 = M2C_FIELD(temp_r5_2942->unkA38, s32 *, 0x118) - 1;
    if (temp_r0_2963 < var_r6_2961) {
        var_r6_2961 = temp_r0_2963;
    }
    var_r7_2968 = lit_1067;
    if (var_r6_2961 > var_r7_2968) {
        var_r7_2968 = var_r6_2961;
    }
    var_f30_2978 = 800.0f;
    if (var_r4_2955 & 0x10008) {
        var_f30_2978 = 500.0f;
    } else if (var_r4_2955 & 0x40) {
        var_f30_2978 = 1300.0f;
    }
    sp10 = -temp_r5_2942->unkC8;
    sp8 = -temp_r5_2942->unkC0;
    temp_f2_3006 = -((0.1f * (f32) var_r7_2968) - 1.0f);
    spC = -temp_r5_2942->unkC4;
    temp_f31_3009 = 1000.0f * temp_r5_2942->unk92C * temp_f2_3006;
    sp50 = (f64) sp10;
    temp_f30_3011 = var_f30_2978 * temp_f2_3006;
    sp48 = (f64) sp8;
    sp28 = sp48 * (f64) temp_f31_3009;
    M2C_FIELD(temp_r5_2942, f64 *, 0x598) = sp28;
    sp30 = (f32) sp50 * temp_f31_3009;
    sp58 = sp28;
    M2C_FIELD(temp_r5_2942, f64 *, 0x5A0) = (f64) sp30;
    temp_r5_3024 = this->unkC;
    sp60 = (f64) sp30;
    sp18 = (f64) M2C_FIELD(temp_r5_3024, f32 *, 0xC0) * (f64) temp_f30_3011;
    M2C_FIELD(temp_r5_3024, f64 *, 0xA0) = sp18;
    sp20 = temp_r5_3024->unkC8 * temp_f30_3011;
    sp38 = sp18;
    M2C_FIELD(temp_r5_3024, f64 *, 0xA8) = (f64) sp20;
    temp_r3_3039 = this->unkC;
    sp40 = (f64) sp20;
    temp_r3_3039->unk6B5 |= 2;
    temp_r3_3044 = this->unkC;
    if ((s32) temp_r3_3044->unk688 != 2) {
        temp_r3_3044->SetMovementType((CharacterMoveType) 0);
    }
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 2, 0x2A, 0, 0.15f, 0U, 0U);
    ((Enemy *) this->unkC)->SetInvulnerableToMeleeAttacks(1U, 1U);
    ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(1U, 1U);
    ((Enemy *) this->unkC)->EnableBlurFX(1U);
    temp_r4_3070 = this->unkC;
loop_20:
    if ((u32) *temp_r4_3070->unkA1C != 0U) {
        temp_r4_3070->unkA1C += 4;
        goto loop_20;
    }
    this->unk38 &= ~0x80;
    this->unk38 &= ~0x40;
    ((KDSoundFader *) &this->unk10)->Init(0.25f, 0.25f);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[5]' to
void EnemyGoal_HitKnockdown::TryTriggerEventCamera(const MKVector3 &arg0) {
    MKCollisionResult sp108;
    M2C_UNK *spCC;
    s32 spC8;
    s32 spC4;
    s32 spC0;
    f32 spB8;
    f32 spB4;
    void *spB0;
    f32 spA8;                                       /* compiler-managed */
    f32 spA4;
    f32 spA0;                                       /* compiler-managed */
    s32 sp9C;
    s32 sp98;
    f64 sp90;
    f64 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    u8 sp14;
    void *sp10;
    s32 spC;
    s32 sp8;
    Enemy *temp_r3_3113;
    Enemy *temp_r3_3129;
    Enemy *temp_r3_3137;
    f32 *temp_r7_3139;
    f32 temp_f1_3136;
    f64 temp_f0_3148;
    f64 temp_f0_3160;
    f64 temp_f1_3251;
    f64 temp_f2_3250;
    void **var_r0_3184;
    void **var_r3_3198;
    void **var_r3_3221;
    void **var_r5_3263;
    void *temp_r3_3248;
    void *temp_r3_3297;
    void *temp_r3_3304;
    void *temp_r4_3120;

    temp_r3_3113 = this->unkC;
    if ((temp_r3_3113->unk928 > 0.0f) && ((void *) this->unk10 == NULL)) {
        temp_r4_3120 = temp_r3_3113->unk634;
        sp10 = temp_r4_3120;
        if (temp_r4_3120 != NULL) {
            sp14 = M2C_FIELD(temp_r4_3120, u8 *, 4);
            M2C_FIELD(temp_r4_3120, u8 *, 4) = 0U;
        }
        temp_r3_3129 = this->unkC;
        temp_f1_3136 = 1.1f * temp_r3_3129->GetCollisionRadius();
        temp_r3_3137 = this->unkC;
        sp40 = 0.0f;
        temp_r7_3139 = temp_r3_3137->unk110.unk460;
        sp38 = 0.0f;
        sp3C = temp_f1_3136;
        sp90 = (f64) sp40;
        sp88 = (f64) sp38;
        temp_f0_3148 = M2C_FIELD(&arg0, f64 *, 0) + sp88;
        sp18 = temp_f0_3148;
        sp58 = temp_f0_3148;
        sp20 = arg0.unk8 + (f32) sp90;
        sp60 = (f64) sp20;
        temp_f0_3160 = M2C_FIELD(temp_r3_3137, f64 *, 0x588) + sp88;
        sp28 = temp_f0_3160;
        sp68 = temp_f0_3160;
        sp30 = temp_r3_3137->unk588.unk8 + (f32) sp90;
        sp70 = (f64) sp30;
        if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp68), *((MKVector3 *) &sp58), M2C_FIELD(temp_r7_3139, f32 *, 0), &sp108, (MKCollisionMode) 7, M2C_FIELD(temp_r7_3139, s32 *, 0x18)) != 0) {
            if ((sp108.unk50 != 0) && (sp108.unk48 != NULL) && (var_r0_3184 = M2C_FIELD(sp108.unk48, void ***, 8), ((var_r0_3184 == NULL) == 0))) {

            } else {
                var_r0_3184 = NULL;
            }
            if (var_r0_3184 != NULL) {
                if ((sp108.unk50 != 0) && (sp108.unk48 != NULL) && (var_r3_3198 = M2C_FIELD(sp108.unk48, void ***, 8), ((var_r3_3198 == NULL) == 0))) {

                } else {
                    var_r3_3198 = NULL;
                }
                if (M2C_FIELD(*var_r3_3198, s32 *, 0xC) & 0x200) {
                    sp7C = 0;
                    sp78 = 0x8B;
                    sp80 = 0;
                    sp84 = 0x3E8;
                    if ((sp108.unk50 != 0) && (sp108.unk48 != NULL) && (var_r3_3221 = M2C_FIELD(sp108.unk48, void ***, 8), ((var_r3_3221 == NULL) == 0))) {

                    } else {
                        var_r3_3221 = NULL;
                    }
                    M2C_FIELD(M2C_FIELD(var_r3_3221, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp78);
                    if (sp80 <= 1) {
                        sp9C = 0;
                        sp98 = 0x8C;
                        spB0 = NULL;
                        spB4 = 0.0f;
                        spA0 = 0.0f;
                        spA4 = 0.0f;
                        spA8 = 0.0f;
                        temp_r3_3248 = M2C_FIELD(sp108.GetProp(), void **, 8);
                        temp_f2_3250 = M2C_FIELD(temp_r3_3248, f64 *, 0x30);
                        temp_f1_3251 = M2C_FIELD(temp_r3_3248, f64 *, 0x38);
                        sp48 = temp_f2_3250;
                        sp50 = temp_f1_3251;
                        spA0 = temp_f2_3250;
                        spA8 = temp_f1_3251;
                        spB8 = 250000.0f;
                        if ((sp108.unk50 != 0) && (sp108.unk48 != NULL) && (var_r5_3263 = M2C_FIELD(sp108.unk48, void ***, 8), ((var_r5_3263 == NULL) == 0))) {

                        } else {
                            var_r5_3263 = NULL;
                        }
                        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, s32, M2C_UNK, f32), 0x94)(gMK, &sp98, 0x10000, 0, M2C_FIELD(var_r5_3263, s32 *, 8) + 0x30, 0, 500.0f);
                        if (spB0 != NULL) {
                            spC4 = 0;
                            spC0 = 0x153;
                            spC8 = 1;
                            spCC = "0.5f";
                            this->unk10 = spB0;
                            temp_r3_3297 = this->unk10;
                            spC = 0;
                            sp8 = 0xB5;
                            M2C_FIELD(M2C_FIELD(temp_r3_3297, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, M2C_UNK, M2C_UNK), 0x2C)(temp_r3_3297, &sp8, 1, 0x153, 0);
                            temp_r3_3304 = this->unk10;
                            Console_Execute(Str_Printf("delay 5.0 (send functionoff %d)", M2C_FIELD(this->unk10, s32 *, 0x14), "0.5f", M2C_FIELD(M2C_FIELD(temp_r3_3304, void **, 0x44), f32 (**)(void *, s32 *), 0x2C)(temp_r3_3304, &spC0)));
                        }
                    }
                }
            }
        }
        if (sp10 != NULL) {
            M2C_FIELD(sp10, u8 *, 4) = sp14;
        }
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void EnemyGoal_HitKnockdown::Terminate() {
    s32 spC;
    s32 sp8;
    Enemy *temp_r3_3343;
    Enemy *temp_r3_3347;
    Enemy *temp_r3_3355;
    Enemy *temp_r3_3359;
    Enemy *temp_r3_3398;
    Enemy *temp_r4_3363;
    Enemy *temp_r4_3389;
    Enemy *temp_r4_3405;
    Enemy *temp_r5_3351;
    void *temp_r3_3416;

    temp_r3_3343 = this->unkC;
    temp_r3_3343->unk6B5 |= 0x20;
    temp_r3_3347 = this->unkC;
    temp_r3_3347->unkA0 = 0.0f;
    temp_r3_3347->unkA4 = 0.0f;
    temp_r3_3347->unkA8 = 0.0f;
    temp_r5_3351 = this->unkC;
    temp_r5_3351->unk5E4 = M2C_FIELD(temp_r5_3351->unk5D8, f32 *, 8);
    temp_r3_3355 = this->unkC;
    temp_r3_3355->unk6B5 &= ~2;
    temp_r3_3359 = this->unkC;
    temp_r3_3359->unk6B5 &= ~1;
    temp_r4_3363 = this->unkC;
loop_2:
    if ((u32) *temp_r4_3363->unkA1C != 0) {
        temp_r4_3363->unkA1C += 4;
        goto loop_2;
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unkC->EnableBlurFX(0U);
    this->unk40 &= ~0x80;
    temp_r4_3389 = this->unkC;
    if ((s32) temp_r4_3389->unkA58 == (s32) this->unk14) {
        temp_r4_3389->unkA58 = 0;
    }
    KDSound_Stop(&this->unk14);
    temp_r3_3398 = this->unkC;
    if (temp_r3_3398->unkAC8 > 0.0f) {
        temp_r3_3398->ThawIfFrozen();
    }
    temp_r4_3405 = this->unkC;
    if (temp_r4_3405->unkAC8 <= 0.0f) {
        temp_r4_3405->unkB08 |= 8;
    }
    temp_r3_3416 = this->unk10;
    if (temp_r3_3416 != NULL) {
        spC = 0;
        sp8 = 0xB4;
        M2C_FIELD(M2C_FIELD(temp_r3_3416, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
u8 EnemyGoal_HitKnockdown::Update() {
    s8 sp236;
    s8 sp235;
    s8 sp234;
    s32 sp230;
    u32 **sp22C;
    s32 sp228;
    s32 sp224;
    s32 sp220;
    f32 sp21C;
    f32 sp218;
    f64 sp210;
    f64 sp208;
    Enemy *sp200;
    s32 sp1FC;
    s32 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    MKVector3 sp1D8;
    f64 sp1D0;                                      /* compiler-managed */
    f64 sp1C8;                                      /* compiler-managed */
    f64 sp1C0;                                      /* compiler-managed */
    f64 sp1B8;                                      /* compiler-managed */
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    MKVector3 sp178;
    f64 sp170;
    f64 sp168;
    MKVector3 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    MKVector3 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
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
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f64 *sp20;
    ContextInfo *sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    AnimSequence *temp_r4_4255;
    AnimSequence *temp_r4_4333;
    ContextInfo *temp_r5_3775;
    Enemy *temp_r30_4327;
    Enemy *temp_r3_3470;
    Enemy *temp_r3_3475;
    Enemy *temp_r3_3599;
    Enemy *temp_r3_3724;
    Enemy *temp_r3_3733;
    Enemy *temp_r3_3741;
    Enemy *temp_r3_3757;
    Enemy *temp_r3_3766;
    Enemy *temp_r3_3771;
    Enemy *temp_r3_3974;
    Enemy *temp_r3_4153;
    Enemy *temp_r3_4183;
    Enemy *temp_r3_4204;
    Enemy *temp_r3_4251;
    Enemy *temp_r3_4314;
    Enemy *temp_r3_4319;
    Enemy *temp_r3_4348;
    Enemy *temp_r4_3455;
    Enemy *temp_r4_3482;
    Enemy *temp_r4_4265;
    Enemy *temp_r5_3632;
    Enemy *temp_r5_3946;
    Enemy *temp_r5_4132;
    Enemy *temp_r5_4178;
    Enemy *temp_r9_3679;
    f32 temp_f0_3494;
    f32 temp_f0_4102;
    f32 temp_f1_3493;
    f32 temp_f1_3855;
    f32 temp_f1_3949;
    f32 temp_f1_4101;
    f32 temp_f2_3948;
    f32 temp_f31_4110;
    f32 temp_f3_3496;
    f32 temp_f3_3950;
    f32 temp_f4_3942;
    f32 temp_f5_3940;
    f32 temp_f6_3939;
    f32 var_f29_4024;
    f32 var_f3_4091;
    f32 var_f4_3861;
    f32 var_f5_3529;
    f32 var_f5_3868;
    f32 var_f6_3471;
    f64 temp_f0_3514;
    f64 temp_f0_4227;
    f64 temp_f0_4269;
    f64 temp_f0_4281;
    f64 temp_f1_3702;
    f64 temp_f1_3873;
    f64 temp_f1_3879;
    f64 temp_f1_3883;
    f64 temp_f1_4030;
    f64 temp_f1_4036;
    f64 temp_f1_4040;
    f64 temp_f2_3534;
    f64 temp_f2_3540;
    f64 temp_f2_3544;
    f64 temp_f2_3701;
    f64 temp_f5_3515;
    s32 temp_r3_3563;
    s32 temp_r3_3644;
    s32 temp_r3_3902;
    s32 temp_r3_4059;
    s32 temp_r4_3776;
    s32 var_r0_3573;
    s32 var_r0_3912;
    s32 var_r0_4069;
    s32 var_r28_3635;
    s32 var_r30_3633;
    s32 var_r7_3677;
    u32 var_r0_3793;
    u8 var_r28_4328;
    void **var_r3_3817;
    void *temp_r3_3658;
    void *temp_r3_3790;
    void *temp_r3_3814;
    void *temp_r4_3643;
    void *var_r3_3650;
    void *var_r3_3661;
    void *var_r3_3782;
    void *var_r3_3806;
    void *var_r4_3835;

    ActivateIfInactive();
    temp_r4_3455 = this->unkC;
    if ((((u8) temp_r4_3455->unk6B5 >> 1U) & 1) && ((s32) temp_r4_3455->unk110.unk16C <= 0) && (temp_r4_3455->unk59C == 0.0f)) {
        temp_r4_3455->unk59C = M2C_FIELD(temp_r4_3455->unk5D8, f32 *, 8);
    }
    temp_r3_3470 = this->unkC;
    var_f6_3471 = 0.0f;
    temp_r3_3470->unk90 = 0.0f;
    temp_r3_3470->unk94 = 0.0f;
    temp_r3_3470->unk98 = 0.0f;
    temp_r3_3475 = this->unkC;
    temp_r3_3475->unk80 = 0.0f;
    temp_r3_3475->unk84 = 0.0f;
    temp_r3_3475->unk88 = 0.0f;
    if (!(((u8) this->unk40 >> 4U) & 1)) {
        temp_r4_3482 = this->unkC;
        if (((u8) temp_r4_3482->unk6B5 >> 1U) & 1) {
            if ((gb.unk30C >= this->unk3C) || (temp_f1_3493 = temp_r4_3482->unk598, temp_f0_3494 = temp_r4_3482->unk59C, temp_f3_3496 = temp_r4_3482->unk5A0, ((((temp_f3_3496 * temp_f3_3496) + ((temp_f1_3493 * temp_f1_3493) + (temp_f0_3494 * temp_f0_3494))) < 0.001f) != 0))) {
                this->unk40 |= 0x10;
            } else if ((s32) temp_r4_3482->unk110.unk16C > 0) {
                temp_f0_3514 = (f64) M2C_FIELD(temp_r4_3482, f32 *, 0x598);
                temp_f5_3515 = (f64) M2C_FIELD(temp_r4_3482, f32 *, 0x5A0);
                spD8 = temp_f0_3514;
                (*(f32 *) ((u8 *) &spD8 + 0x4)) = 0.0f;
                sp1A0 = temp_f5_3515;
                sp198 = temp_f0_3514;
                spE0 = temp_f5_3515;
                var_f5_3529 = ((f32) sp1A0 * (f32) sp1A0) + (((f32) sp198 * (f32) sp198) + ((*(f32 *) ((u8 *) &sp198 + 0x4)) * (*(f32 *) ((u8 *) &sp198 + 0x4))));
                if (var_f5_3529 > 1e-12f) {
                    if (var_f5_3529 > 0.0f) {
                        temp_f2_3534 = __frsqrte(var_f5_3529);
                        temp_f2_3540 = 0.5 * temp_f2_3534 * -(((f64) var_f5_3529 * (temp_f2_3534 * temp_f2_3534)) - 3.0);
                        temp_f2_3544 = 0.5 * temp_f2_3540 * -(((f64) var_f5_3529 * (temp_f2_3540 * temp_f2_3540)) - 3.0);
                        var_f5_3529 = (f32) ((f64) var_f5_3529 * (0.5 * temp_f2_3544 * -(((f64) var_f5_3529 * (temp_f2_3544 * temp_f2_3544)) - 3.0)));
                    } else if (var_f5_3529 < M2C_BITWISE(f32, 0.0)) {
                        var_f5_3529 = __float_nan;
                    } else {
                        sp18 = var_f5_3529;
                        temp_r3_3563 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                        switch (temp_r3_3563) {     /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_3573 = 1;
                            } else {
                                var_r0_3573 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_3573 = 5;
                            } else {
                                var_r0_3573 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_3573 = 4;
                            break;
                        }
                        if (var_r0_3573 == 1) {
                            var_f5_3529 = __float_nan;
                        }
                    }
                    var_f6_3471 = 1.0f / var_f5_3529;
                }
                temp_r3_3599 = this->unkC;
                spCC = (*(f32 *) ((u8 *) &sp198 + 0x4)) * var_f6_3471;
                spC8 = (f32) sp198 * var_f6_3471;
                spD0 = (f32) sp1A0 * var_f6_3471;
                sp1E8 = (f64) spC8;
                sp1F0 = (f64) spD0;
                if ((((f32) sp1F0 * temp_r3_3599->unkC8) + (((f32) sp1E8 * temp_r3_3599->unkC0) + ((*(f32 *) ((u8 *) &sp1E8 + 0x4)) * temp_r3_3599->unkC4))) >= 0.0f) {
                    this->unk40 |= 0x10;
                }
            }
        }
    }
    if (!(((u8) this->unk40 >> 4U) & 1)) {
        temp_r5_3632 = this->unkC;
        var_r30_3633 = 0;
        var_r28_3635 = 0;
        sp1C = M2C_FIELD(&lit_961, ContextInfo **, 0);
        sp20 = M2C_FIELD(&lit_961, f64 **, 4);
        sp1C = &temp_r5_3632->unk110.unk170;
        sp20 = &temp_r5_3632->unk110.unk8;
        do {
            temp_r4_3643 = *(&sp1C + var_r28_3635);
            temp_r3_3644 = M2C_FIELD(temp_r4_3643, s32 *, 0x164);
            if (temp_r3_3644 > 0) {
                if (temp_r3_3644 != 0) {
                    var_r3_3650 = ((u8 *) temp_r4_3643) + ((temp_r3_3644 - 1) * 0x58);
                } else {
                    var_r3_3650 = NULL;
                }
                if (((u8) M2C_FIELD(var_r3_3650, u8 *, 0x50) != 0) && (temp_r3_3658 = M2C_FIELD(var_r3_3650, void **, 0x48), ((temp_r3_3658 == NULL) == 0)) && (var_r3_3661 = M2C_FIELD(temp_r3_3658, void **, 8), ((var_r3_3661 == NULL) == 0))) {

                } else {
                    var_r3_3661 = NULL;
                }
                if ((var_r3_3661 != NULL) && (M2C_FIELD(M2C_FIELD(var_r3_3661, void **, 0), s32 *, 0xC) & 8)) {
                    sp1FC = 0;
                    var_r7_3677 = 1;
                    temp_r9_3679 = this->unkC;
                    if (((u8) this->unk40 >> 6U) & 1) {
                        var_r7_3677 = 8;
                    }
                    sp200 = temp_r9_3679;
                    sp1F8 = 4;
                    temp_f2_3701 = M2C_FIELD(temp_r9_3679, f64 *, 0x588);
                    temp_f1_3702 = M2C_FIELD(temp_r9_3679, f64 *, 0x590);
                    sp208 = temp_f2_3701;
                    sp210 = temp_f1_3702;
                    sp218 = (f32) temp_r9_3679->unkA38->unk118;
                    sp234 = 0;
                    sp220 = var_r7_3677;
                    sp228 = 0x4000;
                    sp235 = 0;
                    sp236 = 0;
                    sp224 = -1;
                    sp22C = &temp_r9_3679->unkA1C;
                    sp230 = 0;
                    sp21C = 1.0f;
                    M2C_FIELD(M2C_FIELD(var_r3_3661, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK, f64, f64), 0x2C)(&sp1F8, 0x4000, 0, temp_f1_3702, temp_f2_3701);
                    this->unkC->unk598 = 0.0f;
                    this->unkC->unk5A0 = 0.0f;
                    temp_r3_3724 = this->unkC;
                    temp_r3_3724->unkA0 = 0.0f;
                    temp_r3_3724->unkA4 = 0.0f;
                    temp_r3_3724->unkA8 = 0.0f;
                }
            }
            var_r30_3633 += 1;
            var_r28_3635 += 4;
        } while (var_r30_3633 < 2);
        temp_r3_3733 = this->unkC;
        if (!(((u8) temp_r3_3733->unk6B5 >> 1U) & 1)) {
            if (GetPushOutWallNormal(temp_r3_3733, &sp1D8) != 0) {
                temp_r3_3741 = this->unkC;
                sp178.operator*(temp_r3_3741->GetCollisionHeight());
                sp68 = sp178 * 5.28426686e-315;
                temp_r3_3757 = this->unkC;
                sp188 = sp68;
                sp70 = sp178.unk8 * 1.5f;
                M2C_FIELD(temp_r3_3757, f32 *, 0xA0) = sp68;
                sp190 = (f64) sp70;
                M2C_FIELD(temp_r3_3757, f32 *, 0xA8) = (f64) sp70;
            } else {
                temp_r3_3766 = this->unkC;
                temp_r3_3766->unkA0 = 0.0f;
                temp_r3_3766->unkA8 = 0.0f;
            }
        }
        temp_r3_3771 = this->unkC;
        if (((u8) temp_r3_3771->unk6B5 >> 1U) & 1) {
            temp_r5_3775 = &temp_r3_3771->unk110.unk170;
            temp_r4_3776 = temp_r3_3771->unk110.unk170.unk164;
            if (temp_r4_3776 > 0) {
                if (temp_r4_3776 != 0) {
                    var_r3_3782 = temp_r5_3775 + ((temp_r4_3776 - 1) * 0x58);
                } else {
                    var_r3_3782 = NULL;
                }
                if (((u8) M2C_FIELD(var_r3_3782, u8 *, 0x50) != 0) && (temp_r3_3790 = M2C_FIELD(var_r3_3782, void **, 0x48), ((temp_r3_3790 == NULL) == 0)) && (var_r0_3793 = M2C_FIELD(temp_r3_3790, u32 *, 8), ((var_r0_3793 == 0U) == 0))) {

                } else {
                    var_r0_3793 = 0U;
                }
                if (var_r0_3793 != 0U) {
                    if (temp_r4_3776 != 0) {
                        var_r3_3806 = temp_r5_3775 + ((temp_r4_3776 - 1) * 0x58);
                    } else {
                        var_r3_3806 = NULL;
                    }
                    if (((u8) M2C_FIELD(var_r3_3806, u8 *, 0x50) != 0) && (temp_r3_3814 = M2C_FIELD(var_r3_3806, void **, 0x48), ((temp_r3_3814 == NULL) == 0)) && (var_r3_3817 = M2C_FIELD(temp_r3_3814, void ***, 8), ((var_r3_3817 == NULL) == 0))) {

                    } else {
                        var_r3_3817 = NULL;
                    }
                    if ((s32) ((M2C_FIELD(*var_r3_3817, s32 *, 0xC) & 8) | 0x40) == 0) {
                        goto block_72;
                    }
                } else {
block_72:
                    if (temp_r4_3776 != 0) {
                        var_r4_3835 = temp_r5_3775 + ((temp_r4_3776 - 1) * 0x58);
                    } else {
                        var_r4_3835 = NULL;
                    }
                    sp1C8 = M2C_FIELD(var_r4_3835, f64 *, 0x10);
                    sp1D0 = M2C_FIELD(var_r4_3835, f64 *, 0x18);
                    temp_f1_3855 = ((f32) sp1D0 * MKVector3::up.unk8) + (((f32) sp1C8 * MKVector3::up.unk0) + ((*(f32 *) ((u8 *) &sp1B0 + 0x1c)) * MKVector3::up.unk4));
                    if ((temp_f1_3855 < 0.25f) && (temp_f1_3855 > -0.25f)) {
                        var_f4_3861 = 0.0f;
                        (*(f32 *) ((u8 *) &sp1B0 + 0x1c)) = 0.0f;
                        var_f5_3868 = ((f32) sp1D0 * (f32) sp1D0) + (((f32) sp1C8 * (f32) sp1C8) + (0.0f * 0.0f));
                        if (var_f5_3868 > 0.000001f) {
                            if (var_f5_3868 > 0.0f) {
                                temp_f1_3873 = __frsqrte(var_f5_3868);
                                temp_f1_3879 = 0.5 * temp_f1_3873 * -(((f64) var_f5_3868 * (temp_f1_3873 * temp_f1_3873)) - 3.0);
                                temp_f1_3883 = 0.5 * temp_f1_3879 * -(((f64) var_f5_3868 * (temp_f1_3879 * temp_f1_3879)) - 3.0);
                                var_f5_3868 = (f32) ((f64) var_f5_3868 * (0.5 * temp_f1_3883 * -(((f64) var_f5_3868 * (temp_f1_3883 * temp_f1_3883)) - 3.0)));
                            } else if (var_f5_3868 < M2C_BITWISE(f32, 0.0)) {
                                var_f5_3868 = __float_nan;
                            } else {
                                sp14 = var_f5_3868;
                                temp_r3_3902 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                                switch (temp_r3_3902) { /* switch 2; irregular */
                                case 0x7F800000:    /* switch 2 */
                                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                        var_r0_3912 = 1;
                                    } else {
                                        var_r0_3912 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 2 */
                                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                        var_r0_3912 = 5;
                                    } else {
                                        var_r0_3912 = 3;
                                    }
                                    break;
                                default:            /* switch 2 */
                                    var_r0_3912 = 4;
                                    break;
                                }
                                if (var_r0_3912 == 1) {
                                    var_f5_3868 = __float_nan;
                                }
                            }
                            var_f4_3861 = 1.0f / var_f5_3868;
                        }
                        temp_f6_3939 = (f32) sp1C8 * var_f4_3861;
                        temp_f5_3940 = (*(f32 *) ((u8 *) &sp1B0 + 0x1c)) * var_f4_3861;
                        temp_f4_3942 = (f32) sp1D0 * var_f4_3861;
                        sp1C8 = temp_f6_3939;
                        (*(f32 *) ((u8 *) &sp1B0 + 0x1c)) = temp_f5_3940;
                        sp1D0 = temp_f4_3942;
                        temp_r5_3946 = this->unkC;
                        temp_f2_3948 = temp_r5_3946->unk598;
                        temp_f1_3949 = temp_r5_3946->unk59C;
                        temp_f3_3950 = temp_r5_3946->unk5A0;
                        if (((temp_f3_3950 * temp_f3_3950) + ((temp_f2_3948 * temp_f2_3948) + (temp_f1_3949 * temp_f1_3949))) < 2500.0f) {
                            if ((s32) temp_r5_3946->unk110.unk16C <= 0) {
                                temp_r5_3946->unk59C += M2C_FIELD(temp_r5_3946->unk5D8, f32 *, 8);
                            }
                            sp58 = (f64) sp1C8 * 5.634608575e-315;
                            temp_r3_3974 = this->unkC;
                            sp168 = sp58;
                            sp60 = sp1D0 * 500.0f;
                            M2C_FIELD(temp_r3_3974, f32 *, 0xA0) = sp58;
                            M2C_FIELD(temp_r3_3974, f32 *, 0xA8) = (f64) sp60;
                            sp170 = (f64) sp60;
                            if (!(((u8) this->unkC->unk6B5 >> 1U) & 1)) {
                                this->unk40 |= 0x10;
                            }
                        } else if (((temp_r5_3946->unkC8 * temp_f4_3942) + ((temp_r5_3946->unkC0 * temp_f6_3939) + (temp_r5_3946->unkC4 * temp_f5_3940))) > 0.0f) {
                            KDMath_GetReflectedVector(sp158, *((MKVector3 *) &temp_r5_3946->unk598));
                            spB8 = -M2C_BITWISE(f32, sp158);
                            spBC = -sp158.unk4;
                            spC0 = -sp158.unk8;
                            sp1B8 = (f64) spB8;
                            sp1C0 = (f64) spC0;
                            var_f29_4024 = ((f32) sp1C0 * (f32) sp1C0) + (((f32) sp1B8 * (f32) sp1B8) + ((*(f32 *) ((u8 *) &sp1B0 + 0xc)) * (*(f32 *) ((u8 *) &sp1B0 + 0xc))));
                            if (var_f29_4024 > 0.000001f) {
                                if (var_f29_4024 > 0.0f) {
                                    temp_f1_4030 = __frsqrte(var_f29_4024);
                                    temp_f1_4036 = 0.5 * temp_f1_4030 * -(((f64) var_f29_4024 * (temp_f1_4030 * temp_f1_4030)) - 3.0);
                                    temp_f1_4040 = 0.5 * temp_f1_4036 * -(((f64) var_f29_4024 * (temp_f1_4036 * temp_f1_4036)) - 3.0);
                                    var_f29_4024 = (f32) ((f64) var_f29_4024 * (0.5 * temp_f1_4040 * -(((f64) var_f29_4024 * (temp_f1_4040 * temp_f1_4040)) - 3.0)));
                                } else if (var_f29_4024 < M2C_BITWISE(f32, 0.0)) {
                                    var_f29_4024 = __float_nan;
                                } else {
                                    sp10 = var_f29_4024;
                                    temp_r3_4059 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                                    switch (temp_r3_4059) { /* switch 3; irregular */
                                    case 0x7F800000: /* switch 3 */
                                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                            var_r0_4069 = 1;
                                        } else {
                                            var_r0_4069 = 2;
                                        }
                                        break;
                                    case 0x0:       /* switch 3 */
                                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                            var_r0_4069 = 5;
                                        } else {
                                            var_r0_4069 = 3;
                                        }
                                        break;
                                    default:        /* switch 3 */
                                        var_r0_4069 = 4;
                                        break;
                                    }
                                    if (var_r0_4069 == 1) {
                                        var_f29_4024 = __float_nan;
                                    }
                                }
                                var_f3_4091 = 1.0f / var_f29_4024;
                            } else {
                                var_f3_4091 = 0.0f;
                                var_f29_4024 = 0.0f;
                            }
                            temp_f1_4101 = (*(f32 *) ((u8 *) &sp1B0 + 0xc)) * var_f3_4091;
                            temp_f0_4102 = (f32) sp1C0 * var_f3_4091;
                            sp1B8 = (f32) sp1B8 * var_f3_4091;
                            (*(f32 *) ((u8 *) &sp1B0 + 0xc)) = temp_f1_4101;
                            sp1C0 = temp_f0_4102;
                            temp_f31_4110 = ((MKVector3 *) &this->unkC->unkA0)->Magnitude();
                            sp28 = -sp1B8;
                            sp2C = -temp_f1_4101;
                            sp30 = -temp_f0_4102;
                            sp138 = (f64) sp28;
                            sp140 = (f64) sp30;
                            sp48 = sp138 * (f64) temp_f31_4110;
                            temp_r5_4132 = this->unkC;
                            sp50 = (f32) sp140 * temp_f31_4110;
                            M2C_FIELD(temp_r5_4132, f32 *, 0xA0) = sp48;
                            M2C_FIELD(temp_r5_4132, f32 *, 0xA8) = (f64) sp50;
                            sp148 = sp48;
                            this->unkC->unkA4 = 0.0f;
                            sp150 = (f64) sp50;
                            (*(f32 *) ((u8 *) &sp1B0 + 0xc)) = -0.5f;
                            sp118.operator*(var_f29_4024);
                            sp38 = sp118 * 5.24282163e-315;
                            temp_r3_4153 = this->unkC;
                            sp128 = sp38;
                            sp40 = sp118.unk8 * 0.75f;
                            M2C_FIELD(temp_r3_4153, f32 *, 0x598) = sp38;
                            M2C_FIELD(temp_r3_4153, f32 *, 0x5A0) = (f64) sp40;
                            sp130 = (f64) sp40;
                            if (!(((u8) this->unk40 >> 5U) & 1)) {
                                KDSound_Play3d(GS_EnemyHitWall, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                                this->unk40 |= 0x20;
                            }
                        }
                    } else {
                        temp_r5_4178 = this->unkC;
                        temp_r5_4178->unk5E4 = M2C_FIELD(temp_r5_4178->unk5D8, f32 *, 8);
                        temp_r3_4183 = this->unkC;
                        temp_r3_4183->unk6B5 &= ~2;
                        if (!(((u8) this->unk40 >> 5U) & 1)) {
                            KDSound_Play3d(GS_EnemyHitWall, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                            this->unk40 |= 0x20;
                        }
                    }
                }
            }
        }
    }
    temp_r3_4204 = this->unkC;
    if ((((u8) temp_r3_4204->unkB09 >> 2U) & 1) && ((temp_r3_4204->unkAB0 - temp_r3_4204->unk588.unk4) > 500.0f)) {
        spA8 = 0.0f;
        spAC = 50.0f;
        spB0 = 0.0f;
        spF8 = (f64) spA8;
        sp100 = (f64) spB0;
        temp_f0_4227 = M2C_FIELD(temp_r3_4204, f64 *, 0x588) + spF8;
        sp98 = temp_f0_4227;
        sp108 = temp_f0_4227;
        spA0 = temp_r3_4204->unk588.unk8 + (f32) sp100;
        sp110 = (f64) spA0;
        if (MKCollision_GetGroundPoint(*((MKVector3 *) &sp108), 550.0f, NULL, M2C_FIELD(temp_r3_4204->unk110.unk460, s32 *, 0x18) | 0x0C000000, 0, NULL, (MKCollisionMode) 7) == 0) {
            this->unk8 = 2;
        }
    }
    temp_r3_4251 = this->unkC;
    if ((s32) temp_r3_4251->unk110.unk16C > 0) {
        temp_r4_4255 = temp_r3_4251->unkA50;
        if ((u32) M2C_FIELD(temp_r3_4251->unk630, u32 *, 0x20) != (u32) temp_r4_4255->unk40) {
            temp_r3_4251->SetAnim(temp_r4_4255, (AnimTransition *) &temp_r4_4255->unk40, 0.15f, 0U);
            temp_r4_4265 = this->unkC;
            temp_f0_4269 = (f64) M2C_FIELD(temp_r4_4265, f32 *, 0x598) * 5.180653787e-315;
            sp88 = temp_f0_4269;
            spE8 = temp_f0_4269;
            sp90 = temp_r4_4265->unk5A0 * 0.25f;
            spF0 = (f64) sp90;
            temp_f0_4281 = M2C_FIELD(temp_r4_4265, f64 *, 0x588) + temp_f0_4269;
            sp78 = temp_f0_4281;
            sp1A8 = temp_f0_4281;
            sp80 = temp_r4_4265->unk588.unk8 + (f32) spF0;
            sp1B0 = (f64) sp80;
            TryTriggerEventCamera(*((MKVector3 *) &sp1A8));
        }
        this->unk40 |= 0x80;
    } else {
        this->unk40 &= ~0x80;
    }
    if ((((u8) this->unk40 >> 4U) & 1) || !(((u8) this->unkC->unk6B5 >> 1U) & 1)) {
        temp_r3_4314 = this->unkC;
        temp_r3_4314->unkA0 = 0.0f;
        temp_r3_4314->unkA4 = 0.0f;
        temp_r3_4314->unkA8 = 0.0f;
        temp_r3_4319 = this->unkC;
        if ((s32) temp_r3_4319->unk110.unk16C > 0) {
            temp_r3_4319->unk598 = 0.0f;
            temp_r3_4319->unk59C = 0.0f;
            temp_r3_4319->unk5A0 = 0.0f;
        }
        temp_r30_4327 = this->unkC;
        var_r28_4328 = 0;
        if (((Character *) temp_r30_4327)->HasAnimFinished() != 0) {
            temp_r4_4333 = temp_r30_4327->unkA50;
            if ((temp_r4_4333 != NULL) && ((u32) temp_r4_4333->unk40 == (u32) M2C_FIELD(temp_r30_4327->unk630, u32 *, 0x20))) {
                var_r28_4328 = 1;
            }
        }
        if (var_r28_4328 != 0) {
            this->unk8 = 2;
            temp_r3_4348 = this->unkC;
            temp_r3_4348->SetupEnemyRegion(temp_r3_4348->unk588, 1000.0f);
        }
    }
    sp8 = 1;
    ((KDSoundFader *) &this->unk14)->Update(GS_EnemySlideGround, 1U, ((u8) this->unk40 >> 7U) & 1, (MKProp *) this->unkC, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if (((u8) this->unk40 >> 7U) & 1) {
        this->unkC->unkA58 = this->unk14;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void EnemyGoal_HitKnockdown::Activate() {
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    MKVector3 sp138;
    MKVector3 sp128;
    MKVector3 sp118;
    f64 sp110;
    f64 sp108;
    MKVector3 spF8;
    f64 spF0;
    f64 spE8;
    MKVector3 spD8;
    MKVector3 spC8;
    MKVector3 spB8;
    f64 spB0;
    f64 spA8;
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    AnimSequence *temp_r31_4496;
    AnimSequence *temp_r3_4476;
    Enemy *temp_r31_4475;
    Enemy *temp_r3_4494;
    Enemy *temp_r3_4524;
    Enemy *temp_r3_4528;
    Enemy *temp_r3_4601;
    Enemy *temp_r3_4610;
    Enemy *temp_r3_4672;
    Enemy *temp_r3_4687;
    Enemy *temp_r4_4465;
    Enemy *temp_r4_4470;
    Enemy *temp_r4_4548;
    Enemy *temp_r4_4582;
    Enemy *temp_r4_4619;
    Enemy *temp_r4_4653;
    Enemy *temp_r4_4705;
    Enemy *temp_r5_4506;
    Enemy *temp_r5_4723;
    f64 temp_f0_4727;
    f64 temp_f0_4740;
    f64 temp_f0_4752;

    this->unk8 = 0;
    temp_r4_4465 = this->unkC;
    temp_r4_4465->unk6B5 &= ~0x20;
    temp_r4_4470 = this->unkC;
    temp_r4_4470->unk6B5 |= 1;
    ((KDSoundFader *) &this->unk14)->Init(0.25f, 0.25f);
    temp_r31_4475 = this->unkC;
    temp_r3_4476 = temp_r31_4475->unkA50;
    if ((temp_r3_4476 == NULL) || ((s32) temp_r3_4476->unk6C != 2) || ((s32) temp_r3_4476->unk68 != 0x2A)) {
        temp_r31_4475->unkA50 = temp_r31_4475->unkA38->GetAnimSequence(2, 0x2A, temp_r31_4475->unkAE4, NULL);
    }
    temp_r3_4494 = this->unkC;
    temp_r31_4496 = temp_r3_4494->unkA50;
    if (((u8) temp_r3_4494->unkA38->unk123 != 0) && (temp_r3_4494->unk928 > 0.0f)) {
        temp_r3_4494->SnapToDirOfHitSource();
        temp_r5_4506 = this->unkC;
        M2C_FIELD(temp_r5_4506, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(temp_r5_4506, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        M2C_FIELD(temp_r5_4506, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r5_4506, f64 *, 0xF0);
        M2C_FIELD(temp_r5_4506, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r5_4506, f64 *, 0xF8);
        temp_r5_4506->unk6B5 |= 0x40;
    }
    this->unkC->unk68C = 0.0f;
    temp_r3_4524 = this->unkC;
    temp_r3_4524->unk598 = 0.0f;
    temp_r3_4524->unk59C = 0.0f;
    temp_r3_4524->unk5A0 = 0.0f;
    temp_r3_4528 = this->unkC;
    temp_r3_4528->unkA0 = 0.0f;
    temp_r3_4528->unkA4 = 0.0f;
    temp_r3_4528->unkA8 = 0.0f;
    this->unk40 = (this->unk40 & ~0x40) | ((CLZ(0xA - this->unkC->unk938) << 1) & 0x40);
    if (((u8) this->unk40 >> 6U) & 1) {
        this->unkC->SetAnim(temp_r31_4496, (AnimTransition *) &temp_r31_4496->unk20, 0.15f, 0U);
        temp_r4_4548 = this->unkC;
        temp_r4_4548->unk6B5 |= 2;
        this->unkC->unk5E4 = 0.0f;
        sp118.operator*(-fInitialKnockdownForce);
        sp128.operator*(0.75f);
        sp138.operator*(-this->unkC->unk928);
        sp38 = sp138 + M2C_BITWISE(f64, sp128);
        temp_r4_4582 = this->unkC;
        sp148 = sp38;
        sp40 = sp138.unk8 + sp128.unk8;
        M2C_FIELD(temp_r4_4582, f32 *, 0x598) = sp38;
        M2C_FIELD(temp_r4_4582, f32 *, 0x5A0) = (f64) sp40;
        sp150 = (f64) sp40;
        spF8.operator*(this->unkC->unk928);
        sp28 = spF8 * 5.24282163e-315;
        temp_r3_4601 = this->unkC;
        sp108 = sp28;
        sp30 = spF8.unk8 * 0.75f;
        M2C_FIELD(temp_r3_4601, f32 *, 0xA0) = sp28;
        sp110 = (f64) sp30;
        M2C_FIELD(temp_r3_4601, f32 *, 0xA8) = (f64) sp30;
    } else {
        temp_r3_4610 = this->unkC;
        if (temp_r3_4610->unk928 > 0.0f) {
            temp_r3_4610->SetAnim(temp_r31_4496, (AnimTransition *) &temp_r31_4496->unk20, 0.15f, 0U);
            temp_r4_4619 = this->unkC;
            temp_r4_4619->unk6B5 |= 2;
            this->unkC->unk5E4 = 0.0f;
            spB8.operator*(-fInitialKnockdownForce);
            spC8.operator*(1.25f);
            spD8.operator*(-this->unkC->unk928);
            sp18 = spD8 + M2C_BITWISE(f64, spC8);
            temp_r4_4653 = this->unkC;
            spE8 = sp18;
            sp20 = spD8.unk8 + spC8.unk8;
            M2C_FIELD(temp_r4_4653, f32 *, 0x598) = sp18;
            M2C_FIELD(temp_r4_4653, f32 *, 0x5A0) = (f64) sp20;
            spF0 = (f64) sp20;
            sp98.operator*(this->unkC->unk928);
            sp8 = sp98 * 5.24282163e-315;
            temp_r3_4672 = this->unkC;
            spA8 = sp8;
            sp10 = sp98.unk8 * 0.75f;
            M2C_FIELD(temp_r3_4672, f32 *, 0xA0) = sp8;
            spB0 = (f64) sp10;
            M2C_FIELD(temp_r3_4672, f32 *, 0xA8) = (f64) sp10;
        } else {
            temp_r3_4610->SetAnim(temp_r31_4496, (AnimTransition *) &temp_r31_4496->unk40, 0.15f, 0U);
        }
    }
    temp_r3_4687 = this->unkC;
    if ((s32) temp_r3_4687->unk688 != 2) {
        ((Character *) temp_r3_4687)->SetMovementType((CharacterMoveType) 0);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unkC->EnableBlurFX(1U);
    temp_r4_4705 = this->unkC;
loop_16:
    if ((u32) *temp_r4_4705->unkA1C != 0) {
        temp_r4_4705->unkA1C += 4;
        goto loop_16;
    }
    this->unk3C = gb.unk30C + 5.0f;
    temp_r5_4723 = this->unkC;
    temp_f0_4727 = (f64) M2C_FIELD(temp_r5_4723, f32 *, 0xA0) * (f64) gUpdateTimeDelta;
    sp58 = temp_f0_4727;
    sp78 = temp_f0_4727;
    sp60 = temp_r5_4723->unkA8 * gUpdateTimeDelta;
    sp80 = (f64) sp60;
    temp_f0_4740 = M2C_FIELD(temp_r5_4723, f64 *, 0x588) + (f64) M2C_FIELD(temp_r5_4723, f32 *, 0x598);
    sp68 = temp_f0_4740;
    sp88 = temp_f0_4740;
    sp70 = temp_r5_4723->unk588.unk8 + temp_r5_4723->unk5A0;
    sp90 = (f64) sp70;
    temp_f0_4752 = sp88 + temp_f0_4727;
    sp48 = temp_f0_4752;
    sp158 = temp_f0_4752;
    sp50 = (f32) sp90 + (f32) sp80;
    sp160 = (f64) sp50;
    TryTriggerEventCamera(*((MKVector3 *) &sp158));
}
#endif

void EnemyGoal_HitKnockup::Terminate() {
    Enemy *temp_r3_4791;
    Enemy *temp_r3_4795;
    Enemy *temp_r3_4799;
    Enemy *temp_r7_4787;

    temp_r7_4787 = this->unkC;
    temp_r7_4787->unk5E4 = M2C_FIELD(temp_r7_4787->unk5D8, f32 *, 8);
    temp_r3_4791 = this->unkC;
    temp_r3_4791->unk6B5 &= ~2;
    temp_r3_4795 = this->unkC;
    temp_r3_4795->unk6B5 &= ~1;
    temp_r3_4799 = this->unkC;
    temp_r3_4799->unk6B5 |= 4;
    this->unkC->EnableBlurFX(0U);
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unkA64'
u8 EnemyGoal_HitKnockup::Update() {
    f64 spF8;
    f64 spF0;
    MKVector3 spE0;
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
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    AnimSequence *temp_r4_4839;
    AnimSequence *temp_r4_4854;
    AnimSequence *temp_r4_4973;
    ContextInfo *temp_r3_5076;
    Enemy *temp_r29_4833;
    Enemy *temp_r3_4851;
    Enemy *temp_r3_4953;
    Enemy *temp_r3_4965;
    Enemy *temp_r3_4969;
    Enemy *temp_r3_4986;
    Enemy *temp_r3_5038;
    Enemy *temp_r3_5056;
    Enemy *temp_r3_5075;
    Enemy *temp_r4_4940;
    Enemy *temp_r5_4858;
    Enemy *temp_r5_4922;
    f32 temp_f0_5051;
    f32 temp_f28_4865;
    f32 temp_f31_5044;
    f64 temp_f0_4867;
    f64 temp_f0_4877;
    f64 temp_f0_4887;
    f64 temp_f0_4899;
    f64 temp_f0_5009;
    f64 temp_f1_5046;
    f64 temp_f1_5052;
    s32 temp_r4_5077;
    u32 var_r0_5094;
    u8 temp_r4_4926;
    u8 var_r30_4834;
    void *temp_r4_5091;
    void *var_r4_5083;

    ActivateIfInactive();
    temp_r29_4833 = this->unkC;
    var_r30_4834 = 0;
    if (((Character *) temp_r29_4833)->HasAnimFinished() != 0) {
        temp_r4_4839 = temp_r29_4833->unkA50;
        if ((temp_r4_4839 != NULL) && ((u32) temp_r4_4839->unk0 == (u32) M2C_FIELD(temp_r29_4833->unk630, u32 *, 0x20))) {
            var_r30_4834 = 1;
        }
    }
    if (var_r30_4834 != 0) {
        temp_r3_4851 = this->unkC;
        temp_r4_4854 = temp_r3_4851->unkA50;
        temp_r3_4851->SetAnim(temp_r4_4854, (AnimTransition *) &temp_r4_4854->unk20, 0.15f, 0U);
    }
    temp_r5_4858 = this->unkC;
    temp_f28_4865 = M2C_FIELD(temp_r5_4858->unk5D8, f32 *, 8);
    temp_f0_4867 = M2C_FIELD(temp_r5_4858, f64 *, 0xD0) * (f64) fKnockupGravityMultiplier;
    sp70 = temp_f0_4867;
    spB0 = temp_f0_4867;
    sp78 = temp_r5_4858->unkD8 * fKnockupGravityMultiplier;
    spB8 = (f64) sp78;
    temp_f0_4877 = temp_f0_4867 * (f64) temp_f28_4865;
    sp60 = temp_f0_4877;
    spC0 = temp_f0_4877;
    sp68 = (f32) spB8 * temp_f28_4865;
    spC8 = (f64) sp68;
    temp_f0_4887 = temp_f0_4877 * (f64) gUpdateTimeDelta;
    sp50 = temp_f0_4887;
    spD0 = temp_f0_4887;
    sp58 = (f32) spC8 * gUpdateTimeDelta;
    spD8 = (f64) sp58;
    temp_f0_4899 = M2C_FIELD(temp_r5_4858, f64 *, 0xA0) + temp_f0_4887;
    sp40 = temp_f0_4899;
    spF0 = temp_f0_4899;
    sp48 = temp_r5_4858->unkA8 + (f32) spD8;
    spF8 = (f64) sp48;
    if ((((u8) temp_r5_4858->unk6B5 >> 2U) & 1) && (((u8) temp_r5_4858->unkB0A >> 6U) & 1)) {
        temp_r5_4858->unkA64 = gb.unk30C + 0.5f;
    }
    temp_r5_4922 = this->unkC;
    if (!(((u8) temp_r5_4922->unk6B5 >> 2U) & 1)) {
        temp_r4_4926 = temp_r5_4922->unkB0A;
        if (((temp_r4_4926 >> 6U) & 1) && (gb.unk30C >= temp_r5_4922->unkA64)) {
            temp_r5_4922->unkB0A = temp_r4_4926 & ~0x40;
        }
    }
    temp_r4_4940 = this->unkC;
    if ((((u8) temp_r4_4940->unkB0A >> 6U) & 1) && (temp_r4_4940->unk59C <= 0.0f)) {
        temp_r4_4940->unk6B5 &= ~4;
        temp_r3_4953 = this->unkC;
        temp_r3_4953->unk598 = 0.0f;
        temp_r3_4953->unk59C = 0.0f;
        temp_r3_4953->unk5A0 = 0.0f;
    } else {
        temp_r4_4940->unk6B5 |= 4;
        temp_r3_4965 = this->unkC;
        M2C_FIELD(temp_r3_4965, f64 *, 0xA0) = spF0;
        M2C_FIELD(temp_r3_4965, f32 *, 0xA8) = spF8;
    }
    temp_r3_4969 = this->unkC;
    if ((s32) temp_r3_4969->unk110.unk16C > 0) {
        temp_r4_4973 = temp_r3_4969->unkA50;
        if ((u32) M2C_FIELD(temp_r3_4969->unk630, u32 *, 0x20) == (u32) temp_r4_4973->unk20) {
            temp_r3_4969->SetAnim(temp_r4_4973, (AnimTransition *) &temp_r4_4973->unk40, 0.15f, 0U);
            this->unk8 = 2;
        }
    }
    temp_r3_4986 = this->unkC;
    if ((((u8) temp_r3_4986->unkB09 >> 2U) & 1) && ((temp_r3_4986->unkAB0 - temp_r3_4986->unk588.unk4) > 500.0f)) {
        sp30 = 0.0f;
        sp34 = 50.0f;
        sp38 = 0.0f;
        sp90 = (f64) sp30;
        sp98 = (f64) sp38;
        temp_f0_5009 = M2C_FIELD(temp_r3_4986, f64 *, 0x588) + sp90;
        sp20 = temp_f0_5009;
        spA0 = temp_f0_5009;
        sp28 = temp_r3_4986->unk588.unk8 + (f32) sp98;
        spA8 = (f64) sp28;
        if (MKCollision_GetGroundPoint(*((MKVector3 *) &spA0), 550.0f, NULL, M2C_FIELD(temp_r3_4986->unk110.unk460, s32 *, 0x18) | 0x0C000000, 0, NULL, (MKCollisionMode) 7) == 0) {
            this->unk8 = 2;
        }
    }
    if (GetPushOutWallNormal(this->unkC, &spE0) != 0) {
        temp_r3_5038 = this->unkC;
        temp_f31_5044 = 3.5f * temp_r3_5038->GetCollisionHeight();
        temp_f1_5046 = M2C_BITWISE(f64, spE0) * (f64) temp_f31_5044;
        spE0 = temp_f1_5046;
        temp_f0_5051 = spE0.unk8 * temp_f31_5044;
        temp_f1_5052 = temp_f1_5046 * (f64) gUpdateTimeDelta;
        spE0.unk8 = temp_f0_5051;
        sp10 = temp_f1_5052;
        temp_r3_5056 = this->unkC;
        sp18 = temp_f0_5051 * gUpdateTimeDelta;
        sp80 = temp_f1_5052;
        sp88 = (f64) sp18;
        M2C_FIELD(temp_r3_5056, f64 *, 0xA0) = (f64) (M2C_FIELD(temp_r3_5056, f64 *, 0xA0) + sp80);
        temp_r3_5056->unkA8 += (f32) sp88;
    }
    if ((u8) this->unk10 == 0) {
        temp_r3_5075 = this->unkC;
        temp_r3_5076 = &temp_r3_5075->unk110.unk170;
        temp_r4_5077 = temp_r3_5075->unk110.unk170.unk164;
        if (temp_r4_5077 > 0) {
            if (temp_r4_5077 != 0) {
                var_r4_5083 = temp_r3_5076 + ((temp_r4_5077 - 1) * 0x58);
            } else {
                var_r4_5083 = NULL;
            }
            if (((u8) M2C_FIELD(var_r4_5083, u8 *, 0x50) != 0) && (temp_r4_5091 = M2C_FIELD(var_r4_5083, void **, 0x48), ((temp_r4_5091 == NULL) == 0)) && (var_r0_5094 = M2C_FIELD(temp_r4_5091, u32 *, 8), ((var_r0_5094 == 0U) == 0))) {

            } else {
                var_r0_5094 = 0U;
            }
            if ((var_r0_5094 == 0U) && (temp_r3_5076->HitID(1U) != 0)) {
                spC = 0;
                sp8 = 0x145;
                InGame_SystemMessage((MKMessage *) &sp8);
                KDSound_Play3d(GS_Rumble5, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                this->unk10 = 1;
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal type
void EnemyGoal_HitKnockup::Activate() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Enemy *temp_r3_5160;
    Enemy *temp_r3_5169;
    Enemy *temp_r3_5173;
    Enemy *temp_r3_5186;
    Enemy *temp_r3_5193;
    Enemy *temp_r3_5215;
    Enemy *temp_r3_5271;
    Enemy *temp_r3_5275;
    Enemy *temp_r3_5278;
    Enemy *temp_r5_5200;
    Enemy *temp_r7_5250;
    f64 temp_f0_5231;

    this->unk8 = 0;
    temp_r3_5160 = this->unkC;
    temp_r3_5160->unk6B5 |= 1;
    temp_r3_5169 = this->unkC;
    temp_r3_5169->unk6B5 &= ~0x20;
    temp_r3_5173 = this->unkC;
    temp_r3_5173->unk6B5 |= 2;
    this->unkC->unk5E4 = 0.0f;
    this->unkC->unk68C = 0.0f;
    this->unkC->SetAnim((AnimSequenceType) 2, 0x2A, 0, 0.15f, 0U, 0U);
    ((Character *) this->unkC)->StopMovement(1U);
    temp_r3_5186 = this->unkC;
    if ((s32) temp_r3_5186->unk688 != 2) {
        ((Character *) temp_r3_5186)->SetMovementType((CharacterMoveType) 0);
    }
    temp_r3_5193 = this->unkC;
    if ((u8) temp_r3_5193->unkA38->unk123 != 0) {
        temp_r3_5193->SnapToDirOfHitSource();
        temp_r5_5200 = this->unkC;
        M2C_FIELD(temp_r5_5200, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(temp_r5_5200, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        M2C_FIELD(temp_r5_5200, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r5_5200, f64 *, 0xF0);
        M2C_FIELD(temp_r5_5200, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r5_5200, f64 *, 0xF8);
        temp_r5_5200->unk6B5 |= 0x40;
    }
    temp_r3_5215 = this->unkC;
    sp8 = -temp_r3_5215->unkC0;
    spC = -temp_r3_5215->unkC4;
    sp10 = -temp_r3_5215->unkC8;
    sp48 = (f64) sp8;
    sp50 = (f64) sp10;
    temp_f0_5231 = sp48 * 5.53552857e-315;
    sp28 = temp_f0_5231;
    sp58 = temp_f0_5231;
    sp30 = (f32) sp50 * 100.0f;
    sp60 = (f64) sp30;
    M2C_FIELD(temp_r3_5215, f64 *, 0xA0) = (f64) (M2C_FIELD(temp_r3_5215, f64 *, 0xA0) + temp_f0_5231);
    temp_r3_5215->unkA8 += (f32) sp60;
    temp_r7_5250 = this->unkC;
    sp18 = M2C_FIELD(temp_r7_5250, f64 *, 0xD0) * (f64) fInitialKnockupForce;
    M2C_FIELD(temp_r7_5250, f64 *, 0x598) = sp18;
    sp20 = temp_r7_5250->unkD8 * fInitialKnockupForce;
    sp38 = sp18;
    M2C_FIELD(temp_r7_5250, f64 *, 0x5A0) = (f64) sp20;
    sp40 = (f64) sp20;
    this->unkC->unk110.unk16C = 0;
    this->unk10 = 0;
    temp_r3_5271 = this->unkC;
    temp_r3_5271->unkB0A &= ~0x40;
    temp_r3_5275 = this->unkC;
    temp_r3_5275->unkAB0 = temp_r3_5275->unk588.unk4;
    temp_r3_5278 = this->unkC;
    temp_r3_5278->unkB09 |= 4;
    this->unkC->EnableBlurFX(1U);
    this->unkC->unkAF4 = 0;
    KDSound_Play3d(GS_EnemyKnockedUp, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
}
#endif

#if 0 // DRAFT: illegal type
u8 EnemyGoal_HitKnockback::Update() {
    s32 spC;
    s32 sp8;
    Character *temp_r3_5326;
    ContextInfo *temp_r3_5327;
    s32 temp_r4_5328;
    u32 var_r0_5345;
    void *temp_r4_5342;
    void *var_r4_5334;

    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    if ((u8) this->unk10 == 0) {
        temp_r3_5326 = this->unkC;
        temp_r3_5327 = &temp_r3_5326->unk110.unk170;
        temp_r4_5328 = temp_r3_5326->unk110.unk170.unk164;
        if (temp_r4_5328 > 0) {
            if (temp_r4_5328 != 0) {
                var_r4_5334 = temp_r3_5327 + ((temp_r4_5328 - 1) * 0x58);
            } else {
                var_r4_5334 = NULL;
            }
            if (((u8) M2C_FIELD(var_r4_5334, u8 *, 0x50) != 0) && (temp_r4_5342 = M2C_FIELD(var_r4_5334, void **, 0x48), ((temp_r4_5342 == NULL) == 0)) && (var_r0_5345 = M2C_FIELD(temp_r4_5342, u32 *, 8), ((var_r0_5345 == 0U) == 0))) {

            } else {
                var_r0_5345 = 0U;
            }
            if ((var_r0_5345 == 0U) && (temp_r3_5327->HitID(1U) != 0)) {
                spC = 0;
                sp8 = 0x145;
                InGame_SystemMessage((MKMessage *) &sp8);
                this->unk10 = 1;
                KDSound_Play3d(GS_Rumble5, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA38'
void EnemyGoal_HitKnockback::Activate() {
    Character *temp_r3_5394;
    Character *temp_r3_5418;
    Character *temp_r3_5425;
    Character *temp_r5_5432;

    this->unk8 = 0;
    temp_r3_5394 = this->unkC;
    if (((u8) temp_r3_5394->unk6B5 >> 4U) & 1) {
        ((Enemy *) temp_r3_5394)->SetAnim((AnimSequenceType) 2, 0x2E, 0, 0.15f, 0U, 0U);
    } else {
        ((Enemy *) temp_r3_5394)->SetAnim((AnimSequenceType) 2, 0x29, 0, 0.15f, 0U, 0U);
    }
    this->unkC->StopMovement(1U);
    temp_r3_5418 = this->unkC;
    if ((s32) temp_r3_5418->unk688 != 2) {
        temp_r3_5418->SetMovementType((CharacterMoveType) 0);
    }
    temp_r3_5425 = this->unkC;
    if ((u8) M2C_FIELD(temp_r3_5425->unkA38, u8 *, 0x123) != 0) {
        ((Enemy *) temp_r3_5425)->SnapToDirOfHitSource();
        temp_r5_5432 = this->unkC;
        M2C_FIELD(temp_r5_5432, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(temp_r5_5432, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        M2C_FIELD(temp_r5_5432, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r5_5432, f64 *, 0xF0);
        M2C_FIELD(temp_r5_5432, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r5_5432, f64 *, 0xF8);
        temp_r5_5432->unk6B5 |= 0x40;
    }
    this->unk10 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkB02'
void EnemyGoal_HitBurn::Terminate() {
    Character *temp_r4_5465;

    this->unk8 = 1;
    temp_r4_5465 = this->unkC;
    temp_r4_5465->unkB02 &= ~0x20;
    this->unkC->ClearHorizForces();
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HeroInterface'
u8 EnemyGoal_HitBurn::Update() {
    AnimSequence *temp_r4_5532;
    AnimSequence *temp_r4_5554;
    Character *temp_r29_5515;
    Character *temp_r3_5491;
    Character *temp_r3_5547;
    Character *temp_r3_5553;
    Character *temp_r3_5567;
    f32 temp_f31_5492;
    u8 var_r30_5528;

    ActivateIfInactive();
    temp_r3_5491 = this->unkC;
    temp_f31_5492 = (f32) pow(0.125, gUpdateTimeDelta);
    M2C_FIELD(temp_r3_5491, f64 *, 0xA0) = (f64) (M2C_FIELD(temp_r3_5491, f64 *, 0xA0) * (f64) temp_f31_5492);
    temp_r3_5491->unkA8 *= temp_f31_5492;
    if (gb.unk0->GetHeroType(&temp_r3_5491->unkA0) == 0) {
        gb.GetSpyro();
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 0x268) = 1;
    }
    temp_r29_5515 = this->unkC;
    if (temp_r29_5515->unk7F0 <= 0.1f) {
        if ((u32) temp_r29_5515->unkA50->unk40 == (u32) M2C_FIELD(temp_r29_5515->unk630, u32 *, 0x20)) {
            var_r30_5528 = 0;
            if (temp_r29_5515->HasAnimFinished() != 0) {
                temp_r4_5532 = temp_r29_5515->unkA50;
                if ((temp_r4_5532 != NULL) && ((u32) temp_r4_5532->unk40 == (u32) M2C_FIELD(temp_r29_5515->unk630, u32 *, 0x20))) {
                    var_r30_5528 = 1;
                }
            }
            if (var_r30_5528 != 0) {
                this->unk8 = 2;
                temp_r3_5547 = this->unkC;
                temp_r3_5547->unkB02 &= ~0x20;
            } else {
                goto block_10;
            }
        } else {
block_10:
            temp_r3_5553 = this->unkC;
            temp_r4_5554 = temp_r3_5553->unkA50;
            if ((u32) temp_r4_5554->unk40 != 0) {
                ((Enemy *) temp_r3_5553)->SetAnim(temp_r4_5554, (AnimTransition *) &temp_r4_5554->unk40, 0.15f, 0U);
            } else {
                this->unk8 = 2;
                temp_r3_5567 = this->unkC;
                temp_r3_5567->unkB02 &= ~0x20;
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA50'
void EnemyGoal_HitBurn::Activate() {
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    MKVector3 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    AnimSequence *temp_r4_5596;
    AnimSequence *temp_r4_5611;
    Character *temp_r3_5609;
    Character *temp_r3_5636;
    Character *temp_r3_5643;
    Character *temp_r3_5791;
    Character *temp_r4_5665;
    Character *temp_r5_5595;
    Character *temp_r5_5650;
    f32 var_f4_5680;
    f32 var_f5_5693;
    f64 temp_f0_5674;
    f64 temp_f0_5786;
    f64 temp_f1_5668;
    f64 temp_f1_5698;
    f64 temp_f1_5704;
    f64 temp_f1_5708;
    s32 temp_r3_5727;
    s32 var_r0_5737;
    u8 var_r5_5610;
    void *temp_r3_5666;

    this->unk8 = 0;
    temp_r5_5595 = this->unkC;
    temp_r4_5596 = temp_r5_5595->unkA50;
    temp_r5_5595->unkB02 |= 0x20;
    if (((temp_r4_5596 == NULL) || ((s32) temp_r4_5596->unk6C == 2)) && ((s32) temp_r4_5596->unk68 == 0x31)) {
        temp_r3_5609 = this->unkC;
        var_r5_5610 = 0;
        temp_r4_5611 = temp_r3_5609->unkA50;
        if ((temp_r4_5611 != NULL) && ((u32) temp_r4_5611->unk20 == (u32) M2C_FIELD(temp_r3_5609->unk630, u32 *, 0x20))) {
            var_r5_5610 = 1;
        }
        if (var_r5_5610 == 0) {
            goto block_7;
        }
    } else {
block_7:
        ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 2, 0x31, 1, 0.0f, 4U, 1U);
    }
    this->unkC->StopMovement(1U);
    temp_r3_5636 = this->unkC;
    if ((s32) temp_r3_5636->unk688 != 2) {
        temp_r3_5636->SetMovementType((CharacterMoveType) 0);
    }
    temp_r3_5643 = this->unkC;
    if ((u8) M2C_FIELD(temp_r3_5643->unkA38, u8 *, 0x123) != 0) {
        ((Enemy *) temp_r3_5643)->SnapToDirOfHitSource();
        temp_r5_5650 = this->unkC;
        M2C_FIELD(temp_r5_5650, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(temp_r5_5650, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        M2C_FIELD(temp_r5_5650, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r5_5650, f64 *, 0xF0);
        M2C_FIELD(temp_r5_5650, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r5_5650, f64 *, 0xF8);
        temp_r5_5650->unk6B5 |= 0x40;
    }
    temp_r4_5665 = this->unkC;
    temp_r3_5666 = temp_r4_5665->unk8;
    temp_f1_5668 = M2C_FIELD(temp_r3_5666, f64 *, 0x30);
    sp50 = temp_f1_5668;
    sp58 = M2C_FIELD(temp_r3_5666, f64 *, 0x38);
    temp_f0_5674 = temp_f1_5668 - M2C_FIELD(temp_r4_5665, f64 *, 0x910);
    sp20 = temp_f0_5674;
    var_f4_5680 = 0.0f;
    sp60 = temp_f0_5674;
    sp28 = (f32) sp58 - temp_r4_5665->unk918;
    (*(f32 *) ((u8 *) &sp58 + 0xc)) = 0.0f;
    sp68 = (f64) sp28;
    var_f5_5693 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (0.0f * 0.0f));
    if (var_f5_5693 > 0.000001f) {
        if (var_f5_5693 > 0.0f) {
            temp_f1_5698 = __frsqrte(var_f5_5693);
            temp_f1_5704 = 0.5 * temp_f1_5698 * -(((f64) var_f5_5693 * (temp_f1_5698 * temp_f1_5698)) - 3.0);
            temp_f1_5708 = 0.5 * temp_f1_5704 * -(((f64) var_f5_5693 * (temp_f1_5704 * temp_f1_5704)) - 3.0);
            var_f5_5693 = (f32) ((f64) var_f5_5693 * (0.5 * temp_f1_5708 * -(((f64) var_f5_5693 * (temp_f1_5708 * temp_f1_5708)) - 3.0)));
        } else if (var_f5_5693 < M2C_BITWISE(f32, 0.0)) {
            var_f5_5693 = __float_nan;
        } else {
            sp8 = var_f5_5693;
            temp_r3_5727 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_5727) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_5737 = 1;
                } else {
                    var_r0_5737 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_5737 = 5;
                } else {
                    var_r0_5737 = 3;
                }
                break;
            default:
                var_r0_5737 = 4;
                break;
            }
            if (var_r0_5737 == 1) {
                var_f5_5693 = __float_nan;
            }
        }
        var_f4_5680 = 1.0f / var_f5_5693;
    }
    sp60 = (f32) sp60 * var_f4_5680;
    (*(f32 *) ((u8 *) &sp58 + 0xc)) *= var_f4_5680;
    sp68 = (f32) sp68 * var_f4_5680;
    sp30.operator*((f32) (this->unkC->unk940 + 1));
    temp_f0_5786 = sp30 * 5.5769738e-315;
    sp10 = temp_f0_5786;
    temp_r3_5791 = this->unkC;
    sp40 = temp_f0_5786;
    sp18 = sp30.unk8 * 200.0f;
    sp48 = (f64) sp18;
    M2C_FIELD(temp_r3_5791, f64 *, 0xA0) = (f64) (M2C_FIELD(temp_r3_5791, f64 *, 0xA0) + temp_f0_5786);
    temp_r3_5791->unkA8 += (f32) sp48;
}
#endif

void EnemyGoal_HitShock::Terminate() {
    Enemy *temp_r5_5817;

    temp_r5_5817 = this->unkC;
    temp_r5_5817->unkB02 &= ~0x20;
    this->unk8 = 1;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HeroInterface'
u8 EnemyGoal_HitShock::Update() {
    AnimSequence *temp_r4_5872;
    AnimSequence *temp_r4_5897;
    Enemy *temp_r29_5856;
    Enemy *temp_r3_5886;
    Enemy *temp_r3_5912;
    Enemy *temp_r4_5836;
    u8 var_r30_5893;

    ActivateIfInactive();
    temp_r4_5836 = this->unkC;
    temp_r4_5836->unkB02 |= 0x20;
    if (gb.unk0->GetHeroType(temp_r4_5836, 1) == 0) {
        gb.GetSpyro();
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 0x268) = 1;
    }
    temp_r29_5856 = this->unkC;
    if ((s32) M2C_FIELD(temp_r29_5856->unk630, s32 *, 0x44) >= 2) {
        if (temp_r29_5856->unk750.unkA0 > 0.1f) {
            Activate();
        } else {
            temp_r4_5872 = temp_r29_5856->unkA50;
            if ((u32) temp_r4_5872->unk40 != 0) {
                temp_r29_5856->SetAnim(temp_r4_5872, (AnimTransition *) &temp_r4_5872->unk40, 0.15f, 0U);
            } else {
                this->unk8 = 2;
                temp_r3_5886 = this->unkC;
                temp_r3_5886->unkB02 &= ~0x20;
            }
        }
    } else {
        var_r30_5893 = 0;
        if (((Character *) temp_r29_5856)->HasAnimFinished() != 0) {
            temp_r4_5897 = temp_r29_5856->unkA50;
            if ((temp_r4_5897 != NULL) && ((u32) temp_r4_5897->unk40 == (u32) M2C_FIELD(temp_r29_5856->unk630, u32 *, 0x20))) {
                var_r30_5893 = 1;
            }
        }
        if (var_r30_5893 != 0) {
            this->unk8 = 2;
            temp_r3_5912 = this->unkC;
            temp_r3_5912->unkB02 &= ~0x20;
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
void EnemyGoal_HitShock::Activate() {
    AnimSequence *temp_r4_5941;
    Enemy *temp_r3_5936;
    Enemy *temp_r3_5940;
    Enemy *temp_r3_5966;
    Enemy *temp_r3_5973;
    Enemy *temp_r5_5980;

    this->unk8 = 0;
    temp_r3_5936 = this->unkC;
    temp_r3_5936->unkB02 |= 0x20;
    temp_r3_5940 = this->unkC;
    temp_r4_5941 = temp_r3_5940->unkA50;
    if ((temp_r4_5941 == NULL) || ((s32) temp_r4_5941->unk6C != 2) || ((s32) temp_r4_5941->unk68 != 0x2C) || ((s32) M2C_FIELD(temp_r3_5940->unk630, s32 *, 0x44) >= 2)) {
        temp_r3_5940->SetAnim((AnimSequenceType) 2, 0x2C, 0, 0.0f, 4U, 1U);
    }
    ((Character *) this->unkC)->StopMovement(1U);
    temp_r3_5966 = this->unkC;
    if ((s32) temp_r3_5966->unk688 != 2) {
        ((Character *) temp_r3_5966)->SetMovementType((CharacterMoveType) 0);
    }
    temp_r3_5973 = this->unkC;
    if ((u8) temp_r3_5973->unkA38->unk123 != 0) {
        temp_r3_5973->SnapToDirOfHitSource();
        temp_r5_5980 = this->unkC;
        M2C_FIELD(temp_r5_5980, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(temp_r5_5980, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        M2C_FIELD(temp_r5_5980, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r5_5980, f64 *, 0xF0);
        M2C_FIELD(temp_r5_5980, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r5_5980, f64 *, 0xF8);
        temp_r5_5980->unk6B5 |= 0x40;
    }
}
#endif

u8 EnemyGoal_HitFlinch::Update() {
    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier 'temp_r3_6039'
void EnemyGoal_HitFlinch::Activate() {
    Character *temp_r3_6039;
    Character *temp_r3_6051;
    Character *temp_r3_6075;
    Character *temp_r3_6082;
    Character *temp_r5_6089;

    this->unk8 = 0;
    if ((u8) this->unk10 != 0) {
        temp_r3_6039 = this->unkC;
        ((Enemy *) temp_r3_6039)->SetAnim((AnimSequenceType) 2, M2C_FIELD(temp_r3_6039->unk638, s32 *, 8) + 0x69, 0, 0.15f, 0U, 0U);
        return;
    }
    temp_r3_6051 = this->unkC;
    if (((u8) temp_r3_6051->unk6B5 >> 4U) & 1) {
        ((Enemy *) temp_r3_6051)->SetAnim((AnimSequenceType) 2, 0x2D, 0, 0.15f, 0U, 0U);
    } else {
        ((Enemy *) temp_r3_6051)->SetAnim((AnimSequenceType) 2, 0x28, 0, 0.15f, 0U, 0U);
    }
    this->unkC->StopMovement(1U);
    temp_r3_6075 = this->unkC;
    if ((s32) temp_r3_6075->unk688 != 2) {
        temp_r3_6075->SetMovementType((CharacterMoveType) 0);
    }
    temp_r3_6082 = this->unkC;
    if ((u8) M2C_FIELD(temp_r3_6082->unkA38, u8 *, 0x123) != 0) {
        ((Enemy *) temp_r3_6082)->SnapToDirOfHitSource();
        temp_r5_6089 = this->unkC;
        M2C_FIELD(temp_r5_6089, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(temp_r5_6089, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        M2C_FIELD(temp_r5_6089, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r5_6089, f64 *, 0xF0);
        M2C_FIELD(temp_r5_6089, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r5_6089, f64 *, 0xF8);
        temp_r5_6089->unk6B5 |= 0x40;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
u8 GetPushOutWallNormal(Enemy *arg0, MKVector3 *arg1) {
    MKCollisionResult sp80;
    MKVector3 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    MKVector3 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    s32 spC;
    f32 sp8;
    f32 temp_f30_6129;
    f32 temp_f6_6212;
    f64 *temp_r5_6177;
    f64 temp_f1_6224;
    f64 temp_f31_6200;
    f64 temp_f4_6175;
    s32 temp_r3_6157;
    s32 var_ctr_6168;
    s32 var_r4_6165;
    u32 temp_r4_6131;
    void *temp_r3_6172;
    void *temp_r5_6130;
    void *temp_r5_6220;

    temp_f30_6129 = M2C_FIELD(arg0->__vptr, f32 (**)(), 0x100)();
    temp_r5_6130 = arg0->unk8;
    temp_r4_6131 = arg0->unkA38->unk270;
    sp60 = M2C_FIELD(temp_r5_6130, f64 *, 0x30);
    sp68 = M2C_FIELD(temp_r5_6130, f64 *, 0x38);
    if (temp_r4_6131 != -1U) {
        MKModel_CalculateNodeWorldPosition(arg0->unk4, (s32) temp_r4_6131, &sp70);
    } else {
        sp70 = arg0->unk60;
        sp70.unk8 = arg0->unk68;
    }
    temp_r3_6157 = MKCollision_SphereCollide(sp70, temp_f30_6129, &sp80, 0xA, (MKCollisionMode) 7, M2C_FIELD(arg0->unk110.unk460, s32 *, 0x18) | 0x0C000000);
    if (temp_r3_6157 != 0) {
        var_r4_6165 = 0;
        var_ctr_6168 = temp_r3_6157;
        if (temp_r3_6157 > 0) {
loop_5:
            temp_r3_6172 = &sp80 + var_r4_6165;
            temp_f4_6175 = M2C_FIELD(temp_r3_6172, f64 *, 0) - sp60;
            sp20 = temp_f4_6175;
            temp_r5_6177 = ((u8 *) temp_r3_6172) + 0x10;
            sp50 = temp_f4_6175;
            sp28 = M2C_FIELD(temp_r3_6172, f32 *, 8) - (f32) sp68;
            sp58 = (f64) sp28;
            sp8 = (M2C_FIELD(temp_r3_6172, f32 *, 0x18) * (f32) sp58) + ((M2C_FIELD(temp_r3_6172, f32 *, 0x10) * (f32) sp50) + (M2C_FIELD(temp_r3_6172, f32 *, 0x14) * (*(f32 *) ((u8 *) &sp50 + 0x4))));
            spC = (M2C_BITWISE(s32, sp8) & 0x80000000) | 0x3F800000;
            temp_f31_6200 = -M2C_BITWISE(f32, spC);
            *temp_r5_6177 *= temp_f31_6200;
            M2C_FIELD(temp_r3_6172, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r3_6172, f32 *, 0x18) * (f32) temp_f31_6200);
            temp_f6_6212 = (M2C_FIELD(temp_r3_6172, f32 *, 0x18) * MKVector3::up.unk8) + ((M2C_FIELD(temp_r3_6172, f32 *, 0x10) * MKVector3::up.unk0) + (M2C_FIELD(temp_r3_6172, f32 *, 0x14) * MKVector3::up.unk4));
            if ((temp_f6_6212 < 0.3f) && (temp_f6_6212 > -0.3f)) {
                temp_r5_6220 = &sp80.unk10 + var_r4_6165;
                temp_f1_6224 = M2C_FIELD(temp_r5_6220, f64 *, 8);
                sp10 = M2C_FIELD(temp_r5_6220, f64 *, 0);
                (*(f32 *) ((u8 *) &sp10 + 0x4)) = 0.0f;
                sp18 = temp_f1_6224;
                sp30 = sp10;
                sp38 = temp_f1_6224;
                Normalise(sp40);
                M2C_FIELD(arg1, f64 *, 0) = M2C_BITWISE(f64, sp40);
                M2C_FIELD(arg1, f64 *, 8) = (f64) sp40.unk8;
                return 1U;
            }
            var_r4_6165 += 0x58;
            var_ctr_6168 -= 1;
            if (var_ctr_6168 == 0) {
                goto block_9;
            }
            goto loop_5;
        }
    }
block_9:
    return 0U;
}
#endif

void EnemyGoals_Hit_cpp::__sinit() {
    f32 temp_f0_6339;
    f64 temp_f1_6320;
    f64 temp_f1_6328;
    f64 temp_f3_6308;
    f64 temp_f4_6317;
    f64 temp_f4_6325;
    f64 temp_f8_6310;

    temp_f3_6308 = __frsqrte(2014000.0);
    temp_f8_6310 = __frsqrte(380000.0);
    temp_f4_6317 = 0.5 * temp_f3_6308 * -((2014000.0 * (temp_f3_6308 * temp_f3_6308)) - 3.0);
    temp_f1_6320 = 0.5 * temp_f8_6310 * -((380000.0 * (temp_f8_6310 * temp_f8_6310)) - 3.0);
    temp_f4_6325 = 0.5 * temp_f4_6317 * -((2014000.0 * (temp_f4_6317 * temp_f4_6317)) - 3.0);
    temp_f1_6328 = 0.5 * temp_f1_6320 * -((380000.0 * (temp_f1_6320 * temp_f1_6320)) - 3.0);
    temp_f0_6339 = (f32) (380000.0 * (0.5 * temp_f1_6328 * -((380000.0 * (temp_f1_6328 * temp_f1_6328)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_6325 * -((2014000.0 * (temp_f4_6325 * temp_f4_6325)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_6339;
}
