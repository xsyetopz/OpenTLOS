#include "spyro/source/IceSnoat.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Critters.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/Level.h"
#include "spyro/source/Volume.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;

void IceSnoatCritter::Deinit() {
    void *temp_r31_54;

    temp_r31_54 = this->unk170;
    if (temp_r31_54 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_54, NULL, 0);
        } else {
            free(temp_r31_54);
        }
    }
    this->unk170 = NULL;
    Critters::Deinit();
}

void IceSnoatCritter::Draw() {
    Matrix sp10;
    M2C_UNK spC;
    s32 var_r30_92;
    s32 var_r31_93;
    void *temp_r29_100;

    var_r30_92 = 0;
    var_r31_93 = 0;
loop_2:
    if (var_r30_92 < (s32) this->unk90) {
        temp_r29_100 = ((u8 *) this->unk170) + var_r31_93;
        this->unk80->SetAnim(M2C_FIELD(temp_r29_100, MKAnim **, 0x50), 0.0f, 0.0f, 0, -1);
        this->unk80->JumpToPos(M2C_FIELD(temp_r29_100, f32 *, 0x54), -1);
        M2C_STRUCT_COPY((s32) &spC + 4, (s32) (((u8 *) temp_r29_100) - 4) + 4, 0x40);
        MKModel_SetWorldMatrix(this->unk4, sp10);
        MKModel_Draw(this->unk4, NULL);
        var_r30_92 += 1;
        var_r31_93 += 0x90;
        goto loop_2;
    }
}

#if 0 // DRAFT: ')' expected
void IceSnoatCritter::FindNewBounceParameters(IceSnoat *arg0) {
    s8 sp260;
    s32 sp25C;
    s32 sp258;
    s32 sp254;
    f32 sp250;
    s32 sp24C;
    s8 sp24B;
    s8 sp24A;
    s16 sp248;
    f32 sp244;
    f32 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp234;
    f32 sp230;
    f32 sp228;
    f32 sp224;
    f32 sp220;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;                                      /* compiler-managed */
    f64 sp1D0;                                      /* compiler-managed */
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    MKVector3 sp160;
    f64 sp158;
    f64 sp150;
    MKVector3 sp140;
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
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
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
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 var_f3_541;
    f32 var_f4_360;
    f32 var_f4_474;
    f32 var_f5_293;
    f64 temp_f0_218;
    f64 temp_f0_237;
    f64 temp_f0_430;
    f64 temp_f1_299;
    f64 temp_f1_305;
    f64 temp_f1_309;
    f64 temp_f1_480;
    f64 temp_f1_486;
    f64 temp_f1_490;
    s32 temp_r3_328;
    s32 temp_r3_509;
    s32 var_r0_338;
    s32 var_r0_519;

    arg0->unk50 = M2C_FIELD(checked_cast<IceSnoatCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x70);
    spE8 = 0.0f;
    spB8 = 0.0f;
    spB0 = 0.0f;
    spB4 = -500.0f;
    spE0 = 0.0f;
    spE4 = 1.0f;
    sp170 = (f64) spB0;
    sp1F0 = (f64) spE0;
    sp1F8 = (f64) spE8;
    sp178 = (f64) spB8;
    arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
    arg0->unk54 = 0.0f;
    sp200 = arg0->unk30;
    sp208 = arg0->unk38;
    sp210 = 0.0f;
    sp214 = 0.0f;
    sp218 = 0.0f;
    sp220 = 0.0f;
    sp224 = 0.0f;
    sp228 = 0.0f;
    sp230 = 0.0f;
    sp234 = 0.0f;
    sp238 = 0.0f;
    sp23C = 1.0f;
    sp240 = 0.0f;
    sp244 = 0.0f;
    sp248 = 0;
    sp24A = 0;
    sp24B = 0;
    sp24C = 0;
    sp250 = 3.4028235e38f;
    sp254 = 0;
    sp258 = 0;
    sp25C = -1;
    sp260 = 0;
    temp_f0_218 = sp200 + sp170;
    spA0 = temp_f0_218;
    sp180 = temp_f0_218;
    spA8 = (f32) sp208 + (f32) sp178;
    sp188 = (f64) spA8;
    spD8 = 0.0f;
    spD0 = 0.0f;
    spD4 = 200.0f;
    sp198 = (f64) spD8;
    sp190 = (f64) spD0;
    temp_f0_237 = sp200 + sp190;
    spC0 = temp_f0_237;
    sp1A0 = temp_f0_237;
    spC8 = (f32) sp208 + (f32) sp198;
    sp1A8 = (f64) spC8;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp1A0), *((MKVector3 *) &sp180), (MKCollisionResult *) &sp210, (MKCollisionMode) 4, 0x0C000000) != 0) {
        sp200 = (f64) sp210;
        sp208 = (f64) sp218;
        sp1F0 = (f64) sp220;
        sp1F8 = (f64) sp228;
    }
    sp160 = this->unkE0.GetRandPos();
    *(MKVector3 *) &sp1E0 = sp160;
    (*(f32 *) ((u8 *) &sp1E0 + 0x4)) = (*(f32 *) ((u8 *) &sp200 + 0x4));
    sp90 = sp1E0 - arg0->unk30;
    sp1D0 = sp90;
    sp98 = (f32) sp1E8 - (f32) M2C_FIELD(arg0, f64 *, 0x38);
    sp1D8 = (f64) sp98;
    var_f5_293 = ((f32) sp1D8 * (f32) sp1D8) + (((f32) sp1D0 * (f32) sp1D0) + ((*(f32 *) ((u8 *) &sp1C8 + 0xc)) * (*(f32 *) ((u8 *) &sp1C8 + 0xc))));
    if (var_f5_293 > 0.000001f) {
        if (var_f5_293 > 0.0f) {
            temp_f1_299 = __frsqrte(var_f5_293);
            temp_f1_305 = 0.5 * temp_f1_299 * -(((f64) var_f5_293 * (temp_f1_299 * temp_f1_299)) - 3.0);
            temp_f1_309 = 0.5 * temp_f1_305 * -(((f64) var_f5_293 * (temp_f1_305 * temp_f1_305)) - 3.0);
            var_f5_293 = (f32) ((f64) var_f5_293 * (0.5 * temp_f1_309 * -(((f64) var_f5_293 * (temp_f1_309 * temp_f1_309)) - 3.0)));
        } else if (var_f5_293 < M2C_BITWISE(f32, 0.0)) {
            var_f5_293 = __float_nan;
        } else {
            spC = var_f5_293;
            temp_r3_328 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_328) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_338 = 1;
                } else {
                    var_r0_338 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_338 = 5;
                } else {
                    var_r0_338 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_338 = 4;
                break;
            }
            if (var_r0_338 == 1) {
                var_f5_293 = __float_nan;
            }
        }
        var_f4_360 = 1.0f / var_f5_293;
    } else {
        var_f4_360 = 0.0f;
        var_f5_293 = 0.0f;
    }
    sp1D0 = (f32) sp1D0 * var_f4_360;
    (*(f32 *) ((u8 *) &sp1C8 + 0xc)) *= var_f4_360;
    sp1D8 = (f32) sp1D8 * var_f4_360;
    M2C_ERROR(/* unknown instruction: cror 0x2, 0x1, 0x2 */);
    if (var_f5_293 == 200.0f) {
        sp140 = ((MKVector3 *) &sp1D0)->operator*(MKRand_Float((int *) &gViewSeed, 100.0f, 200.0f));
        sp20 = sp200 + M2C_BITWISE(f64, sp140);
        sp150 = sp20;
        sp28 = (f32) sp208 + sp140.unk8;
        sp1E0 = sp20;
        sp158 = (f64) sp28;
        sp1E8 = (f64) sp28;
    }
    sp60 = 0.0f;
    sp64 = -500.0f;
    sp68 = 0.0f;
    sp100 = (f64) sp60;
    sp108 = (f64) sp68;
    sp50 = sp1E0 + sp100;
    sp88 = 0.0f;
    sp80 = 0.0f;
    sp84 = 200.0f;
    sp58 = (f32) sp1E8 + (f32) sp108;
    sp120 = (f64) sp80;
    sp110 = sp50;
    sp118 = (f64) sp58;
    sp128 = (f64) sp88;
    temp_f0_430 = sp1E0 + sp120;
    sp70 = temp_f0_430;
    sp130 = temp_f0_430;
    sp78 = (f32) sp1E8 + (f32) sp128;
    sp138 = (f64) sp78;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp130), *((MKVector3 *) &sp110), (MKCollisionResult *) &sp210, (MKCollisionMode) 4, 0x0C000000) != 0) {
        sp1E0 = (f64) sp210;
        sp1E8 = (f64) sp218;
    }
    sp10 = sp1E0 - sp200;
    sp1D0 = sp10;
    sp18 = (f32) sp1E8 - (f32) sp208;
    sp1D8 = (f64) sp18;
    spF0 = sp10;
    spF8 = (f64) sp18;
    var_f4_474 = ((f32) sp1D8 * (f32) sp1D8) + (((f32) sp1D0 * (f32) sp1D0) + ((*(f32 *) ((u8 *) &sp1C8 + 0xc)) * (*(f32 *) ((u8 *) &sp1C8 + 0xc))));
    if (var_f4_474 > 1e-12f) {
        if (var_f4_474 > 0.0f) {
            temp_f1_480 = __frsqrte(var_f4_474);
            temp_f1_486 = 0.5 * temp_f1_480 * -(((f64) var_f4_474 * (temp_f1_480 * temp_f1_480)) - 3.0);
            temp_f1_490 = 0.5 * temp_f1_486 * -(((f64) var_f4_474 * (temp_f1_486 * temp_f1_486)) - 3.0);
            var_f4_474 = (f32) ((f64) var_f4_474 * (0.5 * temp_f1_490 * -(((f64) var_f4_474 * (temp_f1_490 * temp_f1_490)) - 3.0)));
        } else if (var_f4_474 < M2C_BITWISE(f32, 0.0)) {
            var_f4_474 = __float_nan;
        } else {
            sp8 = var_f4_474;
            temp_r3_509 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_509) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_519 = 1;
                } else {
                    var_r0_519 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_519 = 5;
                } else {
                    var_r0_519 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_519 = 4;
                break;
            }
            if (var_r0_519 == 1) {
                var_f4_474 = __float_nan;
            }
        }
        var_f3_541 = 1.0f / var_f4_474;
    } else {
        var_f3_541 = 0.0f;
    }
    sp40 = (f32) sp1D0 * var_f3_541;
    sp44 = (*(f32 *) ((u8 *) &sp1C8 + 0xc)) * var_f3_541;
    sp48 = (f32) sp1D8 * var_f3_541;
    sp1C0 = (f64) sp40;
    sp1C8 = (f64) sp48;
    sp30 = ((*(f32 *) ((u8 *) &sp1C0 + 0x4)) * (f32) sp1F8) - ((f32) sp1C8 * (*(f32 *) ((u8 *) &sp1F0 + 0x4)));
    sp34 = ((f32) sp1C8 * (f32) sp1F0) - ((f32) sp1C0 * (f32) sp1F8);
    sp38 = ((f32) sp1C0 * (*(f32 *) ((u8 *) &sp1F0 + 0x4))) - ((*(f32 *) ((u8 *) &sp1C0 + 0x4)) * (f32) sp1F0);
    sp1B0 = (f64) sp30;
    sp1B8 = (f64) sp38;
    arg0->unk0 = (f32) sp1B0;
    arg0->unk4 = (*(f32 *) ((u8 *) &sp1B0 + 0x4));
    arg0->unk8 = (f32) sp1B8;
    arg0->unkC = 0.0f;
    arg0->unk10 = (f32) sp1F0;
    arg0->unk14 = (*(f32 *) ((u8 *) &sp1F0 + 0x4));
    arg0->unk18 = (f32) sp1F8;
    arg0->unk1C = 0.0f;
    arg0->unk20 = (f32) sp1C0;
    arg0->unk24 = (*(f32 *) ((u8 *) &sp1C0 + 0x4));
    arg0->unk28 = (f32) sp1C8;
    arg0->unk2C = 0.0f;
    M2C_FIELD(arg0, f64 *, 0x30) = (f32) sp200;
    M2C_FIELD(arg0, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp200 + 0x4));
    M2C_FIELD(arg0, f64 *, 0x38) = (f32) sp208;
    M2C_FIELD(arg0, f32 *, 0x3C) = 1.0f;
    arg0->unk68 = sp200;
    arg0->unk70 = sp208;
    arg0->unk78 = sp1D0;
    arg0->unk80 = sp1D8;
}
#endif

void *IceSnoatCritter::Update() {
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
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    IceSnoat *temp_r28_641;
    f32 temp_f1_761;
    f32 temp_f31_679;
    f32 var_f0_662;
    f64 temp_f0_681;
    f64 temp_f0_693;
    f64 temp_f0_772;
    f64 temp_f0_782;
    f64 temp_f0_794;
    f64 temp_f1_723;
    s32 temp_r0_650;
    s32 var_r29_635;
    s32 var_r31_636;
    void *temp_r30_715;
    void *temp_r3_722;

    var_r29_635 = 0;
    var_r31_636 = 0;
loop_24:
    if (var_r29_635 < (s32) this->unk90) {
        temp_r28_641 = (IceSnoat *) (((u8 *) this->unk170) + var_r31_636);
        temp_r28_641->unk64 -= gUpdateTimeDelta;
        temp_r28_641->unk54 += temp_r28_641->unk58 * gUpdateTimeDelta;
        temp_r0_650 = temp_r28_641->unk60;
        switch (temp_r0_650) {                      /* irregular */
        case 0:
            var_f0_662 = temp_r28_641->unk54;
            if (var_f0_662 < 1.0f) {

            } else {
                var_f0_662 = 1.0f;
            }
            if (var_f0_662 > 0.0f) {

            } else {
                var_f0_662 = 0.0f;
            }
            temp_r28_641->unk54 = var_f0_662;
            temp_f31_679 = temp_r28_641->unk54;
            temp_f0_681 = temp_r28_641->unk78 * (f64) temp_f31_679;
            sp58 = temp_f0_681;
            spA8 = temp_f0_681;
            sp60 = M2C_FIELD(temp_r28_641, f32 *, 0x80) * temp_f31_679;
            spB0 = (f64) sp60;
            temp_f0_693 = temp_r28_641->unk68 + temp_f0_681;
            sp48 = temp_f0_693;
            spC8 = temp_f0_693;
            sp50 = M2C_FIELD(temp_r28_641, f32 *, 0x70) + (f32) spB0;
            M2C_FIELD(temp_r28_641, f32 *, 0x30) = (f32) spC8;
            spD0 = (f64) sp50;
            M2C_FIELD(temp_r28_641, f32 *, 0x34) = (*(f32 *) ((u8 *) &spC8 + 0x4));
            M2C_FIELD(temp_r28_641, f32 *, 0x38) = (f32) spD0;
            M2C_FIELD(temp_r28_641, f32 *, 0x3C) = 1.0f;
            if (temp_r28_641->unk54 == 1.0f) {
                temp_r30_715 = temp_r28_641 + 0x30;
                temp_r3_722 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
                temp_f1_723 = M2C_FIELD(temp_r3_722, f64 *, 0x30);
                sp88 = temp_f1_723;
                sp90 = M2C_FIELD(temp_r3_722, f64 *, 0x38);
                sp38 = temp_f1_723 - M2C_FIELD(temp_r30_715, f64 *, 0);
                sp98 = sp38;
                sp40 = (f32) sp90 - M2C_FIELD(temp_r30_715, f32 *, 8);
                spA0 = (f64) sp40;
                if ((((f32) spA0 * (f32) spA0) + (((f32) sp98 * (f32) sp98) + ((*(f32 *) ((u8 *) &sp98 + 0x4)) * (*(f32 *) ((u8 *) &sp98 + 0x4))))) <= 250000.0f) {
                    SetRunState(temp_r28_641);
                } else {
                    FindNewBounceParameters(temp_r28_641);
                }
            }
            break;
        case 1:
            temp_f1_761 = temp_r28_641->unk54;
            if (temp_f1_761 > 1.0f) {
                temp_r28_641->unk54 = temp_f1_761 - 1.0f;
            }
            temp_f0_772 = temp_r28_641->unk78 * 5.60222949e-315;
            sp28 = temp_f0_772;
            sp68 = temp_f0_772;
            sp30 = M2C_FIELD(temp_r28_641, f32 *, 0x80) * 300.0f;
            sp70 = (f64) sp30;
            temp_f0_782 = temp_f0_772 * (f64) gUpdateTimeDelta;
            sp18 = temp_f0_782;
            sp78 = temp_f0_782;
            sp20 = (f32) sp70 * gUpdateTimeDelta;
            sp80 = (f64) sp20;
            temp_f0_794 = temp_r28_641->unk30 + temp_f0_782;
            sp8 = temp_f0_794;
            spB8 = temp_f0_794;
            sp10 = M2C_FIELD(temp_r28_641, f32 *, 0x38) + (f32) sp80;
            M2C_FIELD(temp_r28_641, f32 *, 0x30) = (f32) spB8;
            spC0 = (f64) sp10;
            M2C_FIELD(temp_r28_641, f32 *, 0x34) = (*(f32 *) ((u8 *) &spB8 + 0x4));
            M2C_FIELD(temp_r28_641, f32 *, 0x38) = (f32) spC0;
            M2C_FIELD(temp_r28_641, f32 *, 0x3C) = 1.0f;
            if (temp_r28_641->unk64 <= 0.0f) {
                SetAlertState(temp_r28_641);
            }
            break;
        case 2:
            if (temp_r28_641->unk54 >= 0.5f) {
                SetRunState(temp_r28_641);
            }
            break;
        }
        var_r29_635 += 1;
        var_r31_636 += 0x90;
        goto loop_24;
    }
}

void IceSnoatCritter::SetAlertState(IceSnoat *arg0) {
    IceSnoatCritterDescriptor *desc;

    arg0->unk60 = 2;
    desc = checked_cast<IceSnoatCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    arg0->unk50 = M2C_FIELD(desc, void **, 0x78);
    arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
    arg0->unk54 = 0.0f;
}

#if 0 // DRAFT: ')' expected
void IceSnoatCritter::FindNewRunParameters(IceSnoat *arg0) {
    s8 sp210;
    s32 sp20C;
    s32 sp208;
    s32 sp204;
    f32 sp200;
    s32 sp1FC;
    s8 sp1FB;
    s8 sp1FA;
    s16 sp1F8;
    f32 sp1F4;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E4;
    f32 sp1E0;
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
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
    MKVector3 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_1231;
    f32 temp_f3_1230;
    f32 temp_f4_1232;
    f32 var_f0_1176;
    f32 var_f3_1162;
    f32 var_f4_1095;
    f32 var_f4_1237;
    f64 temp_f0_1054;
    f64 temp_f0_970;
    f64 temp_f0_989;
    f64 temp_f1_1101;
    f64 temp_f1_1107;
    f64 temp_f1_1111;
    f64 temp_f1_1242;
    f64 temp_f1_1248;
    f64 temp_f1_1252;
    s32 temp_r3_1130;
    s32 temp_r3_1271;
    s32 var_r0_1140;
    s32 var_r0_1281;

    arg0->unk50 = M2C_FIELD(checked_cast<IceSnoatCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x74);
    spC8 = 0.0f;
    sp98 = 0.0f;
    sp90 = 0.0f;
    sp94 = -500.0f;
    spC0 = 0.0f;
    spC4 = 1.0f;
    sp120 = (f64) sp90;
    sp1A0 = (f64) spC0;
    sp1A8 = (f64) spC8;
    sp128 = (f64) sp98;
    arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
    arg0->unk54 = 0.0f;
    sp1B0 = arg0->unk30;
    sp1B8 = arg0->unk38;
    sp1C0 = 0.0f;
    sp1C4 = 0.0f;
    sp1C8 = 0.0f;
    sp1D0 = 0.0f;
    sp1D4 = 0.0f;
    sp1D8 = 0.0f;
    sp1E0 = 0.0f;
    sp1E4 = 0.0f;
    sp1E8 = 0.0f;
    sp1EC = 1.0f;
    sp1F0 = 0.0f;
    sp1F4 = 0.0f;
    sp1F8 = 0;
    sp1FA = 0;
    sp1FB = 0;
    sp1FC = 0;
    sp200 = 3.4028235e38f;
    sp204 = 0;
    sp208 = 0;
    sp20C = -1;
    sp210 = 0;
    temp_f0_970 = sp1B0 + sp120;
    sp80 = temp_f0_970;
    sp130 = temp_f0_970;
    sp88 = (f32) sp1B8 + (f32) sp128;
    sp138 = (f64) sp88;
    spB8 = 0.0f;
    spB0 = 0.0f;
    spB4 = 200.0f;
    sp148 = (f64) spB8;
    sp140 = (f64) spB0;
    temp_f0_989 = sp1B0 + sp140;
    spA0 = temp_f0_989;
    sp150 = temp_f0_989;
    spA8 = (f32) sp1B8 + (f32) sp148;
    sp158 = (f64) spA8;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp150), *((MKVector3 *) &sp130), (MKCollisionResult *) &sp1C0, (MKCollisionMode) 4, 0x0C000000) != 0) {
        sp1B0 = (f64) sp1C0;
        sp1B8 = (f64) sp1C8;
        sp1A0 = (f64) sp1D0;
        sp1A8 = (f64) sp1D8;
    }
    sp110 = this->unkE0.GetRandPos();
    sp50 = 0.0f;
    sp54 = -500.0f;
    sp190 = M2C_BITWISE(f64, sp110);
    sp58 = 0.0f;
    (*(f32 *) ((u8 *) &sp190 + 0x4)) = (*(f32 *) ((u8 *) &sp1B0 + 0x4));
    spD0 = (f64) sp50;
    sp198 = (f64) sp110.unk8;
    spD8 = (f64) sp58;
    sp40 = sp190 + spD0;
    sp78 = 0.0f;
    sp70 = 0.0f;
    sp74 = 200.0f;
    sp48 = (f32) sp198 + (f32) spD8;
    spF0 = (f64) sp70;
    spE0 = sp40;
    spE8 = (f64) sp48;
    spF8 = (f64) sp78;
    temp_f0_1054 = sp190 + spF0;
    sp60 = temp_f0_1054;
    sp100 = temp_f0_1054;
    sp68 = (f32) sp198 + (f32) spF8;
    sp108 = (f64) sp68;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp100), *((MKVector3 *) &spE0), (MKCollisionResult *) &sp1C0, (MKCollisionMode) 4, 0x0C000000) != 0) {
        sp190 = (f64) sp1C0;
        sp198 = (f64) sp1C8;
    }
    sp30 = sp190 - sp1B0;
    sp180 = sp30;
    sp38 = (f32) sp198 - (f32) sp1B8;
    sp188 = (f64) sp38;
    var_f4_1095 = ((f32) sp188 * (f32) sp188) + (((f32) sp180 * (f32) sp180) + ((*(f32 *) ((u8 *) &sp180 + 0x4)) * (*(f32 *) ((u8 *) &sp180 + 0x4))));
    if (var_f4_1095 > 1e-12f) {
        if (var_f4_1095 > 0.0f) {
            temp_f1_1101 = __frsqrte(var_f4_1095);
            temp_f1_1107 = 0.5 * temp_f1_1101 * -(((f64) var_f4_1095 * (temp_f1_1101 * temp_f1_1101)) - 3.0);
            temp_f1_1111 = 0.5 * temp_f1_1107 * -(((f64) var_f4_1095 * (temp_f1_1107 * temp_f1_1107)) - 3.0);
            var_f4_1095 = (f32) ((f64) var_f4_1095 * (0.5 * temp_f1_1111 * -(((f64) var_f4_1095 * (temp_f1_1111 * temp_f1_1111)) - 3.0)));
        } else if (var_f4_1095 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1095 = __float_nan;
        } else {
            spC = var_f4_1095;
            temp_r3_1130 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_1130) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1140 = 1;
                } else {
                    var_r0_1140 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1140 = 5;
                } else {
                    var_r0_1140 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1140 = 4;
                break;
            }
            if (var_r0_1140 == 1) {
                var_f4_1095 = __float_nan;
            }
        }
        var_f3_1162 = 1.0f / var_f4_1095;
    } else {
        var_f3_1162 = 0.0f;
    }
    sp24 = (*(f32 *) ((u8 *) &sp180 + 0x4)) * var_f3_1162;
    sp20 = (f32) sp180 * var_f3_1162;
    var_f0_1176 = 0.0f;
    sp28 = (f32) sp188 * var_f3_1162;
    sp170 = (f64) sp20;
    sp178 = (f64) sp28;
    sp10 = ((*(f32 *) ((u8 *) &sp170 + 0x4)) * (f32) sp1A8) - ((f32) sp178 * (*(f32 *) ((u8 *) &sp1A0 + 0x4)));
    sp14 = ((f32) sp178 * (f32) sp1A0) - ((f32) sp170 * (f32) sp1A8);
    sp18 = ((f32) sp170 * (*(f32 *) ((u8 *) &sp1A0 + 0x4))) - ((*(f32 *) ((u8 *) &sp170 + 0x4)) * (f32) sp1A0);
    sp160 = (f64) sp10;
    sp168 = (f64) sp18;
    arg0->unk0 = (f32) sp160;
    arg0->unk4 = (*(f32 *) ((u8 *) &sp160 + 0x4));
    arg0->unk8 = (f32) sp168;
    arg0->unkC = 0.0f;
    arg0->unk10 = (f32) sp1A0;
    arg0->unk14 = (*(f32 *) ((u8 *) &sp1A0 + 0x4));
    arg0->unk18 = (f32) sp1A8;
    arg0->unk1C = 0.0f;
    arg0->unk20 = (f32) sp170;
    arg0->unk24 = (*(f32 *) ((u8 *) &sp170 + 0x4));
    arg0->unk28 = (f32) sp178;
    arg0->unk2C = 0.0f;
    M2C_FIELD(arg0, f64 *, 0x30) = (f32) sp1B0;
    M2C_FIELD(arg0, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp1B0 + 0x4));
    M2C_FIELD(arg0, f64 *, 0x38) = (f32) sp1B8;
    M2C_FIELD(arg0, f32 *, 0x3C) = 1.0f;
    arg0->unk68 = sp1B0;
    arg0->unk70 = sp1B8;
    arg0->unk78 = sp180;
    arg0->unk80 = sp188;
    temp_f3_1230 = (f32) M2C_FIELD(arg0, f64 *, 0x78);
    temp_f2_1231 = M2C_FIELD(arg0, f32 *, 0x7C);
    temp_f4_1232 = (f32) M2C_FIELD(arg0, f64 *, 0x80);
    var_f4_1237 = (temp_f4_1232 * temp_f4_1232) + ((temp_f3_1230 * temp_f3_1230) + (temp_f2_1231 * temp_f2_1231));
    if (var_f4_1237 > 0.000001f) {
        if (var_f4_1237 > 0.0f) {
            temp_f1_1242 = __frsqrte(var_f4_1237);
            temp_f1_1248 = 0.5 * temp_f1_1242 * -(((f64) var_f4_1237 * (temp_f1_1242 * temp_f1_1242)) - 3.0);
            temp_f1_1252 = 0.5 * temp_f1_1248 * -(((f64) var_f4_1237 * (temp_f1_1248 * temp_f1_1248)) - 3.0);
            var_f4_1237 = (f32) ((f64) var_f4_1237 * (0.5 * temp_f1_1252 * -(((f64) var_f4_1237 * (temp_f1_1252 * temp_f1_1252)) - 3.0)));
        } else if (var_f4_1237 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1237 = __float_nan;
        } else {
            sp8 = var_f4_1237;
            temp_r3_1271 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1271) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1281 = 1;
                } else {
                    var_r0_1281 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1281 = 5;
                } else {
                    var_r0_1281 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_1281 = 4;
                break;
            }
            if (var_r0_1281 == 1) {
                var_f4_1237 = __float_nan;
            }
        }
        var_f0_1176 = 1.0f / var_f4_1237;
    } else {
        var_f4_1237 = 0.0f;
    }
    M2C_FIELD(arg0, f64 *, 0x78) = (f32) ((f32) M2C_FIELD(arg0, f64 *, 0x78) * var_f0_1176);
    M2C_FIELD(arg0, f32 *, 0x7C) = (f32) (M2C_FIELD(arg0, f32 *, 0x7C) * var_f0_1176);
    M2C_FIELD(arg0, f64 *, 0x80) = (f32) ((f32) M2C_FIELD(arg0, f64 *, 0x80) * var_f0_1176);
    arg0->unk64 = var_f4_1237 / 300.0f;
}
#endif

void IceSnoatCritter::SetRunState(IceSnoat *arg0) {
    arg0->unk60 = 1;
    FindNewRunParameters(arg0);
}

void IceSnoatCritter::SetBounceState(IceSnoat *arg0) {
    arg0->unk60 = 0;
    FindNewBounceParameters(arg0);
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
f32 IceSnoatCritter::Resolve() {
    s8 spF8;
    s32 spF4;
    s32 spF0;
    s32 spEC;
    f32 spE8;
    s32 spE4;
    s8 spE3;
    s8 spE2;
    s16 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f64 spA0;
    f64 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
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
    f32 sp10;
    f64 sp8;
    IceSnoat *temp_r28_1398;
    f64 temp_f0_1457;
    s32 var_r29_1389;
    s32 var_r31_1391;

    MKProp::Resolve();
    var_r29_1389 = 0;
    var_r31_1391 = 0;
loop_4:
    if (var_r29_1389 < (s32) this->unk90) {
        temp_r28_1398 = (IceSnoat *) (((u8 *) this->unk170) + var_r31_1391);
        sp88 = this->unkE0.GetRandPos();
        sp20 = 0.0f;
        sp98 = M2C_BITWISE(f64, sp88);
        sp18 = 0.0f;
        sp1C = -500.0f;
        (*(f32 *) ((u8 *) &sp98 + 0x4)) = M2C_FIELD(this->unk8, f32 *, 0x34);
        sp48 = (f64) sp18;
        spA0 = (f64) sp88.unk8;
        spA8 = 0.0f;
        spAC = 0.0f;
        spB0 = 0.0f;
        spB8 = 0.0f;
        spBC = 0.0f;
        spC0 = 0.0f;
        spC8 = 0.0f;
        spCC = 0.0f;
        spD0 = 0.0f;
        spD4 = 1.0f;
        spD8 = 0.0f;
        spDC = 0.0f;
        spE0 = 0;
        spE2 = 0;
        spE3 = 0;
        spE4 = 0;
        spE8 = 3.4028235e38f;
        spEC = 0;
        spF0 = 0;
        spF4 = -1;
        spF8 = 0;
        sp50 = (f64) sp20;
        sp8 = sp98 + sp48;
        sp40 = 0.0f;
        sp38 = 0.0f;
        sp3C = 200.0f;
        sp10 = (f32) spA0 + (f32) sp50;
        sp68 = (f64) sp38;
        sp58 = sp8;
        sp60 = (f64) sp10;
        sp70 = (f64) sp40;
        temp_f0_1457 = sp98 + sp68;
        sp28 = temp_f0_1457;
        sp78 = temp_f0_1457;
        sp30 = (f32) spA0 + (f32) sp70;
        sp80 = (f64) sp30;
        if (MKCollision_RayCollide(*((MKVector3 *) &sp78), *((MKVector3 *) &sp58), (MKCollisionResult *) &spA8, (MKCollisionMode) 4, 0x0C000000) != 0) {
            sp98 = (f64) spA8;
            spA0 = (f64) spB0;
        }
        M2C_STRUCT_COPY(temp_r28_1398, &Matrix::identity, 0x40);
        M2C_FIELD(temp_r28_1398, f32 *, 0x30) = (f32) sp98;
        M2C_FIELD(temp_r28_1398, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp98 + 0x4));
        M2C_FIELD(temp_r28_1398, f32 *, 0x38) = (f32) spA0;
        M2C_FIELD(temp_r28_1398, f32 *, 0x3C) = 1.0f;
        SetBounceState(temp_r28_1398);
        var_r29_1389 += 1;
        var_r31_1391 += 0x90;
        goto loop_4;
    }
}
#endif

s32 IceSnoatCritter::LoadDone() {
    s32 temp_r31_1532;
    void *var_r3_1540;

    Critters::LoadDone();
    temp_r31_1532 = this->unk90 * 0x90;
    if (MKHeap::Current() != NULL) {
        var_r3_1540 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r31_1532, NULL, 0);
    } else {
        var_r3_1540 = malloc(temp_r31_1532);
    }
    this->unk170 = var_r3_1540;
}

void IceSnoatCritter::Init() {
    Critters::Init();
}

void IceSnoatCritterDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}

void IceSnoatCritterDescriptor::LoadDone() {
    s8 *temp_r30_1589;
    s8 *temp_r30_1607;
    s8 *temp_r30_1625;
    void *var_r3_1599;
    void *var_r3_1617;
    void *var_r3_1635;

    KDPropDescriptor::LoadDone();
    temp_r30_1589 = this->unk34;
    if (((MKAnimScript *) temp_r30_1589)->Exists("bounce") != 0) {
        var_r3_1599 = ((MKAnimScript *) temp_r30_1589)->GetAnim("bounce");
    } else {
        var_r3_1599 = NULL;
    }
    this->unk70 = (s32) var_r3_1599;
    temp_r30_1607 = this->unk34;
    if (((MKAnimScript *) temp_r30_1607)->Exists("run") != 0) {
        var_r3_1617 = ((MKAnimScript *) temp_r30_1607)->GetAnim("run");
    } else {
        var_r3_1617 = NULL;
    }
    this->unk74 = (s32) var_r3_1617;
    temp_r30_1625 = this->unk34;
    if (((MKAnimScript *) temp_r30_1625)->Exists("alert") != 0) {
        var_r3_1635 = ((MKAnimScript *) temp_r30_1625)->GetAnim("alert");
    } else {
        var_r3_1635 = NULL;
    }
    this->unk78 = (s32) var_r3_1635;
}

void IceSnoatCritterDescriptor::Init() {
    KDPropDescriptor::Init();
}
