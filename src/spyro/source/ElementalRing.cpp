#include "spyro/source/ElementalRing.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDSoundTools.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(KDSoundFlangedFader **);               /* extern */
KDSoundFlangedFader **malloc(M2C_UNK);              /* extern */
extern s32 GS_CCElementalRingEarth1;
extern s32 GS_CCElementalRingEarth2;
extern s32 GS_CCElementalRingEarth3;
extern s32 GS_CCElementalRingElec1;
extern s32 GS_CCElementalRingElec2;
extern s32 GS_CCElementalRingElec3;
extern s32 GS_CCElementalRingFire1;
extern s32 GS_CCElementalRingFire2;
extern s32 GS_CCElementalRingFire3;
extern s32 GS_CCElementalRingIce1;
extern s32 GS_CCElementalRingIce2;
extern s32 GS_CCElementalRingIce3;
extern s32 GS_CCElementalRingSpyroBurn;
extern s32 GS_CCElementalRingSwamp1;
extern s32 GS_CCElementalRingSwamp2;
extern s32 GS_CCElementalRingSwamp3;
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern void **gb;

static s8 lit_stringBase0[0x61] = {
    0x46,
    0x58,
    0x5F,
    0x52,
    0x69,
    0x6E,
    0x67,
    0x45,
    0x6C,
    0x65,
    0x6D,
    0x65,
    0x6E,
    0x74,
    0x46,
    0x69,
    0x72,
    0x65,
    0,
    0x46,
    0x58,
    0x5F,
    0x52,
    0x69,
    0x6E,
    0x67,
    0x45,
    0x6C,
    0x65,
    0x6D,
    0x65,
    0x6E,
    0x74,
    0x45,
    0x6C,
    0x65,
    0x63,
    0,
    0x46,
    0x58,
    0x5F,
    0x52,
    0x69,
    0x6E,
    0x67,
    0x45,
    0x6C,
    0x65,
    0x6D,
    0x65,
    0x6E,
    0x74,
    0x49,
    0x63,
    0x65,
    0,
    0x46,
    0x58,
    0x5F,
    0x52,
    0x69,
    0x6E,
    0x67,
    0x45,
    0x6C,
    0x65,
    0x6D,
    0x65,
    0x6E,
    0x74,
    0x45,
    0x61,
    0x72,
    0x74,
    0x68,
    0,
    0x46,
    0x58,
    0x5F,
    0x52,
    0x69,
    0x6E,
    0x67,
    0x45,
    0x6C,
    0x65,
    0x6D,
    0x65,
    0x6E,
    0x74,
    0x43,
    0x6F,
    0x6E,
    0x76,
    0x65,
    0x78,
    0,
}; /* const */

void ElementalRing::Trigger(const MKVector3 &arg0, const MKVector3 &arg1, int arg2, bool arg3, MKProp *arg4, float arg5, float arg6, float arg7, float arg8) {
    KDSoundFlangedFader **temp_r6_48;
    KDSoundFlangedFader **temp_r6_52;
    KDSoundFlangedFader *temp_r31_54;

    temp_r6_48 = this->unk4C;
    if ((u32) M2C_FIELD(temp_r6_48, u32 *, -4) != 0U) {
        temp_r6_52 = temp_r6_48 - 4;
        this->unk4C = temp_r6_52;
        temp_r31_54 = *temp_r6_52;
        if (temp_r31_54 != NULL) {
            M2C_FIELD(temp_r31_54, f32 *, 0xA4) = arg5;
            M2C_FIELD(temp_r31_54, f32 *, 0xA8) = arg6;
            M2C_FIELD(temp_r31_54, f32 *, 0xAC) = arg7;
            M2C_FIELD(temp_r31_54, f32 *, 0xB0) = arg8;
            M2C_FIELD(temp_r31_54, f64 *, 0x70) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r31_54, f64 *, 0x78) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r31_54, f64 *, 0x90) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r31_54, f64 *, 0x98) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            M2C_FIELD(temp_r31_54, f32 *, 0x80) = 0.0f;
            M2C_FIELD(temp_r31_54, f32 *, 0x84) = 1.0f;
            M2C_FIELD(temp_r31_54, f32 *, 0x88) = 0.0f;
            M2C_FIELD(temp_r31_54, s32 *, 0xB4) = 1;
            M2C_FIELD(temp_r31_54, f32 *, 0xA0) = arg5;
            M2C_FIELD(temp_r31_54, s32 *, 0xC0) = (s32) M2C_FIELD((checked_cast<ElementalRingDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (arg2 * 4)), s32 *, 0x60);
            M2C_FIELD(temp_r31_54, u8 *, 0xC8) = arg3;
            M2C_FIELD(temp_r31_54, MKProp **, 0xC4) = arg4;
            switch (arg2) {                         /* irregular */
            case 0:
                KDSound_Play3d(GS_CCElementalRingFire1, (MKVector3 *) (temp_r31_54 + 0x70), 0U, -1, 0.0f, 0U);
                M2C_FIELD(temp_r31_54, s32 *, 0xB8) = (s32) GS_CCElementalRingFire2;
                M2C_FIELD(temp_r31_54, s32 *, 0xBC) = (s32) GS_CCElementalRingFire3;
                break;
            case 1:
                KDSound_Play3d(GS_CCElementalRingElec1, (MKVector3 *) (temp_r31_54 + 0x70), 0U, -1, 0.0f, 0U);
                M2C_FIELD(temp_r31_54, s32 *, 0xB8) = (s32) GS_CCElementalRingElec2;
                M2C_FIELD(temp_r31_54, s32 *, 0xBC) = (s32) GS_CCElementalRingElec3;
                break;
            case 2:
                KDSound_Play3d(GS_CCElementalRingIce1, (MKVector3 *) (temp_r31_54 + 0x70), 0U, -1, 0.0f, 0U);
                M2C_FIELD(temp_r31_54, s32 *, 0xB8) = (s32) GS_CCElementalRingIce2;
                M2C_FIELD(temp_r31_54, s32 *, 0xBC) = (s32) GS_CCElementalRingIce3;
                break;
            case 3:
                KDSound_Play3d(GS_CCElementalRingEarth1, (MKVector3 *) (temp_r31_54 + 0x70), 0U, -1, 0.0f, 0U);
                M2C_FIELD(temp_r31_54, s32 *, 0xB8) = (s32) GS_CCElementalRingEarth2;
                M2C_FIELD(temp_r31_54, s32 *, 0xBC) = (s32) GS_CCElementalRingEarth3;
                break;
            case 4:
                KDSound_Play3d(GS_CCElementalRingSwamp1, (MKVector3 *) (temp_r31_54 + 0x70), 0U, -1, 0.0f, 0U);
                M2C_FIELD(temp_r31_54, s32 *, 0xB8) = (s32) GS_CCElementalRingSwamp2;
                M2C_FIELD(temp_r31_54, s32 *, 0xBC) = (s32) GS_CCElementalRingSwamp3;
                break;
            }
            temp_r31_54->Init(0, 0.5f, 2.0f, 20.0f, 0.25f, 0.25f);
        }
    }
}

#if 0 // DRAFT: type mismatch
void ElementalRing::Deinit() {
    KDSoundFlangedFader **var_r31_186;
    KDSoundFlangedFader **var_r31_199;
    KDSoundFlangedFader **var_r3_200;
    KDSoundFlangedFader **var_r4_198;
    KDSoundFlangedFader *temp_r0_203;
    KDSoundFlangedFader *temp_r0_222;
    KDSoundFlangedFader *temp_r3_194;
    MKHeap *temp_r3_225;
    u32 temp_r0_208;

    var_r31_186 = this->unk4C;
loop_2:
    if (var_r31_186 != NULL) {
        temp_r3_194 = *var_r31_186;
        if (temp_r3_194 != NULL) {
            temp_r3_194->Deinit();
            var_r31_186 += 4;
            goto loop_2;
        }
    }
    var_r4_198 = this->unk4C;
    var_r31_199 = var_r4_198;
    var_r3_200 = var_r4_198;
loop_7:
    temp_r0_208 = M2C_FIELD(var_r3_200, u32 *, -4);
    var_r3_200 -= 4;
    if (temp_r0_208 != 0U) {
        temp_r0_203 = *var_r3_200;
        if (temp_r0_203 < var_r31_199) {
            var_r31_199 = (KDSoundFlangedFader **) temp_r0_203;
        }
        goto loop_7;
    }
    if (var_r3_200 != &gEmptyPtrListDL) {
loop_13:
        temp_r0_222 = *var_r4_198;
        if (temp_r0_222 != NULL) {
            if (temp_r0_222 < var_r31_199) {
                var_r31_199 = (KDSoundFlangedFader **) temp_r0_222;
            }
            var_r4_198 += 4;
            goto loop_13;
        }
        temp_r3_225 = var_r3_200->Current();
        if (temp_r3_225 != NULL) {
            ((MKHeap *) (temp_r3_225->Current()))->Free(var_r31_199, NULL, 0);
        } else {
            free(var_r31_199);
        }
    }
    this->unk4C = NULL;
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp1F0'
void ElementalRing::Draw() {
    KDSoundFlangedFader **var_r28_335;
    KDSoundFlangedFader *temp_r30_617;
    MKMaterial *temp_r3_360;
    MKMaterial *var_r29_341;
    MKVector3 *temp_r23_470;
    f32 temp_f14_445;
    f32 temp_f14_452;
    f32 temp_f1_449;
    f32 temp_f1_533;
    f32 temp_f24_317;
    f32 temp_f24_322;
    s32 var_r21_407;
    s32 var_r22_436;
    s32 var_r23_298;
    s32 var_r26_300;
    s32 var_r26_437;
    void *temp_r3_326;
    var_r23_298 = 0;
    var_r26_300 = 0;
    this->unk50 += 2.0f * gUpdateTimeDelta;
    do {
        temp_f24_317 = 6.2831855f * ((f32) var_r23_298 / 20.0f);
        temp_f24_322 = 100.0f * -_table_sinf(1.5707964f + temp_f24_317);
        temp_r3_326 = &arg_sp1F0 + var_r26_300;
        var_r23_298 += 1;
        var_r26_300 += 0x10;
        M2C_FIELD(temp_r3_326, f32 *, 0) = (f32) (100.0f * _table_sinf(temp_f24_317));
        M2C_FIELD(temp_r3_326, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r3_326, f32 *, 8) = temp_f24_322;
    } while (var_r23_298 < 0x14);
    var_r28_335 = this->unk4C;
    var_r29_341 = NULL;
loop_15:
    if (var_r28_335 != NULL) {
        temp_r30_617 = *var_r28_335;
        if (temp_r30_617 != NULL) {
            if ((var_r29_341 != NULL) && (var_r29_341 != (MKMaterial *) M2C_FIELD(temp_r30_617, MKMaterial **, 0xC0))) {
                MKEndPrimitive();
            }
            temp_r3_360 = M2C_FIELD(temp_r30_617, MKMaterial **, 0xC0);
            if (var_r29_341 != temp_r3_360) {
                var_r29_341 = temp_r3_360;
                MKMaterial_SetMaterial(temp_r3_360);
                MKPrimitive(0xC, 0x10);
            }
            M2C_STRUCT_COPY((s32) &arg_sp1AC + 4, (s32) (&identity - 4) + 4, 0x40);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_mul $f0, $f1, $f0 */);
            arg_sp190 = arg_sp20;
            arg_sp28 = M2C_FIELD(temp_r30_617, f32 *, 0x88) * M2C_FIELD(temp_r30_617, f32 *, 0x98);
            arg_sp198 = (f64) arg_sp28;
            arg_sp1B0.Scale3x3((Matrix *) &arg_sp1B0, *((MKVector3 *) &arg_sp190));
            arg_sp1E0 = M2C_FIELD(temp_r30_617, f32 *, 0x70);
            arg_sp1E4 = M2C_FIELD(temp_r30_617, f32 *, 0x74);
            arg_sp1E8 = M2C_FIELD(temp_r30_617, f32 *, 0x78);
            arg_sp1EC = 1.0f;
            MKSetMatrix(*((Matrix *) &arg_sp1B0));
            arg_spD8 = 0.0f;
            var_r21_407 = 0;
            arg_spD0 = 0.0f;
            arg_spD4 = 100.0f;
            arg_sp1A8 = (f64) arg_spD8;
            arg_sp1A0 = (f64) arg_spD0;
            do {
                if (var_r21_407 != 0) {
                    arg_sp10 = -(f32) arg_sp1A0;
                    arg_sp14 = -arg_sp1A4;
                    arg_sp18 = -(f32) arg_sp1A8;
                    arg_sp180 = (f64) arg_sp10;
                    arg_sp188 = (f64) arg_sp18;
                    arg_sp1A0 = (f64) arg_sp10;
                    arg_sp1A8 = (f64) arg_sp18;
                }
                MKBegin(0x2A);
                var_r22_436 = 0;
                var_r26_437 = 0;
loop_12:
                temp_f14_445 = (f32) var_r22_436 / 20.0f;
                temp_f1_449 = _table_sinf((6.2831855f * this->unk50) + (10.0f * (3.1415927f * temp_f14_445)));
                arg_spC0 = 1.0f;
                temp_f14_452 = 6.0f * temp_f14_445;
                arg_spC4 = 1.0f;
                arg_spC8 = 1.0f;
                arg_spCC = 1.0f;
                arg_sp170 = (f64) arg_spC0;
                arg_sp178 = (f64) arg_spC8;
                MKSetColorV(*((MKVector4 *) &arg_sp170));
                MKSetTexCoord1F(0.25f * (M2C_FIELD(temp_r30_617, f32 *, 0x90) * (temp_f14_452 * M2C_FIELD(temp_r30_617, f32 *, 0x80))), 0.95f);
                temp_r23_470 = &arg_sp1F0 + var_r26_437;
                MKSetPositionV(*temp_r23_470);
                arg_spB0 = 0.0f;
                arg_spB4 = 0.0f;
                arg_spB8 = 0.0f;
                arg_spBC = 1.0f;
                arg_sp160 = (f64) arg_spB0;
                arg_sp168 = (f64) arg_spB8;
                MKSetColorV(*((MKVector4 *) &arg_sp160));
                MKSetTexCoord1F(0.25f * (M2C_FIELD(temp_r30_617, f32 *, 0x90) * (temp_f14_452 * M2C_FIELD(temp_r30_617, f32 *, 0x80))), 0.0f);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f19 */);
                arg_sp98 = (f32) arg_sp1A8 * ((0.25f * temp_f1_449) + 1.0f);
                arg_sp130 = arg_sp90;
                arg_sp138 = (f64) arg_sp98;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r23, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f18 */);
                arg_sp140 = arg_spA0;
                arg_spA8 = temp_r23_470->unk8 * ((0.005f * temp_f1_449) + 1.0f);
                arg_sp148 = (f64) arg_spA8;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp150 = arg_sp80;
                arg_sp88 = (f32) arg_sp148 + (f32) arg_sp138;
                arg_sp158 = (f64) arg_sp88;
                MKSetPositionV(*((MKVector3 *) &arg_sp150));
                var_r22_436 += 1;
                var_r26_437 += 0x10;
                if (var_r22_436 < 0x14) {
                    goto loop_12;
                }
                temp_f1_533 = _table_sinf((6.2831855f * this->unk50) + 0.0f);
                arg_sp70 = 1.0f;
                arg_sp74 = 1.0f;
                arg_sp78 = 1.0f;
                arg_sp7C = 1.0f;
                arg_sp120 = (f64) arg_sp70;
                arg_sp128 = (f64) arg_sp78;
                MKSetColorV(*((MKVector4 *) &arg_sp120));
                MKSetTexCoord1F(0.25f * (M2C_FIELD(temp_r30_617, f32 *, 0x90) * (6.0f * M2C_FIELD(temp_r30_617, f32 *, 0x80))), 0.95f);
                MKSetPositionV(*((MKVector3 *) &arg_sp1F0));
                arg_sp60 = 0.0f;
                arg_sp64 = 0.0f;
                arg_sp68 = 0.0f;
                arg_sp6C = 1.0f;
                arg_sp110 = (f64) arg_sp60;
                arg_sp118 = (f64) arg_sp68;
                MKSetColorV(*((MKVector4 *) &arg_sp110));
                MKSetTexCoord1F(0.25f * (M2C_FIELD(temp_r30_617, f32 *, 0x90) * (6.0f * M2C_FIELD(temp_r30_617, f32 *, 0x80))), 0.0f);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f17 */);
                arg_spE0 = arg_sp40;
                arg_sp48 = (f32) arg_sp1A8 * ((0.25f * temp_f1_533) + 1.0f);
                arg_spE8 = (f64) arg_sp48;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f16 */);
                arg_spF0 = arg_sp50;
                arg_sp58 = arg_sp1F8 * ((0.005f * temp_f1_533) + 1.0f);
                arg_spF8 = (f64) arg_sp58;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp100 = arg_sp30;
                arg_sp38 = (f32) arg_spF8 + (f32) arg_spE8;
                arg_sp108 = (f64) arg_sp38;
                MKSetPositionV(*((MKVector3 *) &arg_sp100));
                MKEnd();
                var_r21_407 += 1;
            } while (var_r21_407 < 2);
            var_r28_335 += 4;
            goto loop_15;
        }
    }
    if (var_r29_341 != NULL) {
        MKEndPrimitive();
    }
}
#endif

void ElementalRing::Message(MKMessage *arg0) {
    KDSoundFlangedFader **var_r31_678;
    KDSoundFlangedFader *temp_r3_686;

    var_r31_678 = this->unk4C;
loop_2:
    if (var_r31_678 != NULL) {
        temp_r3_686 = *var_r31_678;
        if (temp_r3_686 != NULL) {
            temp_r3_686->Deinit();
            var_r31_678 += 4;
            goto loop_2;
        }
    }
    MKProp::Message(arg0);
}

#if 0 // DRAFT: undefined identifier 'MKVector'
void ElementalRing::Update() {
    s8 sp189;
    s8 sp188;
    s32 sp184;
    f32 sp180;
    s32 sp17C;
    s8 sp17A;
    s8 sp179;
    s8 sp178;
    f64 sp170;                                      /* compiler-managed */
    f64 sp168;                                      /* compiler-managed */
    u32 sp164;
    s32 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    s32 sp13C;
    s32 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    M2C_UNK sp108;
    f64 sp100;
    f64 spF8;
    M2C_UNK spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f64 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDSoundFlangedFader **temp_r3_886;
    KDSoundFlangedFader **var_r30_722;
    KDSoundFlangedFader *temp_r31_1068;
    KDSoundFlangedFader *temp_r4_889;
    f32 temp_f1_811;
    f32 temp_f1_834;
    f32 temp_f1_942;
    f32 temp_f1_975;
    f32 temp_f1_997;
    f32 temp_f25_982;
    f32 temp_f26_921;
    f32 temp_f27_919;
    f32 temp_f2_980;
    f32 temp_f30_830;
    f32 temp_f31_764;
    f32 temp_f4_912;
    f32 temp_f5_911;
    f32 temp_f6_915;
    f32 var_f0_810;
    s32 temp_r0_725;
    s32 temp_r0_748;
    s32 temp_r0_897;
    u32 temp_r4_1010;
    u8 var_r6_730;
    void *temp_r3_952;
    void *temp_r3_985;

    var_r30_722 = this->unk4C;
loop_40:
    if (var_r30_722 != NULL) {
        temp_r31_1068 = *var_r30_722;
        if (temp_r31_1068 != NULL) {
            temp_r0_725 = M2C_FIELD(temp_r31_1068, s32 *, 0xB4);
            var_r6_730 = 0;
            if ((temp_r0_725 == 1) || (temp_r0_725 == 2) || (temp_r0_725 == 3)) {
                var_r6_730 = 1;
            }
            temp_r31_1068->Update(M2C_FIELD(temp_r31_1068, s32 *, 0xB8), 1U, var_r6_730, NULL, (MKVector3 *) (temp_r31_1068 + 0x70), 0U, -1);
            M2C_FIELD(temp_r31_1068, f32 *, 0xA0) = (f32) (M2C_FIELD(temp_r31_1068, f32 *, 0xA0) - gUpdateTimeDelta);
            temp_r0_748 = M2C_FIELD(temp_r31_1068, s32 *, 0xB4);
            switch (temp_r0_748) {                  /* irregular */
            case 0:
                break;
            case 1:
                temp_f31_764 = gUpdateTimeDelta;
                MKVector(4.0f, 1.0f, 4.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                sp118 = sp28;
                sp30 = sp110 * temp_f31_764;
                sp120 = (f64) sp30;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
                M2C_FIELD(temp_r31_1068, f32 *, 0x88) = (f32) (M2C_FIELD(temp_r31_1068, f32 *, 0x88) + (f32) sp120);
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (M2C_FIELD(temp_r31_1068, f32 *, 0xA0) == 0.0f) {
                    M2C_FIELD(temp_r31_1068, s32 *, 0xB4) = 2;
                    M2C_FIELD(temp_r31_1068, f32 *, 0xA0) = (f32) M2C_FIELD(temp_r31_1068, f32 *, 0xA8);
                }
                break;
            case 2:
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (M2C_FIELD(temp_r31_1068, f32 *, 0xA0) == 0.0f) {
                    M2C_FIELD(temp_r31_1068, s32 *, 0xB4) = 3;
                    M2C_FIELD(temp_r31_1068, f32 *, 0xA0) = (f32) M2C_FIELD(temp_r31_1068, f32 *, 0xAC);
                }
                break;
            case 3:
                var_f0_810 = M2C_FIELD(temp_r31_1068, f32 *, 0xA0);
                temp_f1_811 = M2C_FIELD(temp_r31_1068, f32 *, 0xAC);
                if (var_f0_810 < temp_f1_811) {

                } else {
                    var_f0_810 = temp_f1_811;
                }
                if (var_f0_810 > 0.0f) {

                } else {
                    var_f0_810 = 0.0f;
                }
                temp_f30_830 = gUpdateTimeDelta;
                temp_f1_834 = M2C_FIELD(temp_r31_1068, f32 *, 0xB0) * (0.1f + (1.0f - (var_f0_810 / temp_f1_811)));
                MKVector(temp_f1_834, 0.0f, temp_f1_834);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                spF8 = sp18;
                sp20 = spF0 * temp_f30_830;
                sp100 = (f64) sp20;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
                M2C_FIELD(temp_r31_1068, f32 *, 0x88) = (f32) (M2C_FIELD(temp_r31_1068, f32 *, 0x88) + (f32) sp100);
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (M2C_FIELD(temp_r31_1068, f32 *, 0xA0) == 0.0f) {
                    M2C_FIELD(temp_r31_1068, s32 *, 0xB4) = 4;
                    KDSound_Play3d(M2C_FIELD(temp_r31_1068, s32 *, 0xBC), (MKVector3 *) (temp_r31_1068 + 0x70), 0U, -1, 0.0f, 0U);
                    M2C_FIELD(temp_r31_1068, f32 *, 0xA0) = 0.5f;
                }
                break;
            case 4:
                M2C_FIELD(temp_r31_1068, f32 *, 0x84) = (f32) (M2C_FIELD(temp_r31_1068, f32 *, 0xA0) / 1.5f);
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (M2C_FIELD(temp_r31_1068, f32 *, 0xA0) == 0.0f) {
                    M2C_FIELD(temp_r31_1068, s32 *, 0xB4) = 0;
                    M2C_FIELD(temp_r31_1068, f32 *, 0xA0) = 0.0f;
                    temp_r3_886 = this->unk4C;
                    this->unk4C = temp_r3_886 + 4;
                    temp_r4_889 = *temp_r3_886;
                    *temp_r3_886 = *var_r30_722;
                    *var_r30_722 = temp_r4_889;
                }
                break;
            }
            if (((u8) M2C_FIELD(temp_r31_1068, u8 *, 0xC8) != 0) && ((temp_r0_897 = M2C_FIELD(temp_r31_1068, s32 *, 0xB4), ((temp_r0_897 == 3) != 0)) || (temp_r0_897 == 1) || (temp_r0_897 == 2))) {
                sp80 = 0.0f;
                temp_f5_911 = M2C_FIELD(temp_r31_1068, f32 *, 0x94);
                temp_f4_912 = M2C_FIELD(temp_r31_1068, f32 *, 0x84);
                sp78 = 0.0f;
                temp_f6_915 = 100.0f * (M2C_FIELD(temp_r31_1068, f32 *, 0x90) * M2C_FIELD(temp_r31_1068, f32 *, 0x80));
                sp7C = 100.0f;
                temp_f27_919 = temp_f6_915 - 50.0f;
                temp_f26_921 = temp_f6_915 + 50.0f;
                spD0 = (f64) sp80;
                spC8 = (f64) sp78;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                spD8 = sp68;
                sp70 = (f32) spD0 * (temp_f5_911 * temp_f4_912);
                spE0 = (f64) sp70;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                temp_f1_942 = (f32) spE0 * 0.5f;
                sp128 = sp58;
                sp60 = temp_f1_942;
                sp130 = (f64) sp60;
                temp_r3_952 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, f32, f32, f32, f32, f32, f32), 0xC)(gb, temp_f1_942, 50.0f, 100.0f, temp_f4_912, temp_f5_911, temp_f6_915), void **, 8);
                spA8 = M2C_FIELD(temp_r3_952, f64 *, 0x30);
                spB0 = M2C_FIELD(temp_r3_952, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                spB8 = sp48;
                sp50 = M2C_FIELD(temp_r31_1068, f32 *, 0x78) - (f32) spB0;
                temp_f1_975 = (f32) spB8 * (f32) spB8;
                spC0 = (f64) sp50;
                temp_f2_980 = (f32) spC0 * (f32) spC0;
                temp_f25_982 = temp_f2_980 + (temp_f1_975 + (unkspBC * unkspBC));
                temp_r3_985 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, f32, f32), 0xC)(gb, temp_f1_975, temp_f2_980), void **, 8);
                sp98 = M2C_FIELD(temp_r3_985, f64 *, 0x30);
                spA0 = M2C_FIELD(temp_r3_985, f64 *, 0x38);
                if ((temp_f25_982 > (temp_f27_919 * temp_f27_919)) && (temp_f25_982 < (temp_f26_921 * temp_f26_921))) {
                    temp_f1_997 = M2C_FIELD(temp_r31_1068, f32 *, 0x74);
                    if ((unksp9C > temp_f1_997) && (unksp9C < (temp_f1_997 + unksp12C))) {
                        sp13C = 0;
                        temp_r4_1010 = M2C_FIELD(temp_r31_1068, u32 *, 0xC4);
                        sp10 = 0.0f;
                        sp8 = 0.0f;
                        spC = 0.0f;
                        sp90 = (f64) sp10;
                        sp88 = (f64) sp8;
                        sp138 = 7;
                        sp160 = 1;
                        sp164 = temp_r4_1010;
                        sp140 = (f64) sp8;
                        sp148 = (f64) sp10;
                        sp178 = 1;
                        sp184 = 2;
                        sp180 = 10.0f;
                        sp179 = 0;
                        sp17A = 1;
                        sp17C = -1;
                        sp150 = M2C_FIELD(&one, f64 *, 0);
                        sp158 = M2C_FIELD(&one, f64 *, 8);
                        sp188 = 0;
                        if (temp_r4_1010 != 0U) {
                            sp38.GetPos();
                            sp168 = sp38;
                            sp170 = sp40;
                        } else {
                            sp168 = 0.0f;
                            unksp16C = 0.0f;
                            sp170 = 0.0f;
                        }
                        sp189 = 0;
                        sp17C = GS_CCElementalRingSpyroBurn;
                        M2C_FIELD(*gb, M2C_UNK (**)(void **, s32 *), 0x1C)(gb, &sp138);
                    }
                }
            }
            var_r30_722 += 4;
            goto loop_40;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void ElementalRing::Init() {
    KDSoundFlangedFader **temp_r3_1124;
    KDSoundFlangedFader **temp_r3_1130;
    KDSoundFlangedFader **var_r3_1109;
    KDSoundFlangedFader **var_r5_1118;
    MKHeap *temp_r3_1102;
    s32 var_ctr_1122;

    MKProp::Init();
    temp_r3_1102 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1102 != NULL) {
        var_r3_1109 = ((MKHeap *) (temp_r3_1102->Current()))->Alloc(0x358, NULL, 0);
    } else {
        var_r3_1109 = malloc(0x358);
    }
    this->unk4C = var_r3_1109;
    var_r5_1118 = this->unk4C;
    this->unk4C = var_r5_1118 + 0x340;
    M2C_FIELD(var_r5_1118, s32 *, 0x340) = 0;
    var_ctr_1122 = 4;
    do {
        temp_r3_1124 = this->unk4C;
        this->unk4C = temp_r3_1124 + 4;
        M2C_FIELD(temp_r3_1124, KDSoundFlangedFader ***, 4) = var_r5_1118;
        var_r5_1118 += 0xD0;
        var_ctr_1122 -= 1;
    } while (var_ctr_1122 != 0);
    temp_r3_1130 = this->unk4C;
    this->unk4C = temp_r3_1130 + 4;
    M2C_FIELD(temp_r3_1130, KDSoundFlangedFader ***, 4) = NULL;
    this->unk50 = 0.0f;
}
#endif

#if 0 // DRAFT: function call 'MKMaterial_Destroy(ElementalRingDescriptor)' does not match
void ElementalRingDescriptor::Deinit() {
    s32 var_r30_1152;
    s32 var_r31_1153;

    var_r30_1152 = 0;
    var_r31_1153 = 0;
    do {
        MKMaterial_Destroy(*(this + (var_r31_1153 + 0x60)));
        var_r30_1152 += 1;
        var_r31_1153 += 4;
    } while (var_r30_1152 < 5);
    MKPropDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: function call 'MKMaterial_Create(signed char[97])' does not match
void ElementalRingDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = MKMaterial_Create(lit_stringBase0);
    this->unk64 = MKMaterial_Create(&lit_stringBase0[0x13]);
    this->unk68 = MKMaterial_Create(&lit_stringBase0[0x26]);
    this->unk6C = MKMaterial_Create(&lit_stringBase0[0x38]);
    this->unk70 = MKMaterial_Create(&lit_stringBase0[0x4C]);
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ElementalRingDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
