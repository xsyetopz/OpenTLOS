#include "spyro/source/VelocityTrigger.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/TriggerObject.h"
#include "spyro/source/TriggerProp.h"
#include <m2c_macros.h>

extern void **gb;

void VelocityTrigger::OnExit() {
    s32 sp10;
    VelocityTrigger *spC;
    s32 sp8;

    TriggerProp::OnExit();
    spC = NULL;
    sp8 = 0x89;
    sp10 = 3;
    spC = this;
    M2C_FIELD(*gb, M2C_UNK (**)(void **, s32 *), 0x1C)(gb, &sp8);
}

void VelocityTrigger::OnAction() {
    s32 sp10;
    VelocityTrigger *spC;
    s32 sp8;

    TriggerProp::OnAction();
    spC = NULL;
    sp8 = 0x89;
    sp10 = 2;
    spC = this;
    M2C_FIELD(*gb, M2C_UNK (**)(void **, s32 *), 0x1C)(gb, &sp8);
}

void VelocityTrigger::OnEnter() {
    s32 sp10;
    VelocityTrigger *spC;
    s32 sp8;

    TriggerProp::OnEnter();
    spC = NULL;
    sp8 = 0x89;
    sp10 = 1;
    spC = this;
    M2C_FIELD(*gb, M2C_UNK (**)(void **, s32 *), 0x1C)(gb, &sp8);
}

s32 VelocityTrigger::LoadLine(MKIniLine *arg0) {
    s32 var_r31_165;

    var_r31_165 = 0;
    if ((TriggerBoxProp::LoadLine(arg0) != 0) || (M2C_FIELD(this->unk190, u8 (**)(void *, const char *, MKIniLine *), 0x38)(&this->unk190, "box", arg0) != 0) || (arg0->LoadVector3("TrigInitalVelocity", &this->unk250, 0) != 0) || (arg0->LoadVector3("TrigAcceleration", &this->unk260, 0) != 0) || (arg0->LoadVector3("TrigNoiseMin", &this->unk270, 0) != 0) || (arg0->LoadVector3("TrigNoiseMax", &this->unk280, 0) != 0)) {
        var_r31_165 = 1;
    }
    return var_r31_165;
}

void VelocityTrigger::Init() {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    TriggerBoxProp::Init();
    sp3C = 0.0f;
    sp38 = 500.0f;
    sp40 = 0.0f;
    M2C_FIELD(this, f64 *, 0x250) = (f64) sp38;
    sp30 = 0.0f;
    sp20 = 0.0f;
    sp10 = 0.0f;
    sp28 = 100.0f;
    sp2C = 0.0f;
    M2C_FIELD(this, f64 *, 0x258) = (f64) sp40;
    M2C_FIELD(this, f64 *, 0x260) = (f64) sp28;
    sp18 = 0.0f;
    sp1C = -100.0f;
    M2C_FIELD(this, f64 *, 0x268) = (f64) sp30;
    M2C_FIELD(this, f64 *, 0x270) = (f64) sp18;
    sp8 = 0.0f;
    spC = 100.0f;
    M2C_FIELD(this, f64 *, 0x278) = (f64) sp20;
    M2C_FIELD(this, f64 *, 0x280) = (f64) sp8;
    sp78 = (f64) sp38;
    sp80 = (f64) sp40;
    sp68 = (f64) sp28;
    sp70 = (f64) sp30;
    sp58 = (f64) sp18;
    sp60 = (f64) sp20;
    sp48 = (f64) sp8;
    sp50 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x288) = (f64) sp10;
}

s32 VelocityTriggerDescriptor::LoadLine(MKIniLine *arg0) {
    MKPropDescriptor::LoadLine(arg0);
}

void VelocityTriggerDescriptor::Init() {
    TriggerPropDescriptor::Init();
}
