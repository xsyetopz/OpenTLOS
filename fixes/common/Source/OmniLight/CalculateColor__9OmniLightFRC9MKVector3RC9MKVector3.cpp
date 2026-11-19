void OmniLight::CalculateColor(const MKVector3 &arg0, const MKVector3 &arg1) {
    extern f32 __float_nan;
    const MKVector3 *arg2;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist2;
    f32 atten;
    f32 inv;
    f32 dot;
    f32 scale;
    f32 tmp;
    s32 bits;
    s32 cls;

    dx = arg1.unk0 - M2C_FIELD(&arg0, f32 *, 0x10);
    dy = arg1.unk4 - M2C_FIELD(&arg0, f32 *, 0x14);
    dz = arg1.unk8 - M2C_FIELD(&arg0, f32 *, 0x18);
    dist2 = (dz * dz) + ((dx * dx) + (dy * dy));
    atten = dist2 / M2C_FIELD(&arg0, f32 *, 0x24);
    if (atten < 1.0f) {
    } else {
        atten = 1.0f;
    }
    if (atten > 0.0f) {
    } else {
        atten = 0.0f;
    }
    if (dist2 > 0.000001f) {
        if (dist2 > 0.0f) {
            f64 y0;
            f64 y1;
            f64 y2;

            y0 = __frsqrte(dist2);
            y1 = 0.5 * y0 * -(((f64) dist2 * (y0 * y0)) - 3.0);
            y2 = 0.5 * y1 * -(((f64) dist2 * (y1 * y1)) - 3.0);
            dist2 = (f32) ((f64) dist2 * (0.5 * y2 * -(((f64) dist2 * (y2 * y2)) - 3.0)));
        } else if (dist2 < 0.0f) {
            dist2 = __float_nan;
        } else {
            tmp = dist2;
            bits = *(s32 *) &tmp;
            switch (bits & 0x7F800000) {
            case 0x7F800000:
                if (bits & 0x7FFFFF) {
                    cls = 1;
                } else {
                    cls = 2;
                }
                break;
            case 0x0:
                if (bits & 0x7FFFFF) {
                    cls = 5;
                } else {
                    cls = 3;
                }
                break;
            default:
                cls = 4;
                break;
            }
            if (cls == 1) {
                dist2 = __float_nan;
            }
        }
        inv = 1.0f / dist2;
    } else {
        inv = 0.0f;
    }

    dx = dx * inv;
    dy = dy * inv;
    dz = dz * inv;

    /* r6 is live-in in the asm: no instruction in this function sets it. */
    dot = (dz * M2C_FIELD(arg2, f32 *, 8)) + ((dx * M2C_FIELD(arg2, f32 *, 0)) + (dy * M2C_FIELD(arg2, f32 *, 4)));
    if (dot < 0.0f) {
        dot = -dot;
    }
    scale = (1.0f - atten) * dot;

    M2C_FIELD(this, f32 *, 0x0) = M2C_FIELD(&arg0, f32 *, 0x0) * scale;
    M2C_FIELD(this, f32 *, 0x4) = M2C_FIELD(&arg0, f32 *, 0x4) * scale;
    M2C_FIELD(this, f32 *, 0x8) = M2C_FIELD(&arg0, f32 *, 0x8) * scale;
    M2C_FIELD(this, f32 *, 0xC) = 1.0f;
}
