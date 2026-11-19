#ifndef SPYRO_SOURCE_SHADOW_H
#define SPYRO_SOURCE_SHADOW_H

#include <dolphin/types.h>

class MKModel;
class MKProp;
class MKVector3;
class Shadow;

class Shadow {
public:
    void Show(bool);
    void Draw(void);
    void GetLightPos(MKVector3 *);
    void Deinit(void);
    void Init(MKModel *, MKProp *, float, MKVector3 *, float);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ MKModel* unk10;
    /* 0x014 */ MKProp* unk14;
    /* 0x018 */ Shadow* unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 unk2C;
};

void Shadow_Draw(void);
void Shadow_EndDraw(void);
void Shadow_BeginDraw(void);
#endif  // SPYRO_SOURCE_SHADOW_H
