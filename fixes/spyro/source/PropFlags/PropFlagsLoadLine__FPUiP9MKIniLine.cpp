s32 PropFlagsLoadLine(unsigned int *arg0, MKIniLine *arg1) {
    bool sp8;
    s32 var_r27_130;
    s32 var_r29_126;
    const char *temp_r4_163;
    void *temp_r28_162;

    var_r29_126 = 0;
    var_r27_130 = 0;
    sp8 = 0;
    while (var_r27_130 < 8 && (temp_r28_162 = (s8 *) &flagMap + var_r29_126, temp_r4_163 = M2C_FIELD(temp_r28_162, const char **, 4), (s8) *temp_r4_163 != 0)) {
        if (arg1->LoadBool(temp_r4_163, &sp8, 0) != 0) {
            if (sp8 != 0) {
                *arg0 |= M2C_FIELD(temp_r28_162, s32 *, 0);
            } else {
                *arg0 &= ~M2C_FIELD(temp_r28_162, s32 *, 0);
            }
            return 1;
        }
        var_r27_130 += 1;
        var_r29_126 += 8;
    }
    return 0;
}
