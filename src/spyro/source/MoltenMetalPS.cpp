#include "spyro/source/MoltenMetalPS.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gMoltenMetalPSEnv; /* unable to generate initializer: confusing struct layout */

void MoltenMetalPS::UpdateParticles() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    MKParticleChunk *var_r7_62;
    MKParticleSystem::Envelope *temp_r3_115;
    f32 temp_f3_129;
    f32 temp_f3_69;
    f32 temp_f5_122;
    f32 temp_f6_117;
    f32 var_f0_133;
    s32 temp_r3_103;
    s32 temp_r4_114;
    s32 temp_r6_118;
    void *temp_r5_120;
    void *temp_r5_153;
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
            M2C_FIELD(temp_r8_65, f32 *, 4) = (f32) -((1000.0f * gUpdateTimeDelta) - M2C_FIELD(temp_r8_65, f32 *, 4));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r8, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp20 = sp10;
            sp18 = M2C_FIELD(temp_r8_65, f32 *, 8) * gUpdateTimeDelta;
            sp28 = (f64) sp18;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r7, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r7, 0x0, qr0 */);
            var_r7_62->unk8 += (f32) sp28;
            temp_r3_103 = M2C_FIELD(temp_r8_65, s32 *, 0x14);
            if (temp_f3_69 > (this->unk12C * *(this->unk134 + (temp_r3_103 * 0x14)))) {
                M2C_FIELD(temp_r8_65, s32 *, 0x14) = (s32) (temp_r3_103 + 1);
            }
            temp_r4_114 = M2C_FIELD(temp_r8_65, s32 *, 0x14);
            temp_r3_115 = this->unk134;
            temp_f6_117 = this->unk12C;
            temp_r6_118 = (temp_r4_114 - 1) * 0x14;
            temp_r5_120 = temp_r3_115 + temp_r6_118;
            temp_f5_122 = M2C_FIELD(temp_r5_120, f32 *, 0);
            temp_f3_129 = -((temp_f6_117 * temp_f5_122) - temp_f3_69) / (temp_f6_117 * (*(temp_r3_115 + (temp_r4_114 * 0x14)) - temp_f5_122));
            var_r7_62->unk1C = M2C_FIELD(temp_r8_65, f32 *, 0x20) * ((temp_f3_129 * M2C_FIELD(temp_r5_120, f32 *, 0xC)) + M2C_FIELD(temp_r5_120, f32 *, 4));
            var_f0_133 = var_r7_62->unk1C;
            if (var_f0_133 < 1.0f) {

            } else {
                var_f0_133 = 1.0f;
            }
            if (var_f0_133 > 0.0f) {

            } else {
                var_f0_133 = 0.0f;
            }
            var_r7_62->unk1C = var_f0_133;
            temp_r5_153 = this->unk134 + temp_r6_118;
            var_r7_62->unk28 = M2C_FIELD(temp_r8_65, f32 *, 0x1C) * ((temp_f3_129 * M2C_FIELD(temp_r5_153, f32 *, 0x10)) + M2C_FIELD(temp_r5_153, f32 *, 8));
            var_r7_62 = GetNextParticle(&unksp8);
        }
        goto loop_12;
    }
}
#endif

void MoltenMetalPS::Deinit() {
    MKParticleSystem::Deinit();
}

void MoltenMetalPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

#if 0 // DRAFT: undefined identifier 'gMoltenMetalPSEnv'
void MoltenMetalPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 10.5f;
    this->unkAC = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gMoltenMetalPSEnv, 5);
    SetMaxParticleAge(2.0f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}
#endif

void MoltenMetalPSDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
    this->unk80 = 1;
    this->unk84 = 1.0f / (f32) this->unk80;
}
