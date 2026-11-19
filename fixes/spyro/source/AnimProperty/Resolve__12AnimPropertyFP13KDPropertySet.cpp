void AnimProperty::Resolve(KDPropertySet *arg0) {
    KDProperty *found;
    s32 i;
    s32 off;

    found = (KDProperty *) arg0->Find("defaultAnimScript");
    this->unk10 = property_cast<KDAnimScriptProperty *, KDProperty *>(found);
    i = 0;
    off = 0;
    while (i < (s32) this->unk18) {
        i += 1;
        *(void **) ((s8 *) this->unk14 + off) = ((MKAnimScript *) M2C_FIELD(this->unk10, MKAnimScript **, 0x10))->GetAnim(*(const char **) ((s8 *) this->unk14 + off));
        off += 8;
    }
}
