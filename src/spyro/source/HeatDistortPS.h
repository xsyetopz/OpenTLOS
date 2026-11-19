#ifndef SPYRO_SOURCE_HEATDISTORTPS_H
#define SPYRO_SOURCE_HEATDISTORTPS_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"

class HeatDistortPS;
class MKHeap;
class MKMaterial;
class MKVector3;
class Matrix;

class HeatDistortPS {
public:
    class DistortParticle;
    void DrawParticle(HeatDistortPS::DistortParticle *, Matrix *);
    void Emit(const MKVector3 &, const MKVector3 &, float, float);
    void Deinit(void);
    void Draw(void);
    void Update(void);
    void Init(void);
    /* 0x000 */ MKMaterial* unk0;
    /* 0x004 */ MKHeap* unk4;
    /* 0x008 */ MKHeap* unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ MKVector3 unk10;
    /* 0x020 */ MKVector3 unk20;
    /* 0x030 */ MKVector3 unk30;
    /* 0x040 */ MKVector3 unk40;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
};

#endif  // SPYRO_SOURCE_HEATDISTORTPS_H
