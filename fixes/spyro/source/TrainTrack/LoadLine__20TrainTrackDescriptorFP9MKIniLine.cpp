extern "C" s32 stricmp(const char *, const char *);

s32 TrainTrackDescriptor::LoadLine(MKIniLine *arg0) {
    s8 *str;
    s32 idx;

    if (MKPropDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (stricmp((const char *) arg0->GetFieldName(), "piece") == 0) {
        str = (s8 *) arg0->GetString(0);
        idx = this->unk27C;
        this->unk27C = idx + 1;
        strcpy((char *) this + ((idx << 5) + 0x60), (const char *) str);
        return 1;
    }
    return 0;
}
