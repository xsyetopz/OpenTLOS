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

class GamePropColored : public GameProp {  // base: vtable prefix
public:
    virtual ~GamePropColored(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Draw(void);
    GamePropColored(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ MKVector4 unkC8;
};

class GamePropColoredDescriptor : public GamePropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    GamePropColoredDescriptor(void);
};

#endif  // SPYRO_SOURCE_GAMEPROPCOLORED_H
