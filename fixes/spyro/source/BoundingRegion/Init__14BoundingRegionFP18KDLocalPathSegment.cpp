void BoundingRegion::Init(KDLocalPathSegment *arg0) {
    KDLocalPathSegment *temp_r4;

    M2C_FIELD(this, KDLocalPathSegment **, 0) = arg0;
    M2C_FIELD(this, s32 *, 4) = 0;
    temp_r4 = M2C_FIELD(this, KDLocalPathSegment **, 0);
    M2C_FIELD(this, s32 *, 8) = M2C_FIELD(temp_r4, s32 *, 0x20);
    InitBoundaryRect();
}
