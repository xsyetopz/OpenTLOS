#include "spyro/source/ElectricFence.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/GameMessages.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern s32 GS_SpyroZapBurn;
extern void **gMK;
extern s32 gViewSeed;
#if 0 // DRAFT: function call 'MKRand_Int(long *, int, long)' does not match
static s8 lit_stringBase0[0xA8] = {
    0x46,
    0x58,
    0x30,
    0x30,
    0x33,
    0x34,
    0x5F,
    0x45,
    0x6C,
    0x65,
    0x63,
    0x74,
    0x72,
    0x69,
    0x63,
    0x46,
    0x65,
    0x6E,
    0x63,
    0x65,
    0x50,
    0x6F,
    0x73,
    0x74,
    0,
    0x63,
    0x5F,
    0x63,
    0x6F,
    0x6C,
    0x6C,
    0x69,
    0x64,
    0x65,
    0,
    0x46,
    0x58,
    0x30,
    0x30,
    0x33,
    0x33,
    0x5F,
    0x43,
    0x6F,
    0x6C,
    0x6C,
    0x69,
    0x64,
    0x65,
    0x42,
    0x6F,
    0x78,
    0,
    0x77,
    0x61,
    0x79,
    0x70,
    0x6F,
    0x69,
    0x6E,
    0x74,
    0x73,
    0,
    0x77,
    0x61,
    0x79,
    0x70,
    0x6F,
    0x69,
    0x6E,
    0x74,
    0,
    0x53,
    0x74,
    0x61,
    0x72,
    0x74,
    0x4F,
    0x6E,
    0,
    0x4A,
    0x65,
    0x6C,
    0x6C,
    0x79,
    0x46,
    0x69,
    0x73,
    0x68,
    0x49,
    0x44,
    0,
    0x45,
    0x6E,
    0x65,
    0x72,
    0x67,
    0x79,
    0x42,
    0x65,
    0x61,
    0x6D,
    0,
    0x66,
    0x65,
    0x6E,
    0x63,
    0x65,
    0x53,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0x46,
    0x61,
    0x64,
    0x65,
    0x49,
    0x6E,
    0,
    0x66,
    0x65,
    0x6E,
    0x63,
    0x65,
    0x53,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0x46,
    0x61,
    0x64,
    0x65,
    0x4F,
    0x75,
    0x74,
    0,
    0x66,
    0x65,
    0x6E,
    0x63,
    0x65,
    0x53,
    0x68,
    0x75,
    0x74,
    0x44,
    0x6F,
    0x77,
    0x6E,
    0x53,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0,
    0x66,
    0x65,
    0x6E,
    0x63,
    0x65,
    0x53,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0,
}; /* const */

void ElectricFence::AllocBeams() {
    f64 sp10;
    f64 sp8;
    MKSceneManager *temp_r3_57;
    f64 temp_f0_65;
    f64 temp_f1_64;
    s32 var_r28_116;
    s32 var_r28_86;
    s32 var_r31_117;
    s32 var_r31_87;
    void *temp_r29_119;
    void *temp_r30_115;
    void *temp_r30_95;
    void *temp_r3_60;
    void *temp_r3_63;
    void *temp_r3_72;
    void *temp_r3_79;
    void *temp_r4_100;

    temp_r3_57 = this->unk110;
    if (temp_r3_57 != NULL) {
        temp_r3_60 = temp_r3_57->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        if (temp_r3_60 != NULL) {
            temp_r3_63 = M2C_FIELD(temp_r3_60, void **, 8);
            temp_f1_64 = M2C_FIELD(temp_r3_63, f64 *, 0x30);
            temp_f0_65 = M2C_FIELD(temp_r3_63, f64 *, 0x38);
            sp8 = temp_f1_64;
            this->unk100 = temp_f1_64;
            sp10 = temp_f0_65;
            this->unk108 = temp_f0_65;
        } else {
            temp_r3_72 = this->unk8;
            this->unk100 = M2C_FIELD(temp_r3_72, f64 *, 0x30);
            this->unk108 = M2C_FIELD(temp_r3_72, f64 *, 0x38);
        }
    } else {
        temp_r3_79 = this->unk8;
        this->unk100 = M2C_FIELD(temp_r3_79, f64 *, 0x30);
        this->unk108 = M2C_FIELD(temp_r3_79, f64 *, 0x38);
    }
    var_r28_86 = 0;
    var_r31_87 = 0;
    do {
        temp_r30_95 = this + var_r31_87;
        temp_r4_100 = this->unk4C + ((MKRand_Int(&gViewSeed, 0, this->unk50) * 0x70) + 0x30);
        M2C_FIELD(temp_r30_95, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r4_100, f64 *, 0);
        M2C_FIELD(temp_r30_95, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r4_100, f64 *, 8);
        var_r28_86 += 1;
        var_r31_87 += 0x18;
        M2C_FIELD(temp_r30_95, f32 *, 0xDC) = (f32) ((1000.0f * MKRand_Float(&gViewSeed, 0.0f, 1.0f)) + M2C_FIELD(temp_r30_95, f32 *, 0xDC));
    } while (var_r28_86 < 2);
    temp_r30_115 = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r28_116 = 0;
    var_r31_117 = 0;
    do {
        temp_r29_119 = this + var_r31_117;
        if ((u32) M2C_FIELD(temp_r29_119, u32 *, 0xD0) == 0U) {
            ((EnergyBeam *) (M2C_FIELD(temp_r30_115, EnergyBeam **, 0x80)))->SpawnEnergyBeam((MKVector3 *) &this->unk100, temp_r29_119 + 0xD8, 2.0f);
            M2C_FIELD(temp_r29_119, u32 *, 0xD0) = (u32) M2C_ERROR(/* Read from unset register $r3 */);
        }
        var_r28_116 += 1;
        var_r31_117 += 0x18;
    } while (var_r28_116 < 2);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'ElectricFence' to
void ElectricFence::FreeBeams() {
    s32 temp_r28_158;
    s32 var_r27_156;
    s32 var_r31_153;
    void *temp_r29_154;

    var_r31_153 = 0;
    temp_r29_154 = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r27_156 = 0;
    do {
        temp_r28_158 = var_r31_153 + 0xD0;
        ((EnergyBeam *) (M2C_FIELD(temp_r29_154, EnergyBeam **, 0x80)))->FreeEnergyBeam(*(this + temp_r28_158));
        var_r27_156 += 1;
        *(this + temp_r28_158) = 0;
        var_r31_153 += 0x18;
    } while (var_r27_156 < 2);
}
#endif

#if 0 // DRAFT: illegal type
void ElectricFence::EnableFenceCollision(bool arg0) {
    s32 temp_r0_186;
    s32 temp_r0_199;
    s32 var_r4_179;
    s32 var_r5_180;
    s32 var_r8_178;

    var_r8_178 = 0;
    var_r4_179 = 0;
    var_r5_180 = 0;
    if (arg0 != 0) {
loop_3:
        if (var_r8_178 < (s32) (this->unk50 - 1)) {
            temp_r0_186 = var_r5_180 + 0x5C;
            var_r8_178 += 1;
            var_r5_180 += 0x70;
            *(this->unk4C + temp_r0_186) = 1;
            goto loop_3;
        }
        return;
    }
loop_7:
    if (var_r8_178 < (s32) (this->unk50 - 1)) {
        temp_r0_199 = var_r4_179 + 0x5C;
        var_r8_178 += 1;
        var_r4_179 += 0x70;
        *(this->unk4C + temp_r0_199) = 0;
        goto loop_7;
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void ElectricFence::Deinit() {
    MKHeap *temp_r3_248;
    MKModel *temp_r3_227;
    MKModel *temp_r3_234;
    s32 var_r30_221;
    s32 var_r31_222;
    void *temp_r31_247;

    KDSound_Stop(&this->unk114);
    var_r30_221 = 0;
    var_r31_222 = 0;
loop_6:
    if (var_r30_221 < (s32) this->unk50) {
        temp_r3_227 = *(this->unk4C + (var_r31_222 + 0x40));
        if (temp_r3_227 != NULL) {
            MKModel_Destroy(temp_r3_227);
        }
        temp_r3_234 = *(this->unk4C + (var_r31_222 + 0x54));
        if (temp_r3_234 != NULL) {
            MKModel_Destroy(temp_r3_234);
        }
        var_r30_221 += 1;
        var_r31_222 += 0x70;
        goto loop_6;
    }
    FreeBeams();
    temp_r31_247 = this->unk4C;
    temp_r3_248 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_248 != NULL) {
        ((MKHeap *) (temp_r3_248->Current()))->Free(temp_r31_247, NULL, 0);
    } else {
        free(temp_r31_247);
    }
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal type
void ElectricFence::Draw() {
    s32 var_r30_278;
    s32 var_r31_279;

    var_r30_278 = 0;
    var_r31_279 = 0;
loop_2:
    if (var_r30_278 < (s32) this->unk50) {
        MKModel_Draw(*(this->unk4C + (var_r31_279 + 0x40)), NULL);
        var_r30_278 += 1;
        var_r31_279 += 0x70;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void ElectricFence::Message(MKMessage *arg0) {
    MKVector3 *temp_r30_356;
    s32 temp_r0_313;
    s32 var_ctr_378;
    s32 var_ctr_393;
    s32 var_r3_376;
    s32 var_r3_391;
    void *temp_r5_381;
    void *temp_r5_396;

    this->unk114.Message(arg0);
    temp_r0_313 = arg0->unk0;
    switch (temp_r0_313) {                          /* irregular */
    case 181:
        this->unk54 = 1;
        EnableFenceCollision(this->unk54);
        AllocBeams();
        return;
    case 22:
        M2C_FIELD(checked_cast<HitHeroSndMsg *, MKMessage>(arg0), s32 *, 8) = (s32) GS_SpyroZapBurn;
    default:
block_25:
        MKProp::Message(arg0);
        return;
    case 180:
        if (((s32) M2C_FIELD(checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x88) != 0) && ((u8) this->unk54 != 0)) {
            temp_r30_356 = this->unk8 + 0x30;
            KDSound_Play3d(M2C_FIELD(checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x88), temp_r30_356, 0U, -1, 0.0f, 0U);
        }
        this->unk54 = 0;
        EnableFenceCollision(this->unk54);
        FreeBeams();
        return;
    case -3:
        var_r3_376 = 0;
        var_ctr_378 = 2;
        do {
            temp_r5_381 = *(this + (var_r3_376 + 0xD0));
            if (temp_r5_381 != NULL) {
                M2C_FIELD(temp_r5_381, s8 *, 0x10) = 1;
            }
            var_r3_376 += 0x18;
            var_ctr_378 -= 1;
        } while (var_ctr_378 != 0);
        goto block_25;
    case -4:
        var_r3_391 = 0;
        var_ctr_393 = 2;
        do {
            temp_r5_396 = *(this + (var_r3_391 + 0xD0));
            if (temp_r5_396 != NULL) {
                M2C_FIELD(temp_r5_396, s8 *, 0x10) = 0;
            }
            var_r3_391 += 0x18;
            var_ctr_393 -= 1;
        } while (var_ctr_393 != 0);
        goto block_25;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void ElectricFence::Update() {
    f64 sp18;
    f64 sp10;
    s32 sp8;
    MKSceneManager *temp_r3_445;
    f64 temp_f0_453;
    f64 temp_f1_452;
    s32 var_r29_463;
    s32 var_r31_464;
    void *temp_r30_472;
    void *temp_r3_448;
    void *temp_r3_451;
    void *temp_r4_433;
    void *temp_r4_477;

    if ((s32) M2C_FIELD(checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x84) != 0) {
        temp_r4_433 = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        this->unk114.Update(M2C_FIELD(temp_r4_433, s32 *, 0x84), 1U, this->unk54, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    temp_r3_445 = this->unk110;
    if (temp_r3_445 != NULL) {
        temp_r3_448 = temp_r3_445->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        if (temp_r3_448 != NULL) {
            temp_r3_451 = M2C_FIELD(temp_r3_448, void **, 8);
            temp_f1_452 = M2C_FIELD(temp_r3_451, f64 *, 0x30);
            temp_f0_453 = M2C_FIELD(temp_r3_451, f64 *, 0x38);
            sp10 = temp_f1_452;
            this->unk100 = temp_f1_452;
            sp18 = temp_f0_453;
            this->unk108 = temp_f0_453;
        }
    }
    if ((u8) this->unk54 != 0) {
        var_r29_463 = 0;
        var_r31_464 = 0;
        do {
            temp_r30_472 = this + var_r31_464;
            temp_r4_477 = this->unk4C + ((MKRand_Int(&gViewSeed, 0, this->unk50) * 0x70) + 0x30);
            M2C_FIELD(temp_r30_472, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r4_477, f64 *, 0);
            M2C_FIELD(temp_r30_472, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r4_477, f64 *, 8);
            var_r29_463 += 1;
            var_r31_464 += 0x18;
            M2C_FIELD(temp_r30_472, f32 *, 0xDC) = (f32) ((1000.0f * MKRand_Float(&gViewSeed, 0.0f, 1.0f)) + M2C_FIELD(temp_r30_472, f32 *, 0xDC));
        } while (var_r29_463 < 2);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'ElectricFence' to
void ElectricFence::Resolve() {
    s32 var_ctr_514;
    s32 var_r3_511;
    void *temp_r5_517;

    MKProp::Resolve();
    AllocBeams();
    var_r3_511 = 0;
    var_ctr_514 = 2;
    do {
        temp_r5_517 = *(this + (var_r3_511 + 0xD0));
        if (temp_r5_517 != NULL) {
            M2C_FIELD(temp_r5_517, s8 *, 0x10) = 0;
        }
        var_r3_511 += 0x18;
        var_ctr_514 -= 1;
    } while (var_ctr_514 != 0);
}
#endif

#if 0 // DRAFT: identifier 'ElectricFence::LoadDone()' redeclared
s32 ElectricFence::LoadDone() {
    Matrix *temp_r4_764;
    f32 temp_f3_1088;
    f32 temp_f3_1123;
    f32 temp_f6_1095;
    f32 temp_f7_1101;
    f32 temp_f8_1129;
    f32 temp_f9_1135;
    f32 var_f3_669;
    f32 var_f4_601;
    f64 temp_f1_608;
    f64 temp_f1_614;
    f64 temp_f1_618;
    s32 temp_r0_696;
    s32 temp_r0_796;
    s32 temp_r3_637;
    s32 temp_r3_695;
    s32 temp_r5_699;
    s32 temp_r7_746;
    s32 var_r0_647;
    s32 var_r26_972;
    s32 var_r27_566;
    s32 var_r27_732;
    s32 var_r29_974;
    s32 var_r30_564;
    s32 var_r30_730;
    u16 temp_r26_763;
    u16 temp_r3_804;
    void *temp_r26_896;
    void *temp_r29_770;
    void *temp_r3_733;
    void *temp_r4_704;
    void *temp_r5_571;
    void *temp_r5_917;
    void *temp_r6_1000;
    void *temp_r6_700;
    void *temp_r6_914;
    void *temp_r7_809;
    void *temp_r7_916;
    void *temp_r8_754;
    MKProp::LoadDone();
    M2C_STRUCT_COPY((s32) &this->unk6C + 4, (s32) (&identity - 4) + 4, 0x40);
    this->unk8 = &this->unk70;
    var_r30_564 = 0;
    var_r27_566 = 0;
loop_22:
    temp_r3_695 = this->unk50;
    temp_r0_696 = temp_r3_695 - 1;
    if (var_r30_564 < temp_r0_696) {
        temp_r5_571 = this->unk4C;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp100 = 0.0f;
        arg_sp288 = arg_sp108;
        arg_sp110 = M2C_FIELD((temp_r5_571 + (((var_r30_564 + 1) * 0x70) + 0x30)), f32 *, 8) - M2C_FIELD((temp_r5_571 + (var_r27_566 + 0x30)), f32 *, 8);
        arg_sp290 = (f64) arg_sp110;
        arg_spF8 = 0.0f;
        arg_spFC = 1.0f;
        var_f4_601 = ((f32) arg_sp290 * (f32) arg_sp290) + (((f32) arg_sp288 * (f32) arg_sp288) + (arg_sp28C * arg_sp28C));
        arg_sp280 = (f64) arg_sp100;
        arg_sp278 = (f64) arg_spF8;
        if (var_f4_601 > 0.000001f) {
            if (var_f4_601 > 0.0f) {
                temp_f1_608 = __frsqrte(var_f4_601);
                temp_f1_614 = 0.5 * temp_f1_608 * -(((f64) var_f4_601 * (temp_f1_608 * temp_f1_608)) - 3.0);
                temp_f1_618 = 0.5 * temp_f1_614 * -(((f64) var_f4_601 * (temp_f1_614 * temp_f1_614)) - 3.0);
                var_f4_601 = (f32) ((f64) var_f4_601 * (0.5 * temp_f1_618 * -(((f64) var_f4_601 * (temp_f1_618 * temp_f1_618)) - 3.0)));
            } else if (var_f4_601 < M2C_BITWISE(f32, 0.0)) {
                var_f4_601 = __float_nan;
            } else {
                arg_sp10 = var_f4_601;
                temp_r3_637 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_637) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_647 = 1;
                    } else {
                        var_r0_647 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_647 = 5;
                    } else {
                        var_r0_647 = 3;
                    }
                    break;
                default:
                    var_r0_647 = 4;
                    break;
                }
                if (var_r0_647 == 1) {
                    var_f4_601 = __float_nan;
                }
            }
            var_f3_669 = 1.0f / var_f4_601;
        } else {
            var_f3_669 = 0.0f;
            var_f4_601 = 0.0f;
        }
        arg_sp288 = (f32) arg_sp288 * var_f3_669;
        arg_sp28C *= var_f3_669;
        arg_sp290 = (f32) arg_sp290 * var_f3_669;
        *(this->unk4C + (var_r27_566 + 0x68)) = var_f4_601;
        KDMath_BuildMatrixFromFwd(this->unk4C + var_r27_566, *((MKVector3 *) &arg_sp288), (MKVector3 *) &arg_sp278);
        var_r30_564 += 1;
        var_r27_566 += 0x70;
        goto loop_22;
    }
    temp_r5_699 = temp_r0_696 * 0x70;
    temp_r6_700 = this->unk4C;
    temp_r4_704 = temp_r6_700 + (temp_r5_699 + 0x30);
    arg_sp268 = M2C_FIELD(temp_r4_704, f64 *, 0);
    arg_sp270 = M2C_FIELD(temp_r4_704, f64 *, 8);
    M2C_STRUCT_COPY(temp_r6_700 + temp_r5_699, temp_r6_700 + ((temp_r3_695 - 2) * 0x70), 0x40);
    var_r30_730 = 0;
    var_r27_732 = 0;
    temp_r3_733 = this->unk4C + ((this->unk50 - 1) * 0x70);
    M2C_FIELD(temp_r3_733, f32 *, 0x30) = (f32) arg_sp268;
    M2C_FIELD(temp_r3_733, f32 *, 0x34) = arg_sp26C;
    M2C_FIELD(temp_r3_733, f32 *, 0x38) = (f32) arg_sp270;
    M2C_FIELD(temp_r3_733, f32 *, 0x3C) = 1.0f;
loop_27:
    if (var_r30_730 < (s32) this->unk50) {
        temp_r7_746 = var_r27_732 + 0x40;
        *(this->unk4C + temp_r7_746) = MKModel_Create(lit_stringBase0, NULL, 2, NULL);
        temp_r8_754 = this->unk4C + (var_r27_732 + 0x44);
        M2C_FIELD(temp_r8_754, s32 *, 0) = 0;
        M2C_FIELD(temp_r8_754, s8 *, 4) = 1;
        M2C_FIELD(temp_r8_754, ElectricFence **, 8) = this;
        M2C_FIELD(temp_r8_754, s32 *, 0xC) = 0;
        temp_r26_763 = Tools_GetMatchingSubObjectIndex((SubObjectType) 0, *(this->unk4C + temp_r7_746), &lit_stringBase0[0x19]);
        temp_r4_764 = this->unk4C + var_r27_732;
        MKModel_SetWorldMatrix(temp_r4_764->unk40, *temp_r4_764);
        temp_r29_770 = this->unk4C + var_r27_732;
        ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddModel(M2C_FIELD(temp_r29_770, MKModel **, 0x40), (s32) temp_r26_763, (MKCollisionMode) 1, temp_r29_770 + 0x44, 0U);
        *(this->unk4C + (var_r27_732 + 0x48)) = 1;
        if (var_r30_730 < (s32) (this->unk50 - 1)) {
            temp_r0_796 = var_r27_732 + 0x54;
            *(this->unk4C + temp_r0_796) = MKModel_Create(&lit_stringBase0[0x23], NULL, 2, NULL);
            temp_r3_804 = Tools_GetMatchingSubObjectIndex((SubObjectType) 0, *(this->unk4C + temp_r0_796), &lit_stringBase0[0x19]);
            temp_r7_809 = this->unk4C + (var_r27_732 + 0x58);
            M2C_FIELD(temp_r7_809, s32 *, 0) = 0;
            M2C_FIELD(temp_r7_809, s8 *, 4) = 1;
            M2C_FIELD(temp_r7_809, ElectricFence **, 8) = this;
            M2C_FIELD(temp_r7_809, s32 *, 0xC) = 0;
            M2C_STRUCT_COPY((s32) &arg_sp2DC + 4, (s32) ((this->unk4C + var_r27_732) - 4) + 4, 0x40);
            MKVector(0.0f, 400.0f, 0.0f);
            arg_sp38 = -arg_sp300;
            arg_sp3C = -arg_sp304;
            arg_sp40 = -arg_sp308;
            arg_sp208 = (f64) arg_sp38;
            arg_sp210 = (f64) arg_sp40;
            arg_sp218.operator*(*(this->unk4C + (var_r27_732 + 0x68)));
            arg_sp228.operator*(0.5f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp238 = arg_spE8;
            arg_spF0 = arg_sp230 + arg_sp200;
            arg_sp240 = (f64) arg_spF0;
            arg_sp2E0.Translate((Matrix *) &arg_sp2E0, *((MKVector3 *) &arg_sp238));
            arg_spD8 = 100.0f;
            arg_spDC = 800.0f;
            arg_spE0 = *(this->unk4C + (var_r27_732 + 0x68));
            arg_sp1E8 = (f64) arg_spD8;
            arg_sp1F0 = (f64) arg_spE0;
            arg_sp2E0.Scale3x3((Matrix *) &arg_sp2E0, *((MKVector3 *) &arg_sp1E8));
            MKModel_SetWorldMatrix(*(this->unk4C + (var_r27_732 + 0x54)), *((Matrix *) &arg_sp2E0));
            temp_r26_896 = this->unk4C + var_r27_732;
            ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddModel(M2C_FIELD(temp_r26_896, MKModel **, 0x54), (s32) temp_r3_804, (MKCollisionMode) 1, temp_r26_896 + 0x58, 0x100U);
            *(this->unk4C + (var_r27_732 + 0x5C)) = 1;
            temp_r6_914 = this->unk4C;
            temp_r7_916 = temp_r6_914 + (var_r27_732 + 0x20);
            temp_r5_917 = temp_r6_914 + (var_r27_732 + 0x30);
            arg_sp28 = -M2C_FIELD(temp_r7_916, f32 *, 0);
            arg_sp2C = -M2C_FIELD(temp_r7_916, f32 *, 4);
            arg_sp30 = -M2C_FIELD(temp_r7_916, f32 *, 8);
            arg_sp1C8 = (f64) arg_sp28;
            arg_sp1D0 = (f64) arg_sp30;
            arg_sp258 = M2C_FIELD(temp_r5_917, f64 *, 0);
            arg_sp260 = M2C_FIELD(temp_r5_917, f64 *, 8);
            arg_sp1D8.operator*(*(temp_r6_914 + (var_r27_732 + 0x68)));
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spC0 = 0.0f;
            arg_spB8 = 0.0f;
            arg_spBC = 150.0f;
            arg_spD0 = (f32) arg_sp260 + arg_sp1E0;
            arg_sp1B8 = (f64) arg_spB8;
            arg_sp1C0 = (f64) arg_spC0;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spA8 = 0.0f;
            arg_spAC = 150.0f;
            arg_spB0 = 0.0f;
        }
        var_r30_730 += 1;
        var_r27_732 += 0x70;
        goto loop_27;
    }
    EnableFenceCollision(this->unk54);
    var_r26_972 = 0;
    var_r29_974 = 0;
    arg_sp98 = 1e11f;
    arg_sp9C = 1e11f;
    arg_spA0 = 1e11f;
    this->unkB0 = (f64) arg_sp98;
    arg_sp90 = -1e11f;
    arg_sp88 = -1e11f;
    arg_sp8C = -1e11f;
    this->unkB8 = (f64) arg_spA0;
    this->unkC0 = (f64) arg_sp88;
    arg_sp1A8 = (f64) arg_sp98;
    arg_sp1B0 = (f64) arg_spA0;
    arg_sp198 = (f64) arg_sp88;
    arg_sp1A0 = (f64) arg_sp90;
    this->unkC8 = (f64) arg_sp90;
loop_30:
    if (var_r26_972 < (s32) this->unk50) {
        temp_r6_1000 = this->unk4C + (var_r29_974 + 0x30);
        arg_sp248 = M2C_FIELD(temp_r6_1000, f64 *, 0);
        arg_sp250 = M2C_FIELD(temp_r6_1000, f64 *, 8);
        Min(*((MKVector3 *) &arg_sp188), *((MKVector3 *) &this->unkB0));
        this->unkB0 = arg_sp188;
        this->unkB8 = arg_sp190;
        arg_sp78 = (f32) arg_sp248;
        arg_sp7C = arg_sp24C + 800.0f;
        arg_sp80 = (f32) arg_sp250;
        arg_sp168 = (f64) arg_sp78;
        arg_sp170 = (f64) arg_sp80;
        Max(*((MKVector3 *) &arg_sp178), *((MKVector3 *) &this->unkC0));
        var_r26_972 += 1;
        var_r29_974 += 0x70;
        this->unkC0 = arg_sp178;
        this->unkC8 = arg_sp180;
        goto loop_30;
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r28, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp138 = arg_sp18;
    arg_sp20 = (f32) M2C_FIELD(this, f64 *, 0xC8) - (f32) M2C_FIELD(this, f64 *, 0xB8);
    arg_sp140 = (f64) arg_sp20;
    arg_sp148.operator*(0.5f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp158 = arg_sp68;
    arg_sp70 = (f32) M2C_FIELD(this, f64 *, 0xB8) + arg_sp150;
    this->unkA0 = (f32) arg_sp158;
    arg_sp160 = (f64) arg_sp70;
    this->unkA4 = arg_sp15C;
    this->unkA8 = (f32) arg_sp160;
    this->unkAC = 1.0f;
    M2C_STRUCT_COPY((s32) &arg_sp29C + 4, (s32) &this->unk6C + 4, 0x40);
    arg_sp2A0.Inverse((Matrix *) &arg_sp2A0);
    temp_f3_1088 = M2C_FIELD(this, f32 *, 0xB4);
    temp_f6_1095 = (f32) M2C_FIELD(this, f64 *, 0xB0);
    temp_f7_1101 = (f32) M2C_FIELD(this, f64 *, 0xB8);
    arg_sp58 = arg_sp2D0 + ((temp_f7_1101 * arg_sp2C0) + ((temp_f6_1095 * arg_sp2A0) + (temp_f3_1088 * arg_sp2B0)));
    arg_sp5C = arg_sp2D4 + ((temp_f7_1101 * arg_sp2C4) + ((temp_f6_1095 * arg_sp2A4) + (temp_f3_1088 * arg_sp2B4)));
    arg_sp60 = arg_sp2D8 + ((temp_f7_1101 * arg_sp2C8) + ((temp_f6_1095 * arg_sp2A8) + (temp_f3_1088 * arg_sp2B8)));
    this->unkB0 = (f64) arg_sp58;
    this->unkB8 = (f64) arg_sp60;
    temp_f3_1123 = M2C_FIELD(this, f32 *, 0xC4);
    temp_f8_1129 = (f32) M2C_FIELD(this, f64 *, 0xC0);
    temp_f9_1135 = (f32) M2C_FIELD(this, f64 *, 0xC8);
    arg_sp128 = (f64) arg_sp58;
    arg_sp48 = arg_sp2D0 + ((temp_f9_1135 * arg_sp2C0) + ((temp_f8_1129 * arg_sp2A0) + (temp_f3_1123 * arg_sp2B0)));
    arg_sp4C = arg_sp2D4 + ((temp_f9_1135 * arg_sp2C4) + ((temp_f8_1129 * arg_sp2A4) + (temp_f3_1123 * arg_sp2B4)));
    arg_sp50 = arg_sp2D8 + ((temp_f9_1135 * arg_sp2C8) + ((temp_f8_1129 * arg_sp2A8) + (temp_f3_1123 * arg_sp2B8)));
    this->unkC0 = (f64) arg_sp48;
    this->unkC8 = (f64) arg_sp50;
    arg_sp130 = (f64) arg_sp60;
    arg_sp118 = (f64) arg_sp48;
    arg_sp120 = (f64) arg_sp50;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r28, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r28, $r3, 0x0, qr0 */);
    M2C_FIELD(this, f64 *, 0xC8) = (f32) ((f32) M2C_FIELD(this, f64 *, 0xC8) - (f32) M2C_FIELD(this, f64 *, 0xB8));
    this->unkC = (BoundingVolume *) &this->unkB0;
    return 0xC0;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 ElectricFence::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;
    MKHeap *temp_r3_1215;
    MKIniLine *var_r27_1234;
    s32 temp_r0_1249;
    s32 temp_r28_1214;
    s32 temp_r3_1211;
    s32 temp_r3_1245;
    s32 var_r29_1235;
    s32 var_r29_1274;
    void *temp_r5_1248;
    void *var_r3_1222;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField(&lit_stringBase0[0x35]) != 0) {
        temp_r3_1211 = arg0->GetNmbrOfSubLines();
        this->unk50 = temp_r3_1211;
        temp_r28_1214 = this->unk50 * 0x70;
        temp_r3_1215 = temp_r3_1211->Current();
        if (temp_r3_1215 != NULL) {
            var_r3_1222 = ((MKHeap *) (temp_r3_1215->Current()))->Alloc(temp_r28_1214, NULL, 0);
        } else {
            var_r3_1222 = malloc(temp_r28_1214);
        }
        this->unk4C = var_r3_1222;
        var_r27_1234 = arg0->unkC->GetSubLine(arg0);
        var_r29_1235 = 0;
loop_8:
        if (var_r27_1234 != NULL) {
            var_r27_1234->LoadVector3(&lit_stringBase0[0x3F], &sp8, 0);
            temp_r3_1245 = var_r29_1235 + 0x40;
            temp_r5_1248 = this->unk4C + var_r29_1235;
            temp_r0_1249 = var_r29_1235 + 0x54;
            M2C_FIELD(temp_r5_1248, f32 *, 0x30) = M2C_BITWISE(f32, sp8);
            var_r29_1235 += 0x70;
            M2C_FIELD(temp_r5_1248, f32 *, 0x34) = sp8.unk4;
            M2C_FIELD(temp_r5_1248, f32 *, 0x38) = sp8.unk8;
            M2C_FIELD(temp_r5_1248, f32 *, 0x3C) = 1.0f;
            *(this->unk4C + temp_r3_1245) = 0;
            *(this->unk4C + temp_r0_1249) = 0;
            var_r27_1234 = var_r27_1234->unkC->GetNextLine(var_r27_1234);
            goto loop_8;
        }
    }
    var_r29_1274 = 0;
    if ((arg0->LoadBool(&lit_stringBase0[0x48], &this->unk54, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x50], (s32 *) &this->unk110, 0) != 0)) {
        var_r29_1274 = 1;
    }
    return var_r29_1274;
}
#endif

#if 0 // DRAFT: illegal operand
void ElectricFence::Init() {
    s32 temp_r0_1319;
    s32 var_ctr_1317;
    s32 var_r3_1315;
    void *temp_r31_1327;

    MKProp::Init();
    this->unk54 = 1;
    var_r3_1315 = 0;
    this->unk50 = 0;
    var_ctr_1317 = 2;
    do {
        temp_r0_1319 = var_r3_1315 + 0xD0;
        var_r3_1315 += 0x18;
        *(this + temp_r0_1319) = 0;
        var_ctr_1317 -= 1;
    } while (var_ctr_1317 != 0);
    this->unk110 = NULL;
    temp_r31_1327 = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk114.Init(M2C_FIELD(checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x8C), M2C_FIELD(temp_r31_1327, f32 *, 0x90));
}
#endif

#if 0 // DRAFT: expression syntax error
void ElectricFenceDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
    this->unk80 = checked_cast<EnergyBeam *, MKProp>(gMK->CreateProp(&lit_stringBase0[0x5C]));
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 ElectricFenceDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1373;

    var_r31_1373 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x67], &this->unk8C, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x78], &this->unk90, 0) != 0) || (KDSound_LoadLine(arg0, &lit_stringBase0[0x8A], &this->unk88) != 0) || (KDSound_LoadLine(arg0, &lit_stringBase0[0x9D], &this->unk84) != 0)) {
        var_r31_1373 = 1;
    }
    return var_r31_1373;
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
