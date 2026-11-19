void CharacterDojoFX::Enable(bool arg0, MKVector4 arg1) {
    if (arg0 != 0) {
        this->unk2C = 1;
    } else {
        this->unk2C = 0;
    }
    this->unk18 = arg1;
    SetDataActive(arg0);
}
