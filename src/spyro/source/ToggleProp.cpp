#include "spyro/source/ToggleProp.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
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
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/gc/MKModel_GC.h"
#include <m2c_macros.h>

void ToggleProp::Deinit() {
    KDProp::Deinit();
}

void ToggleProp::Message(MKMessage *arg0) {
    TogglePropDescriptor *desc;
    s32 temp_r0_64;
    u8 temp_r4_85;

    temp_r0_64 = arg0->unk0;
    switch (temp_r0_64) {
    case 0xB5:
        desc = checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        if (M2C_FIELD(desc, u8 *, 0x81) != 0) {
            this->unk90 = this->unk90 == 0;
        } else {
            desc = checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            temp_r4_85 = this->unk90;
            if (temp_r4_85 == M2C_FIELD(desc, u8 *, 0x80)) {
                this->unk90 = temp_r4_85 == 0;
            }
        }
        break;
    case 0xB4:
        this->unk90 = 0;
        break;
    }
    KDProp::Message(arg0);
}

void ToggleProp::Draw() {
    TogglePropDescriptor *desc;

    if (this->unk90 != 0) {
        desc = checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, desc->unk78, 1, 1);
    } else {
        desc = checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, desc->unk7C, 1, 1);
    }
    MKModel_Draw(this->unk4, NULL);
}

void ToggleProp::Init() {
    TogglePropDescriptor *desc;

    KDProp::Init();
    desc = checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk90 = M2C_FIELD(desc, u8 *, 0x80);
}

void TogglePropDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}

void TogglePropDescriptor::LoadDone() {
    KDPropDescriptor::LoadDone();
    this->unk78 = MKModel_GetSubObjectIndex(this->unk2C, (SubObjectType) 0, (const char *) this->unk70);
    this->unk7C = MKModel_GetSubObjectIndex(this->unk2C, (SubObjectType) 0, (const char *) this->unk74);
}

s32 TogglePropDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_217;

    var_r31_217 = 0;
    if (((u8) KDPropDescriptor::LoadLine(arg0) != 0) || ((u8) arg0->LoadString("SubobjectOn", (const char **) &this->unk70, 0) != 0) || ((u8) arg0->LoadString("SubobjectOff", (const char **) &this->unk74, 0) != 0) || ((u8) arg0->LoadBool("bStartOn", (bool *) ((s8 *) this + 0x80), 0) != 0) || ((u8) arg0->LoadBool("bToggle", (bool *) ((s8 *) this + 0x81), 0) != 0)) {
        var_r31_217 = 1;
    }
    return var_r31_217;
}

void TogglePropDescriptor::Init() {
    KDPropDescriptor::Init();
    this->unk78 = -1;
    this->unk7C = -1;
    M2C_FIELD(this, s8 *, 0x80) = 0;
    M2C_FIELD(this, s8 *, 0x81) = 1;
}
