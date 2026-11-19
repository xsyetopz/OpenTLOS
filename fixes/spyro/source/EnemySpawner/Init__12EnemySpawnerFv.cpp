void EnemySpawnPool_Action(SpawnAction, int, MKProp **, SpawnerObject *);

void EnemySpawner::Init() {
    MKProp::Init();
    this->unk50.SetIdentity();
    this->unk8 = &this->unk50;
    this->unk10 |= 0x80000;
    this->unk90.Init(EnemySpawnPool_Action, 0);
}
