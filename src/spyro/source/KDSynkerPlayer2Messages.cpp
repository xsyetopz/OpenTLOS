#include "spyro/source/KDSynkerPlayer2Messages.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include <m2c_macros.h>

void KDS_Message_PropLookUpdate::Init(MKVector3 *arg0, MKProp *arg1) {
    this->unk0 = 0x807;
    this->unk8 = arg0;
    this->unkC = arg1;
    this->unk10 = 0;
}

void KDS_Message_PropSetPosRot::Init(const MKVector3 &arg0, const MKVector3 &arg1) {
    this->unk0 = 0x805;
    this->unk8 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk10 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk18 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk20 = M2C_FIELD(&arg1, f64 *, 8);
}

void KDS_Message_PropBodyAnimUpdate::Init(MKAnimScript *arg0, MKAnim *arg1, float arg2, float arg3, float arg4) {
    this->unk0 = 0x806;
    this->unkC = arg1;
    this->unk8 = arg0;
    this->unk10 = arg2;
    this->unk14 = arg3;
    this->unk18 = arg4;
    this->unk1C = 1;
}

void KDS_Message_PropResolve::Set(MKProp *arg0, MKModel *arg1) {
    this->unk8 = (u32) arg0;
    this->unk10 = arg1;
}

void KDS_Message_PropResolve::Set(MKProp *arg0, MKAnimScript *arg1) {
    this->unk8 = (u32) arg0;
    this->unkC = arg1;
}

void KDS_Message_PropResolve::Init() {
    this->unk0 = 0x802;
    this->unk8 = 0;
    this->unkC = NULL;
    this->unk10 = NULL;
}

void KDS_Message_PropEnd::Init(bool arg0, bool arg1) {
    this->unk0 = 0x804;
    this->unk8 = (s8) arg0;
    this->unk9 = (s8) arg1;
}

void KDS_Message_SetCameraSimple::Init(const Matrix &arg0) {
    this->unk0 = 0x801;
    M2C_STRUCT_COPY((s32) (this + 0xC) + 4, (s32) (&arg0 - 4) + 4, 0x40);
}

void KDS_Message_SetCamera::Init(Matrix *arg0, float arg1, float arg2, float arg3) {
    this->unk0 = 0x800;
    this->unk8 = arg0;
    this->unkC = arg1;
    this->unk10 = arg2;
    this->unk14 = arg3;
}
