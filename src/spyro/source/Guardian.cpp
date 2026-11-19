#include "spyro/source/Guardian.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKIni.h"
#include "spyro/source/KDProp.h"
#include "common/Source/MKModel.h"
#include <m2c_macros.h>

static s8 lit_stringBase0[0x38] = {
    0x69,
    0x64,
    0x6C,
    0x65,
    0x30,
    0x31,
    0,
    0x43,
    0x61,
    0x67,
    0x65,
    0x49,
    0x64,
    0x6C,
    0x65,
    0x30,
    0x31,
    0,
    0x53,
    0x6C,
    0x75,
    0x6D,
    0x70,
    0x65,
    0x64,
    0,
    0x53,
    0x75,
    0x73,
    0x70,
    0x65,
    0x6E,
    0x64,
    0x65,
    0x64,
    0,
    0x62,
    0x53,
    0x6C,
    0x75,
    0x6D,
    0x70,
    0x65,
    0x64,
    0,
    0x62,
    0x53,
    0x75,
    0x73,
    0x70,
    0x65,
    0x6E,
    0x64,
    0x65,
    0x64,
    0,
}; /* const */

void Guardian::AttachToCage(bool arg0) {
    if (arg0 != 0) {
        this->unk80->SetAnim(this->unk94, 1.0f, 0.0f, 0, -1);
        return;
    }
    this->unk80->SetAnim(this->unk90, 1.0f, 0.0f, 0, -1);
}

void Guardian::Draw() {
    KDProp::Draw();
}

void Guardian::Update() {
    KDProp::Update();
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char[56]' to
void Guardian::LoadDone() {
    MKAnim *var_r3_119;
    MKAnim *var_r3_137;
    MKAnim *var_r3_155;
    MKAnim *var_r3_173;
    MKAnimScript *temp_r30_109;
    MKAnimScript *temp_r30_127;
    MKAnimScript *temp_r30_145;
    MKAnimScript *temp_r30_163;

    KDProp::LoadDone();
    temp_r30_109 = this->unk80;
    if (temp_r30_109->Exists(lit_stringBase0) != 0) {
        var_r3_119 = temp_r30_109->GetAnim(lit_stringBase0);
    } else {
        var_r3_119 = NULL;
    }
    this->unk90 = var_r3_119;
    temp_r30_127 = this->unk80;
    if (temp_r30_127->Exists(&lit_stringBase0[7]) != 0) {
        var_r3_137 = temp_r30_127->GetAnim(&lit_stringBase0[7]);
    } else {
        var_r3_137 = NULL;
    }
    this->unk94 = var_r3_137;
    temp_r30_145 = this->unk80;
    if (temp_r30_145->Exists(&lit_stringBase0[0x12]) != 0) {
        var_r3_155 = temp_r30_145->GetAnim(&lit_stringBase0[0x12]);
    } else {
        var_r3_155 = NULL;
    }
    this->unk98 = var_r3_155;
    temp_r30_163 = this->unk80;
    if (temp_r30_163->Exists(&lit_stringBase0[0x1A]) != 0) {
        var_r3_173 = temp_r30_163->GetAnim(&lit_stringBase0[0x1A]);
    } else {
        var_r3_173 = NULL;
    }
    this->unk9C = var_r3_173;
    MKModel_SetColor(this->unk4, loadInfo + 0x70);
    if ((u8) this->unkA0 != 0) {
        this->unk80->SetAnim(this->unk98, 1.0f, 0.0f, 0, -1);
        return;
    }
    if ((u8) this->unkA1 != 0) {
        this->unk80->SetAnim(this->unk9C, 1.0f, 0.0f, 0, -1);
        return;
    }
    this->unk80->SetAnim(this->unk90, 1.0f, 0.0f, 0, -1);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
s32 Guardian::LoadLine(MKIniLine *arg0) {
    s32 var_r31_232;

    var_r31_232 = 0;
    if ((KDProp::LoadLine(arg0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x24], &this->unkA0, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x2D], &this->unkA1, 0) != 0)) {
        var_r31_232 = 1;
    }
    return var_r31_232;
}
#endif

void Guardian::Deinit() {
    KDProp::Deinit();
}

void Guardian::Init() {
    KDProp::Init();
    this->unkA0 = 0;
    this->unkA1 = 0;
}
