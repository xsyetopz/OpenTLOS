void SteamTrainCabooseDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    M2C_FIELD(this, void **, 0xE4) = ((MKAnimScript *) this->unk34)->GetAnim("idle");
    this->unkE8 = (long) (((MKAnimScript *) this->unk34)->GetAnim("idle"));
    this->unkEC = (long) (((MKAnimScript *) this->unk34)->GetAnim("flinch"));
    this->unkF0 = (long) (((MKAnimScript *) this->unk34)->GetAnim("crash"));
    this->unkF4 = (long) (checked_cast<Explosion3 *, MKProp>(gMK->CreateProp("Explosion3")));
}
