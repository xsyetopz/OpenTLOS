#include "spyro/source/EnemySpawnPool.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "spyro/source/Character.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/SpawnerObject.h"
#include "unplaced_enums.h"
#include "spyro/source/DataMap.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(s32);                                /* extern */
extern DataMap enemyTypeDataMap;
extern M2C_UNK gEmptyPtrListDL;
extern MKSceneManager *gMK;
extern M2C_UNK gb;
extern s32 iSpawnPools;
extern MKHeap *pSpawnPools;

#if 0 // DRAFT: illegal explicit conversion from 'MKHeap' to
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
        if ((s32) M2C_FIELD(arg0->unkA20, s32 *, 0xF4) == (s32) *(pSpawnPools + var_r31_18)) {
            var_r30_30 = *(pSpawnPools + (var_r31_18 + 4));
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
                    temp_r3_53 = *(pSpawnPools + temp_r4_52);
                    *(pSpawnPools + temp_r4_52) = temp_r3_53 + 4;
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

#if 0 // DRAFT: illegal explicit conversion from 'MKHeap' to
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
            var_r31_100 = *(pSpawnPools + (var_r4_89 + 4));
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

#if 0 // DRAFT: illegal explicit conversion from 'MKHeap' to
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
            temp_r3_158 = *(pSpawnPools + temp_r4_157);
            if ((u32) M2C_FIELD(temp_r3_158, u32 *, -4) == 0U) {
                return NULL;
            }
            temp_r3_165 = temp_r3_158 - 4;
            *(pSpawnPools + temp_r4_157) = temp_r3_165;
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
#endif

#if 0 // DRAFT: undefined identifier 'EnemySpawnPool_Create'
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

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap' to
void EnemySpawnPool_Deinit() {
    MKHeap *temp_r0_239;
    MKHeap *temp_r0_258;
    MKHeap *temp_r28_282;
    MKHeap *temp_r30_232;
    MKHeap *temp_r3_261;
    MKHeap *temp_r3_283;
    MKHeap *var_r29_235;
    MKHeap *var_r3_236;
    MKHeap *var_r4_234;
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
            var_r4_234 = *(temp_r30_232 + temp_r28_233);
            var_r29_235 = var_r4_234;
            var_r3_236 = var_r4_234;
loop_5:
            temp_r0_244 = M2C_FIELD(var_r3_236, u32 *, -4);
            var_r3_236 -= 4;
            if (temp_r0_244 != 0U) {
                temp_r0_239 = var_r3_236->unk0;
                if (temp_r0_239 < var_r29_235) {
                    var_r29_235 = temp_r0_239;
                }
                goto loop_5;
            }
            if (var_r3_236 != &gEmptyPtrListDL) {
loop_11:
                temp_r0_258 = var_r4_234->unk0;
                if (temp_r0_258 != NULL) {
                    if (temp_r0_258 < var_r29_235) {
                        var_r29_235 = temp_r0_258;
                    }
                    var_r4_234 += 4;
                    goto loop_11;
                }
                temp_r3_261 = var_r3_236->Current();
                if (temp_r3_261 != NULL) {
                    ((MKHeap *) (temp_r3_261->Current()))->Free(var_r29_235, NULL, 0);
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
        temp_r3_283 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_283 != NULL) {
            ((MKHeap *) (temp_r3_283->Current()))->Free(temp_r28_282, NULL, 0);
        } else {
            free(temp_r28_282);
        }
    }
    iSpawnPools = 0;
    pSpawnPools = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void EnemySpawnPool_Init() {
    MKHeap *temp_r3_332;
    MKHeap *temp_r3_377;
    MKHeap *temp_r3_386;
    MKHeap *temp_r3_407;
    MKHeap *temp_r3_414;
    MKHeap *temp_r3_421;
    MKHeap *var_r3_339;
    MKHeap *var_r3_395;
    MKHeap *var_r5_406;
    s32 temp_r24_331;
    s32 temp_r26_379;
    s32 temp_r26_431;
    s32 temp_r3_325;
    s32 var_ctr_410;
    s32 var_r25_350;
    s32 var_r28_349;
    u32 temp_r27_369;
    void ***var_r27_432;
    void **temp_r4_438;
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
        temp_r3_332 = ((MKHeap *) temp_r3_325)->Current();
        if (temp_r3_332 != NULL) {
            var_r3_339 = ((MKHeap *) (temp_r3_332->Current()))->Alloc(temp_r24_331, NULL, 0);
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
            temp_r3_377 = M2C_FIELD(var_r3_371, MKHeap **, 0x104);
            temp_r26_379 = *(temp_r3_377 + (var_r25_350 + 4));
            M2C_FIELD(temp_r29_357, u32 *, 0) = temp_r27_369;
            if (temp_r26_379 == 0) {
                M2C_FIELD(temp_r29_357, MKHeap **, 4) = (MKHeap *) (&gEmptyPtrListDL + 4);
            } else {
                temp_r3_386 = temp_r3_377->Current();
                if (temp_r3_386 != NULL) {
                    var_r3_395 = ((MKHeap *) (temp_r3_386->Current()))->Alloc(((temp_r26_379 * 2) + 2) * 4, NULL, 0);
                } else {
                    var_r3_395 = malloc(((temp_r26_379 * 2) + 2) * 4);
                }
                M2C_FIELD(temp_r29_357, MKHeap **, 4) = var_r3_395;
                var_r5_406 = M2C_FIELD(temp_r29_357, MKHeap **, 4);
                temp_r3_407 = var_r5_406 + (temp_r26_379 * 4);
                M2C_FIELD(temp_r29_357, MKHeap **, 4) = temp_r3_407;
                temp_r3_407->unk0 = NULL;
                var_ctr_410 = temp_r26_379;
                if (temp_r26_379 > 0) {
                    do {
                        temp_r3_414 = M2C_FIELD(temp_r29_357, MKHeap **, 4);
                        M2C_FIELD(temp_r29_357, MKHeap **, 4) = (MKHeap *) &temp_r3_414->unk4;
                        temp_r3_414->unk4 = (s32) var_r5_406;
                        var_r5_406 += 4;
                        var_ctr_410 -= 1;
                    } while (var_ctr_410 != 0);
                }
                temp_r3_421 = M2C_FIELD(temp_r29_357, MKHeap **, 4);
                M2C_FIELD(temp_r29_357, MKHeap **, 4) = (MKHeap *) &temp_r3_421->unk4;
                temp_r3_421->unk4 = 0;
            }
            temp_r26_431 = DataMap_GetName(&enemyTypeDataMap, temp_r27_369);
            var_r27_432 = M2C_FIELD(temp_r29_357, MKHeap **, 4) - 4;
loop_24:
            if ((var_r27_432 != NULL) && ((void **) *var_r27_432 != NULL)) {
                temp_r4_438 = *var_r27_432;
                var_r27_432 -= 4;
                *temp_r4_438 = gMK->CreateProp((s8 *) temp_r26_431);
                goto loop_24;
            }
            var_r28_349 += 1;
            var_r25_350 += 8;
            goto loop_27;
        }
    }
}
#endif
