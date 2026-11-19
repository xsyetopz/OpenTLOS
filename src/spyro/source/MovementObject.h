#ifndef SPYRO_SOURCE_MOVEMENTOBJECT_H
#define SPYRO_SOURCE_MOVEMENTOBJECT_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"

class CollisionObject;
class MKIniLine;
class MKVector3;
class MovementObject;
class MovementObjectDescriptor;

class MovementObject {
public:
    void UpdateCollisions(MKVector3 &, bool);
    void Update(bool);
    s32 LoadLine(MKIniLine *);
    void Init(MovementObjectDescriptor *, CollisionObject *);
    MovementObject(void);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ s8 unk28;
    /* 0x029 */ u8 pad29[0x3];
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ MKVector3 unk30;
    /* 0x040 */ MKVector3 unk40;
    /* 0x050 */ MovementObjectDescriptor* unk50;
    /* 0x054 */ CollisionObject* unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ f32 unk5C;
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
};

class MovementObjectDescriptor {
public:
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ s32 unkC;
};

#endif  // SPYRO_SOURCE_MOVEMENTOBJECT_H
