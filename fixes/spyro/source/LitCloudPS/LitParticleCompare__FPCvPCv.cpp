s32 LitParticleCompare(const void *arg0, const void *arg1) {
    void *p0;
    void *p1;

    p0 = *(void *const *) arg0;
    p1 = *(void *const *) arg1;
    return -(s32) (M2C_FIELD(p0, f32 *, 0x38) - M2C_FIELD(p1, f32 *, 0x38));
}
