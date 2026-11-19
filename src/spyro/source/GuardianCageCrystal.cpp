#include "spyro/source/GuardianCageCrystal.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/GuardianCage.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_CrystalSmash2;
extern s32 GS_EnergyBeamLP;
extern void **gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'unkC8'
void GuardianCageCrystal::Deinit() {
    this->unkC8.UnregisterTargetable();
    Shatterable::Deinit();
    KDSound_Stop((s32 *) &this->unk1C8);
}
#endif

#if 0 // DRAFT: ')' expected
void GuardianCageCrystal::Explode() {
    s32 spC;
    s32 sp8;
    void *temp_r3_95;

    if ((u8) M2C_FIELD(this, u8 *, 0x1D4) == 0) {
        M2C_FIELD(this, u8 *, 0x1D4) = 1U;
        ((EnergyBeam *) (M2C_FIELD(checked_cast<GuardianCageCrystalDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0x16C)))->FreeEnergyBeam(M2C_FIELD(this, EnergyBeam::Beam **, 0x1C8));
        M2C_FIELD(this, EnergyBeam::Beam **, 0x1C8) = NULL;
        KDSound_Play3d(GS_CrystalSmash2, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        temp_r3_95 = M2C_FIELD(this, void **, 0x1D0);
        spC = 0;
        sp8 = 0x87;
        M2C_FIELD(M2C_FIELD(temp_r3_95, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_95, &sp8, 0);
        KDSound_Stop((s32 *) &this->unk1C8);
    }
}
#endif

void GuardianCageCrystal::Shatter(bool arg0, MKVector3 *arg1, int arg2, MKVector3 *arg3, bool arg4, bool arg5) {
    Shatterable::Shatter(arg0, arg1, arg2, arg3, arg4, arg5);
    Explode();
}

#if 0 // DRAFT: undefined identifier 'unk1C8'
void GuardianCageCrystal::Message(MKMessage *arg0) {
    GuardianCageCrystal *var_r0_152;
    void *temp_r3_150;

    this->unk1C8.Message(arg0);
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

#if 0 // DRAFT: undefined identifier 'unk1C8'
void GuardianCageCrystal::Update() {
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
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
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
    f64 temp_f1_252;
    f64 temp_f1_258;
    f64 temp_f1_262;
    s32 temp_r3_281;
    s32 var_r0_291;

    sp8 = 1;
    this->unk1C8.Update(GS_EnergyBeamLP, 1U, M2C_FIELD(this, u8 *, 0x1D4) == 0, NULL, &this->unk200, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    Shatterable::Update();
    if ((u8) M2C_FIELD(this, u8 *, 0x1D4) == 0) {
        spD8.GetBeamPosition(M2C_FIELD(this, s32 *, 0x1D0));
        M2C_FIELD(this, f64 *, 0x1B8) = spD8;
        M2C_FIELD(this, f64 *, 0x1C0) = spE0;
        temp_f29_227 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f1_231 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        var_f4_232 = 0.0f;
        sp80 = temp_f29_227;
        sp78 = temp_f1_231;
        sp7C = 0.0f;
        spB0 = (f64) sp80;
        spA8 = (f64) sp78;
        var_f5_247 = ((f32) spB0 * (f32) spB0) + (((f32) spA8 * (f32) spA8) + (unkspAC * unkspAC));
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
        sp4C = unkspAC * var_f4_232;
        sp48 = (f32) spA8 * var_f4_232;
        sp50 = (f32) spB0 * var_f4_232;
        spB8 = (f64) sp48;
        spC0 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        spC8 = sp68;
        sp70 = (f32) spC0 * 60.000004f;
        spD0 = (f64) sp70;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spF8 = sp58;
        sp60 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) spD0;
        sp100 = (f64) sp60;
        sp3C = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        sp38 = 0.0f;
        sp40 = 0.0f;
        sp98 = (f64) sp38;
        spA0 = (f64) sp40;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        spE8 = sp28;
        sp30 = (f32) spA0 * 1000.0f;
        spF0 = (f64) sp30;
        temp_f30_378 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        sp18 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        sp1C = 0.5f;
        sp20 = temp_f30_378;
        sp24 = 1.0f;
        sp88 = (f64) sp18;
        sp90 = (f64) sp20;
        sp14 = MKRand_Float(&gViewSeed, 8.0f, 10.0f);
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &spF8), *((MKVector3 *) &spE8), sp14, *((MKVector4 *) &sp88), 0.0f);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[17]' to
void GuardianCageCrystal::Resolve() {
    f64 sp8;
    void *temp_r31_441;

    M2C_FIELD(this, s32 *, 0x1D0) = checked_cast<GuardianCage *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, M2C_UNK *), 0x60)(gMK, "FireGuardianCage"));
    temp_r31_441 = checked_cast<GuardianCageCrystalDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) Tools_GetMatchingRefPointIndex(this->unk4, "beam"), (MKVector3 *) &this->unk198);
    sp8.GetBeamPosition(M2C_FIELD(this, s32 *, 0x1D0));
    M2C_FIELD(this, f64 *, 0x1B8) = sp8;
    M2C_FIELD(this, f64 *, 0x1C0) = sp10;
    ((EnergyBeam *) (M2C_FIELD(temp_r31_441, EnergyBeam **, 0x16C)))->SpawnEnergyBeam((MKVector3 *) &this->unk198, &this->unk1A8, 1.0f);
    M2C_FIELD(this, s32 *, 0x1C8) = (s32) M2C_ERROR(/* Read from unset register $r3 */);
    this->unkC8.UnregisterTargetable();
    this->unkC8.RegisterTargetable();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'GuardianCageCrystal *' to
s32 GuardianCageCrystal::LoadLine(MKIniLine *arg0) {
    s32 var_r31_484;

    var_r31_484 = 0;
    if ((Shatterable::LoadLine(arg0) != 0) || (arg0->LoadInt("CageLockOnPos", this + 0x1CC, 0) != 0)) {
        var_r31_484 = 1;
    }
    return var_r31_484;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
void GuardianCageCrystal::Reset() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    void *temp_r3_523;

    this->unkC8.UnregisterTargetable();
    this->unkC8.RegisterTargetable();
    temp_r3_523 = checked_cast<GuardianCageCrystalDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((u32) M2C_FIELD(this, u32 *, 0x1C8) == 0U) {
        ((EnergyBeam *) (M2C_FIELD(temp_r3_523, EnergyBeam **, 0x16C)))->SpawnEnergyBeam((MKVector3 *) &this->unk198, &this->unk1A8, 1.0f);
        M2C_FIELD(this, u32 *, 0x1C8) = (u32) M2C_ERROR(/* Read from unset register $r3 */);
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp28 = sp8;
    sp10 = M2C_FIELD(this, f32 *, 0x1B0) + this->unk1A8.unk8;
    sp30 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    M2C_FIELD(this, f64 *, 0x200) = sp18;
    sp20 = (f32) sp30 * 0.5f;
    sp38 = sp18;
    M2C_FIELD(this, f64 *, 0x208) = (f64) sp20;
    sp40 = (f64) sp20;
    M2C_FIELD(this, s8 *, 0x1D4) = 0;
    Shatterable::Reset();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1C8'
void GuardianCageCrystal::Init() {
    Shatterable::Init();
    M2C_FIELD(this, s8 *, 0x1D4) = 0;
    M2C_FIELD(this, s32 *, 0x1CC) = 1;
    M2C_FIELD(this, s32 *, 0x1C8) = 0;
    this->unk1C8.Init(0.25f, 0.25f);
    this->unk200.unk0 = 0.0f;
    this->unk200.unk4 = 0.0f;
    this->unk200.unk8 = 0.0f;
}
#endif

void GuardianCageCrystalDescriptor::Deinit() {
    ShatterableDescriptor::Deinit();
}

#if 0 // DRAFT: expression syntax error
void GuardianCageCrystalDescriptor::LoadDone() {
    ShatterableDescriptor::LoadDone();
    this->unk16C = checked_cast<EnergyBeam *, MKProp>(gMK->CreateProp("EnergyBeam"));
}
#endif

void GuardianCageCrystalDescriptor::Init() {
    ShatterableDescriptor::Init();
}
