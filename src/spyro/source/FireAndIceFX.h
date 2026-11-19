#ifndef SPYRO_SOURCE_FIREANDICEFX_H
#define SPYRO_SOURCE_FIREANDICEFX_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"

class FireAndIceFX;
class MKMaterial;
class MKModel;
class Matrix;

class FireAndIceFX {
public:
    void SetCrumble(const bool &);
    void SetState(const int &, float);
    void SetDefaults(void);
    void Deinit(void);
    void DrawCleanup(void);
    s32 Draw(unsigned short *);
    void Update(void);
    void Init(MKModel *, const float &, const float &);
    /* 0x000 */ Matrix unk0;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ MKMaterial* unk60;
    /* 0x064 */ u8 pad64[0x4];
    /* 0x068 */ s32 unk68;
    /* 0x06c */ MKMaterial* unk6C;
    /* 0x070 */ MKMaterial* unk70;
    /* 0x074 */ MKModel* unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ u8 pad7C[0x4];
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ u8 pad98[0x4];
    /* 0x09c */ f32 unk9C;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ u8 unkA4;
    /* 0x0a5 */ u8 padA5[0x3];
    /* 0x0a8 */ f32 unkA8;
};

#endif  // SPYRO_SOURCE_FIREANDICEFX_H
