void _table_sincosf(float arg0, float &arg1, float &arg2) {
    s32 r5;
    s32 sinIdx;
    s32 cosIdx;
    f32 frac;
    f32 lo;
    f32 hi;

    r5 = (s32) (325.9493f * arg0);
    frac = 325.9493f * (arg0 - (0.0030679617f * (f32) r5));
    sinIdx = (r5 * 4) & 0xFFC;
    cosIdx = ((r5 + 0x200) * 4) & 0xFFC;
    lo = M2C_FIELD(_sinTable, f32 *, sinIdx);
    hi = M2C_FIELD((_sinTable + 4), f32 *, sinIdx);
    arg1 = frac * (hi - lo) + lo;
    lo = M2C_FIELD(_sinTable, f32 *, cosIdx);
    hi = M2C_FIELD((_sinTable + 4), f32 *, cosIdx);
    arg2 = frac * (hi - lo) + lo;
    *(s32 *) &arg1 = *(s32 *) &arg1 | (((u32) r5 << 21) & 0x80000000);
    *(s32 *) &arg2 = *(s32 *) &arg2 | (((u32) (r5 + 0x200) << 21) & 0x80000000);
}
