#include "spyro/source/CameraCollideProp.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"
#include <m2c_macros.h>

extern M2C_UNK gb;

void CameraCollideProp::Reset() {
    KDProp::Reset();
    this->unk70.unk4 = 0;
}

s32 CameraCollideProp::LoadDone() {
    s8 sp14;
    MKCollisionInfo *sp10;
    s32 spC;
    s32 sp8;
    MKCollisionInfo *temp_r5_88;

    KDProp::LoadDone();
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        temp_r5_88 = &this->unk70;
        spC = 0;
        sp8 = 0x40F;
        sp10 = temp_r5_88;
        sp14 = 1;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *, MKCollisionInfo *, M2C_UNK), 0x2C)(&sp8, temp_r5_88, 0x40F);
    }
}

void CameraCollideProp::Deinit() {
    MKCollisionInfo *sp10;
    s32 spC;
    s32 sp8;

    spC = 0;
    sp8 = 0x410;
    sp10 = &this->unk70;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8, 0x410);
    KDProp::Deinit();
}
