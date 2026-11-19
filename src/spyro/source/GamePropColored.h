#ifndef SPYRO_SOURCE_GAMEPROPCOLORED_H
#define SPYRO_SOURCE_GAMEPROPCOLORED_H

#include <dolphin/types.h>
#include "common/Source/MKVector4.h"
#include "spyro/source/GameProp.h"

class GameProp;
class GamePropColored;
class GamePropColoredDescriptor;
class GamePropDescriptor;
class MKIniLine;
class MKVector4;

class GamePropColored : public GameProp {  // base: base ctor call
public:
    virtual ~GamePropColored(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Draw(void);
    GamePropColored(void);
    /* 0x0c8 */ MKVector4 unkC8;
};

class GamePropColoredDescriptor : public GamePropDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    GamePropColoredDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline GamePropColored::~GamePropColored() {
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline GamePropColored::GamePropColored() {
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline GamePropColoredDescriptor::GamePropColoredDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_GAMEPROPCOLORED_H
