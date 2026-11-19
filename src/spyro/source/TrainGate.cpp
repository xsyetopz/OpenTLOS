#include "spyro/source/TrainGate.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'TrainGateState'
static s8 lit_stringBase0[0x29] = {
    0x6F,
    0x6E,
    0x4F,
    0x70,
    0x65,
    0x6E,
    0x65,
    0x64,
    0,
    0x4E,
    0x75,
    0x6D,
    0x53,
    0x77,
    0x69,
    0x74,
    0x63,
    0x68,
    0x65,
    0x73,
    0,
    0x63,
    0x6C,
    0x6F,
    0x73,
    0x65,
    0x64,
    0,
    0x6F,
    0x70,
    0x65,
    0x6E,
    0x69,
    0x6E,
    0x67,
    0,
    0x6F,
    0x70,
    0x65,
    0x6E,
    0,
}; /* const */

void TrainGate::SetState(TrainGateState arg0) {
    this->unkCC = (s32) arg0;
    this->unk80->SetAnim(M2C_FIELD((checked_cast<TrainGateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unkCC * 4)), MKAnim **, 0xE4), 1.0f, 0.0f, 0, -1);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void TrainGate::Message(MKMessage *arg0) {
    s32 temp_r0_80;

    temp_r0_80 = arg0->unk0;
    switch (temp_r0_80) {                           /* irregular */
    case 0xB5:
        this->unkD4 += 1;
        if ((s32) this->unkD4 >= (s32) this->unkD0) {
            this->unkC8.Send(NULL);
            SetState((TrainGateState) 1);
        }
        break;
    case 0xB4:
        M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x20)();
        break;
    }
    GameProp::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void TrainGate::Update() {
    GameProp::Update();
    if ((s32) this->unkCC != 1) {
        return;
    }
    if (this->unk80->unk2C & 1) {
        SetState((TrainGateState) 2);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void TrainGate::Reset() {
    GameProp::Reset();
    SetState((TrainGateState) 0);
    this->unkD4 = 0;
}
#endif

void TrainGate::Resolve() {
    KDPropEx::Resolve();
}

void TrainGate::LoadDone() {
    GameProp::LoadDone();
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char[41]' to
s32 TrainGate::LoadLine(MKIniLine *arg0) {
    s32 var_r31_203;

    var_r31_203 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (this->unkC8.LoadLine(arg0, lit_stringBase0) != 0) || (arg0->LoadInt(&lit_stringBase0[9], &this->unkD0, 0) != 0)) {
        var_r31_203 = 1;
    }
    return var_r31_203;
}
#endif

void TrainGate::Deinit() {
    GameProp::Deinit();
}

void TrainGate::Init() {
    GameProp::Init();
    this->unkD0 = 3;
    this->unkD4 = 0;
}

#if 0 // DRAFT: expression syntax error
void TrainGateDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    this->unkE4 = this->unk34->GetAnim(&lit_stringBase0[0x15]);
    this->unkE8 = this->unk34->GetAnim(&lit_stringBase0[0x1C]);
    this->unkEC = this->unk34->GetAnim(&lit_stringBase0[0x24]);
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<TrainGateDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
