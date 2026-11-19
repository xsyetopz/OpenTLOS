#ifndef SPYRO_SOURCE_SPIKETRAP_H
#define SPYRO_SOURCE_SPIKETRAP_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Trap.h"

class EventMessage;
class KDPropExDescriptor;
class MKIniLine;
class MKMessage;
class SpikeTrap;
class SpikeTrapDescriptor;
class Trap;

class SpikeTrap : public Trap {  // base: vtable prefix
public:
    virtual ~SpikeTrap(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    SpikeTrap(void);
    void SetState(int);
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ u8 unkE4;
    /* 0x0e5 */ u8 padE5[0x3];
    /* 0x0e8 */ EventMessage unkE8;
    /* 0x0ec */ EventMessage unkEC;
};

class SpikeTrapDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    SpikeTrapDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
};

#endif  // SPYRO_SOURCE_SPIKETRAP_H
