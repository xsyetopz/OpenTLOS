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
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ s32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ Shadow unk98;
    /* 0x0c5 */ u8 padC5[0x3];
    /* 0x0c8 */ s32 unkC8;
};

class CollapsiblePropDescriptor : public KDPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
};

class CollapsibleProp_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_COLLAPSIBLEPROP_H
