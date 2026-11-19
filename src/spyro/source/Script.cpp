#include "spyro/source/Script.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/EventMessage.h"
#include "common/Source/Str.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

M2C_UNK __destroy_arr(ScriptProp *, EventMessage *(*)(EventMessage *, s16), M2C_UNK, M2C_UNK); /* extern */
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: function call 'PropFlagsClear(unsigned long *, unsigned int)' does not
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
        PropFlagsClear((u32 *) &this->unk10, 0x80000U);
    }
}
#endif

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void ScriptProp::Message(MKMessage *arg0) {
    s32 temp_r0_100;

    temp_r0_100 = arg0->unk0;
    switch (temp_r0_100) {                          /* irregular */
    case 0xB5:
        if (this->unk10 & 0x160000) {
            PropFlagsSet((u32 *) &this->unk10, 0x80000U);
            this->unk56 = 0;
            this->unk50 = this->unk4C;
            if (this->unk4C <= 0.0f) {
                Execute();
            }
        }
        break;
    case 0xB4:
        if (this->unk10 & 0x160000) {
            PropFlagsClear((u32 *) &this->unk10, 0x80000U);
        }
        break;
    case 0xBE:
        PropFlagsSet((u32 *) &this->unk10, 0x160000U);
        break;
    case 0xBF:
        PropFlagsClear((u32 *) &this->unk10, 0x160000U);
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
#endif

void ScriptProp::Reset() {
    MKProp::Reset();
    this->unk50 = 0.0f;
    this->unk56 = 0;
    this->unk55 = 0;
}

#if 0 // DRAFT: function call 'PropFlagsClear(unsigned long *, unsigned int)' does not
void ScriptProp::Update() {
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
                    PropFlagsClear((u32 *) &this->unk10, 0x80000U);
                    return;
                }
                this->unk50 = this->unk4C;
                return;
            }
            Execute();
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
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
    temp_ret_299 = ((EventMessage *) (this + (var_r31_289 + 0x58)))->LoadLine(arg0, Str_Printf("Message%d", var_r29_287, var_f1_280));
    var_f1_280 = M2C_BITWISE(f32, temp_ret_299);
    if (temp_ret_299 != 0) {
        return 1;
    }
    var_r29_287 += 1;
    var_r31_289 += 4;
    if (var_r29_287 >= 0xA) {
        var_r31_314 = 0;
        if ((arg0->LoadFloat("delay", &this->unk4C, 0) != 0) || (arg0->LoadBool("bDelayEachMessage", &this->unk54, 0) != 0) || (PropFlagsLoadLine((u32 *) &this->unk10, arg0) != 0)) {
            var_r31_314 = 1;
        }
        return var_r31_314;
    }
    goto loop_3;
}
#endif

#if 0 // DRAFT: function call 'PropFlagsInit(unsigned long *, unsigned int)' does not
void ScriptProp::Init() {
    MKProp::Init();
    this->unk4C = 0.0f;
    this->unk50 = 0.0f;
    this->unk54 = 0;
    this->unk55 = 0;
    this->unk56 = 0;
    PropFlagsInit((u32 *) &this->unk10, 0x160000U);
}
#endif
