#ifndef SPYRO_SOURCE_CATAPULT_H
#define SPYRO_SOURCE_CATAPULT_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Shadow.h"

class Ball;
class Catapult;
class CatapultDescriptor;
class Catapult_cpp;
class EventMessage;
class KDProp;
class KDPropDescriptor;
class KDUniformSpline;
class MKIniLine;
class MKMessage;
class Shadow;

class Catapult : public KDProp {  // base: ctor/dtor vtable stores
public:
    class State;
    virtual ~Catapult(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    void SetState(Catapult::State);
    s32 CanLoadBall(void);
    void SetBall(Ball *);
    void GetAmmoDir(void);
    void GetAmmoPos(void);
    void WindBackUpdate(void);
    void WindBackEnter(void);
    void FireUpdate(void);
    void FireEnter(void);
    void LoadAmmoUpdate(void);
    void IdleEnter(void);
    void Unload(void);
    static u8 states[0xb4];
    static u8 pEvents[0x8];
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ f64 unk90;
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ u8 padAC[0x4];
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ u8 padBC[0xc];
    /* 0x0c8 */ Shadow unkC8;
    /* 0x0f5 */ u8 padF5[0x17];
    /* 0x10c */ EventMessage unk10C;
    /* 0x110 */ EventMessage unk110;
    /* 0x114 */ EventMessage unk114;
    /* 0x118 */ KDUniformSpline unk118;
    /* 0x12c */ u32 unk12C;
    /* 0x130 */ s32 unk130;
    /* 0x134 */ s32 unk134;
    /* 0x138 */ f32 unk138;
    /* 0x13c */ f32 unk13C;
    /* 0x140 */ f32 unk140;
    /* 0x144 */ f32 unk144;
    /* 0x148 */ s32 unk148;
    /* 0x14c */ u8 unk14C;
    /* 0x14d */ u8 unk14D;
};

class CatapultDescriptor : public KDPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ s32 unk88;
};

class Catapult_cpp {
public:
    void __sinit(void);
};

s32 Catapult_GetCatapult(int, int);
s32 Catapult_GetMaxPerGroup(void);
void Catapult_InitModule(void);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline Catapult::~Catapult() {
    s32 temp_cr0_eq_43;

    if (this != NULL) {
        if (&this->unk110 != NULL) {
            this->unk110.Deinit();
        }
        if (&this->unk10C != NULL) {
            this->unk10C.Deinit();
        }
        if (&this->unk10C != NULL) {
            this->unk10C.Deinit();
        }
        if ((&this->unkA0 != NULL) && (&this->unkA0 != NULL)) {
            KDSound_Stop(&this->unkA0);
        }
        temp_cr0_eq_43 = this == NULL;
        if (temp_cr0_eq_43 == 0) {
            if (temp_cr0_eq_43 == 0) {
            }
        }
    }
}
#endif

#endif  // SPYRO_SOURCE_CATAPULT_H
