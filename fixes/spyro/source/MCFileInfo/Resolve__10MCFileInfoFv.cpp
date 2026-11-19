void MCFileInfo::Resolve() {
    const char *p;
    s8 c;
    UIText *obj;

    UIContainer::Resolve();
    p = (const char *) this->unk4;
    this->unk218 = 0;
    if (p != NULL) {
        while (*p != 0) {
            c = *p;
            if (c >= 0x30 && c <= 0x39) {
                this->unk218 *= 0xA;
                this->unk218 = (c + this->unk218) - 0x30;
            }
            p++;
        }
    }
    this->unk218 -= 1;
    this->unk68 = ui_cast<UIText *, UIObject *>(FindChild("Percent"));
    this->unk6C = ui_cast<UIText *, UIObject *>(FindChild("Time"));
    this->unk74 = ui_cast<UIText *, UIObject *>(FindChild("Location"));
    this->unk70 = ui_cast<UIText *, UIObject *>(FindChild("Message"));

    obj = (UIText *) this->unk68;
    if (obj != NULL) {
        if (obj->unk68 != NULL) {
            UIStringTable_Remove((const char *) obj->unk68);
        }
        UIStringTable_Add(NULL);
        obj->unk6C = -1;
        obj->unk68 = (s8 *) &this->unk178;
    }
    obj = (UIText *) this->unk6C;
    if (obj != NULL) {
        if (obj->unk68 != NULL) {
            UIStringTable_Remove((const char *) obj->unk68);
        }
        UIStringTable_Add(NULL);
        obj->unk6C = -1;
        obj->unk68 = (s8 *) &this->unk1B8;
    }
    obj = (UIText *) this->unk74;
    if (obj != NULL) {
        if (obj->unk68 != NULL) {
            UIStringTable_Remove((const char *) obj->unk68);
        }
        UIStringTable_Add(NULL);
        obj->unk6C = -1;
        obj->unk68 = (s8 *) &this->unk78;
    }
}
