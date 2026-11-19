u8 UIControls_DirectionPressed(FrontEndControls arg0, int arg1) {
    s32 var_r4_0;
    s8 *temp_r4_165;

    var_r4_0 = arg1;
    if ((var_r4_0 < 0) || (var_r4_0 >= 1)) {
        var_r4_0 = currentController;
    }
    temp_r4_165 = (s8 *) &(&allControllers)[var_r4_0];
    if (M2C_FIELD(temp_r4_165, u8 *, 0x1D) == 0) {
        return M2C_FIELD(temp_r4_165 + (s32) arg0, u8 *, 0x14);
    }
    return 0U;
}
