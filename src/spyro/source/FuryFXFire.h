#ifndef SPYRO_SOURCE_FURYFXFIRE_H
#define SPYRO_SOURCE_FURYFXFIRE_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameMessages.h"
#include "unplaced_enums.h"

class BreathHitMessage;
class Corona;
class FuryFXFire;
class FuryFXFire_cpp;
class MKMaterial;
class MKMessage;
class MKModel;
class MKProp;
class MKVector3;
class ManagedLight;
class Matrix;

class FuryFXFire : public MKProp {  // base: ctor/dtor vtable stores
public:
    class DragonStruct {
    public:
        ~DragonStruct(void);
        DragonStruct(void);
    };
    virtual ~FuryFXFire(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    FuryFXFire(void);
    void ResetFury(void);
    s32 Trigger(const MKVector3 &, bool, bool, HeroHurtReactionType);
    void SetDefaults(void);
    void UpdateDragons(void);
    /* 0x04c */ u8 pad4C[0x40];
    /* 0x08c */ u8 unk8C;
    /* 0x08d */ u8 pad8D[0x3];
    /* 0x090 */ Matrix unk90;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ u8 padDC[0x4];
    /* 0x0e0 */ MKMaterial* unkE0;
    /* 0x0e4 */ MKMaterial* unkE4;
    /* 0x0e8 */ ManagedLight* unkE8;
    /* 0x0ec */ MKModel* unkEC;
    /* 0x0f0 */ MKModel* unkF0;
    /* 0x0f4 */ Corona* unkF4;
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ u8 pad108[0x188];
    /* 0x290 */ BreathHitMessage unk290;
    /* 0x2e4 */ u8 pad2E4[0x4];
    /* 0x2e8 */ s32 unk2E8;
    /* 0x2ec */ s32 unk2EC;
    /* 0x2f0 */ u8 unk2F0;
    /* 0x2f1 */ u8 unk2F1;
};

class FuryFXFire_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unk110'
inline FuryFXFire::FuryFXFire() {
    __construct_array(&this->unk110, (MKAnimScript *(*)(MKAnimScript *)) &FuryFXFire::DragonStruct::DragonStruct, (SpyroSoundPlayer::SpyroLoopSounds *(*)(SpyroSoundPlayer::SpyroLoopSounds *, s16)) &FuryFXFire::DragonStruct::~DragonStruct, 0x80, 3);
    this->unk290.unk4 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk110'
inline FuryFXFire::~FuryFXFire() {
    s32 temp_cr0_eq_27;

    if (this != NULL) {
        __destroy_arr(&this->unk110, &FuryFXFire::DragonStruct::~DragonStruct, 0x80, 3);
        temp_cr0_eq_27 = this == NULL;
        if (temp_cr0_eq_27 == 0) {
            if (temp_cr0_eq_27 == 0) {
                if (temp_cr0_eq_27 == 0) {
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline FuryFXFire::DragonStruct::~DragonStruct() {
    if (((this + 0x4C) != NULL) && ((this + 0x4C) != NULL)) {
        KDSound_Stop((s32 *) (this + 0x4C));
    }
    if (((this + 0x24) != NULL) && ((this + 0x24) != NULL)) {
        KDSound_Stop((s32 *) (this + 0x24));
    }
    if (arg1 > 0) {
        operator delete(this);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FuryFXFire::DragonStruct::DragonStruct() {
    M2C_FIELD(this, s32 *, 0x24) = 0;
    M2C_FIELD(this, s32 *, 0x4C) = 0;
    return this;
}
#endif

#endif  // SPYRO_SOURCE_FURYFXFIRE_H
