#ifndef SPYRO_SOURCE_MANAGEDLIGHT_H
#define SPYRO_SOURCE_MANAGEDLIGHT_H

#include <dolphin/types.h>

class MKVector3;
class MKVector4;
class ManagedLight;

class ManagedLight {
public:
    void SetPosition(const MKVector3 &);
    void SetColor(const MKVector4 &);
    void SetRadius(float);
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ u8 pad30[0x8];
    /* 0x038 */ f32 unk38;
    /* 0x03c */ void* unk3C;
};

#endif  // SPYRO_SOURCE_MANAGEDLIGHT_H
