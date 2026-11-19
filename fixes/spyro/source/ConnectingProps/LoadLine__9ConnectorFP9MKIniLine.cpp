s32 Connector::LoadLine(MKIniLine *arg0) {
    s32 count;
    s32 off;

    if ((MKProp::LoadLine(arg0) != 0) || (this->unk50.LoadLine("region", arg0) != 0)) {
        return 1;
    }
    count = 0;
    off = 0;
    do {
        if (arg0->LoadString(M2C_FIELD(&pChunkTypeNames, const char **, off), (const char **) ((s8 *) this + off + 0xA0), 0) != 0) {
            return 1;
        }
        count += 1;
        off += 4;
    } while (count < 3);
    return 0;
}
