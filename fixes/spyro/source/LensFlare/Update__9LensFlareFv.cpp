void LensFlare::Update() {
    MKZRequest *temp_r31_591;
    f64 temp_f1_597;
    s32 temp_r3_594;

    temp_r31_591 = this->unk8;
    if (temp_r31_591 != NULL) {
        temp_r3_594 = this->unk94;
        if (temp_r3_594 <= 0) {
            temp_f1_597 = M2C_FIELD(temp_r31_591, f64 *, 0);
            this->unk10 = temp_f1_597;
            this->unk18 = M2C_FIELD(temp_r31_591, f64 *, 8);
            this->unk20 = temp_r31_591->unk10;
            this->unk24 = (u8) temp_r31_591->unk14;
            __copy(&this->unk25, (M2C_UNK *) &temp_r31_591->pad15, 0xB, temp_f1_597);
            this->unk30 = (s32) temp_r31_591->unk20;
            return;
        }
        this->unk94 = temp_r3_594 - 1;
    }
}
