#include "spyro/source/CynderEnergyCrystal.h"
#include "common/Source/Animation.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "unplaced_templates.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKModel.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_EnergyCrystalBounce;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;

static s32 lit_598 = 0;
static u8 lit_599 = 0;

#if 0 // DRAFT: undefined identifier 'arg_sp1C'
void CynderEnergyCrystal::UpdateModel() {
    ManagedLight *temp_r3_78;
    Matrix *temp_r5_57;
    void *temp_r3_82;
    M2C_STRUCT_COPY((s32) &arg_sp1C + 4, (s32) &this->unkCC + 4, 0x40);
    temp_r5_57 = this->unkC8;
    if (temp_r5_57 != NULL) {
        arg_sp20.Multiply((Matrix *) &arg_sp20, temp_r5_57);
    }
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp20));
    if ((ManagedLight *) this->unk5E4 != NULL) {
        MKModel_CalculateNodeWorldMatrix(this->unk4, (s32) M2C_FIELD(this->unk5E0->unk20, s16 *, 0x70), (Matrix *) &arg_sp20);
        temp_r3_78 = this->unk5E4;
        arg_sp10 = arg_sp50;
        temp_r3_78->unk10 = arg_sp50;
        temp_r3_78->unk18 = arg_sp58;
        temp_r3_82 = temp_r3_78->unk3C;
        arg_sp18 = arg_sp58;
        if (temp_r3_82 != NULL) {
            M2C_FIELD(temp_r3_82, f64 *, 0x10) = arg_sp50;
            M2C_FIELD(temp_r3_82, f64 *, 0x18) = arg_sp58;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk168'
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
        M2C_FIELD(M2C_FIELD(this, void **, 0x168), M2C_UNK (**)(M2C_UNK *, f32 *, M2C_UNK, f32), 0x10)(&this->unk168, &this->unkD0.unk88, 0, 0.0f);
        M2C_FIELD(M2C_FIELD(this, void **, 0x168), M2C_UNK (**)(f32 *, M2C_UNK *), 0x4C)(&sp8, &this->unk168);
        this->unkD0.unk30 = sp8;
        this->unkD0.unk34 = spC;
        this->unkD0.unk38 = sp10;
        this->unkD0.unk3C = 1.0f;
        this->unk5E8 = this->unk2D4 > 0;
        if ((u8) this->unk5E8 != 0) {
            KDSound_Play3d(GS_EnergyCrystalBounce, (MKVector3 *) &this->unkD0.unk30, 0U, -1, 0.0f, 0U);
            this->unkD0.unk88 = 0.0f;
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

#if 0 // DRAFT: undefined identifier 'unk80'
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
    this->unkD0.unk80 = (s32) Tools_GetMatchingNodeIndex(this->unk4, "handle");
    this->unk5E0 = MKDynamicBone_GetDynamicBone(this->unk4, ((Animation *) (MKModel_GetAnimation(this->unk4)))->GetNodeIndex("d_wobble"));
    temp_r3_256 = checked_cast<CynderEnergyCrystalDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = this;
    spC = 0;
    M2C_FIELD(M2C_FIELD(this, void **, 0x168), M2C_UNK (**)(M2C_UNK *, s32, MKVector3 *, M2C_UNK, MKCollisionInfo *, M2C_UNK, M2C_UNK, M2C_UNK), 8)(&this->unk168, temp_r3_256 + 0xE4, &zero, 1, &this->unk70, 0, 0, 0);
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

#if 0 // DRAFT: undefined identifier 'unk168'
void CynderEnergyCrystal::Deinit() {
    GameProp::Deinit();
    M2C_FIELD(M2C_FIELD(this, void **, 0x168), M2C_UNK (**)(M2C_UNK *), 0xC)(&this->unk168);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk40'
void CynderEnergyCrystal::Init() {
    GameProp::Init();
    this->unkC8 = NULL;
    this->unkD0.SetIdentity();
    this->unkD0.unk40.SetIdentity();
    this->unkD0.unk80 = 0xFFFF;
    this->unk5E8 = 0;
    this->unkD0.unk88 = 0.0f;
    this->unk15C = 0.0f;
    this->unk160 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CynderEnergyCrystalDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unkE4.Init();
    this->unkE4.unk18 = 0x0C000000;
    this->unkE4.unk0 = 100.0f;
    this->unkE4.unk4 = -50.0f;
}
#endif
