s32 DataMap_LoadLineBitfield(MKIniLine *arg0, const char *arg1, const DataMap *arg2, unsigned int *arg3) {
    s16 temp_r31_21;
    s32 temp_r3_32;
    s32 var_r30_23;

    if ((u8) arg0->IsField(arg1) != 0) {
        temp_r31_21 = arg0->unk0;
        *arg3 = 0;
        for (var_r30_23 = 0; var_r30_23 < temp_r31_21;) {
            temp_r3_32 = DataMap_GetValue(arg2, (const char *) arg0->GetString(var_r30_23));
            var_r30_23 += 1;
            *arg3 |= temp_r3_32;
        }
        return 1;
    }
    return 0;
}
