#include "spyro/source/CharacterDescriptor.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/KDProp.h"
#include <m2c_macros.h>

static s8 lit_stringBase0[0xC4] = {
    0x6D,
    0x61,
    0x74,
    0x65,
    0x72,
    0x69,
    0x61,
    0x6C,
    0x49,
    0x44,
    0,
    0x63,
    0x6F,
    0x6C,
    0x49,
    0x74,
    0x65,
    0x6D,
    0x54,
    0x79,
    0x70,
    0x65,
    0,
    0x63,
    0x68,
    0x61,
    0x72,
    0x61,
    0x43,
    0x6F,
    0x6C,
    0x52,
    0x61,
    0x64,
    0x69,
    0x75,
    0x73,
    0,
    0x63,
    0x68,
    0x61,
    0x72,
    0x61,
    0x43,
    0x6F,
    0x6C,
    0x48,
    0x65,
    0x69,
    0x67,
    0x68,
    0x74,
    0,
    0x63,
    0x68,
    0x61,
    0x72,
    0x61,
    0x43,
    0x6F,
    0x6C,
    0x4F,
    0x66,
    0x66,
    0x73,
    0x65,
    0x74,
    0x59,
    0,
    0x62,
    0x46,
    0x69,
    0x6E,
    0x64,
    0x47,
    0x72,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0x43,
    0x6F,
    0x6C,
    0x6F,
    0x75,
    0x72,
    0,
    0x62,
    0x53,
    0x74,
    0x6F,
    0x72,
    0x65,
    0x47,
    0x72,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0x43,
    0x6F,
    0x6C,
    0x6F,
    0x75,
    0x72,
    0x52,
    0x65,
    0x73,
    0x75,
    0x6C,
    0x74,
    0,
    0x6F,
    0x76,
    0x65,
    0x72,
    0x72,
    0x69,
    0x64,
    0x65,
    0x4D,
    0x61,
    0x74,
    0x65,
    0x72,
    0x69,
    0x61,
    0x6C,
    0,
    0x62,
    0x55,
    0x73,
    0x65,
    0x53,
    0x74,
    0x65,
    0x65,
    0x72,
    0x69,
    0x6E,
    0x67,
    0x42,
    0x65,
    0x68,
    0x61,
    0x76,
    0x69,
    0x6F,
    0x75,
    0x72,
    0x73,
    0,
    0x62,
    0x50,
    0x6C,
    0x61,
    0x79,
    0x41,
    0x6E,
    0x69,
    0x6D,
    0x53,
    0x6E,
    0x64,
    0x73,
    0x49,
    0x6E,
    0x43,
    0x75,
    0x74,
    0x73,
    0x63,
    0x65,
    0x6E,
    0x65,
    0x73,
    0,
    0x62,
    0x55,
    0x73,
    0x65,
    0x51,
    0x75,
    0x69,
    0x63,
    0x6B,
    0x43,
    0x6F,
    0x6C,
    0x6C,
    0x69,
    0x73,
    0x69,
    0x6F,
    0x6E,
    0,
}; /* const */

void CharacterDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
    this->unk70 |= 2;
    if ((s32) this->unk6C != 1) {
        return;
    }
    this->unk64 = this->unk68 + this->unk60;
}

#if 0 // DRAFT: function call 'KDProp_LoadMaterialID(MKIniLine *, signed char[196], long
s32 CharacterDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_46;

    var_r31_46 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (KDProp_LoadMaterialID(arg0, lit_stringBase0, &this->unk70) != 0) || (arg0->LoadInt(&lit_stringBase0[0xB], &this->unk6C, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x17], &this->unk60, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x26], &this->unk64, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x35], &this->unk68, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x45], (u8 *) &this->unk74, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x57], this + 0x75, 0) != 0) || (arg0->LoadString(&lit_stringBase0[0x70], &this->unkDC, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x81], this + 0x77, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x98], (u8 *) &this->unk78, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0xB1], this + 0x76, 0) != 0)) {
        var_r31_46 = 1;
    }
    return var_r31_46;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
void CharacterDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = 30.000002f;
    this->unk68 = 40.0f;
    this->unk64 = 2.0f * this->unk60;
    this->unk6C = 0;
    this->unk70 = 0;
    M2C_FIELD(this, s8 *, 0x74) = 0;
    M2C_FIELD(this, s8 *, 0x75) = 0;
    M2C_FIELD(this, s8 *, 0x76) = 0;
    M2C_FIELD(this, s8 *, 0x76) = 1;
    this->unk7C.Init();
    this->unk7C.unk0 = 40.0f;
    this->unk7C.unk4 = this->unk7C.unk0;
    this->unk7C.unk8 = 7;
    this->unk7C.unkC = 1;
    this->unk7C.unk10 = 2;
    this->unk7C.unk14 = 0;
    this->unk7C.unk18 = 0x200;
    this->unk7C.unk1C = 0.8f;
    this->unk7C.unk20 = -1.0f;
    this->unk7C.unk24 = 1;
    this->unk7C.unk28 = 0x4000;
    this->unk7C.unk2C = 0.0f;
    this->unk7C.unk30 = -1.0f;
    this->unk7C.unk34 = 1;
    this->unk7C.unk38 = 1;
    this->unk7C.unk3C = -0.8f;
    this->unk7C.unk40 = -1.0f;
    this->unk7C.unk44 = 1;
    this->unk7C.unk48 = 0;
    memset(&this->unkC8, 0, 0x14U);
    this->unkD0 = -980.0f;
    this->unkD4 = 1;
    M2C_FIELD(this, f32 *, 0xC8) = 550.0f;
    this->unkCC = 9.0f;
    this->unkE0 = -1;
    this->unkE4 = -1;
    this->unkDC = NULL;
    M2C_FIELD(this, s8 *, 0x77) = 0;
    M2C_FIELD(this, s8 *, 0x78) = 0;
}
#endif
