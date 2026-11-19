#include "spyro/source/SlimeTrailFX.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDSpline.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern s32 GS_SpyroZapBurn;
extern f32 *KDSpline_PositionMixer;
extern M2C_UNK gEmptyPtrListDL;
extern s32 gViewSeed;
extern void **gb;

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
void SlimeTrailFXManager::Deinit() {
    MKHeap *temp_r0_43;
    MKHeap *temp_r0_62;
    MKHeap *temp_r3_22;
    MKHeap *temp_r3_65;
    MKHeap *var_r31_39;
    MKHeap *var_r3_40;
    MKHeap *var_r4_38;
    SlimeTrailFX **var_r31_26;
    SlimeTrailFX *temp_r3_34;
    u32 temp_r0_48;

loop_2:
    temp_r3_22 = this->unk0;
    if ((MKHeap *) temp_r3_22->unk0 != NULL) {
        this->unk0 = (MKHeap *) &this->unk0->unk4;
        goto loop_2;
    }
    var_r31_26 = temp_r3_22 - 4;
loop_5:
    if (var_r31_26 != NULL) {
        temp_r3_34 = *var_r31_26;
        if (temp_r3_34 != NULL) {
            temp_r3_34->Deinit();
            var_r31_26 -= 4;
            goto loop_5;
        }
    }
    var_r4_38 = this->unk0;
    var_r31_39 = var_r4_38;
    var_r3_40 = var_r4_38;
loop_10:
    temp_r0_48 = M2C_FIELD(var_r3_40, u32 *, -4);
    var_r3_40 -= 4;
    if (temp_r0_48 != 0U) {
        temp_r0_43 = var_r3_40->unk0;
        if (temp_r0_43 < var_r31_39) {
            var_r31_39 = temp_r0_43;
        }
        goto loop_10;
    }
    if (var_r3_40 != &gEmptyPtrListDL) {
loop_16:
        temp_r0_62 = var_r4_38->unk0;
        if (temp_r0_62 != NULL) {
            if (temp_r0_62 < var_r31_39) {
                var_r31_39 = temp_r0_62;
            }
            var_r4_38 += 4;
            goto loop_16;
        }
        temp_r3_65 = var_r3_40->Current();
        if (temp_r3_65 != NULL) {
            ((MKHeap *) (temp_r3_65->Current()))->Free(var_r31_39, NULL, 0);
        } else {
            free(var_r31_39);
        }
    }
    this->unk0 = NULL;
}
#endif

#if 0 // DRAFT: type mismatch
void SlimeTrailFXManager::FreeTrail(SlimeTrailFX *arg0) {
    MKHeap *temp_r0_107;
    MKHeap *temp_r5_95;
    MKHeap *temp_r6_98;
    MKHeap *var_r7_90;

    var_r7_90 = this->unk0;
loop_4:
    if (var_r7_90 != NULL) {
        temp_r0_107 = var_r7_90->unk0;
        if (temp_r0_107 == NULL) {
            return;
        }
        if (temp_r0_107 == arg0) {
            temp_r5_95 = this->unk0;
            this->unk0 = (MKHeap *) &temp_r5_95->unk4;
            temp_r6_98 = temp_r5_95->unk0;
            temp_r5_95->unk0 = var_r7_90->unk0;
            var_r7_90->unk0 = temp_r6_98;
        }
        var_r7_90 += 4;
        goto loop_4;
    }
}
#endif

SlimeTrailFX *SlimeTrailFXManager::AllocTrail(MKMaterial *arg0) {
    MKHeap *temp_r5_121;
    SlimeTrailFX *temp_r31_130;

    temp_r5_121 = this->unk0;
    if ((SlimeTrailFX *) M2C_FIELD(temp_r5_121, SlimeTrailFX **, -4) == NULL) {
        return NULL;
    }
    this->unk0 = temp_r5_121 - 4;
    temp_r31_130 = M2C_FIELD(temp_r5_121, SlimeTrailFX **, -4);
    if (temp_r31_130 != NULL) {
        temp_r31_130->Reset();
        temp_r31_130->unk20 = arg0;
        return temp_r31_130;
    }
    return NULL;
}

void SlimeTrailFXManager::Draw() {
    f32 sp8;
    MKHeap *temp_r3_176;
    MKHeap *var_r31_168;
    f32 temp_f2_164;

    MKView_Push();
    MKView_GetProjection(NULL, &sp8, NULL);
    temp_f2_164 = sp8 + 0.05f;
    sp8 = temp_f2_164;
    MKView_SetProjection(0.0f, temp_f2_164, 0.0f);
    var_r31_168 = this->unk0;
loop_2:
    if (var_r31_168 != NULL) {
        temp_r3_176 = var_r31_168->unk0;
        if (temp_r3_176 != NULL) {
            ((SlimeTrailFX *) temp_r3_176)->Draw();
            var_r31_168 += 4;
            goto loop_2;
        }
    }
    MKView_Pop();
}

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to
void SlimeTrailFXManager::Update() {
    s8 spC1;
    u8 spC0;
    s32 spBC;
    f32 spB8;
    s32 spB4;
    s8 spB2;
    s8 spB1;
    s8 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    s32 sp9C;
    s32 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    s32 sp74;
    s32 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    KDUniformSpline sp30;
    f32 sp28;
    f64 sp20;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_400;
    MKHeap *var_r31_212;
    f32 temp_f2_243;
    f32 var_f31_252;
    f64 temp_f1_255;
    f64 temp_f1_261;
    f64 temp_f1_265;
    s32 temp_r3_284;
    s32 var_r0_294;
    void *temp_r3_207;

    if ((void **) gb != NULL) {
        temp_r3_207 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(), 0xC)(), void **, 8);
        sp60 = M2C_FIELD(temp_r3_207, f64 *, 0x30);
        sp68 = M2C_FIELD(temp_r3_207, f64 *, 0x38);
        var_r31_212 = this->unk0;
loop_27:
        if (var_r31_212 != NULL) {
            temp_r3_400 = var_r31_212->unk0;
            if (temp_r3_400 != NULL) {
                if ((s32) temp_r3_400->unk4 > 1) {
                    Tools_GetClosestSplineTime((KDUniformSpline *) temp_r3_400, *((MKVector3 *) &sp60), 5);
                    spC = 0.0f;
                    sp30.GetMeasure(M2C_ERROR(/* Read from unset register $f1 */), (Matrix *) var_r31_212->unk0, KDSpline_PositionMixer);
                    sp50 = M2C_BITWISE(f64, sp30);
                    sp58 = (f64) sp30.unk8;
                    sp20 = sp60 - sp50;
                    sp30.unk10 = sp20;
                    sp28 = (f32) sp68 - (f32) sp58;
                    temp_f2_243 = M2C_BITWISE(f32, sp30.unk10);
                    sp48 = (f64) sp28;
                    var_f31_252 = ((f32) sp48 * (f32) sp48) + ((temp_f2_243 * temp_f2_243) + (sp44 * sp44));
                    if (var_f31_252 > 0.0f) {
                        temp_f1_255 = __frsqrte(var_f31_252);
                        temp_f1_261 = 0.5 * temp_f1_255 * -(((f64) var_f31_252 * (temp_f1_255 * temp_f1_255)) - 3.0);
                        temp_f1_265 = 0.5 * temp_f1_261 * -(((f64) var_f31_252 * (temp_f1_261 * temp_f1_261)) - 3.0);
                        var_f31_252 = (f32) ((f64) var_f31_252 * (0.5 * temp_f1_265 * -(((f64) var_f31_252 * (temp_f1_265 * temp_f1_265)) - 3.0)));
                    } else if (var_f31_252 < M2C_BITWISE(f32, 0.0)) {
                        var_f31_252 = __float_nan;
                    } else {
                        sp8 = var_f31_252;
                        temp_r3_284 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_284) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_294 = 1;
                            } else {
                                var_r0_294 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_294 = 5;
                            } else {
                                var_r0_294 = 3;
                            }
                            break;
                        default:
                            var_r0_294 = 4;
                            break;
                        }
                        if (var_r0_294 == 1) {
                            var_f31_252 = __float_nan;
                        }
                    }
                    if (var_f31_252 <= (f32) (1.15 * M2C_FIELD(*gb, f64 (**)(void **), 0x28)(gb))) {
                        sp74 = 0;
                        sp70 = 7;
                        sp98 = 1;
                        sp9C = 0;
                        sp78 = M2C_BITWISE(f64, sp30.unk10);
                        sp80 = sp48;
                        spB0 = 1;
                        spBC = 2;
                        spB8 = 10.0f;
                        spB1 = 0;
                        spB2 = 1;
                        spB4 = -1;
                        sp88 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                        sp90 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                        spC0 = 0;
                        spA0 = 0.0f;
                        spA4 = 0.0f;
                        spA8 = 0.0f;
                        spC1 = 0;
                        M2C_FIELD(*gb, M2C_UNK (**)(void **, s32 *), 0x1C)(gb, &sp70);
                        if (spC0 != 0) {
                            KDSound_Play3d(GS_SpyroZapBurn, M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
                        }
                    }
                }
                var_r31_212 += 4;
                goto loop_27;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SlimeTrailFXManager::Init() {
    MKHeap *temp_r3_421;
    MKHeap *temp_r3_443;
    MKHeap *temp_r3_449;
    MKHeap *temp_r3_457;
    MKHeap *var_r3_428;
    MKHeap *var_r5_437;
    s32 var_ctr_441;

    temp_r3_421 = MKHeap::Current();
    if (temp_r3_421 != NULL) {
        var_r3_428 = ((MKHeap *) (temp_r3_421->Current()))->Alloc(0x248, NULL, 0);
    } else {
        var_r3_428 = malloc(0x248);
    }
    this->unk0 = var_r3_428;
    var_r5_437 = this->unk0;
    this->unk0 = var_r5_437 + 0x210;
    M2C_FIELD(var_r5_437, s32 *, 0x210) = 0;
    var_ctr_441 = 0xC;
    do {
        temp_r3_443 = this->unk0;
        this->unk0 = (MKHeap *) &temp_r3_443->unk4;
        temp_r3_443->unk4 = (s32) var_r5_437;
        var_r5_437 += 0x2C;
        var_ctr_441 -= 1;
    } while (var_ctr_441 != 0);
    temp_r3_449 = this->unk0;
    this->unk0 = (MKHeap *) &temp_r3_449->unk4;
    temp_r3_449->unk4 = 0;
loop_7:
    if ((u32) M2C_FIELD(this->unk0, u32 *, -4) != 0U) {
        temp_r3_457 = this->unk0 - 4;
        this->unk0 = temp_r3_457;
        ((SlimeTrailFX *) temp_r3_457->unk0)->Init();
        goto loop_7;
    }
loop_10:
    if ((MKHeap *) this->unk0->unk0 != NULL) {
        this->unk0 = (MKHeap *) &this->unk0->unk4;
        goto loop_10;
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SlimeTrailFX::Deinit() {
    MKHeap *temp_r31_491;
    MKHeap *temp_r3_492;

    temp_r31_491 = this->unk14;
    temp_r3_492 = MKHeap::Current();
    if (temp_r3_492 != NULL) {
        ((MKHeap *) (temp_r3_492->Current()))->Free(temp_r31_491, NULL, 0);
    } else {
        free(temp_r31_491);
    }
    KDUniformSpline::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SlimeTrailFX::UpdatePos(MKVector3 *arg0, const MKVector3 &arg1) {
    f64 sp10;
    f64 sp8;
    MKVector3 *temp_r3_589;
    s32 temp_r29_576;
    s32 temp_r3_556;
    s32 var_r28_577;
    s32 var_r30_572;
    void *temp_r3_530;
    void *temp_r3_537;
    void *temp_r3_583;

    temp_r3_530 = this->unk14 + (this->unk18 * 0x28);
    M2C_FIELD(temp_r3_530, f64 *, 0) = (f64) M2C_FIELD(arg0, f64 *, 0);
    M2C_FIELD(temp_r3_530, f64 *, 8) = (f64) M2C_FIELD(arg0, f64 *, 8);
    temp_r3_537 = this->unk14 + ((this->unk18 * 0x28) + 0x10);
    M2C_FIELD(temp_r3_537, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(temp_r3_537, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
    M2C_FIELD((this->unk14 + (this->unk18 * 0x28)), f32 *, 0x20) = 25.0f;
    this->unk24 = arg0;
    this->unk18 += 1;
    if ((s32) this->unk18 >= 0xA) {
        this->unk18 = 0;
    }
    temp_r3_556 = this->unk1C;
    if ((s32) this->unk18 == temp_r3_556) {
        this->unk1C = temp_r3_556 + 1;
        if ((s32) this->unk1C >= 0xA) {
            this->unk1C = 0;
        }
    }
    this->unk8 = 0.0f;
    this->unk4 = 0;
    var_r30_572 = this->unk18 - 1;
    if (var_r30_572 < 0) {
        var_r30_572 = 0xA;
    }
    temp_r29_576 = var_r30_572;
    var_r28_577 = 0;
loop_12:
    if (var_r30_572 != (s32) this->unk1C) {
        temp_r3_583 = this->unk14 + (var_r30_572 * 0x28);
        sp8 = M2C_FIELD(temp_r3_583, f64 *, 0);
        sp10 = M2C_FIELD(temp_r3_583, f64 *, 8);
        if (var_r30_572 == temp_r29_576) {
            temp_r3_589 = this->unk24;
            sp8 = M2C_FIELD(temp_r3_589, f64 *, 0);
            sp10 = M2C_FIELD(temp_r3_589, f64 *, 8);
        }
        KDUniformSpline::AddNode(*((MKVector3 *) &sp8));
        var_r30_572 -= 1;
        var_r28_577 += 1;
        if (var_r30_572 < 0) {
            var_r30_572 = 9;
        }
        goto loop_12;
    }
    if (var_r28_577 > 1) {
        this->unk28 = 1;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to
void SlimeTrailFX::Draw() {
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    KDUniformSpline sp1B0;
    KDUniformSpline sp190;
    f64 sp188;
    f64 sp180;
    MKVector3 sp170;
    f64 sp168;
    f64 sp160;
    MKVector3 sp150;
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
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
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
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f24_685;
    f32 temp_f25_708;
    f32 temp_f26_709;
    f32 temp_f2_732;
    f64 temp_f0_793;
    f64 temp_f0_804;
    f64 temp_f0_861;
    f64 temp_f0_872;
    s32 temp_r26_657;
    s32 var_r25_670;

    if ((u8) this->unk28 != 0) {
        MKMaterial_SetMaterial(this->unk20);
        MKPrimitive(0xC, 0x10);
        MKSetMatrix(Matrix::identity);
        temp_r26_657 = this->unk4;
        if ((this->unk18 - 1) >= 0) {

        }
        MKBegin(0x28);
        var_r25_670 = 0;
        do {
            sp8 = 0.0f;
            temp_f24_685 = (f32) var_r25_670 / 19.0f;
            sp1B0.GetMeasure(temp_f24_685, (Matrix *) this, KDSpline_PositionMixer);
            sp1E0 = M2C_BITWISE(f64, sp1B0);
            sp1E8 = (f64) sp1B0.unk8;
            sp190.GetVelocity(temp_f24_685);
            Normalise(*((MKVector3 *) &sp190.unk10));
            sp1D0 = M2C_BITWISE(f64, sp190.unk10);
            sp1D8 = sp1A8;
            temp_f25_708 = 1.0f - temp_f24_685;
            temp_f26_709 = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
            Normalise(sp150);
            temp_f2_732 = M2C_BITWISE(f32, sp150);
            sp18 = (temp_f2_732 * unksp1D4) - (sp150.unk4 * (f32) sp1D0);
            sp14 = (sp150.unk8 * (f32) sp1D0) - (temp_f2_732 * (f32) sp1D8);
            sp10 = (sp150.unk4 * (f32) sp1D8) - (sp150.unk8 * unksp1D4);
            sp168 = (f64) sp18;
            sp160 = (f64) sp10;
            Normalise(sp170);
            sp20 = sp170 * (f64) temp_f26_709;
            sp180 = sp20;
            sp28 = sp170.unk8 * temp_f26_709;
            sp1B0.unk10 = sp20;
            sp188 = (f64) sp28;
            sp1C8 = (f64) sp28;
            if (var_r25_670 == 0) {
                spB0 = 0.0f;
                spB4 = 0.0f;
                spB8 = 0.0f;
                spBC = 1.0f;
                sp140 = (f64) spB0;
                sp148 = (f64) spB8;
                MKSetColorV(*((MKVector4 *) &sp140));
            } else {
                spA0 = temp_f25_708;
                spA4 = temp_f25_708;
                spA8 = temp_f25_708;
                spAC = 1.0f;
                sp130 = (f64) spA0;
                sp138 = (f64) spA8;
                MKSetColorV(*((MKVector4 *) &sp130));
            }
            MKSetTexCoord1F(0.0f, temp_f24_685);
            temp_f0_793 = M2C_BITWISE(f64, sp1B0.unk10) * 5.53552857e-315;
            sp90 = temp_f0_793;
            sp110 = temp_f0_793;
            sp98 = (f32) sp1C8 * 100.0f;
            sp118 = (f64) sp98;
            temp_f0_804 = sp1E0 + temp_f0_793;
            sp80 = temp_f0_804;
            sp120 = temp_f0_804;
            sp88 = (f32) sp1E8 + (f32) sp118;
            sp128 = (f64) sp88;
            MKSetPositionV(*((MKVector3 *) &sp120));
            if (var_r25_670 == 0) {
                sp70 = 0.0f;
                sp74 = 0.0f;
                sp78 = 0.0f;
                sp7C = 1.0f;
                sp100 = (f64) sp70;
                sp108 = (f64) sp78;
                MKSetColorV(*((MKVector4 *) &sp100));
            } else {
                sp60 = temp_f25_708;
                sp64 = temp_f25_708;
                sp68 = temp_f25_708;
                sp6C = 1.0f;
                spF0 = (f64) sp60;
                spF8 = (f64) sp68;
                MKSetColorV(*((MKVector4 *) &spF0));
            }
            MKSetTexCoord1F(1.0f, temp_f24_685);
            sp50 = -M2C_BITWISE(f32, sp1B0.unk10);
            sp54 = -sp1C4;
            sp58 = -(f32) sp1C8;
            spC0 = (f64) sp50;
            spC8 = (f64) sp58;
            temp_f0_861 = spC0 * 5.53552857e-315;
            sp40 = temp_f0_861;
            spD0 = temp_f0_861;
            sp48 = (f32) spC8 * 100.0f;
            spD8 = (f64) sp48;
            temp_f0_872 = sp1E0 + temp_f0_861;
            sp30 = temp_f0_872;
            spE0 = temp_f0_872;
            sp38 = (f32) sp1E8 + (f32) spD8;
            spE8 = (f64) sp38;
            MKSetPositionV(*((MKVector3 *) &spE0));
            var_r25_670 += 1;
        } while (var_r25_670 < 0x14);
        MKEnd();
        MKEndPrimitive();
    }
}
#endif

void SlimeTrailFX::Reset() {
    this->unk18 = 0;
    this->unk1C = 0;
    this->unk24 = NULL;
    this->unk28 = 0;
    this->unk8 = 0.0f;
    this->unk4 = 0;
}

#if 0 // DRAFT: illegal use of non-static member
void SlimeTrailFX::Init() {
    MKHeap *temp_r3_937;
    MKHeap *var_r3_944;

    temp_r3_937 = MKHeap::Current();
    if (temp_r3_937 != NULL) {
        var_r3_944 = ((MKHeap *) (temp_r3_937->Current()))->Alloc(0x190, NULL, 0);
    } else {
        var_r3_944 = malloc(0x190);
    }
    this->unk14 = var_r3_944;
    KDUniformSpline::Init(0xA, 0U);
    this->unk18 = 0;
    this->unk1C = 0;
}
#endif
