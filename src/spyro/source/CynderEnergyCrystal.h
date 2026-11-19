#ifndef SPYRO_SOURCE_CYNDERENERGYCRYSTAL_H
#define SPYRO_SOURCE_CYNDERENERGYCRYSTAL_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"

class ColObjDescriptor;
class CynderEnergyCrystal;
class CynderEnergyCrystalDescriptor;
class GameProp;
class KDPropExDescriptor;
class MKDynamicBone;
class MKIniLine;
class MKMessage;
class ManagedLight;
class Matrix;

class CynderEnergyCrystal : public GameProp {  // base: vtable prefix
public:
    virtual ~CynderEnergyCrystal(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    CynderEnergyCrystal(void);
    void UpdateModel(void);
    void UpdateMovement(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ Matrix* unkC8;
    /* 0x0cc */ u8 unkCC;
    /* 0x0cd */ u8 padCD[0x3];
    /* 0x0d0 */ Matrix unkD0;
    /* 0x110 */ Matrix unk110;
    /* 0x150 */ s32 unk150;
    /* 0x154 */ u8 pad154[0x4];
    /* 0x158 */ u8 unk158;
    /* 0x159 */ u8 pad159[0x3];
    /* 0x15c */ f32 unk15C;
    /* 0x160 */ f32 unk160;
    /* 0x164 */ u8 pad164[0x4];
    /* 0x168 */ void* unk168;
    /* 0x16c */ u8 pad16C[0x168];
    /* 0x2d4 */ s32 unk2D4;
    /* 0x2d8 */ u8 pad2D8[0x308];
    /* 0x5e0 */ MKDynamicBone* unk5E0;
    /* 0x5e4 */ ManagedLight* unk5E4;
    /* 0x5e8 */ u8 unk5E8;
};

class CynderEnergyCrystalDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    CynderEnergyCrystalDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ ColObjDescriptor unkE4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier '__vt'
inline CynderEnergyCrystal::CynderEnergyCrystal() {
    this->unk168 = &__vt;
    return this;
}
#endif

inline CynderEnergyCrystal::~CynderEnergyCrystal() {
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline CynderEnergyCrystalDescriptor::CynderEnergyCrystalDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_CYNDERENERGYCRYSTAL_H
