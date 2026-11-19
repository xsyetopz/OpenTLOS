#ifndef SPYRO_SOURCE_GAMEENUMS_H
#define SPYRO_SOURCE_GAMEENUMS_H

#include <dolphin/types.h>

class DataMap;
class MKIniLine;

s32 ProjectileType_IsDynamite(int);
s32 PropTypes_LoadLine(MKIniLine *, char *, int *);
extern DataMap ElementTypeDataMap;
extern DataMap propTypeDataMap;
extern DataMap heroHurtReactionTypeDataMap;
extern DataMap heroRumbleTypeDataMap;
extern DataMap attackHitTypeDataMap;
extern DataMap enemyDamageTypesDataMap;
extern DataMap enemyTypeDataMap;
extern DataMap projectileTypeDataMap;
extern DataMap spyroCombatArcDataMap;
#endif  // SPYRO_SOURCE_GAMEENUMS_H
