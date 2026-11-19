#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKBaseParticleSystem.h"
#include <m2c_macros.h>

f64 fmod(f32, f32, f32);                            /* extern */
extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gDefaultEnvelope; /* unable to generate initializer: confusing struct layout */

void MKParticleSystem::SetMaxParticleAge(float arg0) {
    this->unk12C = arg0;
    CalculateEnvelope();
}
#endif

#if 0 // DRAFT: undefined identifier 'fabs'
void *MKParticleSystem::HitFloor(MKBaseParticleSystem::ParticleRec *arg1, bool *arg2) {
    f32 temp_f1_27;
    f32 temp_f2_30;
    void *temp_r5_28;
    void *temp_r6_32;

    *arg2 = 0;
    temp_f1_27 = this->unk11C;
    temp_r5_28 = M2C_FIELD(arg1, void **, 4);
    temp_f2_30 = M2C_FIELD(temp_r5_28, f32 *, 4);
    temp_r6_32 = M2C_FIELD(temp_r5_28, void **, 0x2C);
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (temp_f2_30 == (temp_f1_27 - this->unk120)) {
        M2C_FIELD(temp_r5_28, f32 *, 4) = temp_f1_27;
        M2C_FIELD(temp_r6_32, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r6_32, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r6_32, f32 *, 8) = 0.0f;
    } else {
        M2C_FIELD(temp_r5_28, f32 *, 4) = (f32) (temp_f1_27 + (temp_f1_27 - temp_f2_30));
        M2C_FIELD(temp_r6_32, f32 *, 4) = (f32) (this->unk124 * (f32) fabs(M2C_FIELD(temp_r6_32, f32 *, 4)));
    }
    return M2C_FIELD(arg1, void **, 4);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp38'
void MKParticleSystem::UpdateParticles() {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    u8 sp8;
    MKParticleChunk *var_r30_113;
    MKParticleSystem::Envelope *temp_r3_201;
    f32 temp_f26_121;
    f32 temp_f27_85;
    f32 temp_f3_215;
    f32 temp_f5_208;
    f32 temp_f6_203;
    f32 var_f0_219;
    s32 temp_r3_189;
    s32 temp_r4_200;
    s32 temp_r6_204;
    void *temp_r29_117;
    void *temp_r31_84;
    void *temp_r3_238;
    void *temp_r5_206;

    this->unk128 += gUpdateTimeDelta;
    temp_r31_84 = this->unk0;
    temp_f27_85 = gUpdateTimeDelta * this->unkF0;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r28, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */);
    sp68 = sp38;
    sp40 = this->unk100 * gUpdateTimeDelta;
    sp70 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r28, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */);
    sp58 = sp28;
    sp30 = this->unk110 * gUpdateTimeDelta;
    sp60 = (f64) sp30;
    if ((u8) this->unkF4 == 0) {
        var_r30_113 = GetFirstParticle(&unkspC);
loop_16:
        if (var_r30_113 != NULL) {
            temp_r29_117 = var_r30_113->unk2C;
            temp_f26_121 = this->unk128 - M2C_FIELD(temp_r29_117, f32 *, 0x10);
            if (temp_f26_121 > this->unk12C) {
                var_r30_113 = DestroyParticle(&unkspC);
            } else {
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
                var_r30_113->unk8 += (f32) sp70;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                sp48 = sp18;
                sp20 = M2C_FIELD(temp_r29_117, f32 *, 8) * gUpdateTimeDelta;
                sp50 = (f64) sp20;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
                var_r30_113->unk8 += (f32) sp50;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_FIELD(temp_r29_117, f32 *, 8) = (f32) (M2C_FIELD(temp_r29_117, f32 *, 8) * this->unk118);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_FIELD(temp_r29_117, f32 *, 8) = (f32) (M2C_FIELD(temp_r29_117, f32 *, 8) + (f32) sp60);
                var_r30_113->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29_117, f32 *, 0x18);
                var_r30_113->unk20 = (f32) fmod(var_r30_113->unk20 + temp_f27_85, (f32) M2C_FIELD(temp_r31_84, s32 *, 0x80), gUpdateTimeDelta);
                temp_r3_189 = M2C_FIELD(temp_r29_117, s32 *, 0x14);
                if (temp_f26_121 > (this->unk12C * *(this->unk134 + (temp_r3_189 * 0x14)))) {
                    M2C_FIELD(temp_r29_117, s32 *, 0x14) = (s32) (temp_r3_189 + 1);
                }
                temp_r4_200 = M2C_FIELD(temp_r29_117, s32 *, 0x14);
                temp_r3_201 = this->unk134;
                temp_f6_203 = this->unk12C;
                temp_r6_204 = (temp_r4_200 - 1) * 0x14;
                temp_r5_206 = temp_r3_201 + temp_r6_204;
                temp_f5_208 = M2C_FIELD(temp_r5_206, f32 *, 0);
                temp_f3_215 = -((temp_f6_203 * temp_f5_208) - temp_f26_121) / (temp_f6_203 * (*(temp_r3_201 + (temp_r4_200 * 0x14)) - temp_f5_208));
                var_r30_113->unk1C = M2C_FIELD(temp_r29_117, f32 *, 0x20) * ((temp_f3_215 * M2C_FIELD(temp_r5_206, f32 *, 0xC)) + M2C_FIELD(temp_r5_206, f32 *, 4));
                var_f0_219 = var_r30_113->unk1C;
                if (var_f0_219 < 1.0f) {

                } else {
                    var_f0_219 = 1.0f;
                }
                if (var_f0_219 > 0.0f) {

                } else {
                    var_f0_219 = 0.0f;
                }
                var_r30_113->unk1C = var_f0_219;
                temp_r3_238 = this->unk134 + temp_r6_204;
                var_r30_113->unk28 = M2C_FIELD(temp_r29_117, f32 *, 0x1C) * ((temp_f3_215 * M2C_FIELD(temp_r3_238, f32 *, 0x10)) + M2C_FIELD(temp_r3_238, f32 *, 8));
                sp8 = 0;
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (var_r30_113->unk4 == this->unk11C) {
                    var_r30_113 = HitFloor(&unkspC, &sp8);
                }
                if (sp8 == 0) {
                    var_r30_113 = GetNextParticle(&unkspC);
                }
            }
            goto loop_16;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void MKParticleSystem::CalculateEnvelope() {
    MKParticleSystem::Envelope *temp_r5_300;
    MKParticleSystem::Envelope *temp_r5_310;
    f32 temp_f0_313;
    s32 temp_r5_319;
    s32 temp_r7_301;
    s32 temp_r9_295;
    s32 var_ctr_296;
    s32 var_r4_294;
    s32 var_r8_293;
    void *temp_r6_303;
    void *temp_r6_311;

    var_r8_293 = 0;
    var_r4_294 = 0;
    temp_r9_295 = this->unk130 - 1;
    var_ctr_296 = temp_r9_295;
    if (temp_r9_295 > 0) {
        do {
            temp_r5_300 = this->unk134;
            temp_r7_301 = (var_r8_293 + 1) * 0x14;
            var_r8_293 += 1;
            temp_r6_303 = temp_r5_300 + var_r4_294;
            M2C_FIELD(temp_r6_303, f32 *, 0xC) = (f32) (*(temp_r5_300 + (temp_r7_301 + 4)) - M2C_FIELD(temp_r6_303, f32 *, 4));
            temp_r5_310 = this->unk134;
            temp_r6_311 = temp_r5_310 + var_r4_294;
            temp_f0_313 = M2C_FIELD(temp_r6_311, f32 *, 8);
            var_r4_294 += 0x14;
            M2C_FIELD(temp_r6_311, f32 *, 0x10) = (f32) (*(temp_r5_310 + (temp_r7_301 + 8)) - temp_f0_313);
            var_ctr_296 -= 1;
        } while (var_ctr_296 != 0);
    }
    temp_r5_319 = temp_r9_295 * 0x14;
    M2C_FIELD((this->unk134 + temp_r5_319), f32 *, 0xC) = 0.0f;
    M2C_FIELD((this->unk134 + temp_r5_319), f32 *, 0x10) = 0.0f;
}
#endif

void MKParticleSystem::SetEnvelope(MKParticleSystem::Envelope *arg1, int arg2) {
    this->unk134 = arg1;
    this->unk130 = arg2;
    CalculateEnvelope();
}

void *MKParticleSystem::CreateParticle() {
    void *temp_r3_353;
    void *temp_r4_368;

    temp_r3_353 = MKBaseParticleSystem::CreateParticle();
    if (temp_r3_353 == NULL) {
        return NULL;
    }
    M2C_FIELD(temp_r3_353, f32 *, 0x1C) = (f32) M2C_FIELD(this->unk134, f32 *, 4);
    M2C_FIELD(temp_r3_353, f32 *, 0x28) = (f32) M2C_FIELD(this->unk134, f32 *, 8);
    temp_r4_368 = M2C_FIELD(temp_r3_353, void **, 0x2C);
    M2C_FIELD(temp_r4_368, f32 *, 0x10) = (f32) this->unk128;
    M2C_FIELD(temp_r4_368, f32 *, 0) = 0.0f;
    M2C_FIELD(temp_r4_368, f32 *, 4) = 0.0f;
    M2C_FIELD(temp_r4_368, f32 *, 8) = 0.0f;
    M2C_FIELD(temp_r4_368, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r4_368, f32 *, 0x18) = 0.0f;
    M2C_FIELD(temp_r4_368, f32 *, 0x1C) = 1.0f;
    M2C_FIELD(temp_r4_368, f32 *, 0x20) = 1.0f;
    return temp_r3_353;
}

void MKParticleSystem::Deinit() {
    MKBaseParticleSystem::Deinit();
}

#if 0 // DRAFT: undefined identifier 'gDefaultEnvelope'
void MKParticleSystem::Init() {
    MKBaseParticleSystem::Init();
    this->unk128 = 0.0f;
    this->unkF0 = 0.0f;
    this->unkF4 = 0;
    this->unk12C = 10.0f;
    this->unkF8 = 0.0f;
    this->unkFC = 0.0f;
    this->unk100 = 0.0f;
    this->unk108 = 0.0f;
    this->unk10C = -4000.0f;
    this->unk110 = 0.0f;
    this->unk118 = 0.99999f;
    this->unk11C = -1e12f;
    this->unk120 = 0.0f;
    this->unk124 = 0.75f;
    SetEnvelope(&gDefaultEnvelope, 2);
}
#endif
