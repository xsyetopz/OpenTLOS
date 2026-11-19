void EnemyRegion::SetupRegion(const MKVector3 &arg0, float arg1) {
    KDPathIterator iter;
    KDPathManager mgr;
    MKVector3 centroid;
    KDLocalPathSegment *seg;
    f32 *matrix;
    f32 x;
    f32 y;
    f32 z;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 dy;

    iter.Init();
    mgr.NearestPointLocalSegment(1, arg0);
    iter.unk0 = (void *) mgr.unk0;
    iter.unk4 = mgr.unk4;
    iter.unk8 = M2C_FIELD(&mgr, u8 *, 8);
    this->unk31 = 0;
    this->unk30 = 0;
    this->unk0 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk8 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk2C = arg1;
    seg = (KDLocalPathSegment *) iter.unk0;
    if (seg != NULL) {
        ((BoundingRegion *) &this->unk10)->Init(seg);
        if ((u8) ((BoundingRegion *) &this->unk10)->IsPointWithin(arg0) != 0) {
            this->unk30 = PolygonWindingOrderIsClockWise((KDPathSegment *) seg);
            centroid = PolygonCentroid((KDPathSegment *) seg);
            M2C_FIELD(&mgr, f64 *, 0x10) = M2C_FIELD(&centroid, f64 *, 0);
            M2C_FIELD(&mgr, f64 *, 0x18) = M2C_FIELD(&centroid, f64 *, 8);
            M2C_FIELD(&mgr, f64 *, 0x20) = M2C_FIELD(&centroid, f64 *, 0);
            M2C_FIELD(&mgr, f64 *, 0x28) = M2C_FIELD(&centroid, f64 *, 8);
            matrix = (f32 *) seg->unk30;
            if (matrix != NULL) {
                x = centroid.unk0;
                y = centroid.unk4;
                z = centroid.unk8;
                tx = M2C_FIELD(matrix, f32 *, 0x30) + ((z * M2C_FIELD(matrix, f32 *, 0x20)) + ((x * M2C_FIELD(matrix, f32 *, 0)) + (y * M2C_FIELD(matrix, f32 *, 0x10))));
                ty = M2C_FIELD(matrix, f32 *, 0x34) + ((z * M2C_FIELD(matrix, f32 *, 0x24)) + ((x * M2C_FIELD(matrix, f32 *, 4)) + (y * M2C_FIELD(matrix, f32 *, 0x14))));
                tz = M2C_FIELD(matrix, f32 *, 0x38) + ((z * M2C_FIELD(matrix, f32 *, 0x28)) + ((x * M2C_FIELD(matrix, f32 *, 8)) + (y * M2C_FIELD(matrix, f32 *, 0x18))));
                M2C_FIELD(&mgr, f32 *, 0x10) = tx;
                M2C_FIELD(&mgr, f32 *, 0x14) = ty;
                M2C_FIELD(&mgr, f32 *, 0x18) = tz;
            }
            dy = M2C_FIELD(&mgr, f32 *, 0x14) - arg0.unk4;
            if (dy < 500.0f && dy > -500.0f) {
                this->unk31 = 1;
                this->unk0 = M2C_FIELD(&mgr, f64 *, 0x20);
                this->unk8 = M2C_FIELD(&mgr, f64 *, 0x28);
            }
        }
    }
}
