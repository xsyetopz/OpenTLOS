s32 ConsoleProp::LoadDone() {
    s32 off;
    s32 i;

    MKProp::LoadDone();
    off = 0;
    for (i = 0; i < this->unk50; i++) {
        Console_AddMacro((const char *) ((u8 *) this->unk4C + off), *(const char **) ((u8 *) this->unk4C + off + 0x20));
        *(const char **) ((u8 *) this->unk4C + off + 0x20) = NULL;
        off += 0x24;
    }
}
