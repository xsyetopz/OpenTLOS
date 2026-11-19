#ifndef SPYRO_SOURCE_SHOCKWAVE_H
#define SPYRO_SOURCE_SHOCKWAVE_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class KDProp;
class MKModel;
class MKVector3;
class ShockWave;

class ShockWave : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ShockWave(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    void UpdateShockWave(int);
    s32 Start(MKVector3, float, float, bool, bool, bool);
    void SetMessage(int, const char *);
    /* 0x089 */ u8 pad89[0xa7];
    /* 0x130 */ f64 unk130;
    /* 0x138 */ f64 unk138;
    /* 0x140 */ f64 unk140;
    /* 0x148 */ f64 unk148;
    /* 0x150 */ s32 unk150;
    /* 0x154 */ s32 unk154;
    /* 0x158 */ s8* unk158;
    /* 0x15c */ MKModel* unk15C;
    /* 0x160 */ u8 unk160;
    /* 0x161 */ u8 unk161;
    /* 0x162 */ u8 unk162;
};

#endif  // SPYRO_SOURCE_SHOCKWAVE_H
