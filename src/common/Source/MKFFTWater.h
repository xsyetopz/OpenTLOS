#ifndef COMMON_SOURCE_MKFFTWATER_H
#define COMMON_SOURCE_MKFFTWATER_H

#include <dolphin/types.h>
#include "common/Source/MKVector4.h"

class MKCaptureReflection;
class MKFFTBaseType;
class MKFFTNormalMap;
class MKFFTWater;
class MKFFTWaterType;
class MKHeap;
class MKIniLine;
class MKMaterial;
class MKModel;
class MKVector3;
class MKVector4;
class Texture;

class MKCaptureReflection {
public:
    u8 LoadLine(MKIniLine *);
    void Deinit(void);
    void Init(const char *);
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
};

class MKFFTNormalMap {
public:
    class ComplexNumber;
    void FFT(int, MKFFTNormalMap::ComplexNumber *, int, int);
    void BitReverse(MKFFTNormalMap::ComplexNumber *, int, int);
    void FFT2D(int, MKFFTNormalMap::ComplexNumber *);
    void Update(void);
    f32 GetPower(float);
    f32 GetDirectionScale(float, float);
    f32 GetAmplitude(const MKVector3 &);
    void BuildWave(void);
    void LoadDone(void);
    u8 LoadLine(MKIniLine *);
    void Init(void);
    /* 0x000 */ u8 pad0[0x5000];
    /* 0x5000 */ f32 unk5000;
    /* 0x5004 */ f32 unk5004;
    /* 0x5008 */ f32 unk5008;
    /* 0x500c */ f32 unk500C;
    /* 0x5010 */ f32 unk5010;
    /* 0x5014 */ f32 unk5014;
    /* 0x5018 */ f32 unk5018;
    /* 0x501c */ f32 unk501C;
    /* 0x5020 */ s32 unk5020;
    /* 0x5024 */ f32 unk5024;
    /* 0x5028 */ f32 unk5028;
    /* 0x502c */ f32 unk502C;
};

class MKFFTBaseType {
public:
    void Deinit(void);
    void Update(void);
    void LoadDone(void);
    u8 LoadLine(MKIniLine *);
    void Init(MKModel *, const char *, MKFFTWater *);
    /* 0x000 */ MKModel* unk0;
    /* 0x004 */ MKHeap* unk4;
    /* 0x008 */ s16* unk8;
    /* 0x00c */ MKFFTWater* unkC;
    /* 0x010 */ MKFFTNormalMap unk10;
    /* 0x5040 */ MKMaterial* unk5040;
    /* 0x5044 */ MKMaterial* unk5044;
    /* 0x5048 */ MKMaterial* unk5048;
    /* 0x504c */ Texture* unk504C;
    /* 0x5050 */ Texture* unk5050;
    /* 0x5054 */ u8 pad5054[0x4];
    /* 0x5058 */ MKVector4 unk5058;
    /* 0x5068 */ f32 unk5068;
    /* 0x506c */ f32 unk506C;
    /* 0x5070 */ s32 unk5070;
    /* 0x5074 */ u8 pad5074[0x26];
    /* 0x509a */ s8 unk509A;
    /* 0x509b */ u8 pad509B[0x29];
    /* 0x50c4 */ s16* unk50C4;
    /* 0x50c8 */ f32 unk50C8;
    /* 0x50cc */ f32 unk50CC;
};

class MKFFTWater {
public:
    void Draw(unsigned short *, int);
    void DeinitInternal(void);
    void InitInternal(void);
    void Deinit(void);
    void PostDrawOcean(unsigned short *);
    void PreDrawOcean(unsigned short *);
    void ManagedDraw(void);
    void BuildVisibleTypesList(void);
    u8 WaterTypeExistsInMesh(const char *);
    void Init(const char *);
    static u8 typesVisible[0x28];
    static u8 numTypesVisible[0x4];
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ MKModel* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s16* unkC;
};

class MKFFTWaterType {
public:
    void Draw(unsigned short *);
    void Deinit(void);
    void RemoveFromLinkedList(void);
    void FixUpLinkedList(void);
    void LoadDone(void);
    s32 LoadLine(MKIniLine *);
    void Init(MKModel *, const char *, MKFFTWater *);
    /* 0x000 */ u8 pad0[0x509a];
    /* 0x509a */ s8 unk509A;
    /* 0x509b */ u8 pad509B[0x29];
    /* 0x50c4 */ u16* unk50C4;
    /* 0x50c8 */ u8 pad50C8[0x8];
    /* 0x50d0 */ Texture* unk50D0;
    /* 0x50d4 */ MKCaptureReflection unk50D4;
    /* 0x511c */ u8 pad511C[0x4];
    /* 0x5120 */ f32 unk5120;
    /* 0x5124 */ MKMaterial* unk5124;
    /* 0x5128 */ Texture* unk5128;
    /* 0x512c */ u8 pad512C[0x14];
    /* 0x5140 */ MKVector4 unk5140;
    /* 0x5150 */ u8 pad5150[0x4];
    /* 0x5154 */ s32 unk5154;
    /* 0x5158 */ f32 unk5158;
    /* 0x515c */ s32 unk515C;
    /* 0x5160 */ MKFFTWaterType* unk5160;
};

extern u8 pWaterTypes[0x28];
extern u8 gRandomSeed[0x4];
extern u8 bWaterEnabled;
extern s8 bWaterColorChanged;
extern u8 bWaveDataChanged;
#endif  // COMMON_SOURCE_MKFFTWATER_H
