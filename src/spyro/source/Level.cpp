#include "spyro/source/Level.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKChunkSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKLevelChunk.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/AshesPS.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/Collectable.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/CustomMaterialUpdater.h"
#include "spyro/source/CutsceneSystem.h"
#include "spyro/source/DynamiteExplosion.h"
#include "spyro/source/EarthBreathWhirlWinds.h"
#include "spyro/source/ElectricSparks.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EnemyDeathFX.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/ExplosionWarpFX.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/FootStepFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/GemMagicFX.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeatDistortPS.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/LavaBubbleFX.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/Points.h"
#include "spyro/source/PuddleSplash.h"
#include "spyro/source/ScreenWobbleFX.h"
#include "spyro/source/ShotgunWarpFX.h"
#include "spyro/source/SlimeTrailFX.h"
#include "spyro/source/SparksPS.h"
#include "spyro/source/TriggerProp.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/WaterDripPS.h"
#include "spyro/source/ZapArcFX.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKGrass.h"
#include "common/Source/MKMat_MK2_Standard.h"
#include "common/Source/MKRumble.h"
#include "common/Source/MKShockWave_MP.h"
#include "common/Source/MKView.h"
#include "common/Source/MKWind.h"
#include "common/Source/OmniLight.h"
#include "common/Source/Str.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKModel_GC.h"
#include "common/gc/MKView_GC.h"
#include "common/gc/System_GC.h"
#include "spyro/source/Autosave.h"
#include "spyro/source/DataMap.h"
#include "spyro/source/EnemySpawnPool.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/GameConsole.h"
#include "spyro/source/Hud.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Music.h"
#include "spyro/source/Names.h"
#include "spyro/source/PauseMenu.h"
#include "spyro/source/PhrasePlayer.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Tools.h"
#include "spyro/source/UIObject.h"
#include <m2c_macros.h>

s32 *__construct_new_array();                       /* extern */
s32 atoi(s8 *);                                     /* extern */
M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(s32);                                /* extern */
s32 sscanf(s8 *, s8 *, f32 *, Level *);             /* extern */
s32 stricmp(Level *, s8 *);                         /* extern */
extern s32 BONE_BLUR_FX_NODE_POOL_MAX_ALLOCS;
extern s32 BONE_BLUR_FX_NODE_POOL_MAX_NODES;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern CutsceneSystem cutsceneSys;
extern DataMap enemyTypeDataMap;
extern s8 gAssertBool;
#if 0 // DRAFT: undefined identifier 'Pool'
extern Pool<BoneBlurFX::BlurNode> gBoneBlurFXPool;
#endif
extern M2C_UNK gCreationTable;
extern MKHeap gEmptyPtrListDL;
extern GameStateMachine gGMState;
extern GlowingPropManager gGlowingPropManager;
extern void **gMK;
#if 0 // DRAFT: identifier 'gMKDefaults' redeclared
extern M2C_UNK gMKDefaults;
#endif
#if 0 // DRAFT: identifier 'gb' redeclared
extern void **gb;
#endif
extern ChunkInfo *pChunkChooser_TempChunkInfo;
extern s32 *pChunkData;
extern ChunkInfo *pLoadChunkInfo;
extern s8 *platformCode;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'DataMap'
static M2C_UNK pChunkPropQueue;                     /* unable to generate initializer: unknown type */
static M2C_UNK defaultLights;                       /* unable to generate initializer: unknown type */
static M2C_UNK defaultWind;                         /* unable to generate initializer: unknown type */
static M2C_UNK pSpawnerNames;                       /* unable to generate initializer: unknown type */
static DataMap customMaterialUpdaterMap;            /* unable to generate initializer: confusing struct layout */
static s8 *pGlobalLevelName = .L_803582BE;
#endif
#if 0 // DRAFT: identifier 'pGlobalLV3Name' redeclared
static Level *pGlobalLV3Name = &.L_803582C9;
#endif
#if 0 // DRAFT: identifier 'pGlobalModelName' redeclared
static s8 *pGlobalModelName = .L_803582CF;
#endif
#if 0 // DRAFT: declaration syntax error
static M2C_UNK defaultClip;                         /* unable to generate initializer: unknown type */

static s8 .L_803582BE[0xB] = { 0x6C, 0x65, 0x76, 0x65, 0x6C, 0x73, 0x2E, 0x69, 0x6E, 0x69, 0 }; /* const */
static Level .L_803582C9;                           /* type too large by 0xEA; unable to generate initializer: confusing struct layout; const */
static s8 .L_803582CF[0xD] = { 0x67, 0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x2E, 0x6D, 0x6F, 0x64, 0x65, 0x6C, 0 }; /* const */

void ChunkProp::Message(MKMessage *arg0) {
    s32 temp_r0_77;

    temp_r0_77 = arg0->unk0;
    switch (temp_r0_77) {                           /* irregular */
    case 46:
        if ((s32) M2C_FIELD(&gb, s32 *, 0x340) == 0) {
            this->unk4C.Send((MKProp *) this);
        }
        break;
    case 47:
        if ((s32) M2C_FIELD(&gb, s32 *, 0x340) == 0) {
            this->unk50.Send((MKProp *) this);
        }
        break;
    }
    MKProp::Message(arg0);
}
#endif

void ChunkProp::LoadDone() {
    MKProp::LoadDone();
    Disable();
}

s32 ChunkProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_144;

    var_r31_144 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (this->unk4C.LoadLine(arg0, "") != 0) || (this->unk50.LoadLine(arg0, "") != 0)) {
        var_r31_144 = 1;
    }
    return var_r31_144;
}

#if 0 // DRAFT: illegal operand
void ChunkProp::Deinit() {
    s32 var_ctr_188;
    s32 var_r4_181;
    void *temp_r3_203;

    var_r4_181 = 0;
    var_ctr_188 = 3;
    do {
        if ((u32) *(&pChunkPropQueue + var_r4_181) == this) {
            *(&pChunkPropQueue + var_r4_181) = 0;
        }
        var_r4_181 += 4;
        var_ctr_188 -= 1;
    } while (var_ctr_188 != 0);
    temp_r3_203 = M2C_FIELD(M2C_FIELD(M2C_FIELD(*gMK, void *(**)(void **), 0x7C)(gMK), void **, 0xC), void **, 4);
    if ((u32) M2C_FIELD(temp_r3_203, u32 *, 0x1C) == this) {
        M2C_FIELD(temp_r3_203, u32 *, 0x1C) = 0U;
    }
    MKProp::Deinit();
}
#endif

void ChunkProp::Init() {
    MKProp::Init();
    M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(*gMK, void *(**)(void **), 0x7C)(gMK), void **, 0xC), void **, 4), ChunkProp **, 0x1C) = this;
}

#if 0 // DRAFT: function call 'MKModel_RefPointExists(MKModel *, const char[1], long *)'
void Level::EnvDomeChanged() {
    s32 sp8;
    MKModel *temp_r30_253;
    MKModel *temp_r3_251;
    s32 temp_cr0_eq_253;
    s32 temp_r3_276;
    u8 temp_r31_268;
    u8 var_r31_255;

    temp_r3_251 = GetEnvDome();
    temp_r30_253 = temp_r3_251;
    temp_cr0_eq_253 = temp_r30_253 == NULL;
    sp8 = -1;
    var_r31_255 = 0;
    if ((temp_cr0_eq_253 == 0) && (MKModel_RefPointExists(temp_r3_251, "", &sp8) != 0)) {
        var_r31_255 = 1;
    }
    temp_r31_268 = var_r31_255 != 0;
    if (temp_r31_268 != 0) {
        MKModel_CalculateRefPointWorldPosition(temp_r30_253, sp8, &this->unk58);
    }
    temp_r3_276 = this->unk68;
    if ((u32) temp_r3_276 != 0U) {
        M2C_FIELD(temp_r3_276, u8 *, 0x98) = temp_r31_268;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'levelInfoCount'
void *Level::GetStartLevelInfo() {
    s32 var_ctr_294;
    s32 var_r3_292;

    var_r3_292 = 0;
    var_ctr_294 = levelInfoCount;
    if ((s32) levelInfoCount > 0) {
loop_1:
        if ((u8) *(pLevelInfo + (var_r3_292 + 0x19)) != 0) {
            return pLevelInfo + var_r3_292;
        }
        var_r3_292 += 0x128;
        var_ctr_294 -= 1;
        if (var_ctr_294 == 0) {
            /* Duplicate return node #4. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_1;
    }
    return NULL;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'Level' to
void Level::CancelQueue() {
    s32 temp_r29_326;
    s32 var_r28_321;
    s32 var_r31_322;

    var_r28_321 = 0;
    var_r31_322 = 0;
    this->unk1C = 0;
loop_2:
    if (var_r28_321 < (s32) this->unkAC) {
        temp_r29_326 = var_r31_322 + 0x7C;
        ((ChunkInfo *) (*(this + temp_r29_326)))->Dequeue();
        *(this + temp_r29_326) = 0;
        var_r28_321 += 1;
        var_r31_322 += 8;
        goto loop_2;
    }
    this->unkAC = 0;
}
#endif

#if 0 // DRAFT: illegal operand
void Level::EnableChunksForLevel(ChunkInfo *arg0) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKLevelChunk *temp_r3_396;
    MKLevelChunk *temp_r3_420;
    MKLevelChunk *temp_r3_428;
    s32 var_r29_359;
    u8 var_r31_369;
    void **var_r30_360;
    void *temp_r28_364;
    void *temp_r4_365;

    var_r29_359 = 0;
    var_r30_360 = M2C_FIELD(*gMK, void **(**)(void **), 0x2C)(gMK);
loop_15:
    if (var_r29_359 < (s32) this->unk78) {
        temp_r28_364 = M2C_FIELD(*var_r30_360, void **, 0xC);
        temp_r4_365 = M2C_FIELD(temp_r28_364, void **, 4);
        if (temp_r4_365 != NULL) {
            var_r31_369 = 0;
            if (((u32) M2C_FIELD(temp_r4_365, u32 *, 4) == (void *) arg0->unk4) || ((s32) M2C_FIELD(temp_r28_364, s32 *, 0) == 0)) {
                var_r31_369 = 1;
            }
            if ((var_r31_369 == 0) && (M2C_FIELD(temp_r4_365, MKLevelChunk **, 0x5C)->unk134 & 2)) {
                sp14 = 0;
                sp10 = 0x2C;
                temp_r3_396 = M2C_FIELD(M2C_FIELD(temp_r28_364, void **, 4), MKLevelChunk **, 0x5C);
                M2C_FIELD(temp_r3_396->unk8, M2C_UNK (**)(MKLevelChunk *, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x3C)(temp_r3_396, &sp10, 0, 1, 0, 1, 0.0f);
            } else if ((var_r31_369 != 0) && !(M2C_FIELD(temp_r4_365, MKLevelChunk **, 0x5C)->unk134 & 2)) {
                spC = 0;
                sp8 = 0x2D;
                temp_r3_420 = M2C_FIELD(M2C_FIELD(temp_r28_364, void **, 4), MKLevelChunk **, 0x5C);
                M2C_FIELD(temp_r3_420->unk8, M2C_UNK (**)(MKLevelChunk *, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x3C)(temp_r3_420, &sp8, 0, 1, 0, 1, 0.0f);
            }
            temp_r3_428 = M2C_FIELD(M2C_FIELD(temp_r28_364, void **, 4), MKLevelChunk **, 0x5C);
            if (var_r31_369 != 0) {
                temp_r3_428->ApplyFlags(7U);
            } else {
                temp_r3_428->ApplyFlags(0U);
            }
        }
        var_r30_360 += 4;
        var_r29_359 += 1;
        goto loop_15;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk84'
u8 Level::GetNextInQueue(QueueInfo *arg0, bool arg1) {
    arg0->unk0 = NULL;
    arg0->unk4 = -1;
    if ((s32) this->unkAC > 0) {
        arg0->unk0 = this->unk7C;
        arg0->unk4 = this->unk80;
        if (arg1 != 0) {
            memcpy(&this->unk7C, &this->unk84, 0x28U);
            this->unkAC -= 1;
            arg0->unk0->Dequeue();
        }
    }
    return arg0->unk0 != NULL;
}
#endif

#if 0 // DRAFT: illegal operand
MKHeap *Level::AddChunkToQueue(ChunkInfo *arg0, int arg1) {
    ChunkInfo *temp_r3_516;
    s32 temp_r0_508;
    s32 temp_r3_520;
    s32 var_ctr_511;
    s32 var_r27_509;
    s32 var_r4_510;
    void *temp_r28_515;

    if ((u32) this->unk1C == arg0) {
        return NULL;
    }
    temp_r0_508 = this->unkAC;
    var_r27_509 = 0;
    var_r4_510 = 0;
    var_ctr_511 = temp_r0_508;
    if (temp_r0_508 > 0) {
loop_3:
        temp_r28_515 = this + var_r4_510;
        temp_r3_516 = M2C_FIELD(temp_r28_515, ChunkInfo **, 0x7C);
        if (temp_r3_516 == arg0) {
            temp_r3_516->Dequeue();
            temp_r3_520 = this->unkAC;
            if (var_r27_509 < (s32) (temp_r3_520 - 1)) {
                memcpy(temp_r28_515 + 0x7C, this + (((var_r27_509 + 1) * 8) + 0x7C), ((temp_r3_520 - var_r27_509) - 1) * 8);
            }
            this->unkAC -= 1;
        } else {
            var_r27_509 += 1;
            var_r4_510 += 8;
            var_ctr_511 -= 1;
            if (var_ctr_511 != 0) {
                goto loop_3;
            }
        }
    }
    M2C_FIELD((this + (this->unkAC * 8)), ChunkInfo **, 0x7C) = arg0;
    M2C_FIELD((this + (this->unkAC * 8)), s32 *, 0x80) = arg1;
    this->unkAC += 1;
    arg0->Queue();
    return (MKHeap *)1;
}
#endif

void Level::DOFGetPlanes(float *arg0, float *arg1, float *arg2, float *arg3) {
    if (arg0 != NULL) {
        *arg0 = this->unkE8;
    }
    if (arg1 != NULL) {
        *arg1 = this->unkE0;
    }
    if (arg2 != NULL) {
        *arg2 = M2C_FIELD(this, f32 *, 0xE4);
    }
    if (arg3 != NULL) {
        *arg3 = this->unkEC;
    }
}

void Level::DOFSetPlanes(float arg0, float arg1, float arg2, float arg3) {
    this->unkE8 = arg0;
    this->unkE0 = arg1;
    M2C_FIELD(this, f32 *, 0xE4) = arg2;
    this->unkEC = arg3;
}

void Level::DOFApplyEffect() {

}

MKModel *Level::GetEnvDome() {
    MKModel *temp_r3_614;
    MKModel *var_r31_620;
    s32 temp_r3_619;
    s32 temp_r3_644;
    s32 temp_r3_658;
    void *var_r3_623;
    void *var_r3_647;
    void *var_r3_661;

    temp_r3_614 = this->unk30;
    if (temp_r3_614 != NULL) {
        return temp_r3_614;
    }
    temp_r3_619 = this->unk18;
    var_r31_620 = NULL;
    if ((u32) temp_r3_619 != 0U) {
        var_r3_623 = M2C_FIELD(temp_r3_619, void **, 4);
    } else {
        var_r3_623 = M2C_FIELD(this->unk24, void **, 4);
    }
    if ((u32) M2C_FIELD(var_r3_623, u32 *, 0x118) == 0U) {
        return NULL;
    }
    if (M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), u8 (**)(void *), 0x58)(M2C_FIELD(&gb, void **, 0x3B8)) != 0) {
        temp_r3_644 = this->unk18;
        if ((u32) temp_r3_644 != 0U) {
            var_r3_647 = M2C_FIELD(temp_r3_644, void **, 4);
        } else {
            var_r3_647 = M2C_FIELD(this->unk24, void **, 4);
        }
        var_r31_620 = M2C_FIELD(M2C_FIELD(var_r3_647, void **, 0x118), MKModel **, 0x44);
    }
    if (var_r31_620 == NULL) {
        temp_r3_658 = this->unk18;
        if ((u32) temp_r3_658 != 0U) {
            var_r3_661 = M2C_FIELD(temp_r3_658, void **, 4);
        } else {
            var_r3_661 = M2C_FIELD(this->unk24, void **, 4);
        }
        var_r31_620 = M2C_FIELD(M2C_FIELD(var_r3_661, void **, 0x118), MKModel **, 0x40);
    }
    return var_r31_620;
}

#if 0 // DRAFT: undefined identifier 'levelInfoCount'
void *Level::GetLevelByName(const char *arg0) {
    s32 var_r30_694;
    s32 var_r31_695;

    var_r30_694 = 0;
    var_r31_695 = 0;
loop_4:
    if (var_r30_694 >= (s32) levelInfoCount) {
        return NULL;
    }
    if (stricmp(this, *(pLevelInfo + (var_r31_695 + 4))) == 0) {
        return pLevelInfo + var_r31_695;
    }
    var_r30_694 += 1;
    var_r31_695 += 0x128;
    goto loop_4;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'ChunkInfo *' to
void Level::SwitchTo(ChunkInfo *arg0) {
    M2C_FIELD(this, s8 *, 0x6C) = 1;
    this->unk70 = 7e-45f;
    if (((u32) this->unk18 == 0U) && ((u32) this->unk24 == 0U)) {
        if (arg0 != NULL) {
            pLoadChunkInfo = arg0;
            gGMState.SwitchState(6, 1, 0U);
            return;
        }
        FrontEnd_GotoMainMenu();
        return;
    }
    this->unk74 = M2C_BITWISE(f32, arg0);
}
#endif

#if 0 // DRAFT: illegal operand
void Level::SetEnvChunk(ChunkInfo *arg0) {
    s32 temp_r3_771;
    s32 temp_r3_799;
    s32 temp_r4_806;

    temp_r3_771 = this->unk18;
    if (arg0 == (u32) temp_r3_771) {
        if (arg0 != NULL) {
            arg0->Use();
        }
    } else {
        if ((arg0 != NULL) && (((u32) temp_r3_771 == 0U) || ((u32) M2C_FIELD(temp_r3_771, u32 *, 4) != (void *) arg0->unk4))) {
            KDSound_SetLevelID(M2C_FIELD(arg0->unk4, s8 **, 4));
            EnableChunksForLevel(arg0);
            EnvDomeChanged();
        }
        this->unk18 = (s32) arg0;
        temp_r3_799 = this->unk18;
        if ((u32) temp_r3_799 != 0U) {
            temp_r3_799->Use();
        }
        if (arg0 != NULL) {
            temp_r4_806 = arg0->unk20;
            if (temp_r4_806 != -1) {
                KDSound_SetSFXLimit(1U, temp_r4_806);
                return;
            }
        }
        KDSound_SetSFXLimit(0U, 0);
    }
}
#endif

#if 0 // DRAFT: illegal operand
void Level::LoadChunk(ChunkInfo *arg0, int arg1) {
    s32 temp_r9_844;
    u8 var_r7_850;

    this->unk1C = (u32) arg0;
    this->unk20 = arg1;
    if ((s32) arg0->unkC == 2) {
        arg0->Load(NULL, 0, 1U, 1U);
        return;
    }
    temp_r9_844 = this->unk18;
    var_r7_850 = 0;
    if (((u32) temp_r9_844 != 0U) && ((void *) arg0->unk4 == (u32) M2C_FIELD(temp_r9_844, u32 *, 4))) {
        var_r7_850 = 1;
    }
    arg0->Load(NULL, 0, 1U, var_r7_850);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 Level::SetDesiredChunks(ChunkInfo **arg0, int arg1) {
    ChunkInfo *temp_r3_913;
    ChunkInfo *temp_r3_958;
    MKHeap *temp_r3_1024;
    MKHeap *temp_r3_877;
    MKHeap *var_r3_885;
    s32 temp_r25_897;
    s32 temp_r31_951;
    s32 var_r20_891;
    s32 var_r20_908;
    s32 var_r20_953;
    s32 var_r21_907;
    s32 var_r21_929;
    s32 var_r25_952;
    s32 var_r26_894;
    s32 var_r26_946;
    s32 var_r27_941;
    s32 var_r29_876;
    s32 var_r30_928;
    s32 var_r3_986;
    s32 var_r4_985;
    u32 temp_r3_935;
    void *temp_r5_957;

    var_r29_876 = 1;
    temp_r3_877 = MKHeap::Current();
    if (temp_r3_877 != NULL) {
        var_r3_885 = ((MKHeap *) (temp_r3_877->Main()))->TAlloc(arg1 * 4, NULL, 0, 0U);
    } else {
        var_r3_885 = malloc(arg1 * 4);
    }
    var_r20_891 = 0;
    var_r26_894 = 0;
loop_5:
    if (var_r26_894 < (s32) this->unkAC) {
        temp_r25_897 = var_r20_891 + 0x7C;
        ((ChunkInfo *) (*(this + temp_r25_897)))->Dequeue();
        *(this + temp_r25_897) = 0;
        var_r26_894 += 1;
        var_r20_891 += 8;
        goto loop_5;
    }
    var_r21_907 = 0;
    var_r20_908 = 0;
    this->unkAC = 0;
loop_11:
    if (var_r21_907 < arg1) {
        temp_r3_913 = *(arg0 + var_r20_908);
        if ((u32) this->unk1C == temp_r3_913) {
            *(var_r3_885 + var_r20_908) = this->unk20;
        } else {
            *(var_r3_885 + var_r20_908) = Level_ChunkInMemory(temp_r3_913);
        }
        var_r21_907 += 1;
        var_r20_908 += 4;
        goto loop_11;
    }
    var_r30_928 = 0;
    var_r21_929 = 0;
loop_38:
    if (var_r30_928 < arg1) {
        if ((s32) *(var_r3_885 + var_r21_929) < 0) {
            temp_r3_935 = this->unk1C;
            var_r29_876 = 0;
            if (temp_r3_935 != (u32) *(arg0 + var_r21_929)) {
                var_r27_941 = -1;
                if (temp_r3_935 != 0) {
                    var_r27_941 = this->unk20;
                }
                var_r26_946 = -1;
                temp_r31_951 = M2C_FIELD(*gMK, s32 (**)(void **), 0x2C)(gMK);
                var_r25_952 = 0;
                var_r20_953 = 0;
loop_35:
                if ((var_r25_952 < (s32) this->unk78) && (var_r26_946 < 0)) {
                    temp_r5_957 = M2C_FIELD(*(temp_r31_951 + var_r20_953), void **, 0xC);
                    temp_r3_958 = M2C_FIELD(temp_r5_957, ChunkInfo **, 4);
                    if (temp_r3_958 != NULL) {
                        if (((s32) M2C_FIELD(temp_r5_957, s32 *, 0) == (s32) M2C_FIELD(*(arg0 + var_r21_929), s32 *, 0xC)) && (Level_IsChunkInList(temp_r3_958, arg0, arg1) == 0)) {
                            var_r26_946 = var_r25_952;
                        }
                    } else if ((s32) M2C_FIELD(temp_r5_957, s32 *, 0) == (s32) M2C_FIELD(*(arg0 + var_r21_929), s32 *, 0xC)) {
                        var_r26_946 = var_r25_952;
                    }
                    if (var_r26_946 == var_r27_941) {
                        var_r26_946 = -1;
                    }
                    var_r4_985 = 0;
                    var_r3_986 = 0;
loop_30:
                    if ((var_r4_985 < arg1) && (var_r26_946 > -1)) {
                        if (var_r26_946 == (s32) *(var_r3_885 + var_r3_986)) {
                            var_r26_946 = -1;
                        }
                        var_r4_985 += 1;
                        var_r3_986 += 4;
                        goto loop_30;
                    }
                    if (var_r26_946 > -1) {
                        *(var_r3_885 + var_r21_929) = var_r26_946;
                        AddChunkToQueue(*(arg0 + var_r21_929), var_r26_946);
                    }
                    var_r25_952 += 1;
                    var_r20_953 += 4;
                    goto loop_35;
                }
            }
        }
        var_r30_928 += 1;
        var_r21_929 += 4;
        goto loop_38;
    }
    temp_r3_1024 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1024 != NULL) {
        ((MKHeap *) (temp_r3_1024->Main()))->TFree(var_r3_885, NULL, 0);
    } else {
        free(var_r3_885);
    }
    return var_r29_876;
}
#endif

#if 0 // DRAFT: illegal operand
u8 Level_IsChunkInList(ChunkInfo *arg0, ChunkInfo **arg1, int arg2) {
    s32 var_ctr_1049;
    s32 var_r6_1048;

    var_r6_1048 = 0;
    var_ctr_1049 = arg2;
    if (arg2 > 0) {
loop_1:
        if (arg0 == (u32) *(arg1 + var_r6_1048)) {
            return 1U;
        }
        var_r6_1048 += 4;
        var_ctr_1049 -= 1;
        if (var_ctr_1049 == 0) {
            /* Duplicate return node #4. Try simplifying control flow for better match */
            return 0U;
        }
        goto loop_1;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: type mismatch
MKHeap *Level_ChunkInMemory(ChunkInfo *arg0) {
    MKHeap *var_r7_1080;
    s32 temp_r3_1078;
    s32 var_r4_1082;
    void *temp_r5_1087;

    temp_r3_1078 = M2C_FIELD(*gMK, s32 (**)(void **), 0x2C)(gMK);
    var_r7_1080 = NULL;
    var_r4_1082 = 0;
loop_5:
    if (var_r7_1080 >= (s32) M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), s32 *, 0x78)) {
        return (MKHeap *)-1;
    }
    temp_r5_1087 = M2C_FIELD(*(temp_r3_1078 + var_r4_1082), void **, 0xC);
    if ((temp_r5_1087 != NULL) && ((u32) M2C_FIELD(temp_r5_1087, u32 *, 4) == arg0)) {
        return var_r7_1080;
    }
    var_r7_1080 += 1;
    var_r4_1082 += 4;
    goto loop_5;
}
#endif

#if 0 // DRAFT: undefined identifier 'pChunkInfo'
Level *Level::GetNextChunk(ChunkInfo *arg0) {
    Level *temp_r0_1123;
    Level *var_r4_1117;
    void *temp_r3_1129;
    void *temp_r3_1150;
    void *var_r0_1132;
    void *var_r3_1141;

    var_r4_1117 = NULL;
    if (this == NULL) {
        var_r4_1117 = pChunkInfo;
    } else {
        temp_r0_1123 = M2C_FIELD(this, Level **, 8);
        if (temp_r0_1123 != NULL) {
            var_r4_1117 = temp_r0_1123;
        } else {
            temp_r3_1129 = this->unk4;
            if (temp_r3_1129 != NULL) {
                var_r0_1132 = M2C_FIELD(temp_r3_1129, void **, 0x124);
            } else {
                var_r0_1132 = pLevelInfo;
            }
            if (var_r0_1132 != NULL) {
                if (temp_r3_1129 != NULL) {
                    var_r3_1141 = M2C_FIELD(temp_r3_1129, void **, 0x124);
                } else {
                    var_r3_1141 = pLevelInfo;
                }
                var_r4_1117 = M2C_FIELD(var_r3_1141, Level **, 0x11C);
            }
        }
    }
    if (var_r4_1117 != NULL) {
        temp_r3_1150 = var_r4_1117->unk4;
        if ((temp_r3_1150 != NULL) && (var_r4_1117 == (u32) M2C_FIELD(temp_r3_1150, u32 *, 0x118))) {
            var_r4_1117 = var_r4_1117->GetNextChunk((ChunkInfo *) var_r4_1117);
        }
    }
    return var_r4_1117;
}
#endif

#if 0 // DRAFT: undefined identifier 'chunkInfoCount'
void *Level::GetChunkByName(const char *arg0) {
    s32 var_r30_1175;
    s32 var_r31_1176;

    var_r30_1175 = 0;
    var_r31_1176 = 0;
loop_5:
    if (var_r30_1175 >= (s32) chunkInfoCount) {
        return NULL;
    }
    if (((u32) *(pChunkInfo + var_r31_1176) != 0U) && (stricmp(this) == 0)) {
        return pChunkInfo + var_r31_1176;
    }
    var_r30_1175 += 1;
    var_r31_1176 += 0x64;
    goto loop_5;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[1]' to
void Level::ResolveGameSpecificProps() {
    s32 var_r28_1225;
    s32 var_r31_1228;

    var_r28_1225 = 0;
    M2C_FIELD(&gb, s32 *, 0x60) = checked_cast<FootStepFX *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *), 0x60)(gMK, ""));
    var_r31_1228 = 0;
    do {
        var_r28_1225 += 1;
        M2C_FIELD((&gb + var_r31_1228), s32 *, 0x10) = checked_cast<CollectableSpawner *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s32), 0x60)(gMK, *(&pSpawnerNames + var_r31_1228)));
        var_r31_1228 += 4;
    } while (var_r28_1225 < 4);
    M2C_FIELD(&gb, s32 *, 0x64) = checked_cast<Coronas *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *), 0x60)(gMK, ""));
    M2C_FIELD(&gb, s32 *, 0x80) = checked_cast<LightManager *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x68) = checked_cast<CrashFirePS *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x6C) = checked_cast<WaterDripPS *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x74) = checked_cast<EmbersPS *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x78) = checked_cast<KDEnvParticleSystem *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x7C) = checked_cast<KDEnvParticleSystem *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x84) = checked_cast<SparksPS *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x88) = checked_cast<AshesPS *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x90) = checked_cast<LavaBubbleFX *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x8C) = checked_cast<KDEnvParticleSystem *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x94) = checked_cast<ZapArcFX *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x98) = checked_cast<EnemyDeathFX *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x9C) = checked_cast<FlyingChunkPS *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0xA0) = checked_cast<FlyingChunkPS *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0xA4) = checked_cast<FlyingChunkPS *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0xA8) = checked_cast<FlyingChunkPS *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0xAC) = checked_cast<FlyingChunkPS *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0xB0) = checked_cast<FlyingChunkPS *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0xB4) = checked_cast<FlyingChunkPS *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x230) = checked_cast<ElectricSparks *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x234) = checked_cast<FallingLeaves *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x238) = checked_cast<GemMagicFX *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x2A0) = checked_cast<KDEnvParticleSystem *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x2B4) = checked_cast<KDEnvParticleSystem *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x2A4) = checked_cast<KDEnvParticleSystem *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x2F4) = checked_cast<DynamiteExplosion *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x2C0) = checked_cast<Explosion4 *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x2C8) = checked_cast<EarthBreathWhirlWinds *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x2AC) = checked_cast<BoneBlurFXDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, s8 *, void ***), 0x5C)(gMK, "", &gb));
    M2C_FIELD(&gb, s32 *, 0x70) = checked_cast<PuddleSplash *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, s8 *, void ***), 0x60)(gMK, "", &gb));
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void *' to
void Level::ApplyViewParameters() {
    s32 temp_r3_1630;
    u8 var_r3_1649;
    void *var_r3_1633;

    temp_r3_1630 = this->unk18;
    if ((u32) temp_r3_1630 != 0U) {
        var_r3_1633 = M2C_FIELD(temp_r3_1630, void **, 4);
    } else {
        var_r3_1633 = M2C_FIELD(this->unk24, void **, 4);
    }
    M2C_FIELD(gMK, f32 *, 4) = (f32) (this->unk2C * M2C_FIELD(var_r3_1633, f32 *, 0xF8));
    MKView_SetProjection(this->unkC, M2C_FIELD(this, f32 *, 0), M2C_BITWISE(f32, this->unk4));
    var_r3_1649 = 0;
    if ((this->unkB0 != 0.0f) || (this->unkB4 != 0.0f)) {
        var_r3_1649 = 1;
    }
    MKMaterial_EnableFog(var_r3_1649);
    MKMaterial_SetFogColor(this->unkB8);
    MKMaterial_SetFogPlanes(this->unkB0, this->unkB4);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void Level::SetProjectionToDefaults() {
    s32 temp_r4_1681;
    s32 temp_r4_1692;
    void *var_r4_1684;
    void *var_r4_1695;

    this->unkC = 1.0471976f;
    this->unk10 = 50.0f;
    this->unk14 = 2000000.0f;
    temp_r4_1681 = this->unk18;
    if ((u32) temp_r4_1681 != 0U) {
        var_r4_1684 = M2C_FIELD(temp_r4_1681, void **, 4);
    } else {
        var_r4_1684 = M2C_FIELD(this->unk24, void **, 4);
    }
    M2C_FIELD(this, f32 *, 0) = (f32) M2C_FIELD(var_r4_1684, f32 *, 0xB0);
    temp_r4_1692 = this->unk18;
    if ((u32) temp_r4_1692 != 0U) {
        var_r4_1695 = M2C_FIELD(temp_r4_1692, void **, 4);
    } else {
        var_r4_1695 = M2C_FIELD(this->unk24, void **, 4);
    }
    this->unk4 = M2C_FIELD(var_r4_1695, f32 *, 0xB4);
}
#endif

void Level::FreeTempMemory() {

}

void Level::FreeGlobalResources() {
    Autosave_FreeResources();
    Names_DeinitModule();
}

void Level::LoadGlobalResources() {
    cutsceneSys.Init();
    Names_InitModule();
    Autosave_LoadResources();
}

#if 0 // DRAFT: illegal explicit conversion from 'GameGlobals' to
void Level::FinaliseResources() {
    s32 spC;
    s32 sp8;
    s32 var_r26_1763;
    s32 var_r31_1760;
    void *temp_r3_1768;

    if ((void **) gb != NULL) {
        M2C_FIELD(*gb, M2C_UNK (**)(), 0x14)();
    }
    var_r31_1760 = 0;
    var_r26_1763 = 0;
    do {
        temp_r3_1768 = *(&pChunkPropQueue + var_r31_1760);
        if (temp_r3_1768 != NULL) {
            spC = 0;
            sp8 = 0x2E;
            M2C_FIELD(M2C_FIELD(temp_r3_1768, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
        var_r26_1763 += 1;
        *(&pChunkPropQueue + var_r31_1760) = 0;
        var_r31_1760 += 4;
    } while (var_r26_1763 < 3);
}
#endif

#if 0 // DRAFT: function call 'stricmp(unsigned char[4])' does not match
void Level::ResolveGameProps(const char *arg0) {
    if (stricmp(pGlobalLV3Name) == 0) {
        ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->ResolveGameSpecificProps();
    }
}
#endif

#if 0 // DRAFT: illegal type
void Level::CreateNormalResources() {
    MKHeap *temp_r3_2122;
    MKHeap *temp_r3_2127;
    MKHeap *temp_r3_2145;
    MKHeap *temp_r3_2217;
    MKHeap *temp_r3_2230;
    MKHeap *temp_r3_2245;
    MKHeap *temp_r5_2159;
    MKHeap *var_r3_2135;
    MKHeap *var_r3_2153;
    MKHeap *var_r3_2252;
    s32 *temp_r3_1961;
    s32 temp_r0_2027;
    s32 temp_r0_2177;
    s32 temp_r10_1988;
    s32 temp_r11_2083;
    s32 temp_r26_1944;
    s32 temp_r26_2126;
    s32 temp_r26_2144;
    s32 temp_r30_1924;
    s32 temp_r3_1847;
    s32 temp_r3_1860;
    s32 temp_r3_1877;
    s32 temp_r3_1891;
    s32 temp_r3_1903;
    s32 temp_r3_1984;
    s32 temp_r3_2259;
    s32 temp_r4_2165;
    s32 temp_r5_1823;
    s32 temp_r5_2100;
    s32 temp_r8_2035;
    s32 temp_r8_2054;
    s32 temp_r8_2073;
    s32 var_ctr_1980;
    s32 var_r25_1844;
    s32 var_r25_2200;
    s32 var_r27_1845;
    s32 var_r27_2202;
    s32 var_r3_2162;
    s32 var_r4_1965;
    s32 var_r6_2015;
    s32 var_r6_2161;
    void (*var_r3_2199)(MKModel *, u16 *, void *);
    void *temp_r3_2205;
    void *temp_r5_2033;
    void *temp_r9_1992;
    void *var_r0_1850;
    void *var_r0_1863;
    void *var_r12_2038;
    void *var_r12_2057;
    void *var_r3_1835;
    void *var_r3_1880;
    void *var_r3_1894;
    void *var_r3_1906;
    void *var_r4_1826;
    void *var_r4_2103;
    void *var_r5_2020;
    void *var_r8_2076;
    temp_r5_1823 = this->unk18;
    if ((u32) temp_r5_1823 != 0U) {
        var_r4_1826 = M2C_FIELD(temp_r5_1823, void **, 4);
    } else {
        var_r4_1826 = M2C_FIELD(this->unk24, void **, 4);
    }
    if ((u32) temp_r5_1823 != 0U) {
        var_r3_1835 = M2C_FIELD(temp_r5_1823, void **, 4);
    } else {
        var_r3_1835 = M2C_FIELD(this->unk24, void **, 4);
    }
    MKView_SetProjection(0.87266463f, M2C_FIELD(var_r3_1835, f32 *, 0xB0), M2C_FIELD(var_r4_1826, f32 *, 0xB4));
    var_r25_1844 = 0;
    var_r27_1845 = 0;
    do {
        temp_r3_1847 = this->unk18;
        if ((u32) temp_r3_1847 != 0U) {
            var_r0_1850 = M2C_FIELD(temp_r3_1847, void **, 4);
        } else {
            var_r0_1850 = M2C_FIELD(this->unk24, void **, 4);
        }
        MKView_SetLightDirection(var_r25_1844, *(var_r0_1850 + (var_r27_1845 + 0x70)));
        temp_r3_1860 = this->unk18;
        if ((u32) temp_r3_1860 != 0U) {
            var_r0_1863 = M2C_FIELD(temp_r3_1860, void **, 4);
        } else {
            var_r0_1863 = M2C_FIELD(this->unk24, void **, 4);
        }
        MKView_SetLightColor(var_r25_1844, *(var_r0_1863 + (var_r27_1845 + 0x40)));
        var_r25_1844 += 1;
        var_r27_1845 += 0x10;
    } while (var_r25_1844 < 3);
    temp_r3_1877 = this->unk18;
    if ((u32) temp_r3_1877 != 0U) {
        var_r3_1880 = M2C_FIELD(temp_r3_1877, void **, 4);
    } else {
        var_r3_1880 = M2C_FIELD(this->unk24, void **, 4);
    }
    MKView_SetAmbientColor(*(var_r3_1880 + 0xA0));
    MKGrass_Enable(MKGrass_Enable(0U));
    temp_r3_1891 = this->unk18;
    if ((u32) temp_r3_1891 != 0U) {
        var_r3_1894 = M2C_FIELD(temp_r3_1891, void **, 4);
    } else {
        var_r3_1894 = M2C_FIELD(this->unk24, void **, 4);
    }
    this->unk78 = M2C_FIELD(var_r3_1894, s32 *, 0x20) + 1;
    temp_r3_1903 = this->unk18;
    if ((u32) temp_r3_1903 != 0U) {
        var_r3_1906 = M2C_FIELD(temp_r3_1903, void **, 4);
    } else {
        var_r3_1906 = M2C_FIELD(this->unk24, void **, 4);
    }
    temp_r30_1924 = M2C_FIELD(var_r3_1906, s32 *, 0x20) > 1;
    this->unk78 += temp_r30_1924;
    arg_sp20 = M2C_FIELD(&zero, f64 *, 0);
    arg_sp28 = M2C_FIELD(&zero, f64 *, 8);
    arg_sp30 = M2C_FIELD(&zero, f64 *, 0);
    arg_sp38 = M2C_FIELD(&zero, f64 *, 8);
    arg_sp48 = pGlobalModelIni;
    arg_sp50 = &gCreationTable;
    arg_sp4C = pGlobalLevelIni;
    temp_r26_1944 = this->unk78;
    arg_sp10 = M2C_FIELD(&zero, f64 *, 0);
    arg_sp18 = M2C_FIELD(&zero, f64 *, 8);
    arg_sp54 = temp_r26_1944;
    arg_spEC = 0;
    arg_spF0 = &Level::ResolveGameProps;
    arg_sp58 = 2.0f;
    arg_sp40 = 1.0f;
    arg_sp44 = 500.0f;
    operator new[]((temp_r26_1944 * 0x10) + 0x10, NULL, 0);
    temp_r3_1961 = __construct_new_array();
    pChunkData = temp_r3_1961;
    var_r4_1965 = 0;
    arg_sp5C = M2C_FIELD(pWorldInfo, s32 *, 0x3C);
    arg_sp60 = M2C_FIELD(pWorldInfo, s32 *, 0x5C);
    arg_sp68 = M2C_FIELD(pWorldInfo, s32 *, 0x4C);
    arg_sp64 = M2C_FIELD(pWorldInfo, s32 *, 0x2C);
    arg_sp6C = 1;
    *temp_r3_1961 = 0;
    M2C_FIELD(pChunkData, s32 *, 4) = 0;
    arg_sp70 = pChunkData;
    var_ctr_1980 = temp_r30_1924;
    if (temp_r30_1924 > 0) {
        do {
            temp_r3_1984 = var_r4_1965 + 1;
            temp_r10_1988 = temp_r3_1984 * 0x10;
            temp_r9_1992 = &arg_sp20 + (temp_r3_1984 * 0x18);
            M2C_FIELD(temp_r9_1992, s32 *, 0x3C) = (s32) M2C_FIELD(pWorldInfo, s32 *, 0x40);
            var_r4_1965 += 1;
            M2C_FIELD(temp_r9_1992, s32 *, 0x40) = (s32) M2C_FIELD(pWorldInfo, s32 *, 0x60);
            M2C_FIELD(temp_r9_1992, s32 *, 0x48) = (s32) M2C_FIELD(pWorldInfo, s32 *, 0x50);
            M2C_FIELD(temp_r9_1992, s32 *, 0x44) = (s32) M2C_FIELD(pWorldInfo, s32 *, 0x30);
            M2C_FIELD(temp_r9_1992, s8 *, 0x4C) = 0;
            *(pChunkData + temp_r10_1988) = 2;
            *(pChunkData + (temp_r10_1988 + 4)) = 0;
            M2C_FIELD(temp_r9_1992, void **, 0x50) = (void *) (pChunkData + temp_r10_1988);
            var_ctr_1980 -= 1;
        } while (var_ctr_1980 != 0);
    }
    var_r6_2015 = 0;
loop_39:
    temp_r5_2100 = this->unk18;
    if ((u32) temp_r5_2100 != 0U) {
        var_r4_2103 = M2C_FIELD(temp_r5_2100, void **, 4);
    } else {
        var_r4_2103 = M2C_FIELD(this->unk24, void **, 4);
    }
    if (var_r6_2015 < (s32) M2C_FIELD(var_r4_2103, s32 *, 0x20)) {
        if ((u32) temp_r5_2100 != 0U) {
            var_r5_2020 = M2C_FIELD(temp_r5_2100, void **, 4);
        } else {
            var_r5_2020 = M2C_FIELD(this->unk24, void **, 4);
        }
        temp_r0_2027 = temp_r30_1924 + 1 + var_r6_2015;
        temp_r5_2033 = &arg_sp20 + (temp_r0_2027 * 0x18);
        M2C_FIELD(temp_r5_2033, s32 *, 0x3C) = (s32) ((s32) M2C_FIELD(pWorldInfo, s32 *, 0x48) / (s32) M2C_FIELD(var_r5_2020, s32 *, 0x20));
        temp_r8_2035 = this->unk18;
        if ((u32) temp_r8_2035 != 0U) {
            var_r12_2038 = M2C_FIELD(temp_r8_2035, void **, 4);
        } else {
            var_r12_2038 = M2C_FIELD(this->unk24, void **, 4);
        }
        M2C_FIELD(temp_r5_2033, s32 *, 0x40) = (s32) ((s32) (((M2C_FIELD(pWorldInfo, s32 *, 0x58) - M2C_FIELD(pWorldInfo, s32 *, 0x5C)) - M2C_FIELD(pWorldInfo, s32 *, 0x64)) - M2C_FIELD(pWorldInfo, s32 *, 0x60)) / (s32) M2C_FIELD(var_r12_2038, s32 *, 0x20));
        temp_r8_2054 = this->unk18;
        if ((u32) temp_r8_2054 != 0U) {
            var_r12_2057 = M2C_FIELD(temp_r8_2054, void **, 4);
        } else {
            var_r12_2057 = M2C_FIELD(this->unk24, void **, 4);
        }
        M2C_FIELD(temp_r5_2033, s32 *, 0x48) = (s32) ((s32) (((M2C_FIELD(&gMKDefaults, s32 *, 0xDC) - M2C_FIELD(pWorldInfo, s32 *, 0x4C)) - M2C_FIELD(pWorldInfo, s32 *, 0x54)) - M2C_FIELD(pWorldInfo, s32 *, 0x50)) / (s32) M2C_FIELD(var_r12_2057, s32 *, 0x20));
        temp_r8_2073 = this->unk18;
        if ((u32) temp_r8_2073 != 0U) {
            var_r8_2076 = M2C_FIELD(temp_r8_2073, void **, 4);
        } else {
            var_r8_2076 = M2C_FIELD(this->unk24, void **, 4);
        }
        temp_r11_2083 = temp_r0_2027 * 0x10;
        var_r6_2015 += 1;
        M2C_FIELD(temp_r5_2033, s32 *, 0x44) = (s32) ((s32) M2C_FIELD(pWorldInfo, s32 *, 0x38) / (s32) M2C_FIELD(var_r8_2076, s32 *, 0x20));
        M2C_FIELD(temp_r5_2033, s8 *, 0x4C) = 0;
        *(pChunkData + temp_r11_2083) = 1;
        *(pChunkData + (temp_r11_2083 + 4)) = 0;
        M2C_FIELD(temp_r5_2033, void **, 0x50) = (void *) (pChunkData + temp_r11_2083);
        goto loop_39;
    }
    M2C_FIELD(*gMK, M2C_UNK (**)(void **, f64 *), 8)(gMK, &arg_sp20);
    temp_r3_2122 = M2C_FIELD(*gMK, MKHeap *(**)(void **), 0x2C)(gMK);
    temp_r26_2126 = (this->unk78 + 1) * 4;
    temp_r3_2127 = temp_r3_2122->Current();
    if (temp_r3_2127 != NULL) {
        var_r3_2135 = ((MKHeap *) (temp_r3_2127->Main()))->TAlloc(temp_r26_2126, NULL, 0, 0U);
    } else {
        var_r3_2135 = malloc(temp_r26_2126);
    }
    temp_r26_2144 = (this->unk78 + 1) * 4;
    temp_r3_2145 = var_r3_2135->Current();
    if (temp_r3_2145 != NULL) {
        var_r3_2153 = ((MKHeap *) (temp_r3_2145->Main()))->TAlloc(temp_r26_2144, NULL, 0, 0U);
    } else {
        var_r3_2153 = malloc(temp_r26_2144);
    }
    temp_r5_2159 = temp_r3_2122->unk0;
    var_r6_2161 = 0;
    var_r3_2162 = 0;
loop_51:
    if ((s32) (var_r6_2161 + 1) < (s32) this->unk78) {
        temp_r4_2165 = var_r3_2162 + 4;
        var_r6_2161 += 1;
        *(var_r3_2135 + var_r3_2162) = *(temp_r3_2122 + temp_r4_2165);
        *(var_r3_2153 + var_r3_2162) = *(temp_r3_2122 + temp_r4_2165);
        var_r3_2162 += 4;
        goto loop_51;
    }
    temp_r0_2177 = var_r6_2161 * 4;
    *(var_r3_2135 + temp_r0_2177) = temp_r5_2159;
    *(var_r3_2153 + temp_r0_2177) = temp_r5_2159;
    *(var_r3_2135 + (this->unk78 * 4)) = 0;
    *(var_r3_2153 + (this->unk78 * 4)) = 0;
    M2C_FIELD(*gMK, M2C_UNK (**)(void **, MKHeap *), 0xAC)(gMK, var_r3_2153);
    M2C_FIELD(*gMK, M2C_UNK (**)(void **, MKHeap *), 0xB0)(gMK, var_r3_2135);
    var_r3_2199 = Level_TerrainDrawCallback;
    var_r25_2200 = 0;
    var_r27_2202 = 0;
loop_54:
    if (var_r25_2200 < (s32) this->unk78) {
        temp_r3_2205 = *(temp_r3_2122 + var_r27_2202);
        var_r3_2199 = M2C_FIELD(M2C_FIELD(temp_r3_2205, void **, 8), void (*(**)(void *, void (*)(MKModel *, u16 *, void *)))(MKModel *, u16 *, void *), 0x48)(temp_r3_2205, Level_TerrainDrawCallback);
        var_r25_2200 += 1;
        var_r27_2202 += 4;
        goto loop_54;
    }
    temp_r3_2217 = var_r3_2199->Current();
    if (temp_r3_2217 != NULL) {
        ((MKHeap *) (temp_r3_2217->Main()))->TFree(var_r3_2135, NULL, 0);
    } else {
        free(var_r3_2135);
    }
    temp_r3_2230 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_2230 != NULL) {
        ((MKHeap *) (temp_r3_2230->Main()))->TFree(var_r3_2153, NULL, 0);
    } else {
        free(var_r3_2153);
    }
    SetProjectionToDefaults();
    temp_r3_2245 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_2245 != NULL) {
        var_r3_2252 = ((MKHeap *) (temp_r3_2245->Current()))->Alloc(0xA0, NULL, 0);
    } else {
        var_r3_2252 = malloc(0xA0);
    }
    this->unk68 = (s32) var_r3_2252;
    temp_r3_2259 = this->unk68;
    if ((u32) temp_r3_2259 != 0U) {
        temp_r3_2259->Init(&this->unk58);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void *MKLevelChunk::Game_ChunkChooser(MKChunkRequest *arg0, char **arg1, int arg2, MKLevelChunk **arg3, int arg4) {
    void *temp_r4_2303;
    void *temp_r5_2299;

    temp_r5_2299 = *(arg2 + (M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), s32 *, 0x20) * 4));
    if (temp_r5_2299 != NULL) {
        temp_r4_2303 = M2C_FIELD(M2C_FIELD(temp_r5_2299, void **, 0xC), void **, 4);
        if (temp_r4_2303 != NULL) {
            M2C_FIELD(temp_r4_2303, s32 *, 0x24) = 0;
        }
        pChunkChooser_TempChunkInfo = M2C_FIELD(this->unk10, ChunkInfo **, 4);
    }
    return temp_r5_2299;
}
#endif

#if 0 // DRAFT: undefined identifier 'pChunkPropQueue'
s32 MKLevelChunk::Game_ChunkInitComplete(MKLevelChunk *arg0, bool arg1) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    Level *temp_r4_2326;
    s32 temp_r31_2335;
    s32 var_ctr_2366;
    s32 var_r4_2365;
    void *temp_r3_2353;
    void *temp_r3_2392;
    void *var_r30_2338;

    temp_r4_2326 = this->unk14.unk11C;
    if ((temp_r4_2326 != NULL) && ((u8) arg0 == 0)) {
        KDSound_InvalidateSoundIDRange(M2C_FIELD(this, s32 *, 0x130), (s32) temp_r4_2326);
    }
    temp_r31_2335 = this->unkC;
    if ((u8) arg0 != 0) {
        var_r30_2338 = M2C_FIELD(M2C_FIELD(temp_r31_2335, void **, 4), void **, 0x14);
loop_6:
        if (var_r30_2338 != NULL) {
            M2C_FIELD(this->unk8, M2C_UNK (**)(MKLevelChunk *, s32, void *), 0x4C)(this, M2C_FIELD(var_r30_2338, s32 *, 0), var_r30_2338);
            var_r30_2338 = M2C_FIELD(var_r30_2338, void **, 4);
            goto loop_6;
        }
        temp_r3_2353 = M2C_FIELD(M2C_FIELD(temp_r31_2335, void **, 4), void **, 0x1C);
        if (temp_r3_2353 != NULL) {
            if ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 8) != 0) {
                var_r4_2365 = 0;
                var_ctr_2366 = 3;
loop_10:
                if ((u32) *(&pChunkPropQueue + var_r4_2365) == 0U) {
                    *(&pChunkPropQueue + var_r4_2365) = temp_r3_2353;
                } else {
                    var_r4_2365 += 4;
                    var_ctr_2366 -= 1;
                    if (var_ctr_2366 == 0) {

                    } else {
                        goto loop_10;
                    }
                }
            } else {
                sp14 = 0;
                sp10 = 0x2E;
                M2C_FIELD(M2C_FIELD(temp_r3_2353, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
            }
        }
    } else {
        pCurrentEventStrings.unk0 = temp_r31_2335 + 8;
        temp_r3_2392 = M2C_FIELD(M2C_FIELD(temp_r31_2335, void **, 4), void **, 0x1C);
        if (temp_r3_2392 != NULL) {
            spC = 0;
            sp8 = 0x2F;
            M2C_FIELD(M2C_FIELD(temp_r3_2392, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'GetWorldInfo'
s32 MKLevelChunk::Game_UserInit(MKLevelChunk *arg0, bool arg1) {
    ChunkInfo *temp_r4_2439;
    ChunkInfo *temp_r4_2466;
    ChunkInfo *temp_r4_2486;
    f32 var_f1_2428;
    s32 temp_cr0_eq_2441;
    s32 temp_r31_2421;
    s32 var_r4_2452;
    u8 var_r3_2436;
    u8 var_r3_2464;
    u8 var_r3_2487;
    void *temp_r5_2440;
    void *temp_r5_2467;
    void *temp_r5_2488;

    temp_r31_2421 = this->unkC;
    if ((u8) arg0 != 0) {
        if ((s32) M2C_FIELD(&gb, s32 *, 0x340) != 0) {
            var_f1_2428 = 2.0f;
        } else {
            gb.GetWorldInfo();
            var_f1_2428 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x1C);
        }
        KDSound_ResolveSoundIDs(var_f1_2428);
        var_r3_2436 = 0;
        M2C_FIELD(temp_r31_2421, ChunkInfo **, 4) = (ChunkInfo *) pChunkChooser_TempChunkInfo;
        pChunkChooser_TempChunkInfo = NULL;
        temp_r4_2439 = M2C_FIELD(temp_r31_2421, ChunkInfo **, 4);
        temp_r5_2440 = temp_r4_2439->unk4;
        temp_cr0_eq_2441 = temp_r5_2440 == NULL;
        if (temp_cr0_eq_2441 == 0) {
            if ((temp_cr0_eq_2441 == 0) && ((u32) M2C_FIELD(temp_r5_2440, u32 *, 0x118) == temp_r4_2439)) {
                var_r3_2436 = 1;
            }
            if (var_r3_2436 != 0) {
                var_r4_2452 = M2C_FIELD(M2C_FIELD(temp_r5_2440, void **, 0x120), s32 *, 0xF8);
            } else {
                var_r4_2452 = M2C_FIELD(M2C_FIELD(temp_r5_2440, void **, 0x120), s32 *, 0xFC);
            }
        } else {
            var_r4_2452 = 0x400;
        }
        ((UIStringTable *) (temp_r31_2421 + 8))->Init(var_r4_2452);
        var_r3_2464 = 0;
        pCurrentEventStrings.unk0 = temp_r31_2421 + 8;
        temp_r4_2466 = M2C_FIELD(temp_r31_2421, ChunkInfo **, 4);
        temp_r5_2467 = temp_r4_2466->unk4;
        if ((temp_r5_2467 != NULL) && ((u32) M2C_FIELD(temp_r5_2467, u32 *, 0x118) == temp_r4_2466)) {
            var_r3_2464 = 1;
        }
        if (var_r3_2464 != 0) {
            ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->SetEnvChunk(temp_r4_2466);
            ((ChunkInfo *) (M2C_FIELD(temp_r31_2421, ChunkInfo **, 4)))->InitEnv();
            EnemySpawnPool_Init();
        }
    } else {
        temp_r4_2486 = M2C_FIELD(temp_r31_2421, ChunkInfo **, 4);
        var_r3_2487 = 0;
        temp_r5_2488 = temp_r4_2486->unk4;
        if ((temp_r5_2488 != NULL) && ((u32) M2C_FIELD(temp_r5_2488, u32 *, 0x118) == temp_r4_2486)) {
            var_r3_2487 = 1;
        }
        if (var_r3_2487 != 0) {
            EnemySpawnPool_Deinit();
            ((ChunkInfo *) (M2C_FIELD(temp_r31_2421, ChunkInfo **, 4)))->DeinitEnv();
            ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->SetEnvChunk(NULL);
        }
        ((UIStringTable *) (temp_r31_2421 + 8))->Deinit();
        pCurrentEventStrings.unk0 = 0;
        M2C_FIELD(temp_r31_2421, ChunkInfo **, 4) = NULL;
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void Level::DrawEnvDome() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKModel *temp_r3_2529;
    MKModel *temp_r4_2574;
    f32 temp_f1_2548;
    f32 temp_f1_2554;
    f32 temp_f1_2560;
    f32 var_f2_2594;
    f64 temp_f0_2625;
    f64 temp_f0_2636;
    f64 temp_f1_2624;
    f64 temp_f1_2637;
    s32 temp_r3_2533;
    s32 temp_r3_2580;
    s32 temp_r3_2597;
    s32 var_r0_2577;
    void *temp_r29_2542;
    void *temp_r3_2623;
    void *temp_r3_2635;
    void *var_r3_2536;
    void *var_r3_2583;
    void *var_r3_2600;

    temp_r3_2529 = GetEnvDome();
    if (temp_r3_2529 != NULL) {
        MKView_Push();
        temp_r3_2533 = this->unk18;
        if ((u32) temp_r3_2533 != 0U) {
            var_r3_2536 = M2C_FIELD(temp_r3_2533, void **, 4);
        } else {
            var_r3_2536 = M2C_FIELD(this->unk24, void **, 4);
        }
        temp_r29_2542 = M2C_FIELD(var_r3_2536, void **, 0x118);
        MKView_GetProjection(&sp10, &spC, &sp8);
        temp_f1_2548 = M2C_FIELD(temp_r29_2542, f32 *, 0x50);
        if (temp_f1_2548 != -1.0f) {
            spC = temp_f1_2548;
        }
        temp_f1_2554 = M2C_FIELD(temp_r29_2542, f32 *, 0x54);
        if (temp_f1_2554 != -1.0f) {
            sp8 = temp_f1_2554;
        }
        temp_f1_2560 = M2C_FIELD(temp_r29_2542, f32 *, 0x58);
        if (temp_f1_2560 != -1.0f) {
            sp10 = temp_f1_2560;
        }
        MKView_SetProjection(sp10, spC, sp8);
        sp58 = M2C_FIELD(&zero, f64 *, 0);
        sp60 = M2C_FIELD(&zero, f64 *, 8);
        temp_r4_2574 = this->unk30;
        if (temp_r4_2574 != NULL) {
            var_r0_2577 = this->unk48;
        } else {
            temp_r3_2580 = this->unk18;
            if ((u32) temp_r3_2580 != 0U) {
                var_r3_2583 = M2C_FIELD(temp_r3_2580, void **, 4);
            } else {
                var_r3_2583 = M2C_FIELD(this->unk24, void **, 4);
            }
            var_r0_2577 = M2C_FIELD(M2C_FIELD(var_r3_2583, void **, 0x118), s32 *, 0x48);
        }
        if (temp_r4_2574 != NULL) {
            var_f2_2594 = this->unk4C;
        } else {
            temp_r3_2597 = this->unk18;
            if ((u32) temp_r3_2597 != 0U) {
                var_r3_2600 = M2C_FIELD(temp_r3_2597, void **, 4);
            } else {
                var_r3_2600 = M2C_FIELD(this->unk24, void **, 4);
            }
            var_f2_2594 = M2C_FIELD(M2C_FIELD(var_r3_2600, void **, 0x118), f32 *, 0x4C);
        }
        switch (var_r0_2577) {                      /* irregular */
        case 1:
            temp_r3_2623 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
            temp_f1_2624 = M2C_FIELD(temp_r3_2623, f64 *, 0x30);
            temp_f0_2625 = M2C_FIELD(temp_r3_2623, f64 *, 0x38);
            sp48 = temp_f1_2624;
            sp50 = temp_f0_2625;
            sp58 = temp_f1_2624;
            sp60 = temp_f0_2625;
            break;
        case 2:
            temp_r3_2635 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
            temp_f0_2636 = M2C_FIELD(temp_r3_2635, f64 *, 0x30);
            temp_f1_2637 = M2C_FIELD(temp_r3_2635, f64 *, 0x38);
            sp38 = temp_f0_2636;
            sp58 = temp_f0_2636;
            sp40 = temp_f1_2637;
            sp60 = temp_f1_2637;
            unksp5C *= var_f2_2594;
            break;
        case 3:
            sp58 = this->unk38;
            sp60 = this->unk40;
            MKView_SetProjection(this->unkC, this->unk50, this->unk54);
            break;
        }
        MKModel_SetPosition(temp_r3_2529, *((MKVector3 *) &sp58));
        MKModel_Draw(temp_r3_2529, NULL);
        sp18 = 0.0f;
        sp1C = 0.0f;
        sp20 = 0.0f;
        sp24 = 0.0f;
        sp28 = (f64) sp18;
        sp30 = (f64) sp20;
        MKView_Clear(2, *((MKVector4 *) &sp28), 0.0f, 0U);
        MKView_Pop();
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void Level::Draw() {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    EventCamera *temp_r3_2692;
    MKVector3 *var_r4_2708;
    f64 *var_r3_2705;
    s32 temp_r3_2913;
    u8 temp_r28_2755;
    u8 temp_r30_2751;
    u8 var_r4_2694;

    temp_r3_2692 = EventCamera_GetCurrent();
    var_r4_2694 = 0;
    if ((temp_r3_2692 == NULL) || ((u8) temp_r3_2692->unkF4 != 0)) {
        var_r4_2694 = 1;
    }
    if (var_r4_2694 != 0) {
        var_r3_2705 = &sp18;
        var_r4_2708 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), MKVector3 **, 8);
        sp18 = M2C_FIELD(var_r4_2708, f64 *, 0x30);
        sp20 = M2C_FIELD(var_r4_2708, f64 *, 0x38);
    } else {
        var_r4_2708 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), MKVector3 **, 8);
        var_r3_2705 = &sp8;
        sp8 = M2C_FIELD(var_r4_2708, f64 *, 0x30);
        sp10 = M2C_FIELD(var_r4_2708, f64 *, 0x38);
    }
    var_r3_2705->CullGroups(*var_r4_2708);
    if ((u8) M2C_FIELD(this, u8 *, 0x6C) == 0) {
        if ((u8) M2C_FIELD(&gb, CutsceneSystem **, 0xC)->unkA9 != 0) {
            ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->Draw();
            return;
        }
        ApplyViewParameters();
        if ((u8) this->unk28 != 0) {
            temp_r30_2751 = MKMaterial_EnableFog(0U);
            temp_r28_2755 = OmniLight_SuspendAll(1U);
            DrawEnvDome();
            OmniLight_SuspendAll(temp_r28_2755);
            MKMaterial_EnableFog(temp_r30_2751);
        }
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32), 0x8C)(gMK, M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), s32 (**)(void *), 0x58)(M2C_FIELD(&gb, void **, 0x3B8)));
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x28)(gMK, 0);
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x24)(gMK, 0);
        MKGrass_Draw();
        Shadow_Draw();
        M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), M2C_UNK (**)(void **), 0x18)(M2C_FIELD(&gb, void ***, 0));
        if (M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), u8 (**)(void *), 0x58)(M2C_FIELD(&gb, void **, 0x3B8)) == 0) {
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x28)(gMK, 2);
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x24)(gMK, 1);
        } else {
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x28)(gMK, 1);
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x24)(gMK, 2);
        }
        M2C_FIELD(*gMK, M2C_UNK (**)(void **), 0x64)(gMK);
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x28)(gMK, 3);
        M2C_FIELD(*gMK, M2C_UNK (**)(void **), 0x68)(gMK);
        if (M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), u8 (**)(void *), 0x58)(M2C_FIELD(&gb, void **, 0x3B8)) == 0) {
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x28)(gMK, 1);
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x24)(gMK, 2);
        } else {
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x28)(gMK, 2);
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x24)(gMK, 1);
        }
        MKGrass_Draw();
        ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->Draw();
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x24)(gMK, 3);
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK), 0x24)(gMK, 4);
        ((CharacterBodyFXManager *) ((CharacterBodyFXManager *) (&gb + 0x2A8)))->Draw();
        ((SlimeTrailFXManager *) ((SlimeTrailFXManager *) (&gb + 0x2B8)))->Draw();
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x64), void **, 0x44), M2C_UNK (**)(void *), 0x28)(M2C_FIELD(&gb, void **, 0x64));
        if ((u32) this->unk18 != 0U) {
            temp_r3_2913 = this->unk68;
            if ((u32) temp_r3_2913 != 0U) {
                temp_r3_2913->Draw();
            }
        }
    }
}
#endif

void Level_TerrainDrawCallback(MKModel *arg0, unsigned short *arg1, void *arg2) {
    u8 var_r31_2935;

    var_r31_2935 = 1;
    if (arg2 != NULL) {
        var_r31_2935 = MKMaterial_EnableFog(M2C_FIELD(arg2, u8 *, 8));
    }
    MKModel_Draw(arg0, arg1);
    if (arg2 != NULL) {
        MKMaterial_EnableFog(var_r31_2935);
    }
}

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void Level::UpdateState() {
    QueueInfo sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r0_3014;
    s32 var_r25_3047;
    s32 var_r30_3044;
    u32 temp_r3_2986;
    u8 var_r26_2970;
    void *temp_r3_3052;

    if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r26_2970 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r26_2970 = 1;
        }
        if (var_r26_2970 == 0) {
            goto block_6;
        }
    } else {
block_6:
        temp_r3_2986 = this->unk1C;
        if (temp_r3_2986 != 0) {
            temp_r3_2986->UpdateState();
            if (this->unk1C->IsLoaded() != 0) {
                this->unk1C = 0;
            }
        }
        if (((u32) this->unk1C == 0) && (GetNextInQueue(&sp10, 0U) != 0) && ((temp_r0_3014 = M2C_FIELD(*(M2C_FIELD(*gMK, s32 (**)(void **), 0x2C)(gMK) + (sp10.unk4 * 4)), s32 *, 0x90), ((temp_r0_3014 == 1) != 0)) || (temp_r0_3014 == 9))) {
            GetNextInQueue((QueueInfo *) &this->unk1C, 1U);
            LoadChunk((ChunkInfo *) this->unk1C, this->unk20);
        }
        if (((u8) this->unk8 != 0) && ((u32) this->unk1C == 0)) {
            this->unk8 = 0;
            if ((s32) *gGMState.GetCurrState() != 6) {
                Music_Resume();
                var_r30_3044 = 0;
                var_r25_3047 = 0;
                do {
                    temp_r3_3052 = *(&pChunkPropQueue + var_r30_3044);
                    if (temp_r3_3052 != NULL) {
                        spC = 0;
                        sp8 = 0x2E;
                        M2C_FIELD(M2C_FIELD(temp_r3_3052, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
                    }
                    var_r25_3047 += 1;
                    *(&pChunkPropQueue + var_r30_3044) = 0;
                    var_r30_3044 += 4;
                } while (var_r25_3047 < 3);
            }
            if ((u8) this->unk9 != 0) {
                ((GameGlobals::Fade *) ((GameGlobals::Fade *) (&gb + 0x30)))->FadeIn(NULL);
                this->unk9 = 0;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void Level::Update() {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    KDSynkerPlayer3 *temp_r3_3162;
    f32 temp_r0_3102;
    s32 temp_r0_3099;
    s32 temp_r3_3135;
    s32 temp_r3_3186;
    s32 temp_r3_3264;
    u8 var_r29_3147;
    void ***temp_r31_3123;
    void *temp_r27_3161;
    void *temp_r5_3210;
    void *temp_r5_3225;
    void *var_r4_3138;

    if ((u8) M2C_FIELD(this, u8 *, 0x6C) != 0) {
        temp_r0_3099 = M2C_BITWISE(s32, this->unk70) - 1;
        this->unk70 = M2C_BITWISE(f32, temp_r0_3099);
        if (temp_r0_3099 != 0) {
            temp_r0_3102 = this->unk74;
            if (M2C_BITWISE(u32, temp_r0_3102) != 0U) {
                pLoadChunkInfo = M2C_BITWISE(ChunkInfo *, temp_r0_3102);
                gGMState.SwitchState(6, 1, 0U);
                return;
            }
            cutsceneSys.Abort(1U);
            FrontEnd_GotoMainMenu();
        }
    } else {
        temp_r31_3123 = &gb + 0x2CC;
        temp_r31_3123->Begin();
        ((TriggerProp *) (M2C_FIELD(*gMK, TriggerProp *(**)(void **), 0x1C)(gMK)))->UpdateActiveList();
        MKCollision_Update();
        MKGrass_Update();
        MKWind_Update();
        temp_r3_3135 = this->unk18;
        if ((u32) temp_r3_3135 != 0U) {
            var_r4_3138 = M2C_FIELD(temp_r3_3135, void **, 4);
        } else {
            var_r4_3138 = M2C_FIELD(this->unk24, void **, 4);
        }
        var_r29_3147 = 0;
        this->unkB0 = M2C_FIELD(var_r4_3138, f32 *, 0xB8);
        this->unkB4 = M2C_FIELD(var_r4_3138, f32 *, 0xBC);
        M2C_FIELD(this, f64 *, 0xB8) = (f64) M2C_FIELD(var_r4_3138, f64 *, 0xC0);
        M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(var_r4_3138, f64 *, 0xC8);
        this->unkC8 = M2C_FIELD(var_r4_3138, f64 *, 0xD0);
        this->unkD0 = M2C_FIELD(var_r4_3138, f64 *, 0xD8);
        this->unkD8 = M2C_FIELD(var_r4_3138, f32 *, 0xE0);
        temp_r27_3161 = M2C_FIELD(&gb, void **, 0xC);
        temp_r3_3162 = M2C_FIELD(temp_r27_3161, KDSynkerPlayer3 **, 0x78);
        if (((temp_r3_3162 != NULL) && (temp_r3_3162->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r27_3161, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r27_3161 + 0x24))->GetState() == 2))) {
            var_r29_3147 = 1;
        }
        if ((var_r29_3147 != 0) && ((s32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), s32 *, 0x74) == 0) && (temp_r3_3186 = M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), KDSynkerPlayer3 **, 0x78)->unk100.unk0, (((u32) temp_r3_3186 == 0U) == 0))) {
            MKModel_GetPosition(temp_r3_3186->GetModel());
            sp28 = *M2C_ERROR(/* Read from unset register $r3 */);
            sp30 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f64 *, 8);
            FogPoints_Update(*((MKVector3 *) &sp28), (FogInfo *) &this->unkB0);
            WindPoints_Update(*((MKVector3 *) &sp28), (WindInfo *) &this->unkC8);
        } else {
            temp_r5_3210 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), void **, 8);
            sp18 = M2C_FIELD(temp_r5_3210, f64 *, 0x30);
            sp20 = M2C_FIELD(temp_r5_3210, f64 *, 0x38);
            FogPoints_Update(*((MKVector3 *) &sp18), (FogInfo *) &this->unkB0);
            temp_r5_3225 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), void **, 8);
            sp8 = M2C_FIELD(temp_r5_3225, f64 *, 0x30);
            sp10 = M2C_FIELD(temp_r5_3225, f64 *, 0x38);
            WindPoints_Update(*((MKVector3 *) &sp8), (WindInfo *) &this->unkC8);
        }
        ((CharacterBodyFXManager *) ((CharacterBodyFXManager *) (&gb + 0x2A8)))->Update();
        ((SlimeTrailFXManager *) ((SlimeTrailFXManager *) (&gb + 0x2B8)))->Update();
        ((ScreenWobbleFX *) ((ScreenWobbleFX *) (&gb + 0xB8)))->Update();
        ((ShotgunWarpFX *) ((ShotgunWarpFX *) (&gb + 0x130)))->Update();
        ((ExplosionWarpFX *) ((ExplosionWarpFX *) (&gb + 0x1C0)))->Update();
        ((HeatDistortPS *) ((HeatDistortPS *) (&gb + 0x240)))->Update();
        temp_r31_3123->End();
        ((CustomMaterialUpdateManager *) ((CustomMaterialUpdateManager *) (&gb + 0x2BC)))->Update();
        temp_r3_3264 = this->unk68;
        if ((u32) temp_r3_3264 != 0U) {
            temp_r3_3264->Update();
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'pChunkPropQueue'
void Level::Deinit() {
    s32 spC;
    s32 sp8;
    MKHeap *temp_r3_3382;
    s32 temp_cr0_eq_3351;
    s32 temp_r30_3381;
    s32 temp_r3_3377;
    s32 var_ctr_3289;
    s32 var_r4_3281;

    var_r4_3281 = 0;
    var_ctr_3289 = 3;
    do {
        *(&pChunkPropQueue + var_r4_3281) = 0;
        var_r4_3281 += 4;
        var_ctr_3289 -= 1;
    } while (var_ctr_3289 != 0);
    spC = 0;
    sp8 = 0x2A;
    M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x94)(gMK, &sp8, 0, 1, 0, 1, 0.0f);
    MKShockWave_Disable();
    MKRumble_Reset();
    MKGrass_LevelDeinit();
    MKRumble_Mute(0U);
    PhrasePlayer_StopAnyEvent();
    FreeTempMemory();
    cutsceneSys.Deinit();
    CancelQueue();
    M2C_FIELD(*gMK, M2C_UNK (**)(void **), 0xC)(gMK);
    FreeGlobalResources();
    ((CustomMaterialUpdateManager *) ((CustomMaterialUpdateManager *) (&gb + 0x2BC)))->Deinit();
    Hud_DeinitModule();
    ((CharacterBodyFXManager *) ((CharacterBodyFXManager *) (&gb + 0x2A8)))->Deinit();
    gBoneBlurFXPool.Deinit();
    gGlowingPropManager.Deinit();
    ((SlimeTrailFXManager *) ((SlimeTrailFXManager *) (&gb + 0x2B8)))->Deinit();
    temp_cr0_eq_3351 = (s32 *) pChunkData == NULL;
    M2C_FIELD(&gb, s32 *, 0x2C4) = 0;
    if ((temp_cr0_eq_3351 == 0) && (temp_cr0_eq_3351 == 0)) {
        operator delete[](pChunkData - 0x10);
    }
    pChunkData = NULL;
    MKCollision_Deinit();
    MKParticleSystem_DeinitModule();
    Console_DiscardDelayedCmds();
    KDSound_Deinit();
    PauseMenu_Deinit();
    UIObject_MenuStringsDeinit();
    this->unk18 = 0;
    this->unk24 = 0;
    this->unk1C = 0;
    this->unkAC = 0;
    M2C_FIELD(this, s8 *, 0x6C) = 0;
    this->unk70 = 7e-45f;
    this->unk74 = 0.0f;
    NULL->Deinit();
    ((CharacterGraphManager *) (M2C_ERROR(/* Read from unset register $r3 */)))->Deinit();
    temp_r3_3377 = this->unk68;
    if ((u32) temp_r3_3377 != 0U) {
        temp_r3_3377->Deinit();
        temp_r30_3381 = this->unk68;
        temp_r3_3382 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_3382 != NULL) {
            ((MKHeap *) (temp_r3_3382->Current()))->Free((void *) temp_r30_3381, NULL, 0);
        } else {
            free((MKHeap *) temp_r30_3381);
        }
        this->unk68 = 0;
    }
    MKZRequest_DeinitModule();
    if ((u32) M2C_FIELD(&gb, u32 *, 0x3B8) != 0U) {
        M2C_FIELD(&gb, u32 *, 0x3B8) = 0U;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void Level::Init(ChunkInfo *arg0) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 temp_r3_3468;
    u8 var_r30_3480;
    void *var_r3_3471;

    this->unk30 = NULL;
    this->unk38 = M2C_FIELD(&zero, f64 *, 0);
    this->unk40 = M2C_FIELD(&zero, f64 *, 8);
    this->unk48 = 0;
    this->unk4C = 1.0f;
    8->Init((s32) arg0);
    ((CharacterGraphManager *) (M2C_ERROR(/* Read from unset register $r3 */)))->Init();
    this->unk24 = (s32) arg0;
    this->unk18 = 0;
    this->unk1C = 0;
    this->unkAC = 0;
    MKParticleSystem_InitModule(M2C_FIELD(pWorldInfo, s32 *, 4));
    MKCollision_Init();
    sp10 = 69864.0f;
    sp20 = -61537.0f;
    sp8 = 102912.0f;
    spC = 67876.0f;
    sp18 = -105679.0f;
    sp1C = -50000.0f;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    MKCollision_SetDefaultBoundingBox(*((MKVector3 *) &sp38), *((MKVector3 *) &sp28));
    temp_r3_3468 = this->unk18;
    if ((u32) temp_r3_3468 != 0U) {
        var_r3_3471 = M2C_FIELD(temp_r3_3468, void **, 4);
    } else {
        var_r3_3471 = M2C_FIELD(this->unk24, void **, 4);
    }
    var_r30_3480 = 0;
    M2C_FIELD(pGlobalModelIni, s32 *, 0x44) = (s32) M2C_FIELD(var_r3_3471, s32 *, 4);
    M2C_FIELD(this, f32 *, 0xE4) = 0.0f;
    this->unkE0 = 0.0f;
    this->unkEC = 0.0f;
    this->unkE8 = 0.0f;
    M2C_FIELD(this, s8 *, 0x6C) = 0;
    this->unk70 = 7e-45f;
    this->unk74 = 0.0f;
    this->unk8 = 0;
    this->unk9 = 0;
    this->unk28 = 1;
    this->unk2C = 1.0f;
    if ((s32) M2C_FIELD(&gb, s32 *, 0x350) != 0) {
        gameData.GetGameSettings();
        if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x12) != 0) {
            var_r30_3480 = 1;
        }
    }
    MKRumble_Enable(var_r30_3480);
    gameData.GetGameSettings();
    Tools_EnableWideScreen(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x11));
    MKZRequest_InitModule();
    this->unk58.unk0 = 0.0f;
    this->unk58.unk4 = 0.0f;
    this->unk58.unk8 = 0.0f;
    this->unk68 = 0;
    ((CharacterBodyFXManager *) ((CharacterBodyFXManager *) (&gb + 0x2A8)))->Init();
    gBoneBlurFXPool.Init(BONE_BLUR_FX_NODE_POOL_MAX_NODES, BONE_BLUR_FX_NODE_POOL_MAX_ALLOCS);
    gGlowingPropManager.Init();
    ((SlimeTrailFXManager *) ((SlimeTrailFXManager *) (&gb + 0x2B8)))->Init();
    ((CustomMaterialUpdateManager *) ((CustomMaterialUpdateManager *) (&gb + 0x2BC)))->Init();
    M2C_FIELD(&gb, s32 *, 0x2C4) = 0;
    Hud_InitModule();
}
#endif

#if 0 // DRAFT: pointer/array required
void Level::DeinitModule() {
    Level *var_r31_3563;
    Level *var_r3_3562;
    MKHeap *temp_r31_3574;
    MKHeap *temp_r3_3575;
    MKHeap *temp_r3_3596;
    MKHeap *temp_r3_3610;
    MKIni *temp_r31_3595;
    MKIni *temp_r31_3609;

    var_r3_3562 = NULL->GetNextChunk(M2C_ERROR(/* Read from unset register $r4 */));
    var_r31_3563 = var_r3_3562;
loop_2:
    if (var_r31_3563 != NULL) {
        var_r31_3563->Deinit();
        var_r3_3562 = var_r31_3563->GetNextChunk(M2C_ERROR(/* Read from unset register $r4 */));
        var_r31_3563 = var_r3_3562;
        goto loop_2;
    }
    temp_r31_3574 = pLevelInfo;
    temp_r3_3575 = var_r3_3562->Current();
    if (temp_r3_3575 != NULL) {
        ((MKHeap *) (temp_r3_3575->Current()))->Free(temp_r31_3574, NULL, 0);
    } else {
        free(temp_r31_3574);
    }
    pLevelInfo = NULL;
    levelInfoCount = 0;
    pGlobalLevelIni->Deinit();
    pGlobalModelIni->Deinit();
    temp_r31_3595 = pGlobalLevelIni;
    temp_r3_3596 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_3596 != NULL) {
        ((MKHeap *) (temp_r3_3596->Current()))->Free(temp_r31_3595, NULL, 0);
    } else {
        free((MKHeap *) temp_r31_3595);
    }
    temp_r31_3609 = pGlobalModelIni;
    temp_r3_3610 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_3610 != NULL) {
        ((MKHeap *) (temp_r3_3610->Current()))->Free(temp_r31_3609, NULL, 0);
        return;
    }
    free((MKHeap *) temp_r31_3609);
}
#endif

#if 0 // DRAFT: undefined identifier 'pGlobalLevelIni'
void Level::InitLevelInfo() {
    LevelInfo *temp_r3_3813;
    MKHeap *temp_r3_3747;
    MKHeap *var_r3_3754;
    MKIniLine *var_r26_3681;
    MKIniLine *var_r26_3789;
    MKIniLine *var_r27_3775;
    MKIniLine *var_r28_3665;
    MKIniLine *var_r29_3649;
    MKIniLine *var_r29_3828;
    WorldInfo *temp_r4_3762;
    s32 temp_r26_3744;
    s32 temp_r27_3737;
    s32 temp_r28_3740;
    s32 temp_r29_3746;
    s32 temp_r3_3741;
    u8 temp_r3_3810;
    void *temp_r0_3760;
    void *temp_r6_3764;

    pGlobalLevelIni->unk44 = platformCode;
    levelInfoCount = 0;
    chunkInfoCount = 1;
    terrainInfoCount = 0;
    materialInfoCount = 0;
    var_r29_3649 = pGlobalLevelIni->GetFirstLine();
loop_15:
    if (var_r29_3649 != NULL) {
        if (var_r29_3649->IsField("") != 0) {
            levelInfoCount = (s32) (levelInfoCount + 1);
            var_r28_3665 = var_r29_3649->unkC->GetSubLine(var_r29_3649);
loop_13:
            if (var_r28_3665 != NULL) {
                if (var_r28_3665->IsField("") != 0) {
                    chunkInfoCount = (s32) (chunkInfoCount + 1);
                    var_r26_3681 = var_r28_3665->unkC->GetSubLine(var_r28_3665);
loop_11:
                    if (var_r26_3681 != NULL) {
                        if ((var_r26_3681->IsField("") != 0) && (var_r26_3681->GetNmbrOfSubLines() != 0)) {
                            terrainInfoCount = (s32) (terrainInfoCount + 1);
                        } else if (var_r26_3681->IsField("") != 0) {
                            materialInfoCount = (s32) (materialInfoCount + var_r26_3681->GetNmbrOfSubLines());
                        }
                        var_r26_3681 = var_r26_3681->unkC->GetNextLine(var_r26_3681);
                        goto loop_11;
                    }
                }
                var_r28_3665 = var_r28_3665->unkC->GetNextLine(var_r28_3665);
                goto loop_13;
            }
        }
        var_r29_3649 = var_r29_3649->unkC->GetNextLine(var_r29_3649);
        goto loop_15;
    }
    temp_r27_3737 = chunkInfoCount * 0x64;
    temp_r28_3740 = terrainInfoCount * 0xC;
    temp_r3_3741 = materialInfoCount * 0x10;
    temp_r26_3744 = levelInfoCount * 0x128;
    temp_r29_3746 = temp_r26_3744 + (temp_r27_3737 + 0x100 + temp_r28_3740 + temp_r3_3741);
    temp_r3_3747 = temp_r3_3741->Current();
    if (temp_r3_3747 != NULL) {
        var_r3_3754 = ((MKHeap *) (temp_r3_3747->Current()))->Alloc(temp_r29_3746, NULL, 0);
    } else {
        var_r3_3754 = malloc(temp_r29_3746);
    }
    temp_r0_3760 = var_r3_3754 + temp_r26_3744;
    pLevelInfo = var_r3_3754;
    temp_r4_3762 = temp_r0_3760 + temp_r27_3737;
    temp_r6_3764 = temp_r4_3762 + 0x100;
    pChunkInfo = temp_r0_3760;
    pWorldInfo = temp_r4_3762;
    pTerrainInfo = temp_r6_3764;
    pMaterialInfo = (void *) (temp_r6_3764 + temp_r28_3740);
    memset(var_r3_3754, 0, (u32) temp_r29_3746);
    var_r27_3775 = pGlobalLevelIni->GetFirstLine();
loop_31:
    if (var_r27_3775 != NULL) {
        if (var_r27_3775->IsField("") != 0) {
            pWorldInfo->Init();
            var_r26_3789 = var_r27_3775->unkC->GetSubLine(var_r27_3775);
loop_23:
            if (var_r26_3789 != NULL) {
                pWorldInfo->LoadLine(var_r26_3789);
                var_r26_3789 = var_r26_3789->unkC->GetNextLine(var_r26_3789);
                goto loop_23;
            }
            pWorldInfo->LoadDone();
        } else {
            temp_r3_3810 = var_r27_3775->IsField("");
            if (temp_r3_3810 != 0) {
                temp_r3_3813 = temp_r3_3810->AllocLevelInfo();
                pWorldInfo->AddLevelInfo(temp_r3_3813);
                temp_r3_3813->Init();
                var_r27_3775->AsString(0, &temp_r3_3813->unk4);
                var_r29_3828 = var_r27_3775->unkC->GetSubLine(var_r27_3775);
loop_28:
                if (var_r29_3828 != NULL) {
                    temp_r3_3813->LoadLine(var_r29_3828);
                    var_r29_3828 = var_r29_3828->unkC->GetNextLine(var_r29_3828);
                    goto loop_28;
                }
                temp_r3_3813->LoadDone();
            }
        }
        var_r27_3775 = var_r27_3775->unkC->GetNextLine(var_r27_3775);
        goto loop_31;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'pGlobalLevelIni'
void Level::InitModule() {
    operator new(0x50U, NULL, 0);
    pGlobalLevelIni = (MKIni *) M2C_ERROR(/* Read from unset register $r3 */);
    operator new(0x50U, NULL, 0);
    pGlobalModelIni = (MKIni *) M2C_ERROR(/* Read from unset register $r3 */);
    gAssertBool = pGlobalLevelIni->Init(pGlobalLevelName, 0, NULL);
    gAssertBool = pGlobalModelIni->Init(pGlobalModelName, 0, NULL);
    MKWind_Set(4.0f, 400.0f, 10.0f, 4.0f, zero, 0.5f);
    ((Level *) (M2C_ERROR(/* Read from unset register $r3 */)))->InitLevelInfo();
}
#endif

#if 0 // DRAFT: undefined identifier 'materialInfoAllocCount'
MaterialInfo *Level::AllocMaterialInfo() {
    s32 temp_r0_3907;

    temp_r0_3907 = materialInfoAllocCount * 0x10;
    materialInfoAllocCount = (s32) (materialInfoAllocCount + 1);
    return pMaterialInfo + temp_r0_3907;
}
#endif

#if 0 // DRAFT: undefined identifier 'terrainInfoAllocCount'
TerrainInfo *Level::AllocTerrainInfo() {
    s32 temp_r0_3918;

    temp_r0_3918 = terrainInfoAllocCount * 0xC;
    terrainInfoAllocCount = (s32) (terrainInfoAllocCount + 1);
    return pTerrainInfo + temp_r0_3918;
}
#endif

#if 0 // DRAFT: undefined identifier 'chunkInfoAllocCount'
ChunkInfo *Level::AllocChunkInfo() {
    s32 temp_r0_3930;

    temp_r0_3930 = chunkInfoAllocCount * 0x64;
    chunkInfoAllocCount = (s32) (chunkInfoAllocCount + 1);
    return pChunkInfo + temp_r0_3930;
}
#endif

#if 0 // DRAFT: undefined identifier 'pLevelInfo'
LevelInfo *Level::AllocLevelInfo() {
    s32 temp_r0_3946;

    *(pLevelInfo + (levelInfoAllocCount * 0x128)) = levelInfoAllocCount;
    temp_r0_3946 = levelInfoAllocCount * 0x128;
    levelInfoAllocCount = (s32) (levelInfoAllocCount + 1);
    return pLevelInfo + temp_r0_3946;
}
#endif

void MaterialInfo::Destroy() {
    ((CustomMaterialUpdateManager *) ((CustomMaterialUpdateManager *) (&gb + 0x2BC)))->Destroy(this->unk4);
    this->unk4 = NULL;
}

#if 0 // DRAFT: function call 'Tools_GetMatchingMaterial(MKModel *, signed char *)' does
void MaterialInfo::Create(MKModel *arg0) {
    MKMaterial *temp_r3_3987;

    if (arg0 != NULL) {
        temp_r3_3987 = Tools_GetMatchingMaterial(arg0, this->unk0);
        if (temp_r3_3987 != NULL) {
            this->unk4 = ((CustomMaterialUpdateManager *) ((CustomMaterialUpdateManager *) (&gb + 0x2BC)))->Create(temp_r3_3987, this->unk8);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'customMaterialUpdaterMap'
s32 MaterialInfo::LoadLine(MKIniLine *arg0) {
    this->unk0 = arg0->GetFieldName();
    this->unk8 = DataMap_GetValue(&customMaterialUpdaterMap, arg0->GetString(0));
    return 1;
}
#endif

void MaterialInfo::Init() {
    this->unk0 = NULL;
    this->unk4 = NULL;
    this->unk8 = 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
void TerrainInfo::LoadLine(MKIniLine *arg0) {
    arg0->LoadBool("", (u8 *) &this->unk8, 0);
}
#endif

void ChunkInfo::DeinitEnv() {
    MKModel *temp_r3_4105;
    MaterialInfo *var_r31_4070;
    s8 *temp_r3_4098;

    var_r31_4070 = this->unk18;
loop_2:
    if (var_r31_4070 != NULL) {
        var_r31_4070->Destroy();
        var_r31_4070 = var_r31_4070->unkC;
        goto loop_2;
    }
    WindPoints_Deinit();
    FogPoints_Deinit();
    ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->DisableAllLights();
    ((ScreenWobbleFX *) ((ScreenWobbleFX *) (&gb + 0xB8)))->EnableSpeedEffect(0U, 0.0f, 1.0f);
    M2C_FIELD(&gb, f32 *, 0xDC) = 0.0f;
    M2C_FIELD(&gb, s8 *, 0x35D) = 0;
    temp_r3_4098 = this->unk3C;
    if (temp_r3_4098 != NULL) {
        MKModel_Destroy((MKModel *) temp_r3_4098);
        this->unk3C = NULL;
    }
    temp_r3_4105 = this->unk40;
    if (temp_r3_4105 != NULL) {
        MKModel_Destroy(temp_r3_4105);
        this->unk40 = NULL;
    }
    if (PhrasePlayer_IsLevelIniLoaded() != 0) {
        PhrasePlayer_UnloadLevelIni();
    }
}

#if 0 // DRAFT: function call 'MKModel_Create(signed char *, int, int, int)' does not
void ChunkInfo::InitEnv() {
    f64 sp28;
    f64 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    MaterialInfo *var_r31_4172;
    f64 temp_f0_4202;
    f64 temp_f1_4201;
    s32 temp_r3_4132;
    s8 *temp_r3_4144;
    void *temp_r4_4212;
    void *temp_r5_4200;

    temp_r3_4132 = this->unk36;
    if ((u32) temp_r3_4132 != 0U) {
        this->unk3C = MKModel_Create((s8 *) temp_r3_4132, NULL, 2, NULL);
        MKModel_EnableScissoring((MKModel *) this->unk3C, 1U);
    }
    temp_r3_4144 = this->unk3C;
    if (temp_r3_4144 != NULL) {
        this->unk40 = MKModel_Create(temp_r3_4144, NULL, 2, NULL);
        MKModel_EnableScissoring(this->unk40, 1U);
    }
    FogPoints_Init(Str_Printf("", M2C_FIELD(this->unk4, s32 *, 4), "Level Options"));
    WindPoints_Init(Str_Printf("", M2C_FIELD(this->unk4, s32 *, 4), "Level Options"));
    var_r31_4172 = this->unk18;
loop_6:
    if (var_r31_4172 != NULL) {
        var_r31_4172->Create((MKModel *) this->unk3C);
        var_r31_4172 = var_r31_4172->unkC;
        goto loop_6;
    }
    if ((s8 *) M2C_FIELD(this->unk4, s8 **, 8) != NULL) {
        if (PhrasePlayer_IsLevelIniLoaded() != 0) {
            PhrasePlayer_UnloadLevelIni();
        }
        PhrasePlayer_LoadLevelIni(M2C_FIELD(this->unk4, s8 **, 8));
    }
    sp1C = 0;
    temp_r5_4200 = this->unk4;
    temp_f1_4201 = M2C_FIELD(temp_r5_4200, f64 *, 0x30);
    temp_f0_4202 = M2C_FIELD(temp_r5_4200, f64 *, 0x38);
    sp8 = temp_f1_4201;
    sp18 = 0xA0;
    sp20 = temp_f1_4201;
    sp28 = temp_f0_4202;
    sp10 = temp_f0_4202;
    M2C_FIELD(M2C_FIELD(pInstance.unk0, void **, 0x44), M2C_UNK (**)(void *, s32 *, void *, f64), 0x2C)(pInstance.unk0, &sp18, temp_r5_4200, temp_f1_4201);
    temp_r4_4212 = this->unk4;
    M2C_FIELD(&gb, f32 *, 0x37C) = (f32) M2C_FIELD(temp_r4_4212, f32 *, 0x110);
    MKMat_MK2_SetGlowWeights(M2C_FIELD(temp_r4_4212, f32 *, 0x108), M2C_FIELD(temp_r4_4212, f32 *, 0x10C));
}
#endif

void ChunkInfo::Use() {
    this->unk34 = 1;
}

u8 ChunkInfo::IsLoaded() {
    s32 temp_r0_4238;

    temp_r0_4238 = this->unk24;
    if (((u8) (temp_r0_4238 == 3) != 0) && ((s32) this->unk5C > 0)) {
        this->unk24 = 1;
    }
    return temp_r0_4238 == 3;
}

void ChunkInfo::UpdateState() {
    if (M2C_FIELD(*gMK, u8 (**)(void **, s8 *), 0x30)(gMK, this->unk0) != 0) {
        this->unk24 = 3;
    }
}

#if 0 // DRAFT: illegal operand
void ChunkInfo::Load(const char **arg0, int arg1, bool arg2, bool arg3) {
    s32 *sp20;
    s8 sp1D;
    s8 sp1C;
    s32 sp18;
    s8 *sp14;
    s32 sp10;
    ChunkInfo *spC;
    s32 sp8;
    s32 var_r3_4295;
    s8 *var_r4_4316;
    void *temp_r3_4291;
    void *temp_r7_4308;

    temp_r3_4291 = this->unk4;
    if (temp_r3_4291 != NULL) {
        var_r3_4295 = 1;
        if ((u32) M2C_FIELD(temp_r3_4291, u32 *, 0x118) == this) {
            var_r3_4295 = 2;
        }
    } else {
        var_r3_4295 = 0;
    }
    sp8 = var_r3_4295;
    spC = this;
    temp_r7_4308 = this->unk4;
    sp1C = 0;
    sp1D = temp_r7_4308 == NULL;
    sp10 = 0;
    sp20 = &sp8;
    var_r4_4316 = this->unk0;
    sp14 = var_r4_4316;
    sp18 = 1;
    if (temp_r7_4308 != NULL) {
        var_r4_4316 = M2C_FIELD(temp_r7_4308, s8 **, 4);
    }
    this->unk58 = M2C_BITWISE(f32, M2C_FIELD(*gMK, s32 (**)(void **, s8 *, s32 *, s8 **, s32, M2C_UNK, u8, u8), 0x34)(gMK, var_r4_4316, &sp10, arg0, arg1, 0, arg2, arg3));
    this->unk24 = 2;
    Use();
}
#endif

void ChunkInfo::Dequeue() {
    this->unk5C -= 1;
    this->unk24 = 0;
}

void ChunkInfo::Queue() {
    this->unk24 = 1;
    this->unk5C += 1;
}

#if 0 // DRAFT: undefined identifier 'pChunkPropQueue'
s32 ChunkInfo::LoadLine(MKIniLine *arg0) {
    MKIniLine *temp_r3_4412;
    MKIniLine *var_r29_4427;
    MKIniLine *var_r31_4453;
    MKIniLine *var_r3_4452;
    MaterialInfo *temp_r3_4456;
    TerrainInfo *temp_r30_4416;
    f32 var_f1_4388;
    s32 var_r31_4478;

    if (arg0->IsField("") != 0) {
        if ((s16) arg0->unk0 > 1) {
            var_f1_4388 = arg0->GetFloat(1);
        } else {
            var_f1_4388 = 1.0f;
        }
        this->unk48 = var_f1_4388;
        return DataMap_LoadLine(arg0, "", &pChunkPropQueue + 0x98, (u32 *) &this->unk44);
    }
    if (arg0->IsField("") != 0) {
        temp_r3_4412 = arg0->unkC->GetSubLine(arg0);
        if (temp_r3_4412 != NULL) {
            temp_r30_4416 = temp_r3_4412->AllocTerrainInfo();
            temp_r30_4416->unk0 = arg0->GetString(0);
            temp_r30_4416->unk4 = this->unk14;
            this->unk14 = temp_r30_4416;
            var_r29_4427 = arg0->unkC->GetSubLine(arg0);
loop_9:
            if (var_r29_4427 != NULL) {
                this->unk14->LoadLine(var_r29_4427);
                var_r29_4427 = var_r29_4427->unkC->GetNextLine(var_r29_4427);
                goto loop_9;
            }
            return 1;
        }
    }
    if (arg0->IsField("") != 0) {
        var_r3_4452 = arg0->unkC->GetSubLine(arg0);
        var_r31_4453 = var_r3_4452;
loop_14:
        if (var_r31_4453 != NULL) {
            temp_r3_4456 = var_r3_4452->AllocMaterialInfo();
            temp_r3_4456->unkC = this->unk18;
            this->unk18 = temp_r3_4456;
            temp_r3_4456->Init();
            temp_r3_4456->LoadLine(var_r31_4453);
            var_r3_4452 = var_r31_4453->unkC->GetNextLine(var_r31_4453);
            var_r31_4453 = var_r3_4452;
            goto loop_14;
        }
    }
    var_r31_4478 = 0;
    if ((arg0->LoadString("", (s8 **) &this->unk36, 0) != 0) || (arg0->LoadString("", &this->unk3C, 0) != 0) || (arg0->LoadBool("", &this->unk36, 0) != 0) || (arg0->LoadInt("", &this->unk20, 0) != 0) || (arg0->LoadFloat("", &this->unk4C, 0) != 0) || (arg0->LoadFloat("", &this->unk50, 0) != 0) || (arg0->LoadFloat("", &this->unk54, 0) != 0) || (DataMap_LoadLineBitfield(arg0, "", &pChunkPropQueue + 0xD0, &this->unk28) != 0) || (DataMap_LoadLineBitfield(arg0, "", &pChunkPropQueue + 0x108, &this->unk2C) != 0) || (DataMap_LoadLineBitfield(arg0, "", &pChunkPropQueue + 0x130, &this->unk30) != 0)) {
        var_r31_4478 = 1;
    }
    return var_r31_4478;
}
#endif

void ChunkInfo::Deinit() {
    MKHeap *temp_r3_4587;
    void *temp_r30_4586;
    void *temp_r31_4602;

loop_5:
    temp_r31_4602 = this->unk10;
    if (temp_r31_4602 != NULL) {
        temp_r30_4586 = M2C_FIELD(temp_r31_4602, void **, 0x20);
        temp_r3_4587 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_4587 != NULL) {
            ((MKHeap *) (temp_r3_4587->Current()))->Free(temp_r31_4602, NULL, 0);
        } else {
            free((MKHeap *) temp_r31_4602);
        }
        this->unk10 = temp_r30_4586;
        goto loop_5;
    }
}

void ChunkInfo::Init() {
    this->unk0 = NULL;
    this->unk4 = NULL;
    this->unk8 = NULL;
    this->unk58 = 0.0f;
    this->unkC = 1;
    this->unk36 = 0;
    this->unk3C = NULL;
    this->unk3C = NULL;
    this->unk40 = NULL;
    this->unk44 = NULL;
    this->unk48 = 1.0f;
    this->unk10 = NULL;
    this->unk1C = 0;
    this->unk24 = 0;
    this->unk28 = 0xFF;
    this->unk2C = 0xFF;
    this->unk30 = 0xFF;
    this->unk34 = 0;
    this->unk35 = 0;
    this->unk20 = -1;
    this->unk5C = 0;
    this->unk36 = 1;
    this->unk4C = -1.0f;
    this->unk50 = -1.0f;
    this->unk54 = -1.0f;
}

ChunkInfo *LevelInfo::GetChunkByName(const char *arg0) {
    ChunkInfo *var_r31_4657;

    var_r31_4657 = this->unk11C;
loop_4:
    if (var_r31_4657 == NULL) {
        return var_r31_4657;
    }
    if (stricmp((Level *) arg0, var_r31_4657->unk0) == 0) {
        return var_r31_4657;
    }
    var_r31_4657 = var_r31_4657->unk8;
    goto loop_4;
}

void LevelInfo::AddChunkInfo(ChunkInfo *arg0) {
    ChunkInfo *temp_r0_4685;
    ChunkInfo *temp_r0_4696;
    ChunkInfo *var_r3_4691;

    arg0->unk4 = this;
    temp_r0_4685 = this->unk11C;
    if (temp_r0_4685 == NULL) {
        this->unk11C = arg0;
        return;
    }
    var_r3_4691 = temp_r0_4685;
loop_4:
    temp_r0_4696 = var_r3_4691->unk8;
    if (temp_r0_4696 != NULL) {
        var_r3_4691 = temp_r0_4696;
        goto loop_4;
    }
    var_r3_4691->unk8 = arg0;
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void LevelInfo::LoadDone() {
    ChunkInfo *temp_r0_4718;
    s8 *temp_r4_4711;
    s8 *temp_r4_4723;

    temp_r4_4711 = this->unk114;
    if (temp_r4_4711 != NULL) {
        this->unk114 = GetChunkByName(temp_r4_4711);
    } else {
        temp_r0_4718 = this->unk11C;
        if (temp_r0_4718 != NULL) {
            this->unk114 = (s8 *) temp_r0_4718;
        }
    }
    temp_r4_4723 = this->unk118;
    if (temp_r4_4723 != NULL) {
        this->unk118 = GetChunkByName(temp_r4_4723);
        M2C_FIELD(this->unk118, s32 *, 0xC) = 2;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 LevelInfo::LoadLine(MKIniLine *arg0) {
    ChunkInfo *temp_r3_5010;
    MKHeap *temp_r3_5047;
    MKHeap *temp_r3_5050;
    MKHeap *var_r3_5057;
    MKIniLine *var_r27_5068;
    MKIniLine *var_r28_5023;
    f32 var_f1_5043;
    s32 temp_r0_5084;
    s32 temp_ret_5043;
    s32 temp_ret_5110;
    s32 temp_ret_5121;
    s32 var_r26_5097;
    s32 var_r29_5070;
    s32 var_r29_5099;
    u8 temp_r3_5007;
    void *temp_r27_5105;

    if ((arg0->LoadString("", &this->unkC, 0) != 0) || (arg0->LoadInt("", &this->unk10, 0) != 0) || (arg0->LoadString("", &this->unk8, 0) != 0) || (arg0->LoadBool("", (u8 *) &this->unk18, 0) != 0) || (arg0->LoadBool("", this + 0x19, 0) != 0) || (arg0->LoadBool("", this + 0x1A, 0) != 0) || (arg0->LoadBool("", this + 0x1B, 0) != 0) || (arg0->LoadBool("", (u8 *) &this->unk1C, 0) != 0) || (arg0->LoadString("", &this->unk14, 0) != 0) || (arg0->LoadVector4("", &this->unkC0, 0) != 0) || (arg0->LoadVector3("", &this->unkD0, 0) != 0) || (arg0->LoadFloat("", &this->unkE0, 0) != 0) || (arg0->LoadFloat("", &this->unk24, 0) != 0) || (arg0->LoadVector4("", &this->unk30, 0) != 0) || (arg0->LoadInt("", &this->unk28, 0) != 0) || (arg0->LoadFloat("", &this->unk108, 0) != 0) || (arg0->LoadFloat("", &this->unk10C, 0) != 0)) {
        return 1;
    }
    if (arg0->IsField("") != 0) {
        arg0->AsFloat(0, &this->unk110);
        return 1;
    }
    if ((arg0->LoadVector4("", &this->unkA0, 0) != 0) || (arg0->LoadString("", &this->unk114, 0) != 0) || (arg0->LoadString("", &this->unk118, 0) != 0) || (arg0->LoadFloat("", &this->unkF8, 0) != 0) || (arg0->LoadVector3("", &this->unkE8, 0) != 0)) {
        return 1;
    }
    if (arg0->IsField("") != 0) {
        arg0->AsFloat(0, &this->unkB0);
        arg0->AsFloat(1, &this->unkB4);
        goto block_48;
    }
    if (arg0->IsField("") != 0) {
        arg0->AsFloat(0, &this->unkB8);
        arg0->AsFloat(1, &this->unkBC);
        goto block_48;
    }
    temp_r3_5007 = arg0->IsField("");
    if (temp_r3_5007 != 0) {
        temp_r3_5010 = temp_r3_5007->AllocChunkInfo();
        temp_r3_5010->Init();
        AddChunkInfo(temp_r3_5010);
        arg0->AsString(0, &temp_r3_5010->unk0);
        var_r28_5023 = arg0->unkC->GetSubLine(arg0);
loop_33:
        if (var_r28_5023 != NULL) {
            temp_r3_5010->LoadLine(var_r28_5023);
            var_r28_5023 = var_r28_5023->unkC->GetNextLine(var_r28_5023);
            goto loop_33;
        }
        return 1;
    }
    temp_ret_5043 = arg0->IsField("");
    var_f1_5043 = M2C_BITWISE(f32, temp_ret_5043);
    if (temp_ret_5043 != 0) {
        temp_r3_5047 = arg0->GetNmbrOfSubLines();
        this->unk100 = temp_r3_5047;
        temp_r3_5050 = temp_r3_5047->Current();
        if (temp_r3_5050 != NULL) {
            var_r3_5057 = ((MKHeap *) (temp_r3_5050->Current()))->Alloc((s32) temp_r3_5047 * 8, NULL, 0);
        } else {
            var_r3_5057 = malloc((s32) temp_r3_5047 * 8);
        }
        this->unk104 = var_r3_5057;
        var_r27_5068 = arg0->unkC->GetSubLine(arg0);
        var_r29_5070 = 0;
loop_41:
        if (var_r27_5068 != NULL) {
            *(this->unk104 + var_r29_5070) = DataMap_GetValue(&enemyTypeDataMap, var_r27_5068->GetFieldName());
            temp_r0_5084 = var_r29_5070 + 4;
            var_r29_5070 += 8;
            *(this->unk104 + temp_r0_5084) = var_r27_5068->GetInt(0);
            var_r27_5068 = var_r27_5068->unkC->GetNextLine(var_r27_5068);
            goto loop_41;
        }
        goto block_48;
    }
    var_r26_5097 = 0;
    var_r29_5099 = 0;
loop_44:
    temp_r27_5105 = this + var_r29_5099;
    temp_ret_5110 = arg0->LoadVector4(Str_Printf("", var_r26_5097, var_f1_5043), temp_r27_5105 + 0x40, 0);
    if ((temp_ret_5110 != 0) || (temp_ret_5121 = arg0->LoadVector3(Str_Printf("", var_r26_5097, M2C_BITWISE(f32, temp_ret_5110)), temp_r27_5105 + 0x70, 0), var_f1_5043 = M2C_BITWISE(f32, temp_ret_5121), ((temp_ret_5121 == 0) == 0))) {
        return 1;
    }
    var_r26_5097 += 1;
    var_r29_5099 += 0x10;
    if (var_r26_5097 >= 3) {
block_48:
        return 0;
    }
    goto loop_44;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk40'
void LevelInfo::Init() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    this->unkF8 = 1.0f;
    memcpy(&this->unkB0, &this->unk120->unkF0, 8U);
    memcpy(&this->unk40, &this->unk120->unk80, 0x70U);
    memcpy(&this->unkD0, &defaultWind, 0x18U);
    memcpy(&this->unk108, &this->unk120->unk20, 8U);
    memset(&this->unkB8, 0, 0x18U);
    this->unk114 = NULL;
    this->unk118 = NULL;
    this->unk20 = 2;
    this->unk28 = 0;
    this->unk14 = NULL;
    this->unk8 = NULL;
    M2C_FIELD(this, s8 *, 0x1B) = 1;
    M2C_FIELD(this, s8 *, 0x1C) = 1;
    this->unk100 = NULL;
    this->unk104 = NULL;
    sp8 = 1.0f;
    spC = 1.0f;
    this->unk24 = 0.0f;
    sp10 = 0.4f;
    sp14 = 1.0f;
    M2C_FIELD(this, f64 *, 0x30) = (f64) sp8;
    M2C_FIELD(this, f64 *, 0x38) = (f64) sp10;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk110 = 1.0f;
}
#endif

void WorldInfo::AddLevelInfo(LevelInfo *arg0) {
    LevelInfo *temp_r0_5215;
    LevelInfo *temp_r0_5226;
    LevelInfo *var_r3_5221;

    arg0->unk120 = this;
    temp_r0_5215 = this->unk14;
    if (temp_r0_5215 == NULL) {
        this->unk14 = arg0;
        return;
    }
    var_r3_5221 = temp_r0_5215;
loop_4:
    temp_r0_5226 = var_r3_5221->unk124;
    if (temp_r0_5226 != NULL) {
        var_r3_5221 = temp_r0_5226;
        goto loop_4;
    }
    var_r3_5221->unk124 = arg0;
}

void WorldInfo::LoadDone() {
    this->unk74 = this->unk6C * this->unk78;
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
u8 WorldInfo::LoadSize(MKIniLine *arg0, const char *arg1, int *arg2, int *arg3, int arg4) {
    s8 *sp8;
    u8 temp_r3_5256;

    temp_r3_5256 = arg0->IsField(arg1);
    if (temp_r3_5256 != 0) {
        sp8 = NULL;
        arg0->AsString(0, &sp8);
        *arg2 = SizeToInt(sp8, arg4);
        if (arg3 != NULL) {
            *arg3 = *arg2;
        }
    }
    return temp_r3_5256;
}
#endif

#if 0 // DRAFT: function call 'stricmp(Level *, const char[14])' does not match
s32 SizeToInt(const char *arg0, int arg1) {
    M2C_UNK spC;
    f32 sp8;

    if (stricmp((Level *) "", "Level Options") == 0) {
        return arg1;
    }
    if (sscanf(arg0, "", &sp8, (Level *) &spC) == 2) {
        if (stricmp((Level *) &spC, "") == 0) {
            return (s32) (1024.0f * (1024.0f * sp8));
        }
        if (stricmp((Level *) &spC, "") == 0) {
            return (s32) (1024.0f * sp8);
        }
        if (stricmp((Level *) &spC, "") == 0) {
            return (s32) sp8;
        }
        goto block_9;
    }
block_9:
    return atoi(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 WorldInfo::LoadLine(MKIniLine *arg0) {
    f32 var_f1_5673;
    s32 temp_ret_5673;
    s32 temp_ret_5700;
    s32 temp_ret_5711;
    s32 var_r26_5687;
    s32 var_r29_5689;
    void *temp_r27_5695;

    if ((arg0->LoadFloat("", &this->unk0, 0) != 0) || (arg0->LoadInt("", &this->unk4, 0) != 0) || (arg0->LoadFloat("", &this->unk8, 0) != 0) || (arg0->LoadBool("", (u8 *) &this->unkC, 0) != 0) || (arg0->LoadFloat("", &this->unk1C, 0) != 0) || (arg0->LoadFloat("", &this->unk10, 0) != 0) || (arg0->LoadInt("", &this->unk4C, 0) != 0) || (arg0->LoadInt("", &this->unk50, 0) != 0) || (arg0->LoadInt("", &this->unk54, 0) != 0) || (LoadSize(arg0, "", &this->unk58, NULL, M2C_FIELD(&gMKDefaults, s32 *, 0xD8)) != 0) || (LoadSize(arg0, "", &this->unk5C, NULL, 0) != 0) || (LoadSize(arg0, "", &this->unk60, NULL, 0) != 0) || (LoadSize(arg0, "", &this->unk64, NULL, 0) != 0) || (LoadSize(arg0, "", &this->unk68, NULL, 0) != 0) || (arg0->LoadFloat("", &this->unk6C, 0) != 0) || (arg0->LoadFloat("", &this->unk78, 0) != 0) || (arg0->LoadFloat("", &this->unk70, 0) != 0) || (LoadSize(arg0, "", &this->unk2C, &this->unk3C, 0) != 0) || (LoadSize(arg0, "", &this->unk30, &this->unk40, 0) != 0) || (LoadSize(arg0, "", &this->unk34, &this->unk44, 0) != 0) || (LoadSize(arg0, "", &this->unk38, &this->unk48, 0) != 0) || (arg0->LoadVector4("", &this->unkE0, 0) != 0) || (arg0->LoadFloat("", &this->unk20, 0) != 0) || (arg0->LoadFloat("", &this->unk24, 0) != 0) || (LoadSize(arg0, "", &this->unkF8, NULL, 0) != 0) || (LoadSize(arg0, "", &this->unkFC, NULL, 0) != 0) || (arg0->LoadFloat("", (f32 *) (&gb + 0x384), 0) != 0) || (arg0->LoadFloat("", (f32 *) (&gb + 0x388), 0) != 0) || (arg0->LoadFloat("", (f32 *) (&gb + 0x38C), 0) != 0)) {
        return 1;
    }
    temp_ret_5673 = arg0->IsField("");
    var_f1_5673 = M2C_BITWISE(f32, temp_ret_5673);
    if (temp_ret_5673 != 0) {
        arg0->AsFloat(0, &this->unkF0);
        arg0->AsFloat(1, &this->unkF4);
        goto block_37;
    }
    var_r26_5687 = 0;
    var_r29_5689 = 0;
loop_33:
    temp_r27_5695 = this + var_r29_5689;
    temp_ret_5700 = arg0->LoadVector4(Str_Printf("", var_r26_5687, var_f1_5673), temp_r27_5695 + 0x80, 0);
    if ((temp_ret_5700 != 0) || (temp_ret_5711 = arg0->LoadVector3(Str_Printf("", var_r26_5687, M2C_BITWISE(f32, temp_ret_5700)), temp_r27_5695 + 0xB0, 0), var_f1_5673 = M2C_BITWISE(f32, temp_ret_5711), ((temp_ret_5711 == 0) == 0))) {
        return 1;
    }
    var_r26_5687 += 1;
    var_r29_5689 += 0x10;
    if (var_r26_5687 >= 3) {
block_37:
        return 0;
    }
    goto loop_33;
}
#endif

#if 0 // DRAFT: undefined identifier 'defaultClip'
void WorldInfo::Init() {
    this->unk0 = 200000.0f;
    this->unk4 = 0x578;
    this->unk8 = 0.5f;
    this->unk1C = 1.0f;
    M2C_FIELD(this, s8 *, 0xC) = 0;
    this->unk74 = 1.0f;
    this->unk6C = 1.0f;
    this->unk70 = 1.0f;
    this->unk78 = 1.0f;
    this->unk7C = 0;
    memcpy(&this->unkF0, &defaultClip, 8U);
    memcpy(&this->unk80, &defaultLights, 0x70U);
    this->unkF8 = 0x1000;
    this->unkFC = 0x800;
    this->unk18 = 0x1000->AllocChunkInfo();
    this->unk18->Init();
    this->unk18->unk0 = (s8 *) pGlobalLV3Name;
    this->unk18->unkC = 0;
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<PuddleSplash *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<BoneBlurFXDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<EarthBreathWhirlWinds *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<Explosion4 *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<DynamiteExplosion *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<GemMagicFX *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FallingLeaves *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ElectricSparks *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FlyingChunkPS *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<EnemyDeathFX *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ZapArcFX *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<LavaBubbleFX *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<AshesPS *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<SparksPS *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<KDEnvParticleSystem *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<EmbersPS *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<WaterDripPS *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<CrashFirePS *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<LightManager *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<Coronas *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<CollectableSpawner *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FootStepFX *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: undefined identifier 'defaultLights'
void Level_cpp::__sinit() {
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f64 temp_f29_6204;
    f64 temp_f29_6222;
    f64 temp_f2_6181;
    f64 temp_f30_6215;
    f64 temp_f4_6189;
    f64 temp_f5_6193;
    f64 temp_f6_6191;
    f64 temp_f7_6183;
    f64 temp_f8_6197;

    temp_f2_6181 = __frsqrte(2014000.0);
    temp_f7_6183 = __frsqrte(380000.0);
    temp_f4_6189 = temp_f7_6183 * temp_f7_6183;
    temp_f6_6191 = 0.5 * temp_f2_6181;
    temp_f5_6193 = -((2014000.0 * (temp_f2_6181 * temp_f2_6181)) - 3.0);
    sp78 = 0.0f;
    sp7C = 0.3f;
    temp_f8_6197 = temp_f6_6191 * temp_f5_6193;
    sp80 = 0.7f;
    sp84 = 1.0f;
    temp_f29_6204 = 0.5 * temp_f7_6183 * -((380000.0 * temp_f4_6189) - 3.0);
    sp68 = 0.65f;
    sp6C = 0.65f;
    sp70 = 0.65f;
    sp74 = 1.0f;
    temp_f30_6215 = 0.5 * temp_f8_6197 * -((2014000.0 * (temp_f8_6197 * temp_f8_6197)) - 3.0);
    sp58 = 0.65f;
    sp5C = 0.65f;
    sp60 = 0.65f;
    temp_f29_6222 = 0.5 * temp_f29_6204 * -((380000.0 * (temp_f29_6204 * temp_f29_6204)) - 3.0);
    sp64 = 1.0f;
    M2C_FIELD(&defaultLights, f64 *, 0) = (f64) sp78;
    M2C_FIELD(&defaultLights, f64 *, 8) = (f64) sp80;
    M2C_FIELD(&defaultLights, f64 *, 0x10) = (f64) sp68;
    M2C_FIELD(&defaultLights, f64 *, 0x18) = (f64) sp70;
    M2C_FIELD(&defaultLights, f64 *, 0x20) = (f64) sp58;
    M2C_FIELD(&defaultLights, f64 *, 0x28) = (f64) sp60;
    sp48 = 0.0f;
    sp4C = 1.0f;
    sp50 = 0.0f;
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f30_6215 * -((2014000.0 * (temp_f30_6215 * temp_f30_6215)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f29_6222 * -((380000.0 * (temp_f29_6222 * temp_f29_6222)) - 3.0)));
    sp40 = 0.0f;
    sp30 = 0.0f;
    sp10 = 1.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    sp38 = 1.0f;
    sp3C = -1.0f;
    sp28 = -1.0f;
    sp2C = -1.0f;
    sp18 = 0.5f;
    sp1C = 0.5f;
    sp20 = 0.5f;
    sp24 = 1.0f;
    M2C_FIELD(&defaultWind, f64 *, 0) = (f64) sp8;
    M2C_FIELD(&defaultLights, f64 *, 0x30) = (f64) sp48;
    M2C_FIELD(&defaultLights, f64 *, 0x38) = (f64) sp50;
    M2C_FIELD(&defaultLights, f64 *, 0x40) = (f64) sp38;
    M2C_FIELD(&defaultLights, f64 *, 0x48) = (f64) sp40;
    M2C_FIELD(&defaultLights, f64 *, 0x50) = (f64) sp28;
    M2C_FIELD(&defaultLights, f64 *, 0x58) = (f64) sp30;
    M2C_FIELD(&defaultLights, f64 *, 0x60) = (f64) sp18;
    M2C_FIELD(&defaultLights, f64 *, 0x68) = (f64) sp20;
    M2C_FIELD(&defaultWind, f64 *, 8) = (f64) sp10;
}
#endif
