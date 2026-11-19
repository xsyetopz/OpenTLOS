#include "spyro/source/SplineTools.h"
#include "common/Source/MKHeap.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDSpline.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 *KDSpline_PositionMixer;
extern f32 *KDSpline_VelocityMixer;
static s32 lit_603 = 0;
static s32 lit_606 = 0;

#if 0 // DRAFT: illegal type
Matrix **SplitPath::GetPathData(float arg0, float *arg1) {
    f32 temp_f0_23;
    f32 temp_f3_19;
    f32 temp_f4_30;
    s32 temp_r0_11;
    s32 var_ctr_13;
    s32 var_r5_12;
    void *temp_r6_18;

    temp_r0_11 = this->unk4;
    var_r5_12 = 0;
    var_ctr_13 = temp_r0_11;
    if (temp_r0_11 > 0) {
loop_1:
        temp_r6_18 = this->unk0 + var_r5_12;
        temp_f3_19 = M2C_FIELD(temp_r6_18, f32 *, 0xC);
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (arg0 == temp_f3_19) {
            temp_f0_23 = M2C_FIELD(temp_r6_18, f32 *, 0x10);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (arg0 == temp_f0_23) {
                if (arg1 != NULL) {
                    temp_f4_30 = M2C_FIELD(temp_r6_18, f32 *, 4);
                    *arg1 = (((arg0 - temp_f3_19) / (temp_f0_23 - temp_f3_19)) * (M2C_FIELD(temp_r6_18, f32 *, 8) - temp_f4_30)) + temp_f4_30;
                }
                return this->unk0 + var_r5_12;
            }
        }
        var_r5_12 += 0x14;
        var_ctr_13 -= 1;
        if (var_ctr_13 == 0) {
            /* Duplicate return node #7. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_1;
    }
    return NULL;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to
void SplitPath::GetVelocity(float arg0) {
    KDUniformSpline sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 spC;
    f32 sp8;
    Matrix *temp_r4_62;

    temp_r4_62 = *((SplitPath *) (M2C_ERROR(/* Read from unset register $r4 */)))->GetPathData(arg0, &spC);
    sp8 = 0.0f;
    sp30.GetMeasure(spC, temp_r4_62, KDSpline_VelocityMixer);
    sp20 = M2C_BITWISE(f64, sp30);
    sp28 = (f64) sp30.unk8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    M2C_FIELD(this, f64 *, 0) = sp10;
    sp18 = (f32) sp28 * sp8;
    this->unk8 = (f64) sp18;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SplitPath::GetPosition(float arg0) {
    f32 spC;
    f32 sp8;
    Matrix *temp_r4_106;

    temp_r4_106 = *((SplitPath *) (M2C_ERROR(/* Read from unset register $r4 */)))->GetPathData(arg0, &spC);
    sp8 = 0.0f;
    KDUniformSpline::GetMeasure(spC, temp_r4_106, KDSpline_PositionMixer);
}
#endif

#if 0 // DRAFT: illegal type
void SplitPath::Deinit() {
    MKHeap *temp_r3_146;
    s32 var_r30_129;
    s32 var_r31_130;
    void *temp_r31_145;

    var_r30_129 = 0;
    var_r31_130 = 0;
loop_2:
    if (var_r30_129 < (s32) this->unk4) {
        ((KDUniformSpline *) (*(this->unk0 + var_r31_130)))->Deinit();
        operator delete(*(this->unk0 + var_r31_130));
        var_r30_129 += 1;
        var_r31_130 += 0x14;
        goto loop_2;
    }
    temp_r31_145 = this->unk0;
    temp_r3_146 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_146 != NULL) {
        ((MKHeap *) (temp_r3_146->Current()))->Free(temp_r31_145, NULL, 0);
        return;
    }
    free(temp_r31_145);
}
#endif

#if 0 // DRAFT: pointer/array required
void SplitPath::Init(const KDUniformSpline &arg0, int arg1, int arg2) {
    MKHeap *temp_r3_188;
    f32 temp_f1_294;
    s32 temp_r0_175;
    s32 temp_r0_217;
    s32 temp_r0_296;
    s32 temp_r18_187;
    s32 temp_r18_237;
    s32 temp_r18_281;
    s32 temp_r19_174;
    s32 temp_r24_202;
    s32 temp_r26_203;
    s32 temp_r3_181;
    s32 temp_r3_229;
    s32 var_r0_230;
    s32 var_r19_204;
    s32 var_r20_257;
    s32 var_r21_205;
    s32 var_r22_216;
    s32 var_r23_210;
    s32 var_r25_223;
    s32 var_r27_206;
    void *var_r3_195;

    temp_r19_174 = arg0.unk0;
    temp_r0_175 = arg1 - 1;
    temp_r3_181 = arg0.unk0 % temp_r0_175;
    this->unk4 = (temp_r19_174 / temp_r0_175) + (temp_r3_181 != 0);
    temp_r18_187 = this->unk4 * 0x14;
    temp_r3_188 = temp_r3_181->Current();
    if (temp_r3_188 != NULL) {
        var_r3_195 = ((MKHeap *) (temp_r3_188->Current()))->Alloc(temp_r18_187, NULL, 0);
    } else {
        var_r3_195 = malloc(temp_r18_187);
    }
    this->unk0 = var_r3_195;
    temp_r24_202 = temp_r19_174 - 1;
    temp_r26_203 = arg0.unkC;
    var_r19_204 = 0;
    var_r21_205 = 0;
    var_r27_206 = 0;
loop_18:
    if (var_r21_205 < (s32) this->unk4) {
        var_r23_210 = var_r19_204;
        if ((s32) lit_603 > var_r19_204) {
            var_r23_210 = lit_603;
        }
        var_r22_216 = temp_r24_202;
        temp_r0_217 = var_r19_204 + (arg1 - 1);
        if (temp_r0_217 < temp_r24_202) {
            var_r22_216 = temp_r0_217;
        }
        var_r25_223 = var_r23_210 - arg2;
        var_r19_204 = var_r22_216;
        if ((s32) lit_606 > var_r25_223) {
            var_r25_223 = lit_606;
        }
        temp_r3_229 = var_r22_216 + arg2;
        var_r0_230 = temp_r24_202;
        if (temp_r3_229 < temp_r24_202) {
            var_r0_230 = temp_r3_229;
        }
        temp_r18_237 = (var_r0_230 - var_r25_223) + 1;
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8) = 0.0f;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
        }
        *(this->unk0 + var_r27_206) = M2C_ERROR(/* Read from unset register $r3 */);
        ((KDUniformSpline *) (*(this->unk0 + var_r27_206)))->Init(temp_r18_237, 0U);
        var_r20_257 = 0;
loop_16:
        if (var_r20_257 < temp_r18_237) {
            ((KDUniformSpline *) (*(var_r27_206 + this->unk0)))->AddNode(*(temp_r26_203 + ((var_r25_223 + var_r20_257) << 5)));
            var_r20_257 += 1;
            goto loop_16;
        }
        *(this->unk0 + (var_r27_206 + 0xC)) = SplineTools_GetNodeTime(arg0, var_r23_210);
        temp_r18_281 = var_r23_210 - var_r25_223;
        *(this->unk0 + (var_r27_206 + 0x10)) = SplineTools_GetNodeTime(arg0, var_r22_216);
        *(this->unk0 + (var_r27_206 + 4)) = SplineTools_GetNodeTime(*(*(this->unk0 + var_r27_206)), temp_r18_281);
        temp_f1_294 = SplineTools_GetNodeTime(*(*(this->unk0 + var_r27_206)), temp_r18_281 + (var_r22_216 - var_r23_210));
        temp_r0_296 = var_r27_206 + 8;
        var_r21_205 += 1;
        var_r27_206 += 0x14;
        *(this->unk0 + temp_r0_296) = temp_f1_294;
        goto loop_18;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
f32 SplineTools_GetNodeTime(const KDUniformSpline &arg0, int arg1) {
    f32 var_f1_314;
    s32 temp_r0_321;
    s32 var_ctr_317;
    s32 var_r5_315;

    var_f1_314 = 0.0f;
    var_r5_315 = 0;
    var_ctr_317 = arg1;
    if (arg1 > 0) {
        do {
            temp_r0_321 = var_r5_315 + 0x1C;
            var_r5_315 += 0x20;
            var_f1_314 += *(arg0.unkC + temp_r0_321);
            var_ctr_317 -= 1;
        } while (var_ctr_317 != 0);
    }
    return var_f1_314 / arg0.unk8;
}
#endif
