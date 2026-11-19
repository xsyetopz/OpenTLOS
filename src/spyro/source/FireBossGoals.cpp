#include "spyro/source/FireBossGoals.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Character.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/Enemies_FireBoss.h"
#include "spyro/source/Enemies_FireBossDriver.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/SteamTrain.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(s32);                                  /* extern */
s32 malloc(M2C_UNK);                                /* extern */
extern s32 GS_Train3;
extern s32 GS_TrainTurnSqueal1;
extern s32 GS_TrainTurnSqueal2;
extern f32 *KDSpline_PositionMixer;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: pointer/array required
u8 FireBossGoal_Think::Update() {
    EnemyDamageFeedback sp28;
    EnemyHudData sp8;
    f32 temp_f31_39;
    s32 temp_r0_20;
    s32 temp_r30_38;
    s32 temp_r3_105;
    s32 temp_r3_112;
    s32 temp_r3_19;
    s32 temp_r3_37;
    s32 temp_r3_82;
    s32 temp_r4_48;
    s32 temp_r4_81;
    s32 temp_r4_91;
    s32 var_r0_92;
    void ***var_r3_87;
    void **temp_r3_101;

    ActivateIfInactive();
    temp_r3_19 = this->unkC;
    temp_r0_20 = M2C_FIELD(temp_r3_19, s32 *, 0xB10);
    if ((temp_r0_20 >= 0) && (temp_r0_20 <= 3)) {
        temp_r3_19->SelectTarget();
    }
    if (this->unkC->WasHit() != 0) {
        sp28.Init();
        this->unkC->TakeDamage(&sp28, 0U);
        temp_r3_37 = this->unkC;
        temp_r30_38 = M2C_FIELD(temp_r3_37, s32 *, 0xB10);
        temp_f31_39 = M2C_FIELD(temp_r3_37, f32 *, 0xAC8);
        if (temp_r30_38 != 4) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_f31_39 == 0.0f) {
                M2C_FIELD(temp_r3_37, s32 *, 0xB10) = (s32) (temp_r30_38 + 1);
                temp_r4_48 = this->unkC;
                if ((s32) M2C_FIELD(temp_r4_48, s32 *, 0xB10) != 4) {
                    M2C_FIELD(temp_r4_48, s32 *, 0xAE8) = (s32) (M2C_FIELD(temp_r4_48, s32 *, 0xAE8) + 1);
                    this->unkC->GetMaxHealth();
                    this->unkC->SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
                }
            }
        }
        if (temp_r30_38 != (s32) M2C_FIELD(this->unkC, s32 *, 0xB10)) {
            if ((IsActive(0x71) != 0) || (IsActive(0x6F) != 0)) {
                temp_r4_81 = this->unk14;
                temp_r3_82 = temp_r4_81 - 1;
                if ((temp_r3_82 < 0) || (temp_r3_82 >= temp_r4_81)) {
                    var_r3_87 = NULL;
                } else {
                    temp_r4_91 = this->unk10;
                    var_r0_92 = this->unk18 + temp_r3_82;
                    if (var_r0_92 >= temp_r4_91) {
                        var_r0_92 -= temp_r4_91;
                    }
                    var_r3_87 = this->unk1C + (var_r0_92 * 4);
                }
                temp_r3_101 = *var_r3_87;
                temp_r3_105 = M2C_FIELD(*temp_r3_101, s32 (**)(void **), 0x34)(temp_r3_101);
                if (temp_r3_105 < 0x6E) {
                    if (temp_r3_105 < 0x6A) {

                    } else {
                        temp_r3_112 = this->unk14;
                        if (temp_r3_112 > 0) {
                            this->unk14 = temp_r3_112 - 1;
                        }
                    }
                }
            } else {
                RemoveAllSubgoals();
            }
            AddSubgoal__24CompositeGoal<8FireBoss>FP15Goal<8FireBoss>((CompositeGoal<FireBoss> *) this, M2C_FIELD((this + (M2C_FIELD(this->unkC, s32 *, 0xB10) * 4)), Goal<FireBoss> **, 0x3C));
        }
        sp8.EnemyHudData();
        this->unkC->GetMaxHealth();
        sp8.Init((Enemy *) this->unkC, temp_f31_39, M2C_ERROR(/* Read from unset register $f1 */));
        EnemyHud_Modified(sp8);
    }
    this->unk8 = UpdateSubgoals();
    if (((u8) this->unk8 == 2) && ((s32) this->unk14 <= 1)) {
        Activate();
    }
    return (u8) this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp30'
void FireBossGoal_Think::Activate() {
    f32 temp_f1_197;
    f32 temp_f31_209;
    s32 temp_r3_189;
    s32 temp_r3_208;
    s32 temp_r4_223;
    this->unk8 = 0;
    RemoveAllSubgoals();
    if (!(((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 7U) & 1)) {
        arg_sp30.SetIdentity();
        temp_r3_189 = this->unkC;
        arg_sp60 = M2C_FIELD(temp_r3_189, f32 *, 0x5B8);
        arg_sp64 = M2C_FIELD(temp_r3_189, f32 *, 0x5BC);
        temp_f1_197 = M2C_FIELD(temp_r3_189, f32 *, 0x5C0);
        arg_sp68 = temp_f1_197;
        arg_sp6C = 1.0f;
        if (M2C_FIELD(M2C_FIELD(temp_r3_189, void **, 0x44), u8 (**)(s32, M2C_UNK *, M2C_UNK, f32), 0x120)(temp_r3_189, &arg_sp30, 0, temp_f1_197) != 0) {
            arg_sp10.EnemyHudData();
            temp_r3_208 = this->unkC;
            temp_f31_209 = M2C_FIELD(temp_r3_208, f32 *, 0xAC8);
            temp_r3_208->GetMaxHealth();
            arg_sp10.Init((Enemy *) this->unkC, temp_f31_209, M2C_ERROR(/* Read from unset register $f1 */));
            EnemyHud_Modified(*((EnemyHudData *) &arg_sp10));
            M2C_FIELD(&gb, s32 *, 0x360) = (s32) this->unkC;
        }
    }
    temp_r4_223 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_223, u8 *, 0xC42) != 0) {
        M2C_FIELD(temp_r4_223, u8 *, 0xC42) = 0U;
        AddSubgoal__24CompositeGoal<8FireBoss>FP15Goal<8FireBoss>((CompositeGoal<FireBoss> *) this, (Goal<FireBoss> *) this->unk34);
        AddSubgoal__24CompositeGoal<8FireBoss>FP15Goal<8FireBoss>((CompositeGoal<FireBoss> *) this, (Goal<FireBoss> *) this->unk38);
        return;
    }
    AddSubgoal__24CompositeGoal<8FireBoss>FP15Goal<8FireBoss>((CompositeGoal<FireBoss> *) this, M2C_FIELD((this + (M2C_FIELD(temp_r4_223, s32 *, 0xB10) * 4)), Goal<FireBoss> **, 0x3C));
}
#endif

void FireBossGoal_Think::Reset() {
    void *temp_r3_268;
    void *temp_r3_274;

    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk50 = 1;
    temp_r3_268 = M2C_FIELD(this->unkC, void **, 0xF64);
    M2C_FIELD(M2C_FIELD(temp_r3_268, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_268);
    temp_r3_274 = M2C_FIELD(this->unkC, void **, 0xF64);
    M2C_FIELD(M2C_FIELD(temp_r3_274, void **, 0x44), M2C_UNK (**)(void *), 0x54)(temp_r3_274);
}

void FireBossGoal_Think::Deinit() {
    Goal<FireBoss> *temp_r3_314;
    Goal<FireBoss> *temp_r3_319;
    MKHeap *temp_r3_346;
    s32 temp_r31_343;
    void **temp_r3_294;
    void **temp_r3_299;
    void **temp_r3_304;
    void **temp_r3_309;
    void **temp_r3_324;

    temp_r3_294 = this->unk20;
    M2C_FIELD(*temp_r3_294, M2C_UNK (**)(void **), 0xC)(temp_r3_294);
    temp_r3_299 = this->unk24;
    M2C_FIELD(*temp_r3_299, M2C_UNK (**)(void **), 0xC)(temp_r3_299);
    temp_r3_304 = this->unk28;
    M2C_FIELD(*temp_r3_304, M2C_UNK (**)(void **), 0xC)(temp_r3_304);
    temp_r3_309 = this->unk2C;
    M2C_FIELD(*temp_r3_309, M2C_UNK (**)(void **), 0xC)(temp_r3_309);
    temp_r3_314 = this->unk34;
    temp_r3_314->Deinit();
    temp_r3_319 = this->unk38;
    temp_r3_319->Deinit();
    temp_r3_324 = this->unk30;
    M2C_FIELD(*temp_r3_324, M2C_UNK (**)(void **), 0xC)(temp_r3_324);
    operator delete(this->unk20);
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk34);
    operator delete(this->unk38);
    operator delete(this->unk30);
    temp_r31_343 = this->unk1C;
    if ((u32) temp_r31_343 != 0U) {
        temp_r3_346 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_346 != NULL) {
            ((MKHeap *) (temp_r3_346->Current()))->Free((void *) temp_r31_343, NULL, 0);
        } else {
            free(temp_r31_343);
        }
        this->unk1C = 0;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = 0;
    this->unk9 = 0;
    M2C_FIELD(&gb, s32 *, 0x360) = 0;
}

#if 0 // DRAFT: pointer/array required
void FireBossGoal_Think::Init(FireBoss *arg0) {
    Goal<FireBoss> *temp_r4_607;
    Goal<FireBoss> *temp_r4_618;
    MKHeap *temp_r3_536;
    void **temp_r4_563;
    void **temp_r4_574;
    void **temp_r4_585;
    void **temp_r4_596;
    void **temp_r4_629;
    void *var_r3_543;

    if ((u8) this->unk9 == 0) {
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__15Goal<8FireBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__15Goal<8FireBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__15Goal<8FireBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__15Goal<8FireBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__15Goal<8FireBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__15Goal<8FireBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__15Goal<8FireBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_536 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_536 != NULL) {
            var_r3_543 = ((MKHeap *) (temp_r3_536->Current()))->Alloc(0xC, NULL, 0);
        } else {
            var_r3_543 = malloc(0xC);
        }
        this->unk1C = (s32) var_r3_543;
        this->unk10 = 3;
    }
    this->unk8 = 1;
    this->unkC = (s32) arg0;
    this->unk4 = 0x73;
    if ((u32) this->unkC != 0U) {
        this->unk9 = 1;
    }
    temp_r4_563 = this->unk20;
    M2C_FIELD(temp_r4_563, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_563, FireBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_563, s32 *, 4) = 0x6A;
    if ((FireBoss *) M2C_FIELD(temp_r4_563, FireBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_563, s8 *, 9) = 1;
    }
    temp_r4_574 = this->unk24;
    M2C_FIELD(temp_r4_574, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_574, FireBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_574, s32 *, 4) = 0x6B;
    if ((FireBoss *) M2C_FIELD(temp_r4_574, FireBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_574, s8 *, 9) = 1;
    }
    temp_r4_585 = this->unk28;
    M2C_FIELD(temp_r4_585, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_585, FireBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_585, s32 *, 4) = 0x6C;
    if ((FireBoss *) M2C_FIELD(temp_r4_585, FireBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_585, s8 *, 9) = 1;
    }
    temp_r4_596 = this->unk2C;
    M2C_FIELD(temp_r4_596, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_596, FireBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_596, s32 *, 4) = 0x6D;
    if ((FireBoss *) M2C_FIELD(temp_r4_596, FireBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_596, s8 *, 9) = 1;
    }
    temp_r4_607 = this->unk34;
    M2C_FIELD(temp_r4_607, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_607, FireBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_607, s32 *, 4) = 0x71;
    if ((FireBoss *) M2C_FIELD(temp_r4_607, FireBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_607, s8 *, 9) = 1;
    }
    temp_r4_618 = this->unk38;
    M2C_FIELD(temp_r4_618, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_618, FireBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_618, s32 *, 4) = 0x6F;
    if ((FireBoss *) M2C_FIELD(temp_r4_618, FireBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_618, s8 *, 9) = 1;
    }
    temp_r4_629 = this->unk30;
    M2C_FIELD(temp_r4_629, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_629, FireBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_629, s32 *, 4) = 0x72;
    if ((FireBoss *) M2C_FIELD(temp_r4_629, FireBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_629, s8 *, 9) = 1;
    }
    this->unk3C = this->unk20;
    this->unk40 = this->unk24;
    this->unk44 = this->unk28;
    this->unk48 = this->unk2C;
    this->unk4C = this->unk30;
}
#endif

void FireBossGoal_Death::Terminate() {
    M2C_FIELD(this->unkC, f32 *, 0xB20) = 0.0f;
    M2C_FIELD(this->unkC, f32 *, 0xB24) = 0.0f;
    M2C_FIELD(this->unkC, f32 *, 0xB1C) = 0.0f;
    M2C_FIELD(this->unkC, f32 *, 0x68C) = 0.0f;
    M2C_FIELD(this->unkC, s8 *, 0xFCA) = 0;
    M2C_FIELD(this->unkC, s8 *, 0xFCB) = 0;
    M2C_FIELD(this->unkC, s8 *, 0xFC9) = 0;
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'MoveAlongCurrentSpline'
u8 FireBossGoal_Death::Update() {
    f64 sp190;
    f64 sp188;
    f64 sp180;
    KDUniformSpline sp168;
    f64 sp158;
    MKVector3 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    M2C_UNK spF8;
    M2C_UNK spE8;
    MKVector3 spD8;
    MKVector3 spC8;
    MKVector3 spB8;
    M2C_UNK spA8;
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r3_708;
    MKProp *temp_r3_714;
    MKProp *temp_r3_725;
    MKProp *temp_r3_759;
    MKProp *temp_r3_793;
    MKProp *temp_r3_817;
    MKProp *temp_r4_738;
    MKProp *temp_r4_772;
    MKProp *temp_r4_787;
    MKProp *temp_r4_808;
    MKProp *temp_r5_839;
    f32 temp_f1_945;
    f32 var_f0_716;
    s32 var_r28_848;
    u8 temp_r0_774;
    void *temp_r3_773;
    void *temp_r5_858;

    ActivateIfInactive();
    if (M2C_FIELD(&gb, f32 *, 0x30C) > this->unk10) {
        ((SteamTrainEffects *) ((SteamTrainEffects *) (this->unkC + 0xD10)))->EmitBrakingEffects();
        if ((u8) this->unk14 == 0) {
            M2C_FIELD(this->unkC, s8 *, 0xFC9) = 1;
        }
        temp_r3_708 = this->unkC;
        M2C_FIELD(temp_r3_708, f32 *, 0xB24) = (f32) -((M2C_FIELD(temp_r3_708, f32 *, 0xB1C) * gUpdateTimeDelta) - M2C_FIELD(temp_r3_708, f32 *, 0xB24));
        temp_r3_714 = this->unkC;
        var_f0_716 = M2C_FIELD(temp_r3_714, f32 *, 0xB24);
        if (var_f0_716 > 0.0f) {

        } else {
            var_f0_716 = 0.0f;
        }
        M2C_FIELD(temp_r3_714, f32 *, 0xB24) = var_f0_716;
        temp_r3_725 = this->unkC;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((M2C_FIELD(temp_r3_725, f32 *, 0xB20) == 0.0f) && ((u8) this->unk14 == 0) && ((u32) M2C_FIELD(temp_r3_725, u32 *, 0xA44) != 0U)) {
            this->unk14 = 1;
            temp_r4_738 = this->unkC;
            ((EventMessage *) (M2C_FIELD(temp_r4_738, u32 *, 0xA44) + 8))->Send(temp_r4_738);
            M2C_FIELD(this->unkC, s8 *, 0xFC9) = 0;
        }
    }
    if (M2C_FIELD(&gb, f32 *, 0x30C) > this->unk10) {
        M2C_FIELD(this->unkC, f32 *, 0xD24) = 0.0f;
    } else {
        M2C_FIELD(this->unkC, f32 *, 0xD24) = 6.0f;
    }
    temp_r3_759 = this->unkC;
    sp188 = M2C_FIELD(temp_r3_759, f64 *, 0x588);
    sp190 = M2C_FIELD(temp_r3_759, f64 *, 0x590);
    temp_r3_759->MoveAlongCurrentSpline(M2C_FIELD(temp_r3_759, f32 *, 0xB20));
    ((SteamTrainEffects *) ((SteamTrainEffects *) (this->unkC + 0xD10)))->EmitSmoke();
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        temp_r4_772 = this->unkC;
        temp_r3_773 = M2C_FIELD(temp_r4_772, void **, 0xC1C);
        temp_r0_774 = M2C_FIELD(temp_r3_773, u8 *, 0x1D);
        switch ((s32) temp_r0_774) {                /* irregular */
        case 0:
            break;
        case 4:
            M2C_FIELD(temp_r4_772, f32 *, 0xB28) = (f32) M2C_FIELD(temp_r3_773, f32 *, 0x10);
            temp_r4_787 = this->unkC;
            spC = 0.0f;
            sp168.GetMeasure(M2C_FIELD(temp_r4_787, f32 *, 0xB28), M2C_FIELD(temp_r4_787, Matrix **, 0xC14), KDSpline_PositionMixer);
            temp_r3_793 = this->unkC;
            M2C_FIELD(temp_r3_793, f64 *, 0x588) = M2C_BITWISE(f64, sp168);
            M2C_FIELD(temp_r3_793, f64 *, 0x590) = (f64) sp168.unk8;
            M2C_FIELD(this->unkC, s8 *, 0xC42) = 1;
            this->unk8 = 2;
            break;
        default:
            temp_r4_772->InsideEdgeChange();
            break;
        }
    }
    temp_r4_808 = this->unkC;
    sp8 = 0.0f;
    sp158.GetMeasure(M2C_FIELD(temp_r4_808, f32 *, 0xB28), M2C_FIELD(temp_r4_808, Matrix **, 0xC14), KDSpline_PositionMixer);
    temp_r3_817 = this->unkC;
    M2C_FIELD(temp_r3_817, f64 *, 0x588) = sp158;
    M2C_FIELD(temp_r3_817, f64 *, 0x590) = sp160;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp138 = sp58;
    sp60 = M2C_FIELD((this->unkC + 0x588), f32 *, 8) - (f32) sp190;
    sp140 = (f64) sp60;
    Normalise(sp148);
    temp_r5_839 = this->unkC;
    M2C_FIELD(temp_r5_839, f64 *, 0xE0) = M2C_BITWISE(f64, sp148);
    var_r28_848 = 0;
    M2C_FIELD(temp_r5_839, f64 *, 0xE8) = (f64) sp148.unk8;
    M2C_FIELD(temp_r5_839, u8 *, 0x6B5) = (u8) (M2C_FIELD(temp_r5_839, u8 *, 0x6B5) | 0x40);
    do {
        temp_r5_858 = this->unkC->unk8;
        sp38 = -M2C_FIELD(temp_r5_858, f32 *, 0x20);
        sp3C = -M2C_FIELD(temp_r5_858, f32 *, 0x24);
        sp40 = -M2C_FIELD(temp_r5_858, f32 *, 0x28);
        sp88 = (f64) sp38;
        sp90 = (f64) sp40;
        sp98.operator*(400.0f);
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, -1.0f, -1.0f);
        KDRand_Vector(spC8, spB8);
        spD8.operator*(200.0f);
        MKVector(0.0f, 300.0f, 0.0f);
        spF8.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp108 = sp28;
        sp30 = sp100 + spF0;
        sp110 = (f64) sp30;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp118 = sp18;
        sp20 = (f32) sp110 + spD8.unk8;
        sp120 = (f64) sp20;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp128 = sp48;
        sp168.unk10 = sp48;
        sp50 = (f32) sp120 + sp98.unk8;
        sp130 = (f64) sp50;
        sp180 = (f64) sp50;
        sp10 = MKRand_Float(&gViewSeed, 10.0f, 15.0f);
        temp_f1_945 = MKRand_Float(&gViewSeed, 1000.0f, 1500.0f);
        sp70 = 0.0f;
        sp68 = 0.0f;
        sp6C = temp_f1_945;
        sp80 = (f64) sp70;
        sp78 = (f64) sp68;
        ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) &sp168.unk10), *((MKVector3 *) &sp78), sp10);
        var_r28_848 += 1;
    } while (var_r28_848 < 2);
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'SetAnim'
void FireBossGoal_Death::Activate() {
    MKProp *temp_r3_999;

    this->unk8 = 0;
    this->unk10 = 10.0f + M2C_FIELD(&gb, f32 *, 0x30C);
    M2C_FIELD(this->unkC, f32 *, 0xB24) = 1000.0f;
    temp_r3_999 = this->unkC;
    M2C_FIELD(temp_r3_999, f32 *, 0xB1C) = (f32) (2.0f * (0.083333336f * M2C_FIELD(temp_r3_999, f32 *, 0xB24)));
    M2C_FIELD(this->unkC, f32 *, 0x68C) = 3.1415927f;
    this->unkC->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    M2C_FIELD(this->unkC, s8 *, 0xDA0) = 0;
    M2C_FIELD(this->unkC, s32 *, 0x108C) = 5;
    this->unkC->TriggerExplosion();
}
#endif

void FireBossGoal_Turn::Terminate() {
    this->unk8 = 1;
}

u8 FireBossGoal_Turn::Update() {
    FireBoss *temp_r3_1043;

    ActivateIfInactive();
    temp_r3_1043 = this->unkC;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (((temp_r3_1043->unkC8 * temp_r3_1043->unkE8) + ((temp_r3_1043->unkC0 * temp_r3_1043->unkE0) + (temp_r3_1043->unkC4 * temp_r3_1043->unkE4))) == 0.98f) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: illegal type
void FireBossGoal_Turn::Activate() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    FireBoss *temp_r4_1097;
    FireBoss *temp_r4_1101;
    FireBoss *temp_r8_1111;
    f32 temp_f4_1115;
    f32 temp_f5_1123;
    f32 temp_f7_1121;

    this->unk8 = 0;
    M2C_FIELD(this->unkC, f32 *, 0xB20) = 0.0f;
    this->unkC->unkB24 = 100.0f;
    this->unkC->unkB04 = 100.0f;
    this->unkC->unk684 = 3.1415927f;
    this->unkC->unkC20 = (u8 *)1;
    this->unkC->unkC24 = 1;
    temp_r4_1097 = this->unkC;
    Tools_GetClosestSplineTimeXZ((KDUniformSpline *) &temp_r4_1097->unkB20, *((MKVector3 *) &temp_r4_1097->unk588), 0x20);
    temp_r4_1101 = this->unkC;
    this->unkC->SetCurrentEdge(temp_r4_1101->unkC18->GetEdge((KDUniformSpline *) &temp_r4_1101->unkB20, M2C_ERROR(/* Read from unset register $f1 */), 1), M2C_ERROR(/* Read from unset register $f1 */));
    temp_r8_1111 = this->unkC;
    temp_f4_1115 = temp_r8_1111->unkC8;
    temp_f7_1121 = temp_r8_1111->unkC4;
    temp_f5_1123 = temp_r8_1111->unkC0;
    spC = (MKVector3::up.unk8 * temp_f5_1123) - (MKVector3::up.unk0 * temp_f4_1115);
    sp8 = (MKVector3::up.unk4 * temp_f4_1115) - (MKVector3::up.unk8 * temp_f7_1121);
    sp10 = (MKVector3::up.unk0 * temp_f7_1121) - (MKVector3::up.unk4 * temp_f5_1123);
    M2C_FIELD(temp_r8_1111, f64 *, 0xE0) = (f64) sp8;
    M2C_FIELD(temp_r8_1111, f64 *, 0xE8) = (f64) sp10;
    sp18 = (f64) sp8;
    temp_r8_1111->unk6B5 |= 0x40;
    sp20 = (f64) sp10;
    KDSound_Play3d(GS_TrainTurnSqueal1, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    this->unkC->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
}
#endif

void FireBossGoal_Crash::Terminate() {
    M2C_FIELD(this->unkC, f32 *, 0xB20) = 0.0f;
    M2C_FIELD(this->unkC, f32 *, 0xB24) = 0.0f;
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unkA50'
u8 FireBossGoal_Crash::Update() {
    AnimSequence *temp_r4_1196;
    AnimSequence *temp_r4_1211;
    AnimSequence *temp_r4_1246;
    AnimSequence *temp_r4_1259;
    Character *temp_r29_1190;
    Character *temp_r29_1253;
    Character *temp_r3_1208;
    Character *temp_r3_1245;
    Character *temp_r3_1273;
    Character *temp_r5_1218;
    u8 var_r30_1191;
    u8 var_r30_1254;

    ActivateIfInactive();
    temp_r29_1190 = this->unkC;
    var_r30_1191 = 0;
    if (temp_r29_1190->HasAnimFinished() != 0) {
        temp_r4_1196 = temp_r29_1190->unkA50;
        if ((temp_r4_1196 != NULL) && ((u32) temp_r4_1196->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_1190, void **, 0x630), u32 *, 0x20))) {
            var_r30_1191 = 1;
        }
    }
    if (var_r30_1191 != 0) {
        temp_r3_1208 = this->unkC;
        temp_r4_1211 = temp_r3_1208->unkA50;
        temp_r3_1208->SetAnim(temp_r4_1211, (AnimTransition *) &temp_r4_1211->unk20, 0.15f, 0U);
        M2C_FIELD(this->unkC, s8 *, 0xFC9) = 0;
    }
    temp_r5_1218 = this->unkC;
    if (((u32) temp_r5_1218->unkA54 == &temp_r5_1218->unkA50->unk20) && (((s32) M2C_FIELD(M2C_FIELD(temp_r5_1218, void **, 0x630), s32 *, 0x44) >= (s32) (4 - temp_r5_1218->unkB10)) || (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((M2C_FIELD(temp_r5_1218, f32 *, 0xC48) == 20.0f) != 0)))) {
        M2C_FIELD(temp_r5_1218, f32 *, 0xC48) = 0.0f;
        M2C_FIELD(this->unkC, f32 *, 0xB24) = 0.0f;
        M2C_FIELD(this->unkC, f32 *, 0xB1C) = -100.0f;
        temp_r3_1245 = this->unkC;
        temp_r4_1246 = temp_r3_1245->unkA50;
        temp_r3_1245->SetAnim(temp_r4_1246, (AnimTransition *) &temp_r4_1246->unk40, 0.15f, 0U);
        ((FireBossDriver *) (M2C_FIELD(this->unkC, FireBossDriver **, 0xF64)))->CrashExit();
    }
    temp_r29_1253 = this->unkC;
    var_r30_1254 = 0;
    if (temp_r29_1253->HasAnimFinished() != 0) {
        temp_r4_1259 = temp_r29_1253->unkA50;
        if ((temp_r4_1259 != NULL) && ((u32) temp_r4_1259->unk40 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_1253, void **, 0x630), u32 *, 0x20))) {
            var_r30_1254 = 1;
        }
    }
    if (var_r30_1254 != 0) {
        this->unk8 = 2;
        temp_r3_1273 = this->unkC;
        if ((u8) M2C_FIELD(temp_r3_1273, u8 *, 0xC40) != 0) {
            KDSound_Play3d(GS_Train3, temp_r3_1273->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            M2C_FIELD(this->unkC, u8 *, 0xC40) = 0U;
        }
        M2C_FIELD(this->unkC, s8 *, 0xFCA) = 1;
        M2C_FIELD(this->unkC, s8 *, 0xFC9) = 0;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void FireBossGoal_Crash::Activate() {
    this->unk8 = 0;
    M2C_FIELD(this->unkC, f32 *, 0xB20) = 0.0f;
    M2C_FIELD(this->unkC, f32 *, 0xB24) = 0.0f;
    M2C_FIELD(this->unkC, f32 *, 0xB1C) = 0.0f;
    this->unkC->unk684 = 0.0f;
    M2C_FIELD(this->unkC, s8 *, 0xC41) = 0;
    M2C_FIELD(this->unkC, f32 *, 0xD24) = 0.0f;
    M2C_FIELD(this->unkC, s8 *, 0xDA0) = 0;
    M2C_FIELD(this->unkC, s8 *, 0xC45) = 0;
    M2C_FIELD(this->unkC, s8 *, 0xFCA) = 0;
    this->unkC->SetAnim((AnimSequenceType) 2, 0x28, 0, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    ((FireBossDriver *) (M2C_FIELD(this->unkC, FireBossDriver **, 0xF64)))->CrashEnter();
}
#endif

void FireBossGoal_Stage4::Terminate() {
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unkD24'
u8 FireBossGoal_Stage4::Update() {
    f64 sp68;
    f64 sp60;
    f64 sp50;
    f64 sp40;
    MKVector3 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 spC;
    f32 sp8;
    FireBoss *temp_r27_1473;
    FireBoss *temp_r27_1530;
    FireBoss *temp_r3_1385;
    FireBoss *temp_r3_1396;
    FireBoss *temp_r3_1411;
    FireBoss *temp_r3_1440;
    FireBoss *temp_r3_1458;
    FireBoss *temp_r3_1464;
    FireBoss *temp_r3_1550;
    FireBoss *temp_r3_1575;
    FireBoss *temp_r4_1378;
    FireBoss *temp_r4_1389;
    FireBoss *temp_r4_1417;
    FireBoss *temp_r4_1429;
    FireBoss *temp_r4_1544;
    FireBoss *temp_r4_1566;
    FireBoss *temp_r4_1597;
    s32 temp_r3_1483;
    s32 var_ctr_1493;
    s32 var_r29_1492;
    u8 temp_r0_1475;
    u8 temp_r29_1374;
    u8 temp_r30_1379;
    u8 var_r27_1441;
    u8 var_r4_1484;
    void *temp_r3_1474;

    ActivateIfInactive();
    temp_r29_1374 = this->unkC->IsSpyroOnInsideTrack(0);
    temp_r4_1378 = this->unkC;
    temp_r30_1379 = this->unkC->IsSpyroOnInsideTrack(1);
    sp60 = M2C_FIELD(temp_r4_1378, f64 *, 0x588);
    temp_r4_1378->unkD24 = 6.0f;
    temp_r3_1385 = this->unkC;
    sp68 = M2C_FIELD(temp_r4_1378, f64 *, 0x590);
    temp_r3_1385->MoveAlongCurrentSpline(M2C_FIELD(temp_r3_1385, f32 *, 0xB20));
    temp_r4_1389 = this->unkC;
    temp_r4_1389->unkD10.unk230 -= gUpdateTimeDelta;
    temp_r3_1396 = this->unkC;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (temp_r3_1396->unkD10.unk230 == 0.0f) {
        if ((u8) temp_r3_1396->unkD10.unk78 != 0) {
            temp_r3_1396->unkD10.unk230 = temp_r3_1396->unkD10.unk238;
        } else {
            temp_r3_1396->unkD10.unk230 = temp_r3_1396->unkD10.unk234;
        }
        temp_r3_1411 = this->unkC;
        temp_r3_1411->unkD10.unk78 = temp_r3_1411->unkD10.unk78 == 0;
    }
    temp_r4_1417 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_1417->unkC1C, u8 *, 0x1D) == 1) {
        temp_r4_1417->unkD10.EmitSmoke();
    } else {
        temp_r4_1417->unkD10.EmitSteam();
    }
    temp_r4_1429 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_1429->unkC1C, u8 *, 0x1D) == 4) {
        temp_r4_1429->unkD10.EmitBrakingEffects();
        M2C_FIELD(this->unkC, s8 *, 0xFC9) = 1;
    }
    temp_r3_1440 = this->unkC;
    var_r27_1441 = 0;
    if (((u8) M2C_FIELD(temp_r3_1440, u8 *, 0x8B8) == 2) || (temp_r3_1440->unk870.unk30.Get() != NULL)) {
        var_r27_1441 = 1;
    }
    if ((var_r27_1441 != 0) && (temp_r29_1374 == 0) && (temp_r30_1379 == 0)) {
        temp_r3_1458 = this->unkC;
        temp_r3_1458->unkD10.unk228 -= gUpdateTimeDelta;
        temp_r3_1464 = this->unkC;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_r3_1464->unkD10.unk228 == 0.0f) {
            temp_r3_1464->TriggerFireball();
        }
    }
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        temp_r27_1473 = this->unkC;
        temp_r3_1474 = temp_r27_1473->unkC1C;
        temp_r0_1475 = M2C_FIELD(temp_r3_1474, u8 *, 0x1D);
        switch ((s32) temp_r0_1475) {               /* irregular */
        case 0:
            temp_r3_1483 = temp_r27_1473->unkC24;
            var_r4_1484 = 0;
            if ((temp_r3_1483 > 1) && ((temp_r29_1374 != 0) || (temp_r30_1379 != 0))) {
                var_r29_1492 = 0;
                var_ctr_1493 = temp_r3_1483;
                if (temp_r3_1483 > 0) {
loop_27:
                    if ((u8) M2C_FIELD(*(temp_r27_1473 + (var_r29_1492 + 0xC28)), u8 *, 0x1D) == 3) {
                        temp_r27_1473->SetCurrentEdge(M2C_FIELD((temp_r27_1473 + var_r29_1492), FireBossGraphEdge **, 0xC28), temp_r27_1473->CalcEdgeSplineStartTime(M2C_FIELD((temp_r27_1473 + var_r29_1492), FireBossGraphEdge **, 0xC28)));
                        KDSound_Play3d(GS_TrainTurnSqueal2, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                        this->unkC->unkF64->ChargeEnter();
                        var_r4_1484 = 1;
                    } else {
                        var_r29_1492 += 4;
                        var_ctr_1493 -= 1;
                        if (var_ctr_1493 != 0) {
                            goto loop_27;
                        }
                    }
                }
            }
            if (var_r4_1484 == 0) {
                temp_r27_1530 = this->unkC;
                temp_r27_1530->SetCurrentEdge(temp_r27_1530->unkC28, temp_r27_1530->CalcEdgeSplineStartTime(temp_r27_1530->unkC28));
            }
            goto block_34;
        case 4:
            temp_r27_1473->unkB10 = M2C_FIELD(temp_r3_1474, f32 *, 0x10);
            temp_r4_1544 = this->unkC;
            spC = 0.0f;
            sp50.GetMeasure(M2C_BITWISE(f32, temp_r4_1544->unkB10), temp_r4_1544->unkC14, KDSpline_PositionMixer);
            temp_r3_1550 = this->unkC;
            M2C_FIELD(temp_r3_1550, f64 *, 0x588) = sp50;
            M2C_FIELD(temp_r3_1550, f64 *, 0x590) = sp58;
            this->unkC->unkC42 = 1;
            this->unk8 = 2;
            return this->unk8;
        default:
            temp_r27_1473->InsideEdgeChange();
            goto block_34;
        }
    } else {
block_34:
        temp_r4_1566 = this->unkC;
        sp8 = 0.0f;
        sp40.GetMeasure(M2C_BITWISE(f32, temp_r4_1566->unkB10), temp_r4_1566->unkC14, KDSpline_PositionMixer);
        temp_r3_1575 = this->unkC;
        M2C_FIELD(temp_r3_1575, f64 *, 0x588) = sp40;
        M2C_FIELD(temp_r3_1575, f64 *, 0x590) = sp48;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp20 = sp10;
        sp18 = this->unkC->unk588.unk4 - (f32) sp68;
        sp28 = (f64) sp18;
        Normalise(sp30);
        temp_r4_1597 = this->unkC;
        M2C_FIELD(temp_r4_1597, f64 *, 0xE0) = M2C_BITWISE(f64, sp30);
        M2C_FIELD(temp_r4_1597, f64 *, 0xE8) = (f64) sp30.unk8;
        temp_r4_1597->unk6B5 |= 0x40;
        return this->unk8;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void FireBossGoal_Stage4::Activate() {
    FireBoss *temp_r3_1639;

    this->unk8 = 0;
    this->unkC->unkB24 = 2600.0f;
    temp_r3_1639 = this->unkC;
    temp_r3_1639->unkB04 = 0.083333336f * temp_r3_1639->unkB24;
    this->unkC->unk684 = 3.1415927f;
    this->unkC->unkC24 = 3;
    this->unkC->unkD10.unk228 = 1.25f;
    this->unkC->unkD10.unk22C = 1.5f;
    this->unkC->unkD10.unk230 = 2.0f;
    this->unkC->unkD10.unk234 = 1.0f;
    this->unkC->unkD10.unk238 = 2.0f;
    this->unkC->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->unk1074 = 4;
    this->unkC->TriggerExplosion();
}
#endif

void FireBossGoal_Stage3::Terminate() {
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unkD24'
u8 FireBossGoal_Stage3::Update() {
    f64 sp68;
    f64 sp60;
    f64 sp50;
    f64 sp40;
    MKVector3 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 spC;
    f32 sp8;
    FireBoss *temp_r27_1807;
    FireBoss *temp_r27_1868;
    FireBoss *temp_r3_1707;
    FireBoss *temp_r3_1722;
    FireBoss *temp_r3_1737;
    FireBoss *temp_r3_1770;
    FireBoss *temp_r3_1798;
    FireBoss *temp_r3_1888;
    FireBoss *temp_r3_1913;
    FireBoss *temp_r4_1700;
    FireBoss *temp_r4_1711;
    FireBoss *temp_r4_1747;
    FireBoss *temp_r4_1759;
    FireBoss *temp_r4_1788;
    FireBoss *temp_r4_1882;
    FireBoss *temp_r4_1904;
    FireBoss *temp_r4_1935;
    s32 temp_r3_1822;
    s32 var_ctr_1831;
    s32 var_r29_1830;
    u8 temp_r0_1809;
    u8 temp_r29_1696;
    u8 temp_r30_1701;
    u8 var_r27_1771;
    u8 var_r4_1818;
    void *temp_r3_1808;

    ActivateIfInactive();
    temp_r29_1696 = this->unkC->IsSpyroOnInsideTrack(0);
    temp_r4_1700 = this->unkC;
    temp_r30_1701 = this->unkC->IsSpyroOnInsideTrack(1);
    sp60 = M2C_FIELD(temp_r4_1700, f64 *, 0x588);
    temp_r4_1700->unkD24 = 6.0f;
    temp_r3_1707 = this->unkC;
    sp68 = M2C_FIELD(temp_r4_1700, f64 *, 0x590);
    temp_r3_1707->MoveAlongCurrentSpline(M2C_FIELD(temp_r3_1707, f32 *, 0xB20));
    temp_r4_1711 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_1711->unkC1C, u8 *, 0x1D) == 0) {
        temp_r4_1711->unkD10.unk230 -= gUpdateTimeDelta;
        temp_r3_1722 = this->unkC;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_r3_1722->unkD10.unk230 == 0.0f) {
            if ((u8) temp_r3_1722->unkD10.unk78 != 0) {
                temp_r3_1722->unkD10.unk230 = temp_r3_1722->unkD10.unk238;
            } else {
                temp_r3_1722->unkD10.unk230 = temp_r3_1722->unkD10.unk234;
            }
            temp_r3_1737 = this->unkC;
            temp_r3_1737->unkD10.unk78 = temp_r3_1737->unkD10.unk78 == 0;
        }
    } else {
        temp_r4_1711->unkD10.unk78 = 0;
    }
    temp_r4_1747 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_1747->unkC1C, u8 *, 0x1D) == 1) {
        temp_r4_1747->unkD10.EmitSmoke();
    } else {
        temp_r4_1747->unkD10.EmitSteam();
    }
    temp_r4_1759 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_1759->unkC1C, u8 *, 0x1D) == 4) {
        temp_r4_1759->unkD10.EmitBrakingEffects();
        M2C_FIELD(this->unkC, s8 *, 0xFC9) = 1;
    }
    temp_r3_1770 = this->unkC;
    var_r27_1771 = 0;
    if (((u8) M2C_FIELD(temp_r3_1770, u8 *, 0x8B8) == 2) || (temp_r3_1770->unk870.unk30.Get() != NULL)) {
        var_r27_1771 = 1;
    }
    if ((var_r27_1771 != 0) && (temp_r29_1696 == 0) && (temp_r30_1701 == 0)) {
        temp_r4_1788 = this->unkC;
        if ((u8) M2C_FIELD(temp_r4_1788->unkC1C, u8 *, 0x1D) == 0) {
            temp_r4_1788->unkD10.unk228 -= gUpdateTimeDelta;
            temp_r3_1798 = this->unkC;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_r3_1798->unkD10.unk228 == 0.0f) {
                temp_r3_1798->TriggerFireball();
            }
        }
    }
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        temp_r27_1807 = this->unkC;
        temp_r3_1808 = temp_r27_1807->unkC1C;
        temp_r0_1809 = M2C_FIELD(temp_r3_1808, u8 *, 0x1D);
        switch ((s32) temp_r0_1809) {               /* irregular */
        case 0:
            var_r4_1818 = 0;
            if (M2C_FIELD(temp_r27_1807, f32 *, 0xB18) > 1.0f) {
                temp_r3_1822 = temp_r27_1807->unkC24;
                if ((temp_r3_1822 > 1) && ((temp_r29_1696 != 0) || (temp_r30_1701 != 0))) {
                    var_r29_1830 = 0;
                    var_ctr_1831 = temp_r3_1822;
                    if (temp_r3_1822 > 0) {
loop_31:
                        if ((u8) M2C_FIELD(*(temp_r27_1807 + (var_r29_1830 + 0xC28)), u8 *, 0x1D) == 3) {
                            temp_r27_1807->SetCurrentEdge(M2C_FIELD((temp_r27_1807 + var_r29_1830), FireBossGraphEdge **, 0xC28), temp_r27_1807->CalcEdgeSplineStartTime(M2C_FIELD((temp_r27_1807 + var_r29_1830), FireBossGraphEdge **, 0xC28)));
                            KDSound_Play3d(GS_TrainTurnSqueal2, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                            this->unkC->unkF64->ChargeEnter();
                            var_r4_1818 = 1;
                        } else {
                            var_r29_1830 += 4;
                            var_ctr_1831 -= 1;
                            if (var_ctr_1831 != 0) {
                                goto loop_31;
                            }
                        }
                    }
                }
            }
            if (var_r4_1818 == 0) {
                temp_r27_1868 = this->unkC;
                temp_r27_1868->SetCurrentEdge(temp_r27_1868->unkC28, temp_r27_1868->CalcEdgeSplineStartTime(temp_r27_1868->unkC28));
            }
            goto block_38;
        case 4:
            temp_r27_1807->unkB10 = M2C_FIELD(temp_r3_1808, f32 *, 0x10);
            temp_r4_1882 = this->unkC;
            spC = 0.0f;
            sp50.GetMeasure(M2C_BITWISE(f32, temp_r4_1882->unkB10), temp_r4_1882->unkC14, KDSpline_PositionMixer);
            temp_r3_1888 = this->unkC;
            M2C_FIELD(temp_r3_1888, f64 *, 0x588) = sp50;
            M2C_FIELD(temp_r3_1888, f64 *, 0x590) = sp58;
            this->unkC->unkC42 = 1;
            this->unk8 = 2;
            return this->unk8;
        default:
            temp_r27_1807->InsideEdgeChange();
            goto block_38;
        }
    } else {
block_38:
        temp_r4_1904 = this->unkC;
        sp8 = 0.0f;
        sp40.GetMeasure(M2C_BITWISE(f32, temp_r4_1904->unkB10), temp_r4_1904->unkC14, KDSpline_PositionMixer);
        temp_r3_1913 = this->unkC;
        M2C_FIELD(temp_r3_1913, f64 *, 0x588) = sp40;
        M2C_FIELD(temp_r3_1913, f64 *, 0x590) = sp48;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp20 = sp10;
        sp18 = this->unkC->unk588.unk4 - (f32) sp68;
        sp28 = (f64) sp18;
        Normalise(sp30);
        temp_r4_1935 = this->unkC;
        M2C_FIELD(temp_r4_1935, f64 *, 0xE0) = M2C_BITWISE(f64, sp30);
        M2C_FIELD(temp_r4_1935, f64 *, 0xE8) = (f64) sp30.unk8;
        temp_r4_1935->unk6B5 |= 0x40;
        return this->unk8;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void FireBossGoal_Stage3::Activate() {
    FireBoss *temp_r3_1976;

    this->unk8 = 0;
    this->unkC->unkB24 = 2200.0f;
    temp_r3_1976 = this->unkC;
    temp_r3_1976->unkB04 = 0.083333336f * temp_r3_1976->unkB24;
    this->unkC->unk684 = 3.1415927f;
    this->unkC->unkC24 = 3;
    this->unkC->unkD10.unk228 = 2.5f;
    this->unkC->unkD10.unk22C = 2.5f;
    this->unkC->unkD10.unk230 = 2.5f;
    this->unkC->unkD10.unk234 = 1.0f;
    this->unkC->unkD10.unk238 = 2.5f;
    this->unkC->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->unk1074 = 3;
    this->unkC->TriggerExplosion();
}
#endif

void FireBossGoal_Stage2::Terminate() {
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unkD24'
u8 FireBossGoal_Stage2::Update() {
    f64 sp68;
    f64 sp60;
    f64 sp50;
    f64 sp40;
    MKVector3 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 spC;
    f32 sp8;
    FireBoss *temp_r27_2143;
    FireBoss *temp_r27_2204;
    FireBoss *temp_r3_2043;
    FireBoss *temp_r3_2058;
    FireBoss *temp_r3_2073;
    FireBoss *temp_r3_2106;
    FireBoss *temp_r3_2134;
    FireBoss *temp_r3_2224;
    FireBoss *temp_r3_2249;
    FireBoss *temp_r4_2036;
    FireBoss *temp_r4_2047;
    FireBoss *temp_r4_2083;
    FireBoss *temp_r4_2095;
    FireBoss *temp_r4_2124;
    FireBoss *temp_r4_2218;
    FireBoss *temp_r4_2240;
    FireBoss *temp_r4_2271;
    s32 temp_r3_2158;
    s32 var_ctr_2167;
    s32 var_r29_2166;
    u8 temp_r0_2145;
    u8 temp_r29_2032;
    u8 temp_r30_2037;
    u8 var_r27_2107;
    u8 var_r4_2154;
    void *temp_r3_2144;

    ActivateIfInactive();
    temp_r29_2032 = this->unkC->IsSpyroOnInsideTrack(0);
    temp_r4_2036 = this->unkC;
    temp_r30_2037 = this->unkC->IsSpyroOnInsideTrack(1);
    sp60 = M2C_FIELD(temp_r4_2036, f64 *, 0x588);
    temp_r4_2036->unkD24 = 6.0f;
    temp_r3_2043 = this->unkC;
    sp68 = M2C_FIELD(temp_r4_2036, f64 *, 0x590);
    temp_r3_2043->MoveAlongCurrentSpline(M2C_FIELD(temp_r3_2043, f32 *, 0xB20));
    temp_r4_2047 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_2047->unkC1C, u8 *, 0x1D) == 0) {
        temp_r4_2047->unkD10.unk230 -= gUpdateTimeDelta;
        temp_r3_2058 = this->unkC;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_r3_2058->unkD10.unk230 == 0.0f) {
            if ((u8) temp_r3_2058->unkD10.unk78 != 0) {
                temp_r3_2058->unkD10.unk230 = temp_r3_2058->unkD10.unk238;
            } else {
                temp_r3_2058->unkD10.unk230 = temp_r3_2058->unkD10.unk234;
            }
            temp_r3_2073 = this->unkC;
            temp_r3_2073->unkD10.unk78 = temp_r3_2073->unkD10.unk78 == 0;
        }
    } else {
        temp_r4_2047->unkD10.unk78 = 0;
    }
    temp_r4_2083 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_2083->unkC1C, u8 *, 0x1D) == 1) {
        temp_r4_2083->unkD10.EmitSmoke();
    } else {
        temp_r4_2083->unkD10.EmitSteam();
    }
    temp_r4_2095 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_2095->unkC1C, u8 *, 0x1D) == 4) {
        temp_r4_2095->unkD10.EmitBrakingEffects();
        M2C_FIELD(this->unkC, s8 *, 0xFC9) = 1;
    }
    temp_r3_2106 = this->unkC;
    var_r27_2107 = 0;
    if (((u8) M2C_FIELD(temp_r3_2106, u8 *, 0x8B8) == 2) || (temp_r3_2106->unk870.unk30.Get() != NULL)) {
        var_r27_2107 = 1;
    }
    if ((var_r27_2107 != 0) && (temp_r29_2032 == 0) && (temp_r30_2037 == 0)) {
        temp_r4_2124 = this->unkC;
        if ((u8) M2C_FIELD(temp_r4_2124->unkC1C, u8 *, 0x1D) == 0) {
            temp_r4_2124->unkD10.unk228 -= gUpdateTimeDelta;
            temp_r3_2134 = this->unkC;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_r3_2134->unkD10.unk228 == 0.0f) {
                temp_r3_2134->TriggerFireball();
            }
        }
    }
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        temp_r27_2143 = this->unkC;
        temp_r3_2144 = temp_r27_2143->unkC1C;
        temp_r0_2145 = M2C_FIELD(temp_r3_2144, u8 *, 0x1D);
        switch ((s32) temp_r0_2145) {               /* irregular */
        case 0:
            var_r4_2154 = 0;
            if (M2C_FIELD(temp_r27_2143, f32 *, 0xB18) > 2.0f) {
                temp_r3_2158 = temp_r27_2143->unkC24;
                if ((temp_r3_2158 > 1) && ((temp_r29_2032 != 0) || (temp_r30_2037 != 0))) {
                    var_r29_2166 = 0;
                    var_ctr_2167 = temp_r3_2158;
                    if (temp_r3_2158 > 0) {
loop_31:
                        if ((u8) M2C_FIELD(*(temp_r27_2143 + (var_r29_2166 + 0xC28)), u8 *, 0x1D) == 3) {
                            temp_r27_2143->SetCurrentEdge(M2C_FIELD((temp_r27_2143 + var_r29_2166), FireBossGraphEdge **, 0xC28), temp_r27_2143->CalcEdgeSplineStartTime(M2C_FIELD((temp_r27_2143 + var_r29_2166), FireBossGraphEdge **, 0xC28)));
                            KDSound_Play3d(GS_TrainTurnSqueal2, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                            this->unkC->unkF64->ChargeEnter();
                            var_r4_2154 = 1;
                        } else {
                            var_r29_2166 += 4;
                            var_ctr_2167 -= 1;
                            if (var_ctr_2167 != 0) {
                                goto loop_31;
                            }
                        }
                    }
                }
            }
            if (var_r4_2154 == 0) {
                temp_r27_2204 = this->unkC;
                temp_r27_2204->SetCurrentEdge(temp_r27_2204->unkC28, temp_r27_2204->CalcEdgeSplineStartTime(temp_r27_2204->unkC28));
            }
            goto block_38;
        case 4:
            temp_r27_2143->unkB10 = M2C_FIELD(temp_r3_2144, f32 *, 0x10);
            temp_r4_2218 = this->unkC;
            spC = 0.0f;
            sp50.GetMeasure(M2C_BITWISE(f32, temp_r4_2218->unkB10), temp_r4_2218->unkC14, KDSpline_PositionMixer);
            temp_r3_2224 = this->unkC;
            M2C_FIELD(temp_r3_2224, f64 *, 0x588) = sp50;
            M2C_FIELD(temp_r3_2224, f64 *, 0x590) = sp58;
            this->unkC->unkC42 = 1;
            this->unk8 = 2;
            return this->unk8;
        default:
            temp_r27_2143->InsideEdgeChange();
            goto block_38;
        }
    } else {
block_38:
        temp_r4_2240 = this->unkC;
        sp8 = 0.0f;
        sp40.GetMeasure(M2C_BITWISE(f32, temp_r4_2240->unkB10), temp_r4_2240->unkC14, KDSpline_PositionMixer);
        temp_r3_2249 = this->unkC;
        M2C_FIELD(temp_r3_2249, f64 *, 0x588) = sp40;
        M2C_FIELD(temp_r3_2249, f64 *, 0x590) = sp48;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp20 = sp10;
        sp18 = this->unkC->unk588.unk4 - (f32) sp68;
        sp28 = (f64) sp18;
        Normalise(sp30);
        temp_r4_2271 = this->unkC;
        M2C_FIELD(temp_r4_2271, f64 *, 0xE0) = M2C_BITWISE(f64, sp30);
        M2C_FIELD(temp_r4_2271, f64 *, 0xE8) = (f64) sp30.unk8;
        temp_r4_2271->unk6B5 |= 0x40;
        return this->unk8;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void FireBossGoal_Stage2::Activate() {
    FireBoss *temp_r3_2313;

    this->unk8 = 0;
    this->unkC->unkB24 = 1800.0f;
    temp_r3_2313 = this->unkC;
    temp_r3_2313->unkB04 = 0.083333336f * temp_r3_2313->unkB24;
    this->unkC->unk684 = 3.1415927f;
    this->unkC->unkC24 = 3;
    this->unkC->unkD10.unk228 = 5.0f;
    this->unkC->unkD10.unk22C = 3.5f;
    this->unkC->unkD10.unk230 = 3.0f;
    this->unkC->unkD10.unk234 = 1.0f;
    this->unkC->unkD10.unk238 = 3.0f;
    this->unkC->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->unk1074 = 1;
    this->unkC->TriggerExplosion();
}
#endif

void FireBossGoal_Stage1::Terminate() {
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unkD24'
u8 FireBossGoal_Stage1::Update() {
    f64 sp68;
    f64 sp60;
    f64 sp50;
    f64 sp40;
    MKVector3 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 spC;
    f32 sp8;
    FireBoss *temp_r27_2451;
    FireBoss *temp_r27_2512;
    FireBoss *temp_r3_2381;
    FireBoss *temp_r3_2409;
    FireBoss *temp_r3_2441;
    FireBoss *temp_r3_2532;
    FireBoss *temp_r3_2557;
    FireBoss *temp_r4_2374;
    FireBoss *temp_r4_2385;
    FireBoss *temp_r4_2398;
    FireBoss *temp_r4_2427;
    FireBoss *temp_r4_2526;
    FireBoss *temp_r4_2548;
    FireBoss *temp_r4_2579;
    s32 temp_r3_2466;
    s32 var_ctr_2475;
    s32 var_r29_2474;
    u8 temp_r0_2453;
    u8 temp_r29_2370;
    u8 temp_r30_2375;
    u8 var_r27_2410;
    u8 var_r4_2462;
    void *temp_r3_2452;

    ActivateIfInactive();
    temp_r29_2370 = this->unkC->IsSpyroOnInsideTrack(0);
    temp_r4_2374 = this->unkC;
    temp_r30_2375 = this->unkC->IsSpyroOnInsideTrack(1);
    sp60 = M2C_FIELD(temp_r4_2374, f64 *, 0x588);
    temp_r4_2374->unkD24 = 6.0f;
    temp_r3_2381 = this->unkC;
    sp68 = M2C_FIELD(temp_r4_2374, f64 *, 0x590);
    temp_r3_2381->MoveAlongCurrentSpline(M2C_FIELD(temp_r3_2381, f32 *, 0xB20));
    temp_r4_2385 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_2385->unkC1C, u8 *, 0x1D) == 1) {
        temp_r4_2385->unkD10.EmitSmoke();
    } else {
        temp_r4_2385->unkD10.EmitSteam();
    }
    temp_r4_2398 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_2398->unkC1C, u8 *, 0x1D) == 4) {
        temp_r4_2398->unkD10.EmitBrakingEffects();
        M2C_FIELD(this->unkC, s8 *, 0xFC9) = 1;
    }
    temp_r3_2409 = this->unkC;
    var_r27_2410 = 0;
    if (((u8) M2C_FIELD(temp_r3_2409, u8 *, 0x8B8) == 2) || (temp_r3_2409->unk870.unk30.Get() != NULL)) {
        var_r27_2410 = 1;
    }
    if ((var_r27_2410 != 0) && (temp_r29_2370 == 0) && (temp_r30_2375 == 0)) {
        temp_r4_2427 = this->unkC;
        if ((u8) M2C_FIELD(temp_r4_2427->unkC1C, u8 *, 0x1D) == 0) {
            if (M2C_FIELD(temp_r4_2427, f32 *, 0xB18) > 1.0f) {
                temp_r4_2427->unkD10.unk228 -= gUpdateTimeDelta;
            }
            temp_r3_2441 = this->unkC;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_r3_2441->unkD10.unk228 == 0.0f) {
                temp_r3_2441->TriggerFireball();
            }
        }
    }
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        temp_r27_2451 = this->unkC;
        temp_r3_2452 = temp_r27_2451->unkC1C;
        temp_r0_2453 = M2C_FIELD(temp_r3_2452, u8 *, 0x1D);
        switch ((s32) temp_r0_2453) {               /* irregular */
        case 0:
            var_r4_2462 = 0;
            if (M2C_FIELD(temp_r27_2451, f32 *, 0xB18) > 1.0f) {
                temp_r3_2466 = temp_r27_2451->unkC24;
                if ((temp_r3_2466 > 1) && ((temp_r29_2370 != 0) || (temp_r30_2375 != 0))) {
                    var_r29_2474 = 0;
                    var_ctr_2475 = temp_r3_2466;
                    if (temp_r3_2466 > 0) {
loop_26:
                        if ((u8) M2C_FIELD(*(temp_r27_2451 + (var_r29_2474 + 0xC28)), u8 *, 0x1D) == 3) {
                            temp_r27_2451->SetCurrentEdge(M2C_FIELD((temp_r27_2451 + var_r29_2474), FireBossGraphEdge **, 0xC28), temp_r27_2451->CalcEdgeSplineStartTime(M2C_FIELD((temp_r27_2451 + var_r29_2474), FireBossGraphEdge **, 0xC28)));
                            KDSound_Play3d(GS_TrainTurnSqueal2, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                            this->unkC->unkF64->ChargeEnter();
                            var_r4_2462 = 1;
                        } else {
                            var_r29_2474 += 4;
                            var_ctr_2475 -= 1;
                            if (var_ctr_2475 != 0) {
                                goto loop_26;
                            }
                        }
                    }
                }
            }
            if (var_r4_2462 == 0) {
                temp_r27_2512 = this->unkC;
                temp_r27_2512->SetCurrentEdge(temp_r27_2512->unkC28, temp_r27_2512->CalcEdgeSplineStartTime(temp_r27_2512->unkC28));
            }
            goto block_33;
        case 4:
            temp_r27_2451->unkB10 = M2C_FIELD(temp_r3_2452, f32 *, 0x10);
            temp_r4_2526 = this->unkC;
            spC = 0.0f;
            sp50.GetMeasure(M2C_BITWISE(f32, temp_r4_2526->unkB10), temp_r4_2526->unkC14, KDSpline_PositionMixer);
            temp_r3_2532 = this->unkC;
            M2C_FIELD(temp_r3_2532, f64 *, 0x588) = sp50;
            M2C_FIELD(temp_r3_2532, f64 *, 0x590) = sp58;
            this->unkC->unkC42 = 1;
            this->unk8 = 2;
            return this->unk8;
        default:
            temp_r27_2451->InsideEdgeChange();
            goto block_33;
        }
    } else {
block_33:
        temp_r4_2548 = this->unkC;
        sp8 = 0.0f;
        sp40.GetMeasure(M2C_BITWISE(f32, temp_r4_2548->unkB10), temp_r4_2548->unkC14, KDSpline_PositionMixer);
        temp_r3_2557 = this->unkC;
        M2C_FIELD(temp_r3_2557, f64 *, 0x588) = sp40;
        M2C_FIELD(temp_r3_2557, f64 *, 0x590) = sp48;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp20 = sp10;
        sp18 = this->unkC->unk588.unk4 - (f32) sp68;
        sp28 = (f64) sp18;
        Normalise(sp30);
        temp_r4_2579 = this->unkC;
        M2C_FIELD(temp_r4_2579, f64 *, 0xE0) = M2C_BITWISE(f64, sp30);
        M2C_FIELD(temp_r4_2579, f64 *, 0xE8) = (f64) sp30.unk8;
        temp_r4_2579->unk6B5 |= 0x40;
        return this->unk8;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void FireBossGoal_Stage1::Activate() {
    FireBoss *temp_r3_2620;

    this->unk8 = 0;
    this->unkC->unkB24 = 1200.0f;
    temp_r3_2620 = this->unkC;
    temp_r3_2620->unkB04 = 0.083333336f * temp_r3_2620->unkB24;
    this->unkC->unk684 = 3.1415927f;
    this->unkC->unkC24 = 1;
    this->unkC->unkD10.unk228 = 5.0f;
    this->unkC->unkD10.unk22C = 5.0f;
    this->unkC->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->unk1074 = 0;
}
#endif
