#include "spyro/source/ToggleProp.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/KDProp.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/gc/MKModel_GC.h"
#include <m2c_macros.h>

static s8 lit_stringBase0[0x2A] = {
    0x53,
    0x75,
    0x62,
    0x6F,
    0x62,
    0x6A,
    0x65,
    0x63,
    0x74,
    0x4F,
    0x6E,
    0,
    0x53,
    0x75,
    0x62,
    0x6F,
    0x62,
    0x6A,
    0x65,
    0x63,
    0x74,
    0x4F,
    0x66,
    0x66,
    0,
    0x62,
    0x53,
    0x74,
    0x61,
    0x72,
    0x74,
    0x4F,
    0x6E,
    0,
    0x62,
    0x54,
    0x6F,
    0x67,
    0x67,
    0x6C,
    0x65,
    0,
}; /* const */

void ToggleProp::Deinit() {
    KDProp::Deinit();
}

#if 0 // DRAFT: ')' expected
void ToggleProp::Message(MKMessage *arg0) {
    s32 temp_r0_64;
    u8 temp_r4_85;

    temp_r0_64 = arg0->unk0;
    switch (temp_r0_64) {                           /* irregular */
    case 0xB5:
        if ((u8) M2C_FIELD(checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x81) != 0) {
            this->unk90 = this->unk90 == 0;
        } else {
            temp_r4_85 = this->unk90;
            if (temp_r4_85 == (u8) M2C_FIELD(checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x80)) {
                this->unk90 = temp_r4_85 == 0;
            }
        }
        break;
    case 0xB4:
        this->unk90 = 0;
        break;
    }
    KDProp::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void ToggleProp::Draw() {
    if ((u8) this->unk90 != 0) {
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x78), 1U, 1U);
    } else {
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x7C), 1U, 1U);
    }
    MKModel_Draw(this->unk4, NULL);
}
#endif

#if 0 // DRAFT: ')' expected
void ToggleProp::Init() {
    KDProp::Init();
    this->unk90 = M2C_FIELD(checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x80);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void TogglePropDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void TogglePropDescriptor::LoadDone() {
    KDPropDescriptor::LoadDone();
    this->unk78 = MKModel_GetSubObjectIndex(this->unk2C, (SubObjectType) 0, this->unk70);
    this->unk7C = MKModel_GetSubObjectIndex(this->unk2C, (SubObjectType) 0, this->unk74);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 TogglePropDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_217;

    var_r31_217 = 0;
    if ((KDPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadString(lit_stringBase0, &this->unk70, 0) != 0) || (arg0->LoadString(&lit_stringBase0[0xC], &this->unk74, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x19], (u8 *) &this->unk80, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x22], this + 0x81, 0) != 0)) {
        var_r31_217 = 1;
    }
    return var_r31_217;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void TogglePropDescriptor::Init() {
    KDPropDescriptor::Init();
    this->unk78 = -1;
    this->unk7C = -1;
    M2C_FIELD(this, s8 *, 0x80) = 0;
    M2C_FIELD(this, s8 *, 0x81) = 1;
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<TogglePropDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
