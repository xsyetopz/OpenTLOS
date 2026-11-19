f32 SplineTools_GetNodeTime(const KDUniformSpline &arg0, int arg1) {
    f32 sum = 0.0f;
    s32 i;
    u8 *node = (u8 *) arg0.unkC;

    for (i = 0; i < arg1; i++) {
        sum += M2C_FIELD(node, f32 *, 0x1C);
        node += 0x20;
    }
    return sum / arg0.unk8;
}
