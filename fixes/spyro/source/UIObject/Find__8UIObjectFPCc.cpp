extern "C" s32 stricmp(const char *, const char *);
UIContainer *UIObject::Find(const char *arg0) {
    UIContainer *temp_r3_83;
    UIObject *var_r31_55;

    var_r31_55 = NULL;
    if (stricmp(arg0, "system") == 0) {
        return GetRoot();
    }
    if (stricmp(arg0, "this") == 0) {
        return (UIContainer *) this;
    }
    if (stricmp(arg0, "parent") == 0) {
        return this->unkC;
    }
    temp_r3_83 = this->unkC;
    if (temp_r3_83 != NULL) {
        var_r31_55 = temp_r3_83->FindChild(arg0);
    }
    if ((var_r31_55 == NULL) && (IsContainer() != 0)) {
        var_r31_55 = ((UIContainer *) this)->FindChild(arg0);
    }
    if ((var_r31_55 == NULL) && (GetRoot() != NULL)) {
        var_r31_55 = ((UIContainer *) (GetRoot()))->FindChild(arg0);
    }
    return (UIContainer *) var_r31_55;
}
