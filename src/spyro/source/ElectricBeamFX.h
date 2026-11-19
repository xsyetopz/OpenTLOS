#ifndef SPYRO_SOURCE_ELECTRICBEAMFX_H
#define SPYRO_SOURCE_ELECTRICBEAMFX_H

#include <dolphin/types.h>

class ElectricBeam;
class MKAnimScript;
class MKDynamicBone;
class MKMaterial;
class MKModel;
class MKVector3;

class ElectricBeam {
public:
    ElectricBeam(void);
    void EmitSparks(void);
    void Deinit(void);
    void Draw(void);
    void Update(void);
    void SetBeamPositions(MKVector3, MKVector3, MKVector3);
    void UpdateBeam(MKVector3, MKVector3, MKVector3);
    void UpdateWiggleBones(void);
    void UpdateWiggleBone(MKDynamicBone *, void *);
    void Init(void);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ s32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x8];
    /* 0x044 */ MKModel* unk44;
    /* 0x048 */ MKAnimScript* unk48;
    /* 0x04c */ u8 pad4C[0x150];
    /* 0x19c */ u8 unk19C;
    /* 0x19d */ u8 pad19D[0x33];
    /* 0x1d0 */ f32 unk1D0;
    /* 0x1d4 */ f32 unk1D4;
    /* 0x1d8 */ f32 unk1D8;
    /* 0x1dc */ f32 unk1DC;
    /* 0x1e0 */ f32 unk1E0;
    /* 0x1e4 */ u8 unk1E4;
    /* 0x1e5 */ u8 pad1E5[0x3];
    /* 0x1e8 */ f32 unk1E8;
    /* 0x1ec */ f32 unk1EC;
    /* 0x1f0 */ MKMaterial* unk1F0;
    /* 0x1f4 */ u8 unk1F4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk3C'
inline ElectricBeam::ElectricBeam() {
    this->unk30 = 0;
    this->unk34 = 0;
    this->unk38 = 0.0f;
    this->unk3C = 0;
}
#endif

#endif  // SPYRO_SOURCE_ELECTRICBEAMFX_H
