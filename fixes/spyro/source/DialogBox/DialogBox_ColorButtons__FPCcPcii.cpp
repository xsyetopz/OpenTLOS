void DialogBox_ColorButtons(const char *arg0, char *arg1, int arg2, int arg3) {
    s32 var_r29_1624;
    const char *var_r27_1625;
    s8 *var_r28_1626;
    s8 *var_r28_1648;
    s8 *var_r28_1735;
    s8 *var_r28_1744;
    s8 *var_r3_1640;
    s8 *var_r3_1727;
    u8 *var_r4_1704;
    u8 *var_r4_1746;
    u8 temp_r0_1654;
    u8 temp_r0_1659;
    u8 temp_r0_1691;
    u8 temp_r3_1696;
    u8 temp_r3_1706;
    u8 temp_r3_1737;
    u8 temp_r3_1748;
    u8 temp_r4_1642;
    u8 temp_r4_1729;
    u8 var_r30_1628;
    u8 var_r31_1627;

    var_r29_1624 = arg2;
    var_r27_1625 = arg0;
    var_r28_1626 = (s8 *) arg1;
    var_r31_1627 = 0;
    var_r30_1628 = 0;
    if (var_r29_1624 != 0) {
        var_r3_1640 = Str_Printf((const char *) (lit_stringBase0 + 0x49), &buttonColorBright, M2C_FIELD(&buttonColorBright, f32 *, 0), M2C_FIELD(&buttonColorBright, f32 *, 4), M2C_FIELD(&buttonColorBright, f32 *, 8), M2C_FIELD(&buttonColorBright, f32 *, 0xC));
        do {
            temp_r4_1642 = (u8) *var_r3_1640;
            var_r3_1640 += 1;
            *var_r28_1626 = (s8) temp_r4_1642;
            var_r28_1626 += 1;
        } while ((s8) temp_r4_1642 != 0);
        var_r28_1648 = var_r28_1626 - 1;
loop_22:
        temp_r3_1696 = (u8) M2C_FIELD(var_r27_1625, s8 *, 0);
        if (((s8) temp_r3_1696 != 0) && (var_r29_1624 != 0)) {
            if ((s8) temp_r3_1696 == 0x3C) {
                temp_r0_1654 = M2C_FIELD(var_r27_1625, u8 *, 1);
                var_r31_1627 = 1;
                switch ((s8) temp_r0_1654) {
                case 0x2F:
                    temp_r0_1659 = M2C_FIELD(var_r27_1625, u8 *, 2);
                    if ((s8) temp_r0_1659 != 0x66) {
                        if ((s8) temp_r0_1659 < 0x66) {
                            if ((s8) temp_r0_1659 != 0x46) {

                            } else {
                                goto block_10;
                            }
                        }
                    } else {
block_10:
                        var_r30_1628 = 0;
                    }
                    break;
                case 0x66:
                case 0x46:
                    var_r30_1628 = 1;
                    break;
                }
            }
            if ((var_r31_1627 == 0) && (var_r30_1628 != 0)) {
                var_r29_1624 -= 1;
            }
            if ((s8) temp_r3_1696 == 0x3E) {
                var_r31_1627 = 0;
            }
            temp_r0_1691 = (u8) M2C_FIELD(var_r27_1625, s8 *, 0);
            var_r27_1625 += 1;
            *var_r28_1648 = (s8) temp_r0_1691;
            var_r28_1648 += 1;
            goto loop_22;
        }
        var_r4_1704 = lit_stringBase0 + 8;
        do {
            temp_r3_1706 = *var_r4_1704;
            var_r4_1704 += 1;
            *var_r28_1648 = (s8) temp_r3_1706;
            var_r28_1648 += 1;
        } while ((s8) temp_r3_1706 != 0);
        var_r28_1626 = var_r28_1648 - 1;
    }
    if ((s8) (u8) *var_r27_1625 != 0) {
        var_r3_1727 = Str_Printf((const char *) (lit_stringBase0 + 0x49), &buttonColorDull, M2C_FIELD(&buttonColorDull, f32 *, 0), M2C_FIELD(&buttonColorDull, f32 *, 4), M2C_FIELD(&buttonColorDull, f32 *, 8), M2C_FIELD(&buttonColorDull, f32 *, 0xC));
        do {
            temp_r4_1729 = (u8) *var_r3_1727;
            var_r3_1727 += 1;
            *var_r28_1626 = (s8) temp_r4_1729;
            var_r28_1626 += 1;
        } while ((s8) temp_r4_1729 != 0);
        var_r28_1735 = var_r28_1626 - 1;
        do {
            temp_r3_1737 = (u8) *var_r27_1625;
            var_r27_1625 += 1;
            *var_r28_1735 = (s8) temp_r3_1737;
            var_r28_1735 += 1;
        } while ((s8) temp_r3_1737 != 0);
        var_r28_1744 = var_r28_1735 - 1;
        var_r4_1746 = lit_stringBase0 + 8;
        do {
            temp_r3_1748 = *var_r4_1746;
            var_r4_1746 += 1;
            *var_r28_1744 = (s8) temp_r3_1748;
            var_r28_1744 += 1;
        } while ((s8) temp_r3_1748 != 0);
    }
}
