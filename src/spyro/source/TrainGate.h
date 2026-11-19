#ifndef SPYRO_SOURCE_TRAINGATE_H
#define SPYRO_SOURCE_TRAINGATE_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"

class EventMessage;
class GameProp;
class KDPropExDescriptor;
class MKIniLine;
class MKMessage;
class TrainGate;
class TrainGateDescriptor;
class TrainGateState;

class TrainGate : public GameProp {  // base: vtable prefix
public:
    virtual ~TrainGate(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    TrainGate(void);
    void SetState(TrainGateState);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ EventMessage unkC8;
    /* 0x0cc */ s32 unkCC;
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ s32 unkD4;
};

class TrainGateDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Resolve(void);
    TrainGateDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline TrainGate::TrainGate() {
    this->unkC8.unk0 = 0;
    this->unkC8.Init();
    return this;
}
#endif

inline TrainGate::~TrainGate() {
    if (&this->unkC8 != NULL) {
        this->unkC8.Deinit();
    }
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline TrainGateDescriptor::TrainGateDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_TRAINGATE_H
