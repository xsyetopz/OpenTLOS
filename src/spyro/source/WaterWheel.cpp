#include "spyro/source/WaterWheel.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKProp.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Platform.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_WaterwheelMoveLP;
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: expression syntax error
void WaterWheel::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0xB5) {

    } else {
        this->unk1C0 = 1;
    }
    Platform::Message(arg0);
    this->unk184.Message(arg0);
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void WaterWheel::Deinit() {
    KDSound_Stop(&this->unk184);
    Platform::Deinit();
}
#endif

void WaterWheel::UpdateMove() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    if ((u8) this->unk1C0 != 0) {
        this->unk180 += 0.25f * gUpdateTimeDelta;
    }
    sp8 = this->unk180;
    spC = this->unk1B4;
    sp10 = this->unk1B8;
    M2C_FIELD(this, f64 *, 0x110) = (f64) sp8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x118) = (f64) sp10;
}

#if 0 // DRAFT: expression syntax error
void WaterWheel::Update() {
    s32 sp8;

    GameProp::Update();
    sp8 = 1;
    this->unk184.Update(GS_WaterwheelMoveLP, 1U, this->unk1C0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
}
#endif

#if 0 // DRAFT: undefined identifier 'loadInfo'
void WaterWheel::LoadDone() {
    Platform::LoadDone();
    this->unk180 = M2C_FIELD(&loadInfo, f32 *, 0x50);
    M2C_FIELD(this, f64 *, 0x1B0) = (f64) M2C_FIELD(&loadInfo, f32 *, 0x50);
    M2C_FIELD(this, f64 *, 0x1B8) = (f64) M2C_FIELD(&loadInfo, f64 *, 0x58);
}
#endif

#if 0 // DRAFT: expression syntax error
void WaterWheel::Init() {
    Platform::Init();
    this->unk184.Init(0.25f, 0.25f);
    this->unk180 = 0.0f;
    this->unk1C0 = 0;
}
#endif
