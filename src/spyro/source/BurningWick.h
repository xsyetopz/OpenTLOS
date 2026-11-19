#ifndef SPYRO_SOURCE_BURNINGWICK_H
#define SPYRO_SOURCE_BURNINGWICK_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"

class BurningWick;
class MKModel;
class MKProp;
class MKVector3;

class BurningWick : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~BurningWick(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    void Burn(const bool &, const float &);
    s32 Burnt(void);
    void InitData(const int &, MKModel *, const MKVector3 &);
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ MKModel* unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ u8 unk84;
    /* 0x085 */ u8 pad85[0x3];
    /* 0x088 */ MKVector3 unk88;
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ f64 unkA0;
    /* 0x0a8 */ f64 unkA8;
    /* 0x0b0 */ f64 unkB0;
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ f32 unkBC;
    /* 0x0c0 */ f32 unkC0;
};

#endif  // SPYRO_SOURCE_BURNINGWICK_H
