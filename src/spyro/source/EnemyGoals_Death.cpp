#include "spyro/source/EnemyGoals_Death.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/Game.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern s32 GS_Emergency1;
extern s32 GS_EnemyLavaBurn;
extern s32 GS_EnemyTornadoFlyDown;
extern s32 GS_EnemyTornadoFlyUP;
extern s32 GS_EnemyTornadoImpact;
extern s32 GS_SpyroEarthFurySquish;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
static s32 lit_773 = 2;
static u8 lit_774 = 1;
static u8 lit_816 = 1;

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EnemyGoal_Death::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        RemoveAllSubgoals();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void EnemyGoal_Death::Activate() {
    Enemy *temp_r3_44;
    Enemy *temp_r5_48;
    u8 temp_r3_49;

    this->unk8 = 0;
    temp_r3_44 = this->unkC;
    M2C_FIELD(temp_r3_44, u8 *, 0xB02) = (u8) (M2C_FIELD(temp_r3_44, u8 *, 0xB02) & ~0x20);
    temp_r5_48 = this->unkC;
    temp_r3_49 = M2C_FIELD(temp_r5_48, u8 *, 0xB09);
    if (((temp_r3_49 >> 2U) & 1) && ((s32) temp_r5_48->unk110.unk16C > 0)) {
        M2C_FIELD(temp_r5_48, u8 *, 0xB09) = (u8) (temp_r3_49 & ~4);
    }
    RemoveAllSubgoals();
    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk20);
}
#endif

void EnemyGoal_Death::Deinit() {
    Goal<Enemy> *temp_r3_78;
    MKHeap *temp_r3_88;
    void *temp_r31_85;

    temp_r3_78 = this->unk20;
    temp_r3_78->Deinit();
    operator delete(this->unk20);
    temp_r31_85 = this->unk1C;
    if (temp_r31_85 != NULL) {
        temp_r3_88 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_88 != NULL) {
            ((MKHeap *) (temp_r3_88->Current()))->Free(temp_r31_85, NULL, 0);
        } else {
            free(temp_r31_85);
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
void EnemyGoal_Death::Init(Enemy *arg0) {
    MKHeap *temp_r3_162;
    void *var_r3_169;

    if ((u8) this->unk9 == 0) {
        operator new(0x48U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__21CompositeGoal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_162 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_162 != NULL) {
            var_r3_169 = ((MKHeap *) (temp_r3_162->Current()))->Alloc(4, NULL, 0);
        } else {
            var_r3_169 = malloc(4);
        }
        this->unk1C = var_r3_169;
        this->unk10 = 1;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x5B;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    this->unk20->Init(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
u8 EnemyGoal_Respawn::Update() {
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f1_242;
    f32 temp_f3_246;
    f32 temp_f4_239;
    void *temp_r3_211;

    ActivateIfInactive();
    temp_r3_211 = this->unkC;
    if (gb.unk30C >= M2C_FIELD(temp_r3_211, f32 *, 0xA74)) {
        sp60 = M2C_FIELD(temp_r3_211, f32 *, 0x5B8);
        sp64 = M2C_FIELD(temp_r3_211, f32 *, 0x5BC);
        sp68 = M2C_FIELD(temp_r3_211, f32 *, 0x5C0);
        sp6C = 1.0f;
        sp40 = MKVector3::up.unk0;
        sp44 = MKVector3::up.unk4;
        sp48 = MKVector3::up.unk8;
        sp4C = 0.0f;
        temp_f4_239 = M2C_FIELD(temp_r3_211, f32 *, 0x5C8);
        sp50 = temp_f4_239;
        temp_f1_242 = M2C_FIELD(temp_r3_211, f32 *, 0x5CC);
        sp54 = temp_f1_242;
        temp_f3_246 = M2C_FIELD(temp_r3_211, f32 *, 0x5D0);
        sp18 = (MKVector3::up.unk0 * temp_f1_242) - (MKVector3::up.unk4 * temp_f4_239);
        sp58 = temp_f3_246;
        sp28 = (f64) sp18;
        sp10 = (MKVector3::up.unk4 * temp_f3_246) - (MKVector3::up.unk8 * temp_f1_242);
        sp14 = (MKVector3::up.unk8 * temp_f4_239) - (MKVector3::up.unk0 * temp_f3_246);
        sp5C = 0.0f;
        sp20 = (f64) sp10;
        sp30 = (f32) sp20;
        sp34 = unksp24;
        sp38 = (f32) sp28;
        sp3C = 0.0f;
        if (M2C_FIELD(M2C_FIELD(temp_r3_211, void **, 0x44), u8 (**)(f32 *, M2C_UNK, MKVector3 *, f32, f32, f32, f32, f32, f32, f32, f32), 0x120)(&sp30, 0, &MKVector3::up, unksp24, (f32) sp20, temp_f3_246, temp_f4_239, 0.0f, MKVector3::up.unk8, MKVector3::up.unk4, MKVector3::up.unk0) != 0) {
            this->unk8 = 2;
        } else {
            M2C_FIELD(this->unkC, f32 *, 0xA74) = (f32) (gb.unk30C + 0.2f);
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void EnemyGoal_Respawn::Activate() {
    f32 temp_f1_309;
    f64 temp_f1_327;
    void *temp_r3_316;
    void *temp_r3_321;
    void *temp_r3_326;
    void *temp_r3_331;
    void *temp_r4_303;

    this->unk8 = 0;
    temp_r4_303 = this->unkC;
    if (gb.unk30C >= M2C_FIELD(temp_r4_303, f32 *, 0xA74)) {
        temp_f1_309 = M2C_FIELD(temp_r4_303, f32 *, 0xAB4);
        if (temp_f1_309 > 0.0f) {
            M2C_FIELD(temp_r4_303, f32 *, 0xA74) = (f32) (gb.unk30C + temp_f1_309);
        }
    }
    temp_r3_316 = this->unkC;
    M2C_FIELD(M2C_FIELD(temp_r3_316, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_316);
    temp_r3_321 = this->unkC;
    M2C_FIELD(M2C_FIELD(temp_r3_321, void **, 0x44), M2C_UNK (**)(void *), 0x58)(temp_r3_321);
    temp_r3_326 = this->unkC;
    temp_f1_327 = M2C_FIELD(temp_r3_326, f64 *, 0x5B8);
    M2C_FIELD(temp_r3_326, f64 *, 0x588) = temp_f1_327;
    M2C_FIELD(temp_r3_326, f64 *, 0x590) = (f64) M2C_FIELD(temp_r3_326, f64 *, 0x5C0);
    temp_r3_331 = this->unkC;
    M2C_FIELD(M2C_FIELD(temp_r3_331, void **, 0x44), M2C_UNK (**)(void *, f64), 0x68)(temp_r3_331, temp_f1_327);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_Dying::Terminate() {
    MKProp *temp_r3_351;
    MKProp *temp_r4_360;
    SpawnerObject **temp_r3_361;

    temp_r3_351 = this->unkC;
    M2C_FIELD(temp_r3_351->__vptr, M2C_UNK (**)(MKProp *), 0x1CC)(temp_r3_351);
    gb.unk2F8.AddKill();
    temp_r4_360 = this->unkC;
    temp_r3_361 = M2C_FIELD(temp_r4_360, SpawnerObject ***, 0xA48);
    if (temp_r3_361 != NULL) {
        ((SpawnerObject *) (*temp_r3_361))->DespawnItem(temp_r4_360, 1U);
    } else {
        M2C_FIELD(temp_r4_360->__vptr, M2C_UNK (**)(MKProp *, M2C_UNK), 0x4C)(temp_r4_360, 1);
    }
    this->unk8 = 1;
    RemoveAllSubgoals();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EnemyGoal_Dying::Update() {
    MKProp *temp_r3_399;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    temp_r3_399 = this->unkC;
    if ((((u8) M2C_FIELD(temp_r3_399, u8 *, 0xB09) >> 2U) & 1) && ((M2C_FIELD(temp_r3_399, f32 *, 0xAB0) - M2C_FIELD(temp_r3_399, f32 *, 0x58C)) > 4000.0f)) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal type
void EnemyGoal_Dying::Activate() {
    f64 sp28;
    f64 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    MKProp *temp_r3_465;
    MKProp *temp_r4_475;
    MKProp *temp_r4_578;
    f64 temp_f0_454;
    f64 temp_f2_452;
    u32 temp_r3_579;
    u8 temp_r3_556;
    u8 var_r3_518;
    void *temp_r3_431;
    void *temp_r3_487;
    void *temp_r3_506;
    void *temp_r9_451;

    this->unk8 = 0;
    temp_r3_431 = M2C_FIELD(this->unkC, void **, 0x640);
    if (temp_r3_431 != NULL) {
        M2C_FIELD(temp_r3_431, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_431, u8 *, 0x464) & ~0x80);
    }
    ((Targetable *) (this->unkC + 0x6B8))->UnregisterTargetable();
    sp1C = 0;
    temp_r9_451 = this->unkC->unk8;
    temp_f2_452 = M2C_FIELD(temp_r9_451, f64 *, 0x30);
    temp_f0_454 = M2C_FIELD(temp_r9_451, f64 *, 0x38);
    sp8 = temp_f2_452;
    sp18 = 0x57;
    sp20 = temp_f2_452;
    sp28 = temp_f0_454;
    sp1C = 0;
    sp10 = temp_f0_454;
    M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, void *, M2C_UNK, void *, M2C_UNK, f32, f64), 0x94)(gMK, &sp18, 8, 0, temp_r9_451 + 0x30, 1, temp_r9_451, 0, 1000.0f, temp_f2_452);
    temp_r3_465 = this->unkC;
    if (!(((u8) M2C_FIELD(temp_r3_465, u8 *, 0x6B5) >> 4U) & 1)) {
        temp_r3_465->StopMovement(1U);
        M2C_FIELD(this->unkC, f32 *, 0x59C) = 0.0f;
    }
    temp_r4_475 = this->unkC;
    if ((u32) M2C_FIELD(temp_r4_475, u32 *, 0x638) != 0U) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
    } else if ((((u8) M2C_FIELD(temp_r4_475, u8 *, 0xB02) >> 7U) & 1) || ((temp_r3_487 = M2C_FIELD(temp_r4_475, void **, 0xA00), ((temp_r3_487 == NULL) == 0)) && ((u8) M2C_FIELD(temp_r3_487, u8 *, 0x20) != 0))) {
        if ((((u8) M2C_FIELD(temp_r4_475, u8 *, 0xB08) >> 2U) & 1) || (((u8) M2C_FIELD(temp_r4_475, u8 *, 0xB01) >> 1U) & 1)) {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
        } else {
            temp_r3_506 = M2C_FIELD(temp_r4_475, void **, 0xA00);
            if ((temp_r3_506 != NULL) && ((u8) M2C_FIELD(temp_r3_506, u8 *, 0x20) != 0)) {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
            } else {
                var_r3_518 = 0;
                if (((s32) M2C_FIELD(temp_r4_475, s32 *, 0x7C8) == 3) && (M2C_FIELD(temp_r4_475, f32 *, 0x7E4) > 0.0f)) {
                    var_r3_518 = 1;
                }
                if (var_r3_518 != 0) {
                    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
                } else {
                    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk20);
                }
            }
        }
    } else if (((u8) M2C_FIELD(temp_r4_475, u8 *, 0x6B5) >> 4U) & 1) {
        if ((s32) M2C_FIELD(M2C_FIELD(temp_r4_475, void **, 0xA38), s32 *, 0x118) == 3) {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
        } else {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk20);
        }
    } else {
        temp_r3_556 = M2C_FIELD(temp_r4_475, u8 *, 0xB0A);
        if ((temp_r3_556 >> 3U) & 1) {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk40);
        } else if ((temp_r3_556 >> 1U) & 1) {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk40);
        } else {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk20);
        }
    }
    temp_r4_578 = this->unkC;
    temp_r3_579 = M2C_FIELD(temp_r4_578, u32 *, 0xA44);
    if (temp_r3_579 != 0U) {
        ((EventMessage *) (temp_r3_579 + 8))->Send(temp_r4_578);
    }
}
#endif

void EnemyGoal_Dying::Deinit() {
    Goal<Enemy> *temp_r3_600;
    Goal<Enemy> *temp_r3_605;
    Goal<Enemy> *temp_r3_610;
    Goal<Enemy> *temp_r3_615;
    Goal<Enemy> *temp_r3_620;
    Goal<Enemy> *temp_r3_625;
    Goal<Enemy> *temp_r3_640;
    Goal<Enemy> *temp_r3_645;
    MKHeap *temp_r3_673;
    void **temp_r3_630;
    void **temp_r3_635;
    void *temp_r31_670;

    temp_r3_600 = this->unk20;
    temp_r3_600->Deinit();
    temp_r3_605 = this->unk24;
    temp_r3_605->Deinit();
    temp_r3_610 = this->unk28;
    temp_r3_610->Deinit();
    temp_r3_615 = this->unk2C;
    temp_r3_615->Deinit();
    temp_r3_620 = this->unk30;
    temp_r3_620->Deinit();
    temp_r3_625 = this->unk34;
    temp_r3_625->Deinit();
    temp_r3_630 = this->unk3C;
    M2C_FIELD(*temp_r3_630, M2C_UNK (**)(void **), 0xC)(temp_r3_630);
    temp_r3_635 = this->unk38;
    M2C_FIELD(*temp_r3_635, M2C_UNK (**)(void **), 0xC)(temp_r3_635);
    temp_r3_640 = this->unk40;
    temp_r3_640->Deinit();
    temp_r3_645 = this->unk44;
    temp_r3_645->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk3C);
    operator delete(this->unk38);
    operator delete(this->unk40);
    operator delete(this->unk44);
    temp_r31_670 = this->unk1C;
    if (temp_r31_670 != NULL) {
        temp_r3_673 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_673 != NULL) {
            ((MKHeap *) (temp_r3_673->Current()))->Free(temp_r31_670, NULL, 0);
        } else {
            free(temp_r31_670);
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
void EnemyGoal_Dying::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_1002;
    Goal<Enemy> *temp_r4_1035;
    Goal<Enemy> *temp_r4_1046;
    Goal<Enemy> *temp_r4_947;
    Goal<Enemy> *temp_r4_958;
    Goal<Enemy> *temp_r4_969;
    Goal<Enemy> *temp_r4_980;
    Goal<Enemy> *temp_r4_991;
    MKHeap *temp_r3_920;
    void **temp_r4_1013;
    void **temp_r4_1024;
    void *var_r3_927;

    if ((u8) this->unk9 == 0) {
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
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
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
        this->unk40 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk44 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_920 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_920 != NULL) {
            var_r3_927 = ((MKHeap *) (temp_r3_920->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_927 = malloc(8);
        }
        this->unk1C = var_r3_927;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (MKProp *) arg0;
    this->unk4 = 0x5A;
    if ((MKProp *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_947 = this->unk20;
    M2C_FIELD(temp_r4_947, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_947, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_947, s32 *, 4) = 0x16;
    if ((Enemy *) M2C_FIELD(temp_r4_947, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_947, s8 *, 9) = 1;
    }
    temp_r4_958 = this->unk24;
    M2C_FIELD(temp_r4_958, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_958, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_958, s32 *, 4) = 0x17;
    if ((Enemy *) M2C_FIELD(temp_r4_958, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_958, s8 *, 9) = 1;
    }
    temp_r4_969 = this->unk28;
    M2C_FIELD(temp_r4_969, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_969, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_969, s32 *, 4) = 0x18;
    if ((Enemy *) M2C_FIELD(temp_r4_969, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_969, s8 *, 9) = 1;
    }
    temp_r4_980 = this->unk2C;
    M2C_FIELD(temp_r4_980, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_980, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_980, s32 *, 4) = 0x19;
    if ((Enemy *) M2C_FIELD(temp_r4_980, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_980, s8 *, 9) = 1;
    }
    temp_r4_991 = this->unk30;
    M2C_FIELD(temp_r4_991, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_991, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_991, s32 *, 4) = 0x1A;
    if ((Enemy *) M2C_FIELD(temp_r4_991, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_991, s8 *, 9) = 1;
    }
    temp_r4_1002 = this->unk34;
    M2C_FIELD(temp_r4_1002, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1002, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1002, s32 *, 4) = 0x1B;
    if ((Enemy *) M2C_FIELD(temp_r4_1002, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1002, s8 *, 9) = 1;
    }
    temp_r4_1013 = this->unk3C;
    M2C_FIELD(temp_r4_1013, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1013, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1013, s32 *, 4) = 0xB;
    if ((Enemy *) M2C_FIELD(temp_r4_1013, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1013, s8 *, 9) = 1;
    }
    temp_r4_1024 = this->unk38;
    M2C_FIELD(temp_r4_1024, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1024, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1024, s32 *, 4) = 0xA;
    if ((Enemy *) M2C_FIELD(temp_r4_1024, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1024, s8 *, 9) = 1;
    }
    temp_r4_1035 = this->unk40;
    M2C_FIELD(temp_r4_1035, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1035, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1035, s32 *, 4) = 0x1D;
    if ((Enemy *) M2C_FIELD(temp_r4_1035, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1035, s8 *, 9) = 1;
    }
    temp_r4_1046 = this->unk44;
    M2C_FIELD(temp_r4_1046, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1046, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1046, s32 *, 4) = 0x1C;
    if ((Enemy *) M2C_FIELD(temp_r4_1046, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1046, s8 *, 9) = 1;
    }
}
#endif

u8 EnemyGoal_DyingSquished::Update() {
    ActivateIfInactive();
    this->unk10 -= gUpdateTimeDelta;
    if (this->unk10 <= 0.0f) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier 'unkB0A'
void EnemyGoal_DyingSquished::Activate() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Character *temp_r3_1108;
    Character *temp_r3_1112;
    Character *temp_r3_1137;

    this->unk8 = 0;
    temp_r3_1108 = this->unkC;
    temp_r3_1108->unkB0A |= 0x10;
    temp_r3_1112 = this->unkC;
    temp_r3_1112->unkB0A |= 8;
    KDSound_Play3d(GS_SpyroEarthFurySquish, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    this->unk10 = 4.0f;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    sp8 = 1.5f;
    M2C_FIELD(M2C_FIELD(this->unkC, void **, 0x630), f32 *, 0x38) = 0.0f;
    spC = 0.1f;
    temp_r3_1137 = this->unkC;
    sp10 = 1.5f;
    temp_r3_1137->unk730 = (f64) sp8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    temp_r3_1137->unk738 = (f64) sp10;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp13C'
u8 EnemyGoal_DyingWhirlwind::Update() {
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    M2C_UNK sp170;
    M2C_UNK sp16C;
    s8 sp160;
    f64 sp158;
    f64 sp150;
    s32 sp14C;
    s32 sp148;
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
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    Character *temp_r3_1234;
    Character *temp_r3_1245;
    Character *temp_r3_1267;
    Character *temp_r3_1295;
    Character *temp_r3_1301;
    Character *temp_r3_1359;
    Character *temp_r3_1461;
    Character *temp_r4_1196;
    f32 temp_f1_1357;
    f32 temp_f22_1352;
    f32 temp_f23_1355;
    f32 temp_f23_1422;
    f32 temp_f25_1427;
    f32 temp_f3_1286;
    f32 temp_f4_1214;
    f64 temp_f0_1256;
    f64 temp_f0_1376;
    f64 temp_f0_1388;
    s32 temp_r0_1184;
    s32 var_r28_1338;

    ActivateIfInactive();
    temp_r0_1184 = this->unk10;
    switch (temp_r0_1184) {                         /* irregular */
    case 0:
        temp_r4_1196 = this->unkC;
        spA0 = 0.0f;
        sp98 = 0.0f;
        sp9C = 4000.0f * gUpdateTimeDelta;
        sp110 = (f64) spA0;
        sp108 = (f64) sp98;
        sp88 = M2C_FIELD(temp_r4_1196, f64 *, 0x588) + sp108;
        temp_f4_1214 = this->unk14;
        sp138 = sp88;
        sp90 = temp_r4_1196->unk588.unk4 + (f32) sp110;
        sp140 = (f64) sp90;
        M2C_ERROR(/* unknown instruction: cror 0x2, 0x1, 0x2 */);
        if (temp_r4_1196->unk588.unk0 == temp_f4_1214) {
            unksp13C = temp_f4_1214;
            this->unk10 = 1;
            KDSound_Play3d(GS_EnemyTornadoFlyDown, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        }
        temp_r3_1234 = this->unkC;
        M2C_FIELD(temp_r3_1234, f64 *, 0x588) = sp138;
        M2C_FIELD(temp_r3_1234, f32 *, 0x590) = sp140;
        break;
    case 1:
        temp_r3_1245 = this->unkC;
        sp80 = 0.0f;
        sp78 = 0.0f;
        sp7C = 4000.0f * gUpdateTimeDelta;
        sp100 = (f64) sp80;
        spF8 = (f64) sp78;
        temp_f0_1256 = M2C_FIELD(temp_r3_1245, f64 *, 0x588) - spF8;
        sp68 = temp_f0_1256;
        M2C_FIELD(temp_r3_1245, f64 *, 0x588) = temp_f0_1256;
        sp128 = temp_f0_1256;
        sp70 = temp_r3_1245->unk588.unk4 - (f32) sp100;
        M2C_FIELD(temp_r3_1245, f32 *, 0x590) = (f64) sp70;
        temp_r3_1267 = this->unkC;
        sp130 = (f64) sp70;
        if (temp_r3_1267->unk588.unk0 <= this->unk18) {
            M2C_STRUCT_COPY((s32) &sp16C + 4, MKModel_GetWorldMatrix(temp_r3_1267->unk4) - 4 + 4, 0x40);
            temp_f3_1286 = this->unk18;
            sp1A0 = (f32) sp128;
            sp1A4 = temp_f3_1286;
            sp1A8 = (f32) sp130;
            sp1AC = 1.0f;
            temp_r3_1295 = this->unkC;
            unksp12C = temp_f3_1286;
            temp_r3_1295->Teleport(&sp170, &sp16C + 0x40, (f32) sp130, (f32) sp128, temp_f3_1286);
            temp_r3_1301 = this->unkC;
            temp_r3_1301->unkB0A &= ~2;
            KDSound_Play3d(GS_EnemyTornadoImpact, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.6f, 0.4f, 0.1f, this->unkC->unk8 + 0x30, 37.0f, 0, 4.0f, 0U);
            this->unk8 = 2;
            var_r28_1338 = 0;
            do {
                temp_f22_1352 = 6.2831855f * ((f32) var_r28_1338 / 20.0f);
                temp_f23_1355 = -_table_sinf(1.5707964f + temp_f22_1352);
                temp_f1_1357 = _table_sinf(temp_f22_1352);
                sp48 = 0.0f;
                temp_r3_1359 = this->unkC;
                sp4C = 100.0f;
                sp60 = temp_f23_1355;
                sp50 = 0.0f;
                sp58 = temp_f1_1357;
                sp5C = 0.0f;
                spD8 = (f64) sp48;
                sp118 = (f64) sp58;
                sp120 = (f64) sp60;
                spE0 = (f64) sp50;
                temp_f0_1376 = M2C_FIELD(temp_r3_1359, f64 *, 0x588) + spD8;
                sp38 = temp_f0_1376;
                spE8 = temp_f0_1376;
                sp40 = temp_r3_1359->unk588.unk4 + (f32) spE0;
                spF0 = (f64) sp40;
                temp_f0_1388 = sp118 * 5.65986426e-315;
                sp28 = temp_f0_1388;
                spC8 = temp_f0_1388;
                sp30 = (f32) sp120 * 800.0f;
                spD0 = (f64) sp30;
                sp10 = MKRand_Float(&gViewSeed, 1.0f, 1.5f);
                gb.EmitDust(*((MKVector3 *) &spE8), *((MKVector3 *) &spC8), sp10, 0.0f);
                var_r28_1338 += 1;
            } while (var_r28_1338 < 0x14);
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp14C = 0;
                temp_f23_1422 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f25_1427 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f25_1427, temp_f23_1422);
                sp18 = spA8 * 5.398241246e-315;
                sp148 = 0x417;
                sp150 = sp18;
                sp20 = spB0 * 10.0f;
                sp160 = 1;
                sp158 = (f64) sp20;
                spB8 = sp18;
                spC0 = (f64) sp20;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp148, sp18);
            }
        }
        break;
    }
    temp_r3_1461 = this->unkC;
    temp_r3_1461->UpdateModel();
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal type
void EnemyGoal_DyingWhirlwind::Activate() {
    s8 spC8;
    s32 spC4;
    s32 spC0;
    s32 spBC;
    f32 spB8;
    s32 spB4;
    s8 spB3;
    s8 spB2;
    s16 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_1575;
    f64 temp_f3_1567;
    f64 temp_f4_1565;
    void *temp_r3_1563;
    void *temp_r4_1529;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    M2C_FIELD(M2C_FIELD(this->unkC, void **, 0x630), f32 *, 0x38) = 0.0f;
    this->unk10 = 0;
    KDSound_Play3d(GS_EnemyTornadoFlyUP, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    temp_r4_1529 = this->unkC->unk8;
    sp68 = M2C_FIELD(temp_r4_1529, f64 *, 0x30);
    sp20 = 0.0f;
    this->unk18 = unksp6C;
    sp78 = 0.0f;
    sp7C = 0.0f;
    sp80 = 0.0f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp90 = 0.0f;
    sp98 = 0.0f;
    sp9C = 0.0f;
    spA0 = 0.0f;
    spA4 = 1.0f;
    spA8 = 0.0f;
    spAC = 0.0f;
    spB0 = 0;
    spB2 = 0;
    spB3 = 0;
    spB4 = 0;
    spB8 = 3.4028235e38f;
    spBC = 0;
    spC0 = 0;
    spC4 = -1;
    spC8 = 0;
    sp18 = 0.0f;
    temp_r3_1563 = this->unkC->unk8;
    sp1C = 800.0f;
    temp_f4_1565 = M2C_FIELD(temp_r3_1563, f64 *, 0x30);
    temp_f3_1567 = M2C_FIELD(temp_r3_1563, f64 *, 0x38);
    sp28 = (f64) sp18;
    sp38 = temp_f4_1565;
    sp70 = M2C_FIELD(temp_r4_1529, f64 *, 0x38);
    sp30 = (f64) sp20;
    sp40 = temp_f3_1567;
    temp_f0_1575 = sp38 - sp28;
    sp8 = temp_f0_1575;
    sp58 = temp_f4_1565;
    sp48 = temp_f0_1575;
    sp10 = (f32) sp40 - (f32) sp30;
    sp60 = temp_f3_1567;
    sp50 = (f64) sp10;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), (MKCollisionResult *) &sp78, (MKCollisionMode) 7, 0x0C000000) != 0) {
        this->unk18 = sp7C;
    }
    this->unk14 = 7000.0f + this->unk18;
}
#endif

u8 EnemyGoal_DyingTrain::Update() {
    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: illegal implicit conversion from 'AnimSequenceType' to
void EnemyGoal_DyingTrain::Activate() {
    Character *temp_r3_1646;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    temp_r3_1646 = this->unkC;
    temp_r3_1646->SetAnim((AnimSequenceType) 3, M2C_FIELD(temp_r3_1646->unk630, s32 *, 8) + 0x6E, 0, 0.15f, 0U, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5B0'
u8 EnemyGoal_DyingAirborn::Update() {
    Matrix sp80;
    M2C_UNK sp7C;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    Character *temp_r29_1768;
    Character *temp_r3_1680;
    Character *temp_r3_1703;
    f64 temp_f0_1684;
    f64 temp_f1_1713;
    u32 *temp_r4_1774;
    u8 var_r30_1769;
    void *temp_r3_1709;

    ActivateIfInactive();
    temp_r3_1680 = this->unkC;
    temp_f0_1684 = M2C_FIELD(temp_r3_1680, f64 *, 0x5A8) * (f64) gUpdateTimeDelta;
    sp10 = temp_f0_1684;
    sp50 = temp_f0_1684;
    sp18 = temp_r3_1680->unk5B0 * gUpdateTimeDelta;
    sp58 = (f64) sp18;
    M2C_FIELD(temp_r3_1680, f64 *, 0x598) = (f64) (M2C_FIELD(temp_r3_1680, f64 *, 0x598) + temp_f0_1684);
    temp_r3_1680->unk59C += (f32) sp58;
    temp_r3_1703 = this->unkC;
    sp20 = M2C_FIELD(temp_r3_1703, f64 *, 0x598) * (f64) gUpdateTimeDelta;
    temp_r3_1709 = temp_r3_1703->unk8;
    temp_f1_1713 = M2C_FIELD(temp_r3_1709, f64 *, 0x30);
    sp30 = sp20;
    sp28 = temp_r3_1703->unk59C * gUpdateTimeDelta;
    sp40 = temp_f1_1713;
    sp38 = (f64) sp28;
    sp48 = M2C_FIELD(temp_r3_1709, f64 *, 0x38);
    sp40 = temp_f1_1713 + sp30;
    sp70 = sp40;
    sp60 = M2C_FIELD(&MKVector3::up, f64 *, 0);
    sp48 = (f32) sp48 + (f32) sp38;
    sp68 = M2C_FIELD(&MKVector3::up, f64 *, 8);
    sp78 = (f64) sp48;
    M2C_STRUCT_COPY((s32) &sp7C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    KDMath_BuildMatrixFromFwd(&sp80, *((MKVector3 *) &this->unkC->unkC0), (MKVector3 *) &sp60);
    sp80.unk30 = (f32) sp70;
    sp80.unk34 = unksp74;
    sp80.unk38 = (f32) sp78;
    sp80.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unkC->unk4, sp80);
    temp_r29_1768 = this->unkC;
    var_r30_1769 = 0;
    if (temp_r29_1768->HasAnimFinished() != 0) {
        temp_r4_1774 = temp_r29_1768->unkA50;
        if ((temp_r4_1774 != NULL) && ((u32) *temp_r4_1774 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_1768, void **, 0x630), u32 *, 0x20))) {
            var_r30_1769 = 1;
        }
    }
    if (var_r30_1769 != 0) {
        this->unkC->SetAnim((AnimSequenceType) 3, 0x1F, 1, 0.15f, 0U, 0U);
    }
    unksp74 += 50.0f;
    Tools_TestFloor(*((MKVector3 *) &sp70), NULL, 250.0f, (MKCollisionMode) 5);
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'AnimSequenceType' to
void EnemyGoal_DyingAirborn::Activate() {
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
    Character *temp_r3_1834;
    Character *temp_r3_1850;
    Character *temp_r3_1858;

    this->unk8 = 0;
    temp_r3_1834 = this->unkC;
    temp_r3_1834->unk6B5 |= 2;
    this->unkC->SetMovementType((CharacterMoveType) 2);
    sp18 = 0.0f;
    sp1C = 2000.0f;
    temp_r3_1850 = this->unkC;
    sp20 = 0.0f;
    M2C_FIELD(temp_r3_1850, f64 *, 0x598) = (f64) sp18;
    M2C_FIELD(temp_r3_1850, f64 *, 0x5A0) = (f64) sp20;
    sp10 = 0.0f;
    temp_r3_1858 = this->unkC;
    sp8 = 0.0f;
    spC = -2940.0002f;
    sp38 = (f64) sp18;
    M2C_FIELD(temp_r3_1858, f64 *, 0x5A8) = (f64) sp8;
    M2C_FIELD(temp_r3_1858, f64 *, 0x5B0) = (f64) sp10;
    sp40 = (f64) sp20;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    this->unkC->SetAnim((AnimSequenceType) 3, 0x1F, 0, 0.15f, 0U, 0U);
}
#endif

u8 EnemyGoal_DyingStoned::Update() {
    ActivateIfInactive();
    this->unk8 = 2;
    return this->unk8;
}

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void EnemyGoal_DyingStoned::Activate() {
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
    Enemy *temp_r3_1936;
    Enemy *temp_r3_2003;
    f32 temp_f28_1984;
    f32 temp_f28_2025;
    f32 temp_f29_1979;
    f32 temp_f29_2030;
    f64 temp_f0_1946;
    f64 temp_f0_1998;
    f64 temp_f0_2011;
    f64 temp_f0_2044;
    s32 var_r30_1972;
    void *temp_r3_1921;

    this->unk8 = 0;
    this->unkC->ThawIfFrozen();
    temp_r3_1921 = checked_cast<Shatterable *, MKProp>(((MKPropDescriptor *) (M2C_FIELD(this->unkC->unkA20, MKPropDescriptor **, 0x254)))->CreateInstance());
    if (temp_r3_1921 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r3_1921, void **, 0x44), M2C_UNK (**)(), 0x20)();
        M2C_FIELD(M2C_FIELD(temp_r3_1921, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_1921);
        sp70 = 0.0f;
        temp_r3_1936 = this->unkC;
        sp74 = 200.0f;
        sp78 = 0.0f;
        spB0 = (f64) sp70;
        spB8 = (f64) sp78;
        temp_f0_1946 = M2C_FIELD(temp_r3_1936, f64 *, 0x588) + spB0;
        sp60 = temp_f0_1946;
        spC0 = temp_f0_1946;
        sp68 = temp_r3_1936->unk588.unk4 + (f32) spB8;
        spC8 = (f64) sp68;
        MKModel_SetPosition(M2C_FIELD(temp_r3_1921, MKModel **, 4), *((MKVector3 *) &spC0));
        M2C_FIELD(M2C_FIELD(temp_r3_1921, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x94)(temp_r3_1921, 0, 0, -1, 0, 1, 0);
    }
    var_r30_1972 = 0;
    do {
        temp_f29_1979 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f28_1984 = MKRand_Float(&gViewSeed, 0.0f, 3.0f);
        sp50 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp54 = temp_f28_1984;
        sp58 = temp_f29_1979;
        sp90 = (f64) sp50;
        sp98 = (f64) sp58;
        temp_f0_1998 = sp90 * 5.53552857e-315;
        sp40 = temp_f0_1998;
        temp_r3_2003 = this->unkC;
        spA0 = temp_f0_1998;
        sp48 = (f32) sp98 * 100.0f;
        spA8 = (f64) sp48;
        temp_f0_2011 = M2C_FIELD(temp_r3_2003, f64 *, 0x588) + temp_f0_1998;
        sp30 = temp_f0_2011;
        spE0 = temp_f0_2011;
        sp38 = temp_r3_2003->unk588.unk4 + (f32) spA8;
        spE8 = (f64) sp38;
        temp_f28_2025 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f29_2030 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp20 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp24 = temp_f29_2030;
        sp28 = temp_f28_2025;
        sp80 = (f64) sp20;
        sp88 = (f64) sp28;
        temp_f0_2044 = sp80 * 5.60222949e-315;
        sp10 = temp_f0_2044;
        spD0 = temp_f0_2044;
        sp18 = (f32) sp88 * 300.0f;
        spD8 = (f64) sp18;
        sp8 = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
        gb.EmitDust(*((MKVector3 *) &spE0), *((MKVector3 *) &spD0), sp8, 0.0f);
        var_r30_1972 += 1;
    } while (var_r30_1972 < 5);
}
#endif

void EnemyGoal_DyingFrozen::Terminate() {
    this->unk8 = 1;
    this->unkC->ThawIfFrozen();
}

u8 EnemyGoal_DyingFrozen::Update() {
    Enemy *temp_r4_2107;
    u8 var_r3_2108;

    ActivateIfInactive();
    temp_r4_2107 = this->unkC;
    var_r3_2108 = 0;
    if (((s32) temp_r4_2107->unk750.unk68 == 0) && ((u8) M2C_FIELD(temp_r4_2107, u8 *, 0x7F4) != 0)) {
        var_r3_2108 = 1;
    }
    if (var_r3_2108 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: expression syntax error
void EnemyGoal_DyingFrozen::Activate() {
    Enemy *temp_r3_2167;
    Enemy *temp_r3_2174;
    Enemy *temp_r3_2186;
    Enemy *temp_r6_2144;
    s32 var_r5_2145;

    this->unk8 = 0;
    this->unkC->unk740.SetCrumble(lit_816);
    temp_r6_2144 = this->unkC;
    var_r5_2145 = 0x1E;
    if (((u8) M2C_FIELD(temp_r6_2144, u8 *, 0xB08) >> 3U) & 1) {
        var_r5_2145 = 0x20;
    } else if (((u8) temp_r6_2144->unk6B5 >> 4U) & 1) {
        var_r5_2145 = 0x1F;
        M2C_FIELD(temp_r6_2144, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r6_2144, f64 *, 0xC0);
        M2C_FIELD(temp_r6_2144, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r6_2144, f64 *, 0xC8);
        temp_r6_2144->unk6B5 |= 0x40;
        temp_r3_2167 = this->unkC;
        M2C_FIELD(temp_r3_2167, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(temp_r3_2167, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        temp_r3_2167->unk6B5 |= 0x40;
    }
    temp_r3_2174 = this->unkC;
    temp_r3_2174->unk6B5 &= ~0x10;
    this->unkC->SetAnim((AnimSequenceType) 3, var_r5_2145, 0, 0.15f, 0U, 0U);
    temp_r3_2186 = this->unkC;
    if ((s32) temp_r3_2186->unk680 != 2) {
        temp_r3_2186->SetMovementType((CharacterMoveType) 0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk750'
u8 EnemyGoal_DyingBurnt::Update() {
    MKCollisionResult sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    u8 spC;
    void *sp8;
    Character *temp_r29_2231;
    Character *temp_r29_2272;
    Character *temp_r3_2252;
    Character *temp_r3_2294;
    Character *temp_r3_2337;
    Character *temp_r4_2209;
    Character *temp_r4_2314;
    CharacterFireFX *temp_r3_2221;
    f64 temp_f0_2320;
    u32 *temp_r4_2240;
    u32 *temp_r4_2253;
    u32 *temp_r4_2278;
    u32 *temp_r4_2295;
    u8 var_r30_2236;
    u8 var_r30_2273;
    u8 var_r3_2210;
    void *temp_r4_2305;

    ActivateIfInactive();
    temp_r4_2209 = this->unkC;
    var_r3_2210 = 0;
    if (((s32) temp_r4_2209->unk750.unk78 == 0) && ((u8) temp_r4_2209->unk750.unkA4 != 0)) {
        var_r3_2210 = 1;
    }
    if (var_r3_2210 != 0) {
        temp_r3_2221 = temp_r4_2209->unkA08;
        if (temp_r3_2221 != NULL) {
            temp_r3_2221->Enable(0U, 1.0f);
        }
        this->unk8 = 2;
    }
    temp_r29_2231 = this->unkC;
    if ((u32 *) temp_r29_2231->unkA50 != NULL) {
        var_r30_2236 = 0;
        if (temp_r29_2231->HasAnimFinished() != 0) {
            temp_r4_2240 = temp_r29_2231->unkA50;
            if ((temp_r4_2240 != NULL) && ((u32) *temp_r4_2240 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_2231, void **, 0x630), u32 *, 0x20))) {
                var_r30_2236 = 1;
            }
        }
        if (var_r30_2236 != 0) {
            temp_r3_2252 = this->unkC;
            temp_r4_2253 = temp_r3_2252->unkA50;
            if ((u32) M2C_FIELD(temp_r4_2253, u32 *, 0x20) != 0U) {
                temp_r3_2252->SetAnim((AnimSequence *) temp_r4_2253, (AnimTransition *) (temp_r4_2253 + 0x20), 0.15f, 0U);
            } else if ((u32) M2C_FIELD(temp_r4_2253, u32 *, 0x40) != 0U) {
                temp_r3_2252->SetAnim((AnimSequence *) temp_r4_2253, (AnimTransition *) (temp_r4_2253 + 0x40), 0.15f, 0U);
            }
        } else {
            temp_r29_2272 = this->unkC;
            var_r30_2273 = 0;
            if (temp_r29_2272->HasAnimFinished() != 0) {
                temp_r4_2278 = temp_r29_2272->unkA50;
                if ((temp_r4_2278 != NULL) && ((u32) M2C_FIELD(temp_r4_2278, u32 *, 0x40) == (u32) M2C_FIELD(M2C_FIELD(temp_r29_2272, void **, 0x630), u32 *, 0x20))) {
                    var_r30_2273 = 1;
                }
            }
            if ((var_r30_2273 == 0) && (this->unkC->HasAnimFinished() != 0)) {
                temp_r3_2294 = this->unkC;
                temp_r4_2295 = temp_r3_2294->unkA50;
                if ((u32) M2C_FIELD(temp_r4_2295, u32 *, 0x40) != 0U) {
                    temp_r3_2294->SetAnim((AnimSequence *) temp_r4_2295, (AnimTransition *) (temp_r4_2295 + 0x40), 0.15f, 0U);
                }
            }
        }
        temp_r4_2305 = this->unkC->unk634;
        sp8 = temp_r4_2305;
        if (temp_r4_2305 != NULL) {
            spC = M2C_FIELD(temp_r4_2305, u8 *, 4);
            M2C_FIELD(temp_r4_2305, u8 *, 4) = 0U;
        }
        temp_r4_2314 = this->unkC;
        temp_f0_2320 = M2C_FIELD(temp_r4_2314, f64 *, 0x588) + M2C_FIELD(temp_r4_2314, f64 *, 0x90);
        sp10 = temp_f0_2320;
        sp20 = temp_f0_2320;
        sp18 = temp_r4_2314->unk588.unk4 + temp_r4_2314->unk98;
        sp28 = (f64) sp18;
        if (MKCollision_RayCollide(*((MKVector3 *) &temp_r4_2314->unk588), *((MKVector3 *) &sp20), &sp30, (MKCollisionMode) 7, M2C_FIELD(temp_r4_2314->unk110.unk460, s32 *, 0x18)) != 0) {
            temp_r3_2337 = this->unkC;
            M2C_FIELD(temp_r3_2337, f64 *, 0x588) = M2C_BITWISE(f64, sp30);
            M2C_FIELD(temp_r3_2337, f32 *, 0x590) = (f64) sp30.unk8;
        }
        if (sp8 != NULL) {
            M2C_FIELD(sp8, u8 *, 4) = spC;
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'ThawIfFrozen'
void EnemyGoal_DyingBurnt::Activate() {
    Character *temp_r3_2401;
    Character *temp_r3_2408;
    Character *temp_r3_2420;
    Character *temp_r6_2378;
    s32 var_r5_2379;

    this->unk8 = 0;
    this->unkC->ThawIfFrozen();
    this->unkC->unk750.SetState(lit_773, 1.0f);
    this->unkC->unk750.SetCrumble(lit_774);
    temp_r6_2378 = this->unkC;
    var_r5_2379 = 0x1E;
    if (((u8) temp_r6_2378->unkB08 >> 3U) & 1) {
        var_r5_2379 = 0x20;
    } else if (((u8) temp_r6_2378->unk6B5 >> 4U) & 1) {
        var_r5_2379 = 0x1F;
        M2C_FIELD(temp_r6_2378, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r6_2378, f64 *, 0xC0);
        M2C_FIELD(temp_r6_2378, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r6_2378, f64 *, 0xC8);
        temp_r6_2378->unk6B5 |= 0x40;
        temp_r3_2401 = this->unkC;
        M2C_FIELD(temp_r3_2401, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(temp_r3_2401, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        temp_r3_2401->unk6B5 |= 0x40;
    }
    temp_r3_2408 = this->unkC;
    temp_r3_2408->unk6B5 &= ~0x10;
    this->unkC->SetAnim((AnimSequenceType) 3, var_r5_2379, 0, 0.15f, 0U, 0U);
    temp_r3_2420 = this->unkC;
    if (((u8) temp_r3_2420->unkB08 >> 2U) & 1) {
        temp_r3_2420->unk588.unkC = 0.0f;
        temp_r3_2420->unk598 = 0.0f;
        temp_r3_2420->unk59C = 0.0f;
        this->unkC->SetMovementType((CharacterMoveType) 1);
        KDSound_Play3d(GS_Emergency1, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        return;
    }
    if ((s32) temp_r3_2420->unk680 != 2) {
        temp_r3_2420->SetMovementType((CharacterMoveType) 0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA50'
u8 EnemyGoal_DyingDefault::Update() {
    MKCollisionResult sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    u8 spC;
    void *sp8;
    Character *temp_r29_2464;
    Character *temp_r29_2509;
    Character *temp_r3_2485;
    Character *temp_r3_2535;
    Character *temp_r3_2578;
    Character *temp_r4_2555;
    f64 temp_f0_2561;
    u32 *temp_r4_2473;
    u32 *temp_r4_2486;
    u32 *temp_r4_2515;
    u32 *temp_r4_2536;
    u8 var_r30_2469;
    u8 var_r30_2510;
    void *temp_r4_2546;

    ActivateIfInactive();
    temp_r29_2464 = this->unkC;
    if ((u32 *) temp_r29_2464->unkA50 != NULL) {
        var_r30_2469 = 0;
        if (temp_r29_2464->HasAnimFinished() != 0) {
            temp_r4_2473 = temp_r29_2464->unkA50;
            if ((temp_r4_2473 != NULL) && ((u32) *temp_r4_2473 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_2464, void **, 0x630), u32 *, 0x20))) {
                var_r30_2469 = 1;
            }
        }
        if (var_r30_2469 != 0) {
            temp_r3_2485 = this->unkC;
            temp_r4_2486 = temp_r3_2485->unkA50;
            if ((u32) M2C_FIELD(temp_r4_2486, u32 *, 0x20) != 0U) {
                temp_r3_2485->SetAnim((AnimSequence *) temp_r4_2486, (AnimTransition *) (temp_r4_2486 + 0x20), 0.15f, 0U);
            } else if ((u32) M2C_FIELD(temp_r4_2486, u32 *, 0x40) != 0U) {
                temp_r3_2485->SetAnim((AnimSequence *) temp_r4_2486, (AnimTransition *) (temp_r4_2486 + 0x40), 0.15f, 0U);
            } else {
                this->unk8 = 2;
            }
        } else {
            temp_r29_2509 = this->unkC;
            var_r30_2510 = 0;
            if (temp_r29_2509->HasAnimFinished() != 0) {
                temp_r4_2515 = temp_r29_2509->unkA50;
                if ((temp_r4_2515 != NULL) && ((u32) M2C_FIELD(temp_r4_2515, u32 *, 0x40) == (u32) M2C_FIELD(M2C_FIELD(temp_r29_2509, void **, 0x630), u32 *, 0x20))) {
                    var_r30_2510 = 1;
                }
            }
            if (var_r30_2510 != 0) {
                this->unk8 = 2;
            } else if (this->unkC->HasAnimFinished() != 0) {
                temp_r3_2535 = this->unkC;
                temp_r4_2536 = temp_r3_2535->unkA50;
                if ((u32) M2C_FIELD(temp_r4_2536, u32 *, 0x40) != 0U) {
                    temp_r3_2535->SetAnim((AnimSequence *) temp_r4_2536, (AnimTransition *) (temp_r4_2536 + 0x40), 0.15f, 0U);
                }
            }
        }
        temp_r4_2546 = this->unkC->unk634;
        sp8 = temp_r4_2546;
        if (temp_r4_2546 != NULL) {
            spC = M2C_FIELD(temp_r4_2546, u8 *, 4);
            M2C_FIELD(temp_r4_2546, u8 *, 4) = 0U;
        }
        temp_r4_2555 = this->unkC;
        temp_f0_2561 = M2C_FIELD(temp_r4_2555, f64 *, 0x588) + M2C_FIELD(temp_r4_2555, f64 *, 0x90);
        sp10 = temp_f0_2561;
        sp20 = temp_f0_2561;
        sp18 = temp_r4_2555->unk588.unk4 + temp_r4_2555->unk98;
        sp28 = (f64) sp18;
        if (MKCollision_RayCollide(*((MKVector3 *) &temp_r4_2555->unk588), *((MKVector3 *) &sp20), &sp30, (MKCollisionMode) 7, M2C_FIELD(temp_r4_2555->unk110.unk460, s32 *, 0x18)) != 0) {
            temp_r3_2578 = this->unkC;
            M2C_FIELD(temp_r3_2578, f64 *, 0x588) = M2C_BITWISE(f64, sp30);
            M2C_FIELD(temp_r3_2578, f32 *, 0x590) = (f64) sp30.unk8;
        }
        if (sp8 != NULL) {
            M2C_FIELD(sp8, u8 *, 4) = spC;
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'ThawIfFrozen'
void EnemyGoal_DyingDefault::Activate() {
    Character *temp_r3_2610;
    Character *temp_r3_2622;
    Character *temp_r3_2651;
    Character *temp_r3_2658;
    Character *temp_r3_2670;
    Character *temp_r6_2628;
    s32 var_r5_2629;

    this->unk8 = 0;
    this->unkC->ThawIfFrozen();
    temp_r3_2610 = this->unkC;
    if (((u8) temp_r3_2610->unkB02 >> 4U) & 1) {
        KDSound_Play3d(GS_EnemyLavaBurn, temp_r3_2610->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        temp_r3_2622 = this->unkC;
        temp_r3_2622->unkB02 &= ~0x10;
    }
    temp_r6_2628 = this->unkC;
    var_r5_2629 = 0x1E;
    if (((u8) temp_r6_2628->unkB08 >> 3U) & 1) {
        var_r5_2629 = 0x20;
    } else if (((u8) temp_r6_2628->unk6B5 >> 4U) & 1) {
        var_r5_2629 = 0x1F;
        M2C_FIELD(temp_r6_2628, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r6_2628, f64 *, 0xC0);
        M2C_FIELD(temp_r6_2628, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r6_2628, f64 *, 0xC8);
        temp_r6_2628->unk6B5 |= 0x40;
        temp_r3_2651 = this->unkC;
        M2C_FIELD(temp_r3_2651, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(temp_r3_2651, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        temp_r3_2651->unk6B5 |= 0x40;
    }
    temp_r3_2658 = this->unkC;
    temp_r3_2658->unk6B5 &= ~0x10;
    this->unkC->SetAnim((AnimSequenceType) 3, var_r5_2629, 0, 0.15f, 0U, 0U);
    temp_r3_2670 = this->unkC;
    if ((s32) temp_r3_2670->unk680 != 2) {
        temp_r3_2670->SetMovementType((CharacterMoveType) 0);
    }
}
#endif
