extern "C" s32 stricmp(const char *, const char *);

void BobProperty::Resolve(KDPropertySet *arg0) {
    if (((u32) this->unk14 == 0) && (this->unk10 != NULL) && (stricmp((const char *) this->unk10, "localToWorld") == 0)) {
        this->unk14 = (u32) property_cast<KDMatrixProperty *, KDProperty *>((KDProperty *) arg0->Find((const char *) this->unk10));
    }
    this->unk30 = 6.2831855f / this->unk30;
}
