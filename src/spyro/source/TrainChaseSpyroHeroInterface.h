#ifndef SPYRO_SOURCE_TRAINCHASESPYROHEROINTERFACE_H
#define SPYRO_SOURCE_TRAINCHASESPYROHEROINTERFACE_H

#include <dolphin/types.h>
#include "spyro/source/HeroInterface.h"
#include "unplaced_enums.h"

class HeroInterface;
class MKMessage;
class MKPropDescriptor;
class MKVector3;
class TrainChaseSpyroHeroInterface;

class TrainChaseSpyroHeroInterface : public HeroInterface {  // base: inlined ctor vtable stores
public:
    virtual s32 GetHeroType(void);
    virtual void * GetProp(void);
    virtual MKPropDescriptor ** GetTargetable(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
    virtual f32 GetCollideRadius(void);
    virtual MKVector3 GetCollisionCentre(void);
    virtual s32 GetCollisionIgnoreMaterials(void);
    virtual MKPropDescriptor ** GetCollisionInfo(void);
    virtual s32 GetLighting(void);
    virtual s32 GetEffects(void);
    virtual void GetInput(void);
    virtual s32 IsInputActive(void);
    virtual void GetCamera(void);
    virtual s32 IsActive(void);
    virtual s32 IsInvincible(void);
    virtual s32 IsDying(void);
    virtual s32 IsFrozen(void);
    virtual s32 IsHurting(void);
    virtual s32 IsRespawning(void);
    virtual s32 InAir(void);
    virtual s32 IsIdle(void);
    virtual f32 GetCollectHeight(void);
    virtual s32 IsFuryActive(void);
    virtual void AddStat(StatType, float);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline s32 TrainChaseSpyroHeroInterface::GetHeroType() {
    return 2;
}

#if 0 // DRAFT: undefined identifier 'TrainChaseSpyro'
inline void *TrainChaseSpyroHeroInterface::GetProp() {
    return M2C_FIELD(this, TrainChaseSpyro **, 4);
}
#endif

inline MKPropDescriptor **TrainChaseSpyroHeroInterface::GetTargetable() {
    return 0;
}

inline void TrainChaseSpyroHeroInterface::Update() {

}

inline void TrainChaseSpyroHeroInterface::Draw() {

}

inline void TrainChaseSpyroHeroInterface::Message(MKMessage *arg0) {
    void *temp_r3_5669;

    temp_r3_5669 = M2C_FIELD(this, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r3_5669, void **, 0x44), M2C_UNK (**)(void *), 0x2C)(temp_r3_5669);
}

inline void TrainChaseSpyroHeroInterface::Enable() {
    void *temp_r3_5686;

    temp_r3_5686 = M2C_FIELD(this, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r3_5686, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_5686);
}

inline void TrainChaseSpyroHeroInterface::Disable() {
    void *temp_r3_5703;

    temp_r3_5703 = M2C_FIELD(this, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r3_5703, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_5703);
}

inline f32 TrainChaseSpyroHeroInterface::GetCollideRadius() {
    return 100.0f;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector3'
inline MKVector3 TrainChaseSpyroHeroInterface::GetCollisionCentre() {
    MKVector3 result;
    MKVector3 *sret = &result;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_5734;
    f64 temp_f0_5751;
    f64 temp_f1_5740;
    void *temp_r3_5738;

    temp_f1_5734 = M2C_FIELD(this->__vptr, f32 (**)(TrainChaseSpyroHeroInterface *), 0x28)(this);
    sp8 = 0.0f;
    temp_r3_5738 = M2C_FIELD(M2C_FIELD(this, void **, 4), void **, 8);
    spC = temp_f1_5734;
    temp_f1_5740 = M2C_FIELD(temp_r3_5738, f64 *, 0x30);
    sp10 = 0.0f;
    sp28 = (f64) sp8;
    sp38 = temp_f1_5740;
    sp30 = (f64) sp10;
    sp40 = M2C_FIELD(temp_r3_5738, f64 *, 0x38);
    temp_f0_5751 = temp_f1_5740 + sp28;
    sp18 = temp_f0_5751;
    M2C_FIELD(sret, f64 *, 0) = temp_f0_5751;
    sp20 = (f32) sp40 + (f32) sp30;
    M2C_FIELD(sret, f64 *, 8) = (f64) sp20;
    return result;
}
#endif

inline s32 TrainChaseSpyroHeroInterface::GetCollisionIgnoreMaterials() {
    return 0;
}

inline MKPropDescriptor **TrainChaseSpyroHeroInterface::GetCollisionInfo() {

}

inline s32 TrainChaseSpyroHeroInterface::GetLighting() {
    return 0;
}

inline s32 TrainChaseSpyroHeroInterface::GetEffects() {
    return 0;
}

#if 0 // DRAFT: undefined identifier 'TrainChaseSpyro'
inline void TrainChaseSpyroHeroInterface::GetInput() {
    ((TrainChaseSpyro *) (M2C_FIELD(this, TrainChaseSpyro **, 4)))->GetInput();
}
#endif

#if 0 // DRAFT: undefined identifier 'TrainChaseSpyro'
inline void TrainChaseSpyroHeroInterface::GetCamera() {
    ((TrainChaseSpyro *) (M2C_FIELD(this, TrainChaseSpyro **, 4)))->GetCamera();
}
#endif

inline s32 TrainChaseSpyroHeroInterface::IsInvincible() {
    return 0;
}

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
inline s32 TrainChaseSpyroHeroInterface::IsDying() {
    return ((KDStateMachine<TrainChaseSpyro> *) (M2C_FIELD(this, s32 *, 4) + 0x260))->GetState() == 3;
}
#endif

inline s32 TrainChaseSpyroHeroInterface::IsFrozen() {
    return 0;
}

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
inline s32 TrainChaseSpyroHeroInterface::IsHurting() {
    return ((KDStateMachine<TrainChaseSpyro> *) (M2C_FIELD(this, s32 *, 4) + 0x260))->GetState() == 2;
}
#endif

inline s32 TrainChaseSpyroHeroInterface::IsRespawning() {
    return 0;
}

inline s32 TrainChaseSpyroHeroInterface::InAir() {
    return 1;
}

inline s32 TrainChaseSpyroHeroInterface::IsIdle() {
    return 0;
}

inline s32 TrainChaseSpyroHeroInterface::IsActive() {
    return 1;
}

inline s32 TrainChaseSpyroHeroInterface::IsInputActive() {
    return 1;
}

inline f32 TrainChaseSpyroHeroInterface::GetCollectHeight() {
    return 500.0f;
}

inline s32 TrainChaseSpyroHeroInterface::IsFuryActive() {
    return 0;
}

#if 0 // DRAFT: undefined identifier 'Stat'
inline void TrainChaseSpyroHeroInterface::AddStat(StatType arg0, float arg1) {
    ((Stat *) (GameData::gameData + ((s32) arg0 * 0x18) + 0x70))->Add(arg1, 1U);
}
#endif

#endif  // SPYRO_SOURCE_TRAINCHASESPYROHEROINTERFACE_H
