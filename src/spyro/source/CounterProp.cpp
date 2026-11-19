#include "spyro/source/CounterProp.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include <m2c_macros.h>

static s8 lit_stringBase0[0x21] = {
    0x69,
    0x43,
    0x6F,
    0x75,
    0x6E,
    0x74,
    0x53,
    0x69,
    0x7A,
    0x65,
    0,
    0x62,
    0x52,
    0x65,
    0x73,
    0x65,
    0x74,
    0x4F,
    0x6E,
    0x43,
    0x6F,
    0x75,
    0x6E,
    0x74,
    0,
    0x4F,
    0x6E,
    0x43,
    0x6F,
    0x75,
    0x6E,
    0x74,
    0,
}; /* const */

void CounterProp::Deinit() {
    MKProp::Deinit();
}

void CounterProp::Message(MKMessage *arg0) {
    s32 temp_r0_67;

    temp_r0_67 = arg0->unk0;
    switch (temp_r0_67) {                           /* irregular */
    case 0x14E:
        this->unk54 += 1;
        if (((s32) this->unk54 >= (s32) this->unk50) && ((u8) this->unk59 == 0)) {
            this->unk4C.Send(NULL);
            if ((u8) this->unk58 != 0) {
                this->unk54 = 0;
            } else {
                this->unk59 = 1;
            }
        }
        break;
    case 0x14F:
        this->unk54 -= 1;
        break;
    case 0xD5:
        this->unk54 = 0;
        this->unk59 = 0;
        break;
    }
    MKProp::Message(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char[33]' to
s32 CounterProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_131;

    var_r31_131 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt(lit_stringBase0, &this->unk50, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0xB], &this->unk58, 0) != 0) || (this->unk4C.LoadLine(arg0, &lit_stringBase0[0x19]) != 0)) {
        var_r31_131 = 1;
    }
    return var_r31_131;
}
#endif

void CounterProp::Init() {
    MKProp::Init();
    this->unk50 = 0;
    this->unk54 = 0;
    this->unk59 = 0;
    this->unk58 = 0;
}
