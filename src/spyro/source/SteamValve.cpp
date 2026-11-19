#include "spyro/source/SteamValve.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Steam.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_SpyroSteamBurn1;
extern s32 GS_Steam1;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: ')' expected
void SteamValve::Message(MKMessage *arg0) {
    s32 temp_r0_46;

    GameProp::Message(arg0);
    temp_r0_46 = arg0->unk0;
    switch (temp_r0_46) {                           /* irregular */
    case 0xB5:
        this->unkDC = 1;
        this->unkD8 = this->unkD4;
        this->unkDD = 1;
        return;
    case 0xB4:
        this->unkDC = 0;
        this->unkD8 = this->unkD0;
        this->unkDD = 0;
        return;
    case 0x16:
        M2C_FIELD(checked_cast<HitHeroSndMsg *, MKMessage>(arg0), s32 *, 8) = (s32) GS_SpyroSteamBurn1;
        return;
    }
}
#endif

#if 0 // DRAFT: illegal type
void SteamValve::Update() {
    u8 sp280;
    s32 sp27C;
    void *sp278;
    s32 sp274;
    f32 sp270;
    s32 sp26C;
    s8 sp26B;
    s8 sp26A;
    s16 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp25C;
    f32 sp258;
    f32 sp254;
    f32 sp250;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    f32 sp238;
    f32 sp234;
    f32 sp230;
    s8 sp229;
    s8 sp228;
    s32 sp224;
    f32 sp220;
    s32 sp21C;
    s8 sp21A;
    s8 sp219;
    s8 sp218;
    f64 sp210;                                      /* compiler-managed */
    f64 sp208;                                      /* compiler-managed */
    SteamValve *sp204;
    s32 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    s32 sp1DC;
    s32 sp1D8;
    MKVector3 sp1C8;
    MKVector3 sp1B8;
    MKVector3 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
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
    f32 spE0;
    f32 spD0;
    f32 spC0;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp90;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f64 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_173;
    f32 temp_f1_203;
    f32 temp_f2_262;
    f32 temp_f3_431;
    f32 temp_f4_261;
    f32 temp_f5_259;
    f32 var_f28_175;
    s32 var_r30_136;
    void *temp_r3_256;
    void *var_r30_345;

    GameProp::Update();
    this->unkD8 -= gUpdateTimeDelta;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if ((this->unkD8 == 0.0f) && ((u8) this->unkDD != 0)) {
        if ((u8) this->unkDC != 0) {
            this->unkD8 = this->unkD4;
        } else {
            this->unkD8 = this->unkD0;
            KDSound_Play3d(GS_Steam1, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<SteamValveDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4), &sp1C8);
            var_r30_136 = 0;
            do {
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                sp198 = spD8;
                spE0 = M2C_FIELD((this->unk8 + 0x20), f32 *, 8) * -1000.0f;
                sp1A0 = (f64) spE0;
                sp10 = MKRand_Float(&gViewSeed, 3.0f, 7.0f);
                this->unkC8->Emit(sp1C8, *((MKVector3 *) &sp198), sp10);
                var_r30_136 += 1;
            } while (var_r30_136 < 3);
        }
        this->unkDC = this->unkDC == 0;
    }
    if ((u8) this->unkDC != 0) {
        temp_f1_173 = this->unkD0;
        var_f28_175 = 1.0f;
        if (temp_f1_173 > 0.0f) {
            var_f28_175 = (0.75f * (this->unkD8 / temp_f1_173)) + 0.25f;
        }
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<SteamValveDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4), &sp1B8);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_f1_203 = M2C_FIELD((this->unk8 + 0x20), f32 *, 8) * MKRand_Float(&gViewSeed, -1500.0f, -1000.0f);
        sp178 = spC8;
        spD0 = temp_f1_203;
        sp180 = (f64) spD0;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        sp188 = spB8;
        spC0 = (f32) sp180 * var_f28_175;
        sp190 = (f64) spC0;
        spC = var_f28_175 * MKRand_Float(&gViewSeed, 3.0f, 4.75f);
        this->unkC8->Emit(sp1B8, *((MKVector3 *) &sp188), spC);
        sp230 = 0.0f;
        sp234 = 0.0f;
        sp238 = 0.0f;
        sp240 = 0.0f;
        sp244 = 0.0f;
        sp248 = 0.0f;
        sp250 = 0.0f;
        sp254 = 0.0f;
        sp258 = 0.0f;
        sp25C = 1.0f;
        sp260 = 0.0f;
        sp264 = 0.0f;
        sp268 = 0;
        sp26A = 0;
        sp26B = 0;
        sp26C = 0;
        sp270 = 3.4028235e38f;
        sp274 = 0;
        sp278 = NULL;
        sp27C = -1;
        sp280 = 0;
        temp_r3_256 = this->unk8;
        temp_f5_259 = -M2C_FIELD(temp_r3_256, f32 *, 0x20);
        temp_f4_261 = -M2C_FIELD(temp_r3_256, f32 *, 0x24);
        temp_f2_262 = -M2C_FIELD(temp_r3_256, f32 *, 0x28);
        spA8 = temp_f5_259;
        spAC = temp_f4_261;
        spB0 = temp_f2_262;
        sp148 = (f64) spA8;
        sp150 = (f64) spB0;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp158 = sp98;
        spA0 = (f32) sp150 * 75.0f;
        sp160 = (f64) spA0;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f6, $f0 */);
        sp80 = temp_f2_262;
        sp78 = temp_f5_259;
        sp7C = temp_f4_261;
        sp90 = sp1B8.unk8 + (f32) sp160;
        sp108 = (f64) sp78;
        sp168 = sp88;
        sp170 = (f64) sp90;
        sp110 = (f64) sp80;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp118 = sp68;
        sp70 = (f32) sp110 * 500.0f;
        sp120 = (f64) sp70;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        sp128 = sp58;
        sp60 = (f32) sp120 * var_f28_175;
        sp130 = (f64) sp60;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f6, $f0 */);
        sp138 = sp48;
        sp50 = sp1B8.unk8 + (f32) sp130;
        sp140 = (f64) sp50;
        if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp168), *((MKVector3 *) &sp138), 20.0f, (MKCollisionResult *) &sp230, (MKCollisionMode) 7, 0) != 0) {
            if ((sp280 != 0) && (sp278 != NULL) && (var_r30_345 = M2C_FIELD(sp278, void **, 8), ((var_r30_345 == NULL) == 0))) {

            } else {
                var_r30_345 = NULL;
            }
            if (var_r30_345 != NULL) {
                sp20 = 0.0f;
                sp18 = 0.0f;
                sp1C = 0.0f;
                sp1DC = 0;
                spF8 = (f64) sp18;
                sp100 = (f64) sp20;
                sp1D8 = 7;
                sp200 = 1;
                sp204 = this;
                sp1E0 = (f64) sp18;
                sp1E8 = (f64) sp20;
                sp218 = 1;
                sp224 = 2;
                sp220 = 10.0f;
                sp219 = 0;
                sp21A = 1;
                sp21C = -1;
                sp1F0 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                sp1F8 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                sp228 = 0;
                if (this != NULL) {
                    sp38.GetPos();
                    sp208 = sp38;
                    sp210 = sp40;
                } else {
                    sp208 = 0.0f;
                    unksp20C = 0.0f;
                    sp210 = 0.0f;
                }
                sp229 = 0;
                M2C_FIELD(M2C_FIELD(var_r30_345, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(var_r30_345, &sp1D8);
            }
        }
    } else {
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<SteamValveDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4), &sp1A8);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        temp_f3_431 = M2C_FIELD((this->unk8 + 0x20), f32 *, 8) * MKRand_Float(&gViewSeed, -300.0f, -100.0f);
        spE8 = sp28;
        sp30 = temp_f3_431;
        spF0 = (f64) sp30;
        sp8 = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
        this->unkC8->Emit(sp1A8, *((MKVector3 *) &spE8), sp8);
    }
}
#endif

#if 0 // DRAFT: function call 'checked_cast(void *)' does not match
void SteamValve::LoadDone() {
    GameProp::LoadDone();
    this->unkC8 = checked_cast<Steam *, MKProp>(gMK->CreateProp("Steam"));
    if ((u8) this->unkDC == 0) {
        this->unkDD = 0;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 SteamValve::LoadLine(MKIniLine *arg0) {
    s32 var_r31_500;

    var_r31_500 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadFloat("OnTime", &this->unkD0, 0) != 0) || (arg0->LoadFloat("OffTime", &this->unkD4, 0) != 0) || (arg0->LoadFloat("StartDelay", &this->unkD8, 0) != 0) || (arg0->LoadBool("StartOn", &this->unkDC, 0) != 0)) {
        var_r31_500 = 1;
    }
    return var_r31_500;
}
#endif

void SteamValve::Deinit() {
    GameProp::Deinit();
}

void SteamValve::Init() {
    GameProp::Init();
    this->unkCC = 1;
    this->unkD0 = 1.0f;
    this->unkD4 = 2.0f;
    this->unkD8 = 0.0f;
    this->unkDC = 0;
    this->unkDD = 1;
}

void SteamValveDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    this->unkE4 = MKModel_GetRefPointIndex(this->unk2C, "r_fxemit0");
}
