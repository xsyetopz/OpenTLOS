#ifndef SPYRO_SOURCE_MUDGUTS_H
#define SPYRO_SOURCE_MUDGUTS_H

#include <dolphin/types.h>
#include "spyro/source/CreationTable.h"
#include "spyro/source/Critters.h"

class Critters;
class CrittersDescriptor;
class MudGuts;
class MudGutsCritter;
class MudGutsCritterDescriptor;

class MudGuts {
public:
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ f32 unk4;
    /* 0x008 */ u8 pad8[0x18];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
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

class MudGutsCritter : public Critters {  // base: ctor/dtor vtable stores
public:
    virtual ~MudGutsCritter(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    MudGutsCritter(void);
    void FindNewSwimParameters(MudGuts *);
    /* 0x168 */ u8 pad168[0x8];
    /* 0x170 */ void* unk170;
};

class MudGutsCritterDescriptor : public CrittersDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    MudGutsCritterDescriptor(void);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
};

#endif  // SPYRO_SOURCE_MUDGUTS_H
