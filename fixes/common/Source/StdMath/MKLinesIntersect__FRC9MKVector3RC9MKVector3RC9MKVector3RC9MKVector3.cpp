s32 MKLinesIntersect(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3) {
    f32 ax;
    f32 az;
    f32 bx;
    f32 bz;
    f32 cx;
    f32 cz;
    f32 dx;
    f32 dz;
    s32 result;
    s32 sideA;
    s32 sideB;
    s32 sideC;
    s32 sideD;

    az = M2C_FIELD(&arg0, f32 *, 0x8);
    dz = M2C_FIELD(&arg3, f32 *, 0x8);
    bz = M2C_FIELD(&arg1, f32 *, 0x8);
    ax = M2C_FIELD(&arg0, f32 *, 0x0);
    bx = M2C_FIELD(&arg1, f32 *, 0x0);
    dx = M2C_FIELD(&arg3, f32 *, 0x0);
    cz = M2C_FIELD(&arg2, f32 *, 0x8);
    cx = M2C_FIELD(&arg2, f32 *, 0x0);

    result = 0;
    sideA = ((bx - ax) * (dz - az)) > ((dx - ax) * (bz - az));
    sideB = ((bx - ax) * (cz - az)) > ((cx - ax) * (bz - az));
    if (sideA != sideB) {
        sideC = ((dx - cx) * (bz - cz)) > ((bx - cx) * (dz - cz));
        sideD = ((dx - cx) * (az - cz)) > ((ax - cx) * (dz - cz));
        if (sideC != sideD) {
            result = 1;
        }
    }
    return result;
}
