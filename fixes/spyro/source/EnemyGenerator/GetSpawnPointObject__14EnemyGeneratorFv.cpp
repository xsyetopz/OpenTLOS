SpawnPointObject *EnemyGenerator::GetSpawnPointObject() {
    MKVector3 sp8;
    SpawnPointObject *temp_r3_1121;

    temp_r3_1121 = SpawnerObject::GetSpawnPointObject();
    if (temp_r3_1121 != NULL) {
        sp8 = ((EnemyGeneratorDoor *) (GetDoor(temp_r3_1121)))->GetSpawnPos();
        temp_r3_1121->unk40 = sp8.unk0;
        temp_r3_1121->unk44 = sp8.unk4;
        temp_r3_1121->unk48 = sp8.unk8;
        temp_r3_1121->unk4C = 1.0f;
    }
    return temp_r3_1121;
}
