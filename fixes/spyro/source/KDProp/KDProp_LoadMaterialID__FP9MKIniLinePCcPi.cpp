extern "C" s32 stricmp(s8 *, s8 *);
u8 KDProp_LoadMaterialID(MKIniLine *arg0, const char *arg1, int *arg2) {
    s32 temp_r3_25;
    s32 temp_r3_39;
    s32 var_r31_32;

    if (stricmp(arg0->GetFieldName(), (s8 *) arg1) == 0) {
        temp_r3_25 = arg0->GetInt(0);
        if (temp_r3_25 != 0) {
            *arg2 = temp_r3_25;
        } else {
            var_r31_32 = 0;
            *arg2 = 0;
            while (var_r31_32 < (s16) arg0->unk0) {
                temp_r3_39 = MKMaterial_GetMaterialIDMask((const char *) arg0->GetString(var_r31_32));
                var_r31_32 += 1;
                *arg2 |= temp_r3_39;
            }
        }
        return 1U;
    }
    return 0U;
}
