void EnemySpawnPool_Action(SpawnAction, int, MKProp **, SpawnerObject *);

void ShatterWaypointSpawn::Init() {
    Shatterable::Init();
    this->unk200 = 0;
    this->unk1A8.Init(EnemySpawnPool_Action, 0);
    this->unk1A8.unk30 = 0.0f;
    this->unk1A8.unk34 = 0.0f;
    this->unk1FC = 0;
    this->unk1F8 = NULL;
}
