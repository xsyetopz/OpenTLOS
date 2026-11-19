void KDClothProperty::Resolve(KDPropertySet *arg0) {
    MKModel *temp_r4_81;
    s8 *temp_r0_69;
    s8 *temp_r3_78;

    temp_r0_69 = this->unk10;
    if (temp_r0_69 != NULL) {
        this->unk10 = (s8 *) (property_cast<KDModelProperty *, KDProperty *>((KDProperty *) arg0->Find((const char *) temp_r0_69)));
    }
    temp_r3_78 = this->unk10;
    if (temp_r3_78 != NULL) {
        temp_r4_81 = M2C_FIELD(temp_r3_78, MKModel **, 0x10);
        if (temp_r4_81 != NULL) {
            this->unk14.Resolve(temp_r4_81);
        }
    }
}
