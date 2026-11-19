#ifndef SPYRO_SOURCE_CONVEXITYBREATHFX_H
#define SPYRO_SOURCE_CONVEXITYBREATHFX_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/BaseBreathFX.h"

class BaseBreathFX;
class ConvexityBreathFX;
class MKMaterial;
class MKMessage;
class MKModel;
class MKProp;
class MKVector3;
class Matrix;

class ConvexityBreathFX : public BaseBreathFX {  // base: ctor/dtor vtable stores
public:
    virtual ~ConvexityBreathFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    ConvexityBreathFX(void);
    void DrawRings(void);
    void UpdateRings(void);
    void SpawnRing(const MKVector3 &, const MKVector3 &);
    s32 Trigger(MKProp *, const MKVector3 &, const MKVector3 &, const float &);
    /* 0x0a8 */ MKModel* unkA8;
    /* 0x0ac */ s32 unkAC;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ u8 padB4[0x4];
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ f32 unkBC;
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ u8 padC4[0x8];
    /* 0x0cc */ u8 unkCC;
    /* 0x0cd */ u8 padCD[0x3];
    /* 0x0d0 */ Matrix unkD0;
    /* 0x110 */ MKModel* unk110;
    /* 0x114 */ MKMaterial* unk114;
    /* 0x118 */ Matrix** unk118;
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ f32 unk120;
    /* 0x124 */ s32 unk124;
    /* 0x128 */ u8 pad128[0x28];
    /* 0x150 */ f64 unk150;
    /* 0x158 */ f64 unk158;
    /* 0x160 */ MKModel* unk160;
    /* 0x164 */ u8 pad164[0x8];
    /* 0x16c */ u8 unk16C;
    /* 0x16d */ u8 pad16D[0x3];
    /* 0x170 */ Matrix unk170;
    /* 0x1b0 */ f32 unk1B0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline ConvexityBreathFX::~ConvexityBreathFX() {
    s32 temp_cr0_eq_28;

    if (this != NULL) {
        if ((&this->unk124 != NULL) && (&this->unk124 != NULL)) {
            KDSound_Stop((int *) &this->unk124);
        }
        temp_cr0_eq_28 = this == NULL;
        if (temp_cr0_eq_28 == 0) {
            if (temp_cr0_eq_28 == 0) {
                if (temp_cr0_eq_28 == 0) {
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ConvexityBreathFX::ConvexityBreathFX() {
    this->unk124 = 0;
    return this;
}
#endif

#endif  // SPYRO_SOURCE_CONVEXITYBREATHFX_H
