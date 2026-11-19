f32 FightElevator::Resolve() {
    f32 temp_f1;

    Platform::Resolve();
    this->unk298 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) ((MKSceneManager *) gMK)->FindDescriptor("FightElevatorAnchor"));
    temp_f1 = this->unk188;
    if (temp_f1 > 0.0f) {
        this->unk1A8 /= temp_f1;
        return temp_f1;
    }
    this->unk1A8 = 0.0f;
    return temp_f1;
}
