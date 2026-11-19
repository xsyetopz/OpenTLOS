#ifndef SPYRO_SOURCE_STEAMVALVE_H
#define SPYRO_SOURCE_STEAMVALVE_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"

class GameProp;
class GamePropDescriptor;
class MKIniLine;
class MKMessage;
class Steam;
class SteamValve;
class SteamValveDescriptor;

class SteamValve : public GameProp {  // base: base ctor call
public:
    virtual ~SteamValve(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    SteamValve(void);
    /* 0x0c8 */ Steam* unkC8;
    /* 0x0cc */ s8 unkCC;
    /* 0x0cd */ u8 padCD[0x3];
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ u8 unkDC;
    /* 0x0dd */ u8 unkDD;
};

class SteamValveDescriptor : public GamePropDescriptor {  // base: base ctor call
public:
    virtual void Resolve(void);
    SteamValveDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline SteamValve::SteamValve() {
}

inline SteamValve::~SteamValve() {
}

inline SteamValveDescriptor::SteamValveDescriptor() {
}

#endif  // SPYRO_SOURCE_STEAMVALVE_H
