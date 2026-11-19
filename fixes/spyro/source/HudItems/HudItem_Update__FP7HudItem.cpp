u8 HudItem_Update(HudItem *arg0) {
    s32 temp_r0_117;
    u8 (*temp_r12_156)(s32);

    temp_r0_117 = arg0->unk0;
    switch (temp_r0_117) {
    case 2:
        break;
    case 1:
        arg0->unk10 -= gUpdateTimeDelta;
        if (arg0->unk10 <= 0.0f) {
            HudItem_SetState(arg0, (HudItemState) 2, 0U);
        }
        break;
    case 3:
        arg0->unk10 -= gUpdateTimeDelta;
        if (arg0->unk10 <= 0.0f) {
            HudItem_SetState(arg0, (HudItemState) 0, 0U);
        }
        break;
    }
    temp_r12_156 = M2C_FIELD(arg0, u8 (**)(s32), 0x4);
    if ((temp_r12_156 != NULL) && (temp_r12_156(arg0->unk14) != 0) && ((u8) arg0->unk19 == 0)) {
        return 1U;
    }
    return arg0->unk19;
}
