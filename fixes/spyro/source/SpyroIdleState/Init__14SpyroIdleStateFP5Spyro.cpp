void SpyroIdleState::Init(Spyro *arg0) {
    SpyroDescriptor *desc;

    this->unk10 = arg0;
    this->unk14.Init((KDStateMachine<SpyroIdleState>::State *) &SpyroIdleState::states, NULL);
    this->unk28 = 0.0f;
    this->unk2C = 0;
    desc = checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk10->unk0);
    this->unk30.Init(M2C_FIELD(desc, MKAnimScript **, 0x34));
    this->unk3C = 0;
    this->unk44 = 0;
    this->unk40 = 0;
    this->unk48 = -1;
}
