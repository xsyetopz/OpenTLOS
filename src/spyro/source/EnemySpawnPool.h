#ifndef SPYRO_SOURCE_ENEMYSPAWNPOOL_H
#define SPYRO_SOURCE_ENEMYSPAWNPOOL_H

#include <dolphin/types.h>

class MKProp;
class SpawnAction;
class SpawnerObject;

void EnemySpawnPool_Action(SpawnAction, int, MKProp **, SpawnerObject *);
void EnemySpawnPool_Deinit(void);
void EnemySpawnPool_Init(void);
#endif  // SPYRO_SOURCE_ENEMYSPAWNPOOL_H
