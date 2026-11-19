#ifndef SPYRO_SOURCE_SPARXHINT_H
#define SPYRO_SOURCE_SPARXHINT_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EventMessage.h"

class EventMessage;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class SparxHint;
class SparxHintDescriptor;
class SparxHint_cpp;

class SparxHint : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SparxHint(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ u8 unk4C;
    /* 0x04d */ u8 pad4D[0x3];
    /* 0x050 */ u8 unk50;
    /* 0x051 */ u8 pad51[0x3f];
    /* 0x090 */ EventMessage unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ u8 unkA8;
    /* 0x0a9 */ u8 unkA9;
    /* 0x0aa */ u8 unkAA;
    /* 0x0ab */ u8 unkAB;
    /* 0x0ac */ s32 unkAC;
};

class SparxHintDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

class SparxHint_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline SparxHint::~SparxHint() {
    if (&this->unk90 != NULL) {
        this->unk90.Deinit();
    }
    if (this != NULL) {
    }
}

#endif  // SPYRO_SOURCE_SPARXHINT_H
