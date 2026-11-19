#ifndef SPYRO_SOURCE_SB2_H
#define SPYRO_SOURCE_SB2_H

#include <dolphin/types.h>
#include "spyro/source/AITargetData.h"
#include "unplaced_enums.h"

class AITargetData;
class Character;
class CharacterGraphNode;
class EnemyRegion;
class KDSplinePathSegment;
class MKVector3;
class SB2;
class SB2_cpp;
class SteerDirection;
class Targetable;

class SB2 {
public:
    void Arbitrate(void);
    void Calculate(unsigned int);
    void GraphFollowingAny(void);
    void GraphFollowing_EvadeMidNodeTraversal(void);
    void GraphFollowing_EvadeNoMoreNodes(void);
    s32 GraphFollowing_EvadeSelectLink(void);
    void GraphFollowing_PursuitMidNodeTraversal(void);
    void GraphFollowing_PursuitNoMoreNodes(void);
    s32 GraphFollowing_PursuitSelectLink(void);
    void GraphFollowing_RandomMidNodeTraversal(void);
    void GraphFollowing_RandomNoMoreNodes(void);
    s32 GraphFollowing_RandomSelectLink(void);
    void GraphFollowing(void);
    void GraphFollowingSetGoal(void);
    void GraphFollowingOff(void);
    void GraphFollowingOn(CharacterGraphNode *, CharacterGraphNode *, GraphFollowBehaviours, AITargetData *);
    void HazardAvoidance(void);
    void HazardAvoidanceOff(void);
    void HazardAvoidanceOn(void);
    void Containment(void);
    void ContainmentOff(void);
    void ContainmentOn(void);
    void WallAvoidance(void);
    void WallAvoidanceOff(void);
    void WallAvoidanceOn(void);
    void ObstacleAvoidance(void);
    void ObstacleAvoidanceOff(void);
    void ObstacleAvoidanceOn(AITargetData *);
    void PathFollowing(void);
    void PathFollowingSetGoal(void);
    s32 PathFollowingHasReachedNextPoint(void);
    s32 PathFollowingHasLooped(void);
    void PathFollowingOff(void);
    void PathFollowingOn(KDSplinePathSegment *, bool, bool, bool, bool, float);
    void Wander(void);
    void WanderSetGoal(void);
    void WanderOff(void);
    void WanderOn(void);
    void RandomPursuit(void);
    void RandomPursuitSetGoal(void);
    void RandomPursuitOff(void);
    void RandomPursuitOn(AITargetData *);
    void Pursuit(void);
    u8 PursuitPredictPos(MKVector3 *);
    void PursuitSetGoal(void);
    void PursuitOff(void);
    void PursuitOn(AITargetData *);
    void Arrive(void);
    void ArriveSetGoal(void);
    void ArriveOff(void);
    void ArriveOn(AITargetData *);
    void Seek(void);
    void SeekSetGoal(void);
    void SeekOff(void);
    void SeekOn(AITargetData *);
    void ResetSteerDirections(void);
    void SetExclusionRegion(EnemyRegion *);
    void SetRegion(EnemyRegion *);
    void SetVehicle(Targetable *);
    void SetDefaults(void);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ Character* unk0;
    /* 0x004 */ EnemyRegion* unk4;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ AITargetData* unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ AITargetData unk18;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ u8 unk7C;
    /* 0x07d */ u8 pad7D[0x4f];
    /* 0x0cc */ u8 unkCC;
    /* 0x0cd */ u8 padCD[0x2b];
    /* 0x0f8 */ u8 unkF8;
    /* 0x0f9 */ u8 padF9[0x2ff];
    /* 0x3f8 */ s32 unk3F8;
    /* 0x3fc */ u8 pad3FC[0x4];
    /* 0x400 */ u8 unk400;
    /* 0x401 */ u8 pad401[0x3];
    /* 0x404 */ f32 unk404;
    /* 0x408 */ f32 unk408;
    /* 0x40c */ u8 pad40C[0x4];
    /* 0x410 */ f32 unk410;
    /* 0x414 */ s32 unk414;
    /* 0x418 */ u8 unk418;
    /* 0x419 */ u8 pad419[0x7];
    /* 0x420 */ KDSplinePathSegment* unk420;
    /* 0x424 */ f32 unk424;
    /* 0x428 */ f32 unk428;
    /* 0x42c */ f32 unk42C;
    /* 0x430 */ s32 unk430;
    /* 0x434 */ u8 unk434;
    /* 0x435 */ u8 pad435[0x3];
    /* 0x438 */ f32 unk438;
    /* 0x43c */ f32 unk43C;
    /* 0x440 */ f32 unk440;
    /* 0x444 */ f32 unk444;
    /* 0x448 */ CharacterGraphNode* unk448;
    /* 0x44c */ CharacterGraphNode* unk44C;
    /* 0x450 */ AITargetData* unk450;
    /* 0x454 */ s32 unk454;
    /* 0x458 */ u8 unk458;
    /* 0x459 */ u8 pad459[0x7];
    /* 0x460 */ s32 unk460;
    /* 0x464 */ u8 unk464;
};

class SB2_cpp {
public:
    void __sinit(void);
};

class SteerDirection {
public:
    void Init(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ u8 pad34[0x4];
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ u8 pad64[0x4];
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x4];
    /* 0x078 */ f32 unk78;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ u8 pad84[0x4];
    /* 0x088 */ f32 unk88;
    /* 0x08c */ u8 pad8C[0x4];
    /* 0x090 */ u8 unk90;
};

extern u8 fGameTimeLastUpdate[0x4];
extern u32 gAvailableTicksThisUpdate;
#endif  // SPYRO_SOURCE_SB2_H
