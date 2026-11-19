#include "spyro/source/Critters.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/Volume.h"
#include <m2c_macros.h>

void Critters::Draw() {

}

void *Critters::Update() {

}

s32 Critters::LoadDone() {
    KDProp::LoadDone();
    M2C_STRUCT_COPY((s32) &this->unk9C + 4, (s32) (((u8 *) this->unk8) - 4) + 4, 0x40);
    this->unkE0.Init(this->unkA0);
}

s32 Critters::LoadLine(MKIniLine *arg0) {
    s32 var_r31_59;

    var_r31_59 = 0;
    if ((KDProp::LoadLine(arg0) != 0) || (arg0->LoadInt("count", (int *) &this->unk90, 0) != 0)) {
        var_r31_59 = 1;
    }
    return var_r31_59;
}

void Critters::Deinit() {
    this->unk90 = 0;
    KDProp::Deinit();
}

void Critters::Init() {
    KDProp::Init();
    this->unk90 = 0;
}
