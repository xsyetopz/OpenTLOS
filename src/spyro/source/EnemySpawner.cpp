#include "spyro/source/EnemySpawner.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/SpawnPointData.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "unplaced_templates.h"
#include "spyro/source/DataMap.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

extern DataMap enemyTypeDataMap;
extern void **gb;

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void EnemySpawner::Message(MKMessage *arg0) {
    s32 temp_r0_62;

    temp_r0_62 = arg0->unk0;
    switch (temp_r0_62) {                           /* irregular */
    case 0xB5:
        if (!(this->unk18 & 0x80000000)) {
            PropFlagsSet((u32 *) &this->unk10, 0x80000U);
            this->unk90.FunctionOn();
        }
        break;
    case 0xB4:
        if (!(this->unk18 & 0x80000000)) {
            PropFlagsClear((u32 *) &this->unk10, 0x80000U);
            this->unk90.FunctionOff();
        }
        break;
    case 0xE0:
        this->unk90.KillAll();
        break;
    case 0x34:
        M2C_FIELD(checked_cast<GetSpawnerObjectMsg *, MKMessage>(arg0), SpawnerObject **, 8) = &this->unk90;
        break;
    default:
        this->unk90.SendMessageToActive(arg0);
        break;
    case 0xD5:
        this->unk90.DespawnAll();
        break;
    case 0x15F:
        this->unk90.DespawnAll();
        break;
    }
    MKProp::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void EnemySpawner::Update() {
    KDSynkerPlayer3 *temp_r3_165;
    u8 var_r31_162;
    void *temp_r30_164;

    MKProp::Update();
    if (this->unk10 & 0x80000) {
        var_r31_162 = 0;
        temp_r30_164 = M2C_FIELD(&gb, void **, 0xC);
        temp_r3_165 = M2C_FIELD(temp_r30_164, KDSynkerPlayer3 **, 0x78);
        if (((temp_r3_165 != NULL) && (temp_r3_165->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r30_164, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r30_164 + 0x24))->GetState() == 2))) {
            var_r31_162 = 1;
        }
        if (var_r31_162 != 0) {
            return;
        }
        if (this->unk90.IsSpawning() != 0) {
            this->unk90.TrySpawnItems(this->unkE0, 0U);
            return;
        }
        if (this->unk90.IsDying() != 0) {
            this->unk90.GetNumberActive();
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) <= 0) {
                PropFlagsClear((u32 *) &this->unk10, 0x80000U);
            }
        }
    }
}
#endif

void EnemySpawner::Reset() {
    MKProp::Reset();
    this->unk90.DespawnAll();
    this->unk90.SetDefaults();
}

#if 0 // DRAFT: function call 'PropFlagsClear(unsigned long *, unsigned int)' does not
void EnemySpawner::LoadDone() {
    MKProp::LoadDone();
    if (!(this->unk10 & 0x160000)) {
        PropFlagsClear((u32 *) &this->unk10, 0x80000U);
    }
    this->unk50.SetRotationPYR(MKProp::loadInfo + 0x50);
    this->unk50.unk30 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x40);
    this->unk50.unk34 = M2C_BITWISE(f32, MKProp::loadInfo.__vptr);
    this->unk50.unk38 = MKProp::loadInfo.unk48;
    this->unk50.unk3C = 1.0f;
    this->unk90.LoadDone((u32) this->unk18);
    this->unk90.AddSpawnPointBegin(this->unkE0);
}
#endif

#if 0 // DRAFT: function call 'PropFlagsLoadLine(unsigned long *, MKIniLine *)' does not
s32 EnemySpawner::LoadLine(MKIniLine *arg0) {
    if ((MKProp::LoadLine(arg0) != 0) || (PropFlagsLoadLine((u32 *) &this->unk10, arg0) != 0) || (arg0->LoadInt("iMaxSpawnPoints", &this->unkE0, 0) != 0) || (DataMap_LoadLine(arg0, "EnemyType", &enemyTypeDataMap, (u32 *) &this->unkE0) != 0) || (this->unk90.LoadLine(arg0) != 0)) {
        return 1;
    }
    return 0;
}
#endif

void EnemySpawner::Deinit() {
    MKProp::Deinit();
    this->unk90.Deinit();
}

#if 0 // DRAFT: undefined identifier 'EnemySpawnPool_Action'
void EnemySpawner::Init() {
    MKProp::Init();
    this->unk50.SetIdentity();
    this->unk8 = &this->unk50;
    this->unk10 |= 0x80000;
    this->unk90.Init(EnemySpawnPool_Action, 0);
}
#endif

void EnemySpawnerDescriptor::Deinit() {
    MKPropDescriptor::Deinit();
}

void EnemySpawnerDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
}

void EnemySpawnerDescriptor::Init() {
    MKPropDescriptor::Init();
    M2C_FIELD(this, f32 *, 0x60) = -10.0f;
    this->unk64 = 0.0f;
    this->unk68 = -10.0f;
    this->unk70 = 20.0f;
    this->unk74 = 20.0f;
    this->unk78 = 20.0f;
    this->unk1C = (BoundingVolume *) &this->unk60;
}

#if 0 // DRAFT: ')' expected
void SpawnPoint::Message(MKMessage *arg0) {
    s8 sp3A;
    s8 sp39;
    s8 sp38;
    s8 sp34;
    f32 sp30;
    f64 sp28;
    f64 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    f64 temp_f0_460;
    f64 temp_f2_458;
    s32 temp_r0_442;
    void *temp_r4_454;

    temp_r0_442 = arg0->unk0;
    switch (temp_r0_442) {                          /* irregular */
    case 0xAD:
        sp1C = 0;
        KDMath_GetYaw((Matrix *) &this->unk50.unk10);
        temp_r4_454 = this->unk8;
        temp_f2_458 = M2C_FIELD(temp_r4_454, f64 *, 0x30);
        temp_f0_460 = M2C_FIELD(temp_r4_454, f64 *, 0x38);
        sp38 = 0;
        sp18 = 0xE;
        sp20 = temp_f2_458;
        sp28 = temp_f0_460;
        sp30 = M2C_ERROR(/* Read from unset register $f1 */);
        sp34 = 0;
        sp39 = 1;
        sp3A = 1;
        sp38 = 1;
        sp8 = temp_f2_458;
        sp10 = temp_f0_460;
        M2C_FIELD(*gb, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK), 0x1C)(gb, &sp18, 0, 0xE);
        return;
    case 0x35:
        M2C_FIELD(checked_cast<GetSpawnPointObjectMsg *, MKMessage>(arg0), SpawnPointObject **, 8) = &this->unk50;
        return;
    default:
        MKProp::Message(arg0);
        return;
    }
}
#endif

void SpawnPoint::Resolve() {
    MKProp::Resolve();
    this->unk50.Resolve();
}

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void SpawnPoint::LoadDone() {
    MKProp::LoadDone();
    this->unk50.LoadDone();
    if ((u8) this->unk50.unk50 == 0) {
        M2C_STRUCT_COPY((s32) &this->unk50.unkC + 4, (s32) (&MKProp::loadInfo - 4) + 4, 0x40);
        this->unk8 = &this->unk50.unk10;
    }
}
#endif

s32 SpawnPoint::LoadLine(MKIniLine *arg0) {
    s32 var_r31_560;

    var_r31_560 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (this->unk50.LoadLine(arg0) != 0)) {
        var_r31_560 = 1;
    }
    return var_r31_560;
}

void SpawnPoint::Deinit() {
    this->unk50.Deinit();
    MKProp::Deinit();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SpawnPoint::Init() {
    SpawnPointData *temp_r31_612;

    MKProp::Init();
    operator new(0x28U, NULL, 0);
    temp_r31_612 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_612 != NULL) {
        temp_r31_612->__vptr = &__vt;
        temp_r31_612->__vptr = (struct __vt *) &__vt;
        M2C_FIELD(temp_r31_612, s32 *, 8) = 0;
        ((EventMessage *) (temp_r31_612 + 8))->Init();
        M2C_FIELD(temp_r31_612, s32 *, 0xC) = 0;
        ((EventMessage *) (temp_r31_612 + 0xC))->Init();
        M2C_FIELD(temp_r31_612, s32 *, 0x10) = 0;
        ((EventMessage *) (temp_r31_612 + 0x10))->Init();
        M2C_FIELD(temp_r31_612, s32 *, 0x14) = 0;
        ((EventMessage *) (temp_r31_612 + 0x14))->Init();
    }
    this->unk50.Init(temp_r31_612);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'KDSplinePathSegmentProp *' to
void EnemySpawnPointData::Resolve() {
    MKSceneManager *temp_r3_679;
    MKSceneManager *temp_r3_693;
    u32 temp_r3_683;
    u32 temp_r3_697;

    temp_r3_679 = this->unk20;
    if (temp_r3_679 != NULL) {
        temp_r3_683 = checked_cast<KDSplinePathSegmentProp *, MKProp>(temp_r3_679->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        if (temp_r3_683 != 0U) {
            this->unk20 = temp_r3_683 + 0x4C;
        } else {
            this->unk20 = NULL;
        }
    }
    temp_r3_693 = this->unk24;
    if (temp_r3_693 != NULL) {
        temp_r3_697 = checked_cast<CharacterGraphNodeProp *, MKProp>(temp_r3_693->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        if (temp_r3_697 != 0U) {
            this->unk24 = temp_r3_697 + 0x50;
            return;
        }
        this->unk24 = NULL;
    }
}
#endif

void EnemySpawnPointData::LoadDone() {
    KDPathSegment *temp_r3_722;
    KDSplinePathSegment *temp_r3_727;

    temp_r3_722 = this->unk1C;
    if (temp_r3_722 != NULL) {
        temp_r3_722->LoadDone();
    }
    temp_r3_727 = this->unk18;
    if (temp_r3_727 != NULL) {
        temp_r3_727->LoadDone();
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 EnemySpawnPointData::LoadLine(MKIniLine *arg0) {
    s32 var_r31_822;

    if (((KDPathSegment *) this->unk1C == NULL) && (arg0->IsField("wallpoints") != 0) && (arg0->GetNmbrOfSubLines() > 0)) {
        operator new(0x30U, NULL, 0);
        this->unk1C = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk1C->Init();
        this->unk1C->LoadWaypoints(arg0, "wallpoints");
        return 1;
    }
    if (((KDSplinePathSegment *) this->unk18 == NULL) && (arg0->IsField("waypoints") != 0) && (arg0->GetNmbrOfSubLines() > 0)) {
        operator new(0x48U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x30) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x34) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x38) = 0.0f;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x3C) = 0;
        }
        this->unk18 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk18->Init();
        this->unk18->unk44 = 0;
        this->unk18->LoadLine(arg0);
        return 1;
    }
    var_r31_822 = 0;
    if ((arg0->LoadInt("SpawnFlags", &this->unk4, 0) != 0) || (arg0->LoadInt("SpawnPathID", (s32 *) &this->unk20, 0) != 0) || (arg0->LoadInt("SpawnGraphID", (s32 *) &this->unk24, 0) != 0) || (this->unkC.LoadLine(arg0, "OnSpawn") != 0) || (this->unk10.LoadLine(arg0, "OnDespawn") != 0) || (this->unk8.LoadLine(arg0, "OnDeath") != 0) || (this->unk14.LoadLine(arg0, "OnSummon") != 0)) {
        var_r31_822 = 1;
    }
    return var_r31_822;
}
#endif

void EnemySpawnPointData::Deinit() {
    KDPathSegment *temp_r3_897;
    KDSplinePathSegment *temp_r3_904;

    temp_r3_897 = this->unk1C;
    if (temp_r3_897 != NULL) {
        temp_r3_897->Deinit();
        operator delete(this->unk1C);
    }
    temp_r3_904 = this->unk18;
    if (temp_r3_904 != NULL) {
        temp_r3_904->Deinit();
        operator delete(this->unk18);
    }
}

void EnemySpawnPointData::Init() {
    this->unk4 = 2;
    this->unk18 = NULL;
    this->unk1C = NULL;
    this->unk20 = NULL;
    this->unk24 = NULL;
}
