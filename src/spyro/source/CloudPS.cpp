#include "spyro/source/CloudPS.h"
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
static MKParticleSystem::Envelope gCloudPSEnv[5] = {
    { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f },
    { 0.25f, 0.5f, 1.0f, 0.0f, 0.0f },
    { 0.5f, 1.0f, 1.0f, 0.0f, 0.0f },
    { 0.75f, 0.5f, 1.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 1.0f, 0.0f, 0.0f },
};

#if 0 // DRAFT: undefined identifier 'unksp8'
void CloudPS::UpdateParticles() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    MKParticleChunk *var_r30_72;
    MKParticleSystem::Envelope *temp_r3_141;
    MKParticleSystem::Envelope *temp_r5_146;
    MKParticleSystem::Envelope *temp_r5_179;
    f32 temp_f30_79;
    f32 temp_f3_119;
    f32 temp_f3_155;
    f32 temp_f5_148;
    f32 temp_f6_143;
    f32 var_f0_159;
    f64 temp_f0_91;
    s32 temp_r0_142;
    s32 temp_r3_115;
    s32 temp_r3_129;
    s32 temp_r4_140;
    void *temp_r29_75;

    this->unk128 += gUpdateTimeDelta;
    var_r30_72 = GetFirstParticle(&unksp8);
loop_12:
    if (var_r30_72 != NULL) {
        temp_r29_75 = var_r30_72->unk2C;
        temp_f30_79 = this->unk128 - M2C_FIELD(temp_r29_75, f32 *, 0x10);
        if (temp_f30_79 > this->unk12C) {
            var_r30_72 = DestroyParticle(&unksp8);
        } else {
            temp_f0_91 = M2C_FIELD(temp_r29_75, f64 *, 0) * (f64) gUpdateTimeDelta;
            sp10 = temp_f0_91;
            sp20 = temp_f0_91;
            sp18 = M2C_FIELD(temp_r29_75, f32 *, 8) * gUpdateTimeDelta;
            sp28 = (f64) sp18;
            M2C_FIELD(var_r30_72, f64 *, 0) = (f64) (M2C_FIELD(var_r30_72, f64 *, 0) + temp_f0_91);
            var_r30_72->unk8 += (f32) sp28;
            var_r30_72->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29_75, f32 *, 0x18);
            temp_r3_115 = M2C_FIELD(checked_cast<CloudPSDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x80);
            temp_f3_119 = var_r30_72->unk20;
            var_r30_72->unk20 = (f32) fmod(temp_r3_115, temp_f3_119 + this->unkF0, (f32) temp_r3_115, temp_f3_119);
            temp_r3_129 = M2C_FIELD(temp_r29_75, s32 *, 0x14);
            if (temp_f30_79 > (this->unk12C * this->unk134[temp_r3_129].unk0)) {
                M2C_FIELD(temp_r29_75, s32 *, 0x14) = (s32) (temp_r3_129 + 1);
            }
            temp_r4_140 = M2C_FIELD(temp_r29_75, s32 *, 0x14);
            temp_r3_141 = this->unk134;
            temp_r0_142 = temp_r4_140 - 1;
            temp_f6_143 = this->unk12C;
            temp_r5_146 = &temp_r3_141[temp_r0_142];
            temp_f5_148 = temp_r5_146->unk0;
            temp_f3_155 = -((temp_f6_143 * temp_f5_148) - temp_f30_79) / (temp_f6_143 * (temp_r3_141[temp_r4_140].unk0 - temp_f5_148));
            var_r30_72->unk1C = M2C_FIELD(temp_r29_75, f32 *, 0x20) * ((temp_f3_155 * temp_r5_146->unkC) + temp_r5_146->unk4);
            var_f0_159 = var_r30_72->unk1C;
            if (var_f0_159 < 1.0f) {

            } else {
                var_f0_159 = 1.0f;
            }
            if (var_f0_159 > 0.0f) {

            } else {
                var_f0_159 = 0.0f;
            }
            var_r30_72->unk1C = var_f0_159;
            temp_r5_179 = &this->unk134[temp_r0_142];
            var_r30_72->unk28 = M2C_FIELD(temp_r29_75, f32 *, 0x1C) * ((temp_f3_155 * temp_r5_179->unk10) + temp_r5_179->unk8);
            var_r30_72 = GetNextParticle(&unksp8);
        }
        goto loop_12;
    }
}
#endif

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
