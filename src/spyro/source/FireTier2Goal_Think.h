#ifndef SPYRO_SOURCE_FIRETIER2GOAL_THINK_H
#define SPYRO_SOURCE_FIRETIER2GOAL_THINK_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/EnemyGoal_Think.h"
#include "spyro/source/Goal.h"

class Enemy;
class EnemyGoal_Think;
class FireTier2Goal_JumpOutOfLava;
class FireTier2Goal_MoveToLavaEdge;
class FireTier2Goal_Think;
class MKHeap;
class MKVector3;

class FireTier2Goal_JumpOutOfLava : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    u8 FindLavaEdge(const MKVector3 &, MKVector3 *, MKVector3 *);
    u8 FindLavaEdgePath(const MKVector3 &, MKVector3 *, MKVector3 *);
    void Init(Enemy *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ MKHeap* unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
    /* 0x028 */ Goal<Enemy>* unk28;
    /* 0x02c */ Goal<Enemy>* unk2C;
    /* 0x030 */ Goal<Enemy>* unk30;
    /* 0x034 */ u8 pad34[0x4];
    /* 0x038 */ MKVector3 unk38;
    /* 0x048 */ MKVector3 unk48;
    /* 0x058 */ u8 unk58;
};

class FireTier2Goal_MoveToLavaEdge : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ MKVector3* unk10;
    /* 0x014 */ f32 unk14;
};

class FireTier2Goal_Think : public EnemyGoal_Think {  // base: ctor/dtor vtable stores
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual u8 Update(void);
    virtual void Arbitrate(void);
    FireTier2Goal_Think(void);
    void Init(Enemy *);
    /* 0x004 */ u8 pad4[0x5];
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ s32 unkC;
    /* 0x010 */ u8 pad10[0x64];
    /* 0x074 */ MKHeap* unk74;
    /* 0x078 */ Goal<Enemy>* unk78;
    /* 0x07c */ u8 unk7C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void FireTier2Goal_MoveToLavaEdge::Reset() {
    this->unk8 = 1;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FireTier2Goal_Think::FireTier2Goal_Think() {
    this->unk4 = 0;
    this->unk8 = 1;
    this->unk9 = 0;
    this->unkC = 0;
    this->unk1C = 0;
    this->unk18 = 0;
    this->unk10 = 0;
    this->unk14 = 0;
    return this;
}
#endif

inline void FireTier2Goal_Think::Reset() {
    EnemyGoal_Think::Reset();
    this->unk7C = 0;
}

#endif  // SPYRO_SOURCE_FIRETIER2GOAL_THINK_H
