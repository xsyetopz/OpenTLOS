void KDCameraDeltaDrag::Update(const MKVector3 &arg0) {
    f32 temp_f0_143;
    f32 temp_f0_85;
    f32 temp_f1_118;
    f32 temp_f1_145;
    f32 temp_f1_87;
    f32 var_f1_102;
    f32 var_f1_135;
    f32 var_f2_121;
    f32 var_f2_144;
    f32 var_f2_86;
    u8 var_r0_119;

    if ((u8) this->unk10 != 0) {
        if ((u8) this->unk11 != 0) {
            SmoothDrag(0.0f);
            temp_f0_85 = this->unk8;
            var_f2_86 = this->unk0;
            temp_f1_87 = this->unk4;
            if (var_f2_86 < temp_f0_85) {

            } else {
                var_f2_86 = temp_f0_85;
            }
            if (var_f2_86 > temp_f1_87) {

            } else {
                var_f2_86 = temp_f1_87;
            }
            this->unk0 = var_f2_86;
            var_f1_102 = this->unk0;
            if (var_f1_102 < 0.0f) {
                var_f1_102 = -var_f1_102;
            }
            if (var_f1_102 < 1.0f) {
                this->unk0 = 0.0f;
                this->unkC = 0.0f;
                this->unk11 = 0;
                this->unk10 = 0;
            }
        } else {
            temp_f1_118 = M2C_FIELD(&arg0, f32 *, 8);
            var_r0_119 = 0;
            var_f2_121 = -temp_f1_118;
            if ((temp_f1_118 >= -0.05f) && (temp_f1_118 <= 0.05f)) {
                var_r0_119 = 1;
            }
            if (var_r0_119 != 0) {
                var_f2_121 = 0.0f;
            }
            var_f1_135 = 0.0f;
            if (var_f2_121 != 0.0f) {
                var_f1_135 = var_f2_121 + this->unk0;
            }
            SmoothDrag(var_f1_135);
            temp_f0_143 = this->unk8;
            var_f2_144 = this->unk0;
            temp_f1_145 = this->unk4;
            if (var_f2_144 < temp_f0_143) {

            } else {
                var_f2_144 = temp_f0_143;
            }
            if (var_f2_144 > temp_f1_145) {

            } else {
                var_f2_144 = temp_f1_145;
            }
            this->unk0 = var_f2_144;
        }
    }
}
