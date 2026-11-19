#include "spyro/source/PooledShatterProp.h"
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
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal type
void *PooledShatterProp::Update() {
    s32 temp_r4_133;
    void *temp_r3_129;

    Shatterable::Update();
    temp_r3_129 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (((s32) this->unk16C == 0) || ((temp_r4_133 = this->unk180, ((temp_r4_133 == (s32) M2C_FIELD(temp_r3_129, s32 *, 0x160)) != 0)) && ((s32) *(this->unk168 + (((temp_r4_133 - 1) << 7) + 0x44)) == 2))) {
        Reset();
        Disable();
    }
}
#endif
