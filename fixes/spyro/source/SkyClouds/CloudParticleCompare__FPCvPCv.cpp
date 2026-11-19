s32 CloudParticleCompare(const void *arg0, const void *arg1) {
    return -(s32) (M2C_FIELD(*(void *const *) arg0, f32 *, 0x38) - M2C_FIELD(*(void *const *) arg1, f32 *, 0x38));
}
