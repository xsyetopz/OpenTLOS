#include "spyro/source/WeatherRainPS.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

f64 fmod(s32, f32, f32, f32);                       /* extern */
extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gWeatherRainPSEnv; /* unable to generate initializer: confusing struct layout */

void WeatherRainPS::UpdateParticles() {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp18;
    MKParticleChunk *var_r30_66;
    MKParticleSystem::Envelope *temp_r3_156;
    f32 temp_f29_73;
    f32 temp_f3_134;
    f32 temp_f3_169;
    f32 temp_f4_162;
    f32 temp_f5_158;
    f32 var_f0_172;
    s32 temp_r3_130;
    s32 temp_r3_144;
    s32 temp_r4_155;
    s32 temp_r6_159;
    void *temp_r29_69;
    void *temp_r5_160;
    void *temp_r5_192;

    this->unk128 += gUpdateTimeDelta;
    var_r30_66 = GetFirstParticle(&unksp8);
loop_12:
    if (var_r30_66 != NULL) {
        temp_r29_69 = var_r30_66->unk2C;
        temp_f29_73 = this->unk128 - M2C_FIELD(temp_r29_69, f32 *, 0x10);
        if (temp_f29_73 > this->unk12C) {
            var_r30_66 = DestroyParticle(&unksp8);
        } else {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp40 = sp20;
            sp28 = M2C_FIELD(temp_r29_69, f32 *, 8) * gUpdateTimeDelta;
            sp48 = (f64) sp28;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
            var_r30_66->unk8 += (f32) sp48;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            sp30 = sp10;
            sp18 = this->unk110 * gUpdateTimeDelta;
            sp38 = (f64) sp18;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_FIELD(temp_r29_69, f32 *, 8) = (f32) (M2C_FIELD(temp_r29_69, f32 *, 8) + (f32) sp38);
            var_r30_66->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29_69, f32 *, 0x1C);
            temp_r3_130 = M2C_FIELD(checked_cast<MKBaseParticleSystemDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x80);
            temp_f3_134 = var_r30_66->unk20;
            var_r30_66->unk20 = (f32) fmod(temp_r3_130, temp_f3_134 + this->unkF0, (f32) temp_r3_130, temp_f3_134);
            temp_r3_144 = M2C_FIELD(temp_r29_69, s32 *, 0x14);
            if (temp_f29_73 > (this->unk12C * *(this->unk134 + (temp_r3_144 * 0x14)))) {
                M2C_FIELD(temp_r29_69, s32 *, 0x14) = (s32) (temp_r3_144 + 1);
            }
            temp_r4_155 = M2C_FIELD(temp_r29_69, s32 *, 0x14);
            temp_r3_156 = this->unk134;
            temp_f5_158 = this->unk12C;
            temp_r6_159 = (temp_r4_155 - 1) * 0x14;
            temp_r5_160 = temp_r3_156 + temp_r6_159;
            temp_f4_162 = M2C_FIELD(temp_r5_160, f32 *, 0);
            temp_f3_169 = -((temp_f5_158 * temp_f4_162) - temp_f29_73) / (temp_f5_158 * (*(temp_r3_156 + (temp_r4_155 * 0x14)) - temp_f4_162));
            var_r30_66->unk1C = (temp_f3_169 * M2C_FIELD(temp_r5_160, f32 *, 0xC)) + M2C_FIELD(temp_r5_160, f32 *, 4);
            var_f0_172 = var_r30_66->unk1C;
            if (var_f0_172 < 1.0f) {

            } else {
                var_f0_172 = 1.0f;
            }
            if (var_f0_172 > 0.0f) {

            } else {
                var_f0_172 = 0.0f;
            }
            var_r30_66->unk1C = var_f0_172;
            temp_r5_192 = this->unk134 + temp_r6_159;
            var_r30_66->unk28 = M2C_FIELD(temp_r29_69, f32 *, 0x18) * ((temp_f3_169 * M2C_FIELD(temp_r5_192, f32 *, 0x10)) + M2C_FIELD(temp_r5_192, f32 *, 8));
            var_r30_66 = GetNextParticle(&unksp8);
        }
        goto loop_12;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void WeatherRainPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r3_229;
    void *temp_r4_232;

    temp_r3_229 = CreateParticle();
    if (temp_r3_229 != NULL) {
        temp_r4_232 = M2C_FIELD(temp_r3_229, void **, 0x2C);
        M2C_FIELD(temp_r3_229, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_229, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_229, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r4_232, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r4_232, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r4_232, f32 *, 0x18) = (f32) &arg2;
        M2C_FIELD(temp_r4_232, f32 *, 0x1C) = 0.0f;
        M2C_FIELD(temp_r4_232, s32 *, 0x14) = 0;
    }
}
#endif

void WeatherRainPS::Deinit() {
    MKParticleSystem::Deinit();
}

void WeatherRainPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

#if 0 // DRAFT: undefined identifier 'gWeatherRainPSEnv'
void WeatherRainPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 2.5f;
    this->unkAC = 10.0f;
    this->unk108 = 0.0f;
    this->unk10C = -980.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gWeatherRainPSEnv, 5);
    SetMaxParticleAge(5.0f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}
#endif
