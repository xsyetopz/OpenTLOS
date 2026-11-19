void MoleTether::Deinit() {
    if (this->unk1F4 != NULL) {
        MoleTetherDescriptor *desc = checked_cast<MoleTetherDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        EnergyBeam *beam = (EnergyBeam *) M2C_FIELD(desc, EnergyBeam **, 0x16C);
        beam->FreeEnergyBeam(this->unk1F4);
        this->unk1F4 = NULL;
    }
    KDSound_Stop((int *) &this->unk1C8);
    Shatterable::Deinit();
}
