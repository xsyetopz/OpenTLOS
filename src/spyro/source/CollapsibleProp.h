#ifndef SPYRO_SOURCE_COLLAPSIBLEPROP_H
#define SPYRO_SOURCE_COLLAPSIBLEPROP_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"
#include "spyro/source/Shadow.h"

class CollapsibleProp;
class CollapsiblePropDescriptor;
class CollapsibleProp_cpp;
class KDProp;
class KDPropDescriptor;
class MKMessage;
class Shadow;

class CollapsibleProp : public KDProp {  // base: ctor/dtor vtable stores
public:
    class State;
    virtual ~CollapsibleProp(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    void SetState(CollapsibleProp::State);
    /* 0x090 */ s32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ Shadow unk98;
    /* 0x0c8 */ s32 unkC8;
};

class CollapsiblePropDescriptor : public KDPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
};

class CollapsibleProp_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline CollapsibleProp::~CollapsibleProp() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_COLLAPSIBLEPROP_H
