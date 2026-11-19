#ifndef SPYRO_SOURCE_ENEMIES_FIREBOSS_H
#define SPYRO_SOURCE_ENEMIES_FIREBOSS_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class Enemies_FireBoss_cpp;
class Enemy;
class EnemyDescriptor;
class FireBoss;
class FireBossDescriptor;
class FireBossDirectedGraph;
class FireBossGraphEdge;
class FireBossGraphNode;
class KDUniformSpline;
class MKHeap;
class MKIniLine;
class MKMessage;
class MKVector3;

class Enemies_FireBoss_cpp {
public:
    void __sinit(void);
};

class FireBoss : public Enemy {  // base: vtable prefix
public:
    virtual ~FireBoss(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void SetDefaults(void);
    virtual void UpdateMovementCustom(void);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetAimPoint(const MKVector3 &, MKVector3 *);
    virtual void GetCharacterName(void);
    virtual s32 TryFreeze(float, bool, bool);
    FireBoss(void);
    void TriggerExplosion(void);
    void InsideEdgeChange(void);
    FireBossGraphEdge * GetCrashEdgeFromNextBranch(void);
    void RemoveCrashEdgeFromNextBranch(void);
    void LaunchFireball(void);
    void TriggerFireball(void);
    void SquashHero(void);
    void HurtHero(void);
    u8 SpyroIsInFront(void);
    void CheckFlameThrowerHit(void);
    s32 HasRunOverSpyro(void);
    u8 IsSpyroOnInsideTrack(int);
    void SetCurrentEdge(FireBossGraphEdge *, float);
    s32 CheckForEndOfEdge(bool);
    f32 CalcEdgeSplineStartTime(FireBossGraphEdge *);
    void MoveAlongCurrentSpline(float);
    void UpdateNextBranch(void);
    void FinaliseGraph(void);
    void CreateTurnSplines(int, int, int, float, float);
    void CreateInsideSplines(void);
    void CreateOutsideSpline(void);
    void UpdatePhrasesAndSounds(void);
};

class FireBossDescriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    FireBossDescriptor(void);
    /* 0x2b4 */ u8 pad2B4[0x120];
    /* 0x3d4 */ f32 unk3D4;
    /* 0x3d8 */ s32 unk3D8;
    /* 0x3dc */ MKHeap* unk3DC;
};

class FireBossDirectedGraph {
public:
    FireBossGraphEdge * GetEdge(KDUniformSpline *, float, int);
    void GetEdges(FireBossGraphNode *, int, FireBossGraphEdge **, int);
    u8 * GetNode(char);
    void * AddEdge(void);
    FireBossGraphNode * AddNode(const MKVector3 &);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ MKHeap* unk0;
    /* 0x004 */ MKHeap* unk4;
    /* 0x008 */ FireBossGraphNode* unk8;
    /* 0x00c */ FireBossGraphNode* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
};

class FireBossGraphEdge {
public:
    /* 0x000 */ void* unk0;
    /* 0x004 */ FireBossGraphNode* unk4;
    /* 0x008 */ u8 pad8[0x4];
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ s32 unk18;
    /* 0x01c */ u8 unk1C;
    /* 0x01d */ u8 unk1D;
};

class FireBossGraphNode {
public:
    void * GetEdge(FireBossGraphNode *, int);
    void AddEdges(FireBossGraphNode *, KDUniformSpline *, float, float, int, bool, unsigned char, unsigned char);
    void Init(const MKVector3 &, int);
    static u8 pGraph[0x4];
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ void* unk18;
    /* 0x01c */ s32 unk1C;
};

#endif  // SPYRO_SOURCE_ENEMIES_FIREBOSS_H
