#ifndef SPYRO_SOURCE_TARGETMANAGER_H
#define SPYRO_SOURCE_TARGETMANAGER_H

#include <dolphin/types.h>

class AttackerManager;
class ColObjDescriptor;
class MKCollisionInfo;
class MKProp;
class MKVector3;
class TargetContext;
class TargetManager;
class Targetable;

class AttackerManager {
public:
    s32 GetAttackerCount(int);
    void Remove(Targetable *, int);
    void Add(Targetable *, int);
    void Reset(void);
    void Deinit(void);
    void Init(int);
    /* 0x000 */ TargetContext** unk0;
};

class TargetContext {
public:
    void Set(MKProp *);
    void Set(Targetable *);
    Targetable * Get(void);
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ Targetable* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ f32 unkC;
};

class TargetManager {
public:
    TargetManager ** GetNearestFacingEnemy(const MKVector3 &, float, const MKVector3 &, float, bool, bool);
    TargetManager ** GetNearestEnemy(const MKVector3 &, float, bool, bool);
    s32 GetTargets(Targetable **, int, unsigned int, MKVector3 *, float, bool, MKVector3 *, float);
    TargetManager *** Begin(void);
    void Remove(Targetable *);
    void Add(Targetable *);
    void Clear(void);
    void GetNewTargetID(void);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ TargetManager*** unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ TargetContext unk8;
};

class Targetable {
public:
    virtual void Init(ColObjDescriptor *, const MKVector3 &, bool, MKCollisionInfo *, bool, bool, unsigned int, MKProp *, bool) = 0;
    virtual void Deinit(void) = 0;
    virtual s32 Update(MKVector3 *, float, bool) = 0;
    virtual s32 Teleport(const MKVector3 &, float, int) = 0;
    virtual s32 HasHitFloor(void) = 0;
    virtual s32 HasHitWall(void) = 0;
    virtual s32 HasHitRoof(void) = 0;
    virtual s32 HasHitAnything(void) = 0;
    virtual u32 GetFloorProp(void) = 0;
    virtual s32 GetOwner(void) = 0;
    virtual void SetOwner(MKProp *) = 0;
    virtual s32 GetFloorMaterialID(void) = 0;
    virtual u32 GetProp(void) = 0;
    virtual void SetRotation(MKVector3 *, MKVector3) = 0;
    virtual void SetScale(float) = 0;
    virtual void Reset(const MKVector3 &, const MKVector3 &) = 0;
    virtual void GetAttackerManager(void);
    void UnregisterTargetable(void);
    void RegisterTargetable(void);
    static u8 pTargetManager[0x4];
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline void Targetable::GetAttackerManager() {
    return 0;
}
#endif

#endif  // SPYRO_SOURCE_TARGETMANAGER_H
