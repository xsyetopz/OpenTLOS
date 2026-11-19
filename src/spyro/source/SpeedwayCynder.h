#ifndef SPYRO_SOURCE_SPEEDWAYCYNDER_H
#define SPYRO_SOURCE_SPEEDWAYCYNDER_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/NodeLookAt.h"

class CynderBreathFX;
class KDProp;
class MKAnim;
class MKMessage;
class MKPropDescriptor;
class MKVector3;
class Matrix;
class NodeLookAtIK;
class SpeedWaySpyro;
class SpeedwayCynder;
class SpeedwayCynder_cpp;

class SpeedwayCynder : public KDProp {  // base: ctor/dtor vtable stores
public:
    class State;
    virtual ~SpeedwayCynder(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void UpdateSound(void);
    void UpdateCameraRoll(void);
    f32 GetCameraZOffset(void);
    void SetTargetZTime(float, float);
    void UpdateCameraZTime(void);
    s32 ShootFireBomb(const MKVector3 &, const MKVector3 &, const MKVector3 &);
    void UpdateFireBomb(void);
    void UpdateBreath(void);
    void SetAnim(MKAnim *, float, unsigned int);
    void SetAnim(int, float, unsigned int);
    void PostLTWUpdate(void);
    void UpdateLTW(const Matrix *, bool);
    void SetState(SpeedwayCynder::State);
    u8 AnyToFlinchTransition(void);
    s32 FlinchTransition(void);
    void EventCameraUpdate(void);
    void EventCameraExit(void);
    void EventCameraEnter(void);
    void FlinchUpdate(void);
    void FlinchExit(void);
    void FlinchEnter(void);
    u8 AnyToBiteTransition(void);
    void BiteTransition(void);
    void BiteUpdate(void);
    void BiteExit(void);
    void BiteEnter(void);
    s32 GlideTransition(void);
    void GlideUpdate(void);
    void GlideExit(void);
    void GlideEnter(void);
    void StateEnter(void);
    void UpdateLookAtNodes(void);
    static u8 states[0x90];
    /* 0x090 */ NodeLookAtIK unk90;
    /* 0x0d8 */ NodeLookAtIK unkD8;
    /* 0x120 */ NodeLookAtIK unk120;
    /* 0x168 */ NodeLookAtIK unk168;
    /* 0x1b0 */ NodeLookAtIK unk1B0;
    /* 0x1f8 */ f32 unk1F8;
    /* 0x1fc */ u8 pad1FC[0x8];
    /* 0x204 */ f32 unk204;
    /* 0x208 */ f32 unk208;
    /* 0x20c */ u8 pad20C[0x34];
    /* 0x240 */ s32 unk240;
    /* 0x244 */ f32 unk244;
    /* 0x248 */ f32 unk248;
    /* 0x24c */ KDStateMachine<SpeedwayCynder> unk24C;
    /* 0x24d */ u8 pad24D[0x13];
    /* 0x260 */ u32 unk260;
    /* 0x264 */ u32 unk264;
    /* 0x268 */ u8 pad268[0x18];
    /* 0x280 */ f64 unk280;
    /* 0x288 */ f64 unk288;
    /* 0x290 */ u8 unk290;
    /* 0x291 */ u8 pad291[0xf];
    /* 0x2a0 */ f64 unk2A0;
    /* 0x2a8 */ f64 unk2A8;
    /* 0x2b0 */ u8 unk2B0;
    /* 0x2b1 */ u8 pad2B1[0xf];
    /* 0x2c0 */ f64 unk2C0;
    /* 0x2c8 */ f64 unk2C8;
    /* 0x2d0 */ u8 unk2D0;
    /* 0x2d1 */ u8 pad2D1[0xf];
    /* 0x2e0 */ f32 unk2E0;
    /* 0x2e4 */ f32 unk2E4;
    /* 0x2e8 */ f32 unk2E8;
    /* 0x2ec */ f32 unk2EC;
    /* 0x2f0 */ f32 unk2F0;
    /* 0x2f4 */ f32 unk2F4;
    /* 0x2f8 */ f32 unk2F8;
    /* 0x2fc */ f32 unk2FC;
    /* 0x300 */ f32 unk300;
    /* 0x304 */ f32 unk304;
    /* 0x308 */ f32 unk308;
    /* 0x30c */ f32 unk30C;
    /* 0x310 */ f32 unk310;
    /* 0x314 */ f32 unk314;
    /* 0x318 */ f32 unk318;
    /* 0x31c */ f32 unk31C;
    /* 0x320 */ f64 unk320;
    /* 0x328 */ f64 unk328;
    /* 0x330 */ u8 unk330;
    /* 0x331 */ u8 pad331[0xf];
    /* 0x340 */ MKVector3 unk340;
    /* 0x350 */ f64 unk350;
    /* 0x358 */ f64 unk358;
    /* 0x360 */ s32 unk360;
    /* 0x364 */ f32 unk364;
    /* 0x368 */ f32 unk368;
    /* 0x36c */ f32 unk36C;
    /* 0x370 */ s32 unk370;
    /* 0x374 */ f32 unk374;
    /* 0x378 */ s32 unk378;
    /* 0x37c */ SpeedWaySpyro* unk37C;
    /* 0x380 */ MKPropDescriptor* unk380;
    /* 0x384 */ CynderBreathFX* unk384;
    /* 0x388 */ s32 unk388;
    /* 0x38c */ f32 unk38C;
    /* 0x390 */ f32 unk390;
    /* 0x394 */ f32 unk394;
    /* 0x398 */ f32 unk398;
    /* 0x39c */ f32 unk39C;
    /* 0x3a0 */ f32 unk3A0;
    /* 0x3a4 */ f32 unk3A4;
    /* 0x3a8 */ s32 unk3A8;
    /* 0x3ac */ u8 pad3AC[0x24];
    /* 0x3d0 */ s32 unk3D0;
    /* 0x3d4 */ u8 pad3D4[0x24];
    /* 0x3f8 */ u8 unk3F8;
};

class SpeedwayCynder_cpp {
public:
    void __sinit(void);
};

extern f32 enterX;
extern f32 enterY;
extern s32 bHitSpyro;
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline SpeedwayCynder::~SpeedwayCynder() {
    s32 temp_cr0_eq_35;

    if (this != NULL) {
        if ((&this->unk3D0 != NULL) && (&this->unk3D0 != NULL)) {
            KDSound_Stop(&this->unk3D0);
        }
        if ((&this->unk3A8 != NULL) && (&this->unk3A8 != NULL)) {
            KDSound_Stop(&this->unk3A8);
        }
        temp_cr0_eq_35 = this == NULL;
        if (temp_cr0_eq_35 == 0) {
            if (temp_cr0_eq_35 == 0) {
            }
        }
    }
}
#endif

#endif  // SPYRO_SOURCE_SPEEDWAYCYNDER_H
