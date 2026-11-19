u8 BoundingRegion::IsPointInBoundaryRect(const MKVector3 &arg0) {
    Matrix sp40;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 x;
    f32 z;
    Matrix *temp_r4_189;
    void *temp_r3_185;
    u8 var_r3_232;

    x = arg0.unk0;
    z = arg0.unk8;
    temp_r3_185 = M2C_FIELD(this, void **, 0);
    if (temp_r3_185 != NULL) {
        temp_r4_189 = M2C_FIELD(temp_r3_185, Matrix **, 0x30);
        if (temp_r4_189 != NULL) {
            sp40.Inverse(temp_r4_189);
            sp10 = sp40.unk30 + ((arg0.unk8 * sp40.unk20) + ((arg0.unk0 * sp40.unk0) + (arg0.unk4 * sp40.unk10)));
            sp14 = sp40.unk34 + ((arg0.unk8 * sp40.unk24) + ((arg0.unk0 * sp40.unk4) + (arg0.unk4 * sp40.unk14)));
            sp18 = sp40.unk38 + ((arg0.unk8 * sp40.unk28) + ((arg0.unk0 * sp40.unk8) + (arg0.unk4 * sp40.unk18)));
            x = sp10;
            z = sp18;
        }
    }
    var_r3_232 = 0;
    if ((x > M2C_FIELD(this, f32 *, 0xC)) && (x < this->unk10) && (z > this->unk14) && (z < this->unk18)) {
        var_r3_232 = 1;
    }
    return var_r3_232;
}
