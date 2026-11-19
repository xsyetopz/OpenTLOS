#ifndef SPYRO_SOURCE_NODELOOKAT_H
#define SPYRO_SOURCE_NODELOOKAT_H

#include <dolphin/types.h>

class MKModel;
class MKVector3;
class NLStyle;
class NodeLookAt;
class NodeLookAtIK;

class NodeLookAt {
public:
    void Reset(void);
    void Update(MKVector3 *);
    void Init(MKModel *, int, NLStyle);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ MKModel* unk30;
    /* 0x034 */ u32 unk34;
    /* 0x038 */ u8 unk38;
};

class NodeLookAtIK {
public:
    void Update(MKVector3 *);
    f32 GetYawAssist(void) const;
    f32 GetPitchAssist(void) const;
    void Init(MKModel *, int);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ MKModel* unk34;
    /* 0x038 */ u8 unk38;
    /* 0x039 */ u8 pad39[0x3];
    /* 0x03c */ u32 unk3C;
    /* 0x040 */ NodeLookAtIK* unk40;
    /* 0x044 */ void* unk44;
};

#endif  // SPYRO_SOURCE_NODELOOKAT_H
