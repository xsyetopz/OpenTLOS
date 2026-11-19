void ShotgunWarpFX::BuildLocalVertexList() {
    f64 g1;
    f64 g2;
    f64 g3;
    f64 d0;
    f64 d1;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    f32 f24;
    f32 len2;
    f32 inv;
    f32 x;
    f32 y;
    f32 z;
    s32 i;
    s32 j;
    s32 off;
    s32 kind;
    u8 *vtx;

    i = 0;
    f24 = 1500.0f / (f32) this->unkC;
    f23 = 795.0f / (f32) this->unkC;
    f22 = 6.2831855f / (f32) (this->unk10 - 1);
    while (i < (s32) this->unkC) {
        j = 0;
        f21 = (f23 * (f32) i) + 5.0f;
        while (j < this->unk10) {
            f20 = f22 * (f32) j;
            sp14 = 0.45f * (f21 * -_table_sinf(1.5707964f + f20));
            sp10 = f21 * _table_sinf(f20);
            sp18 = -(f24 * (f32) i);
            off = (j + (i * this->unk10)) * 0x30;
            vtx = (u8 *) this->unk0 + off;
            sp28 = (f64) sp18;
            M2C_FIELD(vtx, f64 *, 0) = (f64) sp10;
            M2C_FIELD(vtx, f64 *, 8) = (f64) sp18;
            sp20 = (f64) sp10;
            d0 = M2C_FIELD(vtx, f64 *, 0);
            d1 = M2C_FIELD(vtx, f64 *, 8);
            M2C_FIELD(vtx, f64 *, 0x20) = d0;
            M2C_FIELD(vtx, f64 *, 0x28) = d1;
            M2C_FIELD(vtx, f32 *, 0x28) = 0.0f;
            x = M2C_FIELD(vtx, f32 *, 0x20);
            y = M2C_FIELD(vtx, f32 *, 0x24);
            z = M2C_FIELD(vtx, f32 *, 0x28);
            len2 = (z * z) + ((x * x) + (y * y));
            if (len2 > 0.000001f) {
                if (len2 > 0.0f) {
                    g1 = __frsqrte(len2);
                    g2 = 0.5 * g1 * -(((f64) len2 * (g1 * g1)) - 3.0);
                    g3 = 0.5 * g2 * -(((f64) len2 * (g2 * g2)) - 3.0);
                    len2 = (f32) ((f64) len2 * (0.5 * g3 * -(((f64) len2 * (g3 * g3)) - 3.0)));
                } else if (len2 < M2C_BITWISE(f32, 0.0)) {
                    len2 = __float_nan;
                } else {
                    sp8 = len2;
                    switch (*(s32 *) &sp8 & 0x7F800000) {
                    case 0x7F800000:
                        if (*(s32 *) &sp8 & 0x7FFFFF) {
                            kind = 1;
                        } else {
                            kind = 2;
                        }
                        break;
                    case 0x0:
                        if (*(s32 *) &sp8 & 0x7FFFFF) {
                            kind = 5;
                        } else {
                            kind = 3;
                        }
                        break;
                    default:
                        kind = 4;
                        break;
                    }
                    if (kind == 1) {
                        len2 = __float_nan;
                    }
                }
                inv = 1.0f / len2;
            } else {
                inv = 0.0f;
            }
            M2C_FIELD(vtx, f32 *, 0x20) = (f32) (M2C_FIELD(vtx, f32 *, 0x20) * inv);
            M2C_FIELD(vtx, f32 *, 0x24) = (f32) (M2C_FIELD(vtx, f32 *, 0x24) * inv);
            M2C_FIELD(vtx, f32 *, 0x28) = (f32) (M2C_FIELD(vtx, f32 *, 0x28) * inv);
            j += 1;
        }
        i += 1;
    }
}
