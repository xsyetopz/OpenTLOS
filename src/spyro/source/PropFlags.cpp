#include "spyro/source/PropFlags.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
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

static M2C_UNK flagMap;                             /* unable to generate initializer: unknown type */

s32 PropFlagsMessage(unsigned int *arg0, MKMessage *arg1) {
    s32 temp_r4_11;

    temp_r4_11 = arg1->unk0;
    switch (temp_r4_11) {
    case 0xAF:
        *arg0 |= 0x20000;
        *arg0 &= 0xFFFFFFFB;
        return 1;
    case 0xAE:
        *arg0 &= 0xFFFDFFFF;
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return 1;
    case 0xB1:
        *arg0 |= 0x40000;
        *arg0 &= 0xFFFFFFF7;
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return 1;
    case 0xB0:
        *arg0 &= 0xFFFBFFFF;
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return 1;
    case 0xB3:
        *arg0 |= 0x100000;
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return 1;
    case 0xB2:
        *arg0 &= 0xFFEFFFFF;
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return 1;
    case 0xBE:
        *arg0 |= 0x160000;
        *arg0 &= 0xFFFFFFF3;
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return 1;
    case 0xBF:
        *arg0 &= 0xFFE9FFFF;
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return 1;
    case 0xB5:
        *arg0 |= 0x80000;
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return 1;
    case 0xB4:
        *arg0 &= 0xFFF7FFFF;
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return 1;
    default:
        return 0;
    }
}

void PropFlagsClear(unsigned int *arg0, unsigned int arg1) {
    u32 temp_r4_96;

    *arg0 &= ~arg1;
    temp_r4_96 = *arg0;
    if (!(temp_r4_96 & 0x40000)) {
        *arg0 = temp_r4_96 | 8;
    }
}

void PropFlagsSet(unsigned int *arg0, unsigned int arg1) {
    u32 temp_r4_110;

    *arg0 |= arg1;
    temp_r4_110 = *arg0;
    if (temp_r4_110 & 0x40000) {
        *arg0 = temp_r4_110 & 0xFFFFFFF7;
    }
}

s32 PropFlagsLoadLine(unsigned int *arg0, MKIniLine *arg1) {
    bool sp8;
    s32 var_r27_130;
    s32 var_r29_126;
    const char *temp_r4_163;
    void *temp_r28_162;

    var_r29_126 = 0;
    var_r27_130 = 0;
    sp8 = 0;
    while (var_r27_130 < 8 && (temp_r28_162 = (s8 *) &flagMap + var_r29_126, temp_r4_163 = M2C_FIELD(temp_r28_162, const char **, 4), (s8) *temp_r4_163 != 0)) {
        if (arg1->LoadBool(temp_r4_163, &sp8, 0) != 0) {
            if (sp8 != 0) {
                *arg0 |= M2C_FIELD(temp_r28_162, s32 *, 0);
            } else {
                *arg0 &= ~M2C_FIELD(temp_r28_162, s32 *, 0);
            }
            return 1;
        }
        var_r27_130 += 1;
        var_r29_126 += 8;
    }
    return 0;
}

void PropFlagsInit(unsigned int *arg0, unsigned int arg1) {
    *arg0 |= arg1;
}
