f32 DynamiteExplosion::Resolve() {
    MKProp::Resolve();
    this->unk4C = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) ((MKSceneManager *) gMK)->FindDescriptor("IceCube"));
}
