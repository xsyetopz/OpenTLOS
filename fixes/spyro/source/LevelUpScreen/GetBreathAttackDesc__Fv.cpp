u8 HasAttack(int arg0, int arg1);

u32 GetBreathAttackDesc() {
    s32 var_r5_1640;
    u8 var_r3_1630;
    u8 *temp_r3_1626;
    u8 *temp_r4_1627;

    if (HasAttack(selectionElement, selectionAttack) != 0) {
        temp_r3_1626 = GameData::gameData + (selectionElement << 5);
        temp_r4_1627 = temp_r3_1626 + 0xD4;
        if ((s32) selectionAttack == 3) {
            var_r3_1630 = 0;
            if (((s32) M2C_FIELD(temp_r3_1626, s32 *, 0xD4) == 3) && ((s32) M2C_FIELD(temp_r4_1627, s32 *, 4) == 3)) {
                var_r3_1630 = 1;
            }
            var_r5_1640 = var_r3_1630 != 0;
        } else {
            var_r5_1640 = M2C_FIELD(temp_r4_1627, s32 *, selectionAttack * 4);
        }
        if ((s32) lit_638 < var_r5_1640) {
            var_r5_1640 = lit_638;
        }
        return M2C_FIELD((s8 *) gpTranslation_StringArray, s32 *, (((selectionElement * 6) + (selectionAttack * 3) + var_r5_1640 + 0x258) * 4));
    }
    return 0U;
}
