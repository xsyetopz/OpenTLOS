#include "spyro/source/YawPlatform.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Platform.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

void YawPlatform::Deinit() {
    Platform::Deinit();
}

void YawPlatform::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_60;
    f32 var_f0_61;

    GameProp::Update();
    temp_f2_60 = this->unk180;
    var_f0_61 = this->unk184 + gUpdateTimeDelta;
    if (var_f0_61 < temp_f2_60) {

    } else {
        var_f0_61 = temp_f2_60;
    }
    if (var_f0_61 > 0.0f) {

    } else {
        var_f0_61 = 0.0f;
    }
    this->unk184 = var_f0_61;
    sp10 = 0.0f;
    sp8 = 0.0f;
    spC = this->unk184;
    sp20 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x110) = (f64) sp8;
    sp18 = (f64) sp8;
    M2C_FIELD(this, f64 *, 0x118) = (f64) sp10;
}

void YawPlatform::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0xB5) {
        Platform::Message(arg0);
        return;
    }
    this->unk180 += 1.5707964f;
}

void YawPlatform::LoadDone() {
    Platform::LoadDone();
    this->unk180 = this->unk184;
}

s32 YawPlatform::LoadLine(MKIniLine *arg0) {
    s32 var_r31_146;

    var_r31_146 = 0;
    if ((Platform::LoadLine(arg0) != 0) || (arg0->LoadFloat("StartYaw", &this->unk184, 0) != 0)) {
        var_r31_146 = 1;
    }
    return var_r31_146;
}

void YawPlatform::Init() {
    Platform::Init();
    this->unk184 = 0.0f;
    this->unk180 = 0.0f;
}
