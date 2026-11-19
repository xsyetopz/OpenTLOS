#ifndef SPYRO_SOURCE_ZAPARCFX_H
#define SPYRO_SOURCE_ZAPARCFX_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"

class GameProp;
class MKVector3;
class MKVector4;
class ZapArcFX;

class ZapArcFX : public GameProp {  // base: vtable prefix
public:
    virtual ~ZapArcFX(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    ZapArcFX(void);
    void Trigger(const MKVector3 &, const MKVector3 &, const float &, const bool &, MKVector4);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ void* unkC8;
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ s32 unkD0;
};

#endif  // SPYRO_SOURCE_ZAPARCFX_H
