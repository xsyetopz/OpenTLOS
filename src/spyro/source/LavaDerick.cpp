#include "spyro/source/LavaDerick.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
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
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;

#if 0 // DRAFT: ')' expected
void LavaDerick::Message(MKMessage *arg0) {
    LavaDerick *spC;
    s32 sp8;
    void **temp_r3_61;
    void *temp_r3_65;

    if ((s32) arg0->unk0 != 0x12) {

    } else if ((s32) this->unk180 == (s32) (M2C_FIELD(checked_cast<LavaDerickDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x160) - 1)) {
        temp_r3_61 = M2C_FIELD(checked_cast<CollisionObjectCollideMsg *, MKMessage>(arg0), void ***, 0xC);
        temp_r3_65 = M2C_FIELD(*temp_r3_61, void *(**)(void **), 0x2C)(temp_r3_61);
        if (temp_r3_65 != NULL) {
            spC = NULL;
            sp8 = 0x1A;
            spC = this;
            M2C_FIELD(M2C_FIELD(temp_r3_65, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
    }
    Shatterable::Message(arg0);
}
#endif

void *LavaDerickDescriptor::CalcBounds() {
    MKVector3 sp8;
    BoundingVolume *bv;
    f32 var_f0;

    MKModel_CalculateRefPointWorldPosition(this->unk2C, (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "hurtsphere1"), &sp8);
    bv = this->unk1C;
    var_f0 = sp8.unk0;
    if (var_f0 < bv->unk0) {
    } else {
        var_f0 = bv->unk0;
    }
    bv->unk0 = var_f0;
    var_f0 = sp8.unk4;
    if (var_f0 < bv->unk4) {
    } else {
        var_f0 = bv->unk4;
    }
    bv->unk4 = var_f0;
    var_f0 = sp8.unk8;
    if (var_f0 < bv->unk8) {
    } else {
        var_f0 = bv->unk8;
    }
    bv->unk8 = var_f0;
    var_f0 = sp8.unk0 - bv->unk0;
    if (var_f0 > bv->unk10) {
    } else {
        var_f0 = bv->unk10;
    }
    bv->unk10 = var_f0;
    var_f0 = sp8.unk4 - bv->unk4;
    if (var_f0 > bv->unk14) {
    } else {
        var_f0 = bv->unk14;
    }
    bv->unk14 = var_f0;
    var_f0 = sp8.unk8 - bv->unk8;
    if (var_f0 > bv->unk18) {
    } else {
        var_f0 = bv->unk18;
    }
    bv->unk18 = var_f0;
    bv->unk10 = bv->unk10 - bv->unk0;
    bv->unk14 = bv->unk14 - bv->unk4;
    bv->unk18 -= bv->unk8;
    return &bv->unk10;
}

void LavaDerickDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    CalcBounds();
}

void LavaDerick_cpp::__sinit() {
    f32 temp_f0_247;
    f64 temp_f1_228;
    f64 temp_f1_236;
    f64 temp_f3_216;
    f64 temp_f4_225;
    f64 temp_f4_233;
    f64 temp_f8_218;

    temp_f3_216 = __frsqrte(2014000.0);
    temp_f8_218 = __frsqrte(380000.0);
    temp_f4_225 = 0.5 * temp_f3_216 * -((2014000.0 * (temp_f3_216 * temp_f3_216)) - 3.0);
    temp_f1_228 = 0.5 * temp_f8_218 * -((380000.0 * (temp_f8_218 * temp_f8_218)) - 3.0);
    temp_f4_233 = 0.5 * temp_f4_225 * -((2014000.0 * (temp_f4_225 * temp_f4_225)) - 3.0);
    temp_f1_236 = 0.5 * temp_f1_228 * -((380000.0 * (temp_f1_228 * temp_f1_228)) - 3.0);
    temp_f0_247 = (f32) (380000.0 * (0.5 * temp_f1_236 * -((380000.0 * (temp_f1_236 * temp_f1_236)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_233 * -((2014000.0 * (temp_f4_233 * temp_f4_233)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_247;
}
