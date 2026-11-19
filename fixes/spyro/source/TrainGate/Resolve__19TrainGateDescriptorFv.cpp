void TrainGateDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    M2C_FIELD(this, MKAnim **, 0xE4) = (MKAnim *) ((MKAnimScript *) this->unk34)->GetAnim("closed");
    this->unkE8 = (long) (((MKAnimScript *) this->unk34)->GetAnim("opening"));
    this->unkEC = (long) (((MKAnimScript *) this->unk34)->GetAnim("open"));
}
