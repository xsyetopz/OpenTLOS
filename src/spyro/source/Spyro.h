#ifndef SPYRO_SOURCE_SPYRO_H
#define SPYRO_SOURCE_SPYRO_H

#include <dolphin/types.h>
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"

class AttackerManager;
class ColObjDescriptor;
class CombatStateData;
class ContextInfo;
class HurtMessage;
class InputModifier;
class KDCamera;
class MKAnim;
class MKAnimScript;
class MKCloth;
class MKCollisionInfo;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class Matrix;
class MeleeAttackHitMsg;
class NodeLookAt;
class SafePosInfo;
class Spyro;
class SpyroCombatArcDescriptor;
class SpyroDescriptor;
class SpyroLighting;
class SpyroRotation;
class SpyroSoundPlayer;
class SpyroStateMachine;
class SpyroTargetList;
class Spyro_cpp;
class TargetContext;
class Tools_SendMessageHelper;

class HurtMessage {
public:
    /* 0x000 */ u8 pad0[0x28];
    /* 0x028 */ u32 unk28;
    /* 0x02c */ void* unk2C;
    /* 0x030 */ u8 pad30[0x10];
    /* 0x040 */ u8 unk40;
    /* 0x041 */ u8 unk41;
    /* 0x042 */ u8 unk42;
    /* 0x043 */ u8 pad43[0x1];
    /* 0x044 */ s32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ s8 unk50;
    /* 0x051 */ u8 unk51;
};

class SafePosInfo {
public:
    void SetPos(const MKVector3 &, MKProp *);
    void GetPos(void);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ MKProp* unk10;
};

class Spyro : public MKProp {  // base: ctor/dtor vtable stores
public:
    class AnimEvents;
    class AnimScriptNode;
    class Medium;
    class Nodes;
    class RefPoints;
    virtual ~Spyro(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
    virtual void pure_slot12() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot13() = 0;  // name unknown: no descendant fills this slot
    virtual void GetCenterPos(void);
    virtual void GetProp(void);
    virtual s32 GetEnemy(void);
    virtual s32 IsHero(void);
    virtual s32 IsFriend(void);
    virtual s32 IsEnemy(void);
    virtual s32 IsShatterable(void);
    virtual u8 IsDead(void);
    virtual s32 GetMoveToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetAimPoint(const MKVector3 &, MKVector3 *);
    virtual void GetVel(void);
    virtual f32 GetCollisionRadius(void);
    virtual f32 GetCollisionHeight(void);
    virtual f32 GetTimeLastHit(void);
    virtual s32 IsAttacking(void);
    virtual AttackerManager * GetAttackerManager(void);
    virtual MKCollisionInfo * GetCollisionInfo(void);
    f32 GetDeltaMove(void);
    void AddStat(StatType, float);
    void UpdateRage(void);
    void SetRage(int, float);
    f32 SetFuryAnimSpeed(float);
    void EmitWallHeadbuttEffects(const MKVector3 &);
    void Spawn(void);
    s32 GetCrowdCount(void);
    void UpdateCrowdTest(void);
    void ResetCrowdTest(void);
    void ResetLighting(void);
    void SetLighting(void);
    void UpdateLighting(void);
    u8 SelectBestKnockedUpEnemy(void);
    void UpdateMeleeButtonState(bool);
    s32 GetMeleeButtonState(void);
    void SetMeleeButtonStateTimeout(bool);
    void ClearMeleeButtonState(void);
    void GetCombatHitType(int);
    s32 ChargeCombatArcTest(void);
    void StartCombatArc(int);
    void SetupMeleeAttackHitMsg(int, MeleeAttackHitMsg *);
    void CombatArcCollisionTest(int);
    void UpdateCombatArcs(void);
    s32 ChooseCombatTarget(MKVector3 *, MKVector3 *);
    u8 IsInvincible(void);
    void Show(void);
    void Hide(void);
    u8 IsInTailStrike(void);
    u8 IsInTailSweep(void);
    u8 IsInMelee(void);
    u8 IsCharging(void);
    void GetYaw(void);
    void LandMediumExit(void);
    void LandMediumUpdate(void);
    void LandMediumEnter(void);
    void AirMediumExit(void);
    void AirMediumUpdate(void);
    void AirMediumEnter(void);
    void CalcVelTurnDir(float);
    void CalcYawTurnDir(float);
    void GetJoyDir(void);
    f32 GetJoyYaw(void);
    KDCamera * GetCamera(void);
    InputModifier * GetInput(void);
    void SetForce(const MKVector3 &, float);
    void SetDeltaPos(const MKVector3 &);
    void SetDesiredVelocityVectical(float, float);
    void SetDesiredVelocityHoriz(const MKVector3 &, float);
    void SetDesiredVelocity(const MKVector3 &, float);
    void PushAwayFrom(MKMessage *);
    void StableReposition(const MKVector3 &, float, bool, bool);
    void ClearSafePos(void);
    void SetLastSafePos(const MKVector3 &, MKProp *);
    void TeleportEffects(const MKVector3 &, Matrix *);
    void Teleport(const MKVector3 &, float, int, bool, bool);
    MKAnimScript * GetAnimScript(Spyro::AnimScriptNode);
    void PostSetAnim(void);
    void PreSetAnim(void);
    void SetAnim(MKAnim *, float, Spyro::AnimScriptNode, unsigned int, float);
    void SetAnim(unsigned int, float, Spyro::AnimScriptNode, unsigned int, float);
    void GetRefPos(Spyro::RefPoints);
    void GetNodeMatrix(Spyro::Nodes, Matrix *);
    void GetNodePos(int);
    u8 SlipTest(void);
    void HornDiveTranstion(void);
    u8 TailSweepTailStrikeTransition(void);
    s8 SpikyTransition(void);
    s8 LavaTransition(void);
    s32 AirToStrafeDodgeTransition(void);
    u8 AirToLedgeGrabTransition(void);
    u8 LandToMoveTransition(bool, bool);
    void LandToAirTransition(bool, bool, bool);
    u8 TryChangeState(bool, unsigned int, SpyroStateMsg, bool);
    u8 TryChangeState(bool, unsigned int, MKMessage *, bool);
    void OnStateChange(int, int);
    void OnStateChange(void);
    void IsAgainstMatID(int);
    u8 OnFloor(void);
    void CheckForKnockBack(ContextInfo &, float);
    void UpdateBreathEffects(const Matrix *, const MKVector3 &);
    void SetAutoHealthRegen(bool);
    void SetForceLookAtTarget(MKProp *);
    void UseCynderStrafeState(bool, bool);
    void SelectStrafeTarget(bool);
    u8 IsPlayingStrafeAnim(void);
    u8 CanStrafe(void);
    void SetInvincibilityTimeOut(float);
    void UpdateInvincibility(void);
    void UpdateSlidingSounds(void);
    void UpdateWaterSurfaceFX(bool);
    void UpdateEffects(MKVector3 *);
    void AddFootEffect(int);
    void ColorSpyroFromGround(float);
    void BridgeHit(float, float);
    void BroadcastMessage(int);
    void BroadcaseCollectRequestMessage(float);
    void SetLVEScale(const MKVector3 &);
    void ProcessAnimationEvent(Spyro::AnimEvents);
    void UpdateEvents(void);
    void UpdateAnimation(void);
    void DeathReset(void);
    void ClearData(void);
    void PlatformUpdate(void);
    void PlatformDetach(void);
    void PlatformAttach(MKProp *, MKCollisionInfo *);
    MKProp * OnProp(void);
    void SetMedium(Spyro::Medium);
    s8 Hurt(HurtMessage *);
    u8 DealDamage(float, bool, bool, HurtMessage *);
    void UpdateCheats(void);
    void SetPos(const MKVector3 &);
    void UpdateLastSafePos(void);
    void GetLastSafePos(void);
    void * LastSafePosAvailable(void);
    void UpdateShockwavePosition(void);
    void ModelOffsetPostUpdate(void);
    void ModelOffsetPreUpdate(void);
    void SetModelVisualOffset(const MKVector3 &, bool);
    void ApplyEdgePhysics(MKVector3);
    void ApplyIcePhysics(MKVector3);
    void ApplySlipperyPhysics(MKVector3);
    void ApplyPhysics(MKVector3);
    void ClipVelToEdge(const MKVector3 &);
    void CheckForEdge(void);
    u8 CheckForEdge(float, const MKVector3 &, bool, MKVector3 *);
    u8 CheckForLedge(const MKVector3 &, MKVector3 *, MKVector3 *, MKVector3 *, MKProp **);
    void UpdateMovement(void);
    void UpdateHeadTurning(void);
    void CheckCameraButtons(void);
    void UpdateCameraInfo(const MKVector3 &);
    void UpdateSpyroCameraInfo(void);
    void DrawDebug(void);
    void DrawSpyro(void);
    void GetCollisionCentre(void);
    static u8 pNodeNames[0x18];
    static u8 stateCreators[0xf0];
    static u8 mediumFSMStates[0x6c];
    static u8 pRefPointNames[0x4];
    static u8 defaultEvents[0x8];
    static u8 pAnimScrNodeNames[0x8];
    static u8 pInstance[0x4];
    /* 0x04c */ s32* unk4C;
    /* 0x050 */ u8 pad50[0x4];
    /* 0x054 */ SpyroStateMachine unk54;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ u8 unk78;
    /* 0x079 */ u8 pad79[0x7];
    /* 0x080 */ f32 unk80;
    /* 0x084 */ u8 pad84[0x4];
    /* 0x088 */ void* unk88;
    /* 0x08c */ u8 pad8C[0x4];
    /* 0x090 */ u8 unk90;
    /* 0x091 */ u8 pad91[0x3];
    /* 0x094 */ void** unk94;
    /* 0x098 */ u8 pad98[0x18];
    /* 0x0b0 */ s32 unkB0;
    /* 0x0b4 */ void* unkB4;
    /* 0x0b8 */ u8 padB8[0x8];
    /* 0x0c0 */ MKAnimScript unkC0;
    /* 0x118 */ u8 pad118[0x60];
    /* 0x178 */ NodeLookAt unk178;
    /* 0x1b1 */ u8 pad1B1[0x3];
    /* 0x1b4 */ TargetContext unk1B4;
    /* 0x1c4 */ u8 unk1C4;
    /* 0x1c5 */ u8 unk1C5;
    /* 0x1c6 */ u8 unk1C6;
    /* 0x1c7 */ u8 unk1C7;
    /* 0x1c8 */ u8 unk1C8;
    /* 0x1c9 */ s8 unk1C9;
    /* 0x1ca */ u8 pad1CA[0x6];
    /* 0x1d0 */ MKVector3 unk1D0;
    /* 0x1e0 */ u32 unk1E0;
    /* 0x1e4 */ u8 pad1E4[0x14];
    /* 0x1f8 */ f32 unk1F8;
    /* 0x1fc */ u8 pad1FC[0x4];
    /* 0x200 */ s32 unk200;
    /* 0x204 */ InputModifier unk204;
    /* 0x214 */ InputModifier unk214;
    /* 0x224 */ KDCamera* unk224;
    /* 0x228 */ u8 pad228[0x8];
    /* 0x230 */ s32 unk230;
    /* 0x234 */ u8 pad234[0x4];
    /* 0x238 */ f64 unk238;
    /* 0x240 */ f64 unk240;
    /* 0x248 */ f32 unk248;
    /* 0x24c */ f32 unk24C;
    /* 0x250 */ f32 unk250;
    /* 0x254 */ s32 unk254;
    /* 0x258 */ f32 unk258;
    /* 0x25c */ u8 unk25C;
    /* 0x25d */ u8 unk25D;
    /* 0x25e */ u8 pad25E[0x2];
    /* 0x260 */ void* unk260;
    /* 0x264 */ void** unk264;
    /* 0x268 */ s8 unk268;
    /* 0x269 */ u8 unk269;
    /* 0x26a */ u8 pad26A[0x2];
    /* 0x26c */ MKCollisionInfo unk26C;
    /* 0x27c */ void* unk27C;
    /* 0x280 */ MKCloth* unk280;
    /* 0x284 */ u8 unk284;
    /* 0x285 */ u8 pad285[0x3];
    /* 0x288 */ f64 unk288;
    /* 0x290 */ f64 unk290;
    /* 0x298 */ f32 unk298;
    /* 0x29c */ u8 pad29C[0x4];
    /* 0x2a0 */ f32 unk2A0;
    /* 0x2a4 */ f32 unk2A4;
    /* 0x2a8 */ f32 unk2A8;
    /* 0x2ac */ u8 pad2AC[0x4];
    /* 0x2b0 */ f32 unk2B0;
    /* 0x2b4 */ f32 unk2B4;
    /* 0x2b8 */ f32 unk2B8;
    /* 0x2bc */ u8 pad2BC[0x4];
    /* 0x2c0 */ f32 unk2C0;
    /* 0x2c4 */ f32 unk2C4;
    /* 0x2c8 */ f32 unk2C8;
    /* 0x2cc */ f32 unk2CC;
    /* 0x2d0 */ f32 unk2D0;
    /* 0x2d4 */ f32 unk2D4;
    /* 0x2d8 */ s16 unk2D8;
    /* 0x2da */ s8 unk2DA;
    /* 0x2db */ s8 unk2DB;
    /* 0x2dc */ s32 unk2DC;
    /* 0x2e0 */ f32 unk2E0;
    /* 0x2e4 */ s32 unk2E4;
    /* 0x2e8 */ void* unk2E8;
    /* 0x2ec */ s32 unk2EC;
    /* 0x2f0 */ u8 unk2F0;
    /* 0x2f1 */ u8 pad2F1[0xb];
    /* 0x2fc */ f32 unk2FC;
    /* 0x300 */ f32 unk300;
    /* 0x304 */ u8 pad304[0x4];
    /* 0x308 */ f32 unk308;
    /* 0x30c */ u8 pad30C[0x4];
    /* 0x310 */ f32 unk310;
    /* 0x314 */ f32 unk314;
    /* 0x318 */ f32 unk318;
    /* 0x31c */ u8 pad31C[0x4];
    /* 0x320 */ f32 unk320;
    /* 0x324 */ f32 unk324;
    /* 0x328 */ u8 pad328[0x4];
    /* 0x32c */ f32 unk32C;
    /* 0x330 */ f32 unk330;
    /* 0x334 */ u8 pad334[0x4];
    /* 0x338 */ f32 unk338;
    /* 0x33c */ f32 unk33C;
    /* 0x340 */ f32 unk340;
    /* 0x344 */ u8 pad344[0x4];
    /* 0x348 */ f32 unk348;
    /* 0x34c */ f32 unk34C;
    /* 0x350 */ f32 unk350;
    /* 0x354 */ u8 pad354[0x4];
    /* 0x358 */ s32 unk358;
    /* 0x35c */ s32 unk35C;
    /* 0x360 */ s32 unk360;
    /* 0x364 */ MKProp** unk364;
    /* 0x368 */ f64 unk368;
    /* 0x370 */ f64 unk370;
    /* 0x378 */ f64 unk378;
    /* 0x380 */ f64 unk380;
    /* 0x388 */ f32 unk388;
    /* 0x38c */ f32 unk38C;
    /* 0x390 */ f32 unk390;
    /* 0x394 */ u8 unk394;
    /* 0x395 */ u8 pad395[0x3];
    /* 0x398 */ f32 unk398;
    /* 0x39c */ f32 unk39C;
    /* 0x3a0 */ f32 unk3A0;
    /* 0x3a4 */ u8 pad3A4[0x4];
    /* 0x3a8 */ SpyroRotation unk3A8;
    /* 0x3b4 */ u8 pad3B4[0xc];
    /* 0x3c0 */ f32 unk3C0;
    /* 0x3c4 */ f32 unk3C4;
    /* 0x3c8 */ f32 unk3C8;
    /* 0x3cc */ u8 unk3CC;
    /* 0x3cd */ u8 unk3CD;
    /* 0x3ce */ u8 unk3CE;
    /* 0x3cf */ u8 unk3CF;
    /* 0x3d0 */ s8 unk3D0;
    /* 0x3d1 */ s8 unk3D1;
    /* 0x3d2 */ s8 unk3D2;
    /* 0x3d3 */ u8 unk3D3;
    /* 0x3d4 */ s8 unk3D4;
    /* 0x3d5 */ u8 unk3D5;
    /* 0x3d6 */ u8 unk3D6;
    /* 0x3d7 */ u8 pad3D7[0x1];
    /* 0x3d8 */ u32 unk3D8;
    /* 0x3dc */ f32 unk3DC;
    /* 0x3e0 */ u8 unk3E0;
    /* 0x3e1 */ u8 pad3E1[0x3];
    /* 0x3e4 */ f32 unk3E4;
    /* 0x3e8 */ s32 unk3E8;
    /* 0x3ec */ MKProp* unk3EC;
    /* 0x3f0 */ u8 pad3F0[0x18];
    /* 0x408 */ Spyro* unk408;
    /* 0x40c */ u32 unk40C;
    /* 0x410 */ u8 pad410[0xc];
    /* 0x41c */ s32 unk41C;
    /* 0x420 */ u8 pad420[0x8];
    /* 0x428 */ s32 unk428;
    /* 0x42c */ u8 pad42C[0x4];
    /* 0x430 */ SpyroLighting unk430;
    /* 0x45c */ u8 pad45C[0x4];
    /* 0x460 */ CombatStateData unk460;
    /* 0x4b4 */ u8 pad4B4[0xc];
    /* 0x4c0 */ s32 unk4C0;
    /* 0x4c4 */ f32 unk4C4;
    /* 0x4c8 */ f32 unk4C8;
    /* 0x4cc */ u8 unk4CC;
    /* 0x4cd */ u8 unk4CD;
    /* 0x4ce */ u8 unk4CE;
    /* 0x4cf */ u8 unk4CF;
    /* 0x4d0 */ u8 pad4D0[0x20];
    /* 0x4f0 */ void* unk4F0;
    /* 0x4f4 */ u8 pad4F4[0x4];
    /* 0x4f8 */ MKVector3 unk4F8;
    /* 0x508 */ u8 pad508[0x1e8];
    /* 0x6f0 */ u32* unk6F0;
    /* 0x6f4 */ Tools_SendMessageHelper* unk6F4;
    /* 0x6f8 */ SpyroSoundPlayer unk6F8;
    /* 0x6f9 */ u8 pad6F9[0x477];
    /* 0xb70 */ void* unkB70;
    /* 0xb74 */ f32 unkB74;
    /* 0xb78 */ AttackerManager unkB78;
    /* 0xb7c */ u8 padB7C[0x14];
    /* 0xb90 */ SpyroTargetList unkB90;
    /* 0xba5 */ u8 padBA5[0x3];
    /* 0xba8 */ f32 unkBA8;
    /* 0xbac */ s32 unkBAC;
    /* 0xbb0 */ u8 unkBB0;
    /* 0xbb1 */ u8 padBB1[0x3];
    /* 0xbb4 */ s32 unkBB4;
};

class SpyroCombatArcDescriptor {
public:
    s32 LoadLine(MKIniLine *);
    void Init(void);
    /* 0x000 */ s8* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ s32 unk18;
};

class SpyroDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ ColObjDescriptor unk60;
    /* 0x0ac */ s8* unkAC;
    /* 0x0b0 */ s8* unkB0;
    /* 0x0b4 */ s8* unkB4;
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ f32 unkBC;
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ f32 unkC4;
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ s8* unkCC;
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
};

class Spyro_cpp {
public:
    void __sinit(void);
};

extern f32 SPYRO_COMBAT_SCALE_MAG;
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline Spyro::~Spyro() {
    M2C_UNK *temp_r0_34;
    M2C_UNK *temp_r4_37;
    Spyro *temp_r0_50;
    s32 *temp_r4_53;

    if (this != NULL) {
        this->unk4C = &__vt.unk38;
        if (&this->unk6F8 != NULL) {
            __destroy_arr(&this->unk6F8, &SpyroSoundPlayer::SpyroLoopSounds::~SpyroLoopSounds, 0x58, 0xD);
        }
        if (&this->unk418 != NULL) {
            temp_r0_34 = this->unk420;
            if (temp_r0_34 != NULL) {
                temp_r4_37 = &this->unk418;
                if (temp_r0_34 != temp_r4_37) {
                    M2C_FIELD(this->unk41C, M2C_UNK **, 8) = temp_r0_34;
                    M2C_FIELD(this->unk420, s32 *, 0xC) = (s32) this->unk41C;
                    this->unk41C = (s32) temp_r4_37;
                    this->unk420 = temp_r4_37;
                }
            }
        }
        if (&this->unk3E8 != NULL) {
            temp_r0_50 = this->unk408;
            if (temp_r0_50 != NULL) {
                temp_r4_53 = &this->unk3E8;
                if (temp_r0_50 != temp_r4_53) {
                    M2C_FIELD(this->unk40C, Spyro **, 0x20) = temp_r0_50;
                    this->unk408->unk24 = M2C_BITWISE(f32, this->unk40C);
                    this->unk40C = (u32) temp_r4_53;
                    this->unk408 = (Spyro *) temp_r4_53;
                }
            }
        }
        if (this != NULL) {
        }
    }
}
#endif

inline AttackerManager *Spyro::GetAttackerManager() {
    return &this->unkB78;
}

inline s32 Spyro::IsAttacking() {
    s32 var_r31_98;

    var_r31_98 = 0;
    if ((IsCharging() != 0) || (IsInMelee() != 0) || (IsInTailSweep() != 0) || (IsInTailStrike() != 0) || ((u8) M2C_FIELD(this, u8 *, 0x3D3) != 0)) {
        var_r31_98 = 1;
    }
    return var_r31_98;
}

inline f32 Spyro::GetTimeLastHit() {
    return this->unkB74;
}

inline f32 Spyro::GetCollisionHeight() {
    return 200.0f;
}

inline f32 Spyro::GetCollisionRadius() {
    return 100.0f;
}

inline MKCollisionInfo *Spyro::GetCollisionInfo() {
    return (MKCollisionInfo *) &this->unk264;
}

inline void Spyro::GetVel() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x338);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x340);
}

#if 0 // DRAFT: undefined identifier 'MKVector'
inline s32 Spyro::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;

    MKVector(0.0f, 160.0f, 0.0f);
    ((MKProp *) &sp28)->GetPos();
    sp8 = sp28 + sp18;
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = sp30 + sp20;
    sp38 = sp8;
    sp40 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
inline s32 Spyro::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;

    MKVector(0.0f, 160.0f, 0.0f);
    ((MKProp *) &sp28)->GetPos();
    sp8 = sp28 + sp18;
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = sp30 + sp20;
    sp38 = sp8;
    sp40 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

inline s32 Spyro::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_253;
    f64 temp_f1_252;
    void *temp_r4_250;

    temp_r4_250 = this->unk8;
    temp_f1_252 = M2C_FIELD(temp_r4_250, f64 *, 0x30);
    temp_f0_253 = M2C_FIELD(temp_r4_250, f64 *, 0x38);
    sp8 = temp_f1_252;
    M2C_FIELD(arg1, f64 *, 0) = temp_f1_252;
    sp10 = temp_f0_253;
    M2C_FIELD(arg1, f64 *, 8) = temp_f0_253;
    return 1;
}

inline u8 Spyro::IsDead() {
    return M2C_FIELD(this, u8 *, 0x3CD);
}

inline s32 Spyro::IsShatterable() {
    return 0;
}

inline s32 Spyro::IsEnemy() {
    return 0;
}

inline s32 Spyro::IsFriend() {
    return 0;
}

inline s32 Spyro::IsHero() {
    return 1;
}

inline s32 Spyro::GetEnemy() {
    return 0;
}

inline void Spyro::GetProp() {

}

inline void Spyro::GetCollisionCentre() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_1876;
    f64 temp_f0_1889;
    f64 temp_f1_1864;
    void *temp_r5_1862;

    temp_r5_1862 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 8);
    sp1C = 100.0f;
    temp_f1_1864 = M2C_FIELD(temp_r5_1862, f64 *, 0x30);
    sp18 = 0.0f;
    sp20 = 0.0f;
    sp38 = (f64) sp18;
    sp48 = temp_f1_1864;
    sp40 = (f64) sp20;
    sp50 = M2C_FIELD(temp_r5_1862, f64 *, 0x38);
    temp_f0_1876 = temp_f1_1864 + sp38;
    sp8 = temp_f0_1876;
    sp58 = temp_f0_1876;
    sp10 = (f32) sp50 + (f32) sp40;
    sp60 = (f64) sp10;
    temp_f0_1889 = sp58 + M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x368);
    sp28 = temp_f0_1889;
    M2C_FIELD(this, f64 *, 0) = temp_f0_1889;
    sp30 = (f32) sp60 + M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x370);
    M2C_FIELD(this, f64 *, 8) = (f64) sp30;
}

#endif  // SPYRO_SOURCE_SPYRO_H
