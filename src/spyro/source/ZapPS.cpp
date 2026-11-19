#include "spyro/source/ZapPS.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gZapPSEnv;        /* unable to generate initializer: confusing struct layout */

void ZapPS::UpdateParticles() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    MKParticleChunk *var_r31_64;
    MKParticleSystem::Envelope *temp_r3_108;
    f32 temp_f30_71;
    f32 temp_f3_122;
    f32 temp_f5_115;
    f32 temp_f6_110;
    f32 var_f0_126;
    s32 temp_r4_107;
    s32 temp_r6_111;
    void *temp_r30_67;
    void *temp_r5_113;
    void *temp_r5_146;

    this->unk128 += gUpdateTimeDelta;
    var_r31_64 = GetFirstParticle(&unksp8);
loop_10:
    if (var_r31_64 != NULL) {
        temp_r30_67 = var_r31_64->unk2C;
        temp_f30_71 = this->unk128 - M2C_FIELD(temp_r30_67, f32 *, 0x10);
        if (temp_f30_71 > this->unk12C) {
            var_r31_64 = DestroyParticle(&unksp8);
        } else {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp20 = sp10;
            sp18 = M2C_FIELD(temp_r30_67, f32 *, 8) * gUpdateTimeDelta;
            sp28 = (f64) sp18;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r31, 0x0, qr0 */);
            var_r31_64->unk8 += (f32) sp28;
            var_r31_64->unk24 = 2.0f * MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
            temp_r4_107 = M2C_FIELD(temp_r30_67, s32 *, 0x14);
            temp_r3_108 = this->unk134;
            temp_f6_110 = this->unk12C;
            temp_r6_111 = (temp_r4_107 - 1) * 0x14;
            temp_r5_113 = temp_r3_108 + temp_r6_111;
            temp_f5_115 = M2C_FIELD(temp_r5_113, f32 *, 0);
            temp_f3_122 = -((temp_f6_110 * temp_f5_115) - temp_f30_71) / (temp_f6_110 * (*(temp_r3_108 + (temp_r4_107 * 0x14)) - temp_f5_115));
            var_r31_64->unk1C = M2C_FIELD(temp_r30_67, f32 *, 0x20) * ((temp_f3_122 * M2C_FIELD(temp_r5_113, f32 *, 0xC)) + M2C_FIELD(temp_r5_113, f32 *, 4));
            var_f0_126 = var_r31_64->unk1C;
            if (var_f0_126 < 1.0f) {

            } else {
                var_f0_126 = 1.0f;
            }
            if (var_f0_126 > 0.0f) {

            } else {
                var_f0_126 = 0.0f;
            }
            var_r31_64->unk1C = var_f0_126;
            temp_r5_146 = this->unk134 + temp_r6_111;
            var_r31_64->unk28 = M2C_FIELD(temp_r30_67, f32 *, 0x1C) * ((temp_f3_122 * M2C_FIELD(temp_r5_146, f32 *, 0x10)) + M2C_FIELD(temp_r5_146, f32 *, 8));
            var_r31_64 = GetNextParticle(&unksp8);
        }
        goto loop_10;
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Int(long *, int, int)' does not match
void ZapPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, MKVector4 arg3) {
    void *temp_r30_185;
    void *temp_r3_182;

    temp_r3_182 = CreateParticle();
    if (temp_r3_182 != NULL) {
        temp_r30_185 = M2C_FIELD(temp_r3_182, void **, 0x2C);
        M2C_FIELD(temp_r3_182, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_182, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_182, f32 *, 0x20) = (f32) MKRand_Int(&gViewSeed, 0, 3);
        M2C_FIELD(temp_r30_185, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r30_185, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r30_185, f32 *, 0x1C) = (f32) &arg2;
        M2C_FIELD(temp_r30_185, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r30_185, f32 *, 0x18) = (f32) (2.0f * MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f));
        M2C_FIELD(temp_r3_182, f64 *, 0x10) = (f64) M2C_FIELD(arg3, f64 *, 0);
        M2C_FIELD(temp_r3_182, f64 *, 0x18) = (f64) M2C_FIELD(arg3, f64 *, 8);
        M2C_FIELD(temp_r3_182, f32 *, 0x24) = (f32) (2.0f * MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f));
    }
}
#endif

void ZapPS::Deinit() {
    MKParticleSystem::Deinit();
}

void ZapPS::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

#if 0 // DRAFT: undefined identifier 'gZapPSEnv'
void ZapPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 10.5f;
    this->unkAC = 10.5f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gZapPSEnv, 5);
    SetMaxParticleAge(0.5f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ZapPSDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
    this->unk80 = 1;
    this->unk84 = 1.0f / (f32) this->unk80;
}
#endif
