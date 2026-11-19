#ifndef SPYRO_SOURCE_TRAINCHASESPYROHEROINTERFACE_H
#define SPYRO_SOURCE_TRAINCHASESPYROHEROINTERFACE_H

#include <dolphin/types.h>

class MKMessage;
class StatType;
class TrainChaseSpyro;
class TrainChaseSpyroHeroInterface;

class TrainChaseSpyroHeroInterface {
public:
    virtual s32 GetHeroType(void);
    virtual TrainChaseSpyro * GetProp(void);
    virtual s32 GetTargetable(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
    virtual f32 GetCollideRadius(void);
    virtual void GetCollisionCentre(void);
    virtual s32 GetCollisionIgnoreMaterials(void);
    virtual void GetCollisionInfo(void);
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

#endif  // SPYRO_SOURCE_TRAINCHASESPYROHEROINTERFACE_H
