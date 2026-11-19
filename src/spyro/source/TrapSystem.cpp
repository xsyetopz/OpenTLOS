#include "spyro/source/TrapSystem.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include <m2c_macros.h>

void TrapSystem::Add(MKProp *arg0) {
    arg0->unk28 = this->unk4C;
    this->unk4C = arg0;
}

void TrapSystem::Draw() {
    MKProp::Draw();
}

void TrapSystem::Update() {
    MKProp *var_r31_69;

    MKProp::Update();
    var_r31_69 = this->unk4C;
loop_2:
    if (var_r31_69 != NULL) {
        var_r31_69->Update();
        var_r31_69 = var_r31_69->unk28;
        goto loop_2;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void TrapSystem::Message(MKMessage *arg0) {
    s32 spC;
    s32 sp8;
    MKProp *var_r30_117;
    s32 temp_r0_98;

    MKProp::Message(arg0);
    temp_r0_98 = arg0->unk0;
    if (temp_r0_98 < 0xB6) {
        if (temp_r0_98 < 0xB0) {
            if (temp_r0_98 < 0xAE) {
                return;
            }
            goto block_9;
        }
        if (temp_r0_98 < 0xB4) {
            return;
        }
        goto block_9;
    }
    if (temp_r0_98 < 0xC0) {
        if (temp_r0_98 < 0xBE) {
            return;
        }
block_9:
        var_r30_117 = this->unk4C;
loop_11:
        if (var_r30_117 != NULL) {
            spC = 0;
            sp8 = arg0->unk0;
            var_r30_117->Message(&sp8);
            var_r30_117 = var_r30_117->unk28;
            goto loop_11;
        }
    }
}
#endif

#if 0 // DRAFT: illegal operand
void TrapSystem::LoadDone() {
    MKProp::LoadDone();
    this->unk50.SetIdentity();
    this->unk50.SetRotationPYR(MKProp::loadInfo + 0x50);
    this->unk50.unk30 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x40);
    this->unk50.unk34 = M2C_BITWISE(f32, MKProp::loadInfo.__vptr);
    this->unk50.unk38 = MKProp::loadInfo.unk48;
    this->unk50.unk3C = 1.0f;
    this->unk8 = &this->unk50;
}
#endif

void TrapSystem::Init() {
    MKProp::Init();
    this->unk4C = NULL;
}

void TrapSystemDescriptor::Init() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;

    MKPropDescriptor::Init();
    sp18 = -30.000002f;
    sp1C = -30.000002f;
    sp20 = -30.000002f;
    this->unk60 = (f64) sp18;
    this->unk68 = (f64) sp20;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    sp8 = this->unk60 * 1.591496843e-314;
    this->unk70 = sp8;
    sp10 = (f32) M2C_FIELD(this, f64 *, 0x68) * -2.0f;
    sp28 = sp8;
    this->unk78 = (f64) sp10;
    sp30 = (f64) sp10;
    this->unk1C = (BoundingVolume *) &this->unk60;
}
