void TeslaTower::Deinit() {
    TeslaTowerDescriptor *desc;

    KDSound_Stop((int *) &this->unk114);
    KDSound_Stop((int *) &this->unk13C);
    KDSound_Stop((int *) &this->unk164);
    KDSound_Stop((int *) &this->unk18C);
    ((KDSpline *) &this->unk90)->Deinit();
    desc = checked_cast<TeslaTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((EnergyBeam *) desc->unk70)->FreeEnergyBeam(this->unk110);
    this->unk110 = NULL;
    KDProp::Deinit();
}
