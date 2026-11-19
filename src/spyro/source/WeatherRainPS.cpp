#include "spyro/source/WeatherRainPS.h"
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
static MKParticleSystem::Envelope gWeatherRainPSEnv[5] = {
    { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f },
    { 0.25f, 1.0f, 1.0f, 0.0f, 0.0f },
    { 0.5f, 1.0f, 1.0f, 0.0f, 0.0f },
    { 0.75f, 0.75f, 1.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 1.0f, 0.0f, 0.0f },
};

void WeatherRainPS::UpdateParticles() {
    u8 sp8[0x8];
    MKParticleChunk *var_r31;
    void *temp_r30;
    MKBaseParticleSystemDescriptor *desc;
    MKParticleSystem::Envelope *temp_r5;
    f32 age;
    f32 vel_x;
    f32 vel_y;
    f32 vel_z;
    f32 wind_x;
    f32 wind_y;
    f32 wind_z;
    f32 temp_f0;
    f32 temp_f3;
    f32 temp_f3_224;
    s32 temp_r3;
    s32 temp_r3_199;
    s32 temp_r4;
    s32 idx;

    this->unk128 += gUpdateTimeDelta;
    var_r31 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    while (var_r31 != NULL) {
        temp_r30 = var_r31->unk2C;
        age = this->unk128 - M2C_FIELD(temp_r30, f32 *, 0x10);
        if (age > this->unk12C) {
            var_r31 = DestroyParticle((MKBaseParticleSystem::ParticleRec *) sp8);
            continue;
        }

        /* position += velocity * dt */
        vel_x = M2C_FIELD(temp_r30, f32 *, 0) * gUpdateTimeDelta;
        vel_y = M2C_FIELD(temp_r30, f32 *, 4) * gUpdateTimeDelta;
        vel_z = M2C_FIELD(temp_r30, f32 *, 8) * gUpdateTimeDelta;
        M2C_FIELD(var_r31, f32 *, 0) += vel_x;
        M2C_FIELD(var_r31, f32 *, 4) += vel_y;
        var_r31->unk8 += vel_z;

        /* velocity += wind * dt */
        wind_x = this->unk108 * gUpdateTimeDelta;
        wind_y = this->unk10C * gUpdateTimeDelta;
        wind_z = this->unk110 * gUpdateTimeDelta;
        M2C_FIELD(temp_r30, f32 *, 0) += wind_x;
        M2C_FIELD(temp_r30, f32 *, 4) += wind_y;
        M2C_FIELD(temp_r30, f32 *, 8) += wind_z;

        var_r31->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r30, f32 *, 0x1C);

        desc = checked_cast<MKBaseParticleSystemDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r3 = desc->unk80;
        temp_f3 = var_r31->unk20;
        var_r31->unk20 = (f32) fmod(temp_r3, temp_f3 + this->unkF0, (f32) temp_r3, temp_f3);

        temp_r3_199 = M2C_FIELD(temp_r30, s32 *, 0x14);
        if (age > (this->unk12C * this->unk134[temp_r3_199].unk0)) {
            M2C_FIELD(temp_r30, s32 *, 0x14) = temp_r3_199 + 1;
        }
        temp_r4 = M2C_FIELD(temp_r30, s32 *, 0x14);
        idx = temp_r4 - 1;
        temp_r5 = &this->unk134[idx];
        temp_f3_224 = -((this->unk12C * temp_r5->unk0) - age) / (this->unk12C * (this->unk134[temp_r4].unk0 - temp_r5->unk0));
        var_r31->unk1C = (temp_f3_224 * temp_r5->unkC) + temp_r5->unk4;
        temp_f0 = var_r31->unk1C;
        if (temp_f0 < 1.0f) {
        } else {
            temp_f0 = 1.0f;
        }
        if (temp_f0 > 0.0f) {
        } else {
            temp_f0 = 0.0f;
        }
        var_r31->unk1C = temp_f0;
        var_r31->unk28 = M2C_FIELD(temp_r30, f32 *, 0x18) * ((temp_f3_224 * temp_r5->unk10) + temp_r5->unk8);
        var_r31 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    }
}

void WeatherRainPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r3;
    void *temp_r4;

    temp_r3 = CreateParticle();
    if (temp_r3 != NULL) {
        temp_r4 = M2C_FIELD(temp_r3, void **, 0x2C);
        M2C_FIELD(temp_r3, MKVector3 *, 0) = arg0;
        M2C_FIELD(temp_r3, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r4, MKVector3 *, 0) = arg1;
        M2C_FIELD(temp_r4, f32 *, 0x18) = arg2;
        M2C_FIELD(temp_r4, f32 *, 0x1C) = 0.0f;
        M2C_FIELD(temp_r4, s32 *, 0x14) = 0;
    }
}

void WeatherRainPS::Deinit() {
    MKParticleSystem::Deinit();
}

s32 WeatherRainPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

void WeatherRainPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 2.5f;
    this->unkAC = 10.0f;
    this->unk108 = 0.0f;
    this->unk10C = -980.0f;
    this->unk110 = 0.0f;
    SetEnvelope(gWeatherRainPSEnv, 5);
    SetMaxParticleAge(5.0f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}
