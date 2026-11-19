#include "spyro/source/LitCloudPS.h"
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

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
M2C_UNK qsort(MKHeap *, s32, M2C_UNK, s32 (*)(void *, void *)); /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'MKVector'
void LitCloudPS::Explode() {
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    MKVector3 sp28;
    M2C_UNK sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_95;
    f32 var_f0_96;
    f64 temp_f0_72;
    s32 var_r29_52;
    s32 var_r31_53;
    void *temp_r3_80;
    void *temp_r3_93;

    var_r29_52 = 0;
    var_r31_53 = 0;
loop_5:
    if (var_r29_52 < (s32) this->unk74) {
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, -1.0f, -1.0f);
        KDRand_Vector(sp38, sp28);
        temp_f0_72 = sp38 * 5.676053805e-315;
        sp8 = temp_f0_72;
        sp48 = temp_f0_72;
        temp_r3_80 = *(this->unk80 + var_r31_53) + 0x20;
        sp10 = sp38.unk8 * 1000.0f;
        sp50 = (f64) sp10;
        M2C_FIELD(temp_r3_80, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_80, f64 *, 0) + temp_f0_72);
        M2C_FIELD(temp_r3_80, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_80, f32 *, 8) + (f32) sp50);
        temp_r3_93 = *(this->unk80 + var_r31_53);
        temp_f1_95 = M2C_FIELD(temp_r3_93, f32 *, 0x48);
        var_f0_96 = 0.25f * M2C_FIELD(temp_r3_93, f32 *, 0x4C);
        if (var_f0_96 < temp_f1_95) {

        } else {
            var_f0_96 = temp_f1_95;
        }
        M2C_FIELD(temp_r3_93, f32 *, 0x48) = var_f0_96;
        var_r29_52 += 1;
        var_r31_53 += 4;
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void LitCloudPS::StateUpdate() {
    f64 sp1C8;
    f64 sp1C0;
    MKVector3 sp1B0;
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
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
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
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f1_179;
    f32 temp_f29_351;
    f32 temp_f31_158;
    f32 temp_f6_289;
    f32 var_f2_254;
    f32 var_f4_187;
    f32 var_f5_275;
    f64 temp_f0_293;
    f64 temp_f0_303;
    f64 temp_f0_369;
    f64 temp_f0_379;
    f64 temp_f1_193;
    f64 temp_f1_199;
    f64 temp_f1_203;
    s32 temp_r0_139;
    s32 temp_r3_222;
    s32 var_r0_232;

    temp_r0_139 = this->unk98;
    if (temp_r0_139 != 1) {
        if ((temp_r0_139 < 1) && (temp_r0_139 < 0)) {

        }
    } else if (!(this->unk78 > 0.0f)) {
        this->unk78 = 0.0f;
        temp_f31_158 = MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f);
        spD8 = -1.0f;
        spC8 = 1.0f;
        spD0 = -1.0f;
        spD4 = 0.0f;
        spC0 = 1.0f;
        spC4 = 1.0f;
        sp1A0 = (f64) spD0;
        sp1A8 = (f64) spD8;
        sp190 = (f64) spC0;
        sp198 = (f64) spC8;
        KDRand_Vector(sp1B0, *((MKVector3 *) &sp1A0));
        temp_f1_179 = M2C_BITWISE(f32, sp1B0);
        var_f4_187 = (sp1B0.unk8 * sp1B0.unk8) + ((temp_f1_179 * temp_f1_179) + (sp1B0.unk4 * sp1B0.unk4));
        if (var_f4_187 > 1e-12f) {
            if (var_f4_187 > 0.0f) {
                temp_f1_193 = __frsqrte(var_f4_187);
                temp_f1_199 = 0.5 * temp_f1_193 * -(((f64) var_f4_187 * (temp_f1_193 * temp_f1_193)) - 3.0);
                temp_f1_203 = 0.5 * temp_f1_199 * -(((f64) var_f4_187 * (temp_f1_199 * temp_f1_199)) - 3.0);
                var_f4_187 = (f32) ((f64) var_f4_187 * (0.5 * temp_f1_203 * -(((f64) var_f4_187 * (temp_f1_203 * temp_f1_203)) - 3.0)));
            } else if (var_f4_187 < M2C_BITWISE(f32, 0.0)) {
                var_f4_187 = __float_nan;
            } else {
                sp8 = var_f4_187;
                temp_r3_222 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_222) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_232 = 1;
                    } else {
                        var_r0_232 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_232 = 5;
                    } else {
                        var_r0_232 = 3;
                    }
                    break;
                default:
                    var_r0_232 = 4;
                    break;
                }
                if (var_r0_232 == 1) {
                    var_f4_187 = __float_nan;
                }
            }
            var_f2_254 = 1.0f / var_f4_187;
        } else {
            var_f2_254 = 0.0f;
        }
        spB0 = M2C_BITWISE(f32, sp1B0) * var_f2_254;
        spB4 = sp1B0.unk4 * var_f2_254;
        spB8 = sp1B0.unk8 * var_f2_254;
        sp1C0 = (f64) spB0;
        sp1C8 = (f64) spB8;
        var_f5_275 = 0.125f + (*(f32 *) ((u8 *) &sp1C0 + 0x4));
        if (var_f5_275 < 1.0f) {

        } else {
            var_f5_275 = 1.0f;
        }
        if (var_f5_275 > 0.0f) {

        } else {
            var_f5_275 = 0.0f;
        }
        temp_f6_289 = this->unk4C;
        temp_f0_293 = sp1C0 * 5.593163344e-315;
        spA0 = temp_f0_293;
        sp160 = temp_f0_293;
        spA8 = (f32) sp1C8 * 250.0f;
        sp168 = (f64) spA8;
        temp_f0_303 = temp_f0_293 * (f64) temp_f6_289;
        sp90 = temp_f0_303;
        sp170 = temp_f0_303;
        sp98 = (f32) sp168 * temp_f6_289;
        sp178 = (f64) sp98;
        sp80 = this->unk88 + temp_f0_303;
        sp70 = var_f5_275;
        sp88 = this->unk90 + (f32) sp178;
        sp74 = var_f5_275;
        sp78 = var_f5_275;
        sp7C = temp_f31_158;
        sp180 = sp80;
        sp188 = (f64) sp88;
        sp150 = (f64) sp70;
        sp158 = (f64) sp78;
        Emit(*((MKVector3 *) &sp180), *((MKVector4 *) &sp150), 100.0f * (1.2f + (*(f32 *) ((u8 *) &sp1C0 + 0x4))) * temp_f6_289, 1U);
        sp68 = -1.0f;
        temp_f29_351 = this->unk4C;
        sp58 = 1.0f;
        sp60 = -1.0f;
        sp64 = 0.0f;
        sp50 = 1.0f;
        sp54 = 0.25f;
        sp100 = (f64) sp60;
        sp108 = (f64) sp68;
        spF0 = (f64) sp50;
        spF8 = (f64) sp58;
        KDRand_Vector(sp110, *((MKVector3 *) &sp100));
        temp_f0_369 = sp110 * 5.593163344e-315;
        sp40 = temp_f0_369;
        sp120 = temp_f0_369;
        sp48 = sp110.unk8 * 250.0f;
        sp128 = (f64) sp48;
        temp_f0_379 = temp_f0_369 * (f64) temp_f29_351;
        sp30 = temp_f0_379;
        sp130 = temp_f0_379;
        sp38 = (f32) sp128 * temp_f29_351;
        sp138 = (f64) sp38;
        sp20 = this->unk88 + temp_f0_379;
        sp10 = 0.75f;
        sp14 = 0.75f;
        sp28 = this->unk90 + (f32) sp138;
        sp18 = 0.2f;
        sp1C = 1.0f;
        sp140 = sp20;
        sp148 = (f64) sp28;
        spE0 = (f64) sp10;
        spE8 = (f64) sp18;
        SetLight(*((MKVector3 *) &sp140), *((MKVector4 *) &spE0), this->unk4C * (100.0f * MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f)));
    }
}
#endif

void LitCloudPS::SetScale(float arg0) {
    this->unk4C = arg0;
}

void LitCloudPS::Stop() {
    this->unk98 = 0;
}

void LitCloudPS::Trigger(const MKVector3 &arg0) {
    this->unk98 = 1;
    this->unk88 = M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x90) = (f64) M2C_FIELD(&arg0, f64 *, 8);
}

void LitCloudPS::SetLight(const MKVector3 &arg0, const MKVector4 &arg1, float arg2) {
    this->unk50 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk58 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk60 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk68 = M2C_FIELD(&arg1, f64 *, 8);
    this->unk70 = arg2;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKHeap' to
void LitCloudPS::Emit(const MKVector3 &arg0, const MKVector4 &arg1, float arg2, bool arg3) {
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    MKVector3 sp38;
    MKVector3 sp28;
    M2C_UNK sp18;
    f32 sp10;
    f64 sp8;
    MKHeap *temp_r3_500;
    f32 temp_f1_549;
    f32 temp_f31_558;
    s32 var_ctr_498;
    s32 var_r30_497;
    void *temp_r3_584;
    void *temp_r4_513;
    void *temp_r4_521;

    if ((s32) this->unk74 < 0x63) {
        var_r30_497 = 0;
        var_ctr_498 = 0x64;
loop_2:
        temp_r3_500 = this->unk7C;
        if ((u8) *(temp_r3_500 + (var_r30_497 + 0x50)) == 0) {
            M2C_FIELD((temp_r3_500 + var_r30_497), s8 *, 0x50) = 1;
            temp_r4_513 = this->unk7C + var_r30_497;
            M2C_FIELD(temp_r4_513, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r4_513, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            temp_r4_521 = this->unk7C + (var_r30_497 + 0x10);
            M2C_FIELD(temp_r4_521, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r4_521, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            M2C_FIELD((this->unk7C + var_r30_497), f32 *, 0x44) = arg2;
            M2C_FIELD((this->unk7C + var_r30_497), f32 *, 0x40) = 0.0f;
            M2C_FIELD((this->unk7C + var_r30_497), f32 *, 0x30) = (f32) (2.0f * MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f));
            M2C_FIELD((this->unk7C + var_r30_497), f32 *, 0x34) = (f32) (0.125f * MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f));
            temp_f1_549 = MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f);
            M2C_FIELD((this->unk7C + var_r30_497), f32 *, 0x4C) = temp_f1_549;
            M2C_FIELD((this->unk7C + var_r30_497), f32 *, 0x48) = temp_f1_549;
            temp_f31_558 = this->unk4C;
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp38, sp28);
            sp48.operator*(25.0f);
            sp8 = sp48 * (f64) temp_f31_558;
            temp_r3_584 = this->unk7C + (var_r30_497 + 0x20);
            M2C_FIELD(temp_r3_584, f64 *, 0) = sp8;
            sp10 = sp48.unk8 * temp_f31_558;
            sp58 = sp8;
            M2C_FIELD(temp_r3_584, f64 *, 8) = (f64) sp10;
            sp60 = (f64) sp10;
            *(this->unk80 + (this->unk74 * 4)) = this->unk7C + var_r30_497;
            this->unk74 += 1;
            return;
        }
        var_r30_497 += 0x60;
        var_ctr_498 -= 1;
        if (var_ctr_498 == 0) {

        } else {
            goto loop_2;
        }
    }
}
#endif

void LitCloudPS::Deinit() {
    MKHeap *temp_r31_622;
    MKHeap *temp_r31_636;

    temp_r31_622 = this->unk7C;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_622, NULL, 0);
    } else {
        free(temp_r31_622);
    }
    temp_r31_636 = this->unk80;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_636, NULL, 0);
    } else {
        free(temp_r31_636);
    }
    MKMaterial_Destroy(this->unk84);
    MKProp::Deinit();
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void LitCloudPS::DrawCloudlet(LitCloudPS::LitParticle *arg1, Matrix *arg2) {
    f64 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    Matrix sp310;
    Matrix sp2D0;
    Matrix sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    MKVector3 sp240;
    MKVector3 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    MKVector3 sp200;
    MKVector3 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    MKVector3 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    MKVector3 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    MKVector3 sp180;
    f64 sp178;
    f64 sp170;
    MKVector3 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f64 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
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
    f32 temp_f31_873;
    f32 var_f0_924;
    f32 var_f0_942;
    f32 var_f0_964;
    f32 var_f0_982;
    f32 var_f1_908;
    f32 var_f1_933;
    f32 var_f1_956;
    f32 var_f1_973;
    f32 var_f3_1003;
    f64 temp_f0_887;
    f64 temp_f0_896;

    sp108 = 0.0f;
    sp100 = 1.0f;
    sp104 = 0.0f;
    sp278 = (f64) sp108;
    sp270 = (f64) sp100;
    sp118 = 0.0f;
    sp48 = -(f32) sp278;
    sp110 = 0.0f;
    sp114 = 1.0f;
    sp40 = -(f32) sp270;
    sp44 = -(*(f32 *) ((u8 *) &sp270 + 0x4));
    sp280 = (f64) sp110;
    sp288 = (f64) sp118;
    sp220 = (f64) sp40;
    sp228 = (f64) sp48;
    sp230.operator*(M2C_FIELD(arg1, f32 *, 0x44));
    sp240.operator*(M2C_FIELD(arg1, f32 *, 0x44));
    spA0 = sp240 + M2C_BITWISE(f64, sp230);
    sp350 = spA0;
    spA8 = sp240.unk8 + sp230.unk8;
    sp250 = spA0;
    sp358 = (f64) spA8;
    sp258 = (f64) spA8;
    sp1F0.operator*(M2C_FIELD(arg1, f32 *, 0x44));
    sp200.operator*(M2C_FIELD(arg1, f32 *, 0x44));
    sp90 = sp200 + M2C_BITWISE(f64, sp1F0);
    sp38 = -(f32) sp278;
    sp98 = sp200.unk8 + sp1F0.unk8;
    sp30 = -(f32) sp270;
    sp34 = -(*(f32 *) ((u8 *) &sp270 + 0x4));
    sp360 = sp90;
    sp368 = (f64) sp98;
    sp1A0 = (f64) sp30;
    sp1A8 = (f64) sp38;
    sp210 = sp90;
    sp218 = (f64) sp98;
    sp1B0.operator*(M2C_FIELD(arg1, f32 *, 0x44));
    sp20 = -(f32) sp280;
    sp24 = -(*(f32 *) ((u8 *) &sp280 + 0x4));
    sp28 = -(f32) sp288;
    sp1C0 = (f64) sp20;
    sp1C8 = (f64) sp28;
    sp1D0.operator*(M2C_FIELD(arg1, f32 *, 0x44));
    sp80 = sp1D0 + M2C_BITWISE(f64, sp1B0);
    sp370 = sp80;
    sp88 = sp1D0.unk8 + sp1B0.unk8;
    sp1E0 = sp80;
    sp378 = (f64) sp88;
    sp1E8 = (f64) sp88;
    sp160.operator*(M2C_FIELD(arg1, f32 *, 0x44));
    sp10 = -(f32) sp280;
    sp14 = -(*(f32 *) ((u8 *) &sp280 + 0x4));
    sp18 = -(f32) sp288;
    sp170 = (f64) sp10;
    sp178 = (f64) sp18;
    sp180.operator*(M2C_FIELD(arg1, f32 *, 0x44));
    sp70 = sp180 + M2C_BITWISE(f64, sp160);
    sp190 = sp70;
    sp78 = sp180.unk8 + sp160.unk8;
    sp380 = sp70;
    sp198 = (f64) sp78;
    sp388 = (f64) sp78;
    M2C_STRUCT_COPY((s32) &sp2D0.unk3C + 4, (s32) (arg2 - 4) + 4, 0x40);
    sp2D0.SetIdentity();
    sp2D0.RotateRoll(&sp2D0, M2C_FIELD(arg1, f32 *, 0x30));
    sp310.Multiply3x3(&sp2D0, &sp310);
    sp310.unk30 = M2C_FIELD(arg1, f32 *, 0);
    sp310.unk34 = M2C_FIELD(arg1, f32 *, 4);
    sp310.unk38 = M2C_FIELD(arg1, f32 *, 8);
    sp310.unk3C = 1.0f;
    MKSetMatrix(sp290);
    MKSetMatrix(sp310);
    temp_f31_873 = M2C_FIELD(arg1, f32 *, 0x40);
    spC0 = 1.0f;
    spC4 = 1.0f;
    spC8 = 1.0f;
    spCC = 1.0f;
    sp120 = (f64) spC0;
    sp128 = (f64) spC8;
    spE0 = this->unk60 * (f64) temp_f31_873;
    temp_f0_887 = this->unk68 * (f64) temp_f31_873;
    spE8 = temp_f0_887;
    sp130 = spE0;
    sp138 = temp_f0_887;
    temp_f0_896 = M2C_FIELD(arg1, f64 *, 0x10) + sp130;
    spD0 = temp_f0_896;
    spD8 = M2C_FIELD(arg1, f64 *, 0x18) + temp_f0_887;
    sp140 = temp_f0_896;
    var_f1_908 = (f32) sp140;
    spF0 = 0.0f;
    spF4 = 0.0f;
    spF8 = 0.0f;
    spFC = 0.0f;
    sp148 = spD8;
    sp150 = (f64) spF0;
    sp158 = (f64) spF8;
    if (var_f1_908 < (f32) sp120) {

    } else {
        var_f1_908 = (f32) sp120;
    }
    var_f0_924 = (*(f32 *) ((u8 *) &sp140 + 0x4));
    sp60 = var_f1_908;
    if (var_f0_924 < (*(f32 *) ((u8 *) &sp120 + 0x4))) {

    } else {
        var_f0_924 = (*(f32 *) ((u8 *) &sp120 + 0x4));
    }
    var_f1_933 = (f32) sp148;
    sp64 = var_f0_924;
    if (var_f1_933 < (f32) sp128) {

    } else {
        var_f1_933 = (f32) sp128;
    }
    var_f0_942 = (*(f32 *) ((u8 *) &sp148 + 0x4));
    sp68 = var_f1_933;
    if (var_f0_942 < (*(f32 *) ((u8 *) &sp128 + 0x4))) {

    } else {
        var_f0_942 = (*(f32 *) ((u8 *) &sp128 + 0x4));
    }
    sp6C = var_f0_942;
    spB0 = (f64) sp60;
    var_f1_956 = (f32) spB0;
    spB8 = (f64) sp68;
    if (var_f1_956 > (f32) sp150) {

    } else {
        var_f1_956 = (f32) sp150;
    }
    var_f0_964 = (*(f32 *) ((u8 *) &spB0 + 0x4));
    sp50 = var_f1_956;
    if (var_f0_964 > (*(f32 *) ((u8 *) &sp150 + 0x4))) {

    } else {
        var_f0_964 = (*(f32 *) ((u8 *) &sp150 + 0x4));
    }
    var_f1_973 = (f32) spB8;
    sp54 = var_f0_964;
    if (var_f1_973 > (f32) sp158) {

    } else {
        var_f1_973 = (f32) sp158;
    }
    var_f0_982 = (*(f32 *) ((u8 *) &spB8 + 0x4));
    sp58 = var_f1_973;
    if (var_f0_982 > (*(f32 *) ((u8 *) &sp158 + 0x4))) {

    } else {
        var_f0_982 = (*(f32 *) ((u8 *) &sp158 + 0x4));
    }
    sp5C = var_f0_982;
    sp260 = (f64) sp50;
    sp268 = (f64) sp58;
    var_f3_1003 = (M2C_FIELD(arg1, f32 *, 0x48) / M2C_FIELD(arg1, f32 *, 0x4C)) - 0.5f;
    if (var_f3_1003 < 0.0f) {
        var_f3_1003 = -var_f3_1003;
    }
    (*(f32 *) ((u8 *) &sp268 + 0x4)) *= -((2.0f * var_f3_1003) - 1.0f);
    MKBegin(4);
    MKSetColorV(*((MKVector4 *) &sp260));
    MKSetTexCoord1F(0.0f, 1.0f);
    MKSetPositionV(*((MKVector3 *) &sp350));
    MKSetColorV(*((MKVector4 *) &sp260));
    MKSetTexCoord1F(1.0f, 1.0f);
    MKSetPositionV(*((MKVector3 *) &sp360));
    MKSetColorV(*((MKVector4 *) &sp260));
    MKSetTexCoord1F(0.0f, 0.0f);
    MKSetPositionV(*((MKVector3 *) &sp370));
    MKSetColorV(*((MKVector4 *) &sp260));
    MKSetTexCoord1F(1.0f, 0.0f);
    MKSetPositionV(*((MKVector3 *) &sp380));
    MKEnd();
}
#endif

#if 0 // DRAFT: undefined identifier 'LitParticleCompare'
void LitCloudPS::Draw() {
    Matrix sp10;
    M2C_UNK spC;
    s32 var_r30_1086;
    s32 var_r31_1087;

    qsort(this->unk80, this->unk74, 4, LitParticleCompare);
    M2C_STRUCT_COPY((s32) &spC + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    MKMaterial_SetMaterial(this->unk84);
    MKPrimitive(0xC, 0);
    var_r30_1086 = 0;
    var_r31_1087 = 0;
loop_2:
    if (var_r30_1086 < (s32) this->unk74) {
        DrawCloudlet(*(this->unk80 + var_r31_1087), &sp10);
        var_r30_1086 += 1;
        var_r31_1087 += 4;
        goto loop_2;
    }
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap' to
void *LitCloudPS::Update() {
    f64 sp88;
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    MKHeap *temp_r6_1173;
    f32 temp_f0_1316;
    f32 temp_f1_1193;
    f32 temp_f1_1202;
    f32 temp_f2_1146;
    f32 var_f0_1147;
    f32 var_f4_1301;
    f32 var_f5_1234;
    f64 temp_f0_1333;
    f64 temp_f0_1357;
    f64 temp_f1_1240;
    f64 temp_f1_1246;
    f64 temp_f1_1250;
    s32 temp_r0_1142;
    s32 temp_r4_1269;
    s32 temp_r5_1169;
    s32 var_r31_1128;
    s32 var_r3_1279;
    void *temp_r3_1133;
    void *temp_r3_1144;
    void *temp_r3_1192;
    void *temp_r3_1201;
    void *temp_r3_1309;
    void *temp_r3_1330;
    void *temp_r3_1353;
    void *temp_r4_1163;
    void *temp_r4_1210;

    var_r31_1128 = 0;
    this->unk78 -= gUpdateTimeDelta;
    temp_r3_1133 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp78 = M2C_FIELD(temp_r3_1133, f64 *, 0x38);
    sp70 = M2C_FIELD(temp_r3_1133, f64 *, 0x30);
loop_38:
    if (var_r31_1128 < (s32) this->unk74) {
        temp_r0_1142 = var_r31_1128 * 4;
        temp_r3_1144 = *(this->unk80 + temp_r0_1142);
        temp_f2_1146 = M2C_FIELD(temp_r3_1144, f32 *, 0x4C);
        var_f0_1147 = M2C_FIELD(temp_r3_1144, f32 *, 0x48) - gUpdateTimeDelta;
        if (var_f0_1147 < temp_f2_1146) {

        } else {
            var_f0_1147 = temp_f2_1146;
        }
        if (var_f0_1147 > 0.0f) {

        } else {
            var_f0_1147 = 0.0f;
        }
        M2C_FIELD(temp_r3_1144, f32 *, 0x48) = var_f0_1147;
        temp_r4_1163 = *(this->unk80 + temp_r0_1142);
        if (M2C_FIELD(temp_r4_1163, f32 *, 0x48) <= 0.0f) {
            temp_r5_1169 = var_r31_1128 + 1;
            M2C_FIELD(temp_r4_1163, s8 *, 0x50) = 0;
            temp_r6_1173 = this->unk80;
            memcpy(temp_r6_1173 + temp_r0_1142, temp_r6_1173 + (temp_r5_1169 * 4), (this->unk74 - temp_r5_1169) * 4);
            var_r31_1128 -= 1;
            this->unk74 -= 1;
        } else {
            M2C_FIELD(temp_r4_1163, f32 *, 0x30) = (f32) ((gUpdateTimeDelta * M2C_FIELD(temp_r4_1163, f32 *, 0x34)) + M2C_FIELD(temp_r4_1163, f32 *, 0x30));
            temp_r3_1192 = *(this->unk80 + temp_r0_1142);
            temp_f1_1193 = M2C_FIELD(temp_r3_1192, f32 *, 0x30);
            if (temp_f1_1193 > 6.2831855f) {
                M2C_FIELD(temp_r3_1192, f32 *, 0x30) = (f32) (temp_f1_1193 - 6.2831855f);
            }
            temp_r3_1201 = *(this->unk80 + temp_r0_1142);
            temp_f1_1202 = M2C_FIELD(temp_r3_1201, f32 *, 0x30);
            if (temp_f1_1202 < -6.2831855f) {
                M2C_FIELD(temp_r3_1201, f32 *, 0x30) = (f32) (6.2831855f - temp_f1_1202);
            }
            temp_r4_1210 = *(this->unk80 + temp_r0_1142);
            sp20 = M2C_FIELD(temp_r4_1210, f64 *, 0) - this->unk50;
            sp80 = sp20;
            sp28 = M2C_FIELD(temp_r4_1210, f32 *, 8) - M2C_FIELD(this, f32 *, 0x58);
            sp88 = (f64) sp28;
            sp60 = sp20;
            sp68 = (f64) sp28;
            var_f5_1234 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + ((*(f32 *) ((u8 *) &sp78 + 0xc)) * (*(f32 *) ((u8 *) &sp78 + 0xc))));
            if (var_f5_1234 > 0.000001f) {
                if (var_f5_1234 > 0.0f) {
                    temp_f1_1240 = __frsqrte(var_f5_1234);
                    temp_f1_1246 = 0.5 * temp_f1_1240 * -(((f64) var_f5_1234 * (temp_f1_1240 * temp_f1_1240)) - 3.0);
                    temp_f1_1250 = 0.5 * temp_f1_1246 * -(((f64) var_f5_1234 * (temp_f1_1246 * temp_f1_1246)) - 3.0);
                    var_f5_1234 = (f32) ((f64) var_f5_1234 * (0.5 * temp_f1_1250 * -(((f64) var_f5_1234 * (temp_f1_1250 * temp_f1_1250)) - 3.0)));
                } else if (var_f5_1234 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_1234 = __float_nan;
                } else {
                    sp8 = var_f5_1234;
                    temp_r4_1269 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r4_1269) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r3_1279 = 1;
                        } else {
                            var_r3_1279 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r3_1279 = 5;
                        } else {
                            var_r3_1279 = 3;
                        }
                        break;
                    default:
                        var_r3_1279 = 4;
                        break;
                    }
                    if (var_r3_1279 == 1) {
                        var_f5_1234 = __float_nan;
                    }
                }
                var_f4_1301 = 1.0f / var_f5_1234;
            } else {
                var_f4_1301 = 0.0f;
                var_f5_1234 = 0.0f;
            }
            temp_r3_1309 = *(this->unk80 + temp_r0_1142);
            sp80 = (f32) sp80 * var_f4_1301;
            temp_f0_1316 = this->unk70 + M2C_FIELD(temp_r3_1309, f32 *, 0x44);
            (*(f32 *) ((u8 *) &sp78 + 0xc)) *= var_f4_1301;
            if (var_f5_1234 < temp_f0_1316) {
                M2C_FIELD(temp_r3_1309, f32 *, 0x40) = (f32) (1.0f - (var_f5_1234 / temp_f0_1316));
            } else {
                M2C_FIELD(temp_r3_1309, f32 *, 0x40) = 0.0f;
            }
            temp_r3_1330 = *(this->unk80 + temp_r0_1142);
            temp_f0_1333 = sp70 - M2C_FIELD(temp_r3_1330, f64 *, 0);
            sp30 = temp_f0_1333;
            sp50 = temp_f0_1333;
            sp38 = (f32) sp78 - M2C_FIELD(temp_r3_1330, f32 *, 8);
            sp58 = (f64) sp38;
            M2C_FIELD(temp_r3_1330, f32 *, 0x38) = (f32) (((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + ((*(f32 *) ((u8 *) &sp50 + 0x4)) * (*(f32 *) ((u8 *) &sp50 + 0x4)))));
            temp_r3_1353 = *(this->unk80 + temp_r0_1142);
            temp_f0_1357 = *(temp_r3_1353 + 0x20) * (f64) gUpdateTimeDelta;
            sp10 = temp_f0_1357;
            sp40 = temp_f0_1357;
            sp18 = M2C_FIELD(temp_r3_1353, f32 *, 0x28) * gUpdateTimeDelta;
            sp48 = (f64) sp18;
            M2C_FIELD(temp_r3_1353, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_1353, f64 *, 0) + temp_f0_1357);
            M2C_FIELD(temp_r3_1353, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_1353, f32 *, 8) + (f32) sp48);
        }
        var_r31_1128 += 1;
        goto loop_38;
    }
    StateUpdate();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void LitCloudPS::Init() {
    MKHeap *var_r3_1411;
    MKHeap *var_r3_1425;
    s32 temp_r0_1447;
    s32 var_ctr_1444;
    s32 var_r3_1436;

    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        var_r3_1411 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x2580, NULL, 0);
    } else {
        var_r3_1411 = malloc(0x2580);
    }
    this->unk7C = var_r3_1411;
    if (MKHeap::Current() != NULL) {
        var_r3_1425 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x190, NULL, 0);
    } else {
        var_r3_1425 = malloc(0x190);
    }
    this->unk80 = var_r3_1425;
    this->unk74 = 0;
    var_r3_1436 = 0;
    M2C_FIELD(this, f32 *, 0x50) = 0.0f;
    M2C_FIELD(this, f32 *, 0x54) = 0.0f;
    M2C_FIELD(this, f32 *, 0x58) = 0.0f;
    M2C_FIELD(this, f32 *, 0x60) = 0.0f;
    M2C_FIELD(this, f32 *, 0x64) = 0.0f;
    M2C_FIELD(this, f32 *, 0x68) = 0.0f;
    M2C_FIELD(this, f32 *, 0x6C) = 0.0f;
    var_ctr_1444 = 0x64;
    do {
        temp_r0_1447 = var_r3_1436 + 0x50;
        var_r3_1436 += 0x60;
        *(this->unk7C + temp_r0_1447) = 0;
        var_ctr_1444 -= 1;
    } while (var_ctr_1444 != 0);
    this->unk84 = MKMaterial_Create("FX_381");
    this->unk78 = 0.0f;
    this->unk98 = 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const void' to
s32 LitParticleCompare(const void *arg0, const void *arg1) {
    return -(s32) (M2C_FIELD(*arg0, f32 *, 0x38) - M2C_FIELD(*arg1, f32 *, 0x38));
}
#endif
