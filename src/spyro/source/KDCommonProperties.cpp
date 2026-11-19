#include "spyro/source/KDCommonProperties.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDAnimScriptProperty.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDModelProperty.h"
#include "spyro/source/KDPathProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDSplinePathProperty.h"
#include "unplaced_templates.h"
#include "spyro/source/KDParticleEffects.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, s8 *, s8 *);                      /* extern */
extern f32 *KDSpline_PositionMixer;
extern u8 bRegistered;
extern f32 gUpdateTimeDelta;
static KDPositionProperty classInfo__18KDPositionProperty;
static KDRefPointProperty classInfo__18KDRefPointProperty; /* type too large by 8 */
static KDAnimEventProperty classInfo__19KDAnimEventProperty; /* type too large by 0x14 */
static KDAnimProperty classInfo__14KDAnimProperty;  /* type too large by 0x10 */
static KDMessageHandlerProperty classInfo__24KDMessageHandlerProperty; /* type too large by 0x18 */
static KDPathProperty classInfo__14KDPathProperty;
static KDSplinePathProperty classInfo__20KDSplinePathProperty;
#if 0 // DRAFT: expression syntax error
static KDPathFollowerProperty classInfo__22KDPathFollowerProperty; /* type too large by 0xC */
static KDSoundAttachmentProperty classInfo__25KDSoundAttachmentProperty; /* type too large by 0xC */
static KDAmbientSoundProperty classInfo__22KDAmbientSoundProperty; /* type too large by 0x18 */

void KDAmbientSoundProperty::Update() {
    s32 sp8;
    KDSoundFader *temp_r30_44;
    MKVector3 *temp_r8_51;
    u32 temp_r31_47;
    void **temp_r3_40;

    temp_r3_40 = this->unk14;
    temp_r30_44 = KDProperty::pInstanceMem.__vptr + this->unk8;
    temp_r31_47 = (u32) M2C_FIELD(temp_r30_44, u32 *, 0x28) >> 0x1FU;
    temp_r8_51 = M2C_FIELD(*temp_r3_40, MKVector3 *(**)(void **, void *), 0x50)(temp_r3_40, KDProperty::pInstanceMem.__vptr);
    sp8 = 1;
    temp_r30_44->Update(this->unk10, 1U, (u8) temp_r31_47, NULL, temp_r8_51, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
}
#endif

#if 0 // DRAFT: expression syntax error
void KDAmbientSoundProperty::DeinitInstance() {
    KDSound_Stop(KDProperty::pInstanceMem.__vptr + this->unk8);
}
#endif

#if 0 // DRAFT: expression syntax error
void KDAmbientSoundProperty::InitInstance() {
    void *temp_r3_107;

    *(KDProperty::pInstanceMem.__vptr + (this->unk8 + 0x28)) = 0;
    ((KDSoundFader *) (KDProperty::pInstanceMem.__vptr + this->unk8))->Init(this->unk20, this->unk24);
    temp_r3_107 = KDProperty::pInstanceMem.__vptr + this->unk8;
    if ((u8) this->unk1C != 0) {
        M2C_FIELD(temp_r3_107, s32 *, 0x28) = (s32) (M2C_FIELD(temp_r3_107, s32 *, 0x28) | 0x80000000);
        return;
    }
    M2C_FIELD(temp_r3_107, s32 *, 0x28) = (s32) (M2C_FIELD(temp_r3_107, s32 *, 0x28) & 0x7FFFFFFF);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 KDAmbientSoundProperty::LoadLine(MKIniLine *arg0) {
    s32 var_r31_134;

    var_r31_134 = 0;
    if ((KDSoundAttachmentProperty::LoadLine(arg0) != 0) || (arg0->LoadBool("bOnByDefault", &this->unk1C, 0) != 0) || (arg0->LoadFloat("FadeInTime", &this->unk20, 0) != 0) || (arg0->LoadFloat("FadeOutTime", &this->unk24, 0) != 0)) {
        var_r31_134 = 1;
    }
    return var_r31_134;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void KDAmbientSoundProperty::Init(const char *arg0) {
    KDSoundAttachmentProperty::Init(arg0);
    this->unk1C = 1;
    this->unk20 = 0.25f;
    this->unk24 = 0.25f;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDAmbientSoundProperty::Command(int arg0) {
    void *temp_r5_210;

    if (arg0 < 3) {
        if (arg0 < 1) {
            return;
        }
        temp_r5_210 = KDProperty::pInstanceMem.__vptr + this->unk8;
        if (arg0 == 1) {
            M2C_FIELD(temp_r5_210, s32 *, 0x28) = (s32) (M2C_FIELD(temp_r5_210, s32 *, 0x28) | 0x80000000);
        } else {
            M2C_FIELD(temp_r5_210, s32 *, 0x28) = (s32) (M2C_FIELD(temp_r5_210, s32 *, 0x28) & 0x7FFFFFFF);
        }
        if (arg0 == 2) {
            KDSound_Stop(KDProperty::pInstanceMem.__vptr + this->unk8);
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void KDSoundAttachmentProperty::InitInstance() {
    *(KDProperty::pInstanceMem.__vptr + this->unk8) = 0;
}
#endif

#if 0 // DRAFT: function call 'stricmp(signed char *, const char[12], const char[13])'
void KDSoundAttachmentProperty::Resolve(KDPropertySet *arg0) {
    s8 *temp_r4_271;

    if (stricmp(this->unk18, "PlaceHolder", "bOnByDefault") == 0) {
        this->unk10 = KDSound_ResolveSound(this->unk4, NULL);
    } else {
        this->unk10 = KDSound_ResolveSound(this->unk18, NULL);
    }
    temp_r4_271 = this->unk14;
    if (temp_r4_271 != NULL) {
        this->unk14 = property_cast<KDPositionProperty *, KDProperty *>(arg0->Find(temp_r4_271));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 KDSoundAttachmentProperty::LoadLine(MKIniLine *arg0) {
    u8 var_r31_298;

    var_r31_298 = 0;
    if ((arg0->LoadString("origin", &this->unk14, 0) != 0) || (arg0->LoadString("soundevent", &this->unk18, 0) != 0)) {
        var_r31_298 = 1;
    }
    return var_r31_298;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
void KDSoundAttachmentProperty::Init(const char *arg0) {
    this->unk4 = arg0;
    this->unk14 = "localtoworld";
    this->unk18 = "PLACEHOLDER";
}
#endif

#if 0 // DRAFT: expression syntax error
void KDSoundAttachmentProperty::Command(int arg0) {
    s32 temp_r31_363;
    s8 *temp_r3_353;
    s8 *temp_r3_360;
    void *temp_r30_361;

    switch (arg0) {                                 /* irregular */
    case 1:
        temp_r3_353 = this->unk14;
        if (M2C_FIELD(*temp_r3_353, u32 (**)(s8 *), 0x50)(temp_r3_353) != 0U) {
            temp_r3_360 = this->unk14;
            temp_r30_361 = KDProperty::pInstanceMem.__vptr;
            temp_r31_363 = this->unk8;
            *(temp_r30_361 + temp_r31_363) = KDSound_Play3d(this->unk10, M2C_FIELD(*temp_r3_360, MKVector3 *(**)(s8 *), 0x50)(temp_r3_360), 0U, -1, 0.0f, 1U);
            return;
        }
        return;
    case 2:
        KDSound_Stop(KDProperty::pInstanceMem.__vptr + this->unk8);
        break;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[5])' does not match
s32 KDSoundAttachmentProperty::ResolveCommand(const char *arg0) const {
    s32 temp_r3_412;

    if (stricmp(arg0, "play") == 0) {
        return 1;
    }
    temp_r3_412 = 0 - stricmp(arg0, "stop");
    return 2 & ~((temp_r3_412 - temp_r3_412) - !M2C_CARRY);
}
#endif

#if 0 // DRAFT: expression syntax error
void KDPathFollowerProperty::UpdateSplinePath() {
    f64 sp28;
    KDUniformSpline sp10;
    f32 sp8;
    f32 temp_f2_438;
    f64 temp_f1_480;
    void **temp_r3_479;
    void *temp_r3_487;
    void *temp_r4_435;

    temp_r4_435 = KDProperty::pInstanceMem.__vptr + this->unk8;
    temp_f2_438 = M2C_FIELD(temp_r4_435, f32 *, 0x14) * gUpdateTimeDelta;
    if ((u8) M2C_FIELD(temp_r4_435, u8 *, 1) == 0) {
        M2C_FIELD(temp_r4_435, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r4_435, f32 *, 0x18) + temp_f2_438);
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (M2C_FIELD(temp_r4_435, f32 *, 0x18) == 1.0f) {
            M2C_FIELD(temp_r4_435, u8 *, 0) = (u8) M2C_FIELD(temp_r4_435, u8 *, 2);
            M2C_FIELD(temp_r4_435, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r4_435, f32 *, 0x18) - 1.0f);
        }
    } else {
        M2C_FIELD(temp_r4_435, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r4_435, f32 *, 0x18) - temp_f2_438);
        if (M2C_FIELD(temp_r4_435, f32 *, 0x18) < 0.0f) {
            M2C_FIELD(temp_r4_435, u8 *, 0) = (u8) M2C_FIELD(temp_r4_435, u8 *, 2);
            M2C_FIELD(temp_r4_435, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r4_435, f32 *, 0x18) + 1.0f);
        }
    }
    sp8 = 0.0f;
    sp10.GetMeasure(M2C_FIELD(temp_r4_435, f32 *, 0x18), M2C_FIELD(temp_r4_435, s32 *, 4) + 0x30, KDSpline_PositionMixer);
    temp_r3_479 = this->unk18;
    temp_f1_480 = M2C_BITWISE(f64, sp10);
    sp10.unk10 = temp_f1_480;
    sp28 = (f64) sp10.unk8;
    temp_r3_487 = M2C_FIELD(*temp_r3_479, void *(**)(void **, f64), 0x54)(temp_r3_479, temp_f1_480);
    M2C_FIELD(temp_r3_487, f32 *, 0x30) = M2C_BITWISE(f32, sp10.unk10);
    M2C_FIELD(temp_r3_487, f32 *, 0x34) = sp24;
    M2C_FIELD(temp_r3_487, f32 *, 0x38) = (f32) sp28;
    M2C_FIELD(temp_r3_487, f32 *, 0x3C) = 1.0f;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDPathFollowerProperty::UpdateNormalPath() {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f1_706;
    f32 temp_f2_686;
    f32 temp_f4_684;
    f32 temp_f5_669;
    f32 var_f5_599;
    f64 temp_f2_602;
    f64 temp_f2_608;
    f64 temp_f2_612;
    s32 temp_r0_552;
    s32 temp_r0_563;
    s32 temp_r5_631;
    s32 temp_r5_671;
    s32 temp_r6_529;
    s32 temp_r6_541;
    s32 temp_r6_573;
    s32 temp_r6_675;
    s32 temp_r7_576;
    s32 var_r0_641;
    void **temp_r3_705;
    void *temp_r3_715;
    void *temp_r4_513;
    void *temp_r4_677;
    void *temp_r5_678;
    void *temp_r7_571;
    void *temp_r7_668;

    temp_r4_513 = KDProperty::pInstanceMem.__vptr + this->unk8;
    M2C_FIELD(temp_r4_513, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r4_513, f32 *, 0x18) + (gUpdateTimeDelta * (M2C_FIELD(temp_r4_513, f32 *, 0x14) / M2C_FIELD(temp_r4_513, f32 *, 8))));
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (M2C_FIELD(temp_r4_513, f32 *, 0x18) == 1.0f) {
        if ((u8) M2C_FIELD(temp_r4_513, u8 *, 1) == 0) {
            temp_r6_529 = M2C_FIELD(temp_r4_513, s32 *, 0xC) + 1;
            M2C_FIELD(temp_r4_513, s32 *, 0xC) = temp_r6_529;
            if (temp_r6_529 >= (s32) M2C_FIELD(M2C_FIELD(temp_r4_513, void **, 4), s32 *, 0x20)) {
                M2C_FIELD(temp_r4_513, s32 *, 0xC) = 0;
                M2C_FIELD(temp_r4_513, u8 *, 0) = (u8) M2C_FIELD(temp_r4_513, u8 *, 2);
            }
            temp_r6_541 = M2C_FIELD(temp_r4_513, s32 *, 0x10) + 1;
            M2C_FIELD(temp_r4_513, s32 *, 0x10) = temp_r6_541;
            if (temp_r6_541 >= (s32) M2C_FIELD(M2C_FIELD(temp_r4_513, void **, 4), s32 *, 0x20)) {
                M2C_FIELD(temp_r4_513, s32 *, 0x10) = 0;
            }
        } else {
            temp_r0_552 = M2C_FIELD(temp_r4_513, s32 *, 0xC) - 1;
            M2C_FIELD(temp_r4_513, s32 *, 0xC) = temp_r0_552;
            if (temp_r0_552 < 0) {
                M2C_FIELD(temp_r4_513, s32 *, 0xC) = (s32) (M2C_FIELD(M2C_FIELD(temp_r4_513, void **, 4), s32 *, 0x20) - 1);
                M2C_FIELD(temp_r4_513, u8 *, 0) = (u8) M2C_FIELD(temp_r4_513, u8 *, 2);
            }
            temp_r0_563 = M2C_FIELD(temp_r4_513, s32 *, 0x10) - 1;
            M2C_FIELD(temp_r4_513, s32 *, 0x10) = temp_r0_563;
            if (temp_r0_563 < 0) {
                M2C_FIELD(temp_r4_513, s32 *, 0x10) = (s32) (M2C_FIELD(M2C_FIELD(temp_r4_513, void **, 4), s32 *, 0x20) - 1);
            }
        }
        temp_r7_571 = M2C_FIELD(temp_r4_513, void **, 4);
        temp_r6_573 = M2C_FIELD(temp_r7_571, s32 *, 0x1C);
        temp_r7_576 = M2C_FIELD(temp_r7_571, s32 *, 0x24);
        M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r6, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r5, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f2, $f1 */);
        sp70 = sp60;
        sp68 = M2C_FIELD((temp_r7_576 + (M2C_FIELD(temp_r4_513, s32 *, 0xC) * temp_r6_573)), f32 *, 8) - M2C_FIELD((temp_r7_576 + (M2C_FIELD(temp_r4_513, s32 *, 0x10) * temp_r6_573)), f32 *, 8);
        sp78 = (f64) sp68;
        var_f5_599 = ((f32) sp78 * (f32) sp78) + (((f32) sp70 * (f32) sp70) + (unksp74 * unksp74));
        if (var_f5_599 > 0.0f) {
            temp_f2_602 = __frsqrte(var_f5_599);
            temp_f2_608 = 0.5 * temp_f2_602 * -(((f64) var_f5_599 * (temp_f2_602 * temp_f2_602)) - 3.0);
            temp_f2_612 = 0.5 * temp_f2_608 * -(((f64) var_f5_599 * (temp_f2_608 * temp_f2_608)) - 3.0);
            var_f5_599 = (f32) ((f64) var_f5_599 * (0.5 * temp_f2_612 * -(((f64) var_f5_599 * (temp_f2_612 * temp_f2_612)) - 3.0)));
        } else if (var_f5_599 < M2C_BITWISE(f32, 0.0)) {
            var_f5_599 = __float_nan;
        } else {
            sp8 = var_f5_599;
            temp_r5_631 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r5_631) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_641 = 1;
                } else {
                    var_r0_641 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_641 = 5;
                } else {
                    var_r0_641 = 3;
                }
                break;
            default:
                var_r0_641 = 4;
                break;
            }
            if (var_r0_641 == 1) {
                var_f5_599 = __float_nan;
            }
        }
        M2C_FIELD(temp_r4_513, f32 *, 8) = var_f5_599;
        M2C_FIELD(temp_r4_513, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r4_513, f32 *, 0x18) - 1.0f);
    }
    temp_r7_668 = M2C_FIELD(temp_r4_513, void **, 4);
    temp_f5_669 = M2C_FIELD(temp_r4_513, f32 *, 0x18);
    temp_r5_671 = M2C_FIELD(temp_r7_668, s32 *, 0x1C);
    temp_r6_675 = M2C_FIELD(temp_r7_668, s32 *, 0x24);
    temp_r4_677 = temp_r6_675 + (M2C_FIELD(temp_r4_513, s32 *, 0x10) * temp_r5_671);
    temp_r5_678 = temp_r6_675 + (M2C_FIELD(temp_r4_513, s32 *, 0xC) * temp_r5_671);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f1, $f1, $f3 */);
    temp_f4_684 = M2C_FIELD(temp_r5_678, f32 *, 8);
    temp_f2_686 = M2C_FIELD(temp_r4_677, f32 *, 8) - temp_f4_684;
    sp50 = sp30;
    sp38 = temp_f2_686;
    sp58 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
    sp40 = sp20;
    sp28 = (f32) sp58 * temp_f5_669;
    sp48 = (f64) sp28;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
    temp_r3_705 = this->unk18;
    temp_f1_706 = temp_f4_684 + (f32) sp48;
    sp80 = sp10;
    sp18 = temp_f1_706;
    sp88 = (f64) sp18;
    temp_r3_715 = M2C_FIELD(*temp_r3_705, void *(**)(void **, void *, void *, s32, void *, f32, f32, M2C_UNK, f32, f32), 0x54)(temp_r3_705, temp_r4_677, temp_r5_678, temp_r6_675, temp_r7_668, temp_f1_706, temp_f2_686, M2C_ERROR(/* unknown instruction: psq_lx $f3, $zero, $r5, 0x0, qr0 */), temp_f4_684, temp_f5_669);
    M2C_FIELD(temp_r3_715, f32 *, 0x30) = (f32) sp80;
    M2C_FIELD(temp_r3_715, f32 *, 0x34) = unksp84;
    M2C_FIELD(temp_r3_715, f32 *, 0x38) = (f32) sp88;
    M2C_FIELD(temp_r3_715, f32 *, 0x3C) = 1.0f;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDPathFollowerProperty::Update() {
    if ((u8) *(KDProperty::pInstanceMem.__vptr + this->unk8) != 0) {
        if ((u8) this->unk10 != 0) {
            UpdateSplinePath();
            return;
        }
        UpdateNormalPath();
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void KDPathFollowerProperty::ResolveInstance() {
    void *temp_r31_766;
    void *temp_r4_785;

    temp_r31_766 = KDProperty::pInstanceMem.__vptr + this->unk8;
    if ((u8) this->unk10 != 0) {
        M2C_FIELD(temp_r31_766, void **, 4) = (void *) (KDProperty::pInstanceMem.__vptr + property_cast<KDSplinePathProperty *, KDPathProperty *>(this->unk14)->unk8);
        M2C_FIELD(temp_r31_766, f32 *, 0x14) = (f32) (M2C_FIELD(temp_r31_766, f32 *, 0x14) / M2C_FIELD(M2C_FIELD(temp_r31_766, void **, 4), f32 *, 0x38));
        return;
    }
    M2C_FIELD(temp_r31_766, void **, 4) = (void *) (KDProperty::pInstanceMem.__vptr + this->unk14->unk8);
    temp_r4_785 = M2C_FIELD(temp_r31_766, void **, 4);
    M2C_FIELD(temp_r31_766, f32 *, 8) = (f32) *(M2C_FIELD(temp_r4_785, s32 *, 0x24) + ((M2C_FIELD(temp_r31_766, s32 *, 0x10) * M2C_FIELD(temp_r4_785, s32 *, 0x1C)) + 0xC));
}
#endif

#if 0 // DRAFT: expression syntax error
s32 KDPathFollowerProperty::LoadLineInstance(MKIniLine *arg0) {
    s32 var_r30_835;
    void *temp_r3_824;

    if (arg0->LoadBool("bFunctioning", KDProperty::pInstanceMem.__vptr + (this->unk8 + 3), 0) != 0) {
        temp_r3_824 = KDProperty::pInstanceMem.__vptr + this->unk8;
        M2C_FIELD(temp_r3_824, u8 *, 0) = (u8) M2C_FIELD(temp_r3_824, u8 *, 3);
    }
    var_r30_835 = 0;
    if ((arg0->LoadFloat("pathSpeed", KDProperty::pInstanceMem.__vptr + (this->unk8 + 0x14), 0) != 0) || (arg0->LoadBool("bLooping", KDProperty::pInstanceMem.__vptr + (this->unk8 + 2), 0) != 0)) {
        var_r30_835 = 1;
    }
    return var_r30_835;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDPathFollowerProperty::InitInstance() {
    void *temp_r3_872;

    temp_r3_872 = KDProperty::pInstanceMem.__vptr + this->unk8;
    M2C_FIELD(temp_r3_872, s8 *, 0) = 0;
    M2C_FIELD(temp_r3_872, s8 *, 1) = 0;
    M2C_FIELD(temp_r3_872, s8 *, 2) = 1;
    M2C_FIELD(temp_r3_872, s8 *, 3) = 0;
    M2C_FIELD(temp_r3_872, s32 *, 4) = 0;
    M2C_FIELD(temp_r3_872, f32 *, 8) = 0.0f;
    M2C_FIELD(temp_r3_872, s32 *, 0xC) = 0;
    M2C_FIELD(temp_r3_872, s32 *, 0x10) = 1;
    M2C_FIELD(temp_r3_872, f32 *, 0x14) = 0.0f;
    M2C_FIELD(temp_r3_872, f32 *, 0x18) = 0.0f;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void KDPathFollowerProperty::Resolve(KDPropertySet *arg0) {
    KDPathProperty *temp_r4_900;

    this->unk18 = property_cast<KDMatrixProperty *, KDProperty *>(arg0->Find((s8 *) this->unk18));
    temp_r4_900 = this->unk14;
    if (temp_r4_900 != NULL) {
        this->unk14 = property_cast<KDPathProperty *, KDProperty *>(arg0->Find((s8 *) temp_r4_900));
    }
    this->unk10 = this->unk14->IsOfType((KDPropertyClassInfo *) &KDSplinePathProperty::classInfo);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 KDPathFollowerProperty::LoadLine(MKIniLine *arg0) {
    return (u8) (arg0->LoadString("path", (s8 **) &this->unk14, 0) != 0);
}
#endif

#if 0 // DRAFT: expression syntax error
void KDPathFollowerProperty::Command(int arg0) {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f1_1147;
    f32 temp_f2_1127;
    f32 temp_f4_1125;
    f32 temp_f5_1110;
    f32 var_f5_1045;
    f64 temp_f2_1048;
    f64 temp_f2_1054;
    f64 temp_f2_1058;
    s32 temp_r3_987;
    s32 temp_r5_1077;
    s32 temp_r5_1112;
    s32 temp_r6_1020;
    s32 temp_r6_1116;
    s32 temp_r7_1023;
    s32 var_r8_996;
    void **temp_r3_1146;
    void *temp_r3_1156;
    void *temp_r4_1118;
    void *temp_r4_976;
    void *temp_r4_998;
    void *temp_r5_1119;
    void *temp_r6_1008;
    void *temp_r7_1018;
    void *temp_r7_1109;

    switch (arg0) {                                 /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        *(KDProperty::pInstanceMem.__vptr + this->unk8) = 1;
        return;
    case 2:                                         /* switch 1 */
        *(KDProperty::pInstanceMem.__vptr + this->unk8) = 0;
        return;
    case 3:                                         /* switch 1 */
        temp_r4_976 = KDProperty::pInstanceMem.__vptr + this->unk8;
        M2C_FIELD(temp_r4_976, u8 *, 1) = (u8) (M2C_FIELD(temp_r4_976, u8 *, 1) == 0);
        M2C_FIELD(temp_r4_976, f32 *, 0x18) = (f32) (1.0f - M2C_FIELD(temp_r4_976, f32 *, 0x18));
        if ((u8) this->unk10 == 0) {
            temp_r3_987 = M2C_FIELD(temp_r4_976, s32 *, 0xC);
            M2C_FIELD(temp_r4_976, s32 *, 0xC) = (s32) M2C_FIELD(temp_r4_976, s32 *, 0x10);
            M2C_FIELD(temp_r4_976, s32 *, 0x10) = temp_r3_987;
            return;
        }
        return;
    case 4:                                         /* switch 1 */
        var_r8_996 = 1;
        temp_r4_998 = KDProperty::pInstanceMem.__vptr + this->unk8;
        M2C_FIELD(temp_r4_998, u8 *, 0) = (u8) M2C_FIELD(temp_r4_998, u8 *, 3);
        M2C_FIELD(temp_r4_998, s8 *, 1) = 0;
        M2C_FIELD(temp_r4_998, s32 *, 0xC) = 0;
        M2C_FIELD(temp_r4_998, s32 *, 0x10) = 1;
        M2C_FIELD(temp_r4_998, f32 *, 0x18) = 0.0f;
        if ((u8) this->unk10 != 0) {
            temp_r6_1008 = M2C_FIELD(temp_r4_998, void **, 4);
            M2C_FIELD(temp_r4_998, f32 *, 8) = (f32) *(M2C_FIELD(temp_r6_1008, s32 *, 0x24) + ((M2C_FIELD(temp_r4_998, s32 *, 0x10) * M2C_FIELD(temp_r6_1008, s32 *, 0x1C)) + 0xC));
        } else {
            temp_r7_1018 = M2C_FIELD(temp_r4_998, void **, 4);
            temp_r6_1020 = M2C_FIELD(temp_r7_1018, s32 *, 0x1C);
            temp_r7_1023 = M2C_FIELD(temp_r7_1018, s32 *, 0x24);
            M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r6, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r5, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f1, $f2, $f1 */);
            sp70 = sp60;
            sp68 = M2C_FIELD((temp_r7_1023 + (M2C_FIELD(temp_r4_998, s32 *, 0xC) * temp_r6_1020)), f32 *, 8) - M2C_FIELD((temp_r7_1023 + (M2C_FIELD(temp_r4_998, s32 *, 0x10) * temp_r6_1020)), f32 *, 8);
            sp78 = (f64) sp68;
            var_f5_1045 = ((f32) sp78 * (f32) sp78) + (((f32) sp70 * (f32) sp70) + (unksp74 * unksp74));
            if (var_f5_1045 > 0.0f) {
                temp_f2_1048 = __frsqrte(var_f5_1045);
                temp_f2_1054 = 0.5 * temp_f2_1048 * -(((f64) var_f5_1045 * (temp_f2_1048 * temp_f2_1048)) - 3.0);
                temp_f2_1058 = 0.5 * temp_f2_1054 * -(((f64) var_f5_1045 * (temp_f2_1054 * temp_f2_1054)) - 3.0);
                var_f5_1045 = (f32) ((f64) var_f5_1045 * (0.5 * temp_f2_1058 * -(((f64) var_f5_1045 * (temp_f2_1058 * temp_f2_1058)) - 3.0)));
            } else if (var_f5_1045 < M2C_BITWISE(f32, 0.0)) {
                var_f5_1045 = __float_nan;
            } else {
                sp8 = var_f5_1045;
                temp_r5_1077 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r5_1077) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {

                    } else {
                        var_r8_996 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r8_996 = 5;
                    } else {
                        var_r8_996 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r8_996 = 4;
                    break;
                }
                if (var_r8_996 == 1) {
                    var_f5_1045 = __float_nan;
                }
            }
            M2C_FIELD(temp_r4_998, f32 *, 8) = var_f5_1045;
        }
        temp_r7_1109 = M2C_FIELD(temp_r4_998, void **, 4);
        temp_f5_1110 = M2C_FIELD(temp_r4_998, f32 *, 0x18);
        temp_r5_1112 = M2C_FIELD(temp_r7_1109, s32 *, 0x1C);
        temp_r6_1116 = M2C_FIELD(temp_r7_1109, s32 *, 0x24);
        temp_r4_1118 = temp_r6_1116 + (M2C_FIELD(temp_r4_998, s32 *, 0x10) * temp_r5_1112);
        temp_r5_1119 = temp_r6_1116 + (M2C_FIELD(temp_r4_998, s32 *, 0xC) * temp_r5_1112);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f1, $f3 */);
        temp_f4_1125 = M2C_FIELD(temp_r5_1119, f32 *, 8);
        temp_f2_1127 = M2C_FIELD(temp_r4_1118, f32 *, 8) - temp_f4_1125;
        sp50 = sp30;
        sp38 = temp_f2_1127;
        sp58 = (f64) sp38;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
        sp40 = sp20;
        sp28 = (f32) sp58 * temp_f5_1110;
        sp48 = (f64) sp28;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
        temp_r3_1146 = this->unk18;
        temp_f1_1147 = temp_f4_1125 + (f32) sp48;
        sp80 = sp10;
        sp18 = temp_f1_1147;
        sp88 = (f64) sp18;
        temp_r3_1156 = M2C_FIELD(*temp_r3_1146, void *(**)(void **, void *, void *, s32, void *, f32, f32, M2C_UNK, f32, f32), 0x54)(temp_r3_1146, temp_r4_1118, temp_r5_1119, temp_r6_1116, temp_r7_1109, temp_f1_1147, temp_f2_1127, M2C_ERROR(/* unknown instruction: psq_lx $f3, $zero, $r5, 0x0, qr0 */), temp_f4_1125, temp_f5_1110);
        M2C_FIELD(temp_r3_1156, f32 *, 0x30) = (f32) sp80;
        M2C_FIELD(temp_r3_1156, f32 *, 0x34) = unksp84;
        M2C_FIELD(temp_r3_1156, f32 *, 0x38) = (f32) sp88;
        M2C_FIELD(temp_r3_1156, f32 *, 0x3C) = 1.0f;
        break;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[6])' does not match
s32 KDPathFollowerProperty::ResolveCommand(const char *arg0) const {
    s32 temp_r3_1215;

    if (stricmp(arg0, "start") == 0) {
        return 1;
    }
    if (stricmp(arg0, "stop") == 0) {
        return 2;
    }
    if (stricmp(arg0, "switchDirection") == 0) {
        return 3;
    }
    temp_r3_1215 = 0 - stricmp(arg0, "reset");
    return 4 & ~((temp_r3_1215 - temp_r3_1215) - !M2C_CARRY);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1C'
void KDMessageHandlerProperty::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 == (s32) this->unk1C) {
        Trigger();
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void KDMessageHandlerProperty::Trigger() {
    KDPropertyCommand **var_r29_1269;
    KDPropertyCommand *temp_r3_1275;
    s32 temp_cr0_eq_1258;
    s32 temp_r0_1281;
    s32 temp_r31_1259;
    u8 var_r5_1282;
    void *temp_r30_1257;

    temp_r30_1257 = KDProperty::pInstanceMem.__vptr;
    temp_cr0_eq_1258 = (u8) this->unk24 == 0;
    temp_r31_1259 = this->unk8;
    if ((temp_cr0_eq_1258 != 0) || ((temp_cr0_eq_1258 == 0) && ((u8) *(temp_r30_1257 + temp_r31_1259) == 0))) {
        if ((s32) this->unk10.unk0 == 1) {
            var_r29_1269 = &this->unk10.unk4;
        } else {
            var_r29_1269 = &this->unk10.unk4->unk0;
        }
loop_12:
        if (var_r29_1269 != NULL) {
            temp_r3_1275 = M2C_FIELD(var_r29_1269, KDPropertyCommand **, 0);
            M2C_FIELD(temp_r3_1275->unk0, M2C_UNK (**)(KDPropertyCommand *, s32), 0x48)(temp_r3_1275, M2C_FIELD(var_r29_1269, s32 *, 4));
            temp_r0_1281 = this->unk10.unk0;
            var_r5_1282 = 0;
            if ((temp_r0_1281 > 1) && ((KDPropertyCommand **) (var_r29_1269 + 8) < (void *) (this->unk10.unk4 + (temp_r0_1281 * 8)))) {
                var_r5_1282 = 1;
            }
            if (var_r5_1282 != 0) {
                var_r29_1269 += 8;
            } else {
                var_r29_1269 = NULL;
            }
            goto loop_12;
        }
    }
    *(temp_r30_1257 + temp_r31_1259) = 1;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDMessageHandlerProperty::InitInstance() {
    *(KDProperty::pInstanceMem.__vptr + this->unk8) = 0;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDMessageHandlerProperty::Resolve(KDPropertySet *arg0) {
    KDProperty *var_r31_1364;
    KDPropertyCommand **var_r31_1334;
    s32 temp_r0_1343;
    u8 var_r5_1344;

    if ((s32) this->unk10.unk0 == 1) {
        var_r31_1334 = &this->unk10.unk4;
    } else {
        var_r31_1334 = &this->unk10.unk4->unk0;
    }
loop_9:
    if (var_r31_1334 != NULL) {
        var_r31_1334->Resolve(arg0);
        temp_r0_1343 = this->unk10.unk0;
        var_r5_1344 = 0;
        if ((temp_r0_1343 > 1) && ((KDPropertyCommand **) (var_r31_1334 + 8) < (void *) (this->unk10.unk4 + (temp_r0_1343 * 8)))) {
            var_r5_1344 = 1;
        }
        if (var_r5_1344 != 0) {
            var_r31_1334 += 8;
        } else {
            var_r31_1334 = NULL;
        }
        goto loop_9;
    }
    var_r31_1364 = this->unkC;
loop_13:
    if (var_r31_1364 != NULL) {
        this->unk20 = property_cast<KDMessageHandlerProperty *, KDProperty *>(var_r31_1364);
        if ((KDMessageHandlerProperty *) this->unk20 == NULL) {
            var_r31_1364 = var_r31_1364->unkC;
            goto loop_13;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1C'
s32 KDMessageHandlerProperty::LoadLine(MKIniLine *arg0) {
    s32 var_r30_1397;
    u8 var_r31_1400;

    var_r30_1397 = 1;
    var_r31_1400 = 0;
    if ((arg0->LoadString("message", (s8 **) &this->unk1C, 0) != 0) || (arg0->LoadBool("oneShot", &this->unk24, 0) != 0)) {
        var_r31_1400 = 1;
    }
    if ((var_r31_1400 == 0) && (this->unk10.LoadLine(arg0, "script") == 0)) {
        var_r30_1397 = 0;
    }
    return var_r30_1397;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
void KDMessageHandlerProperty::Init(const char *arg0) {
    this->unk4 = arg0;
    this->unk24 = 0;
    this->unk1C = 0;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDAnimProperty::Command(int arg0) {
    s32 var_r5_1459;

    if (arg0 != 1) {
        return;
    }
    var_r5_1459 = 4;
    if ((u8) this->unk1C != 0) {
        var_r5_1459 = 1;
    }
    ((MKAnimScript *) (*(KDProperty::pInstanceMem.__vptr + M2C_FIELD(this->unk10, s32 *, 8))))->SetAnim(this->unk14, 1.0f, this->unk18, var_r5_1459, -1);
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[5], const char[13])' does
s32 KDAnimProperty::ResolveCommand(const char *arg0) const {
    return stricmp(arg0, "Play", "bOnByDefault") == 0;
}
#endif

#if 0 // DRAFT: function call 'property_cast(KDPropertyCommand *)' does not match
void KDAnimProperty::Resolve(KDPropertySet *arg0) {
    MKAnim *temp_r4_1518;
    MKAnimScript *temp_r3_1515;
    s8 *var_r0_1528;
    s8 *var_r4_1525;

    this->unk10 = property_cast<KDAnimScriptProperty *, KDProperty *>(arg0->Find("defaultAnimScript"));
    temp_r3_1515 = M2C_FIELD(this->unk10, MKAnimScript **, 0x10);
    if (temp_r3_1515 != NULL) {
        temp_r4_1518 = this->unk14;
        if (temp_r4_1518 != NULL) {
            this->unk14 = temp_r3_1515->GetAnim(&temp_r4_1518->unk0);
            return;
        }
        var_r4_1525 = this->unk4;
        if (var_r4_1525 != NULL) {
            var_r0_1528 = var_r4_1525;
        } else {
            var_r0_1528 = "";
        }
        if (var_r0_1528 != NULL) {
            if (var_r4_1525 != NULL) {

            } else {
                var_r4_1525 = "";
            }
            this->unk14 = temp_r3_1515->GetAnim(var_r4_1525);
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 KDAnimProperty::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1567;

    var_r31_1567 = 0;
    if ((arg0->LoadString("anim", (s8 **) &this->unk14, 0) != 0) || (arg0->LoadFloat("tweenTime", &this->unk18, 0) != 0) || (arg0->LoadBool("bKeepRelPos", &this->unk1C, 0) != 0)) {
        var_r31_1567 = 1;
    }
    return var_r31_1567;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDAnimEventProperty::Update() {
    MKAnimScript *temp_r31_1615;
    s32 temp_r4_1628;
    s32 var_r30_1611;
    u32 temp_r3_1632;

    var_r30_1611 = 0;
    temp_r31_1615 = *(KDProperty::pInstanceMem.__vptr + M2C_FIELD(this->unk1C, s32 *, 8));
loop_3:
    temp_r4_1628 = var_r30_1611;
    var_r30_1611 += 1;
    temp_r3_1632 = temp_r31_1615->GetEvent(temp_r4_1628, (MKAnimScriptedEvent::EventType) 0);
    if (temp_r3_1632 == 0U) {
        return;
    }
    if (temp_r3_1632 == (s8 *) this->unk20) {
        Trigger();
        return;
    }
    goto loop_3;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDAnimEventProperty::Resolve(KDPropertySet *arg0) {
    KDPropertyCommand **var_r30_1655;
    MKAnimScript *temp_r3_1693;
    s32 temp_r0_1664;
    s8 *temp_r4_1696;
    s8 *var_r0_1707;
    s8 *var_r4_1704;
    u8 var_r5_1665;

    if ((s32) this->unk10.unk0 == 1) {
        var_r30_1655 = &this->unk10.unk4;
    } else {
        var_r30_1655 = &this->unk10.unk4->unk0;
    }
loop_9:
    if (var_r30_1655 != NULL) {
        var_r30_1655->Resolve(arg0);
        temp_r0_1664 = this->unk10.unk0;
        var_r5_1665 = 0;
        if ((temp_r0_1664 > 1) && ((KDPropertyCommand **) (var_r30_1655 + 8) < (void *) (this->unk10.unk4 + (temp_r0_1664 * 8)))) {
            var_r5_1665 = 1;
        }
        if (var_r5_1665 != 0) {
            var_r30_1655 += 8;
        } else {
            var_r30_1655 = NULL;
        }
        goto loop_9;
    }
    this->unk1C = property_cast<KDAnimScriptProperty *, KDProperty *>(arg0->Find("defaultAnimScript"));
    temp_r3_1693 = M2C_FIELD(this->unk1C, MKAnimScript **, 0x10);
    if (temp_r3_1693 != NULL) {
        temp_r4_1696 = this->unk20;
        if (temp_r4_1696 != NULL) {
            this->unk20 = temp_r3_1693->GetEventByName(temp_r4_1696, (MKAnimScriptedEvent::EventType) 0);
            return;
        }
        var_r4_1704 = this->unk4;
        if (var_r4_1704 != NULL) {
            var_r0_1707 = var_r4_1704;
        } else {
            var_r0_1707 = "";
        }
        if (var_r0_1707 != NULL) {
            if (var_r4_1704 != NULL) {

            } else {
                var_r4_1704 = "";
            }
            this->unk20 = temp_r3_1693->GetEventByName(var_r4_1704, (MKAnimScriptedEvent::EventType) 0);
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
s32 KDAnimEventProperty::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1747;

    var_r31_1747 = 1;
    if ((this->unk10.LoadLine(arg0, "script") == 0) && (arg0->LoadString("event", &this->unk20, 0) == 0)) {
        var_r31_1747 = 0;
    }
    return var_r31_1747;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDRefPointProperty::Update() {
    Matrix *temp_r3_1796;

    MKModel_GetRefPointMatrix(*(KDProperty::pInstanceMem.__vptr + M2C_FIELD(this->unk10, s32 *, 8)), (s32) this->unk14, KDProperty::pInstanceMem.__vptr + this->unk8, 0U);
    temp_r3_1796 = KDProperty::pInstanceMem.__vptr + this->unk8;
    temp_r3_1796->Multiply4x4(temp_r3_1796, MKModel_GetWorldMatrix(*(KDProperty::pInstanceMem.__vptr + M2C_FIELD(this->unk10, s32 *, 8))));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void KDRefPointProperty::Resolve(KDPropertySet *arg0) {
    MKModel *temp_r3_1826;
    s8 *temp_r0_1814;
    s8 *temp_r3_1823;
    s8 *var_r0_1839;
    s8 *var_r4_1836;
    u32 temp_r4_1829;

    temp_r0_1814 = this->unk10;
    if (temp_r0_1814 != NULL) {
        this->unk10 = property_cast<KDModelProperty *, KDProperty *>(arg0->Find(temp_r0_1814));
    }
    temp_r3_1823 = this->unk10;
    if ((temp_r3_1823 != NULL) && (temp_r3_1826 = M2C_FIELD(temp_r3_1823, MKModel **, 0x10), ((temp_r3_1826 == NULL) == 0))) {
        temp_r4_1829 = this->unk14;
        if (temp_r4_1829 != 0) {
            this->unk14 = MKModel_GetRefPointIndex(temp_r3_1826, (s8 *) temp_r4_1829);
            return;
        }
        var_r4_1836 = this->unk4;
        if (var_r4_1836 != NULL) {
            var_r0_1839 = var_r4_1836;
        } else {
            var_r0_1839 = "";
        }
        if (var_r0_1839 != NULL) {
            if (var_r4_1836 != NULL) {

            } else {
                var_r4_1836 = "";
            }
            this->unk14 = MKModel_GetRefPointIndex(temp_r3_1826, var_r4_1836);
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 KDRefPointProperty::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1878;

    var_r31_1878 = 0;
    if ((arg0->LoadString("model", &this->unk10, 0) != 0) || (arg0->LoadString("refPoint", (s8 **) &this->unk14, 0) != 0)) {
        var_r31_1878 = 1;
    }
    return var_r31_1878;
}
#endif

void KDCommonProperties_RegisterAll(KDPropertyClassRegistry *arg0) {
    if ((u8) bRegistered == 0) {
        bRegistered = 1;
        arg0->Add((KDPropertyClassInfo *) &KDScriptProperty::classInfo);
        arg0->Add((KDPropertyClassInfo *) &KDPositionProperty::classInfo);
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0x10));
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0x20));
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0x30));
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0x40));
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0x50));
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0x60));
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0x70));
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0x80));
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0x90));
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0xA0));
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0xB0));
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0xC0));
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0xD0));
        arg0->Add((KDPropertyClassInfo *) (&KDPositionProperty::classInfo + 0xE0));
        KDParticleEffects_RegisterAll(arg0);
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void KDCommonProperties_cpp::__sinit() {
    KDPositionProperty *temp_r11_3110;
    KDPositionProperty *temp_r12_3069;
    KDPositionProperty *temp_r16_3070;
    KDPositionProperty *temp_r19_3128;
    KDPositionProperty *temp_r22_3059;
    KDPositionProperty *temp_r22_3125;
    KDPositionProperty *temp_r25_3063;
    KDPositionProperty *temp_r25_3122;
    KDPositionProperty *temp_r28_3065;
    KDPositionProperty *temp_r28_3119;
    KDPositionProperty *temp_r5_3116;
    KDPositionProperty *temp_r6_3076;
    KDPositionProperty *temp_r8_3113;
    KDPositionProperty *temp_r9_3073;

    temp_r22_3059 = &KDPositionProperty::classInfo + 0x10;
    temp_r25_3063 = &KDPositionProperty::classInfo + 0x20;
    temp_r28_3065 = &KDPositionProperty::classInfo + 0x30;
    temp_r12_3069 = &KDPositionProperty::classInfo + 0x40;
    temp_r16_3070 = &KDPositionProperty::classInfo + 0x70;
    temp_r9_3073 = &KDPositionProperty::classInfo + 0x50;
    temp_r6_3076 = &KDPositionProperty::classInfo + 0x60;
    KDPositionProperty::classInfo.__vptr = "KDPosition";
    KDPositionProperty::classInfo.unk8 = NULL;
    KDPositionProperty::classInfo.unk4 = &KDPropertyConstructor<KDPositionProperty>::Construct;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0x10) = "KDMatrix";
    temp_r22_3059->unk8 = &KDPositionProperty::classInfo;
    temp_r22_3059->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDMatrixProperty>::Construct;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0x20) = "KDMatrixRef";
    temp_r25_3063->unk8 = temp_r22_3059;
    temp_r25_3063->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDMatrixRefProperty>::Construct;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0x30) = "KDRefPoint";
    temp_r28_3065->unk8 = temp_r22_3059;
    temp_r28_3065->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDRefPointProperty>::Construct;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0x40) = "KDModel";
    temp_r12_3069->unk8 = NULL;
    temp_r12_3069->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDModelProperty>::Construct;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0x50) = "KDAnimScript";
    temp_r9_3073->unk8 = NULL;
    temp_r9_3073->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDAnimScriptProperty>::Construct;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0x60) = "KDAnimEvent";
    temp_r6_3076->unk8 = (KDPositionProperty *) &KDScriptProperty::classInfo;
    temp_r6_3076->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDAnimEventProperty>::Construct;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0x70) = "KDAnim";
    temp_r16_3070->unk8 = NULL;
    temp_r16_3070->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDAnimProperty>::Construct;
    temp_r11_3110 = &KDPositionProperty::classInfo + 0x80;
    temp_r8_3113 = &KDPositionProperty::classInfo + 0x90;
    temp_r5_3116 = &KDPositionProperty::classInfo + 0xA0;
    temp_r28_3119 = &KDPositionProperty::classInfo + 0xB0;
    temp_r25_3122 = &KDPositionProperty::classInfo + 0xC0;
    temp_r22_3125 = &KDPositionProperty::classInfo + 0xD0;
    temp_r19_3128 = &KDPositionProperty::classInfo + 0xE0;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0x80) = "KDMessageHandler";
    temp_r11_3110->unk8 = (KDPositionProperty *) &KDScriptProperty::classInfo;
    temp_r11_3110->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDMessageHandlerProperty>::Construct;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0x90) = "KDPath";
    temp_r8_3113->unk8 = NULL;
    temp_r8_3113->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDPathProperty>::Construct;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0xA0) = "KDSplinePath";
    temp_r5_3116->unk8 = temp_r8_3113;
    temp_r5_3116->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDSplinePathProperty>::Construct;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0xB0) = "KDPathFollower";
    temp_r28_3119->unk8 = NULL;
    temp_r28_3119->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDPathFollowerProperty>::Construct;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0xC0) = "KDCloth";
    temp_r25_3122->unk8 = NULL;
    temp_r25_3122->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDClothProperty>::Construct;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0xD0) = "KDSoundAttachment";
    temp_r22_3125->unk8 = NULL;
    temp_r22_3125->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDSoundAttachmentProperty>::Construct;
    M2C_FIELD(&KDPositionProperty::classInfo, s8 **, 0xE0) = "KDAmbientSound";
    temp_r19_3128->unk8 = temp_r22_3125;
    temp_r19_3128->unk4 = (void (*)(KDPropertyConstructor<KDPositionProperty> *)) &KDPropertyConstructor<KDAmbientSoundProperty>::Construct;
}
#endif
