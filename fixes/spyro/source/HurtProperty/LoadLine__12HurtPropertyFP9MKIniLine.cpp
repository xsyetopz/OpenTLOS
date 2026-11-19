s32 HurtProperty::LoadLine(MKIniLine *arg0) {
    if (this->unk18 == NULL) {
        this->unk18 = arg0;
    }
    return (u8) (arg0->LoadString("origin", (const char **) &this->unk10, 0) != 0);
}
