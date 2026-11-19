#include "spyro/source/Trap.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/TrapSystem.h"
#include "unplaced_templates.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

f32 Trap::GetCollisionHeight() {
    return 0.0f;
}

f32 Trap::GetCollisionRadius() {
    return 0.0f;
}

void Trap::GetVel() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
}

s32 Trap::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_40;
    f64 temp_f1_39;
    void *temp_r4_37;

    temp_r4_37 = this->unk8;
    temp_f1_39 = M2C_FIELD(temp_r4_37, f64 *, 0x30);
    temp_f0_40 = M2C_FIELD(temp_r4_37, f64 *, 0x38);
    sp8 = temp_f1_39;
    M2C_FIELD(arg1, f64 *, 0) = temp_f1_39;
    sp10 = temp_f0_40;
    M2C_FIELD(arg1, f64 *, 8) = temp_f0_40;
    return 1;
}

s32 Trap::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_56;
    f64 temp_f1_55;
    void *temp_r4_53;

    temp_r4_53 = this->unk8;
    temp_f1_55 = M2C_FIELD(temp_r4_53, f64 *, 0x30);
    temp_f0_56 = M2C_FIELD(temp_r4_53, f64 *, 0x38);
    sp8 = temp_f1_55;
    M2C_FIELD(arg1, f64 *, 0) = temp_f1_55;
    sp10 = temp_f0_56;
    M2C_FIELD(arg1, f64 *, 8) = temp_f0_56;
    return 1;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
s32 Trap::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    MKVector3 sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_80;

    sp28 = GetPos();
    temp_f0_80 = M2C_FIELD(&arg0, f64 *, 0) - M2C_BITWISE(f64, sp28);
    sp8 = temp_f0_80;
    sp38 = temp_f0_80;
    sp10 = arg0.unk8 - sp28.unk8;
    sp40 = (f64) sp10;
    sp48 = Normalise(*((MKVector3 *) &sp38));
    sp58 = sp48.operator*(100.0f);
    sp68 = GetPos();
    sp18 = sp68 + M2C_BITWISE(f64, sp58);
    M2C_FIELD(arg1, f64 *, 0) = sp18;
    sp20 = sp68.unk8 + sp58.unk8;
    sp78 = sp18;
    sp80 = (f64) sp20;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp20;
    return 1;
}
#endif

s32 Trap::IsEnemy() {
    return 0;
}

s32 Trap::IsFriend() {
    return 0;
}

s32 Trap::IsHero() {
    return 0;
}

void Trap::GetProp() {

}

#if 0 // DRAFT: undefined identifier 'GetTargetableMsg'
void Trap::Message(MKMessage *arg0) {
    Trap *var_r0_223;
    s32 temp_r0_159;
    void *temp_r3_221;

    temp_r0_159 = arg0->unk0;
    switch (temp_r0_159) {                          /* irregular */
    case 0xBE:
    case 0xAF:
        if ((MKSceneManager *) this->unkD4 != NULL) {
            this->unk10 |= 0x20000;
            return;
        }
    default:
block_27:
        GameProp::Message(arg0);
        return;
    case 0xB4:
    case 0xBF:
    case 0xAE:
        if ((MKSceneManager *) this->unkD4 != NULL) {
            this->unk10 &= 0xFFFDFFFF;
            return;
        }
        goto block_27;
    case 0x422:
        GameProp::Message(arg0);
        if ((MKSceneManager *) this->unkD4 != NULL) {
            this->unk10 |= 4;
            return;
        }
        break;
    case 0x6C:
        this->unkDC.Send((MKProp *) this);
        goto block_27;
    case 0x8E:
        temp_r3_221 = checked_cast<GetTargetableMsg *, MKMessage>(arg0);
        var_r0_223 = this;
        if (this != NULL) {
            var_r0_223 = (Trap *) &this->unkC8;
        }
        M2C_FIELD(temp_r3_221, Trap **, 8) = var_r0_223;
        return;
    }
}
#endif

void Trap::PropUpdate() {
    GameProp::PropUpdate();
    if ((MKSceneManager *) this->unkD4 != NULL) {
        this->unk10 |= 4;
    }
}

void Trap::Reset() {
    GameProp::Reset();
    this->unkD8 = 1;
}

f32 Trap::Resolve() {
    MKSceneManager *temp_r3_291;
    MKSceneManager *temp_r3_297;

    KDPropEx::Resolve();
    temp_r3_291 = this->unkD4;
    if (temp_r3_291 != NULL) {
        this->unkD4 = (MKSceneManager *) (checked_cast<TrapSystem *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) temp_r3_291)));
        temp_r3_297 = this->unkD4;
        if (temp_r3_297 != NULL) {
            ((TrapSystem *) temp_r3_297)->Add((MKProp *) this);
            this->unk10 |= 4;
        }
    }
}

s32 Trap::LoadDone() {
    GameProp::LoadDone();
    if ((MKSceneManager *) this->unkD4 != NULL) {
        this->unk10 |= 4;
    }
}

s32 Trap::LoadLine(MKIniLine *arg0) {
    s32 var_r31_345;

    var_r31_345 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadInt("system", (int *) &this->unkD4, 0) != 0) || (arg0->LoadBool("CanBeDisarmed", (bool *) &this->unkD9, 0) != 0) || (this->unkDC.LoadLine(arg0, "OnDisarmed") != 0)) {
        var_r31_345 = 1;
    }
    return var_r31_345;
}

void Trap::Init() {
    GameProp::Init();
    this->unkD0 = 0;
    this->unkD4 = NULL;
    this->unkD8 = 1;
    this->unkD9 = 0;
}

void TrapDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unkC = 0x10;
}
