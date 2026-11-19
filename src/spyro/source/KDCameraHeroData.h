#ifndef SPYRO_SOURCE_KDCAMERAHERODATA_H
#define SPYRO_SOURCE_KDCAMERAHERODATA_H

#include <dolphin/types.h>

class HeroDataMessage;
class KDCameraHeroData;

class KDCameraHeroData {
public:
    u8 IsMoving(void);
    void Copy(HeroDataMessage &);
    void GetDir(void);
    /* 0x000 */ u8 pad0[0x30];
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f64 unk38;
    /* 0x040 */ f64 unk40;
    /* 0x048 */ f64 unk48;
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f64 unk58;
    /* 0x060 */ u8 pad60[0x34];
    /* 0x094 */ u8 unk94;
    /* 0x095 */ u8 pad95[0x13];
    /* 0x0a8 */ void* unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ u8 padB4[0x14];
    /* 0x0c8 */ f64 unkC8;
    /* 0x0d0 */ f32 unkD0;
};

#endif  // SPYRO_SOURCE_KDCAMERAHERODATA_H
