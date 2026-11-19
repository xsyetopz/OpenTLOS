#include "spyro/source/StickyPS.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKVector3.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

void StickyPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, float arg3) {
    void *temp_r3_55;
    void *temp_r4_58;

    temp_r3_55 = CreateParticle();
    if (temp_r3_55 != NULL) {
        temp_r4_58 = M2C_FIELD(temp_r3_55, void **, 0x2C);
        M2C_FIELD(temp_r3_55, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_55, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_55, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_55, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r4_58, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r4_58, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r4_58, f32 *, 0x18) = arg2;
        M2C_FIELD(temp_r4_58, f32 *, 0x10) = arg3;
        M2C_FIELD(temp_r4_58, f32 *, 0x14) = (f32) this->unkF4;
        M2C_FIELD(temp_r4_58, s8 *, 0x1C) = 0;
    }
}

#if 0 // DRAFT: undefined identifier 'sp30'
void StickyPS::UpdateParticles() {
    s8 spD0;
    s32 spCC;
    s32 spC8;
    s32 spC4;
    f32 spC0;
    s32 spBC;
    s8 spBB;
    s8 spBA;
    s16 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    MKParticleChunk *var_r28_139;
    f32 temp_f0_253;
    f32 temp_f27_147;
    f32 temp_f2_259;
    f32 temp_f3_272;
    f32 temp_f4_267;
    s32 temp_r29_114;
    s32 var_r3_252;
    s32 var_r4_251;
    void *temp_r27_143;
    void *temp_r30_112;
    void *temp_r5_266;

    this->unkF4 += gUpdateTimeDelta;
    temp_r30_112 = this->unk0;
    temp_r29_114 = M2C_FIELD(temp_r30_112, s32 *, 0xD4);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */);
    sp70 = sp30;
    sp38 = M2C_FIELD(temp_r30_112, f32 *, 0xA8) * gUpdateTimeDelta;
    sp78 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
    sp60 = sp20;
    sp28 = M2C_FIELD(temp_r30_112, f32 *, 0xB8) * gUpdateTimeDelta;
    sp68 = (f64) sp28;
    var_r28_139 = GetFirstParticle(&unksp8);
loop_10:
    if (var_r28_139 != NULL) {
        temp_r27_143 = var_r28_139->unk2C;
        temp_f27_147 = this->unkF4 - M2C_FIELD(temp_r27_143, f32 *, 0x14);
        if (temp_f27_147 > M2C_FIELD(temp_r30_112, f32 *, 0xC8)) {
            var_r28_139 = DestroyParticle(&unksp8);
        } else {
            if ((u8) M2C_FIELD(temp_r27_143, u8 *, 0x1C) == 0) {
                sp50 = M2C_FIELD(var_r28_139, f64 *, 0);
                sp58 = M2C_FIELD(var_r28_139, f64 *, 8);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r28, 0x0, qr0 */);
                var_r28_139->unk8 += (f32) sp78;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                sp40 = sp10;
                sp18 = M2C_FIELD(temp_r27_143, f32 *, 8) * gUpdateTimeDelta;
                sp48 = (f64) sp18;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r28, 0x0, qr0 */);
                var_r28_139->unk8 += (f32) sp48;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r27, 0x0, qr0 */);
                M2C_FIELD(temp_r27_143, f32 *, 8) = (f32) (M2C_FIELD(temp_r27_143, f32 *, 8) * M2C_FIELD(temp_r30_112, f32 *, 0xC4));
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r27, 0x0, qr0 */);
                M2C_FIELD(temp_r27_143, f32 *, 8) = (f32) (M2C_FIELD(temp_r27_143, f32 *, 8) + (f32) sp68);
                var_r28_139->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r27_143, f32 *, 0x10);
                sp80 = 0.0f;
                sp84 = 0.0f;
                sp88 = 0.0f;
                sp90 = 0.0f;
                sp94 = 0.0f;
                sp98 = 0.0f;
                spA0 = 0.0f;
                spA4 = 0.0f;
                spA8 = 0.0f;
                spAC = 1.0f;
                spB0 = 0.0f;
                spB4 = 0.0f;
                spB8 = 0;
                spBA = 0;
                spBB = 0;
                spBC = 0;
                spC0 = 3.4028235e38f;
                spC4 = 0;
                spC8 = 0;
                spCC = -1;
                spD0 = 0;
                if (MKCollision_RayCollide(*((MKVector3 *) &sp50), *((MKVector3 *) var_r28_139), (MKCollisionResult *) &sp80, (MKCollisionMode) 7, 0x0C000000) != 0) {
                    M2C_FIELD(temp_r27_143, u8 *, 0x1C) = 1U;
                    M2C_FIELD(var_r28_139, f64 *, 0) = (f64) sp80;
                    M2C_FIELD(var_r28_139, f64 *, 8) = (f64) sp88;
                }
            }
            var_r4_251 = 1;
            var_r3_252 = 0x14;
            temp_f0_253 = temp_f27_147 / M2C_FIELD(temp_r30_112, f32 *, 0xC8);
loop_8:
            temp_f2_259 = *(temp_r29_114 + var_r3_252);
            if (temp_f0_253 > temp_f2_259) {
                var_r4_251 += 1;
                var_r3_252 += 0x14;
                goto loop_8;
            }
            temp_r5_266 = temp_r29_114 + ((var_r4_251 - 1) * 0x14);
            temp_f4_267 = M2C_FIELD(temp_r5_266, f32 *, 0);
            temp_f3_272 = (temp_f0_253 - temp_f4_267) / (temp_f2_259 - temp_f4_267);
            var_r28_139->unk1C = (temp_f3_272 * M2C_FIELD(temp_r5_266, f32 *, 0xC)) + M2C_FIELD(temp_r5_266, f32 *, 4);
            var_r28_139->unk28 = M2C_FIELD(temp_r27_143, f32 *, 0x18) * ((temp_f3_272 * M2C_FIELD(temp_r5_266, f32 *, 0x10)) + M2C_FIELD(temp_r5_266, f32 *, 8));
            var_r28_139 = GetNextParticle(&unksp8);
        }
        goto loop_10;
    }
}
#endif
