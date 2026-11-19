#ifndef SPYRO_SOURCE_LENSFLARE_H
#define SPYRO_SOURCE_LENSFLARE_H

#include <dolphin/types.h>

class LensFlare;
class MKMaterial;
class MKVector3;
class MKZRequest;

class LensFlare {
public:
    void DrawSun(MKVector3, float);
    void Draw(void);
    void Update(void);
    void Deinit(void);
    void Init(MKVector3 *);
    /* 0x000 */ MKMaterial* unk0;
    /* 0x004 */ MKMaterial* unk4;
    /* 0x008 */ MKZRequest* unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 unk24;
    /* 0x025 */ u8 pad25[0xb];
    /* 0x030 */ s32 unk30;
    /* 0x034 */ u8 pad34[0x4];
    /* 0x038 */ MKVector3* unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05c */ s32 unk5C;
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ u8 unk98;
};

#endif  // SPYRO_SOURCE_LENSFLARE_H
