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
    /* 0x168 */ u8 pad168[0x8];
    /* 0x170 */ void* unk170;
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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline LavaFiddlerCritter::LavaFiddlerCritter() {
    return this;
}
#endif

inline LavaFiddlerCritter::~LavaFiddlerCritter() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
                if (temp_cr0_eq_15 == 0) {
                }
            }
        }
    }
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline LavaFiddlerCritterDescriptor::LavaFiddlerCritterDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_LAVAFIDDLER_H
