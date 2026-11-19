void EarthBreathFX::DrawSeedBullets(void) {
    Matrix m;
    MKVector3 **slot;
    MKVector3 *elem;
    f32 fwd[3];
    f32 up[3];
    f32 sc[3];
    f32 len2;
    f32 len;
    f32 inv;
    f32 speed;
    f32 f25;
    f64 e0;
    f64 e1;
    f64 e2;
    s32 bits;
    s32 cls;

    up[0] = 0.0f;
    up[1] = 1.0f;
    up[2] = 0.0f;
    slot = this->unkC8;
    while (slot != NULL && *slot != NULL) {
        elem = *slot;
        fwd[0] = M2C_FIELD(elem, f32 *, 0x10);
        fwd[1] = M2C_FIELD(elem, f32 *, 0x14);
        fwd[2] = M2C_FIELD(elem, f32 *, 0x18);
        len2 = (fwd[2] * fwd[2]) + ((fwd[0] * fwd[0]) + (fwd[1] * fwd[1]));
        if (len2 > 0.000001f) {
            if (len2 > 0.0f) {
                e0 = __frsqrte(len2);
                e1 = 0.5 * e0 * -(((f64) len2 * (e0 * e0)) - 3.0);
                e2 = 0.5 * e1 * -(((f64) len2 * (e1 * e1)) - 3.0);
                len = (f32) ((f64) len2 * (0.5 * e2 * -(((f64) len2 * (e2 * e2)) - 3.0)));
            } else if (len2 < 0.0f) {
                len = __float_nan;
            } else {
                len = len2;
                bits = M2C_BITWISE(s32, len2) & 0x7F800000;
                switch (bits) {
                case 0x7F800000:
                    if (M2C_BITWISE(s32, len2) & 0x7FFFFF) {
                        cls = 1;
                    } else {
                        cls = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, len2) & 0x7FFFFF) {
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
                    len = __float_nan;
                }
            }
            inv = 1.0f / len;
        } else {
            inv = 0.0f;
            len = 0.0f;
        }
        speed = len / 1000.0f;
        if (!(speed < 2.0f)) {
            speed = 2.0f;
        }
        if (!(speed > 0.0f)) {
            speed = 0.0f;
        }
        fwd[0] = fwd[0] * inv;
        fwd[1] = fwd[1] * inv;
        fwd[2] = fwd[2] * inv;
        f25 = 2.0f * (M2C_FIELD(elem, f32 *, 0x20) / M2C_FIELD(elem, f32 *, 0x24));
        sc[0] = f25;
        sc[1] = f25;
        sc[2] = 2.0f * speed;
        KDMath_BuildMatrixFromFwd(&m, *(MKVector3 *) fwd, (MKVector3 *) up);
        m.Scale3x3(&m, *(MKVector3 *) sc);
        m.unk30 = elem->unk0;
        m.unk34 = elem->unk4;
        m.unk38 = elem->unk8;
        m.unk3C = 1.0f;
        MKModel_SetWorldMatrix(this->unk128, m);
        MKModel_Draw(this->unk128, NULL);
        slot += 1;
    }
}
