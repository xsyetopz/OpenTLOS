f32 _table_sinf(float arg0) {
    s32 idx;
    s32 r6;
    f32 lo;
    f32 hi;
    f32 res;

    r6 = (s32) (325.9493f * arg0);
    idx = (r6 * 4) & 0xFFC;
    lo = M2C_FIELD(_sinTable, f32 *, idx);
    hi = M2C_FIELD(_sinTable, f32 *, idx + 4);
    res = (325.9493f * (arg0 - (0.0030679617f * (f32) r6))) * (hi - lo) + lo;
    *(s32 *) &res = *(s32 *) &res | (((u32) r6 << 21) & 0x80000000);
    return res;
}
