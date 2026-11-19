void FlyingChunkPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3, float arg4, const MKVector4 &arg5, int arg6, MKProp *arg7) {
    Matrix spB0;
    MKVector3 sp88;
    MKVector3 sp98;
    FlyingChunkPSDescriptor *desc;
    MKHeap **bounds;
    Matrix **pool;
    Matrix *mtx;
    f64 nr;
    f32 x1;
    f32 y1;
    f32 z1;
    f32 up_x;
    f32 up_y;
    f32 up_z;
    f32 w_x;
    f32 w_y;
    f32 w_z;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp14;
    f32 sp10;
    f32 magSq;
    f32 invLen;
    f32 dotAbs;
    f32 magSq2;
    f32 sx;
    f32 sy;
    f32 sz;
    s32 cls;
    s32 i;

    pool = this->unkD8;
    if ((u32) M2C_FIELD(pool, u32 *, -4) != 0U) {
        pool -= 1;
        this->unkD8 = pool;
        mtx = *pool;
        if (mtx != NULL) {
            desc = checked_cast<FlyingChunkPSDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            M2C_FIELD(mtx, f64 *, 0x40) = M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(mtx, f64 *, 0x48) = M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(mtx, f64 *, 0x50) = M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(mtx, f64 *, 0x58) = M2C_FIELD(&arg1, f64 *, 8);
            M2C_FIELD(mtx, f32 *, 0x84) = desc->unkF0;
            M2C_FIELD(mtx, f32 *, 0x88) = arg4;
            M2C_FIELD(mtx, s32 *, 0x94) = MKRand_Int((int *) &gViewSeed, 0, desc->unkEC);
            M2C_FIELD(mtx, f64 *, 0x60) = M2C_FIELD(&arg5, f64 *, 0);
            M2C_FIELD(mtx, f64 *, 0x68) = M2C_FIELD(&arg5, f64 *, 8);
            M2C_FIELD(mtx, s8 *, 0x9D) = 0;
            M2C_FIELD(mtx, s32 *, 0x98) = arg6;
            M2C_FIELD(mtx, MKProp **, 0x80) = arg7;
            bounds = MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, M2C_FIELD(mtx, s32 *, 0x94));
            M2C_FIELD(mtx, f32 *, 0x90) = M2C_FIELD(bounds, f32 *, 0xC);

            up_x = 0.0f;
            up_y = -1.0f;
            up_z = 0.0f;
            x1 = M2C_FIELD(mtx, f32 *, 0x50);
            y1 = M2C_FIELD(mtx, f32 *, 0x54);
            z1 = M2C_FIELD(mtx, f32 *, 0x58);
            sp18 = (y1 * up_z) - (z1 * up_y);
            sp1C = (z1 * up_x) - (x1 * up_z);
            sp20 = (x1 * up_y) - (y1 * up_x);
            sp88.unk0 = sp18;
            sp88.unk4 = sp1C;
            sp88.unk8 = sp20;
            sp98 = Normalise(sp88);
            M2C_FIELD(mtx, f64 *, 0x70) = M2C_FIELD(&sp98, f64 *, 0);
            M2C_FIELD(mtx, f64 *, 0x78) = M2C_FIELD(&sp98, f64 *, 8);

            magSq = (z1 * z1) + ((x1 * x1) + (y1 * y1));
            if (magSq > 1e-12f) {
                if (magSq > 0.0f) {
                    nr = __frsqrte(magSq);
                    nr = 0.5 * nr * -(((f64) magSq * (nr * nr)) - 3.0);
                    nr = 0.5 * nr * -(((f64) magSq * (nr * nr)) - 3.0);
                    magSq = (f32) ((f64) magSq * (0.5 * nr * -(((f64) magSq * (nr * nr)) - 3.0)));
                } else if (magSq < 0.0f) {
                    magSq = __float_nan;
                } else {
                    sp14 = magSq;
                    cls = M2C_FIELD(&sp14, s32 *, 0) & 0x7F800000;
                    switch (cls) {
                    case 0x7F800000:
                        if (M2C_FIELD(&sp14, s32 *, 0) & 0x7FFFFF) {
                            cls = 1;
                        } else {
                            cls = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_FIELD(&sp14, s32 *, 0) & 0x7FFFFF) {
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
                        magSq = __float_nan;
                    }
                }
                invLen = 1.0f / magSq;
            } else {
                invLen = 0.0f;
            }

            sx = x1 * invLen;
            sy = y1 * invLen;
            sz = z1 * invLen;
            w_x = 1.0f;
            w_y = -1.0f;
            w_z = 0.0f;
            dotAbs = (w_z * sz) + ((w_x * sx) + (w_y * sy));
            if (dotAbs < 0.0f) {
                dotAbs = -dotAbs;
            }

            magSq2 = (z1 * z1) + ((x1 * x1) + (y1 * y1));
            if (magSq2 > 0.0f) {
                nr = __frsqrte(magSq2);
                nr = 0.5 * nr * -(((f64) magSq2 * (nr * nr)) - 3.0);
                nr = 0.5 * nr * -(((f64) magSq2 * (nr * nr)) - 3.0);
                magSq2 = (f32) ((f64) magSq2 * (0.5 * nr * -(((f64) magSq2 * (nr * nr)) - 3.0)));
            } else if (magSq2 < 0.0f) {
                magSq2 = __float_nan;
            } else {
                sp10 = magSq2;
                cls = M2C_FIELD(&sp10, s32 *, 0) & 0x7F800000;
                switch (cls) {
                case 0x7F800000:
                    if (M2C_FIELD(&sp10, s32 *, 0) & 0x7FFFFF) {
                        cls = 1;
                    } else {
                        cls = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_FIELD(&sp10, s32 *, 0) & 0x7FFFFF) {
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
                    magSq2 = __float_nan;
                }
            }
            M2C_FIELD(mtx, f32 *, 0x8C) = 2.5f * ((1.0f - dotAbs) * (gUpdateTimeDelta * (magSq2 / (0.7853982f * M2C_FIELD(mtx, f32 *, 0x90)))));

            for (i = 0; i < 0x40; i += 4) {
                M2C_FIELD(mtx, u32 *, i) = M2C_FIELD(&Matrix::identity, u32 *, i);
            }
            mtx->Scale3x3(mtx, M2C_FIELD(mtx, f32 *, 0x88));
            spB0.SetRotateAroundAxis(M2C_FIELD(mtx, MKVector3 *, 0x70), M2C_FIELD(mtx, f32 *, 0x8C));
            mtx->Multiply3x3(mtx, &spB0);
            mtx->unk30 = M2C_FIELD(mtx, f32 *, 0x40);
            mtx->unk34 = M2C_FIELD(mtx, f32 *, 0x44);
            mtx->unk38 = M2C_FIELD(mtx, f32 *, 0x48);
            mtx->unk3C = 1.0f;
        }
    }
}
