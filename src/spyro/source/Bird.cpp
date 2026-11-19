#include "spyro/source/Bird.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Critters.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Level.h"
#include "spyro/source/Volume.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK acos(f32, f32, f32, f32);                   /* extern */
M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern s32 GS_PLACEHOLDER;
extern f32 *KDSpline_PositionMixer;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

void BirdCritter::Deinit() {
    s32 var_r30_68;
    s32 var_r31_69;
    void *temp_r31_54;
    void *temp_r31_82;

    temp_r31_54 = this->unk174;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_54, NULL, 0);
    } else {
        free(temp_r31_54);
    }
    var_r30_68 = 0;
    var_r31_69 = 0;
loop_5:
    if (var_r30_68 < (s32) this->unk90) {
        ((KDUniformSpline *) (((u8 *) this->unk170) + (var_r31_69 + 0x68)))->Deinit();
        var_r30_68 += 1;
        var_r31_69 += 0x90;
        goto loop_5;
    }
    temp_r31_82 = this->unk170;
    if (temp_r31_82 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_82, NULL, 0);
        } else {
            free(temp_r31_82);
        }
    }
    this->unk170 = NULL;
    Critters::Deinit();
}

void BirdCritter::Draw() {
    Matrix sp10;
    M2C_UNK spC;
    s32 var_r30_120;
    s32 var_r31_121;
    void *temp_r29_128;

    var_r30_120 = 0;
    var_r31_121 = 0;
loop_2:
    if (var_r30_120 < (s32) this->unk90) {
        temp_r29_128 = ((u8 *) this->unk170) + var_r31_121;
        this->unk80->SetAnim(M2C_FIELD(temp_r29_128, MKAnim **, 0x50), 0.0f, 0.0f, 0, -1);
        this->unk80->JumpToPos(M2C_FIELD(temp_r29_128, f32 *, 0x54), -1);
        M2C_STRUCT_COPY((s32) &spC + 4, (s32) (((u8 *) temp_r29_128) - 4) + 4, 0x40);
        MKModel_SetWorldMatrix(this->unk4, sp10);
        MKModel_Draw(this->unk4, NULL);
        var_r30_120 += 1;
        var_r31_121 += 0x90;
        goto loop_2;
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'Volume' to 'double'
void BirdCritter::FindNewFlyParameters(Bird *arg0, bool arg1) {
    f64 sp200;
    Volume sp178;
    f64 sp170;
    f64 sp168;
    MKVector3 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    MKVector3 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    MKVector3 spF8;
    MKVector3 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    MKVector3 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
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
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f3_467;
    f32 var_f28_293;
    f32 var_f29_336;
    f32 var_f4_531;
    f32 var_f4_598;
    f32 var_f5_229;
    f64 temp_f1_206;
    f64 temp_f1_296;
    f64 temp_f1_417;
    f64 temp_f1_537;
    f64 temp_f1_543;
    f64 temp_f1_547;
    f64 temp_f2_232;
    f64 temp_f2_238;
    f64 temp_f2_242;
    f64 temp_f2_339;
    f64 temp_f2_345;
    f64 temp_f2_349;
    s32 temp_r3_261;
    s32 temp_r3_368;
    s32 temp_r3_566;
    s32 temp_r5_196;
    s32 var_r0_271;
    s32 var_r0_378;
    s32 var_r0_576;
    s32 var_r26_647;
    s32 var_r27_488;
    s32 var_r29_486;
    s32 var_r29_648;
    void *temp_r3_205;
    void *temp_r3_632;

    sp178.GetRandPos();
    sp178.unk30 = M2C_BITWISE(f64, sp178);
    sp178.unk38 = sp178.unk8;
    if ((arg1 != 0) && (temp_r5_196 = this->unk178, ((temp_r5_196 == 0) == 0))) {
        temp_r3_205 = ((u8 *) this->unk174) + (MKRand_Int((int *) &gViewSeed, 0, temp_r5_196) * 0x10);
        temp_f1_206 = M2C_FIELD(temp_r3_205, f64 *, 0);
        sp18 = temp_f1_206;
        sp20 = M2C_FIELD(temp_r3_205, f64 *, 8);
        sp98 = temp_f1_206 - M2C_FIELD(arg0, f64 *, 0x30);
        sp168 = sp98;
        spA0 = (f32) sp20 - arg0->unk38;
        sp170 = (f64) spA0;
        var_f5_229 = ((f32) sp170 * (f32) sp170) + (((f32) sp168 * (f32) sp168) + ((*(f32 *) ((u8 *) &sp168 + 0x4)) * (*(f32 *) ((u8 *) &sp168 + 0x4))));
        if (var_f5_229 > 0.0f) {
            temp_f2_232 = __frsqrte(var_f5_229);
            temp_f2_238 = 0.5 * temp_f2_232 * -(((f64) var_f5_229 * (temp_f2_232 * temp_f2_232)) - 3.0);
            temp_f2_242 = 0.5 * temp_f2_238 * -(((f64) var_f5_229 * (temp_f2_238 * temp_f2_238)) - 3.0);
            var_f5_229 = (f32) ((f64) var_f5_229 * (0.5 * temp_f2_242 * -(((f64) var_f5_229 * (temp_f2_242 * temp_f2_242)) - 3.0)));
        } else if (var_f5_229 < M2C_BITWISE(f32, 0.0)) {
            var_f5_229 = __float_nan;
        } else {
            sp10 = var_f5_229;
            temp_r3_261 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_261) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_271 = 1;
                } else {
                    var_r0_271 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_271 = 5;
                } else {
                    var_r0_271 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_271 = 4;
                break;
            }
            if (var_r0_271 == 1) {
                var_f5_229 = __float_nan;
            }
        }
        var_f28_293 = var_f5_229;
        temp_f1_296 = sp18 - M2C_FIELD(arg0, f64 *, 0x30);
        sp68 = temp_f1_296;
        sp148 = temp_f1_296;
        sp70 = (f32) sp20 - arg0->unk38;
        sp150 = (f64) sp70;
        Normalise(sp158);
        sp178.unk20 = M2C_BITWISE(f64, sp158);
        sp178.unk28 = (f64) sp158.unk8;
        arg0->unk88 = 1;
    } else {
        sp88 = sp178.unk30 - M2C_FIELD(arg0, f64 *, 0x30);
        sp138 = sp88;
        sp90 = (f32) sp178.unk38 - arg0->unk38;
        sp140 = (f64) sp90;
        var_f29_336 = ((f32) sp140 * (f32) sp140) + (((f32) sp138 * (f32) sp138) + ((*(f32 *) ((u8 *) &sp138 + 0x4)) * (*(f32 *) ((u8 *) &sp138 + 0x4))));
        if (var_f29_336 > 0.0f) {
            temp_f2_339 = __frsqrte(var_f29_336);
            temp_f2_345 = 0.5 * temp_f2_339 * -(((f64) var_f29_336 * (temp_f2_339 * temp_f2_339)) - 3.0);
            temp_f2_349 = 0.5 * temp_f2_345 * -(((f64) var_f29_336 * (temp_f2_345 * temp_f2_345)) - 3.0);
            var_f29_336 = (f32) ((f64) var_f29_336 * (0.5 * temp_f2_349 * -(((f64) var_f29_336 * (temp_f2_349 * temp_f2_349)) - 3.0)));
        } else if (var_f29_336 < M2C_BITWISE(f32, 0.0)) {
            var_f29_336 = __float_nan;
        } else {
            spC = var_f29_336;
            temp_r3_368 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_368) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_378 = 1;
                } else {
                    var_r0_378 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_378 = 5;
                } else {
                    var_r0_378 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_378 = 4;
                break;
            }
            if (var_r0_378 == 1) {
                var_f29_336 = __float_nan;
            }
        }
        if (var_f29_336 < 3.4028235e38f) {

        } else {
            var_f29_336 = 3.4028235e38f;
        }
        if (var_f29_336 > 1000.0f) {

        } else {
            var_f29_336 = 1000.0f;
        }
        var_f28_293 = var_f29_336;
        temp_f1_417 = sp178.unk30 - M2C_FIELD(arg0, f64 *, 0x30);
        sp58 = temp_f1_417;
        sp118 = temp_f1_417;
        sp60 = (f32) sp178.unk38 - arg0->unk38;
        sp120 = (f64) sp60;
        Normalise(sp128);
        sp178.unk20 = M2C_BITWISE(f64, sp128);
        sp178.unk28 = (f64) sp128.unk8;
        spF8.operator*(var_f29_336);
        sp48 = M2C_FIELD(arg0, f64 *, 0x30) + M2C_BITWISE(f64, spF8);
        arg0->unk88 = 0;
        sp108 = sp48;
        sp50 = arg0->unk38 + spF8.unk8;
        sp18 = sp48;
        sp110 = (f64) sp50;
        sp20 = (f64) sp50;
    }
    sp178.unk40 = M2C_FIELD(arg0, f64 *, 0x30);
    sp178.unk40.unk8 = (f64) M2C_FIELD(arg0, f32 *, 0x38);
    sp178.unk80 = sp18;
    sp200 = sp20;
    temp_f3_467 = arg0->unk20;
    acos((arg0->unk28 * (f32) sp178.unk28) + ((temp_f3_467 * (f32) sp178.unk20) + (arg0->unk24 * (*(f32 *) ((u8 *) &sp178 + 0x24)))), (f32) sp178.unk20, temp_f3_467, (f32) sp178.unk28);
    sp78 = -arg0->unk20;
    sp7C = -arg0->unk24;
    var_r29_486 = 0;
    var_r27_488 = 0;
    sp80 = -arg0->unk28;
    sp178.unk10 = (f64) sp78;
    sp178.unk18 = (f64) sp80;
    do {
        sp38 = -arg0->unk20;
        sp3C = -arg0->unk24;
        sp40 = -arg0->unk28;
        spD8 = (f64) sp38;
        spE0 = (f64) sp40;
        KDMath_Smooth<MKVector3>(spE8, *((MKVector3 *) &spD8), (f32) var_r29_486 / 3.0f, 1.0f);
        sp178.unk10 = M2C_BITWISE(f64, spE8);
        sp178.unk18 = (f64) spE8.unk8;
        var_f4_531 = ((f32) sp178.unk18 * (f32) sp178.unk18) + (((f32) sp178.unk10 * (f32) sp178.unk10) + ((*(f32 *) ((u8 *) &sp178 + 0x14)) * (*(f32 *) ((u8 *) &sp178 + 0x14))));
        if (var_f4_531 > 0.000001f) {
            if (var_f4_531 > 0.0f) {
                temp_f1_537 = __frsqrte(var_f4_531);
                temp_f1_543 = 0.5 * temp_f1_537 * -(((f64) var_f4_531 * (temp_f1_537 * temp_f1_537)) - 3.0);
                temp_f1_547 = 0.5 * temp_f1_543 * -(((f64) var_f4_531 * (temp_f1_543 * temp_f1_543)) - 3.0);
                var_f4_531 = (f32) ((f64) var_f4_531 * (0.5 * temp_f1_547 * -(((f64) var_f4_531 * (temp_f1_547 * temp_f1_547)) - 3.0)));
            } else if (var_f4_531 < M2C_BITWISE(f32, 0.0)) {
                var_f4_531 = __float_nan;
            } else {
                sp8 = var_f4_531;
                temp_r3_566 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_566) {              /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_576 = 1;
                    } else {
                        var_r0_576 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_576 = 5;
                    } else {
                        var_r0_576 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_576 = 4;
                    break;
                }
                if (var_r0_576 == 1) {
                    var_f4_531 = __float_nan;
                }
            }
            var_f4_598 = 1.0f / var_f4_531;
        } else {
            var_f4_598 = 0.0f;
        }
        sp178.unk10 = (f32) sp178.unk10 * var_f4_598;
        (*(f32 *) ((u8 *) &sp178 + 0x14)) *= var_f4_598;
        sp178.unk18 = (f32) sp178.unk18 * var_f4_598;
        spA8.operator*(var_f28_293);
        spB8.operator*((f32) (var_r29_486 + 1) * 0.25f);
        sp28 = M2C_FIELD(arg0, f64 *, 0x30) + M2C_BITWISE(f64, spB8);
        temp_r3_632 = &sp178.unk40 + (var_r27_488 + 0x10);
        var_r29_486 += 1;
        var_r27_488 += 0x10;
        M2C_FIELD(temp_r3_632, f64 *, 0) = sp28;
        sp30 = arg0->unk38 + spB8.unk8;
        spC8 = sp28;
        spD0 = (f64) sp30;
        M2C_FIELD(temp_r3_632, f64 *, 8) = (f64) sp30;
    } while (var_r29_486 < 3);
    var_r26_647 = 0;
    var_r29_648 = 0;
    arg0->unk68.unk8 = 0.0f;
    arg0->unk68.unk4 = 0;
    do {
        arg0->unk68.AddNode(sp178.unk40 + var_r29_648);
        var_r26_647 += 1;
        var_r29_648 += 0x10;
    } while (var_r26_647 < 5);
    arg0->unk7C = 0.0f;
    arg0->unk84 = 600.0f / arg0->unk68.unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void BirdCritter::SetFlyingExitState(Bird *arg0) {
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;                                       /* compiler-managed */
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 var_f4_818;
    f32 var_f6_780;
    f64 temp_f1_823;
    f64 temp_f1_829;
    f64 temp_f1_833;
    s32 temp_r30_774;
    s32 temp_r3_852;
    s32 var_r0_862;

    arg0->unk60 = 5;
    temp_r30_774 = arg0->unk60;
    var_f6_780 = 0.0f;
    arg0->unk50 = M2C_FIELD((checked_cast<BirdCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r30_774 * 4)), void **, 0x70);
    arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
    arg0->unk54 = 0.0f;
    sp10 = -arg0->unk20;
    sp14 = -arg0->unk24;
    sp18 = -arg0->unk28;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    (*(f32 *) ((u8 *) &sp38 + 0xc)) = 0.0f;
    var_f4_818 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (0.0f * 0.0f));
    if (var_f4_818 > 0.000001f) {
        if (var_f4_818 > 0.0f) {
            temp_f1_823 = __frsqrte(var_f4_818);
            temp_f1_829 = 0.5 * temp_f1_823 * -(((f64) var_f4_818 * (temp_f1_823 * temp_f1_823)) - 3.0);
            temp_f1_833 = 0.5 * temp_f1_829 * -(((f64) var_f4_818 * (temp_f1_829 * temp_f1_829)) - 3.0);
            var_f4_818 = (f32) ((f64) var_f4_818 * (0.5 * temp_f1_833 * -(((f64) var_f4_818 * (temp_f1_833 * temp_f1_833)) - 3.0)));
        } else if (var_f4_818 < M2C_BITWISE(f32, 0.0)) {
            var_f4_818 = __float_nan;
        } else {
            sp8 = var_f4_818;
            temp_r3_852 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_852) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_862 = 1;
                } else {
                    var_r0_862 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_862 = 5;
                } else {
                    var_r0_862 = 3;
                }
                break;
            default:
                var_r0_862 = 4;
                break;
            }
            if (var_r0_862 == 1) {
                var_f4_818 = __float_nan;
            }
        }
        var_f6_780 = 1.0f / var_f4_818;
    }
    sp40 = (f32) sp40 * var_f6_780;
    (*(f32 *) ((u8 *) &sp38 + 0xc)) *= var_f6_780;
    sp48 = (f32) sp48 * var_f6_780;
    sp30 = M2C_FIELD(arg0, f64 *, 0x30);
    sp38 = M2C_FIELD(arg0, f64 *, 0x38);
    sp20 = M2C_FIELD(&MKVector3::up, f64 *, 0);
    sp28 = M2C_FIELD(&MKVector3::up, f64 *, 8);
    KDMath_BuildMatrixFromFwd((Matrix *) arg0, *((MKVector3 *) &sp40), (MKVector3 *) &sp20);
    M2C_FIELD(arg0, f64 *, 0x30) = (f32) sp30;
    arg0->unk34 = (*(f32 *) ((u8 *) &sp30 + 0x4));
    arg0->unk38 = (f32) sp38;
    arg0->unk3C = 1.0f;
}
#endif

void BirdCritter::SetFlyingLoopState(Bird *arg0) {
    s32 temp_r31_934;

    arg0->unk60 = 4;
    temp_r31_934 = arg0->unk60;
    arg0->unk50 = M2C_FIELD((checked_cast<BirdCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r31_934 * 4)), void **, 0x70);
    arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
    arg0->unk54 = 0.0f;
    FindNewFlyParameters(arg0, 0U);
}

void BirdCritter::SetFlyingEnterState(Bird *arg0) {
    s32 temp_r31_978;

    arg0->unk60 = 3;
    temp_r31_978 = arg0->unk60;
    arg0->unk50 = M2C_FIELD((checked_cast<BirdCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r31_978 * 4)), void **, 0x70);
    arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
    arg0->unk54 = 0.0f;
}

void BirdCritter::SetIdleState(Bird *arg0) {
    s32 temp_r31_1022;

    arg0->unk60 = MKRand_Int((int *) &gViewSeed, 0, 3);
    temp_r31_1022 = arg0->unk60;
    arg0->unk50 = M2C_FIELD((checked_cast<BirdCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r31_1022 * 4)), void **, 0x70);
    arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
    arg0->unk54 = 0.0f;
}

#if 0 // DRAFT: ')' expected
void *BirdCritter::Update() {
    f64 sp108;                                      /* compiler-managed */
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;
    f64 spF0;
    f64 spE8;
    KDUniformSpline spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
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
    f32 spC;
    f32 sp8;
    Bird *temp_r30_1068;
    f32 temp_f10_1314;
    f32 temp_f10_1361;
    f32 temp_f11_1312;
    f32 temp_f11_1360;
    f32 temp_f12_1358;
    f32 temp_f1_1082;
    f32 temp_f1_1140;
    f32 temp_f1_1158;
    f32 temp_f1_1177;
    f32 temp_f1_1180;
    f32 temp_f31_1098;
    f32 temp_f3_1178;
    f32 temp_f3_1324;
    f32 temp_f9_1316;
    f32 var_f0_1188;
    f32 var_f2_1170;
    f32 var_f2_1303;
    f32 var_f31_1206;
    f32 var_f4_1236;
    f64 temp_f1_1242;
    f64 temp_f1_1248;
    f64 temp_f1_1252;
    s32 temp_r0_1112;
    s32 temp_r3_1271;
    s32 var_r0_1281;
    s32 var_r28_1063;
    s32 var_r31_1062;

    var_r31_1062 = 0;
    var_r28_1063 = 0;
loop_63:
    if (var_r31_1062 < (s32) this->unk90) {
        temp_r30_1068 = (Bird *) (((u8 *) this->unk170) + var_r28_1063);
        temp_r30_1068->unk64 -= gUpdateTimeDelta;
        temp_r30_1068->unk54 += temp_r30_1068->unk58 * gUpdateTimeDelta;
        if ((s32) M2C_FIELD(checked_cast<BirdCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x90) != 0) {
            temp_f1_1082 = temp_r30_1068->unk8C;
            if (temp_f1_1082 <= 0.0f) {
                KDSound_Play3d(M2C_FIELD(checked_cast<BirdCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x90), temp_r30_1068 + 0x30, 0U, -1, 0.0f, 0U);
                temp_f31_1098 = M2C_FIELD(checked_cast<BirdCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x8C);
                temp_r30_1068->unk8C = MKRand_Float((int *) &gViewSeed, M2C_FIELD(checked_cast<BirdCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x88), temp_f31_1098);
            } else {
                temp_r30_1068->unk8C = temp_f1_1082 - gUpdateTimeDelta;
            }
        }
        temp_r0_1112 = temp_r30_1068->unk60;
        switch (temp_r0_1112) {                     /* switch 1; irregular */
        default:                                    /* switch 1 */
            if ((temp_r30_1068->unk64 <= 0.0f) && (temp_r30_1068->unk54 >= 1.0f)) {
                SetFlyingEnterState(temp_r30_1068);
            }
            temp_f1_1140 = temp_r30_1068->unk54;
            if (temp_f1_1140 > 1.0f) {
                temp_r30_1068->unk54 = temp_f1_1140 - 1.0f;
            }
            break;
        case 3:                                     /* switch 1 */
            if (temp_r30_1068->unk54 >= 1.0f) {
                SetFlyingLoopState(temp_r30_1068);
            }
            break;
        case 4:                                     /* switch 1 */
            temp_f1_1158 = temp_r30_1068->unk54;
            if (temp_f1_1158 > 1.0f) {
                temp_r30_1068->unk54 = temp_f1_1158 - 1.0f;
            }
            var_f2_1170 = 0.5f * (1.0f * gUpdateTimeDelta);
            if (var_f2_1170 < 1.0f) {

            } else {
                var_f2_1170 = 1.0f;
            }
            temp_f1_1177 = temp_r30_1068->unk80;
            temp_f3_1178 = temp_r30_1068->unk84;
            temp_f1_1180 = (var_f2_1170 * (temp_f3_1178 - temp_f1_1177)) + temp_f1_1177;
            temp_r30_1068->unk80 = (var_f2_1170 * (temp_f3_1178 - temp_f1_1180)) + temp_f1_1180;
            var_f0_1188 = (temp_r30_1068->unk80 * gUpdateTimeDelta) + temp_r30_1068->unk7C;
            if (var_f0_1188 < 1.0f) {

            } else {
                var_f0_1188 = 1.0f;
            }
            if (var_f0_1188 > 0.0f) {

            } else {
                var_f0_1188 = 0.0f;
            }
            temp_r30_1068->unk7C = var_f0_1188;
            var_f31_1206 = temp_r30_1068->unk7C - 0.001f;
            if (var_f31_1206 < 1.0f) {

            } else {
                var_f31_1206 = 1.0f;
            }
            if (var_f31_1206 > 0.0f) {

            } else {
                var_f31_1206 = 0.0f;
            }
            spD0.GetVelocity(var_f31_1206);
            sp100 = M2C_BITWISE(f64, spD0);
            sp108 = (f64) spD0.unk8;
            var_f4_1236 = ((f32) sp108 * (f32) sp108) + (((f32) sp100 * (f32) sp100) + ((*(f32 *) ((u8 *) &spF8 + 0xc)) * (*(f32 *) ((u8 *) &spF8 + 0xc))));
            if (var_f4_1236 > 0.000001f) {
                if (var_f4_1236 > 0.0f) {
                    temp_f1_1242 = __frsqrte(var_f4_1236);
                    temp_f1_1248 = 0.5 * temp_f1_1242 * -(((f64) var_f4_1236 * (temp_f1_1242 * temp_f1_1242)) - 3.0);
                    temp_f1_1252 = 0.5 * temp_f1_1248 * -(((f64) var_f4_1236 * (temp_f1_1248 * temp_f1_1248)) - 3.0);
                    var_f4_1236 = (f32) ((f64) var_f4_1236 * (0.5 * temp_f1_1252 * -(((f64) var_f4_1236 * (temp_f1_1252 * temp_f1_1252)) - 3.0)));
                } else if (var_f4_1236 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1236 = __float_nan;
                } else {
                    sp8 = var_f4_1236;
                    temp_r3_1271 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_1271) {         /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1281 = 1;
                        } else {
                            var_r0_1281 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1281 = 5;
                        } else {
                            var_r0_1281 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_1281 = 4;
                        break;
                    }
                    if (var_r0_1281 == 1) {
                        var_f4_1236 = __float_nan;
                    }
                }
                var_f2_1303 = 1.0f / var_f4_1236;
            } else {
                var_f2_1303 = 0.0f;
            }
            temp_f11_1312 = (f32) sp100 * var_f2_1303;
            temp_f10_1314 = (*(f32 *) ((u8 *) &spF8 + 0xc)) * var_f2_1303;
            temp_f9_1316 = (f32) sp108 * var_f2_1303;
            spD0.unk10 = M2C_FIELD(&MKVector3::up, f64 *, 0);
            spE8 = M2C_FIELD(&MKVector3::up, f64 *, 8);
            temp_f3_1324 = M2C_BITWISE(f32, spD0.unk10);
            sp50 = -temp_f11_1312;
            sp54 = -temp_f10_1314;
            sp58 = -temp_f9_1316;
            spA0 = (f64) sp50;
            spA8 = (f64) sp58;
            sp100 = temp_f11_1312;
            (*(f32 *) ((u8 *) &spF8 + 0xc)) = temp_f10_1314;
            sp108 = temp_f9_1316;
            sp48 = ((f32) spA0 * spE4) - ((*(f32 *) ((u8 *) &spA0 + 0x4)) * temp_f3_1324);
            sp40 = ((*(f32 *) ((u8 *) &spA0 + 0x4)) * (f32) spE8) - ((f32) spA8 * spE4);
            sp44 = ((f32) spA8 * temp_f3_1324) - ((f32) spA0 * (f32) spE8);
            spB8 = (f64) sp48;
            spB0 = (f64) sp40;
            Normalise(spC0);
            temp_f12_1358 = -sp100;
            temp_f11_1360 = -(*(f32 *) ((u8 *) &spF8 + 0xc));
            temp_f10_1361 = -sp108;
            sp10 = temp_f12_1358;
            sp14 = temp_f11_1360;
            spF0 = M2C_BITWISE(f64, spC0);
            sp18 = temp_f10_1361;
            sp80 = (f64) sp10;
            spF8 = (f64) spC0.unk8;
            sp88 = (f64) sp18;
            temp_r30_1068->unk0 = (f32) spF0;
            temp_r30_1068->unk4 = (*(f32 *) ((u8 *) &spF0 + 0x4));
            temp_r30_1068->unk8 = (f32) spF8;
            sp30 = ((*(f32 *) ((u8 *) &spF0 + 0x4)) * (f32) sp88) - ((f32) spF8 * (*(f32 *) ((u8 *) &sp80 + 0x4)));
            sp34 = ((f32) spF8 * (f32) sp80) - ((f32) spF0 * (f32) sp88);
            sp38 = ((f32) spF0 * (*(f32 *) ((u8 *) &sp80 + 0x4))) - ((*(f32 *) ((u8 *) &spF0 + 0x4)) * (f32) sp80);
            spD0.unk10 = (f64) sp30;
            sp28 = temp_f10_1361;
            temp_r30_1068->unkC = 0.0f;
            spE8 = (f64) sp38;
            temp_r30_1068->unk10 = (f32) spD0.unk10;
            temp_r30_1068->unk14 = spE4;
            temp_r30_1068->unk18 = (f32) spE8;
            sp78 = (f64) sp28;
            sp20 = temp_f12_1358;
            sp24 = temp_f11_1360;
            temp_r30_1068->unk1C = 0.0f;
            sp70 = (f64) sp20;
            temp_r30_1068->unk20 = (f32) sp70;
            temp_r30_1068->unk24 = (*(f32 *) ((u8 *) &sp70 + 0x4));
            temp_r30_1068->unk28 = (f32) sp78;
            temp_r30_1068->unk2C = 0.0f;
            sp90 = (f64) sp30;
            sp98 = (f64) sp38;
            spC = 0.0f;
            ((KDUniformSpline *) &sp60)->GetMeasure(var_f31_1206, (Matrix *) &temp_r30_1068->unk68, KDSpline_PositionMixer);
            M2C_FIELD(temp_r30_1068, f32 *, 0x30) = sp60;
            temp_r30_1068->unk34 = sp64;
            temp_r30_1068->unk38 = sp68;
            temp_r30_1068->unk3C = 1.0f;
            if (temp_r30_1068->unk7C >= 1.0f) {
                if ((u8) temp_r30_1068->unk88 != 0) {
                    SetFlyingExitState(temp_r30_1068);
                } else {
                    FindNewFlyParameters(temp_r30_1068, MKRand_Int((int *) &gViewSeed, 0, 4) == 0);
                }
            }
            break;
        case 5:                                     /* switch 1 */
            if (temp_r30_1068->unk54 >= 1.0f) {
                SetIdleState(temp_r30_1068);
            }
            break;
        }
        var_r31_1062 += 1;
        var_r28_1063 += 0x90;
        goto loop_63;
    }
}
#endif

#if 0 // DRAFT: ')' expected
f32 BirdCritter::Resolve() {
    f64 sp20;
    f64 sp18;
    f64 sp8;
    Bird *temp_r30_1502;
    f32 temp_f30_1514;
    s32 temp_r5_1526;
    s32 var_r28_1496;
    s32 var_r31_1495;
    void *temp_r4_1540;

    MKProp::Resolve();
    var_r31_1495 = 0;
    var_r28_1496 = 0;
loop_7:
    if (var_r31_1495 < (s32) this->unk90) {
        temp_r30_1502 = (Bird *) (((u8 *) this->unk170) + var_r28_1496);
        temp_r30_1502->unk7C = 0.0f;
        temp_r30_1502->unk80 = 0.0f;
        ((KDUniformSpline *) (temp_r30_1502 + 0x68))->Init(5, 0U);
        if ((s32) M2C_FIELD(checked_cast<BirdCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x90) != 0) {
            temp_f30_1514 = M2C_FIELD(checked_cast<BirdCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x8C);
            temp_r30_1502->unk8C = MKRand_Float((int *) &gViewSeed, M2C_FIELD(checked_cast<BirdCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x88), temp_f30_1514);
        }
        ((Volume *) &sp8)->GetRandPos();
        temp_r5_1526 = this->unk178;
        sp18 = sp8;
        sp20 = sp10;
        if (temp_r5_1526 != 0) {
            temp_r4_1540 = ((u8 *) this->unk174) + (MKRand_Int((int *) &gViewSeed, 0, temp_r5_1526) * 0x10);
            sp18 = M2C_FIELD(temp_r4_1540, f64 *, 0);
            sp20 = M2C_FIELD(temp_r4_1540, f64 *, 8);
            M2C_STRUCT_COPY(temp_r30_1502, &Matrix::identity, 0x40);
            M2C_FIELD(temp_r30_1502, f32 *, 0x30) = (f32) sp18;
            temp_r30_1502->unk34 = (*(f32 *) ((u8 *) &sp18 + 0x4));
            temp_r30_1502->unk38 = (f32) sp20;
            temp_r30_1502->unk3C = 1.0f;
            SetIdleState(temp_r30_1502);
        } else {
            M2C_STRUCT_COPY(temp_r30_1502, &Matrix::identity, 0x40);
            M2C_FIELD(temp_r30_1502, f32 *, 0x30) = (f32) sp18;
            temp_r30_1502->unk34 = (*(f32 *) ((u8 *) &sp18 + 0x4));
            temp_r30_1502->unk38 = (f32) sp20;
            temp_r30_1502->unk3C = 1.0f;
            SetFlyingLoopState(temp_r30_1502);
            FindNewFlyParameters(temp_r30_1502, 0U);
        }
        var_r31_1495 += 1;
        var_r28_1496 += 0x90;
        goto loop_7;
    }
}
#endif

s32 BirdCritter::LoadDone() {
    s32 temp_r31_1623;
    void *var_r3_1631;

    Critters::LoadDone();
    temp_r31_1623 = this->unk90 * 0x90;
    if (MKHeap::Current() != NULL) {
        var_r3_1631 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r31_1623, NULL, 0);
    } else {
        var_r3_1631 = malloc(temp_r31_1623);
    }
    this->unk170 = var_r3_1631;
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to 'MKVector3 *'
s32 BirdCritter::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r30_1689;
    s32 temp_r31_1670;
    s32 var_r31_1688;
    void *var_r3_1678;

    if (Critters::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("Waypoints") != 0) {
        this->unk178 = arg0->GetNmbrOfSubLines();
        temp_r31_1670 = this->unk178 * 0x10;
        if (MKHeap::Current() != NULL) {
            var_r3_1678 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r31_1670, NULL, 0);
        } else {
            var_r3_1678 = malloc(temp_r31_1670);
        }
        this->unk174 = var_r3_1678;
        var_r31_1688 = 0;
        var_r30_1689 = arg0->unkC->GetSubLine(arg0);
loop_8:
        if (var_r30_1689 != NULL) {
            var_r30_1689->AsVector3(0, ((u8 *) this->unk174) + var_r31_1688);
            var_r31_1688 += 0x10;
            var_r30_1689 = var_r30_1689->unkC->GetNextLine(var_r30_1689);
            goto loop_8;
        }
        return 1;
    }
    return 0;
}
#endif

void BirdCritter::Init() {
    Critters::Init();
    this->unk178 = 0;
    this->unk174 = NULL;
}

void BirdCritterDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}

void BirdCritterDescriptor::LoadDone() {
    s8 *temp_r30_1758;
    s8 *temp_r30_1778;
    s8 *temp_r30_1796;
    s8 *temp_r30_1814;
    s8 *temp_r30_1832;
    s8 *temp_r30_1850;
    void *var_r3_1770;
    void *var_r3_1788;
    void *var_r3_1806;
    void *var_r3_1824;
    void *var_r3_1842;
    void *var_r3_1860;

    KDPropDescriptor::LoadDone();
    temp_r30_1758 = this->unk34;
    if (((MKAnimScript *) temp_r30_1758)->Exists("song") != 0) {
        var_r3_1770 = ((MKAnimScript *) temp_r30_1758)->GetAnim("song");
    } else {
        var_r3_1770 = NULL;
    }
    this->unk70 = (s32) var_r3_1770;
    temp_r30_1778 = this->unk34;
    if (((MKAnimScript *) temp_r30_1778)->Exists("watch") != 0) {
        var_r3_1788 = ((MKAnimScript *) temp_r30_1778)->GetAnim("watch");
    } else {
        var_r3_1788 = NULL;
    }
    this->unk74 = (s32) var_r3_1788;
    temp_r30_1796 = this->unk34;
    if (((MKAnimScript *) temp_r30_1796)->Exists("jump") != 0) {
        var_r3_1806 = ((MKAnimScript *) temp_r30_1796)->GetAnim("jump");
    } else {
        var_r3_1806 = NULL;
    }
    this->unk78 = (s32) var_r3_1806;
    temp_r30_1814 = this->unk34;
    if (((MKAnimScript *) temp_r30_1814)->Exists("depart") != 0) {
        var_r3_1824 = ((MKAnimScript *) temp_r30_1814)->GetAnim("depart");
    } else {
        var_r3_1824 = NULL;
    }
    this->unk7C = (s32) var_r3_1824;
    temp_r30_1832 = this->unk34;
    if (((MKAnimScript *) temp_r30_1832)->Exists("flight") != 0) {
        var_r3_1842 = ((MKAnimScript *) temp_r30_1832)->GetAnim("flight");
    } else {
        var_r3_1842 = NULL;
    }
    this->unk80 = (s32) var_r3_1842;
    temp_r30_1850 = this->unk34;
    if (((MKAnimScript *) temp_r30_1850)->Exists("arrive") != 0) {
        var_r3_1860 = ((MKAnimScript *) temp_r30_1850)->GetAnim("arrive");
    } else {
        var_r3_1860 = NULL;
    }
    this->unk84 = (s32) var_r3_1860;
}

s32 BirdCritterDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1882;

    var_r31_1882 = 0;
    if ((KDPropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "randomSound", (int *) &this->unk90) != 0) || (arg0->LoadFloat("minSoundDelay", &this->unk88, 0) != 0) || (arg0->LoadFloat("maxSoundDelay", &this->unk8C, 0) != 0)) {
        var_r31_1882 = 1;
    }
    return var_r31_1882;
}

void BirdCritterDescriptor::Init() {
    KDPropDescriptor::Init();
    this->unk88 = 5.0f;
    this->unk8C = 10.0f;
    this->unk90 = GS_PLACEHOLDER;
}
