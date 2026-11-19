#include "spyro/source/MoltenMetalBucketTrack.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
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
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/LiquidFX.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/MoltenMetalBucket.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

extern f32 *KDSpline_PositionMixer;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
static s32 lit_616 = 2;
static s32 lit_618 = 0x05F5E0FF;

#if 0 // DRAFT: illegal explicit conversion from 'float' to 'signed char *'
void MoltenMetalBucketTrack::Message(MKMessage *arg0) {
    f32 temp_r3_54;
    s32 temp_r0_47;

    temp_r0_47 = arg0->unk0;
    if (temp_r0_47 < -2) {
        if (temp_r0_47 < -4) {

        } else {
            temp_r3_54 = this->unk4C.unk28;
            M2C_FIELD(M2C_FIELD(temp_r3_54, void **, 0x44), M2C_UNK (**)(f32), 0x2C)(temp_r3_54);
        }
    }
    MKProp::Message(arg0);
}
#endif

#if 0 // DRAFT: ')' expected
void MoltenMetalBucketTrack::Draw() {
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;                                       /* compiler-managed */
    KDUniformSpline spA0;
    f64 sp98;
    f64 sp90;
    MKVector3 sp80;
    f64 sp78;
    KDUniformSpline sp60;
    f64 sp58;
    f64 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f27_151;
    f64 temp_f0_167;
    s32 temp_r0_104;
    s32 var_r29_135;
    s32 var_r30_109;
    s32 var_r3_100;

    MKMaterial_SetMaterial(M2C_FIELD(checked_cast<MoltenMetalBucketTrackDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x80));
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(Matrix::identity);
    var_r3_100 = lit_618;
    temp_r0_104 = (s32) (this->unk4C.unk8 / 300.0f);
    if (temp_r0_104 < var_r3_100) {
        var_r3_100 = temp_r0_104;
    }
    var_r30_109 = lit_616;
    if (var_r3_100 > var_r30_109) {
        var_r30_109 = var_r3_100;
    }
    sp40 = 1.0f;
    sp44 = 1.0f;
    sp48 = 1.0f;
    sp4C = 1.0f;
    spD0 = (f64) sp40;
    spD8 = (f64) sp48;
    MKBegin(var_r30_109 * 2);
    var_r29_135 = 0;
loop_6:
    if (var_r29_135 < var_r30_109) {
        spC = 0.0f;
        temp_f27_151 = (f32) var_r29_135 * (1.0f / (f32) (var_r30_109 - 1));
        spA0.GetMeasure(temp_f27_151, (Matrix *) &this->unk4C.unk14, KDSpline_PositionMixer);
        spA0.unk10 = M2C_BITWISE(f64, spA0);
        spB8 = (f64) spA0.unk8;
        sp8 = 0.0f;
        sp60.GetMeasure(temp_f27_151, &this->unk4C, KDSpline_PositionMixer);
        temp_f0_167 = M2C_BITWISE(f64, sp60) - M2C_BITWISE(f64, spA0.unk10);
        sp10 = temp_f0_167;
        sp60.unk10 = temp_f0_167;
        sp18 = sp60.unk8 - (f32) spB8;
        sp78 = (f64) sp18;
        sp80.operator*(0.5f);
        sp30 = M2C_BITWISE(f64, spA0.unk10) + M2C_BITWISE(f64, sp80);
        sp20 = 0.0f;
        sp24 = 100.0f;
        sp38 = (f32) spB8 + sp80.unk8;
        sp28 = 0.0f;
        sp50 = (f64) sp20;
        sp90 = sp30;
        sp98 = (f64) sp38;
        spC0 = sp30;
        spC8 = (f64) sp38;
        sp58 = (f64) sp28;
        spA0.unk10 = M2C_BITWISE(f64, spA0.unk10) + sp50;
        spB8 = (f32) spB8 + (f32) sp58;
        MKSetColorV(*((MKVector4 *) &spD0));
        MKSetTexCoord1F(1.0f, (f32) var_r29_135);
        MKSetPositionV(*((MKVector3 *) &spC0));
        MKSetColorV(*((MKVector4 *) &spD0));
        MKSetTexCoord1F(0.0f, (f32) var_r29_135);
        MKSetPositionV(*((MKVector3 *) &spA0.unk10));
        var_r29_135 += 1;
        goto loop_6;
    }
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to 'MoltenMetalBucket *'
void *MoltenMetalBucketTrack::Update() {
    f32 sp24C;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp234;
    f32 sp230;
    f32 sp22C;
    f32 sp228;
    f32 sp224;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    KDUniformSpline sp170;
    f64 sp160;
    f64 sp150;
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
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f64 sp70;
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
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f30_397;
    f32 temp_f3_276;
    f32 temp_f8_820;
    f32 var_f29_400;
    f32 var_f3_688;
    f32 var_f3_797;
    f32 var_f4_621;
    f32 var_f4_730;
    f32 var_f5_588;
    f32 var_f6_521;
    f64 temp_f1_627;
    f64 temp_f1_633;
    f64 temp_f1_637;
    f64 temp_f1_736;
    f64 temp_f1_742;
    f64 temp_f1_746;
    f64 temp_f2_471;
    f64 temp_f2_482;
    f64 temp_f2_493;
    f64 temp_f3_527;
    f64 temp_f3_533;
    f64 temp_f3_537;
    s32 temp_r0_275;
    s32 temp_r3_556;
    s32 temp_r3_656;
    s32 temp_r3_765;
    s32 var_r0_566;
    s32 var_r0_666;
    s32 var_r0_775;

    MKProp::Update();
    temp_r0_275 = this->unkE4;
    temp_f3_276 = 500.0f / this->unk4C.unk8;
    switch (temp_r0_275) {                          /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        this->unkE8 -= gUpdateTimeDelta;
        if (this->unkE8 <= 0.0f) {
            ((MoltenMetalBucket *) (M2C_BITWISE(MoltenMetalBucket *, this->unk4C.unk28)))->Start();
            this->unkE4 = 1;
            this->unkE8 = 3.0f;
        }
        break;
    case 1:                                         /* switch 1 */
        this->unk4C.unk2C += temp_f3_276 * gUpdateTimeDelta;
        if (this->unk4C.unk2C >= 0.99f) {
            ((MoltenMetalBucket *) (M2C_BITWISE(MoltenMetalBucket *, this->unk4C.unk28)))->Stop();
            this->unk4C.unk2C = 0.99f;
            this->unkE4 = 2;
            this->unkE8 = 3.0f;
        }
        break;
    case 2:                                         /* switch 1 */
        this->unkE8 -= gUpdateTimeDelta;
        if (this->unkE8 <= 0.0f) {
            ((MoltenMetalBucket *) (M2C_BITWISE(MoltenMetalBucket *, this->unk4C.unk28)))->Pour();
            this->unkE4 = 3;
            this->unkE8 = 3.0f;
        }
        break;
    case 3:                                         /* switch 1 */
        this->unkE8 -= gUpdateTimeDelta;
        if (this->unkE8 <= 0.0f) {
            ((MoltenMetalBucket *) (M2C_BITWISE(MoltenMetalBucket *, this->unk4C.unk28)))->PourStop();
            this->unkE4 = 4;
            this->unkE8 = 3.0f;
        }
        break;
    case 4:                                         /* switch 1 */
        this->unkE8 -= gUpdateTimeDelta;
        if (this->unkE8 <= 0.0f) {
            ((MoltenMetalBucket *) (M2C_BITWISE(MoltenMetalBucket *, this->unk4C.unk28)))->Stop();
            this->unkE4 = 5;
            this->unkE8 = 3.0f;
        }
        break;
    case 5:                                         /* switch 1 */
        this->unk4C.unk2C = -((temp_f3_276 * gUpdateTimeDelta) - this->unk4C.unk2C);
        if (this->unk4C.unk2C <= 0.0f) {
            ((MoltenMetalBucket *) (M2C_BITWISE(MoltenMetalBucket *, this->unk4C.unk28)))->Start();
            this->unk4C.unk2C = 0.0f;
            this->unkE4 = 0;
            this->unkE8 = 3.0f;
        }
        break;
    }
    temp_f30_397 = this->unk4C.unk2C;
    var_f29_400 = 0.01f + temp_f30_397;
    if (var_f29_400 > 1.0f) {
        var_f29_400 = 1.0f;
    }
    sp28 = 0.0f;
    sp170.GetMeasure(temp_f30_397, &this->unk4C, KDSpline_PositionMixer);
    sp200 = M2C_BITWISE(f64, sp170);
    sp208 = (f64) sp170.unk8;
    sp24 = 0.0f;
    ((KDUniformSpline *) &sp160)->GetMeasure(temp_f30_397, (Matrix *) &this->unk4C.unk14, KDSpline_PositionMixer);
    sp1F0 = sp160;
    sp1F8 = sp168;
    sp20 = 0.0f;
    ((KDUniformSpline *) &sp150)->GetMeasure(var_f29_400, &this->unk4C, KDSpline_PositionMixer);
    sp1E0 = sp150;
    sp1E8 = sp158;
    sp1C = 0.0f;
    ((KDUniformSpline *) &sp140)->GetMeasure(var_f29_400, (Matrix *) &this->unk4C.unk14, KDSpline_PositionMixer);
    sp1D0 = sp140;
    sp1D8 = sp148;
    (*(f32 *) ((u8 *) &sp1E0 + 0x4)) = (*(f32 *) ((u8 *) &sp200 + 0x4));
    (*(f32 *) ((u8 *) &sp1D0 + 0x4)) = (*(f32 *) ((u8 *) &sp1F0 + 0x4));
    spD0 = sp200 + sp1F0;
    sp130 = spD0;
    spD8 = (f32) sp208 + (f32) sp1F8;
    sp138 = (f64) spD8;
    temp_f2_471 = spD0 * 5.222099017e-315;
    spC0 = temp_f2_471;
    sp1C0 = temp_f2_471;
    spC8 = (f32) sp138 * 0.5f;
    sp1C8 = (f64) spC8;
    temp_f2_482 = sp1E0 + sp1D0;
    spB0 = temp_f2_482;
    sp120 = temp_f2_482;
    spB8 = (f32) sp1E8 + (f32) sp1D8;
    sp128 = (f64) spB8;
    temp_f2_493 = temp_f2_482 * 5.222099017e-315;
    spA0 = temp_f2_493;
    sp1B0 = temp_f2_493;
    spA8 = (f32) sp128 * 0.5f;
    sp1B8 = (f64) spA8;
    sp90 = sp1C0 - temp_f2_493;
    sp110 = sp90;
    sp98 = (f32) sp1C8 - (f32) sp1B8;
    sp118 = (f64) sp98;
    var_f6_521 = ((f32) sp118 * (f32) sp118) + (((f32) sp110 * (f32) sp110) + ((*(f32 *) ((u8 *) &sp110 + 0x4)) * (*(f32 *) ((u8 *) &sp110 + 0x4))));
    if (var_f6_521 > 1e-12f) {
        if (var_f6_521 > 0.0f) {
            temp_f3_527 = __frsqrte(var_f6_521);
            temp_f3_533 = 0.5 * temp_f3_527 * -(((f64) var_f6_521 * (temp_f3_527 * temp_f3_527)) - 3.0);
            temp_f3_537 = 0.5 * temp_f3_533 * -(((f64) var_f6_521 * (temp_f3_533 * temp_f3_533)) - 3.0);
            var_f6_521 = (f32) ((f64) var_f6_521 * (0.5 * temp_f3_537 * -(((f64) var_f6_521 * (temp_f3_537 * temp_f3_537)) - 3.0)));
        } else if (var_f6_521 < M2C_BITWISE(f32, 0.0)) {
            var_f6_521 = __float_nan;
        } else {
            sp18 = var_f6_521;
            temp_r3_556 = M2C_BITWISE(s32, sp18) & 0x7F800000;
            switch (temp_r3_556) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                    var_r0_566 = 1;
                } else {
                    var_r0_566 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                    var_r0_566 = 5;
                } else {
                    var_r0_566 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_566 = 4;
                break;
            }
            if (var_r0_566 == 1) {
                var_f6_521 = __float_nan;
            }
        }
        var_f5_588 = 1.0f / var_f6_521;
    } else {
        var_f5_588 = 0.0f;
    }
    sp84 = (*(f32 *) ((u8 *) &sp110 + 0x4)) * var_f5_588;
    sp80 = (f32) sp110 * var_f5_588;
    sp88 = (f32) sp118 * var_f5_588;
    sp1A0 = (f64) sp80;
    sp1A8 = (f64) sp88;
    sp70 = sp200 - sp1F0;
    sp78 = (f32) sp208 - (f32) sp1F8;
    sp100 = sp70;
    sp108 = (f64) sp78;
    var_f4_621 = ((f32) sp108 * (f32) sp108) + (((f32) sp100 * (f32) sp100) + ((*(f32 *) ((u8 *) &sp100 + 0x4)) * (*(f32 *) ((u8 *) &sp100 + 0x4))));
    if (var_f4_621 > 1e-12f) {
        if (var_f4_621 > 0.0f) {
            temp_f1_627 = __frsqrte(var_f4_621);
            temp_f1_633 = 0.5 * temp_f1_627 * -(((f64) var_f4_621 * (temp_f1_627 * temp_f1_627)) - 3.0);
            temp_f1_637 = 0.5 * temp_f1_633 * -(((f64) var_f4_621 * (temp_f1_633 * temp_f1_633)) - 3.0);
            var_f4_621 = (f32) ((f64) var_f4_621 * (0.5 * temp_f1_637 * -(((f64) var_f4_621 * (temp_f1_637 * temp_f1_637)) - 3.0)));
        } else if (var_f4_621 < M2C_BITWISE(f32, 0.0)) {
            var_f4_621 = __float_nan;
        } else {
            sp14 = var_f4_621;
            temp_r3_656 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_656) {                  /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_666 = 1;
                } else {
                    var_r0_666 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_666 = 5;
                } else {
                    var_r0_666 = 3;
                }
                break;
            default:                                /* switch 3 */
                var_r0_666 = 4;
                break;
            }
            if (var_r0_666 == 1) {
                var_f4_621 = __float_nan;
            }
        }
        var_f3_688 = 1.0f / var_f4_621;
    } else {
        var_f3_688 = 0.0f;
    }
    sp64 = (*(f32 *) ((u8 *) &sp100 + 0x4)) * var_f3_688;
    sp60 = (f32) sp100 * var_f3_688;
    sp68 = (f32) sp108 * var_f3_688;
    sp190 = (f64) sp60;
    sp198 = (f64) sp68;
    sp50 = ((*(f32 *) ((u8 *) &sp1A0 + 0x4)) * (f32) sp198) - ((f32) sp1A8 * (*(f32 *) ((u8 *) &sp190 + 0x4)));
    sp54 = ((f32) sp1A8 * (f32) sp190) - ((f32) sp1A0 * (f32) sp198);
    sp58 = ((f32) sp1A0 * (*(f32 *) ((u8 *) &sp190 + 0x4))) - ((*(f32 *) ((u8 *) &sp1A0 + 0x4)) * (f32) sp190);
    spF0 = (f64) sp50;
    spF8 = (f64) sp58;
    var_f4_730 = ((f32) spF8 * (f32) spF8) + (((f32) spF0 * (f32) spF0) + ((*(f32 *) ((u8 *) &spF0 + 0x4)) * (*(f32 *) ((u8 *) &spF0 + 0x4))));
    if (var_f4_730 > 1e-12f) {
        if (var_f4_730 > 0.0f) {
            temp_f1_736 = __frsqrte(var_f4_730);
            temp_f1_742 = 0.5 * temp_f1_736 * -(((f64) var_f4_730 * (temp_f1_736 * temp_f1_736)) - 3.0);
            temp_f1_746 = 0.5 * temp_f1_742 * -(((f64) var_f4_730 * (temp_f1_742 * temp_f1_742)) - 3.0);
            var_f4_730 = (f32) ((f64) var_f4_730 * (0.5 * temp_f1_746 * -(((f64) var_f4_730 * (temp_f1_746 * temp_f1_746)) - 3.0)));
        } else if (var_f4_730 < M2C_BITWISE(f32, 0.0)) {
            var_f4_730 = __float_nan;
        } else {
            sp10 = var_f4_730;
            temp_r3_765 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_765) {                  /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_775 = 1;
                } else {
                    var_r0_775 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_775 = 5;
                } else {
                    var_r0_775 = 3;
                }
                break;
            default:                                /* switch 4 */
                var_r0_775 = 4;
                break;
            }
            if (var_r0_775 == 1) {
                var_f4_730 = __float_nan;
            }
        }
        var_f3_797 = 1.0f / var_f4_730;
    } else {
        var_f3_797 = 0.0f;
    }
    sp44 = (*(f32 *) ((u8 *) &spF0 + 0x4)) * var_f3_797;
    sp40 = (f32) spF0 * var_f3_797;
    sp48 = (f32) spF8 * var_f3_797;
    sp170.unk10 = (f64) sp40;
    sp188 = (f64) sp48;
    temp_f8_820 = M2C_BITWISE(f32, sp170.unk10);
    sp38 = (temp_f8_820 * (*(f32 *) ((u8 *) &sp1A0 + 0x4))) - (sp184 * (f32) sp1A0);
    sp30 = (sp184 * (f32) sp1A8) - ((f32) sp188 * (*(f32 *) ((u8 *) &sp1A0 + 0x4)));
    sp34 = ((f32) sp188 * (f32) sp1A0) - (temp_f8_820 * (f32) sp1A8);
    spE8 = (f64) sp38;
    spE0 = (f64) sp30;
    sp190 = (f64) sp30;
    sp198 = (f64) sp38;
    M2C_STRUCT_COPY((s32) &unksp20C + 4, MKModel_GetWorldMatrix(M2C_FIELD(this->unk4C.unk28, MKModel **, 4)) - 4 + 4, 0x40);
    sp240 = (f32) sp1C0;
    sp244 = (*(f32 *) ((u8 *) &sp1C0 + 0x4));
    sp248 = (f32) sp1C8;
    sp24C = 1.0f;
    sp210 = (f32) sp190;
    sp214 = (*(f32 *) ((u8 *) &sp190 + 0x4));
    sp218 = (f32) sp198;
    sp21C = 0.0f;
    sp220 = M2C_BITWISE(f32, sp170.unk10);
    sp224 = sp184;
    sp228 = (f32) sp188;
    sp22C = 0.0f;
    sp230 = (f32) sp1A0;
    sp234 = (*(f32 *) ((u8 *) &sp1A0 + 0x4));
    sp238 = (f32) sp1A8;
    sp23C = 0.0f;
    MKModel_SetWorldMatrix(M2C_FIELD(this->unk4C.unk28, MKModel **, 4), *((Matrix *) &sp210));
}
#endif

f32 MoltenMetalBucketTrack::Resolve() {
    MKProp::Resolve();
    Update();
}

#if 0 // DRAFT: illegal explicit conversion from 'MKIniLine' to 'double'
s32 MoltenMetalBucketTrack::LoadLine(MKIniLine *arg0) {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKIniLine sp58;
    MKVector3 sp48;
    MKVector3 sp38;
    MKIniLine sp28;
    MKVector3 sp18;
    MKVector3 sp8;
    MKIniLine *var_r30_1016;
    MKIniLine *var_r30_942;
    f64 temp_f0_1031;
    f64 temp_f0_957;
    f64 temp_f1_1030;
    f64 temp_f1_956;
    s32 temp_r3_1017;
    s32 temp_r3_943;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("LeftTrack") != 0) {
        var_r30_942 = arg0->unkC->GetSubLine(arg0);
        temp_r3_943 = arg0->GetNmbrOfSubLines();
        if (temp_r3_943 != 0) {
            ((KDUniformSpline *) &this->unk4C)->Init(temp_r3_943, 0U);
loop_9:
            if (var_r30_942 != NULL) {
                sp58.GetVector3((s32) var_r30_942);
                temp_f1_956 = M2C_BITWISE(f64, sp58);
                temp_f0_957 = M2C_BITWISE(f64, sp58.unk8);
                sp78 = temp_f1_956;
                sp80 = temp_f0_957;
                if ((u8) this->unkE0 != 0) {
                    M2C_FIELD(this, f64 *, 0x80) = temp_f1_956;
                    M2C_FIELD(this, f64 *, 0x88) = temp_f0_957;
                    this->unk90 = sp78;
                    this->unk98 = sp80;
                    this->unkE0 = 0;
                } else {
                    Min(sp48, *((MKVector3 *) &this->unk4C.unk34));
                    M2C_FIELD(this, f64 *, 0x80) = M2C_BITWISE(f64, sp48);
                    M2C_FIELD(this, f64 *, 0x88) = (f64) sp48.unk8;
                    Max(sp38, *((MKVector3 *) &this->unk90));
                    this->unk90 = M2C_BITWISE(f64, sp38);
                    this->unk98 = (f64) sp38.unk8;
                }
                ((KDUniformSpline *) &this->unk4C)->AddNode(*((MKVector3 *) &sp78));
                var_r30_942 = var_r30_942->unkC->GetNextLine(var_r30_942);
                goto loop_9;
            }
        }
        return 1;
    }
    if (arg0->IsField("RightTrack") != 0) {
        var_r30_1016 = arg0->unkC->GetSubLine(arg0);
        temp_r3_1017 = arg0->GetNmbrOfSubLines();
        if (temp_r3_1017 != 0) {
            ((KDUniformSpline *) &this->unk4C.unk14)->Init(temp_r3_1017, 0U);
loop_18:
            if (var_r30_1016 != NULL) {
                sp28.GetVector3((s32) var_r30_1016);
                temp_f1_1030 = M2C_BITWISE(f64, sp28);
                temp_f0_1031 = M2C_BITWISE(f64, sp28.unk8);
                sp68 = temp_f1_1030;
                sp70 = temp_f0_1031;
                if ((u8) this->unkE0 != 0) {
                    M2C_FIELD(this, f64 *, 0x80) = temp_f1_1030;
                    M2C_FIELD(this, f64 *, 0x88) = temp_f0_1031;
                    this->unk90 = sp68;
                    this->unk98 = sp70;
                    this->unkE0 = 0;
                } else {
                    Min(sp18, *((MKVector3 *) &this->unk4C.unk34));
                    M2C_FIELD(this, f64 *, 0x80) = M2C_BITWISE(f64, sp18);
                    M2C_FIELD(this, f64 *, 0x88) = (f64) sp18.unk8;
                    Max(sp8, *((MKVector3 *) &this->unk90));
                    this->unk90 = M2C_BITWISE(f64, sp8);
                    this->unk98 = (f64) sp8.unk8;
                }
                ((KDUniformSpline *) &this->unk4C.unk14)->AddNode(*((MKVector3 *) &sp68));
                var_r30_1016 = var_r30_1016->unkC->GetNextLine(var_r30_1016);
                goto loop_18;
            }
        }
        return 1;
    }
    return 0;
}
#endif

void MoltenMetalBucketTrack::Deinit() {
    MKProp::Deinit();
    ((KDUniformSpline *) &this->unk4C)->Deinit();
    ((KDUniformSpline *) &this->unk4C.unk14)->Deinit();
}

#if 0 // DRAFT: ')' expected
void MoltenMetalBucketTrack::Init() {
    MKProp::Init();
    M2C_STRUCT_COPY((s32) (this + 0x9C) + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    this->unk8 = &this->unkA0;
    this->unk4C.unk28 = M2C_BITWISE(f32, checked_cast<MoltenMetalBucket *, MKProp>(gMK->CreateProp("MoltenMetalBucket")));
    this->unk4C.unk2C = 0.0f;
    M2C_FIELD(this, f64 *, 0x80) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x88) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk90 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk98 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkC = (BoundingVolume *) &this->unk4C.unk34;
    this->unkE0 = 1;
    this->unkE4 = 0;
    this->unkE8 = 5.0f;
}
#endif

void MoltenMetalBucketTrackDescriptor::Deinit() {
    MKMaterial_Destroy(this->unk80);
    MKPropDescriptor::Deinit();
}

void MoltenMetalBucketTrackDescriptor::Init() {
    MKPropDescriptor::Init();
    M2C_FIELD(this, f64 *, 0x60) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk68 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk70 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk78 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk1C = (BoundingVolume *) &this->unk60;
    this->unk80 = (MKMaterial *) (MKMaterial_Create("p0017_FireSteelLedgeRail"));
}
