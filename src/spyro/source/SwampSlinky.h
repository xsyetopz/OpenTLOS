#ifndef SPYRO_SOURCE_SWAMPSLINKY_H
#define SPYRO_SOURCE_SWAMPSLINKY_H

#include <dolphin/types.h>
#include "spyro/source/CreationTable.h"
#include "spyro/source/Critters.h"

class Critters;
class CrittersDescriptor;
class SwampSlinky;
class SwampSlinkyDescriptor;

class SwampSlinky : public Critters {  // base: ctor/dtor vtable stores
public:
    virtual ~SwampSlinky(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    SwampSlinky(void);
    /* 0x168 */ u8 pad168[0x8];
    /* 0x170 */ void* unk170;
};

class SwampSlinkyDescriptor : public CrittersDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SwampSlinkyDescriptor(void);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SwampSlinky::SwampSlinky() {
    return this;
}
#endif

inline SwampSlinky::~SwampSlinky() {
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
inline SwampSlinkyDescriptor::SwampSlinkyDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SWAMPSLINKY_H
