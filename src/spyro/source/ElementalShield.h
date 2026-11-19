#ifndef SPYRO_SOURCE_ELEMENTALSHIELD_H
#define SPYRO_SOURCE_ELEMENTALSHIELD_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class ElementalShield;
class KDProp;
class MKMaterial;
class MKMessage;
class MKVector3;

class ElementalShield : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ElementalShield(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Disable(void);
    void SetElement(int);
    void Trigger(MKVector3 *, float, bool);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ s32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ f32 unk9C;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ s32 unkA4;
    /* 0x0a8 */ u8 unkA8;
    /* 0x0a9 */ u8 padA9[0x3];
    /* 0x0ac */ MKVector3* unkAC;
    /* 0x0b0 */ MKMaterial* unkB0;
    /* 0x0b4 */ s32 unkB4;
    /* 0x0b8 */ s32 unkB8;
    /* 0x0bc */ s32 unkBC;
    /* 0x0c0 */ s32 unkC0;
    /* 0x0c4 */ s32 unkC4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline ElementalShield::~ElementalShield() {
    s32 temp_cr0_eq_28;

    if (this != NULL) {
        if ((&this->unkC4 != NULL) && (&this->unkC4 != NULL)) {
            KDSound_Stop(&this->unkC4);
        }
        temp_cr0_eq_28 = this == NULL;
        if (temp_cr0_eq_28 == 0) {
            if (temp_cr0_eq_28 == 0) {
            }
        }
    }
}
#endif

#endif  // SPYRO_SOURCE_ELEMENTALSHIELD_H
