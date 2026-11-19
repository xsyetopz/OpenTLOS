f32 Platform::Resolve() {
    PlatformDescriptor *desc;

    KDPropEx::Resolve();
    this->unk150.Resolve();
    this->unk150.Attach((PlatformAttachment *) ((s8 *) this + 0x15C));
    desc = checked_cast<PlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((desc->unkFC > 0.0f) && (this->unk175 != 0)) {
        UpdateShadow();
    }
}
