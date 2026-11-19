#include "spyro/source/EmbersPS.h"
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
#include "spyro/source/WindFX.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
static MKParticleSystem::Envelope gEmbersPSEnv[5] = {
    { 0.0f, 1.0f, 1.0f, 0.0f, 0.0f },
    { 0.25f, 1.0f, 0.75f, 0.0f, 0.0f },
    { 0.5f, 1.0f, 0.5f, 0.0f, 0.0f },
    { 0.75f, 1.0f, 0.25f, 0.0f, 0.0f },
    { 1.0f, 1.0f, 0.0f, 0.0f, 0.0f },
};

#if 0 // DRAFT: undefined identifier 'unksp8'
void EmbersPS::ApplyWind(WindFX *arg0) {
    WindFX sp20;
    f32 sp18;
    f64 sp10;
    MKParticleChunk *var_r30_73;
    f32 temp_f31_81;
    f64 temp_f0_87;
    void *temp_r29_76;

    var_r30_73 = GetFirstParticle(&unksp8);
loop_2:
    if (var_r30_73 != NULL) {
        temp_r29_76 = var_r30_73->unk2C;
        temp_f31_81 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        sp20.GetVelocity(*((MKVector3 *) arg0));
        temp_f0_87 = sp20.unk0 * (f64) temp_f31_81;
        sp10 = temp_f0_87;
        sp20.unk10 = temp_f0_87;
        sp18 = (f32) sp20.unk8 * temp_f31_81;
        sp20.unk18 = (f64) sp18;
        M2C_FIELD(temp_r29_76, f64 *, 0) = (f64) (M2C_FIELD(temp_r29_76, f64 *, 0) + (f64) sp20.unk10);
        M2C_FIELD(temp_r29_76, f32 *, 8) = (f32) (M2C_FIELD(temp_r29_76, f32 *, 8) + (f32) (f64) sp18);
        var_r30_73 = GetNextParticle(&unksp8);
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp8'
void EmbersPS::UpdateParticles() {
    MKParticleChunk *var_r3_129;
    void *temp_r5_132;

    var_r3_129 = GetFirstParticle(&unksp8);
loop_2:
    if (var_r3_129 != NULL) {
        temp_r5_132 = var_r3_129->unk2C;
        M2C_FIELD(temp_r5_132, f32 *, 4) = (f32) ((M2C_FIELD(temp_r5_132, f32 *, 0x24) * gUpdateTimeDelta) + M2C_FIELD(temp_r5_132, f32 *, 4));
        var_r3_129 = GetNextParticle(&unksp8);
        goto loop_2;
    }
    MKParticleSystem::UpdateParticles();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void EmbersPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, const MKVector4 &arg3, float arg4) {
    void *temp_r3_170;
    void *temp_r4_173;

    temp_r3_170 = CreateParticle();
    if (temp_r3_170 != NULL) {
        temp_r4_173 = M2C_FIELD(temp_r3_170, void **, 0x2C);
        M2C_FIELD(temp_r3_170, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_170, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_170, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_170, f64 *, 0x10) = (f64) M2C_FIELD(&arg3, f64 *, 0);
        M2C_FIELD(temp_r3_170, f64 *, 0x18) = (f64) M2C_FIELD(&arg3, f64 *, 8);
        M2C_FIELD(temp_r4_173, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r4_173, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r4_173, f32 *, 0x1C) = (f32) &arg2;
        M2C_FIELD(temp_r4_173, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r4_173, f32 *, 0x18) = 0.0f;
        M2C_FIELD(temp_r4_173, f32 *, 0x24) = arg4;
    }
}
#endif

void EmbersPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 5.0f;
    this->unkAC = 5.0f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(gEmbersPSEnv, 5);
    SetMaxParticleAge(0.85f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
    this->unk118 = 0.95f;
}

void EmbersPSDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
    this->unk80 = 1;
    this->unk84 = 1.0f / (f32) this->unk80;
}
