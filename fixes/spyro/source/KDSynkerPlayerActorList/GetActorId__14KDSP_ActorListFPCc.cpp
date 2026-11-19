s32 KDSP_ActorList::GetActorId(const char *arg0) {
    s32 i;
    s32 off;
    s32 name;

    off = 0;
    for (i = 0; i < this->unk0; i++) {
        name = M2C_FIELD(this->unk4, s32 *, off + 0x5C);
        if (strcmpi((s32) name, (s8 *) arg0) == 0) {
            return i;
        }
        off += 0x138;
    }
    return -1;
}
