void BurningWick::Burn(const bool &arg0, const float &arg1) {
    this->unk84 = *(u8 *) &arg0;
    if (this->unk84 != 0) {
        this->unk74 = 0.0f;
        this->unk7C = arg1;
        return;
    }
    this->unk74 = 0.0f;
    this->unk7C = 0.1f;
}
