#ifndef SPYRO_SOURCE_TARGETMANAGER_H
#define SPYRO_SOURCE_TARGETMANAGER_H

#include <dolphin/types.h>

class AttackerManager;
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
    /* 0x004 */ s32 unk4;
    /* 0x008 */ TargetContext unk8;
};

class Targetable {
public:
    virtual void pure_slot0() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot1() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot2() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot3() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot4() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot5() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot6() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot7() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot8() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot9() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot10() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot11() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot12() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot13() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot14() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot15() = 0;  // name unknown: no descendant fills this slot
    virtual s32 GetAttackerManager(void);
    void UnregisterTargetable(void);
    void RegisterTargetable(void);
    static u8 pTargetManager[0x4];
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 Targetable::GetAttackerManager() {
    return 0;
}

#endif  // SPYRO_SOURCE_TARGETMANAGER_H
