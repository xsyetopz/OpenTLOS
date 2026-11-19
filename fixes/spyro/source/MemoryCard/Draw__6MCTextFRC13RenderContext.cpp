s8 *MemoryCard_String(char *arg0, int arg1);

void MCText::Draw(const RenderContext &arg0) {
    char spF0[0x20];
    Matrix sp60;
    f64 sp58;
    f64 sp50;
    f64 sp40;
    f64 sp48;
    f64 sp30;
    f64 sp38;
    f64 sp20;
    f64 sp28;
    f64 sp10;
    f64 sp18;
    f32 temp_f3_134;
    s32 temp_r3_93;
    s32 temp_r4_123;
    s32 temp_r4_72;
    u32 color;
    Attributes &attr = M2C_FIELD(this, Attributes *, 0x18);

    sp58 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp50 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(&sp58, f32 *, 0x4) = 1.0f;
    if ((M2C_FIELD(this, s32 *, 0x6C) >= 0) && (M2C_FIELD(this, MKFont **, 0x64) != NULL) && !(attr.unk34 <= 0.0f)) {
        if (attr.unk38 <= 0.0f) {
            return;
        }
        RenderContext spA0;
        spA0.AddState(arg0, attr);
        color = (u32) (128.0f * M2C_FIELD(&spA0, f32 *, 0x48)) << 16;
        color = ((u32) (128.0f * M2C_FIELD(&spA0, f32 *, 0x4C)) << 24) | color;
        color = ((u32) (128.0f * M2C_FIELD(&spA0, f32 *, 0x44)) << 8) | color;
        color = ((u32) (128.0f * M2C_FIELD(&spA0, f32 *, 0x40))) | color;
        temp_r4_72 = attr.unk3C;
        if (!(temp_r4_72 & 3)) {
            M2C_FIELD(&sp50, f32 *, 0x0) = attr.unk34 * 0.5f;
        } else if (temp_r4_72 & 1) {
            M2C_FIELD(&sp50, f32 *, 0x0) = 0.0f;
        } else {
            M2C_FIELD(&sp50, f32 *, 0x0) = attr.unk34 / -2.0f;
        }
        temp_r3_93 = attr.unk3C;
        if (!(temp_r3_93 & 0xC)) {
            M2C_FIELD(&sp50, f32 *, 0x4) = attr.unk38 * 0.5f;
        } else if (temp_r3_93 & 4) {
            M2C_FIELD(&sp50, f32 *, 0x4) = 0.0f;
        } else {
            M2C_FIELD(&sp50, f32 *, 0x4) = attr.unk38 / -2.0f;
        }
        sp60.SetIdentity();
        sp60.Translate(&sp60, *((MKVector3 *) &sp50));
        ((Matrix *) &spA0)->Multiply(&sp60, (Matrix *) &spA0);
        temp_r4_123 = M2C_FIELD(this, s32 *, 0x6C);
        if ((temp_r4_123 >= 0) && (((u32 *) gpTranslation_StringArray)[temp_r4_123] != 0U)) {
            MemoryCard_String(spF0, temp_r4_123);
            temp_f3_134 = M2C_FIELD(this, f32 *, 0x70);
            if ((temp_f3_134 != 0.0f) || (M2C_FIELD(this, f32 *, 0x74) != 0.0f)) {
                M2C_FIELD(&sp20, f32 *, 0x0) = spA0.unk30 + temp_f3_134;
                M2C_FIELD(&sp20, f32 *, 0x4) = spA0.unk34 + M2C_FIELD(this, f32 *, 0x74);
                M2C_FIELD(&sp28, f32 *, 0x0) = spA0.unk38;
                sp48 = sp28;
                sp40 = sp20;
                spA0.unk30 = M2C_FIELD(&sp40, f32 *, 0x0);
                spA0.unk34 = M2C_FIELD(&sp40, f32 *, 0x4);
                spA0.unk38 = M2C_FIELD(&sp48, f32 *, 0x0);
                spA0.unk3C = 1.0f;
                M2C_FIELD(this, MKFont **, 0x64)->DrawString(spF0, attr.unk34, attr.unk38, (Matrix *) &spA0, attr.unk3C, 0x80000000U, 1.0f, 1.0f, NULL, 1U);
                M2C_FIELD(&sp18, f32 *, 0x0) = spA0.unk38;
                M2C_FIELD(&sp10, f32 *, 0x0) = spA0.unk30 - M2C_FIELD(this, f32 *, 0x70);
                M2C_FIELD(&sp10, f32 *, 0x4) = spA0.unk34 - M2C_FIELD(this, f32 *, 0x74);
                sp38 = sp18;
                sp30 = sp10;
                spA0.unk30 = M2C_FIELD(&sp30, f32 *, 0x0);
                spA0.unk34 = M2C_FIELD(&sp30, f32 *, 0x4);
                spA0.unk38 = M2C_FIELD(&sp38, f32 *, 0x0);
                spA0.unk3C = 1.0f;
            }
            M2C_FIELD(this, MKFont **, 0x64)->DrawString(spF0, attr.unk34, attr.unk38, (Matrix *) &spA0, attr.unk3C, color, 1.0f, 1.0f, NULL, 1U);
        }
    }
}
