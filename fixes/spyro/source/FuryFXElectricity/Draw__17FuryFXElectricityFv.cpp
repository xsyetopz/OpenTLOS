void FuryFXElectricity::Draw() {
    s32 temp_r0_826;
    s32 var_r30_839;
    s32 var_r31_840;

    temp_r0_826 = this->unk90;
    if ((temp_r0_826 == 2) || (temp_r0_826 == 3) || (temp_r0_826 == 4)) {
        DrawElectricityRing();
        if ((s32) this->unk90 != 4) {
            var_r30_839 = 0;
            var_r31_840 = 0;
            do {
                DrawWindyRing((FuryFXElectricity::WindyRing *) ((s8 *) this + (var_r31_840 + 0xD0)));
                var_r30_839 += 1;
                var_r31_840 += 0x10;
            } while (var_r30_839 < 3);
        }
    }
}
