extern "C" char *strtok(char *, const char *);
void KDSP_ActorList::ResolveLookAt() {
    s8 sp8[0x20];
    s8 sp28[0x20];
    KDSP_Actor *actor;
    s8 *entry;
    s32 i;
    s32 j;
    s32 off;
    s32 roff;

    off = 0;
    for (i = 0; i < this->unk0; i++) {
        actor = (KDSP_Actor *) (this->unk4 + off);
        if (!(actor->unk40 & 4) && !(actor->unk40 & 8)) {
            roff = 0;
            for (j = 0; j < actor->unk44; j++) {
                entry = (s8 *) actor->unk48 + roff;
                strcpy((char *) sp28, (const char *) M2C_FIELD(entry, s8 **, 8));
                strtok((char *) sp28, ":");
                M2C_FIELD(entry, KDSP_Actor **, 0xC) = FindActor((const char *) sp28);
                roff += 0x14;
                M2C_FIELD(entry, s32 *, 0x10) = (u16) M2C_FIELD(entry, KDSP_Actor **, 0xC)->GetMatchingNodeIndex(strtok(NULL, "\n"));
            }
            roff = 0;
            for (j = 0; j < actor->unk4C; j++) {
                entry = (s8 *) actor->unk50 + roff;
                strcpy((char *) sp8, (const char *) M2C_FIELD(entry, s8 **, 8));
                strtok((char *) sp8, ":");
                M2C_FIELD(entry, KDSP_Actor **, 0xC) = FindActor((const char *) sp8);
                roff += 0x14;
                M2C_FIELD(entry, s32 *, 0x10) = (u16) M2C_FIELD(entry, KDSP_Actor **, 0xC)->GetMatchingNodeIndex(strtok(NULL, "\n"));
            }
        }
        off += 0x138;
    }
}
