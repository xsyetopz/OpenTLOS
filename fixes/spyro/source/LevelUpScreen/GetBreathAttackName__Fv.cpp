u8 HasAttack(int arg0, int arg1);

u32 GetBreathAttackName() {
    s32 var_r5_1700;
    u8 var_r3_1690;
    u8 *temp_r3_1686;
    u8 *temp_r4_1687;

    if (HasAttack(selectionElement, selectionAttack) != 0) {
        temp_r3_1686 = GameData::gameData + (selectionElement << 5);
        temp_r4_1687 = temp_r3_1686 + 0xD4;
        if ((s32) selectionAttack == 3) {
            var_r3_1690 = 0;
            if (((s32) M2C_FIELD(temp_r3_1686, s32 *, 0xD4) == 3) && ((s32) M2C_FIELD(temp_r4_1687, s32 *, 4) == 3)) {
                var_r3_1690 = 1;
            }
            var_r5_1700 = var_r3_1690 != 0;
        } else {
            var_r5_1700 = M2C_FIELD(temp_r4_1687, s32 *, selectionAttack * 4);
        }
        if ((s32) lit_629 < var_r5_1700) {
            var_r5_1700 = lit_629;
        }
        return M2C_FIELD((s8 *) gpTranslation_StringArray, s32 *, (((selectionElement * 6) + (selectionAttack * 3) + var_r5_1700 + 0x271) * 4));
    }
    return 0U;
}
