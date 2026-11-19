#include "spyro/source/ShotgunWarpFX.h"
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
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 gUpdateTimeDelta;

static s32 lit_555 = 0;

void ShotgunWarpFX::UpdateWarp() {
    M2C_UNK sp6C;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 p0;
    f32 p1;
    f32 p2;
    f32 var_f0_28;
    f32 var_f0_46;
    f32 x;
    f32 y;
    f32 z;
    s32 i;
    s32 j;
    s32 off;
    s32 count;
    u8 *vtx;
    u8 *vtx4;

    var_f0_28 = this->unk68 - gUpdateTimeDelta;
    if (var_f0_28 < 0.65f) {

    } else {
        var_f0_28 = 0.65f;
    }
    if (var_f0_28 > 0.0f) {

    } else {
        var_f0_28 = 0.0f;
    }
    this->unk68 = var_f0_28;
    var_f0_46 = this->unk6C - gUpdateTimeDelta;
    if (var_f0_46 < 0.175f) {

    } else {
        var_f0_46 = 0.175f;
    }
    if (var_f0_46 > 0.0f) {

    } else {
        var_f0_46 = 0.0f;
    }
    this->unk6C = var_f0_46;
    if (!(this->unk68 <= 0.0f)) {
        this->unk74 += 1;
        *(Matrix *) ((u8 *) &sp6C + 4) = *(Matrix *) ((u8 *) &this->unk1C + 4);
        M2C_FIELD(&sp6C, f32 *, 0x34) = 0.0f;
        M2C_FIELD(&sp6C, f32 *, 0x38) = 0.0f;
        M2C_FIELD(&sp6C, f32 *, 0x3C) = 0.0f;
        M2C_FIELD(&sp6C, f32 *, 0x40) = 1.0f;
        if (this->unk74 < this->unkC) {
            for (j = 0; j < this->unk10; j++) {
                off = (j + (this->unk74 * this->unk10)) * 0x30;
                vtx = (u8 *) this->unk0 + off + 0x20;
                x = M2C_FIELD(vtx, f32 *, 0);
                y = M2C_FIELD(vtx, f32 *, 4);
                z = M2C_FIELD(vtx, f32 *, 8);
                sp10 = 0.0f + ((z * M2C_FIELD(&sp6C, f32 *, 0x24)) + ((x * M2C_FIELD(&sp6C, f32 *, 4)) + (y * M2C_FIELD(&sp6C, f32 *, 0x14))));
                sp14 = 0.0f + ((z * M2C_FIELD(&sp6C, f32 *, 0x28)) + ((x * M2C_FIELD(&sp6C, f32 *, 8)) + (y * M2C_FIELD(&sp6C, f32 *, 0x18))));
                sp18 = 0.0f + ((z * M2C_FIELD(&sp6C, f32 *, 0x2C)) + ((x * M2C_FIELD(&sp6C, f32 *, 0xC)) + (y * M2C_FIELD(&sp6C, f32 *, 0x1C))));
                vtx4 = (u8 *) this->unk4 + off + 0x20;
                p0 = sp10 * 10000.0f;
                p1 = sp14 * 10000.0f;
                p2 = sp18 * 10000.0f;
                M2C_FIELD(vtx4, f32 *, 0) = M2C_FIELD(vtx4, f32 *, 0) + p0;
                M2C_FIELD(vtx4, f32 *, 4) = M2C_FIELD(vtx4, f32 *, 4) + p1;
                M2C_FIELD(vtx4, f32 *, 8) = M2C_FIELD(vtx4, f32 *, 8) + p2;
            }
        }
        count = this->unkC * this->unk10;
        off = 0;
        for (i = 0; i < count; i++) {
            vtx = (u8 *) this->unk4 + off;
            M2C_FIELD(vtx, f32 *, 0x10) = M2C_FIELD(vtx, f32 *, 0x10) + (M2C_FIELD(vtx, f32 *, 0x20) * gUpdateTimeDelta);
            M2C_FIELD(vtx, f32 *, 0x14) = M2C_FIELD(vtx, f32 *, 0x14) + (M2C_FIELD(vtx, f32 *, 0x24) * gUpdateTimeDelta);
            M2C_FIELD(vtx, f32 *, 0x18) = M2C_FIELD(vtx, f32 *, 0x18) + (M2C_FIELD(vtx, f32 *, 0x28) * gUpdateTimeDelta);
            M2C_FIELD(vtx, f32 *, 0x10) = M2C_FIELD(vtx, f32 *, 0x10) * 0.25f;
            M2C_FIELD(vtx, f32 *, 0x14) = M2C_FIELD(vtx, f32 *, 0x14) * 0.25f;
            M2C_FIELD(vtx, f32 *, 0x18) = M2C_FIELD(vtx, f32 *, 0x18) * 0.25f;
            M2C_FIELD(vtx, f32 *, 0x20) = M2C_FIELD(vtx, f32 *, 0x20) * 0.75f;
            M2C_FIELD(vtx, f32 *, 0x24) = M2C_FIELD(vtx, f32 *, 0x24) * 0.75f;
            M2C_FIELD(vtx, f32 *, 0x28) = M2C_FIELD(vtx, f32 *, 0x28) * 0.75f;
            x = M2C_FIELD(vtx, f32 *, 0x20);
            y = M2C_FIELD(vtx, f32 *, 0x24);
            z = M2C_FIELD(vtx, f32 *, 0x28);
            if (((z * z) + ((x * x) + (y * y))) > 100.0f) {
                M2C_FIELD(vtx, f32 *, 0x20) = 0.0f;
                M2C_FIELD(vtx, f32 *, 0x24) = 0.0f;
                M2C_FIELD(vtx, f32 *, 0x28) = 0.0f;
            }
            off += 0x30;
        }
    }
}

void ShotgunWarpFX::StartWarp(Matrix *arg0) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_289;
    f32 temp_f3_288;
    f32 temp_f4_276;
    f32 temp_f5_287;
    f32 temp_f7_281;
    f32 temp_f8_290;
    s32 temp_r0_266;
    s32 temp_r7_271;
    s32 temp_r8_273;
    s32 var_ctr_267;
    s32 var_r5_263;
    void *temp_r6_278;
    void *temp_r7_313;
    void *temp_r8_319;
    void *temp_r9_274;

    M2C_STRUCT_COPY((s32) &this->unk1C + 4, (s32) (arg0 - 4) + 4, 0x40);
    var_r5_263 = 0;
    temp_r0_266 = this->unkC * this->unk10;
    var_ctr_267 = temp_r0_266;
    if (temp_r0_266 > 0) {
        do {
            temp_r7_271 = var_r5_263 + 0x10;
            temp_r8_273 = var_r5_263 + 0x20;
            temp_r9_274 = ((u8 *) this->unk0) + var_r5_263;
            temp_f4_276 = M2C_FIELD(temp_r9_274, f32 *, 4);
            temp_r6_278 = ((u8 *) this->unk4) + var_r5_263;
            temp_f7_281 = M2C_FIELD(temp_r9_274, f32 *, 0);
            temp_f5_287 = (temp_f7_281 * arg0->unk0) + (temp_f4_276 * arg0->unk10);
            temp_f3_288 = (temp_f7_281 * arg0->unk4) + (temp_f4_276 * arg0->unk14);
            temp_f1_289 = (temp_f7_281 * arg0->unk8) + (temp_f4_276 * arg0->unk18);
            temp_f8_290 = M2C_FIELD(temp_r9_274, f32 *, 8);
            var_r5_263 += 0x30;
            sp8 = arg0->unk30 + ((temp_f8_290 * arg0->unk20) + temp_f5_287);
            spC = arg0->unk34 + ((temp_f8_290 * arg0->unk24) + temp_f3_288);
            sp10 = arg0->unk38 + ((temp_f8_290 * arg0->unk28) + temp_f1_289);
            M2C_FIELD(temp_r6_278, f64 *, 0) = (f64) sp8;
            M2C_FIELD(temp_r6_278, f64 *, 8) = (f64) sp10;
            sp18 = (f64) sp8;
            temp_r7_313 = ((u8 *) this->unk4) + temp_r7_271;
            M2C_FIELD(temp_r7_313, f32 *, 0) = 0.0f;
            M2C_FIELD(temp_r7_313, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r7_313, f32 *, 8) = 0.0f;
            sp20 = (f64) sp10;
            temp_r8_319 = ((u8 *) this->unk4) + temp_r8_273;
            M2C_FIELD(temp_r8_319, f32 *, 0) = 0.0f;
            M2C_FIELD(temp_r8_319, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r8_319, f32 *, 8) = 0.0f;
            var_ctr_267 -= 1;
        } while (var_ctr_267 != 0);
    }
    this->unk68 = 0.65f;
    this->unk6C = 0.175f;
    this->unk70 = 1;
    this->unk74 = 0;
}

void ShotgunWarpFX::BuildLocalVertexList() {
    f64 g1;
    f64 g2;
    f64 g3;
    f64 d0;
    f64 d1;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    f32 f24;
    f32 len2;
    f32 inv;
    f32 x;
    f32 y;
    f32 z;
    s32 i;
    s32 j;
    s32 off;
    s32 kind;
    u8 *vtx;

    i = 0;
    f24 = 1500.0f / (f32) this->unkC;
    f23 = 795.0f / (f32) this->unkC;
    f22 = 6.2831855f / (f32) (this->unk10 - 1);
    while (i < (s32) this->unkC) {
        j = 0;
        f21 = (f23 * (f32) i) + 5.0f;
        while (j < this->unk10) {
            f20 = f22 * (f32) j;
            sp14 = 0.45f * (f21 * -_table_sinf(1.5707964f + f20));
            sp10 = f21 * _table_sinf(f20);
            sp18 = -(f24 * (f32) i);
            off = (j + (i * this->unk10)) * 0x30;
            vtx = (u8 *) this->unk0 + off;
            sp28 = (f64) sp18;
            M2C_FIELD(vtx, f64 *, 0) = (f64) sp10;
            M2C_FIELD(vtx, f64 *, 8) = (f64) sp18;
            sp20 = (f64) sp10;
            d0 = M2C_FIELD(vtx, f64 *, 0);
            d1 = M2C_FIELD(vtx, f64 *, 8);
            M2C_FIELD(vtx, f64 *, 0x20) = d0;
            M2C_FIELD(vtx, f64 *, 0x28) = d1;
            M2C_FIELD(vtx, f32 *, 0x28) = 0.0f;
            x = M2C_FIELD(vtx, f32 *, 0x20);
            y = M2C_FIELD(vtx, f32 *, 0x24);
            z = M2C_FIELD(vtx, f32 *, 0x28);
            len2 = (z * z) + ((x * x) + (y * y));
            if (len2 > 0.000001f) {
                if (len2 > 0.0f) {
                    g1 = __frsqrte(len2);
                    g2 = 0.5 * g1 * -(((f64) len2 * (g1 * g1)) - 3.0);
                    g3 = 0.5 * g2 * -(((f64) len2 * (g2 * g2)) - 3.0);
                    len2 = (f32) ((f64) len2 * (0.5 * g3 * -(((f64) len2 * (g3 * g3)) - 3.0)));
                } else if (len2 < M2C_BITWISE(f32, 0.0)) {
                    len2 = __float_nan;
                } else {
                    sp8 = len2;
                    switch (*(s32 *) &sp8 & 0x7F800000) {
                    case 0x7F800000:
                        if (*(s32 *) &sp8 & 0x7FFFFF) {
                            kind = 1;
                        } else {
                            kind = 2;
                        }
                        break;
                    case 0x0:
                        if (*(s32 *) &sp8 & 0x7FFFFF) {
                            kind = 5;
                        } else {
                            kind = 3;
                        }
                        break;
                    default:
                        kind = 4;
                        break;
                    }
                    if (kind == 1) {
                        len2 = __float_nan;
                    }
                }
                inv = 1.0f / len2;
            } else {
                inv = 0.0f;
            }
            M2C_FIELD(vtx, f32 *, 0x20) = (f32) (M2C_FIELD(vtx, f32 *, 0x20) * inv);
            M2C_FIELD(vtx, f32 *, 0x24) = (f32) (M2C_FIELD(vtx, f32 *, 0x24) * inv);
            M2C_FIELD(vtx, f32 *, 0x28) = (f32) (M2C_FIELD(vtx, f32 *, 0x28) * inv);
            j += 1;
        }
        i += 1;
    }
}

void ShotgunWarpFX::Deinit() {
    void *temp_r31_597;
    void *temp_r31_611;
    void *temp_r31_625;

    MKMaterial_Destroy(this->unk60);
    MKMaterial_Destroy(this->unk64);
    temp_r31_597 = this->unk0;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_597, NULL, 0);
    } else {
        free(temp_r31_597);
    }
    temp_r31_611 = this->unk4;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_611, NULL, 0);
    } else {
        free(temp_r31_611);
    }
    temp_r31_625 = this->unk8;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_625, NULL, 0);
        return;
    }
    free(temp_r31_625);
}

void ShotgunWarpFX::Draw() {
    Matrix spC0;
    MKVector3 spB0;
    MKVector3 pos;
    MKVector4 col;
    f32 alpha;
    f32 t;
    f32 temp;
    s32 count;
    s32 i;
    s32 j;
    s32 k;
    s32 row;
    s32 c;
    s32 a;
    s32 b;
    s32 n;
    s32 lo;
    u8 *vtx;

    if (!(this->unk68 <= 0.0f)) {
        MKMaterial_SetMaterial(this->unk60);
        MKPrimitive(0xC, 0x10);
        MKSetMatrix(Matrix::identity);
        t = this->unk68;
        count = this->unkC * this->unk10;
        alpha = 1.0f;
        if (t < 0.325f) {
            alpha = t / 0.325f;
        }
        spC0 = *MKView_GetWorldToScreenMatrix();
        i = 0;
        j = 0;
        k = 0;
        for (i = 0; i < count; i++) {
            Xform3D2D(&spB0, *(MKVector3 *) ((u8 *) this->unk4 + k), &spC0);
            temp = spB0.unk0;
            if (temp < 1.0f) {

            } else {
                temp = 1.0f;
            }
            if (temp > 0.0f) {

            } else {
                temp = 0.0f;
            }
            *(f32 *) ((u8 *) this->unk8 + j) = temp;
            temp = spB0.unk4;
            if (temp < 1.0f) {

            } else {
                temp = 1.0f;
            }
            if (temp > 0.0f) {

            } else {
                temp = 0.0f;
            }
            k += 0x30;
            j += 8;
            *(f32 *) ((u8 *) this->unk8 + (j - 8 + 4)) = temp;
        }
        for (row = 0; row < (s32) (this->unkC - 1); row++) {
            MKBegin(this->unk10 * 2);
            for (c = 0; c < this->unk10; c++) {
                a = c + (row * this->unk10);
                b = c + ((row + 1) * this->unk10);
                MKSetColorF(1.0f, 1.0f, 1.0f, alpha);
                MKSetTexCoord1F(*(f32 *) ((u8 *) this->unk8 + (a * 8)), *(f32 *) ((u8 *) this->unk8 + (a * 8) + 4));
                vtx = (u8 *) this->unk4 + (a * 0x30);
                pos.unk0 = M2C_FIELD(vtx, f32 *, 0) + M2C_FIELD(vtx, f32 *, 0x10);
                pos.unk4 = M2C_FIELD(vtx, f32 *, 4) + M2C_FIELD(vtx, f32 *, 0x14);
                pos.unk8 = M2C_FIELD(vtx, f32 *, 8) + M2C_FIELD(vtx, f32 *, 0x18);
                MKSetPositionV(pos);
                MKSetColorF(1.0f, 1.0f, 1.0f, alpha);
                MKSetTexCoord1F(*(f32 *) ((u8 *) this->unk8 + (b * 8)), *(f32 *) ((u8 *) this->unk8 + (b * 8) + 4));
                vtx = (u8 *) this->unk4 + (b * 0x30);
                pos.unk0 = M2C_FIELD(vtx, f32 *, 0) + M2C_FIELD(vtx, f32 *, 0x10);
                pos.unk4 = M2C_FIELD(vtx, f32 *, 4) + M2C_FIELD(vtx, f32 *, 0x14);
                pos.unk8 = M2C_FIELD(vtx, f32 *, 8) + M2C_FIELD(vtx, f32 *, 0x18);
                MKSetPositionV(pos);
            }
            MKEnd();
        }
        MKEndPrimitive();
        temp = this->unk6C;
        if ((temp > 0.0f) || ((u8) this->unk70 != 0)) {
            if (temp <= 0.0f) {
                this->unk70 = 0;
            }
            MKMaterial_SetMaterial(this->unk64);
            MKPrimitive(0xC, 0x10);
            MKSetMatrix(Matrix::identity);
            col.unk0 = this->unk78 * alpha;
            col.unk4 = this->unk7C * alpha;
            col.unk8 = this->unk80 * alpha;
            col.unkC = alpha;
            n = this->unkC - 2;
            lo = (s32) ((f32) n * (1.0f - (this->unk6C / 0.175f)));
            if (lo < n) {
                n = lo;
            }
            lo = lit_555;
            if (n > lo) {
                lo = n;
            }
            MKBegin(this->unk10 * 2);
            for (k = 0; k < this->unk10; k++) {
                t = 6.0f * ((f32) k / (f32) this->unk10);
                MKSetColorV(col);
                MKSetTexCoord1F(t, 0.95f);
                vtx = (u8 *) this->unk4 + ((k + (lo * this->unk10)) * 0x30);
                pos.unk0 = M2C_FIELD(vtx, f32 *, 0) + M2C_FIELD(vtx, f32 *, 0x10);
                pos.unk4 = M2C_FIELD(vtx, f32 *, 4) + M2C_FIELD(vtx, f32 *, 0x14);
                pos.unk8 = M2C_FIELD(vtx, f32 *, 8) + M2C_FIELD(vtx, f32 *, 0x18);
                MKSetPositionV(pos);
                MKSetColorV(col);
                MKSetTexCoord1F(t, 0.05f);
                vtx = (u8 *) this->unk4 + ((k + ((lo + 1) * this->unk10)) * 0x30);
                pos.unk0 = M2C_FIELD(vtx, f32 *, 0) + M2C_FIELD(vtx, f32 *, 0x10);
                pos.unk4 = M2C_FIELD(vtx, f32 *, 4) + M2C_FIELD(vtx, f32 *, 0x14);
                pos.unk8 = M2C_FIELD(vtx, f32 *, 8) + M2C_FIELD(vtx, f32 *, 0x18);
                MKSetPositionV(pos);
            }
            MKEnd();
            MKEndPrimitive();
        }
    }
}

f32 Xform3D2D(MKVector3 *arg0, const MKVector3 &arg1, Matrix *arg2) {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_1057;
    f32 temp_f4_1043;
    f32 var_f0_1093;
    f32 var_f0_1112;

    sp38 = arg1.unk0;
    sp3C = arg1.unk4;
    sp40 = arg1.unk8;
    sp78 = (f64) sp38;
    sp44 = 1.0f;
    sp80 = (f64) sp40;
    sp30 = ((*(f32 *) ((u8 *) &sp80 + 0x4)) * arg2->unk38) + (((f32) sp80 * arg2->unk28) + (((f32) sp78 * arg2->unk8) + ((*(f32 *) ((u8 *) &sp78 + 0x4)) * arg2->unk18)));
    temp_f4_1043 = ((*(f32 *) ((u8 *) &sp80 + 0x4)) * arg2->unk34) + (((f32) sp80 * arg2->unk24) + (((f32) sp78 * arg2->unk4) + ((*(f32 *) ((u8 *) &sp78 + 0x4)) * arg2->unk14)));
    sp34 = ((*(f32 *) ((u8 *) &sp80 + 0x4)) * arg2->unk3C) + (((f32) sp80 * arg2->unk2C) + (((f32) sp78 * arg2->unkC) + ((*(f32 *) ((u8 *) &sp78 + 0x4)) * arg2->unk1C)));
    sp28 = ((*(f32 *) ((u8 *) &sp80 + 0x4)) * arg2->unk30) + (((f32) sp80 * arg2->unk20) + (((f32) sp78 * arg2->unk0) + ((*(f32 *) ((u8 *) &sp78 + 0x4)) * arg2->unk10)));
    sp80 = (f64) sp30;
    sp2C = temp_f4_1043;
    sp70 = (f64) sp30;
    sp68 = (f64) sp28;
    sp78 = (f64) sp28;
    if ((*(f32 *) ((u8 *) &sp80 + 0x4)) != 0.0f) {
        temp_f2_1057 = 1.0f / (*(f32 *) ((u8 *) &sp80 + 0x4));
        sp18 = sp78 * (f64) temp_f2_1057;
        M2C_FIELD(arg0, f64 *, 0) = sp18;
        sp20 = (f32) sp80 * temp_f2_1057;
        sp58 = sp18;
        sp60 = (f64) sp20;
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp20;
    }
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 0.0f;
    sp48 = (f64) sp8;
    sp50 = (f64) sp10;
    M2C_FIELD(arg0, f64 *, 0) = (f64) (M2C_FIELD(arg0, f64 *, 0) + sp48);
    arg0->unk8 += (f32) sp50;
    var_f0_1093 = 0.5f * arg0->unk0;
    if (var_f0_1093 < 1.0f) {

    } else {
        var_f0_1093 = 1.0f;
    }
    if (var_f0_1093 > 0.0f) {

    } else {
        var_f0_1093 = 0.0f;
    }
    arg0->unk0 = var_f0_1093;
    var_f0_1112 = -((0.5f * arg0->unk4) - 1.0f);
    if (var_f0_1112 < 1.0f) {

    } else {
        var_f0_1112 = 1.0f;
    }
    if (var_f0_1112 > 0.0f) {

    } else {
        var_f0_1112 = 0.0f;
    }
    arg0->unk4 = var_f0_1112;
    return (*(f32 *) ((u8 *) &sp80 + 0x4));
}

void ShotgunWarpFX::Update() {
    UpdateWarp();
}

void ShotgunWarpFX::Init() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 temp_r30_1160;
    s32 temp_r30_1178;
    s32 temp_r30_1196;
    void *var_r3_1168;
    void *var_r3_1186;
    void *var_r3_1204;

    this->unkC = 6;
    this->unk10 = 0x14;
    temp_r30_1160 = this->unkC * this->unk10 * 0x30;
    if (MKHeap::Current() != NULL) {
        var_r3_1168 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1160, NULL, 0);
    } else {
        var_r3_1168 = malloc(temp_r30_1160);
    }
    this->unk0 = var_r3_1168;
    temp_r30_1178 = this->unkC * this->unk10 * 0x30;
    if (MKHeap::Current() != NULL) {
        var_r3_1186 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1178, NULL, 0);
    } else {
        var_r3_1186 = malloc(temp_r30_1178);
    }
    this->unk4 = var_r3_1186;
    temp_r30_1196 = this->unkC * this->unk10 * 8;
    if (MKHeap::Current() != NULL) {
        var_r3_1204 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1196, NULL, 0);
    } else {
        var_r3_1204 = malloc(temp_r30_1196);
    }
    this->unk8 = var_r3_1204;
    this->unk60 = (MKMaterial *) (MKMaterial_Create("fx_wobblemat"));
    BuildLocalVertexList();
    this->unk68 = 0.0f;
    this->unk6C = 0.0f;
    sp8 = 0.5f;
    spC = 1.0f;
    this->unk74 = 0;
    sp10 = 0.5f;
    sp14 = 1.0f;
    M2C_FIELD(this, f64 *, 0x78) = (f64) sp8;
    M2C_FIELD(this, f64 *, 0x80) = (f64) sp10;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk70 = 0;
    this->unk64 = (MKMaterial *) (MKMaterial_Create("fx_359"));
}
