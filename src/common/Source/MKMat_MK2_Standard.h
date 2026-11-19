#ifndef COMMON_SOURCE_MKMAT_MK2_STANDARD_H
#define COMMON_SOURCE_MKMAT_MK2_STANDARD_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"

class MKMat_MK2_Standard;
class MKMat_MK2_Standard_MaterialType;
class MKMat_MK2_Standard_cpp;
class MKMaterial;
class MatInfo;
class Matrix;
class Texture;

class MKMat_MK2_Standard {
public:
    void UsePass(void);
};

class MKMat_MK2_Standard_cpp {
public:
    void __sinit(void);
};

class MatInfo {
public:
    /* 0x000 */ u8 pad0[0x24];
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f64 unk38;
    /* 0x040 */ Matrix unk40;
    /* 0x0cc */ u8 padCC[0x18];
    /* 0x0e4 */ s8 unkE4;
    /* 0x0e5 */ u8 padE5[0x3];
    /* 0x0e8 */ Texture unkE8;
    /* 0x170 */ f32 unk170;
    /* 0x174 */ f32 unk174;
    /* 0x178 */ f32 unk178;
    /* 0x17c */ f32 unk17C;
    /* 0x180 */ f32 unk180;
    /* 0x184 */ f32 unk184;
    /* 0x188 */ f32 unk188;
    /* 0x18c */ f32 unk18C;
    /* 0x190 */ f32 unk190;
    /* 0x194 */ u8 pad194[0x48];
    /* 0x1dc */ u8 unk1DC;
    /* 0x1dd */ s8 unk1DD;
};

void MKMat_MK2_SetGlowWeights(float, float);
void MKMaterial_LinkMaterial_MK2_Standard(bool);
void MKMaterial_LinkMaterialGC_MK2_Standard(bool);
void Updater_ColorPulse(MKMaterial *, void *);
void Updater_Animate(MKMaterial *, void *);
void Updater_SinRotate(MKMaterial *, void *);
void Updater_Rotate(MKMaterial *, void *);
void Updater_SinScroll(MKMaterial *, void *);
void Updater_Scroll(MKMaterial *, void *);
void MKMat_MK2_Standard_DESTROY(MKMaterial *);
MKMaterial * MKMat_MK2_Standard_INIT(MatInfo *);
void MKMat_MK2_SetAlphaRef(MKMaterial *, float);
s32 MKMat_MK2_SetMaterialType(MKMaterial *, MKMat_MK2_Standard_MaterialType);
Texture * MKMat_MK2_GetBaseTexture(MKMaterial *);
extern f32 weight64;
extern f32 weight128;
extern s8 gbInitialiseMK2StandardGlow;
#endif  // COMMON_SOURCE_MKMAT_MK2_STANDARD_H
