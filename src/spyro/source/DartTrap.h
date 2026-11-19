#ifndef SPYRO_SOURCE_DARTTRAP_H
#define SPYRO_SOURCE_DARTTRAP_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class DartTrap;
class DartTrapDescriptor;
class KDProp;
class KDPropDescriptor;
class MKIniLine;
class MKMessage;

class DartTrap : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~DartTrap(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    void SetState(int);
    void SetAnim(int);
    void Shoot(void);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ void* unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09c */ f32 unk9C;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ u8 unkB0;
};

class DartTrapDescriptor : public KDPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
};

#endif  // SPYRO_SOURCE_DARTTRAP_H
