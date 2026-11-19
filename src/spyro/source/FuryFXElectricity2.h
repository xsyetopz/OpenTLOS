#ifndef SPYRO_SOURCE_FURYFXELECTRICITY2_H
#define SPYRO_SOURCE_FURYFXELECTRICITY2_H

#include <dolphin/types.h>
#include "spyro/source/FuryFX.h"
#include "spyro/source/GameMessages.h"

class BreathHitMessage;
class FuryFX;
class FuryFXElectricity2;
class FuryFXElectricity2_cpp;
class MKVector3;
class ManagedLight;
class Targetable;
class ZapPS;

class FuryFXElectricity2 : public FuryFX {  // base: ctor/dtor vtable stores
public:
    virtual ~FuryFXElectricity2(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    FuryFXElectricity2(void);
    void ResetFury(void);
    void DestroyAllLightningCages(void);
    void SpawnLightningCages(void);
    void SpawnLightningCage(Targetable *);
    void UpdateLightningCages(void);
    s32 Trigger(const MKVector3 &);
    void SetDefaults(void);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ s32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ u8 padA4[0x4];
    /* 0x0a8 */ ManagedLight* unkA8;
    /* 0x0ac */ ZapPS* unkAC;
    /* 0x0b0 */ BreathHitMessage unkB0;
    /* 0x101 */ u8 pad101[0x7];
    /* 0x108 */ f64 unk108;
    /* 0x110 */ f64 unk110;
    /* 0x118 */ f32 unk118;
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ f32 unk120;
    /* 0x124 */ void**** unk124;
    /* 0x128 */ s32 unk128;
};

class FuryFXElectricity2_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk4'
inline FuryFXElectricity2::FuryFXElectricity2() {
    this->unkB0.unk4 = 0;
    return this;
}
#endif

inline FuryFXElectricity2::~FuryFXElectricity2() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
                if (temp_cr0_eq_15 == 0) {
                }
            }
        }
    }
}

#endif  // SPYRO_SOURCE_FURYFXELECTRICITY2_H
