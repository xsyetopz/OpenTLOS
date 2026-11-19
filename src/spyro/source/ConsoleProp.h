#ifndef SPYRO_SOURCE_CONSOLEPROP_H
#define SPYRO_SOURCE_CONSOLEPROP_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class ConsoleProp;
class MKIniLine;
class MKProp;

class ConsoleProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ConsoleProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    /* 0x04c */ void* unk4C;
    /* 0x050 */ s32 unk50;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ConsoleProp::~ConsoleProp() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_CONSOLEPROP_H
