#include "spyro/source/ExplosionWarpFX.h"
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
#include "spyro/source/ShotgunWarpFX.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: undefined identifier 'sp90'
void ExplosionWarpFX::UpdateWarp() {
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    M2C_UNK sp6C;
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
    f32 sp14;
    f32 sp10;
    f32 temp_f0_197;
    f32 temp_f13_91;
    f32 temp_f27_94;
    f32 temp_f28_92;
    f32 temp_f5_196;
    f32 temp_f6_198;
    f32 var_f0_28;
    f64 temp_f0_154;
    f64 temp_f13_114;
    s32 temp_r0_144;
    s32 temp_r5_136;
    s32 temp_r6_88;
    s32 var_ctr_145;
    s32 var_r4_141;
    s32 var_r7_72;
    void *temp_r0_150;
    void *temp_r4_122;
    void *temp_r5_158;
    void *temp_r5_186;
    void *temp_r5_90;
    void *temp_r6_152;
    void *temp_r6_176;
    void *temp_r6_195;

    var_f0_28 = this->unk64 - gUpdateTimeDelta;
    if (var_f0_28 < 0.65f) {

    } else {
        var_f0_28 = 0.65f;
    }
    if (var_f0_28 > 0.0f) {

    } else {
        var_f0_28 = 0.0f;
    }
    this->unk64 = var_f0_28;
    if (!(this->unk64 <= 0.0f)) {
        this->unk68 += 1;
        M2C_STRUCT_COPY((s32) &sp6C + 4, (s32) &this->unk1C + 4, 0x40);
        spA0 = 0.0f;
        spA4 = 0.0f;
        spA8 = 0.0f;
        spAC = 1.0f;
        if ((s32) this->unk68 < (s32) this->unkC) {
            var_r7_72 = 0;
loop_10:
            temp_r5_136 = this->unk10;
            if (var_r7_72 < temp_r5_136) {
                temp_r6_88 = (var_r7_72 + (this->unk68 * temp_r5_136)) * 0x30;
                temp_r5_90 = ((u8 *) this->unk0) + (temp_r6_88 + 0x20);
                temp_f13_91 = M2C_FIELD(temp_r5_90, f32 *, 4);
                temp_f28_92 = M2C_FIELD(temp_r5_90, f32 *, 0);
                temp_f27_94 = M2C_FIELD(temp_r5_90, f32 *, 8);
                sp10 = 0.0f + ((temp_f27_94 * sp90) + ((temp_f28_92 * sp70) + (temp_f13_91 * sp80)));
                sp14 = 0.0f + ((temp_f27_94 * sp94) + ((temp_f28_92 * sp74) + (temp_f13_91 * sp84)));
                sp18 = 0.0f + ((temp_f27_94 * sp98) + ((temp_f28_92 * sp78) + (temp_f13_91 * sp88)));
                sp50 = (f64) sp10;
                sp58 = (f64) sp18;
                temp_f13_114 = sp50 * 5.811479333e-315;
                sp30 = temp_f13_114;
                sp60 = temp_f13_114;
                temp_r4_122 = ((u8 *) this->unk4) + (temp_r6_88 + 0x20);
                sp38 = (f32) sp58 * 10000.0f;
                sp68 = (f64) sp38;
                M2C_FIELD(temp_r4_122, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_122, f64 *, 0) + temp_f13_114);
                var_r7_72 += 1;
                M2C_FIELD(temp_r4_122, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_122, f32 *, 8) + (f32) sp68);
                goto loop_10;
            }
        }
        var_r4_141 = 0;
        temp_r0_144 = this->unkC * this->unk10;
        var_ctr_145 = temp_r0_144;
        if (temp_r0_144 > 0) {
            do {
                temp_r0_150 = this->unk4;
                temp_r6_152 = ((u8 *) temp_r0_150) + (var_r4_141 + 0x20);
                temp_f0_154 = M2C_FIELD(temp_r6_152, f64 *, 0) * (f64) gUpdateTimeDelta;
                sp20 = temp_f0_154;
                temp_r5_158 = ((u8 *) temp_r0_150) + (var_r4_141 + 0x10);
                sp40 = temp_f0_154;
                sp28 = M2C_FIELD(temp_r6_152, f32 *, 8) * gUpdateTimeDelta;
                sp48 = (f64) sp28;
                M2C_FIELD(temp_r5_158, f64 *, 0) = (f64) (M2C_FIELD(temp_r5_158, f64 *, 0) + temp_f0_154);
                M2C_FIELD(temp_r5_158, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_158, f32 *, 8) + (f32) sp48);
                temp_r6_176 = ((u8 *) this->unk4) + (var_r4_141 + 0x10);
                M2C_FIELD(temp_r6_176, f64 *, 0) = (f64) (M2C_FIELD(temp_r6_176, f64 *, 0) * 5.180653787e-315);
                M2C_FIELD(temp_r6_176, f32 *, 8) = (f32) (M2C_FIELD(temp_r6_176, f32 *, 8) * 0.25f);
                temp_r5_186 = ((u8 *) this->unk4) + (var_r4_141 + 0x20);
                M2C_FIELD(temp_r5_186, f64 *, 0) = (f64) (M2C_FIELD(temp_r5_186, f64 *, 0) * 5.24282163e-315);
                M2C_FIELD(temp_r5_186, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_186, f32 *, 8) * 0.75f);
                temp_r6_195 = ((u8 *) this->unk4) + (var_r4_141 + 0x20);
                temp_f5_196 = M2C_FIELD(temp_r6_195, f32 *, 0);
                temp_f0_197 = M2C_FIELD(temp_r6_195, f32 *, 4);
                temp_f6_198 = M2C_FIELD(temp_r6_195, f32 *, 8);
                if (((temp_f6_198 * temp_f6_198) + ((temp_f5_196 * temp_f5_196) + (temp_f0_197 * temp_f0_197))) <= 100.0f) {
                    M2C_FIELD(temp_r6_195, f32 *, 0) = 0.0f;
                    M2C_FIELD(temp_r6_195, f32 *, 4) = 0.0f;
                    M2C_FIELD(temp_r6_195, f32 *, 8) = 0.0f;
                }
                var_r4_141 += 0x30;
                var_ctr_145 -= 1;
            } while (var_ctr_145 != 0);
        }
    }
}
#endif

void ExplosionWarpFX::StartWarp(Matrix *arg0) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f4_258;
    f32 temp_f7_265;
    f32 temp_f8_271;
    s32 temp_r0_248;
    s32 temp_r7_253;
    s32 temp_r8_255;
    s32 var_ctr_249;
    s32 var_r5_245;
    void *temp_r6_259;
    void *temp_r7_295;
    void *temp_r8_301;
    void *temp_r9_256;

    M2C_STRUCT_COPY((s32) &this->unk1C + 4, (s32) (arg0 - 4) + 4, 0x40);
    var_r5_245 = 0;
    temp_r0_248 = this->unkC * this->unk10;
    var_ctr_249 = temp_r0_248;
    if (temp_r0_248 > 0) {
        do {
            temp_r7_253 = var_r5_245 + 0x10;
            temp_r8_255 = var_r5_245 + 0x20;
            temp_r9_256 = ((u8 *) this->unk0) + var_r5_245;
            temp_f4_258 = M2C_FIELD(temp_r9_256, f32 *, 4);
            temp_r6_259 = ((u8 *) this->unk4) + var_r5_245;
            var_r5_245 += 0x30;
            temp_f7_265 = M2C_FIELD(temp_r9_256, f32 *, 0);
            temp_f8_271 = M2C_FIELD(temp_r9_256, f32 *, 8);
            sp8 = arg0->unk30 + ((temp_f8_271 * arg0->unk20) + ((temp_f7_265 * arg0->unk0) + (temp_f4_258 * arg0->unk10)));
            spC = arg0->unk34 + ((temp_f8_271 * arg0->unk24) + ((temp_f7_265 * arg0->unk4) + (temp_f4_258 * arg0->unk14)));
            sp10 = arg0->unk38 + ((temp_f8_271 * arg0->unk28) + ((temp_f7_265 * arg0->unk8) + (temp_f4_258 * arg0->unk18)));
            M2C_FIELD(temp_r6_259, f64 *, 0) = (f64) sp8;
            M2C_FIELD(temp_r6_259, f64 *, 8) = (f64) sp10;
            sp18 = (f64) sp8;
            temp_r7_295 = ((u8 *) this->unk4) + temp_r7_253;
            M2C_FIELD(temp_r7_295, f32 *, 0) = 0.0f;
            M2C_FIELD(temp_r7_295, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r7_295, f32 *, 8) = 0.0f;
            sp20 = (f64) sp10;
            temp_r8_301 = ((u8 *) this->unk4) + temp_r8_255;
            M2C_FIELD(temp_r8_301, f32 *, 0) = 0.0f;
            M2C_FIELD(temp_r8_301, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r8_301, f32 *, 8) = 0.0f;
            var_ctr_249 -= 1;
        } while (var_ctr_249 != 0);
    }
    this->unk64 = 0.65f;
    this->unk68 = 0;
}

void ExplosionWarpFX::BuildLocalVertexList() {
    f32 stepU;
    f32 stepV;
    f32 stepA;
    f32 rad;
    f32 zs;
    f32 xs;
    f32 ys;
    f32 ang;
    f32 cosv;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 sum;
    f32 root;
    f32 scale;
    f64 r0;
    f64 r1;
    f64 r2;
    u8 *pos;
    u8 *nrm;
    s32 i;
    s32 j;

    stepU = 400.0f / (f32) this->unkC;
    stepV = 999.0f / (f32) this->unkC;
    stepA = 6.2831855f / (f32) (this->unk10 - 1);

    for (i = 0; i < (s32) this->unkC; i++) {
        zs = -(stepU * (f32) i);
        rad = (stepV * (f32) i) + 1.0f;
        for (j = 0; j < this->unk10; j++) {
            ang = stepA * (f32) j;
            cosv = _table_sinf(1.5707964f + ang);
            ys = rad * -cosv;
            xs = rad * _table_sinf(ang);

            pos = (u8 *) this->unk0 + (j + i * this->unk10) * 0x30;
            M2C_FIELD(pos, f32 *, 0) = xs;
            M2C_FIELD(pos, f32 *, 4) = ys;
            M2C_FIELD(pos, f32 *, 8) = zs;

            /* Normal at +0x20: a copy of the position with z forced to 0. */
            nrm = pos + 0x20;
            M2C_FIELD(nrm, f32 *, 0) = xs;
            M2C_FIELD(nrm, f32 *, 4) = ys;
            M2C_FIELD(nrm, f32 *, 8) = 0.0f;

            nx = M2C_FIELD(nrm, f32 *, 0);
            ny = M2C_FIELD(nrm, f32 *, 4);
            nz = M2C_FIELD(nrm, f32 *, 8);
            sum = (nz * nz) + ((nx * nx) + (ny * ny));
            if (sum <= 0.000001f) {
                scale = 0.0f;
            } else {
                /* MWCC's inline sqrt: frsqrte refined by three Newton steps in f64. */
                r0 = __frsqrte(sum);
                r1 = 0.5 * r0 * -(((f64) sum * (r0 * r0)) - 3.0);
                r2 = 0.5 * r1 * -(((f64) sum * (r1 * r1)) - 3.0);
                root = (f32) ((f64) sum * (0.5 * r2 * -(((f64) sum * (r2 * r2)) - 3.0)));
                scale = 1.0f / root;
            }
            M2C_FIELD(nrm, f32 *, 0) = nx * scale;
            M2C_FIELD(nrm, f32 *, 4) = ny * scale;
            M2C_FIELD(nrm, f32 *, 8) = nz * scale;
        }
    }
}

void ExplosionWarpFX::Deinit() {
    void *temp_r31_567;
    void *temp_r31_581;
    void *temp_r31_595;

    MKMaterial_Destroy(this->unk60);
    temp_r31_567 = this->unk0;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_567, NULL, 0);
    } else {
        free(temp_r31_567);
    }
    temp_r31_581 = this->unk4;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_581, NULL, 0);
    } else {
        free(temp_r31_581);
    }
    temp_r31_595 = this->unk8;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_595, NULL, 0);
        return;
    }
    free(temp_r31_595);
}

void ExplosionWarpFX::Draw() {
    Matrix worldToScreen;
    MKVector3 local;
    MKVector3 pa;
    MKVector3 pb;
    MKVector4 col;
    f32 fade;
    f32 x;
    f32 y;
    s32 count;
    s32 i;
    s32 row;
    s32 j;
    s32 ia;
    s32 ib;
    u8 *p;
    u8 *uv;

    if (this->unk64 <= 0.0f) {
        return;
    }

    MKMaterial_SetMaterial(this->unk60);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(Matrix::identity);

    fade = 1.0f;
    if (this->unk64 < 0.325f) {
        fade = this->unk64 / 0.325f;
    }

    count = this->unkC * this->unk10;
    M2C_STRUCT_COPY(&worldToScreen, MKView_GetWorldToScreenMatrix(), 0x40);

    /* Project each point to screen space and clamp x and y to [0, 1]. */
    for (i = 0; i < count; i++) {
        p = (u8 *) this->unk4 + i * 0x30;
        Xform3D2D(&local, *(MKVector3 *) p, &worldToScreen);

        x = local.unk0;
        if (x < 1.0f) {
        } else {
            x = 1.0f;
        }
        if (x > 0.0f) {
        } else {
            x = 0.0f;
        }
        y = local.unk4;
        if (y < 1.0f) {
        } else {
            y = 1.0f;
        }
        if (y > 0.0f) {
        } else {
            y = 0.0f;
        }
        uv = (u8 *) this->unk8 + i * 8;
        M2C_FIELD(uv, f32 *, 0) = x;
        M2C_FIELD(uv, f32 *, 4) = y;
    }

    /* Each row of the grid is one strip of 2 * unk10 vertices. The last row is drawn with alpha 0. */
    for (row = 0; row < this->unkC - 1; row++) {
        col.unk0 = 1.0f;
        col.unk4 = 1.0f;
        col.unk8 = 1.0f;
        if (row == this->unkC - 2) {
            col.unkC = 0.0f;
        } else {
            col.unkC = fade;
        }

        MKBegin(this->unk10 * 2);
        for (j = 0; j < this->unk10; j++) {
            ia = j + row * this->unk10;
            ib = j + (row + 1) * this->unk10;

            MKSetColorV(col);
            uv = (u8 *) this->unk8 + ia * 8;
            MKSetTexCoord1F(M2C_FIELD(uv, f32 *, 0), M2C_FIELD(uv, f32 *, 4));
            p = (u8 *) this->unk4 + ia * 0x30;
            pa.unk0 = M2C_FIELD(p, f32 *, 0) + M2C_FIELD(p, f32 *, 0x10);
            pa.unk4 = M2C_FIELD(p, f32 *, 4) + M2C_FIELD(p, f32 *, 0x14);
            pa.unk8 = M2C_FIELD(p, f32 *, 8) + M2C_FIELD(p, f32 *, 0x18);
            MKSetPositionV(pa);

            MKSetColorV(col);
            uv = (u8 *) this->unk8 + ib * 8;
            MKSetTexCoord1F(M2C_FIELD(uv, f32 *, 0), M2C_FIELD(uv, f32 *, 4));
            p = (u8 *) this->unk4 + ib * 0x30;
            pb.unk0 = M2C_FIELD(p, f32 *, 0) + M2C_FIELD(p, f32 *, 0x10);
            pb.unk4 = M2C_FIELD(p, f32 *, 4) + M2C_FIELD(p, f32 *, 0x14);
            pb.unk8 = M2C_FIELD(p, f32 *, 8) + M2C_FIELD(p, f32 *, 0x18);
            MKSetPositionV(pb);
        }
        MKEnd();
    }
    MKEndPrimitive();
}

void ExplosionWarpFX::Update() {
    UpdateWarp();
}

void ExplosionWarpFX::Init() {
    s32 temp_r30_857;
    s32 temp_r30_875;
    s32 temp_r30_893;
    void *var_r3_865;
    void *var_r3_883;
    void *var_r3_901;

    this->unkC = 6;
    this->unk10 = 0x14;
    temp_r30_857 = this->unkC * this->unk10 * 0x30;
    if (MKHeap::Current() != NULL) {
        var_r3_865 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_857, NULL, 0);
    } else {
        var_r3_865 = malloc(temp_r30_857);
    }
    this->unk0 = var_r3_865;
    temp_r30_875 = this->unkC * this->unk10 * 0x30;
    if (MKHeap::Current() != NULL) {
        var_r3_883 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_875, NULL, 0);
    } else {
        var_r3_883 = malloc(temp_r30_875);
    }
    this->unk4 = var_r3_883;
    temp_r30_893 = this->unkC * this->unk10 * 8;
    if (MKHeap::Current() != NULL) {
        var_r3_901 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_893, NULL, 0);
    } else {
        var_r3_901 = malloc(temp_r30_893);
    }
    this->unk8 = var_r3_901;
    this->unk60 = (MKMaterial *) (MKMaterial_Create("fx_wobblemat"));
    BuildLocalVertexList();
    this->unk64 = 0.0f;
    this->unk68 = 0;
}
