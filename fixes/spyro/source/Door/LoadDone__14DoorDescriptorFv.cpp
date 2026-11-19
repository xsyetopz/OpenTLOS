void DoorDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    M2C_FIELD(this, s32 *, 0xE4) = (s32) ((MKAnimScript *) this->unk34)->GetAnim("Closed");
    this->unkE8 = (long) (((MKAnimScript *) this->unk34)->GetAnim("Opening"));
    this->unkEC = (long) (((MKAnimScript *) this->unk34)->GetAnim("Open"));
    this->unkF0 = (long) (((MKAnimScript *) this->unk34)->GetAnim("Closing"));
}
