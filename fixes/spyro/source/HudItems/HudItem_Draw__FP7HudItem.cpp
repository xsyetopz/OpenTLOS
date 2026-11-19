void HudItem_Draw(HudItem *arg0) {
    void (*temp_r12_55)(s32, f32, f32);
    f32 var_f1_84;

    temp_r12_55 = M2C_FIELD(arg0, void (**)(s32, f32, f32), 0x8);
    if (temp_r12_55 != NULL) {
        switch (arg0->unk0) {
        case 1:
            temp_r12_55(arg0->unk14, 1.0f - (arg0->unk10 / 0.5f), 1.0f);
            return;
        case 2:
            if ((u8) arg0->unk19 != 0) {
                var_f1_84 = 1.0f;
            } else {
                var_f1_84 = -((arg0->unk10 * 0.5f) - 1.0f);
            }
            ((void (*)(s32, f32))temp_r12_55)(arg0->unk14, var_f1_84);
            return;
        case 3:
            ((void (*)(s32, f32))temp_r12_55)(arg0->unk14, arg0->unk10 / 0.5f);
            break;
        }
    }
}
