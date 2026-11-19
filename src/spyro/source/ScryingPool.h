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
    virtual void Update(void);
    virtual void Message(MKMessage *);
    ScryingPool(void);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
};

class ScryingPoolDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    ScryingPoolDescriptor(void);
    /* 0x0c0 */ s32 unkC0;
    /* 0x0c4 */ s32 unkC4;
};

#endif  // SPYRO_SOURCE_SCRYINGPOOL_H
