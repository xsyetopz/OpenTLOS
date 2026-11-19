#include "spyro/source/HudItems.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

void HudItem_Fixed(HudItem *arg0, bool arg1) {
    M2C_UNK var_r4_18;

    if ((u8) arg0->unk18 != 0) {
        arg0->unk19 = arg1;
        var_r4_18 = 0;
        if ((u8) arg0->unk19 != 0) {
            var_r4_18 = 2;
        }
        HudItem_SetState(arg0, (HudItemState) var_r4_18, 0U);
    }
}

void HudItem_Modified(HudItem *arg0) {
    HudItem_SetState(arg0, (HudItemState) 2, 0U);
}

#if 0 // DRAFT: undefined identifier 'unk8'
void HudItem_Draw(HudItem *arg0) {
    M2C_UNK (*temp_r12_55)(s32, f32, f32);
    f32 var_f1_84;
    s32 temp_r4_58;

    temp_r12_55 = arg0->unk8;
    if (temp_r12_55 != NULL) {
        temp_r4_58 = arg0->unk0;
        switch (temp_r4_58) {                       /* irregular */
        case 1:
            temp_r12_55(arg0->unk14, 1.0f - (arg0->unk10 / 0.5f), 1.0f);
            return;
        case 2:
            if ((u8) arg0->unk19 != 0) {
                var_f1_84 = 1.0f;
            } else {
                var_f1_84 = -((arg0->unk10 * 0.5f) - 1.0f);
            }
            temp_r12_55(arg0->unk14, var_f1_84);
            return;
        case 3:
            temp_r12_55(arg0->unk14, arg0->unk10 / 0.5f);
            break;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
u8 HudItem_Update(HudItem *arg0) {
    s32 temp_r0_117;
    u8 (*temp_r12_156)(s32);

    temp_r0_117 = arg0->unk0;
    switch (temp_r0_117) {                          /* irregular */
    case 2:
        break;
    case 1:
        arg0->unk10 -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (arg0->unk10 == 0.0f) {
            HudItem_SetState(arg0, (HudItemState) 2, 0U);
        }
        break;
    case 3:
        arg0->unk10 -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (arg0->unk10 == 0.0f) {
            HudItem_SetState(arg0, (HudItemState) 0, 0U);
        }
        break;
    }
    temp_r12_156 = arg0->unk4;
    if ((temp_r12_156 != NULL) && (temp_r12_156(arg0->unk14) != 0) && ((u8) arg0->unk19 == 0)) {
        return 1U;
    }
    return arg0->unk19;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC'
void HudItem_SetState(HudItem *arg0, HudItemState arg1, bool arg2) {
    M2C_UNK (*temp_r12_355)(s32, s32);
    f32 var_f0_203;
    f32 var_f0_233;
    f32 var_f0_283;
    f32 var_f0_317;
    s32 temp_r6_185;

    temp_r6_185 = arg0->unk0;
    switch (temp_r6_185) {                          /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        if (arg2 != 0) {
            arg0->unk0 = (s32) arg1;
            if ((s32) arg1 == 2) {
                var_f0_203 = 2.0f;
            } else if ((s32) arg1 == 0) {
                var_f0_203 = 0.0f;
            } else {
                var_f0_203 = 0.5f;
            }
            arg0->unk10 = var_f0_203;
        } else if ((s32) arg1 < 3) {
            if ((s32) arg1 < 1) {

            } else {
                arg0->unk0 = 1;
                arg0->unk10 = 0.5f;
            }
        }
        break;
    case 1:                                         /* switch 1 */
        if (arg2 != 0) {
            arg0->unk0 = (s32) arg1;
            if ((s32) arg1 == 2) {
                var_f0_233 = 2.0f;
            } else if ((s32) arg1 == 0) {
                var_f0_233 = 0.0f;
            } else {
                var_f0_233 = 0.5f;
            }
            arg0->unk10 = var_f0_233;
        } else {
            switch ((s32) arg1) {                   /* switch 2; irregular */
            case 3:                                 /* switch 2 */
            case 0:                                 /* switch 2 */
                if ((u8) arg0->unk19 == 0) {
                    arg0->unk0 = 3;
                    arg0->unk10 = 0.5f - arg0->unk10;
                }
                break;
            case 2:                                 /* switch 2 */
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (arg0->unk10 == 0.0f) {
                    arg0->unk0 = 2;
                    arg0->unk10 = 1.0f;
                }
                break;
            }
        }
        break;
    case 2:                                         /* switch 1 */
        if (arg2 != 0) {
            arg0->unk0 = (s32) arg1;
            if ((s32) arg1 == 2) {
                var_f0_283 = 2.0f;
            } else if ((s32) arg1 == 0) {
                var_f0_283 = 0.0f;
            } else {
                var_f0_283 = 0.5f;
            }
            arg0->unk10 = var_f0_283;
        } else if ((s32) arg1 != 3) {
            if ((s32) arg1 < 3) {
                if ((s32) arg1 != 0) {

                } else {
                    goto block_45;
                }
            }
        } else {
block_45:
            if ((u8) arg0->unk19 == 0) {
                arg0->unk0 = 3;
                arg0->unk10 = 0.5f;
            }
        }
        break;
    case 3:                                         /* switch 1 */
        if (arg2 != 0) {
            arg0->unk0 = (s32) arg1;
            if ((s32) arg1 == 2) {
                var_f0_317 = 2.0f;
            } else if ((s32) arg1 == 0) {
                var_f0_317 = 0.0f;
            } else {
                var_f0_317 = 0.5f;
            }
            arg0->unk10 = var_f0_317;
        } else if ((s32) arg1 != 0) {
            if (((s32) arg1 >= 0) && ((s32) arg1 < 3)) {
                arg0->unk0 = 1;
                arg0->unk10 = 0.5f - arg0->unk10;
            }
        } else {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (arg0->unk10 == 0.0f) {
                arg0->unk0 = 0;
                arg0->unk10 = 0.0f;
            }
        }
        break;
    }
    if ((s32) arg0->unk0 != temp_r6_185) {
        temp_r12_355 = arg0->unkC;
        if (temp_r12_355 != NULL) {
            temp_r12_355(arg0->unk14, temp_r6_185);
        }
    }
}
#endif
