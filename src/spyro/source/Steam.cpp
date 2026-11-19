#include "spyro/source/Steam.h"
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
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

f64 fmod(s32, f32, f32, f32);                       /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
static MKParticleSystem::Envelope gSteamEnv[5] = {
    { 0.0f, 0.5f, 1.0f, 0.0f, 0.0f },
    { 0.25f, 0.375f, 2.0f, 0.0f, 0.0f },
    { 0.5f, 0.25f, 4.0f, 0.0f, 0.0f },
    { 0.75f, 0.125f, 7.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 12.0f, 0.0f, 0.0f },
};

#if 0 // DRAFT: undefined identifier 'unksp8'
void Steam::UpdateParticles() {
    f64 sp58;
    f64 sp50;
    MKVector3 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    MKParticleChunk *var_r30_66;
    MKParticleSystem::Envelope *temp_r3_164;
    MKParticleSystem::Envelope *temp_r5_169;
    MKParticleSystem::Envelope *temp_r5_203;
    f32 temp_f29_73;
    f32 temp_f2_214;
    f32 temp_f31_90;
    f32 temp_f3_142;
    f32 temp_f4_213;
    f32 temp_f5_171;
    f32 temp_f6_166;
    f32 temp_f6_178;
    f32 var_f0_182;
    f64 temp_f0_114;
    f64 temp_f0_94;
    s32 temp_r0_165;
    s32 temp_r3_138;
    s32 temp_r3_152;
    s32 temp_r4_163;
    void *temp_r29_69;

    this->unk128 += gUpdateTimeDelta;
    var_r30_66 = GetFirstParticle(&unksp8);
loop_12:
    if (var_r30_66 != NULL) {
        temp_r29_69 = var_r30_66->unk2C;
        temp_f29_73 = this->unk128 - M2C_FIELD(temp_r29_69, f32 *, 0x10);
        if (temp_f29_73 > this->unk12C) {
            var_r30_66 = DestroyParticle(&unksp8);
        } else {
            M2C_FIELD(temp_r29_69, f32 *, 4) = (f32) ((500.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r29_69, f32 *, 4));
            temp_f31_90 = gUpdateTimeDelta;
            sp40.operator*(1.5f);
            temp_f0_94 = sp40 * (f64) temp_f31_90;
            sp20 = temp_f0_94;
            sp50 = temp_f0_94;
            sp28 = sp40.unk8 * temp_f31_90;
            sp58 = (f64) sp28;
            M2C_FIELD(temp_r29_69, f64 *, 0) = (f64) (M2C_FIELD(temp_r29_69, f64 *, 0) - temp_f0_94);
            M2C_FIELD(temp_r29_69, f32 *, 8) = (f32) (M2C_FIELD(temp_r29_69, f32 *, 8) - (f32) sp58);
            temp_f0_114 = M2C_FIELD(temp_r29_69, f64 *, 0) * (f64) gUpdateTimeDelta;
            sp10 = temp_f0_114;
            sp30 = temp_f0_114;
            sp18 = M2C_FIELD(temp_r29_69, f32 *, 8) * gUpdateTimeDelta;
            sp38 = (f64) sp18;
            M2C_FIELD(var_r30_66, f64 *, 0) = (f64) (M2C_FIELD(var_r30_66, f64 *, 0) + temp_f0_114);
            var_r30_66->unk8 += (f32) sp38;
            var_r30_66->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29_69, f32 *, 0x18);
            temp_r3_138 = M2C_FIELD(checked_cast<SteamDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x80);
            temp_f3_142 = var_r30_66->unk20;
            var_r30_66->unk20 = (f32) fmod(temp_r3_138, temp_f3_142 + this->unkF0, (f32) temp_r3_138, temp_f3_142);
            temp_r3_152 = M2C_FIELD(temp_r29_69, s32 *, 0x14);
            if (temp_f29_73 > (this->unk12C * this->unk134[temp_r3_152].unk0)) {
                M2C_FIELD(temp_r29_69, s32 *, 0x14) = (s32) (temp_r3_152 + 1);
            }
            temp_r4_163 = M2C_FIELD(temp_r29_69, s32 *, 0x14);
            temp_r3_164 = this->unk134;
            temp_r0_165 = temp_r4_163 - 1;
            temp_f6_166 = this->unk12C;
            temp_r5_169 = &temp_r3_164[temp_r0_165];
            temp_f5_171 = temp_r5_169->unk0;
            temp_f6_178 = -((temp_f6_166 * temp_f5_171) - temp_f29_73) / (temp_f6_166 * (temp_r3_164[temp_r4_163].unk0 - temp_f5_171));
            var_r30_66->unk1C = M2C_FIELD(temp_r29_69, f32 *, 0x20) * ((temp_f6_178 * temp_r5_169->unkC) + temp_r5_169->unk4);
            var_f0_182 = var_r30_66->unk1C;
            if (var_f0_182 < 1.0f) {

            } else {
                var_f0_182 = 1.0f;
            }
            if (var_f0_182 > 0.0f) {

            } else {
                var_f0_182 = 0.0f;
            }
            var_r30_66->unk1C = var_f0_182;
            temp_r5_203 = &this->unk134[temp_r0_165];
            var_r30_66->unk28 = M2C_FIELD(temp_r29_69, f32 *, 0x1C) * ((temp_f6_178 * temp_r5_203->unk10) + temp_r5_203->unk8);
            temp_f4_213 = temp_f29_73 / this->unk12C;
            temp_f2_214 = (0.35f * temp_f4_213) + 0.75f;
            var_r30_66->unk10 = temp_f2_214;
            var_r30_66->unk14 = temp_f2_214;
            var_r30_66->unk18 = (0.9f * temp_f4_213) + 0.1f;
            var_r30_66 = GetNextParticle(&unksp8);
        }
        goto loop_12;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to 'float'
void Steam::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r30_253;
    void *temp_r3_250;

    temp_r3_250 = CreateParticle();
    if (temp_r3_250 != NULL) {
        temp_r30_253 = M2C_FIELD(temp_r3_250, void **, 0x2C);
        M2C_FIELD(temp_r3_250, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_250, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_250, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r30_253, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r30_253, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r30_253, f32 *, 0x1C) = (f32) &arg2;
        M2C_FIELD(temp_r30_253, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r3_250, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r30_253, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, -0.3f, 0.3f);
    }
}
#endif

void Steam::Deinit() {
    MKParticleSystem::Deinit();
}

s32 Steam::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

void Steam::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 10.5f;
    this->unkAC = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(gSteamEnv, 5);
    SetMaxParticleAge(1.0f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}

void SteamDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
    this->unk80 = 1;
    this->unk84 = 1.0f / (f32) this->unk80;
}
