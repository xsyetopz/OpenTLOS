#include "spyro/source/KDFaderObject.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

f32 KDFaderObject::GetFadePercentage() {
    f32 temp_f1_50;
    f32 temp_f2_28;
    s32 temp_r4_11;

    temp_r4_11 = this->unk4;
    if ((temp_r4_11 == 1) || ((temp_r4_11 == 0) && ((s32) this->unk8 == 1))) {
        if ((temp_r4_11 != 1) || (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((this->unk10 == 0.0f) == 0))) {
            temp_f2_28 = this->unk10;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_f2_28 == 0.0f) {
                return 1.0f;
            }
            return 1.0f - (this->unkC / temp_f2_28);
        }
        return 0.0f;
    }
    if ((temp_r4_11 == 2) || ((temp_r4_11 == 0) && ((s32) this->unk8 == 2))) {
        temp_f1_50 = this->unk14;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f1_50 == 0.0f) {
            return 1.0f;
        }
        return this->unkC / temp_f1_50;
    }
    return 0.0f;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDFaderObject::FadeState'
s32 KDFaderObject::GetNextState(KDFaderObject::FadeState arg1, KDFaderObject::FadeMode arg2) {
    s32 var_r0_87;

    switch ((s32) arg1) {                           /* switch 1; irregular */
    default:                                        /* switch 1 */
    case 0:                                         /* switch 1 */
        if (((u32) ((s32) arg2 - 1) <= 2U) || ((s32) arg2 == 4)) {
            var_r0_87 = 1;
        } else if (((u32) ((s32) arg2 - 5) <= 2U) || ((s32) arg2 == 8)) {
            var_r0_87 = 2;
        } else {
            var_r0_87 = 3;
        }
        break;
    case 1:                                         /* switch 1 */
        switch ((s32) arg2) {                       /* switch 2; irregular */
        case 3:                                     /* switch 2 */
            var_r0_87 = 2;
            break;
        case 2:                                     /* switch 2 */
        case 4:                                     /* switch 2 */
            var_r0_87 = 3;
            break;
        default:                                    /* switch 2 */
            var_r0_87 = 0;
            break;
        }
        break;
    case 2:                                         /* switch 1 */
        switch ((s32) arg2) {                       /* switch 3; irregular */
        case 7:                                     /* switch 3 */
            var_r0_87 = 1;
            break;
        case 6:                                     /* switch 3 */
        case 8:                                     /* switch 3 */
            var_r0_87 = 3;
            break;
        default:                                    /* switch 3 */
            var_r0_87 = 0;
            break;
        }
        break;
    case 3:                                         /* switch 1 */
        switch ((s32) arg2) {                       /* switch 4; irregular */
        case 10:                                    /* switch 4 */
        case 8:                                     /* switch 4 */
            var_r0_87 = 1;
            break;
        case 11:                                    /* switch 4 */
        case 4:                                     /* switch 4 */
            var_r0_87 = 2;
            break;
        default:                                    /* switch 4 */
            var_r0_87 = 0;
            break;
        }
        break;
    }
    switch (var_r0_87) {                            /* switch 5; irregular */
    case 1:                                         /* switch 5 */
        this->unkC = this->unk10;
        break;
    case 2:                                         /* switch 5 */
        this->unkC = this->unk14;
        break;
    case 3:                                         /* switch 5 */
        this->unkC = this->unk18;
        break;
    }
    return var_r0_87;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDFaderObject::FadeMode'
void KDFaderObject::Fade(KDFaderObject::FadeMode arg1, float farg0, float farg1, float farg2, bool arg2) {
    f32 temp_f1_202;
    f32 var_f0_208;
    f32 var_f31_198;
    s32 temp_r0_257;
    s32 temp_r3_195;
    s32 temp_r3_253;

    temp_r3_195 = this->unk4;
    var_f31_198 = 1.0f;
    if (temp_r3_195 != 0) {
        temp_f1_202 = this->unkC;
        if ((temp_f1_202 > 0.0f) && (arg2 != 0)) {
            var_f0_208 = temp_f1_202;
            switch (temp_r3_195) {                  /* switch 1; irregular */
            case 1:                                 /* switch 1 */
                var_f0_208 = this->unk10;
                break;
            case 2:                                 /* switch 1 */
                var_f0_208 = this->unk14;
                break;
            case 3:                                 /* switch 1 */
                var_f0_208 = this->unk18;
                break;
            }
            var_f31_198 = temp_f1_202 / var_f0_208;
            if (((temp_r3_195 == 1) && (GetNextState((KDFaderObject::FadeState) 0, arg1) == 2)) || (((s32) this->unk4 == 2) && (GetNextState((KDFaderObject::FadeState) 0, arg1) == 1))) {
                var_f31_198 = 1.0f - var_f31_198;
            }
        }
    }
    this->unk10 = farg0;
    this->unk14 = farg1;
    this->unk18 = farg2;
    this->unk0 = (s32) arg1;
    temp_r3_253 = GetNextState((KDFaderObject::FadeState) 0, arg1);
    this->unk8 = this->unk4;
    this->unk4 = temp_r3_253;
    temp_r0_257 = this->unk4;
    switch (temp_r0_257) {                          /* switch 2; irregular */
    case 1:                                         /* switch 2 */
        this->unkC = this->unk10;
        break;
    case 2:                                         /* switch 2 */
        this->unkC = this->unk14;
        break;
    case 3:                                         /* switch 2 */
        this->unkC = this->unk18;
        break;
    default:                                        /* switch 2 */
        this->unkC = 0.0f;
        break;
    }
    this->unkC *= var_f31_198;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void KDFaderObject::Update() {
    s32 temp_r3_319;

    if ((s32) this->unk4 != 0) {
        this->unkC -= gUpdateTimeDelta;
        if (this->unkC < 0.0f) {
            this->unkC = 0.0f;
            temp_r3_319 = GetNextState((KDFaderObject::FadeState) this->unk4, (KDFaderObject::FadeMode) this->unk0);
            this->unk8 = this->unk4;
            this->unk4 = temp_r3_319;
        }
    }
}
#endif

void KDFaderObject::Reset() {
    this->unk0 = 1;
    this->unk8 = 0;
    this->unk4 = 0;
    this->unkC = 0.0f;
    this->unk18 = -1.0f;
    this->unk14 = -1.0f;
    this->unk10 = -1.0f;
}
