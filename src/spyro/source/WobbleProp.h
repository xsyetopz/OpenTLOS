#ifndef SPYRO_SOURCE_WOBBLEPROP_H
#define SPYRO_SOURCE_WOBBLEPROP_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"

class GameProp;
class GamePropDescriptor;
class MKIniLine;
class MKMaterial;
class MKMessage;
class WobbleProp;
class WobblePropDescriptor;

class WobbleProp : public GameProp {  // base: base ctor call
public:
    virtual ~WobbleProp(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    WobbleProp(void);
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

class WobblePropDescriptor : public GamePropDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    WobblePropDescriptor(void);
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ s8* unkEC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline WobbleProp::WobbleProp() {
    return this;
}
#endif

inline WobbleProp::~WobbleProp() {
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline WobblePropDescriptor::WobblePropDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_WOBBLEPROP_H
