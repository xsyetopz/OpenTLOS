void TriggerPolyObject::LoadDone() {
    f32 temp_f1_126;
    f32 temp_f1_134;
    s32 var_r3_120;
    s32 var_r5_119;

    this->unk88.Init(this->unk84, this->unk80);
    var_r5_119 = 0;
    var_r3_120 = 0;
    while (var_r5_119 < this->unk80) {
        temp_f1_126 = M2C_FIELD(this->unk84, f32 *, var_r3_120 + 4);
        if (temp_f1_126 < this->unk88.unk1C) {
            this->unk88.unk1C = temp_f1_126;
        }
        temp_f1_134 = M2C_FIELD(this->unk84, f32 *, var_r3_120 + 4);
        if (temp_f1_134 > this->unkA8) {
            this->unkA8 = temp_f1_134;
        }
        var_r5_119 += 1;
        var_r3_120 += 0x10;
    }
}
