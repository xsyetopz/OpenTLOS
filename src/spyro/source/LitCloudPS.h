#ifndef SPYRO_SOURCE_LITCLOUDPS_H
#define SPYRO_SOURCE_LITCLOUDPS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class LitCloudPS;
class MKHeap;
class MKMaterial;
class MKProp;
class MKVector3;
class MKVector4;
class Matrix;

class LitCloudPS : public MKProp {  // base: ctor/dtor vtable stores
public:
    class LitParticle;
    virtual ~LitCloudPS(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    void Explode(void);
    void StateUpdate(void);
    void SetScale(float);
    void Stop(void);
    void Trigger(const MKVector3 &);
    void SetLight(const MKVector3 &, const MKVector4 &, float);
    void Emit(const MKVector3 &, const MKVector4 &, float, bool);
    void DrawCloudlet(LitCloudPS::LitParticle *, Matrix *);
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f64 unk58;
    /* 0x060 */ f64 unk60;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ MKHeap* unk7C;
    /* 0x080 */ MKHeap* unk80;
    /* 0x084 */ MKMaterial* unk84;
    /* 0x088 */ f64 unk88;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ u8 pad94[0x4];
    /* 0x098 */ s32 unk98;
};

#endif  // SPYRO_SOURCE_LITCLOUDPS_H
