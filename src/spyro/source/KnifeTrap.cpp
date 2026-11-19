#include "spyro/source/KnifeTrap.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Trap.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

void *KnifeTrap::Update() {
    GameProp::Update();
    if (this->unk10 & 0x20000) {

    }
}

void KnifeTrap::Reset() {
    PropFlagsSet((unsigned int *) &this->unk10, 0x80000U);
    Trap::Reset();
}

void KnifeTrapDescriptor::Init() {
    TrapDescriptor::Init();
    this->unkC = 0x12;
}
