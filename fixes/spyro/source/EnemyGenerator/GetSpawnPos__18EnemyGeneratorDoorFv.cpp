MKVector3 EnemyGeneratorDoor::GetSpawnPos() {
    MKVector3 sp8;
    SpawnPointObject *temp_r3_455;

    if ((s32) M2C_FIELD(M2C_FIELD(this, void **, 0), s32 *, 0x80) > 0) {
        temp_r3_455 = this->unk18;
        sp8 = *(MKVector3 *) &temp_r3_455->unk40;
    } else {
        MKModel_CalculateRefPointWorldPosition(M2C_FIELD(M2C_FIELD(this, void **, 8), MKModel **, 4), this->unk14, &sp8);
    }
    return sp8;
}
