void KDSP_Sounds::ResolveActors(KDSP_ActorList *arg0) {
    u8 *block;
    u8 *rec;
    u8 *entry;
    s32 i;
    s32 j;
    s32 k;

    i = 0;
    while (i < arg0->unk0) {
        block = (u8 *) arg0->unk4 + i * 0x138;
        j = 0;
        while (j < M2C_FIELD(block, s32 *, 0x54)) {
            rec = M2C_FIELD(block, u8 **, 0x58) + j * 0x24;
            k = 0;
            while (k < (s32) this->unk8) {
                entry = (u8 *) this->unkC + k * 0x18;
                if ((M2C_FIELD(entry, s32 *, 0) == M2C_FIELD(rec, s32 *, 0)) &&
                    (stricmp((s32) (entry + 8), (s32) (rec + 0xC)) == 0)) {
                    M2C_FIELD(entry, u8 **, 0x14) = block;
                }
                k += 1;
            }
            j += 1;
        }
        i += 1;
    }
}
