#include "spyro/source/EmbersPS.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/WindFX.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gEmbersPSEnv;     /* unable to generate initializer: confusing struct layout */

void EmbersPS::ApplyWind(WindFX *arg0) {
    WindFX sp20;
    f32 sp18;
    MKParticleChunk *var_r30_73;
    f32 temp_f31_81;
    void *temp_r29_76;

    var_r30_73 = GetFirstParticle(&unksp8);
loop_2:
    if (var_r30_73 != NULL) {
        temp_r29_76 = var_r30_73->unk2C;
        temp_f31_81 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        sp20.GetVelocity(*((MKVector3 *) arg0));
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp20.unk10 = sp10;
        sp18 = (f32) sp20.unk8 * temp_f31_81;
        sp20.unk18 = (f64) sp18;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
        M2C_FIELD(temp_r29_76, f32 *, 8) = (f32) (M2C_FIELD(temp_r29_76, f32 *, 8) + (f32) sp20.unk18);
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

#if 0 // DRAFT: undefined identifier 'unk48'
void EmbersPS::Init() {
    MKParticleSystem::Init();
    this->unk60.unk48 = 5.0f;
    this->unk60.unk4C = 5.0f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gEmbersPSEnv, 5);
    SetMaxParticleAge(0.85f);
    this->unk60.unk50 = 0.0f;
    this->unkF0 = 0.0f;
    this->unk118 = 0.95f;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void EmbersPSDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
    this->unk80 = 1;
    this->unk84 = 1.0f / (f32) this->unk80;
}
#endif
