#ifndef SPYRO_SOURCE_POINTS_H
#define SPYRO_SOURCE_POINTS_H

#include <dolphin/types.h>

class FogInfo;
class MKVector3;
class WindInfo;

template <class T0>
class Points {
public:
    void GetValueAt(const MKVector3 &, T0 *, T0 (*)(const T0 &, const T0 &, float));
    void Init(const char *);
};

class FogInfo {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
};

class WindInfo {
public:
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f32 unk10;
};

void WindPoints_Update(const MKVector3 &, WindInfo *);
void WindPoints_Deinit(void);
void WindPoints_Init(const char *);
void WindPoints_DeinitModule(void);
void WindPoints_InitModule(void);
void FogPoints_Update(const MKVector3 &, FogInfo *);
void FogPoints_Deinit(void);
void FogPoints_Init(const char *);
void FogPoints_DeinitModule(void);
void FogPoints_InitModule(void);
#endif  // SPYRO_SOURCE_POINTS_H
