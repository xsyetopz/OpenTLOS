MKVector3 KDUniformSpline::GetNextPositionFast(float farg0, Matrix *arg2, int *arg3, float *arg4) const {
    MKVector3 result;
    f32 t;
    f32 dur;
    f32 frac;
    f32 frac2;
    f32 frac3;

    if (((s32) this->unk4 > 0) && (this->unk8 == 0.0f)) {
        return *(MKVector3 *) this->unkC;
    }
    t = farg0 * this->unk8;
    if (*arg4 == 0.0f) {
        *arg3 = -1;
    }
    if (t >= *arg4) {
        while ((t >= *arg4) && ((s32) *arg3 < (s32) (this->unk4 - 2))) {
            *arg3 += 1;
            *arg4 += *(f32 *) (this->unkC + ((*arg3 << 5) + 0x1C));
        }
        GetMatrix(*arg3, arg2);
    }
    dur = *(f32 *) (this->unkC + ((*arg3 << 5) + 0x1C));
    frac = (t - (*arg4 - dur)) / dur;
    frac2 = frac * frac;
    frac3 = frac * frac2;
    result.unk0 = arg2->unk30 + ((frac * arg2->unk20) + ((frac3 * arg2->unk0) + (frac2 * arg2->unk10)));
    result.unk4 = arg2->unk34 + ((frac * arg2->unk24) + ((frac3 * arg2->unk4) + (frac2 * arg2->unk14)));
    result.unk8 = arg2->unk38 + ((frac * arg2->unk28) + ((frac3 * arg2->unk8) + (frac2 * arg2->unk18)));
    return result;
}
