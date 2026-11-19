#ifndef SPYRO_SOURCE_ENEMYSETTINGS_H
#define SPYRO_SOURCE_ENEMYSETTINGS_H

#include <dolphin/types.h>

class EnemySettingType;
class EnemySettings;
class MKIniLine;

class EnemySettings {
public:
    void LoadLine(MKIniLine *);
    void InitToOne(void);
};

void EnemySettings_UnregisterSettings(EnemySettings *);
void EnemySettings_RegisterSettings(const char *, EnemySettings *);
f32 EnemySettings_GetEnemySetting(EnemySettingType);
void EnemySettings_ParseDDASettings(MKIniLine *);
void EnemySettings_ParseLevelSettings(MKIniLine *, const char *, EnemySettings *);
void EnemySettings_ParseBaselineSettings(MKIniLine *);
void EnemySettings_ParseEnemyDDALevel(MKIniLine *);
void EnemySettings_ParseIniFile(const char *);
void EnemySettings_DeinitModule(void);
void EnemySettings_InitModule(void);
#endif  // SPYRO_SOURCE_ENEMYSETTINGS_H
