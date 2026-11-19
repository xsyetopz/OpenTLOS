#ifndef SPYRO_SOURCE_PLATFORM_H
#define SPYRO_SOURCE_PLATFORM_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/PlatformObject.h"

class GameProp;
class KDPropExDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;
class Platform;
class PlatformAttachment;
class PlatformDescriptor;
class PlatformObject;
class PlatformRider;

class PlatformRider {
public:
    void ToWorldDir(const MKVector3 &);
    void ToWorld(const MKVector3 &);
    void Attach(PlatformAttachment *);
    void Resolve(void);
    void LoadLine(MKIniLine *);
    void Init(void);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
};

class Platform : public GameProp {  // base: vtable prefix
public:
    virtual ~Platform(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Message(MKMessage *);
    virtual void PropUpdate(void);
    virtual void UpdateMove(void);
    virtual void UpdateScale(void);
    virtual void UpdateSway(void);
    virtual void UpdateRotate(void);
    virtual void UpdateBob(void);
    Platform(void);
    void UpdateShadow(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ f64 unkC8;
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ u8 padE4[0x4];
    /* 0x0e8 */ f64 unkE8;
    /* 0x0f0 */ f64 unkF0;
    /* 0x0f8 */ f64 unkF8;
    /* 0x100 */ f64 unk100;
    /* 0x108 */ PlatformObject unk108;
    /* 0x14c */ u8 pad14C[0x4];
    /* 0x150 */ PlatformRider unk150;
    /* 0x160 */ u8 pad160[0xc];
    /* 0x16c */ f32 unk16C;
    /* 0x170 */ f32 unk170;
    /* 0x174 */ s8 unk174;
    /* 0x175 */ u8 unk175;
    /* 0x176 */ u8 pad176[0x2];
    /* 0x178 */ s32 unk178;
};

class PlatformDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    PlatformDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ f32 unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ s8 unkF4;
    /* 0x0f5 */ u8 unkF5;
    /* 0x0f6 */ u8 padF6[0x2];
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ u8 unk104;
    /* 0x105 */ u8 pad105[0x3];
    /* 0x108 */ f32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ u8 unk118;
    /* 0x119 */ u8 pad119[0x3];
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ f32 unk120;
};

#endif  // SPYRO_SOURCE_PLATFORM_H
