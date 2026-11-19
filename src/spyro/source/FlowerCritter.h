#ifndef SPYRO_SOURCE_FLOWERCRITTER_H
#define SPYRO_SOURCE_FLOWERCRITTER_H

#include <dolphin/types.h>
#include "spyro/source/CreationTable.h"
#include "spyro/source/Critters.h"

class Critters;
class CrittersDescriptor;
class FlowerCritter;
class FlowerCritterDescriptor;
class MKIniLine;

class FlowerCritter : public Critters {  // base: ctor/dtor vtable stores
public:
    virtual ~FlowerCritter(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Draw(void);
    FlowerCritter(void);
    /* 0x168 */ u8 pad168[0x8];
    /* 0x170 */ void* unk170;
    /* 0x174 */ u8 unk174;
};

class FlowerCritterDescriptor : public CrittersDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    FlowerCritterDescriptor(void);
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline FlowerCritter::FlowerCritter() {
}

inline FlowerCritter::~FlowerCritter() {
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

inline FlowerCritterDescriptor::FlowerCritterDescriptor() {
}

#endif  // SPYRO_SOURCE_FLOWERCRITTER_H
