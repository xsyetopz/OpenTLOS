#ifndef SPYRO_SOURCE_SIEGETOWER_H
#define SPYRO_SOURCE_SIEGETOWER_H

#include <dolphin/types.h>
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
class MKVector3;
class Shatterable;
class ShatterableDescriptor;
class SiegeTower;
class SiegeTowerDescriptor;
class Targetable;

class SiegeTower : public Shatterable {  // base: base ctor call
public:
    virtual ~SiegeTower(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
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
    /* 0x1a8 */ f64 unk1A8;
    /* 0x1b0 */ f64 unk1B0;
    /* 0x1b8 */ f32 unk1B8;
    /* 0x1bc */ u8 pad1BC[0x4];
    /* 0x1c0 */ EnemyGenerator unk1C0;
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

class SiegeTowerDescriptor : public ShatterableDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SiegeTowerDescriptor(void);
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

#if 0 // DRAFT: undefined identifier 'unkC8'
inline SiegeTower::SiegeTower() {
    EnemyGenerator *temp_r30_21900;

    temp_r30_21900 = &this->unk1C0;
    this->unkC8 = &__vt + 0x48;
    this->unk1C0.__vptr = &__vt;
    this->unk1C0.unk3C.unk0 = 0;
    temp_r30_21900->unk3C.Init();
    this->unk1C0.unk40.unk0 = 0;
    temp_r30_21900->unk40.Init();
    this->unk1C0.__vptr = &__vt;
    this->unk1C0.unk68.unk0 = 0;
    temp_r30_21900->unk68.Init();
    this->unk1C0.unk6C.unk0 = 0;
    temp_r30_21900->unk6C.Init();
    this->unk2A0 = 0;
    this->unk2C8 = 0;
    this->unk2F0 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline SiegeTower::~SiegeTower() {
    EventMessage *temp_r3_47;
    EventMessage *temp_r3_53;
    EventMessage *temp_r3_60;
    EventMessage *temp_r3_66;

    if (this != NULL) {
        this->unkC8 = &__vt.unk48;
        if ((&this->unk2F0 != NULL) && (&this->unk2F0 != NULL)) {
            KDSound_Stop((int *) &this->unk2F0);
        }
        if ((&this->unk2C8 != NULL) && (&this->unk2C8 != NULL)) {
            KDSound_Stop((int *) &this->unk2C8);
        }
        if ((&this->unk2A0 != NULL) && (&this->unk2A0 != NULL)) {
            KDSound_Stop((int *) &this->unk2A0);
        }
        if (&this->unk1C0 != NULL) {
            temp_r3_47 = &this->unk1C0.unk6C;
            this->unk1C0.__vptr = &__vt;
            if (temp_r3_47 != NULL) {
                temp_r3_47->Deinit();
            }
            temp_r3_53 = &this->unk1C0.unk68;
            if (temp_r3_53 != NULL) {
                temp_r3_53->Deinit();
            }
            if (&this->unk1C0 != NULL) {
                temp_r3_60 = &this->unk1C0.unk40;
                this->unk1C0.__vptr = &__vt;
                if (temp_r3_60 != NULL) {
                    temp_r3_60->Deinit();
                }
                temp_r3_66 = &this->unk1C0.unk3C;
                if (temp_r3_66 != NULL) {
                    temp_r3_66->Deinit();
                }
            }
        }
    }
}
#endif

inline SiegeTowerDescriptor::SiegeTowerDescriptor() {
}

#endif  // SPYRO_SOURCE_SIEGETOWER_H
