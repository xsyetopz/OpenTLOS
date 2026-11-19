#ifndef SPYRO_SOURCE_GAMEMESSAGES_H
#define SPYRO_SOURCE_GAMEMESSAGES_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"

class BreathHitMessage;
class Collectable;
class Enemy;
class EventCamera;
class FindNearestCollectableMsg;
class FuryEventCameraMsg;
class GetNearestEventCameraMsg;
class HitHeroSndMsg;
class IsInAlertRangeMsg;
class MKCollisionInfo;
class MKProp;
class MKVector3;

class BreathHitMessage {
public:
    void Init(MKProp *, float, int, int, int, int, int, int);
    void Init(MKProp *, int, int, int, int, int, int, int);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ MKVector3 unk20;
    /* 0x030 */ MKCollisionInfo* unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ s32 unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ s8 unk50;
};

class FindNearestCollectableMsg {
public:
    void Test(Collectable *);
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ u8 unk18;
    /* 0x019 */ u8 pad19[0x3];
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ Collectable* unk24;
};

class FuryEventCameraMsg {
public:
    u8 IsSenderBehindWall(EventCamera *);
    s32 AddCamera(EventCamera *);
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 pad8[0x50];
    /* 0x058 */ s32 unk58;
};

class GetNearestEventCameraMsg {
public:
    void Test(MKProp *, const MKVector3 &);
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ MKProp* unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
};

class HitHeroSndMsg {
public:
    HitHeroSndMsg(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
};

class IsInAlertRangeMsg {
public:
    void Test(Enemy *);
    void Init(const MKVector3 &, float);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ f32 unk18;
    /* 0x01c */ Enemy* unk1C;
    /* 0x020 */ f32 unk20;
};

#endif  // SPYRO_SOURCE_GAMEMESSAGES_H
