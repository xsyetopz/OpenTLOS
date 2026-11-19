void MineCartDoorDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    M2C_FIELD(this, void **, 0xE4) = ((MKAnimScript *) this->unk34)->GetAnim("Opening");
    this->unkE8 = (long) (((MKAnimScript *) this->unk34)->GetAnim("Open"));
    this->unkEC = (long) (((MKAnimScript *) this->unk34)->GetAnim("Closing"));
    this->unkF0 = (long) (((MKAnimScript *) this->unk34)->GetAnim("Closed"));
}
