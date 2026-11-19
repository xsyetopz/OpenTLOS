#include "spyro/source/EnemyDescriptor.h"
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
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterDescriptor.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Crate.h"
#include "spyro/source/ElementalRing.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/PooledShatterProp.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "spyro/source/DataMap.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(void ***);                             /* extern */
s32 malloc(s32);                                    /* extern */
extern DataMap ElementTypeDataMap;
extern s32 GS_CLArmorHit;
extern s32 GS_CLArmorSmash;
extern s32 GS_EnemySpinMed;
extern s32 GS_SpyroMeleeHit;
extern DataMap enemyDamageTypesDataMap;
extern DataMap enemyTypeDataMap;
extern M2C_UNK gEmptyPtrList;
extern MKSceneManager *gMK;
extern s32 gViewSeed;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'DataMap'
static DataMap dataMapAnimSequence;                 /* unable to generate initializer: confusing struct layout */
static DataMap dataMapRaces;                        /* unable to generate initializer: confusing struct layout */
static M2C_UNK emAnims;                             /* unable to generate initializer: unknown type */

void AnimSequence::Init(int arg0) {
    s32 var_ctr_20;
    s32 var_r4_16;
    void *temp_r6_22;

    this->unk6C = arg0;
    var_r4_16 = 0;
    this->unk60 = 0.0f;
    this->unk64 = 1.0f;
    this->unk68 = 0;
    var_ctr_20 = 3;
    do {
        temp_r6_22 = this + var_r4_16;
        var_r4_16 += 0x20;
        M2C_FIELD(temp_r6_22, s32 *, 0) = 0;
        M2C_FIELD(temp_r6_22, f32 *, 0x18) = 0.0f;
        M2C_FIELD(temp_r6_22, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r6_22, f32 *, 0xC) = 0.0f;
        M2C_FIELD(temp_r6_22, f32 *, 0x10) = 0.0f;
        var_ctr_20 -= 1;
    } while (var_ctr_20 != 0);
}
#endif

#if 0 // DRAFT: function call 'Tools_GetMatchingSubObjectIndex(SubObjectType, MKModel *,
void EnemyDescriptor::InitArmour() {
    M2C_UNK sp28;
    s8 sp8;
    MKHeap *temp_r3_109;
    MKHeap *temp_r3_125;
    MKHeap *temp_r3_158;
    MKHeap *temp_r3_160;
    MKHeap *temp_r3_93;
    MKHeap *var_r3_100;
    MKHeap *var_r3_116;
    MKHeap *var_r3_77;
    f32 temp_ret_202;
    f32 var_f1_132;
    s32 temp_r0_89;
    s32 temp_r26_159;
    s32 temp_r27_108;
    s32 temp_r27_124;
    s32 temp_r27_92;
    s32 temp_ret_136;
    s32 var_r26_179;
    s32 var_r28_143;
    s32 var_r28_65;
    s32 var_r30_141;
    s32 var_r30_64;
    u8 temp_r0_41;
    void *temp_r3_185;
    void *temp_ret_132;
    void *var_r3_132;
    void *var_r3_167;

    temp_r0_41 = this->unk1D6;
    if ((temp_r0_41 != 0) || !(this->unkF0 <= 0.0f)) {
        if ((temp_r0_41 != 0) && (GetEnemySetting((EnemySettingType) 1) <= 0.0f)) {
            return;
        }
        var_r30_64 = 0;
        var_r28_65 = 0;
loop_6:
        *(&sp28 + var_r28_65) = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, Str_Printf("armour_%0.2d", var_r30_64 + 1));
        var_r3_77 = *(&sp28 + var_r28_65);
        if (var_r3_77 != (MKHeap *)-1U) {
            var_r3_77 = (MKHeap *) this->unk234;
            var_r30_64 += 1;
            var_r28_65 += 4;
            this->unk234 = var_r3_77 + 1;
            if (var_r30_64 < 0x14) {
                goto loop_6;
            }
        }
        temp_r0_89 = this->unk234;
        if (temp_r0_89 > 0) {
            temp_r27_92 = temp_r0_89 * 4;
            temp_r3_93 = var_r3_77->Current();
            if (temp_r3_93 != NULL) {
                var_r3_100 = ((MKHeap *) (temp_r3_93->Current()))->Alloc(temp_r27_92, NULL, 0);
            } else {
                var_r3_100 = malloc(temp_r27_92);
            }
            this->unk238 = (s32) var_r3_100;
            temp_r27_108 = this->unk234 * 4;
            temp_r3_109 = var_r3_100->Current();
            if (temp_r3_109 != NULL) {
                var_r3_116 = ((MKHeap *) (temp_r3_109->Current()))->Alloc(temp_r27_108, NULL, 0);
            } else {
                var_r3_116 = malloc(temp_r27_108);
            }
            this->unk23C = var_r3_116;
            temp_r27_124 = this->unk234 * 4;
            temp_r3_125 = var_r3_116->Current();
            if (temp_r3_125 != NULL) {
                temp_ret_132 = ((MKHeap *) (temp_r3_125->Current()))->Alloc(temp_r27_124, NULL, 0);
                var_f1_132 = M2C_BITWISE(f32, temp_ret_132);
                var_r3_132 = temp_ret_132;
            } else {
                temp_ret_136 = malloc(temp_r27_124);
                var_f1_132 = M2C_BITWISE(f32, temp_ret_136);
                var_r3_132 = temp_ret_136;
            }
            this->unk240 = (s32) var_r3_132;
            var_r30_141 = 0;
            var_r28_143 = 0;
loop_27:
            if (var_r30_141 < (s32) this->unk234) {
                *(this->unk238 + var_r28_143) = *(&sp28 + var_r28_143);
                strcpy(&sp8, Str_Printf("%s_armour_%0.2d", this->unk0, var_r30_141 + 1, var_f1_132));
                temp_r3_158 = strlen(&sp8);
                temp_r26_159 = temp_r3_158 + 1;
                temp_r3_160 = temp_r3_158->Current();
                if (temp_r3_160 != NULL) {
                    var_r3_167 = ((MKHeap *) (temp_r3_160->Current()))->Alloc(temp_r26_159, NULL, 0);
                } else {
                    var_r3_167 = malloc(temp_r26_159);
                }
                *(this->unk23C + var_r28_143) = var_r3_167;
                strcpy(*(this->unk23C + var_r28_143), &sp8);
                var_r26_179 = 0;
                do {
                    temp_r3_185 = checked_cast<PooledShatterProp *, MKProp>(gMK->CreateProp(*(var_r28_143 + this->unk23C)));
                    if (temp_r3_185 != NULL) {
                        M2C_FIELD(M2C_FIELD(temp_r3_185, void **, 0x44), M2C_UNK (**)(), 0x34)();
                    }
                    var_r26_179 += 1;
                } while (var_r26_179 < 5);
                temp_ret_202 = gMK->FindDescriptor(*(this->unk23C + var_r28_143));
                var_f1_132 = temp_ret_202;
                var_r30_141 += 1;
                *(this->unk240 + var_r28_143) = M2C_BITWISE(s32, temp_ret_202);
                var_r28_143 += 4;
                goto loop_27;
            }
        }
    }
}
#endif

f32 EnemyDescriptor::GetEnemyAttackSetting(EnemySettingType arg0, EnemyAttack *arg1) {
    s32 temp_r31_264;

    if ((u8) this->unk1D6 == 0) {
        if ((s32) arg0 != 6) {
            if ((s32) arg0 < 6) {
                if ((s32) arg0 < 5) {
                    if ((s32) arg0 < 0) {
                        goto block_14;
                    }
                    return 0.0f;
                }
                return arg1->unk4;
            }
            if ((s32) arg0 != 8) {
                if ((s32) arg0 < 8) {
                    return arg1->unkC;
                }
block_14:
                return 1.0f;
            }
            return arg1->unk10;
        }
        return arg1->unk8;
    }
    temp_r31_264 = (s32) arg0 * 4;
    return M2C_FIELD((arg1 + temp_r31_264), f32 *, 0x54) * (M2C_FIELD((this + temp_r31_264), f32 *, 0x1D8) * EnemySettings_GetEnemySetting(arg0));
}

f32 EnemyDescriptor::GetEnemySetting(EnemySettingType arg0) {
    if ((u8) this->unk1D6 == 0) {
        if ((s32) arg0 != 3) {
            if ((s32) arg0 < 3) {
                if ((s32) arg0 != 1) {
                    if ((s32) arg0 < 1) {
                        if ((s32) arg0 < 0) {
                            goto block_16;
                        }
                        return this->unkE8;
                    }
                    return this->unk170;
                }
                return this->unkF0;
            }
            if ((s32) arg0 < 9) {
                if ((s32) arg0 < 5) {
                    return this->unk178;
                }
                return EnemySettings_GetEnemySetting(arg0);
            }
block_16:
            return 1.0f;
        }
        return this->unk174;
    }
    return M2C_FIELD((this + ((s32) arg0 * 4)), f32 *, 0x1D8) * EnemySettings_GetEnemySetting(arg0);
}

f32 EnemyDescriptor::GetMaxArmour() {
    if ((u8) this->unk1D6 != 0) {
        return GetEnemySetting((EnemySettingType) 1);
    }
    return this->unkF0;
}

f32 EnemyDescriptor::GetDamageMultiplier(unsigned int arg0, int arg1, bool arg2) {
    MKHeap *temp_r7_368;
    s32 temp_r0_375;
    s32 var_ctr_378;
    s32 var_r3_377;
    s32 var_r5_0;
    void *temp_r8_384;

    var_r5_0 = arg1;
    temp_r7_368 = this->unk2AC;
    if (temp_r7_368 != NULL) {
        if (arg2 != 0) {
            var_r5_0 = 3;
        }
        temp_r0_375 = this->unk2B0;
        var_r3_377 = 0;
        var_ctr_378 = temp_r0_375;
        if (temp_r0_375 > 0) {
loop_4:
            if ((u32) (arg0 & 0x47F0) == 0) {
                temp_r8_384 = temp_r7_368 + var_r3_377;
                if ((arg0 & M2C_FIELD(temp_r8_384, s32 *, 0)) && (var_r5_0 == (s32) M2C_FIELD(temp_r8_384, s32 *, 4))) {
                    return M2C_FIELD(temp_r8_384, f32 *, 8);
                }
            }
            var_r3_377 += 0xC;
            var_ctr_378 -= 1;
            if (var_ctr_378 == 0) {
                /* Duplicate return node #9. Try simplifying control flow for better match */
                return 1.0f;
            }
            goto loop_4;
        }
        /* Duplicate return node #9. Try simplifying control flow for better match */
        return 1.0f;
    }
    return 1.0f;
}

void **EnemyDescriptor::GetAttack(int arg0) {
    void ****temp_r3_404;
    void ***var_r6_407;
    void **temp_r3_418;

    temp_r3_404 = this->unk228;
    if (temp_r3_404 != NULL) {
        var_r6_407 = *temp_r3_404;
loop_4:
        if ((var_r6_407 == NULL) || (temp_r3_418 = *var_r6_407, ((temp_r3_418 == NULL) != 0))) {
            /* Duplicate return node #6. Try simplifying control flow for better match */
            return NULL;
        }
        if ((s32) M2C_FIELD(*temp_r3_418, s32 *, 0x68) != arg0) {
            var_r6_407 += 4;
            goto loop_4;
        }
        return temp_r3_418;
    }
    return NULL;
}

u8 EnemyDescriptor::HasAttack(unsigned int arg0, int arg1) {
    void ****temp_r3_429;
    void ***var_r6_432;
    void **temp_r3_449;

    temp_r3_429 = this->unk228;
    if (temp_r3_429 != NULL) {
        var_r6_432 = *temp_r3_429;
loop_6:
        if ((var_r6_432 == NULL) || (temp_r3_449 = *var_r6_432, ((temp_r3_449 == NULL) != 0))) {
            /* Duplicate return node #8. Try simplifying control flow for better match */
            return 0U;
        }
        if (((s32) M2C_FIELD(temp_r3_449, s32 *, 0x3C) == arg1) && (arg0 == (u32) (arg0 & M2C_FIELD(temp_r3_449, s32 *, 0x38)))) {
            return 1U;
        }
        var_r6_432 += 4;
        goto loop_6;
    }
    return 0U;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void *EnemyDescriptor::GetAnimSequence(int arg0, int arg1, int arg2, AnimSequence *arg3) const {
    f32 temp_f1_495;
    f32 temp_f1_510;
    f32 temp_f3_525;
    f32 var_f30_506;
    f32 var_f31_470;
    s32 temp_r0_485;
    s32 temp_r5_520;
    s32 var_ctr_486;
    s32 var_r29_473;
    s32 var_r3_484;
    s32 var_r4_517;
    s32 var_r6_516;
    s32 var_r7_512;
    s32 var_r8_514;
    void *temp_r28_483;
    void *temp_r4_491;
    void *var_r3_521;

    var_f31_470 = 0.0f;
    var_r29_473 = 0;
    if (arg2 >= (s32) this->unk200) {
        return NULL;
    }
    temp_r28_483 = this->unk1FC + ((arg2 * 0x98) + (arg0 * 8));
    var_r3_484 = 0;
    temp_r0_485 = M2C_FIELD(temp_r28_483, s32 *, 4);
    var_ctr_486 = temp_r0_485;
    if (temp_r0_485 > 0) {
        do {
            temp_r4_491 = M2C_FIELD(temp_r28_483, s32 *, 0) + var_r3_484;
            if (arg1 == (s32) M2C_FIELD(temp_r4_491, s32 *, 0x68)) {
                temp_f1_495 = M2C_FIELD(temp_r4_491, f32 *, 0x60);
                if (temp_f1_495 > 0.0f) {
                    var_f31_470 += temp_f1_495;
                    var_r29_473 += 1;
                }
            }
            var_r3_484 += 0x70;
            var_ctr_486 -= 1;
        } while (var_ctr_486 != 0);
    }
    if (var_r29_473 > 0) {
        var_f30_506 = 0.0f;
        temp_f1_510 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        var_r7_512 = 0;
        var_r8_514 = 0;
        var_r6_516 = 0;
        var_r4_517 = 0;
loop_22:
        if (!(var_f31_470 > 0.0f) || (var_r6_516 >= (s32) M2C_FIELD(temp_r28_483, s32 *, 4))) {
            goto block_24;
        }
        temp_r5_520 = M2C_FIELD(temp_r28_483, s32 *, 0);
        var_r3_521 = temp_r5_520 + var_r4_517;
        if (arg1 == (s32) M2C_FIELD(var_r3_521, s32 *, 0x68)) {
            temp_f3_525 = M2C_FIELD(var_r3_521, f32 *, 0x60);
            if (temp_f3_525 > 0.0f) {
                var_f30_506 += temp_f3_525 * (1.0f / var_f31_470);
                if ((arg3 != var_r3_521) || (var_r29_473 <= 1)) {
                    var_r8_514 += 1;
                    goto block_18;
                }
                if ((arg3 == var_r3_521) && ((s32) (var_r8_514 + 1) == var_r29_473)) {
                    var_r3_521 = temp_r5_520 + (var_r7_512 * 0x70);
block_18:
                    if (var_f30_506 > temp_f1_510) {
                        return var_r3_521;
                    }
                    var_r7_512 = var_r6_516;
                    goto block_21;
                }
                var_r8_514 += 1;
                goto block_21;
            }
        }
block_21:
        var_r6_516 += 1;
        var_r4_517 += 0x70;
        goto loop_22;
    }
block_24:
    return NULL;
}
#endif

#if 0 // DRAFT: type mismatch
void EnemyDescriptor::Deinit_Attacks() {
    MKHeap *temp_r3_615;
    MKHeap *temp_r3_631;
    void ****temp_r31_603;
    void ****temp_r31_630;
    void ****temp_r3_586;
    void ***temp_r30_611;
    void ***temp_r3_606;
    void ***var_r30_589;
    void **temp_r3_599;

    temp_r3_586 = this->unk228;
    if (temp_r3_586 != NULL) {
        var_r30_589 = *temp_r3_586;
loop_3:
        if (var_r30_589 != NULL) {
            temp_r3_599 = *var_r30_589;
            if (temp_r3_599 != NULL) {
                ((EnemyAttack *) temp_r3_599)->Deinit();
                operator delete(*var_r30_589);
                var_r30_589 += 4;
                goto loop_3;
            }
        }
        temp_r31_603 = this->unk228;
        do {
            temp_r3_606 = *temp_r31_603 - 4;
            *temp_r31_603 = temp_r3_606;
        } while ((void **) *temp_r3_606 != NULL);
        temp_r30_611 = *temp_r31_603;
        if (temp_r30_611 != &gEmptyPtrList) {
            temp_r3_615 = ((MKHeap *) temp_r3_606)->Current();
            if (temp_r3_615 != NULL) {
                ((MKHeap *) (temp_r3_615->Current()))->Free(temp_r30_611, NULL, 0);
            } else {
                free(temp_r30_611);
            }
        }
        *temp_r31_603 = NULL;
        temp_r31_630 = this->unk228;
        temp_r3_631 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_631 != NULL) {
            ((MKHeap *) (temp_r3_631->Current()))->Free(temp_r31_630, NULL, 0);
        } else {
            free((void ***) temp_r31_630);
        }
        this->unk228 = NULL;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void **' to
void EnemyDescriptor::Deinit_Animation() {
    MKHeap *temp_r3_675;
    MKHeap *temp_r3_704;
    s32 var_r26_662;
    s32 var_r27_667;
    s32 var_r30_666;
    s32 var_r31_663;
    void ***temp_r28_672;
    void ***temp_r28_701;
    void *temp_r0_691;

    var_r26_662 = 0;
    var_r31_663 = 0;
loop_8:
    if (var_r26_662 < (s32) this->unk200) {
        var_r30_666 = 0;
        var_r27_667 = 0;
        do {
            temp_r28_672 = *(var_r31_663 + (this->unk1FC + var_r30_666));
            if (temp_r28_672 != NULL) {
                temp_r3_675 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
                if (temp_r3_675 != NULL) {
                    ((MKHeap *) (temp_r3_675->Current()))->Free(temp_r28_672, NULL, 0);
                } else {
                    free(temp_r28_672);
                }
            }
            var_r27_667 += 1;
            temp_r0_691 = this->unk1FC + var_r30_666;
            var_r30_666 += 8;
            *(var_r31_663 + temp_r0_691) = 0;
        } while (var_r27_667 < 0x13);
        var_r26_662 += 1;
        var_r31_663 += 0x98;
        goto loop_8;
    }
    temp_r28_701 = this->unk1FC;
    if (temp_r28_701 != NULL) {
        temp_r3_704 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_704 != NULL) {
            ((MKHeap *) (temp_r3_704->Current()))->Free(temp_r28_701, NULL, 0);
            return;
        }
        free(temp_r28_701);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
s32 EnemyDescriptor::LoadLine_DamageMultipliers(MKIniLine *arg0) {
    MKHeap *temp_r3_740;
    MKHeap *var_r3_747;
    MKIniLine *var_r26_789;
    MKIniLine *var_r30_780;
    s32 temp_r0_736;
    s32 temp_r0_763;
    s32 temp_r27_739;
    s32 temp_r3_734;
    s32 temp_r3_762;
    s32 var_r28_777;
    s32 var_r4_753;
    s32 var_r8_758;

    temp_r3_734 = arg0->GetNmbrOfSubLines();
    this->unk2B0 = temp_r3_734;
    temp_r0_736 = this->unk2B0;
    if (temp_r0_736 > 0) {
        temp_r27_739 = temp_r0_736 * 0xC;
        temp_r3_740 = ((MKHeap *) temp_r3_734)->Current();
        if (temp_r3_740 != NULL) {
            var_r3_747 = ((MKHeap *) (temp_r3_740->Current()))->Alloc(temp_r27_739, NULL, 0);
        } else {
            var_r3_747 = malloc(temp_r27_739);
        }
        var_r4_753 = 0;
        this->unk2AC = var_r3_747;
        var_r8_758 = 0;
loop_6:
        if (var_r8_758 < (s32) this->unk2B0) {
            temp_r3_762 = var_r4_753 + 4;
            temp_r0_763 = var_r4_753 + 8;
            var_r8_758 += 1;
            *(this->unk2AC + var_r4_753) = 0;
            var_r4_753 += 0xC;
            *(this->unk2AC + temp_r3_762) = 0;
            *(this->unk2AC + temp_r0_763) = 1.0f;
            goto loop_6;
        }
        var_r28_777 = 0;
        var_r30_780 = arg0->unkC->GetSubLine(arg0);
loop_15:
        if (var_r30_780 != NULL) {
            var_r26_789 = var_r30_780->unkC->GetSubLine(var_r30_780);
            *(this->unk2AC + var_r28_777) = DataMap_GetValue(&enemyDamageTypesDataMap, var_r30_780->GetFieldName());
            if ((u32) *(this->unk2AC + var_r28_777) != 0U) {
loop_13:
                if (var_r26_789 != NULL) {
                    if (var_r26_789->LoadInt("iAttackLevel", this->unk2AC + (var_r28_777 + 4), 0) == 0) {
                        var_r26_789->LoadFloat("value", this->unk2AC + (var_r28_777 + 8), 0);
                    }
                    var_r26_789 = var_r26_789->unkC->GetNextLine(var_r26_789);
                    goto loop_13;
                }
            }
            var_r30_780 = var_r30_780->unkC->GetNextLine(var_r30_780);
            var_r28_777 += 0xC;
            goto loop_15;
        }
    }
    return 1;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 EnemyDescriptor::LoadLine_Attacks(MKIniLine *arg0) {
    MKHeap *temp_r3_857;
    MKHeap *temp_r3_881;
    MKIniLine *var_r28_921;
    MKIniLine *var_r30_938;
    s32 temp_r3_872;
    s32 temp_r3_965;
    s32 var_ctr_902;
    void ****temp_r31_874;
    void ****temp_r5_928;
    void ****var_r3_864;
    void ***temp_r3_906;
    void ***temp_r3_912;
    void ***temp_r4_931;
    void ***var_r3_889;
    void ***var_r5_962;
    void **temp_r31_929;
    void **temp_r3_1007;

    temp_r3_857 = MKHeap::Current();
    if (temp_r3_857 != NULL) {
        var_r3_864 = ((MKHeap *) (temp_r3_857->Current()))->Alloc(4, NULL, 0);
    } else {
        var_r3_864 = malloc(4);
    }
    this->unk228 = var_r3_864;
    temp_r3_872 = arg0->GetNmbrOfSubLines();
    temp_r31_874 = this->unk228;
    if (temp_r3_872 == 0) {
        *temp_r31_874 = &gEmptyPtrList + 4;
    } else {
        temp_r3_881 = ((MKHeap *) temp_r3_872)->Current();
        if (temp_r3_881 != NULL) {
            var_r3_889 = ((MKHeap *) (temp_r3_881->Current()))->Alloc((temp_r3_872 + 2) * 4, NULL, 0);
        } else {
            var_r3_889 = malloc((temp_r3_872 + 2) * 4);
        }
        *temp_r31_874 = var_r3_889;
        M2C_FIELD(*temp_r31_874, void ***, 0) = NULL;
        var_ctr_902 = temp_r3_872;
        if (temp_r3_872 > 0) {
            do {
                temp_r3_906 = *temp_r31_874;
                *temp_r31_874 = temp_r3_906 + 4;
                M2C_FIELD(temp_r3_906, s32 *, 4) = 0xDEADBEEF;
                var_ctr_902 -= 1;
            } while (var_ctr_902 != 0);
        }
        temp_r3_912 = *temp_r31_874;
        *temp_r31_874 = temp_r3_912 + 4;
        M2C_FIELD(temp_r3_912, s32 *, 4) = 0;
    }
    var_r28_921 = arg0->unkC->GetSubLine(arg0);
loop_16:
    if (var_r28_921 != NULL) {
        operator new(0x90U, NULL, 0);
        temp_r5_928 = this->unk228;
        temp_r31_929 = M2C_ERROR(/* Read from unset register $r3 */);
        temp_r4_931 = *temp_r5_928 - 4;
        *temp_r5_928 = temp_r4_931;
        *temp_r4_931 = temp_r31_929;
        ((EnemyAttack *) (M2C_ERROR(/* Read from unset register $r3 */)))->Init();
        var_r30_938 = var_r28_921->unkC->GetSubLine(var_r28_921);
loop_14:
        if (var_r30_938 != NULL) {
            ((EnemyAttack *) temp_r31_929)->LoadLine(var_r30_938, this);
            var_r30_938 = var_r30_938->unkC->GetNextLine(var_r30_938);
            goto loop_14;
        }
        ((EnemyAttack *) temp_r31_929)->LoadDone();
        var_r28_921 = var_r28_921->unkC->GetNextLine(var_r28_921);
        goto loop_16;
    }
    var_r5_962 = *this->unk228;
loop_27:
    if (var_r5_962 != NULL) {
        temp_r3_1007 = *var_r5_962;
        if (temp_r3_1007 != NULL) {
            temp_r3_965 = M2C_FIELD(temp_r3_1007, s32 *, 0x38);
            if (temp_r3_965 & 1) {
                this->unk214 += 1;
                this->unk224 += M2C_FIELD(*var_r5_962, s32 *, 0x78);
            } else if (temp_r3_965 & 4) {
                this->unk218 += 1;
                this->unk224 += M2C_FIELD(*var_r5_962, s32 *, 0x78);
            } else if (temp_r3_965 & 2) {
                this->unk21C += 1;
            } else if (temp_r3_965 & 0x70000) {
                this->unk220 += 1;
            }
            var_r5_962 += 4;
            goto loop_27;
        }
    }
    return 1;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void EnemyDescriptor::LoadLine_AnimSequence(MKIniLine *arg0, AnimSequence *arg1) {
    MKIniLine *var_r29_1030;
    s8 *temp_r26_1097;
    s8 *temp_r26_1124;
    s8 *temp_r27_1070;
    s8 *temp_r3_1069;
    s8 *temp_r3_1096;
    s8 *temp_r3_1123;
    void *var_r3_1079;
    void *var_r3_1106;
    void *var_r3_1133;

    var_r29_1030 = arg0;
    arg1->unk68 = 0;
loop_20:
    if (var_r29_1030 != NULL) {
        if ((var_r29_1030->LoadInt("iVariation", (int *) &arg1->unk68, 0) == 0) && (var_r29_1030->LoadFloat("fWeighting", &arg1->unk60, 0) == 0) && (var_r29_1030->LoadFloat("fAnimSpeed", &arg1->unk64, 0) == 0)) {
            if (var_r29_1030->IsField("pEnter") != 0) {
                temp_r3_1069 = var_r29_1030->GetString(0);
                temp_r27_1070 = this->unk34;
                if (((MKAnimScript *) temp_r27_1070)->Exists(temp_r3_1069) != 0) {
                    var_r3_1079 = ((MKAnimScript *) temp_r27_1070)->GetAnim(temp_r3_1069);
                } else {
                    var_r3_1079 = NULL;
                }
                arg1->unk0 = (u32) var_r3_1079;
            } else if (var_r29_1030->IsField("pLoop") != 0) {
                temp_r3_1096 = var_r29_1030->GetString(0);
                temp_r26_1097 = this->unk34;
                if (((MKAnimScript *) temp_r26_1097)->Exists(temp_r3_1096) != 0) {
                    var_r3_1106 = ((MKAnimScript *) temp_r26_1097)->GetAnim(temp_r3_1096);
                } else {
                    var_r3_1106 = NULL;
                }
                arg1->unk20 = (u32) var_r3_1106;
            } else if (var_r29_1030->IsField("pExit") != 0) {
                temp_r3_1123 = var_r29_1030->GetString(0);
                temp_r26_1124 = this->unk34;
                if (((MKAnimScript *) temp_r26_1124)->Exists(temp_r3_1123) != 0) {
                    var_r3_1133 = ((MKAnimScript *) temp_r26_1124)->GetAnim(temp_r3_1123);
                } else {
                    var_r3_1133 = NULL;
                }
                arg1->unk40 = (u32) var_r3_1133;
            }
        }
        var_r29_1030 = var_r29_1030->unkC->GetNextLine(var_r29_1030);
        goto loop_20;
    }
}
#endif

#if 0 // DRAFT: function call 'DataMap_GetValue(DataMap *, signed char *)' does not match
s32 EnemyDescriptor::LoadLine_Animation(MKIniLine *arg0, int arg1) {
    MKHeap *temp_r3_1186;
    MKIniLine *var_r27_1209;
    s32 temp_r29_1185;
    s32 temp_r3_1173;
    s32 temp_r3_1182;
    s32 var_r26_1207;
    s32 var_r29_1208;
    void *temp_r28_1181;
    void *var_r3_1193;

    if (arg0->GetFieldName() != NULL) {
        temp_r3_1173 = DataMap_GetValue(&dataMapAnimSequence, arg0->GetFieldName());
        if (temp_r3_1173 != 0) {
            temp_r28_1181 = this->unk1FC + ((arg1 * 0x98) + (temp_r3_1173 * 8));
            temp_r3_1182 = arg0->GetNmbrOfSubLines();
            M2C_FIELD(temp_r28_1181, s32 *, 4) = temp_r3_1182;
            temp_r29_1185 = M2C_FIELD(temp_r28_1181, s32 *, 4) * 0x70;
            temp_r3_1186 = ((MKHeap *) temp_r3_1182)->Current();
            if (temp_r3_1186 != NULL) {
                var_r3_1193 = ((MKHeap *) (temp_r3_1186->Current()))->Alloc(temp_r29_1185, NULL, 0);
            } else {
                var_r3_1193 = malloc(temp_r29_1185);
            }
            M2C_FIELD(temp_r28_1181, void **, 0) = var_r3_1193;
            memset(M2C_FIELD(temp_r28_1181, void **, 0), 0, (u32) temp_r29_1185);
            var_r26_1207 = 0;
            var_r29_1208 = 0;
            var_r27_1209 = arg0->unkC->GetSubLine(arg0);
loop_7:
            if ((var_r27_1209 != NULL) && (var_r26_1207 < (s32) M2C_FIELD(temp_r28_1181, s32 *, 4))) {
                ((AnimSequence *) (M2C_FIELD(temp_r28_1181, void **, 0) + var_r29_1208))->Init(temp_r3_1173);
                LoadLine_AnimSequence(var_r27_1209->unkC->GetSubLine(var_r27_1209), M2C_FIELD(temp_r28_1181, void **, 0) + var_r29_1208);
                var_r26_1207 += 1;
                var_r29_1208 += 0x70;
                var_r27_1209 = var_r27_1209->unkC->GetNextLine(var_r27_1209);
                goto loop_7;
            }
            return 1;
        }
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 EnemyDescriptor::LoadLine_General(MKIniLine *arg0) {
    u8 sp8;
    MKHeap *temp_r3_1288;
    MKHeap *var_r3_1295;
    s16 temp_r3_1286;
    s32 temp_r28_1287;
    s32 var_r27_1307;
    s32 var_r31_1308;
    s32 var_r31_1333;
    u16 temp_r0_1320;

    sp8 = 0;
    if ((arg0->LoadBool("bFriend", &sp8, 0) != 0) && (sp8 != 0)) {
        this->unkC &= 0xFFFFFFF7;
        this->unkC |= 4;
    }
    if (arg0->IsField("LeafEffectNodes") != 0) {
        temp_r3_1286 = arg0->unk0;
        temp_r28_1287 = temp_r3_1286 + 1;
        temp_r3_1288 = ((MKHeap *) temp_r3_1286)->Current();
        if (temp_r3_1288 != NULL) {
            var_r3_1295 = ((MKHeap *) (temp_r3_1288->Current()))->Alloc(temp_r28_1287 * 4, NULL, 0);
        } else {
            var_r3_1295 = malloc(temp_r28_1287 * 4);
        }
        this->unk27C = var_r3_1295;
        var_r27_1307 = 0;
        var_r31_1308 = 0;
        M2C_FIELD((this->unk27C + (temp_r28_1287 * 4)), s32 *, -4) = 0xFFFF;
loop_9:
        if (var_r27_1307 < (s32) (temp_r28_1287 - 1)) {
            temp_r0_1320 = Tools_GetMatchingNodeIndex(this->unk2C, arg0->GetString(var_r27_1307));
            var_r27_1307 += 1;
            *(this->unk27C + var_r31_1308) = (s32) temp_r0_1320;
            var_r31_1308 += 4;
            goto loop_9;
        }
    }
    var_r31_1333 = 0;
    if ((arg0->LoadFloat("iMaxHealth", &this->unkE8, 0) != 0) || (arg0->LoadFloat("iMaxShieldHealth", &this->unkEC, 0) != 0) || (arg0->LoadFloat("iMaxArmour", &this->unkF0, 0) != 0) || (arg0->LoadInt("uArmourType", (int *) &this->unk104, 0) != 0) || (arg0->LoadInt("iFuryDamage", (int *) &this->unkF8, 0) != 0) || (arg0->LoadBool("bCanSquish", &this->unkFC, 0) != 0) || (arg0->LoadInt("iBreathDamage", (int *) &this->unk100, 0) != 0) || (arg0->LoadInt("iGemsHealth", (int *) &this->unk108, 0) != 0) || (arg0->LoadInt("iGemsSpirit", (int *) &this->unk10C, 0) != 0) || (arg0->LoadInt("iGemsMagic", (int *) &this->unk110, 0) != 0) || (arg0->LoadInt("iGemsFury", (int *) &this->unk114, 0) != 0) || (arg0->LoadInt("iTier", (int *) &this->unk118, 0) != 0) || (arg0->LoadInt("iHealthBarStages", (int *) &this->unk11C, 0) != 0) || (DataMap_LoadLine(arg0, "race", &dataMapRaces, (unsigned int *) &this->unk1CC) != 0) || (arg0->LoadBool("bImmortal", &this->unk120, 0) != 0) || (arg0->LoadBool("bDieInLava", &this->unk121, 0) != 0) || (arg0->LoadBool("bDieInWater", &this->unk122, 0) != 0) || (arg0->LoadFloat("fMaxFreezeCount", &this->unk124, 0) != 0) || (arg0->LoadFloat("fFreezeDuration", &this->unk128, 0) != 0) || (arg0->LoadFloat("fAlertRange", &this->unk12C, 0) != 0) || (arg0->LoadFloat("fCriticalAlertRange", &this->unk130, 0) != 0) || (arg0->LoadFloat("fRemainAlertRange", &this->unk134, 0) != 0) || (arg0->LoadFloat("fMeleeDistanceMode", &this->unk138, 0) != 0) || (arg0->LoadFloat("fRangedDistanceMode", &this->unk13C, 0) != 0) || (arg0->LoadFloat("fVisibleAngle", &this->unk14C, 0) != 0) || (arg0->LoadFloat("fFocalPointDistance", &this->unk148, 0) != 0) || (arg0->LoadFloat("fDodgeChance", &this->unk150, 0) != 0) || (arg0->LoadFloat("fEvadeDistance", &this->unk140, 0) != 0) || (arg0->LoadFloat("fEvadeRandomChance", &this->unk144, 0) != 0) || (arg0->LoadFloat("fFlySpeed", &this->unk164, 0) != 0) || (arg0->LoadFloat("fIdleRotSpeed", &this->unk154, 0) != 0) || (arg0->LoadFloat("fWalkRotSpeed", &this->unk158, 0) != 0) || (arg0->LoadFloat("fRunRotSpeed", &this->unk15C, 0) != 0) || (arg0->LoadFloat("fAlertRotSpeed", &this->unk160, 0) != 0) || (arg0->LoadFloat("fMass", &this->unk168, 0) != 0) || (arg0->LoadFloat("fDefensiveMax", &this->unk170, 0) != 0) || (arg0->LoadFloat("fDefensiveHitWeight", &this->unk174, 0) != 0) || (arg0->LoadFloat("fDefensivenessDecayRate", &this->unk178, 0) != 0) || (arg0->LoadBool("bRandomPursuit", &this->unk17C, 0) != 0) || (arg0->LoadBool("bSeekToAttackTarget", &this->unk17D, 0) != 0) || (arg0->LoadBool("bFinishMovementAnim", &this->unk17E, 0) != 0) || (arg0->LoadBool("bUseEnemySettings", &this->unk1D6, 0) != 0) || (arg0->LoadBool("bOldArmourSystem", &this->unk1D7, 0) != 0) || (KDSound_LoadLine(arg0, "soundLoop01", (int *) &this->unk1A4) != 0) || (KDSound_LoadLine(arg0, "soundLoop02", (int *) &this->unk1A8) != 0) || (KDSound_LoadLine(arg0, "soundLoop03", (int *) &this->unk1AC) != 0) || (KDSound_LoadLine(arg0, "sndAirFlinch", (int *) &this->unk1C0) != 0) || (KDSound_LoadLine(arg0, "sndAirSpin", (int *) &this->unk1C4) != 0) || (KDSound_LoadLine(arg0, "sndBurnFlee", (int *) &this->unk1C8) != 0) || (KDSound_LoadLine(arg0, "sndArmourHitBreathFire", (int *) &this->unk194) != 0) || (KDSound_LoadLine(arg0, "sndArmourHitBreathEarth", (int *) &this->unk198) != 0) || (KDSound_LoadLine(arg0, "sndArmourHitBreathIce", (int *) &this->unk19C) != 0) || (KDSound_LoadLine(arg0, "sndArmourHitBreathElectricity", (int *) &this->unk1A0) != 0) || (KDSound_LoadLine(arg0, "sndSpit", (int *) &this->unk1B8) != 0) || (KDSound_LoadLine(arg0, "sndSpitSplat", (int *) &this->unk1BC) != 0)) {
        var_r31_1333 = 1;
    }
    return var_r31_1333;
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, signed char *)' does not match
void EnemyDescriptor::LoadDescriptorData() {
    MKIni sp28;
    s8 sp8;
    MKHeap *temp_r3_1883;
    MKIniLine *var_r27_1929;
    MKIniLine *var_r27_1969;
    MKIniLine *var_r29_1857;
    MKIniLine *var_r29_1917;
    MKIniLine *var_r3_1853;
    MKIniLine *var_r3_1915;
    s32 temp_r0_1879;
    s32 temp_r28_1882;
    s32 var_r28_1898;
    s32 var_r28_1914;
    s32 var_r29_1897;
    u8 temp_r3_1842;
    void ***var_r3_1890;

    temp_r3_1842 = ((MKIni *) &sp8)->Exists((s8 *) (u32) (u64) strcpy(&sp8, Str_Printf("%s.add", this->unk278)));
    if (temp_r3_1842 != 0) {
        ((MKHeap *) temp_r3_1842)->ActivateTempMemOverride();
        ((MKHeap *) (sp28.Init(&sp8, 0, NULL)))->DeactivateTempMemOverride();
        var_r3_1853 = sp28.GetFirstLine();
        this->unk200 = 0;
        var_r29_1857 = var_r3_1853;
loop_5:
        if (var_r29_1857 != NULL) {
            if (var_r29_1857->IsSection("Animation") != 0) {
                this->unk200 += 1;
            }
            var_r3_1853 = var_r29_1857->unkC->GetNextLine(var_r29_1857);
            var_r29_1857 = var_r3_1853;
            goto loop_5;
        }
        this->unk1FC = NULL;
        temp_r0_1879 = this->unk200;
        if (temp_r0_1879 != 0) {
            temp_r28_1882 = temp_r0_1879 * 0x98;
            temp_r3_1883 = ((MKHeap *) var_r3_1853)->Current();
            if (temp_r3_1883 != NULL) {
                var_r3_1890 = ((MKHeap *) (temp_r3_1883->Current()))->Alloc(temp_r28_1882, NULL, 0);
            } else {
                var_r3_1890 = malloc(temp_r28_1882);
            }
            this->unk1FC = var_r3_1890;
            var_r29_1897 = 0;
            var_r28_1898 = 0;
loop_12:
            if (var_r29_1897 < (s32) this->unk200) {
                memset(this->unk1FC + var_r28_1898, 0, 0x98U);
                var_r29_1897 += 1;
                var_r28_1898 += 0x98;
                goto loop_12;
            }
        }
        var_r28_1914 = 0;
        var_r3_1915 = sp28.GetFirstLine();
        var_r29_1917 = var_r3_1915;
loop_34:
        if (var_r29_1917 != NULL) {
            if (var_r29_1917->IsSection("General") != 0) {
                var_r27_1929 = var_r29_1917->unkC->GetSubLine(var_r29_1917);
loop_17:
                if (var_r27_1929 != NULL) {
                    LoadLine_General(var_r27_1929);
                    var_r27_1929 = var_r27_1929->unkC->GetNextLine(var_r27_1929);
                    goto loop_17;
                }
            } else if (var_r29_1917->IsSection("EnemySettings") != 0) {
                this->unk1D8.LoadLine(var_r29_1917->unkC->GetSubLine(var_r29_1917));
            } else if (var_r29_1917->IsSection("Animation") != 0) {
                var_r27_1969 = var_r29_1917->unkC->GetSubLine(var_r29_1917);
loop_24:
                if (var_r27_1969 != NULL) {
                    LoadLine_Animation(var_r27_1969, var_r28_1914);
                    var_r27_1969 = var_r27_1969->unkC->GetNextLine(var_r27_1969);
                    goto loop_24;
                }
                var_r28_1914 += 1;
            } else if (var_r29_1917->IsSection("Attacks") != 0) {
                LoadLine_Attacks(var_r29_1917);
            } else if (var_r29_1917->IsSection("DamageMultipliers") != 0) {
                LoadLine_DamageMultipliers(var_r29_1917);
            } else if (((EAPManagerDescriptor *) this->unk230 == NULL) && (var_r29_1917->IsSection("AttackPatterns") != 0)) {
                operator new(8U, NULL, 0);
                this->unk230 = M2C_ERROR(/* Read from unset register $r3 */);
                this->unk230->LoadLine(this, var_r29_1917);
            }
            var_r3_1915 = var_r29_1917->unkC->GetNextLine(var_r29_1917);
            var_r29_1917 = var_r3_1915;
            goto loop_34;
        }
        ((MKHeap *) var_r3_1915)->ActivateTempMemOverride();
        sp28.Deinit();
        ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->DeactivateTempMemOverride();
    }
}
#endif

void EnemyDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    this->unk254 = gMK->FindDescriptor("EnemyStonedShatter");
}

#if 0 // DRAFT: function call 'DataMap_GetValue(DataMap *, signed char *)' does not match
void EnemyDescriptor::LoadDone() {
    f64 sp10;
    f32 sp8;
    CharacterBreathFXDescriptor *var_r3_2371;
    MKHeap *temp_r3_2360;
    MKHeap *temp_r3_2364;
    f32 temp_f1_2132;
    f32 temp_f2_2131;
    f32 temp_f3_2133;
    f32 var_f4_2138;
    f64 temp_f1_2141;
    f64 temp_f1_2147;
    f64 temp_f1_2151;
    s32 temp_r3_2170;
    s32 var_r0_2180;
    s32 var_r20_2115;
    s32 var_r21_2110;
    s32 var_r22_2106;
    s32 var_r23_2102;
    s32 var_r25_2114;
    s32 var_r27_2109;
    s32 var_r28_2105;
    s32 var_r29_2101;
    void *temp_r26_2116;
    void *temp_r30_2118;
    void *temp_r3_2223;

    CharacterDescriptor::LoadDone();
    this->unkF4 = DataMap_GetValue(&enemyTypeDataMap, this->unk0);
    this->unk7C.unk0 = this->unk60;
    this->unk7C.unk4 = this->unk7C.unk0;
    LoadDescriptorData();
    if ((u8) this->unk1D6 != 0) {
        EnemySettings_RegisterSettings(this->unk278, &this->unk1D8);
    }
    var_r29_2101 = 0;
    var_r23_2102 = 0;
loop_30:
    if (var_r29_2101 < (s32) this->unk200) {
        var_r28_2105 = 0;
        var_r22_2106 = 0;
        do {
            var_r27_2109 = 0;
            var_r21_2110 = 0;
loop_27:
            temp_r3_2223 = var_r23_2102 + var_r22_2106 + this->unk1FC;
            if (var_r27_2109 < (s32) M2C_FIELD(temp_r3_2223, s32 *, 4)) {
                var_r25_2114 = 0;
                var_r20_2115 = 0;
                temp_r26_2116 = M2C_FIELD(temp_r3_2223, s32 *, 0) + var_r21_2110;
                do {
                    temp_r30_2118 = ((u8 *) temp_r26_2116) + var_r20_2115;
                    if ((void *) M2C_FIELD(temp_r30_2118, void **, 0) != NULL) {
                        SumAnimTranslation((MKAnimScript *) &sp10, (MKAnim *) this->unk34, M2C_FIELD(temp_r26_2116, f32 *, 0x64));
                        M2C_FIELD(temp_r30_2118, f64 *, 8) = sp10;
                        M2C_FIELD(temp_r30_2118, f64 *, 0x10) = sp18;
                        temp_f2_2131 = (f32) M2C_FIELD(temp_r30_2118, f64 *, 8);
                        temp_f1_2132 = M2C_FIELD(temp_r30_2118, f32 *, 0xC);
                        temp_f3_2133 = (f32) M2C_FIELD(temp_r30_2118, f64 *, 0x10);
                        var_f4_2138 = (temp_f3_2133 * temp_f3_2133) + ((temp_f2_2131 * temp_f2_2131) + (temp_f1_2132 * temp_f1_2132));
                        if (var_f4_2138 > 0.0f) {
                            temp_f1_2141 = __frsqrte(var_f4_2138);
                            temp_f1_2147 = 0.5 * temp_f1_2141 * -(((f64) var_f4_2138 * (temp_f1_2141 * temp_f1_2141)) - 3.0);
                            temp_f1_2151 = 0.5 * temp_f1_2147 * -(((f64) var_f4_2138 * (temp_f1_2147 * temp_f1_2147)) - 3.0);
                            var_f4_2138 = (f32) ((f64) var_f4_2138 * (0.5 * temp_f1_2151 * -(((f64) var_f4_2138 * (temp_f1_2151 * temp_f1_2151)) - 3.0)));
                        } else if (var_f4_2138 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_2138 = __float_nan;
                        } else {
                            sp8 = var_f4_2138;
                            temp_r3_2170 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_2170) { /* irregular */
                            case 0x7F800000:
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_2180 = 1;
                                } else {
                                    var_r0_2180 = 2;
                                }
                                break;
                            case 0x0:
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_2180 = 5;
                                } else {
                                    var_r0_2180 = 3;
                                }
                                break;
                            default:
                                var_r0_2180 = 4;
                                break;
                            }
                            if (var_r0_2180 == 1) {
                                var_f4_2138 = __float_nan;
                            }
                        }
                        M2C_FIELD(temp_r30_2118, f32 *, 0x18) = (f32) (var_f4_2138 / ((f32) M2C_FIELD(M2C_FIELD(temp_r30_2118, void **, 0), s16 *, 4) / 30.0f));
                    }
                    var_r25_2114 += 1;
                    var_r20_2115 += 0x20;
                } while (var_r25_2114 < 3);
                var_r27_2109 += 1;
                var_r21_2110 += 0x70;
                goto loop_27;
            }
            var_r28_2105 += 1;
            var_r22_2106 += 8;
        } while (var_r28_2105 < 0x13);
        var_r29_2101 += 1;
        var_r23_2102 += 0x98;
        goto loop_30;
    }
    this->unk12C *= 100.0f;
    this->unk130 *= 100.0f;
    this->unk134 *= 100.0f;
    this->unk138 *= 100.0f;
    this->unk13C *= 100.0f;
    this->unk148 *= 100.0f;
    this->unk140 *= 100.0f;
    this->unk164 *= 100.0f;
    this->unk14C *= 0.017453292f;
    this->unk154 *= 0.017453292f;
    this->unk158 *= 0.017453292f;
    this->unk15C *= 0.017453292f;
    this->unk160 *= 0.017453292f;
    this->unk268 = (u32) Tools_GetMatchingNodeIndex(this->unk2C, "l_foot");
    this->unk26C = (u32) Tools_GetMatchingNodeIndex(this->unk2C, "r_foot");
    this->unk270 = (u32) Tools_GetMatchingNodeIndex(this->unk2C, "head");
    this->unk288 = (s32) Tools_GetMatchingNodeIndex(this->unk2C, "pelvis");
    this->unk290 = GetAnimSequence(4, 0x14, 0, NULL);
    this->unk294 = GetAnimSequence(4, 0x15, 0, NULL);
    InitArmour();
    this->unk29C = MKMaterial_Create"FX_FireOverride";
    this->unk2A0 = MKMaterial_Create"FX_ElectricityOverride";
    this->unk2A4 = MKMaterial_Create"FX_IceOverride";
    this->unk2A8 = MKMaterial_Create"FX_EarthOverride";
    this->unk298 = (u32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "shield");
    this->unk284 = (MKHeap *) Tools_GetMatchingRefPointIndex(this->unk2C, "breath");
    if ((u8) this->unk264 != 0) {
        temp_r3_2360 = this->unk284;
        if (temp_r3_2360 != (MKHeap *)-1U) {
            temp_r3_2364 = temp_r3_2360->Current();
            if (temp_r3_2364 != NULL) {
                var_r3_2371 = ((MKHeap *) (temp_r3_2364->Current()))->Alloc(0x20, NULL, 0);
            } else {
                var_r3_2371 = malloc(0x20);
            }
            this->unk258 = var_r3_2371;
            this->unk258->Init();
            this->unk258->unk0 = (u32) this->unk284;
        }
    }
    this->unk260 = checked_cast<IceBitsPS *, MKProp>(gMK->CreateProp("IceBitsPS"));
    if (HasAttack(0x2000U, 0) != 0) {
        this->unk25C = checked_cast<ElementalRing *, MKProp>(gMK->CreateProp("ElementalRing"));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 EnemyDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2421;

    var_r31_2421 = 0;
    if ((CharacterDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "sndHeroHit", (int *) &this->unk180) != 0) || (KDSound_LoadLine(arg0, "sndHurt", (int *) &this->unk190) != 0) || (KDSound_LoadLine(arg0, "sndHitByHero", (int *) &this->unk184) != 0) || (KDSound_LoadLine(arg0, "sndHitByExplosion", (int *) &this->unk188) != 0) || (KDSound_LoadLine(arg0, "sndHitByHeroBlocked", (int *) &this->unk18C) != 0) || (KDSound_LoadLine(arg0, "sndArmourHitMelee", (int *) &this->unk1B0) != 0) || (KDSound_LoadLine(arg0, "sndArmourShatter", (int *) &this->unk1B4) != 0) || (arg0->LoadString("meleeTrailsPropName", &this->unk274, 0) != 0) || (DataMap_LoadLine(arg0, "iElementType", &ElementTypeDataMap, (unsigned int *) &this->unk1D0) != 0) || (arg0->LoadString("addfile", &this->unk278, 0) != 0) || (arg0->LoadBool("bBreathFX", &this->unk264, 0) != 0) || (arg0->LoadBool("bBodyEffects", &this->unk265, 0) != 0) || (arg0->LoadInt("iInitialAttackPattern", (int *) &this->unk22C, 0) != 0)) {
        var_r31_2421 = 1;
    }
    return var_r31_2421;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap' to
void EnemyDescriptor::Deinit() {
    CharacterBreathFXDescriptor *temp_r29_2578;
    EAPManagerDescriptor *temp_r3_2555;
    MKHeap *temp_r29_2562;
    MKHeap *temp_r29_2638;
    MKHeap *temp_r29_2668;
    MKHeap *temp_r3_2565;
    MKHeap *temp_r3_2581;
    MKHeap *temp_r3_2597;
    MKHeap *temp_r3_2617;
    MKHeap *temp_r3_2619;
    MKHeap *temp_r3_2639;
    MKHeap *temp_r3_2655;
    MKHeap *temp_r3_2671;
    s32 temp_r28_2692;
    s32 temp_r29_2594;
    s32 temp_r29_2652;
    s32 var_r27_2613;
    s32 var_r27_2688;
    s32 var_r30_2614;
    s32 var_r30_2689;
    void ***temp_r29_2618;

    temp_r3_2555 = this->unk230;
    if (temp_r3_2555 != NULL) {
        temp_r3_2555->Deinit();
        operator delete(this->unk230);
    }
    temp_r29_2562 = this->unk2AC;
    if (temp_r29_2562 != NULL) {
        temp_r3_2565 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2565 != NULL) {
            ((MKHeap *) (temp_r3_2565->Current()))->Free(temp_r29_2562, NULL, 0);
        } else {
            free((void ***) temp_r29_2562);
        }
    }
    temp_r29_2578 = this->unk258;
    if (temp_r29_2578 != NULL) {
        temp_r3_2581 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2581 != NULL) {
            ((MKHeap *) (temp_r3_2581->Current()))->Free(temp_r29_2578, NULL, 0);
        } else {
            free((void ***) temp_r29_2578);
        }
    }
    temp_r29_2594 = this->unk238;
    if ((u32) temp_r29_2594 != 0U) {
        temp_r3_2597 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2597 != NULL) {
            ((MKHeap *) (temp_r3_2597->Current()))->Free((void *) temp_r29_2594, NULL, 0);
        } else {
            free((void ***) temp_r29_2594);
        }
    }
    if ((MKHeap *) this->unk23C != NULL) {
        var_r27_2613 = 0;
        var_r30_2614 = 0;
loop_20:
        if (var_r27_2613 < (s32) this->unk234) {
            temp_r3_2617 = this->unk23C;
            temp_r29_2618 = *(temp_r3_2617 + var_r30_2614);
            temp_r3_2619 = temp_r3_2617->Current();
            if (temp_r3_2619 != NULL) {
                ((MKHeap *) (temp_r3_2619->Current()))->Free(temp_r29_2618, NULL, 0);
            } else {
                free(temp_r29_2618);
            }
            var_r27_2613 += 1;
            var_r30_2614 += 4;
            goto loop_20;
        }
        temp_r29_2638 = this->unk23C;
        temp_r3_2639 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2639 != NULL) {
            ((MKHeap *) (temp_r3_2639->Current()))->Free(temp_r29_2638, NULL, 0);
        } else {
            free((void ***) temp_r29_2638);
        }
    }
    temp_r29_2652 = this->unk240;
    if ((u32) temp_r29_2652 != 0U) {
        temp_r3_2655 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2655 != NULL) {
            ((MKHeap *) (temp_r3_2655->Current()))->Free((void *) temp_r29_2652, NULL, 0);
        } else {
            free((void ***) temp_r29_2652);
        }
    }
    temp_r29_2668 = this->unk27C;
    if (temp_r29_2668 != NULL) {
        temp_r3_2671 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2671 != NULL) {
            ((MKHeap *) (temp_r3_2671->Current()))->Free(temp_r29_2668, NULL, 0);
        } else {
            free((void ***) temp_r29_2668);
        }
    }
    Deinit_Animation();
    Deinit_Attacks();
    var_r27_2688 = 0;
    var_r30_2689 = 0;
    do {
        temp_r28_2692 = var_r30_2689 + 0x29C;
        MKMaterial_Destroy(*(this + temp_r28_2692));
        var_r27_2688 += 1;
        *(this + temp_r28_2692) = 0;
        var_r30_2689 += 4;
    } while (var_r27_2688 < 4);
    if ((u8) this->unk1D6 != 0) {
        EnemySettings_UnregisterSettings(&this->unk1D8);
    }
    MKPropDescriptor::Deinit();
}
#endif

void EnemyDescriptor::Init() {
    CharacterDescriptor::Init();
    this->unkC |= 0x28;
    this->unk7C.unk10 = 3;
    this->unk7C.unk18 |= 0x20000000;
    this->unk60 = 40.0f;
    this->unk64 = 2.0f * this->unk60;
    this->unk68 = 50.0f;
    this->unkE8 = 100.0f;
    this->unkEC = 0.0f;
    this->unkF0 = 0.0f;
    this->unkF8 = 0;
    this->unkFC = 1;
    this->unk100 = 0;
    this->unk104 = 0;
    this->unk108 = 1;
    this->unk10C = 1;
    this->unk110 = 1;
    this->unk114 = 1;
    this->unk118 = 1;
    this->unk11C = 1;
    this->unk120 = 0;
    this->unk121 = 1;
    this->unk122 = 0;
    this->unk123 = 1;
    this->unk124 = 0.0f;
    this->unk128 = 5.0f;
    this->unk12C = 12.0f;
    this->unk130 = 4.0f;
    this->unk134 = 14.0f;
    this->unk138 = 15.0f;
    this->unk13C = 13.0f;
    this->unk140 = 20.0f;
    this->unk144 = 0.0f;
    this->unk148 = 1.0f;
    this->unk14C = 270.0f;
    this->unk150 = 0.0f;
    this->unk164 = 0.0f;
    this->unk154 = 360.0f;
    this->unk158 = 60.0f;
    this->unk15C = 100.0f;
    this->unk160 = 720.0f;
    this->unk168 = 1.0f;
    this->unk16C = 800.0f;
    this->unk170 = 1.0f;
    this->unk174 = 0.0f;
    this->unk178 = 10.0f;
    this->unk17C = 0;
    this->unk17D = 0;
    this->unk17E = 0;
    this->unk180 = GS_SpyroMeleeHit;
    this->unk184 = 0;
    this->unk188 = 0;
    this->unk18C = 0;
    this->unk190 = 0;
    this->unk1A4 = 0;
    this->unk1A8 = 0;
    this->unk1AC = 0;
    this->unk1B8 = 0;
    this->unk1BC = 0;
    this->unk1C0 = 0;
    this->unk1C4 = GS_EnemySpinMed;
    this->unk1C0 = 0;
    this->unk194 = GS_CLArmorHit;
    this->unk198 = GS_CLArmorHit;
    this->unk19C = GS_CLArmorHit;
    this->unk1A0 = GS_CLArmorHit;
    this->unk1B0 = GS_CLArmorHit;
    this->unk1B4 = GS_CLArmorSmash;
    this->unk1CC = -1;
    this->unk1D0 = 0x7FFFFFFE;
    this->unk1D4 = 1;
    this->unk1D5 = 1;
    this->unk1D6 = 0;
    this->unk1D7 = 0;
    this->unk1D8.InitToOne();
    this->unk214 = 0;
    this->unk21C = 0;
    this->unk218 = 0;
    this->unk220 = 0;
    this->unk224 = 0;
    this->unk228 = NULL;
    this->unk274 = NULL;
    this->unk248 = 0;
    this->unk268 = 0xFFFF;
    this->unk26C = 0xFFFF;
    this->unk270 = 0xFFFF;
    this->unk288 = 0xFFFF;
    this->unk27C = NULL;
    this->unk25C = 0;
    this->unk234 = 0;
    this->unk238 = 0;
    this->unk23C = NULL;
    this->unk240 = 0;
    this->unk278 = NULL;
    this->unk280 = 0xFFFF;
    this->unk284 = (MKHeap *)0xFFFFU;
    this->unk264 = 0;
    this->unk258 = NULL;
    this->unk28C = NULL;
    this->unk265 = 1;
    this->unk204 = &emAnims;
    this->unk208 = 0xE;
    this->unk20C = 0xB;
    this->unk210 = 0xA;
    this->unk2AC = NULL;
    this->unk2B0 = 0;
    this->unk230 = NULL;
    this->unk22C = 0;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void SumAnimTranslation(MKAnimScript *arg0, MKAnim *arg1, float arg2) {
    f32 sp20;
    f32 sp1C;
    f32 sp18;                                       /* compiler-managed */
    MKVector3 sp8;
    MKAnim *temp_r31_2905;
    s32 temp_r3_2942;

    temp_r31_2905 = M2C_ERROR(/* Read from unset register $r5 */);
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp20 = 0.0f;
    if (temp_r31_2905 != NULL) {
        ((MKAnimScript *) arg1)->SetAnim(temp_r31_2905, arg2, 0.0f, 4, -1);
        if (arg2 < 0.0f) {
            ((MKAnimScript *) arg1)->SetCurrentFrame((s32) temp_r31_2905->unkC);
        }
loop_4:
        temp_r3_2942 = arg1->unk2C;
        if (!(temp_r3_2942 & 1) && !(temp_r3_2942 & 2)) {
            ((MKAnimScript *) arg1)->Animate(MKModel_GetAnimation(M2C_FIELD(arg1, MKModel **, 8)), -1, &sp8);
            sp18 = (f64) sp18 + M2C_BITWISE(f64, sp8);
            sp20 += sp8.unk8;
            goto loop_4;
        }
    }
    M2C_FIELD(arg0, f64 *, 0) = sp18;
    M2C_FIELD(arg0, f64 *, 8) = (f64) sp20;
}
#endif
