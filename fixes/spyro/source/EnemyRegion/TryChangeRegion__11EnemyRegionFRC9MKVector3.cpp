s32 EnemyRegion::TryChangeRegion(const MKVector3 &arg0) {
    KDPathIterator iter;
    KDPathManager mgr;
    MKVector3 centroid;
    KDLocalPathSegment *seg;
    s32 sp74;
    s32 sp78;
    s32 sp7C;
    f32 sp80;
    f32 sp84;
    f32 sp88;
    f32 sp8C;
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
    seg = (KDLocalPathSegment *) mgr.unk0;
    if (seg == NULL) {
        return 0;
    }
    if ((u8) this->unk31 != 0 && (s32) seg == this->unk10) {
        return 0;
    }

    sp74 = 0;
    sp78 = 0;
    sp7C = 0;
    sp80 = 0.0f;
    sp84 = 0.0f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    ((BoundingRegion *) &sp74)->Init(seg);
    if ((u8) ((BoundingRegion *) &sp74)->IsPointWithin(arg0) == 0) {
        return 0;
    }

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
        SetupRegion(seg);
        return 1;
    }
    return 0;
}
