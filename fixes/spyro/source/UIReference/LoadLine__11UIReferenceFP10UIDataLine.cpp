s32 UIReference::LoadLine(UIDataLine *arg0) {
    const char *sp8;

    sp8 = NULL;
    if (((MKIniLine *) arg0)->LoadString("target", &sp8, 0) != 0) {
        this->unk60 = (void **) ((s32 (*)(const char *)) UIStringTable_Add)(sp8);
        return 1;
    }
    return UIObject::LoadLine(arg0);
}
