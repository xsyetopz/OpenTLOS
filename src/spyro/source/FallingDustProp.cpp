#include "spyro/source/FallingDustProp.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/Game.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDProp.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

void FallingDustProp::Trigger() {
    this->unkA4 = 1;
    this->unkA0 = 0.0f;
    this->unkAC = 0.5f;
    this->unkB0.unkC = 1.0f;
}

void FallingDustProp::Deinit() {
    KDProp::Deinit();
}

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void FallingDustProp::Draw() {
    Matrix sp10;
    M2C_UNK spC;

    M2C_STRUCT_COPY((s32) &spC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp10.unk30 = 0.0f;
    sp10.unk34 = this->unkA0;
    sp10.unk38 = 0.0f;
    sp10.unk3C = 1.0f;
    MKMaterial_SetTextureMatrix(this->unkA8, &sp10);
    MKMaterial_SetColor(this->unkA8, this->unkB0);
    KDProp::Draw();
}
#endif

void FallingDustProp::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0xB5) {

    } else {
        Trigger();
    }
    KDProp::Message(arg0);
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HeroInterface'
void FallingDustProp::Update() {
    s8 sp3A0;
    s32 sp39C;
    s32 sp398;
    s32 sp394;
    f32 sp390;
    s32 sp38C;
    s8 sp38B;
    s8 sp38A;
    s16 sp388;
    f32 sp384;
    f32 sp380;
    f32 sp37C;
    f32 sp378;
    f32 sp374;
    f32 sp370;
    f32 sp368;
    f32 sp364;
    f32 sp360;
    f32 sp358;
    f32 sp354;
    f32 sp350;
    MKVector3 sp340;
    MKVector3 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f32 sp308;
    f32 sp304;
    f32 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f32 sp2EC;
    f32 sp2E8;                                      /* compiler-managed */
    f32 sp2E4;
    f32 sp2E0;                                      /* compiler-managed */
    f64 sp2D8;
    f64 sp2D0;
    MKVector3 sp2C0;
    MKVector3 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    MKVector3 sp220;
    f64 sp218;
    f64 sp210;
    MKVector3 sp200;
    MKVector3 sp1F0;
    M2C_UNK sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    MKVector3 sp1C0;
    MKVector3 sp1B0;
    M2C_UNK sp1A0;
    f64 sp198;
    f64 sp190;
    MKVector3 sp180;
    f64 sp178;
    f64 sp170;
    MKVector3 sp160;
    MKVector3 sp150;
    M2C_UNK sp140;
    f64 sp138;
    f64 sp130;
    MKVector3 sp120;
    f64 sp118;
    f64 sp110;
    MKVector3 sp100;
    MKVector3 spF0;
    M2C_UNK spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f2_495;
    f32 temp_f2_499;
    f32 temp_f4_280;
    f32 var_f3_488;
    f64 temp_f0_295;
    f64 temp_f0_518;
    f64 temp_f5_274;
    s32 temp_r0_192;
    s32 var_r25_322;
    s32 var_r25_520;
    s32 var_r3_180;
    u8 var_r4_169;
    void *temp_r27_586;
    void *temp_r31_161;
    void *temp_r3_167;
    void *temp_r3_272;
    void *temp_r3_571;
    void *temp_r3_583;

    KDProp::Update();
    temp_r31_161 = checked_cast<FallingDustPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r3_167 = gb.unk0->GetInput(&gb);
    var_r4_169 = 0;
    if (((u8) M2C_FIELD(temp_r3_167, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_167, u8 *, 4) != 0)) {
        var_r4_169 = 1;
    }
    if (var_r4_169 != 0) {
        var_r3_180 = 0;
    } else {
        var_r3_180 = MKInput_Pressed(0xA, (MKInputDevices) M2C_FIELD(temp_r3_167, s32 *, 0));
    }
    if ((u8) var_r3_180 != 0) {
        Trigger();
    }
    temp_r0_192 = this->unkA4;
    if (temp_r0_192 != 1) {
        if ((temp_r0_192 < 1) && (temp_r0_192 < 0)) {

        }
    } else {
        this->unkAC -= gUpdateTimeDelta;
        if (this->unkAC > 0.0f) {
            sp2E0 = 0.5f;
            sp2E4 = 0.5f;
            sp2E8 = 0.5f;
            sp2EC = 1.0f;
            sp300 = 0.0f;
            sp304 = 0.0f;
            sp308 = 0.0f;
            MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk90, &sp340);
            MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk94, &sp330);
            spD0 = M2C_BITWISE(f64, sp330) - M2C_BITWISE(f64, sp340);
            spD8 = sp330.unk8 - sp340.unk8;
            spA8 = 0.0f;
            spA0 = 0.0f;
            spA4 = -100.0f;
            sp2D0 = spD0;
            sp2D8 = (f64) spD8;
            sp350 = 0.0f;
            sp354 = 0.0f;
            sp358 = 0.0f;
            sp360 = 0.0f;
            sp364 = 0.0f;
            sp368 = 0.0f;
            sp370 = 0.0f;
            sp374 = 0.0f;
            sp378 = 0.0f;
            sp37C = 1.0f;
            sp380 = 0.0f;
            sp384 = 0.0f;
            sp388 = 0;
            sp38A = 0;
            sp38B = 0;
            sp38C = 0;
            sp390 = 3.4028235e38f;
            sp394 = 0;
            sp398 = 0;
            sp39C = -1;
            sp3A0 = 0;
            sp240 = (f64) spA0;
            temp_r3_272 = ((u8 *) this->unk8) + 0x30;
            sp248 = (f64) spA8;
            temp_f5_274 = M2C_FIELD(temp_r3_272, f64 *, 0);
            sp90 = temp_f5_274 + sp240;
            spC8 = 0.0f;
            temp_f4_280 = M2C_FIELD(temp_r3_272, f32 *, 8);
            spC0 = 0.0f;
            spC4 = 100.0f;
            sp98 = temp_f4_280 + (f32) sp248;
            sp260 = (f64) spC0;
            sp250 = sp90;
            sp258 = (f64) sp98;
            sp268 = (f64) spC8;
            temp_f0_295 = temp_f5_274 + sp260;
            spB0 = temp_f0_295;
            sp270 = temp_f0_295;
            spB8 = temp_f4_280 + (f32) sp268;
            sp278 = (f64) spB8;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp270), *((MKVector3 *) &sp250), (MKCollisionResult *) &sp350, (MKCollisionMode) 7, 0) != 0) {
                sp2E0 = (f64) sp370;
                sp2E8 = (f64) sp378;
            }
            var_r25_322 = 0;
            do {
                sp220.operator*(MKRand_Float(&gViewSeed, 0.0f, 1.0f));
                sp70 = M2C_BITWISE(f64, sp340) + M2C_BITWISE(f64, sp220);
                sp230 = sp70;
                sp78 = sp340.unk8 + sp220.unk8;
                sp320 = sp70;
                sp238 = (f64) sp78;
                sp328 = (f64) sp78;
                MKVector(1.0f, 1.0f, 1.0f);
                MKVector(-1.0f, -1.0f, -1.0f);
                KDRand_Vector(sp200, sp1F0);
                sp60 = sp200 * 5.328646264e-315;
                sp210 = sp60;
                sp68 = sp200.unk8 * 3.1415927f;
                sp2F0 = sp60;
                sp218 = (f64) sp68;
                sp2F8 = (f64) sp68;
                MKVector(0.5f, -0.5f, 0.5f);
                MKVector(-0.5f, -1.0f, -0.5f);
                KDRand_Vector(sp1C0, sp1B0);
                sp50 = sp1C0 * 5.676053805e-315;
                sp1D0 = sp50;
                sp58 = sp1C0.unk8 * 1000.0f;
                sp310 = sp50;
                sp1D8 = (f64) sp58;
                sp318 = (f64) sp58;
                ((FlyingChunkPS *) gb.unkA4)->Emit(*((MKVector3 *) &sp320), *((MKVector3 *) &sp310), *((MKVector3 *) &sp300), *((MKVector3 *) &sp2F0), MKRand_Float(&gViewSeed, 0.2f, 0.4f), *((MKVector4 *) &sp2E0), 0, NULL);
                sp180.operator*(MKRand_Float(&gViewSeed, 0.0f, 1.0f));
                sp40 = M2C_BITWISE(f64, sp340) + M2C_BITWISE(f64, sp180);
                sp190 = sp40;
                sp48 = sp340.unk8 + sp180.unk8;
                sp320 = sp40;
                sp198 = (f64) sp48;
                sp328 = (f64) sp48;
                MKVector(0.25f, -0.5f, 0.25f);
                MKVector(-0.25f, -1.0f, -0.25f);
                KDRand_Vector(sp160, sp150);
                sp30 = sp160 * 5.717499035e-315;
                sp170 = sp30;
                sp38 = sp160.unk8 * 2000.0f;
                sp310 = sp30;
                sp178 = (f64) sp38;
                sp318 = (f64) sp38;
                sp8 = MKRand_Float(&gViewSeed, 0.125f, 0.5f);
                gb.EmitSmallRocks(*((MKVector3 *) &sp320), *((MKVector3 *) &sp310), sp8);
                var_r25_322 += 1;
            } while (var_r25_322 < 3);
        }
        this->unkA0 -= gUpdateTimeDelta;
        if (this->unkA0 <= -0.5f) {
            var_f3_488 = 0.5f * (5.0f * gUpdateTimeDelta);
            if (var_f3_488 < 1.0f) {

            } else {
                var_f3_488 = 1.0f;
            }
            temp_f2_495 = this->unkB0.unkC;
            temp_f2_499 = (var_f3_488 * (0.0f - temp_f2_495)) + temp_f2_495;
            this->unkB0.unkC = (var_f3_488 * (0.0f - temp_f2_499)) + temp_f2_499;
            if (this->unkA0 > (-0.5f - gUpdateTimeDelta)) {
                MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk98, &sp2C0);
                MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk9C, &sp2B0);
                temp_f0_518 = M2C_BITWISE(f64, sp2B0) - M2C_BITWISE(f64, sp2C0);
                sp80 = temp_f0_518;
                var_r25_520 = 0;
                sp280 = temp_f0_518;
                sp88 = sp2B0.unk8 - sp2C0.unk8;
                sp288 = (f64) sp88;
                do {
                    sp120.operator*(MKRand_Float(&gViewSeed, 0.0f, 1.0f));
                    sp20 = M2C_BITWISE(f64, sp2C0) + M2C_BITWISE(f64, sp120);
                    sp130 = sp20;
                    sp28 = sp2C0.unk8 + sp120.unk8;
                    sp2A0 = sp20;
                    sp138 = (f64) sp28;
                    sp2A8 = (f64) sp28;
                    MKVector(0.5f, 0.1f, 0.5f);
                    MKVector(-0.5f, 0.1f, -0.5f);
                    KDRand_Vector(sp100, spF0);
                    sp10 = sp100 * 5.676053805e-315;
                    temp_r3_571 = M2C_FIELD(temp_r31_161, void **, 0x70);
                    sp110 = sp10;
                    sp18 = sp100.unk8 * 1000.0f;
                    sp290 = sp10;
                    sp118 = (f64) sp18;
                    sp298 = (f64) sp18;
                    temp_r3_583 = M2C_FIELD(M2C_FIELD(temp_r3_571, void **, 0x44), void *(**)(void *, f64), 0x3C)(temp_r3_571, sp10);
                    if (temp_r3_583 != NULL) {
                        temp_r27_586 = M2C_FIELD(temp_r3_583, void **, 0x2C);
                        M2C_FIELD(temp_r3_583, f64 *, 0) = sp2A0;
                        M2C_FIELD(temp_r3_583, f64 *, 8) = sp2A8;
                        M2C_FIELD(temp_r3_583, f32 *, 0x20) = 0.0f;
                        M2C_FIELD(temp_r3_583, f32 *, 0x28) = 0.0f;
                        M2C_FIELD(temp_r27_586, f64 *, 0) = sp290;
                        M2C_FIELD(temp_r27_586, f64 *, 8) = sp298;
                        M2C_FIELD(temp_r27_586, f32 *, 0x18) = MKRand_Float(&gViewSeed, 3.0f, 3.5f);
                        M2C_FIELD(temp_r27_586, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
                        M2C_FIELD(temp_r27_586, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r31_161, void **, 0x70), f32 *, 0xF4);
                    }
                    var_r25_520 += 1;
                } while (var_r25_520 < 5);
            }
        }
        if (this->unkA0 <= -1.0f) {
            this->unkA4 = 0;
            this->unkB0.unkC = 0.0f;
        }
    }
}
#endif

void FallingDustProp::LoadDone() {
    KDProp::LoadDone();
    this->unkA8 = Tools_GetMatchingMaterial(this->unk4, "fx_0340");
    this->unk90 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "Top1");
    this->unk94 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "Top2");
    this->unk98 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "Bottom1");
    this->unk9C = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "Bottom2");
}

void FallingDustProp::Init() {
    KDProp::Init();
    this->unkA0 = 0.0f;
    this->unkA4 = 0;
    this->unkAC = 0.0f;
    this->unkB0.unk0 = 1.0f;
    this->unkB0.unk4 = 1.0f;
    this->unkB0.unk8 = 1.0f;
    this->unkB0.unkC = 0.0f;
}

#if 0 // DRAFT: illegal implicit conversion from 'KDEnvParticleSystem *' to
void FallingDustPropDescriptor::Init() {
    KDPropDescriptor::Init();
    this->unk70 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("DustPuffPS"));
}
#endif
