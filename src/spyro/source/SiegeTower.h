#ifndef SPYRO_SOURCE_SIEGETOWER_H
#define SPYRO_SOURCE_SIEGETOWER_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/Shatterable.h"

class Ball;
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
};

class SiegeTowerDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SiegeTowerDescriptor(void);
    /* 0x048 */ u8 pad48[0x1c];
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

#if 0 // DRAFT: undefined identifier 'unk1B0'
inline SiegeTower::SiegeTower() {
    f64 *temp_r30_21900;

    temp_r30_21900 = &this->unk1B0;
    this->unkC8 = &__vt + 0x48;
    M2C_FIELD(this, M2C_UNK **, 0x1C0) = &__vt;
    this->unk1C0.unk2C = 0;
    ((EventMessage *) (temp_r30_21900 + 0x3C))->Init();
    this->unk1C0.unk30 = 0.0f;
    ((EventMessage *) ((EventMessage *) (temp_r30_21900 + 0x40)))->Init();
    M2C_FIELD(this, M2C_UNK **, 0x1C0) = &__vt;
    this->unk1C0.unk58 = NULL;
    ((EventMessage *) ((EventMessage *) (temp_r30_21900 + 0x68)))->Init();
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
                temp_r3_47->Deinit();
            }
            temp_r3_53 = &this->unk1C0.unk58;
            if (temp_r3_53 != NULL) {
                temp_r3_53->Deinit();
            }
            if (&this->unk1B0 != NULL) {
                temp_r3_60 = &this->unk1C0.unk30;
                M2C_FIELD(this, M2C_UNK **, 0x1C0) = &__vt;
                if (temp_r3_60 != NULL) {
                    temp_r3_60->Deinit();
                }
                temp_r3_66 = &this->unk1C0.unk2C;
                if (temp_r3_66 != NULL) {
                    temp_r3_66->Deinit();
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
