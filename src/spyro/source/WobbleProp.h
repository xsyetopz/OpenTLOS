#ifndef SPYRO_SOURCE_WOBBLEPROP_H
#define SPYRO_SOURCE_WOBBLEPROP_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"

class GameProp;
class KDPropExDescriptor;
class MKIniLine;
class MKMaterial;
class MKMessage;
class WobbleProp;
class WobblePropDescriptor;

class WobbleProp : public GameProp {  // base: vtable prefix
public:
    virtual ~WobbleProp(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    WobbleProp(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ void* unkC8;
    /* 0x0cc */ u8 unkCC;
    /* 0x0cd */ u8 padCD[0x3];
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ MKMaterial* unkD4;
    /* 0x0d8 */ s32 unkD8;
    /* 0x0dc */ u8 unkDC;
    /* 0x0dd */ u8 padDD[0x3];
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ f32 unkE8;
};

class WobblePropDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    WobblePropDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ s8* unkEC;
};

#endif  // SPYRO_SOURCE_WOBBLEPROP_H
