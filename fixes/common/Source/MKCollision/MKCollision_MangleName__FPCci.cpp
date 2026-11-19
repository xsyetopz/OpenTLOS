void MKCollision_MangleName(const char *arg0, int arg1) {
    char buf[0x104];
    char *sp8 = buf + 4;
    s8 *temp_ret_91;
    s8 *var_r31_93;

    temp_ret_91 = Str_Printf("_%02d", arg1);
    var_r31_93 = temp_ret_91;
    if (arg1 < 0) {
        var_r31_93 = Str_Printf("_all");
    }
    M2C_STRUCT_COPY(buf, &lit_834, 0x100);
    strncpy(sp8, arg0, 0x20 - (strlen((const char *) var_r31_93) + 5));
    Str_Printf("%s%s", sp8, var_r31_93);
}
