s32 BoundingRegion::IsPointWithin(const MKVector3 &arg0) {
    MKVector3 sp18;
    u32 temp_r3_285;
    u32 temp_r4_286;

    if (IsPointInBoundaryRect(arg0) == 0) {
        return 0;
    }
    sp18.unk0 = __float_max;
    sp18.unk4 = 0.0f;
    sp18.unk8 = arg0.unk8;
    temp_r3_285 = GetIntersectCount(arg0, sp18);
    temp_r4_286 = temp_r3_285 >> 0x1FU;
    return (((temp_r3_285 & 1) ^ temp_r4_286) - temp_r4_286) == 1;
}
