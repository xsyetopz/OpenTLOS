#include "spyro/source/BlizzardBreathPS.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gBlizzardBreathPSEnv; /* unable to generate initializer: confusing struct layout */

void BlizzardBreathPS::UpdateParticles() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    MKParticleChunk *var_r7_62;
    MKParticleSystem::Envelope *temp_r3_120;
    f32 temp_f3_134;
    f32 temp_f3_69;
    f32 temp_f5_127;
    f32 temp_f6_122;
    f32 var_f0_138;
    s32 temp_r3_108;
    s32 temp_r4_119;
    s32 temp_r6_123;
    void *temp_r5_125;
    void *temp_r5_158;
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
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r8, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp20 = sp10;
            sp18 = M2C_FIELD(temp_r8_65, f32 *, 8) * gUpdateTimeDelta;
            sp28 = (f64) sp18;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r7, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r7, 0x0, qr0 */);
            var_r7_62->unk8 += (f32) sp28;
            var_r7_62->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r8_65, f32 *, 0x18);
            temp_r3_108 = M2C_FIELD(temp_r8_65, s32 *, 0x14);
            if (temp_f3_69 > (this->unk12C * *(this->unk134 + (temp_r3_108 * 0x14)))) {
                M2C_FIELD(temp_r8_65, s32 *, 0x14) = (s32) (temp_r3_108 + 1);
            }
            temp_r4_119 = M2C_FIELD(temp_r8_65, s32 *, 0x14);
            temp_r3_120 = this->unk134;
            temp_f6_122 = this->unk12C;
            temp_r6_123 = (temp_r4_119 - 1) * 0x14;
            temp_r5_125 = temp_r3_120 + temp_r6_123;
            temp_f5_127 = M2C_FIELD(temp_r5_125, f32 *, 0);
            temp_f3_134 = -((temp_f6_122 * temp_f5_127) - temp_f3_69) / (temp_f6_122 * (*(temp_r3_120 + (temp_r4_119 * 0x14)) - temp_f5_127));
            var_r7_62->unk1C = M2C_FIELD(temp_r8_65, f32 *, 0x20) * ((temp_f3_134 * M2C_FIELD(temp_r5_125, f32 *, 0xC)) + M2C_FIELD(temp_r5_125, f32 *, 4));
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
            temp_r5_158 = this->unk134 + temp_r6_123;
            var_r7_62->unk28 = M2C_FIELD(temp_r8_65, f32 *, 0x1C) * ((temp_f3_134 * M2C_FIELD(temp_r5_158, f32 *, 0x10)) + M2C_FIELD(temp_r5_158, f32 *, 8));
            var_r7_62 = GetNextParticle(&unksp8);
        }
        goto loop_12;
    }
}
#endif

void BlizzardBreathPS::Deinit() {
    MKParticleSystem::Deinit();
}

void BlizzardBreathPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

#if 0 // DRAFT: undefined identifier 'gBlizzardBreathPSEnv'
void BlizzardBreathPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 10.5f;
    this->unkAC = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gBlizzardBreathPSEnv, 5);
    SetMaxParticleAge(1.0f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}
#endif

void BlizzardBreathPSDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
    this->unk80 = 1;
    this->unk84 = 1.0f / (f32) this->unk80;
}
