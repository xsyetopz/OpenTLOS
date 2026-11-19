#ifndef SPYRO_SOURCE_SCRYINGPOOL_H
#define SPYRO_SOURCE_SCRYINGPOOL_H

#include <dolphin/types.h>
#include "spyro/source/KDPropEx.h"

class KDPropEx;
class KDPropExDescriptor;
class MKIniLine;
class MKMessage;
class ScryingPool;
class ScryingPoolDescriptor;

class ScryingPool : public KDPropEx {  // base: ctor/dtor vtable stores
public:
    virtual ~ScryingPool(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    ScryingPool(void);
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
};

class ScryingPoolDescriptor : public KDPropExDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    ScryingPoolDescriptor(void);
    /* 0x0c0 */ s32 unkC0;
    /* 0x0c4 */ s32 unkC4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ScryingPool::ScryingPool() {
    this->unk98 = 0;
}

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline ScryingPool::~ScryingPool() {
    s32 temp_cr0_eq_28;

    if (this != NULL) {
        if ((&this->unk98 != NULL) && (&this->unk98 != NULL)) {
            KDSound_Stop((int *) &this->unk98);
        }
        temp_cr0_eq_28 = this == NULL;
        if (temp_cr0_eq_28 == 0) {
            if (temp_cr0_eq_28 == 0) {
                if (temp_cr0_eq_28 == 0) {
                }
            }
        }
    }
}
#endif

inline ScryingPoolDescriptor::ScryingPoolDescriptor() {
}

#endif  // SPYRO_SOURCE_SCRYINGPOOL_H
