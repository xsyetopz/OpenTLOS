#ifndef SPYRO_SOURCE_GAMEPARTICLEEMITTER_H
#define SPYRO_SOURCE_GAMEPARTICLEEMITTER_H

#include <dolphin/types.h>
#include "common/Source/MKVector4.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPath.h"

class DirectedLineEmitter;
class EmitterProperty;
class Explosion4;
class FoundryGas;
class GameParticleEmitter;
class GameProp;
class KDPathSegment;
class LavaSteamPS;
class LiquidFX;
class MKIniLine;
class MKMessage;
class MKVector3;
class MKVector4;
class PointDirEmitter;
class SparksPS;

class DirectedLineEmitter {
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Deinit(void);
    virtual void GetEmissionData(MKVector3 *, MKVector3 *, MKVector3 *, MKVector4 *);
    virtual void SetDirection(const MKVector3 &);
    virtual void SetPosition(const MKVector3 &);
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ KDPathSegment unk3C;
    /* 0x070 */ u8 pad70[0x2c];
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ s32 unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ f32 unkAC;
};

class EmitterProperty {
public:
    virtual void pure_slot0() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot1() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot2() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot3() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot4() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot5() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot6() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot7() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot8() = 0;  // name unknown: no descendant fills this slot
};

class GameParticleEmitter : public GameProp {  // base: vtable prefix
public:
    virtual ~GameParticleEmitter(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    GameParticleEmitter(void);
    void EmitEmber(void);
    void EmitDust(void);
    void EmitWaterDrip(void);
    void EmitWaterfallMist(void);
    void EmitWaterfall(void);
    void EmitHeat(void);
    void EmitExplosion(void);
    void EmitLavaSteam(void);
    void EmitSparks(void);
    void EmitFoundryGas(void);
    void EmitMoltenMetal(void);
    void EmitLavaBubble(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ void** unkC8;
    /* 0x0cc */ u32 unkCC;
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ s32 unkDC;
    /* 0x0e0 */ u8 unkE0;
    /* 0x0e1 */ u8 unkE1;
    /* 0x0e2 */ u8 padE2[0x2];
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ LiquidFX* unkE8;
    /* 0x0ec */ FoundryGas* unkEC;
    /* 0x0f0 */ SparksPS* unkF0;
    /* 0x0f4 */ LavaSteamPS* unkF4;
    /* 0x0f8 */ Explosion4* unkF8;
    /* 0x0fc */ void* unkFC;
    /* 0x100 */ void* unk100;
    /* 0x104 */ u8 pad104[0x4];
    /* 0x108 */ MKVector4 unk108;
};

class PointDirEmitter {
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Deinit(void);
    virtual void GetEmissionData(MKVector3 *, MKVector3 *, MKVector3 *, MKVector4 *);
    virtual void SetDirection(const MKVector3 &);
    virtual void SetPosition(const MKVector3 &);
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ f32 unk40;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline GameParticleEmitter::GameParticleEmitter() {
    return this;
}
#endif

inline GameParticleEmitter::~GameParticleEmitter() {
}

#endif  // SPYRO_SOURCE_GAMEPARTICLEEMITTER_H
