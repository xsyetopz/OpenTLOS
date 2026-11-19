#ifndef SPYRO_SOURCE_KDCAMERAJUMPTARGETOFFSET_H
#define SPYRO_SOURCE_KDCAMERAJUMPTARGETOFFSET_H

#include <dolphin/types.h>

class KDCameraHeroData;
class KDCameraJumpTargetOffset;

class KDCameraJumpTargetOffset {
public:
    void Update(KDCameraHeroData &);
    void Exit(KDCameraHeroData &);
    void Enter(KDCameraHeroData &);
    void ClearData(void);
    void Init(float);
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 pad1[0x3];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
};

#endif  // SPYRO_SOURCE_KDCAMERAJUMPTARGETOFFSET_H
