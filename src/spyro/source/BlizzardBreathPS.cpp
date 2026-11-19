#include "spyro/source/BlizzardBreathPS.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/Matrix.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
static MKParticleSystem::Envelope gBlizzardBreathPSEnv[5] = {
    { 0.0f, 1.0f, 0.05f, 0.0f, 0.0f },
    { 0.25f, 1.0f, 0.3f, 0.0f, 0.0f },
    { 0.5f, 1.0f, 0.7f, 0.0f, 0.0f },
    { 0.75f, 0.5f, 1.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 1.5f, 0.0f, 0.0f },
};

void BlizzardBreathPS::UpdateParticles() {
    u8 sp8[0x8];
    MKParticleChunk *var_r7;
    void *temp_r8;
    MKParticleSystem::Envelope *temp_r5;
    MKParticleSystem::Envelope *temp_r5_alt;
    f32 temp_f3;
    f32 temp_f3_134;
    f32 temp_f0;
    f32 sp18;
    s32 temp_r3;
    s32 temp_r4;
    s32 idx;

    this->unk128 += gUpdateTimeDelta;
    var_r7 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    while (var_r7 != NULL) {
        temp_r8 = var_r7->unk2C;
        temp_f3 = this->unk128 - M2C_FIELD(temp_r8, f32 *, 0x10);
        if (temp_f3 > this->unk12C) {
            var_r7 = DestroyParticle((MKBaseParticleSystem::ParticleRec *) sp8);
            continue;
        }
        M2C_FIELD(temp_r8, f32 *, 4) = (f32) -((3000.0f * gUpdateTimeDelta) - M2C_FIELD(temp_r8, f32 *, 4));
        M2C_FIELD(var_r7, f32 *, 0) += M2C_FIELD(temp_r8, f32 *, 0) * gUpdateTimeDelta;
        M2C_FIELD(var_r7, f32 *, 4) += M2C_FIELD(temp_r8, f32 *, 4) * gUpdateTimeDelta;
        sp18 = M2C_FIELD(temp_r8, f32 *, 8) * gUpdateTimeDelta;
        var_r7->unk8 += sp18;
        var_r7->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r8, f32 *, 0x18);
        temp_r3 = M2C_FIELD(temp_r8, s32 *, 0x14);
        if (temp_f3 > (this->unk12C * this->unk134[temp_r3].unk0)) {
            M2C_FIELD(temp_r8, s32 *, 0x14) = temp_r3 + 1;
        }
        temp_r4 = M2C_FIELD(temp_r8, s32 *, 0x14);
        idx = temp_r4 - 1;
        temp_r5 = &this->unk134[idx];
        temp_f3_134 = -((this->unk12C * temp_r5->unk0) - temp_f3) / (this->unk12C * (this->unk134[temp_r4].unk0 - temp_r5->unk0));
        var_r7->unk1C = M2C_FIELD(temp_r8, f32 *, 0x20) * ((temp_f3_134 * temp_r5->unkC) + temp_r5->unk4);
        temp_f0 = var_r7->unk1C;
        if (temp_f0 < 1.0f) {
        } else {
            temp_f0 = 1.0f;
        }
        if (temp_f0 > 0.0f) {
        } else {
            temp_f0 = 0.0f;
        }
        var_r7->unk1C = temp_f0;
        temp_r5_alt = &this->unk134[idx];
        var_r7->unk28 = M2C_FIELD(temp_r8, f32 *, 0x1C) * ((temp_f3_134 * temp_r5_alt->unk10) + temp_r5_alt->unk8);
        var_r7 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    }
}

void BlizzardBreathPS::Deinit() {
    MKParticleSystem::Deinit();
}

s32 BlizzardBreathPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

void BlizzardBreathPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 10.5f;
    this->unkAC = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(gBlizzardBreathPSEnv, 5);
    SetMaxParticleAge(1.0f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}

void BlizzardBreathPSDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
    this->unk80 = 1;
    this->unk84 = 1.0f / (f32) this->unk80;
}
