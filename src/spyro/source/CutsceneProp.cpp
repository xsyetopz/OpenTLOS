#include "spyro/source/CutsceneProp.h"
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
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/CutsceneObject.h"
#include "spyro/source/CutsceneSystem.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/GameVideo.h"
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
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

extern s8 bShowLoading;
extern GameStateMachine gGMState;
extern M2C_UNK gb;

void CutsceneProp::Disable() {
    this->unk18 = this->unk18 | 0x80000000;
    PropFlagsClear((unsigned int *) &this->unk10, 0x20000U);
}

f32 CutsceneProp::Resolve() {
    MKProp::Resolve();
    this->unk50.Resolve();
}

#if 0 // DRAFT: undefined identifier 'unk6D'
void CutsceneProp::Message(MKMessage *arg0) {
    s32 temp_r0_89;
    s32 temp_r3_107;

    temp_r0_89 = arg0->unk0;
    switch (temp_r0_89) {                           /* irregular */
    case 0xC2:
        temp_r3_107 = this->unk10;
        if (temp_r3_107 & 0x160000) {
            if ((temp_r3_107 & 0x20000) && ((u8) this->unk50.unk5A == 0)) {
                if (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x54)(M2C_FIELD(&gb, void ***, 0)) != 0) {
                    this->unk50.unk6D = 1;
                } else if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 8) != 0) || ((s32) *gGMState.GetCurrState() == 6)) {
                    this->unk50.unk6E = 1;
                } else if ((s32) M2C_FIELD(&gb, s32 *, 0x340) == 0) {
                    if ((u8) this->unk50.unk6C != 0) {
                        ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->PlayIntro(this->unk50, this->unk50.unk68);
                    } else {
                        ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->Play(this->unk50, this->unk50.unk68);
                    }
                }
            }
        default:
block_26:
            PropFlagsMessage((unsigned int *) &this->unk10, arg0);
            MKProp::Message(arg0);
        }
        break;
    case 0xBF:
        PropFlagsClear((unsigned int *) &this->unk10, 0x160000U);
        goto block_26;
    case 0xBE:
        PropFlagsSet((unsigned int *) &this->unk10, 0x160000U);
        goto block_26;
    case 0x2A:
        Disable();
        goto block_26;
    case 0x21:
        this->unk50.unk58 = 0;
        goto block_26;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6D'
void *CutsceneProp::Update() {
    MKProp::Update();
    this->unk50.Update();
    if ((s32) M2C_FIELD(&gb, s32 *, 0x340) == 0) {
        if (((u8) this->unk50.unk6D != 0) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x54)(M2C_FIELD(&gb, void ***, 0)) == 0)) {
            if ((u8) this->unk50.unk6C != 0) {
                ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->PlayIntro(this->unk50, this->unk50.unk68);
            } else {
                ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->Play(this->unk50, this->unk50.unk68);
            }
            this->unk50.unk6D = 0;
            return;
        }
        if (((u8) this->unk50.unk6E != 0) && ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 8) == 0) && ((s32) *gGMState.GetCurrState() == 7)) {
            bShowLoading = 1;
            if ((u8) this->unk50.unk6C != 0) {
                ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->PlayIntro(this->unk50, this->unk50.unk68);
            } else {
                ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->Play(this->unk50, this->unk50.unk68);
            }
            this->unk50.unk6E = 0;
        }
    }
}
#endif

s32 CutsceneProp::LoadLine(MKIniLine *arg0) {
    s32 result = 0;

    if (((u8) MKProp::LoadLine(arg0) != 0) || ((u8) arg0->LoadBool("bLevelIntro", (bool *) &this->unkBC, 0) != 0) || ((u8) arg0->LoadFloat("MusicDuckValue", &this->unkB8, 0) != 0) || ((u8) PropFlagsLoadLine((unsigned int *) &this->unk10, arg0) != 0) || ((u8) this->unk50.LoadLine(arg0) != 0)) {
        result = 1;
    }
    return result;
}

void CutsceneProp::Deinit() {
    MKProp::Deinit();
}

void CutsceneProp::Init() {
    MKProp::Init();
    this->unkBC = 0;
    this->unkB8 = 0.0f;
    PropFlagsSet((unsigned int *) &this->unk10, 0x160000U);
    this->unkBD = 0;
    this->unkBE = 0;
}
