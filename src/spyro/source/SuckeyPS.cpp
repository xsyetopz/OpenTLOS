#include "spyro/source/SuckeyPS.h"
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
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
static MKParticleSystem::Envelope gSuckeyPSEnv[5] = {
    { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f },
    { 0.25f, 0.5f, 0.85f, 0.0f, 0.0f },
    { 0.5f, 1.0f, 0.75f, 0.0f, 0.0f },
    { 0.75f, 1.0f, 0.5f, 0.0f, 0.0f },
    { 1.0f, 1.0f, 0.0f, 0.0f, 0.0f },
};

#if 0 // DRAFT: undefined identifier 'unksp8'
void SuckeyPS::UpdateParticles() {
    f64 sp38;
    f64 sp30;
    MKVector3 sp20;
    f32 sp18;
    f64 sp10;
    MKParticleChunk *var_r30_77;
    MKParticleSystem::Envelope *temp_r3_141;
    MKParticleSystem::Envelope *temp_r5_145;
    MKParticleSystem::Envelope *temp_r5_177;
    f32 temp_f2_82;
    f32 temp_f30_84;
    f32 temp_f3_154;
    f32 temp_f4_147;
    f32 temp_f5_143;
    f32 var_f0_157;
    f32 var_f0_95;
    s32 temp_r0_142;
    s32 temp_r3_128;
    s32 temp_r4_140;
    void *temp_r29_80;

    M2C_STRUCT_COPY((s32) (this + 0x5C) + 4, this->unk140 - 4 + 4, 0x40);
    this->unk128 += gUpdateTimeDelta;
    var_r30_77 = GetFirstParticle(&unksp8);
loop_18:
    if (var_r30_77 != NULL) {
        temp_r29_80 = var_r30_77->unk2C;
        temp_f2_82 = M2C_FIELD(temp_r29_80, f32 *, 0x20);
        temp_f30_84 = temp_f2_82 * this->unk12C;
        if (temp_f2_82 == 1.0f) {
            var_r30_77 = DestroyParticle(&unksp8);
        } else {
            var_f0_95 = (M2C_FIELD(temp_r29_80, f32 *, 0x24) * gUpdateTimeDelta) + temp_f2_82;
            if (var_f0_95 < 1.0f) {

            } else {
                var_f0_95 = 1.0f;
            }
            if (var_f0_95 > 0.0f) {

            } else {
                var_f0_95 = 0.0f;
            }
            M2C_FIELD(temp_r29_80, f32 *, 0x20) = var_f0_95;
            sp20.operator*(M2C_FIELD(temp_r29_80, f32 *, 0x20));
            sp10 = M2C_FIELD(temp_r29_80, f64 *, 0x10) + M2C_BITWISE(f64, sp20);
            M2C_FIELD(var_r30_77, f64 *, 0) = sp10;
            sp18 = M2C_FIELD(temp_r29_80, f32 *, 0x18) + sp20.unk8;
            sp30 = sp10;
            M2C_FIELD(var_r30_77, f64 *, 8) = (f64) sp18;
            temp_r3_128 = M2C_FIELD(temp_r29_80, s32 *, 0x28);
            sp38 = (f64) sp18;
            if (temp_f30_84 > (this->unk12C * this->unk134[temp_r3_128].unk0)) {
                M2C_FIELD(temp_r29_80, s32 *, 0x28) = (s32) (temp_r3_128 + 1);
            }
            temp_r4_140 = M2C_FIELD(temp_r29_80, s32 *, 0x28);
            temp_r3_141 = this->unk134;
            temp_r0_142 = temp_r4_140 - 1;
            temp_f5_143 = this->unk12C;
            temp_r5_145 = &temp_r3_141[temp_r0_142];
            temp_f4_147 = temp_r5_145->unk0;
            temp_f3_154 = -((temp_f5_143 * temp_f4_147) - temp_f30_84) / (temp_f5_143 * (temp_r3_141[temp_r4_140].unk0 - temp_f4_147));
            var_r30_77->unk1C = (temp_f3_154 * temp_r5_145->unkC) + temp_r5_145->unk4;
            var_f0_157 = var_r30_77->unk1C;
            if (var_f0_157 < 1.0f) {

            } else {
                var_f0_157 = 1.0f;
            }
            if (var_f0_157 > 0.0f) {

            } else {
                var_f0_157 = 0.0f;
            }
            var_r30_77->unk1C = var_f0_157;
            temp_r5_177 = &this->unk134[temp_r0_142];
            var_r30_77->unk28 = M2C_FIELD(temp_r29_80, f32 *, 0x2C) * ((temp_f3_154 * temp_r5_177->unk10) + temp_r5_177->unk8);
            var_r30_77 = GetNextParticle(&unksp8);
        }
        goto loop_18;
    }
}
#endif

void SuckeyPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, float arg3) {
    f32 sp28x;
    f32 sp28y;
    f32 sp28z;
    f32 sp8x;
    f32 sp8y;
    f32 sp8z;
    void *temp_r30_220;
    void *temp_r3_215;

    temp_r3_215 = CreateParticle();
    if (temp_r3_215 != NULL) {
        temp_r30_220 = M2C_FIELD(temp_r3_215, void **, 0x2C);
        M2C_FIELD(temp_r3_215, f32 *, 0x10) = 1.0f;
        M2C_FIELD(temp_r3_215, f32 *, 0x14) = 1.0f;
        M2C_FIELD(temp_r3_215, f32 *, 0x18) = 1.0f;
        M2C_FIELD(temp_r3_215, f32 *, 0x1C) = 1.0f;
        M2C_FIELD(temp_r30_220, f32 *, 0x10) = M2C_FIELD(&arg0, f32 *, 0x0);
        M2C_FIELD(temp_r30_220, f32 *, 0x14) = M2C_FIELD(&arg0, f32 *, 0x4);
        M2C_FIELD(temp_r30_220, f32 *, 0x18) = M2C_FIELD(&arg0, f32 *, 0x8);
        M2C_FIELD(temp_r30_220, f32 *, 0x1C) = M2C_FIELD(&arg0, f32 *, 0xC);
        M2C_FIELD(temp_r3_215, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r30_220, s32 *, 0x28) = 1;
        M2C_FIELD(temp_r30_220, f32 *, 0x0) = M2C_FIELD(&arg1, f32 *, 0x0);
        M2C_FIELD(temp_r30_220, f32 *, 0x4) = M2C_FIELD(&arg1, f32 *, 0x4);
        M2C_FIELD(temp_r30_220, f32 *, 0x8) = M2C_FIELD(&arg1, f32 *, 0x8);
        M2C_FIELD(temp_r30_220, f32 *, 0xC) = M2C_FIELD(&arg1, f32 *, 0xC);
        M2C_FIELD(temp_r30_220, f32 *, 0x2C) = arg2;
        M2C_FIELD(temp_r30_220, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r30_220, f32 *, 0x24) = arg3;

        /* MKVector3::operator*(D.unk20) on D's velocity, per lane. */
        sp28x = M2C_FIELD(temp_r30_220, f32 *, 0x0) * M2C_FIELD(temp_r30_220, f32 *, 0x20);
        sp28y = M2C_FIELD(temp_r30_220, f32 *, 0x4) * M2C_FIELD(temp_r30_220, f32 *, 0x20);
        sp28z = M2C_FIELD(temp_r30_220, f32 *, 0x8) * M2C_FIELD(temp_r30_220, f32 *, 0x20);

        sp8x = M2C_FIELD(temp_r30_220, f32 *, 0x10) + sp28x;
        sp8y = M2C_FIELD(temp_r30_220, f32 *, 0x14) + sp28y;
        sp8z = M2C_FIELD(temp_r30_220, f32 *, 0x18) + sp28z;
        M2C_FIELD(temp_r3_215, f32 *, 0x0) = sp8x;
        M2C_FIELD(temp_r3_215, f32 *, 0x4) = sp8y;
        M2C_FIELD(temp_r3_215, f32 *, 0x8) = sp8z;
        M2C_FIELD(temp_r3_215, f32 *, 0x24) = 2.0f * MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r3_215, f32 *, 0x28) = M2C_FIELD(temp_r30_220, f32 *, 0x2C);
    }
}

void SuckeyPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 5.0f;
    this->unkAC = 5.0f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(gSuckeyPSEnv, 5);
    SetMaxParticleAge(10.0f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
    this->unk140 = 0;
}
