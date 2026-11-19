#include "spyro/source/LavaSteamPS.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

f64 fmod(s32, f32, f32, f32);                       /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gLavaSteamPSEnv;  /* unable to generate initializer: confusing struct layout */

void LavaSteamPS::UpdateParticles() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    MKParticleChunk *var_r30_64;
    MKParticleSystem::Envelope *temp_r3_138;
    f32 temp_f2_188;
    f32 temp_f30_71;
    f32 temp_f3_116;
    f32 temp_f4_187;
    f32 temp_f5_145;
    f32 temp_f6_140;
    f32 temp_f6_152;
    f32 var_f0_156;
    f64 temp_f0_88;
    s32 temp_r3_112;
    s32 temp_r3_126;
    s32 temp_r4_137;
    s32 temp_r6_141;
    void *temp_r29_67;
    void *temp_r5_143;
    void *temp_r5_177;

    this->unk128 += gUpdateTimeDelta;
    var_r30_64 = GetFirstParticle(&unksp8);
loop_12:
    if (var_r30_64 != NULL) {
        temp_r29_67 = var_r30_64->unk2C;
        temp_f30_71 = this->unk128 - M2C_FIELD(temp_r29_67, f32 *, 0x10);
        if (temp_f30_71 > this->unk12C) {
            var_r30_64 = DestroyParticle(&unksp8);
        } else {
            M2C_FIELD(temp_r29_67, f32 *, 4) = (f32) ((1500.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r29_67, f32 *, 4));
            temp_f0_88 = M2C_FIELD(temp_r29_67, f64 *, 0) * (f64) gUpdateTimeDelta;
            sp10 = temp_f0_88;
            sp20 = temp_f0_88;
            sp18 = M2C_FIELD(temp_r29_67, f32 *, 8) * gUpdateTimeDelta;
            sp28 = (f64) sp18;
            M2C_FIELD(var_r30_64, f64 *, 0) = (f64) (M2C_FIELD(var_r30_64, f64 *, 0) + temp_f0_88);
            var_r30_64->unk8 += (f32) sp28;
            var_r30_64->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29_67, f32 *, 0x18);
            temp_r3_112 = M2C_FIELD(checked_cast<LavaSteamPSDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x80);
            temp_f3_116 = var_r30_64->unk20;
            var_r30_64->unk20 = (f32) fmod(temp_r3_112, temp_f3_116 + this->unkF0, (f32) temp_r3_112, temp_f3_116);
            temp_r3_126 = M2C_FIELD(temp_r29_67, s32 *, 0x14);
            if (temp_f30_71 > (this->unk12C * *(this->unk134 + (temp_r3_126 * 0x14)))) {
                M2C_FIELD(temp_r29_67, s32 *, 0x14) = (s32) (temp_r3_126 + 1);
            }
            temp_r4_137 = M2C_FIELD(temp_r29_67, s32 *, 0x14);
            temp_r3_138 = this->unk134;
            temp_f6_140 = this->unk12C;
            temp_r6_141 = (temp_r4_137 - 1) * 0x14;
            temp_r5_143 = temp_r3_138 + temp_r6_141;
            temp_f5_145 = M2C_FIELD(temp_r5_143, f32 *, 0);
            temp_f6_152 = -((temp_f6_140 * temp_f5_145) - temp_f30_71) / (temp_f6_140 * (*(temp_r3_138 + (temp_r4_137 * 0x14)) - temp_f5_145));
            var_r30_64->unk1C = M2C_FIELD(temp_r29_67, f32 *, 0x20) * ((temp_f6_152 * M2C_FIELD(temp_r5_143, f32 *, 0xC)) + M2C_FIELD(temp_r5_143, f32 *, 4));
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
            temp_r5_177 = this->unk134 + temp_r6_141;
            var_r30_64->unk28 = M2C_FIELD(temp_r29_67, f32 *, 0x1C) * ((temp_f6_152 * M2C_FIELD(temp_r5_177, f32 *, 0x10)) + M2C_FIELD(temp_r5_177, f32 *, 8));
            temp_f4_187 = temp_f30_71 / this->unk12C;
            temp_f2_188 = (0.35f * temp_f4_187) + 0.75f;
            var_r30_64->unk10 = temp_f2_188;
            var_r30_64->unk14 = temp_f2_188;
            var_r30_64->unk18 = (0.9f * temp_f4_187) + 0.1f;
            var_r30_64 = GetNextParticle(&unksp8);
        }
        goto loop_12;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void LavaSteamPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r30_225;
    void *temp_r3_222;

    temp_r3_222 = CreateParticle();
    if (temp_r3_222 != NULL) {
        temp_r30_225 = M2C_FIELD(temp_r3_222, void **, 0x2C);
        M2C_FIELD(temp_r3_222, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_222, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_222, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r30_225, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r30_225, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r30_225, f32 *, 0x1C) = (f32) &arg2;
        M2C_FIELD(temp_r30_225, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r3_222, f32 *, 0x24) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r30_225, f32 *, 0x18) = MKRand_Float(&gViewSeed, -0.3f, 0.3f);
    }
}
#endif

void LavaSteamPS::Deinit() {
    MKParticleSystem::Deinit();
}

void LavaSteamPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

#if 0 // DRAFT: undefined identifier 'gLavaSteamPSEnv'
void LavaSteamPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 10.5f;
    this->unkAC = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gLavaSteamPSEnv, 5);
    SetMaxParticleAge(1.0f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}
#endif

void LavaSteamPSDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
    this->unk80 = 1;
    this->unk84 = 1.0f / (f32) this->unk80;
}
