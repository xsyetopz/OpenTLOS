void Platform::PropUpdate() {
    PlatformDescriptor *desc;

    GameProp::PropUpdate();
    this->unk108.BeginUpdate();
    this->unk108.UpdateTilt();
    UpdateMove();
    UpdateSway();
    UpdateRotate();
    UpdateBob();
    this->unk108.EndUpdate();
    desc = checked_cast<PlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((desc->unkFC > 0.0f) && (this->unk175 != 0)) {
        UpdateShadow();
    }
    UpdateScale();
}
