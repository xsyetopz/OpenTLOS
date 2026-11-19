#include "spyro/source/ScriptedCounterProp.h"
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
#include <m2c_macros.h>

M2C_UNK __destroy_arr(u8 *, EventMessage *(*)(EventMessage *, s16), M2C_UNK, M2C_UNK); /* extern */

void ScriptedCounterProp::Message(MKMessage *arg0) {
    s32 temp_r3_56;

    if ((s32) arg0->unk0 == 0x14E) {
        temp_r3_56 = this->unk9C;
        if (temp_r3_56 < 0x14) {
            this->unk9C = temp_r3_56 + 1;
            ((EventMessage *) (this + ((temp_r3_56 * 4) + 0x4C)))->Send(NULL);
        }
    } else {
        MKProp::Message(arg0);
    }
}

f32 ScriptedCounterProp::Resolve() {
    MKProp::Resolve();
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to 'const char *'
s32 ScriptedCounterProp::LoadLine(MKIniLine *arg0) {
    f32 var_f1_98;
    s32 temp_ret_117;
    s32 temp_ret_98;
    s32 var_r29_105;
    s32 var_r31_107;

    temp_ret_98 = MKProp::LoadLine(arg0);
    var_f1_98 = M2C_BITWISE(f32, temp_ret_98);
    if (temp_ret_98 != 0) {
        return 1;
    }
    var_r29_105 = 0;
    var_r31_107 = 0;
loop_3:
    temp_ret_117 = (const char *) (((EventMessage *) (this + (var_r31_107 + 0x4C)))->LoadLine(arg0, Str_Printf("OnEventCount%d", var_r29_105 + 1, var_f1_98)));
    var_f1_98 = M2C_BITWISE(f32, temp_ret_117);
    if (temp_ret_117 != 0) {
        return 1;
    }
    var_r29_105 += 1;
    var_r31_107 += 4;
    if (var_r29_105 >= 0x14) {
        return 0;
    }
    goto loop_3;
}
#endif

void ScriptedCounterProp::Init() {
    s32 var_r30_146;
    s32 var_r31_145;

    MKProp::Init();
    var_r31_145 = 0;
    var_r30_146 = 0;
    this->unk9C = 0;
    do {
        ((EventMessage *) (this + (var_r31_145 + 0x4C)))->Init();
        var_r30_146 += 1;
        var_r31_145 += 4;
    } while (var_r30_146 < 0x14);
}
