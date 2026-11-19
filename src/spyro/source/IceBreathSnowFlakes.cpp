#include "spyro/source/IceBreathSnowFlakes.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/WindFX.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

f64 fmod(s32, f32, f32, f32);                       /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gIceBreathSnowFlakesEnv; /* unable to generate initializer: confusing struct layout */

void IceBreathSnowFlakes::ApplyWind(WindFX *arg0) {
    WindFX sp10;
    MKParticleChunk *var_r3_56;
    void *temp_r31_59;

    var_r3_56 = GetFirstParticle(&unksp8);
loop_2:
    if (var_r3_56 != NULL) {
        temp_r31_59 = var_r3_56->unk2C;
        sp10.GetVelocity(*((MKVector3 *) arg0));
        sp10.unk10 = M2C_BITWISE(f64, sp10);
        sp10.unk18 = sp10.unk8;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r31, 0x0, qr0 */);
        M2C_FIELD(temp_r31_59, f32 *, 8) = (f32) (M2C_FIELD(temp_r31_59, f32 *, 8) + (f32) sp10.unk18);
        var_r3_56 = GetNextParticle(&unksp8);
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp8'
void IceBreathSnowFlakes::UpdateParticles() {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp18;
    MKParticleChunk *var_r30_109;
    MKParticleSystem::Envelope *temp_r3_199;
    f32 temp_f29_116;
    f32 temp_f3_177;
    f32 temp_f3_213;
    f32 temp_f5_206;
    f32 temp_f6_201;
    f32 var_f0_217;
    s32 temp_r3_173;
    s32 temp_r3_187;
    s32 temp_r4_198;
    s32 temp_r6_202;
    void *temp_r29_112;
    void *temp_r5_204;
    void *temp_r5_237;

    this->unk128 += gUpdateTimeDelta;
    var_r30_109 = GetFirstParticle(&unksp8);
loop_12:
    if (var_r30_109 != NULL) {
        temp_r29_112 = var_r30_109->unk2C;
        temp_f29_116 = this->unk128 - M2C_FIELD(temp_r29_112, f32 *, 0x10);
        if (temp_f29_116 > this->unk12C) {
            var_r30_109 = DestroyParticle(&unksp8);
        } else {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp40 = sp20;
            sp28 = M2C_FIELD(temp_r29_112, f32 *, 8) * gUpdateTimeDelta;
            sp48 = (f64) sp28;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
            var_r30_109->unk8 += (f32) sp48;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            sp30 = sp10;
            sp18 = this->unk110 * gUpdateTimeDelta;
            sp38 = (f64) sp18;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_FIELD(temp_r29_112, f32 *, 8) = (f32) (M2C_FIELD(temp_r29_112, f32 *, 8) + (f32) sp38);
            var_r30_109->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29_112, f32 *, 0x18);
            temp_r3_173 = M2C_FIELD(checked_cast<MKBaseParticleSystemDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x80);
            temp_f3_177 = var_r30_109->unk20;
            var_r30_109->unk20 = (f32) fmod(temp_r3_173, temp_f3_177 + this->unkF0, (f32) temp_r3_173, temp_f3_177);
            temp_r3_187 = M2C_FIELD(temp_r29_112, s32 *, 0x14);
            if (temp_f29_116 > (this->unk12C * *(this->unk134 + (temp_r3_187 * 0x14)))) {
                M2C_FIELD(temp_r29_112, s32 *, 0x14) = (s32) (temp_r3_187 + 1);
            }
            temp_r4_198 = M2C_FIELD(temp_r29_112, s32 *, 0x14);
            temp_r3_199 = this->unk134;
            temp_f6_201 = this->unk12C;
            temp_r6_202 = (temp_r4_198 - 1) * 0x14;
            temp_r5_204 = temp_r3_199 + temp_r6_202;
            temp_f5_206 = M2C_FIELD(temp_r5_204, f32 *, 0);
            temp_f3_213 = -((temp_f6_201 * temp_f5_206) - temp_f29_116) / (temp_f6_201 * (*(temp_r3_199 + (temp_r4_198 * 0x14)) - temp_f5_206));
            var_r30_109->unk1C = M2C_FIELD(temp_r29_112, f32 *, 0x20) * ((temp_f3_213 * M2C_FIELD(temp_r5_204, f32 *, 0xC)) + M2C_FIELD(temp_r5_204, f32 *, 4));
            var_f0_217 = var_r30_109->unk1C;
            if (var_f0_217 < 1.0f) {

            } else {
                var_f0_217 = 1.0f;
            }
            if (var_f0_217 > 0.0f) {

            } else {
                var_f0_217 = 0.0f;
            }
            var_r30_109->unk1C = var_f0_217;
            temp_r5_237 = this->unk134 + temp_r6_202;
            var_r30_109->unk28 = M2C_FIELD(temp_r29_112, f32 *, 0x1C) * ((temp_f3_213 * M2C_FIELD(temp_r5_237, f32 *, 0x10)) + M2C_FIELD(temp_r5_237, f32 *, 8));
            var_r30_109 = GetNextParticle(&unksp8);
        }
        goto loop_12;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void IceBreathSnowFlakes::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r31_277;
    void *temp_r3_274;

    temp_r3_274 = CreateParticle();
    if (temp_r3_274 != NULL) {
        temp_r31_277 = M2C_FIELD(temp_r3_274, void **, 0x2C);
        M2C_FIELD(temp_r3_274, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_274, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_274, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r31_277, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r31_277, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r31_277, f32 *, 0x1C) = (f32) &arg2;
        M2C_FIELD(temp_r31_277, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r31_277, f32 *, 0x18) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
    }
}
#endif

void IceBreathSnowFlakes::Deinit() {
    MKParticleSystem::Deinit();
}

void IceBreathSnowFlakes::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

#if 0 // DRAFT: undefined identifier 'unk48'
void IceBreathSnowFlakes::Init() {
    MKParticleSystem::Init();
    this->unk60.unk48 = 10.5f;
    this->unk60.unk4C = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = -200.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gIceBreathSnowFlakesEnv, 5);
    SetMaxParticleAge(5.0f);
    this->unk60.unk50 = 0.0f;
    this->unkF0 = 0.0f;
}
#endif
