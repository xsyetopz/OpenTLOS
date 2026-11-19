s32 ValidateVector(const MKVector3 &arg0) {
    s32 var_r5_12;

    var_r5_12 = 0;
    if ((((u32) (M2C_FIELD(&arg0, s32 *, 0x0) & 0x7F800000) + 0x80800000) != 0U) && (((u32) (M2C_FIELD(&arg0, s32 *, 0x4) & 0x7F800000) + 0x80800000) != 0U) && (((u32) (M2C_FIELD(&arg0, s32 *, 0x8) & 0x7F800000) + 0x80800000) != 0U)) {
        var_r5_12 = 1;
    }
    return var_r5_12;
}
