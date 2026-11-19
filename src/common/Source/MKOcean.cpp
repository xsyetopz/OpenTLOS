#include "common/Source/MKOcean.h"
#include "common/Source/MKFFTWater.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/Matrix.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'areaList' redeclared
f64 acos(f32);                                      /* extern */
f64 pow(s32, s32, f32, M2C_UNK *, s32, s32, s32, f32, f32, f64); /* extern */
extern M2C_UNK areaList;
#endif
extern u8 bWaveDataChanged;
extern s32 gViewSeed;
static M2C_UNK lit_510;                                /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_511;                                /* unable to generate initializer: unknown type; const */

void MKOcean::EndDraw(unsigned short *arg0) {

}

#if 0 // DRAFT: illegal use of non-static member
void MKOcean::Update() {
    MKFFTBaseType::Update();
    if ((u8) bWaveDataChanged != 0) {
        BuildOceanWaves();
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void MKOcean::BuildOceanWaves() {
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    f32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    f32 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f19_145;
    f32 temp_f1_150;
    f32 temp_f1_173;
    f32 temp_f20_148;
    f32 temp_f20_171;
    f32 temp_f21_151;
    f32 temp_f22_140;
    f32 temp_f23_112;
    f32 temp_f25_98;
    f32 temp_f2_198;
    f32 temp_f2_97;
    f32 var_f1_201;
    f32 var_f20_120;
    f32 var_f20_206;
    f32 var_f24_102;
    f32 var_f4_218;
    f64 temp_f1_221;
    f64 temp_f1_227;
    f64 temp_f1_231;
    s32 temp_r0_139;
    s32 temp_r3_250;
    s32 var_r0_260;
    s32 var_r29_110;
    u32 temp_r0_137;
    u32 temp_r3_134;
    u32 var_r31_107;
    void *temp_r26_175;

    sp80 = M2C_FIELD(&lit_510, f32 *, 0);
    sp84 = M2C_FIELD(&lit_510, s32 *, 4);
    sp88 = M2C_FIELD(&lit_510, s32 *, 8);
    sp8C = M2C_FIELD(&lit_510, s32 *, 0xC);
    sp70 = M2C_FIELD(&lit_511, f32 *, 0);
    sp74 = M2C_FIELD(&lit_511, s32 *, 4);
    sp78 = M2C_FIELD(&lit_511, s32 *, 8);
    sp7C = M2C_FIELD(&lit_511, s32 *, 0xC);
    temp_f2_97 = this->unk5184;
    temp_f25_98 = (f32) pow(M2C_FIELD(&lit_511, s32 *, 8), M2C_FIELD(&lit_511, s32 *, 4), M2C_FIELD(&lit_511, f32 *, 0), &lit_511, M2C_FIELD(&lit_510, s32 *, 0xC), M2C_FIELD(&lit_510, s32 *, 8), M2C_FIELD(&lit_510, s32 *, 4), M2C_FIELD(&lit_510, f32 *, 0), this->unk5180 / this->unk5184, 0.1428571492433548);
    var_f24_102 = temp_f2_97;
    var_r31_107 = 0;
    var_r29_110 = 0;
    temp_f23_112 = 0.5f * (100.0f * (temp_f2_97 + this->unk5180));
    do {
        var_f20_120 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        if (MKRand_Float(&gViewSeed, 0.0f, 1.0f) > var_f20_120) {
            var_f20_120 = 1.0f - var_f20_120;
        }
        temp_r3_134 = var_r31_107 >> 0x1FU;
        temp_r0_137 = (var_r31_107 << 0x1E) - temp_r3_134;
        temp_r0_139 = ((temp_r0_137 << 2) | (temp_r0_137 >> 0x1EU)) + temp_r3_134;
        temp_f22_140 = (3.1415927f * this->unk10.unk5014) / 180.0f;
        temp_f19_145 = ((f32) acos(var_f20_120) * (&sp80)[temp_r0_139]) + temp_f22_140 + (&sp70)[temp_r0_139];
        temp_f20_148 = _table_sinf(1.5707964f + temp_f19_145);
        temp_f1_150 = _table_sinf(temp_f19_145);
        temp_f21_151 = 6.2831855f / var_f24_102;
        sp38 = temp_f20_148;
        sp30 = temp_f1_150;
        sp34 = 0.0f;
        sp60 = (f64) sp30;
        sp68 = (f64) sp38;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f21 */);
        sp50 = sp20;
        sp28 = (f32) sp68 * temp_f21_151;
        sp58 = (f64) sp28;
        temp_f20_171 = _table_sinf(1.5707964f + temp_f22_140);
        temp_f1_173 = _table_sinf(temp_f22_140);
        temp_r26_175 = this + var_r29_110;
        sp18 = temp_f20_171;
        sp10 = temp_f1_173;
        sp14 = 0.0f;
        sp48 = (f64) sp18;
        sp40 = (f64) sp10;
        M2C_FIELD(temp_r26_175, f32 *, 0x50D0) = (f32) ((f32) sp50 / 100.0f);
        M2C_FIELD(temp_r26_175, f32 *, 0x50D4) = (f32) ((f32) sp58 / 100.0f);
        M2C_FIELD(temp_r26_175, f32 *, 0x50E0) = (f32) (100.0f * var_f24_102);
        temp_f2_198 = ((f32) sp68 * (f32) sp48) + (((f32) sp60 * (f32) sp40) + (unksp64 * unksp44));
        if (temp_f2_198 < 0.0f) {
            var_f1_201 = -temp_f2_198;
        } else {
            var_f1_201 = temp_f2_198;
        }
        var_f20_206 = M2C_FIELD(temp_r26_175, f32 *, 0x50E0);
        if (temp_f23_112 < var_f20_206) {
            var_f20_206 = temp_f23_112;
        }
        M2C_FIELD(temp_r26_175, f32 *, 0x50D8) = (f32) (this->unk5178 * var_f20_206 * this->unk10.GetDirectionScale(var_f1_201, temp_f2_198));
        var_f4_218 = this->unk10.unk5000 * temp_f21_151;
        if (var_f4_218 > 0.0f) {
            temp_f1_221 = __frsqrte(var_f4_218);
            temp_f1_227 = 0.5 * temp_f1_221 * -(((f64) var_f4_218 * (temp_f1_221 * temp_f1_221)) - 3.0);
            temp_f1_231 = 0.5 * temp_f1_227 * -(((f64) var_f4_218 * (temp_f1_227 * temp_f1_227)) - 3.0);
            var_f4_218 = (f32) ((f64) var_f4_218 * (0.5 * temp_f1_231 * -(((f64) var_f4_218 * (temp_f1_231 * temp_f1_231)) - 3.0)));
        } else if (var_f4_218 < M2C_BITWISE(f32, 0.0)) {
            var_f4_218 = __float_nan;
        } else {
            sp8 = var_f4_218;
            temp_r3_250 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_250) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_260 = 1;
                } else {
                    var_r0_260 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_260 = 5;
                } else {
                    var_r0_260 = 3;
                }
                break;
            default:
                var_r0_260 = 4;
                break;
            }
            if (var_r0_260 == 1) {
                var_f4_218 = __float_nan;
            }
        }
        var_r31_107 += 1;
        var_f24_102 *= temp_f25_98;
        M2C_FIELD(temp_r26_175, f32 *, 0x50DC) = var_f4_218;
        var_r29_110 += 0x14;
    } while ((s32) var_r31_107 < 8);
}
#endif

#if 0 // DRAFT: illegal operand
void MKOcean::Deinit() {
    void *var_r4_328;
    void *var_r4_361;
    void *var_r6_336;

    var_r4_328 = M2C_FIELD(&areaList, void **, 4);
    if (var_r4_328 != (u32) M2C_FIELD(&areaList, u32 *, 8)) {

    } else {
        var_r4_328 = NULL;
    }
    var_r6_336 = var_r4_328;
loop_11:
    if (var_r6_336 != NULL) {
        if ((u32) M2C_FIELD(var_r6_336, u32 *, 0x10) == this) {
            if (var_r6_336 != (void *) M2C_FIELD(&areaList, void **, 4)) {
                M2C_FIELD(var_r6_336, f32 *, 0) = (f32) M2C_FIELD(M2C_FIELD(&areaList, void **, 4), f32 *, 0);
                M2C_FIELD(var_r6_336, f32 *, 4) = (f32) M2C_FIELD(M2C_FIELD(&areaList, void **, 4), f32 *, 4);
                M2C_FIELD(var_r6_336, f32 *, 8) = (f32) M2C_FIELD(M2C_FIELD(&areaList, void **, 4), f32 *, 8);
                M2C_FIELD(var_r6_336, f32 *, 0xC) = (f32) M2C_FIELD(M2C_FIELD(&areaList, void **, 4), f32 *, 0xC);
                M2C_FIELD(var_r6_336, u32 *, 0x10) = (u32) M2C_FIELD(M2C_FIELD(&areaList, void **, 4), u32 *, 0x10);
            }
            M2C_FIELD(&areaList, void **, 4) = (void *) (M2C_FIELD(&areaList, void **, 4) + 0x14);
        }
        var_r4_361 = var_r6_336 + 0x14;
        if (var_r4_361 >= (u32) M2C_FIELD(&areaList, u32 *, 8)) {
            var_r4_361 = NULL;
        }
        var_r6_336 = var_r4_361;
        goto loop_11;
    }
    MKFFTBaseType::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void MKOcean::LoadDone() {
    MKHeap **temp_r3_421;
    f32 temp_f0_443;
    f32 temp_f0_454;
    f32 temp_f1_423;
    f32 temp_f1_432;
    f32 var_f0_422;
    f32 var_f0_431;
    f32 var_f2_442;
    f32 var_f2_453;
    s32 var_r30_399;
    void *var_r31_392;

    MKFFTBaseType::LoadDone();
    if ((u32) M2C_FIELD(&areaList, u32 *, 0) < (void *) M2C_FIELD(&areaList, void **, 4)) {
        var_r31_392 = M2C_FIELD(&areaList, void **, 4) - 0x14;
        M2C_FIELD(&areaList, void **, 4) = var_r31_392;
    } else {
        var_r31_392 = NULL;
    }
    var_r30_399 = 0;
    M2C_FIELD(var_r31_392, f32 *, 8) = 1e8f;
    M2C_FIELD(var_r31_392, f32 *, 0) = 1e8f;
    M2C_FIELD(var_r31_392, f32 *, 0xC) = -1e8f;
    M2C_FIELD(var_r31_392, f32 *, 4) = -1e8f;
    M2C_FIELD(var_r31_392, MKOcean **, 0x10) = this;
loop_19:
    if (var_r30_399 < (s32) this->unk4) {
        if ((u8) *(this->unk8 + var_r30_399) != 0) {
            this->unk5210 = M2C_FIELD(MKModel_GetSubObjectOrigin(M2C_FIELD(this, MKModel **, 0), (SubObjectType) 0, var_r30_399), f32 *, 4);
            temp_r3_421 = MKModel_GetBoundingVolume(M2C_FIELD(this, MKModel **, 0), (SubObjectType) 0, var_r30_399);
            var_f0_422 = M2C_FIELD(var_r31_392, f32 *, 0);
            temp_f1_423 = M2C_FIELD(temp_r3_421, f32 *, 0);
            if (var_f0_422 < temp_f1_423) {

            } else {
                var_f0_422 = temp_f1_423;
            }
            M2C_FIELD(var_r31_392, f32 *, 0) = var_f0_422;
            var_f0_431 = M2C_FIELD(var_r31_392, f32 *, 8);
            temp_f1_432 = M2C_FIELD(temp_r3_421, f32 *, 8);
            if (var_f0_431 < temp_f1_432) {

            } else {
                var_f0_431 = temp_f1_432;
            }
            M2C_FIELD(var_r31_392, f32 *, 8) = var_f0_431;
            var_f2_442 = M2C_FIELD(var_r31_392, f32 *, 4);
            temp_f0_443 = M2C_BITWISE(f32, M2C_FIELD(temp_r3_421, MKHeap **, 0)) + M2C_FIELD(temp_r3_421, f32 *, 0x10);
            if (var_f2_442 > temp_f0_443) {

            } else {
                var_f2_442 = temp_f0_443;
            }
            M2C_FIELD(var_r31_392, f32 *, 4) = var_f2_442;
            var_f2_453 = M2C_FIELD(var_r31_392, f32 *, 0xC);
            temp_f0_454 = M2C_FIELD(temp_r3_421, f32 *, 8) + M2C_FIELD(temp_r3_421, f32 *, 0x18);
            if (var_f2_453 > temp_f0_454) {

            } else {
                var_f2_453 = temp_f0_454;
            }
            M2C_FIELD(var_r31_392, f32 *, 0xC) = var_f2_453;
        }
        var_r30_399 += 1;
        goto loop_19;
    }
    BuildOceanWaves();
    M2C_STRUCT_COPY((s32) &this->unk51BC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    this->unk5200 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 MKOcean::LoadLine(MKIniLine *arg0) {
    s32 var_r31_500;

    var_r31_500 = 0;
    if ((MKFFTBaseType::LoadLine(arg0) != 0) || (arg0->LoadFloat("Wave1XFrequency", &this->unk50D0, 0) != 0) || (arg0->LoadFloat("Wave1ZFrequency", &this->unk50D4, 0) != 0) || (arg0->LoadFloat("SmallestWaveLength", &this->unk5180, 0) != 0) || (arg0->LoadFloat("LargestWaveLength", &this->unk5184, 0) != 0) || (arg0->LoadFloat("FadeOff", &this->unk5174, 0) != 0) || (arg0->LoadFloat("WaveHeight", &this->unk5178, 0) != 0) || (arg0->LoadFloat("heightScaler", &this->unk517C, 0) != 0) || (arg0->LoadFloat("deadDistance", &this->unk521C, 0) != 0) || (arg0->LoadBool("Enabled", &this->unk520C, 0) != 0) || (arg0->LoadFloat("WobbleAmount", &this->unk5170, 0) != 0)) {
        var_r31_500 = 1;
    }
    return var_r31_500;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void MKOcean::Init(MKModel *arg0, const char *arg1, MKFFTWater *arg2) {
    s32 var_ctr_618;
    s32 var_r3_617;
    void *temp_r4_620;

    MKFFTBaseType::Init(arg0, arg1, this->unk5208);
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
#endif
