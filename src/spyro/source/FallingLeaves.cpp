#include "spyro/source/FallingLeaves.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/WindFX.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKParticleSystem::Envelope'
static MKParticleSystem::Envelope gFallingLeavesEnvelope; /* unable to generate initializer: confusing struct layout */

void FallingLeaves::Message(MKMessage *arg0) {
    s32 temp_r0_52;

    temp_r0_52 = arg0->unk0;
    switch (temp_r0_52) {                           /* irregular */
    case 0xB5:
        this->unk1E1 = 1;
        break;
    case 0xB4:
        this->unk1E1 = 0;
        break;
    }
    MKBaseParticleSystem::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spA0'
void FallingLeaves::Draw() {
    MKParticleChunk *var_r27_169;
    f32 temp_f18_339;
    f32 temp_f19_333;
    f32 temp_f1_118;
    f32 temp_f31_272;
    f32 temp_f3_116;
    f32 temp_f8_114;
    f32 temp_f9_120;
    f32 var_f22_117;
    f32 var_f23_113;
    s32 temp_r0_187;
    void *temp_r28_184;
    var_f23_113 = 0.0f;
    temp_f8_114 = this->unk60.unk48;
    temp_f3_116 = this->unk60.unk4C;
    var_f22_117 = 0.0f;
    temp_f1_118 = -temp_f8_114;
    arg_spA0 = 0.0f;
    temp_f9_120 = -temp_f3_116;
    arg_sp90 = 0.0f;
    arg_sp80 = 0.0f;
    arg_sp70 = 0.0f;
    arg_sp98 = temp_f1_118;
    arg_sp9C = temp_f3_116;
    arg_sp88 = temp_f1_118;
    arg_sp8C = temp_f9_120;
    arg_sp78 = temp_f8_114;
    arg_sp7C = temp_f3_116;
    arg_sp68 = temp_f8_114;
    arg_sp6C = temp_f9_120;
    arg_sp158 = (f64) arg_sp98;
    arg_sp160 = (f64) arg_spA0;
    arg_sp200 = (f64) arg_sp98;
    arg_sp208 = (f64) arg_spA0;
    arg_sp148 = (f64) arg_sp88;
    arg_sp150 = (f64) arg_sp90;
    arg_sp210 = (f64) arg_sp88;
    arg_sp218 = (f64) arg_sp90;
    arg_sp138 = (f64) arg_sp78;
    arg_sp140 = (f64) arg_sp80;
    arg_sp220 = (f64) arg_sp78;
    arg_sp228 = (f64) arg_sp80;
    arg_sp128 = (f64) arg_sp68;
    arg_sp130 = (f64) arg_sp70;
    arg_sp230 = (f64) arg_sp68;
    arg_sp238 = (f64) arg_sp70;
    MKMaterial_SetMaterial(M2C_FIELD(checked_cast<FallingLeavesDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x38));
    MKPrimitive(0xC, 0x10);
    var_r27_169 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) &arg_sp10);
    M2C_ERROR(/* unknown instruction: psq_lx $f29, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f27, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f25, $zero, $r28, 0x0, qr0 */);
loop_16:
    if (var_r27_169 != NULL) {
        temp_r28_184 = var_r27_169->unk2C;
        temp_r0_187 = (s32) var_r27_169->unk20;
        switch (temp_r0_187) {                      /* irregular */
        case 0:
            var_f23_113 = 0.0f;
            var_f22_117 = 0.0f;
            break;
        case 1:
            var_f23_113 = 0.5f;
            var_f22_117 = 0.0f;
            break;
        case 2:
            var_f23_113 = 0.0f;
            var_f22_117 = 0.5f;
            break;
        case 3:
            var_f23_113 = 0.5f;
            var_f22_117 = 0.5f;
            break;
        }
        arg_sp180.SetIdentity();
        if ((u8) M2C_FIELD(temp_r28_184, u8 *, 0x28) == 0) {
            arg_sp180.SetRotationPitch(0.017453292f * M2C_FIELD(temp_r28_184, f32 *, 0x24));
            arg_sp180.RotateYaw((Matrix *) &arg_sp180, 0.017453292f * var_r27_169->unk24);
            arg_sp1B0 = M2C_BITWISE(f32, var_r27_169->unk0);
            arg_sp1B4 = var_r27_169->unk4;
            arg_sp1B8 = var_r27_169->unk8;
            arg_sp1BC = 1.0f;
        } else {
            arg_spB8 = 0.0f;
            arg_spBC = 0.0f;
            arg_spC0 = 1.0f;
            arg_sp60 = 0.0f;
            arg_sp58 = 0.0f;
            arg_sp5C = 1.0f;
            arg_sp168 = (f64) arg_spB8;
            arg_sp170 = (f64) arg_spC0;
            M2C_FIELD(temp_r28_184, f64 *, 0x30) = (f64) arg_sp58;
            arg_sp118 = (f64) arg_sp58;
            arg_sp120 = (f64) arg_sp60;
            M2C_FIELD(temp_r28_184, f64 *, 0x38) = (f64) arg_sp60;
            KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp180, *(temp_r28_184 + 0x30), (MKVector3 *) &arg_sp168);
            arg_sp1B0 = M2C_BITWISE(f32, var_r27_169->unk0);
            arg_sp1B4 = var_r27_169->unk4;
            arg_sp1B8 = var_r27_169->unk8;
            arg_sp1BC = 1.0f;
        }
        temp_f31_272 = M2C_FIELD(temp_r28_184, f32 *, 0x18);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f2, $f29, $f31 */);
        arg_sp50 = (f32) arg_sp208 * temp_f31_272;
        arg_sp108 = arg_sp48;
        arg_sp110 = (f64) arg_sp50;
        arg_sp1C0 = arg_sp48;
        arg_sp1C8 = (f64) arg_sp50;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f2, $f27, $f31 */);
        arg_sp40 = (f32) arg_sp218 * temp_f31_272;
        arg_spF8 = arg_sp38;
        arg_sp100 = (f64) arg_sp40;
        arg_sp1D0 = arg_sp38;
        arg_sp1D8 = (f64) arg_sp40;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f2, $f25, $f31 */);
        arg_sp30 = (f32) arg_sp228 * temp_f31_272;
        arg_spE8 = arg_sp28;
        arg_spF0 = (f64) arg_sp30;
        arg_sp1E0 = arg_sp28;
        arg_sp1E8 = (f64) arg_sp30;
        arg_sp20 = (f32) arg_sp238 * temp_f31_272;
        arg_spD8 = arg_sp18;
        arg_spE0 = (f64) arg_sp20;
        arg_sp1F0 = arg_sp18;
        arg_sp1F8 = (f64) arg_sp20;
        MKSetMatrix(*((Matrix *) &arg_sp180));
        MKBegin(4);
        arg_spA8 = 0.5f;
        arg_spAC = 0.5f;
        arg_spB0 = 0.5f;
        arg_spB4 = 1.0f;
        arg_spC8 = (f64) arg_spA8;
        arg_spD0 = (f64) arg_spB0;
        MKSetColorV(*((MKVector4 *) &arg_spC8));
        MKSetTexCoord1F(var_f23_113, var_f22_117);
        MKSetPositionV(*((MKVector3 *) &arg_sp1C0));
        temp_f19_333 = 0.5f + var_f22_117;
        MKSetTexCoord1F(var_f23_113, temp_f19_333);
        MKSetPositionV(*((MKVector3 *) &arg_sp1D0));
        temp_f18_339 = 0.5f + var_f23_113;
        MKSetTexCoord1F(temp_f18_339, var_f22_117);
        MKSetPositionV(*((MKVector3 *) &arg_sp1E0));
        MKSetTexCoord1F(temp_f18_339, temp_f19_333);
        MKSetPositionV(*((MKVector3 *) &arg_sp1F0));
        MKEnd();
        var_r27_169 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) &arg_sp10);
        goto loop_16;
    }
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'FallingLeaves' to
void FallingLeaves::AddForce(const MKVector3 &arg0, const float &arg1, const float &arg2) {
    s32 var_ctr_400;
    s32 var_r7_399;
    void *temp_r3_406;

    var_r7_399 = 0;
    var_ctr_400 = 4;
loop_1:
    if ((u8) *(this + (var_r7_399 + 0x178)) == 0) {
        temp_r3_406 = this + var_r7_399;
        M2C_FIELD(temp_r3_406, s8 *, 0x178) = 1;
        M2C_FIELD(temp_r3_406, f64 *, 0x160) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_406, f64 *, 0x168) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_406, f32 *, 0x170) = (f32) &arg1;
        M2C_FIELD(temp_r3_406, f32 *, 0x174) = (f32) &arg2;
        return;
    }
    var_r7_399 += 0x20;
    var_ctr_400 -= 1;
    if (var_ctr_400 == 0) {
        return;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp108'
void FallingLeaves::UpdateParticles() {
    MKParticleChunk *var_r31_467;
    f32 temp_f0_689;
    f32 temp_f1_594;
    f32 temp_f1_674;
    f32 temp_f1_688;
    f32 temp_f23_659;
    f32 temp_f23_933;
    f32 temp_f23_965;
    f32 temp_f24_931;
    f32 temp_f25_550;
    f32 temp_f25_938;
    f32 temp_f29_548;
    f32 temp_f2_473;
    f32 temp_f30_517;
    f32 temp_f3_474;
    f32 temp_f4_736;
    f32 var_f0_572;
    f32 var_f3_904;
    f32 var_f4_837;
    f64 temp_f1_843;
    f64 temp_f1_849;
    f64 temp_f1_853;
    s32 temp_r3_872;
    s32 var_r0_882;
    s32 var_r27_807;
    s32 var_r29_806;
    void *temp_r30_470;
    void *temp_r4_809;
    arg_sp108 = 0.0f;
    arg_sp100 = 0.0f;
    arg_sp104 = 0.0f;
    arg_sp228 = (f64) arg_sp108;
    arg_sp220 = (f64) arg_sp100;
    this->unk128 += gUpdateTimeDelta;
    var_r31_467 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) &arg_sp18);
loop_51:
    if (var_r31_467 != NULL) {
        temp_r30_470 = var_r31_467->unk2C;
        temp_f2_473 = this->unk12C;
        temp_f3_474 = this->unk128 - M2C_FIELD(temp_r30_470, f32 *, 0x10);
        if (temp_f3_474 > temp_f2_473) {
            var_r31_467 = DestroyParticle((MKBaseParticleSystem::ParticleRec *) &arg_sp18);
        } else {
            if (temp_f3_474 > (0.75f * temp_f2_473)) {
                M2C_FIELD(temp_r30_470, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r30_470, f32 *, 0x18) * 0.75f);
            }
            if ((u8) M2C_FIELD(temp_r30_470, u8 *, 0x28) == 0) {
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                arg_sp1E0 = arg_sp80;
                arg_sp88 = M2C_FIELD(temp_r30_470, f32 *, 8) * gUpdateTimeDelta;
                arg_sp1E8 = (f64) arg_sp88;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r31, 0x0, qr0 */);
                var_r31_467->unk8 += (f32) arg_sp1E8;
                temp_f30_517 = gUpdateTimeDelta;
                arg_sp1C0.operator*(MKRand_Float(&gViewSeed, 0.0f, 0.25f));
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                arg_sp1D0 = arg_sp70;
                arg_sp78 = arg_sp1C8 * temp_f30_517;
                arg_sp1D8 = (f64) arg_sp78;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
                M2C_FIELD(temp_r30_470, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_470, f32 *, 8) + (f32) arg_sp1D8);
                temp_f29_548 = gUpdateTimeDelta;
                temp_f25_550 = 1.0f - (M2C_FIELD(temp_r30_470, f32 *, 0x24) / 90.0f);
                MKVector(0.0f, -200.0f * temp_f25_550, 0.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                arg_sp1B0 = arg_sp60;
                arg_sp68 = arg_sp1A8 * temp_f29_548;
                arg_sp1B8 = (f64) arg_sp68;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
                M2C_FIELD(temp_r30_470, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_470, f32 *, 8) + (f32) arg_sp1B8);
                var_f0_572 = M2C_FIELD(temp_r30_470, f32 *, 4);
                if (var_f0_572 < 1000.0f) {

                } else {
                    var_f0_572 = 1000.0f;
                }
                if (var_f0_572 > -200.0f) {

                } else {
                    var_f0_572 = -200.0f;
                }
                M2C_FIELD(temp_r30_470, f32 *, 4) = var_f0_572;
                var_r31_467->unk24 += M2C_FIELD(temp_r30_470, f32 *, 0x14) * gUpdateTimeDelta;
                temp_f1_594 = var_r31_467->unk24;
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if (temp_f1_594 == 360.0f) {
                    var_r31_467->unk24 = temp_f1_594 - 360.0f;
                }
                arg_sp230.SetIdentity();
                arg_sp230.RotateYaw((Matrix *) &arg_sp230, 0.017453292f * var_r31_467->unk24);
                arg_spF0 = 0.0f;
                arg_spF4 = 0.0f;
                arg_spF8 = 1.0f;
                arg_sp210 = (f64) arg_spF0;
                arg_sp218 = (f64) arg_spF8;
                arg_sp14 = 1.0f - temp_f25_550;
                arg_sp50 = arg_sp260 + (((f32) arg_sp218 * arg_sp250) + (((f32) arg_sp210 * arg_sp230) + (arg_sp214 * arg_sp240)));
                arg_sp54 = arg_sp264 + (((f32) arg_sp218 * arg_sp254) + (((f32) arg_sp210 * arg_sp234) + (arg_sp214 * arg_sp244)));
                arg_sp58 = arg_sp268 + (((f32) arg_sp218 * arg_sp258) + (((f32) arg_sp210 * arg_sp238) + (arg_sp214 * arg_sp248)));
                arg_sp190 = (f64) arg_sp50;
                arg_sp198 = (f64) arg_sp58;
                arg_sp210 = (f64) arg_sp50;
                arg_sp218 = (f64) arg_sp58;
                temp_f23_659 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                temp_f1_674 = (f32) arg_sp218 * (gUpdateTimeDelta * (2000.0f * temp_f23_659 * Clamp<float>(0.25f, arg_sp14, 0.5f)));
                arg_sp180 = arg_sp40;
                arg_sp48 = temp_f1_674;
                arg_sp188 = (f64) arg_sp48;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
                M2C_FIELD(temp_r30_470, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_470, f32 *, 8) + (f32) arg_sp188);
            }
            temp_f1_688 = var_r31_467->unk4;
            temp_f0_689 = M2C_FIELD(temp_r30_470, f32 *, 0x20);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if ((temp_f1_688 == temp_f0_689) && ((u8) M2C_FIELD(temp_r30_470, u8 *, 0x28) == 0)) {
                arg_spC0 = 0.0f;
                arg_spC4 = -1500.0f;
                arg_spC8 = 0.0f;
                arg_sp270 = 0.0f;
                arg_sp274 = 0.0f;
                arg_sp278 = 0.0f;
                arg_sp280 = 0.0f;
                arg_sp284 = 0.0f;
                arg_sp288 = 0.0f;
                arg_sp290 = 0.0f;
                arg_sp294 = 0.0f;
                arg_sp298 = 0.0f;
                arg_sp29C = 1.0f;
                arg_sp2A0 = 0.0f;
                arg_sp2A4 = 0.0f;
                arg_sp2A8 = 0;
                arg_sp2A8 = 0;
                (s8) arg_sp2A8 = 0;
                arg_sp2AC = 0;
                arg_sp2B0 = 3.4028235e38f;
                arg_sp2B4 = 0;
                arg_sp2B8 = 0;
                arg_sp2BC = -1;
                arg_sp2C0 = 0;
                arg_sp140 = (f64) arg_spC0;
                arg_sp148 = (f64) arg_spC8;
                M2C_ERROR(/* unknown instruction: psq_lx $f5, $zero, $r31, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
                arg_spE8 = 0.0f;
                temp_f4_736 = var_r31_467->unk8;
                arg_spE0 = 0.0f;
                arg_spE4 = 500.0f;
                arg_spB8 = temp_f4_736 + (f32) arg_sp148;
                arg_sp160 = (f64) arg_spE0;
                arg_sp150 = arg_spB0;
                arg_sp158 = (f64) arg_spB8;
                arg_sp168 = (f64) arg_spE8;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
                arg_sp170 = arg_spD0;
                arg_spD8 = temp_f4_736 + (f32) arg_sp168;
                arg_sp178 = (f64) arg_spD8;
                if (MKCollision_RayCollide(*((MKVector3 *) &arg_sp170), *((MKVector3 *) &arg_sp150), (MKCollisionResult *) &arg_sp270, (MKCollisionMode) 4, 1) != 0) {
                    M2C_FIELD(temp_r30_470, f32 *, 0x20) = (f32) (5.0f + arg_sp274);
                    M2C_FIELD(temp_r30_470, f64 *, 0x30) = (f64) arg_sp280;
                    M2C_FIELD(temp_r30_470, f64 *, 0x38) = (f64) arg_sp288;
                } else {
                    arg_sp30 = 0.0f;
                    arg_sp34 = 1.0f;
                    arg_sp38 = 0.0f;
                    M2C_FIELD(temp_r30_470, f64 *, 0x30) = (f64) arg_sp30;
                    arg_sp130 = (f64) arg_sp30;
                    arg_sp138 = (f64) arg_sp38;
                    M2C_FIELD(temp_r30_470, f64 *, 0x38) = (f64) arg_sp38;
                }
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (var_r31_467->unk4 == M2C_FIELD(temp_r30_470, f32 *, 0x20)) {
                    M2C_FIELD(temp_r30_470, u8 *, 0x28) = 1U;
                    var_r31_467->unk4 = M2C_FIELD(temp_r30_470, f32 *, 0x20);
                }
            } else if (temp_f1_688 > temp_f0_689) {
                M2C_FIELD(temp_r30_470, u8 *, 0x28) = 0U;
            }
            var_r29_806 = 0;
            var_r27_807 = 0;
            do {
                temp_r4_809 = this + var_r27_807;
                if (((u8) M2C_FIELD(temp_r4_809, u8 *, 0x178) != 0) && ((u8) M2C_FIELD(temp_r30_470, u8 *, 0x28) != 0)) {
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r4, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp200 = arg_spA0;
                    arg_spA8 = var_r31_467->unk8 - M2C_FIELD(temp_r4_809, f32 *, 0x168);
                    arg_sp208 = (f64) arg_spA8;
                    var_f4_837 = ((f32) arg_sp208 * (f32) arg_sp208) + (((f32) arg_sp200 * (f32) arg_sp200) + (arg_sp204 * arg_sp204));
                    if (var_f4_837 > 0.000001f) {
                        if (var_f4_837 > 0.0f) {
                            temp_f1_843 = __frsqrte(var_f4_837);
                            temp_f1_849 = 0.5 * temp_f1_843 * -(((f64) var_f4_837 * (temp_f1_843 * temp_f1_843)) - 3.0);
                            temp_f1_853 = 0.5 * temp_f1_849 * -(((f64) var_f4_837 * (temp_f1_849 * temp_f1_849)) - 3.0);
                            var_f4_837 = (f32) ((f64) var_f4_837 * (0.5 * temp_f1_853 * -(((f64) var_f4_837 * (temp_f1_853 * temp_f1_853)) - 3.0)));
                        } else if (var_f4_837 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_837 = __float_nan;
                        } else {
                            arg_sp10 = var_f4_837;
                            temp_r3_872 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                            switch (temp_r3_872) {  /* irregular */
                            case 0x7F800000:
                                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                    var_r0_882 = 1;
                                } else {
                                    var_r0_882 = 2;
                                }
                                break;
                            case 0x0:
                                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                    var_r0_882 = 5;
                                } else {
                                    var_r0_882 = 3;
                                }
                                break;
                            default:
                                var_r0_882 = 4;
                                break;
                            }
                            if (var_r0_882 == 1) {
                                var_f4_837 = __float_nan;
                            }
                        }
                        var_f3_904 = 1.0f / var_f4_837;
                    } else {
                        var_f3_904 = 0.0f;
                        var_f4_837 = 0.0f;
                    }
                    arg_sp200 = (f32) arg_sp200 * var_f3_904;
                    arg_sp204 *= var_f3_904;
                    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                    if (var_f4_837 == M2C_FIELD(temp_r4_809, f32 *, 0x170)) {
                        M2C_FIELD(temp_r30_470, f32 *, 0x24) = MKRand_Float(&gViewSeed, 7.5f, 85.0f);
                        temp_f24_931 = 1.0f - (M2C_FIELD(temp_r30_470, f32 *, 0x24) / 90.0f);
                        temp_f23_933 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        temp_f25_938 = MKRand_Float(&gViewSeed, 0.0f, 0.1f);
                        arg_sp90 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        arg_sp94 = temp_f25_938;
                        arg_sp98 = temp_f23_933;
                        arg_sp1F0 = (f64) arg_sp90;
                        arg_sp1F8 = (f64) arg_sp98;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                        M2C_FIELD(temp_r30_470, f64 *, 0) = arg_sp1F0;
                        arg_sp1F8 = (f32) arg_sp1F8 * 25.0f;
                        M2C_FIELD(temp_r30_470, f32 *, 8) = arg_sp1F8;
                        temp_f23_965 = MKRand_Float(&gViewSeed, -0.5f, 0.5f);
                        MKVector(MKRand_Float(&gViewSeed, -0.5f, 0.5f), 1.0f, temp_f23_965);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                        arg_sp120 = arg_sp20;
                        arg_sp28 = arg_sp118 * 300.0f;
                        arg_sp128 = (f64) arg_sp28;
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
                        M2C_FIELD(temp_r30_470, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_470, f32 *, 8) + (f32) arg_sp128);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
                        M2C_FIELD(temp_r30_470, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_470, f32 *, 8) * temp_f24_931);
                        M2C_FIELD(temp_r30_470, u8 *, 0x28) = 0U;
                    }
                }
                var_r29_806 += 1;
                var_r27_807 += 0x20;
            } while (var_r29_806 < 4);
            var_r31_467 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) &arg_sp18);
        }
        goto loop_51;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp8'
void FallingLeaves::ApplyWind(WindFX *arg0) {
    WindFX sp70;
    M2C_UNK sp60;
    f64 sp58;
    f64 sp50;
    M2C_UNK sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    MKParticleChunk *var_r31_1079;
    f32 temp_f27_1161;
    f32 temp_f28_1159;
    f32 temp_f29_1090;
    f32 temp_f31_1120;
    void *temp_r30_1082;

    var_r31_1079 = GetFirstParticle(&unksp8);
loop_6:
    if (var_r31_1079 != NULL) {
        temp_r30_1082 = var_r31_1079->unk2C;
        if ((u8) M2C_FIELD(temp_r30_1082, u8 *, 0x28) == 0) {
            temp_f29_1090 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
            sp70.GetVelocity(*((MKVector3 *) arg0));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            sp70.unk10 = sp20;
            sp28 = (f32) sp70.unk8 * temp_f29_1090;
            sp70.unk18 = (f64) sp28;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_FIELD(temp_r30_1082, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_1082, f32 *, 8) + (f32) sp70.unk18);
        } else {
            temp_f31_1120 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
            sp60.GetVelocity(*((MKVector3 *) arg0));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp70.unk20 = sp30;
            sp38 = sp68 * temp_f31_1120;
            sp70.unk28 = (f64) sp38;
            if ((((f32) sp70.unk28 * (f32) sp70.unk28) + (((f32) sp70.unk20 * (f32) sp70.unk20) + (unksp94 * unksp94))) != 0.0f) {
                M2C_FIELD(temp_r30_1082, f32 *, 0x24) = MKRand_Float(&gViewSeed, 7.5f, 85.0f);
                temp_f28_1159 = 1.0f - (M2C_FIELD(temp_r30_1082, f32 *, 0x24) / 90.0f);
                temp_f27_1161 = MKRand_Float(&gViewSeed, -0.5f, 0.5f);
                MKVector(MKRand_Float(&gViewSeed, -0.5f, 0.5f), 1.0f, temp_f27_1161);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                sp50 = sp10;
                sp18 = sp48 * 300.0f;
                sp58 = (f64) sp18;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
                M2C_FIELD(temp_r30_1082, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_1082, f32 *, 8) + (f32) sp58);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
                M2C_FIELD(temp_r30_1082, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_1082, f32 *, 8) * temp_f28_1159);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
                M2C_FIELD(temp_r30_1082, f32 *, 8) = (f32) (M2C_FIELD(temp_r30_1082, f32 *, 8) + (f32) sp70.unk28);
                M2C_FIELD(temp_r30_1082, u8 *, 0x28) = 0U;
            }
        }
        var_r31_1079 = GetNextParticle(&unksp8);
        goto loop_6;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp4C'
void FallingLeaves::Update() {
    s32 temp_r0_1326;
    s32 var_ctr_1324;
    s32 var_r3_1321;
    void *temp_r3_1247;
    if ((u8) this->unk1E1 != 0) {
        temp_r3_1247 = this->unk8;
        this->unk140 = M2C_FIELD(temp_r3_1247, f64 *, 0x30);
        this->unk148 = M2C_FIELD(temp_r3_1247, f64 *, 0x38);
    }
    M2C_STRUCT_COPY((s32) &arg_sp4C + 4, M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), s32 *, 8) - 4 + 4, 0x40);
    arg_sp30 = arg_sp70;
    arg_sp40 = arg_sp80;
    arg_sp48 = arg_sp88;
    arg_sp38 = arg_sp78;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_sp20 = arg_sp10;
    arg_sp18 = (f32) arg_sp38 * 50.0f;
    arg_sp28 = (f64) arg_sp18;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp48 = (f32) arg_sp48 + (f32) arg_sp28;
    arg_sp44 -= 20.0f;
    AddForce(*((MKVector3 *) &arg_sp40), 50.0f, 200.0f);
    UpdateParticles();
    if ((u8) this->unk1E1 != 0) {
        Emit();
        SpawnGround(*((MKVector3 *) &this->unk140));
    }
    var_r3_1321 = 0;
    var_ctr_1324 = 4;
    do {
        temp_r0_1326 = var_r3_1321 + 0x178;
        var_r3_1321 += 0x20;
        *(this + temp_r0_1326) = 0;
        var_ctr_1324 -= 1;
    } while (var_ctr_1324 != 0);
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void FallingLeaves::SpawnGround(const MKVector3 &arg0) {
    MKCollisionResult spD8;
    f64 spD0;                                       /* compiler-managed */
    f64 spC8;
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;
    f64 spB0;
    f64 spA8;
    M2C_UNK sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    M2C_UNK sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_f1_1423;
    f32 temp_f27_1397;
    f32 temp_f28_1367;
    f32 temp_f29_1372;
    f32 temp_f3_1465;
    f64 temp_f30_1359;
    f64 temp_f31_1361;
    void *temp_r30_1432;
    void *temp_r3_1429;

    temp_f30_1359 = M2C_FIELD(&arg0, f64 *, 0);
    temp_f31_1361 = M2C_FIELD(&arg0, f64 *, 8);
    temp_f28_1367 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
    temp_f29_1372 = MKRand_Float(&gViewSeed, 0.0f, 0.1f);
    sp48 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
    sp4C = temp_f29_1372;
    sp50 = temp_f28_1367;
    spC8 = (f64) sp48;
    spD0 = (f64) sp50;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
    spB8 = temp_f30_1359;
    spC0 = temp_f31_1361;
    spD0 = (f32) spD0 * 25.0f;
    temp_f27_1397 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
    MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), 0.0f, temp_f27_1397);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
    spA8 = sp18;
    sp20 = spA0 * 500.0f;
    spB0 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    temp_f1_1423 = (f32) spC0;
    spC0 = temp_f1_1423 + (f32) spB0;
    temp_r3_1429 = CreateParticle(temp_f1_1423);
    if (temp_r3_1429 != NULL) {
        temp_r30_1432 = M2C_FIELD(temp_r3_1429, void **, 0x2C);
        M2C_FIELD(temp_r3_1429, f64 *, 0) = spB8;
        M2C_FIELD(temp_r3_1429, f64 *, 8) = (f64) spC0;
        M2C_FIELD(temp_r30_1432, f64 *, 0) = spC8;
        M2C_FIELD(temp_r30_1432, f64 *, 8) = (f64) spD0;
        M2C_FIELD(temp_r30_1432, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.1f, 0.25f);
        M2C_FIELD(temp_r30_1432, f32 *, 0x1C) = 1.0f;
        M2C_FIELD(temp_r30_1432, f32 *, 0x24) = MKRand_Float(&gViewSeed, 7.5f, 85.0f);
        temp_f3_1465 = (f32) MKRand_Int(&gViewSeed, 0, 4);
        sp40 = 0.0f;
        M2C_FIELD(temp_r3_1429, f32 *, 0x20) = temp_f3_1465;
        sp38 = 0.0f;
        sp3C = 500.0f;
        sp80 = (f64) sp40;
        sp78 = (f64) sp38;
        M2C_FIELD(temp_r30_1432, f32 *, 0x14) = (f32) (500.0f * (1.0f - (M2C_FIELD(temp_r30_1432, f32 *, 0x24) / 90.0f)));
        M2C_FIELD(temp_r30_1432, f32 *, 0x20) = unkspBC;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp88 = sp28;
        sp30 = spC0 + (f32) sp80;
        sp90 = (f64) sp30;
        if (MKCollision_GetGroundPoint(*((MKVector3 *) &sp88), 3000.0f, &spD8, 0, 2, NULL, (MKCollisionMode) 6) != 0) {
            M2C_FIELD(temp_r30_1432, f32 *, 0x20) = (f32) (10.0f + spD8.unk4);
            MKVector(0.0f, 10.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_FIELD(temp_r3_1429, f64 *, 0) = sp8;
            sp10 = spD8.unk8 + sp60;
            sp68 = sp8;
            M2C_FIELD(temp_r3_1429, f64 *, 8) = (f64) sp10;
            sp70 = (f64) sp10;
            M2C_FIELD(temp_r30_1432, f64 *, 0x30) = (f64) spD8.unk10;
            M2C_FIELD(temp_r30_1432, f64 *, 0x38) = (f64) spD8.unk18;
        }
        M2C_FIELD(temp_r30_1432, s8 *, 0x28) = 1;
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void FallingLeaves::Emit() {
    MKCollisionResult spC8;
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;
    f64 spB0;                                       /* compiler-managed */
    f64 spA8;
    f64 spA0;
    f64 sp98;
    M2C_UNK sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f28_1577;
    f32 temp_f28_1609;
    f32 temp_f29_1582;
    s32 var_r29_1571;
    void *temp_r28_1651;
    void *temp_r3_1648;

    var_r29_1571 = 0;
    do {
        temp_f28_1577 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f29_1582 = MKRand_Float(&gViewSeed, 0.0f, 0.1f);
        sp48 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp4C = temp_f29_1582;
        sp50 = temp_f28_1577;
        spB8 = (f64) sp48;
        spC0 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        spA8 = this->unk140;
        spC0 = (f32) spC0 * 25.0f;
        spB0 = this->unk148;
        temp_f28_1609 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), 0.0f, temp_f28_1609);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp98 = sp18;
        sp20 = sp90 * 700.0f;
        spA0 = (f64) sp20;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spB0 = (f32) spB0 + (f32) spA0;
        unkspAC += MKRand_Float(&gViewSeed, 725.0f, 800.0f);
        temp_r3_1648 = CreateParticle();
        if (temp_r3_1648 != NULL) {
            temp_r28_1651 = M2C_FIELD(temp_r3_1648, void **, 0x2C);
            M2C_FIELD(temp_r3_1648, f64 *, 0) = spA8;
            M2C_FIELD(temp_r3_1648, f64 *, 8) = (f64) spB0;
            M2C_FIELD(temp_r28_1651, f64 *, 0) = spB8;
            M2C_FIELD(temp_r28_1651, f64 *, 8) = (f64) spC0;
            M2C_FIELD(temp_r28_1651, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.1f, 0.25f);
            M2C_FIELD(temp_r28_1651, f32 *, 0x1C) = 1.0f;
            M2C_FIELD(temp_r28_1651, f32 *, 0x24) = MKRand_Float(&gViewSeed, 7.5f, 85.0f);
            M2C_FIELD(temp_r3_1648, f32 *, 0x20) = (f32) MKRand_Int(&gViewSeed, 0, 4);
            M2C_FIELD(temp_r3_1648, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 270.0f);
            sp10 = 0.0f;
            sp40 = 0.0f;
            sp8 = 0.0f;
            spC = 1.0f;
            M2C_FIELD(temp_r28_1651, f32 *, 0x14) = (f32) (500.0f * (1.0f - (M2C_FIELD(temp_r28_1651, f32 *, 0x24) / 90.0f)));
            M2C_FIELD(temp_r28_1651, f64 *, 0x30) = (f64) sp8;
            M2C_FIELD(temp_r28_1651, f64 *, 0x38) = (f64) sp10;
            sp38 = 0.0f;
            sp3C = 500.0f;
            sp78 = (f64) sp8;
            sp58 = (f64) sp38;
            sp80 = (f64) sp10;
            M2C_FIELD(temp_r28_1651, f32 *, 0x20) = unkspAC;
            sp60 = (f64) sp40;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp68 = sp28;
            sp30 = spB0 + (f32) sp60;
            sp70 = (f64) sp30;
            if (MKCollision_GetGroundPoint(*((MKVector3 *) &sp68), 3000.0f, &spC8, 0, 2, NULL, (MKCollisionMode) 6) != 0) {
                M2C_FIELD(temp_r28_1651, f32 *, 0x20) = (f32) (10.0f + spC8.unk4);
                M2C_FIELD(temp_r28_1651, f64 *, 0x30) = (f64) spC8.unk10;
                M2C_FIELD(temp_r28_1651, f64 *, 0x38) = (f64) spC8.unk18;
            }
            M2C_FIELD(temp_r28_1651, s8 *, 0x28) = 0;
        }
        var_r29_1571 += 1;
    } while (var_r29_1571 < 0xA);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void FallingLeaves::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, const int &arg3, bool arg4) {
    s8 sp128;
    s32 sp124;
    s32 sp120;
    s32 sp11C;
    f32 sp118;
    s32 sp114;
    s8 sp113;
    s8 sp112;
    s16 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f64 spD0;
    f64 spC8;
    M2C_UNK spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f4_1905;
    void *temp_r30_1788;
    void *temp_r3_1785;

    temp_r3_1785 = M2C_FIELD(this->__vptr, void *(**)(), 0x3C)();
    if (temp_r3_1785 != NULL) {
        temp_r30_1788 = M2C_FIELD(temp_r3_1785, void **, 0x2C);
        M2C_FIELD(temp_r3_1785, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_1785, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r30_1788, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r30_1788, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r30_1788, f32 *, 0x18) = (f32) &arg2;
        M2C_FIELD(temp_r30_1788, f32 *, 0x1C) = 1.0f;
        M2C_FIELD(temp_r30_1788, f32 *, 0x24) = MKRand_Float(&gViewSeed, 7.5f, 55.0f);
        M2C_FIELD(temp_r3_1785, f32 *, 0x20) = (f32) &arg3;
        MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        MKVector(1.0f, 1.0f, 1.0f, 1.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_FIELD(temp_r3_1785, f64 *, 0x10) = sp18;
        spC8 = sp18;
        spD0 = sp20;
        M2C_FIELD(temp_r3_1785, f64 *, 0x18) = sp20;
        M2C_FIELD(temp_r3_1785, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 270.0f);
        sp10 = 0.0f;
        sp8 = 0.0f;
        spC = 1.0f;
        spB0 = (f64) sp10;
        spA8 = (f64) sp8;
        M2C_FIELD(temp_r30_1788, f32 *, 0x14) = (f32) (500.0f * (1.0f - (M2C_FIELD(temp_r30_1788, f32 *, 0x24) / 90.0f)));
        M2C_FIELD(temp_r30_1788, f64 *, 0x30) = (f64) sp8;
        M2C_FIELD(temp_r30_1788, f64 *, 0x38) = (f64) sp10;
        M2C_FIELD(temp_r30_1788, f32 *, 0x20) = (f32) (arg0.unk4 - 200000.0f);
        if (arg4 != 0) {
            sp40 = 0.0f;
            sp38 = 0.0f;
            sp3C = -3000.0f;
            spD8 = 0.0f;
            sp68 = (f64) sp38;
            spDC = 0.0f;
            spE0 = 0.0f;
            spE8 = 0.0f;
            spEC = 0.0f;
            spF0 = 0.0f;
            spF8 = 0.0f;
            spFC = 0.0f;
            sp100 = 0.0f;
            sp104 = 1.0f;
            sp108 = 0.0f;
            sp10C = 0.0f;
            sp110 = 0;
            sp112 = 0;
            sp113 = 0;
            sp114 = 0;
            sp118 = 3.4028235e38f;
            sp11C = 0;
            sp120 = 0;
            sp124 = -1;
            sp128 = 0;
            sp70 = (f64) sp40;
            M2C_ERROR(/* unknown instruction: psq_lx $f5, $zero, $r25, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
            temp_f4_1905 = arg0.unk8;
            sp60 = 0.0f;
            sp58 = 0.0f;
            sp5C = 500.0f;
            sp30 = temp_f4_1905 + (f32) sp70;
            sp88 = (f64) sp58;
            sp78 = sp28;
            sp80 = (f64) sp30;
            sp90 = (f64) sp60;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
            sp98 = sp48;
            sp50 = temp_f4_1905 + (f32) sp90;
            spA0 = (f64) sp50;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp98), *((MKVector3 *) &sp78), (MKCollisionResult *) &spD8, (MKCollisionMode) 4, 1) != 0) {
                M2C_FIELD(temp_r30_1788, f32 *, 0x20) = (f32) (10.0f + spDC);
                M2C_FIELD(temp_r30_1788, f64 *, 0x30) = (f64) spE8;
                M2C_FIELD(temp_r30_1788, f64 *, 0x38) = (f64) spF0;
            }
        }
        M2C_FIELD(temp_r30_1788, s8 *, 0x28) = 0;
    }
}
#endif

void FallingLeaves::Deinit() {
    MKParticleSystem::Deinit();
}

void FallingLeaves::Resolve() {
    MKProp::Resolve();
}

void FallingLeaves::LoadDone() {
    MKBaseParticleSystem::LoadDone();
}

#if 0 // DRAFT: undefined identifier 'gFallingLeavesEnvelope'
void FallingLeaves::Init() {
    s32 temp_r0_2027;
    s32 var_ctr_2025;
    s32 var_r3_2022;

    MKParticleSystem::Init();
    this->unk60.unk48 = 15.0f;
    this->unk60.unk4C = 15.0f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(&gFallingLeavesEnvelope, 5);
    SetMaxParticleAge(10.0f);
    var_r3_2022 = 0;
    var_ctr_2025 = 4;
    do {
        temp_r0_2027 = var_r3_2022 + 0x178;
        var_r3_2022 += 0x20;
        *(this + temp_r0_2027) = 0;
        var_ctr_2025 -= 1;
    } while (var_ctr_2025 != 0);
    this->unk1E0 = 1;
    this->unk1E1 = 0;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FallingLeavesDescriptor::Init() {
    MKBaseParticleSystemDescriptor::Init();
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FallingLeavesDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif

void FallingLeaves_cpp::__sinit() {
    f32 temp_f0_2096;
    f64 temp_f1_2077;
    f64 temp_f1_2085;
    f64 temp_f3_2065;
    f64 temp_f4_2074;
    f64 temp_f4_2082;
    f64 temp_f8_2067;

    temp_f3_2065 = __frsqrte(2014000.0);
    temp_f8_2067 = __frsqrte(380000.0);
    temp_f4_2074 = 0.5 * temp_f3_2065 * -((2014000.0 * (temp_f3_2065 * temp_f3_2065)) - 3.0);
    temp_f1_2077 = 0.5 * temp_f8_2067 * -((380000.0 * (temp_f8_2067 * temp_f8_2067)) - 3.0);
    temp_f4_2082 = 0.5 * temp_f4_2074 * -((2014000.0 * (temp_f4_2074 * temp_f4_2074)) - 3.0);
    temp_f1_2085 = 0.5 * temp_f1_2077 * -((380000.0 * (temp_f1_2077 * temp_f1_2077)) - 3.0);
    temp_f0_2096 = (f32) (380000.0 * (0.5 * temp_f1_2085 * -((380000.0 * (temp_f1_2085 * temp_f1_2085)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_2082 * -((2014000.0 * (temp_f4_2082 * temp_f4_2082)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_2096;
}
