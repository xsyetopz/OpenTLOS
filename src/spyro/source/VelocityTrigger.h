#ifndef SPYRO_SOURCE_VELOCITYTRIGGER_H
#define SPYRO_SOURCE_VELOCITYTRIGGER_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/CreationTable.h"
#include "spyro/source/TriggerProp.h"

class MKIniLine;
class MKVector3;
class TriggerBoxProp;
class TriggerBoxPropDescriptor;
class VelocityTrigger;
class VelocityTriggerDescriptor;

class VelocityTrigger : public TriggerBoxProp {  // base: ctor/dtor vtable stores
public:
    virtual ~VelocityTrigger(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    virtual void OnAction(void);
    VelocityTrigger(void);
    /* 0x0c1 */ u8 padC1[0xcf];
    /* 0x190 */ void* unk190;
    /* 0x194 */ u8 pad194[0xbc];
    /* 0x250 */ MKVector3 unk250;
    /* 0x260 */ MKVector3 unk260;
    /* 0x270 */ MKVector3 unk270;
    /* 0x280 */ MKVector3 unk280;
};

class VelocityTriggerDescriptor : public TriggerBoxPropDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    VelocityTriggerDescriptor(void);
};

#endif  // SPYRO_SOURCE_VELOCITYTRIGGER_H
