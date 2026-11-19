#include "common/Source/MKOcean.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFFTWater.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

f64 acos(f32);                                      /* extern */
f64 pow(s32, s32, f32, M2C_UNK *, s32, s32, s32, f32, f32, f64); /* extern */
#if 0 // DRAFT: identifier 'areaList' redeclared was declared as: 'unsigned char[12]' now declared as: 'long'
extern M2C_UNK areaList;
#endif
extern u8 bWaveDataChanged;
extern s32 gViewSeed;
static M2C_UNK lit_510;                                /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_511;                                /* unable to generate initializer: unknown type; const */

void MKOcean::EndDraw(unsigned short *arg0) {

}

void MKOcean::Update() {
    ((MKFFTBaseType *) this)->Update();
    if ((u8) bWaveDataChanged != 0) {
        BuildOceanWaves();
    }
}

extern "C" f64 pow(f64, f64);
void MKOcean::BuildOceanWaves() {
    f32 arr80[4];
    f32 arr70[4];
    f32 ratio;
    f32 k;
    f32 limit;
    f32 angleBase;
    f32 angle;
    f32 cosA;
    f32 sinA;
    f32 cosB;
    f32 sinB;
    f32 freq;
    f32 dot;
    f32 absDot;
    f32 steep;
    f32 f4v;
    f32 tmp;
    f32 r1;
    f32 r2;
    f64 t0;
    f64 t1;
    f64 t2;
    s32 bits;
    s32 cls;
    s32 r0;
    s32 i;
    s32 idx;
    s32 off;
    u8 *base;

    arr80[0] = M2C_FIELD(&lit_510, f32 *, 0);
    arr80[1] = M2C_FIELD(&lit_510, f32 *, 4);
    arr80[2] = M2C_FIELD(&lit_510, f32 *, 8);
    arr80[3] = M2C_FIELD(&lit_510, f32 *, 0xC);
    arr70[0] = M2C_FIELD(&lit_511, f32 *, 0);
    arr70[1] = M2C_FIELD(&lit_511, f32 *, 4);
    arr70[2] = M2C_FIELD(&lit_511, f32 *, 8);
    arr70[3] = M2C_FIELD(&lit_511, f32 *, 0xC);

    ratio = (f32) pow(this->unk5180 / this->unk5184, 0.1428571492433548);
    k = this->unk5184;
    limit = 0.5f * (100.0f * (this->unk5184 + this->unk5180));
    angleBase = (3.1415927f * this->unk10.unk5014) / 180.0f;
    i = 0;
    off = 0;
    do {
        r1 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        r2 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        if (r2 > r1) {
            r1 = 1.0f - r1;
        }
        angle = (f32) acos(r1);
        idx = i & 3;
        freq = 6.2831855f / k;
        f4v = 0.0f;

        {
            f32 f19 = (angle * arr80[idx]) + angleBase + arr70[idx];

            cosA = _table_sinf(1.5707964f + f19);
            sinA = _table_sinf(f19);
        }
        cosB = _table_sinf(1.5707964f + angleBase);
        sinB = _table_sinf(angleBase);

        base = (u8 *) this + off;
        M2C_FIELD(base, f32 *, 0x50D0) = (f32) ((sinA * freq) / 100.0f);
        M2C_FIELD(base, f32 *, 0x50D4) = (f32) ((cosA * freq) / 100.0f);
        M2C_FIELD(base, f32 *, 0x50E0) = 100.0f * k;

        dot = (cosA * cosB) + (sinA * sinB);
        if (dot < 0.0f) {
            absDot = -dot;
        } else {
            absDot = dot;
        }

        steep = M2C_FIELD(base, f32 *, 0x50E0);
        if (limit < steep) {
            steep = limit;
        }
        M2C_FIELD(base, f32 *, 0x50D8) = (f32) (this->unk5178 * steep * this->unk10.GetDirectionScale(absDot, dot));

        f4v = this->unk10.unk5000 * freq;
        if (f4v > 0.0f) {
            t0 = __frsqrte((f64) f4v);
            t1 = 0.5 * t0 * -(((f64) f4v * (t0 * t0)) - 3.0);
            t2 = 0.5 * t1 * -(((f64) f4v * (t1 * t1)) - 3.0);
            f4v = (f32) ((f64) f4v * (0.5 * t2 * -(((f64) f4v * (t2 * t2)) - 3.0)));
        } else if (f4v < 0.0f) {
            f4v = __float_nan;
        } else {
            tmp = f4v;
            bits = *(s32 *) &tmp;
            cls = bits & 0x7F800000;
            if (cls == 0x7F800000) {
                if (bits & 0x7FFFFF) {
                    r0 = 1;
                } else {
                    r0 = 2;
                }
            } else if (cls == 0) {
                if (bits & 0x7FFFFF) {
                    r0 = 5;
                } else {
                    r0 = 3;
                }
            } else {
                r0 = 4;
            }
            if (r0 == 1) {
                f4v = __float_nan;
            }
        }
        M2C_FIELD(base, f32 *, 0x50DC) = f4v;

        i += 1;
        k *= ratio;
        off += 0x14;
    } while (i < 8);
}

void MKOcean::Deinit() {
    u8 *var_r4_328;
    u8 *var_r4_361;
    u8 *var_r6_336;

    var_r4_328 = (u8 *) M2C_FIELD(&areaList, void **, 4);
    if ((u32) var_r4_328 == M2C_FIELD(&areaList, u32 *, 8)) {
        var_r4_328 = NULL;
    }
    var_r6_336 = var_r4_328;
    while (var_r6_336 != NULL) {
        if (M2C_FIELD(var_r6_336, u32 *, 0x10) == (u32) this) {
            if (var_r6_336 != (u8 *) M2C_FIELD(&areaList, void **, 4)) {
                M2C_FIELD(var_r6_336, f32 *, 0) = M2C_FIELD(M2C_FIELD(&areaList, void **, 4), f32 *, 0);
                M2C_FIELD(var_r6_336, f32 *, 4) = M2C_FIELD(M2C_FIELD(&areaList, void **, 4), f32 *, 4);
                M2C_FIELD(var_r6_336, f32 *, 8) = M2C_FIELD(M2C_FIELD(&areaList, void **, 4), f32 *, 8);
                M2C_FIELD(var_r6_336, f32 *, 0xC) = M2C_FIELD(M2C_FIELD(&areaList, void **, 4), f32 *, 0xC);
                M2C_FIELD(var_r6_336, u32 *, 0x10) = M2C_FIELD(M2C_FIELD(&areaList, void **, 4), u32 *, 0x10);
            }
            M2C_FIELD(&areaList, void **, 4) = ((u8 *) M2C_FIELD(&areaList, void **, 4)) + 0x14;
        }
        var_r4_361 = var_r6_336 + 0x14;
        if ((u32) var_r4_361 >= M2C_FIELD(&areaList, u32 *, 8)) {
            var_r4_361 = NULL;
        }
        var_r6_336 = var_r4_361;
    }
    ((MKFFTBaseType *) this)->Deinit();
}

void MKOcean::LoadDone() {
    u8 *var_r31_392;
    f32 *temp_r3_421;
    f32 *temp_origin;
    f32 var_f0_422;
    f32 var_f0_431;
    f32 var_f2_442;
    f32 var_f2_453;
    f32 temp_f0_443;
    f32 temp_f0_454;
    f32 temp_f1_423;
    f32 temp_f1_432;
    s32 var_r30_399;
    s32 j;
    u32 *dst;
    u32 *src;

    ((MKFFTBaseType *) this)->LoadDone();
    if ((u32) M2C_FIELD(&areaList, u32 *, 0) < (u32) M2C_FIELD(&areaList, u32 *, 4)) {
        var_r31_392 = (u8 *) M2C_FIELD(&areaList, void **, 4) - 0x14;
        M2C_FIELD(&areaList, void **, 4) = var_r31_392;
    } else {
        var_r31_392 = NULL;
    }
    var_r30_399 = 0;
    M2C_FIELD(var_r31_392, f32 *, 8) = 1e8f;
    M2C_FIELD(var_r31_392, f32 *, 0) = 1e8f;
    M2C_FIELD(var_r31_392, f32 *, 0xC) = -1e8f;
    M2C_FIELD(var_r31_392, f32 *, 4) = -1e8f;
    M2C_FIELD(var_r31_392, u32 *, 0x10) = (u32) this;
    while (var_r30_399 < this->unk4) {
        if (*((u8 *) this->unk8 + var_r30_399) != 0) {
            temp_origin = (f32 *) MKModel_GetSubObjectOrigin(*(MKModel **) &this->unk0, (SubObjectType) 0, var_r30_399);
            this->unk5210 = M2C_FIELD(temp_origin, f32 *, 4);
            temp_r3_421 = (f32 *) MKModel_GetBoundingVolume(*(MKModel **) &this->unk0, (SubObjectType) 0, var_r30_399);
            var_f0_422 = M2C_FIELD(var_r31_392, f32 *, 0);
            temp_f1_423 = M2C_FIELD(temp_r3_421, f32 *, 0);
            if (!(var_f0_422 < temp_f1_423)) {
                var_f0_422 = temp_f1_423;
            }
            M2C_FIELD(var_r31_392, f32 *, 0) = var_f0_422;
            var_f0_431 = M2C_FIELD(var_r31_392, f32 *, 8);
            temp_f1_432 = M2C_FIELD(temp_r3_421, f32 *, 8);
            if (!(var_f0_431 < temp_f1_432)) {
                var_f0_431 = temp_f1_432;
            }
            M2C_FIELD(var_r31_392, f32 *, 8) = var_f0_431;
            var_f2_442 = M2C_FIELD(var_r31_392, f32 *, 4);
            temp_f0_443 = M2C_FIELD(temp_r3_421, f32 *, 0) + M2C_FIELD(temp_r3_421, f32 *, 0x10);
            if (!(var_f2_442 > temp_f0_443)) {
                var_f2_442 = temp_f0_443;
            }
            M2C_FIELD(var_r31_392, f32 *, 4) = var_f2_442;
            var_f2_453 = M2C_FIELD(var_r31_392, f32 *, 0xC);
            temp_f0_454 = M2C_FIELD(temp_r3_421, f32 *, 8) + M2C_FIELD(temp_r3_421, f32 *, 0x18);
            if (!(var_f2_453 > temp_f0_454)) {
                var_f2_453 = temp_f0_454;
            }
            M2C_FIELD(var_r31_392, f32 *, 0xC) = var_f2_453;
        }
        var_r30_399 += 1;
    }
    this->BuildOceanWaves();
    dst = (u32 *) ((u8 *) &this->unk51BC + 4);
    src = (u32 *) &Matrix::identity;
    for (j = 0; j < 0x10; j++) {
        dst[j] = src[j];
    }
    this->unk5200 = 0.0f;
}

s32 MKOcean::LoadLine(MKIniLine *arg0) {
    s32 var_r31_500;

    var_r31_500 = 0;
    if ((((MKFFTBaseType *) this)->LoadLine(arg0) != 0) || (arg0->LoadFloat("Wave1XFrequency", &this->unk50D0, 0) != 0) || (arg0->LoadFloat("Wave1ZFrequency", &this->unk50D4, 0) != 0) || (arg0->LoadFloat("SmallestWaveLength", &this->unk5180, 0) != 0) || (arg0->LoadFloat("LargestWaveLength", &this->unk5184, 0) != 0) || (arg0->LoadFloat("FadeOff", &this->unk5174, 0) != 0) || (arg0->LoadFloat("WaveHeight", &this->unk5178, 0) != 0) || (arg0->LoadFloat("heightScaler", &this->unk517C, 0) != 0) || (arg0->LoadFloat("deadDistance", &this->unk521C, 0) != 0) || (arg0->LoadBool("Enabled", (bool *) &this->unk520C, 0) != 0) || (arg0->LoadFloat("WobbleAmount", &this->unk5170, 0) != 0)) {
        var_r31_500 = 1;
    }
    return var_r31_500;
}

void MKOcean::Init(MKModel *arg0, const char *arg1, MKFFTWater *arg2) {
    s32 var_ctr_618;
    s32 var_r3_617;
    void *temp_r4_620;

    ((MKFFTBaseType *) this)->Init(arg0, arg1, this->unk5208);
    var_r3_617 = 0;
    var_ctr_618 = 8;
    do {
        temp_r4_620 = this + var_r3_617;
        var_r3_617 += 0x14;
        M2C_FIELD(temp_r4_620, f32 *, 0x50D4) = 0.01f;
        M2C_FIELD(temp_r4_620, f32 *, 0x50D0) = 0.01f;
        M2C_FIELD(temp_r4_620, f32 *, 0x50D8) = 1.0f;
        M2C_FIELD(temp_r4_620, f32 *, 0x50DC) = 1.0f;
        var_ctr_618 -= 1;
    } while (var_ctr_618 != 0);
    this->unk5180 = 0.8f;
    this->unk5184 = 10.0f;
    this->unk5178 = 0.018f;
    this->unk5174 = 0.24f;
    this->unk5170 = 0.14f;
    this->unk5204 = 0.0f;
    this->unk520C = 1;
    this->unk5210 = 0.0f;
    this->unk5214 = 50.0f;
    this->unk5218 = 0.0f;
    this->unk521C = 35.0f;
    this->unk517C = 1.0f;
}
