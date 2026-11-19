void FuryFXElectricity::Deinit() {
    MKMaterial *temp_r3_779;
    MKMaterial *temp_r3_784;
    MKMaterial *temp_r3_789;
    ManagedLight *temp_r4_794;

    temp_r3_779 = this->unkA8;
    if (temp_r3_779 != NULL) {
        MKMaterial_Destroy(temp_r3_779);
    }
    temp_r3_784 = this->unkC8;
    if (temp_r3_784 != NULL) {
        MKMaterial_Destroy(temp_r3_784);
    }
    temp_r3_789 = this->unkCC;
    if (temp_r3_789 != NULL) {
        MKMaterial_Destroy(temp_r3_789);
    }
    temp_r4_794 = this->unkC4;
    if (temp_r4_794 != NULL) {
        ((LightManager *) gb.unk80)->FreeManagedLight(temp_r4_794);
    }
    M2C_FIELD(&gb, TimeDeltaModifier *, 0x2CC).Disable(this->unk188);
    this->unk188 = -1;
    FuryFX::Deinit();
}
