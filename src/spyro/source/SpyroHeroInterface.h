#ifndef SPYRO_SOURCE_SPYROHEROINTERFACE_H
#define SPYRO_SOURCE_SPYROHEROINTERFACE_H

#include <dolphin/types.h>

class MKMessage;
class MKVector3;
class Spyro;
class SpyroEffects;
class SpyroHeroInterface;
class SpyroLighting;
class StatType;

class SpyroHeroInterface {
public:
    virtual s32 GetHeroType(void);
    virtual Spyro * GetProp(void);
    virtual Spyro * GetTargetable(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
    virtual f32 GetCollideRadius(void);
    virtual void GetCollisionCentre(void);
    virtual s32 GetCollisionIgnoreMaterials(void);
    virtual void GetCollisionInfo(void);
    virtual SpyroLighting * GetLighting(void);
    virtual SpyroEffects * GetEffects(void);
    virtual void GetInput(void);
    virtual u8 IsInputActive(void);
    virtual void GetCamera(void);
    virtual s32 IsActive(void);
    virtual void IsInvincible(void);
    virtual u8 IsDying(void);
    virtual u8 IsFrozen(void);
    virtual s32 IsHurting(void);
    virtual u8 IsRespawning(void);
    virtual s32 InAir(void);
    virtual s32 IsIdle(void);
    virtual f32 GetCollectHeight(void);
    virtual s32 IsFuryActive(void);
    virtual void AddStat(StatType, float);
    virtual void UpdateCameraInfo(const MKVector3 &);
};

#endif  // SPYRO_SOURCE_SPYROHEROINTERFACE_H
