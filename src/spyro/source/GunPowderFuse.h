#ifndef SPYRO_SOURCE_GUNPOWDERFUSE_H
#define SPYRO_SOURCE_GUNPOWDERFUSE_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/SplineProp.h"

class BurnPoint;
class EventMessage;
class GunPowderFuse;
class GunPowderFuse_cpp;
class MKIniLine;
class MKMaterial;
class MKMessage;
class SplineProp;

class GunPowderFuse : public SplineProp {  // base: ctor/dtor vtable stores
public:
    virtual ~GunPowderFuse(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void EmitBurn(float);
    BurnPoint * GetFirst(void);
    BurnPoint * GetNextPositive(BurnPoint *);
    void UpdatePartners(void);
    s32 GetPartner(BurnPoint *);
    u8 IsBurnable(float);
    u8 TooClose(float);
    u8 HasAvailableBurnPoints(void);
    u8 IsBurntOut(void);
    u8 IsBurning(void);
    void Burn(float);
    /* 0x0b8 */ u8 padB8[0x8];
    /* 0x0c0 */ EventMessage unkC0;
    /* 0x0c4 */ u8 padC4[0x1e0];
    /* 0x2a4 */ MKMaterial* unk2A4;
    /* 0x2a8 */ f32 unk2A8;
    /* 0x2ac */ f32 unk2AC;
    /* 0x2b0 */ f32 unk2B0;
    /* 0x2b4 */ s32 unk2B4;
    /* 0x2b8 */ u8 unk2B8;
    /* 0x2b9 */ u8 unk2B9;
    /* 0x2ba */ u8 unk2BA;
};

class GunPowderFuse_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_GUNPOWDERFUSE_H
