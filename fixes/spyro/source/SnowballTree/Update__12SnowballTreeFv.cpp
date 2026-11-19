void *SnowballTree::Update() {
    SnowballTreeDescriptor *desc;
    f32 timer;

    KDProp::Update();
    timer = this->unkBC;
    if (timer > 0.0f) {
        this->unkBC = timer - gUpdateTimeDelta;
        if (this->unkBC <= 0.0f) {
            desc = checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            this->unkB8 = KDSound_Play3d(desc->unk7C, &this->unkA0, 0U, -1, 0.0f, false);
        }
    }
    desc = checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((desc->unk7C != 0) && ((u8) KDSound_IsVoicePlaying(this->unkB8) == 0) && (this->unkBC <= 0.0f)) {
        desc = checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        timer = desc->unk84;
        desc = checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        this->unkBC = MKRand_Float((int *) &gViewSeed, desc->unk80, timer);
    }
    if (((u8) this->unkC4 != 0) && (this->unk80->unk2C & 1)) {
        desc = checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        this->unk80->SetAnim((MKAnim *) desc->unk88, 1.0f, 0.0f, 0, -1);
        this->unkC4 = 0;
    }
}
