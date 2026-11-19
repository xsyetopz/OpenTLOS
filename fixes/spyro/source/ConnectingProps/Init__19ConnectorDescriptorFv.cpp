void ConnectorDescriptor::Init() {
    ConnectorDescriptor **first;

    MKPropDescriptor::Init();
    first = (ConnectorDescriptor **) ConnectorDescriptor::pFirstDesc;
    this->unk68 = *first;
    this->unk64 = NULL;
    if (*first != NULL) {
        (*first)->unk64 = this;
    }
    *first = this;
    this->unk60 = M2C_FIELD(*gMK, void *(**)(void **), 0x7C)(gMK);
}
