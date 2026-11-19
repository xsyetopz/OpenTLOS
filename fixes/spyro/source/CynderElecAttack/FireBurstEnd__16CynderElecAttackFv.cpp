void CynderElecAttack::FireBurstEnd() {
    ManagedLight *temp_r4_91;

    this->unk158 = 0;
    this->unk150 = NULL;
    this->unk154 = NULL;
    temp_r4_91 = this->unk15C;
    if (temp_r4_91 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_91, false);
    }
    if (this->unk160 != NULL) {
        ((EnergyBeam *) *(EnergyBeam **) ((s8 *) checked_cast<CynderElecAttackDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + 0xF0))->FreeEnergyBeam(this->unk160);
        this->unk160 = NULL;
    }
    Disable();
}
