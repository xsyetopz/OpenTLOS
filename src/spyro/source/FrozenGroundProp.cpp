#include "spyro/source/FrozenGroundProp.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"
#include <m2c_macros.h>

void FrozenGroundProp::Deinit() {
    KDProp::Deinit();
}

void FrozenGroundProp::Init() {
    KDProp::Init();
}
