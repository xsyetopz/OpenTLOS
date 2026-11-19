void KDSP_Subtitles::Update(KDSP_ActorList *arg0, int arg1) {
    s32 actorOff;
    s32 entryOff;
    s32 count;
    s32 i;
    s32 j;
    s32 hit;
    s32 slot;
    s32 last;
    void *actor;
    void *entry;

    actorOff = 0;
    count = arg0->unk0;
    for (i = 0; i < count; i++) {
        actor = (void *) (arg0->unk4 + actorOff);
        entryOff = 0;
        for (j = 0; j < M2C_FIELD(actor, s32 *, 0x54); j++) {
            entry = (void *) (M2C_FIELD(actor, s32 *, 0x58) + entryOff);
            slot = M2C_FIELD(entry, s32 *, 0x1C);
            hit = 0;
            if (arg1 >= M2C_FIELD(entry, s32 *, 0) && arg1 < (s32) (M2C_FIELD(entry, s32 *, 0) + M2C_FIELD(entry, s32 *, 4))) {
                hit = 1;
            }
            if (slot == -1) {
                if (hit != 0) {
                    M2C_FIELD(entry, s32 *, 0x1C) = this->unkA8;
                    *(void **) ((u8 *) this + this->unkA8 * 8 + 0xAC) = *(void **) ((u8 *) this + M2C_FIELD(entry, s32 *, 8) * 4);
                    *(f32 *) ((u8 *) this + this->unkA8 * 8 + 0xB0) = 0.033f * (f32) M2C_FIELD(entry, s32 *, 4);
                    this->unkA8 = (this->unkA8 + 1) % 3;
                }
            } else {
                if (hit == 0) {
                    *(void **) ((u8 *) this + slot * 8 + 0xAC) = NULL;
                    *(f32 *) ((u8 *) this + slot * 8 + 0xB0) = 0.0f;
                    M2C_FIELD(entry, s32 *, 0x1C) = -1;
                }
            }
            entryOff += 0x24;
        }
        actorOff += 0x138;
    }

    last = 0;
    for (i = 0; i < 3; i++) {
        if (*(u32 *) ((u8 *) this + i * 8 + 0xAC) != 0) {
            last = i + 1;
        }
    }
    this->unkA4 = last;
    if (last == 0) {
        this->unkA8 = 0;
    }
}
