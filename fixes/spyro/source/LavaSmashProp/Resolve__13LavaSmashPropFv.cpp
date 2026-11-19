f32 LavaSmashProp::Resolve() {
    LavaSmashPropDescriptor *desc;
    LavaSmashPropDescriptor *fade;

    Shatterable::Resolve();
    desc = checked_cast<LavaSmashPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    fade = checked_cast<LavaSmashPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unk1A8)->Init(fade->unk180, desc->unk184);
    this->unk1D0 = 0;
}
