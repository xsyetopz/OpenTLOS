#ifndef SPYRO_SOURCE_SIEGETOWER_H
#define SPYRO_SOURCE_SIEGETOWER_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/Shatterable.h"

class Ball;
class EnemyGeneratorDescriptor;
class MKDynamicBone;
class MKIniLine;
class MKMessage;
class MKPropDescriptor;
class MKVector3;
class Shatterable;
class SiegeTower;
class SiegeTowerDescriptor;
class Targetable;

class SiegeTower : public Shatterable {  // base: vtable prefix
public:
    virtual ~SiegeTower(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    SiegeTower(void);
    void ZapBall(Ball *);
    void Shoot(Targetable *);
    void UpdateShooting(Targetable *);
    void CalcSpikeBeamPositions(void);
    void FreeElecBeams(void);
    void AllocElecBeams(void);
    void UpdateTurning(MKVector3);
    void UpdateTurretBone(MKDynamicBone *, void *);
};

class SiegeTowerDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SiegeTowerDescriptor(void);
    /* 0x048 */ u8 pad48[0x1c];
    /* 0x064 */ s32 unk64;
    /* 0x068 */ u8 pad68[0x104];
    /* 0x16c */ s32 unk16C;
    /* 0x170 */ s32 unk170;
    /* 0x174 */ s32 unk174;
    /* 0x178 */ s32 unk178;
    /* 0x17c */ s32 unk17C;
    /* 0x180 */ s32 unk180;
    /* 0x184 */ EnemyGeneratorDescriptor unk184;
};

s32 SiegeTower_GetSiegeTower(int, int);
s32 SiegeTower_GetMaxPerGroup(void);
void SiegeTower_InitModule(void);
#endif  // SPYRO_SOURCE_SIEGETOWER_H
