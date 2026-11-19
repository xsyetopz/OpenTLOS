#include "spyro/source/ShatterablePlatform.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
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
#include "spyro/source/SeeSaw.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

void ShatterablePlatform::Reset() {
    Matrix sp20;
    f64 sp18;
    f64 sp10;

    Shatterable::Reset();
    this->unk1C0.Reset();
    M2C_FIELD(this, f64 *, 0x1C8) = (f64) this->unk208;
    M2C_FIELD(this, f64 *, 0x1D0) = (f64) this->unk210;
    sp10 = M2C_FIELD(this, f64 *, 0x1C8);
    sp18 = M2C_FIELD(this, f64 *, 0x1D0);
    M2C_STRUCT_COPY(&sp20, MKModel_GetWorldMatrix(this->unk4), 0x40);
    sp20.SetRotationPYR(*((MKVector3 *) &sp10));
    MKModel_SetWorldMatrix(this->unk4, sp20);
}

void ShatterablePlatform::Deinit() {
    this->unk1C0.Deinit();
    Shatterable::Deinit();
}

#if 0 // DRAFT: ')' expected
void ShatterablePlatform::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0x88) {
        this->unk1C0.Message(arg0);
        Shatterable::Message(arg0);
        return;
    }
    M2C_FIELD(checked_cast<CanHeroHurtYouMsg *, MKMessage>(arg0), s8 *, 8) = 0;
}
#endif

void *ShatterablePlatform::Update() {
    ShatterableDescriptor *temp_r3;
    ShatterableDescriptor *temp_r31;
    u8 *temp_r3_2;

    temp_r3 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((s32) this->unk180 == (s32) M2C_FIELD(temp_r3, s32 *, 0x160)) {
        temp_r31 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r3 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r3_2 = (u8 *) M2C_FIELD(temp_r3, u8 **, 0x11C) + (M2C_FIELD(temp_r31, s32 *, 0x160) * 0x17C);
        if ((u8) temp_r3_2[-4] != 0) {
            return Shatterable::Update();
        }
    }
    this->unk1C0.unk4 = (MKCollisionInfo *) (((u8 *) this->unk168) + ((this->unk180 << 7) + 0x68));
    this->unk1C0.BeginUpdate();
    this->unk1C0.UpdateTilt();
    UpdateMove();
    this->unk1C0.EndUpdate();
    return Shatterable::Update();
}

s32 ShatterablePlatform::LoadDone() {
    Shatterable::LoadDone();
    this->unk208 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x50);
    this->unk210 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x58);
    this->unk1C0.Init(&this->unk1A8, (MKCollisionInfo *) (((u8 *) this->unk168) + ((this->unk180 << 7) + 0x68)));
    this->unk1C0.LoadDone((MKProp *) this, (MKVector3 *) ((s8 *) &MKProp::loadInfo + 0x60));
    M2C_FIELD(this, f64 *, 0x1C8) = (f64) this->unk208;
    M2C_FIELD(this, f64 *, 0x1D0) = (f64) this->unk210;
}

void ShatterablePlatform::Init() {
    Shatterable::Init();
    this->unk1A8.unk0 = 0.5f;
    this->unk1A8.unk4 = 0.0f;
    this->unk1A8.unk8 = 0.0f;
    this->unk1A8.unkC = 6.0f;
    this->unk1A8.unk10 = 0;
    this->unk1A8.unk11 = 1;
    this->unk1A8.unk0 = 0.0f;
    this->unk1A8.unk11 = 0;
    this->unk1A8.unk4 = ((MKVector3 *) (MKModel_GetBoundingVolume(M2C_FIELD(this->unk0, MKModel **, 0x2C), (SubObjectType) 0, -1)))->Magnitude();
    this->unk1A8.unk8 = 0.1f * this->unk1A8.unk4;
}
