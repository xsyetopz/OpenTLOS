#include "spyro/source/BeetleNestSmall.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EnemySpawner.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/GoopFX.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerCamera.h"
#include "spyro/source/KDSynkerPlayerEvents.h"
#include "spyro/source/KDSynkerPlayerSounds.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointData.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/shatterwaypointspawn.h"
#include "unplaced_templates.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'FindInteractivePropMsg'
void BeetleNestSmall::Message(MKMessage *arg0) {
    s32 temp_r0_47;
    void *temp_r3_60;

    temp_r0_47 = arg0->unk0;
    switch (temp_r0_47) {                           /* irregular */
    case 0x79:
        temp_r3_60 = checked_cast<FindInteractivePropMsg *, MKMessage>(arg0);
        if ((s32) M2C_FIELD(temp_r3_60, s32 *, 8) == 4) {
            M2C_FIELD(temp_r3_60, BeetleNestSmall **, 0xC) = this;
            return;
        }
        return;
    case 0xB5:
        this->unk1A8.FunctionOn();
    default:
block_10:
        Shatterable::Message(arg0);
        break;
    case 0xB4:
        this->unk1A8.FunctionOff();
        goto block_10;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void *BeetleNestSmall::Update() {
    MKVector3 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDSynkerPlayer3 *temp_r3_137;
    SpawnPointObject *temp_r30_253;
    f32 temp_f3_194;
    f64 temp_f0_192;
    f64 temp_f0_203;
    s32 temp_r29_242;
    s32 temp_r3_99;
    s32 var_r28_246;
    u32 temp_r4_252;
    u8 var_r30_134;
    void *temp_r29_136;
    void *temp_r3_187;
    void *temp_r3_236;
    void *temp_r4_190;

    Shatterable::Update();
    temp_r3_99 = this->unk80->unk2C;
    if ((temp_r3_99 & 1) && !(temp_r3_99 & 2)) {
        this->unk80->SetAnim(M2C_FIELD(checked_cast<BeetleNestSmallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x170), 1.0f, 0.0f, 0, -1);
    }
    if ((this->unk1A8.IsSpawning() != 0) && (IsDead() != 0)) {
        this->unk1A8.FunctionOff();
    }
    if (this->unk1A8.IsSpawning() != 0) {
        var_r30_134 = 0;
        temp_r29_136 = M2C_FIELD(&gb, void **, 0xC);
        temp_r3_137 = M2C_FIELD(temp_r29_136, KDSynkerPlayer3 **, 0x78);
        if (((temp_r3_137 != NULL) && (temp_r3_137->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r29_136, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r29_136) + 0x24))->GetState() == 2))) {
            var_r30_134 = 1;
        }
        if ((var_r30_134 == 0) && ((s32) this->unk1FC > 0)) {
            this->unk1A8.UpdateUsedSpawnPointMask();
            if (this->unk1A8.TrySpawnItem(M2C_FIELD(checked_cast<BeetleNestSmallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x16C)) != NULL) {
                this->unk80->SetAnim(M2C_FIELD(checked_cast<BeetleNestSmallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x174), 1.0f, 0.0f, 0, -1);
                MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) this->unk208, &sp98);
                temp_r3_187 = checked_cast<BeetleNestSmallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                temp_r4_190 = ((u8 *) this->unk8) + 0x10;
                temp_f0_192 = M2C_FIELD(temp_r4_190, f64 *, 0) * 5.53552857e-315;
                sp38 = temp_f0_192;
                temp_f3_194 = M2C_FIELD(temp_r4_190, f32 *, 8);
                sp68 = temp_f0_192;
                sp40 = temp_f3_194 * 100.0f;
                sp70 = (f64) sp40;
                temp_f0_203 = M2C_BITWISE(f64, sp98) + temp_f0_192;
                sp28 = temp_f0_203;
                sp78 = temp_f0_203;
                sp30 = sp98.unk8 + (f32) sp70;
                sp80 = (f64) sp30;
                sp18 = M2C_FIELD(temp_r4_190, f64 *, 0) * 5.7700341e-315;
                sp20 = temp_f3_194 * 5000.0f;
                sp8 = 1.0f;
                spC = 1.0f;
                sp10 = 1.0f;
                sp14 = 1.0f;
                sp58 = sp18;
                sp60 = (f64) sp20;
                sp48 = (f64) sp8;
                sp50 = (f64) sp10;
                temp_r3_236 = M2C_FIELD(temp_r3_187, void **, 0x178);
                M2C_FIELD(M2C_FIELD(temp_r3_236, void **, 0x44), M2C_UNK (**)(void *, f64 *, f64 *, f64 *, f32, f64, f64, f64), 0x3C)(temp_r3_236, &sp78, &sp58, &sp48, 3.0f, (f64) sp8, (f64) sp20, sp18);
            }
        }
    }
    temp_r29_242 = this->unk1FC;
    if (temp_r29_242 != 0) {
        var_r28_246 = 0;
loop_21:
        if (var_r28_246 < temp_r29_242) {
            temp_r4_252 = this->unk208;
            temp_r30_253 = this->unk1A8.GetSpawnPoint(var_r28_246);
            if (temp_r4_252 != -1U) {
                MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_252, &sp88);
                temp_r30_253->unk40 = M2C_BITWISE(f32, sp88);
                temp_r30_253->unk44 = sp88.unk4;
                temp_r30_253->unk48 = sp88.unk8;
                temp_r30_253->unk4C = 1.0f;
            }
            var_r28_246 += 1;
            goto loop_21;
        }
    }
}
#endif

#if 0 // DRAFT: function call 'checked_cast(void *)' does not match 'checked_cast<...>(T1 *)'
s32 BeetleNestSmall::LoadDone() {
    f64 sp20;
    f64 sp18;
    MKVector3 sp8;
    SpawnPointObject *temp_r3_316;
    s32 temp_r28_302;
    s32 var_r27_310;
    s32 var_r31_311;
    u32 temp_r4_338;
    void *temp_r30_320;
    void *temp_r3_331;

    ShatterWaypointSpawn::LoadDone();
    this->unk208 = (u32) Tools_GetMatchingRefPointIndex(this->unk4, "spawn");
    temp_r28_302 = this->unk1FC;
    this->unk1A8.unk30 = 0.0f;
    this->unk1A8.unk34 = 5.0f;
    this->unk1A8.unk4C |= 0x10;
    if (temp_r28_302 != 0) {
        var_r27_310 = 0;
        var_r31_311 = 0;
loop_5:
        if (var_r27_310 < temp_r28_302) {
            temp_r3_316 = this->unk1A8.GetSpawnPoint(var_r27_310);
            temp_r30_320 = checked_cast<EnemySpawnPointData *, SpawnPointData>(temp_r3_316->unk4);
            operator new(0x30U, NULL, 0);
            M2C_FIELD(temp_r30_320, KDPathSegment **, 0x1C) = (KDPathSegment *) M2C_ERROR(/* Read from unset register $r3 */);
            ((KDPathSegment *) (M2C_FIELD(temp_r30_320, KDPathSegment **, 0x1C)))->Init();
            temp_r3_331 = ((u8 *) this->unk1F8) + var_r31_311;
            sp18 = M2C_FIELD(temp_r3_331, f64 *, 0);
            sp20 = M2C_FIELD(temp_r3_331, f64 *, 8);
            ((KDPathSegment *) (M2C_FIELD(temp_r30_320, KDPathSegment **, 0x1C)))->CopyWaypointArray((MKVector3 *) &sp18, 1);
            temp_r4_338 = this->unk208;
            if (temp_r4_338 != -1U) {
                MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_338, &sp8);
                temp_r3_316->unk40 = M2C_BITWISE(f32, sp8);
                temp_r3_316->unk44 = sp8.unk4;
                temp_r3_316->unk48 = sp8.unk8;
                temp_r3_316->unk4C = 1.0f;
            }
            var_r27_310 += 1;
            var_r31_311 += 0x10;
            goto loop_5;
        }
    }
}
#endif

void BeetleNestSmall::Init() {
    ShatterWaypointSpawn::Init();
}

void BeetleNestSmallDescriptor::LoadDone() {
    ShatterableDescriptor::LoadDone();
    this->unk170 = (long) (((MKAnimScript *) this->unk34)->GetAnim("idle"));
    this->unk174 = (long) (((MKAnimScript *) this->unk34)->GetAnim("spawn"));
}

void BeetleNestSmallDescriptor::Init() {
    ShatterWaypointSpawnDescriptor::Init();
    this->unk174 = 0;
    this->unk170 = 0;
    this->unk178 = (long) (checked_cast<GoopFX *, MKProp>(gMK->CreateProp("GoopFX")));
}
