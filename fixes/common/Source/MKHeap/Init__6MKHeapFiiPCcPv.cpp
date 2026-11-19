void MKHeap::Init(int arg0, int arg1, const char *arg2, void *arg3) {
    s32 spC;
    s32 sp8;
    s32 var_r6_1024;

    if (arg3 != NULL) {
        this->unk0 = (MKHeap *) arg3;
        this->unk4 = (s32) ((u8 *) this->unk0 + arg0) - (arg1 * 0x10);
        M2C_FIELD(this, s8 *, 0x34) = 1;
    } else {
        this->unk0 = (MKHeap *) OSAllocFromHeap(__OSCurrHeap, arg0 + (arg1 * 0x10));
        this->unk4 = (s32) ((u8 *) this->unk0 + arg0);
        M2C_FIELD(this, s8 *, 0x34) = 0;
        memset(this->unk0, 0xCD, (u32) arg0);
    }
    this->unkC = (s32) this->unk0;
    M2C_FIELD(this, s32 *, 0x30) = 0;
    strcpy((char *) &this->unk4C, arg2);
    if (((u8) gbGoldMaster == 0) && (this->unk0 == NULL)) {
        sp8 = black;
        spC = white;
        OSFatal(*(GXColor *) &spC, *(GXColor *) &sp8, (const char *) Str_Printf("MKHeap::Init couldn't grab %d bytes!", arg0));
    }
    this->unk3C = arg1;
    *(s32 *) &this->unk38 = this->unk4;
    this->unk44 = this->unk4;
    this->unk48 = NULL;
    var_r6_1024 = this->unk4;
    while ((u32) var_r6_1024 < (u32) (*(s32 *) &this->unk38 + (arg1 * 0x10))) {
        M2C_FIELD(var_r6_1024, s32 *, 0) = -1;
        M2C_FIELD(var_r6_1024, s32 *, 4) = -1;
        M2C_FIELD(var_r6_1024, s32 *, 8) = 0;
        M2C_FIELD(var_r6_1024, s32 *, 0xC) = 0;
        var_r6_1024 += 0x10;
    }
    AddHeapToGlobalList();
}
