void EnemyHud_Modified(MKProp *arg0, float arg1, float arg2, float arg3) {
    if ((arg0 == NULL) || ((u32) M2C_FIELD(&gb, u32 *, 0x360) == 0U) || ((u32) M2C_FIELD(&gb, u32 *, 0x360) == (u32) arg0)) {
        M2C_FIELD(&hudData, s8 *, 0x6D) = 0;
        if (arg0 != NULL) {
            HudItem_Modified((HudItem *) ((s8 *) &hudItem + 0x20));
            M2C_FIELD(&hudData, f32 *, 0x3C) = 2.0f;
        } else if ((u8) M2C_FIELD(&hudItem, u8 *, 0x39) == 0) {
            HudItem_SetState((HudItem *) ((s8 *) &hudItem + 0x20), (HudItemState) 0, 1U);
            M2C_FIELD(&hudData, f32 *, 0x3C) = 0.0f;
        }
        M2C_FIELD(&hudData, f32 *, 0x64) = arg2;
        if (arg0 != (MKProp *) M2C_FIELD(&hudData, MKProp **, 0x5C)) {
            M2C_FIELD(&hudData, f32 *, 0x60) = arg1;
        }
        M2C_FIELD(&hudData, f32 *, 0x68) = arg3;
        M2C_FIELD(&hudData, MKProp **, 0x5C) = arg0;
    }
}
