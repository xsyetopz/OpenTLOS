void UIEvent::Resolve(UIObject *arg0) {
    const char *name;
    s8 *argName;

    /* unk0 starts as a name string; the lookup replaces it with the object it names. */
    name = (const char *) this->unk0;
    if (name != NULL) {
        this->unk0 = (void **) arg0->Find(name);
        UIStringTable_Remove(name);
    }
    if (((void **) this->unk0 != NULL) && (GetScriptArgType(this->unk4) == 1)) {
        argName = this->unk8;
        if (argName != NULL) {
            this->unk8 = (s8 *) ((UIObject *) this->unk0)->Find((const char *) argName);
            UIStringTable_Remove((const char *) argName);
        }
    }
}
