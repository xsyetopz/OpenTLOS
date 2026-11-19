#include "spyro/source/SuckeyPS.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKVector3.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gSuckeyPSEnv;     /* unable to generate initializer: confusing struct layout */

void SuckeyPS::UpdateParticles() {
    f64 sp38;
    f64 sp30;
    MKVector3 sp20;
    f32 sp18;
    MKParticleChunk *var_r30_77;
    MKParticleSystem::Envelope *temp_r3_141;
    f32 temp_f2_82;
    f32 temp_f30_84;
    f32 temp_f3_154;
    f32 temp_f4_147;
    f32 temp_f5_143;
    f32 var_f0_157;
    f32 var_f0_95;
    s32 temp_r3_128;
    s32 temp_r4_140;
    s32 temp_r6_144;
    void *temp_r29_80;
    void *temp_r5_145;
    void *temp_r5_177;

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
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_FIELD(var_r30_77, f64 *, 0) = sp10;
            sp18 = M2C_FIELD(temp_r29_80, f32 *, 0x18) + sp20.unk8;
            sp30 = sp10;
            M2C_FIELD(var_r30_77, f64 *, 8) = (f64) sp18;
            temp_r3_128 = M2C_FIELD(temp_r29_80, s32 *, 0x28);
            sp38 = (f64) sp18;
            if (temp_f30_84 > (this->unk12C * *(this->unk134 + (temp_r3_128 * 0x14)))) {
                M2C_FIELD(temp_r29_80, s32 *, 0x28) = (s32) (temp_r3_128 + 1);
            }
            temp_r4_140 = M2C_FIELD(temp_r29_80, s32 *, 0x28);
            temp_r3_141 = this->unk134;
            temp_f5_143 = this->unk12C;
            temp_r6_144 = (temp_r4_140 - 1) * 0x14;
            temp_r5_145 = temp_r3_141 + temp_r6_144;
            temp_f4_147 = M2C_FIELD(temp_r5_145, f32 *, 0);
            temp_f3_154 = -((temp_f5_143 * temp_f4_147) - temp_f30_84) / (temp_f5_143 * (*(temp_r3_141 + (temp_r4_140 * 0x14)) - temp_f4_147));
            var_r30_77->unk1C = (temp_f3_154 * M2C_FIELD(temp_r5_145, f32 *, 0xC)) + M2C_FIELD(temp_r5_145, f32 *, 4);
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
            temp_r5_177 = this->unk134 + temp_r6_144;
            var_r30_77->unk28 = M2C_FIELD(temp_r29_80, f32 *, 0x2C) * ((temp_f3_154 * M2C_FIELD(temp_r5_177, f32 *, 0x10)) + M2C_FIELD(temp_r5_177, f32 *, 8));
            var_r30_77 = GetNextParticle(&unksp8);
        }
        goto loop_18;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
void SuckeyPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, float arg3) {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    void *temp_r30_220;
    void *temp_r3_215;

    temp_r3_215 = CreateParticle();
    if (temp_r3_215 != NULL) {
        temp_r30_220 = M2C_FIELD(temp_r3_215, void **, 0x2C);
        sp18 = 1.0f;
        sp1C = 1.0f;
        sp20 = 1.0f;
        sp24 = 1.0f;
        M2C_FIELD(temp_r3_215, f64 *, 0x10) = (f64) sp18;
        M2C_FIELD(temp_r3_215, f64 *, 0x18) = (f64) sp20;
        M2C_FIELD(temp_r30_220, f64 *, 0x10) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r30_220, f64 *, 0x18) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_215, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r30_220, s32 *, 0x28) = 1;
        M2C_FIELD(temp_r30_220, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r30_220, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r30_220, f32 *, 0x2C) = (f32) &arg2;
        M2C_FIELD(temp_r30_220, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r30_220, f32 *, 0x24) = arg3;
        sp48 = (f64) sp18;
        sp50 = (f64) sp20;
        sp28.operator*(M2C_FIELD(temp_r30_220, f32 *, 0x20));
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(temp_r3_215, f64 *, 0) = sp8;
        sp10 = (f32) M2C_FIELD(temp_r30_220, f64 *, 0x18) + sp28.unk8;
        sp38 = sp8;
        sp40 = (f64) sp10;
        M2C_FIELD(temp_r3_215, f64 *, 8) = (f64) sp10;
        M2C_FIELD(temp_r3_215, f32 *, 0x24) = (f32) (2.0f * MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f));
        M2C_FIELD(temp_r3_215, f32 *, 0x28) = (f32) M2C_FIELD(temp_r30_220, f32 *, 0x2C);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'gSuckeyPSEnv'
void SuckeyPS::Init() {
    MKParticleSystem::Init();
    this->unkA8 = 5.0f;
    this->unkAC = 5.0f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gSuckeyPSEnv, 5);
    SetMaxParticleAge(10.0f);
    this->unkB0 = 0.0f;
    this->unkF0 = 0.0f;
    this->unk140 = 0;
}
#endif
