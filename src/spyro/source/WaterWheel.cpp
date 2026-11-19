#include "spyro/source/WaterWheel.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
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
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Platform.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SeeSaw.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include <m2c_macros.h>

extern s32 GS_WaterwheelMoveLP;
extern f32 gUpdateTimeDelta;

void WaterWheel::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0xB5) {

    } else {
        this->unk1C0 = 1;
    }
    Platform::Message(arg0);
    ((KDSoundPlayer *) &this->unk184)->Message(arg0);
}

void WaterWheel::Deinit() {
    KDSound_Stop((int *) &this->unk184);
    Platform::Deinit();
}

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

void *WaterWheel::Update() {
    s32 sp8;

    GameProp::Update();
    sp8 = 1;
    ((KDSoundFader *) &this->unk184)->Update(GS_WaterwheelMoveLP, 1U, this->unk1C0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
}

s32 WaterWheel::LoadDone() {
    Platform::LoadDone();
    this->unk180 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x50);
    M2C_FIELD(this, f64 *, 0x1B0) = (f64) M2C_FIELD(&MKProp::loadInfo, f32 *, 0x50);
    M2C_FIELD(this, f64 *, 0x1B8) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x58);
}

void WaterWheel::Init() {
    Platform::Init();
    ((KDSoundFader *) &this->unk184)->Init(0.25f, 0.25f);
    this->unk180 = 0.0f;
    this->unk1C0 = 0;
}
