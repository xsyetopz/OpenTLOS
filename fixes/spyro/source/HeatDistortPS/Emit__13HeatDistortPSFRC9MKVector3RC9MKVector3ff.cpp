void HeatDistortPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, float arg3) {
    MKVector3 sp48;
    MKVector3 sp38;
    MKVector3 sp28;
    s32 var_ctr_346;
    s32 var_r30_345;

    if ((s32) this->unkC < 0x63) {
        var_r30_345 = 0;
        var_ctr_346 = 0x64;
        do {
            if (M2C_FIELD(this->unk4, u8 *, var_r30_345 + 0x60) == 0) {
                M2C_FIELD(this->unk4, s8 *, var_r30_345 + 0x60) = 1;
                M2C_FIELD(this->unk4, MKVector3 *, var_r30_345) = arg0;
                M2C_FIELD(this->unk4, MKVector3 *, var_r30_345 + 0x40) = arg1;
                M2C_FIELD(this->unk4, f32 *, var_r30_345 + 0x50) = arg2;
                M2C_FIELD(this->unk4, f32 *, var_r30_345 + 0x54) = arg3;
                M2C_FIELD(this->unk4, f32 *, var_r30_345 + 0x58) = arg3;
                sp28.unk0 = 6.2831855f;
                sp28.unk4 = 6.2831855f;
                sp28.unk8 = 6.2831855f;
                sp38.unk0 = 0.0f;
                sp38.unk4 = 0.0f;
                sp38.unk8 = 0.0f;
                sp48 = KDRand_Vector(sp38, sp28);
                M2C_FIELD(this->unk4, MKVector3 *, var_r30_345 + 0x30) = sp48;
                M2C_FIELD(this->unk8, s8 **, this->unkC * 4) = (s8 *) this->unk4 + var_r30_345;
                this->unkC += 1;
                return;
            }
            var_r30_345 += 0x70;
            var_ctr_346 -= 1;
        } while (var_ctr_346 != 0);
    }
}
