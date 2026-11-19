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

#endif  // SPYRO_SOURCE_SCRIPTEDCOUNTERPROP_H
