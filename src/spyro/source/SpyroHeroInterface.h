#ifndef SPYRO_SOURCE_SPYROHEROINTERFACE_H
#define SPYRO_SOURCE_SPYROHEROINTERFACE_H

#include <dolphin/types.h>
#include "spyro/source/HeroInterface.h"
#include "unplaced_enums.h"

class HeroInterface;
class MKMessage;
class MKPropDescriptor;
class MKVector3;
class SpyroHeroInterface;

class SpyroHeroInterface : public HeroInterface {  // base: inlined ctor vtable stores
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
    virtual void UpdateCameraInfo(const MKVector3 &);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline s32 SpyroHeroInterface::GetHeroType() {
    return 0;
}

#if 0 // DRAFT: undefined identifier 'Spyro'
inline void *SpyroHeroInterface::GetProp() {
    return M2C_FIELD(this, Spyro **, 4);
}
#endif

#if 0 // DRAFT: undefined identifier 'Spyro'
inline MKPropDescriptor **SpyroHeroInterface::GetTargetable() {
    Spyro *temp_r3_17436;

    temp_r3_17436 = M2C_FIELD(this, Spyro **, 4);
    if (temp_r3_17436 != NULL) {
        return temp_r3_17436 + 0x4C;
    }
    return temp_r3_17436;
}
#endif

inline void SpyroHeroInterface::Update() {
    void *temp_r3_17449;

    temp_r3_17449 = M2C_FIELD(this, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r3_17449, void **, 0x44), M2C_UNK (**)(void *), 0x24)(temp_r3_17449);
}

inline void SpyroHeroInterface::Draw() {
    void *temp_r3_17466;

    temp_r3_17466 = M2C_FIELD(this, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r3_17466, void **, 0x44), M2C_UNK (**)(void *), 0x28)(temp_r3_17466);
}

inline void SpyroHeroInterface::Message(MKMessage *arg0) {
    void *temp_r3_17483;

    temp_r3_17483 = M2C_FIELD(this, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r3_17483, void **, 0x44), M2C_UNK (**)(void *), 0x2C)(temp_r3_17483);
}

inline void SpyroHeroInterface::Enable() {
    void *temp_r3_17500;

    temp_r3_17500 = M2C_FIELD(this, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r3_17500, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_17500);
}

inline void SpyroHeroInterface::Disable() {
    void *temp_r3_17517;

    temp_r3_17517 = M2C_FIELD(this, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r3_17517, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_17517);
}

inline f32 SpyroHeroInterface::GetCollideRadius() {
    return 100.0f;
}

inline void SpyroHeroInterface::GetCollisionCentre() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_17556;
    f64 temp_f0_17569;
    f64 temp_f1_17544;
    void *temp_r4_17542;
    void *temp_r5_17540;

    temp_r5_17540 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 4);
    temp_r4_17542 = M2C_FIELD(temp_r5_17540, void **, 8);
    sp30 = 0.0f;
    temp_f1_17544 = M2C_FIELD(temp_r4_17542, f64 *, 0x30);
    sp28 = 0.0f;
    sp2C = 100.0f;
    sp48 = temp_f1_17544;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    sp50 = M2C_FIELD(temp_r4_17542, f64 *, 0x38);
    temp_f0_17556 = temp_f1_17544 + sp58;
    sp18 = temp_f0_17556;
    sp38 = temp_f0_17556;
    sp20 = (f32) sp50 + (f32) sp60;
    sp40 = (f64) sp20;
    temp_f0_17569 = sp38 + M2C_FIELD(temp_r5_17540, f64 *, 0x368);
    sp8 = temp_f0_17569;
    M2C_FIELD(this, f64 *, 0) = temp_f0_17569;
    sp10 = (f32) sp40 + M2C_FIELD(temp_r5_17540, f32 *, 0x370);
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}

inline s32 SpyroHeroInterface::GetCollisionIgnoreMaterials() {
    return 0x220;
}

inline MKPropDescriptor **SpyroHeroInterface::GetCollisionInfo() {
    void *temp_r3_17596;

    temp_r3_17596 = M2C_FIELD(this, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r3_17596, void **, 0x44), M2C_UNK (**)(void *), 0xC8)(temp_r3_17596);
}

inline s32 SpyroHeroInterface::GetLighting() {
    return M2C_FIELD(this, s32 *, 4) + 0x430;
}

#if 0 // DRAFT: undefined identifier 'SpyroEffects'
inline s32 SpyroHeroInterface::GetEffects() {
    return M2C_FIELD(M2C_FIELD(this, void **, 4), SpyroEffects **, 0x260);
}
#endif

#if 0 // DRAFT: undefined identifier 'Spyro'
inline void SpyroHeroInterface::GetInput() {
    ((Spyro *) (M2C_FIELD(this, Spyro **, 4)))->GetInput();
}
#endif

#if 0 // DRAFT: undefined identifier 'Spyro'
inline void SpyroHeroInterface::GetCamera() {
    ((Spyro *) (M2C_FIELD(this, Spyro **, 4)))->GetCamera();
}
#endif

#if 0 // DRAFT: undefined identifier 'Spyro'
inline void SpyroHeroInterface::UpdateCameraInfo(const MKVector3 &arg0) {
    ((Spyro *) (M2C_FIELD(this, Spyro **, 4)))->UpdateCameraInfo(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'Spyro'
inline s32 SpyroHeroInterface::IsInvincible() {
    ((Spyro *) (M2C_FIELD(this, Spyro **, 4)))->IsInvincible();
}
#endif

inline s32 SpyroHeroInterface::IsDying() {
    return M2C_FIELD(M2C_FIELD(this, void **, 4), u8 *, 0x3CD);
}

inline s32 SpyroHeroInterface::IsFrozen() {
    return M2C_FIELD(M2C_FIELD(this, void **, 4), u8 *, 0x3CE);
}

inline s32 SpyroHeroInterface::IsHurting() {
    return M2C_FIELD(M2C_FIELD(this, void **, 4), s32 *, 0x5C) == 9;
}

inline s32 SpyroHeroInterface::IsRespawning() {
    return M2C_FIELD(M2C_FIELD(this, void **, 4), u8 *, 0x3CF);
}

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
inline s32 SpyroHeroInterface::InAir() {
    return ((KDStateMachine<Spyro> *) (M2C_FIELD(this, s32 *, 4) + 0x7C))->GetState() == 2;
}
#endif

inline s32 SpyroHeroInterface::IsIdle() {
    return M2C_FIELD(M2C_FIELD(this, void **, 4), s32 *, 0x5C) == 4;
}

inline s32 SpyroHeroInterface::IsActive() {
    void *temp_r4_17746;

    temp_r4_17746 = M2C_FIELD(this, void **, 4);
    if (((u8) M2C_FIELD(temp_r4_17746, u8 *, 0x90) != 0) && ((u8) M2C_FIELD(temp_r4_17746, u8 *, 0x1C4) != 0)) {
        return 1;
    }
    return 0;
}

inline s32 SpyroHeroInterface::IsInputActive() {
    return M2C_FIELD(M2C_FIELD(this, void **, 4), u8 *, 0x1C4);
}

#if 0 // DRAFT: ')' expected
inline f32 SpyroHeroInterface::GetCollectHeight() {
    return M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>(*M2C_FIELD(this, MKPropDescriptor ***, 4)), f32 *, 0xB8);
}
#endif

inline s32 SpyroHeroInterface::IsFuryActive() {
    return M2C_FIELD(M2C_FIELD(this, void **, 4), s32 *, 0x5C) == 0xE;
}

#if 0 // DRAFT: undefined identifier 'Spyro'
inline void SpyroHeroInterface::AddStat(StatType arg0, float arg1) {
    ((Spyro *) (M2C_FIELD(this, Spyro **, 4)))->AddStat(arg0, arg1);
}
#endif

#endif  // SPYRO_SOURCE_SPYROHEROINTERFACE_H
