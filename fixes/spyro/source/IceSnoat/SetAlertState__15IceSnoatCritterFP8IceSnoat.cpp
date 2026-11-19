void IceSnoatCritter::SetAlertState(IceSnoat *arg0) {
    IceSnoatCritterDescriptor *desc;

    arg0->unk60 = 2;
    desc = checked_cast<IceSnoatCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    arg0->unk50 = M2C_FIELD(desc, void **, 0x78);
    arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
    arg0->unk54 = 0.0f;
}
