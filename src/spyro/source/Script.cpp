#include "spyro/source/Script.h"
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
#include "common/Source/Str.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

M2C_UNK __destroy_arr(ScriptProp *, EventMessage *(*)(EventMessage *, s16), M2C_UNK, M2C_UNK); /* extern */
extern f32 gUpdateTimeDelta;

void ScriptProp::Execute() {
    u8 temp_r3_66;

loop_2:
    temp_r3_66 = this->unk56;
    if (((s8) temp_r3_66 < 0xA) && ((u8) this->unk55 == 0)) {
        ((EventMessage *) (this + (((s8) temp_r3_66 * 4) + 0x58)))->Send((MKProp *) this);
        this->unk56 += 1;
        goto loop_2;
    }
    if (((u8) this->unk55 == 0) && ((s8) temp_r3_66 == 0xA)) {
        PropFlagsClear((unsigned int *) &this->unk10, 0x80000U);
    }
}

void ScriptProp::Message(MKMessage *arg0) {
    s32 temp_r0_100;

    temp_r0_100 = arg0->unk0;
    switch (temp_r0_100) {                          /* irregular */
    case 0xB5:
        if (this->unk10 & 0x160000) {
            PropFlagsSet((unsigned int *) &this->unk10, 0x80000U);
            this->unk56 = 0;
            this->unk50 = this->unk4C;
            if (this->unk4C <= 0.0f) {
                Execute();
            }
        }
        break;
    case 0xB4:
        if (this->unk10 & 0x160000) {
            PropFlagsClear((unsigned int *) &this->unk10, 0x80000U);
        }
        break;
    case 0xBE:
        PropFlagsSet((unsigned int *) &this->unk10, 0x160000U);
        break;
    case 0xBF:
        PropFlagsClear((unsigned int *) &this->unk10, 0x160000U);
        break;
    case 0xE4:
        if (this->unk10 & 0x80000) {
            this->unk55 = 1;
        }
        break;
    case 0xE5:
        if ((u8) this->unk55 != 0) {
            this->unk55 = 0;
            if (this->unk4C <= 0.0f) {
                Execute();
            }
        }
        break;
    }
    MKProp::Message(arg0);
}

void ScriptProp::Reset() {
    MKProp::Reset();
    this->unk50 = 0.0f;
    this->unk56 = 0;
    this->unk55 = 0;
}

void *ScriptProp::Update() {
    s32 temp_r3_218;
    u8 temp_r3_240;

    MKProp::Update();
    temp_r3_218 = this->unk10;
    if (temp_r3_218 & 0x20000) {
        if (!(temp_r3_218 & 0x80000)) {
            return;
        }
        if (((u8) this->unk55 == 0) && (this->unk50 -= gUpdateTimeDelta, ((this->unk50 <= 0.0f) != 0))) {
            if ((u8) this->unk54 != 0) {
                temp_r3_240 = this->unk56;
                this->unk56 = temp_r3_240 + 1;
                ((EventMessage *) (this + (((s8) temp_r3_240 * 4) + 0x58)))->Send((MKProp *) this);
                if ((s32) this->unk56 == 0xA) {
                    PropFlagsClear((unsigned int *) &this->unk10, 0x80000U);
                    return;
                }
                this->unk50 = this->unk4C;
                return;
            }
            Execute();
        }
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to 'const char *'
s32 ScriptProp::LoadLine(MKIniLine *arg0) {
    f32 var_f1_280;
    s32 temp_ret_280;
    s32 temp_ret_299;
    s32 var_r29_287;
    s32 var_r31_289;
    s32 var_r31_314;

    temp_ret_280 = MKProp::LoadLine(arg0);
    var_f1_280 = M2C_BITWISE(f32, temp_ret_280);
    if (temp_ret_280 != 0) {
        return 1;
    }
    var_r29_287 = 0;
    var_r31_289 = 0;
loop_3:
    temp_ret_299 = (const char *) (((EventMessage *) (this + (var_r31_289 + 0x58)))->LoadLine(arg0, Str_Printf("Message%d", var_r29_287, var_f1_280)));
    var_f1_280 = M2C_BITWISE(f32, temp_ret_299);
    if (temp_ret_299 != 0) {
        return 1;
    }
    var_r29_287 += 1;
    var_r31_289 += 4;
    if (var_r29_287 >= 0xA) {
        var_r31_314 = 0;
        if ((arg0->LoadFloat("delay", &this->unk4C, 0) != 0) || (arg0->LoadBool("bDelayEachMessage", &this->unk54, 0) != 0) || (PropFlagsLoadLine((unsigned int *) &this->unk10, arg0) != 0)) {
            var_r31_314 = 1;
        }
        return var_r31_314;
    }
    goto loop_3;
}
#endif

void ScriptProp::Init() {
    MKProp::Init();
    this->unk4C = 0.0f;
    this->unk50 = 0.0f;
    this->unk54 = 0;
    this->unk55 = 0;
    this->unk56 = 0;
    PropFlagsInit((unsigned int *) &this->unk10, 0x160000U);
}
