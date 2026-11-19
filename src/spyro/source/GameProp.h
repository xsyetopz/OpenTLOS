#ifndef SPYRO_SOURCE_GAMEPROP_H
#define SPYRO_SOURCE_GAMEPROP_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSoundTools.h"

class EventMessage;
class FireAndIceFX;
class GameProp;
class GamePropDescriptor;
class KDPropEx;
class KDPropExDescriptor;
class KDSound_LoopSoundEvent;
class MKIniLine;
class MKMessage;

class GameProp : public KDPropEx {  // base: ctor/dtor vtable stores
public:
    virtual ~GameProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void PropUpdate(void);
    virtual void Activate(void);
    virtual void Deactivate(void);
    GameProp(void);
    void PostDraw(void);
    void PreDraw(void);
    /* 0x090 */ KDSound_LoopSoundEvent unk90;
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ s32 unkBC;
    /* 0x0c0 */ FireAndIceFX* unkC0;
};

class GamePropDescriptor : public KDPropExDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    GamePropDescriptor(void);
    /* 0x0c0 */ s8* unkC0;
    /* 0x0c4 */ s8* unkC4;
    /* 0x0c8 */ s8* unkC8;
    /* 0x0cc */ EventMessage unkCC;
    /* 0x0d0 */ EventMessage unkD0;
    /* 0x0d4 */ s32 unkD4;
    /* 0x0d8 */ s32 unkD8;
    /* 0x0dc */ s32 unkDC;
    /* 0x0e0 */ s32 unkE0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline GameProp::~GameProp() {
    s32 temp_cr0_eq_17649;

    temp_cr0_eq_17649 = this == NULL;
    if (temp_cr0_eq_17649 == 0) {
        if (temp_cr0_eq_17649 == 0) {
            if (temp_cr0_eq_17649 == 0) {
                if (temp_cr0_eq_17649 == 0) {
                }
            }
        }
    }
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline GameProp::GameProp() {
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline GamePropDescriptor::GamePropDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_GAMEPROP_H
