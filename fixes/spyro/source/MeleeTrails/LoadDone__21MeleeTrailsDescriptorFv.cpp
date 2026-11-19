void MeleeTrailsDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    InitMeleeTrailData((char *) &this->unkE8);
}
