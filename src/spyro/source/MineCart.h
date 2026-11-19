#ifndef SPYRO_SOURCE_MINECART_H
#define SPYRO_SOURCE_MINECART_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"
#include "spyro/source/Shadow.h"

class GameProp;
class GamePropDescriptor;
class MKDynamicBone;
class MKIniLine;
class MKMessage;
class MineCart;
class MineCartDescriptor;
class Shadow;

class MineCart : public GameProp {  // base: base ctor call
public:
    virtual ~MineCart(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    MineCart(void);
    void UpdateWheelBone(MKDynamicBone *, void *);
    void UpdateEffects(void);
    /* 0x0c8 */ f64 unkC8;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ u8 padD4[0x4];
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ u8 padE4[0x4];
    /* 0x0e8 */ Shadow unkE8;
    /* 0x118 */ f32 unk118;
    /* 0x11c */ u8 pad11C[0x4c];
    /* 0x168 */ f64 unk168;
    /* 0x170 */ f64 unk170;
    /* 0x178 */ void* unk178;
    /* 0x17c */ s32 unk17C;
};

class MineCartDescriptor : public GamePropDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    MineCartDescriptor(void);
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ f32 unkEC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MineCart::MineCart() {
    this->unk17C = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline MineCart::~MineCart() {
    if ((&this->unk17C != NULL) && (&this->unk17C != NULL)) {
        KDSound_Stop(&this->unk17C);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MineCartDescriptor::MineCartDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_MINECART_H
