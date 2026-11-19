#ifndef SPYRO_SOURCE_FLAMEBREATHBEAMFX_H
#define SPYRO_SOURCE_FLAMEBREATHBEAMFX_H

#include <dolphin/types.h>
#include "common/Source/MKVector4.h"
#include "spyro/source/KDSpline.h"

class FlameBreathBeam;
class KDUniformSpline;
class MKMaterial;
class MKVector3;
class MKVector4;

class FlameBreathBeam {
public:
    void Deinit(void);
    void Draw(void);
    void Update(void);
    void ResetBeamNodes(MKVector3, MKVector3, MKVector3);
    void SetBeamPositions(MKVector3, MKVector3, MKVector3);
    void UpdateBeam(MKVector3, MKVector3, MKVector3);
    void Init(const char *, const char *, const char *, const char *);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ u8 pad8[0xc];
    /* 0x014 */ MKMaterial* unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ u8 pad20[0xc];
    /* 0x02c */ MKMaterial* unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ u8 pad38[0xc];
    /* 0x044 */ MKMaterial* unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ u8 pad50[0xc];
    /* 0x05c */ MKMaterial* unk5C;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ u8 pad68[0xc];
    /* 0x074 */ MKMaterial* unk74;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f64 unk80;
    /* 0x088 */ f64 unk88;
    /* 0x090 */ f64 unk90;
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ f64 unkA0;
    /* 0x0a8 */ f64 unkA8;
    /* 0x0b0 */ f64 unkB0;
    /* 0x0b8 */ f64 unkB8;
    /* 0x0c0 */ f64 unkC0;
    /* 0x0c8 */ KDUniformSpline unkC8;
    /* 0x0dc */ MKMaterial* unkDC;
    /* 0x0e0 */ MKMaterial* unkE0;
    /* 0x0e4 */ MKMaterial* unkE4;
    /* 0x0e8 */ MKMaterial* unkE8;
    /* 0x0ec */ u8 padEC[0x4];
    /* 0x0f0 */ MKVector4 unkF0;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ u8 unk108;
    /* 0x109 */ u8 pad109[0x3];
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f32 unk110;
};

#endif  // SPYRO_SOURCE_FLAMEBREATHBEAMFX_H
