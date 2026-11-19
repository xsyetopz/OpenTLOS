void CynderElecAttack::Deinit() {
    ManagedLight *temp_r4_51;

    temp_r4_51 = this->unk15C;
    if (temp_r4_51 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_51);
    }
    if (this->unk160 != NULL) {
        ((EnergyBeam *) *(EnergyBeam **) ((s8 *) checked_cast<CynderElecAttackDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + 0xF0))->FreeEnergyBeam(this->unk160);
        this->unk160 = NULL;
    }
    Projectile::Deinit();
}
