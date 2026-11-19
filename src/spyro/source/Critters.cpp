#include "spyro/source/Critters.h"
#include "common/Source/MKIni.h"
#include "spyro/source/KDProp.h"
#include <m2c_macros.h>

void Critters::Draw() {

}

void Critters::Update() {

}

#if 0 // DRAFT: undefined identifier 'unk9C'
void Critters::LoadDone() {
    KDProp::LoadDone();
    M2C_STRUCT_COPY((s32) &this->unk9C + 4, (s32) (this->unk8 - 4) + 4, 0x40);
    this->unkA0.unk40.Init(this->unkA0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 Critters::LoadLine(MKIniLine *arg0) {
    s32 var_r31_59;

    var_r31_59 = 0;
    if ((KDProp::LoadLine(arg0) != 0) || (arg0->LoadInt("count", &this->unk90, 0) != 0)) {
        var_r31_59 = 1;
    }
    return var_r31_59;
}
#endif

void Critters::Deinit() {
    this->unk90 = 0;
    KDProp::Deinit();
}

void Critters::Init() {
    KDProp::Init();
    this->unk90 = 0;
}
