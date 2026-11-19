void ElecZapCrystal::Draw() {
    MKVector4 color;
    f32 ratio;
    void **entry;
    void *fader;

    MKModel_SetColor(this->unk4, this->unkC8);
    MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, this->unk90, 1U, 1U);
    MKModel_Draw(this->unk4, NULL);
    entry = (void **) this->unkB0;
    while (entry != NULL) {
        fader = *entry;
        if (fader == NULL) {
            break;
        }
        ratio = M2C_FIELD(fader, f32 *, 8) / M2C_FIELD(fader, f32 *, 4);
        color.unk0 = ratio;
        color.unk4 = ratio;
        color.unk8 = ratio;
        color.unkC = 1.0f;
        MKModel_SetColor(this->unk4, color);
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(fader, s32 *, 0), 1U, 1U);
        MKModel_Draw(this->unk4, NULL);
        entry += 1;
    }
}
