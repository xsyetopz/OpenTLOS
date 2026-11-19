f32 ExplosiveBarrel::GetRadius() {
    ExplosiveBarrelDescriptor *desc;

    desc = checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    return desc->unk174;
}
