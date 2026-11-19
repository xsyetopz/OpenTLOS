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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unk0'
inline void MeleeAttackHitMsg::Init(MKProp *arg0, const MKVector3 &arg1, float arg2, bool arg3, int arg4, unsigned int arg5, MKPtrList<MKProp> *arg6, float arg7) {
    this->unk0 = 4;
    this->unk8 = (Spyro *) arg0;
    this->unk10 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk18 = M2C_FIELD(&arg1, f64 *, 8);
    this->unk20 = arg2;
    this->unk3C = arg3;
    this->unk28 = arg4;
    this->unk30 = (s32) arg5;
    this->unk3D = 0;
    this->unk3E = 0;
    this->unk2C = -1;
    this->unk34 = &arg6->unk0;
    this->unk38 = 0;
    this->unk24 = arg7;
}
#endif

#endif  // SPYRO_SOURCE_MELEEATTACKHITMSG_H
