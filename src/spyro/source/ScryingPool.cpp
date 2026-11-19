#include "spyro/source/ScryingPool.h"
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
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;
extern M2C_UNK gb;

void ScryingPool::Deinit() {
    KDSound_Stop((int *) &this->unk98);
    KDPropEx::Deinit();
}

void ScryingPool::Message(MKMessage *arg0) {
    ((KDSoundPlayer *) &this->unk98)->Message(arg0);
    KDPropEx::Message(arg0);
}

#if 0 // DRAFT: ')' expected
void *ScryingPool::Update() {
    s32 sp8;
    s32 temp_r4_104;
    u8 var_r30_154;
    u8 var_r30_184;

    KDPropEx::Update();
    temp_r4_104 = this->unk94;
    if (temp_r4_104 != 0) {
        sp8 = 1;
        ((KDSoundFader *) &this->unk98)->Update(temp_r4_104, 1U, temp_r4_104 == this->unk90, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if (((s32) this->unk94 != (s32) this->unk90) && (KDSound_IsVoicePlaying(this->unk98) == 0)) {
        this->unk94 = this->unk90;
    }
    if (((s32) this->unk94 == 0) && ((s32) this->unk90 == 0) && ((s32) M2C_FIELD(checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xC0) != 0)) {
        this->unk90 = M2C_FIELD(checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xC0);
    }
    if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r30_154 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r30_154 = 1;
        }
        if ((var_r30_154 != 0) && ((s32) this->unk90 != (s32) M2C_FIELD(checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xC4))) {
            this->unk90 = M2C_FIELD(checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xC4);
        }
    }
    if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r30_184 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r30_184 = 1;
        }
        if (var_r30_184 == 0) {
            goto block_23;
        }
    } else {
block_23:
        if ((s32) this->unk90 != (s32) M2C_FIELD(checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xC0)) {
            this->unk90 = M2C_FIELD(checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xC0);
        }
    }
}
#endif

void ScryingPool::Init() {
    KDPropEx::Init();
    ((KDSoundFader *) &this->unk98)->Init(0.25f, 0.25f);
    this->unk90 = GS_PLACEHOLDER;
    this->unk94 = GS_PLACEHOLDER;
}

s32 ScryingPoolDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_251;

    var_r31_251 = 0;
    if ((KDPropExDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "normalSound", (int *) &this->unkC0) != 0) || (KDSound_LoadLine(arg0, "cutsceneSound", (int *) &this->unkC4) != 0)) {
        var_r31_251 = 1;
    }
    return var_r31_251;
}

void ScryingPoolDescriptor::Init() {
    KDPropExDescriptor::Init();
    this->unkC0 = GS_PLACEHOLDER;
    this->unkC4 = GS_PLACEHOLDER;
}
