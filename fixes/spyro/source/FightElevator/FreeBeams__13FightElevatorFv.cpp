void FightElevator::FreeBeams() {
    EnergyBeam::Beam *beam;
    FightElevatorDescriptor *desc;
    s32 off;
    s32 count;

    off = 0;
    desc = checked_cast<FightElevatorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    count = 0;
    do {
        beam = M2C_FIELD(this, EnergyBeam::Beam **, 0x20C + off);
        if (beam != NULL) {
            ((EnergyBeam *) (M2C_FIELD(desc, EnergyBeam **, 0x130)))->FreeEnergyBeam(beam);
            M2C_FIELD(this, EnergyBeam::Beam **, 0x20C + off) = NULL;
        }
        count += 1;
        off += 4;
    } while (count < 6);
}
