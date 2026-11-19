#ifndef SPYRO_SOURCE_FURYFXFIRE2_H
#define SPYRO_SOURCE_FURYFXFIRE2_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GroundFire.h"

class BreathHitMessage;
class ClusterBomb;
class Explosion4;
class FuryFX;
class FuryFXFire2;
class FuryFXFire2_cpp;
class GroundFire;
class MKModel;
class MKVector3;
class Matrix;

class FuryFXFire2 : public FuryFX {  // base: ctor/dtor vtable stores
public:
    class Meteor;
    virtual ~FuryFXFire2(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    FuryFXFire2(void);
    void ResetFury(void);
    void SpawnMeteor(void);
    void DrawMeteor(FuryFXFire2::Meteor *);
    void DrawMeteors(void);
    void UpdateMeteors(void);
    s32 Trigger(const MKVector3 &);
    void SetDefaults(void);
    /* 0x090 */ Matrix unk90;
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ u8 padD4[0x4];
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ u8 padE4[0x4];
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ u8 padEC[0x4];
    /* 0x0f0 */ BreathHitMessage unkF0;
    /* 0x144 */ u8 pad144[0x4];
    /* 0x148 */ MKModel* unk148;
    /* 0x14c */ f32 unk14C;
    /* 0x150 */ FuryFXFire2::Meteor** unk150;
    /* 0x154 */ Explosion4* unk154;
    /* 0x158 */ s32 unk158;
    /* 0x15c */ f32 unk15C;
    /* 0x160 */ ClusterBomb* unk160;
    /* 0x164 */ GroundFire unk164;
};

class FuryFXFire2_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FuryFXFire2::FuryFXFire2() {
    this->unkF0.unk4 = 0;
    return this;
}
#endif

inline FuryFXFire2::~FuryFXFire2() {
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

#endif  // SPYRO_SOURCE_FURYFXFIRE2_H
