#include "spyro/source/ElementalRing.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
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
        temp_r3_225 = ((MKHeap *) var_r3_200)->Current();
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

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void ElementalRing::Draw() {
    MKVector3 sp1F0;
    Matrix sp1B0;
    M2C_UNK sp1AC;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    KDSoundFlangedFader **var_r28_335;
    KDSoundFlangedFader *temp_r30_617;
    MKMaterial *temp_r3_360;
    MKMaterial *var_r29_341;
    MKVector3 *temp_r23_470;
    f32 temp_f14_445;
    f32 temp_f14_452;
    f32 temp_f1_449;
    f32 temp_f1_490;
    f32 temp_f1_533;
    f32 temp_f24_317;
    f32 temp_f24_322;
    f32 temp_f2_496;
    f32 temp_f2_571;
    f32 temp_f3_576;
    f64 temp_f0_383;
    f64 temp_f0_504;
    f64 temp_f0_515;
    f64 temp_f0_574;
    f64 temp_f0_586;
    f64 temp_f0_597;
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
        temp_r3_326 = &sp1F0 + var_r26_300;
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
            M2C_STRUCT_COPY((s32) &sp1AC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_f0_383 = M2C_FIELD(temp_r30_617, f64 *, 0x80) * M2C_FIELD(temp_r30_617, f64 *, 0x90);
            sp20 = temp_f0_383;
            sp190 = temp_f0_383;
            sp28 = M2C_FIELD(temp_r30_617, f32 *, 0x88) * M2C_FIELD(temp_r30_617, f32 *, 0x98);
            sp198 = (f64) sp28;
            sp1B0.Scale3x3(&sp1B0, *((MKVector3 *) &sp190));
            sp1B0.unk30 = M2C_FIELD(temp_r30_617, f32 *, 0x70);
            sp1B0.unk34 = M2C_FIELD(temp_r30_617, f32 *, 0x74);
            sp1B0.unk38 = M2C_FIELD(temp_r30_617, f32 *, 0x78);
            sp1B0.unk3C = 1.0f;
            MKSetMatrix(sp1B0);
            spD8 = 0.0f;
            var_r21_407 = 0;
            spD0 = 0.0f;
            spD4 = 100.0f;
            sp1A8 = (f64) spD8;
            sp1A0 = (f64) spD0;
            do {
                if (var_r21_407 != 0) {
                    sp10 = -(f32) sp1A0;
                    sp14 = -(*(f32 *) ((u8 *) &sp1A0 + 0x4));
                    sp18 = -(f32) sp1A8;
                    sp180 = (f64) sp10;
                    sp188 = (f64) sp18;
                    sp1A0 = (f64) sp10;
                    sp1A8 = (f64) sp18;
                }
                MKBegin(0x2A);
                var_r22_436 = 0;
                var_r26_437 = 0;
loop_12:
                temp_f14_445 = (f32) var_r22_436 / 20.0f;
                temp_f1_449 = _table_sinf((6.2831855f * this->unk50) + (10.0f * (3.1415927f * temp_f14_445)));
                spC0 = 1.0f;
                temp_f14_452 = 6.0f * temp_f14_445;
                spC4 = 1.0f;
                spC8 = 1.0f;
                spCC = 1.0f;
                sp170 = (f64) spC0;
                sp178 = (f64) spC8;
                MKSetColorV(*((MKVector4 *) &sp170));
                MKSetTexCoord1F(0.25f * ((f32) M2C_FIELD(temp_r30_617, f64 *, 0x90) * (temp_f14_452 * (f32) M2C_FIELD(temp_r30_617, f64 *, 0x80))), 0.95f);
                temp_r23_470 = &sp1F0 + var_r26_437;
                MKSetPositionV(*temp_r23_470);
                spB0 = 0.0f;
                spB4 = 0.0f;
                spB8 = 0.0f;
                spBC = 1.0f;
                sp160 = (f64) spB0;
                sp168 = (f64) spB8;
                MKSetColorV(*((MKVector4 *) &sp160));
                MKSetTexCoord1F(0.25f * ((f32) M2C_FIELD(temp_r30_617, f64 *, 0x90) * (temp_f14_452 * (f32) M2C_FIELD(temp_r30_617, f64 *, 0x80))), 0.0f);
                temp_f1_490 = (0.25f * temp_f1_449) + 1.0f;
                sp90 = sp1A0 * (f64) temp_f1_490;
                temp_f2_496 = (0.005f * temp_f1_449) + 1.0f;
                sp98 = (f32) sp1A8 * temp_f1_490;
                sp130 = sp90;
                sp138 = (f64) sp98;
                temp_f0_504 = M2C_FIELD(temp_r23_470, f64 *, 0) * (f64) temp_f2_496;
                spA0 = temp_f0_504;
                sp140 = temp_f0_504;
                spA8 = temp_r23_470->unk8 * temp_f2_496;
                sp148 = (f64) spA8;
                temp_f0_515 = sp140 + sp130;
                sp80 = temp_f0_515;
                sp150 = temp_f0_515;
                sp88 = (f32) sp148 + (f32) sp138;
                sp158 = (f64) sp88;
                MKSetPositionV(*((MKVector3 *) &sp150));
                var_r22_436 += 1;
                var_r26_437 += 0x10;
                if (var_r22_436 < 0x14) {
                    goto loop_12;
                }
                temp_f1_533 = _table_sinf((6.2831855f * this->unk50) + 0.0f);
                sp70 = 1.0f;
                sp74 = 1.0f;
                sp78 = 1.0f;
                sp7C = 1.0f;
                sp120 = (f64) sp70;
                sp128 = (f64) sp78;
                MKSetColorV(*((MKVector4 *) &sp120));
                MKSetTexCoord1F(0.25f * ((f32) M2C_FIELD(temp_r30_617, f64 *, 0x90) * (6.0f * (f32) M2C_FIELD(temp_r30_617, f64 *, 0x80))), 0.95f);
                MKSetPositionV(sp1F0);
                sp60 = 0.0f;
                sp64 = 0.0f;
                sp68 = 0.0f;
                sp6C = 1.0f;
                sp110 = (f64) sp60;
                sp118 = (f64) sp68;
                MKSetColorV(*((MKVector4 *) &sp110));
                MKSetTexCoord1F(0.25f * ((f32) M2C_FIELD(temp_r30_617, f64 *, 0x90) * (6.0f * (f32) M2C_FIELD(temp_r30_617, f64 *, 0x80))), 0.0f);
                temp_f2_571 = (0.25f * temp_f1_533) + 1.0f;
                temp_f0_574 = sp1A0 * (f64) temp_f2_571;
                sp40 = temp_f0_574;
                temp_f3_576 = (0.005f * temp_f1_533) + 1.0f;
                spE0 = temp_f0_574;
                sp48 = (f32) sp1A8 * temp_f2_571;
                spE8 = (f64) sp48;
                temp_f0_586 = sp1F0 * (f64) temp_f3_576;
                sp50 = temp_f0_586;
                spF0 = temp_f0_586;
                sp58 = sp1F0.unk8 * temp_f3_576;
                spF8 = (f64) sp58;
                temp_f0_597 = spF0 + temp_f0_574;
                sp30 = temp_f0_597;
                sp100 = temp_f0_597;
                sp38 = (f32) spF8 + (f32) spE8;
                sp108 = (f64) sp38;
                MKSetPositionV(*((MKVector3 *) &sp100));
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
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spE8;
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
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
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
    f32 temp_f28_917;
    f32 temp_f2_980;
    f32 temp_f30_830;
    f32 temp_f31_764;
    f32 temp_f4_912;
    f32 temp_f5_911;
    f32 temp_f6_915;
    f32 var_f0_810;
    f64 temp_f0_770;
    f64 temp_f0_839;
    f64 temp_f0_925;
    f64 temp_f0_936;
    f64 temp_f0_960;
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
                temp_f0_770 = sp108 * (f64) temp_f31_764;
                sp28 = temp_f0_770;
                sp118 = temp_f0_770;
                sp30 = sp110 * temp_f31_764;
                sp120 = (f64) sp30;
                M2C_FIELD(temp_r31_1068, f64 *, 0x80) = (f64) (M2C_FIELD(temp_r31_1068, f64 *, 0x80) + temp_f0_770);
                M2C_FIELD(temp_r31_1068, f32 *, 0x88) = (f32) (M2C_FIELD(temp_r31_1068, f32 *, 0x88) + (f32) sp120);
                if (M2C_FIELD(temp_r31_1068, f32 *, 0xA0) <= 0.0f) {
                    M2C_FIELD(temp_r31_1068, s32 *, 0xB4) = 2;
                    M2C_FIELD(temp_r31_1068, f32 *, 0xA0) = (f32) M2C_FIELD(temp_r31_1068, f32 *, 0xA8);
                }
                break;
            case 2:
                if (M2C_FIELD(temp_r31_1068, f32 *, 0xA0) <= 0.0f) {
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
                temp_f0_839 = spE8 * (f64) temp_f30_830;
                sp18 = temp_f0_839;
                spF8 = temp_f0_839;
                sp20 = spF0 * temp_f30_830;
                sp100 = (f64) sp20;
                M2C_FIELD(temp_r31_1068, f64 *, 0x80) = (f64) (M2C_FIELD(temp_r31_1068, f64 *, 0x80) + temp_f0_839);
                M2C_FIELD(temp_r31_1068, f32 *, 0x88) = (f32) (M2C_FIELD(temp_r31_1068, f32 *, 0x88) + (f32) sp100);
                if (M2C_FIELD(temp_r31_1068, f32 *, 0xA0) <= 0.0f) {
                    M2C_FIELD(temp_r31_1068, s32 *, 0xB4) = 4;
                    KDSound_Play3d(M2C_FIELD(temp_r31_1068, s32 *, 0xBC), (MKVector3 *) (temp_r31_1068 + 0x70), 0U, -1, 0.0f, 0U);
                    M2C_FIELD(temp_r31_1068, f32 *, 0xA0) = 0.5f;
                }
                break;
            case 4:
                M2C_FIELD(temp_r31_1068, f32 *, 0x84) = (f32) (M2C_FIELD(temp_r31_1068, f32 *, 0xA0) / 1.5f);
                if (M2C_FIELD(temp_r31_1068, f32 *, 0xA0) <= 0.0f) {
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
                temp_f6_915 = 100.0f * (M2C_FIELD(temp_r31_1068, f32 *, 0x90) * (f32) M2C_FIELD(temp_r31_1068, f64 *, 0x80));
                temp_f28_917 = temp_f5_911 * temp_f4_912;
                sp7C = 100.0f;
                temp_f27_919 = temp_f6_915 - 50.0f;
                temp_f26_921 = temp_f6_915 + 50.0f;
                spD0 = (f64) sp80;
                spC8 = (f64) sp78;
                temp_f0_925 = spC8 * (f64) temp_f28_917;
                sp68 = temp_f0_925;
                spD8 = temp_f0_925;
                sp70 = (f32) spD0 * temp_f28_917;
                spE0 = (f64) sp70;
                temp_f0_936 = temp_f0_925 * 5.222099017e-315;
                sp58 = temp_f0_936;
                temp_f1_942 = (f32) spE0 * 0.5f;
                sp128 = temp_f0_936;
                sp60 = temp_f1_942;
                sp130 = (f64) sp60;
                temp_r3_952 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, f32, f32, f32, f32, f32, f32), 0xC)(gb, temp_f1_942, 50.0f, 100.0f, temp_f4_912, temp_f5_911, temp_f6_915), void **, 8);
                spA8 = M2C_FIELD(temp_r3_952, f64 *, 0x30);
                spB0 = M2C_FIELD(temp_r3_952, f64 *, 0x38);
                temp_f0_960 = M2C_FIELD(temp_r31_1068, f64 *, 0x70) - spA8;
                sp48 = temp_f0_960;
                spB8 = temp_f0_960;
                sp50 = M2C_FIELD(temp_r31_1068, f32 *, 0x78) - (f32) spB0;
                temp_f1_975 = (f32) spB8 * (f32) spB8;
                spC0 = (f64) sp50;
                temp_f2_980 = (f32) spC0 * (f32) spC0;
                temp_f25_982 = temp_f2_980 + (temp_f1_975 + ((*(f32 *) ((u8 *) &spB8 + 0x4)) * (*(f32 *) ((u8 *) &spB8 + 0x4))));
                temp_r3_985 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, f32, f32), 0xC)(gb, temp_f1_975, temp_f2_980), void **, 8);
                sp98 = M2C_FIELD(temp_r3_985, f64 *, 0x30);
                spA0 = M2C_FIELD(temp_r3_985, f64 *, 0x38);
                if ((temp_f25_982 > (temp_f27_919 * temp_f27_919)) && (temp_f25_982 < (temp_f26_921 * temp_f26_921))) {
                    temp_f1_997 = M2C_FIELD(temp_r31_1068, f32 *, 0x74);
                    if (((*(f32 *) ((u8 *) &sp98 + 0x4)) > temp_f1_997) && ((*(f32 *) ((u8 *) &sp98 + 0x4)) < (temp_f1_997 + (*(f32 *) ((u8 *) &sp128 + 0x4))))) {
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
                        sp150 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                        sp158 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                        sp188 = 0;
                        if (temp_r4_1010 != 0U) {
                            ((MKProp *) &sp38)->GetPos();
                            sp168 = sp38;
                            sp170 = sp40;
                        } else {
                            sp168 = 0.0f;
                            (*(f32 *) ((u8 *) &sp164 + 0x8)) = 0.0f;
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

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void ElementalRingDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = MKMaterial_Create("FX_RingElementFire");
    this->unk64 = MKMaterial_Create("FX_RingElementElec");
    this->unk68 = MKMaterial_Create("FX_RingElementIce");
    this->unk6C = MKMaterial_Create("FX_RingElementEarth");
    this->unk70 = MKMaterial_Create("FX_RingElementConvex");
}
#endif
