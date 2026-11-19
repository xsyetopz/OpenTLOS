f32 SeeSaw::Resolve() {
    SeeSawDescriptor *desc;
    SeeSawDescriptor *desc2;

    MKProp::Resolve();
    desc = checked_cast<SeeSawDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    desc2 = checked_cast<SeeSawDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unkF0)->Init(desc2->unk74, desc->unk78);
}
