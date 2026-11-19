#include "spyro/source/CharacterDescriptor.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/KDProp.h"
#include <m2c_macros.h>

void CharacterDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
    this->unk70 |= 2;
    if ((s32) this->unk6C != 1) {
        return;
    }
    this->unk64 = this->unk68 + this->unk60;
}

s32 CharacterDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_46;

    var_r31_46 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (KDProp_LoadMaterialID(arg0, "materialID", (int *) &this->unk70) != 0) || (arg0->LoadInt("colItemType", (int *) &this->unk6C, 0) != 0) || (arg0->LoadFloat("charaColRadius", &this->unk60, 0) != 0) || (arg0->LoadFloat("charaColHeight", &this->unk64, 0) != 0) || (arg0->LoadFloat("charaColOffsetY", &this->unk68, 0) != 0) || (arg0->LoadBool("bFindGroundColour", (bool *) &this->unk74, 0) != 0) || (arg0->LoadBool("bStoreGroundColourResult", (bool *) ((u8 *) this + 0x75), 0) != 0) || (arg0->LoadString("overrideMaterial", (const char **) &this->unkDC, 0) != 0) || (arg0->LoadBool("bUseSteeringBehaviours", (bool *) ((u8 *) this + 0x77), 0) != 0) || (arg0->LoadBool("bPlayAnimSndsInCutscenes", (bool *) &this->unk78, 0) != 0) || (arg0->LoadBool("bUseQuickCollision", (bool *) ((u8 *) this + 0x76), 0) != 0)) {
        var_r31_46 = 1;
    }
    return var_r31_46;
}

void CharacterDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = 30.000002f;
    this->unk68 = 40.0f;
    this->unk64 = 2.0f * this->unk60;
    this->unk6C = 0;
    this->unk70 = 0;
    M2C_FIELD(this, s8 *, 0x74) = 0;
    M2C_FIELD(this, s8 *, 0x75) = 0;
    M2C_FIELD(this, s8 *, 0x76) = 0;
    M2C_FIELD(this, s8 *, 0x76) = 1;
    this->unk7C.Init();
    this->unk7C.unk0 = 40.0f;
    this->unk7C.unk4 = this->unk7C.unk0;
    this->unk7C.unk8 = 7;
    this->unk7C.unkC = 1;
    this->unk7C.unk10 = 2;
    this->unk7C.unk14 = 0;
    this->unk7C.unk18 = 0x200;
    this->unk7C.unk1C = 0.8f;
    this->unk7C.unk20 = -1.0f;
    this->unk7C.unk24 = 1;
    this->unk7C.unk28 = 0x4000;
    this->unk7C.unk2C = 0.0f;
    this->unk7C.unk30 = -1.0f;
    this->unk7C.unk34 = 1;
    this->unk7C.unk38 = 1;
    this->unk7C.unk3C = -0.8f;
    this->unk7C.unk40 = -1.0f;
    this->unk7C.unk44 = 1;
    this->unk7C.unk48 = 0;
    memset(&this->unkC8, 0, 0x14U);
    this->unkD0 = -980.0f;
    this->unkD4 = 1;
    M2C_FIELD(this, f32 *, 0xC8) = 550.0f;
    this->unkCC = 9.0f;
    this->unkE0 = -1;
    this->unkE4 = -1;
    this->unkDC = NULL;
    M2C_FIELD(this, s8 *, 0x77) = 0;
    M2C_FIELD(this, s8 *, 0x78) = 0;
}
