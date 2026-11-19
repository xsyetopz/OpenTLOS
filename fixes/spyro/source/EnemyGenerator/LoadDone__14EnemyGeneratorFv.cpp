void EnemyGenerator::LoadDone() {
    MKProp *temp_r4_1696;
    s32 var_r7_1699;

    temp_r4_1696 = this->unk60;
    if (temp_r4_1696 != NULL) {
        var_r7_1699 = temp_r4_1696->unk18;
    } else {
        var_r7_1699 = 1;
    }
    SpawnerObject::LoadDone(0, 0xA, false, (u32) var_r7_1699);
}
