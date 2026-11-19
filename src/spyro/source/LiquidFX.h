#ifndef SPYRO_SOURCE_LIQUIDFX_H
#define SPYRO_SOURCE_LIQUIDFX_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"

class BreathHitMessage;
class GameProp;
class GamePropDescriptor;
class LFX_Blob;
class LiquidFX;
class LiquidFXDescriptor;
class MKMaterial;
class MKVector3;
class ManagedLight;

class LFX_Blob {
public:
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x1c];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x70];
    /* 0x09c */ s32 unk9C;
};

class LiquidFX : public GameProp {  // base: vtable prefix
public:
    virtual ~LiquidFX(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Draw(void);
    LiquidFX(void);
    void SpawnGroundCollisionFX(LFX_Blob *);
    s32 Emit(const int &, const MKVector3 &, const MKVector3 &, const MKVector3 &, const float &, float, bool, BreathHitMessage *, int, int);
    /* 0x0c8 */ u8 padC8[0x3e80];
    /* 0x3f48 */ s32 unk3F48;
    /* 0x3f4c */ s32 unk3F4C;
    /* 0x3f50 */ f32 unk3F50;
    /* 0x3f54 */ u8 pad3F54[0x8];
    /* 0x3f5c */ s32 unk3F5C;
    /* 0x3f60 */ s32 unk3F60;
    /* 0x3f64 */ MKMaterial* unk3F64;
    /* 0x3f68 */ f32 unk3F68;
    /* 0x3f6c */ MKMaterial* unk3F6C;
    /* 0x3f70 */ MKMaterial* unk3F70;
    /* 0x3f74 */ MKMaterial* unk3F74;
    /* 0x3f78 */ s32 unk3F78;
    /* 0x3f7c */ f32 unk3F7C;
    /* 0x3f80 */ BreathHitMessage* unk3F80;
    /* 0x3f84 */ ManagedLight* unk3F84;
    /* 0x3f88 */ f32 unk3F88;
};

class LiquidFXDescriptor : public GamePropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    LiquidFXDescriptor(void);
    static u8 pFirstDesc[0x4];
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ LiquidFXDescriptor* unkEC;
    /* 0x0f0 */ LiquidFXDescriptor* unkF0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk3F54'
inline LiquidFX::LiquidFX() {
    this->unk3F48 = 0;
    this->unk3F4C = 0;
    this->unk3F50 = 0.0f;
    this->unk3F54 = 0;
}
#endif

inline LiquidFX::~LiquidFX() {
}

inline LiquidFXDescriptor::LiquidFXDescriptor() {
}

#endif  // SPYRO_SOURCE_LIQUIDFX_H
