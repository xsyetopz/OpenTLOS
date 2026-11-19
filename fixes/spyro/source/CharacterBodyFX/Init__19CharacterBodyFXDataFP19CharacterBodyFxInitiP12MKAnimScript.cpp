void CharacterBodyFXData::Init(CharacterBodyFxInit *arg0, int arg1, MKAnimScript *arg2) {
    s32 i;
    s32 off;
    u8 *entry;

    i = 0;
    off = 0;
    this->unk0 = arg0;
    this->unk4 = arg1;
    while (i < this->unk4) {
        entry = (u8 *) this->unk0 + off;
        if (*(s32 *) entry == 0) {
            *(s32 *) ((u8 *) this->unk0 + off + 8) = (u16) Tools_GetMatchingNodeIndex(arg2->unk8, *(char **) (entry + 4));
        } else {
            *(s32 *) ((u8 *) this->unk0 + off + 8) = (u16) Tools_GetMatchingRefPointIndex(arg2->unk8, *(char **) (entry + 4));
        }
        i += 1;
        off += 0x30;
    }
}
