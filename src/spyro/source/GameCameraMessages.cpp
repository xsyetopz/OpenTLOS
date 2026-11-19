#include "spyro/source/GameCameraMessages.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/Matrix.h"
#include <m2c_macros.h>

void AddCameraTrackedShakePropMessage::Init(MKProp *arg0, float arg1, float arg2, bool arg3, float arg4) {
    this->unk0 = 0x455;
    this->unk8 = arg0;
    this->unkC = arg1;
    this->unk10 = arg2;
    this->unk14 = (s8) arg3;
    this->unk18 = arg4;
}
