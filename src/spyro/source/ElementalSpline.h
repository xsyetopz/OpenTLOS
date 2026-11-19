#ifndef SPYRO_SOURCE_ELEMENTALSPLINE_H
#define SPYRO_SOURCE_ELEMENTALSPLINE_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/SplineProp.h"

class ElementalSpline;
class ElementalSplineDescriptor;
class ElementalSpline_cpp;
class EventMessage;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKProp;
class MKVector4;
class SplinePropDescriptor;

class ElementalSpline : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ElementalSpline(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    ElementalSpline(void);
    void StateESOffExit(void);
    void StateESOffUpdate(void);
    void StateESOffEnter(void);
    void StateESTurningOffExit(void);
    void StateESTurningOffUpdate(void);
    void StateESTurningOffEnter(void);
    void StateESOnExit(void);
    void StateESOnUpdate(void);
    void StateESOnEnter(void);
    void StateESTurningOnExit(void);
    void StateESTurningOnUpdate(void);
    void StateESTurningOnEnter(void);
    void EmitEarthParticles(float, float);
    void EmitIceParticles(float, float);
    void EmitElectricityParticles(float, float);
    void EmitFireParticles(float, float);
    void EmitParticles(float, float);
    void DrawEarthSpline(float, float);
    void DrawIceSpline(float, float);
    void DrawElectricitySpline(float, float);
    void DrawFireSpline(float, float);
    /* 0x04c */ u8 unk4C;
    /* 0x04d */ u8 pad4D[0x63];
    /* 0x0b0 */ void* unkB0;
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ u8 padB8[0x8];
    /* 0x0c0 */ s32 unkC0;
    /* 0x0c4 */ u8 padC4[0x10];
    /* 0x0d4 */ EventMessage unkD4;
    /* 0x0d8 */ EventMessage unkD8;
    /* 0x0dc */ u8 padDC[0x4];
    /* 0x0e0 */ MKVector4 unkE0;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ MKMaterial* unkF4;
    /* 0x0f8 */ MKMaterial* unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ f32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ s32 unk110;
    /* 0x114 */ s32 unk114;
    /* 0x118 */ u8 unk118;
    /* 0x119 */ u8 pad119[0x7];
    /* 0x120 */ s32 unk120;
};

class ElementalSplineDescriptor : public SplinePropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void LoadDone(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ s32 unk60;
};

class ElementalSpline_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC4'
inline ElementalSpline::ElementalSpline() {
    this->unkC0 = -1;
    this->unkC4 = -1;
    this->unkC8 = 0;
    this->unkCC = 0;
    this->unkD4.unk0 = 0;
    this->unkD4.Init();
    this->unkD8.unk0 = 0;
    this->unkD8.Init();
    this->unk120 = 0;
}
#endif

inline ElementalSpline::~ElementalSpline() {
    s32 temp_cr0_eq_34;

    if (this != NULL) {
        if (&this->unkD8 != NULL) {
            this->unkD8.Deinit();
        }
        if (&this->unkD4 != NULL) {
            this->unkD4.Deinit();
        }
        temp_cr0_eq_34 = this == NULL;
        if (temp_cr0_eq_34 == 0) {
            if (temp_cr0_eq_34 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_ELEMENTALSPLINE_H
