#include "spyro/source/CynderEnergyCrystal.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/CollisionObject.h"
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
#include "spyro/source/Level.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_EnergyCrystalBounce;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;

static s32 lit_598 = 0;
static u8 lit_599 = 0;

void CynderEnergyCrystal::UpdateModel() {
    Matrix sp20;
    M2C_UNK sp1C;
    f64 sp18;
    f64 sp10;
    ManagedLight *temp_r3_78;
    Matrix *temp_r5_57;
    void *temp_r3_82;

    M2C_STRUCT_COPY((s32) &sp1C + 4, (s32) &this->unkCC + 4, 0x40);
    temp_r5_57 = this->unkC8;
    if (temp_r5_57 != NULL) {
        sp20.Multiply(&sp20, temp_r5_57);
    }
    MKModel_SetWorldMatrix(this->unk4, sp20);
    if ((ManagedLight *) this->unk5E4 != NULL) {
        MKModel_CalculateNodeWorldMatrix(this->unk4, (s32) M2C_FIELD(this->unk5E0->unk20, s16 *, 0x70), &sp20);
        temp_r3_78 = this->unk5E4;
        sp10 = (f64) sp20.unk30;
        temp_r3_78->unk10 = (f64) sp20.unk30;
        temp_r3_78->unk18 = (f64) sp20.unk38;
        temp_r3_82 = temp_r3_78->unk3C;
        sp18 = (f64) sp20.unk38;
        if (temp_r3_82 != NULL) {
            M2C_FIELD(temp_r3_82, f64 *, 0x10) = (f64) sp20.unk30;
            M2C_FIELD(temp_r3_82, f64 *, 0x18) = (f64) sp20.unk38;
        }
    }
}

#if 0 // DRAFT: undefined identifier 'spC'
void CynderEnergyCrystal::UpdateMovement() {
    f32 sp8;
    f32 var_f0_118;

    if (((Matrix *) this->unkC8 == NULL) && ((u8) this->unk5E8 == 0)) {
        this->unk15C -= 980.0f * gUpdateTimeDelta * gUpdateTimeDelta;
        var_f0_118 = this->unk15C;
        if (var_f0_118 > -1500.0f) {

        } else {
            var_f0_118 = -1500.0f;
        }
        this->unk15C = var_f0_118;
        M2C_FIELD(this->unk168, M2C_UNK (**)(void **, u8 *, M2C_UNK, f32), 0x10)(&this->unk168, &this->unk158, 0, 0.0f);
        M2C_FIELD(this->unk168, M2C_UNK (**)(f32 *, void **), 0x4C)(&sp8, &this->unk168);
        this->unkD0.unk30 = sp8;
        this->unkD0.unk34 = spC;
        this->unkD0.unk38 = sp10;
        this->unkD0.unk3C = 1.0f;
        this->unk5E8 = this->unk2D4 > 0;
        if ((u8) this->unk5E8 != 0) {
            KDSound_Play3d(GS_EnergyCrystalBounce, (MKVector3 *) &this->unkD0.unk30, 0U, -1, 0.0f, 0U);
            M2C_FIELD(this, f32 *, 0x158) = 0.0f;
            this->unk15C = 0.0f;
            this->unk160 = 0.0f;
            this->unkD0.SetRotationToNone();
            this->unk5E0->Reset();
            this->unk5E0->unk30 = 0;
        }
    }
}
#endif

void CynderEnergyCrystal::Message(MKMessage *arg0) {
    GameProp::Message(arg0);
}

void CynderEnergyCrystal::Update() {
    GameProp::Update();
    UpdateMovement();
    UpdateModel();
}

void CynderEnergyCrystal::Resolve() {
    KDPropEx::Resolve();
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void CynderEnergyCrystal::LoadDone() {
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 spC;
    CynderEnergyCrystal *sp8;
    ManagedLight *temp_r4_311;
    s32 temp_r3_256;

    GameProp::LoadDone();
    this->unk150 = (s32) Tools_GetMatchingNodeIndex(this->unk4, "handle");
    this->unk5E0 = MKDynamicBone_GetDynamicBone(this->unk4, ((Animation *) (MKModel_GetAnimation(this->unk4)))->GetNodeIndex("d_wobble"));
    temp_r3_256 = checked_cast<CynderEnergyCrystalDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = this;
    spC = 0;
    M2C_FIELD(this->unk168, M2C_UNK (**)(void **, s32, MKVector3 *, M2C_UNK, MKCollisionInfo *, M2C_UNK, M2C_UNK, M2C_UNK), 8)(&this->unk168, temp_r3_256 + 0xE4, &MKVector3::zero, 1, &this->unk70, 0, 0, 0);
    sp28 = 0.0f;
    sp38 = 0.0f;
    sp10 = 1.0f;
    sp14 = 0.1f;
    sp18 = 0.75f;
    sp1C = 1.0f;
    sp20 = 0.0f;
    sp24 = 0.0f;
    sp30 = 0.0f;
    sp34 = 0.0f;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    sp68 = (f64) sp38;
    this->unk5E4 = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp60), *((MKVector3 *) &sp50), *((MKVector4 *) &sp40), 700.0f, lit_598, lit_599);
    temp_r4_311 = this->unk5E4;
    if (temp_r4_311 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_311, 1U);
    }
}
#endif

s32 CynderEnergyCrystal::LoadLine(MKIniLine *arg0) {
    GameProp::LoadLine(arg0);
}

void CynderEnergyCrystal::Deinit() {
    GameProp::Deinit();
    M2C_FIELD(this->unk168, M2C_UNK (**)(void **), 0xC)(&this->unk168);
}

void CynderEnergyCrystal::Init() {
    GameProp::Init();
    this->unkC8 = NULL;
    this->unkD0.SetIdentity();
    this->unk110.SetIdentity();
    this->unk150 = 0xFFFF;
    this->unk5E8 = 0;
    M2C_FIELD(this, f32 *, 0x158) = 0.0f;
    this->unk15C = 0.0f;
    this->unk160 = 0.0f;
}

#if 0 // DRAFT: undefined identifier 'unkE4'
void CynderEnergyCrystalDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unkE4.Init();
    this->unkE4.unk18 = 0x0C000000;
    this->unkE4.unk0 = 100.0f;
    this->unkE4.unk4 = -50.0f;
}
#endif
