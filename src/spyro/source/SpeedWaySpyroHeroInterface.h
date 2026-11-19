#ifndef SPYRO_SOURCE_SPEEDWAYSPYROHEROINTERFACE_H
#define SPYRO_SOURCE_SPEEDWAYSPYROHEROINTERFACE_H

#include <dolphin/types.h>
#include "spyro/source/HeroInterface.h"
#include "unplaced_enums.h"

class HeroInterface;
class MKMessage;
class MKPropDescriptor;
class SpeedWaySpyroHeroInterface;

class SpeedWaySpyroHeroInterface : public HeroInterface {  // base: inlined ctor vtable stores
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
    virtual void GetCollisionCentre(void);
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

inline s32 SpeedWaySpyroHeroInterface::GetHeroType() {
    return 1;
}

inline void *SpeedWaySpyroHeroInterface::GetProp() {
    return M2C_FIELD(this, MKPropDescriptor ***, 4);
}

inline MKPropDescriptor **SpeedWaySpyroHeroInterface::GetTargetable() {
    MKPropDescriptor **temp_r3_6689;

    temp_r3_6689 = M2C_FIELD(this, MKPropDescriptor ***, 4);
    if (temp_r3_6689 != NULL) {
        return temp_r3_6689 + 0x90;
    }
    return temp_r3_6689;
}

inline void SpeedWaySpyroHeroInterface::Update() {

}

inline void SpeedWaySpyroHeroInterface::Draw() {

}

inline void SpeedWaySpyroHeroInterface::Message(MKMessage *arg0) {
    void *temp_r3_6714;

    temp_r3_6714 = M2C_FIELD(this, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r3_6714, void **, 0x44), M2C_UNK (**)(void *), 0x2C)(temp_r3_6714);
}

inline void SpeedWaySpyroHeroInterface::Enable() {
    void *temp_r3_6731;

    temp_r3_6731 = M2C_FIELD(this, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r3_6731, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_6731);
}

inline void SpeedWaySpyroHeroInterface::Disable() {
    void *temp_r3_6748;

    temp_r3_6748 = M2C_FIELD(this, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r3_6748, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_6748);
}

#if 0 // DRAFT: ')' expected
inline f32 SpeedWaySpyroHeroInterface::GetCollideRadius() {
    return M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>(*M2C_FIELD(this, MKPropDescriptor ***, 4)), f32 *, 0x194);
}
#endif

inline void SpeedWaySpyroHeroInterface::GetCollisionCentre() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_6788;
    f64 temp_f0_6805;
    f64 temp_f1_6794;
    void *temp_r31_6782;
    void *temp_r3_6792;

    temp_r31_6782 = M2C_ERROR(/* Read from unset register $r4 */);
    temp_f1_6788 = M2C_FIELD(M2C_FIELD(temp_r31_6782, void **, 0), f32 (**)(void *), 0x28)(temp_r31_6782);
    sp8 = 0.0f;
    temp_r3_6792 = M2C_FIELD(M2C_FIELD(temp_r31_6782, void **, 4), void **, 8);
    spC = temp_f1_6788;
    temp_f1_6794 = M2C_FIELD(temp_r3_6792, f64 *, 0x30);
    sp10 = 0.0f;
    sp28 = (f64) sp8;
    sp38 = temp_f1_6794;
    sp30 = (f64) sp10;
    sp40 = M2C_FIELD(temp_r3_6792, f64 *, 0x38);
    temp_f0_6805 = temp_f1_6794 + sp28;
    sp18 = temp_f0_6805;
    M2C_FIELD(this, f64 *, 0) = temp_f0_6805;
    sp20 = (f32) sp40 + (f32) sp30;
    M2C_FIELD(this, f64 *, 8) = (f64) sp20;
}

#if 0 // DRAFT: ')' expected
inline s32 SpeedWaySpyroHeroInterface::GetCollisionIgnoreMaterials() {
    return M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>(*M2C_FIELD(this, MKPropDescriptor ***, 4)), s32 *, 0x1AC);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
inline MKPropDescriptor **SpeedWaySpyroHeroInterface::GetCollisionInfo() {
    return M2C_FIELD(this, s32 *, 4) + 0x70;
}
#endif

inline s32 SpeedWaySpyroHeroInterface::GetLighting() {
    return 0;
}

inline s32 SpeedWaySpyroHeroInterface::GetEffects() {
    return 0;
}

#if 0 // DRAFT: undefined identifier 'SpeedWaySpyro'
inline void SpeedWaySpyroHeroInterface::GetInput() {
    ((SpeedWaySpyro *) (M2C_FIELD(this, SpeedWaySpyro **, 4)))->GetInput();
}
#endif

#if 0 // DRAFT: undefined identifier 'SpeedWaySpyro'
inline void SpeedWaySpyroHeroInterface::GetCamera() {
    ((SpeedWaySpyro *) (M2C_FIELD(this, SpeedWaySpyro **, 4)))->GetCamera();
}
#endif

inline s32 SpeedWaySpyroHeroInterface::IsInvincible() {
    return 0;
}

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
inline s32 SpeedWaySpyroHeroInterface::IsDying() {
    return ((KDStateMachine<SpeedWaySpyro> *) (M2C_FIELD(this, s32 *, 4) + 0x180))->GetState() == 7;
}
#endif

inline s32 SpeedWaySpyroHeroInterface::IsFrozen() {
    return 0;
}

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
inline s32 SpeedWaySpyroHeroInterface::IsHurting() {
    s32 var_r31_6928;

    var_r31_6928 = 1;
    if ((((KDStateMachine<SpeedWaySpyro> *) (M2C_FIELD(this, s32 *, 4) + 0x180))->GetState() != 6) && (((KDStateMachine<SpeedWaySpyro> *) (M2C_FIELD(this, s32 *, 4) + 0x180))->GetState() != 5)) {
        var_r31_6928 = 0;
    }
    return var_r31_6928;
}
#endif

inline s32 SpeedWaySpyroHeroInterface::IsRespawning() {
    return 0;
}

inline s32 SpeedWaySpyroHeroInterface::InAir() {
    return 1;
}

inline s32 SpeedWaySpyroHeroInterface::IsIdle() {
    return 0;
}

inline s32 SpeedWaySpyroHeroInterface::IsActive() {
    return 1;
}

inline s32 SpeedWaySpyroHeroInterface::IsInputActive() {
    return 1;
}

inline f32 SpeedWaySpyroHeroInterface::GetCollectHeight() {
    return 500.0f;
}

inline s32 SpeedWaySpyroHeroInterface::IsFuryActive() {
    return 0;
}

#if 0 // DRAFT: undefined identifier 'Stat'
inline void SpeedWaySpyroHeroInterface::AddStat(StatType arg0, float arg1) {
    ((Stat *) (GameData::gameData + ((s32) arg0 * 0x18) + 0x70))->Add(arg1, 1U);
}
#endif

#endif  // SPYRO_SOURCE_SPEEDWAYSPYROHEROINTERFACE_H
