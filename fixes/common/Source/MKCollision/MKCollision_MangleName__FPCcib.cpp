void MKCollision_MangleName(const char *arg0, int arg1, bool arg2) {
    char buf[0x104];
    char *sp8 = buf + 4;
    s8 *temp_ret_29;
    s8 *var_r30_31;
    s8 *var_r5_24;
    s8 *var_r4_37;

    var_r5_24 = (s8 *) "s";
    if (arg2 != 0) {
        var_r5_24 = (s8 *) "b";
    }
    temp_ret_29 = Str_Printf("_%02d%s", arg1, var_r5_24);
    var_r30_31 = temp_ret_29;
    if (arg1 < 0) {
        var_r4_37 = (s8 *) "s";
        if (arg2 != 0) {
            var_r4_37 = (s8 *) "b";
        }
        var_r30_31 = Str_Printf("_all%s", var_r4_37);
    }
    M2C_STRUCT_COPY(buf, &lit_840, 0x100);
    strncpy(sp8, arg0, 0x20 - (strlen((const char *) var_r30_31) + 5));
    Str_Printf("%s%s", sp8, var_r30_31);
}
