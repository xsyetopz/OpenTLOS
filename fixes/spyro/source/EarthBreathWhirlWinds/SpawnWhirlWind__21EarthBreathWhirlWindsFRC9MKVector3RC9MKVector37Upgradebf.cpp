void EarthBreathWhirlWinds::SpawnWhirlWind(const MKVector3 &arg0, const MKVector3 &arg1, Upgrade arg2, bool arg3, float arg4) {
    u8 *list;
    KDSoundFader *fader;
    Matrix *mtx;
    MKVector3 vecA;
    MKVector3 vecB;
    MKVector3 rnd;
    MKVector3 fwd;
    MKVector3 up;
    f32 sum;
    f32 inv;
    f32 sp8;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f64 t1;
    f64 t2;
    f64 t3;
    s32 bits;
    s32 kind;

    list = (u8 *) this->unk4C;
    fader = M2C_FIELD(list, KDSoundFader **, -4);
    if (fader != NULL) {
        this->unk4C = (MKHeap *) (list - 4);

        vecA.unk0 = -1.0f;
        vecA.unk4 = 0.0f;
        vecA.unk8 = -1.0f;
        vecA.unkC = 0.0f;
        vecB.unk0 = 1.0f;
        vecB.unk4 = 0.0f;
        vecB.unk8 = 1.0f;
        vecB.unkC = 0.0f;
        rnd = KDRand_Vector(vecA, vecB);

        sum = (rnd.unk8 * rnd.unk8) + ((rnd.unk0 * rnd.unk0) + (rnd.unk4 * rnd.unk4));
        if (sum > 1e-12f) {
            if (sum > 0.0f) {
                t1 = __frsqrte(sum);
                t2 = 0.5 * t1 * -(((f64) sum * (t1 * t1)) - 3.0);
                t3 = 0.5 * t2 * -(((f64) sum * (t2 * t2)) - 3.0);
                sum = (f32) ((f64) sum * (0.5 * t3 * -(((f64) sum * (t3 * t3)) - 3.0)));
            } else if (sum < 0.0f) {
                sum = __float_nan;
            } else {
                sp8 = sum;
                bits = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (bits) {
                case 0x7F800000:
                    kind = (M2C_BITWISE(s32, sp8) & 0x7FFFFF) ? 1 : 2;
                    break;
                case 0x0:
                    kind = (M2C_BITWISE(s32, sp8) & 0x7FFFFF) ? 5 : 3;
                    break;
                default:
                    kind = 4;
                    break;
                }
                if (kind == 1) {
                    sum = __float_nan;
                }
            }
            inv = 1.0f / sum;
        } else {
            inv = 0.0f;
        }

        sp10 = rnd.unk0 * inv;
        sp14 = rnd.unk4 * inv;
        sp18 = rnd.unk8 * inv;
        fwd.unk0 = sp10;
        fwd.unk4 = sp14;
        fwd.unk8 = sp18;
        fwd.unkC = 0.0f;

        M2C_STRUCT_COPY((u8 *) fader + 0xA0, &Matrix::identity, 0x40);
        mtx = (Matrix *) ((u8 *) fader + 0xA0);
        up.unk0 = 0.0f;
        up.unk4 = 1.0f;
        up.unk8 = 0.0f;
        up.unkC = 0.0f;
        KDMath_BuildMatrixFromFwd(mtx, fwd, &up);
        mtx->Scale3x3(mtx, arg1);

        M2C_FIELD(fader, f32 *, 0xD0) = arg0.unk0;
        M2C_FIELD(fader, f32 *, 0xD4) = arg0.unk4;
        M2C_FIELD(fader, f32 *, 0xD8) = arg0.unk8;
        M2C_FIELD(fader, f32 *, 0xDC) = 1.0f;
        M2C_FIELD(fader, f32 *, 0xF4) = 0.5f;
        M2C_FIELD(fader, s32 *, 0x100) = 1;
        M2C_FIELD(fader, f32 *, 0xF8) = 1.0f;
        M2C_STRUCT_COPY((u8 *) fader + 0xE0, &fwd, 0x10);
        M2C_FIELD(fader, f32 *, 0xFC) = 0.0f;
        M2C_FIELD(fader, s32 *, 0x104) = (s32) arg2;
        fader->Init(1.0f, 1.0f);
        M2C_STRUCT_COPY((u8 *) fader + 0x50, &arg0, 0x10);
        M2C_FIELD(fader, f32 *, 0x48) = 50.0f * arg1.unk0;
        M2C_FIELD(fader, f32 *, 0x4C) = 50.0f * arg1.unk4;
        M2C_STRUCT_COPY((u8 *) fader + 0x60, &Matrix::identity, 0x40);
        mtx = (Matrix *) ((u8 *) fader + 0x60);
        mtx->RotateYaw(mtx, 0.3926991f);
        M2C_FIELD(fader, u8 *, 0x108) = arg3;
        M2C_FIELD(fader, f32 *, 0xF0) = arg4;
    }
}
