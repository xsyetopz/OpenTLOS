void ElectricFence::Draw() {
    s32 var_r30_278;
    s32 var_r31_279;

    var_r30_278 = 0;
    var_r31_279 = 0;
    while (var_r30_278 < unk50) {
        MKModel_Draw(M2C_FIELD(unk4C, MKModel **, var_r31_279 + 0x40), NULL);
        var_r30_278 += 1;
        var_r31_279 += 0x70;
    }
}
