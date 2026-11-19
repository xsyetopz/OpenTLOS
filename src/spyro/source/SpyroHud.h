#ifndef SPYRO_SOURCE_SPYROHUD_H
#define SPYRO_SOURCE_SPYROHUD_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class Enemy;
class EnemyHudData;
class MKProp;
class SpyroHud_cpp;

class EnemyHudData {
public:
    void Init(Enemy *, float, float);
    EnemyHudData(void);
    /* 0x000 */ Enemy* unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
};

class SpyroHud_cpp {
public:
    void __sinit(void);
};

s32 EnemyHud_GetEnemy(void);
void EnemyHud_Modified(const EnemyHudData &);
void EnemyHud_Modified(MKProp *, float, float, float);
void SpyroHud_ResetAfterCutScene(void);
void SpyroHud_Deinit(void);
void SpyroHud_Init(void);
void SpyroHud_StateChange(void *, HudItemState, HudItemState);
void SpyroHud_Draw(void *, HudItemState, float);
s32 SpyroHud_Update(void *);
#endif  // SPYRO_SOURCE_SPYROHUD_H
