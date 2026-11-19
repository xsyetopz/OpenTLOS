#ifndef SPYRO_SOURCE_GRUBBLE_H
#define SPYRO_SOURCE_GRUBBLE_H

#include <dolphin/types.h>
#include "spyro/source/CreationTable.h"
#include "spyro/source/Critters.h"

class Critters;
class CrittersDescriptor;
class Grubble;
class GrubbleCritter;
class GrubbleCritterDescriptor;

class Grubble {
public:
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ f32 unk4;
    /* 0x008 */ u8 pad8[0x28];
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

class GrubbleCritter : public Critters {  // base: ctor/dtor vtable stores
public:
    virtual ~GrubbleCritter(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    GrubbleCritter(void);
    void FindNewWalkParameters(Grubble *);
    void SetHideState(Grubble *);
    /* 0x168 */ u8 pad168[0x8];
    /* 0x170 */ void* unk170;
};

class GrubbleCritterDescriptor : public CrittersDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    GrubbleCritterDescriptor(void);
    /* 0x070 */ u8 pad70[0x4];
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline GrubbleCritter::GrubbleCritter() {
    return this;
}
#endif

inline GrubbleCritter::~GrubbleCritter() {
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
inline GrubbleCritterDescriptor::GrubbleCritterDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_GRUBBLE_H
