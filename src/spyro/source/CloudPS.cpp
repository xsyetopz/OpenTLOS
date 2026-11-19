#include "spyro/source/CloudPS.h"
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
#include <m2c_macros.h>

f64 fmod(s32, f32, f32, f32);                       /* extern */
extern f32 gUpdateTimeDelta;
static MKParticleSystem::Envelope gCloudPSEnv[5] = {
    { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f },
    { 0.25f, 0.5f, 1.0f, 0.0f, 0.0f },
    { 0.5f, 1.0f, 1.0f, 0.0f, 0.0f },
    { 0.75f, 0.5f, 1.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 1.0f, 0.0f, 0.0f },
};

void CloudPS::UpdateParticles() {
    u8 sp8[0x8];
    MKParticleChunk *var_r30;
    void *temp_r29;
    MKParticleSystem::Envelope *temp_r5;
    MKParticleSystem::Envelope *temp_r5_alt;
    f32 temp_f30;
    f32 temp_f3;
    f32 temp_f3_155;
    f32 temp_f0;
    f32 sp18;
    s32 temp_r3;
    s32 temp_r3_129;
    s32 idx;
    s32 temp_r4;
    CloudPSDescriptor *desc;

    this->unk128 += gUpdateTimeDelta;
    var_r30 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    while (var_r30 != NULL) {
        temp_r29 = var_r30->unk2C;
        temp_f30 = this->unk128 - M2C_FIELD(temp_r29, f32 *, 0x10);
        if (temp_f30 > this->unk12C) {
            var_r30 = DestroyParticle((MKBaseParticleSystem::ParticleRec *) sp8);
            continue;
        }
        M2C_FIELD(var_r30, f32 *, 0) += M2C_FIELD(temp_r29, f32 *, 0) * gUpdateTimeDelta;
        M2C_FIELD(var_r30, f32 *, 4) += M2C_FIELD(temp_r29, f32 *, 4) * gUpdateTimeDelta;
        sp18 = M2C_FIELD(temp_r29, f32 *, 8) * gUpdateTimeDelta;
        var_r30->unk8 += sp18;
        var_r30->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29, f32 *, 0x18);
        desc = checked_cast<CloudPSDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r3 = M2C_FIELD(desc, s32 *, 0x80);
        temp_f3 = var_r30->unk20;
        var_r30->unk20 = (f32) fmod(temp_r3, temp_f3 + this->unkF0, (f32) temp_r3, temp_f3);
        temp_r3_129 = M2C_FIELD(temp_r29, s32 *, 0x14);
        if (temp_f30 > (this->unk12C * this->unk134[temp_r3_129].unk0)) {
            M2C_FIELD(temp_r29, s32 *, 0x14) = temp_r3_129 + 1;
        }
        temp_r4 = M2C_FIELD(temp_r29, s32 *, 0x14);
        idx = temp_r4 - 1;
        temp_r5 = &this->unk134[idx];
        temp_f3_155 = -((this->unk12C * temp_r5->unk0) - temp_f30) / (this->unk12C * (this->unk134[temp_r4].unk0 - temp_r5->unk0));
        var_r30->unk1C = M2C_FIELD(temp_r29, f32 *, 0x20) * ((temp_f3_155 * temp_r5->unkC) + temp_r5->unk4);
        temp_f0 = var_r30->unk1C;
        if (temp_f0 < 1.0f) {
        } else {
            temp_f0 = 1.0f;
        }
        if (temp_f0 > 0.0f) {
        } else {
            temp_f0 = 0.0f;
        }
        var_r30->unk1C = temp_f0;
        temp_r5_alt = &this->unk134[idx];
        var_r30->unk28 = M2C_FIELD(temp_r29, f32 *, 0x1C) * ((temp_f3_155 * temp_r5_alt->unk10) + temp_r5_alt->unk8);
        var_r30 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    }
}

void CloudPS::Deinit() {
    MKParticleSystem::Deinit();
}

s32 CloudPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

void CloudPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 10.5f;
    this->unkAC = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(gCloudPSEnv, 5);
    SetMaxParticleAge(5.0f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}

void CloudPSDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
    this->unk80 = 1;
    this->unk84 = 1.0f / (f32) this->unk80;
}
