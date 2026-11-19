#ifndef SPYRO_SOURCE_SPYROFURYSTATE_H
#define SPYRO_SOURCE_SPYROFURYSTATE_H

#include <dolphin/types.h>
#include "spyro/source/SpyroState.h"

class MKMessage;
class Spyro;
class SpyroFuryState;
class SpyroFuryState_cpp;
class SpyroState;
class SpyroStateMessages;

class SpyroFuryState : public SpyroState {  // base: inlined ctor vtable stores
public:
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &);
    virtual void Exit(void);
    virtual void Update(void);
    virtual s32 Transition(void);
    virtual void ProcessAnimEvent(unsigned int);
    virtual void Message(MKMessage *);
    virtual void GetStateInfo(void);
    static u8 states[0x24];
    /* 0x004 */ u8 pad4[0x24];
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ u8 pad34[0x4];
    /* 0x038 */ u8 unk38;
    /* 0x039 */ u8 unk39;
};

class SpyroFuryState_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk14'
inline void SpyroFuryState::GetStateInfo() {
    this->unk14.GetStateName(-1);
}
#endif

#endif  // SPYRO_SOURCE_SPYROFURYSTATE_H
