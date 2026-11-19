#include "spyro/source/CrashMistPS.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/Matrix.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern s32 gViewSeed;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gCrashMistPSEnv;  /* unable to generate initializer: confusing struct layout */

void CrashMistPS::UpdateParticles() {
    MKParticleChunk *var_r3_57;

    MKParticleSystem::UpdateParticles();
    var_r3_57 = GetFirstParticle(&unksp8);
loop_2:
    if (var_r3_57 != NULL) {
        var_r3_57 = GetNextParticle(&unksp8);
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void CrashMistPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, const float &arg3, const MKVector4 &arg4, const float &arg5) {
    void *temp_r31_92;
    void *temp_r3_89;

    temp_r3_89 = CreateParticle();
    if (temp_r3_89 != NULL) {
        temp_r31_92 = M2C_FIELD(temp_r3_89, void **, 0x2C);
        M2C_FIELD(temp_r3_89, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_89, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_89, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_89, f64 *, 0x10) = (f64) M2C_FIELD(&arg4, f64 *, 0);
        M2C_FIELD(temp_r3_89, f64 *, 0x18) = (f64) M2C_FIELD(&arg4, f64 *, 8);
        M2C_FIELD(temp_r31_92, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r31_92, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r31_92, f32 *, 0x1C) = (f32) &arg2;
        M2C_FIELD(temp_r31_92, f32 *, 0x20) = (f32) &arg5;
        M2C_FIELD(temp_r31_92, f32 *, 0x18) = (f32) (&arg3 * MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f));
    }
}
#endif

void CrashMistPS::Deinit() {
    MKParticleSystem::Deinit();
}

void CrashMistPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

#if 0 // DRAFT: undefined identifier 'gCrashMistPSEnv'
void CrashMistPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 10.5f;
    this->unkAC = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gCrashMistPSEnv, 5);
    SetMaxParticleAge(3.0f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}
#endif
