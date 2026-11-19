#include "spyro/source/Explosion3.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/ExpShock.h"
#include "spyro/source/ExpSmokeAndFlamesPS.h"
#include "spyro/source/ExplosionFX.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_Explosion5;
extern s32 GS_Rumble1Soft;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

static s32 lit_556 = 0;
static u8 lit_557 = 1;

#if 0 // DRAFT: illegal operand
void Explosion3::Trigger(const MKVector3 &arg0, const float &arg1, bool arg2, bool arg3, const MKVector3 &arg4, MKProp *arg5) {
    s32 sp170;
    f32 sp16C;
    s8 sp16A;
    s8 sp169;
    s8 sp168;
    s32 sp164;
    f32 sp160;
    f64 sp158;
    f64 sp150;
    MKProp *sp148;
    s32 sp144;
    s32 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
    MKVector3 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp48;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r3_210;
    ManagedLight *temp_r3_233;
    ManagedLight *temp_r3_265;
    f32 temp_f0_234;
    f32 temp_f1_297;
    f32 temp_f23_117;
    f32 temp_f24_122;
    f32 temp_f29_185;
    f32 temp_f31_99;
    f64 temp_f3_287;
    f64 temp_f4_285;
    s32 temp_r3_320;
    s32 temp_r3_330;
    s32 var_r25_104;
    s32 var_r25_184;
    void *temp_r3_223;
    void *temp_r3_236;
    void *temp_r3_271;

    sp88 = 0.0f;
    sp80 = 0.0f;
    sp84 = 0.0f;
    spC = 5.0f * &arg1;
    sp110 = (f64) sp80;
    sp118 = (f64) sp88;
    this->unk4C->Emit(arg0, *((MKVector3 *) &sp110), spC);
    sp78 = 0.0f;
    sp70 = 0.0f;
    sp74 = 0.0f;
    sp108 = (f64) sp78;
    sp100 = (f64) sp70;
    this->unk50->Emit(arg0, *((MKVector3 *) &sp100), arg1);
    temp_f31_99 = &arg1;
    this->unk64 = temp_f31_99;
    var_r25_104 = 0;
loop_2:
    if (var_r25_104 < (s32) (10.0f * temp_f31_99)) {
        temp_f23_117 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f24_122 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp60 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp64 = temp_f24_122;
        sp68 = temp_f23_117;
        spE0 = (f64) sp60;
        spE8 = (f64) sp68;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        spF0 = sp50;
        sp58 = (f32) spE8 * 2000.0f;
        spF8 = (f64) sp58;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp30 = 1.0f;
        sp34 = 0.8f;
        sp48 = (f32) spF8 * temp_f31_99;
        sp38 = 0.1f;
        sp3C = 1.0f;
        sp130 = sp40;
        sp138 = (f64) sp48;
        spD0 = (f64) sp30;
        spD8 = (f64) sp38;
        sp8 = temp_f31_99 * MKRand_Float(&gViewSeed, 10.0f, 20.0f);
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(arg0, *((MKVector3 *) &sp130), sp8, *((MKVector4 *) &spD0), 0.0f);
        var_r25_104 += 1;
        goto loop_2;
    }
    if (arg2 != 0) {
        var_r25_184 = 0;
        temp_f29_185 = &arg1;
        do {
            this->unk54->CreateTendril(arg0, temp_f29_185 * MKRand_Float(&gViewSeed, 0.5f, 2.0f));
            var_r25_184 += 1;
        } while (var_r25_184 < 5);
    }
    this->unk54->CreateShockwave(arg0, arg4, 0.35f * &arg1);
    this->unk5C = 1;
    this->unk60 = 1.0f;
    temp_r3_210 = this->unk58;
    if (temp_r3_210 != NULL) {
        sp20 = 1.0f;
        sp24 = 0.5f;
        sp28 = 0.0f;
        sp2C = 1.0f;
        temp_r3_210->unk20 = (f64) sp20;
        temp_r3_210->unk28 = (f64) sp28;
        temp_r3_223 = temp_r3_210->unk3C;
        spC0 = (f64) sp20;
        spC8 = (f64) sp28;
        if (temp_r3_223 != NULL) {
            M2C_FIELD(temp_r3_223, f64 *, 0) = (f64) sp20;
            M2C_FIELD(temp_r3_223, f64 *, 8) = (f64) sp28;
        }
        temp_r3_233 = this->unk58;
        temp_f0_234 = 2000.0f * this->unk64;
        temp_r3_233->unk38 = temp_f0_234;
        temp_r3_236 = temp_r3_233->unk3C;
        if (temp_r3_236 != NULL) {
            M2C_FIELD(temp_r3_236, f32 *, 0x20) = temp_f0_234;
            M2C_FIELD(temp_r3_236, f32 *, 0x24) = (f32) (temp_f0_234 * temp_f0_234);
            M2C_FIELD(temp_r3_236, f32 *, 0x28) = (f32) (1.0f / temp_f0_234);
            M2C_FIELD(temp_r3_236, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_236, f32 *, 0x24));
        }
        sp90.operator*(100.0f);
        spA0.operator*(this->unk64);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_r3_265 = this->unk58;
        spB0 = sp10;
        sp18 = arg0.unk8 + spA0.unk8;
        temp_r3_265->unk10 = sp10;
        temp_r3_265->unk18 = (f64) sp18;
        temp_r3_271 = temp_r3_265->unk3C;
        spB8 = (f64) sp18;
        if (temp_r3_271 != NULL) {
            M2C_FIELD(temp_r3_271, f64 *, 0x10) = sp10;
            M2C_FIELD(temp_r3_271, f64 *, 0x18) = (f64) sp18;
        }
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unk58, 1U);
    }
    temp_f4_285 = M2C_FIELD(&arg0, f64 *, 0);
    temp_f3_287 = (f64) M2C_FIELD(&arg0, f32 *, 8);
    sp120 = temp_f4_285;
    sp128 = temp_f3_287;
    if (arg3 != 0) {
        temp_f1_297 = 300.0f * &arg1;
        sp144 = 0;
        sp140 = 1;
        sp148 = arg5;
        sp150 = temp_f4_285;
        sp158 = temp_f3_287;
        sp160 = temp_f1_297;
        sp168 = 0;
        sp169 = 0;
        sp16A = 1;
        sp164 = 0;
        sp16C = 5.0f;
        sp170 = 0;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, M2C_UNK, f32, f32), 0x94)(gMK, &sp140, 0, 0, &sp120, 1, 0, temp_f1_297, 300.0f);
    }
    temp_r3_320 = this->unk68;
    if (temp_r3_320 != 0) {
        KDSound_Play3d(temp_r3_320, (MKVector3 *) &sp120, 0U, -1, 0.0f, 0U);
    }
    temp_r3_330 = this->unk6C;
    if (temp_r3_330 != 0) {
        KDSound_Play3d(temp_r3_330, (MKVector3 *) &sp120, 0U, -1, 0.0f, 0U);
    }
    if ((u8) this->unk70 != 0) {
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.0f, 0.8f * &arg1, 0.1f, (MKVector3 *) &sp120, 50.0f, 0, 4.0f, 0U);
    }
}
#endif

void Explosion3::Deinit() {
    ManagedLight *temp_r4_396;

    MKProp::Deinit();
    temp_r4_396 = this->unk58;
    if (temp_r4_396 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_396, 0U);
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(this->unk58);
        this->unk58 = NULL;
    }
}

#if 0 // DRAFT: undefined identifier 'sp10'
void Explosion3::Update() {
    f64 sp20;
    f64 sp18;
    ManagedLight *temp_r4_440;
    ManagedLight *temp_r4_450;
    ManagedLight *temp_r4_471;
    f32 temp_f0_456;
    f32 temp_f3_434;
    s32 temp_r0_423;
    void *temp_r3_489;
    void *temp_r4_458;

    temp_r0_423 = this->unk5C;
    if (temp_r0_423 != 1) {
        if (temp_r0_423 < 1) {

        }
    } else {
        this->unk60 -= gUpdateTimeDelta;
        temp_f3_434 = this->unk60;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f3_434 == 0.0f) {
            this->unk5C = 0;
            temp_r4_440 = this->unk58;
            if (temp_r4_440 != NULL) {
                ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_440, 0U);
            }
        } else {
            temp_r4_450 = this->unk58;
            if (temp_r4_450 != NULL) {
                temp_f0_456 = temp_f3_434 * (2000.0f * this->unk64);
                temp_r4_450->unk38 = temp_f0_456;
                temp_r4_458 = temp_r4_450->unk3C;
                if (temp_r4_458 != NULL) {
                    M2C_FIELD(temp_r4_458, f32 *, 0x20) = temp_f0_456;
                    M2C_FIELD(temp_r4_458, f32 *, 0x24) = (f32) (temp_f0_456 * temp_f0_456);
                    M2C_FIELD(temp_r4_458, f32 *, 0x28) = (f32) (1.0f / temp_f0_456);
                    M2C_FIELD(temp_r4_458, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r4_458, f32 *, 0x24));
                }
                temp_r4_471 = this->unk58;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
                sp20 = sp10;
                unksp24 = 1.0f;
                temp_r4_471->unk20 = sp8;
                sp18 = sp8;
                temp_r4_471->unk28 = sp20;
                temp_r3_489 = temp_r4_471->unk3C;
                if (temp_r3_489 != NULL) {
                    M2C_FIELD(temp_r3_489, f64 *, 0) = sp8;
                    M2C_FIELD(temp_r3_489, f64 *, 8) = sp20;
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Explosion3::LoadDone() {
    MKProp::LoadDone();
    this->unk68 = M2C_FIELD(checked_cast<Explosion3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60);
    this->unk6C = M2C_FIELD(checked_cast<Explosion3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x64);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void Explosion3::Resolve() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r4_569;

    MKProp::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    this->unk58 = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 1000.0f, lit_556, lit_557);
    temp_r4_569 = this->unk58;
    if (temp_r4_569 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_569, 0U);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void Explosion3::Init() {
    MKProp::Init();
    this->unk4C = checked_cast<ExpSmokeAndFlamesPS *, MKProp>(gMK->CreateProp("ExpSmokeAndFlamesPS"));
    this->unk50 = checked_cast<ExpShock *, MKProp>(gMK->CreateProp("ExpShock"));
    this->unk54 = checked_cast<ExplosionFX *, MKProp>(gMK->CreateProp("ExplosionFX"));
    this->unk68 = 0;
    this->unk6C = 0;
    this->unk70 = 1;
}
#endif

#if 0 // DRAFT: function call 'KDSound_LoadLine(MKIniLine *, const char[11], long *)' does
s32 Explosion3Descriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_633;

    var_r31_633 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "sndExplode", &this->unk60) != 0) || (KDSound_LoadLine(arg0, "sndExplodeRumble", &this->unk64) != 0)) {
        var_r31_633 = 1;
    }
    return var_r31_633;
}
#endif

void Explosion3Descriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = GS_Explosion5;
    this->unk64 = GS_Rumble1Soft;
}
