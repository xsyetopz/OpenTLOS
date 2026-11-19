#ifndef SPYRO_SOURCE_FIREBOSSGOALS_H
#define SPYRO_SOURCE_FIREBOSSGOALS_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class Character;
class FireBoss;
class FireBossGoal_Crash;
class FireBossGoal_Death;
class FireBossGoal_Stage1;
class FireBossGoal_Stage2;
class FireBossGoal_Stage3;
class FireBossGoal_Stage4;
class FireBossGoal_Think;
class FireBossGoal_Turn;
class MKProp;

class FireBossGoal_Crash : public Goal<FireBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class FireBossGoal_Death : public Goal<FireBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ MKProp* unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 unk14;
};

class FireBossGoal_Stage1 : public Goal<FireBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ FireBoss* unkC;
};

class FireBossGoal_Stage2 : public Goal<FireBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ FireBoss* unkC;
};

class FireBossGoal_Stage3 : public Goal<FireBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ FireBoss* unkC;
};

class FireBossGoal_Stage4 : public Goal<FireBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ FireBoss* unkC;
};

class FireBossGoal_Think : public CompositeGoal<FireBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    void Init(FireBoss *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ void** unk20;
    /* 0x024 */ void** unk24;
    /* 0x028 */ void** unk28;
    /* 0x02c */ void** unk2C;
    /* 0x030 */ void** unk30;
    /* 0x034 */ Goal<FireBoss>* unk34;
    /* 0x038 */ Goal<FireBoss>* unk38;
    /* 0x03c */ void** unk3C;
    /* 0x040 */ void** unk40;
    /* 0x044 */ void** unk44;
    /* 0x048 */ void** unk48;
    /* 0x04c */ void** unk4C;
    /* 0x050 */ s8 unk50;
};

class FireBossGoal_Turn : public Goal<FireBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ FireBoss* unkC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void FireBossGoal_Death::Reset() {
    this->unk8 = 1;
    this->unk14 = 0;
}

#endif  // SPYRO_SOURCE_FIREBOSSGOALS_H
