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

#if 0 // DRAFT: undefined identifier 'unksp8'
void IceBreathSnow::UpdateParticles() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    MKParticleChunk *var_r30_64;
    MKParticleSystem::Envelope *temp_r3_133;
    MKParticleSystem::Envelope *temp_r5_138;
    MKParticleSystem::Envelope *temp_r5_171;
    f32 temp_f30_71;
    f32 temp_f3_111;
    f32 temp_f3_147;
    f32 temp_f5_140;
    f32 temp_f6_135;
    f32 var_f0_151;
    f64 temp_f0_83;
    s32 temp_r0_134;
    s32 temp_r3_107;
    s32 temp_r3_121;
    s32 temp_r4_132;
    void *temp_r29_67;

    this->unk128 += gUpdateTimeDelta;
    var_r30_64 = GetFirstParticle(&unksp8);
loop_12:
    if (var_r30_64 != NULL) {
        temp_r29_67 = var_r30_64->unk2C;
        temp_f30_71 = this->unk128 - M2C_FIELD(temp_r29_67, f32 *, 0x10);
        if (temp_f30_71 > this->unk12C) {
            var_r30_64 = DestroyParticle(&unksp8);
        } else {
            temp_f0_83 = M2C_FIELD(temp_r29_67, f64 *, 0) * (f64) gUpdateTimeDelta;
            sp10 = temp_f0_83;
            sp20 = temp_f0_83;
            sp18 = M2C_FIELD(temp_r29_67, f32 *, 8) * gUpdateTimeDelta;
            sp28 = (f64) sp18;
            M2C_FIELD(var_r30_64, f64 *, 0) = (f64) (M2C_FIELD(var_r30_64, f64 *, 0) + temp_f0_83);
            var_r30_64->unk8 += (f32) sp28;
            var_r30_64->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29_67, f32 *, 0x18);
            temp_r3_107 = M2C_FIELD(checked_cast<MKBaseParticleSystemDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x80);
            temp_f3_111 = var_r30_64->unk20;
            var_r30_64->unk20 = (f32) fmod(temp_r3_107, temp_f3_111 + this->unkF0, (f32) temp_r3_107, temp_f3_111);
            temp_r3_121 = M2C_FIELD(temp_r29_67, s32 *, 0x14);
            if (temp_f30_71 > (this->unk12C * this->unk134[temp_r3_121].unk0)) {
                M2C_FIELD(temp_r29_67, s32 *, 0x14) = (s32) (temp_r3_121 + 1);
            }
            temp_r4_132 = M2C_FIELD(temp_r29_67, s32 *, 0x14);
            temp_r3_133 = this->unk134;
            temp_r0_134 = temp_r4_132 - 1;
            temp_f6_135 = this->unk12C;
            temp_r5_138 = &temp_r3_133[temp_r0_134];
            temp_f5_140 = temp_r5_138->unk0;
            temp_f3_147 = -((temp_f6_135 * temp_f5_140) - temp_f30_71) / (temp_f6_135 * (temp_r3_133[temp_r4_132].unk0 - temp_f5_140));
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
            var_r30_64 = GetNextParticle(&unksp8);
        }
        goto loop_12;
    }
}
#endif

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
