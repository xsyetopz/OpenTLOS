#ifndef SPYRO_SOURCE_TESLATOWER_H
#define SPYRO_SOURCE_TESLATOWER_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/KDProp.h"

class KDProp;
class KDPropDescriptor;
class MKDynamicBone;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKVector3;
class Matrix;
class TeslaTower;
class TeslaTowerDescriptor;

class TeslaTower : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TeslaTower(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void UpdateTurretTurning(void);
    void ZapTarget(const MKVector3 &, const MKVector3 &);
    u8 FindZapTargets(bool);
    void DrawLightCone(void);
    void UpdateTurretBone(MKDynamicBone *, void *);
    /* 0x090 */ Matrix unk90;
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ MKVector3 unkE0;
    /* 0x0f0 */ f64 unkF0;
    /* 0x0f8 */ f64 unkF8;
    /* 0x100 */ f64 unk100;
    /* 0x108 */ f64 unk108;
    /* 0x110 */ EnergyBeam::Beam* unk110;
    /* 0x114 */ s32 unk114;
    /* 0x118 */ u8 pad118[0x24];
    /* 0x13c */ s32 unk13C;
    /* 0x140 */ u8 pad140[0x24];
    /* 0x164 */ s32 unk164;
    /* 0x168 */ u8 pad168[0x24];
    /* 0x18c */ s32 unk18C;
    /* 0x190 */ u8 pad190[0x28];
    /* 0x1b8 */ f64 unk1B8;
    /* 0x1c0 */ f64 unk1C0;
    /* 0x1c8 */ f32 unk1C8;
};

class TeslaTowerDescriptor : public KDPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    /* 0x070 */ s32 unk70;
    /* 0x074 */ MKMaterial* unk74;
    /* 0x078 */ s32 unk78;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline TeslaTower::~TeslaTower() {
    s32 temp_cr0_eq_49;

    if (this != NULL) {
        if ((&this->unk18C != NULL) && (&this->unk18C != NULL)) {
            KDSound_Stop((int *) &this->unk18C);
        }
        if ((&this->unk164 != NULL) && (&this->unk164 != NULL)) {
            KDSound_Stop((int *) &this->unk164);
        }
        if ((&this->unk13C != NULL) && (&this->unk13C != NULL)) {
            KDSound_Stop((int *) &this->unk13C);
        }
        if ((&this->unk114 != NULL) && (&this->unk114 != NULL)) {
            KDSound_Stop((int *) &this->unk114);
        }
        temp_cr0_eq_49 = this == NULL;
        if (temp_cr0_eq_49 == 0) {
            if (temp_cr0_eq_49 == 0) {
            }
        }
    }
}
#endif

#endif  // SPYRO_SOURCE_TESLATOWER_H
