#ifndef SPYRO_SOURCE_GOOPFX_H
#define SPYRO_SOURCE_GOOPFX_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"

class GoopFX;
class GoopFXDescriptor;
class KDProp;
class KDPropExDescriptor;
class MKIniLine;
class MKMaterial;
class MKVector3;
class MKVector4;
class Matrix;

class GoopFX : public KDProp {  // base: vtable prefix
public:
    virtual ~GoopFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Emit(const MKVector3 &, const MKVector3 &, float, const MKVector4 &);
    GoopFX(void);
};

class GoopFXDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    class Goop;
    class GoopNode;
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    GoopFXDescriptor(void);
    void DrawGoop(GoopFXDescriptor::Goop *);
    void Emit(const MKVector3 &, const MKVector3 &, float, const MKVector4 &);
    void UpdateGoopNodes(GoopFXDescriptor::GoopNode *, GoopFXDescriptor::GoopNode *, GoopFXDescriptor::Goop *);
    u8 TwoFrozenNodes(GoopFXDescriptor::Goop *);
    u8 UpdateGoop(GoopFXDescriptor::Goop *);
    void DrawGoopList(void);
    void UpdateGoopList(void);
    /* 0x0c0 */ u8 padC0[0x20];
    /* 0x0e0 */ MKMaterial* unkE0;
    /* 0x0e4 */ u8 unkE4;
    /* 0x0e5 */ u8 unkE5;
    /* 0x0e6 */ u8 padE6[0x2];
    /* 0x0e8 */ GoopFXDescriptor::Goop** unkE8;
    /* 0x0ec */ u8 unkEC;
    /* 0x0ed */ u8 padED[0x3];
    /* 0x0f0 */ Matrix unkF0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline GoopFX::GoopFX() {
    return this;
}
#endif

inline GoopFX::~GoopFX() {
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline GoopFXDescriptor::GoopFXDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_GOOPFX_H
