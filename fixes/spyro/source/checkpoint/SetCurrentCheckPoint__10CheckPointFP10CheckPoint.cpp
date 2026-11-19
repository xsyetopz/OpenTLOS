void CheckPoint::SetCurrentCheckPoint(CheckPoint *arg0) {
    ChunkInfo *temp_r4_63;
    u8 var_r3_64;
    void *temp_r5_65;

    if (*(CheckPoint **) CheckPoint::pCurrentCheckPoint != arg0) {
        *(CheckPoint **) CheckPoint::pCurrentCheckPoint = arg0;
        if (arg0 != NULL) {
            temp_r4_63 = arg0->unk1B8;
            var_r3_64 = 0;
            temp_r5_65 = temp_r4_63->unk4;
            if ((temp_r5_65 != NULL) && (M2C_FIELD(temp_r5_65, ChunkInfo **, 0x118) == temp_r4_63)) {
                var_r3_64 = 1;
            }
            if (var_r3_64 == 0) {
                ((GameData *) GameData::gameData)->SetSaveChunk(temp_r4_63);
            }
        }
    }
}
