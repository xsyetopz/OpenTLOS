#include "spyro/source/RefFXEmitter.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
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
#include "spyro/source/Steam.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

void RefFXEmitter::Message(MKMessage *arg0) {
    KDProp::Message(arg0);
}

void *RefFXEmitter::Update() {
    Matrix sp60;
    MKVector3 sp48;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp10;
    f32 temp_f2_71;
    f32 temp_f31_137;
    u8 var_r0_70;
    RefFXEmitterDescriptor *temp_r4_desc;
    RefFXEmitterDescriptor *temp_r31_132;

    KDProp::Update();
    var_r0_70 = 0;
    temp_f2_71 = this->unk90;
    if (temp_f2_71 == 0.0f) {
        temp_r4_desc = checked_cast<RefFXEmitterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        this->unk94 = MKRand_Int((int *) &gViewSeed, 0, M2C_FIELD(temp_r4_desc, s32 *, 0x98));
        this->unk90 = MKRand_Float((int *) &gViewSeed, 0.2f, 0.8f);
        var_r0_70 = 1;
    } else if (temp_f2_71 > 0.0f) {
        this->unk90 = temp_f2_71 - gUpdateTimeDelta;
        if (this->unk90 <= 0.0f) {
            this->unk90 = MKRand_Float((int *) &gViewSeed, -1.0f, -0.2f);
        }
        var_r0_70 = 1;
    } else {
        this->unk90 = temp_f2_71 + gUpdateTimeDelta;
        if (this->unk90 > 0.0f) {
            this->unk90 = 0.0f;
        }
    }
    if (var_r0_70 != 0) {
        temp_r4_desc = checked_cast<RefFXEmitterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        MKModel_GetRefPointMatrix(this->unk4, M2C_FIELD(temp_r4_desc, s32 *, (this->unk94 * 4) + 0x70), &sp60, 1U);
        temp_r31_132 = checked_cast<RefFXEmitterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_f31_137 = MKRand_Float((int *) &gViewSeed, -700.0f, -300.0f);
        sp28 = -sp60.unk10;
        sp2C = -sp60.unk14;
        sp30 = -sp60.unk18;
        sp48.unk0 = sp28 * temp_f31_137;
        sp48.unk4 = sp2C * temp_f31_137;
        sp48.unk8 = sp30 * temp_f31_137;
        sp10 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
        ((Steam *) (M2C_FIELD(temp_r31_132, Steam **, 0x9C)))->Emit(*((MKVector3 *) &sp60.unk30), sp48, sp10);
    }
}

s32 RefFXEmitter::LoadDone() {
    KDProp::LoadDone();
}

s32 RefFXEmitter::LoadLine(MKIniLine *arg0) {
    KDProp::LoadLine(arg0);
}

void RefFXEmitter::Deinit() {
    KDProp::Deinit();
}

void RefFXEmitter::Init() {
    KDProp::Init();
    this->unk90 = 0.0f;
    this->unk94 = 0;
}

void RefFXEmitterDescriptor::Resolve() {
    s32 sp8;
    s32 temp_r3_257;
    s32 temp_r4_257;

    MKPropDescriptor::Resolve();
    sp8 = -1;
    this->unk98 = 0;
    while (MKModel_RefPointExists(this->unk2C, (const char *) Str_Printf("r_fxemit%d", this->unk98), (int *) &sp8) != 0) {
        temp_r3_257 = this->unk98;
        temp_r4_257 = sp8;
        this->unk98 = temp_r3_257 + 1;
        *(s32 *) ((u8 *) this + ((temp_r3_257 * 4) + 0x70)) = temp_r4_257;
    }
    this->unk9C = (long) (checked_cast<Steam *, MKProp>(gMK->CreateProp("Steam")));
}
