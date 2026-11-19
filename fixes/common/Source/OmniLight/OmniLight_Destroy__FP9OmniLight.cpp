void OmniLight_Destroy(OmniLight *arg0) {
    s32 *var_r4;
    s32 *temp_r3;
    s32 temp_r5;

    if ((u8) arg0->unk30 != 0) {
        arg0->unk30 = 0;
        *(s32 *) OmniLight::totalEnabled -= 1;
    }
    var_r4 = (s32 *) lightList;
    while (*var_r4 != 0) {
        if (*var_r4 == (s32) arg0) {
            temp_r3 = (s32 *) lightList;
            lightList = (M2C_UNK *) ((u8 *) temp_r3 + 4);
            temp_r5 = *temp_r3;
            *temp_r3 = *var_r4;
            *var_r4 = temp_r5;
            return;
        }
        var_r4 = (s32 *) ((u8 *) var_r4 + 4);
    }
}
