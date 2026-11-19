#include "spyro/source/GuardianCageCrystal.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/Guardian.h"
#include "spyro/source/GuardianCage.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_CrystalSmash2;
extern s32 GS_EnergyBeamLP;
extern void **gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'unkC8'
void GuardianCageCrystal::Deinit() {
    ((Targetable *) &this->unkC8)->UnregisterTargetable();
    Shatterable::Deinit();
    KDSound_Stop((int *) &this->unk1D8);
}
#endif

#if 0 // DRAFT: ')' expected
void GuardianCageCrystal::Explode() {
    s32 spC;
    s32 sp8;
    void *temp_r3_95;

    if ((u8) this->unk1D4 == 0) {
        this->unk1D4 = 1;
        ((EnergyBeam *) (M2C_FIELD(checked_cast<GuardianCageCrystalDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0x16C)))->FreeEnergyBeam(this->unk1C8);
        this->unk1C8 = NULL;
        KDSound_Play3d(GS_CrystalSmash2, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
        temp_r3_95 = this->unk1D0;
        spC = 0;
        sp8 = 0x87;
        M2C_FIELD(M2C_FIELD(temp_r3_95, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_95, &sp8, 0);
        KDSound_Stop((int *) &this->unk1D8);
    }
}
#endif

void GuardianCageCrystal::Shatter(bool arg0, MKVector3 *arg1, int arg2, MKVector3 *arg3, bool arg4, bool arg5) {
    Shatterable::Shatter(arg0, arg1, arg2, arg3, arg4, arg5);
    Explode();
}

#if 0 // DRAFT: undefined identifier 'GetTargetableMsg'
void GuardianCageCrystal::Message(MKMessage *arg0) {
    GuardianCageCrystal *var_r0_152;
    void *temp_r3_150;

    ((KDSoundPlayer *) &this->unk1D8)->Message(arg0);
    if ((s32) arg0->unk0 != 0x8E) {
        Shatterable::Message(arg0);
        return;
    }
    temp_r3_150 = checked_cast<GetTargetableMsg *, MKMessage>(arg0);
    var_r0_152 = this;
    if (this != NULL) {
        var_r0_152 = (GuardianCageCrystal *) &this->unkC8;
    }
    M2C_FIELD(temp_r3_150, GuardianCageCrystal **, 8) = var_r0_152;
}
#endif

void GuardianCageCrystal::Draw() {
    Shatterable::Draw();
}

#if 0 // DRAFT: undefined identifier 'spE0'
void *GuardianCageCrystal::Update() {
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    f32 temp_f1_231;
    f32 temp_f29_227;
    f32 temp_f30_378;
    f32 var_f4_232;
    f32 var_f5_247;
    f64 temp_f0_328;
    f64 temp_f0_341;
    f64 temp_f0_365;
    f64 temp_f1_252;
    f64 temp_f1_258;
    f64 temp_f1_262;
    s32 temp_r3_281;
    s32 var_r0_291;
    void *temp_r4_335;

    sp8 = 1;
    ((KDSoundFader *) &this->unk1D8)->Update(GS_EnergyBeamLP, 1U, this->unk1D4 == 0, NULL, &this->unk200, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    Shatterable::Update();
    if ((u8) this->unk1D4 == 0) {
        ((GuardianCage *) &spD8)->GetBeamPosition((s32) this->unk1D0);
        this->unk1B8 = spD8;
        this->unk1C0 = spE0;
        temp_f29_227 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f1_231 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        var_f4_232 = 0.0f;
        sp80 = temp_f29_227;
        sp78 = temp_f1_231;
        sp7C = 0.0f;
        spB0 = (f64) sp80;
        spA8 = (f64) sp78;
        var_f5_247 = ((f32) spB0 * (f32) spB0) + (((f32) spA8 * (f32) spA8) + ((*(f32 *) ((u8 *) &spA8 + 0x4)) * (*(f32 *) ((u8 *) &spA8 + 0x4))));
        if (var_f5_247 > 1e-12f) {
            if (var_f5_247 > 0.0f) {
                temp_f1_252 = __frsqrte(var_f5_247);
                temp_f1_258 = 0.5 * temp_f1_252 * -(((f64) var_f5_247 * (temp_f1_252 * temp_f1_252)) - 3.0);
                temp_f1_262 = 0.5 * temp_f1_258 * -(((f64) var_f5_247 * (temp_f1_258 * temp_f1_258)) - 3.0);
                var_f5_247 = (f32) ((f64) var_f5_247 * (0.5 * temp_f1_262 * -(((f64) var_f5_247 * (temp_f1_262 * temp_f1_262)) - 3.0)));
            } else if (var_f5_247 < M2C_BITWISE(f32, 0.0)) {
                var_f5_247 = __float_nan;
            } else {
                sp10 = var_f5_247;
                temp_r3_281 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_281) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_291 = 1;
                    } else {
                        var_r0_291 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_291 = 5;
                    } else {
                        var_r0_291 = 3;
                    }
                    break;
                default:
                    var_r0_291 = 4;
                    break;
                }
                if (var_r0_291 == 1) {
                    var_f5_247 = __float_nan;
                }
            }
            var_f4_232 = 1.0f / var_f5_247;
        }
        sp4C = (*(f32 *) ((u8 *) &spA8 + 0x4)) * var_f4_232;
        sp48 = (f32) spA8 * var_f4_232;
        sp50 = (f32) spB0 * var_f4_232;
        spB8 = (f64) sp48;
        spC0 = (f64) sp50;
        temp_f0_328 = spB8 * 5.50703498e-315;
        sp68 = temp_f0_328;
        spC8 = temp_f0_328;
        temp_r4_335 = ((u8 *) this->unk8) + 0x30;
        sp70 = (f32) spC0 * 60.000004f;
        spD0 = (f64) sp70;
        temp_f0_341 = M2C_FIELD(temp_r4_335, f64 *, 0) + temp_f0_328;
        sp58 = temp_f0_341;
        spF8 = temp_f0_341;
        sp60 = M2C_FIELD(temp_r4_335, f32 *, 8) + (f32) spD0;
        sp100 = (f64) sp60;
        sp3C = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
        sp38 = 0.0f;
        sp40 = 0.0f;
        sp98 = (f64) sp38;
        spA0 = (f64) sp40;
        temp_f0_365 = sp98 * 5.676053805e-315;
        sp28 = temp_f0_365;
        spE8 = temp_f0_365;
        sp30 = (f32) spA0 * 1000.0f;
        spF0 = (f64) sp30;
        temp_f30_378 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
        sp18 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
        sp1C = 0.5f;
        sp20 = temp_f30_378;
        sp24 = 1.0f;
        sp88 = (f64) sp18;
        sp90 = (f64) sp20;
        sp14 = MKRand_Float((int *) &gViewSeed, 8.0f, 10.0f);
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &spF8), *((MKVector3 *) &spE8), sp14, *((MKVector4 *) &sp88), 0.0f);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[17]' to 'long *'
f32 GuardianCageCrystal::Resolve() {
    f64 sp8;
    void *temp_r31_441;

    this->unk1D0 = (long *) (checked_cast<GuardianCage *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, M2C_UNK *), 0x60)(gMK, "FireGuardianCage")));
    temp_r31_441 = checked_cast<GuardianCageCrystalDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) Tools_GetMatchingRefPointIndex(this->unk4, "beam"), &this->unk1A8);
    ((GuardianCage *) &sp8)->GetBeamPosition((s32) this->unk1D0);
    this->unk1B8 = sp8;
    this->unk1C0 = sp10;
    ((EnergyBeam *) (M2C_FIELD(temp_r31_441, EnergyBeam **, 0x16C)))->SpawnEnergyBeam(&this->unk1A8, (MKVector3 *) &this->unk1B8, 1.0f);
    this->unk1C8 = M2C_ERROR(/* Read from unset register $r3 */);
    ((Targetable *) &this->unkC8)->UnregisterTargetable();
    ((Targetable *) &this->unkC8)->RegisterTargetable();
}
#endif

s32 GuardianCageCrystal::LoadLine(MKIniLine *arg0) {
    s32 var_r31_484;

    var_r31_484 = 0;
    if ((Shatterable::LoadLine(arg0) != 0) || (arg0->LoadInt("CageLockOnPos", (int *) &this->unk1CC, 0) != 0)) {
        var_r31_484 = 1;
    }
    return var_r31_484;
}

#if 0 // DRAFT: undefined identifier 'unkC8'
void GuardianCageCrystal::Reset() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_538;
    void *temp_r3_523;

    ((Targetable *) &this->unkC8)->UnregisterTargetable();
    ((Targetable *) &this->unkC8)->RegisterTargetable();
    temp_r3_523 = checked_cast<GuardianCageCrystalDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((EnergyBeam::Beam *) this->unk1C8 == NULL) {
        ((EnergyBeam *) (M2C_FIELD(temp_r3_523, EnergyBeam **, 0x16C)))->SpawnEnergyBeam(&this->unk1A8, (MKVector3 *) &this->unk1B8, 1.0f);
        this->unk1C8 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    temp_f0_538 = M2C_FIELD(this, f64 *, 0x1A8) + this->unk1B8;
    sp8 = temp_f0_538;
    sp28 = temp_f0_538;
    sp10 = this->unk1A8.unk8 + M2C_FIELD(this, f32 *, 0x1C0);
    sp30 = (f64) sp10;
    sp18 = temp_f0_538 * 5.222099017e-315;
    M2C_FIELD(this, f64 *, 0x200) = sp18;
    sp20 = (f32) sp30 * 0.5f;
    sp38 = sp18;
    M2C_FIELD(this, f64 *, 0x208) = (f64) sp20;
    sp40 = (f64) sp20;
    this->unk1D4 = 0;
    Shatterable::Reset();
}
#endif

void GuardianCageCrystal::Init() {
    Shatterable::Init();
    this->unk1D4 = 0;
    this->unk1CC = 1;
    this->unk1C8 = NULL;
    ((KDSoundFader *) &this->unk1D8)->Init(0.25f, 0.25f);
    this->unk200.unk0 = 0.0f;
    this->unk200.unk4 = 0.0f;
    this->unk200.unk8 = 0.0f;
}

void GuardianCageCrystalDescriptor::Deinit() {
    ShatterableDescriptor::Deinit();
}

#if 0 // DRAFT: undefined identifier 'unk16C'
void GuardianCageCrystalDescriptor::LoadDone() {
    ShatterableDescriptor::LoadDone();
    this->unk16C = checked_cast<EnergyBeam *, MKProp>(((MKSceneManager *) gMK)->CreateProp("EnergyBeam"));
}
#endif

void GuardianCageCrystalDescriptor::Init() {
    ShatterableDescriptor::Init();
}
