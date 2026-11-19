#ifndef SPYRO_SOURCE_MELEEATTACKHITMSG_H
#define SPYRO_SOURCE_MELEEATTACKHITMSG_H

#include <dolphin/types.h>
#include "common/Source/MKPtrList.h"

class MKProp;
class MKVector3;
class MeleeAttackHitMsg;
class Spyro;

class MeleeAttackHitMsg {
public:
    void Init(MKProp *, const MKVector3 &, float, bool, int, unsigned int, MKPtrList<MKProp> *, float);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ Spyro* unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ MKProp*** unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ s8 unk3C;
    /* 0x03d */ s8 unk3D;
    /* 0x03e */ s8 unk3E;
};

#endif  // SPYRO_SOURCE_MELEEATTACKHITMSG_H
