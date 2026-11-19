#ifndef SPYRO_SOURCE_SPYROTOOLS_H
#define SPYRO_SOURCE_SPYROTOOLS_H

#include <dolphin/types.h>

class MKModel;
class MKProp;
class MKVector3;
class SpyroLighting;
class SpyroNodeHelper;
class SpyroRotation;
class SpyroStuck;
class SpyroTargetList;
class SpyroTools_cpp;

class SpyroLighting {
public:
    void ApplyPointLight(MKVector3, float, float);
    void SetLight(MKVector3, float);
    void Reset(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ void* unk28;
};

class SpyroNodeHelper {
public:
    void SetPYR(const MKVector3 &);
    void Init(MKModel *, int);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ MKModel* unk14;
};

class SpyroRotation {
public:
    void RollTowards(float, float);
    void YawTowards(float, float);
    void YawTowards(const MKVector3 &, float);
    void RotateTowards(float, float, float, float);
    void Init(MKModel *, int);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
};

class SpyroStuck {
public:
    void Update(void);
    void Reset(void);
    void Init(MKProp *);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ MKProp* unk18;
};

class SpyroTargetList {
public:
    s32 CompareTargets(const void *, const void *);
    void **** UpdateTargetList(void);
    void ClearCurrentTarget(void);
    void GetCurrentTarget(void);
    s32 SelectTarget(bool);
    void SetDefaults(void);
    void Deinit(void);
    void Init(float, unsigned int, bool);
    /* 0x000 */ void*** unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ void**** unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ u32 unk10;
    /* 0x014 */ u8 unk14;
};

class SpyroTools_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_SPYROTOOLS_H
