#ifndef SPYRO_SOURCE_UIPROP_H
#define SPYRO_SOURCE_UIPROP_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/UIStringTable.h"

class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class UIProp;
class UIPropDescriptor;
class UIStringTable;

class UIProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~UIProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ s8* unk50;
    /* 0x054 */ void** unk54;
    /* 0x058 */ UIStringTable unk58;
    /* 0x060 */ s32 unk60;
};

class UIPropDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline UIProp::~UIProp() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_UIPROP_H
