#ifndef SPYRO_SOURCE_EXPLOSIVEBARRELPATH_H
#define SPYRO_SOURCE_EXPLOSIVEBARRELPATH_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"

class ExplosiveBarrelPath;
class ExplosiveBarrelPathDescriptor;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class Matrix;

class ExplosiveBarrelPath : public MKProp {  // base: ctor/dtor vtable stores
public:
    class BarrelData {
    public:
        ~BarrelData(void);
        BarrelData(void);
    };
    virtual ~ExplosiveBarrelPath(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    void EmitDust(const MKVector3 &, const MKVector3 &, float);
    void GetBarrelMiddle(ExplosiveBarrelPath::BarrelData *);
    void UpdateBarrelModel(ExplosiveBarrelPath::BarrelData *);
    s32 GetNextInactiveBarrelID(void);
    void PushBarrel(int);
    void ExplodeBarrel(int);
    s32 SpawnBarrel(MKProp *);
    void CalcStandPosAndDir(void);
    void GetStandDir(void);
    void GetStandPos(void);
    /* 0x04c */ MKProp* unk4C;
    /* 0x050 */ Matrix unk50;
    /* 0x090 */ u8 pad90[0x100];
    /* 0x190 */ f64 unk190;
    /* 0x198 */ f64 unk198;
    /* 0x1a0 */ f64 unk1A0;
    /* 0x1a8 */ f64 unk1A8;
    /* 0x1b0 */ u8 unk1B0;
    /* 0x1b1 */ s8 unk1B1;
    /* 0x1b2 */ u8 pad1B2[0x2e];
    /* 0x1e0 */ f64 unk1E0;
    /* 0x1e8 */ f64 unk1E8;
    /* 0x1f0 */ f64 unk1F0;
    /* 0x1f8 */ f64 unk1F8;
    /* 0x200 */ f64 unk200;
    /* 0x208 */ f64 unk208;
    /* 0x210 */ f64 unk210;
    /* 0x218 */ f64 unk218;
    /* 0x220 */ f32 unk220;
    /* 0x224 */ f32 unk224;
    /* 0x228 */ s32 unk228;
    /* 0x22c */ f32 unk22C;
    /* 0x230 */ u8 unk230;
    /* 0x231 */ u8 unk231;
    /* 0x232 */ u8 unk232;
    /* 0x233 */ u8 pad233[0x1];
    /* 0x234 */ f32 unk234;
    /* 0x238 */ f32 unk238;
    /* 0x23c */ f32 unk23C;
};

class ExplosiveBarrelPathDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ u8 pad64[0x14];
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f64 unk80;
    /* 0x088 */ f64 unk88;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: '(' expected
inline ExplosiveBarrelPath::~ExplosiveBarrelPath() {
    __destroy_arr(&this->unk50.unk28, &ExplosiveBarrelPath::BarrelData::~BarrelData, 0x44, 4);
    if (this != NULL) {
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1C'
inline ExplosiveBarrelPath::BarrelData::~BarrelData() {
    if ((&this->unk1C != NULL) && (&this->unk1C != NULL)) {
        KDSound_Stop(&this->unk1C);
    }
    if (arg1 > 0) {
        operator delete(this);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1C'
inline ExplosiveBarrelPath::BarrelData::BarrelData() {
    this->unk1C = 0;
    return this;
}
#endif

#endif  // SPYRO_SOURCE_EXPLOSIVEBARRELPATH_H
