void MoleTether::Shatter(bool arg0, MKVector3 *arg1, int arg2, MKVector3 *arg3, bool arg4) {
    if (this->unk1F4 != NULL) {
        MoleTetherDescriptor *desc = checked_cast<MoleTetherDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        EnergyBeam *beam = (EnergyBeam *) M2C_FIELD(desc, EnergyBeam **, 0x16C);
        beam->FreeEnergyBeam(this->unk1F4);
        this->unk1F4 = NULL;
    }
    this->unk1FC = 0;
    Shatterable::Shatter(arg0, arg1, arg2, arg3, arg4, 0U);
}
