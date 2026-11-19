#ifndef SPYRO_SOURCE_FIGHTELEVATOR_H
#define SPYRO_SOURCE_FIGHTELEVATOR_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Platform.h"

class EventMessage;
class FightElevator;
class FightElevatorDescriptor;
class FightElevator_cpp;
class KDPropExDescriptor;
class MKIniLine;
class MKMessage;
class Platform;

class FightElevator : public Platform {  // base: vtable prefix
public:
    virtual ~FightElevator(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void UpdateMove(void);
    FightElevator(void);
    s32 GetClosestWaypointToPlayerIndex(void);
    void UpdateAnchors(void);
    void ClearAnchors(void);
    void FindAnchors(void);
    void SetBeamPositions(void);
    void FreeBeams(void);
    void AllocBeams(void);
    void SetDefaults(void);
    /* 0x180 */ s32 unk180;
    /* 0x184 */ s32 unk184;
    /* 0x188 */ f32 unk188;
    /* 0x18c */ s32 unk18C;
    /* 0x190 */ u8 pad190[0x4];
    /* 0x194 */ f32 unk194;
    /* 0x198 */ s32 unk198;
    /* 0x19c */ s32 unk19C;
    /* 0x1a0 */ s32 unk1A0;
    /* 0x1a4 */ u8 unk1A4;
    /* 0x1a5 */ u8 unk1A5;
    /* 0x1a6 */ u8 pad1A6[0x2];
    /* 0x1a8 */ f32 unk1A8;
    /* 0x1ac */ f32 unk1AC;
    /* 0x1b0 */ u8 unk1B0;
    /* 0x1b1 */ s8 unk1B1;
    /* 0x1b2 */ u8 pad1B2[0x2];
    /* 0x1b4 */ f32 unk1B4;
    /* 0x1b8 */ s32 unk1B8;
    /* 0x1bc */ s32 unk1BC;
    /* 0x1c0 */ u8 pad1C0[0x24];
    /* 0x1e4 */ s32 unk1E4;
    /* 0x1e8 */ u8 pad1E8[0xa0];
    /* 0x288 */ f64 unk288;
    /* 0x290 */ f64 unk290;
    /* 0x298 */ void* unk298;
    /* 0x29c */ u8 pad29C[0x18];
    /* 0x2b4 */ EventMessage unk2B4;
    /* 0x2b8 */ u8 unk2B8;
};

class FightElevatorDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    FightElevatorDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x64];
    /* 0x124 */ s32 unk124;
    /* 0x128 */ s32 unk128;
    /* 0x12c */ s32 unk12C;
    /* 0x130 */ s32 unk130;
};

class FightElevator_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline FightElevator::FightElevator() {
    this->unk180 = 0;
    this->unk184 = 0;
    this->unk188 = 0.0f;
    this->unk18C = 0;
    this->unk1BC = 0;
    this->unk1E4 = 0;
    this->unk2B4.unk0 = 0;
    this->unk2B4.Init();
}

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline FightElevator::~FightElevator() {
    if (&this->unk2B4 != NULL) {
        this->unk2B4.Deinit();
    }
    if ((&this->unk1E4 != NULL) && (&this->unk1E4 != NULL)) {
        KDSound_Stop((int *) &this->unk1E4);
    }
    if ((&this->unk1BC != NULL) && (&this->unk1BC != NULL)) {
        KDSound_Stop((int *) &this->unk1BC);
    }
}
#endif

inline FightElevatorDescriptor::FightElevatorDescriptor() {
}

#endif  // SPYRO_SOURCE_FIGHTELEVATOR_H
