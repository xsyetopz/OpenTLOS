#include "spyro/source/CameraData.h"
#include <m2c_macros.h>

void CameraData::ClearData() {
    this->unk4 = 1.0f;
    this->unk0 = 1.0f;
    this->unk8 = 0;
    this->unkC = 1.0f;
}

u8 CameraData::GetJumpWithTy() {
    return this->unk8;
}

f32 CameraData::GetPlayerRotatePitchMultiplier() {
    return this->unkC * this->unk4;
}

f32 CameraData::GetPlayerRotateYawMultiplier() {
    return this->unkC * this->unk0;
}

void CameraData::Deinit() {

}

void CameraData::Init() {
    ClearData();
}

CameraData::CameraData() {
    ClearData();
}
