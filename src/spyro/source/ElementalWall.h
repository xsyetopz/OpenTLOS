#ifndef SPYRO_SOURCE_ELEMENTALWALL_H
#define SPYRO_SOURCE_ELEMENTALWALL_H

#include <dolphin/types.h>
#include "spyro/source/SplineProp.h"

class ElementalWall;
class ElementalWallDescriptor;
class ElementalWall_cpp;
class MKIniLine;
class MKMaterial;
class MKMessage;
class SplineProp;
class SplinePropDescriptor;

class ElementalWall : public SplineProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ElementalWall(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void CalcBounds(void);
    ElementalWall(void);
    void StateEWOffExit(void);
    void StateEWOffUpdate(void);
    void StateEWOffEnter(void);
    void StateEWTurningOffExit(void);
    void StateEWTurningOffUpdate(void);
    void StateEWTurningOffEnter(void);
    void StateEWOnExit(void);
    void StateEWOnUpdate(void);
    void StateEWOnEnter(void);
    void StateEWTurningOnExit(void);
    void StateEWTurningOnUpdate(void);
    void StateEWTurningOnEnter(void);
    void EmitEarthParticles(float, float);
    void EmitIceParticles(float, float);
    void EmitElectricityParticles(float, float);
    void EmitFireParticles(float, float);
    void EmitParticles(float, float);
    void DrawEarthWall(float, float);
    void DrawIceWall(float, float);
    void DrawElectricityWall(float, float);
    void DrawFireWall(float, float);
    /* 0x0b8 */ u8 padB8[0x8];
    /* 0x0c0 */ f64 unkC0;
    /* 0x0c8 */ f64 unkC8;
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ u8 padE4[0x10];
    /* 0x0f4 */ MKMaterial* unkF4;
    /* 0x0f8 */ MKMaterial* unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ s32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ f32 unk118;
    /* 0x11c */ u8 unk11C;
    /* 0x11d */ u8 pad11D[0x3];
    /* 0x120 */ f32 unk120;
    /* 0x124 */ f32 unk124;
    /* 0x128 */ u8 unk128;
    /* 0x129 */ u8 pad129[0x7];
    /* 0x130 */ s32 unk130;
};

class ElementalWallDescriptor : public SplinePropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void LoadDone(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ s32 unk60;
};

class ElementalWall_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkE4'
inline ElementalWall::ElementalWall() {
    this->unkE0 = -1;
    this->unkE4 = -1;
    this->unkE8 = 0;
    this->unkEC = 0;
    this->unk130 = 0;
    return this;
}
#endif

inline ElementalWall::~ElementalWall() {
    s32 temp_cr0_eq_24;

    if (this != NULL) {
        temp_cr0_eq_24 = this == NULL;
        if (temp_cr0_eq_24 == 0) {
            if (temp_cr0_eq_24 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_ELEMENTALWALL_H
