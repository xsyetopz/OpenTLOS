extern "C" void free(void *);
s32 MKLevelChunk::DeinitChunk() {
    void *temp_r30;
    u8 var_r5;

    var_r5 = 0;
    switch (this->unk4) {
    case 0:
        MKGrass_LevelDeinit();
        M2C_FIELD(this, MKCollisionManager **, 0x94)->Enable(0);
        var_r5 = 1;
        break;
    case 5:
        if (M2C_FIELD(this, u32 *, 0x13C) & 8) {
            M2C_FIELD(this, MKFFTWater **, 0x98)->Deinit();
            operator delete(M2C_FIELD(this, void **, 0x98));
            temp_r30 = M2C_FIELD(this, void **, 0x9C);
            if (MKHeap::Current() != NULL) {
                MKHeap::Current()->Free(temp_r30, NULL, 0);
            } else {
                free(temp_r30);
            }
            M2C_FIELD(this, void **, 0x9C) = NULL;
            M2C_FIELD(this, void **, 0x98) = NULL;
            M2C_FIELD(this, u32 *, 0x13C) &= 0xFFFFFFF7;
        }
        var_r5 = 1;
        break;
    case 4:
        if (M2C_FIELD(this, u32 *, 0x13C) & 0x10) {
            Game_UserInit(NULL, 0U);
            M2C_FIELD(this, u32 *, 0x13C) &= 0xFFFFFFEF;
        }
        var_r5 = 1;
        break;
    case 7:
        if (M2C_FIELD(this, u32 *, 0x13C) & 1) {
            M2C_FIELD(this, u32 *, 0x13C) &= 0xFFFFFFFE;
            M2C_FIELD(this, MKCollisionManager **, 0x94)->Deinit();
        }
        if (M2C_FIELD(this, u32 *, 0x13C) & 2) {
            M2C_FIELD(this, u32 *, 0x13C) &= 0xFFFFFFFD;
            MKCollision_RemoveManager(M2C_FIELD(this, MKCollisionManager **, 0x94));
        }
        var_r5 = 1;
        break;
    case 8:
        if (M2C_FIELD(this, u32 *, 0x13C) & 0x20000) {
            M2C_FIELD(this, MKIni **, 0x8C)->Deinit();
            M2C_FIELD(this, u32 *, 0x13C) &= 0xFFFDFFFF;
        }
        var_r5 = 1;
        break;
    }
    return var_r5;
}
