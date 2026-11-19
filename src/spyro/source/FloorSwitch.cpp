#include "spyro/source/FloorSwitch.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Trap.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;
extern f32 ONE_OVER_THRESHOLD_DIST_WITH_DELTABEND;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 THRESHOLD_DIST;
extern s32 gViewSeed;
extern M2C_UNK gb;

void FloorSwitch::SetState(int arg0) {
    void *temp_r31_63;

    this->unkE0 = arg0;
    if ((MKAnimScript *) this->unk80 != NULL) {
        temp_r31_63 = checked_cast<FloorSwitchDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        this->unk80->SetAnim(M2C_FIELD((checked_cast<FloorSwitchDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unkE0 * 4)), MKAnim **, 0xF8), M2C_FIELD(temp_r31_63, f32 *, 0x108), 0.0f, 0, -1);
    }
}

#if 0 // DRAFT: undefined identifier 'IsActivatedMsg'
void FloorSwitch::Message(MKMessage *arg0) {
    u8 sp10;
    s32 spC;
    s32 sp8;
    KDSoundPlayer *temp_r3_105;
    KDSoundPlayer *temp_r3_94;
    KDSoundPlayer *temp_r3_99;
    s32 temp_r0_111;
    void **temp_r3_128;
    void *temp_r3_151;

    temp_r3_94 = M2C_FIELD(this, KDSoundPlayer **, 0x114);
    if (temp_r3_94 != NULL) {
        temp_r3_94->Message(arg0);
    }
    temp_r3_99 = M2C_FIELD(this, KDSoundPlayer **, 0x118);
    if (temp_r3_99 != NULL) {
        temp_r3_99->Message(arg0);
    }
    temp_r3_105 = this->unk114;
    if (temp_r3_105 != NULL) {
        temp_r3_105->Message(arg0);
    }
    temp_r0_111 = arg0->unk0;
    switch (temp_r0_111) {                          /* irregular */
    case 0x12:
        spC = 0;
        sp10 = 0;
        sp8 = 0x6E;
        temp_r3_128 = arg0->unkC;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(*temp_r3_128, void *(**)(void **), 0x2C)(temp_r3_128), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        if ((sp10 != 0) && ((s32) this->unkE0 == -1)) {
            M2C_FIELD(this, u8 *, 0xEC) = (u8) (M2C_FIELD(this, u8 *, 0xEC) | 0x80);
        }
        break;
    case 0x4F:
        temp_r3_151 = checked_cast<IsActivatedMsg *, MKMessage>(arg0);
        if ((s32) this->unkE0 == 2) {
            M2C_FIELD(temp_r3_151, s8 *, 8) = 1;
        } else {
            M2C_FIELD(temp_r3_151, s8 *, 8) = 0;
        }
        break;
    case 0x50:
        M2C_FIELD(this, u8 *, 0xEC) = (u8) (M2C_FIELD(this, u8 *, 0xEC) | 0x80);
        break;
    }
    Trap::Message(arg0);
}
#endif

void FloorSwitch::Reset() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    Trap::Reset();
    M2C_FIELD(this, u8 *, 0xEC) = (u8) (M2C_FIELD(this, u8 *, 0xEC) & ~0x80);
    M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) | 0x80);
    M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) & ~0x40);
    M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) & ~0x20);
    M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) & ~0x10);
    SetState(0);
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
    M2C_FIELD(this, u8 *, 0xEC) = (u8) (M2C_FIELD(this, u8 *, 0xEC) & ~0x40);
    M2C_FIELD(this, f64 *, 0x100) = (f64) sp8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk100 = (f64) sp10;
}

void FloorSwitch::Draw() {
    f64 sp10;
    f64 sp8;
    f64 *temp_r3_240;
    s32 temp_r0_236;

    temp_r0_236 = this->unk120.unk0;
    if ((u32) temp_r0_236 != 0U) {
        temp_r3_240 = MKMaterial_GetColor((MKMaterial *) temp_r0_236);
        sp8 = M2C_FIELD(temp_r3_240, f64 *, 0);
        sp10 = M2C_FIELD(temp_r3_240, f64 *, 8);
        MKMaterial_SetColor((MKMaterial *) this->unk120.unk0, *((MKVector4 *) &this->unkEC));
        GameProp::Draw();
        MKMaterial_SetColor((MKMaterial *) this->unk120.unk0, *((MKVector4 *) &sp8));
        return;
    }
    GameProp::Draw();
}

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void FloorSwitch::Update() {
    s8 sp130;
    f64 sp128;
    f64 sp120;
    s32 sp11C;
    s32 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    M2C_UNK spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp10;
    s32 sp8;
    KDSoundFader *temp_r3_281;
    MKAnimScript *temp_r3_583;
    MKAnimScript *temp_r3_652;
    MKVector3 *temp_r30_609;
    f32 temp_f1_412;
    f32 temp_f1_536;
    f32 temp_f28_355;
    f32 temp_f29_350;
    f32 var_f3_487;
    f32 var_f4_420;
    f64 temp_f1_426;
    f64 temp_f1_432;
    f64 temp_f1_436;
    s32 temp_r0_544;
    s32 temp_r3_455;
    s32 var_r0_465;
    u8 var_r4_584;
    u8 var_r4_650;
    void *temp_r4_290;
    void *temp_r4_309;
    void *temp_r4_328;

    GameProp::Update();
    temp_r3_281 = M2C_FIELD(this, KDSoundFader **, 0x114);
    if (temp_r3_281 != NULL) {
        KDSound_SetPitch(temp_r3_281->unk0, 1.0f);
        temp_r4_290 = checked_cast<FloorSwitchDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) (M2C_FIELD(this, KDSoundFader **, 0x114)))->Update(M2C_FIELD(temp_r4_290, s32 *, 0xEC), 1U, ((u8) M2C_FIELD(this, u8 *, 0x110) >> 7U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((KDSoundFader *) M2C_FIELD(this, KDSoundFader **, 0x118) != NULL) {
        temp_r4_309 = checked_cast<FloorSwitchDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) (M2C_FIELD(this, KDSoundFader **, 0x118)))->Update(M2C_FIELD(temp_r4_309, s32 *, 0xF0), 1U, ((u8) M2C_FIELD(this, u8 *, 0x110) >> 6U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((KDSoundPlayer *) this->unk114 != NULL) {
        temp_r4_328 = checked_cast<FloorSwitchDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        this->unk114->Update(M2C_FIELD(temp_r4_328, s32 *, 0xF4), 1U, ((u8) M2C_FIELD(this, u8 *, 0x110) >> 5U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if (((u8) M2C_FIELD(this, u8 *, 0x110) >> 5U) & 1) {
        sp11C = 0;
        temp_f29_350 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f28_355 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f28_355, temp_f29_350);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp118 = 0x417;
        sp20 = spE0 * 10.0f;
        sp120 = sp18;
        sp128 = (f64) sp20;
        sp130 = 1;
        spE8 = sp18;
        spF0 = (f64) sp20;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp118, sp18);
    }
    sp80 = -1.0f;
    sp70 = 1.0f;
    sp78 = -1.0f;
    sp7C = 0.0f;
    sp68 = 1.0f;
    sp6C = 0.0f;
    sp98 = (f64) sp78;
    spA0 = (f64) sp80;
    sp88 = (f64) sp68;
    sp90 = (f64) sp70;
    KDRand_Vector(spA8, *((MKVector3 *) &sp98));
    temp_f1_412 = M2C_BITWISE(f32, spA8);
    var_f4_420 = (spA8.unk8 * spA8.unk8) + ((temp_f1_412 * temp_f1_412) + (spA8.unk4 * spA8.unk4));
    if (var_f4_420 > 1e-12f) {
        if (var_f4_420 > 0.0f) {
            temp_f1_426 = __frsqrte(var_f4_420);
            temp_f1_432 = 0.5 * temp_f1_426 * -(((f64) var_f4_420 * (temp_f1_426 * temp_f1_426)) - 3.0);
            temp_f1_436 = 0.5 * temp_f1_432 * -(((f64) var_f4_420 * (temp_f1_432 * temp_f1_432)) - 3.0);
            var_f4_420 = (f32) ((f64) var_f4_420 * (0.5 * temp_f1_436 * -(((f64) var_f4_420 * (temp_f1_436 * temp_f1_436)) - 3.0)));
        } else if (var_f4_420 < M2C_BITWISE(f32, 0.0)) {
            var_f4_420 = __float_nan;
        } else {
            sp10 = var_f4_420;
            temp_r3_455 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_455) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_465 = 1;
                } else {
                    var_r0_465 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_465 = 5;
                } else {
                    var_r0_465 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_465 = 4;
                break;
            }
            if (var_r0_465 == 1) {
                var_f4_420 = __float_nan;
            }
        }
        var_f3_487 = 1.0f / var_f4_420;
    } else {
        var_f3_487 = 0.0f;
    }
    sp38 = M2C_BITWISE(f32, spA8) * var_f3_487;
    sp3C = spA8.unk4 * var_f3_487;
    sp40 = spA8.unk8 * var_f3_487;
    spB8 = (f64) sp38;
    spC0 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    spC8 = sp58;
    sp60 = (f32) spC0 * 100.0f;
    spD0 = (f64) sp60;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp108 = sp48;
    sp50 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) spD0;
    sp110 = (f64) sp50;
    temp_f1_536 = 1000.0f * MKRand_Float(&gViewSeed, 1.0f, 2.0f);
    sp30 = 0.0f;
    sp28 = 0.0f;
    sp2C = temp_f1_536;
    sp100 = (f64) sp30;
    spF8 = (f64) sp28;
    temp_r0_544 = this->unkE0;
    switch (temp_r0_544) {                          /* switch 2; irregular */
    default:                                        /* switch 2 */
    case 0:                                         /* switch 2 */
        if (((u8) M2C_FIELD(this, u8 *, 0xEC) >> 6U) & 1) {
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &sp108), *((MKVector3 *) &spF8), 5.0f, *((MKVector4 *) &this->unkEC), 0.0f);
        }
        if (((u8) M2C_FIELD(this, u8 *, 0xEC) >> 7U) & 1) {
            SetState(1);
        }
        M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) | 0x80);
        break;
    case 1:                                         /* switch 2 */
        temp_r3_583 = this->unk80;
        var_r4_584 = 0;
        if ((temp_r3_583 != NULL) && (temp_r3_583->unk2C & 1)) {
            var_r4_584 = 1;
        }
        if (temp_r3_583 == NULL) {
            var_r4_584 = 1;
        }
        if (var_r4_584 != 0) {
            M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) & ~0x80);
            if ((s32) M2C_FIELD(checked_cast<FloorSwitchDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE8) != 0) {
                temp_r30_609 = this->unk8 + 0x30;
                KDSound_Play3d(M2C_FIELD(checked_cast<FloorSwitchDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE8), temp_r30_609, 0U, -1, 0.0f, 0U);
            }
            M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) | 0x40);
            SetState(2);
            this->unk118.Send((MKProp *) this);
        }
        break;
    case 2:                                         /* switch 2 */
        if (!(((u8) M2C_FIELD(this, u8 *, 0xEC) >> 7U) & 1)) {
            SetState(3);
            this->unk11C.Send((MKProp *) this);
        }
        M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) & ~0x80);
        break;
    case 3:                                         /* switch 2 */
        var_r4_650 = 0;
        M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) & ~0x40);
        temp_r3_652 = this->unk80;
        if ((temp_r3_652 != NULL) && (temp_r3_652->unk2C & 1)) {
            var_r4_650 = 1;
        }
        if (temp_r3_652 == NULL) {
            var_r4_650 = 1;
        }
        if (var_r4_650 != 0) {
            SetState(0);
            M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) | 0x80);
        }
        break;
    }
    if ((s32) this->unkE0 == -1) {
        M2C_FIELD(this, u8 *, 0xEC) = (u8) (M2C_FIELD(this, u8 *, 0xEC) & ~0x80);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void FloorSwitch::LoadDone() {
    Trap::LoadDone();
    if ((s32) M2C_FIELD(checked_cast<FloorSwitchDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xEC) != 0) {
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = 0;
        }
        M2C_FIELD(this, KDSoundFader **, 0x114) = (KDSoundFader *) M2C_ERROR(/* Read from unset register $r3 */);
        ((KDSoundFader *) (M2C_FIELD(this, KDSoundFader **, 0x114)))->Init(0.25f, 0.25f);
    }
    if ((s32) M2C_FIELD(checked_cast<FloorSwitchDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xF0) != 0) {
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = 0;
        }
        M2C_FIELD(this, KDSoundFader **, 0x118) = (KDSoundFader *) M2C_ERROR(/* Read from unset register $r3 */);
        ((KDSoundFader *) (M2C_FIELD(this, KDSoundFader **, 0x118)))->Init(0.25f, 0.25f);
    }
    if ((s32) M2C_FIELD(checked_cast<FloorSwitchDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xF4) != 0) {
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = 0;
        }
        this->unk114 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk114->Init(0.25f, 0.25f);
    }
    this->unk120.unk0 = MKMaterial_Create("p_white_pad");
}
#endif

#if 0 // DRAFT: expression syntax error
s32 FloorSwitch::LoadLine(MKIniLine *arg0) {
    s32 var_r31_786;

    var_r31_786 = 0;
    if ((Trap::LoadLine(arg0) != 0) || (this->unk118.LoadLine(arg0, "OnPressed") != 0) || (this->unk11C.LoadLine(arg0, "OnReleased") != 0) || (arg0->LoadInt("ActivatorPropID", &this->unkE0, 0) != 0) || (arg0->LoadFloat("ActivationRange", (f32 *) &this->unkE4, 0) != 0) || (arg0->LoadVector4("SwitchColor", (MKVector4 *) &this->unkEC, 0) != 0)) {
        var_r31_786 = 1;
    }
    return var_r31_786;
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void FloorSwitch::Deinit() {
    KDSoundPlayer *temp_r31_897;
    KDSoundPlayer *temp_r3_893;
    s32 *temp_r31_863;
    s32 *temp_r31_880;
    s32 *temp_r3_859;
    s32 *temp_r3_876;
    s32 temp_cr0_eq_864;
    s32 temp_cr0_eq_881;
    s32 temp_cr0_eq_898;
    s32 temp_r3_852;

    temp_r3_852 = this->unk120.unk0;
    if ((u32) temp_r3_852 != 0U) {
        MKMaterial_Destroy((MKMaterial *) temp_r3_852);
        this->unk120.unk0 = 0;
    }
    temp_r3_859 = M2C_FIELD(this, s32 **, 0x114);
    if (temp_r3_859 != NULL) {
        KDSound_Stop(temp_r3_859);
        temp_r31_863 = M2C_FIELD(this, s32 **, 0x114);
        temp_cr0_eq_864 = temp_r31_863 == NULL;
        if (temp_cr0_eq_864 == 0) {
            if (temp_cr0_eq_864 == 0) {
                KDSound_Stop(temp_r31_863);
            }
            operator delete(temp_r31_863);
        }
        M2C_FIELD(this, s32 **, 0x114) = NULL;
    }
    temp_r3_876 = M2C_FIELD(this, s32 **, 0x118);
    if (temp_r3_876 != NULL) {
        KDSound_Stop(temp_r3_876);
        temp_r31_880 = M2C_FIELD(this, s32 **, 0x118);
        temp_cr0_eq_881 = temp_r31_880 == NULL;
        if (temp_cr0_eq_881 == 0) {
            if (temp_cr0_eq_881 == 0) {
                KDSound_Stop(temp_r31_880);
            }
            operator delete(temp_r31_880);
        }
        M2C_FIELD(this, s32 **, 0x118) = NULL;
    }
    temp_r3_893 = this->unk114;
    if (temp_r3_893 != NULL) {
        KDSound_Stop(&temp_r3_893->unk0);
        temp_r31_897 = this->unk114;
        temp_cr0_eq_898 = temp_r31_897 == NULL;
        if (temp_cr0_eq_898 == 0) {
            if (temp_cr0_eq_898 == 0) {
                KDSound_Stop(&temp_r31_897->unk0);
            }
            operator delete(temp_r31_897);
        }
        this->unk114 = NULL;
    }
    GameProp::Deinit();
}
#endif

void FloorSwitch::Init() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    Trap::Init();
    M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) | 0x80);
    sp10 = 1.0f;
    M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) & ~0x40);
    sp18 = 1.0f;
    M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) & ~0x20);
    sp1C = 1.0f;
    M2C_FIELD(this, u8 *, 0x110) = (u8) (M2C_FIELD(this, u8 *, 0x110) & ~0x10);
    M2C_FIELD(this, s32 *, 0x114) = 0;
    M2C_FIELD(this, s32 *, 0x118) = 0;
    this->unk114 = NULL;
    this->unkE0 = -1;
    this->unkE4 = 0.0f;
    sp20 = 1.0f;
    sp24 = 1.0f;
    M2C_FIELD(this, f64 *, 0xF0) = (f64) sp18;
    M2C_FIELD(this, f64 *, 0xF8) = (f64) sp20;
    sp8 = 1.0f;
    spC = 1.0f;
    M2C_FIELD(this, u8 *, 0xEC) = (u8) (M2C_FIELD(this, u8 *, 0xEC) | 0x40);
    M2C_FIELD(this, f64 *, 0x100) = (f64) sp8;
    this->unk100 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    this->unk120.unk0 = 0;
}

#if 0 // DRAFT: illegal use of non-static member
void FloorSwitchDescriptor::LoadDone() {
    s8 *temp_r3_989;

    GamePropDescriptor::LoadDone();
    temp_r3_989 = this->unk34;
    if (temp_r3_989 != NULL) {
        this->unkF8 = temp_r3_989->GetAnim("idle");
        this->unkFC = this->unk34->GetAnim("activate");
        this->unk100 = this->unk34->GetAnim("activated");
        this->unk104 = this->unk34->GetAnim("deactivate");
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 FloorSwitchDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1032;

    var_r31_1032 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "beckonSoundLoop", &this->unkEC) != 0) || (KDSound_LoadLine(arg0, "activeSoundLoop", &this->unkF0) != 0) || (KDSound_LoadLine(arg0, "dropSoundLoop", &this->unkF4) != 0) || (KDSound_LoadLine(arg0, "activationSound", &this->unkE8) != 0) || (KDSound_LoadLine(arg0, "beginActivationSound", &this->unkE4) != 0) || (arg0->LoadFloat("AnimSpeed", &this->unk108, 0) != 0)) {
        var_r31_1032 = 1;
    }
    return var_r31_1032;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FloorSwitchDescriptor::Init() {
    TrapDescriptor::Init();
    this->unkE4 = GS_PLACEHOLDER;
    this->unkE8 = GS_PLACEHOLDER;
    this->unkEC = GS_PLACEHOLDER;
    this->unkF0 = GS_PLACEHOLDER;
    this->unkF4 = GS_PLACEHOLDER;
    this->unk108 = 1.0f;
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<IsActivatedMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FloorSwitchDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif

void FloorSwitch_cpp::__sinit() {
    f64 temp_f1_1156;
    f64 temp_f1_1164;
    f64 temp_f2_1147;
    f64 temp_f4_1145;
    f64 temp_f4_1153;
    f64 temp_f4_1161;
    f64 temp_f6_1140;
    f64 temp_f9_1142;

    temp_f6_1140 = __frsqrte(2014000.0);
    temp_f9_1142 = __frsqrte(380000.0);
    temp_f4_1145 = temp_f6_1140 * temp_f6_1140;
    temp_f2_1147 = temp_f9_1142 * temp_f9_1142;
    THRESHOLD_DIST = 1440000.0f;
    ONE_OVER_THRESHOLD_DIST_WITH_DELTABEND = 4.1666667e-8f;
    temp_f4_1153 = 0.5 * temp_f6_1140 * -((2014000.0 * temp_f4_1145) - 3.0);
    temp_f1_1156 = 0.5 * temp_f9_1142 * -((380000.0 * temp_f2_1147) - 3.0);
    temp_f4_1161 = 0.5 * temp_f4_1153 * -((2014000.0 * (temp_f4_1153 * temp_f4_1153)) - 3.0);
    temp_f1_1164 = 0.5 * temp_f1_1156 * -((380000.0 * (temp_f1_1156 * temp_f1_1156)) - 3.0);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1161 * -((2014000.0 * (temp_f4_1161 * temp_f4_1161)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_1164 * -((380000.0 * (temp_f1_1164 * temp_f1_1164)) - 3.0)));
}
