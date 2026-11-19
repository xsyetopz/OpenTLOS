s32 MeleeTrailsDescriptor::LoadLine(MKIniLine *arg0) {
    const char *sp8;

    if ((arg0->IsField("mtdFile") != 0) && (arg0->AsString(0, &sp8) != 0)) {
        strncpy((char *) &this->unkE8, sp8, 0x40U);
        this->unk127 = 0;
    }
    return GamePropDescriptor::LoadLine(arg0);
}
