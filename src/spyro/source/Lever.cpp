#include "spyro/source/Lever.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include <m2c_macros.h>

extern s32 GS_LavaLeverPullStart;
extern s32 GS_PLACEHOLDER;
extern M2C_UNK gb;

f32 Lever::GetCollisionHeight() {
    return 200.0f;
}

f32 Lever::GetCollisionRadius() {
    return 100.0f;
}

#if 0 // DRAFT: undefined identifier 'zero'
void Lever::GetVel() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(&zero, f64 *, 8);
}
#endif

s32 Lever::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    return 0;
}

s32 Lever::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    return 0;
}

s32 Lever::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    return 0;
}

s32 Lever::IsEnemy() {
    return 0;
}

s32 Lever::IsFriend() {
    return 0;
}

s32 Lever::IsHero() {
    return 0;
}

void Lever::GetProp() {

}

void Lever::SetState(int arg0) {
    this->unkD0 = arg0;
    this->unk80->SetAnim(M2C_FIELD((checked_cast<LeverDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unkD0 * 4)), MKAnim **, 0xEC), 1.0f, 0.0f, 0, -1);
}

void Lever::Release() {
    SetState(3);
}

void Lever::Pull() {
    SetState(1);
}

void Lever::GetStandDir() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0xE8);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0xF0);
}

void Lever::GetStandPos() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0xD8);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0xE0);
}

#if 0 // DRAFT: ')' expected
void Lever::Message(MKMessage *arg0) {
    KDSoundPlayer *temp_r3_250;
    Lever *var_r0_322;
    s32 temp_r0_255;
    void *temp_r3_290;
    void *temp_r3_308;
    void *temp_r3_320;

    temp_r3_250 = this->unk100;
    if (temp_r3_250 != NULL) {
        temp_r3_250->Message(arg0);
    }
    temp_r0_255 = arg0->unk0;
    switch (temp_r0_255) {                          /* irregular */
    case 0x146:
        Pull();
    default:
block_28:
        GameProp::Message(arg0);
        return;
    case 0x147:
        Release();
        goto block_28;
    case 0x4:
        temp_r3_290 = checked_cast<MeleeAttackHitMsg *, MKMessage>(arg0);
        if (((s32) this->unkD0 == 2) && !(M2C_FIELD(temp_r3_290, s32 *, 0x30) & 0x1000)) {
            Release();
        }
        goto block_28;
    case 0x88:
        M2C_FIELD(checked_cast<CanHeroHurtYouMsg *, MKMessage>(arg0), s8 *, 8) = 1;
        return;
    case 0x79:
        temp_r3_308 = checked_cast<FindInteractivePropMsg *, MKMessage>(arg0);
        if ((s32) M2C_FIELD(temp_r3_308, s32 *, 8) == 0) {
            M2C_FIELD(temp_r3_308, Lever **, 0xC) = this;
        }
        goto block_28;
    case 0x14:
        Pull();
        goto block_28;
    case 0x8E:
        temp_r3_320 = checked_cast<GetTargetableMsg *, MKMessage>(arg0);
        var_r0_322 = this;
        if (this != NULL) {
            var_r0_322 = (Lever *) &this->unkC8;
        }
        M2C_FIELD(temp_r3_320, Lever **, 8) = var_r0_322;
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void Lever::Update() {
    s32 sp8;
    KDSoundPlayer *temp_r3_388;
    KDSynkerPlayer3 *temp_r3_354;
    s32 temp_r0_404;
    s32 var_r4_381;
    u8 var_r27_350;
    u8 var_r30_353;
    void *temp_r28_352;

    GameProp::Update();
    var_r27_350 = 0;
    temp_r28_352 = M2C_FIELD(&gb, void **, 0xC);
    var_r30_353 = 0;
    temp_r3_354 = M2C_FIELD(temp_r28_352, KDSynkerPlayer3 **, 0x78);
    if (((temp_r3_354 != NULL) && (temp_r3_354->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r28_352, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r28_352 + 0x24))->GetState() == 2))) {
        var_r30_353 = 1;
    }
    if ((var_r30_353 != 0) && ((s32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), s32 *, 0x74) == 0)) {
        var_r27_350 = 1;
    }
    if (var_r27_350 != 0) {
        var_r4_381 = GS_LavaLeverPullStart;
    } else {
        var_r4_381 = M2C_FIELD(checked_cast<LeverDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4);
    }
    temp_r3_388 = this->unk100;
    if (temp_r3_388 != NULL) {
        sp8 = 1;
        temp_r3_388->Update(var_r4_381, 1U, this->unkD0 == 2, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    temp_r0_404 = this->unkD0;
    switch (temp_r0_404) {                          /* irregular */
    case 1:
        if (this->unk80->unk2C & 1) {
            this->unkF8.Send((MKProp *) this);
            SetState(2);
            return;
        }
    case 2:
        return;
    case 3:
        if (this->unk80->unk2C & 1) {
            this->unkFC.Send((MKProp *) this);
            SetState(0);
        }
        break;
    }
}
#endif

void Lever::Resolve() {
    KDPropEx::Resolve();
}

#if 0 // DRAFT: ')' expected
void Lever::LoadDone() {
    GameProp::LoadDone();
    MKModel_GetRefPointMatrix(this->unk4, M2C_FIELD(checked_cast<LeverDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE8), (Matrix *) &arg_sp50, 1U);
    arg_sp10.SetRotateAroundAxis(up, 3.1415927f);
    arg_sp50.Multiply3x3((Matrix *) &arg_sp50, (Matrix *) &arg_sp10);
    this->unkD8 = arg_sp80;
    this->unkE0 = arg_sp88;
    this->unkE8 = arg_sp70;
    this->unkF0 = arg_sp78;
    this->unkC8.RegisterTargetable();
    if ((s32) M2C_FIELD(checked_cast<LeverDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4) != 0) {
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = 0;
        }
        this->unk100 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk100->Init(0.25f, 0.75f);
    }
}
#endif

s32 Lever::LoadLine(MKIniLine *arg0) {
    s32 var_r31_535;

    var_r31_535 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (this->unkF8.LoadLine(arg0, "OnPull") != 0) || (this->unkFC.LoadLine(arg0, "OnRelease") != 0)) {
        var_r31_535 = 1;
    }
    return var_r31_535;
}

#if 0 // DRAFT: undefined identifier 'unkC8'
void Lever::Deinit() {
    KDSoundPlayer *temp_r31_579;
    KDSoundPlayer *temp_r3_575;
    s32 temp_cr0_eq_580;

    this->unkC8.UnregisterTargetable();
    temp_r3_575 = this->unk100;
    if (temp_r3_575 != NULL) {
        KDSound_Stop(&temp_r3_575->unk0);
        temp_r31_579 = this->unk100;
        temp_cr0_eq_580 = temp_r31_579 == NULL;
        if (temp_cr0_eq_580 == 0) {
            if (temp_cr0_eq_580 == 0) {
                KDSound_Stop(&temp_r31_579->unk0);
            }
            operator delete(temp_r31_579);
        }
    }
    GameProp::Deinit();
}
#endif

void Lever::Init() {
    GameProp::Init();
    this->unkD0 = 0;
    M2C_FIELD(this, f32 *, 0xD8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xDC) = 0.0f;
    M2C_FIELD(this, f32 *, 0xE0) = 0.0f;
    M2C_FIELD(this, f32 *, 0xE8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xEC) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF0) = 0.0f;
    this->unk100 = NULL;
}

#if 0 // DRAFT: illegal use of non-static member
void LeverDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkE8 = MKModel_GetRefPointIndex(this->unk2C, "r_P0029_Stand");
    this->unkEC = this->unk34->GetAnim("BindPose");
    this->unkF0 = this->unk34->GetAnim("LeverPull_Start");
    this->unkF4 = this->unk34->GetAnim("LeverPull_Loop");
    this->unkF8 = this->unk34->GetAnim("LeverPull_End");
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 LeverDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_679;

    var_r31_679 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "LoopSound", &this->unkE4) != 0)) {
        var_r31_679 = 1;
    }
    return var_r31_679;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void LeverDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unkE4 = GS_PLACEHOLDER;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsAttacking'
void Lever::lit_200lit_IsAttacking() {
    ((Lever *) (this - 0xC8))->Lever::IsAttacking();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetTimeLastHit'
void Lever::lit_200lit_GetTimeLastHit() {
    ((Lever *) (this - 0xC8))->Lever::GetTimeLastHit();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionHeight'
void Lever::lit_200lit_GetCollisionHeight() {
    ((Lever *) (this - 0xC8))->Lever::GetCollisionHeight();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionRadius'
void Lever::lit_200lit_GetCollisionRadius() {
    ((Lever *) (this - 0xC8))->Lever::GetCollisionRadius();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionInfo'
void Lever::lit_200lit_GetCollisionInfo() {
    ((Lever *) (this - 0xC8))->Lever::GetCollisionInfo();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetVel'
void Lever::lit_200lit_GetVel() {
    Lever::GetVel();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetAimPoint'
void Lever::lit_200lit_GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((Lever *) (this - 0xC8))->Lever::GetAimPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetLookToPoint'
void Lever::lit_200lit_GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((Lever *) (this - 0xC8))->Lever::GetLookToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetMoveToPoint'
void Lever::lit_200lit_GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((Lever *) (this - 0xC8))->Lever::GetMoveToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsDead'
void Lever::lit_200lit_IsDead() {
    ((Lever *) (this - 0xC8))->Lever::IsDead();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsShatterable'
void Lever::lit_200lit_IsShatterable() {
    ((Lever *) (this - 0xC8))->Lever::IsShatterable();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsEnemy'
void Lever::lit_200lit_IsEnemy() {
    ((Lever *) (this - 0xC8))->Lever::IsEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsFriend'
void Lever::lit_200lit_IsFriend() {
    ((Lever *) (this - 0xC8))->Lever::IsFriend();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsHero'
void Lever::lit_200lit_IsHero() {
    ((Lever *) (this - 0xC8))->Lever::IsHero();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetEnemy'
void Lever::lit_200lit_GetEnemy() {
    ((Lever *) (this - 0xC8))->Lever::GetEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetProp'
void Lever::lit_200lit_GetProp() {
    ((Lever *) (this - 0xC8))->Lever::GetProp();
}
#endif
