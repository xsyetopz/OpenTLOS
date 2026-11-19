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

#if 0 // DRAFT: ')' expected
void ToggleProp::Message(MKMessage *arg0) {
    s32 temp_r0_64;
    u8 temp_r4_85;

    temp_r0_64 = arg0->unk0;
    switch (temp_r0_64) {                           /* irregular */
    case 0xB5:
        if ((u8) M2C_FIELD(checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x81) != 0) {
            this->unk90 = this->unk90 == 0;
        } else {
            temp_r4_85 = this->unk90;
            if (temp_r4_85 == (u8) M2C_FIELD(checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x80)) {
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
#endif

#if 0 // DRAFT: ')' expected
void ToggleProp::Draw() {
    if ((u8) this->unk90 != 0) {
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x78), 1U, 1U);
    } else {
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x7C), 1U, 1U);
    }
    MKModel_Draw(this->unk4, NULL);
}
#endif

#if 0 // DRAFT: ')' expected
void ToggleProp::Init() {
    KDProp::Init();
    this->unk90 = M2C_FIELD(checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x80);
}
#endif

void TogglePropDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}

#if 0 // DRAFT: function call 'MKModel_GetSubObjectIndex(MKModel *, SubObjectType, signed char *)' does not match 'MKModel_GetSubObjectIndex(const MKModel *, SubObjectType, con
void TogglePropDescriptor::LoadDone() {
    KDPropDescriptor::LoadDone();
    this->unk78 = MKModel_GetSubObjectIndex(this->unk2C, (SubObjectType) 0, this->unk70);
    this->unk7C = MKModel_GetSubObjectIndex(this->unk2C, (SubObjectType) 0, this->unk74);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to 'const char **'
s32 TogglePropDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_217;

    var_r31_217 = 0;
    if ((KDPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadString("SubobjectOn", &this->unk70, 0) != 0) || (arg0->LoadString("SubobjectOff", &this->unk74, 0) != 0) || (arg0->LoadBool("bStartOn", (u8 *) &this->unk80, 0) != 0) || (arg0->LoadBool("bToggle", this + 0x81, 0) != 0)) {
        var_r31_217 = 1;
    }
    return var_r31_217;
}
#endif

void TogglePropDescriptor::Init() {
    KDPropDescriptor::Init();
    this->unk78 = -1;
    this->unk7C = -1;
    M2C_FIELD(this, s8 *, 0x80) = 0;
    M2C_FIELD(this, s8 *, 0x81) = 1;
}
