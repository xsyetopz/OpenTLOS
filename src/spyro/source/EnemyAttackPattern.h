#ifndef SPYRO_SOURCE_ENEMYATTACKPATTERN_H
#define SPYRO_SOURCE_ENEMYATTACKPATTERN_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class AITargetData;
class DataMap;
class EAPCondition;
class EAPItem;
class EAPManager;
class EAPManagerDescriptor;
class Enemy;
class EnemyAttack;
class EnemyAttackPattern;
class EnemyDescriptor;
class MKIniLine;

class EAPCondition {
public:
    void LoadLine(MKIniLine *);
    void Init(void);
    /* 0x000 */ EnemyAttack* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ f32 unkC;
};

class EAPItem {
public:
    void LoadLine(MKIniLine *);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ EnemyAttack* unk0;
    /* 0x004 */ void* unk4;
    /* 0x008 */ s32 unk8;
};

class EAPManager {
public:
    u32 EvaluateCondition(EAPItem *, EAPCondition *, Enemy *, AITargetData *);
    s32 ReEvaluate(Enemy *, AITargetData *);
    s32 Evaluate(Enemy *, AITargetData *, int *, int);
    void SetCurrentEAP(int);
    void SetDefaults(void);
    static void Deinit(void);
    void Init(EAPManagerDescriptor *);
    /* 0x000 */ EAPManagerDescriptor* unk0;
    /* 0x004 */ s32* unk4;
    /* 0x008 */ EnemyAttack** unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ u8 unk10;
};

class EAPManagerDescriptor {
public:
    void LoadLine(EnemyDescriptor *, MKIniLine *);
    void Deinit(void);
    /* 0x000 */ void* unk0;
    /* 0x004 */ s32 unk4;
};

class EnemyAttackPattern {
public:
    void LoadLine(MKIniLine *);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ void* unk0;
    /* 0x004 */ s32 unk4;
};

s32 EAP_GetEAPConditionType(eEAPCondition);
extern DataMap dataMapEAPCondition;
#endif  // SPYRO_SOURCE_ENEMYATTACKPATTERN_H
