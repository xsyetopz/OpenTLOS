void UIReference::Resolve() {
    void **temp_r31_68;

    UIObject::Resolve();
    temp_r31_68 = this->unk60;
    if (temp_r31_68 != NULL) {
        this->unk60 = (void **) (Find((const char *) temp_r31_68));
        UIStringTable_Remove((const char *) temp_r31_68);
    }
}
