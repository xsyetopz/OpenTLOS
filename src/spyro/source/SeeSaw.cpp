#include "spyro/source/SeeSaw.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Platform.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKModel.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern void **gMK;
extern f32 gUpdateTimeDelta;

void SeeSaw::Detach(PlatformAttachment *arg0) {
    this->unk13C -= 1;
    arg0->unkC->unk8 = arg0->unk8;
    arg0->unk8->unkC = arg0->unkC;
    arg0->unkC = arg0;
    arg0->unk8 = arg0;
}

void SeeSaw::Attach(PlatformAttachment *arg0) {
    arg0->unk8 = &this->unk118;
    arg0->unkC = this->unk118.unkC;
    this->unk118.unkC = arg0;
    arg0->unkC->unk8 = arg0;
    this->unk13C += 1;
}

#if 0 // DRAFT: undefined identifier 'PlatformAttachDetachMsg'
void SeeSaw::Message(MKMessage *arg0) {
    s32 temp_r0_111;
    void *temp_r3_120;
    void *temp_r3_130;

    ((KDSoundPlayer *) &this->unkF0)->Message(arg0);
    temp_r0_111 = arg0->unk0;
    switch (temp_r0_111) {                          /* irregular */
    case 35:
        temp_r3_120 = checked_cast<PlatformAttachDetachMsg *, MKMessage>(arg0);
        Attach(M2C_FIELD(temp_r3_120, PlatformAttachment **, 8));
        M2C_FIELD(temp_r3_120, s8 *, 0xC) = 1;
        break;
    case 36:
        temp_r3_130 = checked_cast<PlatformAttachDetachMsg *, MKMessage>(arg0);
        Detach(M2C_FIELD(temp_r3_130, PlatformAttachment **, 8));
        M2C_FIELD(temp_r3_130, s8 *, 0xC) = 1;
        break;
    }
    KDProp::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8C'
void SeeSaw::Update() {
    void *sp1B0;
    f64 sp1A8;                                      /* compiler-managed */
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    M2C_UNK sp150;
    Matrix sp110;
    Matrix spD0;
    s8 spCC;
    void *spC8;
    M2C_UNK *spC4;
    f64 *spC0;
    void *spBC;
    s32 spB8;
    s32 spB4;
    void *spB0;
    s32 spAC;
    s32 spA8;
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    s32 sp14;
    f32 sp10;
    s32 sp8;
    MKHeap *temp_r3_191;
    MKHeap *temp_r3_559;
    Platform *temp_r3_222;
    Platform *temp_r3_545;
    PlatformAttachment *var_r26_211;
    PlatformAttachment *var_r26_488;
    f32 temp_f2_382;
    f32 temp_f2_524;
    f32 temp_f30_315;
    f32 temp_f30_386;
    f32 temp_f31_292;
    f32 temp_f3_229;
    f32 temp_f3_325;
    f32 temp_f3_339;
    f32 temp_f3_355;
    f32 temp_f3_378;
    f32 temp_f3_500;
    f32 temp_f3_521;
    f32 temp_f4_376;
    f32 temp_f4_523;
    f32 temp_f5_519;
    f32 temp_f6_235;
    f32 temp_f6_506;
    f32 temp_f7_244;
    f32 temp_f7_512;
    f32 var_f0_330;
    s32 temp_r0_187;
    s32 temp_r0_281;
    s32 temp_r27_190;
    s32 var_r28_213;
    s32 var_r30_477;
    void *temp_r27_406;
    void *temp_r3_231;
    void *temp_r3_266;
    void *temp_r4_417;
    void *temp_r6_498;
    void *temp_r6_536;
    void *temp_r7_496;
    void *var_r3_199;

    this->unk90.Inverse((Matrix *) this->unk8);
    M2C_STRUCT_COPY((s32) &sp110.unk3C + 4, (s32) &this->unk8C + 4, 0x40);
    sp190 = this->unkD0;
    sp198 = this->unkD8;
    sp1A0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp1A8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    temp_r0_187 = this->unk13C;
    if (temp_r0_187 != 0) {
        temp_r27_190 = temp_r0_187 * 0x10;
        temp_r3_191 = ((MKHeap *) &MKVector3::zero)->Current();
        if (temp_r3_191 != NULL) {
            var_r3_199 = ((MKHeap *) (temp_r3_191->Main()))->TAlloc(temp_r27_190, NULL, 0, 0U);
        } else {
            var_r3_199 = malloc(temp_r27_190);
        }
        sp1B0 = var_r3_199;
    } else {
        sp1B0 = NULL;
    }
    var_r26_211 = this->unk118.unk8;
    var_r28_213 = 0;
loop_8:
    if (var_r26_211 != &this->unk118) {
        spAC = 0;
        spA8 = 0x5B;
        spB0 = NULL;
        temp_r3_222 = var_r26_211->unk0;
        temp_r3_222->Message(&spA8);
        temp_f3_229 = M2C_FIELD(spB0, f32 *, 4);
        temp_r3_231 = ((u8 *) sp1B0) + var_r28_213;
        temp_f6_235 = M2C_FIELD(spB0, f32 *, 0);
        temp_f7_244 = M2C_FIELD(spB0, f32 *, 8);
        sp38 = this->unk90.unk30 + ((temp_f7_244 * this->unk90.unk20) + ((temp_f6_235 * this->unk90.unk0) + (temp_f3_229 * this->unk90.unk10)));
        sp3C = this->unk90.unk34 + ((temp_f7_244 * this->unk90.unk24) + ((temp_f6_235 * this->unk90.unk4) + (temp_f3_229 * this->unk90.unk14)));
        sp40 = this->unk90.unk38 + ((temp_f7_244 * this->unk90.unk28) + ((temp_f6_235 * this->unk90.unk8) + (temp_f3_229 * this->unk90.unk18)));
        M2C_FIELD(temp_r3_231, f64 *, 0) = (f64) sp38;
        M2C_FIELD(temp_r3_231, f64 *, 8) = (f64) sp40;
        sp78 = (f64) sp38;
        temp_r3_266 = ((u8 *) sp1B0) + var_r28_213;
        sp80 = (f64) sp40;
        sp1A0 += M2C_FIELD(temp_r3_266, f64 *, 0);
        var_r28_213 += 0x10;
        sp1A8 = (f32) sp1A8 + M2C_FIELD(temp_r3_266, f32 *, 8);
        var_r26_211 = var_r26_211->unk8;
        goto loop_8;
    }
    temp_r0_281 = this->unk13C;
    if (temp_r0_281 > 0) {
        temp_f31_292 = 1.0f / (f32) temp_r0_281;
        sp1A0 *= (f64) temp_f31_292;
        sp98 = sp1A0;
        sp1A8 *= temp_f31_292;
        (*(f32 *) ((u8 *) &sp98 + 0x4)) = 0.0f;
        spA0 = (f64) sp1A8;
        ClampMagnitude(sp68, this->unk12C);
        sp98 = M2C_BITWISE(f64, sp68);
        spA0 = (f64) sp68.unk8;
        temp_f30_315 = this->unk130 / this->unk12C;
        sp98 *= (f64) temp_f30_315;
        spA0 = (f32) spA0 * temp_f30_315;
        this->unk128 = (f32) sp98;
        temp_f3_325 = this->unk128;
        if (temp_f3_325 < 0.0f) {
            var_f0_330 = -temp_f3_325;
        } else {
            var_f0_330 = temp_f3_325;
        }
        sp10 = temp_f3_325;
        temp_f3_339 = (f32) M2C_FIELD(this, f64 *, 0xD8);
        sp14 = (M2C_BITWISE(s32, sp10) & 0x80000000) | 0x3F800000;
        M2C_FIELD(this, f64 *, 0xD8) = (f32) ((gUpdateTimeDelta * (this->unk134 * var_f0_330) * ((this->unk130 * M2C_BITWISE(f32, sp14)) - temp_f3_339)) + temp_f3_339);
    } else {
        this->unk128 = 0.0f;
        temp_f3_355 = (f32) M2C_FIELD(this, f64 *, 0xD8);
        M2C_FIELD(this, f64 *, 0xD8) = (f32) ((0.1f * gUpdateTimeDelta * (this->unk128 - temp_f3_355)) + temp_f3_355);
    }
    M2C_FIELD(this, f32 *, 0xD4) = (f32) ((this->unk138 * gUpdateTimeDelta) + M2C_FIELD(this, f32 *, 0xD4));
    if ((s32) M2C_FIELD(checked_cast<SeeSawDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x70) != 0) {
        temp_f4_376 = M2C_FIELD(this, f32 *, 0xD4) - this->unkE4;
        temp_f3_378 = (f32) M2C_FIELD(this, f64 *, 0xD0) - this->unkE0;
        temp_f2_382 = (f32) M2C_FIELD(this, f64 *, 0xD8) - this->unkE8;
        temp_f30_386 = (temp_f2_382 * temp_f2_382) + ((temp_f3_378 * temp_f3_378) + (temp_f4_376 * temp_f4_376));
        if (temp_f30_386 >= M2C_FIELD(checked_cast<SeeSawDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x84)) {
            this->unk140 = 1;
        } else {
            this->unk140 = 0;
        }
        if ((s32) M2C_FIELD(checked_cast<SeeSawDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x70) != 0) {
            temp_r27_406 = checked_cast<SeeSawDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            KDSound_SetPitch(this->unkF0, (temp_f30_386 * M2C_FIELD(temp_r27_406, f32 *, 0x80)) + M2C_FIELD(checked_cast<SeeSawDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x7C));
            temp_r4_417 = checked_cast<SeeSawDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            sp8 = 1;
            ((KDSoundFader *) &this->unkF0)->Update(M2C_FIELD(temp_r4_417, s32 *, 0x70), 1U, this->unk140, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        }
        M2C_FIELD(this, f32 *, 0xE0) = (f64) this->unkD0;
        M2C_FIELD(this, f32 *, 0xE8) = (f64) this->unkD8;
    }
    M2C_STRUCT_COPY((s32) &spCC + 4, (s32) (((u8 *) this->unk8) - 4) + 4, 0x40);
    spD0.SetRotationPitch((f32) M2C_FIELD(this, f64 *, 0xD0));
    sp110.SetRotationRoll((f32) M2C_FIELD(this, f64 *, 0xD8));
    spD0.Multiply3x3(&spD0, &sp110);
    sp110.SetRotationYaw(M2C_FIELD(this, f32 *, 0xD4));
    spD0.Multiply3x3(&spD0, &sp110);
    MKModel_SetWorldMatrix(this->unk4, spD0);
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->ForceUpdate((u32) this->unk70.unkC);
    sp28 = this->unkD0 - sp190;
    var_r30_477 = 0;
    sp88 = sp28;
    sp30 = (f32) M2C_FIELD(this, f64 *, 0xD8) - (f32) sp198;
    sp58 = sp28;
    sp90 = (f64) sp30;
    sp60 = (f64) sp30;
    var_r26_488 = this->unk118.unk8;
loop_24:
    if (var_r26_488 != &this->unk118) {
        temp_r7_496 = this->unk8;
        temp_r6_498 = ((u8 *) sp1B0) + var_r30_477;
        temp_f3_500 = M2C_FIELD(temp_r6_498, f32 *, 4);
        temp_f6_506 = M2C_FIELD(temp_r6_498, f32 *, 0);
        temp_f7_512 = M2C_FIELD(temp_r6_498, f32 *, 8);
        temp_f5_519 = M2C_FIELD(temp_r7_496, f32 *, 0x30);
        temp_f3_521 = M2C_FIELD(temp_r7_496, f32 *, 0x34);
        temp_f4_523 = temp_f5_519 + ((temp_f7_512 * M2C_FIELD(temp_r7_496, f32 *, 0x20)) + ((temp_f6_506 * M2C_FIELD(temp_r7_496, f32 *, 0)) + (temp_f3_500 * M2C_FIELD(temp_r7_496, f32 *, 0x10))));
        temp_f2_524 = temp_f3_521 + ((temp_f7_512 * M2C_FIELD(temp_r7_496, f32 *, 0x24)) + ((temp_f6_506 * M2C_FIELD(temp_r7_496, f32 *, 4)) + (temp_f3_500 * M2C_FIELD(temp_r7_496, f32 *, 0x14))));
        sp18 = temp_f4_523;
        sp1C = temp_f2_524;
        sp20 = M2C_FIELD(temp_r7_496, f32 *, 0x38) + ((temp_f7_512 * M2C_FIELD(temp_r7_496, f32 *, 0x28)) + ((temp_f6_506 * M2C_FIELD(temp_r7_496, f32 *, 8)) + (temp_f3_500 * M2C_FIELD(temp_r7_496, f32 *, 0x18))));
        M2C_FIELD(temp_r6_498, f32 *, 0) = (f64) sp18;
        M2C_FIELD(temp_r6_498, f32 *, 8) = (f64) sp20;
        spB8 = 0;
        temp_r6_536 = this->unk8;
        sp48 = (f64) sp18;
        spB4 = 0x22;
        spBC = ((u8 *) sp1B0) + var_r30_477;
        spC0 = &sp88;
        spC4 = &sp150;
        spC8 = temp_r6_536;
        spCC = 0;
        temp_r3_545 = var_r26_488->unk0;
        sp50 = (f64) sp20;
        temp_r3_545->Message(&spB4, 0, temp_r6_536, temp_r7_496, (f64) sp18, temp_f2_524, temp_f3_521, temp_f4_523, temp_f5_519, temp_f6_506, temp_f7_512);
        var_r26_488 = var_r26_488->unk8;
        var_r30_477 += 0x10;
        goto loop_24;
    }
    if (sp1B0 != NULL) {
        temp_r3_559 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_559 != NULL) {
            ((MKHeap *) (temp_r3_559->Main()))->TFree(sp1B0, NULL, 0);
            return;
        }
        free(sp1B0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void SeeSaw::LoadDone() {
    f32 sp8;
    MKHeap **temp_r3_600;
    f32 temp_f0_602;
    f32 temp_f1_601;
    f32 temp_f3_604;
    f32 var_f4_609;
    f64 temp_f1_612;
    f64 temp_f1_618;
    f64 temp_f1_622;
    s32 temp_r3_641;
    s32 var_r0_651;

    KDProp::LoadDone();
    this->unk138 *= 0.017453292f;
    temp_r3_600 = MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1);
    temp_f1_601 = M2C_FIELD(temp_r3_600, f32 *, 0);
    temp_f0_602 = M2C_FIELD(temp_r3_600, f32 *, 4);
    temp_f3_604 = M2C_FIELD(temp_r3_600, f32 *, 8);
    var_f4_609 = (temp_f3_604 * temp_f3_604) + ((temp_f1_601 * temp_f1_601) + (temp_f0_602 * temp_f0_602));
    if (var_f4_609 > 0.0f) {
        temp_f1_612 = __frsqrte(var_f4_609);
        temp_f1_618 = 0.5 * temp_f1_612 * -(((f64) var_f4_609 * (temp_f1_612 * temp_f1_612)) - 3.0);
        temp_f1_622 = 0.5 * temp_f1_618 * -(((f64) var_f4_609 * (temp_f1_618 * temp_f1_618)) - 3.0);
        var_f4_609 = (f32) ((f64) var_f4_609 * (0.5 * temp_f1_622 * -(((f64) var_f4_609 * (temp_f1_622 * temp_f1_622)) - 3.0)));
    } else if (var_f4_609 < M2C_BITWISE(f32, 0.0)) {
        var_f4_609 = __float_nan;
    } else {
        sp8 = var_f4_609;
        temp_r3_641 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_641) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_651 = 1;
            } else {
                var_r0_651 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_651 = 5;
            } else {
                var_r0_651 = 3;
            }
            break;
        default:
            var_r0_651 = 4;
            break;
        }
        if (var_r0_651 == 1) {
            var_f4_609 = __float_nan;
        }
    }
    this->unk12C = var_f4_609;
    this->unk128 = 0.0f;
    M2C_FIELD(this, f32 *, 0xD4) = (f32) M2C_FIELD(&MKProp::loadInfo, f32 *, 0x54);
    M2C_FIELD(this, f64 *, 0xE0) = (f64) this->unkD0;
    M2C_FIELD(this, f64 *, 0xE8) = (f64) this->unkD8;
}
#endif

s32 SeeSaw::LoadLine(MKIniLine *arg0) {
    s32 var_r31_699;

    var_r31_699 = 0;
    if ((KDProp::LoadLine(arg0) != 0) || (arg0->LoadFloat("fRotSpeed", &this->unk134, 0) != 0) || (arg0->LoadFloat("fMaxTilt", &this->unk130, 0) != 0) || (arg0->LoadFloat("spinSpeed", &this->unk138, 0) != 0)) {
        var_r31_699 = 1;
    }
    return var_r31_699;
}

#if 0 // DRAFT: ')' expected
void SeeSaw::Resolve() {
    void *temp_r31_751;

    MKProp::Resolve();
    temp_r31_751 = checked_cast<SeeSawDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unkF0)->Init(M2C_FIELD(checked_cast<SeeSawDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x74), M2C_FIELD(temp_r31_751, f32 *, 0x78));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SeeSaw::Deinit() {
    s32 spC;
    s32 sp8;
    Platform *temp_r3_778;
    PlatformAttachment *temp_r3_787;

loop_2:
    temp_r3_787 = this->unk118.unk8;
    if (temp_r3_787 != &this->unk118) {
        temp_r3_778 = temp_r3_787->unk0;
        spC = 0;
        sp8 = 0x26;
        temp_r3_778->Message(&sp8);
        goto loop_2;
    }
    KDSound_Stop(&this->unkF0);
    KDProp::Deinit();
}
#endif

void SeeSaw::Init() {
    KDProp::Init();
    this->unkD0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unkD8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk140 = 0;
    this->unk130 = 0.7853982f;
    this->unk134 = 2.0f;
    this->unk13C = 0;
    this->unk138 = 15.0f;
}

#if 0 // DRAFT: function call 'KDSound_LoadLine(MKIniLine *, const char[10], long *)' does
s32 SeeSawDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_840;

    var_r31_840 = 0;
    if ((KDPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("tiltFadeIn", &this->unk74, 0) != 0) || (arg0->LoadFloat("tiltFadeOut", &this->unk78, 0) != 0) || (arg0->LoadFloat("tiltBasePitch", &this->unk7C, 0) != 0) || (arg0->LoadFloat("tiltPitchMult", &this->unk80, 0) != 0) || (arg0->LoadFloat("tiltSoundThreshold", &this->unk84, 0) != 0) || (KDSound_LoadLine(arg0, "sndTiltLP", &this->unk70) != 0)) {
        var_r31_840 = 1;
    }
    return var_r31_840;
}
#endif

void SeeSawDescriptor::Init() {
    KDPropDescriptor::Init();
    this->unkC |= 0x4002;
    this->unk70 = 0;
    this->unk74 = 0.25f;
    this->unk78 = 0.25f;
    this->unk7C = 0.85f;
    this->unk80 = 100.0f;
    this->unk84 = 0.0000005f;
}
