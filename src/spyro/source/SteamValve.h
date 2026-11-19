#ifndef SPYRO_SOURCE_STEAMVALVE_H
#define SPYRO_SOURCE_STEAMVALVE_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"

class GameProp;
class KDPropExDescriptor;
class MKIniLine;
class MKMessage;
class Steam;
class SteamValve;
class SteamValveDescriptor;

class SteamValve : public GameProp {  // base: vtable prefix
public:
    virtual ~SteamValve(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    SteamValve(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ Steam* unkC8;
    /* 0x0cc */ s8 unkCC;
    /* 0x0cd */ u8 padCD[0x3];
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ u8 unkDC;
    /* 0x0dd */ u8 unkDD;
};

class SteamValveDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Resolve(void);
    SteamValveDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
};

#endif  // SPYRO_SOURCE_STEAMVALVE_H
