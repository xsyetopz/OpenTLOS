#include "spyro/source/CloudPS.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

f64 fmod(s32, f32, f32, f32);                       /* extern */
extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gCloudPSEnv;      /* unable to generate initializer: confusing struct layout */

void CloudPS::UpdateParticles() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    MKParticleChunk *var_r30_72;
    MKParticleSystem::Envelope *temp_r3_141;
    f32 temp_f30_79;
    f32 temp_f3_119;
    f32 temp_f3_155;
    f32 temp_f5_148;
    f32 temp_f6_143;
    f32 var_f0_159;
    s32 temp_r3_115;
    s32 temp_r3_129;
    s32 temp_r4_140;
    s32 temp_r6_144;
    void *temp_r29_75;
    void *temp_r5_146;
    void *temp_r5_179;

    this->unk128 += gUpdateTimeDelta;
    var_r30_72 = GetFirstParticle(&unksp8);
loop_12:
    if (var_r30_72 != NULL) {
        temp_r29_75 = var_r30_72->unk2C;
        temp_f30_79 = this->unk128 - M2C_FIELD(temp_r29_75, f32 *, 0x10);
        if (temp_f30_79 > this->unk12C) {
            var_r30_72 = DestroyParticle(&unksp8);
        } else {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp20 = sp10;
            sp18 = M2C_FIELD(temp_r29_75, f32 *, 8) * gUpdateTimeDelta;
            sp28 = (f64) sp18;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
            var_r30_72->unk8 += (f32) sp28;
            var_r30_72->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29_75, f32 *, 0x18);
            temp_r3_115 = M2C_FIELD(checked_cast<CloudPSDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x80);
            temp_f3_119 = var_r30_72->unk20;
            var_r30_72->unk20 = (f32) fmod(temp_r3_115, temp_f3_119 + this->unkF0, (f32) temp_r3_115, temp_f3_119);
            temp_r3_129 = M2C_FIELD(temp_r29_75, s32 *, 0x14);
            if (temp_f30_79 > (this->unk12C * *(this->unk134 + (temp_r3_129 * 0x14)))) {
                M2C_FIELD(temp_r29_75, s32 *, 0x14) = (s32) (temp_r3_129 + 1);
            }
            temp_r4_140 = M2C_FIELD(temp_r29_75, s32 *, 0x14);
            temp_r3_141 = this->unk134;
            temp_f6_143 = this->unk12C;
            temp_r6_144 = (temp_r4_140 - 1) * 0x14;
            temp_r5_146 = temp_r3_141 + temp_r6_144;
            temp_f5_148 = M2C_FIELD(temp_r5_146, f32 *, 0);
            temp_f3_155 = -((temp_f6_143 * temp_f5_148) - temp_f30_79) / (temp_f6_143 * (*(temp_r3_141 + (temp_r4_140 * 0x14)) - temp_f5_148));
            var_r30_72->unk1C = M2C_FIELD(temp_r29_75, f32 *, 0x20) * ((temp_f3_155 * M2C_FIELD(temp_r5_146, f32 *, 0xC)) + M2C_FIELD(temp_r5_146, f32 *, 4));
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
            temp_r5_179 = this->unk134 + temp_r6_144;
            var_r30_72->unk28 = M2C_FIELD(temp_r29_75, f32 *, 0x1C) * ((temp_f3_155 * M2C_FIELD(temp_r5_179, f32 *, 0x10)) + M2C_FIELD(temp_r5_179, f32 *, 8));
            var_r30_72 = GetNextParticle(&unksp8);
        }
        goto loop_12;
    }
}
#endif

void CloudPS::Deinit() {
    MKParticleSystem::Deinit();
}

void CloudPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

#if 0 // DRAFT: undefined identifier 'gCloudPSEnv'
void CloudPS::Init() {
    MKParticleSystem::Init();
    this->unk60.unk48 = 10.5f;
    this->unk60.unk4C = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gCloudPSEnv, 5);
    SetMaxParticleAge(5.0f);
    this->unk60.unk50 = 0.0f;
    this->unkF0 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CloudPSDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
    this->unk80 = 1;
    this->unk84 = 1.0f / (f32) this->unk80;
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<CloudPSDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
