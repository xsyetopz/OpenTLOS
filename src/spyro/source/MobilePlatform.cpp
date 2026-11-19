#include "spyro/source/MobilePlatform.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Platform.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/PropFlags.h"
#include "spyro/source/SplineTools.h"
#include <m2c_macros.h>

f64 atan2();                                        /* extern */
f64 fmod(f32, f32);                                 /* extern */
extern s32 GS_PLACEHOLDER;
extern f32 *KDSpline_AccelerationMixer;
extern f32 *KDSpline_PositionMixer;
extern f32 *KDSpline_VelocityMixer;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;
u8 mpfLoadInfo__14MobilePlatform[0x10];

#if 0 // DRAFT: ')' expected
void MobilePlatform::UpdateSag() {
    f32 temp_f1_111;
    f32 temp_f1_114;
    f32 temp_f31_76;
    f32 temp_f3_86;
    f32 temp_f4_93;
    f32 temp_f4_97;
    f32 var_f2_104;
    f32 var_f5_85;

    if (M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x140) > 0.0f) {
        temp_f31_76 = gUpdateTimeDelta;
        var_f5_85 = 0.5f * (2.0f * temp_f31_76);
        temp_f3_86 = this->unk244 * M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x140);
        if (var_f5_85 < 1.0f) {

        } else {
            var_f5_85 = 1.0f;
        }
        temp_f4_93 = this->unk244;
        temp_f4_97 = (var_f5_85 * (temp_f3_86 - temp_f4_93)) + temp_f4_93;
        this->unk244 = (var_f5_85 * (temp_f3_86 - temp_f4_97)) + temp_f4_97;
        var_f2_104 = 0.5f * (4.0f * gUpdateTimeDelta);
        if (var_f2_104 < 1.0f) {

        } else {
            var_f2_104 = 1.0f;
        }
        temp_f1_111 = this->unk244;
        temp_f1_114 = (var_f2_104 * (0.0f - temp_f1_111)) + temp_f1_111;
        this->unk244 = (var_f2_104 * (0.0f - temp_f1_114)) + temp_f1_114;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk10'
void MobilePlatform::SetYaw(float arg0, float arg1) {
    KDSplinePathSegment spB8;
    f64 spB0;
    f64 spA8;
    KDUniformSpline sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_209;
    f32 temp_f1_259;
    f32 temp_f2_158;
    f32 var_f0_246;
    f32 var_f1_236;
    f32 var_f4_212;

    if ((s32) this->unk19C.unk30.unk4 > 1) {
        spB8.GetVelocity(arg0);
        spB8.unk10.ToWorldDir(*((MKVector3 *) &this->unk150));
        spB8.unk20 = spB8.unk10;
        temp_f2_158 = M2C_BITWISE(f32, spB8.unk20);
        spB8.unk28 = M2C_BITWISE(f64, spB8.unk18);
        spB8.unk24 = 0.0f;
        if (((((f32) spB8.unk28 * (f32) spB8.unk28) + ((temp_f2_158 * temp_f2_158) + (0.0f * 0.0f))) < 0.0001f) && (arg0 == 0.0f)) {
            sp88.GetAcceleration(arg0);
            sp88.unk10.ToWorldDir(*((MKVector3 *) &this->unk150));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            spA8 = sp28;
            sp30 = spA0 * 10000.0f;
            spB8.unk20 = sp28;
            spB0 = (f64) sp30;
            spB8.unk28 = (f64) sp30;
        }
        spB8.unk24 = 0.0f;
        if ((((f32) spB8.unk28 * (f32) spB8.unk28) + (((f32) spB8.unk20 * (f32) spB8.unk20) + (0.0f * 0.0f))) > 0.0001f) {
            temp_f1_209 = (f32) atan2();
            if ((s32) this->unk184 == 0) {
                var_f4_212 = 1.0f;
            } else {
                var_f4_212 = -1.0f;
            }
            sp78 = M2C_FIELD(this, f64 *, 0x110);
            sp80 = M2C_FIELD(this, f64 *, 0x118);
            sp10 = KDMath_GetSmallestAngle(unksp7C, (6.2831855f * var_f4_212) + (1.5707964f + temp_f1_209));
            sp40 = M2C_FIELD(this, f64 *, 0x118);
            sp38 = M2C_FIELD(this, f64 *, 0x110);
            if (arg1 < 0.0f) {
                var_f1_236 = -arg1;
            } else {
                var_f1_236 = arg1;
            }
            sp8 = var_f1_236;
            if (arg1 < 0.0f) {
                var_f0_246 = -arg1;
            } else {
                var_f0_246 = arg1;
            }
            spC = -var_f0_246;
            sp48 = M2C_FIELD(this, f64 *, 0x110);
            sp50 = M2C_FIELD(this, f64 *, 0x118);
            temp_f1_259 = Clamp<float>(spC, sp10, sp8);
            sp58 = M2C_FIELD(this, f64 *, 0x110);
            sp20 = (f32) sp40;
            sp18 = (f32) sp58;
            sp1C = unksp4C + temp_f1_259;
            sp60 = M2C_FIELD(this, f64 *, 0x118);
            M2C_FIELD(this, f64 *, 0x110) = (f64) sp18;
            sp68 = (f64) sp18;
            sp70 = (f64) sp20;
            M2C_FIELD(this, f64 *, 0x118) = (f64) sp20;
        }
    }
}
#endif

f32 MobilePlatform::GetTime() {
    f32 var_f1_396;

    var_f1_396 = 0.0f;
    if (this->unk18C == 0.0f) {

    } else {
        var_f1_396 = (f32) fmod(this->unkB8 + this->unk194, this->unk1E8) / this->unk18C;
    }
    if (var_f1_396 > 1.0f) {
        if ((u8) this->unk1E4 != 0) {
            return 1.0f;
        }
        this->unk184 = 1;
        return 2.0f - var_f1_396;
    }
    this->unk184 = 0;
    return var_f1_396;
}

void MobilePlatform::UpdateScale() {

}

#if 0 // DRAFT: undefined identifier 'sp48'
void MobilePlatform::UpdateMove() {
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    KDUniformSpline sp88;
    PlatformRider sp78;
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
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    f32 sp8;
    MKVector3 *temp_r30_517;
    MKVector3 *temp_r30_571;
    MKVector3 *temp_r30_615;
    MKVector3 *temp_r30_662;
    f32 temp_f1_489;
    f32 temp_f1_543;
    f32 temp_f1_587;
    f32 temp_f2_527;
    f32 var_f31_491;
    s32 temp_r0_486;
    s32 temp_r0_540;
    s32 temp_r3_510;

    if (!(this->unk10 & 0x80000)) {
        sp60 = 0.0f;
        sp58 = 0.0f;
        sp5C = -this->unk244;
        spD0 = (f64) sp60;
        spC8 = (f64) sp58;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spA8 = sp48;
        sp50 = M2C_FIELD(this, f32 *, 0x258) + (f32) spD0;
        spB0 = (f64) sp50;
        MKModel_SetPosition(this->unk4, *((MKVector3 *) &spA8));
        return;
    }
    temp_r0_486 = this->unk19C.unk20;
    if (temp_r0_486 > 1) {
        temp_f1_489 = GetTime();
        var_f31_491 = temp_f1_489;
        sp8 = 0.0f;
        sp88.GetMeasure(temp_f1_489, (Matrix *) &this->unk19C.unk30, KDSpline_PositionMixer);
        sp88.unk10.ToWorld(*((MKVector3 *) &this->unk150));
        MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp88.unk10));
        if ((s32) M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x13C) != 0) {
            temp_r3_510 = this->unk184;
            if (temp_r3_510 != (s32) this->unk188) {
                this->unk188 = temp_r3_510;
                temp_r30_517 = this->unk8 + 0x30;
                KDSound_Play3d(M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x13C), temp_r30_517, 0U, -1, 0.0f, 0U);
            }
        }
        temp_f2_527 = this->unk180;
        if (temp_f2_527 > 0.0f) {
            SetYaw(var_f31_491, temp_f2_527);
        }
        M2C_FIELD(this, s8 *, 0x218) = 1;
        if ((u8) M2C_FIELD(this, u8 *, 0x1EC) != 0) {
            temp_r0_540 = this->unk184;
            if ((temp_r0_540 == 0) && ((temp_f1_543 = M2C_BITWISE(f32, this->unk1F0), M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((var_f31_491 == temp_f1_543) != 0)) || (this->unk1F4 > var_f31_491))) {
                sp20 = 0;
                var_f31_491 = temp_f1_543;
                sp1C = 0xB4;
                Message(&sp1C);
                M2C_FIELD(this, s8 *, 0x218) = 0;
                if ((s32) M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x138) != 0) {
                    temp_r30_571 = this->unk8 + 0x30;
                    KDSound_Play3d(M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x138), temp_r30_571, 0U, -1, 0.0f, 0U);
                }
                this->unk1F4 = -1.0f;
            } else if ((temp_r0_540 == 1) && ((temp_f1_587 = M2C_BITWISE(f32, this->unk1F0), M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((var_f31_491 == temp_f1_587) != 0)) || (this->unk1F4 < var_f31_491))) {
                sp18 = 0;
                var_f31_491 = temp_f1_587;
                sp14 = 0xB4;
                Message(&sp14);
                M2C_FIELD(this, s8 *, 0x218) = 0;
                if ((s32) M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x138) != 0) {
                    temp_r30_615 = this->unk8 + 0x30;
                    KDSound_Play3d(M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x138), temp_r30_615, 0U, -1, 0.0f, 0U);
                }
                this->unk1F4 = -1.0f;
            } else {
                this->unk1F4 = var_f31_491;
            }
        }
        if (((u8) this->unk1E4 != 0) && (this->unk10 & 0x80000) && (var_f31_491 > 0.99f) && ((s32) this->unk184 == 0)) {
            sp10 = 0;
            spC = 0xB4;
            Message(&spC);
            M2C_FIELD(this, s8 *, 0x218) = 0;
            if ((s32) M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x138) != 0) {
                temp_r30_662 = this->unk8 + 0x30;
                KDSound_Play3d(M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x138), temp_r30_662, 0U, -1, 0.0f, 0U);
            }
            if ((u8) this->unk19C.unk45 != 0) {
                this->unk190 = 0.0f;
            }
        }
    } else if (temp_r0_486 > 0) {
        sp78.ToWorld(*((MKVector3 *) &this->unk150));
        MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp78));
    }
    MKModel_GetPosition(this->unk4);
    this->unk250 = *M2C_ERROR(/* Read from unset register $r3 */);
    this->unk250 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f64 *, 8);
    sp40 = 0.0f;
    sp38 = 0.0f;
    sp3C = -this->unk244;
    spC0 = (f64) sp40;
    spB8 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp68 = sp28;
    sp30 = M2C_FIELD(this, f32 *, 0x258) + (f32) spC0;
    sp70 = (f64) sp30;
    MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp68));
}
#endif

#if 0 // DRAFT: ')' expected
void MobilePlatform::Message(MKMessage *arg0) {
    MKVector3 *temp_r29_1046;
    MKVector3 *temp_r29_1073;
    MKVector3 *temp_r29_1116;
    MKVector3 *temp_r29_1141;
    f32 temp_f2_933;
    f32 temp_f31_799;
    f32 var_f0_1090;
    f32 var_f0_895;
    f32 var_f1_820;
    s32 temp_r0_745;
    void *temp_r29_934;
    void *temp_r29_988;
    temp_r0_745 = arg0->unk0;
    switch (temp_r0_745) {                          /* irregular */
    case 0xB5:
        M2C_FIELD(this, s8 *, 0x218) = 1;
        if (!(this->unk10 & 0x80000) && (((u8) M2C_FIELD(this, u8 *, 0x1EC) == 0) || (this->unk1F4 != -1.0f))) {
            this->unk194 = (this->unk190 + this->unk1E8) - (f32) fmod(this->unkB8, this->unk1E8);
            temp_f31_799 = this->unk180;
            if ((temp_f31_799 > 0.0f) && ((s32) this->unk19C.unk30.unk0 > 1)) {
                SetYaw(GetTime(), temp_f31_799);
            }
        }
    default:
block_73:
        if ((s32) M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x134) != 0) {
            this->unk218.Message(arg0);
        }
        PropFlagsMessage((u32 *) &this->unk10, arg0);
        Platform::Message(arg0);
        return;
    case 0xD5:
        Reset();
        M2C_FIELD(this, s8 *, 0x218) = 0;
        var_f1_820 = M2C_FIELD(MobilePlatform::mpfLoadInfo, f32 *, 8);
        if (var_f1_820 < 1.0f) {

        } else {
            var_f1_820 = 1.0f;
        }
        if (var_f1_820 > 0.0f) {

        } else {
            var_f1_820 = 0.0f;
        }
        this->unk190 = this->unk18C * var_f1_820;
        this->unk194 = (this->unk190 + this->unk1E8) - (f32) fmod(this->unkB8, this->unk1E8);
        if ((s32) this->unk19C.unk20 > 1) {
            if (this->unk180 > 0.0f) {
                SetYaw(0.0f, 6.2831855f);
            }
            M2C_STRUCT_COPY((s32) &arg_sp2C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
            arg_sp20 = M2C_FIELD(this, f64 *, 0x110);
            arg_sp28 = M2C_FIELD(this, f64 *, 0x118);
            arg_sp30.SetRotationPYR(*((MKVector3 *) &arg_sp20));
            MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp30));
        }
        if ((s32) this->unk19C.unk20 > 0) {
            MKModel_SetPosition(this->unk4, *this->unk19C.unk24);
        }
        M2C_FIELD(this, s32 *, 0x1F0) = 0;
        GetTime();
        if ((s32) this->unk184 == 0) {
            var_f0_895 = 1.0f;
        } else {
            var_f0_895 = 0.0f;
        }
        this->unk1F0 = var_f0_895;
        M2C_FIELD(this, f32 *, 0x210) = 0.0f;
        UpdateScale();
        return;
    case 0xB4:
        M2C_FIELD(this, s8 *, 0x218) = 0;
        if (this->unk10 & 0x80000) {
            if (this->unk18C > 0.0f) {
                this->unk190 = (f32) fmod(this->unkB8 + this->unk194, this->unk1E8);
            }
            this->unk1F4 = -1.0f;
        }
        goto block_73;
    case 0x23:
        temp_f2_933 = M2C_FIELD(this, f32 *, 0x210);
        temp_r29_934 = checked_cast<PlatformAttachDetachMsg *, MKMessage>(arg0);
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (((temp_f2_933 != 1.0f) || !(this->unk210 > 0.0f)) && ((M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f2_933 == 0.0f) == 0)) || !(this->unk210 < 0.0f)) && !(M2C_BITWISE(f32, this->unk204.unk0) > 0.0f)) {
            M2C_FIELD(temp_r29_934, s8 *, 0xC) = 0;
            return;
        }
        if ((u32) M2C_FIELD(M2C_FIELD(temp_r29_934, void **, 8), u32 *, 0) == M2C_FIELD(*gb, u32 (**)(void **), 0xC)(gb)) {
            this->unk204.unk0 = 0.2f;
            M2C_FIELD(this, s8 *, 0x20C) = 1;
        }
        if ((u32) M2C_FIELD(M2C_FIELD(temp_r29_934, void **, 8), u32 *, 4) != &this->unk108) {
            this->unk244 = 1.0f;
        }
        goto block_73;
    case 0x24:
        temp_r29_988 = checked_cast<PlatformAttachDetachMsg *, MKMessage>(arg0);
        if ((u32) *M2C_FIELD(temp_r29_988, u32 **, 8) == M2C_FIELD(*gb, u32 (**)(void **, void ***), 0xC)(gb, &gb)) {
            this->unk204.unk0 = 1.2f;
            M2C_FIELD(this, s8 *, 0x20C) = 0;
        }
        goto block_73;
    case 0xC4:
        if ((u8) M2C_FIELD(this, u8 *, 0x1EC) != 0) {
            M2C_FIELD(this, s32 *, 0x1F0) = (s32) ((M2C_FIELD(this, s32 *, 0x1F0) + 1) % this->unk19C.unk20);
            this->unk1F0 = SplineTools_GetNodeTime(this->unk19C.unk30, M2C_FIELD(this, s32 *, 0x1F0));
            if ((s32) this->unk184 == 0) {
                this->unk1F4 = 0.0f;
            } else {
                this->unk1F4 = 1.0f;
            }
            arg_sp1C = 0;
            arg_sp18 = 0xB5;
            Message(&arg_sp18);
            if ((s32) M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x13C) != 0) {
                temp_r29_1046 = this->unk8 + 0x30;
                KDSound_Play3d(M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x13C), temp_r29_1046, 0U, -1, 0.0f, 0U);
            }
        }
        goto block_73;
    case 0xC5:
        arg_sp14 = 0;
        arg_sp10 = 0xB5;
        Message(&arg_sp10);
        if ((s32) M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x13C) != 0) {
            temp_r29_1073 = this->unk8 + 0x30;
            KDSound_Play3d(M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x13C), temp_r29_1073, 0U, -1, 0.0f, 0U);
        }
        M2C_FIELD(this, s32 *, 0x1F0) = 0;
        GetTime();
        if ((s32) this->unk184 == 0) {
            var_f0_1090 = 1.0f;
        } else {
            var_f0_1090 = 0.0f;
        }
        this->unk1F0 = var_f0_1090;
        goto block_73;
    case 0xBE:
        if (!(this->unk10 & 0x160000)) {
            M2C_FIELD(this, f32 *, 0x210) = 0.0f;
            this->unk210 = 1.0f;
            M2C_FIELD(this->__vptr, M2C_UNK (**)(f32), 0x4C)(0.0f);
            if ((s32) M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x130) != 0) {
                temp_r29_1116 = this->unk8 + 0x30;
                KDSound_Play3d(M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x130), temp_r29_1116, 0U, -1, 0.0f, 0U);
            }
        }
        goto block_73;
    case 0xBF:
        if (this->unk10 & 0x160000) {
            M2C_FIELD(this, f32 *, 0x210) = 1.0f;
            this->unk210 = -1.0f;
            if ((s32) M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x12C) != 0) {
                temp_r29_1141 = this->unk8 + 0x30;
                KDSound_Play3d(M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x12C), temp_r29_1141, 0U, -1, 0.0f, 0U);
                return;
            }
        } else {
            goto block_73;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void MobilePlatform::PropUpdate() {
    s32 sp8;
    f32 temp_f0_1243;
    f32 temp_f2_1213;
    f32 temp_f2_1238;
    void *temp_r4_1194;

    if ((s32) M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x134) != 0) {
        temp_r4_1194 = checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        this->unk218.Update(M2C_FIELD(temp_r4_1194, s32 *, 0x134), 1U, M2C_FIELD(this, u8 *, 0x218), (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if (!(this->unk10 & 0x20000)) {
        this->unk70.unk4 = 0;
        return;
    }
    temp_f2_1213 = M2C_FIELD(this, f32 *, 0x210);
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (((temp_f2_1213 == 1.0f) && (this->unk210 > 0.0f)) || ((M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f2_1213 == 0.0f) != 0)) && (this->unk210 < 0.0f))) {
        this->unk70.unk4 = 1;
    }
    UpdateSag();
    Platform::PropUpdate();
    temp_f2_1238 = M2C_BITWISE(f32, this->unk204.unk0);
    if ((temp_f2_1238 > 0.0f) && (temp_f0_1243 = temp_f2_1238 - gUpdateTimeDelta, this->unk204.unk0 = temp_f0_1243, M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f0_1243 == 0.0f) != 0))) {
        this->unk204.unk0 = -1.0f;
        if ((u8) M2C_FIELD(this, u8 *, 0x20C) != 0) {
            this->unk1FC.Send((MKProp *) this);
            return;
        }
        this->unk200.Send((MKProp *) this);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp20'
void MobilePlatform::LoadDone() {
    f32 var_f1_1389;
    f64 temp_f0_1285;
    f64 temp_f1_1284;
    s32 temp_r4_1305;
    void *temp_r3_1283;
    void *temp_r3_1315;
    Platform::LoadDone();
    this->unk19C.LoadDone();
    temp_r3_1283 = this->unk8;
    temp_f1_1284 = M2C_FIELD(temp_r3_1283, f64 *, 0x30);
    temp_f0_1285 = M2C_FIELD(temp_r3_1283, f64 *, 0x38);
    arg_sp20 = temp_f1_1284;
    this->unk250 = temp_f1_1284;
    this->unk250 = temp_f0_1285;
    arg_sp28 = temp_f0_1285;
    if ((s32) this->unk19C.unk20 > 0) {
        MKModel_SetPosition(this->unk4, *this->unk19C.unk24);
    }
    if ((s32) this->unk19C.unk20 > 1) {
        if ((u8) this->unk19C.unk45 == 0) {
            temp_r4_1305 = this->unk19C.unk30.unkC;
            M2C_FIELD(temp_r4_1305, f32 *, 0x10) = (f32) MKVector3::zero.unk0;
            M2C_FIELD(temp_r4_1305, f32 *, 0x14) = (f32) MKVector3::zero.unk4;
            M2C_FIELD(temp_r4_1305, f32 *, 0x18) = (f32) MKVector3::zero.unk8;
            temp_r3_1315 = this->unk19C.unk30.unkC + ((this->unk19C.unk30.unk0 - 1) << 5);
            M2C_FIELD(temp_r3_1315, f32 *, 0x10) = (f32) MKVector3::zero.unk0;
            M2C_FIELD(temp_r3_1315, f32 *, 0x14) = (f32) MKVector3::zero.unk4;
            M2C_FIELD(temp_r3_1315, f32 *, 0x18) = (f32) MKVector3::zero.unk8;
        }
        this->unk19C.unk30.RegulateSpeed();
        if (this->unk180 > 0.0f) {
            SetYaw(0.0f, 6.2831855f);
        }
        M2C_STRUCT_COPY((s32) &arg_sp2C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        arg_sp10 = M2C_FIELD(this, f64 *, 0x110);
        arg_sp18 = M2C_FIELD(this, f64 *, 0x118);
        arg_sp30.SetRotationPYR(*((MKVector3 *) &arg_sp10));
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp30));
        if (M2C_FIELD(MobilePlatform::mpfLoadInfo, f32 *, 4) > 0.0f) {
            M2C_FIELD(MobilePlatform::mpfLoadInfo, f32 *, 0) = (f32) (this->unk19C.unk30.unk8 / M2C_FIELD(MobilePlatform::mpfLoadInfo, f32 *, 4));
        }
        this->unk18C = this->unk19C.unk30.unk8 / M2C_FIELD(MobilePlatform::mpfLoadInfo, f32 *, 0);
        this->unk1E8 = this->unk18C * (f32) ((u8) ((u8) this->unk19C.unk45 == 0) + 1);
    } else {
        this->unk1E8 = 1.0f;
    }
    var_f1_1389 = M2C_FIELD(MobilePlatform::mpfLoadInfo, f32 *, 8);
    if (var_f1_1389 < 1.0f) {

    } else {
        var_f1_1389 = 1.0f;
    }
    if (var_f1_1389 > 0.0f) {

    } else {
        var_f1_1389 = 0.0f;
    }
    this->unk190 = this->unk18C * var_f1_1389;
    this->unk194 = (this->unk190 + this->unk1E8) - (f32) fmod(this->unkB8, this->unk1E8);
    if (M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x124) != 0.0f) {
        this->unk198 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
    }
    this->unk204.unk0 = -1.0f;
    this->unk1F4 = -1.0f;
    M2C_FIELD(this, f32 *, 0x210) = 1.0f;
    this->unk210 = 1.0f;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 MobilePlatform::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1449;

    var_r31_1449 = 0;
    if ((Platform::LoadLine(arg0) != 0) || (arg0->LoadFloat("turnSpeed", &this->unk180, 0) != 0) || (arg0->LoadFloat("speed", (f32 *) MobilePlatform::mpfLoadInfo, 0) != 0) || (arg0->LoadFloat("period", (f32 *) &MobilePlatform::mpfLoadInfo[4], 0) != 0) || (arg0->LoadFloat("startTime", (f32 *) &MobilePlatform::mpfLoadInfo[8], 0) != 0) || (arg0->LoadBool("bMoveOne", &this->unk1E4, 0) != 0) || (arg0->LoadBool("bNonCircular", &MobilePlatform::mpfLoadInfo[0xC], 0) != 0) || (arg0->LoadBool("bSingleMove", (u8 *) &this->unk1E8, 0) != 0) || (arg0->LoadFloat("fFlipDelay", &this->unk1F8, 0) != 0) || (this->unk1FC.LoadLine(arg0, "OnAttach") != 0) || (this->unk200.LoadLine(arg0, "OnDetach") != 0) || (this->unk19C.LoadLine(arg0) != 0)) {
        var_r31_1449 = 1;
    }
    return var_r31_1449;
}
#endif

void MobilePlatform::Reset() {
    Platform::Reset();
    this->unk244 = 0.0f;
    M2C_FIELD(this, s8 *, 0x218) = 0;
}

#if 0 // DRAFT: ')' expected
void MobilePlatform::Deinit() {
    if ((s32) M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x134) != 0) {
        KDSound_Stop((s32 *) &this->unk218);
    }
    this->unk19C.Deinit();
    Platform::Deinit();
}
#endif

#if 0 // DRAFT: ')' expected
void MobilePlatform::Init() {
    Platform::Init();
    MobilePlatform::mpfLoadInfo[0xC] = 0;
    M2C_FIELD(MobilePlatform::mpfLoadInfo, f32 *, 0) = 7.0f;
    M2C_FIELD(MobilePlatform::mpfLoadInfo, f32 *, 4) = -1.0f;
    M2C_FIELD(MobilePlatform::mpfLoadInfo, f32 *, 8) = 0.0f;
    this->unk19C.Init();
    this->unk184 = 0;
    this->unk188 = 2;
    this->unk1E4 = 0;
    this->unk18C = 0.0f;
    this->unk180 = 0.0f;
    this->unk190 = 0.0f;
    this->unk198 = 0.0f;
    M2C_FIELD(this, s32 *, 0x1F0) = 0;
    this->unk1F0 = 1.0f;
    this->unk1F4 = -1.0f;
    M2C_FIELD(this, s8 *, 0x1EC) = 0;
    this->unk244 = 0.0f;
    this->unk244 = 0.0f;
    M2C_FIELD(this, s8 *, 0x218) = 0;
    if ((s32) M2C_FIELD(checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x134) != 0) {
        this->unk218.Init(1.0f, 1.0f);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
s32 MobilePlatformDescriptor::IsDescriptor(MKPropDescriptor *arg0) {
    void *var_r4_1682;
    void *var_r5_1670;
    void *var_r5_1690;

    var_r5_1670 = *MobilePlatformDescriptor::pFirstDesc;
loop_2:
    if ((var_r5_1670 != NULL) && !(M2C_FIELD(M2C_FIELD(var_r5_1670, void **, 0x144), s32 *, 0x138) & 2)) {
        var_r5_1670 = M2C_FIELD(var_r5_1670, void **, 0x14C);
        goto loop_2;
    }
    var_r4_1682 = var_r5_1670;
loop_12:
    if (var_r4_1682 == NULL) {
        return 0;
    }
    if (var_r4_1682 == this) {
        return 1;
    }
    var_r5_1690 = M2C_FIELD(var_r4_1682, void **, 0x14C);
loop_9:
    if ((var_r5_1690 != NULL) && !(M2C_FIELD(M2C_FIELD(var_r5_1690, void **, 0x144), s32 *, 0x138) & 2)) {
        var_r5_1690 = M2C_FIELD(var_r5_1690, void **, 0x14C);
        goto loop_9;
    }
    var_r4_1682 = var_r5_1690;
    goto loop_12;
}
#endif

#if 0 // DRAFT: function call 'KDSound_LoadLine(MKIniLine *, const char[12], long *)' does
s32 MobilePlatformDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1719;

    var_r31_1719 = 0;
    if ((PlatformDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("BobFreq", &this->unk124, 0) != 0) || (arg0->LoadFloat("BobMag", &this->unk128, 0) != 0) || (arg0->LoadFloat("MaxSag", &this->unk140, 0) != 0) || (KDSound_LoadLine(arg0, "sndScaleOut", &this->unk130) != 0) || (KDSound_LoadLine(arg0, "sndScaleIn", &this->unk12C) != 0) || (KDSound_LoadLine(arg0, "sndMoving", &this->unk134) != 0) || (KDSound_LoadLine(arg0, "sndStart", &this->unk13C) != 0) || (KDSound_LoadLine(arg0, "sndStop", &this->unk138) != 0)) {
        var_r31_1719 = 1;
    }
    return var_r31_1719;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MobilePlatformDescriptor *' to
void MobilePlatformDescriptor::Deinit() {
    MobilePlatformDescriptor *temp_r4_1813;
    MobilePlatformDescriptor *temp_r4_1819;

    if ((MobilePlatformDescriptor *) *MobilePlatformDescriptor::pFirstDesc == this) {
        *MobilePlatformDescriptor::pFirstDesc = this->unk14C;
    }
    temp_r4_1813 = this->unk148;
    if (temp_r4_1813 != NULL) {
        temp_r4_1813->unk14C = this->unk14C;
    }
    temp_r4_1819 = this->unk14C;
    if (temp_r4_1819 != NULL) {
        temp_r4_1819->unk148 = this->unk148;
    }
    this->unk148 = NULL;
    this->unk14C = NULL;
    this->unk144 = NULL;
    KDPropExDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void MobilePlatformDescriptor::Init() {
    PlatformDescriptor::Init();
    this->unkF0 = 2.5f;
    this->unk104 = 1;
    this->unk108 = 0.3f;
    this->unk10C = 0.061086524f;
    this->unk110 = 0.2f;
    this->unk114 = 0.07853982f;
    this->unk124 = 0.25f;
    this->unk128 = 1.5f;
    this->unk130 = GS_PLACEHOLDER;
    this->unk12C = GS_PLACEHOLDER;
    this->unk134 = GS_PLACEHOLDER;
    this->unk138 = GS_PLACEHOLDER;
    this->unk13C = GS_PLACEHOLDER;
    this->unk140 = 0.0f;
    this->unk14C = *MobilePlatformDescriptor::pFirstDesc;
    this->unk148 = NULL;
    if ((MobilePlatformDescriptor *) *MobilePlatformDescriptor::pFirstDesc != NULL) {
        (*MobilePlatformDescriptor::pFirstDesc)->unk148 = this;
    }
    *MobilePlatformDescriptor::pFirstDesc = this;
    this->unk144 = M2C_FIELD(*gMK, void *(**)(void **), 0x7C)(gMK);
}
#endif
