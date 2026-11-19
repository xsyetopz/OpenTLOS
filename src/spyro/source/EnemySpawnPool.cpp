#include "spyro/source/EnemySpawnPool.h"
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
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "spyro/source/DataMap.h"
#include <m2c_macros.h>

M2C_UNK free(M2C_UNK *);                            /* extern */
M2C_UNK *malloc(s32);                               /* extern */
extern DataMap enemyTypeDataMap;
extern M2C_UNK gEmptyPtrListDL;
extern MKSceneManager *gMK;
extern M2C_UNK gb;
extern s32 iSpawnPools;
extern M2C_UNK *pSpawnPools;

#if 0 // DRAFT: illegal operand
void EnemySpawnPool_Destroy(Enemy *arg0) {
    s32 spC;
    s32 sp8;
    s32 temp_r4_52;
    s32 var_ctr_20;
    s32 var_r31_18;
    u32 **temp_r3_53;
    u32 **var_r30_30;
    u32 *temp_r3_66;
    u32 *temp_r4_56;

    if ((arg0 != NULL) && (var_r31_18 = 0, var_ctr_20 = iSpawnPools, (((s32) iSpawnPools > 0) != 0))) {
loop_2:
        if ((s32) arg0->unkA38->unkF4 == (s32) *(pSpawnPools + var_r31_18)) {
            var_r30_30 = (unsigned long **) (*(pSpawnPools + (var_r31_18 + 4)));
loop_7:
            if (var_r30_30 != NULL) {
                temp_r3_66 = *var_r30_30;
                if (temp_r3_66 == NULL) {
                    return;
                }
                if ((u32) *temp_r3_66 == arg0) {
                    spC = 0;
                    sp8 = 0x15F;
                    arg0->Message(&sp8);
                    arg0->Disable();
                    temp_r4_52 = var_r31_18 + 4;
                    temp_r3_53 = (unsigned long **) (*(pSpawnPools + temp_r4_52));
                    *(pSpawnPools + temp_r4_52) = (long) (temp_r3_53 + 4);
                    temp_r4_56 = *temp_r3_53;
                    *temp_r3_53 = *var_r30_30;
                    *var_r30_30 = temp_r4_56;
                    return;
                }
                var_r30_30 += 4;
                goto loop_7;
            }
        } else {
            var_r31_18 += 8;
            var_ctr_20 -= 1;
            if (var_ctr_20 == 0) {

            } else {
                goto loop_2;
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA48'
Character *EnemySpawnPool_Recycle(int arg0, SpawnerObject *arg1) {
    Character ***var_r31_100;
    Character **temp_r3_127;
    Character *temp_r30_103;
    s32 var_ctr_92;
    s32 var_r4_89;
    u32 *temp_r3_104;

    var_r4_89 = 0;
    var_ctr_92 = iSpawnPools;
    if ((s32) iSpawnPools > 0) {
loop_1:
        if (arg0 == (s32) *(pSpawnPools + var_r4_89)) {
            var_r31_100 = (Character ***) (*(pSpawnPools + (var_r4_89 + 4)));
loop_8:
            if (var_r31_100 != NULL) {
                temp_r3_127 = *var_r31_100;
                if (temp_r3_127 == NULL) {
                    goto block_12;
                }
                temp_r30_103 = *temp_r3_127;
                temp_r3_104 = temp_r30_103->unkA48;
                if (((temp_r3_104 == NULL) || (arg1 != (u32) *temp_r3_104)) && (temp_r30_103->IsActive() == 0)) {
                    temp_r30_103->Recycle();
                    return temp_r30_103;
                }
                var_r31_100 += 4;
                goto loop_8;
            }
            goto block_12;
        }
        var_r4_89 += 8;
        var_ctr_92 -= 1;
        if (var_ctr_92 == 0) {
            goto block_12;
        }
        goto loop_1;
    }
block_12:
    return NULL;
}
#endif

MKProp *EnemySpawnPool_Create(int arg0) {
    MKProp ***temp_r3_165;
    s32 temp_r4_157;
    s32 var_ctr_150;
    s32 var_r4_148;
    void *temp_r3_158;

    var_r4_148 = 0;
    var_ctr_150 = iSpawnPools;
    if ((s32) iSpawnPools > 0) {
loop_1:
        if (arg0 == (s32) *(pSpawnPools + var_r4_148)) {
            temp_r4_157 = var_r4_148 + 4;
            temp_r3_158 = (void *) (*(pSpawnPools + temp_r4_157));
            if ((u32) M2C_FIELD(temp_r3_158, u32 *, -4) == 0U) {
                return NULL;
            }
            temp_r3_165 = (MKProp ***) (((u8 *) temp_r3_158) - 4);
            *(pSpawnPools + temp_r4_157) = (long) (temp_r3_165);
            return **temp_r3_165;
        }
        var_r4_148 += 8;
        var_ctr_150 -= 1;
        if (var_ctr_150 == 0) {
            /* Duplicate return node #6. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_1;
    }
    return NULL;
}

#if 0 // DRAFT: undefined identifier 'EnemySpawnPool_Recycle'
void EnemySpawnPool_Action(SpawnAction arg0, int arg1, MKProp **arg2, SpawnerObject *arg3) {
    switch ((s32) arg0) {                           /* irregular */
    case 0:
        *arg2 = EnemySpawnPool_Create(arg1);
        return;
    case 1:
        *arg2 = EnemySpawnPool_Recycle(arg1, arg3);
        return;
    case 2:
        EnemySpawnPool_Destroy((Enemy *) *arg2);
        return;
    }
}
#endif

void EnemySpawnPool_Deinit() {
    M2C_UNK *temp_r0_239;
    M2C_UNK *temp_r0_258;
    M2C_UNK *temp_r28_282;
    M2C_UNK *temp_r30_232;
    M2C_UNK *var_r29_235;
    M2C_UNK *var_r3_236;
    M2C_UNK *var_r4_234;
    s32 temp_r28_233;
    s32 var_r27_228;
    s32 var_r31_229;
    u32 temp_r0_244;

    if ((s32) iSpawnPools > 0) {
        var_r27_228 = 0;
        var_r31_229 = 0;
loop_16:
        if (var_r27_228 < (s32) iSpawnPools) {
            temp_r30_232 = pSpawnPools;
            temp_r28_233 = var_r31_229 + 4;
            var_r4_234 = (long *) (*(temp_r30_232 + temp_r28_233));
            var_r29_235 = var_r4_234;
            var_r3_236 = var_r4_234;
loop_5:
            temp_r0_244 = M2C_FIELD(var_r3_236, u32 *, -4);
            var_r3_236 -= 4;
            if (temp_r0_244 != 0U) {
                temp_r0_239 = (long *) (*var_r3_236);
                if (temp_r0_239 < var_r29_235) {
                    var_r29_235 = temp_r0_239;
                }
                goto loop_5;
            }
            if (var_r3_236 != &gEmptyPtrListDL) {
loop_11:
                temp_r0_258 = (long *) (*var_r4_234);
                if (temp_r0_258 != NULL) {
                    if (temp_r0_258 < var_r29_235) {
                        var_r29_235 = temp_r0_258;
                    }
                    var_r4_234 += 4;
                    goto loop_11;
                }
                if (MKHeap::Current() != NULL) {
                    ((MKHeap *) (MKHeap::Current()))->Free(var_r29_235, NULL, 0);
                } else {
                    free(var_r29_235);
                }
            }
            var_r31_229 += 8;
            *(temp_r30_232 + temp_r28_233) = 0;
            var_r27_228 += 1;
            goto loop_16;
        }
        temp_r28_282 = pSpawnPools;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r28_282, NULL, 0);
        } else {
            free(temp_r28_282);
        }
    }
    iSpawnPools = 0;
    pSpawnPools = NULL;
}

#if 0 // DRAFT: pointer/array required
void EnemySpawnPool_Init() {
    M2C_UNK *temp_r3_407;
    M2C_UNK *temp_r3_414;
    M2C_UNK *temp_r3_421;
    M2C_UNK *temp_r4_438;
    M2C_UNK *var_r27_432;
    M2C_UNK *var_r3_339;
    M2C_UNK *var_r3_395;
    M2C_UNK *var_r5_406;
    s32 temp_r24_331;
    s32 temp_r26_379;
    s32 temp_r26_431;
    s32 temp_r3_325;
    s32 var_ctr_410;
    s32 var_r25_350;
    s32 var_r28_349;
    u32 temp_r27_369;
    void *temp_r29_357;
    void *temp_r3_356;
    void *temp_r4_316;
    void *temp_r5_366;
    void *var_r3_319;
    void *var_r3_360;
    void *var_r3_371;

    temp_r4_316 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x18);
    if (temp_r4_316 != NULL) {
        var_r3_319 = M2C_FIELD(temp_r4_316, void **, 4);
    } else {
        var_r3_319 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x24), void **, 4);
    }
    temp_r3_325 = M2C_FIELD(var_r3_319, s32 *, 0x100);
    iSpawnPools = temp_r3_325;
    pSpawnPools = NULL;
    if (temp_r3_325 > 0) {
        temp_r24_331 = temp_r3_325 * 8;
        if (MKHeap::Current() != NULL) {
            var_r3_339 = (long *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r24_331, NULL, 0));
        } else {
            var_r3_339 = malloc(temp_r24_331);
        }
        pSpawnPools = var_r3_339;
        var_r28_349 = 0;
        var_r25_350 = 0;
loop_27:
        if (var_r28_349 < (s32) iSpawnPools) {
            temp_r3_356 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x18);
            temp_r29_357 = pSpawnPools + var_r25_350;
            if (temp_r3_356 != NULL) {
                var_r3_360 = M2C_FIELD(temp_r3_356, void **, 4);
            } else {
                var_r3_360 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x24), void **, 4);
            }
            temp_r5_366 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x18);
            temp_r27_369 = *(M2C_FIELD(var_r3_360, s32 *, 0x104) + var_r25_350);
            if (temp_r5_366 != NULL) {
                var_r3_371 = M2C_FIELD(temp_r5_366, void **, 4);
            } else {
                var_r3_371 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x24), void **, 4);
            }
            temp_r26_379 = *(M2C_FIELD(var_r3_371, s32 *, 0x104) + (var_r25_350 + 4));
            M2C_FIELD(temp_r29_357, u32 *, 0) = temp_r27_369;
            if (temp_r26_379 == 0) {
                M2C_FIELD(temp_r29_357, M2C_UNK **, 4) = (M2C_UNK *) (&gEmptyPtrListDL + 4);
            } else {
                if (MKHeap::Current() != NULL) {
                    var_r3_395 = (long *) (((MKHeap *) (MKHeap::Current()))->Alloc(((temp_r26_379 * 2) + 2) * 4, NULL, 0));
                } else {
                    var_r3_395 = malloc(((temp_r26_379 * 2) + 2) * 4);
                }
                M2C_FIELD(temp_r29_357, M2C_UNK **, 4) = var_r3_395;
                var_r5_406 = M2C_FIELD(temp_r29_357, M2C_UNK **, 4);
                temp_r3_407 = &var_r5_406[temp_r26_379];
                M2C_FIELD(temp_r29_357, M2C_UNK **, 4) = temp_r3_407;
                *temp_r3_407 = NULL;
                var_ctr_410 = temp_r26_379;
                if (temp_r26_379 > 0) {
                    do {
                        temp_r3_414 = M2C_FIELD(temp_r29_357, M2C_UNK **, 4);
                        M2C_FIELD(temp_r29_357, M2C_UNK **, 4) = (M2C_UNK *) (temp_r3_414 + 4);
                        M2C_FIELD(temp_r3_414, M2C_UNK **, 4) = var_r5_406;
                        var_r5_406 += 4;
                        var_ctr_410 -= 1;
                    } while (var_ctr_410 != 0);
                }
                temp_r3_421 = M2C_FIELD(temp_r29_357, M2C_UNK **, 4);
                M2C_FIELD(temp_r29_357, M2C_UNK **, 4) = (M2C_UNK *) (temp_r3_421 + 4);
                M2C_FIELD(temp_r3_421, M2C_UNK **, 4) = NULL;
            }
            temp_r26_431 = DataMap_GetName(&enemyTypeDataMap, temp_r27_369);
            var_r27_432 = M2C_FIELD(temp_r29_357, M2C_UNK **, 4) - 4;
loop_24:
            if ((var_r27_432 != NULL) && ((M2C_UNK *) *var_r27_432 != NULL)) {
                temp_r4_438 = (long *) (*var_r27_432);
                var_r27_432 -= 4;
                *temp_r4_438 = (const char *) (gMK->CreateProp((s8 *) temp_r26_431));
                goto loop_24;
            }
            var_r28_349 += 1;
            var_r25_350 += 8;
            goto loop_27;
        }
    }
}
#endif
