#ifndef SPYRO_SOURCE_ENEMYDATATYPES_H
#define SPYRO_SOURCE_ENEMYDATATYPES_H

#include <dolphin/types.h>
#include "spyro/source/EnemySettings.h"

class AnimSequence;
class AttackSweepData;
class DataMap;
class Enemy;
class EnemyAttack;
class EnemyDamageFeedback;
class EnemyDescriptor;
class EnemyMovementManager;
class EnemySettings;
class EnemySpawnGraphData;
class MKCollisionInfo;
class MKIniLine;
class MKVector3;

class AttackSweepData {
public:
    void SetDefaults(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 unk4;
    /* 0x005 */ s8 unk5;
};

class EnemyAttack {
public:
    void LoadDone(void);
    s32 LoadLine(MKIniLine *, EnemyDescriptor *);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ AnimSequence* unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ s32 unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ EnemySettings unk54;
    /* 0x055 */ u8 pad55[0x23];
    /* 0x078 */ s32 unk78;
    /* 0x07c */ u32* unk7C;
    /* 0x080 */ u32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ u8 unk8C;
    /* 0x08d */ u8 unk8D;
    /* 0x08e */ u8 unk8E;
    /* 0x08f */ u8 unk8F;
};

class EnemyDamageFeedback {
public:
    void Init(float, bool, const MKVector3 &, int, int, bool, bool, MKCollisionInfo *, float, float);
    void Init(void);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ u8 unk34;
};

class EnemyMovementManager {
public:
    void SetExitingAnim(void);
    s32 ** SelectAnim(void);
    void Update(void);
    void Set(unsigned int, int, int, int);
    void Deinit(void);
    void Init(Enemy *);
    /* 0x000 */ Enemy* unk0;
    /* 0x004 */ u32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ u8 unk14;
};

class EnemySpawnGraphData {
public:
    void SetDefaults(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
};

s32 EnemyMovementType_GetMask(int);
extern s8 * pEnemyAnimEvents;
extern DataMap dataMapEAP;
#endif  // SPYRO_SOURCE_ENEMYDATATYPES_H
