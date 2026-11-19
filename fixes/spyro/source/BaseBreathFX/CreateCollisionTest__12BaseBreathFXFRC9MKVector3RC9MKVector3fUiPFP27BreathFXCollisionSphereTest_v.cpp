void BaseBreathFX::CreateCollisionTest(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, unsigned int arg3, void (*arg4)(BreathFXCollisionSphereTest *)) {
    s32 var_ctr_101;
    s32 var_r8_99;
    u8 *temp_r9_103;
    u8 *temp_r4_129;
    u8 *temp_r11_133;
    u8 *temp_r4_139;

    if (this->unk94 >= 0.125f) {
        var_r8_99 = 0;
        this->unk94 = 0.0f;
        var_ctr_101 = 0x1E;
loop_2:
        temp_r9_103 = (u8 *) this->unk90;
        if ((u8) *(temp_r9_103 + (var_r8_99 + 0x6C)) == 0) {
            M2C_FIELD((((u8 *) this->unk90) + var_r8_99), s8 *, 0x6C) = 1;
            M2C_FIELD((((u8 *) this->unk90) + var_r8_99), u32 *, 0x68) = arg3;
            M2C_FIELD((((u8 *) this->unk90) + var_r8_99), f32 *, 0x30) = 0.0f;
            M2C_FIELD((((u8 *) this->unk90) + var_r8_99), f32 *, 0x34) = arg2;
            temp_r4_129 = ((u8 *) this->unk90) + (var_r8_99 + 0x20);
            M2C_FIELD(temp_r4_129, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r4_129, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            temp_r11_133 = ((u8 *) this->unk90) + (var_r8_99 + 0x10);
            M2C_FIELD(temp_r11_133, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r11_133, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            temp_r4_139 = ((u8 *) this->unk90) + var_r8_99;
            M2C_FIELD(temp_r4_139, f64 *, 0) = (f64) M2C_FIELD(temp_r11_133, f64 *, 0);
            M2C_FIELD(temp_r4_139, f64 *, 8) = (f64) M2C_FIELD(temp_r11_133, f64 *, 8);
            M2C_FIELD((((u8 *) this->unk90) + var_r8_99), void (**)(BreathFXCollisionSphereTest *), 0x38) = arg4;
            M2C_FIELD((((u8 *) this->unk90) + var_r8_99), s32 *, 0x3C) = 0;
            M2C_FIELD((((u8 *) this->unk90) + var_r8_99), s32 *, 0x40) = 0;
            return;
        }
        var_r8_99 += 0x70;
        var_ctr_101 -= 1;
        if (var_ctr_101 == 0) {
            return;
        }
        goto loop_2;
    }
}
