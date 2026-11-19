#include "spyro/source/GiveColorPS.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDSpline.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern f32 *KDSpline_PositionMixer;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
static MKParticleSystem::Envelope gGiveColorPSEnv[5] = {
    { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f },
    { 0.25f, 1.0f, 1.0f, 0.0f, 0.0f },
    { 0.5f, 0.5f, 0.75f, 0.0f, 0.0f },
    { 0.75f, 1.0f, 0.5f, 0.0f, 0.0f },
    { 1.0f, 1.0f, 0.0f, 0.0f, 0.0f },
};

#if 0 // DRAFT: undefined identifier 'unkspC'
void GiveColorPS::UpdateParticles() {
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    MKVector3 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp8;
    MKParticleChunk *var_r31_71;
    MKParticleSystem::Envelope *temp_r3_238;
    MKParticleSystem::Envelope *temp_r3_272;
    MKParticleSystem::Envelope *temp_r5_242;
    f32 temp_f1_184;
    f32 temp_f1_76;
    f32 temp_f27_178;
    f32 temp_f28_172;
    f32 temp_f29_78;
    f32 temp_f3_251;
    f32 temp_f4_244;
    f32 temp_f5_240;
    f32 var_f0_254;
    f32 var_f0_88;
    f64 temp_f0_115;
    f64 temp_f0_148;
    f64 temp_f0_202;
    s32 temp_r0_239;
    s32 temp_r3_226;
    s32 temp_r4_237;
    void *temp_r30_74;

    this->unk128 += gUpdateTimeDelta;
    var_r31_71 = GetFirstParticle(&unkspC);
loop_25:
    if (var_r31_71 != NULL) {
        temp_r30_74 = var_r31_71->unk2C;
        temp_f1_76 = M2C_FIELD(temp_r30_74, f32 *, 0x20);
        temp_f29_78 = temp_f1_76 * this->unk12C;
        if (temp_f1_76 == 1.0f) {
            var_r31_71 = DestroyParticle(&unkspC);
        } else {
            var_f0_88 = temp_f1_76 + gUpdateTimeDelta;
            if (var_f0_88 < 1.0f) {

            } else {
                var_f0_88 = 1.0f;
            }
            if (var_f0_88 > 0.0f) {

            } else {
                var_f0_88 = 0.0f;
            }
            M2C_FIELD(temp_r30_74, f32 *, 0x20) = var_f0_88;
            if ((u8) this->unk188 == 0) {
                M2C_FIELD(temp_r30_74, u8 *, 0x24) = 0U;
            }
            if ((u8) M2C_FIELD(temp_r30_74, u8 *, 0x24) == 0) {
                temp_f0_115 = M2C_FIELD(temp_r30_74, f64 *, 0) * (f64) gUpdateTimeDelta;
                sp38 = temp_f0_115;
                spA8 = temp_f0_115;
                sp40 = M2C_FIELD(temp_r30_74, f32 *, 8) * gUpdateTimeDelta;
                spB0 = (f64) sp40;
                M2C_FIELD(var_r31_71, f64 *, 0) = (f64) (M2C_FIELD(var_r31_71, f64 *, 0) + temp_f0_115);
                var_r31_71->unk8 += (f32) spB0;
            } else {
                sp8 = 0.0f;
                ((KDUniformSpline *) &sp98)->GetMeasure(M2C_FIELD(temp_r30_74, f32 *, 0x20), (Matrix *) &this->unk140, KDSpline_PositionMixer);
                spC8 = sp98;
                spD0 = spA0;
                temp_f0_148 = spC8 - M2C_FIELD(var_r31_71, f64 *, 0);
                sp28 = temp_f0_148;
                sp88 = temp_f0_148;
                sp30 = (f32) spD0 - var_r31_71->unk8;
                sp90 = (f64) sp30;
                M2C_FIELD(temp_r30_74, f64 *, 0) = (f64) (M2C_FIELD(temp_r30_74, f64 *, 0) + temp_f0_148);
                M2C_FIELD(temp_r30_74, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_74, f32 *, 8) + (f32) sp90);
                M2C_FIELD(var_r31_71, f64 *, 0) = sp98;
                M2C_FIELD(var_r31_71, f32 *, 8) = spA0;
                temp_f28_172 = 1.0f - M2C_FIELD(temp_r30_74, f32 *, 0x20);
                temp_f27_178 = temp_f28_172 * (75.0f * _table_sinf(1.5707964f + var_r31_71->unk24));
                temp_f1_184 = 75.0f * _table_sinf(var_r31_71->unk24);
                sp50 = 0.0f;
                sp48 = 0.0f;
                sp4C = 1.0f;
                spC0 = (f64) sp50;
                spB8 = (f64) sp48;
                sp58.operator*(temp_f28_172 * temp_f1_184);
                sp68.operator*(temp_f27_178);
                temp_f0_202 = sp68 + M2C_BITWISE(f64, sp58);
                sp18 = temp_f0_202;
                sp78 = temp_f0_202;
                sp20 = sp68.unk8 + sp58.unk8;
                sp80 = (f64) sp20;
                M2C_FIELD(var_r31_71, f64 *, 0) = (f64) (M2C_FIELD(var_r31_71, f64 *, 0) + temp_f0_202);
                var_r31_71->unk8 += (f32) sp80;
            }
            var_r31_71->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r30_74, f32 *, 0x18);
            temp_r3_226 = M2C_FIELD(temp_r30_74, s32 *, 0x14);
            if (temp_f29_78 > (this->unk12C * this->unk134[temp_r3_226].unk0)) {
                M2C_FIELD(temp_r30_74, s32 *, 0x14) = (s32) (temp_r3_226 + 1);
            }
            temp_r4_237 = M2C_FIELD(temp_r30_74, s32 *, 0x14);
            temp_r3_238 = this->unk134;
            temp_r0_239 = temp_r4_237 - 1;
            temp_f5_240 = this->unk12C;
            temp_r5_242 = &temp_r3_238[temp_r0_239];
            temp_f4_244 = temp_r5_242->unk0;
            temp_f3_251 = -((temp_f5_240 * temp_f4_244) - temp_f29_78) / (temp_f5_240 * (temp_r3_238[temp_r4_237].unk0 - temp_f4_244));
            var_r31_71->unk1C = (temp_f3_251 * temp_r5_242->unkC) + temp_r5_242->unk4;
            var_f0_254 = var_r31_71->unk1C;
            if (var_f0_254 < 1.0f) {

            } else {
                var_f0_254 = 1.0f;
            }
            if (var_f0_254 > 0.0f) {

            } else {
                var_f0_254 = 0.0f;
            }
            var_r31_71->unk1C = var_f0_254;
            temp_r3_272 = &this->unk134[temp_r0_239];
            var_r31_71->unk28 = M2C_FIELD(temp_r30_74, f32 *, 0x1C) * ((temp_f3_251 * temp_r3_272->unk10) + temp_r3_272->unk8);
            if ((u8) M2C_FIELD(temp_r30_74, u8 *, 0x24) == 0) {
                var_r31_71->unk1C = 1.0f - M2C_FIELD(temp_r30_74, f32 *, 0x20);
            }
            var_r31_71 = GetNextParticle(&unkspC);
        }
        goto loop_25;
    }
    this->unk188 = 0;
}
#endif

void GiveColorPS::Deinit() {
    ((KDUniformSpline *) &this->unk140)->Deinit();
    MKParticleSystem::Deinit();
}

s32 GiveColorPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

void GiveColorPS::Init() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f30_386;
    f32 temp_f30_404;
    f32 temp_f31_381;
    f32 temp_f31_409;

    MKParticleSystem::Init();
    this->unkA8 = 10.5f;
    this->unkAC = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(gGiveColorPSEnv, 5);
    SetMaxParticleAge(10.0f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
    this->unk188 = 0;
    temp_f31_381 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    temp_f30_386 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    sp18 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    sp1C = temp_f30_386;
    sp20 = temp_f31_381;
    this->unk158 = (f64) sp18;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    this->unk160 = (f64) sp20;
    temp_f30_404 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    temp_f31_409 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    sp8 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    spC = temp_f31_409;
    sp10 = temp_f30_404;
    this->unk168 = (f64) sp8;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    this->unk170 = (f64) sp10;
    ((KDUniformSpline *) &this->unk140)->Init(3, 0U);
}
