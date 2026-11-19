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

#if 0 // DRAFT: undefined identifier 'unksp8'
void BlizzardBreathPS::UpdateParticles() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    MKParticleChunk *var_r7_62;
    MKParticleSystem::Envelope *temp_r3_120;
    MKParticleSystem::Envelope *temp_r5_125;
    MKParticleSystem::Envelope *temp_r5_158;
    f32 temp_f3_134;
    f32 temp_f3_69;
    f32 temp_f5_127;
    f32 temp_f6_122;
    f32 var_f0_138;
    f64 temp_f0_86;
    s32 temp_r0_121;
    s32 temp_r3_108;
    s32 temp_r4_119;
    void *temp_r8_65;

    this->unk128 += gUpdateTimeDelta;
    var_r7_62 = GetFirstParticle(&unksp8);
loop_12:
    if (var_r7_62 != NULL) {
        temp_r8_65 = var_r7_62->unk2C;
        temp_f3_69 = this->unk128 - M2C_FIELD(temp_r8_65, f32 *, 0x10);
        if (temp_f3_69 > this->unk12C) {
            var_r7_62 = DestroyParticle(&unksp8);
        } else {
            M2C_FIELD(temp_r8_65, f32 *, 4) = (f32) -((3000.0f * gUpdateTimeDelta) - M2C_FIELD(temp_r8_65, f32 *, 4));
            temp_f0_86 = M2C_FIELD(temp_r8_65, f64 *, 0) * (f64) gUpdateTimeDelta;
            sp10 = temp_f0_86;
            sp20 = temp_f0_86;
            sp18 = M2C_FIELD(temp_r8_65, f32 *, 8) * gUpdateTimeDelta;
            sp28 = (f64) sp18;
            M2C_FIELD(var_r7_62, f64 *, 0) = (f64) (M2C_FIELD(var_r7_62, f64 *, 0) + temp_f0_86);
            var_r7_62->unk8 += (f32) sp28;
            var_r7_62->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r8_65, f32 *, 0x18);
            temp_r3_108 = M2C_FIELD(temp_r8_65, s32 *, 0x14);
            if (temp_f3_69 > (this->unk12C * this->unk134[temp_r3_108].unk0)) {
                M2C_FIELD(temp_r8_65, s32 *, 0x14) = (s32) (temp_r3_108 + 1);
            }
            temp_r4_119 = M2C_FIELD(temp_r8_65, s32 *, 0x14);
            temp_r3_120 = this->unk134;
            temp_r0_121 = temp_r4_119 - 1;
            temp_f6_122 = this->unk12C;
            temp_r5_125 = &temp_r3_120[temp_r0_121];
            temp_f5_127 = temp_r5_125->unk0;
            temp_f3_134 = -((temp_f6_122 * temp_f5_127) - temp_f3_69) / (temp_f6_122 * (temp_r3_120[temp_r4_119].unk0 - temp_f5_127));
            var_r7_62->unk1C = M2C_FIELD(temp_r8_65, f32 *, 0x20) * ((temp_f3_134 * temp_r5_125->unkC) + temp_r5_125->unk4);
            var_f0_138 = var_r7_62->unk1C;
            if (var_f0_138 < 1.0f) {

            } else {
                var_f0_138 = 1.0f;
            }
            if (var_f0_138 > 0.0f) {

            } else {
                var_f0_138 = 0.0f;
            }
            var_r7_62->unk1C = var_f0_138;
            temp_r5_158 = &this->unk134[temp_r0_121];
            var_r7_62->unk28 = M2C_FIELD(temp_r8_65, f32 *, 0x1C) * ((temp_f3_134 * temp_r5_158->unk10) + temp_r5_158->unk8);
            var_r7_62 = GetNextParticle(&unksp8);
        }
        goto loop_12;
    }
}
#endif

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
