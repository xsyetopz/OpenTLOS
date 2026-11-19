CharInfo *MKFont::GetCharacter(const char *arg0, int *arg1, FontPage **arg2) {
    CharInfo *var_r3_703;
    FontPage *temp_r5_684;
    s8 *temp_r4_692;
    s32 temp_cr0_eq_648;
    s32 temp_r7_685;
    s32 var_r3_678;
    s8 *temp_r3_646;
    s8 *temp_r4_656;
    u32 var_ctr_680;
    u8 temp_r3_657;

    if (IsToken(arg0, (u32) *arg1) != 0) {
loop_4:
        temp_r3_646 = (s8 *) (arg0 + *arg1);
        temp_cr0_eq_648 = (s32) M2C_FIELD(temp_r3_646, u8 *, -1) == 0x3E;
        if ((temp_cr0_eq_648 != 0) && ((s32) (u8) M2C_FIELD(temp_r3_646, u8 *, 0) != 0x3C)) {
            goto block_7;
        }
        *arg1 += 1;
        if ((s8) (u8) arg0[*arg1] == 0) {
            return NULL;
        }
        goto loop_4;
    }
block_7:
    temp_r4_656 = (s8 *) (arg0 + *arg1);
    temp_r3_657 = (u8) M2C_FIELD(temp_r4_656, u8 *, 0);
    if ((((s32) temp_r3_657 == 0x3C) && ((s32) M2C_FIELD(temp_r4_656, u8 *, 1) == 0x3C)) || (((s32) (s8) temp_r3_657 == 0x3E) && ((s32) M2C_FIELD(temp_r4_656, u8 *, 1) == 0x3E))) {
        *arg1 += 1;
    }
    var_r3_678 = 0;
    var_ctr_680 = M2C_FIELD(&gMKDefaults, u32 *, 0xB0);
    if (var_ctr_680 > 0U) {
loop_13:
        temp_r5_684 = (FontPage *) (*(s8 **) MKFont::currentFontStack + var_r3_678);
        temp_r7_685 = *arg1;
        if (((u32) temp_r5_684->unk8 <= (u32) temp_r7_685) && ((u32) temp_r5_684->unkC >= (u32) temp_r7_685)) {
            temp_r4_692 = (s8 *) temp_r5_684->unk0;
            if (temp_r4_692 != NULL) {
                var_r3_703 = (CharInfo *) (M2C_FIELD(*(s8 **) (*(s8 **) temp_r4_692 + temp_r5_684->unk4 * 4), s32 *, 0x28) + (((u8) arg0[temp_r7_685] << 5) & 0x1FE0));
                if (arg2 != NULL) {
                    *arg2 = temp_r5_684;
                    return var_r3_703;
                }
                return var_r3_703;
            }
        }
        var_r3_678 += 0x14;
        var_ctr_680 -= 1;
        if (var_ctr_680 == 0U) {
            goto block_19;
        }
        goto loop_13;
    }
block_19:
    var_r3_703 = NULL;
    return var_r3_703;
}
