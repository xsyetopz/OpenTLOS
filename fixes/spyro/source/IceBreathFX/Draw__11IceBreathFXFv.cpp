void IceBreathFX::Draw() {
    Matrix spA0;
    MKVector3 sp48;
    MKVector3 sp68;
    MKVector3 sp78;
    MKVector3 sp88;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 len2;
    f32 nrm;
    f32 inv;
    f64 t0;
    f64 t1;
    f64 t2;
    f64 t3;
    s32 bits;
    s32 cls;
    s32 idx;
    s32 ctr;
    u8 *elem;

    if (EventCamera_GetCurrent() == NULL) {
        ctr = 0;
        idx = 0;
        do {
            elem = (u8 *) this->unkA8 + idx;
            if (M2C_FIELD(elem, u8 *, 0x20) != 0) {
                dx = M2C_FIELD(elem, f32 *, 0x10);
                dy = M2C_FIELD(elem, f32 *, 0x14);
                dz = M2C_FIELD(elem, f32 *, 0x18);
                len2 = (dz * dz) + ((dx * dx) + (dy * dy));
                if (len2 > 0.000001f) {
                    if (len2 > 0.0f) {
                        t0 = __frsqrte((f64) len2);
                        t1 = 0.5 * t0 * -(((f64) len2 * (t0 * t0)) - 3.0);
                        t2 = 0.5 * t1 * -(((f64) len2 * (t1 * t1)) - 3.0);
                        t3 = 0.5 * t2 * -(((f64) len2 * (t2 * t2)) - 3.0);
                        nrm = (f32) ((f64) len2 * t3);
                    } else if (len2 < 0.0f) {
                        nrm = __float_nan;
                    } else {
                        nrm = len2;
                        bits = *(s32 *) &len2;
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
                            nrm = __float_nan;
                        }
                    }
                    inv = 1.0f / nrm;
                } else {
                    inv = 0.0f;
                }
                sp88.unk0 = dx * inv;
                sp88.unk4 = dy * inv;
                sp88.unk8 = dz * inv;
                sp68.unk0 = -sp88.unk0;
                sp68.unk4 = -sp88.unk4;
                sp68.unk8 = -sp88.unk8;
                sp78.unk0 = 0.0f;
                sp78.unk4 = 1.0f;
                sp78.unk8 = 0.0f;
                KDMath_BuildMatrixFromFwd(&spA0, sp68, &sp78);
                spA0.Scale3x3(&spA0, this->unk1A0);
                sp48 = sp88.operator*(100.0f * this->unk1A0);
                elem = (u8 *) this->unkA8 + idx;
                spA0.unk30 = M2C_FIELD(elem, f32 *, 0x0) + sp48.unk0;
                spA0.unk34 = M2C_FIELD(elem, f32 *, 0x4) + sp48.unk4;
                spA0.unk38 = M2C_FIELD(elem, f32 *, 0x8) + sp48.unk8;
                spA0.unk3C = 1.0f;
                MKModel_SetWorldMatrix(this->unkB4, spA0);
                MKModel_Draw(this->unkB4, NULL);
            }
            ctr += 1;
            idx += 0x30;
        } while (ctr < 0x19);
        DrawWallIceShards();
    }
}
