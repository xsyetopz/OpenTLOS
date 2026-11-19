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

void Steam::UpdateParticles() {
    f64 fmod(f64, f64); /* libm fmod(double, double), as the asm calls it */
    u8 sp8[0x8];
    MKParticleChunk *var_r30;
    void *temp_r29;
    MKParticleSystem::Envelope *lo;
    SteamDescriptor *desc;
    f32 dt;
    f32 age;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 wx;
    f32 wy;
    f32 wz;
    f32 t;
    f32 frac;
    f32 span;
    s32 cur;
    s32 prev;

    this->unk128 += gUpdateTimeDelta;
    var_r30 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    while (var_r30 != NULL) {
        temp_r29 = var_r30->unk2C;
        age = this->unk128 - M2C_FIELD(temp_r29, f32 *, 0x10);
        if (age > this->unk12C) {
            var_r30 = DestroyParticle((MKBaseParticleSystem::ParticleRec *) sp8);
            continue;
        }
        dt = gUpdateTimeDelta;
        M2C_FIELD(temp_r29, f32 *, 4) = (500.0f * dt) + M2C_FIELD(temp_r29, f32 *, 4);

        /* MKVector3::operator*(1.5f) per lane, then scale by dt; velocity -= that. */
        tx = M2C_FIELD(temp_r29, f32 *, 0) * 1.5f;
        ty = M2C_FIELD(temp_r29, f32 *, 4) * 1.5f;
        tz = M2C_FIELD(temp_r29, f32 *, 8) * 1.5f;
        vx = tx * dt;
        vy = ty * dt;
        vz = tz * dt;
        M2C_FIELD(temp_r29, f32 *, 0) = M2C_FIELD(temp_r29, f32 *, 0) - vx;
        M2C_FIELD(temp_r29, f32 *, 4) = M2C_FIELD(temp_r29, f32 *, 4) - vy;
        M2C_FIELD(temp_r29, f32 *, 8) = M2C_FIELD(temp_r29, f32 *, 8) - vz;

        /* position += velocity * dt */
        wx = M2C_FIELD(temp_r29, f32 *, 0) * dt;
        wy = M2C_FIELD(temp_r29, f32 *, 4) * dt;
        wz = M2C_FIELD(temp_r29, f32 *, 8) * dt;
        M2C_FIELD(var_r30, f32 *, 0) = M2C_FIELD(var_r30, f32 *, 0) + wx;
        M2C_FIELD(var_r30, f32 *, 4) = M2C_FIELD(var_r30, f32 *, 4) + wy;
        M2C_FIELD(var_r30, f32 *, 8) = M2C_FIELD(var_r30, f32 *, 8) + wz;
        var_r30->unk24 += dt * M2C_FIELD(temp_r29, f32 *, 0x18);

        desc = checked_cast<SteamDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_r30->unk20 = (f32) fmod((f64) (var_r30->unk20 + this->unkF0), (f64) desc->unk80);

        cur = M2C_FIELD(temp_r29, s32 *, 0x14);
        if (age > (this->unk12C * this->unk134[cur].unk0)) {
            M2C_FIELD(temp_r29, s32 *, 0x14) = cur + 1;
        }
        cur = M2C_FIELD(temp_r29, s32 *, 0x14);
        prev = cur - 1;
        lo = &this->unk134[prev];
        span = this->unk12C * (this->unk134[cur].unk0 - lo->unk0);
        t = (age - (this->unk12C * lo->unk0)) / span;

        var_r30->unk1C = M2C_FIELD(temp_r29, f32 *, 0x20) * ((t * lo->unkC) + lo->unk4);
        if (var_r30->unk1C < 1.0f) {
        } else {
            var_r30->unk1C = 1.0f;
        }
        if (var_r30->unk1C > 0.0f) {
        } else {
            var_r30->unk1C = 0.0f;
        }

        var_r30->unk28 = M2C_FIELD(temp_r29, f32 *, 0x1C) * ((t * lo->unk10) + lo->unk8);

        frac = age / this->unk12C;
        var_r30->unk10 = (0.35f * frac) + 0.75f;
        var_r30->unk14 = (0.35f * frac) + 0.75f;
        var_r30->unk18 = (0.9f * frac) + 0.1f;
        var_r30 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    }
}

void Steam::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r30_253;
    void *temp_r3_250;

    temp_r3_250 = CreateParticle();
    if (temp_r3_250 != NULL) {
        temp_r30_253 = M2C_FIELD(temp_r3_250, void **, 0x2C);
        M2C_FIELD(temp_r3_250, f64 *, 0) = M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_250, f64 *, 8) = M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_250, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r30_253, f64 *, 0) = M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r30_253, f64 *, 8) = M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r30_253, f32 *, 0x1C) = arg2;
        M2C_FIELD(temp_r30_253, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r3_250, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r30_253, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, -0.3f, 0.3f);
    }
}

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
