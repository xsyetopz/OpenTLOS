s32 Connector::LoadDone() {
    s32 count;
    s32 off;
    const char *name;

    MKProp::LoadDone();
    count = 0;
    this->unkAC = 0;
    off = 0;
    do {
        name = M2C_FIELD(this, const char **, off + 0xA0);
        if ((name != NULL) && (*name != 0)) {
            M2C_FIELD(this, void **, off + 0xA0) = Level::GetChunkByName(name);
            this->unkAC += 1;
        } else {
            M2C_FIELD(this, void **, off + 0xA0) = NULL;
        }
        count += 1;
        off += 4;
    } while (count < 3);
}
