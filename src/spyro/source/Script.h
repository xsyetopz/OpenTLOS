#ifndef SPYRO_SOURCE_SCRIPT_H
#define SPYRO_SOURCE_SCRIPT_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class MKIniLine;
class MKMessage;
class MKProp;
class ScriptProp;

class ScriptProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ScriptProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    void Execute(void);
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ u8 unk54;
    /* 0x055 */ u8 unk55;
    /* 0x056 */ u8 unk56;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'EventMessage'
inline ScriptProp::~ScriptProp() {
    __destroy_arr(this + 0x58, &EventMessage::~EventMessage, 4, 0xA);
    if (this != NULL) {
    }
}
#endif

#endif  // SPYRO_SOURCE_SCRIPT_H
