#ifndef SPYRO_SOURCE_SIEGETOWER_H
#define SPYRO_SOURCE_SIEGETOWER_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/Shatterable.h"

class Ball;
class EnemyGenerator;
class EnemyGeneratorDescriptor;
class MKDynamicBone;
class MKIniLine;
class MKMessage;
class MKPropDescriptor;
class MKVector3;
class Shatterable;
class SiegeTower;
class SiegeTowerDescriptor;
class Targetable;

class SiegeTower : public Shatterable {  // base: vtable prefix
public:
    virtual ~SiegeTower(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    SiegeTower(void);
    void ZapBall(Ball *);
    void Shoot(Targetable *);
    void UpdateShooting(Targetable *);
    void CalcSpikeBeamPositions(void);
    void FreeElecBeams(void);
    void AllocElecBeams(void);
    void UpdateTurning(MKVector3);
    void UpdateTurretBone(MKDynamicBone *, void *);
    /* 0x1a3 */ u8 pad1A3[0x5];
    /* 0x1a8 */ f64 unk1A8;
    /* 0x1b0 */ f64 unk1B0;
    /* 0x1b8 */ f32 unk1B8;
    /* 0x1bc */ u8 pad1BC[0x4];
    /* 0x1c0 */ EnemyGenerator unk1C0;
    /* 0x246 */ u8 pad246[0x2];
    /* 0x248 */ void* unk248;
    /* 0x24c */ EnergyBeam::Beam* unk24C;
    /* 0x250 */ MKVector3 unk250;
    /* 0x260 */ MKVector3 unk260;
    /* 0x270 */ MKVector3 unk270;
    /* 0x280 */ MKVector3 unk280;
    /* 0x290 */ f32 unk290;
    /* 0x294 */ f32 unk294;
    /* 0x298 */ u32 unk298;
    /* 0x29c */ s32 unk29C;
    /* 0x2a0 */ s32 unk2A0;
    /* 0x2a4 */ u8 pad2A4[0x24];
    /* 0x2c8 */ s32 unk2C8;
    /* 0x2cc */ u8 pad2CC[0x24];
    /* 0x2f0 */ s32 unk2F0;
    /* 0x2f4 */ u8 pad2F4[0x24];
    /* 0x318 */ f32 unk318;
    /* 0x31c */ f32 unk31C;
    /* 0x320 */ f32 unk320;
    /* 0x324 */ u32 unk324;
    /* 0x328 */ s32 unk328;
    /* 0x32c */ u8 unk32C;
    /* 0x32d */ u8 unk32D;
};

class SiegeTowerDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SiegeTowerDescriptor(void);
    /* 0x044 */ u8 pad44[0x20];
    /* 0x064 */ s32 unk64;
    /* 0x068 */ u8 pad68[0x104];
    /* 0x16c */ s32 unk16C;
    /* 0x170 */ s32 unk170;
    /* 0x174 */ s32 unk174;
    /* 0x178 */ s32 unk178;
    /* 0x17c */ s32 unk17C;
    /* 0x180 */ s32 unk180;
    /* 0x184 */ EnemyGeneratorDescriptor unk184;
};

s32 SiegeTower_GetSiegeTower(int, int);
s32 SiegeTower_GetMaxPerGroup(void);
void SiegeTower_InitModule(void);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unkC8'
inline SiegeTower::SiegeTower() {
    f64 *temp_r30_21900;

    temp_r30_21900 = &this->unk1B0;
    this->unkC8 = &__vt + 0x48;
    M2C_FIELD(this, M2C_UNK **, 0x1C0) = &__vt;
    this->unk1C0.unk2C = 0;
    ((EventMessage *) (temp_r30_21900 + 0x3C))->Init();
    this->unk1C0.unk30 = 0.0f;
    ((EventMessage *) (temp_r30_21900 + 0x40))->Init();
    M2C_FIELD(this, M2C_UNK **, 0x1C0) = &__vt;
    this->unk1C0.unk58 = NULL;
    ((EventMessage *) (temp_r30_21900 + 0x68))->Init();
    this->unk1C0.unk5C = NULL;
    ((EventMessage *) (temp_r30_21900 + 0x6C))->Init();
    this->unk280.unkC = 0.0f;
    this->unk2C8 = 0;
    this->unk2F0 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline SiegeTower::~SiegeTower() {
    f32 *temp_r3_60;
    s32 *temp_r3_66;
    void **temp_r3_47;
    void **temp_r3_53;

    if (this != NULL) {
        this->unkC8 = &__vt.unk48;
        if ((&this->unk2F0 != NULL) && (&this->unk2F0 != NULL)) {
            KDSound_Stop(&this->unk2F0);
        }
        if ((&this->unk2C8 != NULL) && (&this->unk2C8 != NULL)) {
            KDSound_Stop(&this->unk2C8);
        }
        if ((&this->unk280.unkC != NULL) && (&this->unk280.unkC != NULL)) {
            KDSound_Stop((s32 *) &this->unk280.unkC);
        }
        if (&this->unk1B0 != NULL) {
            temp_r3_47 = &this->unk1C0.unk5C;
            M2C_FIELD(this, M2C_UNK **, 0x1C0) = &__vt;
            if (temp_r3_47 != NULL) {
                ((EventMessage *) temp_r3_47)->Deinit();
            }
            temp_r3_53 = &this->unk1C0.unk58;
            if (temp_r3_53 != NULL) {
                ((EventMessage *) temp_r3_53)->Deinit();
            }
            if (&this->unk1B0 != NULL) {
                temp_r3_60 = &this->unk1C0.unk30;
                M2C_FIELD(this, M2C_UNK **, 0x1C0) = &__vt;
                if (temp_r3_60 != NULL) {
                    ((EventMessage *) temp_r3_60)->Deinit();
                }
                temp_r3_66 = &this->unk1C0.unk2C;
                if (temp_r3_66 != NULL) {
                    ((EventMessage *) temp_r3_66)->Deinit();
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SiegeTowerDescriptor::SiegeTowerDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SIEGETOWER_H
