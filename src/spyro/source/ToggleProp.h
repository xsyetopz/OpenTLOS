#ifndef SPYRO_SOURCE_TOGGLEPROP_H
#define SPYRO_SOURCE_TOGGLEPROP_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/KDProp.h"

class KDProp;
class MKIniLine;
class MKMessage;
class MKPropDescriptor;
class ToggleProp;
class TogglePropDescriptor;

class ToggleProp : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ToggleProp(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ u8 unk90;
};

class TogglePropDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    /* 0x048 */ u8 pad48[0x28];
    /* 0x070 */ s8* unk70;
    /* 0x074 */ s8* unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ToggleProp::~ToggleProp() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_TOGGLEPROP_H
