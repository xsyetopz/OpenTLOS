#ifndef SPYRO_SOURCE_FIREBOMBFX_H
#define SPYRO_SOURCE_FIREBOMBFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"

class BreathHitMessage;
class ClusterBomb;
class Explosion4;
class FireBombFX;
class FireBombFXDescriptor;
class GameProp;
class MKCollisionInfo;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class MKVector4;
class ManagedLight;
class ShapedTrailFX;

class FireBombFX : public GameProp {  // base: vtable prefix
public:
    virtual ~FireBombFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    FireBombFX(void);
    void Fire(const MKVector3 &, const MKVector3 &, float, MKProp *, bool, bool, int, const MKVector3 &);
    void DrawFlameBall(void);
    void Explode(const MKVector3 &, const MKVector3 &, MKCollisionInfo *);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ ShapedTrailFX* unkCC;
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ u8 unkE0;
    /* 0x0e1 */ u8 padE1[0x17];
    /* 0x0f8 */ Explosion4* unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ ManagedLight* unk108;
    /* 0x10c */ u8 pad10C[0x4];
    /* 0x110 */ MKVector4 unk110;
    /* 0x120 */ MKProp* unk120;
    /* 0x124 */ f32 unk124;
    /* 0x128 */ f32 unk128;
    /* 0x12c */ u8 pad12C[0x4];
    /* 0x130 */ BreathHitMessage unk130;
    /* 0x181 */ u8 pad181[0x7];
    /* 0x188 */ s32 unk188;
    /* 0x18c */ u8 pad18C[0x24];
    /* 0x1b0 */ u8 unk1B0;
    /* 0x1b1 */ u8 pad1B1[0x3];
    /* 0x1b4 */ ClusterBomb* unk1B4;
    /* 0x1b8 */ u8 unk1B8;
    /* 0x1b9 */ u8 pad1B9[0x3];
    /* 0x1bc */ s32 unk1BC;
    /* 0x1c0 */ s32 unk1C0;
    /* 0x1c4 */ s32 unk1C4;
    /* 0x1c8 */ f32 unk1C8;
    /* 0x1cc */ u8 pad1CC[0x8];
    /* 0x1d4 */ f32 unk1D4;
    /* 0x1d8 */ f32 unk1D8;
};

class FireBombFXDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    FireBombFXDescriptor(void);
    /* 0x048 */ u8 pad48[0x9c];
    /* 0x0e4 */ s8* unkE4;
    /* 0x0e8 */ s8* unkE8;
    /* 0x0ec */ MKMaterial* unkEC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk4'
inline FireBombFX::FireBombFX() {
    this->unk130.unk4 = 0;
    this->unk188 = 0;
    this->unk1BC = 0;
    this->unk1C0 = 0;
    this->unk1C4 = 0.0f;
    this->unk1C8 = 0.0f;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline FireBombFX::~FireBombFX() {
    if ((&this->unk188 != NULL) && (&this->unk188 != NULL)) {
        KDSound_Stop(&this->unk188);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FireBombFXDescriptor::FireBombFXDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_FIREBOMBFX_H
