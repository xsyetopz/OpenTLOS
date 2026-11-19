void HudItem_SetState(HudItem *arg0, HudItemState arg1, bool arg2) {
    void (*temp_r12_355)(s32, s32);
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
                if (arg0->unk10 <= 0.0f) {
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
        } else if (arg0->unk10 <= 0.0f) {
            arg0->unk0 = 0;
            arg0->unk10 = 0.0f;
        }
        break;
    }
    if ((s32) arg0->unk0 != temp_r6_185) {
        /* Callback at +0xC, invoked with (unk14, previous state) as the asm does. */
        temp_r12_355 = M2C_FIELD(arg0, void (**)(s32, s32), 0xC);
        if (temp_r12_355 != NULL) {
            temp_r12_355(arg0->unk14, temp_r6_185);
        }
    }
}
