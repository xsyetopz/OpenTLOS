void EnemySpawnPool_Action(SpawnAction arg0, int arg1, MKProp **arg2, SpawnerObject *arg3) {
    switch ((s32) arg0) {
    case 0:
        *arg2 = EnemySpawnPool_Create(arg1);
        return;
    case 1:
        *arg2 = (MKProp *) EnemySpawnPool_Recycle(arg1, arg3);
        return;
    case 2:
        EnemySpawnPool_Destroy((Enemy *) *arg2);
        return;
    }
}
