void ZapArcFX::Draw() {
    s32 var_r28_684;
    s32 var_r31_685;
    void *temp_r5_688;
    f32 temp_f31_701;
    MKVector4 sp38;

    var_r28_684 = 0;
    var_r31_685 = 0;
    do {
        temp_r5_688 = ((u8 *) this->unkC8) + var_r31_685;
        if ((u8) M2C_FIELD(temp_r5_688, u8 *, 0x48) != 0) {
            temp_f31_701 = 1.0f - (M2C_FIELD(temp_r5_688, f32 *, 0x44) / 0.25f);
            MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(temp_r5_688, s32 *, 0x4C), 1, 1);
            MKModel_SetWorldMatrix(this->unk4, *((Matrix *) temp_r5_688));
            sp38.unk0 = temp_f31_701 * M2C_FIELD(temp_r5_688, f32 *, 0x50);
            sp38.unk4 = temp_f31_701 * M2C_FIELD(temp_r5_688, f32 *, 0x54);
            sp38.unk8 = temp_f31_701 * M2C_FIELD(temp_r5_688, f32 *, 0x58);
            sp38.unkC = 1.0f * M2C_FIELD(temp_r5_688, f32 *, 0x5C);
            MKModel_SetColor(this->unk4, sp38);
            MKModel_Draw(this->unk4, NULL);
        }
        var_r28_684 += 1;
        var_r31_685 += 0x60;
    } while (var_r28_684 < 0x50);
}
