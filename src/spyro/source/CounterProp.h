#ifndef SPYRO_SOURCE_COUNTERPROP_H
#define SPYRO_SOURCE_COUNTERPROP_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EventMessage.h"

class CounterProp;
class EventMessage;
class MKIniLine;
class MKMessage;
class MKProp;

class CounterProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~CounterProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ EventMessage unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ u8 unk58;
    /* 0x059 */ u8 unk59;
};

#endif  // SPYRO_SOURCE_COUNTERPROP_H
