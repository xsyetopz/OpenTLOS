#include "spyro/source/ShatterablePlatform.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unksp1C'
void ShatterablePlatform::Reset() {
    Matrix sp20;
    f64 sp18;
    f64 sp10;

    Shatterable::Reset();
    ((PlatformObject *) &this->unk1A8.unk8)->Reset();
    M2C_FIELD(this, f64 *, 0x1C8) = (f64) M2C_FIELD(this, f64 *, 0x208);
    M2C_FIELD(this, f64 *, 0x1D0) = (f64) M2C_FIELD(this, f64 *, 0x210);
    sp10 = M2C_FIELD(this, f64 *, 0x1C8);
    sp18 = M2C_FIELD(this, f64 *, 0x1D0);
    M2C_STRUCT_COPY((s32) &unksp1C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    sp20.SetRotationPYR(*((MKVector3 *) &sp10));
    MKModel_SetWorldMatrix(this->unk4, sp20);
}
#endif

void ShatterablePlatform::Deinit() {
    ((PlatformObject *) &this->unk1A8.unk8)->Deinit();
    Shatterable::Deinit();
}

#if 0 // DRAFT: ')' expected
void ShatterablePlatform::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0x88) {
        ((PlatformObject *) &this->unk1A8.unk8)->Message(arg0);
        Shatterable::Message(arg0);
        return;
    }
    M2C_FIELD(checked_cast<CanHeroHurtYouMsg *, MKMessage>(arg0), s8 *, 8) = 0;
}
#endif

#if 0 // DRAFT: ')' expected
void ShatterablePlatform::Update() {
    void *temp_r31_124;

    if ((MKProp *) this->unk170 == (s32) M2C_FIELD(checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x160)) {
        temp_r31_124 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        if ((u8) M2C_FIELD((M2C_FIELD(checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x11C) + (M2C_FIELD(temp_r31_124, s32 *, 0x160) * 0x17C)), u8 *, -4) != 0) {
            Shatterable::Update();
            return;
        }
    }
    this->unk1A8.unkC = M2C_BITWISE(f32, (((u8 *) this->unk158) + (((s32) this->unk170 << 7) + 0x68)));
    ((PlatformObject *) &this->unk1A8.unk8)->BeginUpdate();
    ((PlatformObject *) &this->unk1A8.unk8)->UpdateTilt();
    UpdateMove();
    ((PlatformObject *) &this->unk1A8.unk8)->EndUpdate();
    Shatterable::Update();
}
#endif

#if 0 // DRAFT: expression syntax error
void ShatterablePlatform::LoadDone() {
    Shatterable::LoadDone();
    M2C_FIELD(this, f64 *, 0x208) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x50);
    M2C_FIELD(this, f64 *, 0x210) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x58);
    ((PlatformObject *) &this->unk1A8.unk8)->Init((PlatformObjectDesc *) &this->unk198, ((u8 *) this->unk158) + (((s32) this->unk170 << 7) + 0x68));
    ((PlatformObject *) &this->unk1A8.unk8)->LoadDone((MKProp *) this, &MKProp::loadInfo + 0x60);
    M2C_FIELD(this, f64 *, 0x1C8) = (f64) M2C_FIELD(this, f64 *, 0x208);
    M2C_FIELD(this, f64 *, 0x1D0) = (f64) M2C_FIELD(this, f64 *, 0x210);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1B4'
void ShatterablePlatform::Init() {
    Shatterable::Init();
    this->unk198 = 0.5f;
    M2C_FIELD(this, f32 *, 0x1AC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1B0) = 0.0f;
    this->unk1B4 = 6.0f;
    M2C_FIELD(this, s8 *, 0x1B8) = 0;
    M2C_FIELD(this, s8 *, 0x1B9) = 1;
    this->unk198 = 0.0f;
    M2C_FIELD(this, s8 *, 0x1B9) = 0;
    M2C_FIELD(this, f32 *, 0x1AC) = ((MKVector3 *) (MKModel_GetBoundingVolume(M2C_FIELD(this->unk0, MKModel **, 0x2C), (SubObjectType) 0, -1)))->Magnitude();
    M2C_FIELD(this, f32 *, 0x1B0) = (f32) (0.1f * M2C_FIELD(this, f32 *, 0x1AC));
}
#endif
