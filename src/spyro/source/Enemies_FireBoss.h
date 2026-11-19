#ifndef SPYRO_SOURCE_ENEMIES_FIREBOSS_H
#define SPYRO_SOURCE_ENEMIES_FIREBOSS_H

#include <dolphin/types.h>
#include "common/Source/MKAnimScript.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/SteamTrain.h"

class Enemies_FireBoss_cpp;
class Enemy;
class EnemyDescriptor;
class EventMessage;
class FireBoss;
class FireBossDescriptor;
class FireBossDirectedGraph;
class FireBossDriver;
class FireBossGraphEdge;
class FireBossGraphNode;
class KDUniformSpline;
class MKAnimScript;
class MKHeap;
class MKIniLine;
class MKMessage;
class MKVector3;
class SteamTrainEffects;

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
    /* 0xb10 */ s32 unkB10;
    /* 0xb14 */ s32 unkB14;
    /* 0xb18 */ f32 unkB18;
    /* 0xb1c */ f32 unkB1C;
    /* 0xb20 */ f32 unkB20;
    /* 0xb24 */ f32 unkB24;
    /* 0xb28 */ f32 unkB28;
    /* 0xb2c */ f32 unkB2C;
    /* 0xb30 */ f32 unkB30;
    /* 0xb34 */ f32 unkB34;
    /* 0xb38 */ KDUniformSpline unkB38;
    /* 0xb4c */ KDUniformSpline unkB4C;
    /* 0xb60 */ KDUniformSpline unkB60;
    /* 0xb74 */ u8 padB74[0xa0];
    /* 0xc14 */ void* unkC14;
    /* 0xc18 */ FireBossDirectedGraph* unkC18;
    /* 0xc1c */ FireBossGraphEdge* unkC1C;
    /* 0xc20 */ u8* unkC20;
    /* 0xc24 */ s32 unkC24;
    /* 0xc28 */ u8 padC28[0x10];
    /* 0xc38 */ s32 unkC38;
    /* 0xc3c */ s32 unkC3C;
    /* 0xc40 */ s8 unkC40;
    /* 0xc41 */ u8 unkC41;
    /* 0xc42 */ s8 unkC42;
    /* 0xc43 */ u8 unkC43;
    /* 0xc44 */ s8 unkC44;
    /* 0xc45 */ s8 unkC45;
    /* 0xc46 */ u8 padC46[0x2];
    /* 0xc48 */ f32 unkC48;
    /* 0xc4c */ u8 padC4C[0xc4];
    /* 0xd10 */ SteamTrainEffects unkD10;
    /* 0xf4c */ u8 padF4C[0x4];
    /* 0xf50 */ f32 unkF50;
    /* 0xf54 */ f32 unkF54;
    /* 0xf58 */ f32 unkF58;
    /* 0xf5c */ f32 unkF5C;
    /* 0xf60 */ f32 unkF60;
    /* 0xf64 */ FireBossDriver* unkF64;
    /* 0xf68 */ void* unkF68;
    /* 0xf6c */ u8 padF6C[0x4];
    /* 0xf70 */ MKAnimScript unkF70;
    /* 0xfc8 */ u8 unkFC8;
    /* 0xfc9 */ u8 unkFC9;
    /* 0xfca */ u8 unkFCA;
    /* 0xfcb */ u8 unkFCB;
    /* 0xfcc */ s32 unkFCC;
    /* 0xfd0 */ u8 padFD0[0x24];
    /* 0xff4 */ s32 unkFF4;
    /* 0xff8 */ u8 padFF8[0x24];
    /* 0x101c */ s32 unk101C;
    /* 0x1020 */ u8 pad1020[0x24];
    /* 0x1044 */ s32 unk1044;
    /* 0x1048 */ u8 pad1048[0x24];
    /* 0x106c */ s32 unk106C;
    /* 0x1070 */ s32 unk1070;
    /* 0x1074 */ s32 unk1074;
    /* 0x1078 */ s8* unk1078;
    /* 0x107c */ f32 unk107C;
    /* 0x1080 */ f32 unk1080;
    /* 0x1084 */ EventMessage unk1084;
    /* 0x1088 */ void** unk1088;
    /* 0x108c */ s32 unk108C;
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
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 pad1[0x3];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ void* unk18;
    /* 0x01c */ s32 unk1C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline FireBoss::FireBoss() {
    this->unk6B8 = &__vt + 0x84;
    this->unkB38.unk0 = 0;
    this->unkB38.unk4 = 0;
    this->unkB38.unk8 = 0.0f;
    this->unkB38.unkC = 0;
    __construct_array(&this->unkB4C, (MKAnimScript *(*)(MKAnimScript *)) &KDUniformSpline::KDUniformSpline, NULL, 0x14, 2);
    __construct_array(&this->unkB74, (MKAnimScript *(*)(MKAnimScript *)) &KDUniformSpline::KDUniformSpline, NULL, 0x14, 8);
    this->unkFCC = 0;
    this->unkFF4 = 0;
    this->unk101C = 0;
    this->unk1044 = 0;
    this->unk1084.unk0 = 0;
    this->unk1084.Init();
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline FireBoss::~FireBoss() {
    this->unk6B8 = &__vt.unk84;
    if (&this->unk1084 != NULL) {
        this->unk1084.Deinit();
    }
    if ((&this->unk1044 != NULL) && (&this->unk1044 != NULL)) {
        KDSound_Stop((int *) &this->unk1044);
    }
    if ((&this->unk101C != NULL) && (&this->unk101C != NULL)) {
        KDSound_Stop((int *) &this->unk101C);
    }
    if ((&this->unkFF4 != NULL) && (&this->unkFF4 != NULL)) {
        KDSound_Stop((int *) &this->unkFF4);
    }
    if ((&this->unkFCC != NULL) && (&this->unkFCC != NULL)) {
        KDSound_Stop((int *) &this->unkFCC);
    }
}
#endif

inline s32 FireBoss::TryFreeze(float arg0, bool arg1, bool arg2) {
    return 0;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FireBossDescriptor::FireBossDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_FIREBOSS_H
