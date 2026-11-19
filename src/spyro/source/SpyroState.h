#ifndef SPYRO_SOURCE_SPYROSTATE_H
#define SPYRO_SOURCE_SPYROSTATE_H

#include <dolphin/types.h>

class MKMessage;
class Spyro;
class SpyroState;
class SpyroStateCreatorTableEntry;
class SpyroStateMachine;
class SpyroStateMessages;
class SpyroState_cpp;

class SpyroState {
public:
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &) = 0;
    virtual void Exit(void) = 0;
    virtual void Update(void) = 0;
    virtual s32 Transition(void) = 0;
    virtual void ProcessAnimEvent(unsigned int);
    virtual void Message(MKMessage *);
    virtual void * GetStateInfo(void);
};

class SpyroStateMachine {
public:
    s32 GetMedium(int);
    void ProcessAnimEvent(unsigned int);
    void Message(MKMessage *);
    void Update(void);
    void SetState(int, MKMessage *);
    void SetState(int, SpyroStateMessages &);
    void Reset(int, SpyroStateMessages &);
    void Deinit(void);
    void Init(Spyro *, SpyroStateCreatorTableEntry *, int);
    /* 0x000 */ Spyro* unk0;
    /* 0x004 */ void* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
};

class SpyroStateMessages {
public:
    s32 IsMessageOnList(int);
    MKMessage * GetMessage(int);
    void AddMessage(int);
    void AddMessage(MKMessage *);
    /* 0x000 */ u8 pad0[0x50];
    /* 0x050 */ u32 unk50;
};

class SpyroState_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline void SpyroState::Init(Spyro *arg0) {
    M2C_FIELD(this, Spyro **, 0x10) = arg0;
}

inline void SpyroState::Deinit() {

}

inline void SpyroState::ProcessAnimEvent(unsigned int arg0) {

}

inline void SpyroState::Message(MKMessage *arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'const char[1]' to
inline void *SpyroState::GetStateInfo() {
    return "";
}
#endif

#endif  // SPYRO_SOURCE_SPYROSTATE_H
