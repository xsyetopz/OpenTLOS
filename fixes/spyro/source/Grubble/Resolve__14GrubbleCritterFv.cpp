f32 GrubbleCritter::Resolve() {
    s32 temp_r0_1151;
    s32 var_r3_1145;
    s32 var_r6_1146;

    MKProp::Resolve();
    var_r3_1145 = 0;
    var_r6_1146 = 0;
    while (var_r6_1146 < this->unk90) {
        temp_r0_1151 = var_r3_1145 + 0x60;
        var_r6_1146 += 1;
        var_r3_1145 += 0x70;
        M2C_FIELD(this->unk170, s32 *, temp_r0_1151) = 0;
    }
}
