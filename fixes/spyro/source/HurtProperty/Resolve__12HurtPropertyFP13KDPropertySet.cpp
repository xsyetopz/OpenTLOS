void HurtProperty::Resolve(KDPropertySet *arg0) {
    s8 *temp_r0_373;

    if (this->unk14 == NULL) {
        temp_r0_373 = this->unk10;
        if (temp_r0_373 != NULL) {
            this->unk14 = (void **) property_cast<KDMatrixProperty *, KDProperty *>((KDProperty *) arg0->Find((const char *) temp_r0_373));
        }
    }
}
