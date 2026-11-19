void LightManager::FreeManagedLight(ManagedLight *arg0) {
    s32 idx;

    if (arg0 != NULL) {
        M2C_FIELD(arg0, s8 *, 0x34) = 0;
        M2C_FIELD(arg0, s8 *, 0x48) = 0;
        if (arg0->unk3C != NULL) {
            OmniLight_Destroy((OmniLight *) arg0->unk3C);
            arg0->unk3C = NULL;
        }
        idx = M2C_FIELD(arg0, s32 *, 0x44);
        if (idx >= 0) {
            M2C_FIELD(((s8 *) this) + (idx * 4), s32 *, 0x4C) = 0;
            M2C_FIELD(arg0, s32 *, 0x44) = -1;
        }
    }
}
