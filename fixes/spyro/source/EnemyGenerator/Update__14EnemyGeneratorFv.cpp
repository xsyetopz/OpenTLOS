class CutsceneSystem;

void EnemyGenerator::Update() {
    KDSynkerPlayer3 *temp_r3_1254;
    u8 var_r30_1251;
    void *temp_r29_1253;

    if ((this->unk7C < this->unk78) && (HasEnemyWaveFinished() != 0)) {
        this->unk7C += 1;
        StartEnemyWave();
        this->unk68.Send(NULL);
        if (this->unk7C == this->unk78) {
            this->unk6C.Send(NULL);
        }
    }
    if (this->unk7C < this->unk78) {
        var_r30_1251 = 0;
        temp_r29_1253 = M2C_FIELD(&gb, void **, 0xC);
        temp_r3_1254 = M2C_FIELD(temp_r29_1253, KDSynkerPlayer3 **, 0x78);
        if (((temp_r3_1254 != NULL) && (temp_r3_1254->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r29_1253, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r29_1253) + 0x24))->GetState() == 2))) {
            var_r30_1251 = 1;
        }
        if (var_r30_1251 == 0) {
            TrySpawnItems(M2C_FIELD(((u8 *) this->unk50->unk14 + (this->unk7C * 0x14)), s32 *, 8), false);
        }
    }
}
