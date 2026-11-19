#ifndef SPYRO_SOURCE_FURYFXEARTH_H
#define SPYRO_SOURCE_FURYFXEARTH_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/WindFX.h"

class BreathHitMessage;
class Corona;
class FallingLeaves;
class FuryFX;
class FuryFXEarth;
class FuryFXEarth_cpp;
class MKPropDescriptor;
class MKVector3;
class ManagedLight;
class Matrix;
class SuckeyPS;
class WindFX;

class FuryFXEarth : public FuryFX {  // base: ctor/dtor vtable stores
public:
    virtual ~FuryFXEarth(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    FuryFXEarth(void);
    void TriggerBoulders(void);
    void ResetFury(void);
    s32 Trigger(const MKVector3 &, bool);
    void SetDefaults(void);
    void EmitLeaves(void);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ WindFX unk90;
    /* 0x0c0 */ Matrix unkC0;
    /* 0x100 */ FallingLeaves* unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ f32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ MKVector3 unk110;
    /* 0x120 */ u8 pad120[0x30];
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ f32 unk158;
    /* 0x15c */ f32 unk15C;
    /* 0x160 */ SuckeyPS* unk160;
    /* 0x164 */ Corona* unk164;
    /* 0x168 */ BreathHitMessage unk168;
    /* 0x1b9 */ u8 pad1B9[0x7];
    /* 0x1c0 */ MKPropDescriptor* unk1C0;
    /* 0x1c4 */ s32 unk1C4;
    /* 0x1c8 */ u8 unk1C8;
    /* 0x1c9 */ u8 pad1C9[0x3];
    /* 0x1cc */ ManagedLight* unk1CC;
};

class FuryFXEarth_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FuryFXEarth::FuryFXEarth() {
    this->unk168.unk4 = 0;
    return this;
}
#endif

inline FuryFXEarth::~FuryFXEarth() {
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

#endif  // SPYRO_SOURCE_FURYFXEARTH_H
