#ifndef SPYRO_SOURCE_DRAGONBUST_H
#define SPYRO_SOURCE_DRAGONBUST_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"

class DragonBust;
class DragonBust_cpp;
class GameProp;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKModel;
class MKSceneManager;
class ManagedLight;

class DragonBust : public GameProp {  // base: base ctor call
public:
    class State;
    virtual ~DragonBust(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    DragonBust(void);
    void ActivatingBUpdate(void);
    void ActivatingBEnter(void);
    void ActivatingAUpdate(void);
    void ActivatingAEnter(void);
    void SlidingIntoPlaceUpdate(void);
    void SlidingIntoPlaceEnter(void);
    void SlideUpdate(void);
    void IdleUpdate(void);
    void IdleEnter(void);
    void SetState(DragonBust::State);
    static u8 states[0xd8];
    /* 0x0c8 */ s32 unkC8;
    /* 0x0cc */ u8 padCC[0x10];
    /* 0x0dc */ s32 unkDC;
    /* 0x0e0 */ MKSceneManager* unkE0;
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ f64 unkE8;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ u8 padF4[0x4];
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ f32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ ManagedLight* unk118;
    /* 0x11c */ MKModel* unk11C;
    /* 0x120 */ MKMaterial* unk120;
    /* 0x124 */ MKMaterial* unk124;
    /* 0x128 */ void* unk128;
    /* 0x12c */ u8 unk12C;
    /* 0x12d */ u8 pad12D[0x3];
    /* 0x130 */ s32 unk130;
    /* 0x134 */ u8 pad134[0x24];
    /* 0x158 */ u8 unk158;
};

class DragonBust_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkCC'
inline DragonBust::DragonBust() {
    this->unkC8 = -1;
    this->unkCC = -1;
    this->unkD0 = 0;
    this->unkD4 = 0;
    this->unk130 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline DragonBust::~DragonBust() {
    if ((&this->unk130 != NULL) && (&this->unk130 != NULL)) {
        KDSound_Stop((int *) &this->unk130);
    }
}
#endif

#endif  // SPYRO_SOURCE_DRAGONBUST_H
