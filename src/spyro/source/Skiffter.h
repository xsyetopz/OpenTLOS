#ifndef SPYRO_SOURCE_SKIFFTER_H
#define SPYRO_SOURCE_SKIFFTER_H

#include <dolphin/types.h>
#include "spyro/source/CreationTable.h"
#include "spyro/source/Critters.h"

class Critters;
class CrittersDescriptor;
class MKIniLine;
class SkiffterCritter;
class SkiffterCritterDescriptor;

class SkiffterCritter : public Critters {  // base: ctor/dtor vtable stores
public:
    virtual ~SkiffterCritter(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Draw(void);
    SkiffterCritter(void);
    /* 0x168 */ u8 pad168[0x8];
    /* 0x170 */ void* unk170;
    /* 0x174 */ void* unk174;
    /* 0x178 */ s32 unk178;
};

class SkiffterCritterDescriptor : public CrittersDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SkiffterCritterDescriptor(void);
    /* 0x070 */ u8 pad70[0x4];
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline SkiffterCritter::SkiffterCritter() {
}

inline SkiffterCritter::~SkiffterCritter() {
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

inline SkiffterCritterDescriptor::SkiffterCritterDescriptor() {
}

#endif  // SPYRO_SOURCE_SKIFFTER_H
