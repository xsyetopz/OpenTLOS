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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline SpikeTrap::SpikeTrap() {
    M2C_FIELD(this, void **, 0xC8) = (void *) (&__vt + 0x48);
    this->unkE8.unk0 = 0;
    this->unkE8.Init();
    this->unkEC.unk0 = 0;
    this->unkEC.Init();
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline SpikeTrap::~SpikeTrap() {
    M2C_FIELD(this, s32 **, 0xC8) = &__vt.unk48;
    if (&this->unkEC != NULL) {
        this->unkEC.Deinit();
    }
    if (&this->unkE8 != NULL) {
        this->unkE8.Deinit();
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SpikeTrapDescriptor::SpikeTrapDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SPIKETRAP_H
