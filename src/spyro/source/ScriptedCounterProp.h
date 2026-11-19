#ifndef SPYRO_SOURCE_SCRIPTEDCOUNTERPROP_H
#define SPYRO_SOURCE_SCRIPTEDCOUNTERPROP_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class MKIniLine;
class MKMessage;
class MKProp;
class ScriptedCounterProp;

class ScriptedCounterProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ScriptedCounterProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ u8 pad4C[0x50];
    /* 0x09c */ s32 unk9C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk4C'
inline ScriptedCounterProp::~ScriptedCounterProp() {
    __destroy_arr(&this->unk4C, &EventMessage::~EventMessage, 4, 0x14);
    if (this != NULL) {
    }
}
#endif

#endif  // SPYRO_SOURCE_SCRIPTEDCOUNTERPROP_H
