#include "spyro/source/IceBreathSnow.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/Matrix.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

f64 fmod(s32, f32, f32, f32);                       /* extern */
extern f32 gUpdateTimeDelta;
static MKParticleSystem::Envelope gIceBreathSnowEnv[5] = {
    { 0.0f, 1.0f, 0.07f, 0.0f, 0.0f },
    { 0.25f, 0.75f, 0.25f, 0.0f, 0.0f },
    { 0.5f, 0.5f, 0.5f, 0.0f, 0.0f },
    { 0.75f, 0.25f, 0.75f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 1.0f, 0.0f, 0.0f },
};

void IceBreathSnow::UpdateParticles() {
    f64 fmod(f64, f64);
    MKBaseParticleSystemDescriptor *desc;
    MKParticleChunk *var_r30_64;
    void *temp_r29_67;
    void *sp8[2];
    MKParticleSystem::Envelope *temp_r5_138;
    MKParticleSystem::Envelope *temp_r5_171;
    f32 temp_f30_71;
    f32 temp_f3_147;
    f32 temp_f5_140;
    f32 temp_f6_135;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 var_f0_151;
    s32 count;
    s32 temp_r3_121;
    s32 temp_r4_132;
    s32 temp_r0_134;

    this->unk128 += gUpdateTimeDelta;
    var_r30_64 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    while (var_r30_64 != NULL) {
        temp_r29_67 = var_r30_64->unk2C;
        temp_f30_71 = this->unk128 - M2C_FIELD(temp_r29_67, f32 *, 0x10);
        if (temp_f30_71 > this->unk12C) {
            var_r30_64 = DestroyParticle((MKBaseParticleSystem::ParticleRec *) sp8);
        } else {
            tx = M2C_FIELD(temp_r29_67, f32 *, 0) * gUpdateTimeDelta;
            ty = M2C_FIELD(temp_r29_67, f32 *, 4) * gUpdateTimeDelta;
            tz = M2C_FIELD(temp_r29_67, f32 *, 8) * gUpdateTimeDelta;
            M2C_FIELD(var_r30_64, f32 *, 0) = M2C_FIELD(var_r30_64, f32 *, 0) + tx;
            var_r30_64->unk4 += ty;
            var_r30_64->unk8 += tz;
            var_r30_64->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29_67, f32 *, 0x18);
            desc = checked_cast<MKBaseParticleSystemDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            count = M2C_FIELD(desc, s32 *, 0x80);
            var_r30_64->unk20 = (f32) fmod((f64) (var_r30_64->unk20 + this->unkF0), (f64) count);
            temp_r3_121 = M2C_FIELD(temp_r29_67, s32 *, 0x14);
            if (temp_f30_71 > (this->unk12C * this->unk134[temp_r3_121].unk0)) {
                M2C_FIELD(temp_r29_67, s32 *, 0x14) = temp_r3_121 + 1;
            }
            temp_r4_132 = M2C_FIELD(temp_r29_67, s32 *, 0x14);
            temp_r0_134 = temp_r4_132 - 1;
            temp_f6_135 = this->unk12C;
            temp_r5_138 = &this->unk134[temp_r0_134];
            temp_f5_140 = temp_r5_138->unk0;
            temp_f3_147 = -((temp_f6_135 * temp_f5_140) - temp_f30_71) / (temp_f6_135 * (this->unk134[temp_r4_132].unk0 - temp_f5_140));
            var_r30_64->unk1C = M2C_FIELD(temp_r29_67, f32 *, 0x20) * ((temp_f3_147 * temp_r5_138->unkC) + temp_r5_138->unk4);
            var_f0_151 = var_r30_64->unk1C;
            if (var_f0_151 < 1.0f) {

            } else {
                var_f0_151 = 1.0f;
            }
            if (var_f0_151 > 0.0f) {

            } else {
                var_f0_151 = 0.0f;
            }
            var_r30_64->unk1C = var_f0_151;
            temp_r5_171 = &this->unk134[temp_r0_134];
            var_r30_64->unk28 = M2C_FIELD(temp_r29_67, f32 *, 0x1C) * ((temp_f3_147 * temp_r5_171->unk10) + temp_r5_171->unk8);
            var_r30_64 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
        }
    }
}

void IceBreathSnow::Deinit() {
    MKParticleSystem::Deinit();
}

s32 IceBreathSnow::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

void IceBreathSnow::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 10.5f;
    this->unkAC = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(gIceBreathSnowEnv, 5);
    SetMaxParticleAge(0.35f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}
