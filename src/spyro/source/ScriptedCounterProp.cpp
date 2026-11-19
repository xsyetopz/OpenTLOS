#include "spyro/source/ScriptedCounterProp.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/EventMessage.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

M2C_UNK __destroy_arr(M2C_UNK *, EventMessage *(*)(EventMessage *, s16), M2C_UNK, M2C_UNK); /* extern */
static s8 lit_stringBase0[0xF] = {
    0x4F,
    0x6E,
    0x45,
    0x76,
    0x65,
    0x6E,
    0x74,
    0x43,
    0x6F,
    0x75,
    0x6E,
    0x74,
    0x25,
    0x64,
    0,
}; /* const */

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

void ScriptedCounterProp::Resolve() {
    MKProp::Resolve();
}

#if 0 // DRAFT: function call 'Str_Printf(signed char[15], long, float)' does not match
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
    temp_ret_117 = ((EventMessage *) (this + (var_r31_107 + 0x4C)))->LoadLine(arg0, Str_Printf(lit_stringBase0, var_r29_105 + 1, var_f1_98));
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
