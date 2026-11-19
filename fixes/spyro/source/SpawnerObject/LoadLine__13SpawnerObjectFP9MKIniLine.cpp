s32 SpawnerObject::LoadLine(MKIniLine *arg0) {
    s32 spC;
    u8 sp8;

    sp8 = 0;
    spC = 0;
    if ((arg0->LoadFloat("fSpawnDelay", &this->unk30, 0) != 0) || (arg0->LoadFloat("fDelayBetweenSpawns", &this->unk34, 0) != 0) || (arg0->LoadInt("iMaxSpawnItems", (int *) &this->unk28, 0) != 0) || (arg0->LoadInt("iMaxSpawnAmount", (int *) &this->unk24, 0) != 0) || (this->unk3C.LoadLine(arg0, "OnAllDead") != 0) || (this->unk40.LoadLine(arg0, "OnChildSpawnerAllDead") != 0)) {
        return 1;
    }
    if (arg0->LoadBool("bOnlySpawnOffscreen", (bool *) &sp8, 0) != 0) {
        this->unk4C = (this->unk4C & ~0x20) | ((sp8 << 5) & 0x20);
        goto block_14;
    }
    if (arg0->LoadBool("bLockSpawnPoints", (bool *) &sp8, 0) != 0) {
        this->unk4C = (this->unk4C & ~0x10) | ((sp8 << 4) & 0x10);
        goto block_14;
    }
    if (arg0->LoadInt("zone", (int *) &spC, 0) != 0) {
        this->unk18 = spC;
block_14:
        return 1;
    }
    return 0;
}
