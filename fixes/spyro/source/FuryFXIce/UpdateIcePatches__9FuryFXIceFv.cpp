void FuryFXIce::UpdateIcePatches() {
    void **slot;
    void **freeSlot;
    u8 *patch;
    void *tmp;
    f32 t;
    f32 frac;
    f32 base;
    s32 state;

    this->unkB0 &= ~0x80;
    slot = (void **) this->unk110;
    while (slot != NULL) {
        patch = (u8 *) *slot;
        if (patch == NULL) {
            return;
        }
        M2C_FIELD(patch, f32 *, 0x48) = M2C_FIELD(patch, f32 *, 0x48) - gUpdateTimeDelta;
        this->unkB0 |= 0x80;
        state = M2C_FIELD(patch, s32 *, 0x50);
        switch (state) {
        case 1:
            t = M2C_FIELD(patch, f32 *, 0x48);
            if (t >= 0.5f) {
                t = 0.5f;
            }
            if (t <= 0.0f) {
                t = 0.0f;
            }
            M2C_FIELD(patch, f32 *, 0x48) = t;
            M2C_FIELD(patch, f32 *, 0x44) = M2C_FIELD(patch, f32 *, 0x40) * (1.0f - (t / 0.5f));
            if (t <= 0.0f) {
                M2C_FIELD(patch, s32 *, 0x50) = 2;
                M2C_FIELD(patch, f32 *, 0x48) = 1.5f;
                M2C_FIELD(patch, f32 *, 0x44) = M2C_FIELD(patch, f32 *, 0x40);
            }
            break;
        case 2:
            if (M2C_FIELD(patch, f32 *, 0x48) <= 0.0f) {
                M2C_FIELD(patch, s32 *, 0x50) = 3;
                M2C_FIELD(patch, f32 *, 0x48) = 0.25f;
            }
            break;
        case 3:
            t = M2C_FIELD(patch, f32 *, 0x48);
            if (t >= 0.25f) {
                t = 0.25f;
            }
            if (t <= 0.0f) {
                t = 0.0f;
            }
            M2C_FIELD(patch, f32 *, 0x48) = t;
            base = M2C_FIELD(patch, f32 *, 0x40);
            frac = t / 0.25f;
            M2C_FIELD(patch, f32 *, 0x44) = (0.25f * base) * (1.0f - frac) + base;
            M2C_FIELD(patch, f32 *, 0x4C) = frac;
            if (t <= 0.0f) {
                M2C_FIELD(patch, s32 *, 0x50) = 0;
                M2C_FIELD(patch, f32 *, 0x48) = 0.0f;
                freeSlot = (void **) this->unk110;
                this->unk110 = freeSlot + 1;
                tmp = *freeSlot;
                *freeSlot = *slot;
                *slot = tmp;
            }
            break;
        default:
            break;
        }
        slot = slot + 1;
    }
}
