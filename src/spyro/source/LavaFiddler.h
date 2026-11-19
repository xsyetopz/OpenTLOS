#ifndef SPYRO_SOURCE_LAVAFIDDLER_H
#define SPYRO_SOURCE_LAVAFIDDLER_H

#include <dolphin/types.h>
#include "spyro/source/CreationTable.h"
#include "spyro/source/Critters.h"

class Critters;
class CrittersDescriptor;
class LavaFiddler;
class LavaFiddlerCritter;
class LavaFiddlerCritterDescriptor;

class LavaFiddler {
public:
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ u8 pad10[0x10];
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f64 unk38;
    /* 0x040 */ u8 pad40[0x10];
    /* 0x050 */ void* unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ f32 unk64;
};

class LavaFiddlerCritter : public Critters {  // base: ctor/dtor vtable stores
public:
    virtual ~LavaFiddlerCritter(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    LavaFiddlerCritter(void);
    void SetIdleState(LavaFiddler *);
    void FindNewWalkParameters(LavaFiddler *);
    void SetHideState(LavaFiddler *);
};

class LavaFiddlerCritterDescriptor : public CrittersDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    LavaFiddlerCritterDescriptor(void);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
};

#endif  // SPYRO_SOURCE_LAVAFIDDLER_H
