#include "spyro/source/Character.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CharacterDescriptor.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/KDSynkerPlayer2Messages.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/SB2.h"
#include "unplaced_templates.h"
#include "common/Source/MKWind.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/PropFlags.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(MKCollisionInfo *);                    /* extern */
MKCollisionInfo *malloc(M2C_UNK);                   /* extern */
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'unk58C'
static s8 lit_stringBase0[0x39] = {
    0x62,
    0x53,
    0x79,
    0x6E,
    0x6B,
    0x65,
    0x72,
    0x4C,
    0x6F,
    0x6F,
    0x6B,
    0x41,
    0x74,
    0,
    0x62,
    0x53,
    0x79,
    0x6E,
    0x6B,
    0x65,
    0x72,
    0x41,
    0x6E,
    0x69,
    0x6D,
    0x61,
    0x74,
    0x65,
    0,
    0x70,
    0x6C,
    0x61,
    0x74,
    0x66,
    0x6F,
    0x72,
    0x6D,
    0x49,
    0x44,
    0,
    0x62,
    0x44,
    0x72,
    0x61,
    0x77,
    0x49,
    0x6E,
    0x43,
    0x75,
    0x74,
    0x73,
    0x63,
    0x65,
    0x6E,
    0x65,
    0x73,
    0,
}; /* const */

void Character::UpdateSpeed() {
    f32 temp_f1_29;
    f32 temp_f1_32;
    f32 temp_f3_30;
    f32 var_f2_22;

    var_f2_22 = 0.5f * (2.0f * gUpdateTimeDelta);
    if (var_f2_22 < 1.0f) {

    } else {
        var_f2_22 = 1.0f;
    }
    temp_f1_29 = this->unk110.unk58C;
    temp_f3_30 = this->unk110.unk590;
    temp_f1_32 = (var_f2_22 * (temp_f3_30 - temp_f1_29)) + temp_f1_29;
    this->unk110.unk58C = (var_f2_22 * (temp_f3_30 - temp_f1_32)) + temp_f1_32;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk590'
void Character::SetDesiredSpeed(float arg0) {
    this->unk110.unk590 = arg0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk530'
u8 Character::IsSteeringEnabled() {
    SB2 *temp_r4_49;

    temp_r4_49 = this->unk110.unk530;
    if ((temp_r4_49 != NULL) && (((u8) temp_r4_49->unk464 >> 7U) & 1)) {
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: ')' expected
void Character::UpdateCollisionItems() {
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp20;
    f32 sp10;
    s32 temp_r0_70;

    temp_r0_70 = M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x6C);
    switch (temp_r0_70) {                           /* irregular */
    case 0:
        sp48.operator*(M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x60));
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        this->unk60 = sp18;
        sp20 = this->unk110.unk480 + sp48.unk8;
        sp58 = sp18;
        this->unk68 = (f64) sp20;
        sp60 = (f64) sp20;
        sp28.operator*(M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x64));
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        this->unk70 = sp8;
        sp10 = this->unk110.unk480 + sp28.unk8;
        sp38 = sp8;
        sp40 = (f64) sp10;
        this->unk78 = (f64) sp10;
        return;
    case 1:
        this->unk60 = this->unk110.unk478;
        this->unk68 = (f64) M2C_FIELD(this, f32 *, 0x590);
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkF4'
void Character::GetDesiredHeadingMatrix(Matrix *arg0) {
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f11_155;
    f32 temp_f8_153;
    f32 temp_f9_160;
    f32 var_f3_254;
    f32 var_f4_187;
    f64 temp_f1_193;
    f64 temp_f1_199;
    f64 temp_f1_203;
    s32 temp_r3_222;
    s32 var_r0_232;

    sp40 = -this->unkE0;
    temp_f8_153 = this->unkF8;
    sp44 = -this->unkE4;
    temp_f11_155 = this->unkF0;
    sp48 = -this->unkE8;
    sp50 = (f64) sp40;
    temp_f9_160 = this->unkF4;
    sp58 = (f64) sp48;
    sp98 = M2C_FIELD(this, f64 *, 0xF8);
    sp90 = M2C_FIELD(this, f64 *, 0xF0);
    sp34 = (temp_f8_153 * (f32) sp50) - (temp_f11_155 * (f32) sp58);
    sp30 = (temp_f9_160 * (f32) sp58) - (temp_f8_153 * unksp54);
    sp38 = (temp_f11_155 * unksp54) - (temp_f9_160 * (f32) sp50);
    sp60 = (f64) sp30;
    sp68 = (f64) sp38;
    var_f4_187 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (unksp64 * unksp64));
    if (var_f4_187 > 1e-12f) {
        if (var_f4_187 > 0.0f) {
            temp_f1_193 = __frsqrte(var_f4_187);
            temp_f1_199 = 0.5 * temp_f1_193 * -(((f64) var_f4_187 * (temp_f1_193 * temp_f1_193)) - 3.0);
            temp_f1_203 = 0.5 * temp_f1_199 * -(((f64) var_f4_187 * (temp_f1_199 * temp_f1_199)) - 3.0);
            var_f4_187 = (f32) ((f64) var_f4_187 * (0.5 * temp_f1_203 * -(((f64) var_f4_187 * (temp_f1_203 * temp_f1_203)) - 3.0)));
        } else if (var_f4_187 < M2C_BITWISE(f32, 0.0)) {
            var_f4_187 = __float_nan;
        } else {
            sp8 = var_f4_187;
            temp_r3_222 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_222) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_232 = 1;
                } else {
                    var_r0_232 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_232 = 5;
                } else {
                    var_r0_232 = 3;
                }
                break;
            default:
                var_r0_232 = 4;
                break;
            }
            if (var_r0_232 == 1) {
                var_f4_187 = __float_nan;
            }
        }
        var_f3_254 = 1.0f / var_f4_187;
    } else {
        var_f3_254 = 0.0f;
    }
    sp24 = unksp64 * var_f3_254;
    sp20 = (f32) sp60 * var_f3_254;
    sp28 = (f32) sp68 * var_f3_254;
    sp80 = (f64) sp20;
    sp88 = (f64) sp28;
    sp18 = ((f32) sp80 * unksp94) - (unksp84 * (f32) sp90);
    sp10 = (unksp84 * (f32) sp98) - ((f32) sp88 * unksp94);
    sp14 = ((f32) sp88 * (f32) sp90) - ((f32) sp80 * (f32) sp98);
    sp78 = (f64) sp18;
    sp70 = (f64) sp10;
    arg0->SetIdentity();
    arg0->unk0 = (f32) sp80;
    arg0->unk4 = unksp84;
    arg0->unk8 = (f32) sp88;
    arg0->unkC = 0.0f;
    arg0->unk10 = (f32) sp90;
    arg0->unk14 = unksp94;
    arg0->unk18 = (f32) sp98;
    arg0->unk1C = 0.0f;
    arg0->unk20 = (f32) sp70;
    arg0->unk24 = unksp74;
    arg0->unk28 = (f32) sp78;
    arg0->unk2C = 0.0f;
}
#endif

#if 0 // DRAFT: function call 'operator*(float, MKVector3)' does not match
void Character::ClearHorizForces() {
    MKVector3 sp8;
    f32 temp_f1_346;

    temp_f1_346 = (f32) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r3 */) >> 0x1FU);
    if (temp_f1_346 < 0.0f) {
        this->unkA0 = 0.0f;
        this->unkA4 = 0.0f;
        this->unkA8 = 0.0f;
        return;
    }
    __ml(temp_f1_346, sp8);
    M2C_FIELD(this, f32 *, 0xA0) = M2C_BITWISE(f64, sp8);
    M2C_FIELD(this, f32 *, 0xA8) = (f64) sp8.unk8;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CharacterMoveType'
void Character::SetMovementType(CharacterMoveType arg0) {
    s32 temp_r0_378;

    temp_r0_378 = this->unk110.unk578;
    if ((temp_r0_378 != (s32) arg0) && (temp_r0_378 == 1)) {
        M2C_FIELD(this->unk110.__vptr, M2C_UNK (**)(CollisionObject *, f64 *, M2C_UNK, f32), 0x14)(&this->unk110, &this->unk110.unk478, 0xA, 1.0f);
    }
    this->unk110.unk578 = (s32) arg0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void Character::ResetCloth() {
    s16 temp_r31_411;
    s32 var_r30_412;

    temp_r31_411 = MKModel_GetNmbrOfSubObjects(this->unk4, (SubObjectType) 2);
    var_r30_412 = 0;
loop_2:
    if (var_r30_412 < temp_r31_411) {
        ((MKCloth *) (MKModel_GetClothSubObject(this->unk4, var_r30_412)))->Reset();
        var_r30_412 += 1;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk57C'
void Character::UpdateRotation() {
    f64 sp138;
    f64 sp130;
    f64 sp120;
    MKVector3 sp110;
    MKVector3 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f31_442;
    f32 temp_f3_603;
    f32 temp_f5_601;
    f32 temp_f6_480;
    f32 temp_f7_484;
    f32 temp_f7_606;
    f32 temp_f9_482;
    f32 var_f3_580;
    f32 var_f4_513;
    f64 temp_f1_519;
    f64 temp_f1_525;
    f64 temp_f1_529;
    s32 temp_r3_548;
    s32 var_r0_558;

    temp_f31_442 = this->unk110.unk57C * gUpdateTimeDelta;
    if (IsSteeringEnabled() != 0) {
        sp120.Calculate((u32) this->unk110.unk530);
        M2C_FIELD(this, f64 *, 0xE0) = sp120;
        M2C_FIELD(this, f64 *, 0xE8) = sp128;
    }
    KDMath_Slerp(sp110, *((MKVector3 *) &this->unkC0), temp_f31_442);
    M2C_FIELD(this, f64 *, 0xC0) = M2C_BITWISE(f64, sp110);
    M2C_FIELD(this, f64 *, 0xC8) = (f64) sp110.unk8;
    KDMath_Slerp(sp100, *((MKVector3 *) &this->unkD0), temp_f31_442);
    M2C_FIELD(this, f64 *, 0xD0) = M2C_BITWISE(f64, sp100);
    M2C_FIELD(this, f64 *, 0xD8) = (f64) sp100.unk8;
    temp_f6_480 = this->unkD8;
    temp_f9_482 = this->unkD0;
    sp70 = -this->unkC0;
    temp_f7_484 = this->unkD4;
    sp74 = -this->unkC4;
    sp78 = -this->unkC8;
    spE0 = (f64) sp70;
    spE8 = (f64) sp78;
    sp60 = (temp_f7_484 * (f32) spE8) - (temp_f6_480 * unkspE4);
    sp64 = (temp_f6_480 * (f32) spE0) - (temp_f9_482 * (f32) spE8);
    sp68 = (temp_f9_482 * unkspE4) - (temp_f7_484 * (f32) spE0);
    spF0 = (f64) sp60;
    spF8 = (f64) sp68;
    var_f4_513 = ((f32) spF8 * (f32) spF8) + (((f32) spF0 * (f32) spF0) + (unkspF4 * unkspF4));
    if (var_f4_513 > 1e-12f) {
        if (var_f4_513 > 0.0f) {
            temp_f1_519 = __frsqrte(var_f4_513);
            temp_f1_525 = 0.5 * temp_f1_519 * -(((f64) var_f4_513 * (temp_f1_519 * temp_f1_519)) - 3.0);
            temp_f1_529 = 0.5 * temp_f1_525 * -(((f64) var_f4_513 * (temp_f1_525 * temp_f1_525)) - 3.0);
            var_f4_513 = (f32) ((f64) var_f4_513 * (0.5 * temp_f1_529 * -(((f64) var_f4_513 * (temp_f1_529 * temp_f1_529)) - 3.0)));
        } else if (var_f4_513 < M2C_BITWISE(f32, 0.0)) {
            var_f4_513 = __float_nan;
        } else {
            sp8 = var_f4_513;
            temp_r3_548 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_548) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_558 = 1;
                } else {
                    var_r0_558 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_558 = 5;
                } else {
                    var_r0_558 = 3;
                }
                break;
            default:
                var_r0_558 = 4;
                break;
            }
            if (var_r0_558 == 1) {
                var_f4_513 = __float_nan;
            }
        }
        var_f3_580 = 1.0f / var_f4_513;
    } else {
        var_f3_580 = 0.0f;
    }
    sp54 = unkspF4 * var_f3_580;
    sp50 = (f32) spF0 * var_f3_580;
    sp58 = (f32) spF8 * var_f3_580;
    sp130 = (f64) sp50;
    sp138 = (f64) sp58;
    if (((u8) this->unk110.unk5A5 >> 6U) & 1) {
        temp_f5_601 = this->unkD0;
        temp_f3_603 = this->unkD8;
        temp_f7_606 = this->unkD4;
        sp18 = ((f32) sp130 * temp_f7_606) - (unksp134 * temp_f5_601);
        sp14 = ((f32) sp138 * temp_f5_601) - ((f32) sp130 * temp_f3_603);
        sp10 = (unksp134 * temp_f3_603) - ((f32) sp138 * temp_f7_606);
        spB8 = (f64) sp18;
        spB0 = (f64) sp10;
        Normalise(spC0);
        sp40 = -M2C_BITWISE(f32, spC0);
        sp44 = -spC0.unk4;
        sp48 = -spC0.unk8;
        M2C_FIELD(this, f64 *, 0xC0) = (f64) sp40;
        spD0 = (f64) sp40;
        spD8 = (f64) sp48;
        M2C_FIELD(this, f64 *, 0xC8) = (f64) sp48;
        return;
    }
    sp30 = -this->unkC0;
    sp34 = -this->unkC4;
    sp38 = -this->unkC8;
    sp80 = (f64) sp30;
    sp88 = (f64) sp38;
    sp28 = ((f32) sp80 * unksp134) - (unksp84 * (f32) sp130);
    sp20 = (unksp84 * (f32) sp138) - ((f32) sp88 * unksp134);
    sp24 = ((f32) sp88 * (f32) sp130) - ((f32) sp80 * (f32) sp138);
    sp98 = (f64) sp28;
    sp90 = (f64) sp20;
    Normalise(spA0);
    M2C_FIELD(this, f64 *, 0xD0) = M2C_BITWISE(f64, spA0);
    M2C_FIELD(this, f64 *, 0xD8) = (f64) spA0.unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk490'
MKVector3 *Character::UpdateVelocity() {
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    MKVector3 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f0_741;
    f32 temp_f1_740;
    f32 temp_f29_888;
    f32 temp_f30_860;
    f32 temp_f4_742;
    f32 temp_f4_938;
    f32 temp_f5_940;
    f32 temp_f6_944;
    f32 var_f4_748;
    f64 temp_f1_751;
    f64 temp_f1_757;
    f64 temp_f1_761;
    s32 var_r0_790;
    u8 var_r3_705;

    var_r3_705 = IsSteeringEnabled();
    if (var_r3_705 == 0) {
        var_r3_705 = 0x598;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r3, 0x0, qr0 */);
        this->unk110.unk490 += this->unk98;
    } else if (this->unk110.unk590 > 0.0f) {
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
        this->unk110.unk488 = sp60;
        sp68 = this->unk98 * (1.0f / gUpdateTimeDelta);
        spF0 = sp60;
        M2C_FIELD(this, f32 *, 0x5A0) = (f64) sp68;
        temp_f1_740 = (f32) M2C_FIELD(this, f64 *, 0x598);
        temp_f0_741 = M2C_FIELD(this, f32 *, 0x59C);
        temp_f4_742 = this->unk110.unk490;
        spF8 = (f64) sp68;
        var_f4_748 = (temp_f4_742 * temp_f4_742) + ((temp_f1_740 * temp_f1_740) + (temp_f0_741 * temp_f0_741));
        if (var_f4_748 > 0.0f) {
            temp_f1_751 = __frsqrte(var_f4_748);
            temp_f1_757 = 0.5 * temp_f1_751 * -(((f64) var_f4_748 * (temp_f1_751 * temp_f1_751)) - 3.0);
            temp_f1_761 = 0.5 * temp_f1_757 * -(((f64) var_f4_748 * (temp_f1_757 * temp_f1_757)) - 3.0);
            var_f4_748 = (f32) ((f64) var_f4_748 * (0.5 * temp_f1_761 * -(((f64) var_f4_748 * (temp_f1_761 * temp_f1_761)) - 3.0)));
        } else if (var_f4_748 < M2C_BITWISE(f32, 0.0)) {
            var_r3_705 = (u8) &__float_nan;
            var_f4_748 = *(u8) &__float_nan;
        } else {
            sp8 = var_f4_748;
            var_r3_705 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch ((s32) var_r3_705) {             /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_790 = 1;
                } else {
                    var_r0_790 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_790 = 5;
                } else {
                    var_r0_790 = 3;
                }
                break;
            default:
                var_r0_790 = 4;
                break;
            }
            if (var_r0_790 == 1) {
                var_r3_705 = (u8) &__float_nan;
                var_f4_748 = *(u8) &__float_nan;
            }
        }
        this->unk110.unk580 = var_f4_748;
    } else {
        M2C_FIELD(this, f64 *, 0x598) = 0.0f;
        M2C_FIELD(this, f32 *, 0x59C) = 0.0f;
        this->unk110.unk490 = 0.0f;
        this->unk110.unk580 = 0.0f;
    }
    if (((u8) this->unk110.unk5A5 >> 2U) & 1) {
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        spE0 = sp50;
        sp58 = this->unkA8 * gUpdateTimeDelta;
        spE8 = (f64) sp58;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
        this->unk110.unk490 += (f32) spE8;
    }
    if (!(((u8) this->unk110.unk5A5 >> 4U) & 1) && (this->unk110.unk4D4 < 0.0f) && ((s32) this->unk110.unk16C <= 0)) {
        if (IsSteeringEnabled() == 0) {
            temp_f30_860 = gUpdateTimeDelta;
            spC0.operator*(this->unk110.unk4D4);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            spD0 = sp40;
            sp48 = spC0.unk8 * temp_f30_860;
            spD8 = (f64) sp48;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
            this->unk110.unk490 += (f32) spD8;
            temp_f29_888 = gUpdateTimeDelta;
            spA0.operator*(this->unk110.unk4D4);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            spB0 = sp30;
            sp38 = spA0.unk8 * temp_f29_888;
            spB8 = (f64) sp38;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
            this->unkA8 += (f32) spB8;
        } else {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            sp90 = sp20;
            sp28 = up.unk8 * this->unk110.unk4D4;
            sp98 = (f64) sp28;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
            this->unk110.unk490 += (f32) sp98;
        }
        var_r3_705 = (u8) &up;
        temp_f4_938 = M2C_FIELD(this, f32 *, 0x59C);
        temp_f5_940 = (f32) M2C_FIELD(this, f64 *, 0x598);
        temp_f6_944 = this->unk110.unk490;
        if (((temp_f6_944 * M2C_FIELD((u8) &up, f32 *, 8)) + ((temp_f5_940 * M2C_FIELD((u8) &up, f32 *, 0)) + (temp_f4_938 * M2C_FIELD((u8) &up, f32 *, 4)))) < -1500.0f) {
            __ml((temp_f6_944 * this->unkD8) + ((temp_f5_940 * this->unkD0) + (temp_f4_938 * this->unkD4)), sp80);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r4, 0x0, qr0 */);
            var_r3_705 = (u8) &up;
            this->unk110.unk490 -= sp80.unk8;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            sp70 = sp10;
            sp18 = M2C_FIELD((u8) &up, f32 *, 8) * -1500.0f;
            sp78 = (f64) sp18;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r4, 0x0, qr0 */);
            this->unk110.unk490 += (f32) sp78;
        }
    }
    return (MKVector3 *) var_r3_705;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk520'
void Character::UpdateAnimation() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKAnimScript *temp_r3_1016;
    f32 temp_f3_1030;
    f32 temp_f6_1036;
    f32 temp_f7_1042;
    s32 temp_cr0_eq_1069;
    s32 temp_r3_1089;
    u32 var_r5_1101;
    u8 var_r30_1073;
    void *temp_r3_1029;
    void *var_r3_1096;

    temp_r3_1016 = this->unk110.unk520;
    if ((temp_r3_1016 != NULL) && ((u32) temp_r3_1016->unk20 != 0)) {
        this->unk110.unk520->Animate(MKModel_GetAnimation(temp_r3_1016->unk8), -1, (MKVector3 *) &this->unk80);
        temp_r3_1029 = this->unk8;
        temp_f3_1030 = this->unk84;
        temp_f6_1036 = this->unk80;
        temp_f7_1042 = this->unk88;
        sp8 = (temp_f7_1042 * M2C_FIELD(temp_r3_1029, f32 *, 0x20)) + ((temp_f6_1036 * M2C_FIELD(temp_r3_1029, f32 *, 0)) + (temp_f3_1030 * M2C_FIELD(temp_r3_1029, f32 *, 0x10)));
        spC = (temp_f7_1042 * M2C_FIELD(temp_r3_1029, f32 *, 0x24)) + ((temp_f6_1036 * M2C_FIELD(temp_r3_1029, f32 *, 4)) + (temp_f3_1030 * M2C_FIELD(temp_r3_1029, f32 *, 0x14)));
        sp10 = (temp_f7_1042 * M2C_FIELD(temp_r3_1029, f32 *, 0x28)) + ((temp_f6_1036 * M2C_FIELD(temp_r3_1029, f32 *, 8)) + (temp_f3_1030 * M2C_FIELD(temp_r3_1029, f32 *, 0x18)));
        M2C_FIELD(this, f64 *, 0x90) = (f64) sp8;
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        M2C_FIELD(this, f64 *, 0x98) = (f64) sp10;
    }
    if (((u8) M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x78) == 0) && (temp_cr0_eq_1069 = (void *) M2C_FIELD(&gb, void **, 0xC) == NULL, (temp_cr0_eq_1069 == 0))) {
        if (temp_cr0_eq_1069 == 0) {
            var_r30_1073 = 0;
            if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
                var_r30_1073 = 1;
            }
            if (var_r30_1073 == 0) {
                goto block_11;
            }
        }
    } else {
block_11:
        temp_r3_1089 = this->unk110.unk16C;
        if (temp_r3_1089 > 0) {
            if (temp_r3_1089 != 0) {
                var_r3_1096 = this + ((temp_r3_1089 - 1) * 0x58) + 0x118;
            } else {
                var_r3_1096 = NULL;
            }
            var_r5_1101 = M2C_FIELD(var_r3_1096, u32 *, 0x44);
        } else {
            var_r5_1101 = 0;
        }
        KDSound_Play3d(this->unk110.unk520, (MKVector3 *) &this->unk110.unk478, var_r5_1101, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp6C'
void Character::UpdateModel() {
    f32 temp_f10_1146;
    f32 temp_f12_1150;
    f32 temp_f2_1147;
    f32 temp_f7_1145;
    f32 temp_f8_1143;
    f32 temp_f9_1148;
    M2C_STRUCT_COPY((s32) &arg_sp6C + 4, (s32) (&identity - 4) + 4, 0x40);
    temp_f8_1143 = -this->unkC0;
    temp_f7_1145 = -this->unkC4;
    temp_f10_1146 = this->unkD4;
    temp_f2_1147 = -this->unkC8;
    temp_f9_1148 = this->unkD8;
    arg_sp10 = temp_f8_1143;
    temp_f12_1150 = this->unkD0;
    arg_sp14 = temp_f7_1145;
    arg_sp18 = temp_f2_1147;
    arg_sp50 = (f64) arg_sp10;
    arg_sp58 = (f64) arg_sp18;
    arg_sp28 = temp_f2_1147;
    arg_sp48 = (f64) arg_sp28;
    arg_sp38 = (temp_f12_1150 * arg_sp54) - (temp_f10_1146 * (f32) arg_sp50);
    arg_sp30 = (temp_f10_1146 * (f32) arg_sp58) - (temp_f9_1148 * arg_sp54);
    arg_sp34 = (temp_f9_1148 * (f32) arg_sp50) - (temp_f12_1150 * (f32) arg_sp58);
    arg_sp68 = (f64) arg_sp38;
    arg_sp60 = (f64) arg_sp30;
    arg_sp20 = temp_f8_1143;
    arg_sp24 = temp_f7_1145;
    arg_sp70 = (f32) arg_sp60;
    arg_sp40 = (f64) arg_sp20;
    arg_sp74 = arg_sp64;
    arg_sp78 = (f32) arg_sp68;
    arg_sp7C = 0.0f;
    arg_sp80 = temp_f12_1150;
    arg_sp84 = temp_f10_1146;
    arg_sp88 = temp_f9_1148;
    arg_sp8C = 0.0f;
    arg_sp90 = (f32) arg_sp40;
    arg_sp94 = arg_sp44;
    arg_sp98 = (f32) arg_sp48;
    arg_sp9C = 0.0f;
    arg_spA0 = M2C_FIELD(this, f32 *, 0x588);
    arg_spA4 = M2C_FIELD(this, f32 *, 0x58C);
    arg_spA8 = this->unk110.unk480;
    arg_spAC = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp70));
}
#endif

#if 0 // DRAFT: undefined identifier 'unk57C'
void Character::StopMovement(bool arg0) {
    MKVector3 sp8;
    f32 temp_f1_1240;

    this->unk110.unk57C = 0.0f;
    if (arg0 != 0) {
        this->unk110.unk58C = 0.0f;
        this->unk110.unk590 = 0.0f;
    }
    temp_f1_1240 = (this->unk110.unk490 * this->unkD8) + ((M2C_FIELD(this, f32 *, 0x598) * this->unkD0) + (M2C_FIELD(this, f32 *, 0x59C) * this->unkD4));
    if (temp_f1_1240 < 0.0f) {
        __ml(temp_f1_1240, sp8);
        this->unk110.unk488 = M2C_BITWISE(f64, sp8);
        M2C_FIELD(this, f32 *, 0x5A0) = (f64) sp8.unk8;
    } else {
        M2C_FIELD(this, f32 *, 0x598) = 0.0f;
        M2C_FIELD(this, f32 *, 0x59C) = 0.0f;
        this->unk110.unk490 = 0.0f;
    }
    ClearHorizForces();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk488'
void Character::UpdateMovementArbitrary() {
    MKCollisionResult sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    MKVector3 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    MKVector3 sp230;
    MKVector3 sp220;
    f64 sp218;
    f64 sp210;
    MKVector3 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    MKVector3 sp1D0;
    MKVector3 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    MKVector3 sp190;
    f64 sp188;
    f64 sp180;
    MKVector3 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    MKVector3 sp140;
    f32 sp138;
    f32 sp128;
    f32 sp118;
    f32 sp108;
    f32 spF8;
    f32 spE8;
    f32 spD8;
    f32 spC8;
    f32 spB8;
    f32 spA8;
    f32 sp98;
    f32 sp88;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 *temp_r29_1450;
    f32 *temp_r29_1647;
    f32 temp_f1_1383;
    f32 temp_f1_1422;
    f32 temp_f28_1788;
    f32 temp_f2_1837;
    f32 var_f26_1301;
    f64 temp_f1_1304;
    f64 temp_f1_1310;
    f64 temp_f1_1314;
    s32 temp_r3_1333;
    s32 var_r0_1343;
    u8 var_r31_1373;

    sp300 = this->unk110.unk488;
    sp308 = M2C_FIELD(this, f64 *, 0x5A0);
    var_f26_1301 = ((f32) sp308 * (f32) sp308) + (((f32) sp300 * (f32) sp300) + (unksp304 * unksp304));
    if (var_f26_1301 > 0.0f) {
        temp_f1_1304 = __frsqrte(var_f26_1301);
        temp_f1_1310 = 0.5 * temp_f1_1304 * -(((f64) var_f26_1301 * (temp_f1_1304 * temp_f1_1304)) - 3.0);
        temp_f1_1314 = 0.5 * temp_f1_1310 * -(((f64) var_f26_1301 * (temp_f1_1310 * temp_f1_1310)) - 3.0);
        var_f26_1301 = (f32) ((f64) var_f26_1301 * (0.5 * temp_f1_1314 * -(((f64) var_f26_1301 * (temp_f1_1314 * temp_f1_1314)) - 3.0)));
    } else if (var_f26_1301 < M2C_BITWISE(f32, 0.0)) {
        var_f26_1301 = __float_nan;
    } else {
        sp8 = var_f26_1301;
        temp_r3_1333 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_1333) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_1343 = 1;
            } else {
                var_r0_1343 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_1343 = 5;
            } else {
                var_r0_1343 = 3;
            }
            break;
        default:
            var_r0_1343 = 4;
            break;
        }
        if (var_r0_1343 == 1) {
            var_f26_1301 = __float_nan;
        }
    }
    UpdateRotation();
    if ((var_f26_1301 > 0.0f) && (((u8) this->unk110.unk5A5 >> 5U) & 1)) {
        var_r31_1373 = 0;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_f1_1383 = this->unkD8 * M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x60);
        sp2C0 = sp130;
        sp138 = temp_f1_1383;
        sp2C8 = (f64) sp138;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp2D0 = sp120;
        sp128 = (f32) sp2C8 * 1.1f;
        sp2D8 = (f64) sp128;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp2F0 = sp110;
        sp118 = this->unk110.unk480 + (f32) sp2D8;
        sp2F8 = (f64) sp118;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        temp_f1_1422 = this->unkC8 * M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x60);
        sp2A0 = sp100;
        sp108 = temp_f1_1422;
        sp2A8 = (f64) sp108;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp2B0 = spF0;
        spF8 = (f32) sp2F8 + (f32) sp2A8;
        sp2B8 = (f64) spF8;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp2E0 = spE0;
        spE8 = (f32) sp2B8 + (f32) sp308;
        sp2E8 = (f64) spE8;
        temp_r29_1450 = this->unk110.unk460;
        if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp2F0), *((MKVector3 *) &sp2E0), M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x60), &sp310, (MKCollisionMode) 5, M2C_FIELD(temp_r29_1450, s32 *, 0x18)) != 0) {
            if (((sp310.unk18 * this->unkD8) + ((sp310.unk10 * this->unkD0) + (sp310.unk14 * this->unkD4))) > 0.65f) {
                sp50 = (sp310.unk14 * (f32) sp308) - (sp310.unk18 * unksp304);
                sp54 = (sp310.unk18 * (f32) sp300) - (sp310.unk10 * (f32) sp308);
                sp58 = (sp310.unk10 * unksp304) - (sp310.unk14 * (f32) sp300);
                sp260 = (f64) sp50;
                sp268 = (f64) sp58;
                sp40 = (sp310.unk14 * (f32) sp268) - (sp310.unk18 * unksp264);
                sp44 = (sp310.unk18 * (f32) sp260) - (sp310.unk10 * (f32) sp268);
                sp48 = (sp310.unk10 * unksp264) - (sp310.unk14 * (f32) sp260);
                sp270 = (f64) sp40;
                sp278 = (f64) sp48;
                Normalise(sp280);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                sp290 = spD0;
                spD8 = sp280.unk8 * -var_f26_1301;
                sp300 = spD0;
                sp298 = (f64) spD8;
                sp308 = (f64) spD8;
            }
            M2C_FIELD(this, f64 *, 0xF0) = (f64) sp310.unk10;
            M2C_FIELD(this, f64 *, 0xF8) = (f64) sp310.unk18;
            this->unk110.unk5A5 |= 0x40;
        } else {
            sp220.operator*(M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x60));
            sp230.operator*(1.1f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp240 = sp30;
            sp38 = this->unk110.unk480 + sp230.unk8;
            sp248 = (f64) sp38;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp2F0 = spC0;
            spC8 = (f32) sp248 + (f32) sp308;
            sp250 = spC0;
            sp2F8 = (f64) spC8;
            sp258 = (f64) spC8;
            sp200.operator*(-((1.1f * M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x60)) + 20.0f));
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp2E0 = spB0;
            spB8 = (f32) sp2F8 + sp200.unk8;
            sp210 = spB0;
            sp2E8 = (f64) spB8;
            sp218 = (f64) spB8;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp2F0), *((MKVector3 *) &sp2E0), &sp310, (MKCollisionMode) 5, M2C_FIELD(this->unk110.unk460, s32 *, 0x18)) != 0) {
                M2C_FIELD(this, f64 *, 0xF0) = (f64) sp310.unk10;
                M2C_FIELD(this, f64 *, 0xF8) = (f64) sp310.unk18;
                this->unk110.unk5A5 |= 0x40;
            } else {
                sp1C0.operator*(-200.0f);
                sp1D0.operator*(-100.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp1E0 = sp20;
                sp28 = this->unk110.unk480 + sp1D0.unk8;
                sp1E8 = (f64) sp28;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp2E0 = spA0;
                sp1F0 = spA0;
                spA8 = (f32) sp1E8 + sp1C0.unk8;
                sp2E8 = (f64) spA8;
                sp1F8 = (f64) spA8;
                temp_r29_1647 = this->unk110.unk460;
                if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp2F0), *((MKVector3 *) &sp2E0), M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x60), &sp310, (MKCollisionMode) 5, M2C_FIELD(temp_r29_1647, s32 *, 0x18)) != 0) {
                    var_r31_1373 = 1;
                    M2C_FIELD(this, f64 *, 0xF0) = (f64) sp310.unk10;
                    M2C_FIELD(this, f64 *, 0xF8) = (f64) sp310.unk18;
                    this->unk110.unk5A5 |= 0x40;
                }
            }
        }
        if (var_r31_1373 != 0) {

        }
        sp190.operator*(10.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp1A0 = sp10;
        sp18 = this->unk110.unk480 + (f32) sp308;
        sp1A8 = (f64) sp18;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp1B0 = sp90;
        sp2F0 = sp90;
        sp98 = (f32) sp1A8 + sp190.unk8;
        sp1B8 = (f64) sp98;
        sp2F8 = (f64) sp98;
        if (var_r31_1373 != 0) {

        }
        sp170.operator*(50.0f);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp2E0 = sp80;
        sp88 = (f32) sp2F8 - sp170.unk8;
        sp180 = sp80;
        sp2E8 = (f64) sp88;
        sp188 = (f64) sp88;
        if (MKCollision_RayCollide(*((MKVector3 *) &sp2F0), *((MKVector3 *) &sp2E0), &sp310, (MKCollisionMode) 5, M2C_FIELD(this->unk110.unk460, s32 *, 0x18)) != 0) {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            this->unk110.unk16C = 1;
            sp78 = sp310.unk8 - this->unk110.unk480;
            M2C_FIELD(this, f64 *, 0x118) = M2C_BITWISE(f64, sp310);
            this->unk110.unk10 = (f64) sp310.unk8;
            sp160 = sp70;
            this->unk110.unk18 = (f64) sp310.unk10;
            this->unk110.unk20 = (f64) sp310.unk18;
            sp168 = (f64) sp78;
            this->unk110.unk28 = (f64) sp310.unk20;
            this->unk110.unk30 = (f64) sp310.unk28;
            sp300 = sp70;
            this->unk110.unk38 = sp310.unk30;
            this->unk110.unk3C = sp310.unk34;
            sp308 = (f64) sp78;
            this->unk110.unk40 = sp310.unk38;
            this->unk110.unk44 = (void *) sp310.unk3C;
            this->unk110.unk48 = sp310.unk40;
            this->unk110.unk4C = sp310.unk44;
            this->unk110.unk50 = sp310.unk48;
            this->unk110.unk54 = sp310.unk4C;
            this->unk110.unk58 = sp310.unk50;
        } else {
            temp_f28_1788 = gUpdateTimeDelta;
            sp140.operator*(-980.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            sp150 = sp60;
            sp68 = sp140.unk8 * temp_f28_1788;
            sp158 = (f64) sp68;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
            this->unk110.unk490 += (f32) sp158;
            sp300 = this->unk110.unk488;
            M2C_FIELD(this, f64 *, 0xF0) = (f64) M2C_FIELD(&up, f64 *, 0);
            M2C_FIELD(this, f64 *, 0xF8) = (f64) M2C_FIELD(&up, f64 *, 8);
            sp308 = M2C_FIELD(this, f64 *, 0x5A0);
            this->unk110.unk5A5 |= 0x40;
        }
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
    temp_f2_1837 = this->unk110.unk480 + (f32) sp308;
    this->unk110.unk480 = temp_f2_1837;
    this->unk100 = sp300;
    this->unk108 = sp308;
    UpdateModel(sp300, temp_f2_1837);
}
#endif

#if 0 // DRAFT: '(' expected
void Character::UpdateMovementNormal() {
    struct __vt *sp84;
    f32 sp80;
    s8 sp7C;
    f32 sp78;
    s32 sp74;
    s8 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    s32 sp5C;
    s32 sp58;
    f64 sp48;
    MKVector3 sp38;
    f64 sp30;
    f64 sp28;
    MKVector3 sp18;
    f32 sp10;
    f32 temp_f1_1942;
    f32 temp_f31_1970;

    sp84 = &__vt;
    sp58 = 0x30;
    sp5C = 0;
    sp84 = &__vt;
    sp60 = 0.0f;
    sp64 = 0.0f;
    sp68 = 0.0f;
    sp70 = 0;
    sp74 = -1;
    sp78 = 0.0f;
    sp7C = 0;
    sp80 = 0.0f;
    sp58 = 0x31;
    if (this->unk110.unk5A5 & 1) {
        this->unk110.unk440 = (MKMessage *) &sp58;
    }
    UpdateRotation();
    UpdateVelocity();
    if ((IsSteeringEnabled() != 0) || (((u8) this->unk110.unk5A5 >> 1U) & 1)) {

    }
    sp48.Update((u8) &this->unk110.unk478);
    this->unk100 = sp48;
    this->unk108 = sp50;
    this->unk110.unk440 = NULL;
    temp_f1_1942 = (this->unk110.unk490 * this->unkD8) + ((M2C_FIELD(this, f32 *, 0x598) * this->unkD0) + (M2C_FIELD(this, f32 *, 0x59C) * this->unkD4));
    if (!(((u8) this->unk110.unk5A5 >> 4U) & 1) && (temp_f1_1942 < 0.0f) && ((s32) this->unk110.unk16C > 0) && ((MKProp *) this->unk110.unk52C == NULL) && (this->unk110.unk4E0 & 1)) {
        __ml(temp_f1_1942, sp38);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
        this->unk110.unk490 -= sp38.unk8;
        temp_f31_1970 = gUpdateTimeDelta;
        sp18.operator*(this->unk110.unk4D4);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp28 = sp8;
        sp10 = sp18.unk8 * temp_f31_1970;
        sp30 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
        this->unk110.unk490 += (f32) sp30;
    }
    UpdateModel();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk578'
void Character::UpdateMovement() {
    s32 temp_r0_2021;
    s32 temp_r30_2022;
    void *temp_r31_2055;

    temp_r0_2021 = this->unk110.unk578;
    temp_r30_2022 = M2C_FIELD(this->__vptr, s32 (**)(M2C_UNK), 0x3C)(0);
    switch (temp_r0_2021) {                         /* irregular */
    case 0:
        UpdateMovementNormal();
        break;
    case 1:
        UpdateMovementArbitrary();
        break;
    case 2:
        UpdateMovementCustom();
        break;
    }
    UpdateCollisionItems();
    temp_r31_2055 = checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    FindGroundColour(M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x74), M2C_FIELD(temp_r31_2055, u8 *, 0x75));
    EnableCollision(temp_r30_2022);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk554'
void Character::BridgeHit(float arg0, float arg1) {
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    s32 spBC;
    s32 spB8;
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
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r4_2083;
    void *temp_r5_2086;

    temp_r4_2083 = this->unk110.unk554;
    if (temp_r4_2083 != NULL) {
        temp_r5_2086 = this->unk8;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r5, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f4 */);
        sp78 = sp48;
        sp50 = M2C_FIELD(temp_r5_2086, f32 *, 8) * arg0;
        sp88 = M2C_FIELD(temp_r5_2086, f64 *, 0x30);
        sp80 = (f64) sp50;
        sp90 = M2C_FIELD(temp_r5_2086, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
        spA8 = sp38;
        sp40 = (f32) sp90 + (f32) sp80;
        spB0 = (f64) sp40;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f7 */);
        sp98 = sp28;
        sp30 = this->unk110.unk490 * 0.002f;
        spC = -1.0f;
        spA0 = (f64) sp30;
        sp8 = -(f32) sp98;
        unksp9C = 1.0f;
        sp10 = -(f32) spA0;
        sp58 = (f64) sp8;
        spBC = 0;
        sp60 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
        spC0 = sp38;
        spC8 = (f64) sp40;
        sp20 = (f32) sp60 * arg1;
        spD0 = sp18;
        spD8 = (f64) sp20;
        spB8 = 0x3C;
        sp68 = sp18;
        sp70 = (f64) sp20;
        M2C_FIELD(M2C_FIELD(temp_r4_2083, void **, 0x44), M2C_UNK (**)(void *, s32 *, void *, f64, f32, f32, f64, f64, f64, f32), 0x2C)(temp_r4_2083, &spB8, temp_r5_2086, sp18, (f32) sp60, 1.0f, (f64) sp30, (f64) sp40, sp38, 0.002f);
    }
}
#endif

void **Character::PlatformFind(MKCollisionResult *arg0, int arg1) {
    s32 var_ctr_2176;
    s32 var_r6_2175;
    u8 temp_r8_2181;
    u8 var_r9_2173;
    void **var_r0_2187;
    void **var_r0_2217;
    void **var_r3_2174;
    void **var_r5_2201;
    void *temp_r3_2214;
    void *temp_r5_2184;
    void *temp_r5_2198;
    void *temp_r7_2180;

    var_r9_2173 = 0;
    var_r3_2174 = NULL;
    var_r6_2175 = 0;
    var_ctr_2176 = arg1;
    if (arg1 > 0) {
        do {
            temp_r7_2180 = arg0 + var_r6_2175;
            temp_r8_2181 = M2C_FIELD(temp_r7_2180, u8 *, 0x50);
            if ((temp_r8_2181 != 0) && (temp_r5_2184 = M2C_FIELD(temp_r7_2180, void **, 0x48), ((temp_r5_2184 == NULL) == 0)) && (var_r0_2187 = M2C_FIELD(temp_r5_2184, void ***, 8), ((var_r0_2187 == NULL) == 0))) {

            } else {
                var_r0_2187 = NULL;
            }
            if (var_r0_2187 != NULL) {
                if ((temp_r8_2181 != 0) && (temp_r5_2198 = M2C_FIELD(temp_r7_2180, void **, 0x48), ((temp_r5_2198 == NULL) == 0)) && (var_r5_2201 = M2C_FIELD(temp_r5_2198, void ***, 8), ((var_r5_2201 == NULL) == 0))) {

                } else {
                    var_r5_2201 = NULL;
                }
                if (M2C_FIELD(*var_r5_2201, s32 *, 0xC) & 0x4000) {
                    if ((temp_r8_2181 != 0) && (temp_r3_2214 = M2C_FIELD(temp_r7_2180, void **, 0x48), ((temp_r3_2214 == NULL) == 0)) && (var_r0_2217 = M2C_FIELD(temp_r3_2214, void ***, 8), ((var_r0_2217 == NULL) == 0))) {

                    } else {
                        var_r0_2217 = NULL;
                    }
                    var_r3_2174 = var_r0_2217;
                } else {
                    goto block_19;
                }
            } else {
block_19:
                var_r9_2173 = 1;
            }
            var_r6_2175 += 0x58;
            var_ctr_2176 -= 1;
        } while (var_ctr_2176 != 0);
    }
    if (var_r9_2173 != 0) {
        return NULL;
    }
    return var_r3_2174;
}

#if 0 // DRAFT: undefined identifier 'unk52C'
void Character::PlatformDetach() {
    s32 sp2C;
    s8 sp28;
    M2C_UNK *sp24;
    s32 sp20;
    s32 sp1C;
    s8 sp18;
    M2C_UNK *sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_2246;
    void *temp_r3_2266;

    temp_r3_2246 = this->unk110.unk52C;
    if (temp_r3_2246 != NULL) {
        sp20 = 0;
        sp1C = 0x24;
        sp24 = &this->unk110.unk560;
        sp28 = 0;
        sp2C = 0;
        M2C_FIELD(temp_r3_2246->__vptr, M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp1C, 0x24, 0);
        this->unk110.unk52C = NULL;
        return;
    }
    temp_r3_2266 = this->unk110.unk554;
    if (temp_r3_2266 != NULL) {
        spC = 0;
        sp8 = 0x9A;
        sp10 = &this->unk110.unk538;
        sp18 = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_2266, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp8, 0x9A, 0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk52C'
void Character::PlatformAttach(MKProp *arg0, MKCollisionInfo *arg1) {
    MKCollisionInfo *sp2C;
    u8 sp28;
    M2C_UNK *sp24;
    s32 sp20;
    s32 sp1C;
    s8 sp18;
    MKCollisionInfo *sp14;
    M2C_UNK *sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_2314;
    s32 temp_r3_2301;

    PlatformDetach();
    temp_r3_2301 = M2C_FIELD(arg0->unk0, s32 *, 0xC);
    if (temp_r3_2301 & 0x4000) {
        this->unk110.unk52C = arg0;
        sp20 = 0;
        sp1C = 0x23;
        sp24 = &this->unk110.unk560;
        sp28 = 0;
        sp2C = arg1;
        temp_r3_2314 = this->unk110.unk52C;
        temp_r3_2314->Message(&sp1C, 0);
        if (sp28 == 0) {
            this->unk110.unk52C = NULL;
        }
    } else if (temp_r3_2301 & 0x20000) {
        spC = 0;
        sp8 = 0x99;
        sp10 = &this->unk110.unk538;
        sp14 = arg1;
        sp18 = 0;
        arg0->Message(&sp8, 0x99, 0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk52C'
void Character::PlatformUpdate() {
    MKProp *temp_r0_2387;
    MKProp *var_r31_2358;
    s32 temp_r3_2420;
    s32 temp_r4_2359;
    void *temp_r0_2393;
    void *var_r3_2366;
    void *var_r3_2379;
    void *var_r3_2426;

    var_r31_2358 = NULL;
    temp_r4_2359 = this->unk110.unk16C;
    if (temp_r4_2359 > 0) {
        if (temp_r4_2359 != 0) {
            var_r3_2366 = this + ((temp_r4_2359 - 1) * 0x58) + 0x118;
        } else {
            var_r3_2366 = NULL;
        }
        if ((u32) M2C_FIELD(var_r3_2366, u32 *, 0x48) != 0U) {
            if (temp_r4_2359 != 0) {
                var_r3_2379 = this + ((temp_r4_2359 - 1) * 0x58) + 0x118;
            } else {
                var_r3_2379 = NULL;
            }
            var_r31_2358 = M2C_FIELD(M2C_FIELD(var_r3_2379, void **, 0x48), MKProp **, 8);
        }
    }
    temp_r0_2387 = this->unk110.unk52C;
    if (((temp_r0_2387 != NULL) && (var_r31_2358 != temp_r0_2387)) || ((temp_r0_2393 = this->unk110.unk554, ((temp_r0_2393 == NULL) == 0)) && (var_r31_2358 != temp_r0_2393))) {
        PlatformDetach();
    }
    if ((var_r31_2358 != NULL) && (((var_r31_2358 != (MKProp *) this->unk110.unk52C) && (M2C_FIELD(var_r31_2358->unk0, s32 *, 0xC) & 0x4000)) || ((var_r31_2358 != (void *) this->unk110.unk554) && (M2C_FIELD(var_r31_2358->unk0, s32 *, 0xC) & 0x20000)))) {
        temp_r3_2420 = this->unk110.unk16C;
        if (temp_r3_2420 != 0) {
            var_r3_2426 = this + ((temp_r3_2420 - 1) * 0x58) + 0x118;
        } else {
            var_r3_2426 = NULL;
        }
        PlatformAttach(var_r31_2358, M2C_FIELD(var_r3_2426, MKCollisionInfo **, 0x48));
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp30'
void Character::RotateNodePYR(int arg0, const MKVector3 &arg1) {
    if (arg0 >= 0) {
        arg_sp30.GetNodeOrigin(MKModel_GetAnimation(this->unk4));
        arg_sp40 = arg_sp30;
        arg_sp48 = arg_sp38;
        arg_sp50.SetIdentity();
        arg_sp10 = -(f32) arg_sp40;
        arg_sp14 = -arg_sp44;
        arg_sp18 = -(f32) arg_sp48;
        arg_sp20 = (f64) arg_sp10;
        arg_sp28 = (f64) arg_sp18;
        arg_sp50.Translate((Matrix *) &arg_sp50, *((MKVector3 *) &arg_sp20));
        arg_sp50.RotatePYR((Matrix *) &arg_sp50, arg1);
        arg_sp50.Translate((Matrix *) &arg_sp50, *((MKVector3 *) &arg_sp40));
        ((Animation *) (MKModel_GetAnimation(this->unk4)))->SetCustomMatrix(arg0, (Matrix *) &arg_sp50, (AnimationMatrixPosition) 2, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp30'
void Character::RotateNodePitch(int arg0, float arg1) {
    if (arg0 >= 0) {
        arg_sp30.GetNodeOrigin(MKModel_GetAnimation(this->unk4));
        arg_sp40 = arg_sp30;
        arg_sp48 = arg_sp38;
        arg_sp50.SetIdentity();
        arg_sp10 = -(f32) arg_sp40;
        arg_sp14 = -arg_sp44;
        arg_sp18 = -(f32) arg_sp48;
        arg_sp20 = (f64) arg_sp10;
        arg_sp28 = (f64) arg_sp18;
        arg_sp50.Translate((Matrix *) &arg_sp50, *((MKVector3 *) &arg_sp20));
        arg_sp50.RotatePitch((Matrix *) &arg_sp50, arg1);
        arg_sp50.Translate((Matrix *) &arg_sp50, *((MKVector3 *) &arg_sp40));
        ((Animation *) (MKModel_GetAnimation(this->unk4)))->SetCustomMatrix(arg0, (Matrix *) &arg_sp50, (AnimationMatrixPosition) 2, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp30'
void Character::RotateNodeYaw(int arg0, float arg1) {
    if (arg0 >= 0) {
        arg_sp30.GetNodeOrigin(MKModel_GetAnimation(this->unk4));
        arg_sp40 = arg_sp30;
        arg_sp48 = arg_sp38;
        arg_sp50.SetIdentity();
        arg_sp10 = -(f32) arg_sp40;
        arg_sp14 = -arg_sp44;
        arg_sp18 = -(f32) arg_sp48;
        arg_sp20 = (f64) arg_sp10;
        arg_sp28 = (f64) arg_sp18;
        arg_sp50.Translate((Matrix *) &arg_sp50, *((MKVector3 *) &arg_sp20));
        arg_sp50.RotateYaw((Matrix *) &arg_sp50, arg1);
        arg_sp50.Translate((Matrix *) &arg_sp50, *((MKVector3 *) &arg_sp40));
        ((Animation *) (MKModel_GetAnimation(this->unk4)))->SetCustomMatrix(arg0, (Matrix *) &arg_sp50, (AnimationMatrixPosition) 2, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk520'
s32 Character::HasAnimFinished() {
    MKAnimScript *temp_r6_2655;
    s32 temp_r4_2656;
    s32 var_r5_2663;

    temp_r6_2655 = this->unk110.unk520;
    temp_r4_2656 = temp_r6_2655->unk2C;
    if (temp_r4_2656 & 1) {
        return 1;
    }
    var_r5_2663 = 0;
    if ((temp_r4_2656 & 2) && ((s32) temp_r6_2655->unk44 > (s32) this->unk110.unk594)) {
        var_r5_2663 = 1;
    }
    return var_r5_2663;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A4'
void Character::SetAnim(MKAnim *arg0, float arg1, float arg2, float arg3, unsigned int arg4) {
    MKAnimScript *temp_r3_2696;
    f32 var_f3_0;
    s32 temp_r3_2723;
    u32 temp_r6_2697;
    u32 var_r5_2735;
    void *var_r3_2730;

    var_f3_0 = arg3;
    if (this->unk110.unk5A4 & 1) {
        var_f3_0 = 0.0f;
    }
    if (arg0 != NULL) {
        temp_r3_2696 = this->unk110.unk520;
        temp_r6_2697 = temp_r3_2696->unk20;
        if ((temp_r6_2697 != arg0) || (arg4 & 4)) {
            if ((temp_r6_2697 == arg0) && (arg4 & 4)) {
                var_f3_0 = 0.0f;
            }
            temp_r3_2696->SetAnim(arg0, arg2, var_f3_0, (s32) arg4, -1);
            this->unk110.unk584 = arg1;
            this->unk110.unk594 = 0;
            if (arg2 < 0.0f) {
                this->unk110.unk594 += 1;
            }
            temp_r3_2723 = this->unk110.unk16C;
            if (temp_r3_2723 > 0) {
                if (temp_r3_2723 != 0) {
                    var_r3_2730 = this + ((temp_r3_2723 - 1) * 0x58) + 0x118;
                } else {
                    var_r3_2730 = NULL;
                }
                var_r5_2735 = M2C_FIELD(var_r3_2730, u32 *, 0x44);
            } else {
                var_r5_2735 = 0;
            }
            KDSound_Play3d(this->unk110.unk520, (MKVector3 *) &this->unk110.unk478, var_r5_2735, 0.0f, 0U);
            return;
        }
        if (arg2 != temp_r3_2696->unk38) {
            temp_r3_2696->unk38 = arg2;
            this->unk110.unk584 = arg1;
        }
        this->unk110.unk594 = this->unk110.unk520->unk44;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp28'
void Character::LerpModelColour(const MKVector4 &arg0, float arg1) {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;

    MKModel_GetColor(this->unk4);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f3, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f3 */);
    sp48 = sp28;
    sp50 = sp30;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp38 = sp18;
    sp40 = sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
    sp58 = sp8;
    sp60 = sp10;
    MKModel_SetColor(this->unk4, *((MKVector4 *) &sp58));
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKCollisionResult' to
void Character::FindGroundColour(bool arg0, bool arg1) {
    MKCollisionResult sp30;
    f64 sp28;
    f64 sp20;
    f64 sp10;
    u8 spC;
    MKCollisionInfo *sp8;
    MKCollisionInfo *temp_r4_2861;
    s32 temp_r3_2836;
    void *temp_r6_2870;

    temp_r3_2836 = this->unk110.unk16C;
    if (temp_r3_2836 > 0) {
        if (temp_r3_2836 != 0) {

        }
        Tools_GroundColor(&sp30);
        this->unk50 = M2C_BITWISE(f64, sp30);
        this->unk58 = (f64) sp30.unk8;
        return;
    }
    if (!(((u8) this->unk110.unk5A5 >> 4U) & 1) && (arg0 != 0)) {
        temp_r4_2861 = this->unk110.unk464;
        sp8 = temp_r4_2861;
        if (temp_r4_2861 != NULL) {
            spC = temp_r4_2861->unk4;
            temp_r4_2861->unk4 = 0;
        }
        temp_r6_2870 = this->unk8;
        sp20 = M2C_FIELD(temp_r6_2870, f64 *, 0x30);
        sp28 = M2C_FIELD(temp_r6_2870, f64 *, 0x38);
        FindAnyCollisionPosY(*((MKVector3 *) &sp20), 1000.0f, *((MKCollisionResult *) &sp30.unk10));
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
            Tools_GroundColor((MKCollisionResult *) &sp10);
            this->unk50 = sp10;
            this->unk58 = sp18;
            if (arg1 != 0) {
                this->unk110.unk16C = 1;
                M2C_FIELD(this, f64 *, 0x118) = (f64) sp30.unk10;
                this->unk110.unk10 = (f64) sp30.unk18;
                this->unk110.unk18 = (f64) sp30.unk20;
                this->unk110.unk20 = (f64) sp30.unk28;
                this->unk110.unk28 = (f64) sp30.unk30;
                this->unk110.unk30 = M2C_BITWISE(f64, sp30.unk38);
                this->unk110.unk38 = sp30.unk40;
                this->unk110.unk3C = M2C_BITWISE(f32, sp30.unk44);
                this->unk110.unk40 = (s32) sp30.unk48;
                this->unk110.unk44 = (void *) sp30.unk4C;
                this->unk110.unk48 = M2C_BITWISE(f32, sp30.unk50);
                this->unk110.unk4C = sp84;
                this->unk110.unk50 = sp88;
                this->unk110.unk54 = sp8C;
                this->unk110.unk58 = sp90;
            }
        } else {
            M2C_FIELD(this, f64 *, 0x50) = 1.0f;
            M2C_FIELD(this, f32 *, 0x54) = 1.0f;
            M2C_FIELD(this, f64 *, 0x58) = 1.0f;
            M2C_FIELD(this, f32 *, 0x5C) = 1.0f;
        }
        if (sp8 != NULL) {
            sp8->unk4 = spC;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk524'
void Character::FindAnyCollisionPosY(const MKVector3 &arg0, float arg1, MKCollisionResult &arg2) {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    u8 spC;
    MKCollisionInfo *sp8;
    MKCollisionInfo *temp_r6_2951;
    f32 temp_f4_2974;

    temp_r6_2951 = this->unk110.unk524;
    sp8 = temp_r6_2951;
    if (temp_r6_2951 != NULL) {
        spC = temp_r6_2951->unk4;
        temp_r6_2951->unk4 = 0;
    }
    sp40 = 0.0f;
    sp44 = 10.0f;
    sp48 = 0.0f;
    sp60 = (f64) sp40;
    sp68 = (f64) sp48;
    M2C_ERROR(/* unknown instruction: psq_lx $f5, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
    temp_f4_2974 = arg0.unk8;
    sp28 = 0.0f;
    sp38 = temp_f4_2974 + (f32) sp68;
    sp20 = 0.0f;
    sp24 = -arg1;
    sp80 = sp30;
    sp50 = (f64) sp20;
    sp88 = (f64) sp38;
    sp58 = (f64) sp28;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
    sp70 = sp10;
    sp18 = temp_f4_2974 + (f32) sp58;
    sp78 = (f64) sp18;
    MKCollision_RayCollide(*((MKVector3 *) &sp80), *((MKVector3 *) &sp70), &arg2, (MKCollisionMode) 7, M2C_FIELD(this->unk110.unk460, s32 *, 0x18) | 0x200);
    if (sp8 != NULL) {
        sp8->unk4 = spC;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 Character::Teleport(const Matrix *arg0) {
    f64 sp10;
    u8 spC;
    MKCollisionInfo *sp8;
    MKCollisionInfo *temp_r4_3027;
    f64 temp_f1_3064;
    f64 temp_f2_3056;
    f64 temp_f3_3055;

    temp_r4_3027 = this->unk110.unk464;
    sp8 = temp_r4_3027;
    if (temp_r4_3027 != NULL) {
        spC = temp_r4_3027->unk4;
        temp_r4_3027->unk4 = 0;
    }
    if (M2C_FIELD(this->unk110.__vptr, u8 (**)(CollisionObject *, f32 *, M2C_UNK, f32), 0x14)(&this->unk110, &arg0->unk30, 0xA, 5.0f) != 0) {
        M2C_FIELD(this, f64 *, 0xE0) = (f64) M2C_FIELD(arg0, f64 *, 0x20);
        M2C_FIELD(this, f64 *, 0xE8) = (f64) M2C_FIELD(arg0, f64 *, 0x28);
        temp_f3_3055 = M2C_FIELD(this, f64 *, 0xE0);
        temp_f2_3056 = M2C_FIELD(this, f64 *, 0xE8);
        M2C_FIELD(this, f64 *, 0xC0) = temp_f3_3055;
        M2C_FIELD(this, f64 *, 0xC8) = temp_f2_3056;
        this->unk110.unk5A5 |= 0x40;
        M2C_FIELD(this, f64 *, 0xF0) = (f64) M2C_FIELD(arg0, f64 *, 0x10);
        M2C_FIELD(this, f64 *, 0xF8) = (f64) M2C_FIELD(arg0, f64 *, 0x18);
        temp_f1_3064 = M2C_FIELD(this, f64 *, 0xF0);
        M2C_FIELD(this, f64 *, 0xD0) = temp_f1_3064;
        M2C_FIELD(this, f64 *, 0xD8) = (f64) M2C_FIELD(this, f64 *, 0xF8);
        this->unk110.unk5A5 |= 0x40;
        M2C_FIELD(this->unk110.__vptr, M2C_UNK (**)(f64 *, CollisionObject *, M2C_UNK, f64, f64, f64), 0x4C)(&sp10, &this->unk110, 1, temp_f1_3064, temp_f2_3056, temp_f3_3055);
        this->unk110.unk478 = sp10;
        M2C_FIELD(this, f64 *, 0x590) = sp18;
        UpdateCollisionItems(sp10);
        UpdateModel();
        ResetCloth();
        if (((u32) this->unk110.unk524->unkC != 0U) && (M2C_FIELD(*gMK, u32 (**)(void **), 0x7C)(gMK) != 0U)) {
            ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->ForceUpdate((u32) this->unk110.unk524->unkC);
        }
        if (sp8 != NULL) {
            sp8->unk4 = spC;
        }
        return 1;
    }
    if (sp8 != NULL) {
        sp8->unk4 = spC;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void Character::SetupCollision() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    M2C_UNK var_r31_3154;
    f32 temp_f31_3215;
    s32 temp_r0_3159;
    void *temp_r30_3147;

    temp_r30_3147 = checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    UpdateCollisionItems();
    var_r31_3154 = 1;
    if (M2C_FIELD(temp_r30_3147, s32 *, 0x14) & 1) {
        var_r31_3154 = 2;
    }
    temp_r0_3159 = M2C_FIELD(temp_r30_3147, s32 *, 0x6C);
    switch (temp_r0_3159) {                         /* irregular */
    case 0:
        sp18 = 1.0f;
        sp1C = 1.0f;
        sp20 = 1.0f;
        sp24 = 1.0f;
        sp28 = 1.0f;
        sp2C = 1.0f;
        sp30 = 1.0f;
        sp34 = 1.0f;
        sp48 = (f64) sp18;
        sp50 = (f64) sp20;
        sp58 = (f64) sp28;
        sp60 = (f64) sp30;
        ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **, f64, f64, f64), 0x84)(gMK, (f64) sp28, (f64) sp20, (f64) sp18)))->AddCapsule((MKVector3 *) &this->unk60, (MKVector3 *) &this->unk70, M2C_FIELD(temp_r30_3147, f32 *, 0x60), *((MKVector4 *) &sp58), *((MKVector4 *) &sp48), (MKCollisionMode) var_r31_3154, this->unk110.unk524, M2C_FIELD(temp_r30_3147, u32 *, 0x70));
        return;
    case 1:
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        sp38 = (f64) sp8;
        sp40 = (f64) sp10;
        temp_f31_3215 = M2C_FIELD(temp_r30_3147, f32 *, 0x60);
        ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **, f64), 0x84)(gMK, (f64) sp8)))->AddSphere((MKVector3 *) &this->unk60, temp_f31_3215, temp_f31_3215, *((MKVector4 *) &sp38), (MKCollisionMode) 2, this->unk110.unk524, M2C_FIELD(temp_r30_3147, u32 *, 0x70));
        return;
    case 2:
        ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddModel(this->unk4, 0, (MKCollisionMode) 2, this->unk110.unk524, 0U);
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sWorkingChunkID'
s32 Character::IsActive() {
    s32 temp_r3_3259;
    s32 var_r31_3258;

    var_r31_3258 = 0;
    temp_r3_3259 = this->unk10;
    if ((temp_r3_3259 & 0x20000) && (temp_r3_3259 & 0x40000) && (M2C_FIELD(*gMK, u8 (**)(void **, s32), 0x9C)(gMK, sWorkingChunkID.unk0) != 0)) {
        var_r31_3258 = 1;
    }
    return var_r31_3258;
}
#endif

void Character::Recycle() {
    PlatformDetach();
}

void Character::Despawn(bool arg0) {
    PlatformDetach();
    Disable();
}

#if 0 // DRAFT: undefined identifier '__vptr'
s32 Character::Spawn(SpawnPointRef *arg0) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f64 temp_f1_3376;
    void *temp_r31_3395;

    M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x30)();
    Activate();
    SetMovementType((CharacterMoveType) 2);
    this->unk110.unk4A8 = 0.0f;
    this->unk110.unk4AC = 0.0f;
    this->unk110.unk4B0 = 0.0f;
    this->unk110.unk4B8 = 0.0f;
    this->unk110.unk4BC = 0.0f;
    this->unk110.unk4C0 = 0.0f;
    M2C_FIELD(this, f32 *, 0x588) = 0.0f;
    M2C_FIELD(this, f32 *, 0x58C) = 0.0f;
    this->unk110.unk480 = 0.0f;
    UpdateCollisionItems();
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp20 = 1.0f;
    M2C_FIELD(this, f64 *, 0xE0) = (f64) sp18;
    M2C_FIELD(this, f64 *, 0xE8) = (f64) sp20;
    sp8 = 0.0f;
    M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(this, f64 *, 0xE0);
    M2C_FIELD(this, f64 *, 0xC8) = (f64) M2C_FIELD(this, f64 *, 0xE8);
    spC = 1.0f;
    sp10 = 0.0f;
    this->unk110.unk5A5 |= 0x40;
    M2C_FIELD(this, f64 *, 0xF0) = (f64) sp8;
    M2C_FIELD(this, f64 *, 0xF8) = (f64) sp10;
    temp_f1_3376 = M2C_FIELD(this, f64 *, 0xF0);
    sp38 = (f64) sp18;
    M2C_FIELD(this, f64 *, 0xD0) = temp_f1_3376;
    M2C_FIELD(this, f64 *, 0xD8) = (f64) M2C_FIELD(this, f64 *, 0xF8);
    sp40 = (f64) sp20;
    this->unk110.unk5A5 |= 0x40;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    UpdateModel(1, temp_f1_3376, (f64) sp10, (f64) sp8, (f64) sp20, (f64) sp18);
    ResetCloth();
    temp_r31_3395 = checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    FindGroundColour(M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x74), M2C_FIELD(temp_r31_3395, u8 *, 0x75));
    LerpModelColour(*((MKVector4 *) &this->unk50), 1.0f);
    MKModel_SetAlpha(this->unk4, 1.0f);
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 Character::Spawn(const Matrix *arg0) {
    MKCollisionResult sp10;
    s32 spC;
    s32 sp8;
    KDSynkerPlayer3 *temp_r3_3516;
    f32 *temp_r29_3446;
    f32 *temp_r5_3467;
    s32 temp_r27_3471;
    s32 temp_r3_3456;
    s32 var_r31_3470;
    u8 var_r29_3517;
    void **var_r28_3438;
    void *temp_r28_3513;
    void *temp_r29_3491;

    M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x30)();
    Deactivate();
    var_r28_3438 = NULL;
    M2C_FIELD(this, f64 *, 0x5B8) = (f64) M2C_FIELD(arg0, f64 *, 0x30);
    M2C_FIELD(this, f64 *, 0x5C0) = (f64) M2C_FIELD(arg0, f64 *, 0x38);
    M2C_FIELD(this, f64 *, 0x5C8) = (f64) M2C_FIELD(arg0, f64 *, 0x20);
    M2C_FIELD(this, f64 *, 0x5D0) = (f64) M2C_FIELD(arg0, f64 *, 0x28);
    this->unk110.unk52C = NULL;
    temp_r29_3446 = this->unk110.unk460;
    temp_r3_3456 = MKCollision_SphereCollide(*((MKVector3 *) &this->unk110.unk4A8), M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x60), &sp10, 0xA, (MKCollisionMode) 2, M2C_FIELD(temp_r29_3446, s32 *, 0x18) | 0x2000);
    if (temp_r3_3456 != 0) {
        var_r28_3438 = PlatformFind(&sp10, temp_r3_3456);
        if (var_r28_3438 == NULL) {
            return 0;
        }
    }
    temp_r5_3467 = this->unk110.unk460;
    var_r31_3470 = 0;
    temp_r27_3471 = M2C_FIELD(temp_r5_3467, s32 *, 0x18);
    M2C_FIELD(temp_r5_3467, s32 *, 0x18) = (s32) (temp_r27_3471 | 0x2000);
    if (Teleport(arg0, temp_r5_3467) != 0) {
        var_r31_3470 = 1;
        Activate();
        MKModel_SetAlpha(this->unk4, 1.0f);
        temp_r29_3491 = checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        FindGroundColour(M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x74), M2C_FIELD(temp_r29_3491, u8 *, 0x75));
        LerpModelColour(*((MKVector4 *) &this->unk50), 1.0f);
        if (var_r28_3438 != NULL) {
            PlatformAttach((MKProp *) var_r28_3438, NULL);
        }
    }
    M2C_FIELD(this->unk110.unk460, s32 *, 0x18) = temp_r27_3471;
    temp_r28_3513 = M2C_FIELD(&gb, void **, 0xC);
    if (temp_r28_3513 != NULL) {
        temp_r3_3516 = M2C_FIELD(temp_r28_3513, KDSynkerPlayer3 **, 0x78);
        var_r29_3517 = 0;
        if (((temp_r3_3516 != NULL) && (temp_r3_3516->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r28_3513, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r28_3513 + 0x24))->GetState() == 2))) {
            var_r29_3517 = 1;
        }
        if (var_r29_3517 != 0) {
            spC = 0;
            sp8 = 0x1C;
            Message(&sp8);
        }
    }
    return var_r31_3470;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk524'
u8 Character::IsCollisionEnabled() {
    return this->unk110.unk524->unk4;
}
#endif

#if 0 // DRAFT: identifier 'Character::EnableCollision(bool)' redeclared
u8 Character::EnableCollision(bool arg0) {
    MKCollisionInfo *temp_r4_3568;
    u8 temp_r3_3569;

    temp_r4_3568 = this->unk110.unk524;
    temp_r3_3569 = temp_r4_3568->unk4;
    if (arg0 != 0) {
        temp_r4_3568->unk4 = 1;
        return temp_r3_3569;
    }
    temp_r4_3568->unk4 = 0;
    return temp_r3_3569;
}
#endif

#if 0 // DRAFT: function call 'PropFlagsClear(unsigned long *, unsigned int)' does not
void Character::Deactivate() {
    PropFlagsClear((u32 *) &this->unk10, 0x60000U);
    EnableCollision(0);
    this->unk110.unk4F0.Show(0U);
}
#endif

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void Character::Activate() {
    PropFlagsSet((u32 *) &this->unk10, 0x60000U);
    EnableCollision(1);
}
#endif

#if 0 // DRAFT: function call 'PropFlagsClear(unsigned long *, unsigned int)' does not
void Character::Disable() {
    this->unk18 = this->unk18 | 0x80000000;
    PropFlagsClear((u32 *) &this->unk10, 0x160000U);
}
#endif

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void Character::Enable() {
    this->unk18 = this->unk18 & 0x7FFFFFFF;
    PropFlagsSet((u32 *) &this->unk10, 0x160000U);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Character::Message(MKMessage *arg0) {
    f32 temp_f1_3856;
    f32 temp_f2_3988;
    f32 temp_f3_3994;
    f32 temp_f4_3991;
    f32 temp_f6_3985;
    f32 temp_f7_3983;
    f32 temp_f8_3977;
    f64 temp_f1_4025;
    f64 temp_f1_4060;
    s32 temp_r0_3681;
    s8 temp_r28_3797;
    u8 var_r27_3873;
    u8 var_r28_3887;
    u8 var_r31_3868;
    u8 var_r4_3872;
    void *temp_r31_3978;
    void *temp_r31_4086;
    void *temp_r3_3844;
    void *temp_r5_4024;
    void *temp_r5_4057;
    temp_r0_3681 = arg0->unk0;
    if (temp_r0_3681 != 0x9C) {
        switch (temp_r0_3681) {                     /* irregular */
        case 190:
            M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x54)();
            goto block_88;
        case 191:
            M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x58)();
            goto block_88;
        default:
            M2C_FIELD(this->__vptr, s8 (**)(s32), 0x3C)(((u32) this->unk10 >> 0x14U) & 1);
            goto block_88;
        case 213:
            M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x20)();
            goto block_88;
        case 82:
            temp_r28_3797 = M2C_FIELD(this->__vptr, s8 (**)(s32), 0x3C)(0);
            M2C_FIELD(checked_cast<CollisionMsg *, MKMessage>(arg0), s8 *, 8) = temp_r28_3797;
            goto block_88;
        case 83:
            EnableCollision(M2C_FIELD(checked_cast<CollisionMsg *, MKMessage>(arg0), u8 *, 8));
            goto block_88;
        case 39:
            M2C_FIELD(checked_cast<CollisionInfoRequest *, MKMessage>(arg0), MKCollisionInfo **, 8) = (MKCollisionInfo *) this->unk110.unk524;
            goto block_88;
        case 2050:
            ((KDS_Message_PropResolve *) (checked_cast<P23KDS_Message_PropResolve))->Set(9MKMessage>__FP9MKMessage(arg0), (MKProp *) this, this->unk110.unk520);
            goto block_88;
        case 2051:
            if (this->unk10 & 0x01000000) {
                PropFlagsClear((u32 *) &this->unk10, 0x20000U);
            }
            goto block_88;
        case 2052:
            if (this->unk10 & 0x01000000) {
                PropFlagsSet((u32 *) &this->unk10, 0x20000U);
            }
            goto block_88;
        case 2053:
            temp_r3_3844 = checked_cast<KDS_Message_PropSetPosRot *, MKMessage>(arg0);
            arg_sp90.SetRotationPYR(*(temp_r3_3844 + 0x18));
            arg_spC0 = M2C_FIELD(temp_r3_3844, f32 *, 8);
            arg_spC4 = M2C_FIELD(temp_r3_3844, f32 *, 0xC);
            temp_f1_3856 = M2C_FIELD(temp_r3_3844, f32 *, 0x10);
            arg_spC8 = temp_f1_3856;
            arg_spCC = 1.0f;
            Teleport(&arg_sp90, temp_f1_3856);
            return;
        case -3:
            this->unk110.ResetResults();
            var_r31_3868 = 0;
            if (this->unk10 & 0x40000) {
                var_r4_3872 = 0;
                var_r27_3873 = 1;
                if ((((u8) this->unk110.unk5A5 >> 7U) & 1) || ((void *) M2C_FIELD(&gb, void **, 0xC) == NULL)) {
                    var_r4_3872 = 1;
                }
                if (var_r4_3872 == 0) {
                    var_r28_3887 = 0;
                    if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
                        var_r28_3887 = 1;
                    }
                    if (var_r28_3887 != 0) {
                        var_r27_3873 = 0;
                    }
                }
                if (var_r27_3873 != 0) {
                    var_r31_3868 = 1;
                }
            }
            this->unk110.unk4F0.Show(var_r31_3868);
            PropFlagsSet((u32 *) &this->unk10, 0x20000U);
            goto block_88;
        case -4:
            this->unk110.ResetResults();
            this->unk110.unk4F0.Show(0U);
            PropFlagsClear((u32 *) &this->unk10, 0x20000U);
            goto block_88;
        case 28:
        case 31:
            M2C_FIELD(this, s32 *, 0x6A8) = 0x52;
            this->unk110.unk5A0 = 1;
            Message(&this->unk110.unk598);
            if (!(((u8) this->unk110.unk5A5 >> 7U) & 1)) {
                this->unk110.unk4F0.Show(0U);
            }
            goto block_88;
        case 358:
            this->unk110.unk5A5 |= 0x80;
            goto block_88;
        case 359:
            this->unk110.unk5A5 &= ~0x80;
            goto block_88;
        case 29:
            M2C_FIELD(this, s32 *, 0x6A8) = 0x53;
            M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK *), 0x2C)(&this->unk110.unk598);
            this->unk110.unk4F0.Show(((u32) this->unk10 >> 0x12U) & 1);
            goto block_88;
        case 34:
            if ((MKProp *) this->unk110.unk52C != NULL) {
                temp_f8_3977 = this->unkC0;
                temp_r31_3978 = checked_cast<PlatformMoveMsg *, MKMessage>(arg0);
                arg_sp70 = temp_f8_3977;
                temp_f7_3983 = this->unkC4;
                arg_sp74 = temp_f7_3983;
                temp_f6_3985 = this->unkC8;
                arg_sp78 = temp_f6_3985;
                arg_sp7C = 0.0f;
                temp_f2_3988 = this->unkD0;
                arg_sp60 = temp_f2_3988;
                temp_f4_3991 = this->unkD4;
                arg_sp64 = temp_f4_3991;
                temp_f3_3994 = this->unkD8;
                arg_sp68 = temp_f3_3994;
                arg_sp18 = (temp_f2_3988 * temp_f7_3983) - (temp_f4_3991 * temp_f8_3977);
                arg_sp14 = (temp_f3_3994 * temp_f8_3977) - (temp_f2_3988 * temp_f6_3985);
                arg_sp10 = (temp_f4_3991 * temp_f6_3985) - (temp_f3_3994 * temp_f7_3983);
                arg_sp48 = (f64) arg_sp18;
                arg_sp40 = (f64) arg_sp10;
                arg_sp6C = 0.0f;
                arg_sp50 = (f32) arg_sp40;
                arg_sp54 = arg_sp44;
                arg_sp58 = (f32) arg_sp48;
                arg_sp5C = 0.0f;
                arg_sp50.RotateYaw((Matrix *) &arg_sp50, M2C_FIELD(M2C_FIELD(temp_r31_3978, void **, 0xC), f32 *, 4));
                M2C_FIELD(this, f32 *, 0xC0) = (f64) arg_sp70;
                M2C_FIELD(this, f32 *, 0xC8) = (f64) arg_sp78;
                temp_r5_4024 = M2C_FIELD(temp_r31_3978, void **, 8);
                temp_f1_4025 = M2C_FIELD(temp_r5_4024, f64 *, 0);
                this->unk110.unk450 = temp_f1_4025;
                this->unk110.unk458 = M2C_FIELD(temp_r5_4024, f64 *, 8);
                M2C_FIELD(this->unk110.__vptr, M2C_UNK (**)(f64 *, CollisionObject *, void *, f64), 0x4C)(&arg_sp30, &this->unk110, temp_r5_4024, temp_f1_4025);
                this->unk110.unk478 = arg_sp30;
                M2C_FIELD(this, f64 *, 0x590) = arg_sp38;
                UpdateCollisionItems(arg_sp30);
                UpdateModel();
            }
            goto block_88;
        case 155:
            temp_r5_4057 = M2C_FIELD(checked_cast<RopeBridgeMoveMsg *, MKMessage>(arg0), void **, 8);
            temp_f1_4060 = M2C_FIELD(temp_r5_4057, f64 *, 0);
            this->unk110.unk450 = temp_f1_4060;
            this->unk110.unk458 = M2C_FIELD(temp_r5_4057, f64 *, 8);
            M2C_FIELD(this->unk110.__vptr, M2C_UNK (**)(f64 *, CollisionObject *, void *, f64), 0x4C)(&arg_sp20, &this->unk110, temp_r5_4057, temp_f1_4060);
            this->unk110.unk478 = arg_sp20;
            M2C_FIELD(this, f64 *, 0x590) = arg_sp28;
            UpdateCollisionItems(arg_sp20);
            UpdateModel();
            goto block_88;
        case 91:
            temp_r31_4086 = this->unk8 + 0x30;
            M2C_FIELD(checked_cast<GetPosMsg *, MKMessage>(arg0), void **, 8) = temp_r31_4086;
            goto block_88;
        case 245:
            Tools_ResetEachInstance((MKPropDescriptor *) this->unk0);
            goto block_88;
        }
    } else {
    case 38:
        PlatformDetach();
        this->unk110.unk16C = 0;
    case 2055:
block_88:
        PropFlagsMessage((u32 *) &this->unk10, arg0);
        MKProp::Message(arg0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A5'
void Character::Draw() {
    KDSynkerPlayer3 *temp_r3_4127;
    f32 temp_f0_4172;
    u8 var_r30_4124;
    u8 var_r4_4164;
    void *temp_r28_4126;

    if (this->unk10 & 0x40000) {
        if (!(((u8) this->unk110.unk5A5 >> 7U) & 1)) {
            var_r30_4124 = 0;
            temp_r28_4126 = M2C_FIELD(&gb, void **, 0xC);
            temp_r3_4127 = M2C_FIELD(temp_r28_4126, KDSynkerPlayer3 **, 0x78);
            if (((temp_r3_4127 != NULL) && (temp_r3_4127->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r28_4126, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r28_4126 + 0x24))->GetState() == 2))) {
                var_r30_4124 = 1;
            }
            if ((var_r30_4124 == 0) || ((s32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), s32 *, 0x74) != 0)) {
                goto block_9;
            }
        } else {
block_9:
            MKProp::Draw();
            if ((MKModel *) this->unk4 != NULL) {
                LerpModelColour(*((MKVector4 *) &this->unk50), 0.1f);
                MKModel_SetAlpha(this->unk4, this->unk20);
                var_r4_4164 = 0;
                if (this->unk10 & 0x8000) {
                    temp_f0_4172 = M2C_FIELD(this->unk0, f32 *, 0x20) * M2C_FIELD(gMK, f32 *, 4);
                    if (this->unk24 < (temp_f0_4172 * temp_f0_4172)) {
                        var_r4_4164 = 1;
                    }
                }
                MKModel_EnableScissoring(this->unk4, var_r4_4164);
                MKModel_Draw(this->unk4, NULL);
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A5'
void Character::Update() {
    MKVector3 sp18;
    f64 sp10;
    f64 sp8;
    KDSynkerPlayer3 *temp_r3_4228;
    s16 temp_r30_4298;
    s32 temp_r3_4328;
    s32 temp_r4_4258;
    s32 var_r0_4288;
    s32 var_r28_4299;
    u32 var_r0_4270;
    u8 var_r30_4225;
    void *temp_r28_4227;
    void *temp_r5_4302;
    void *var_r3_4265;
    void *var_r3_4283;
    void *var_r3_4335;

    this->unk80 = 0.0f;
    this->unk84 = 0.0f;
    this->unk88 = 0.0f;
    this->unk90 = 0.0f;
    this->unk94 = 0.0f;
    this->unk98 = 0.0f;
    if ((IsSteeringEnabled() == 0) && !(((u8) this->unk110.unk5A5 >> 1U) & 1)) {
        M2C_FIELD(this, f32 *, 0x598) = 0.0f;
        M2C_FIELD(this, f32 *, 0x59C) = 0.0f;
        this->unk110.unk490 = 0.0f;
        this->unk110.unk580 = 0.0f;
    }
    if (this->unk10 & 0x20000) {
        if (!(((u8) this->unk110.unk5A5 >> 7U) & 1)) {
            var_r30_4225 = 0;
            temp_r28_4227 = M2C_FIELD(&gb, void **, 0xC);
            temp_r3_4228 = M2C_FIELD(temp_r28_4227, KDSynkerPlayer3 **, 0x78);
            if (((temp_r3_4228 != NULL) && (temp_r3_4228->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r28_4227, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r28_4227 + 0x24))->GetState() == 2))) {
                var_r30_4225 = 1;
            }
            if ((var_r30_4225 == 0) || ((s32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), s32 *, 0x74) != 0)) {
                goto block_12;
            }
        } else {
block_12:
            MKProp::Update();
            BridgeHit(0.0f, 50.0f);
            temp_r4_4258 = this->unk110.unk16C;
            if (temp_r4_4258 > 0) {
                if (temp_r4_4258 != 0) {
                    var_r3_4265 = this + ((temp_r4_4258 - 1) * 0x58) + 0x118;
                } else {
                    var_r3_4265 = NULL;
                }
                var_r0_4270 = M2C_FIELD(var_r3_4265, u32 *, 0x44);
            } else {
                var_r0_4270 = 0U;
            }
            if (var_r0_4270 != 0U) {
                if (temp_r4_4258 > 0) {
                    if (temp_r4_4258 != 0) {
                        var_r3_4283 = this + ((temp_r4_4258 - 1) * 0x58) + 0x118;
                    } else {
                        var_r3_4283 = NULL;
                    }
                    var_r0_4288 = M2C_FIELD(var_r3_4283, s32 *, 0x44);
                } else {
                    var_r0_4288 = 0;
                }
                this->unk110.unk574 = var_r0_4288;
            }
            temp_r30_4298 = MKModel_GetNmbrOfSubObjects(this->unk4, (SubObjectType) 2);
            var_r28_4299 = 0;
loop_28:
            if (var_r28_4299 < temp_r30_4298) {
                temp_r5_4302 = this->unk8;
                sp8 = M2C_FIELD(temp_r5_4302, f64 *, 0x30);
                sp10 = M2C_FIELD(temp_r5_4302, f64 *, 0x38);
                MKWind_GetVelocity(sp18);
                ((MKCloth *) (MKModel_GetClothSubObject(this->unk4, var_r28_4299)))->SetForce(1, sp18, -1);
                var_r28_4299 += 1;
                goto loop_28;
            }
            this->unk110.unk4F0.Show(((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1);
            temp_r3_4328 = this->unk110.unk16C;
            if (temp_r3_4328 > 0) {
                if (temp_r3_4328 != 0) {
                    var_r3_4335 = this + ((temp_r3_4328 - 1) * 0x58) + 0x118;
                } else {
                    var_r3_4335 = NULL;
                }
                this->unk110.unk4F0.unk28 = M2C_FIELD(var_r3_4335, f32 *, 4);
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk570'
void Character::SetDefaults() {
    SB2 *temp_r3_4417;

    this->unk10 = this->unk110.unk570;
    this->unk110.unk5A4 = 0;
    this->unk110.unk5A5 &= ~0x80;
    this->unk110.unk5A5 &= ~0x10;
    this->unk110.unk5A5 &= ~0x20;
    this->unk110.unk5A5 |= 0x40;
    this->unk110.unk5A5 &= ~8;
    this->unk110.unk5A5 &= ~2;
    this->unk110.unk5A5 &= ~1;
    this->unk110.unk5A5 |= 4;
    M2C_FIELD(this, f32 *, 0x50) = 1.0f;
    M2C_FIELD(this, f32 *, 0x54) = 1.0f;
    M2C_FIELD(this, f32 *, 0x58) = 1.0f;
    M2C_FIELD(this, f32 *, 0x5C) = 1.0f;
    this->unk110.unk574 = 0;
    this->unk110.unk578 = 0;
    this->unk90 = 0.0f;
    this->unk94 = 0.0f;
    this->unk98 = 0.0f;
    this->unk80 = 0.0f;
    this->unk84 = 0.0f;
    this->unk88 = 0.0f;
    this->unkA0 = 0.0f;
    this->unkA4 = 0.0f;
    this->unkA8 = 0.0f;
    this->unkB0 = 0.0f;
    this->unkB4 = 0.0f;
    this->unkB8 = 0.0f;
    M2C_FIELD(this, f32 *, 0x100) = 0.0f;
    M2C_FIELD(this, f32 *, 0x104) = 0.0f;
    M2C_FIELD(this, f32 *, 0x108) = 0.0f;
    this->unk110.unk580 = 0.0f;
    this->unk110.unk58C = 0.0f;
    this->unk110.unk590 = 0.0f;
    this->unk110.unk57C = 0.0f;
    this->unk110.unk588 = 1.0f;
    this->unk110.unk52C = NULL;
    this->unk110.unk528 = 0;
    temp_r3_4417 = this->unk110.unk530;
    if (temp_r3_4417 != NULL) {
        temp_r3_4417->SetDefaults();
    }
    this->unk110.unk594 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk52C'
void Character::Resolve() {
    MKProp *temp_r3_4440;

    MKProp::Resolve();
    temp_r3_4440 = this->unk110.unk52C;
    if (temp_r3_4440 != NULL) {
        this->unk110.unk52C = NULL;
        PlatformAttach(temp_r3_4440->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)), NULL);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk570'
void Character::LoadDone() {
    f64 sp20;
    f64 sp10;
    s32 spC;
    Character *sp8;
    MKModel *temp_r3_4494;
    MKModel *temp_r3_4504;
    f64 temp_f1_4629;
    f64 temp_f2_4621;
    f64 temp_f3_4620;
    s8 *var_r30_4473;
    void *temp_r30_4558;
    void *temp_r3_4469;
    void *temp_r3_4560;
    void *temp_r4_4468;

    this->unk10 = this->unk110.unk570;
    temp_r4_4468 = this->unk0;
    temp_r3_4469 = M2C_FIELD(temp_r4_4468, void **, 0x34);
    if (temp_r3_4469 != NULL) {
        var_r30_4473 = NULL;
        if ((u32) MKModel_GetAnimation(M2C_FIELD(temp_r3_4469, MKModel **, 8))->unk18 != 0U) {
            var_r30_4473 = (s8 *)1;
        }
        this->unk110.unk520 = ((MKAnimScript *) (((MKAnimScript *) (M2C_FIELD(this->unk0, MKAnimScript **, 0x34)))->GetName()))->Create(var_r30_4473, M2C_ERROR(/* Read from unset register $r5 */));
        this->unk4 = this->unk110.unk520->unk8;
        this->unk10 &= 0xFFFFFFFB;
    } else {
        temp_r3_4494 = M2C_FIELD(temp_r4_4468, MKModel **, 0x2C);
        if (temp_r3_4494 != NULL) {
            this->unk4 = MKModel_Create(MKModel_GetName(temp_r3_4494), NULL, 2, NULL);
        }
    }
    temp_r3_4504 = this->unk4;
    if (temp_r3_4504 != NULL) {
        this->unk8 = MKModel_GetWorldMatrix(temp_r3_4504);
    }
    MKProp::LoadDone();
    if (((MKAnimScript *) this->unk110.unk520 == NULL) && ((MKModel *) this->unk4 == NULL)) {
        this->unk10 = (this->unk10 & 0xFFFFFFFC) | 2;
        return;
    }
    if (this->unk10 & 0x800000) {
        ((Animation *) (MKModel_GetAnimation(this->unk4)))->EnableCustomMatrices(1U);
    }
    if (MKModel_GetNmbrOfSubObjects(this->unk4, (SubObjectType) 2) != 0) {
        MKModel_SetClothManualUpdate(this->unk4, 1U);
    }
    if ((u32) M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u32 *, 0xDC) != 0U) {
        this->unk110.unk534 = MKMaterial_Create(M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s8 **, 0xDC));
    }
    this->unk110.unk570 |= this->unk10;
    temp_r30_4558 = checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r3_4560 = checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = this;
    spC = 0;
    M2C_FIELD(this->unk110.__vptr, M2C_UNK (**)(CollisionObject *, void *, f32 *, u8, MKCollisionInfo *, M2C_UNK, M2C_UNK, M2C_UNK), 8)(&this->unk110, temp_r3_4560 + 0x7C, &this->unk110.unk4A8, M2C_FIELD(temp_r30_4558, u8 *, 0x76), this->unk110.unk524, 0, 1, 0);
    this->unk110.unk478.Init(checked_cast<P19CharacterDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0) + 0xC8, &this->unk110);
    M2C_FIELD(this->unk110.__vptr, M2C_UNK (**)(f64 *, CollisionObject *), 0x4C)(&sp20, &this->unk110);
    M2C_FIELD(this, f64 *, 0x5B8) = sp20;
    M2C_FIELD(this, f64 *, 0x5C0) = sp28;
    this->unk110.unk478 = M2C_FIELD(this, f64 *, 0x5B8);
    M2C_FIELD(this, f64 *, 0x590) = (f64) M2C_FIELD(this, f64 *, 0x5C0);
    KDMath_GetDirection(NormaliseAngle(this->unk110.unk4BC));
    M2C_FIELD(this, f64 *, 0x5C8) = sp10;
    M2C_FIELD(this, f64 *, 0x5D0) = sp18;
    M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(this, f64 *, 0x5C8);
    M2C_FIELD(this, f64 *, 0xC8) = (f64) M2C_FIELD(this, f64 *, 0x5D0);
    M2C_FIELD(this, f64 *, 0xE0) = (f64) M2C_FIELD(this, f64 *, 0xC0);
    M2C_FIELD(this, f64 *, 0xE8) = (f64) M2C_FIELD(this, f64 *, 0xC8);
    temp_f3_4620 = M2C_FIELD(this, f64 *, 0xE0);
    temp_f2_4621 = M2C_FIELD(this, f64 *, 0xE8);
    M2C_FIELD(this, f64 *, 0xC0) = temp_f3_4620;
    M2C_FIELD(this, f64 *, 0xC8) = temp_f2_4621;
    this->unk110.unk5A5 |= 0x40;
    M2C_FIELD(this, f64 *, 0xF0) = (f64) M2C_FIELD(&up, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xF8) = (f64) M2C_FIELD(&up, f64 *, 8);
    temp_f1_4629 = M2C_FIELD(this, f64 *, 0xF0);
    M2C_FIELD(this, f64 *, 0xD0) = temp_f1_4629;
    M2C_FIELD(this, f64 *, 0xD8) = (f64) M2C_FIELD(this, f64 *, 0xF8);
    this->unk110.unk5A5 |= 0x40;
    UpdateModel(&up, 1, temp_f1_4629, temp_f2_4621, temp_f3_4620);
    SetupCollision();
    this->unk110.unk4F0.Init(this->unk4, (MKProp *) this, 2000.0f, NULL, 1500.0f);
    this->unk110.unk4F0.Show(0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 Character::LoadLine(MKIniLine *arg0) {
    u8 sp8;

    sp8 = 0;
    if ((arg0->IsField(lit_stringBase0) != 0) && (arg0->GetBool(0) != 0)) {
        PropFlagsSet((u32 *) &this->unk10, 0x800000U);
    }
    if ((arg0->IsField(&lit_stringBase0[0xE]) != 0) && (arg0->GetBool(0) != 0)) {
        PropFlagsSet((u32 *) &this->unk10, 0x01000000U);
    }
    if ((MKProp::LoadLine(arg0) != 0) || (this->unk110.unk478.LoadLine(arg0) != 0) || (PropFlagsLoadLine((u32 *) &this->unk110.unk570, arg0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x1D], (s32 *) &this->unk110.unk52C, 0) != 0)) {
        return 1;
    }
    if (arg0->LoadBool(&lit_stringBase0[0x28], &sp8, 0) != 0) {
        this->unk110.unk5A5 = (this->unk110.unk5A5 & ~0x80) | ((sp8 << 7) & 0x80);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk530'
void Character::Deinit() {
    MKAnimScript *temp_r3_4777;
    MKCollisionInfo *temp_r31_4797;
    MKHeap *temp_r3_4800;
    MKResource *temp_r3_4790;
    SB2 *temp_r3_4766;

    temp_r3_4766 = this->unk110.unk530;
    if (temp_r3_4766 != NULL) {
        temp_r3_4766->Deinit();
        operator delete(this->unk110.unk530);
    }
    PlatformDetach();
    this->unk110.unk4F0.Deinit();
    temp_r3_4777 = this->unk110.unk520;
    if (temp_r3_4777 != NULL) {
        temp_r3_4777->Destroy();
    }
    this->unk110.unk520 = NULL;
    this->unk4 = NULL;
    M2C_FIELD(this->unk110.__vptr, M2C_UNK (**)(CollisionObject *), 0xC)(&this->unk110);
    temp_r3_4790 = this->unk110.unk534;
    if (temp_r3_4790 != NULL) {
        MKMaterial_Destroy((MKMaterial *) temp_r3_4790);
    }
    this->unk110.unk534 = NULL;
    temp_r31_4797 = this->unk110.unk524;
    if (temp_r31_4797 != NULL) {
        temp_r3_4800 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_4800 != NULL) {
            ((MKHeap *) (temp_r3_4800->Current()))->Free(temp_r31_4797, NULL, 0);
        } else {
            free(temp_r31_4797);
        }
    }
    this->unk110.unk524 = NULL;
    if (EnemyHud_GetEnemy() == this) {
        EnemyHud_Modified(NULL, 0.0f, 0.0f, 0.0f);
    }
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk524'
void Character::Init() {
    MKCollisionInfo *temp_r4_4861;
    MKCollisionInfo *var_r3_4851;
    MKHeap *temp_r3_4844;

    MKProp::Init();
    this->unk110.unk524 = NULL;
    temp_r3_4844 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4844 != NULL) {
        var_r3_4851 = ((MKHeap *) (temp_r3_4844->Current()))->Alloc(0x10, NULL, 0);
    } else {
        var_r3_4851 = malloc(0x10);
    }
    this->unk110.unk524 = var_r3_4851;
    temp_r4_4861 = this->unk110.unk524;
    temp_r4_4861->unk0 = 0;
    temp_r4_4861->unk4 = 1;
    temp_r4_4861->unk8 = (MKProp *) this;
    temp_r4_4861->unkC = 0;
    this->unk110.unk520 = NULL;
    this->unk110.unk534 = NULL;
    this->unk110.unk570 = this->unk10 | 0x160000;
    M2C_FIELD(this, f32 *, 0x60) = 0.0f;
    M2C_FIELD(this, f32 *, 0x64) = 0.0f;
    M2C_FIELD(this, f32 *, 0x68) = 0.0f;
    M2C_FIELD(this, f32 *, 0x70) = 0.0f;
    M2C_FIELD(this, f32 *, 0x74) = 0.0f;
    M2C_FIELD(this, f32 *, 0x78) = 0.0f;
    this->unk110.unk530 = NULL;
    if ((u8) M2C_FIELD(checked_cast<CharacterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x77) != 0) {
        operator new(0x468U, NULL, 0);
        this->unk110.unk530 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk110.unk530->Init();
    }
    this->unk110.unk52C = NULL;
    M2C_FIELD(this, Character **, 0x670) = this;
    this->unk110.unk550 = this;
    Character::SetDefaults();
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<RopeBridgeMoveMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<KDS_Message_PropSetPosRot *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<KDS_Message_PropResolve *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<CharacterDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
