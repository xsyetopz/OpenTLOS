#include "spyro/source/SparksPS.h"
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
static MKParticleSystem::Envelope gSparksPSEnv[5] = {
    { 0.0f, 1.0f, 1.0f, 0.0f, 0.0f },
    { 0.25f, 0.75f, 1.0f, 0.0f, 0.0f },
    { 0.5f, 0.5f, 1.0f, 0.0f, 0.0f },
    { 0.75f, 0.25f, 1.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 1.0f, 0.0f, 0.0f },
};

void SparksPS::UpdateParticles() {
    u8 sp8[0x8];
    f32 sp60;
    f32 sp64;
    f32 sp68;
    MKParticleChunk *var_r30_64;
    MKParticleSystem::Envelope *temp_r3_138;
    MKParticleSystem::Envelope *temp_r5_143;
    MKParticleSystem::Envelope *temp_r5_176;
    f32 temp_f30_71;
    f32 temp_f3_116;
    f32 temp_f3_152;
    f32 temp_f5_145;
    f32 temp_f6_140;
    f32 var_f0_156;
    s32 temp_r0_139;
    s32 temp_r3_112;
    s32 temp_r3_126;
    s32 temp_r4_137;
    void *temp_r29_67;
    SparksPSDescriptor *desc;

    this->unk128 += gUpdateTimeDelta;
    var_r30_64 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
loop_12:
    if (var_r30_64 != NULL) {
        temp_r29_67 = var_r30_64->unk2C;
        temp_f30_71 = this->unk128 - M2C_FIELD(temp_r29_67, f32 *, 0x10);
        if (temp_f30_71 > this->unk12C) {
            var_r30_64 = DestroyParticle((MKBaseParticleSystem::ParticleRec *) sp8);
        } else {
            M2C_FIELD(temp_r29_67, f32 *, 4) = (f32) -((1000.0f * gUpdateTimeDelta) - M2C_FIELD(temp_r29_67, f32 *, 4));
            /* Position and z advance: per-lane f32 of velocity * delta, as the paired-single asm does. */
            sp60 = M2C_FIELD(temp_r29_67, f32 *, 0) * gUpdateTimeDelta;
            sp64 = M2C_FIELD(temp_r29_67, f32 *, 4) * gUpdateTimeDelta;
            M2C_FIELD(var_r30_64, f32 *, 0) += sp60;
            M2C_FIELD(var_r30_64, f32 *, 4) += sp64;
            sp68 = M2C_FIELD(temp_r29_67, f32 *, 8) * gUpdateTimeDelta;
            var_r30_64->unk8 += sp68;
            var_r30_64->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29_67, f32 *, 0x18);
            desc = checked_cast<SparksPSDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            temp_r3_112 = M2C_FIELD(desc, s32 *, 0x80);
            temp_f3_116 = var_r30_64->unk20;
            var_r30_64->unk20 = (f32) fmod(temp_r3_112, temp_f3_116 + this->unkF0, (f32) temp_r3_112, temp_f3_116);
            temp_r3_126 = M2C_FIELD(temp_r29_67, s32 *, 0x14);
            if (temp_f30_71 > (this->unk12C * this->unk134[temp_r3_126].unk0)) {
                M2C_FIELD(temp_r29_67, s32 *, 0x14) = (s32) (temp_r3_126 + 1);
            }
            temp_r4_137 = M2C_FIELD(temp_r29_67, s32 *, 0x14);
            temp_r3_138 = this->unk134;
            temp_r0_139 = temp_r4_137 - 1;
            temp_f6_140 = this->unk12C;
            temp_r5_143 = &temp_r3_138[temp_r0_139];
            temp_f5_145 = temp_r5_143->unk0;
            temp_f3_152 = -((temp_f6_140 * temp_f5_145) - temp_f30_71) / (temp_f6_140 * (temp_r3_138[temp_r4_137].unk0 - temp_f5_145));
            var_r30_64->unk1C = M2C_FIELD(temp_r29_67, f32 *, 0x20) * ((temp_f3_152 * temp_r5_143->unkC) + temp_r5_143->unk4);
            var_f0_156 = var_r30_64->unk1C;
            if (var_f0_156 < 1.0f) {

            } else {
                var_f0_156 = 1.0f;
            }
            if (var_f0_156 > 0.0f) {

            } else {
                var_f0_156 = 0.0f;
            }
            var_r30_64->unk1C = var_f0_156;
            temp_r5_176 = &this->unk134[temp_r0_139];
            var_r30_64->unk28 = M2C_FIELD(temp_r29_67, f32 *, 0x1C) * ((temp_f3_152 * temp_r5_176->unk10) + temp_r5_176->unk8);
            var_r30_64 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
        }
        goto loop_12;
    }
}

void SparksPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r30_214;
    void *temp_r3_211;

    temp_r3_211 = CreateParticle();
    if (temp_r3_211 != NULL) {
        temp_r30_214 = M2C_FIELD(temp_r3_211, void **, 0x2C);
        M2C_FIELD(temp_r3_211, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_211, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_211, f32 *, 0x20) = (f32) MKRand_Int((int *) &gViewSeed, 0, 3);
        M2C_FIELD(temp_r30_214, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r30_214, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r30_214, f32 *, 0x1C) = arg2;
        M2C_FIELD(temp_r30_214, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r30_214, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r3_211, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
    }
}

void SparksPS::Deinit() {
    MKParticleSystem::Deinit();
}

s32 SparksPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

void SparksPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 10.5f;
    this->unkAC = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(gSparksPSEnv, 5);
    SetMaxParticleAge(0.5f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}

void SparksPSDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
    this->unk80 = 1;
    this->unk84 = 1.0f / (f32) this->unk80;
}
