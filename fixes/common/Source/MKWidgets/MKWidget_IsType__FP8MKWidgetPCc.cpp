s32 MKWidget_IsType(MKWidget *arg0, const char *arg1) {
    void *var_r31_595;

    var_r31_595 = arg0->unkC;
loop_4:
    if (var_r31_595 == NULL) {
        return 0;
    }
    if (strcmp(arg1, (const char *) M2C_FIELD(var_r31_595, s8 **, 0)) == 0) {
        return 1;
    }
    var_r31_595 = M2C_FIELD(var_r31_595, void **, 8);
    goto loop_4;
}
