#include "spyro/source/SkyClouds.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
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
#include "spyro/source/Level.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(SkyClouds::CloudEmitter **);           /* extern */
SkyClouds::CloudEmitter **malloc(M2C_UNK);          /* extern */
f64 pow(f64, f32);                                  /* extern */
M2C_UNK qsort(SkyClouds::CloudEmitter **, s32, M2C_UNK, s32 (*)(void *, void *)); /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal operand
u8 SkyClouds::DestroyByOwner(SkyClouds::CloudEmitter *arg1) {
    SkyClouds::CloudEmitter **temp_r6_79;
    SkyClouds::CloudEmitter *temp_r3_59;
    SkyClouds::CloudEmitter *temp_r4_69;
    f32 temp_f31_53;
    s32 temp_r3_75;
    s32 var_r30_54;
    u8 var_r31_51;

    var_r31_51 = 0;
    temp_f31_53 = (f32) pow(0.5, gUpdateTimeDelta);
    var_r30_54 = 0;
loop_5:
    if (var_r30_54 < (s32) this->unk4C) {
        temp_r3_59 = this->unk54[var_r30_54];
        if ((u32) M2C_FIELD(temp_r3_59, u32 *, 0x44) == arg1) {
            var_r31_51 = 1;
            M2C_FIELD(temp_r3_59, f32 *, 0x1C) = (f32) (M2C_FIELD(temp_r3_59, f32 *, 0x1C) * temp_f31_53);
            temp_r4_69 = this->unk54[var_r30_54];
            if (M2C_FIELD(temp_r4_69, f32 *, 0x1C) <= 0.05f) {
                temp_r3_75 = var_r30_54 + 1;
                M2C_FIELD(temp_r4_69, s8 *, 0x48) = 0;
                temp_r6_79 = this->unk54;
                memcpy(&temp_r6_79[var_r30_54], &temp_r6_79[temp_r3_75], (this->unk4C - temp_r3_75) * 4);
                var_r30_54 -= 1;
                this->unk4C -= 1;
            }
        }
        var_r30_54 += 1;
        goto loop_5;
    }
    return var_r31_51;
}
#endif

void SkyClouds::UpdateCameraVel() {

}

void SkyClouds::UpdateClouds() {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    SkyClouds::CloudEmitter **temp_r3_166;
    SkyClouds::CloudEmitter **var_r31_125;
    SkyClouds::CloudEmitter *temp_r4_169;
    SkyClouds::CloudEmitter *temp_r4_178;
    f64 temp_f0_142;
    void *temp_r3_128;

    var_r31_125 = this->unkC0;
    temp_r3_128 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp30 = M2C_FIELD(temp_r3_128, f64 *, 0x38);
    sp28 = M2C_FIELD(temp_r3_128, f64 *, 0x30);
loop_5:
    if (var_r31_125 != NULL) {
        temp_r4_178 = *var_r31_125;
        if (temp_r4_178 != NULL) {
            M2C_FIELD(temp_r4_178, f32 *, 0x20) = (f32) (M2C_FIELD(temp_r4_178, f32 *, 0x20) - gUpdateTimeDelta);
            temp_f0_142 = sp28 - M2C_FIELD(temp_r4_178, f64 *, 0);
            sp8 = temp_f0_142;
            sp18 = temp_f0_142;
            sp10 = (f32) sp30 - M2C_FIELD(temp_r4_178, f32 *, 8);
            sp20 = (f64) sp10;
            if (((((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + ((*(f32 *) ((u8 *) &sp18 + 0x4)) * (*(f32 *) ((u8 *) &sp18 + 0x4))))) >= 4.9e7f) && (DestroyByOwner(temp_r4_178) == 0)) {
                temp_r3_166 = this->unkC0;
                this->unkC0 = temp_r3_166 + 4;
                temp_r4_169 = *temp_r3_166;
                *temp_r3_166 = *var_r31_125;
                *var_r31_125 = temp_r4_169;
            }
            var_r31_125 += 4;
            goto loop_5;
        }
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void SkyClouds::SpawnCloudEmitter(const MKVector3 &arg0, const MKVector3 &arg1, float arg2) {
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    SkyClouds::CloudEmitter **temp_r3_215;
    SkyClouds::CloudEmitter **temp_r3_219;
    SkyClouds::CloudEmitter *temp_r31_221;
    f32 temp_f1_275;
    f32 temp_f26_269;
    f32 temp_f31_271;
    f64 temp_f0_287;
    s32 var_r30_225;

    temp_r3_215 = this->unkC0;
    if ((u32) M2C_FIELD(temp_r3_215, u32 *, -4) != 0U) {
        temp_r3_219 = temp_r3_215 - 4;
        this->unkC0 = temp_r3_219;
        temp_r31_221 = *temp_r3_219;
        if (temp_r31_221 != NULL) {
            var_r30_225 = 0;
            M2C_FIELD(temp_r31_221, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r31_221, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r31_221, f64 *, 0x10) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r31_221, f64 *, 0x18) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            M2C_FIELD(temp_r31_221, f32 *, 0x24) = arg2;
            M2C_FIELD(temp_r31_221, f32 *, 0x20) = 0.0f;
            do {
                sp40 = 1.0f;
                sp50 = -1.0f;
                sp38 = 1.0f;
                sp3C = 1.0f;
                sp48 = -1.0f;
                sp4C = -1.0f;
                sp88 = (f64) sp38;
                sp90 = (f64) sp40;
                sp98 = (f64) sp48;
                spA0 = (f64) sp50;
                KDRand_Vector(spA8, *((MKVector3 *) &sp98));
                spB8 = M2C_BITWISE(f64, spA8);
                spC0 = (f64) spA8.unk8;
                temp_f26_269 = (0.25f * (1.0f + (*(f32 *) ((u8 *) &spB8 + 0x4)))) + 0.5f;
                temp_f31_271 = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                temp_f1_275 = MKRand_Float((int *) &gViewSeed, 0.1f, 0.5f);
                sp8 = temp_f26_269;
                spC = temp_f26_269;
                sp10 = temp_f26_269;
                sp14 = temp_f1_275;
                sp58 = (f64) sp8;
                sp60 = (f64) sp10;
                temp_f0_287 = spB8 * M2C_FIELD(temp_r31_221, f64 *, 0x10);
                sp28 = temp_f0_287;
                sp68 = temp_f0_287;
                sp30 = (f32) spC0 * (f32) M2C_FIELD(temp_r31_221, f64 *, 0x18);
                sp70 = (f64) sp30;
                sp18 = sp68 + M2C_FIELD(temp_r31_221, f64 *, 0);
                sp20 = (f32) sp70 + (f32) M2C_FIELD(temp_r31_221, f64 *, 8);
                sp78 = sp18;
                sp80 = (f64) sp20;
                Emit(*((MKVector3 *) &sp78), *((MKVector4 *) &sp58), 300.0f * ((1.0f - temp_f26_269) + temp_f31_271), temp_r31_221);
                var_r30_225 += 1;
            } while (var_r30_225 < 0x14);
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'SkyClouds::CloudEmitter **' to
void SkyClouds::Emit(const MKVector3 &arg1, const MKVector4 &arg2, float farg0, SkyClouds::CloudEmitter *arg3) {
    SkyClouds::CloudEmitter **temp_r3_358;
    s32 var_ctr_356;
    s32 var_r29_355;
    void *temp_r4_371;
    void *temp_r4_378;
    void *temp_r4_407;

    if ((s32) this->unk4C < 0x63) {
        var_r29_355 = 0;
        var_ctr_356 = 0x64;
loop_2:
        temp_r3_358 = this->unk50;
        if ((u8) *(temp_r3_358 + (var_r29_355 + 0x48)) == 0) {
            M2C_FIELD((temp_r3_358 + var_r29_355), s8 *, 0x48) = 1;
            temp_r4_371 = this->unk50 + var_r29_355;
            M2C_FIELD(temp_r4_371, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r4_371, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            temp_r4_378 = this->unk50 + (var_r29_355 + 0x10);
            M2C_FIELD(temp_r4_378, f64 *, 0) = (f64) M2C_FIELD(&arg2, f64 *, 0);
            M2C_FIELD(temp_r4_378, f64 *, 8) = (f64) M2C_FIELD(&arg2, f64 *, 8);
            M2C_FIELD((this->unk50 + var_r29_355), f32 *, 0x3C) = farg0;
            M2C_FIELD((this->unk50 + var_r29_355), f32 *, 0x30) = (f32) (2.0f * MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f));
            M2C_FIELD((this->unk50 + var_r29_355), f32 *, 0x34) = (f32) (0.125f * MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f));
            M2C_FIELD((this->unk50 + var_r29_355), f32 *, 0x40) = 2.0f;
            temp_r4_407 = this->unk50 + (var_r29_355 + 0x20);
            M2C_FIELD(temp_r4_407, f32 *, 0) = 0.0f;
            M2C_FIELD(temp_r4_407, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r4_407, f32 *, 8) = 0.0f;
            M2C_FIELD((this->unk50 + var_r29_355), SkyClouds::CloudEmitter **, 0x44) = arg3;
            this->unk54[this->unk4C] = this->unk50 + var_r29_355;
            this->unk4C += 1;
            return;
        }
        var_r29_355 += 0x50;
        var_ctr_356 -= 1;
        if (var_ctr_356 == 0) {

        } else {
            goto loop_2;
        }
    }
}
#endif

#if 0 // DRAFT: type mismatch
void SkyClouds::Deinit() {
    SkyClouds::CloudEmitter **temp_r31_443;
    SkyClouds::CloudEmitter **temp_r31_457;
    SkyClouds::CloudEmitter **var_r31_474;
    SkyClouds::CloudEmitter **var_r3_475;
    SkyClouds::CloudEmitter **var_r4_473;
    SkyClouds::CloudEmitter *temp_r0_478;
    SkyClouds::CloudEmitter *temp_r0_497;
    u32 temp_r0_483;

    temp_r31_443 = this->unk50;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_443, NULL, 0);
    } else {
        free(temp_r31_443);
    }
    temp_r31_457 = this->unk54;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_457, NULL, 0);
    } else {
        free(temp_r31_457);
    }
    MKMaterial_Destroy(this->unk58);
    var_r4_473 = this->unkC0;
    var_r31_474 = var_r4_473;
    var_r3_475 = var_r4_473;
loop_9:
    temp_r0_483 = M2C_FIELD(var_r3_475, u32 *, -4);
    var_r3_475 -= 4;
    if (temp_r0_483 != 0U) {
        temp_r0_478 = *var_r3_475;
        if (temp_r0_478 < var_r31_474) {
            var_r31_474 = (SkyClouds::CloudEmitter **) temp_r0_478;
        }
        goto loop_9;
    }
    if (var_r3_475 != &gEmptyPtrListDL) {
loop_15:
        temp_r0_497 = *var_r4_473;
        if (temp_r0_497 != NULL) {
            if (temp_r0_497 < var_r31_474) {
                var_r31_474 = (SkyClouds::CloudEmitter **) temp_r0_497;
            }
            var_r4_473 += 4;
            goto loop_15;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_474, NULL, 0);
        } else {
            free(var_r31_474);
        }
    }
    this->unkC0 = NULL;
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void SkyClouds::DrawCloudlet(SkyClouds::CloudParticle *arg1, Matrix *arg2) {
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    Matrix sp270;
    Matrix sp230;
    Matrix sp1F0;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    MKVector3 sp198;
    MKVector3 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    MKVector3 sp158;
    MKVector3 sp148;
    f64 sp140;
    f64 sp138;
    MKVector3 sp128;
    f64 sp120;
    f64 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    MKVector3 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 var_f4_736;
    f64 temp_f1_739;
    f64 temp_f1_745;
    f64 temp_f1_749;
    s32 temp_r3_768;
    s32 var_r0_778;

    spA0 = 0.0f;
    sp98 = 1.0f;
    sp9C = 0.0f;
    sp1D0 = (f64) spA0;
    sp1C8 = (f64) sp98;
    spB0 = 0.0f;
    sp50 = -(f32) sp1D0;
    spA8 = 0.0f;
    spAC = 1.0f;
    sp48 = -(f32) sp1C8;
    sp4C = -(*(f32 *) ((u8 *) &sp1C8 + 0x4));
    sp1D8 = (f64) spA8;
    sp1E0 = (f64) spB0;
    sp178 = (f64) sp48;
    sp180 = (f64) sp50;
    sp188.operator*(M2C_FIELD(arg1, f32 *, 0x3C));
    sp198.operator*(M2C_FIELD(arg1, f32 *, 0x3C));
    sp88 = sp198 + M2C_BITWISE(f64, sp188);
    sp2B0 = sp88;
    sp90 = sp198.unk8 + sp188.unk8;
    sp1A8 = sp88;
    sp2B8 = (f64) sp90;
    sp1B0 = (f64) sp90;
    sp148.operator*(M2C_FIELD(arg1, f32 *, 0x3C));
    sp158.operator*(M2C_FIELD(arg1, f32 *, 0x3C));
    sp78 = sp158 + M2C_BITWISE(f64, sp148);
    sp40 = -(f32) sp1D0;
    sp80 = sp158.unk8 + sp148.unk8;
    sp38 = -(f32) sp1C8;
    sp3C = -(*(f32 *) ((u8 *) &sp1C8 + 0x4));
    sp2C0 = sp78;
    sp2C8 = (f64) sp80;
    spF8 = (f64) sp38;
    sp100 = (f64) sp40;
    sp168 = sp78;
    sp170 = (f64) sp80;
    sp108.operator*(M2C_FIELD(arg1, f32 *, 0x3C));
    sp28 = -(f32) sp1D8;
    sp2C = -(*(f32 *) ((u8 *) &sp1D8 + 0x4));
    sp30 = -(f32) sp1E0;
    sp118 = (f64) sp28;
    sp120 = (f64) sp30;
    sp128.operator*(M2C_FIELD(arg1, f32 *, 0x3C));
    sp68 = sp128 + M2C_BITWISE(f64, sp108);
    sp2D0 = sp68;
    sp70 = sp128.unk8 + sp108.unk8;
    sp138 = sp68;
    sp2D8 = (f64) sp70;
    sp140 = (f64) sp70;
    spB8.operator*(M2C_FIELD(arg1, f32 *, 0x3C));
    sp18 = -(f32) sp1D8;
    sp1C = -(*(f32 *) ((u8 *) &sp1D8 + 0x4));
    sp20 = -(f32) sp1E0;
    spC8 = (f64) sp18;
    spD0 = (f64) sp20;
    spD8.operator*(M2C_FIELD(arg1, f32 *, 0x3C));
    sp58 = spD8 + M2C_BITWISE(f64, spB8);
    spE8 = sp58;
    sp60 = spD8.unk8 + spB8.unk8;
    sp2E0 = sp58;
    spF0 = (f64) sp60;
    sp2E8 = (f64) sp60;
    M2C_STRUCT_COPY((s32) &sp230.unk3C + 4, (s32) (arg2 - 4) + 4, 0x40);
    sp230.SetIdentity();
    sp230.RotateRoll(&sp230, M2C_FIELD(arg1, f32 *, 0x30));
    sp270.Multiply3x3(&sp230, &sp270);
    sp270.unk30 = M2C_FIELD(arg1, f32 *, 0);
    sp270.unk34 = M2C_FIELD(arg1, f32 *, 4);
    sp270.unk38 = M2C_FIELD(arg1, f32 *, 8);
    sp270.unk3C = 1.0f;
    MKSetMatrix(sp1F0);
    MKSetMatrix(sp270);
    sp1B8 = M2C_FIELD(arg1, f64 *, 0x10);
    sp1C0 = M2C_FIELD(arg1, f64 *, 0x18);
    var_f4_736 = M2C_FIELD(arg1, f32 *, 0x38);
    if (var_f4_736 > 0.0f) {
        temp_f1_739 = __frsqrte(var_f4_736);
        temp_f1_745 = 0.5 * temp_f1_739 * -(((f64) var_f4_736 * (temp_f1_739 * temp_f1_739)) - 3.0);
        temp_f1_749 = 0.5 * temp_f1_745 * -(((f64) var_f4_736 * (temp_f1_745 * temp_f1_745)) - 3.0);
        var_f4_736 = (f32) ((f64) var_f4_736 * (0.5 * temp_f1_749 * -(((f64) var_f4_736 * (temp_f1_749 * temp_f1_749)) - 3.0)));
    } else if (var_f4_736 < M2C_BITWISE(f32, 0.0)) {
        var_f4_736 = __float_nan;
    } else {
        sp10 = var_f4_736;
        temp_r3_768 = M2C_BITWISE(s32, sp10) & 0x7F800000;
        switch (temp_r3_768) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_778 = 1;
            } else {
                var_r0_778 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_778 = 5;
            } else {
                var_r0_778 = 3;
            }
            break;
        default:
            var_r0_778 = 4;
            break;
        }
        if (var_r0_778 == 1) {
            var_f4_736 = __float_nan;
        }
    }
    if (var_f4_736 < 800.0f) {

    } else {
        var_f4_736 = 800.0f;
    }
    if (var_f4_736 > 0.0f) {

    } else {
        var_f4_736 = 0.0f;
    }
    (*(f32 *) ((u8 *) &sp1C0 + 0x4)) *= -((M2C_FIELD(arg1, f32 *, 0x40) * 0.5f) - 1.0f) * (var_f4_736 / 800.0f);
    MKBegin(4);
    MKSetColorV(*((MKVector4 *) &sp1B8));
    MKSetTexCoord1F(0.0f, 1.0f);
    MKSetPositionV(*((MKVector3 *) &sp2B0));
    MKSetColorV(*((MKVector4 *) &sp1B8));
    MKSetTexCoord1F(1.0f, 1.0f);
    MKSetPositionV(*((MKVector3 *) &sp2C0));
    MKSetColorV(*((MKVector4 *) &sp1B8));
    MKSetTexCoord1F(0.0f, 0.0f);
    MKSetPositionV(*((MKVector3 *) &sp2D0));
    MKSetColorV(*((MKVector4 *) &sp1B8));
    MKSetTexCoord1F(1.0f, 0.0f);
    MKSetPositionV(*((MKVector3 *) &sp2E0));
    MKEnd();
}
#endif

#if 0 // DRAFT: undefined identifier 'CloudParticleCompare'
void SkyClouds::Draw() {
    Matrix sp10;
    M2C_UNK spC;
    s32 var_r30_895;
    s32 var_r31_896;

    qsort(this->unk54, this->unk4C, 4, CloudParticleCompare);
    M2C_STRUCT_COPY((s32) &spC + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    MKMaterial_SetMaterial(this->unk58);
    MKPrimitive(0xC, 0);
    var_r30_895 = 0;
    var_r31_896 = 0;
loop_2:
    if (var_r30_895 < (s32) this->unk4C) {
        DrawCloudlet(*(this->unk54 + var_r31_896), &sp10);
        var_r30_895 += 1;
        var_r31_896 += 4;
        goto loop_2;
    }
    MKEndPrimitive();
}
#endif

s32 SkyClouds::LoadDone() {
    MKProp::LoadDone();
    M2C_STRUCT_COPY((s32) &this->unk7C + 4, (s32) (&MKProp::loadInfo - 4) + 4, 0x40);
}

#if 0 // DRAFT: illegal type
void *SkyClouds::Update() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f3_999;
    f32 temp_f4_1007;
    f32 var_f3_975;
    f64 temp_f3_1018;
    f64 temp_f3_1042;
    s32 var_r3_961;
    s32 var_r6_957;
    void *temp_r4_1006;
    void *temp_r4_1015;
    void *temp_r4_1038;
    void *temp_r4_963;
    void *temp_r4_973;
    void *temp_r4_992;
    void *temp_r4_998;

    var_r6_957 = 0;
    var_r3_961 = 0;
    temp_r4_963 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp50 = M2C_FIELD(temp_r4_963, f64 *, 0x38);
    sp48 = M2C_FIELD(temp_r4_963, f64 *, 0x30);
loop_12:
    if (var_r6_957 < (s32) this->unk4C) {
        temp_r4_973 = *(this->unk54 + var_r3_961);
        var_f3_975 = M2C_FIELD(temp_r4_973, f32 *, 0x40) - gUpdateTimeDelta;
        if (var_f3_975 < 2.0f) {

        } else {
            var_f3_975 = 2.0f;
        }
        if (var_f3_975 > 0.0f) {

        } else {
            var_f3_975 = 0.0f;
        }
        M2C_FIELD(temp_r4_973, f32 *, 0x40) = var_f3_975;
        temp_r4_992 = *(this->unk54 + var_r3_961);
        M2C_FIELD(temp_r4_992, f32 *, 0x30) = (f32) ((gUpdateTimeDelta * M2C_FIELD(temp_r4_992, f32 *, 0x34)) + M2C_FIELD(temp_r4_992, f32 *, 0x30));
        temp_r4_998 = *(this->unk54 + var_r3_961);
        temp_f3_999 = M2C_FIELD(temp_r4_998, f32 *, 0x30);
        if (temp_f3_999 > 6.2831855f) {
            M2C_FIELD(temp_r4_998, f32 *, 0x30) = (f32) (temp_f3_999 - 6.2831855f);
        }
        temp_r4_1006 = *(this->unk54 + var_r3_961);
        temp_f4_1007 = M2C_FIELD(temp_r4_1006, f32 *, 0x30);
        if (temp_f4_1007 < -6.2831855f) {
            M2C_FIELD(temp_r4_1006, f32 *, 0x30) = (f32) (6.2831855f - temp_f4_1007);
        }
        temp_r4_1015 = *(this->unk54 + var_r3_961);
        temp_f3_1018 = sp48 - M2C_FIELD(temp_r4_1015, f64 *, 0);
        sp18 = temp_f3_1018;
        sp38 = temp_f3_1018;
        sp20 = (f32) sp50 - M2C_FIELD(temp_r4_1015, f32 *, 8);
        sp40 = (f64) sp20;
        M2C_FIELD(temp_r4_1015, f32 *, 0x38) = (f32) (((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * (*(f32 *) ((u8 *) &sp38 + 0x4)))));
        temp_r4_1038 = *(this->unk54 + var_r3_961);
        temp_f3_1042 = *(temp_r4_1038 + 0x20) * (f64) gUpdateTimeDelta;
        sp8 = temp_f3_1042;
        sp28 = temp_f3_1042;
        sp10 = M2C_FIELD(temp_r4_1038, f32 *, 0x28) * gUpdateTimeDelta;
        sp30 = (f64) sp10;
        M2C_FIELD(temp_r4_1038, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_1038, f64 *, 0) + temp_f3_1042);
        var_r6_957 += 1;
        var_r3_961 += 4;
        M2C_FIELD(temp_r4_1038, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_1038, f32 *, 8) + (f32) sp30);
        goto loop_12;
    }
    UpdateClouds();
    UpdateCameraVel();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void SkyClouds::Init() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    SkyClouds::CloudEmitter **temp_r3_1174;
    SkyClouds::CloudEmitter **temp_r3_1180;
    SkyClouds::CloudEmitter **var_r3_1092;
    SkyClouds::CloudEmitter **var_r3_1106;
    SkyClouds::CloudEmitter **var_r3_1159;
    SkyClouds::CloudEmitter **var_r5_1168;
    s32 temp_r0_1120;
    s32 var_ctr_1117;
    s32 var_ctr_1172;
    s32 var_r3_1115;

    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        var_r3_1092 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x1F40, NULL, 0);
    } else {
        var_r3_1092 = malloc(0x1F40);
    }
    this->unk50 = var_r3_1092;
    if (MKHeap::Current() != NULL) {
        var_r3_1106 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x190, NULL, 0);
    } else {
        var_r3_1106 = malloc(0x190);
    }
    this->unk54 = var_r3_1106;
    var_r3_1115 = 0;
    this->unk4C = 0;
    var_ctr_1117 = 0x64;
    do {
        temp_r0_1120 = var_r3_1115 + 0x48;
        var_r3_1115 += 0x50;
        *(this->unk50 + temp_r0_1120) = 0;
        var_ctr_1117 -= 1;
    } while (var_ctr_1117 != 0);
    this->unk58 = MKMaterial_Create("fx_381");
    sp20 = -0.5f;
    sp18 = -0.5f;
    sp1C = -0.5f;
    this->unk8 = &this->unk80;
    M2C_FIELD(this, f64 *, 0x60) = (f64) sp18;
    sp10 = 1.0f;
    sp8 = 1.0f;
    spC = 1.0f;
    this->unk68 = (f64) sp20;
    this->unk70 = (f64) sp8;
    M2C_FIELD(this, f64 *, 0x78) = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    this->unkC = (BoundingVolume *) &this->unk60;
    if (MKHeap::Current() != NULL) {
        var_r3_1159 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x210, NULL, 0);
    } else {
        var_r3_1159 = malloc(0x210);
    }
    this->unkC0 = var_r3_1159;
    var_r5_1168 = this->unkC0;
    this->unkC0 = var_r5_1168 + 0x1E0;
    M2C_FIELD(var_r5_1168, s32 *, 0x1E0) = 0;
    var_ctr_1172 = 0xA;
    do {
        temp_r3_1174 = this->unkC0;
        this->unkC0 = temp_r3_1174 + 4;
        M2C_FIELD(temp_r3_1174, SkyClouds::CloudEmitter ***, 4) = var_r5_1168;
        var_r5_1168 += 0x30;
        var_ctr_1172 -= 1;
    } while (var_ctr_1172 != 0);
    temp_r3_1180 = this->unkC0;
    this->unkC0 = temp_r3_1180 + 4;
    M2C_FIELD(temp_r3_1180, SkyClouds::CloudEmitter ***, 4) = NULL;
    this->unkC8 = 0.0f;
    this->unkCC = 0.0f;
    this->unkD0 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const void' to
s32 CloudParticleCompare(const void *arg0, const void *arg1) {
    return -(s32) (M2C_FIELD(*arg0, f32 *, 0x38) - M2C_FIELD(*arg1, f32 *, 0x38));
}
#endif

void SkyCloudsDescriptor::Init() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    MKPropDescriptor::Init();
    sp18 = -0.5f;
    sp1C = -0.5f;
    sp20 = -0.5f;
    this->unk1C = (BoundingVolume *) &this->unk60;
    M2C_FIELD(this, f64 *, 0x60) = (f64) sp18;
    sp10 = 1.0f;
    sp8 = 1.0f;
    spC = 1.0f;
    this->unk68 = (f64) sp20;
    this->unk70 = (f64) sp8;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    this->unk78 = (f64) sp10;
}
