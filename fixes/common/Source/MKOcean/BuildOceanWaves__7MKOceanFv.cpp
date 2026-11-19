extern "C" f64 pow(f64, f64);

void MKOcean::BuildOceanWaves() {
    f32 arr80[4];
    f32 arr70[4];
    f32 ratio;
    f32 k;
    f32 limit;
    f32 angleBase;
    f32 angle;
    f32 cosA;
    f32 sinA;
    f32 cosB;
    f32 sinB;
    f32 freq;
    f32 dot;
    f32 absDot;
    f32 steep;
    f32 f4v;
    f32 tmp;
    f32 r1;
    f32 r2;
    f64 t0;
    f64 t1;
    f64 t2;
    s32 bits;
    s32 cls;
    s32 r0;
    s32 i;
    s32 idx;
    s32 off;
    u8 *base;

    arr80[0] = M2C_FIELD(&lit_510, f32 *, 0);
    arr80[1] = M2C_FIELD(&lit_510, f32 *, 4);
    arr80[2] = M2C_FIELD(&lit_510, f32 *, 8);
    arr80[3] = M2C_FIELD(&lit_510, f32 *, 0xC);
    arr70[0] = M2C_FIELD(&lit_511, f32 *, 0);
    arr70[1] = M2C_FIELD(&lit_511, f32 *, 4);
    arr70[2] = M2C_FIELD(&lit_511, f32 *, 8);
    arr70[3] = M2C_FIELD(&lit_511, f32 *, 0xC);

    ratio = (f32) pow(this->unk5180 / this->unk5184, 0.1428571492433548);
    k = this->unk5184;
    limit = 0.5f * (100.0f * (this->unk5184 + this->unk5180));
    angleBase = (3.1415927f * this->unk10.unk5014) / 180.0f;
    i = 0;
    off = 0;
    do {
        r1 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        r2 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        if (r2 > r1) {
            r1 = 1.0f - r1;
        }
        angle = (f32) acos(r1);
        idx = i & 3;
        freq = 6.2831855f / k;
        f4v = 0.0f;

        {
            f32 f19 = (angle * arr80[idx]) + angleBase + arr70[idx];

            cosA = _table_sinf(1.5707964f + f19);
            sinA = _table_sinf(f19);
        }
        cosB = _table_sinf(1.5707964f + angleBase);
        sinB = _table_sinf(angleBase);

        base = (u8 *) this + off;
        M2C_FIELD(base, f32 *, 0x50D0) = (f32) ((sinA * freq) / 100.0f);
        M2C_FIELD(base, f32 *, 0x50D4) = (f32) ((cosA * freq) / 100.0f);
        M2C_FIELD(base, f32 *, 0x50E0) = 100.0f * k;

        dot = (cosA * cosB) + (sinA * sinB);
        if (dot < 0.0f) {
            absDot = -dot;
        } else {
            absDot = dot;
        }

        steep = M2C_FIELD(base, f32 *, 0x50E0);
        if (limit < steep) {
            steep = limit;
        }
        M2C_FIELD(base, f32 *, 0x50D8) = (f32) (this->unk5178 * steep * this->unk10.GetDirectionScale(absDot, dot));

        f4v = this->unk10.unk5000 * freq;
        if (f4v > 0.0f) {
            t0 = __frsqrte((f64) f4v);
            t1 = 0.5 * t0 * -(((f64) f4v * (t0 * t0)) - 3.0);
            t2 = 0.5 * t1 * -(((f64) f4v * (t1 * t1)) - 3.0);
            f4v = (f32) ((f64) f4v * (0.5 * t2 * -(((f64) f4v * (t2 * t2)) - 3.0)));
        } else if (f4v < 0.0f) {
            f4v = __float_nan;
        } else {
            tmp = f4v;
            bits = *(s32 *) &tmp;
            cls = bits & 0x7F800000;
            if (cls == 0x7F800000) {
                if (bits & 0x7FFFFF) {
                    r0 = 1;
                } else {
                    r0 = 2;
                }
            } else if (cls == 0) {
                if (bits & 0x7FFFFF) {
                    r0 = 5;
                } else {
                    r0 = 3;
                }
            } else {
                r0 = 4;
            }
            if (r0 == 1) {
                f4v = __float_nan;
            }
        }
        M2C_FIELD(base, f32 *, 0x50DC) = f4v;

        i += 1;
        k *= ratio;
        off += 0x14;
    } while (i < 8);
}
