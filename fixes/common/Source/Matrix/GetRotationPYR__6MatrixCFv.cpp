extern "C" double atan2(double, double);

MKVector3 Matrix::GetRotationPYR(void) const {
    MKVector3 result;
    Matrix sp20;
    s32 *d;
    const s32 *q;
    s32 i;
    s32 w;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 absU0;
    f32 absU4;

    d = (s32 *) &sp20 - 1;
    q = (const s32 *) this - 1;
    for (i = 0; i < 8; i++) {
        w = q[1];
        q += 2;
        d[1] = w;
        d += 2;
        d[0] = q[0];
    }

    if (sp20.unk0 < 0.0f) {
        absU0 = -sp20.unk0;
    } else {
        absU0 = sp20.unk0;
    }
    if (absU0 < 0.001f) {
        if (sp20.unk4 < 0.0f) {
            absU4 = -sp20.unk4;
        } else {
            absU4 = sp20.unk4;
        }
        if (absU4 < 0.001f) {
            sp18 = 0.0f;
            goto roll;
        }
    }
    if (sp20.unk0 > 0.0f) {
        sp18 = (f32) atan2(-sp20.unk4, sp20.unk0);
    } else if (sp20.unk0 < 0.0f) {
        sp18 = (f32) atan2(sp20.unk4, -sp20.unk0);
    } else {
        sp18 = 0.0f;
    }
roll:
    sp20.RotateRoll(&sp20, -sp18);
    sp14 = (f32) atan2(sp20.unk8, sp20.unk0);
    sp20.RotateYaw(&sp20, -sp14);
    sp10 = (f32) atan2(sp20.unk24, sp20.unk28);
    M2C_FIELD(&result, f64 *, 0) = M2C_FIELD(&sp10, f64 *, 0);
    M2C_FIELD(&result, f64 *, 8) = M2C_FIELD(&sp18, f64 *, 0);
    return result;
}
