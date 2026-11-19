KDSP_Actor *KDSP_ActorList::FindActor(const char *arg0) {
    s32 i;
    s32 off;

    off = 0;
    for (i = 0; i < this->unk0; i++) {
        if (stricmp((s32) M2C_FIELD(this->unk4, s32 *, off + 0x5C), (s8 *) arg0) == 0) {
            return (KDSP_Actor *) (this->unk4 + off);
        }
        off += 0x138;
    }
    return NULL;
}
