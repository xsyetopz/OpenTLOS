#ifndef SPYRO_SOURCE_STALACTITECHARGE_H
#define SPYRO_SOURCE_STALACTITECHARGE_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/KDStateMachine.h"

class IceBossStalactiteSpawner;
class KDSplinePathSegment;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKSceneManager;
class StalactiteCharge;
class StalactiteChargeDescriptor;
class StalactiteCharge_cpp;

class StalactiteCharge : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~StalactiteCharge(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    void StateSCResetExit(void);
    void StateSCResetUpdate(void);
    void StateSCResetEnter(void);
    void StateSCLerpCameraExit(void);
    void StateSCLerpCameraUpdate(void);
    void StateSCLerpCameraEnter(void);
    void StateSCDropExit(void);
    void StateSCDropUpdate(void);
    void StateSCDropEnter(void);
    void StateSCWaitExit(void);
    void StateSCWaitUpdate(void);
    void StateSCWaitEnter(void);
    StalactiteCharge(void);
    /* 0x04c */ IceBossStalactiteSpawner* unk4C;
    /* 0x050 */ KDStateMachine<StalactiteCharge> unk50;
    /* 0x051 */ u8 pad51[0x3];
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05c */ s32 unk5C;
    /* 0x060 */ u8 pad60[0xc];
    /* 0x06c */ u8 unk6C;
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ u8 unk70;
    /* 0x071 */ u8 pad71[0x2f];
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ u8 unkB0;
    /* 0x0b1 */ u8 padB1[0x3];
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ u8 padBC[0x4];
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ f32 unkC4;
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ u8 padCC[0x4];
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ u8 unkE8;
    /* 0x0e9 */ u8 padE9[0x3];
    /* 0x0ec */ KDSplinePathSegment* unkEC;
    /* 0x0f0 */ MKSceneManager* unkF0;
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ u8 padFC[0x4];
    /* 0x100 */ f64 unk100;
    /* 0x108 */ f64 unk108;
    /* 0x110 */ f64 unk110;
    /* 0x118 */ f64 unk118;
    /* 0x120 */ f64 unk120;
    /* 0x128 */ f32 unk128;
    /* 0x12c */ u8 pad12C[0x4];
    /* 0x130 */ f64 unk130;
    /* 0x138 */ f32 unk138;
    /* 0x13c */ u8 pad13C[0x4];
    /* 0x140 */ u8 unk140;
    /* 0x141 */ u8 pad141[0x3];
    /* 0x144 */ s32 unk144;
    /* 0x148 */ u8 pad148[0x28];
    /* 0x170 */ f64 unk170;
    /* 0x178 */ f64 unk178;
};

class StalactiteChargeDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ s32 unk60;
};

class StalactiteCharge_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline StalactiteCharge::~StalactiteCharge() {
    if ((&this->unk144 != NULL) && (&this->unk144 != NULL)) {
        KDSound_Stop(&this->unk144);
    }
    if (this != NULL) {
    }
}
#endif

#endif  // SPYRO_SOURCE_STALACTITECHARGE_H
