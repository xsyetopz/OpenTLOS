void ExplosionWarpFX::BuildLocalVertexList() {
    f32 stepU;
    f32 stepV;
    f32 stepA;
    f32 rad;
    f32 zs;
    f32 xs;
    f32 ys;
    f32 ang;
    f32 cosv;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 sum;
    f32 root;
    f32 scale;
    f64 r0;
    f64 r1;
    f64 r2;
    u8 *pos;
    u8 *nrm;
    s32 i;
    s32 j;

    stepU = 400.0f / (f32) this->unkC;
    stepV = 999.0f / (f32) this->unkC;
    stepA = 6.2831855f / (f32) (this->unk10 - 1);

    for (i = 0; i < (s32) this->unkC; i++) {
        zs = -(stepU * (f32) i);
        rad = (stepV * (f32) i) + 1.0f;
        for (j = 0; j < this->unk10; j++) {
            ang = stepA * (f32) j;
            cosv = _table_sinf(1.5707964f + ang);
            ys = rad * -cosv;
            xs = rad * _table_sinf(ang);

            pos = (u8 *) this->unk0 + (j + i * this->unk10) * 0x30;
            M2C_FIELD(pos, f32 *, 0) = xs;
            M2C_FIELD(pos, f32 *, 4) = ys;
            M2C_FIELD(pos, f32 *, 8) = zs;

            /* Normal at +0x20: a copy of the position with z forced to 0. */
            nrm = pos + 0x20;
            M2C_FIELD(nrm, f32 *, 0) = xs;
            M2C_FIELD(nrm, f32 *, 4) = ys;
            M2C_FIELD(nrm, f32 *, 8) = 0.0f;

            nx = M2C_FIELD(nrm, f32 *, 0);
            ny = M2C_FIELD(nrm, f32 *, 4);
            nz = M2C_FIELD(nrm, f32 *, 8);
            sum = (nz * nz) + ((nx * nx) + (ny * ny));
            if (sum <= 0.000001f) {
                scale = 0.0f;
            } else {
                /* MWCC's inline sqrt: frsqrte refined by three Newton steps in f64. */
                r0 = __frsqrte(sum);
                r1 = 0.5 * r0 * -(((f64) sum * (r0 * r0)) - 3.0);
                r2 = 0.5 * r1 * -(((f64) sum * (r1 * r1)) - 3.0);
                root = (f32) ((f64) sum * (0.5 * r2 * -(((f64) sum * (r2 * r2)) - 3.0)));
                scale = 1.0f / root;
            }
            M2C_FIELD(nrm, f32 *, 0) = nx * scale;
            M2C_FIELD(nrm, f32 *, 4) = ny * scale;
            M2C_FIELD(nrm, f32 *, 8) = nz * scale;
        }
    }
}
