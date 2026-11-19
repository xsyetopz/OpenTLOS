#include "spyro/source/EnemyAttackPattern.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameData.h"
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
#include "common/Source/StdMath.h"
#include "spyro/source/DataMap.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 fCachedOwnerAngle;
extern f32 fCachedTargetAngle;
extern s32 gViewSeed;
extern EnemyDescriptor *pCurrEnemyDescriptor;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'DataMap'
static DataMap dataMapEAPCondition[0x10] = {
    { 0, "None" },
    { 1, "InsideDistRange" },
    { 2, "OutsideDistRange" },
    { 3, "InsideAngleRange" },
    { 4, "OutsideAngleRange" },
    { 5, "OnPrevAttackHit" },
    { 6, "OnPrevAttackMiss" },
    { 7, "InDefensiveThreshold" },
    { 8, "OutDefensiveThreshold" },
    { 9, "OnHitDelay" },
    { 0xA, "OnMissDelay" },
    { 0xB, "OutsideRegion" },
    { 0xC, "OutsideLOS" },
    { 0xD, "OnHit" },
    { 0xE, "NotOnScreen" },
    { 0, NULL },
};
#endif

#if 0 // DRAFT: function call 'DataMap_GetValue(DataMap, signed char *)' does not match 'DataMap_GetValue(const DataMap *, const char *)'
void EAPCondition::LoadLine(MKIniLine *arg0) {
    s32 temp_r0_27;

    this->unk4 = DataMap_GetValue(dataMapEAPCondition, arg0->GetFieldName());
    this->unk8 = EAP_GetEAPConditionType((eEAPCondition) this->unk4);
    temp_r0_27 = this->unk4;
    if ((temp_r0_27 >= 7) || (temp_r0_27 < 5)) {
        this->unkC = arg0->GetFloat(0);
        return;
    }
    this->unkC = arg0->GetFloat(2);
    this->unk0 = (EnemyAttack *) (pCurrEnemyDescriptor->GetAttack(arg0->GetInt(1)));
}
#endif

void EAPCondition::Init() {
    this->unk0 = NULL;
    this->unk4 = 0;
    this->unk8 = 0;
    this->unkC = 0.0f;
}

void EAPItem::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r30_83;
    s32 temp_r0_86;
    s32 temp_r31_89;
    s32 var_r29_112;
    s32 var_r31_113;
    void *var_r3_97;

    var_r30_83 = arg0->unkC->GetSubLine(arg0);
    this->unk8 = arg0->GetNmbrOfSubLines();
    temp_r0_86 = this->unk8;
    if (temp_r0_86 != 0) {
        temp_r31_89 = temp_r0_86 * 0x10;
        if (MKHeap::Current() != NULL) {
            var_r3_97 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r31_89, NULL, 0);
        } else {
            var_r3_97 = malloc(temp_r31_89);
        }
        this->unk4 = var_r3_97;
    }
    this->unk0 = (EnemyAttack *) (pCurrEnemyDescriptor->GetAttack(arg0->GetInt(0)));
    var_r29_112 = 0;
    var_r31_113 = 0;
loop_7:
    if (var_r29_112 < (s32) this->unk8) {
        ((EAPCondition *) (((u8 *) this->unk4) + var_r31_113))->Init();
        ((EAPCondition *) (((u8 *) this->unk4) + var_r31_113))->LoadLine(var_r30_83);
        var_r30_83 = var_r30_83->unkC->GetNextLine(var_r30_83);
        var_r29_112 += 1;
        var_r31_113 += 0x10;
        goto loop_7;
    }
}

void EAPItem::Deinit() {
    void *temp_r31_148;

    temp_r31_148 = this->unk4;
    if (temp_r31_148 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_148, NULL, 0);
        } else {
            free(temp_r31_148);
        }
    }
    this->unk0 = NULL;
    this->unk4 = NULL;
    this->unk8 = 0;
}

void EAPItem::Init() {
    this->unk0 = NULL;
    this->unk4 = NULL;
    this->unk8 = 0;
}

void EnemyAttackPattern::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r30_198;
    s32 temp_r0_201;
    s32 temp_r31_204;
    s32 var_r29_220;
    s32 var_r31_221;
    void *var_r3_212;

    var_r30_198 = arg0->unkC->GetSubLine(arg0);
    this->unk4 = arg0->GetNmbrOfSubLines();
    temp_r0_201 = this->unk4;
    if (temp_r0_201 != 0) {
        temp_r31_204 = temp_r0_201 * 0xC;
        if (MKHeap::Current() != NULL) {
            var_r3_212 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r31_204, NULL, 0);
        } else {
            var_r3_212 = malloc(temp_r31_204);
        }
        this->unk0 = var_r3_212;
    }
    var_r29_220 = 0;
    var_r31_221 = 0;
loop_7:
    if (var_r29_220 < (s32) this->unk4) {
        ((EAPItem *) (((u8 *) this->unk0) + var_r31_221))->Init();
        ((EAPItem *) (((u8 *) this->unk0) + var_r31_221))->LoadLine(var_r30_198);
        var_r30_198 = var_r30_198->unkC->GetNextLine(var_r30_198);
        var_r29_220 += 1;
        var_r31_221 += 0xC;
        goto loop_7;
    }
}

void EnemyAttackPattern::Deinit() {
    s32 var_r30_259;
    s32 var_r31_260;
    void *temp_r31_272;

    if ((void *) this->unk0 != NULL) {
        var_r30_259 = 0;
        var_r31_260 = 0;
loop_3:
        if (var_r30_259 < (s32) this->unk4) {
            ((EAPItem *) (((u8 *) this->unk0) + var_r31_260))->Deinit();
            var_r30_259 += 1;
            var_r31_260 += 0xC;
            goto loop_3;
        }
        temp_r31_272 = this->unk0;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_272, NULL, 0);
        } else {
            free(temp_r31_272);
        }
    }
    this->unk0 = NULL;
    this->unk4 = 0;
}

void EnemyAttackPattern::Init() {
    this->unk0 = NULL;
    this->unk4 = 0;
}

void EAPManagerDescriptor::LoadLine(EnemyDescriptor *arg0, MKIniLine *arg1) {
    MKIniLine *temp_r0_318;
    MKIniLine *var_r30_321;
    s32 temp_r0_324;
    s32 temp_r31_327;
    s32 var_r29_343;
    s32 var_r31_344;
    void *var_r3_335;

    temp_r0_318 = arg1->unkC->GetSubLine(arg1);
    pCurrEnemyDescriptor = arg0;
    var_r30_321 = temp_r0_318;
    this->unk4 = arg1->GetNmbrOfSubLines();
    temp_r0_324 = this->unk4;
    if (temp_r0_324 != 0) {
        temp_r31_327 = temp_r0_324 * 8;
        if (MKHeap::Current() != NULL) {
            var_r3_335 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r31_327, NULL, 0);
        } else {
            var_r3_335 = malloc(temp_r31_327);
        }
        this->unk0 = var_r3_335;
    }
    var_r29_343 = 0;
    var_r31_344 = 0;
loop_7:
    if (var_r29_343 < (s32) this->unk4) {
        ((EnemyAttackPattern *) (((u8 *) this->unk0) + var_r31_344))->Init();
        ((EnemyAttackPattern *) (((u8 *) this->unk0) + var_r31_344))->LoadLine(var_r30_321);
        var_r30_321 = var_r30_321->unkC->GetNextLine(var_r30_321);
        var_r29_343 += 1;
        var_r31_344 += 8;
        goto loop_7;
    }
    pCurrEnemyDescriptor = NULL;
}

void EAPManagerDescriptor::Deinit() {
    s32 var_r30_384;
    s32 var_r31_385;
    void *temp_r31_397;

    if ((void *) this->unk0 != NULL) {
        var_r30_384 = 0;
        var_r31_385 = 0;
loop_3:
        if (var_r30_384 < (s32) this->unk4) {
            ((EnemyAttackPattern *) (((u8 *) this->unk0) + var_r31_385))->Deinit();
            var_r30_384 += 1;
            var_r31_385 += 8;
            goto loop_3;
        }
        temp_r31_397 = this->unk0;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_397, NULL, 0);
        } else {
            free(temp_r31_397);
        }
    }
    this->unk0 = NULL;
    this->unk4 = 0;
}

#if 0 // DRAFT: illegal use of keyword
u32 EAPManager::EvaluateCondition(EAPItem *arg0, EAPCondition *arg1, Enemy *arg2, AITargetData *arg3) {
    EnemyAttack **temp_r3_563;
    EnemyAttack **temp_r3_579;
    f32 temp_f0_498;
    f32 temp_f0_535;
    f32 temp_f1_451;
    f32 temp_f1_467;
    f32 temp_f1_491;
    f32 temp_f1_528;
    f32 temp_f31_450;
    f32 temp_f31_466;
    f32 temp_f31_487;
    f32 temp_f31_524;
    s32 temp_r0_438;
    u32 var_r4_560;
    u32 var_r4_576;
    u8 temp_r4_612;
    u8 var_r0_534;

    if ((s32) arg1->unk8 == 1) {
        return 0U;
    }
    temp_r0_438 = arg1->unk4;
    if ((u32) temp_r0_438 <= 0xEU) {
        switch (temp_r0_438) {
        case 1:
            temp_f31_450 = arg0->unk0->unk28;
            temp_f1_451 = arg3->GetDist();
            if ((temp_f1_451 >= arg0->unk0->unk24) && (temp_f1_451 <= temp_f31_450)) {
                return 1U;
            }
            /* Duplicate return node #44. Try simplifying control flow for better match */
            return 0U;
        case 2:
            temp_f31_466 = arg0->unk0->unk28;
            temp_f1_467 = arg3->GetDist();
            if (!(temp_f1_467 >= arg0->unk0->unk24) || !(temp_f1_467 <= temp_f31_466)) {
                return 1U;
            }
            /* Duplicate return node #44. Try simplifying control flow for better match */
            return 0U;
        case 3:
            temp_f31_487 = NormaliseAngle(fCachedOwnerAngle + arg0->unk0->unk2C);
            temp_f1_491 = NormaliseAngle(fCachedOwnerAngle + arg0->unk0->unk30);
            if (temp_f31_487 > temp_f1_491) {
                temp_f0_498 = 6.2831855f - temp_f31_487;
                if ((fCachedTargetAngle > temp_f31_487) || ((fCachedTargetAngle + temp_f0_498) < (temp_f1_491 + temp_f0_498))) {
                    return 1U;
                }
                /* Duplicate return node #44. Try simplifying control flow for better match */
                return 0U;
            }
            if ((fCachedTargetAngle > temp_f31_487) && ((fCachedTargetAngle - temp_f31_487) < (temp_f1_491 - temp_f31_487))) {
                return 1U;
            }
            /* Duplicate return node #44. Try simplifying control flow for better match */
            return 0U;
        case 4:
            temp_f31_524 = NormaliseAngle(fCachedOwnerAngle + arg0->unk0->unk2C);
            temp_f1_528 = NormaliseAngle(fCachedOwnerAngle + arg0->unk0->unk30);
            if (temp_f31_524 > temp_f1_528) {
                var_r0_534 = 0;
                temp_f0_535 = 6.2831855f - temp_f31_524;
                if ((fCachedTargetAngle > temp_f31_524) || ((fCachedTargetAngle + temp_f0_535) < (temp_f1_528 + temp_f0_535))) {
                    var_r0_534 = 1;
                }
            } else {
                var_r0_534 = 0;
                if ((fCachedTargetAngle > temp_f31_524) && ((fCachedTargetAngle - temp_f31_524) < (temp_f1_528 - temp_f31_524))) {
                    var_r0_534 = 1;
                }
            }
            return var_r0_534 == 0;
        case 5:
            var_r4_560 = 0;
            if (((u8) this->unk10 >> 7U) & 1) {
                temp_r3_563 = this->unk8;
                if ((temp_r3_563 != NULL) && ((EnemyAttack *) *temp_r3_563 == (EnemyAttack *) arg1->unk0)) {
                    var_r4_560 = 1;
                }
            }
            return var_r4_560;
        case 6:
            var_r4_576 = 0;
            if (!(((u8) this->unk10 >> 7U) & 1)) {
                temp_r3_579 = this->unk8;
                if ((temp_r3_579 != NULL) && ((EnemyAttack *) *temp_r3_579 == (EnemyAttack *) arg1->unk0)) {
                    var_r4_576 = 1;
                }
            }
            return var_r4_576;
        case 7:
            arg2->unkA38->GetEnemyAttackSetting((EnemySettingType) 7, arg0->unk0);
            return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
        case 8:
            arg2->unkA38->GetEnemyAttackSetting((EnemySettingType) 7, arg0->unk0);
            return (u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU;
        case 11:
            temp_r4_612 = M2C_FIELD(arg3, u8 *, 0x49);
            if (!((temp_r4_612 >> 6U) & 1) || ((temp_r4_612 >> 5U) & 1)) {
                return 1U;
            }
            /* Duplicate return node #44. Try simplifying control flow for better match */
            return 0U;
        case 12:
            return (((u8) M2C_FIELD(arg3, u8 *, 0x49) >> 4U) & 1) == 0;
        case 13:
            return ((u8) this->unk10 >> 6U) & 1;
        case 14:
            return (((u8) this->unk10 >> 5U) & 1) == 0;
        }
    } else {
    case 0:
    case 9:
    case 10:
        return 0U;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to 'EAPItem *'
s32 EAPManager::ReEvaluate(Enemy *arg0, AITargetData *arg1) {
    M2C_UNK sp8;
    EAPCondition *temp_r28_682;
    EnemyAttack **temp_r3_707;
    s32 var_r29_676;
    s32 var_r30_678;
    s32 var_r31_677;

    fCachedOwnerAngle = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &arg0->unkC0)));
    ((AITargetData *) &sp8)->GetDir();
    fCachedTargetAngle = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &sp8)));
    if ((EnemyAttack **) this->unk8 != NULL) {
        var_r29_676 = 0;
        var_r31_677 = 0;
        var_r30_678 = 0;
loop_7:
        temp_r3_707 = this->unk8;
        if (var_r29_676 >= (s32) M2C_FIELD(temp_r3_707, s32 *, 8)) {
            fCachedOwnerAngle = 0.0f;
            fCachedTargetAngle = 0.0f;
            return 1;
        }
        temp_r28_682 = (EAPCondition *) (M2C_FIELD(temp_r3_707, s32 *, 4) + var_r30_678);
        if ((temp_r28_682->unkC < 0.0f) && (EvaluateCondition(*this->unk4 + var_r31_677, temp_r28_682, arg0, arg1) != 0) && (temp_r28_682->unkC < 0.0f)) {
            return 0;
        }
        var_r29_676 += 1;
        var_r31_677 += 0xC;
        var_r30_678 += 0x10;
        goto loop_7;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to 'EAPItem *'
s32 EAPManager::Evaluate(Enemy *arg0, AITargetData *arg1, int *arg2, int arg3) {
    AITargetData sp8;
    EAPCondition *temp_r25_797;
    f32 temp_f0_860;
    f32 temp_f0_889;
    f32 temp_f1_876;
    f32 var_f28_749;
    f32 var_f29_746;
    f32 var_f30_796;
    s32 *temp_r5_880;
    s32 temp_r0_826;
    s32 temp_r0_884;
    s32 temp_r4_849;
    s32 var_ctr_822;
    s32 var_ctr_885;
    s32 var_r17_792;
    s32 var_r18_787;
    s32 var_r19_786;
    s32 var_r26_791;
    s32 var_r27_785;
    s32 var_r3_821;
    s32 var_r3_883;
    s32 var_r6_882;
    u8 var_r17_754;
    u8 var_r28_790;
    void *temp_r3_850;

    var_f29_746 = 0.0f;
    var_f28_749 = 0.0f;
    var_r17_754 = 0;
    if (((u8) M2C_FIELD(arg1, u8 *, 0x48) == 2) || (arg1->unk40.Get() != NULL)) {
        var_r17_754 = 1;
    }
    if (var_r17_754 != 0) {
        fCachedOwnerAngle = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &arg0->unkC0)));
        sp8.GetDir();
        fCachedTargetAngle = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &sp8)));
        memset(&sp8.unk10, 0, 0x50U);
        var_r27_785 = 0;
        var_r19_786 = 0;
        var_r18_787 = 0;
loop_23:
        if (var_r27_785 < (s32) M2C_FIELD(this->unk4, s32 *, 4)) {
            var_r28_790 = arg2 == NULL;
            var_r26_791 = 0;
            var_r17_792 = 0;
loop_17:
            temp_r4_849 = M2C_FIELD(this->unk4, s32 *, 0);
            temp_r3_850 = (void *) (var_r18_787 + temp_r4_849);
            if (var_r26_791 < (s32) M2C_FIELD(temp_r3_850, s32 *, 8)) {
                var_f30_796 = 0.0f;
                temp_r25_797 = (EAPCondition *) (M2C_FIELD(temp_r3_850, s32 *, 4) + var_r17_792);
                if (((s32) temp_r25_797->unk8 != 1) && (!(M2C_FIELD(M2C_FIELD(temp_r3_850, void **, 0), s32 *, 0x38) & 0x1000) || !(M2C_FIELD(GameData::gameData, f32 *, 0xA0) <= 0.0f))) {
                    if (EvaluateCondition(temp_r4_849 + var_r18_787, temp_r25_797, arg0, arg1) != 0) {
                        var_f30_796 = temp_r25_797->unkC;
                        if (var_r28_790 == 0) {
                            var_r3_821 = 0;
                            var_ctr_822 = arg3;
                            if (arg3 > 0) {
                                do {
                                    temp_r0_826 = *(arg2 + var_r3_821);
                                    var_r3_821 += 4;
                                    var_r28_790 = temp_r25_797->unk4 == temp_r0_826;
                                    var_ctr_822 -= 1;
                                } while (var_ctr_822 != 0);
                            }
                        }
                    }
                    if (var_f30_796 < 0.0f) {
                        *(&sp8.unk10 + var_r19_786) = -1.0f;
                    } else {
                        *(&sp8.unk10 + var_r19_786) = *(&sp8.unk10 + var_r19_786) + var_f30_796;
                        goto block_16;
                    }
                } else {
block_16:
                    var_r26_791 += 1;
                    var_r17_792 += 0x10;
                    goto loop_17;
                }
            }
            if (var_r28_790 == 0) {
                *(&sp8.unk10 + var_r19_786) = 0.0f;
            }
            temp_f0_860 = *(&sp8.unk10 + var_r19_786);
            if (temp_f0_860 > 0.0f) {
                var_f29_746 += temp_f0_860;
            }
            var_r27_785 += 1;
            var_r19_786 += 4;
            var_r18_787 += 0xC;
            goto loop_23;
        }
        temp_f1_876 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        if (var_f29_746 > 0.0f) {
            temp_r5_880 = this->unk4;
            var_r6_882 = 0;
            var_r3_883 = 0;
            temp_r0_884 = M2C_FIELD(temp_r5_880, s32 *, 4);
            var_ctr_885 = temp_r0_884;
            if (temp_r0_884 > 0) {
loop_26:
                temp_f0_889 = *(&sp8.unk10 + var_r3_883);
                if (temp_f0_889 >= 0.0f) {
                    var_f28_749 += temp_f0_889 / var_f29_746;
                    if (var_f28_749 > temp_f1_876) {
                        return M2C_FIELD(temp_r5_880, s32 *, 0) + (var_r6_882 * 0xC);
                    }
                }
                var_r6_882 += 1;
                var_r3_883 += 4;
                var_ctr_885 -= 1;
                if (var_ctr_885 == 0) {
                    goto block_30;
                }
                goto loop_26;
            }
        }
        goto block_30;
    }
block_30:
    fCachedOwnerAngle = 0.0f;
    fCachedTargetAngle = 0.0f;
    return 0;
}
#endif

#if 0 // DRAFT: illegal type
void EAPManager::SetCurrentEAP(int arg0) {
    EAPManagerDescriptor *temp_r5_931;

    this->unk4 = NULL;
    temp_r5_931 = this->unk0;
    if ((temp_r5_931 != NULL) && ((s32) temp_r5_931->unk4 > arg0)) {
        this->unk4 = temp_r5_931->unk0 + (arg0 * 8);
    }
}
#endif

void EAPManager::SetDefaults() {
    this->unk4 = NULL;
    this->unk8 = NULL;
    this->unk10 &= ~0x80;
    this->unk10 &= ~0x40;
    this->unk10 &= ~0x20;
}

void EAPManager::Deinit() {

}

void EAPManager::Init(EAPManagerDescriptor *arg0) {
    this->unk0 = arg0;
    this->unk4 = NULL;
    this->unk8 = NULL;
    this->unk10 &= ~0x80;
    this->unk10 &= ~0x40;
    this->unk10 &= ~0x20;
}

s32 EAP_GetEAPConditionType(eEAPCondition arg0) {
    if ((s32) arg0 < 0xB) {
        if ((s32) arg0 < 9) {
            /* Duplicate return node #4. Try simplifying control flow for better match */
            return 0;
        }
        return 1;
    }
    return 0;
}
