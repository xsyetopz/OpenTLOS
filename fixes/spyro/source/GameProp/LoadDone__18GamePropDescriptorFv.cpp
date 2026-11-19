void GamePropDescriptor::LoadDone() {
    KDPropExDescriptor::LoadDone();
    if (this->unk34 != NULL) {
        if (this->unkC0 != NULL) {
            this->unkC0 = (s8 *) ((MKAnimScript *) this->unk34)->GetAnim((const char *) this->unkC0);
        }
        if (this->unkC4 != NULL) {
            this->unkC4 = (s8 *) ((MKAnimScript *) this->unk34)->GetAnim((const char *) this->unkC4);
        }
        if (this->unkC8 != NULL) {
            this->unkC8 = (s8 *) ((MKAnimScript *) this->unk34)->GetAnim((const char *) this->unkC8);
        }
    }
    this->unkC |= 0x20;
}
