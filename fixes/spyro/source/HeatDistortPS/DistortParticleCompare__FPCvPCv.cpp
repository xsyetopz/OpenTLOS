s32 DistortParticleCompare(const void *arg0, const void *arg1) {
    return -(s32) (M2C_FIELD(*(const void **) arg0, f32 *, 0x5C) - M2C_FIELD(*(const void **) arg1, f32 *, 0x5C));
}
