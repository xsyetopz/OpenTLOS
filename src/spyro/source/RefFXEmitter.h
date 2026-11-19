#ifndef SPYRO_SOURCE_REFFXEMITTER_H
#define SPYRO_SOURCE_REFFXEMITTER_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class KDProp;
class KDPropDescriptor;
class MKIniLine;
class MKMessage;
class RefFXEmitter;
class RefFXEmitterDescriptor;

class RefFXEmitter : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~RefFXEmitter(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    /* 0x090 */ f32 unk90;
    /* 0x094 */ s32 unk94;
};

class RefFXEmitterDescriptor : public KDPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Resolve(void);
    /* 0x070 */ u8 pad70[0x28];
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline RefFXEmitter::~RefFXEmitter() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_REFFXEMITTER_H
