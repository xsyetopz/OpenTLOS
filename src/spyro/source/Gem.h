#ifndef SPYRO_SOURCE_GEM_H
#define SPYRO_SOURCE_GEM_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/Collectable.h"

class Collectable;
class CollectableState;
class Gem;
class GemDescriptor;
class Gem_cpp;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKPropDescriptor;
class MKVector3;

class Gem : public Collectable {  // base: ctor/dtor vtable stores
public:
    virtual ~Gem(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void GetDescriptor(void);
    virtual void Spawn(const MKVector3 *, const MKVector3 *, bool);
    virtual void CollectEffects(void);
    virtual void SetState(CollectableState);
    virtual void CollectingStateInit(void);
    /* 0x145 */ u8 pad145[0x3];
    /* 0x148 */ s32 unk148;
};

class GemDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    /* 0x044 */ u8 pad44[0x22];
    /* 0x066 */ s8 unk66;
    /* 0x067 */ u8 pad67[0x5];
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ u8 pad70[0x4];
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ u8 pad7C[0x1c];
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ u8 padA0[0x28];
    /* 0x0c8 */ s32 unkC8;
    /* 0x0cc */ s32 unkCC;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ MKMaterial* unkD4;
};

class Gem_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unk128'
inline Gem::~Gem() {
    M2C_UNK *temp_r0_26;
    M2C_UNK *temp_r0_42;
    M2C_UNK *temp_r5_29;
    M2C_UNK *temp_r5_45;
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (&this->unk128 != NULL) {
                temp_r0_26 = this->unk12C;
                if (temp_r0_26 != NULL) {
                    temp_r5_29 = &this->unk128;
                    if (temp_r0_26 != temp_r5_29) {
                        M2C_FIELD(this->unk130, M2C_UNK **, 4) = temp_r0_26;
                        M2C_FIELD(this->unk12C, M2C_UNK **, 8) = (M2C_UNK *) this->unk130;
                        this->unk130 = temp_r5_29;
                        this->unk12C = temp_r5_29;
                    }
                }
            }
            if (&this->unkB0 != NULL) {
                temp_r0_42 = this->unkB8;
                if (temp_r0_42 != NULL) {
                    temp_r5_45 = &this->unkB0;
                    if (temp_r0_42 != temp_r5_45) {
                        M2C_FIELD(this->unkBC, M2C_UNK **, 8) = temp_r0_42;
                        M2C_FIELD(this->unkB8, M2C_UNK **, 0xC) = (M2C_UNK *) this->unkBC;
                        this->unkBC = temp_r5_45;
                        this->unkB8 = temp_r5_45;
                    }
                }
            }
            if (this != NULL) {
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'checked_cast'
inline void Gem::GetDescriptor() {
    checked_cast<GemDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
}
#endif

#endif  // SPYRO_SOURCE_GEM_H
