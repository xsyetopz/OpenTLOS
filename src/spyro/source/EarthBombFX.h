#ifndef SPYRO_SOURCE_EARTHBOMBFX_H
#define SPYRO_SOURCE_EARTHBOMBFX_H

#include <dolphin/types.h>
#include "common/Source/MKVector4.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"

class BreathHitMessage;
class EarthBombFX;
class EarthBombFXDescriptor;
class GameProp;
class GamePropDescriptor;
class MKCollisionInfo;
class MKMaterial;
class MKMessage;
class MKProp;
class MKVector3;
class MKVector4;
class ManagedLight;

class EarthBombFX : public GameProp {  // base: vtable prefix
public:
    virtual ~EarthBombFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    EarthBombFX(void);
    void Fire(const MKVector3 &, const MKVector3 &, float, MKProp *, const MKVector3 &);
    void Explode(const MKVector3 &, const MKVector3 &, MKCollisionInfo *);
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ u8 padCC[0x4];
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ u8 unkE0;
    /* 0x0e1 */ u8 padE1[0x17];
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ ManagedLight* unk100;
    /* 0x104 */ u8 pad104[0x4];
    /* 0x108 */ MKVector4 unk108;
    /* 0x118 */ MKProp* unk118;
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ f32 unk120;
    /* 0x124 */ u8 pad124[0x4];
    /* 0x128 */ BreathHitMessage unk128;
    /* 0x180 */ s32 unk180;
};

class EarthBombFXDescriptor : public GamePropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Deinit(void);
    EarthBombFXDescriptor(void);
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ MKMaterial* unkEC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline EarthBombFX::EarthBombFX() {
    this->unk128.unk4 = 0;
    M2C_FIELD(this, s32 *, 0x180) = 0;
}

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline EarthBombFX::~EarthBombFX() {
    if (((this + 0x180) != NULL) && ((this + 0x180) != NULL)) {
        KDSound_Stop((s32 *) (this + 0x180));
    }
}
#endif

inline EarthBombFXDescriptor::EarthBombFXDescriptor() {
}

#endif  // SPYRO_SOURCE_EARTHBOMBFX_H
