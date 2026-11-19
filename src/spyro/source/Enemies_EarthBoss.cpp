#include "spyro/source/Enemies_EarthBoss.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionItem.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionModel.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKDynamicBone.h"
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
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EarthBossGoals.h"
#include "spyro/source/EarthShockwave.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/Goal.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/PhrasePlayer.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 atoi(s8 *);                                     /* extern */
M2C_UNK free(MKAnimScript *);                       /* extern */
MKCollisionInfo *malloc(s32);                       /* extern */
extern s32 GS_SSAlert;
extern s32 GS_SSAttack3;
extern void **gMK;
extern MKMaterial *gRenderState;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern void *gpTranslation_StringArray;

static s32 lit_1315 = 4;
static s32 lit_1319 = 5;
static s32 lit_1334 = 1;
#if 0 // DRAFT: illegal return value in void/constructor/destructor function
static M2C_UNK lit_1039;                               /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_1040;                               /* unable to generate initializer: unknown type; const */

void EarthBoss::GetCharacterName() {
    return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x32C);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void EarthBoss::InterceptDamage() {
    s32 temp_r0_101;
    s32 temp_r4_68;
    s32 var_ctr_83;
    s32 var_r0_69;
    s32 var_r5_78;
    s32 var_r8_56;
    void *temp_r7_85;
    void *var_r6_64;

    var_r8_56 = 0;
loop_13:
    temp_r0_101 = this->unk9D4;
    if (var_r8_56 < temp_r0_101) {
        if ((var_r8_56 < 0) || (var_r8_56 >= temp_r0_101)) {
            var_r6_64 = NULL;
        } else {
            temp_r4_68 = this->unk9D0;
            var_r0_69 = this->unk9D8 + var_r8_56;
            if (var_r0_69 >= temp_r4_68) {
                var_r0_69 -= temp_r4_68;
            }
            var_r6_64 = this->unk9DC + (var_r0_69 * 0x38);
        }
        var_r5_78 = 0;
        M2C_FIELD(var_r6_64, u8 *, 0x34) = (u8) (M2C_FIELD(var_r6_64, u8 *, 0x34) & ~0x80);
        var_ctr_83 = 6;
        do {
            temp_r7_85 = this + var_r5_78;
            if (((u32) M2C_FIELD(var_r6_64, u32 *, 0x10) == (u32) M2C_FIELD(temp_r7_85, u32 *, 0xB10)) && ((u8) M2C_FIELD(temp_r7_85, u8 *, 0xB56) != 0)) {
                M2C_FIELD(var_r6_64, f32 *, 0x24) = (f32) (M2C_FIELD(var_r6_64, f32 *, 0x24) * 1.5f);
            }
            var_r5_78 += 0x48;
            var_ctr_83 -= 1;
        } while (var_ctr_83 != 0);
        var_r8_56 += 1;
        goto loop_13;
    }
}
#endif

s32 EarthBoss::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp10;
    f64 sp8;
    f32 temp_f0_135;
    f32 temp_f1_129;
    f32 temp_f2_130;
    f32 temp_f6_127;
    f32 var_f7_112;
    s32 var_ctr_122;
    s32 var_r6_113;
    void *temp_r4_124;
    void *temp_r7_114;

    var_f7_112 = 3.4028235e38f;
    var_r6_113 = 0;
    temp_r7_114 = this->unk8;
    sp8 = M2C_FIELD(temp_r7_114, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r7_114, f64 *, 0x38);
    var_ctr_122 = 6;
    do {
        temp_r4_124 = this + var_r6_113;
        temp_f6_127 = M2C_FIELD(temp_r4_124, f32 *, 0xB1C) - arg0.unk4;
        temp_f1_129 = M2C_FIELD(temp_r4_124, f32 *, 0xB18) - arg0.unk0;
        temp_f2_130 = M2C_FIELD(temp_r4_124, f32 *, 0xB20) - arg0.unk8;
        temp_f0_135 = (temp_f2_130 * temp_f2_130) + ((temp_f1_129 * temp_f1_129) + (temp_f6_127 * temp_f6_127));
        if (temp_f0_135 < var_f7_112) {
            var_f7_112 = temp_f0_135;
            sp8 = (f64) M2C_FIELD(temp_r4_124, f32 *, 0xB18);
            sp10 = (f64) M2C_FIELD(temp_r4_124, f32 *, 0xB20);
        }
        var_r6_113 += 0x48;
        var_ctr_122 -= 1;
    } while (var_ctr_122 != 0);
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    M2C_FIELD(arg1, f64 *, 8) = sp10;
    return 1;
}

s32 EarthBoss::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp10;
    f64 sp8;
    f32 temp_f0_183;
    f32 temp_f1_177;
    f32 temp_f2_178;
    f32 temp_f6_175;
    f32 var_f7_160;
    s32 var_ctr_170;
    s32 var_r6_161;
    void *temp_r4_172;
    void *temp_r7_162;

    var_f7_160 = 3.4028235e38f;
    var_r6_161 = 0;
    temp_r7_162 = this->unk8;
    sp8 = M2C_FIELD(temp_r7_162, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r7_162, f64 *, 0x38);
    var_ctr_170 = 6;
    do {
        temp_r4_172 = this + var_r6_161;
        temp_f6_175 = M2C_FIELD(temp_r4_172, f32 *, 0xB1C) - arg0.unk4;
        temp_f1_177 = M2C_FIELD(temp_r4_172, f32 *, 0xB18) - arg0.unk0;
        temp_f2_178 = M2C_FIELD(temp_r4_172, f32 *, 0xB20) - arg0.unk8;
        temp_f0_183 = (temp_f2_178 * temp_f2_178) + ((temp_f1_177 * temp_f1_177) + (temp_f6_175 * temp_f6_175));
        if (temp_f0_183 < var_f7_160) {
            var_f7_160 = temp_f0_183;
            sp8 = (f64) M2C_FIELD(temp_r4_172, f32 *, 0xB18);
            sp10 = (f64) M2C_FIELD(temp_r4_172, f32 *, 0xB20);
        }
        var_r6_161 += 0x48;
        var_ctr_170 -= 1;
    } while (var_ctr_170 != 0);
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    M2C_FIELD(arg1, f64 *, 8) = sp10;
    return 1;
}

void EarthBoss::RestartStage() {
    EarthBossArm *temp_r4_216;
    s32 var_r0_222;

    GetMaxHealth();
    SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
    UpdateEnemyHud();
    temp_r4_216 = this->unkCC0;
    if (temp_r4_216 != NULL) {
        var_r0_222 = 0xA - (this->unkAE8 * 4);
        if ((s32) lit_1334 > var_r0_222) {
            var_r0_222 = lit_1334;
        }
        temp_r4_216->unk388 = var_r0_222;
    }
    this->unkCC8 = (0.5f * (f32) (this->unkA38->unk11C - this->unkAE8)) + 1.0f;
}

void EarthBossArm::DoHitFx(EnemyDamageFeedback *arg0) {
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 var_f1_351;
    s32 temp_r0_350;
    s32 temp_r5_257;

    temp_r5_257 = arg0->unk20;
    if (temp_r5_257 & 0x10) {
        sp58 = 1.0f;
        sp5C = 0.5f;
        this->unk450 = 0.5f;
        sp60 = 0.0f;
        sp64 = 1.0f;
        this->unk458 = (f64) sp58;
        spB8 = (f64) sp58;
        spC0 = (f64) sp60;
        this->unk460 = (f64) sp60;
        return;
    }
    if (temp_r5_257 & 0x20) {
        sp48 = 1.0f;
        sp4C = 1.0f;
        this->unk450 = 0.5f;
        sp50 = 0.4f;
        sp54 = 1.0f;
        this->unk458 = (f64) sp48;
        spA8 = (f64) sp48;
        spB0 = (f64) sp50;
        this->unk460 = (f64) sp50;
        return;
    }
    if (temp_r5_257 & 0x40) {
        sp38 = 0.25f;
        sp3C = 0.25f;
        this->unk450 = 0.5f;
        sp40 = 1.0f;
        sp44 = 1.0f;
        this->unk458 = (f64) sp38;
        sp98 = (f64) sp38;
        spA0 = (f64) sp40;
        this->unk460 = (f64) sp40;
        return;
    }
    if (temp_r5_257 & 4) {
        sp28 = 0.25f;
        sp2C = 0.25f;
        this->unk450 = 0.5f;
        sp30 = 1.0f;
        sp34 = 1.0f;
        this->unk458 = (f64) sp28;
        sp88 = (f64) sp28;
        sp90 = (f64) sp30;
        this->unk460 = (f64) sp30;
        return;
    }
    if (temp_r5_257 & 0x80) {
        sp18 = 0.0f;
        sp1C = 1.0f;
        this->unk450 = 0.5f;
        sp20 = 0.0f;
        sp24 = 1.0f;
        this->unk458 = (f64) sp18;
        sp78 = (f64) sp18;
        sp80 = (f64) sp20;
        this->unk460 = (f64) sp20;
        return;
    }
    if (temp_r5_257 & 1) {
        temp_r0_350 = arg0->unk30;
        var_f1_351 = 1.5f;
        switch (temp_r0_350) {                      /* irregular */
        case 1:
            var_f1_351 = 2.5f;
            break;
        case 2:
            var_f1_351 = 2.5f;
            break;
        case 3:
            var_f1_351 = 4.0f;
            break;
        }
        this->unk3A0.SetState(lit_1315, var_f1_351);
        return;
    }
    if (temp_r5_257 & 2) {
        this->unk3A0.SetState(lit_1319, 1.0f);
        return;
    }
    if (temp_r5_257 & 8) {
        sp8 = 0.0f;
        spC = 1.0f;
        this->unk450 = 0.5f;
        sp10 = 0.0f;
        sp14 = 1.0f;
        this->unk458 = (f64) sp8;
        sp68 = (f64) sp8;
        sp70 = (f64) sp10;
        this->unk460 = (f64) sp10;
    }
}

#if 0 // DRAFT: undefined identifier 'MKVector'
void EarthBoss::DoHitFx(EnemyDamageFeedback *arg0) {
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    MKVector3 spF8;
    MKVector3 spE8;
    M2C_UNK spD8;
    MKVector3 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
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
    f64 sp8;
    f32 temp_f1_485;
    s32 var_r29_444;

    Enemy::DoHitFx(arg0);
    this->unkCC0->DoHitFx(arg0);
    if (arg0->unk20 & 0x3F0) {
        var_r29_444 = 0;
        do {
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(spF8, spE8);
            sp8 = spF8 * 5.758944265e-315;
            sp18 = 1.0f;
            sp1C = 0.75f;
            sp10 = spF8.unk8 * 4000.0f;
            sp20 = 0.2f;
            sp24 = 1.0f;
            sp108 = sp8;
            sp110 = (f64) sp10;
            sp118 = sp8;
            sp120 = (f64) sp10;
            sp68 = (f64) sp18;
            sp70 = (f64) sp20;
            temp_f1_485 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
            sp30 = 3.1415927f;
            sp40 = -3.1415927f;
            sp50 = 3.1415927f;
            sp60 = -3.1415927f;
            sp28 = 3.1415927f;
            sp2C = 3.1415927f;
            sp38 = -3.1415927f;
            sp3C = -3.1415927f;
            sp48 = 3.1415927f;
            sp4C = 3.1415927f;
            sp58 = -3.1415927f;
            sp5C = -3.1415927f;
            sp78 = (f64) sp28;
            sp80 = (f64) sp30;
            sp88 = (f64) sp38;
            sp90 = (f64) sp40;
            spA8 = (f64) sp48;
            spB0 = (f64) sp50;
            spB8 = (f64) sp58;
            spC0 = (f64) sp60;
            KDRand_Vector(sp98, *((MKVector3 *) &sp88));
            KDRand_Vector(spC8, *((MKVector3 *) &spB8));
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xAC)))->Emit(*((MKVector3 *) arg0), *((MKVector3 *) &sp118), spC8, sp98, temp_f1_485, *((MKVector4 *) &sp68), 0, (MKProp *) this);
            var_r29_444 += 1;
        } while (var_r29_444 < 0xA);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
void EarthBoss::CollideWithShatterables() {
    MKCollisionResult sp38;
    M2C_UNK *sp34;
    s32 sp30;
    s8 sp2C;
    s32 sp28;
    s32 sp24;
    s8 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 spC;
    s32 sp8;
    f32 var_f1_578;
    s32 temp_r31_616;
    s32 var_r26_618;
    s32 var_r27_571;
    s32 var_r29_617;
    s32 var_r30_570;
    void **var_r3_629;
    void **var_r3_661;
    void *temp_r3_626;
    void *temp_r3_658;
    void *temp_r6_622;

    var_r30_570 = 0;
    var_r27_571 = 0;
    sp34 = &__vt;
    spC = 0;
    sp34 = &__vt;
    do {
        var_f1_578 = 0.0f;
        if ((var_r30_570 != 2) || ((s32) this->unkCC0->unk38C == 0)) {
            if (var_r30_570 != 4) {
                if (var_r30_570 < 4) {
                    if (var_r30_570 < 2) {
                        if (var_r30_570 < 0) {

                        } else {
                            var_f1_578 = 200.0f;
                        }
                    } else {
                        var_f1_578 = 150.0f;
                    }
                } else if (var_r30_570 < 6) {
                    var_f1_578 = 350.0f;
                }
            } else {
                var_f1_578 = 200.0f;
            }
            temp_r31_616 = MKCollision_SphereCollide(*(this + (var_r27_571 + 0xB18)), var_f1_578, &sp38, 0xA, (MKCollisionMode) 2, 0x0C000000);
            var_r29_617 = 0;
            var_r26_618 = 0;
loop_28:
            if (var_r29_617 < temp_r31_616) {
                temp_r6_622 = &sp38 + var_r26_618;
                if (((u8) M2C_FIELD(temp_r6_622, u8 *, 0x50) != 0) && (temp_r3_626 = M2C_FIELD(temp_r6_622, void **, 0x48), ((temp_r3_626 == NULL) == 0)) && (var_r3_629 = M2C_FIELD(temp_r3_626, void ***, 8), ((var_r3_629 == NULL) == 0))) {

                } else {
                    var_r3_629 = NULL;
                }
                if (M2C_FIELD(*var_r3_629, s32 *, 0xC) & 0x200) {
                    sp8 = 0x30;
                    sp10 = 0.0f;
                    sp14 = 0.0f;
                    sp18 = 0.0f;
                    sp20 = 0;
                    sp24 = -1;
                    sp28 = 0;
                    sp2C = 0;
                    sp30 = 0;
                    sp8 = 0x31;
                    if (((u8) M2C_FIELD(temp_r6_622, u8 *, 0x50) != 0) && (temp_r3_658 = M2C_FIELD(temp_r6_622, void **, 0x48), ((temp_r3_658 == NULL) == 0)) && (var_r3_661 = M2C_FIELD(temp_r3_658, void ***, 8), ((var_r3_661 == NULL) == 0))) {

                    } else {
                        var_r3_661 = NULL;
                    }
                    M2C_FIELD(M2C_FIELD(var_r3_661, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
                }
                var_r29_617 += 1;
                var_r26_618 += 0x58;
                goto loop_28;
            }
        }
        var_r30_570 += 1;
        var_r27_571 += 0x48;
    } while (var_r30_570 < 6);
}
#endif

void EarthBoss::ShowFist(bool arg0) {
    MKModel *temp_r4_700;
    u16 temp_r3_706;
    u32 temp_r5_717;

    temp_r4_700 = this->unk4;
    if (temp_r4_700 != NULL) {
        temp_r3_706 = Tools_GetMatchingSubObjectIndex((SubObjectType) 0, temp_r4_700, "Fist");
        if (temp_r3_706 != -1U) {
            MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, (s32) temp_r3_706, arg0, 1U);
        }
        temp_r5_717 = this->unkCD8;
        if (temp_r5_717 != -1U) {
            MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, (s32) temp_r5_717, arg0, 1U);
        }
    }
}

#if 0 // DRAFT: illegal operands 'EarthBossDescriptor' != 'float'
void EarthBoss::UpdatePhrasesAndSounds() {
    EnemyDescriptor *temp_r3_749;
    f32 temp_f1_851;
    f32 temp_f30_760;
    f32 temp_f30_775;
    f32 temp_f31_756;
    f32 temp_f31_812;
    s32 var_r29_781;
    s32 var_r30_782;

    temp_r3_749 = this->unkA38;
    temp_f31_756 = this->unkAC8;
    temp_f30_760 = (f32) temp_r3_749->unk11C * this->unkA38->GetEnemySetting((EnemySettingType) 0);
    temp_f30_775 = ((temp_f30_760 - ((f32) (this->unkAE8 + 1) * temp_r3_749->GetEnemySetting((EnemySettingType) 0))) + temp_f31_756) / temp_f30_760;
    if (temp_f30_775 > this->unkCEC) {
        this->unkCEC = temp_f30_775;
    }
    var_r29_781 = 0;
    var_r30_782 = 0;
loop_3:
    if ((temp_f30_775 != 0.0f) && (*(checked_cast<EarthBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_782 + 0x2D4)) != 0.0f) && (this->unkCEC > *(checked_cast<EarthBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_782 + 0x2D4))) && (temp_f30_775 <= *(checked_cast<EarthBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_782 + 0x2D4)))) {
        temp_f31_812 = 2.0f * M2C_FIELD(checked_cast<EarthBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2FC);
        this->unkCF0 = MKRand_Float((int *) &gViewSeed, M2C_FIELD(checked_cast<EarthBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2FC), temp_f31_812);
        this->unkCE8 = checked_cast<EarthBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_782 + 0x2B4);
    } else {
        var_r29_781 += 1;
        var_r30_782 += 0x24;
        if (var_r29_781 < 2) {
            goto loop_3;
        }
    }
    if ((this->unkCF0 < 0.0f) && ((s8 *) this->unkCE8 != NULL) && (PhrasePlayer_IsAnyEventPlaying() == 0)) {
        this->unkCE4 = PhrasePlayer_PlayEvent(this->unkCE8);
        this->unkCF0 = 0.0f;
        this->unkCE8 = NULL;
    }
    this->unkCEC = temp_f30_775;
    temp_f1_851 = this->unkCF0;
    if (temp_f1_851 > 0.0f) {
        this->unkCF0 = temp_f1_851 - gUpdateTimeDelta;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'Matrix' to
void EarthBoss::UpdateCollisionItems() {
    f64 sp180;
    M2C_UNK sp150;
    Matrix sp110;
    Matrix spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    MKVector3 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    Animation *temp_r29_887;
    EarthBossArm *temp_r4_1013;
    f32 temp_f30_949;
    f32 temp_f31_957;
    f32 temp_f3_915;
    f32 temp_f6_922;
    f32 temp_f8_928;
    f64 temp_f0_1050;
    f64 temp_f0_1062;
    s32 temp_r25_900;
    s32 var_r26_889;
    s32 var_r28_888;
    void *temp_r30_891;

    temp_r29_887 = MKModel_GetAnimation(this->unk4);
    var_r28_888 = 0;
    var_r26_889 = 0;
    do {
        temp_r30_891 = this + var_r26_889;
        if ((u8) M2C_FIELD(temp_r30_891, u8 *, 0xB55) != 0) {
            temp_r25_900 = M2C_FIELD(temp_r30_891, s32 *, 0xB50);
            M2C_STRUCT_COPY((s32) &spD0.unk3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            MKModel_CalculateNodeWorldMatrix(this->unk4, temp_r25_900, &sp110);
            sp110.Inverse(&sp110);
            temp_f3_915 = M2C_FIELD(temp_r30_891, f32 *, 0xB3C);
            temp_f6_922 = M2C_FIELD(temp_r30_891, f32 *, 0xB38);
            temp_f8_928 = M2C_FIELD(temp_r30_891, f32 *, 0xB40);
            sp50 = (temp_f8_928 * sp110.unk20) + ((temp_f6_922 * M2C_BITWISE(f32, sp110)) + (temp_f3_915 * sp110.unk10));
            sp54 = (temp_f8_928 * sp110.unk24) + ((temp_f6_922 * sp110.unk4) + (temp_f3_915 * sp110.unk14));
            sp58 = (temp_f8_928 * sp110.unk28) + ((temp_f6_922 * sp110.unk8) + (temp_f3_915 * sp110.unk18));
            spC0 = (f64) sp50;
            spC8 = (f64) sp58;
            temp_f30_949 = 50.0f * (1.0f - (M2C_FIELD(temp_r30_891, f32 *, 0xB48) / 1.0f));
            spD0.SetIdentity();
            temp_f31_957 = _table_sinf(8.0f * (3.1415927f * M2C_FIELD(temp_r30_891, f32 *, 0xB48)));
            spA0.operator*(temp_f30_949);
            sp40 = spA0 * (f64) temp_f31_957;
            spB0 = sp40;
            sp48 = spA0.unk8 * temp_f31_957;
            spB8 = (f64) sp48;
            spD0.unk30 = (f32) spB0;
            spD0.unk34 = (*(f32 *) ((u8 *) &spB0 + 0x4));
            spD0.unk38 = (f32) spB8;
            spD0.unk3C = 1.0f;
            temp_r29_887->SetCustomMatrix(temp_r25_900, &spD0, (AnimationMatrixPosition) 2, 0U);
            M2C_FIELD(temp_r30_891, f32 *, 0xB48) = (f32) (M2C_FIELD(temp_r30_891, f32 *, 0xB48) + gUpdateTimeDelta);
            if (M2C_FIELD(temp_r30_891, f32 *, 0xB48) >= 1.0f) {
                M2C_FIELD(temp_r30_891, u8 *, 0xB55) = 0U;
                ((Animation *) (MKModel_GetAnimation(this->unk4)))->SetCustomMatrix(temp_r25_900, NULL, (AnimationMatrixPosition) 2, 0U);
            }
        }
        if ((u8) M2C_FIELD(temp_r30_891, u8 *, 0xB54) != 0) {
            ((Matrix *) &sp150)->SetIdentity();
            if ((var_r28_888 == 2) && (temp_r4_1013 = this->unkCC0, (((s32) temp_r4_1013->unk38C == 0) == 0))) {
                MKModel_CalculateNodeWorldMatrix(temp_r4_1013->unk4, temp_r4_1013->unk344, (Matrix *) &sp150);
                sp80.operator*(200.0f);
                sp30 = sp180 + M2C_BITWISE(f64, sp80);
                M2C_FIELD(temp_r30_891, f64 *, 0xB18) = sp30;
                sp38 = sp188 + sp80.unk8;
                sp90 = sp30;
                sp98 = (f64) sp38;
                M2C_FIELD(temp_r30_891, f64 *, 0xB20) = (f64) sp38;
            } else {
                MKModel_CalculateNodeWorldMatrix(this->unk4, M2C_FIELD(temp_r30_891, s32 *, 0xB4C), (Matrix *) &sp150);
                ((Matrix *) &sp150)->YAxis3();
                temp_f0_1050 = *M2C_ERROR(/* Read from unset register $r3 */) * M2C_FIELD(temp_r30_891, f64 *, 0xB28);
                sp10 = temp_f0_1050;
                sp60 = temp_f0_1050;
                sp18 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8) * M2C_FIELD(temp_r30_891, f32 *, 0xB30);
                sp68 = (f64) sp18;
                temp_f0_1062 = sp180 + temp_f0_1050;
                sp20 = temp_f0_1062;
                M2C_FIELD(temp_r30_891, f64 *, 0xB18) = temp_f0_1062;
                sp70 = temp_f0_1062;
                sp28 = sp188 + (f32) sp68;
                sp78 = (f64) sp28;
                M2C_FIELD(temp_r30_891, f64 *, 0xB20) = (f64) sp28;
            }
        }
        var_r28_888 += 1;
        var_r26_889 += 0x48;
    } while (var_r28_888 < 6);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'EarthBoss' to
void EarthBoss::TempDisableCollision(bool arg0) {
    s32 temp_r0_1109;
    s32 var_ctr_1107;
    s32 var_ctr_1117;
    s32 var_r4_1104;
    s32 var_r5_1102;
    void *temp_r5_1119;

    var_r5_1102 = 0;
    var_r4_1104 = 0;
    if (arg0 != 0) {
        var_ctr_1107 = 6;
        do {
            temp_r0_1109 = var_r5_1102 + 0xB10;
            var_r5_1102 += 0x48;
            M2C_FIELD(*(this + temp_r0_1109), s8 *, 4) = 0;
            var_ctr_1107 -= 1;
        } while (var_ctr_1107 != 0);
        return;
    }
    var_ctr_1117 = 6;
    do {
        temp_r5_1119 = this + var_r4_1104;
        var_r4_1104 += 0x48;
        M2C_FIELD(M2C_FIELD(temp_r5_1119, void **, 0xB10), u8 *, 4) = (u8) M2C_FIELD(temp_r5_1119, u8 *, 0xB54);
        var_ctr_1117 -= 1;
    } while (var_ctr_1117 != 0);
}
#endif

void EarthBoss::UpdateEnemyHud() {
    EnemyHudData sp8;
    f32 temp_f31_1143;

    if ((u8) this->unkCDD != 0) {
        sp8.EnemyHudData();
        temp_f31_1143 = this->unkAC8;
        GetMaxHealth();
        sp8.Init((Enemy *) this, temp_f31_1143, M2C_ERROR(/* Read from unset register $f1 */));
        EnemyHud_Modified(sp8);
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EarthBoss::Despawn(bool arg0) {
    EarthBossArm *temp_r3_1176;

    Enemy::Despawn(arg0);
    M2C_FIELD(&gb, s32 *, 0x360) = 0;
    temp_r3_1176 = this->unkCC0;
    if (temp_r3_1176 != NULL) {
        M2C_FIELD(temp_r3_1176->__vptr, M2C_UNK (**)(), 0x34)();
    }
    UpdateEnemyHud();
}
#endif

s32 EarthBoss::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    if (Enemy::Spawn(arg0, arg1) != 0) {
        UpdateEnemyHud();
        KDSound_Stop((int *) &this->unkCE0);
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: ')' expected
void EarthBoss::Message(MKMessage *arg0) {
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    EarthBossArm *temp_r3_1324;
    f32 temp_f1_1355;
    f32 temp_f5_1361;
    f32 temp_f6_1347;
    s32 temp_r0_1232;
    void *temp_r3_1264;

    temp_r0_1232 = arg0->unk0;
    switch (temp_r0_1232) {                         /* irregular */
    case 181:
        Enable();
    default:
block_28:
        Enemy::Message(arg0);
        return;
    case 123:
        UpdateEnemyHud();
        return;
    case 5:
        temp_r3_1264 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
        if ((s32) M2C_FIELD(temp_r3_1264, s32 *, 0x38) == 3) {
            if (M2C_FIELD(temp_r3_1264, f32 *, 0x34) > 0.0f) {
                if ((s32) M2C_FIELD(temp_r3_1264, s32 *, 0x48) != 0) {
                    M2C_FIELD(temp_r3_1264, f32 *, 0x34) = 0.1f;
                } else {
                    M2C_FIELD(temp_r3_1264, f32 *, 0x34) = (f32) M2C_FIELD(checked_cast<EarthBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xF8);
                    M2C_FIELD(temp_r3_1264, s32 *, 0x38) = 0;
                }
                goto block_28;
            }
        } else {
            goto block_28;
        }
        break;
    case -3:
        if (!(((u8) this->unkB09 >> 7U) & 1)) {
            Enemy::Message(arg0);
            Deactivate();
            return;
        }
        goto block_28;
    case 21:
        if ((IsDying() == 0) && (IsDead() == 0)) {
            this->unkCF4.Send(NULL);
            RestartStage();
            this->unkCDC = 1;
            temp_r3_1324 = this->unkCC0;
            if (temp_r3_1324 != NULL) {
                M2C_FIELD(temp_r3_1324->__vptr, M2C_UNK (**)(), 0x20)();
            }
            ShowFist(1U);
            M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_f6_1347 = this->unk5C8;
            sp50 = temp_f6_1347;
            temp_f1_1355 = this->unk5CC;
            sp54 = temp_f1_1355;
            temp_f5_1361 = this->unk5D0;
            sp58 = temp_f5_1361;
            sp18 = (MKVector3::up.unk0 * temp_f1_1355) - (MKVector3::up.unk4 * temp_f6_1347);
            sp10 = (MKVector3::up.unk4 * temp_f5_1361) - (MKVector3::up.unk8 * temp_f1_1355);
            sp14 = (MKVector3::up.unk8 * temp_f6_1347) - (MKVector3::up.unk0 * temp_f5_1361);
            sp28 = (f64) sp18;
            sp20 = (f64) sp10;
            sp5C = 0.0f;
            sp30 = (f32) sp20;
            sp34 = (*(f32 *) ((u8 *) &sp20 + 0x4));
            sp38 = (f32) sp28;
            sp3C = 0.0f;
            sp60 = this->unk5B8;
            sp64 = this->unk5BC;
            sp68 = this->unk5C0;
            sp6C = 1.0f;
            TempDisableCollision(1U);
            Teleport(&sp30);
            TempDisableCollision(0U);
        }
        goto block_28;
    case 211:
        this->unkCDD = 1;
        M2C_FIELD(&gb, EarthBoss **, 0x360) = this;
        UpdateEnemyHud();
        goto block_28;
    }
}
#endif

void EarthBoss::Draw() {
    Enemy::Draw();
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
void EarthBoss::CheckAnimEvents() {
    s8 sp90;
    f64 sp88;
    f64 sp80;
    s32 sp7C;
    s32 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    M2C_UNK sp38;
    f64 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    EnemyAttack *temp_r30_1514;
    f32 temp_f31_1466;
    s32 temp_r0_1516;
    void *temp_r3_1509;

    if (((MKAnimScript *) this->unk630)->CheckEvent(4) != 0) {
        temp_f31_1466 = ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.025f, 0.2f, 0.2f, ((u8 *) this->unk8) + 0x30, 80.0f, 0, 4.0f, 0U);
        sp7C = 0;
        MKVector(0.025f, 0.4f, 0.025f);
        sp48.operator*(500.0f);
        sp8 = sp48 * (f64) temp_f31_1466;
        sp78 = 0x417;
        sp10 = sp48.unk8 * temp_f31_1466;
        sp80 = sp8;
        sp88 = (f64) sp10;
        sp90 = 1;
        sp58 = sp8;
        sp60 = (f64) sp10;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp78, sp8);
    }
    if (((MKAnimScript *) this->unk630)->CheckEvent(0xB) != 0) {
        temp_r3_1509 = this->unk8;
        sp68 = M2C_FIELD(temp_r3_1509, f64 *, 0x30);
        sp70 = M2C_FIELD(temp_r3_1509, f64 *, 0x38);
        temp_r30_1514 = this->unkA20;
        temp_r0_1516 = temp_r30_1514->unk0->unk68;
        switch (temp_r0_1516) {                     /* irregular */
        case 0x3D:
            MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) *temp_r30_1514->unk7C, (MKVector3 *) &sp68);
            /* fallthrough */
        case 0x3E:
            MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) *temp_r30_1514->unk7C, (MKVector3 *) &sp68);
            break;
        }
        sp1C = 1.0f;
        sp18 = 0.0f;
        sp20 = 0.0f;
        sp24 = 1.0f;
        sp28 = (f64) sp18;
        sp30 = (f64) sp20;
        this->unkCC4->Trigger(*((MKVector3 *) &sp68), 1.0f, 1U, (MKVector4) &sp28);
        return;
    }
    Enemy::CheckAnimEvents();
}
#endif

void EarthBoss::Update() {
    EarthBossArm *temp_r3_1580;

    TempDisableCollision(1U);
    Enemy::Update();
    TempDisableCollision(0U);
    temp_r3_1580 = this->unkCC0;
    temp_r3_1580->Update();
    CollideWithShatterables();
    UpdatePhrasesAndSounds();
}

void EarthBoss::SetDefaults() {
    Enemy::SetDefaults();
    this->unkCDC = 0;
    this->unkCDD = 0;
    this->unkCC8 = 0.0f;
    RestartStage();
}

#if 0 // DRAFT: illegal implicit conversion from 'EarthBoss *' to
void EarthBoss::SetupCollisionSphere(int arg0, const char *arg1, const char *arg2, float arg3, const MKVector3 &arg4) {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKCollisionInfo *temp_r3_1675;
    MKCollisionInfo *var_r3_1663;
    MKHeap *temp_r3_1646;
    MKHeap *temp_r3_1656;
    s32 temp_r30_1628;
    void *temp_r29_1669;

    temp_r30_1628 = arg0 * 0x48;
    M2C_FIELD((this + temp_r30_1628), s8 *, 0xB54) = 1;
    M2C_FIELD((this + temp_r30_1628), s32 *, 0xB4C) = (s32) Tools_GetMatchingNodeIndex(this->unk4, arg1);
    temp_r3_1646 = this + temp_r30_1628;
    M2C_FIELD(temp_r3_1646, s32 *, 0xB50) = (s32) Tools_GetMatchingNodeIndex(this->unk4, arg2);
    M2C_FIELD(temp_r3_1646, f32 *, 0xB18) = 0.0f;
    M2C_FIELD(temp_r3_1646, f32 *, 0xB1C) = 0.0f;
    M2C_FIELD(temp_r3_1646, f32 *, 0xB20) = 0.0f;
    M2C_FIELD(temp_r3_1646, f64 *, 0xB28) = (f64) M2C_FIELD(&arg4, f64 *, 0);
    M2C_FIELD(temp_r3_1646, f64 *, 0xB30) = (f64) M2C_FIELD(&arg4, f64 *, 8);
    temp_r3_1656 = temp_r3_1646->Current();
    if (temp_r3_1656 != NULL) {
        var_r3_1663 = ((MKHeap *) (temp_r3_1656->Current()))->Alloc(0x10, NULL, 0);
    } else {
        var_r3_1663 = malloc(0x10);
    }
    temp_r29_1669 = this + temp_r30_1628;
    M2C_FIELD(temp_r29_1669, MKCollisionInfo **, 0xB10) = var_r3_1663;
    temp_r3_1675 = M2C_FIELD(temp_r29_1669, MKCollisionInfo **, 0xB10);
    sp8 = 1.0f;
    temp_r3_1675->unk0 = 0;
    temp_r3_1675->unk4 = 1;
    temp_r3_1675->unk8 = (MKProp *) this;
    temp_r3_1675->unkC = 0;
    spC = 0.0f;
    M2C_FIELD(temp_r29_1669, MKCollisionInfo **, 0xB10)->unk4 = 0;
    M2C_FIELD(temp_r29_1669, s8 *, 0xB56) = 0;
    M2C_FIELD(temp_r29_1669, s8 *, 0xB55) = 0;
    sp10 = 0.0f;
    sp14 = 1.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **, M2C_UNK, f64, f32), 0x84)(gMK, 0, (f64) sp8, 1.0f)))->AddSphere(this + (temp_r30_1628 + 0xB18), arg3, 0.0f, *((MKVector4 *) &sp18), (MKCollisionMode) 2, M2C_FIELD(temp_r29_1669, MKCollisionInfo **, 0xB10), (u32) this->unkA38->unk70);
}
#endif

void EarthBoss::SetupCollision() {
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
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
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp60 = 0.0f;
    sp58 = 0.0f;
    sp5C = 200.0f;
    spC0 = (f64) sp60;
    spB8 = (f64) sp58;
    SetupCollisionSphere(0, "L_Foot", "L_Calf", 200.0f, *((MKVector3 *) &spB8));
    sp50 = 0.0f;
    sp48 = 0.0f;
    sp4C = 200.0f;
    spB0 = (f64) sp50;
    spA8 = (f64) sp48;
    SetupCollisionSphere(1, "R_Foot", "R_Calf", 200.0f, *((MKVector3 *) &spA8));
    sp40 = 0.0f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    spA0 = (f64) sp40;
    sp98 = (f64) sp38;
    SetupCollisionSphere(2, "L_Hand", "L_Forearm", 200.0f, *((MKVector3 *) &sp98));
    sp30 = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp90 = (f64) sp30;
    sp88 = (f64) sp28;
    SetupCollisionSphere(3, "R_Hand", "R_Forearm", 200.0f, *((MKVector3 *) &sp88));
    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = 130.0f;
    sp80 = (f64) sp20;
    sp78 = (f64) sp18;
    SetupCollisionSphere(4, "Pelvis", "Pelvis", 200.0f, *((MKVector3 *) &sp78));
    sp8 = 300.0f;
    spC = 250.0f;
    sp10 = 0.0f;
    sp68 = (f64) sp8;
    sp70 = (f64) sp10;
    SetupCollisionSphere(5, "Spine03", "Spine02", 350.0f, *((MKVector3 *) &sp68));
}

void EarthBoss::LoadDone() {
    Enemy::LoadDone();
    this->unkA40 = this->unkA3C;
    this->unkCCC = (s32) Tools_GetMatchingNodeIndex(this->unk4, "L_Bicep");
    this->unkCD0 = (s32) Tools_GetMatchingNodeIndex(this->unk4, "L_Forearm");
    this->unkCD4 = (s32) Tools_GetMatchingNodeIndex(this->unk4, "L_Hand");
    this->unkCD8 = (u32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, "rubble05");
    ShowFist(1U);
    this->unkCC0 = checked_cast<EarthBossArm *, MKProp>(((MKSceneManager *) gMK)->CreateProp("EarthBossArm"));
    this->unkCC0->Init2(this);
    if (!(this->unk680 & 0x160000)) {
        Disable();
    }
}

s32 EarthBoss::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1913;

    var_r31_1913 = 0;
    if ((Enemy::LoadLine(arg0) != 0) || (this->unkCF4.LoadLine(arg0, "OnReset") != 0)) {
        var_r31_1913 = 1;
    }
    return var_r31_1913;
}

#if 0 // DRAFT: illegal implicit conversion from 'EarthBoss' to
void EarthBoss::Deinit() {
    MKAnimScript *temp_r30_1949;
    MKHeap *temp_r3_1950;
    s32 var_r29_1945;
    s32 var_r31_1946;

    Enemy::Deinit();
    var_r29_1945 = 0;
    var_r31_1946 = 0;
    do {
        temp_r30_1949 = *(this + (var_r31_1946 + 0xB10));
        temp_r3_1950 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1950 != NULL) {
            ((MKHeap *) (temp_r3_1950->Current()))->Free(temp_r30_1949, NULL, 0);
        } else {
            free(temp_r30_1949);
        }
        var_r29_1945 += 1;
        var_r31_1946 += 0x48;
    } while (var_r29_1945 < 6);
    KDSound_Stop((int *) &this->unkCE0);
    PhrasePlayer_StopEvent(this->unkCE4);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EarthBoss::Init() {
    EarthBossGoal_Think *temp_r31_1993;

    this->unkCC0 = NULL;
    Enemy::Init();
    operator new(0x44U, NULL, 0);
    temp_r31_1993 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_1993 != NULL) {
        temp_r31_1993->__vptr = &__vt__16Goal<9EarthBoss>;
        temp_r31_1993->unk4 = 0;
        temp_r31_1993->unk8 = 1;
        temp_r31_1993->unk9 = 0;
        temp_r31_1993->unkC = NULL;
        temp_r31_1993->__vptr = (struct __vt__16Goal<9EarthBoss> *) &__vt__25CompositeGoal<9EarthBoss>;
        temp_r31_1993->unk1C = NULL;
        temp_r31_1993->unk18 = 0;
        temp_r31_1993->unk10 = 0;
        temp_r31_1993->unk14 = 0;
        temp_r31_1993->__vptr = &__vt;
    }
    temp_r31_1993->Init(this);
    this->unkA3C = &temp_r31_1993->__vptr;
    this->unkCE0 = 0;
    this->unkCE4 = 0;
    this->unkCE8 = NULL;
    this->unkCEC = 0.0f;
    this->unkCF0 = 0.0f;
    this->unkCC4 = checked_cast<EarthShockwave *, MKProp>(((MKSceneManager *) gMK)->CreateProp("EarthShockwave"));
    this->unkCF4.Init();
}
#endif

#if 0 // DRAFT: illegal operand
void EarthBossDescriptor::LoadDone() {
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
    BoundingVolume *temp_r3_2065;
    BoundingVolume *temp_r3_2085;
    s32 temp_r0_2056;
    s32 var_ctr_2054;
    s32 var_r3_2053;

    EnemyDescriptor::LoadDone();
    var_r3_2053 = 0;
    var_ctr_2054 = 2;
    do {
        temp_r0_2056 = var_r3_2053 + 0x2D4;
        var_r3_2053 += 0x24;
        *(this + temp_r0_2056) = *(this + temp_r0_2056) / 100.0f;
        var_ctr_2054 -= 1;
    } while (var_ctr_2054 != 0);
    sp18 = 0.0f;
    temp_r3_2065 = this->unk1C;
    sp1C = 0.0f;
    sp20 = 500.0f;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    M2C_FIELD(temp_r3_2065, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_2065, f64 *, 0) - sp38);
    sp10 = 500.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    temp_r3_2065->unk8 -= (f32) sp40;
    temp_r3_2085 = this->unk1C;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    M2C_FIELD(temp_r3_2085, f64 *, 0x10) = (f64) (M2C_FIELD(temp_r3_2085, f64 *, 0x10) + sp28);
    temp_r3_2085->unk18 += (f32) sp30;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_1039'
s32 EarthBossDescriptor::LoadLine(MKIniLine *arg0) {
    s8 sp36;
    s8 sp2C;
    M2C_UNK sp28;
    s8 spC;
    s8 *sp8;
    MKIniLine *var_r29_2156;
    s32 temp_r5_2219;
    s32 temp_ret_2176;
    s32 temp_ret_2216;

    M2C_STRUCT_COPY((s32) &sp28 + 4, (s32) (&lit_1039 - 4) + 4, 0x20);
    M2C_STRUCT_COPY((s32) &sp8 + 4, (s32) (&lit_1040 - 4) + 4, 0x20);
    if (EnemyDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("HurtPhrases") != 0) {
        var_r29_2156 = arg0->unkC->GetSubLine(arg0);
loop_11:
        if (var_r29_2156 != NULL) {
            strcpy(&sp2C, var_r29_2156->GetFieldName());
            if (strnicmp("hurtPhrase", &sp2C, 0xA) == 0) {
                strcpy(&spC, &sp36);
                temp_ret_2176 = atoi(&spC);
                if (temp_ret_2176 <= 2) {
                    var_r29_2156->LoadString(Str_Printf("hurtPhrase%s", &spC, M2C_BITWISE(f32, temp_ret_2176)), &sp8, 0);
                    strcpy(this + (((atoi(&spC) - 1) * 0x24) + 0x2B4), sp8);
                }
            } else if (strnicmp("Percentage", &sp2C, 0xA) == 0) {
                strcpy(&spC, &sp36);
                if (atoi(&spC) <= 2) {
                    temp_ret_2216 = atoi(&spC);
                    temp_r5_2219 = (temp_ret_2216 - 1) * 0x24;
                    var_r29_2156->LoadFloat(Str_Printf("percentage%s", &spC, temp_r5_2219, M2C_BITWISE(f32, temp_ret_2216)), this + (temp_r5_2219 + 0x2D4), 0);
                }
            }
            var_r29_2156 = var_r29_2156->unkC->GetNextLine(var_r29_2156);
            goto loop_11;
        }
        return 1;
    }
    return arg0->LoadFloat("phraseDelay", &this->unk2FC, 0);
}
#endif

#if 0 // DRAFT: function call 'strcpy(unsigned char *, const char[1])' does not match
void EarthBossDescriptor::Init() {
    s32 var_r28_2276;
    s32 var_r30_2270;
    void *temp_r29_2281;

    EnemyDescriptor::Init();
    var_r30_2270 = 0;
    this->unk7C.unk18 |= 0x04000000;
    var_r28_2276 = 0;
    this->unk123 = 0;
    this->unk1D4 = 0;
    this->unk2FC = 1.0f;
    do {
        temp_r29_2281 = this + var_r30_2270;
        strcpy(((u8 *) temp_r29_2281) + 0x2B4, "");
        var_r28_2276 += 1;
        M2C_FIELD(temp_r29_2281, f32 *, 0x2D4) = 0.0f;
        var_r30_2270 += 0x24;
    } while (var_r28_2276 < 2);
}
#endif

f32 EarthBossArm::GetCollisionHeight() {
    return 400.0f;
}

f32 EarthBossArm::GetCollisionRadius() {
    return 200.0f;
}

void *EarthBossArm::GetCollisionInfo() {
    return M2C_FIELD(this->unk370, void **, 0xBA0);
}

s32 EarthBossArm::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    if (arg1 != NULL) {
        MKModel_CalculateNodeWorldPosition(this->unk4, this->unk344, arg1);
        return 1;
    }
    return 0;
}

s32 EarthBossArm::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    if (arg1 != NULL) {
        MKModel_CalculateNodeWorldPosition(this->unk4, this->unk344, arg1);
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: function call 'Message(Enemy *)' does not match
void EarthBossArm::Message(MKMessage *arg0) {
    f64 sp10;
    f64 sp8;
    Enemy *temp_r3_2398;
    Enemy *temp_r3_2405;
    s32 temp_r0_2375;
    void *temp_r31_2415;
    void *temp_r4_2414;

    temp_r0_2375 = arg0->unk0;
    switch (temp_r0_2375) {                         /* irregular */
    case 0x5:
    case 0x1:
        if ((u8) M2C_FIELD(&gb, u8 *, 0x381) == 0) {
            temp_r3_2398 = this->unk370;
            temp_r3_2398->Message();
            return;
        }
        return;
    case 0x88:
    case 0x4:
        temp_r3_2405 = this->unk370;
        temp_r3_2405->Message();
        return;
    case 0x77:
        temp_r4_2414 = this->unk8;
        temp_r31_2415 = checked_cast<GetHitFxPosMsg *, MKMessage>(arg0);
        sp8 = M2C_FIELD(temp_r4_2414, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r4_2414, f64 *, 0x38);
        MKModel_CalculateNodeWorldPosition(this->unk4, this->unk344, (MKVector3 *) &sp8);
        M2C_FIELD(temp_r31_2415, f64 *, 8) = sp8;
        M2C_FIELD(temp_r31_2415, f64 *, 0x10) = sp10;
        M2C_FIELD(temp_r31_2415, s8 *, 0x18) = 1;
        return;
    default:
        MKProp::Message(arg0);
        break;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4C'
void EarthBossArm::Disable() {
    Enemy *temp_r31_2456;

    this->unk18 = this->unk18 | 0x80000000;
    this->unk4C.UnregisterTargetable();
    temp_r31_2456 = this->unk370;
    M2C_FIELD(GetCollisionInfo(), Enemy **, 8) = temp_r31_2456;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4C'
void EarthBossArm::Enable() {
    this->unk18 = this->unk18 & 0x7FFFFFFF;
    this->unk4C.RegisterTargetable();
    M2C_FIELD(GetCollisionInfo(), EarthBossArm **, 8) = this;
}
#endif

void EarthBossArm::Reset() {
    MKProp::Reset();
    Disable();
    SetRetracted();
}

void EarthBossArm::Draw() {
    f64 sp10;
    f64 sp8;
    f64 *temp_r3_2533;

    MKProp::Draw();
    if (this->unk3A0.Draw(NULL) == 0) {
        temp_r3_2533 = MKModel_GetColor(this->unk4);
        sp8 = M2C_FIELD(temp_r3_2533, f64 *, 0);
        sp10 = M2C_FIELD(temp_r3_2533, f64 *, 8);
        if (this->unk450 > 0.0f) {
            MKModel_SetColor(this->unk4, *((MKVector4 *) &this->unk458));
        }
        MKModel_Draw(this->unk4, NULL);
        if (this->unk450 > 0.0f) {
            MKModel_SetColor(this->unk4, *((MKVector4 *) &sp8));
        }
        if (this->unk450 > 0.0f) {
            gRenderState = this->unk468;
            MKProp::Draw();
            gRenderState = NULL;
        }
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'Matrix' to
s32 EarthBossArm::CheckMeleeHit(EnemyAttack *arg0) {
    u8 sp180;
    s32 sp17C;
    void *sp178;
    s32 sp174;
    f32 sp170;
    s32 sp16C;
    s8 sp16B;
    s8 sp16A;
    s16 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    Matrix spF0;
    M2C_UNK *spE4;
    s32 spE0;
    s8 spDC;
    s32 spD8;
    s32 spD4;
    s8 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    s32 spBC;
    s32 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    Enemy *temp_r3_2806;
    Enemy *temp_r4_2861;
    MKProp *var_r0_2687;
    MKProp *var_r31_2701;
    f32 var_f4_2716;
    f32 var_f5_2729;
    f64 temp_f0_2600;
    f64 temp_f0_2612;
    f64 temp_f0_2710;
    f64 temp_f1_2734;
    f64 temp_f1_2740;
    f64 temp_f1_2744;
    f64 temp_f2_2610;
    s32 temp_r3_2763;
    s32 var_r0_2773;
    u32 *temp_r3_2863;
    u32 *var_r4_2807;
    u32 temp_r0_2816;

    MKModel_CalculateNodeWorldMatrix(this->unk4, this->unk344, &spF0);
    temp_f0_2600 = M2C_BITWISE(f64, spF0) * 5.5769738e-315;
    sp58 = temp_f0_2600;
    sp78 = temp_f0_2600;
    sp60 = spF0.unk8 * 200.0f;
    sp80 = (f64) sp60;
    temp_f2_2610 = spF0.unk30;
    temp_f0_2612 = temp_f2_2610 + temp_f0_2600;
    sp48 = temp_f0_2612;
    spA8 = temp_f0_2612;
    sp50 = spF0.unk38 + (f32) sp80;
    spB0 = (f64) sp50;
    sp38 = M2C_BITWISE(f64, spF0) * 5.626513803e-315;
    sp40 = spF0.unk8 * 450.0f;
    sp68 = sp38;
    sp70 = (f64) sp40;
    sp28 = temp_f2_2610 + sp68;
    sp98 = sp28;
    sp30 = spF0.unk38 + (f32) sp70;
    sp130 = 0.0f;
    spA0 = (f64) sp30;
    sp134 = 0.0f;
    sp138 = 0.0f;
    sp140 = 0.0f;
    sp144 = 0.0f;
    sp148 = 0.0f;
    sp150 = 0.0f;
    sp154 = 0.0f;
    sp158 = 0.0f;
    sp15C = 1.0f;
    sp160 = 0.0f;
    sp164 = 0.0f;
    sp168 = 0;
    sp16A = 0;
    sp16B = 0;
    sp16C = 0;
    sp170 = 3.4028235e38f;
    sp174 = 0;
    sp178 = NULL;
    sp17C = -1;
    sp180 = 0;
    if (MKCollision_SweepSphereCollide(*((MKVector3 *) &spA8), *((MKVector3 *) &sp98), 200.0f, (MKCollisionResult *) &sp130, (MKCollisionMode) 2, (M2C_FIELD(this->unk370->unk110.unk460, s32 *, 0x18) & 0xFBFFFFFF) | 0x08000000) != 0) {
        if ((sp180 != 0) && (sp178 != NULL) && (var_r0_2687 = M2C_FIELD(sp178, MKProp **, 8), ((var_r0_2687 == NULL) == 0))) {

        } else {
            var_r0_2687 = NULL;
        }
        if (var_r0_2687 != NULL) {
            if ((sp180 != 0) && (sp178 != NULL) && (var_r31_2701 = M2C_FIELD(sp178, MKProp **, 8), ((var_r31_2701 == NULL) == 0))) {

            } else {
                var_r31_2701 = NULL;
            }
            temp_f0_2710 = (f64) sp130 - sp98;
            sp18 = temp_f0_2710;
            var_f4_2716 = 0.0f;
            sp88 = temp_f0_2710;
            sp20 = sp138 - (f32) spA0;
            (*(f32 *) ((u8 *) &sp80 + 0xc)) = 0.0f;
            sp90 = (f64) sp20;
            var_f5_2729 = ((f32) sp90 * (f32) sp90) + (((f32) sp88 * (f32) sp88) + (0.0f * 0.0f));
            if (var_f5_2729 > 0.000001f) {
                if (var_f5_2729 > 0.0f) {
                    temp_f1_2734 = __frsqrte(var_f5_2729);
                    temp_f1_2740 = 0.5 * temp_f1_2734 * -(((f64) var_f5_2729 * (temp_f1_2734 * temp_f1_2734)) - 3.0);
                    temp_f1_2744 = 0.5 * temp_f1_2740 * -(((f64) var_f5_2729 * (temp_f1_2740 * temp_f1_2740)) - 3.0);
                    var_f5_2729 = (f32) ((f64) var_f5_2729 * (0.5 * temp_f1_2744 * -(((f64) var_f5_2729 * (temp_f1_2744 * temp_f1_2744)) - 3.0)));
                } else if (var_f5_2729 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_2729 = __float_nan;
                } else {
                    sp10 = var_f5_2729;
                    temp_r3_2763 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_2763) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_2773 = 1;
                        } else {
                            var_r0_2773 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_2773 = 5;
                        } else {
                            var_r0_2773 = 3;
                        }
                        break;
                    default:
                        var_r0_2773 = 4;
                        break;
                    }
                    if (var_r0_2773 == 1) {
                        var_f5_2729 = __float_nan;
                    }
                }
                var_f4_2716 = 1.0f / var_f5_2729;
            }
            sp88 = (f32) sp88 * var_f4_2716;
            (*(f32 *) ((u8 *) &sp80 + 0xc)) *= var_f4_2716;
            sp90 = (f32) sp90 * var_f4_2716;
            temp_r3_2806 = this->unk370;
            var_r4_2807 = temp_r3_2806->unkA1C;
loop_35:
            temp_r0_2816 = *var_r4_2807;
            if (temp_r0_2816 == 0) {
                var_r4_2807 = NULL;
            } else if (temp_r0_2816 == var_r31_2701) {

            } else {
                var_r4_2807 += 4;
                goto loop_35;
            }
            if (var_r4_2807 == NULL) {
                if (temp_r3_2806->MeleeDamageTarget(var_r31_2701, arg0, *((MKVector3 *) &sp88), -1) != 0) {
                    return 1;
                }
                spE4 = &__vt;
                spB8 = 0x30;
                spBC = 0;
                spE4 = &__vt;
                spC0 = 0.0f;
                spC4 = 0.0f;
                spC8 = 0.0f;
                spD0 = 0;
                spD4 = -1;
                spD8 = 0;
                spDC = 0;
                spE0 = 0;
                spB8 = 0x31;
                var_r31_2701->Message(&spB8, -1, &__vt, 0);
                temp_r4_2861 = this->unk370;
                temp_r3_2863 = temp_r4_2861->unkA1C - 4;
                temp_r4_2861->unkA1C = temp_r3_2863;
                *temp_r3_2863 = (u32) var_r31_2701;
                goto block_41;
            }
            goto block_41;
        }
        goto block_41;
    }
block_41:
    sp130 = 0.0f;
    sp134 = 0.0f;
    sp138 = 0.0f;
    sp140 = 0.0f;
    sp144 = 0.0f;
    sp148 = 0.0f;
    sp150 = 0.0f;
    sp154 = 0.0f;
    sp158 = 0.0f;
    sp15C = 1.0f;
    sp160 = 0.0f;
    sp164 = 0.0f;
    sp168 = 0;
    sp16A = 0;
    sp16B = 0;
    sp16C = 0;
    sp170 = 3.4028235e38f;
    sp174 = 0;
    sp178 = NULL;
    sp17C = -1;
    sp180 = 0;
    if (((u8) this->unk390 == 0) && (MKCollision_SweepSphereCollide(*((MKVector3 *) &spA8), *((MKVector3 *) &sp98), 200.0f, (MKCollisionResult *) &sp130, (MKCollisionMode) 4, 0) != 0)) {
        this->unk390 = 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30'
void EarthBossArm::Extend() {
    Matrix spA0;
    f64 sp90;
    Animation sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    Animation *temp_r4_2936;
    f32 temp_f1_2973;
    f32 temp_f2_2976;
    f32 temp_f5_2978;
    f32 var_f4_2983;
    f64 temp_f1_2986;
    f64 temp_f1_2992;
    f64 temp_f1_2996;
    s32 temp_r0_3065;
    s32 temp_r30_2939;
    s32 temp_r3_3015;
    s32 var_ctr_3057;
    s32 var_r0_3025;
    s32 var_r3_3053;
    s32 var_r7_3049;
    void *temp_r6_3060;
    void *var_r3_2957;

    temp_r4_2936 = MKModel_GetAnimation(this->unk4);
    this->unk390 = 0;
    temp_r30_2939 = this->unk144;
    sp58.GetNodeOrigin((s32) temp_r4_2936);
    sp58.unk30 = M2C_BITWISE(f64, sp58);
    sp90 = sp58.unk8;
    MKModel_CalculateNodeWorldMatrix(this->unk4, temp_r30_2939, &spA0);
    if ((s32) this->unk364 > 0) {
        var_r3_2957 = this->unk36C + (this->unk368 * 0x10);
    } else {
        var_r3_2957 = NULL;
    }
    sp28 = M2C_FIELD(var_r3_2957, f64 *, 0) - spA0.unk30;
    sp58.unk20 = sp28;
    sp30 = M2C_FIELD(var_r3_2957, f32 *, 8) - spA0.unk38;
    temp_f1_2973 = M2C_BITWISE(f32, sp58.unk24);
    temp_f2_2976 = M2C_BITWISE(f32, sp58.unk20);
    sp58.unk28 = (f64) sp30;
    temp_f5_2978 = M2C_BITWISE(f32, sp58.unk28);
    sp48 = sp28;
    sp50 = (f64) sp30;
    var_f4_2983 = (temp_f5_2978 * temp_f5_2978) + ((temp_f2_2976 * temp_f2_2976) + (temp_f1_2973 * temp_f1_2973));
    if (var_f4_2983 > 0.0f) {
        temp_f1_2986 = __frsqrte(var_f4_2983);
        temp_f1_2992 = 0.5 * temp_f1_2986 * -(((f64) var_f4_2983 * (temp_f1_2986 * temp_f1_2986)) - 3.0);
        temp_f1_2996 = 0.5 * temp_f1_2992 * -(((f64) var_f4_2983 * (temp_f1_2992 * temp_f1_2992)) - 3.0);
        var_f4_2983 = (f32) ((f64) var_f4_2983 * (0.5 * temp_f1_2996 * -(((f64) var_f4_2983 * (temp_f1_2996 * temp_f1_2996)) - 3.0)));
    } else if (var_f4_2983 < M2C_BITWISE(f32, 0.0)) {
        var_f4_2983 = __float_nan;
    } else {
        sp10 = var_f4_2983;
        temp_r3_3015 = M2C_BITWISE(s32, sp10) & 0x7F800000;
        switch (temp_r3_3015) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_3025 = 1;
            } else {
                var_r0_3025 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_3025 = 5;
            } else {
                var_r0_3025 = 3;
            }
            break;
        default:
            var_r0_3025 = 4;
            break;
        }
        if (var_r0_3025 == 1) {
            var_f4_2983 = __float_nan;
        }
    }
    var_r7_3049 = 2;
    var_r3_3053 = 0x100;
    var_ctr_3057 = 4;
    do {
        temp_r6_3060 = this + var_r3_3053;
        sp18 = sp58.unk30 - M2C_FIELD(temp_r6_3060, f64 *, 0x70);
        temp_r0_3065 = var_r7_3049 - 1;
        var_r7_3049 += 1;
        var_r3_3053 += 0x80;
        sp58.unk10 = sp18;
        sp20 = (f32) sp90 - M2C_FIELD(temp_r6_3060, f32 *, 0x78);
        sp38 = sp18;
        M2C_FIELD(temp_r6_3060, f32 *, 0xCC) = (f32) (((var_f4_2983 - 400.0f) * 0.25f * (f32) temp_r0_3065) + M2C_BITWISE(f32, sp58.unk10));
        sp40 = (f64) sp20;
        M2C_FIELD(temp_r6_3060, f32 *, 0xD0) = (f32) M2C_FIELD(temp_r6_3060, f32 *, 0xC8);
        M2C_FIELD(temp_r6_3060, f32 *, 0xD4) = 0.0f;
        sp58.unk18 = (f64) sp20;
        M2C_FIELD(temp_r6_3060, s8 *, 0xD8) = 0;
        var_ctr_3057 -= 1;
    } while (var_ctr_3057 != 0);
    this->unk38C = 4;
}
#endif

#if 0 // DRAFT: function call 'Normalise(MKVector3)' does not match
void EarthBossArm::Aim(const MKVector3 &arg0) {
    Matrix spE0;
    Matrix spA0;
    Matrix sp60;
    M2C_UNK sp5C;
    f64 sp58;
    f64 sp50;
    MKVector3 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    Enemy *temp_r4_3136;
    Enemy *temp_r4_3141;
    f32 temp_f2_3183;
    f32 temp_f4_3181;
    f32 temp_f6_3170;
    f64 temp_f0_3150;

    this->unk38C = 3;
    this->unk378 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk380 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk368 = 0;
    this->unk364 = 0;
    M2C_STRUCT_COPY((s32) &sp5C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    sp60.Inverse(&sp60);
    temp_r4_3136 = this->unk370;
    MKModel_CalculateNodeWorldMatrix(temp_r4_3136->unk4, M2C_FIELD(temp_r4_3136, s32 *, 0xCD0), &spE0);
    temp_r4_3141 = this->unk370;
    MKModel_CalculateNodeWorldMatrix(temp_r4_3141->unk4, M2C_FIELD(temp_r4_3141, s32 *, 0xCD4), &spA0);
    temp_f0_3150 = spA0.unk30 - spE0.unk30;
    sp10 = temp_f0_3150;
    sp30 = temp_f0_3150;
    sp18 = spA0.unk38 - spE0.unk38;
    sp38 = (f64) sp18;
    Normalise(sp40);
    temp_f6_3170 = M2C_BITWISE(f32, sp40);
    temp_f4_3181 = (sp40.unk8 * sp60.unk20) + ((temp_f6_3170 * M2C_BITWISE(f32, sp60)) + (sp40.unk4 * sp60.unk10));
    temp_f2_3183 = (sp40.unk8 * sp60.unk24) + ((temp_f6_3170 * sp60.unk4) + (sp40.unk4 * sp60.unk14));
    sp20 = temp_f4_3181;
    sp24 = temp_f2_3183;
    sp28 = (sp40.unk8 * sp60.unk28) + ((temp_f6_3170 * sp60.unk8) + (sp40.unk4 * sp60.unk18));
    this->unkE0 = (f64) sp20;
    this->unkE8 = (f64) sp28;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    Enable((f64) sp20, temp_f2_3183, sp60.unk24, temp_f4_3181, sp60.unk20, temp_f6_3170, sp40.unk8);
    ((EarthBoss *) this->unk370)->ShowFist(0U);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'Animation' to
void EarthBossArm::Retract() {
    Animation sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Animation *temp_r3_3218;
    s32 var_ctr_3234;
    s32 var_r3_3229;
    void *temp_r5_3239;

    temp_r3_3218 = MKModel_GetAnimation(this->unk4);
    if ((s32) this->unk38C != 1) {
        sp28.GetNodeOrigin((s32) temp_r3_3218);
        var_r3_3229 = 0x100;
        sp28.unk28 = sp28.unk8;
        sp28.unk20 = M2C_BITWISE(f64, sp28);
        var_ctr_3234 = 4;
        do {
            temp_r5_3239 = this + var_r3_3229;
            sp8 = M2C_BITWISE(f64, sp28.unk20) - M2C_FIELD(temp_r5_3239, f64 *, 0x70);
            var_r3_3229 += 0x80;
            sp28.unk10 = sp8;
            M2C_FIELD(temp_r5_3239, f32 *, 0xD0) = (f32) M2C_FIELD(temp_r5_3239, f32 *, 0xC8);
            sp10 = M2C_BITWISE(f32, sp28.unk28) - M2C_FIELD(temp_r5_3239, f32 *, 0x78);
            M2C_FIELD(temp_r5_3239, f32 *, 0xCC) = M2C_BITWISE(f32, sp28.unk10);
            M2C_FIELD(temp_r5_3239, f32 *, 0xD4) = 0.0f;
            sp18 = sp8;
            sp20 = (f64) sp10;
            sp28.unk18 = (f64) sp10;
            M2C_FIELD(temp_r5_3239, s8 *, 0xD8) = 0;
            var_ctr_3234 -= 1;
        } while (var_ctr_3234 != 0);
        this->unk38C = 1;
        this->unk390 = 0;
        KDSound_Play3d(GS_SSAlert, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void EarthBossArm::SetRetracted() {
    Matrix spD0;
    M2C_UNK spCC;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
    MKVector3 sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    Animation *temp_r28_3296;
    Enemy *temp_r4_3311;
    Enemy *temp_r4_3316;
    f32 temp_f6_3344;
    f64 temp_f0_3323;
    s32 var_r27_3337;
    s32 var_r30_3339;
    void *temp_r29_3370;

    temp_r28_3296 = MKModel_GetAnimation(this->unk4);
    M2C_STRUCT_COPY((s32) &spCC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    spD0.Inverse(&spD0);
    temp_r4_3311 = this->unk370;
    MKModel_CalculateNodeWorldPosition(temp_r4_3311->unk4, M2C_FIELD(temp_r4_3311, s32 *, 0xCD0), &sp90);
    temp_r4_3316 = this->unk370;
    MKModel_CalculateNodeWorldPosition(temp_r4_3316->unk4, M2C_FIELD(temp_r4_3316, s32 *, 0xCD4), &spA0);
    temp_f0_3323 = M2C_BITWISE(f64, spA0) - M2C_BITWISE(f64, sp90);
    sp10 = temp_f0_3323;
    sp60 = temp_f0_3323;
    sp18 = spA0.unk8 - sp90.unk8;
    sp68 = (f64) sp18;
    Normalise(sp70);
    var_r27_3337 = 2;
    var_r30_3339 = 0x100;
    temp_f6_3344 = M2C_BITWISE(f32, sp70);
    sp30 = (sp70.unk8 * spD0.unk20) + ((temp_f6_3344 * M2C_BITWISE(f32, spD0)) + (sp70.unk4 * spD0.unk10));
    sp34 = (sp70.unk8 * spD0.unk24) + ((temp_f6_3344 * spD0.unk4) + (sp70.unk4 * spD0.unk14));
    sp38 = (sp70.unk8 * spD0.unk28) + ((temp_f6_3344 * spD0.unk8) + (sp70.unk4 * spD0.unk18));
    this->unkE0 = (f64) sp30;
    sp80 = (f64) sp30;
    sp88 = (f64) sp38;
    this->unkE8 = (f64) sp38;
    do {
        temp_r29_3370 = this + var_r30_3339;
        temp_r28_3296->GetNodeParentIndex(M2C_FIELD(temp_r29_3370, s32 *, 0xC4));
        ((Animation *) &sp50)->GetNodeOrigin((s32) temp_r28_3296);
        spC0 = sp50;
        spC8 = sp58;
        sp20 = sp50 - M2C_FIELD(temp_r29_3370, f64 *, 0x70);
        var_r27_3337 += 1;
        var_r30_3339 += 0x80;
        spB0 = sp20;
        sp40 = sp20;
        M2C_FIELD(temp_r29_3370, f32 *, 0xC8) = (f32) spB0;
        sp28 = (f32) spC8 - M2C_FIELD(temp_r29_3370, f32 *, 0x78);
        M2C_FIELD(temp_r29_3370, f32 *, 0xCC) = (f32) spB0;
        M2C_FIELD(temp_r29_3370, f32 *, 0xD4) = 0.0f;
        sp48 = (f64) sp28;
        spB8 = (f64) sp28;
        M2C_FIELD(temp_r29_3370, s8 *, 0xD8) = 1;
    } while (var_r27_3337 <= 5);
    this->unk38C = 0;
    this->unk390 = 0;
    Disable();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void EarthBossArm::UpdateExtensionBone(MKDynamicBone *arg0, void *arg1) {
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Animation *temp_r3_3437;

    temp_r3_3437 = MKModel_GetAnimation(M2C_BITWISE(MKModel *, this->unk24));
    sp18 = 0.0f;
    sp10 = arg0->unk68;
    sp14 = 0.0f;
    sp28 = (f64) sp18;
    sp20 = (f64) sp10;
    M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp30.unk30 = (f32) sp20;
    sp30.unk34 = (*(f32 *) ((u8 *) &sp20 + 0x4));
    sp30.unk38 = (f32) sp28;
    sp30.unk3C = 1.0f;
    temp_r3_3437->SetCustomMatrix(arg0->unk64, &sp30, (AnimationMatrixPosition) 4, 0U);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void EarthBossArm::UpdateElbowBone(MKDynamicBone *arg0, void *arg1) {
    Matrix sp250;
    Matrix sp210;
    Matrix sp1D0;
    Matrix sp190;
    Matrix sp150;
    M2C_UNK sp14C;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
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
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    s16 sp10;
    Animation *temp_r3_3529;
    f32 temp_f3_3540;
    f32 temp_f6_3549;
    f32 temp_f7_3555;
    f32 var_f2_3710;
    f32 var_f4_3643;
    f64 temp_f1_3649;
    f64 temp_f1_3655;
    f64 temp_f1_3659;
    s32 temp_r29_3519;
    s32 temp_r29_3527;
    s32 temp_r29_3826;
    s32 temp_r3_3678;
    s32 var_r0_3688;

    M2C_STRUCT_COPY((s32) &sp190.unk3C + 4, MKModel_GetWorldMatrix(M2C_BITWISE(MKModel *, this->unk24)) - 4 + 4, 0x40);
    M2C_STRUCT_COPY((s32) &sp150.unk3C + 4, (s32) &sp190.unk3C + 4, 0x40);
    sp190.Inverse(&sp190);
    temp_r29_3519 = arg0->unk64;
    ((Animation *) (MKModel_GetAnimation(M2C_BITWISE(MKModel *, this->unk24))))->SetCustomMatrix(temp_r29_3519, NULL, (AnimationMatrixPosition) 2, 0U);
    temp_r29_3527 = arg0->unk64;
    temp_r3_3529 = MKModel_GetAnimation(M2C_BITWISE(MKModel *, this->unk24));
    sp10 = (s16) temp_r29_3527;
    temp_r3_3529->CalculateMatrices(&sp210, 1, &sp10, NULL);
    sp250.Multiply(&sp210, &sp1D0);
    temp_f3_3540 = arg0->unk14;
    temp_f6_3549 = arg0->unk10;
    temp_f7_3555 = arg0->unk18;
    sp98 = (temp_f7_3555 * sp250.unk20) + ((temp_f6_3549 * M2C_BITWISE(f32, sp250)) + (temp_f3_3540 * sp250.unk10));
    sp9C = (temp_f7_3555 * sp250.unk24) + ((temp_f6_3549 * sp250.unk4) + (temp_f3_3540 * sp250.unk14));
    spA0 = (temp_f7_3555 * sp250.unk28) + ((temp_f6_3549 * sp250.unk8) + (temp_f3_3540 * sp250.unk18));
    sp138 = (f64) sp98;
    sp140 = (f64) spA0;
    sp250.Translate(&sp250, *((MKVector3 *) &sp138));
    sp88 = (sp250.unk18 * sp190.unk20) + ((sp250.unk10 * M2C_BITWISE(f32, sp190)) + (sp250.unk14 * sp190.unk10));
    sp8C = (sp250.unk18 * sp190.unk24) + ((sp250.unk10 * sp190.unk4) + (sp250.unk14 * sp190.unk14));
    sp90 = (sp250.unk18 * sp190.unk28) + ((sp250.unk10 * sp190.unk8) + (sp250.unk14 * sp190.unk18));
    sp118 = (f64) sp88;
    sp120 = (f64) sp90;
    sp128 = M2C_FIELD(arg0, f64 *, 0);
    sp130 = M2C_FIELD(arg0, f64 *, 8);
    sp78 = -(f32) sp118;
    sp7C = -(*(f32 *) ((u8 *) &sp118 + 0x4));
    sp80 = -(f32) sp120;
    spE8 = (f64) sp78;
    spF0 = (f64) sp80;
    sp6C = ((f32) spF0 * (f32) sp128) - ((f32) spE8 * (f32) sp130);
    sp68 = ((*(f32 *) ((u8 *) &spE8 + 0x4)) * (f32) sp130) - ((f32) spF0 * (*(f32 *) ((u8 *) &sp128 + 0x4)));
    sp70 = ((f32) spE8 * (*(f32 *) ((u8 *) &sp128 + 0x4))) - ((*(f32 *) ((u8 *) &spE8 + 0x4)) * (f32) sp128);
    spF8 = (f64) sp68;
    sp100 = (f64) sp70;
    var_f4_3643 = ((f32) sp100 * (f32) sp100) + (((f32) spF8 * (f32) spF8) + ((*(f32 *) ((u8 *) &spF8 + 0x4)) * (*(f32 *) ((u8 *) &spF8 + 0x4))));
    if (var_f4_3643 > 1e-12f) {
        if (var_f4_3643 > 0.0f) {
            temp_f1_3649 = __frsqrte(var_f4_3643);
            temp_f1_3655 = 0.5 * temp_f1_3649 * -(((f64) var_f4_3643 * (temp_f1_3649 * temp_f1_3649)) - 3.0);
            temp_f1_3659 = 0.5 * temp_f1_3655 * -(((f64) var_f4_3643 * (temp_f1_3655 * temp_f1_3655)) - 3.0);
            var_f4_3643 = (f32) ((f64) var_f4_3643 * (0.5 * temp_f1_3659 * -(((f64) var_f4_3643 * (temp_f1_3659 * temp_f1_3659)) - 3.0)));
        } else if (var_f4_3643 < M2C_BITWISE(f32, 0.0)) {
            var_f4_3643 = __float_nan;
        } else {
            sp14 = var_f4_3643;
            temp_r3_3678 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_3678) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_3688 = 1;
                } else {
                    var_r0_3688 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_3688 = 5;
                } else {
                    var_r0_3688 = 3;
                }
                break;
            default:
                var_r0_3688 = 4;
                break;
            }
            if (var_r0_3688 == 1) {
                var_f4_3643 = __float_nan;
            }
        }
        var_f2_3710 = 1.0f / var_f4_3643;
    } else {
        var_f2_3710 = 0.0f;
    }
    sp60 = (f32) sp100 * var_f2_3710;
    sp58 = (f32) spF8 * var_f2_3710;
    sp5C = (*(f32 *) ((u8 *) &spF8 + 0x4)) * var_f2_3710;
    sp110 = (f64) sp60;
    sp108 = (f64) sp58;
    sp20 = -(f32) sp130;
    sp30 = -(f32) sp110;
    spD0 = (f64) sp20;
    spC0 = (f64) sp30;
    sp28 = -(f32) sp108;
    sp2C = -(*(f32 *) ((u8 *) &sp108 + 0x4));
    sp18 = -(f32) sp128;
    spB8 = (f64) sp28;
    sp1C = -(*(f32 *) ((u8 *) &sp128 + 0x4));
    spC8 = (f64) sp18;
    sp210 = (f32) sp128;
    sp210.unk4 = (*(f32 *) ((u8 *) &sp128 + 0x4));
    sp210.unk8 = (f32) sp130;
    sp50 = ((f32) spB8 * (*(f32 *) ((u8 *) &spC8 + 0x4))) - ((*(f32 *) ((u8 *) &spB8 + 0x4)) * (f32) spC8);
    sp48 = ((*(f32 *) ((u8 *) &spB8 + 0x4)) * (f32) spD0) - ((f32) spC0 * (*(f32 *) ((u8 *) &spC8 + 0x4)));
    sp4C = ((f32) spC0 * (f32) spC8) - ((f32) spB8 * (f32) spD0);
    sp120 = (f64) sp50;
    sp118 = (f64) sp48;
    spD8 = (f64) sp48;
    spE0 = (f64) sp50;
    sp210.unkC = 0.0f;
    sp210.unk10 = (f32) sp118;
    sp210.unk14 = (*(f32 *) ((u8 *) &sp118 + 0x4));
    sp210.unk18 = (f32) sp120;
    sp210.unk1C = 0.0f;
    sp210.unk20 = (f32) sp108;
    sp210.unk24 = (*(f32 *) ((u8 *) &sp108 + 0x4));
    sp210.unk28 = (f32) sp110;
    sp210.unk2C = 0.0f;
    M2C_STRUCT_COPY((s32) &sp14C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp38 = -arg0->unk10;
    sp3C = -arg0->unk14;
    sp40 = -arg0->unk18;
    spA8 = (f64) sp38;
    spB0 = (f64) sp40;
    sp150.Translate(&sp150, *((MKVector3 *) &spA8));
    sp210.Multiply(&sp150, &sp210);
    sp210.Translate(&sp210, *((MKVector3 *) &arg0->unk10));
    temp_r29_3826 = arg0->unk64;
    ((Animation *) (MKModel_GetAnimation(M2C_BITWISE(MKModel *, this->unk24))))->SetCustomMatrix(temp_r29_3826, &sp210, (AnimationMatrixPosition) 4, 0U);
}
#endif

void EarthBossArm::UpdateShoulderBone(MKDynamicBone *arg0, void *arg1) {

}

#if 0 // DRAFT: undefined identifier 'fabs'
void EarthBossArm::UpdateRetraction() {
    f32 temp_f0_3865;
    f32 temp_f3_3874;
    f32 var_f3_3864;
    s32 var_ctr_3855;
    s32 var_r4_3854;
    void *temp_r5_3857;

    var_r4_3854 = 0x100;
    var_ctr_3855 = 4;
    do {
        temp_r5_3857 = this + var_r4_3854;
        if ((u8) M2C_FIELD(temp_r5_3857, u8 *, 0xD8) == 0) {
            var_f3_3864 = 1.0f;
            temp_f0_3865 = (gUpdateTimeDelta * 1.0f) + M2C_FIELD(temp_r5_3857, f32 *, 0xD4);
            if (var_f3_3864 < temp_f0_3865) {

            } else {
                var_f3_3864 = temp_f0_3865;
            }
            M2C_FIELD(temp_r5_3857, f32 *, 0xD4) = var_f3_3864;
            temp_f3_3874 = M2C_FIELD(temp_r5_3857, f32 *, 0xD0);
            M2C_FIELD(temp_r5_3857, f32 *, 0xC8) = (f32) ((M2C_FIELD(temp_r5_3857, f32 *, 0xD4) * (M2C_FIELD(temp_r5_3857, f32 *, 0xCC) - temp_f3_3874)) + temp_f3_3874);
            if ((M2C_FIELD(temp_r5_3857, f32 *, 0xD4) >= 1.0f) || ((f32) fabs(M2C_FIELD(temp_r5_3857, f32 *, 0xCC) - M2C_FIELD(temp_r5_3857, f32 *, 0xC8)) < 0.01f)) {
                if ((s32) this->unk38C == 1) {
                    this->unk38C = 2;
                }
                M2C_FIELD(temp_r5_3857, u8 *, 0xD8) = 1U;
            }
        }
        var_r4_3854 += 0x80;
        var_ctr_3855 -= 1;
    } while (var_ctr_3855 != 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'fabs'
void EarthBossArm::UpdateExtension() {
    MKVector3 spC0;
    M2C_UNK sp90;
    s8 sp88;
    f64 sp80;
    f64 sp78;
    s32 sp74;
    s32 sp70;
    f64 sp68;
    f64 sp60;
    MKVector3 sp50;
    M2C_UNK sp40;
    f64 sp38;
    f64 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f0_3934;
    f32 temp_f31_3987;
    f32 temp_f3_3943;
    f32 var_f3_3933;
    s32 var_r27_3924;
    s32 var_r29_3923;
    void *temp_r3_3926;

    var_r29_3923 = 2;
    var_r27_3924 = 0x100;
    do {
        temp_r3_3926 = this + var_r27_3924;
        if ((u8) M2C_FIELD(temp_r3_3926, u8 *, 0xD8) == 0) {
            var_f3_3933 = 1.0f;
            temp_f0_3934 = (gUpdateTimeDelta * 5.0f) + M2C_FIELD(temp_r3_3926, f32 *, 0xD4);
            if (var_f3_3933 < temp_f0_3934) {

            } else {
                var_f3_3933 = temp_f0_3934;
            }
            M2C_FIELD(temp_r3_3926, f32 *, 0xD4) = var_f3_3933;
            temp_f3_3943 = M2C_FIELD(temp_r3_3926, f32 *, 0xD0);
            M2C_FIELD(temp_r3_3926, f32 *, 0xC8) = (f32) ((M2C_FIELD(temp_r3_3926, f32 *, 0xD4) * (M2C_FIELD(temp_r3_3926, f32 *, 0xCC) - temp_f3_3943)) + temp_f3_3943);
            if ((M2C_FIELD(temp_r3_3926, f32 *, 0xD4) >= 1.0f) || ((f32) fabs(M2C_FIELD(temp_r3_3926, f32 *, 0xCC) - M2C_FIELD(temp_r3_3926, f32 *, 0xC8)) < 0.01f)) {
                M2C_FIELD(temp_r3_3926, u8 *, 0xD8) = 1U;
                if (((s32) this->unk38C == 4) && ((u8) this->unk390 != 0)) {
                    temp_f31_3987 = ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.05f, 0.4f, 0.2f, ((u8 *) this->unk8) + 0x30, 80.0f, 0, 4.0f, 0U);
                    sp74 = 0;
                    MKVector(0.05f, 0.8f, 0.05f);
                    sp50.operator*(500.0f);
                    sp10 = sp50 * (f64) temp_f31_3987;
                    sp70 = 0x417;
                    sp78 = sp10;
                    sp18 = sp50.unk8 * temp_f31_3987;
                    sp88 = 1;
                    sp80 = (f64) sp18;
                    sp60 = sp10;
                    sp68 = (f64) sp18;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp70, sp10);
                    KDSound_Play3d(GS_SSAttack3, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
                    MKModel_CalculateNodeWorldMatrix(this->unk4, this->unk344, (Matrix *) &sp90);
                    sp20 = 0.0f;
                    sp24 = 1.0f;
                    sp28 = 0.0f;
                    sp2C = 1.0f;
                    sp30 = (f64) sp20;
                    sp38 = (f64) sp28;
                    ((EarthShockwave *) (M2C_FIELD(this->unk370, EarthShockwave **, 0xCC4)))->Trigger(spC0, 0.75f, 1U, (MKVector4) &sp30);
                }
                this->unk38C = 5;
            }
        }
        var_r29_3923 += 1;
        var_r27_3924 += 0x80;
    } while (var_r29_3923 <= 5);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'AITargetData' to
void EarthBossArm::UpdateTarget() {
    u8 sp290;
    s32 sp28C;
    void *sp288;
    s32 sp284;
    f32 sp280;
    s32 sp27C;
    s8 sp27B;
    s8 sp27A;
    s16 sp278;
    f32 sp274;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp258;
    f32 sp254;
    f32 sp250;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    f32 sp22C;
    f32 sp228;
    f32 sp224;
    f32 sp220;
    f32 sp20C;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    M2C_UNK sp1FC;
    MKVector3 sp1E8;
    AITargetData sp198;
    f32 sp188;
    f32 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp158;
    MKVector3 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    MKVector3 spE8;
    f64 spE0;
    f64 spD8;
    MKVector3 spC8;
    f64 spC0;
    f64 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    Enemy *temp_r3_4087;
    Enemy *temp_r3_4141;
    Enemy *temp_r4_4133;
    Enemy *temp_r4_4155;
    Enemy *temp_r5_4199;
    f32 temp_f29_4151;
    f32 temp_f2_4167;
    f32 temp_f3_4163;
    f32 temp_f4_4298;
    f32 temp_f5_4161;
    f32 var_f1_4508;
    f32 var_f29_4354;
    f32 var_f8_4421;
    f64 temp_f0_4562;
    f64 temp_f1_4360;
    f64 temp_f1_4366;
    f64 temp_f1_4370;
    f64 temp_f1_4432;
    f64 temp_f1_4561;
    f64 temp_f5_4292;
    s32 temp_r0_4109;
    s32 temp_r0_4583;
    s32 temp_r3_4110;
    s32 temp_r3_4120;
    s32 temp_r3_4389;
    s32 temp_r3_4574;
    s32 temp_r3_4584;
    s32 temp_r4_4596;
    s32 var_r0_4399;
    s32 var_r0_4597;
    s32 var_r28_4434;
    u32 var_r0_4548;
    u8 var_r30_4086;
    void *temp_r3_4559;
    void *temp_r3_4609;

    var_r30_4086 = 0;
    temp_r3_4087 = this->unk370;
    if (((u8) M2C_FIELD(temp_r3_4087, u8 *, 0x8B8) == 2) || (temp_r3_4087->unk870.unk40.Get() != NULL)) {
        var_r30_4086 = 1;
    }
    if (var_r30_4086 != 0) {
        this->unk388 = 6;
loop_9:
        temp_r3_4120 = this->unk364;
        if (temp_r3_4120 >= (s32) this->unk388) {
            if (temp_r3_4120 > 0) {
                this->unk368 += 1;
                temp_r0_4109 = this->unk368;
                temp_r3_4110 = this->unk360;
                if (temp_r0_4109 >= temp_r3_4110) {
                    this->unk368 = temp_r0_4109 - temp_r3_4110;
                }
                this->unk364 -= 1;
            }
            goto loop_9;
        }
        sp198.GetPos();
        this->unk378 = M2C_BITWISE(f64, sp198);
        this->unk380 = (f64) sp198.unk8;
        temp_r4_4133 = this->unk370;
        MKModel_CalculateNodeWorldPosition(temp_r4_4133->unk4, M2C_FIELD(temp_r4_4133, s32 *, 0xCD4), &sp1E8);
        ((AITargetData *) &sp188)->GetDir();
        temp_r3_4141 = this->unk370;
        temp_f29_4151 = (temp_r3_4141->unkC8 * sp190) + ((temp_r3_4141->unkC0 * sp188) + (temp_r3_4141->unkC4 * sp18C));
        if (temp_f29_4151 < _table_sinf(2.6179938f)) {
            temp_r4_4155 = this->unk370;
            temp_f5_4161 = temp_r4_4155->unkC0;
            temp_f3_4163 = temp_r4_4155->unkC8;
            temp_f2_4167 = temp_r4_4155->unkC4;
            spB0 = (MKVector3::up.unk0 * temp_f2_4167) - (MKVector3::up.unk4 * temp_f5_4161);
            spAC = (MKVector3::up.unk8 * temp_f5_4161) - (MKVector3::up.unk0 * temp_f3_4163);
            spA8 = (MKVector3::up.unk4 * temp_f3_4163) - (MKVector3::up.unk8 * temp_f2_4167);
            sp198.unk40.unk8 = (f64) spB0;
            sp198.unk40 = (f64) spA8;
            M2C_STRUCT_COPY((s32) &sp1FC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            sp200 = M2C_BITWISE(f32, sp198.unk40);
            sp204 = M2C_BITWISE(f32, sp198.unk40.unk4);
            sp208 = M2C_BITWISE(f32, sp198.unk40.unk8);
            sp20C = 0.0f;
            temp_r5_4199 = this->unk370;
            sp220 = temp_r5_4199->unkC0;
            sp224 = temp_r5_4199->unkC4;
            sp228 = temp_r5_4199->unkC8;
            sp22C = 0.0f;
            ((AITargetData *) &sp178)->GetDir();
            if (((sp180 * M2C_BITWISE(f32, sp198.unk40.unk8)) + ((sp178 * M2C_BITWISE(f32, sp198.unk40)) + (sp17C * M2C_BITWISE(f32, sp198.unk40.unk4)))) > 0.0f) {
                ((Matrix *) &sp200)->RotateYaw((Matrix *) &sp200, -1.0471976f);
            } else {
                ((Matrix *) &sp200)->RotateYaw((Matrix *) &sp200, 1.0471976f);
            }
            sp148.operator*(this->unk370->unk870.GetDist());
            ((MKProp *) &sp158)->GetPos();
            sp48 = sp158 + M2C_BITWISE(f64, sp148);
            this->unk378 = sp48;
            sp50 = sp160 + sp148.unk8;
            sp80 = 0.0f;
            this->unk380 = (f64) sp50;
            sp78 = 0.0f;
            sp7C = 500.0f;
            sp240 = 0.0f;
            sp244 = 0.0f;
            sp248 = 0.0f;
            sp250 = 0.0f;
            sp254 = 0.0f;
            sp258 = 0.0f;
            sp260 = 0.0f;
            sp264 = 0.0f;
            sp268 = 0.0f;
            sp26C = 1.0f;
            sp270 = 0.0f;
            sp274 = 0.0f;
            sp278 = 0;
            sp27A = 0;
            sp27B = 0;
            sp27C = 0;
            sp280 = 3.4028235e38f;
            sp284 = 0;
            sp288 = NULL;
            sp28C = -1;
            sp290 = 0;
            sp108 = (f64) sp78;
            sp168 = sp48;
            sp170 = (f64) sp50;
            sp110 = (f64) sp80;
            temp_f5_4292 = this->unk378;
            sp68 = temp_f5_4292 - sp108;
            spA0 = 0.0f;
            temp_f4_4298 = (f32) M2C_FIELD(this, f64 *, 0x380);
            sp98 = 0.0f;
            sp9C = 300.0f;
            sp70 = temp_f4_4298 - (f32) sp110;
            sp128 = (f64) sp98;
            sp118 = sp68;
            sp120 = (f64) sp70;
            sp130 = (f64) spA0;
            sp88 = temp_f5_4292 + sp128;
            sp90 = temp_f4_4298 + (f32) sp130;
            sp138 = sp88;
            sp140 = (f64) sp90;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp138), *((MKVector3 *) &sp118), (MKCollisionResult *) &sp240, (MKCollisionMode) 4, 0) != 0) {
                M2C_FIELD(this, f32 *, 0x37C) = sp244;
            }
        }
        sp58 = this->unk378 - M2C_BITWISE(f64, sp1E8);
        sp198.unk30 = sp58;
        sp60 = (f32) M2C_FIELD(this, f64 *, 0x380) - sp1E8.unk8;
        sp198.unk38 = (f64) sp60;
        var_f29_4354 = (sp198.unk38 * sp198.unk38) + ((sp198.unk30 * sp198.unk30) + (sp198.unk34 * sp198.unk34));
        if (var_f29_4354 > 0.000001f) {
            if (var_f29_4354 > 0.0f) {
                temp_f1_4360 = __frsqrte(var_f29_4354);
                temp_f1_4366 = 0.5 * temp_f1_4360 * -(((f64) var_f29_4354 * (temp_f1_4360 * temp_f1_4360)) - 3.0);
                temp_f1_4370 = 0.5 * temp_f1_4366 * -(((f64) var_f29_4354 * (temp_f1_4366 * temp_f1_4366)) - 3.0);
                var_f29_4354 = (f32) ((f64) var_f29_4354 * (0.5 * temp_f1_4370 * -(((f64) var_f29_4354 * (temp_f1_4370 * temp_f1_4370)) - 3.0)));
            } else if (var_f29_4354 < M2C_BITWISE(f32, 0.0)) {
                var_f29_4354 = __float_nan;
            } else {
                sp10 = var_f29_4354;
                temp_r3_4389 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_4389) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_4399 = 1;
                    } else {
                        var_r0_4399 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_4399 = 5;
                    } else {
                        var_r0_4399 = 3;
                    }
                    break;
                default:
                    var_r0_4399 = 4;
                    break;
                }
                if (var_r0_4399 == 1) {
                    var_f29_4354 = __float_nan;
                }
            }
            var_f8_4421 = 1.0f / var_f29_4354;
        } else {
            var_f8_4421 = 0.0f;
            var_f29_4354 = 0.0f;
        }
        temp_f1_4432 = M2C_BITWISE(f64, sp1E8);
        var_r28_4434 = 0;
        sp198.unk30 *= var_f8_4421;
        sp198.unk34 *= var_f8_4421;
        sp198.unk38 *= var_f8_4421;
        sp240 = 0.0f;
        sp244 = 0.0f;
        sp248 = 0.0f;
        sp250 = 0.0f;
        sp254 = 0.0f;
        sp258 = 0.0f;
        sp260 = 0.0f;
        sp264 = 0.0f;
        sp268 = 0.0f;
        sp26C = 1.0f;
        sp270 = 0.0f;
        sp274 = 0.0f;
        sp278 = 0;
        sp27A = 0;
        sp27B = 0;
        sp27C = 0;
        sp280 = 3.4028235e38f;
        sp284 = 0;
        sp288 = NULL;
        sp28C = -1;
        sp290 = 0;
        sp18 = temp_f1_4432;
        sp20 = (f64) sp1E8.unk8;
        sp198.unk20 = temp_f1_4432;
        sp198.unk28 = (f64) sp1E8.unk8;
        sp198.unk10 = temp_f1_4432;
        sp198.unk18 = (f64) sp1E8.unk8;
loop_49:
        if (var_r28_4434 < (s32) (var_f29_4354 / 500.0f)) {
            spE8.operator*((f32) var_r28_4434 * 500.0f);
            sp38 = M2C_BITWISE(f64, sp1E8) + M2C_BITWISE(f64, spE8);
            spF8 = sp38;
            sp40 = sp1E8.unk8 + spE8.unk8;
            var_f1_4508 = (f32) (var_r28_4434 + 1) * 500.0f;
            sp198.unk20 = sp38;
            sp100 = (f64) sp40;
            sp198.unk28 = (f64) sp40;
            if (var_f1_4508 < var_f29_4354) {

            } else {
                var_f1_4508 = var_f29_4354;
            }
            spC8.operator*(var_f1_4508);
            sp28 = M2C_BITWISE(f64, sp1E8) + M2C_BITWISE(f64, spC8);
            spD8 = sp28;
            sp30 = sp1E8.unk8 + spC8.unk8;
            sp198.unk10 = sp28;
            spE0 = (f64) sp30;
            sp198.unk18 = (f64) sp30;
            if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp198.unk20), *((MKVector3 *) &sp198.unk10), 200.0f, (MKCollisionResult *) &sp240, (MKCollisionMode) 7, 0x0C000000) != 0) {
                if ((sp290 != 0) && (sp288 != NULL) && (var_r0_4548 = M2C_FIELD(sp288, u32 *, 8), ((var_r0_4548 == 0U) == 0))) {

                } else {
                    var_r0_4548 = 0U;
                }
                if (var_r0_4548 != 0U) {
                    temp_r3_4559 = M2C_FIELD(((MKCollisionResult *) &sp240)->GetProp(), void **, 8);
                    temp_f1_4561 = M2C_FIELD(temp_r3_4559, f64 *, 0x30);
                    temp_f0_4562 = M2C_FIELD(temp_r3_4559, f64 *, 0x38);
                    spB8 = temp_f1_4561;
                    this->unk378 = temp_f1_4561;
                    this->unk380 = temp_f0_4562;
                    this->unk368 = 0;
                    spC0 = temp_f0_4562;
                    this->unk364 = 0;
                }
            }
            var_r28_4434 += 1;
            goto loop_49;
        }
        temp_r3_4574 = this->unk364;
        if ((temp_r3_4574 == (s32) this->unk360) && (temp_r3_4574 > 0)) {
            this->unk368 += 1;
            temp_r0_4583 = this->unk368;
            temp_r3_4584 = this->unk360;
            if (temp_r0_4583 >= temp_r3_4584) {
                this->unk368 = temp_r0_4583 - temp_r3_4584;
            }
            this->unk364 -= 1;
        }
        temp_r4_4596 = this->unk360;
        var_r0_4597 = this->unk368 + this->unk364;
        if (var_r0_4597 >= temp_r4_4596) {
            var_r0_4597 -= temp_r4_4596;
        }
        this->unk364 += 1;
        temp_r3_4609 = this->unk36C + (var_r0_4597 * 0x10);
        M2C_FIELD(temp_r3_4609, f64 *, 0) = (f64) this->unk378;
        M2C_FIELD(temp_r3_4609, f64 *, 8) = (f64) this->unk380;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void EarthBossArm::Update() {
    f32 sp3BC;
    f32 sp3B8;
    f32 sp3B4;
    f32 sp3B0;
    f32 sp3AC;
    f32 sp3A8;
    f32 sp3A4;
    f32 sp3A0;
    f32 sp39C;
    f32 sp398;
    f32 sp394;
    f32 sp390;
    Matrix sp350;
    Matrix sp310;
    Matrix sp2D0;
    Matrix sp290;
    Matrix sp250;
    f32 sp23C;
    f32 sp238;
    f32 sp234;
    f32 sp230;
    f32 sp22C;
    f32 sp228;
    f32 sp224;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    MKVector3 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    MKVector3 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Enemy *temp_r4_4645;
    Enemy *temp_r4_4650;
    Enemy *temp_r4_4655;
    f32 temp_f10_5149;
    f32 temp_f8_5159;
    f32 temp_f9_5153;
    f32 var_f1_5240;
    f32 var_f3_4748;
    f32 var_f4_4681;
    f32 var_f4_4909;
    f32 var_f4_4976;
    f32 var_f4_5027;
    f32 var_f9_5094;
    f64 temp_f1_4687;
    f64 temp_f1_4693;
    f64 temp_f1_4697;
    f64 temp_f1_4915;
    f64 temp_f1_4921;
    f64 temp_f1_4925;
    f64 temp_f1_5033;
    f64 temp_f1_5039;
    f64 temp_f1_5043;
    s32 temp_r0_4828;
    s32 temp_r0_4843;
    s32 temp_r0_5252;
    s32 temp_r0_5306;
    s32 temp_r3_4716;
    s32 temp_r3_4944;
    s32 temp_r3_5062;
    s32 var_r0_4726;
    s32 var_r0_4954;
    s32 var_r0_5072;
    void *var_r3_4854;

    MKProp::Update();
    this->unk450 -= gUpdateTimeDelta;
    this->unk3A0.Update();
    temp_r4_4645 = this->unk370;
    MKModel_CalculateNodeWorldMatrix(temp_r4_4645->unk4, M2C_FIELD(temp_r4_4645, s32 *, 0xCCC), &sp350);
    temp_r4_4650 = this->unk370;
    MKModel_CalculateNodeWorldMatrix(temp_r4_4650->unk4, M2C_FIELD(temp_r4_4650, s32 *, 0xCD0), &sp310);
    temp_r4_4655 = this->unk370;
    MKModel_CalculateNodeWorldMatrix(temp_r4_4655->unk4, M2C_FIELD(temp_r4_4655, s32 *, 0xCD4), &sp2D0);
    spF0 = sp310.unk30 - sp350.unk30;
    sp1D0 = spF0;
    spF8 = sp310.unk38 - sp350.unk38;
    sp1D8 = (f64) spF8;
    var_f4_4681 = ((f32) sp1D8 * (f32) sp1D8) + (((f32) sp1D0 * (f32) sp1D0) + ((*(f32 *) ((u8 *) &sp1D0 + 0x4)) * (*(f32 *) ((u8 *) &sp1D0 + 0x4))));
    if (var_f4_4681 > 1e-12f) {
        if (var_f4_4681 > 0.0f) {
            temp_f1_4687 = __frsqrte(var_f4_4681);
            temp_f1_4693 = 0.5 * temp_f1_4687 * -(((f64) var_f4_4681 * (temp_f1_4687 * temp_f1_4687)) - 3.0);
            temp_f1_4697 = 0.5 * temp_f1_4693 * -(((f64) var_f4_4681 * (temp_f1_4693 * temp_f1_4693)) - 3.0);
            var_f4_4681 = (f32) ((f64) var_f4_4681 * (0.5 * temp_f1_4697 * -(((f64) var_f4_4681 * (temp_f1_4697 * temp_f1_4697)) - 3.0)));
        } else if (var_f4_4681 < M2C_BITWISE(f32, 0.0)) {
            var_f4_4681 = __float_nan;
        } else {
            sp18 = var_f4_4681;
            temp_r3_4716 = M2C_BITWISE(s32, sp18) & 0x7F800000;
            switch (temp_r3_4716) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                    var_r0_4726 = 1;
                } else {
                    var_r0_4726 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                    var_r0_4726 = 5;
                } else {
                    var_r0_4726 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_4726 = 4;
                break;
            }
            if (var_r0_4726 == 1) {
                var_f4_4681 = __float_nan;
            }
        }
        var_f3_4748 = 1.0f / var_f4_4681;
    } else {
        var_f3_4748 = 0.0f;
    }
    spE4 = (*(f32 *) ((u8 *) &sp1D0 + 0x4)) * var_f3_4748;
    spE0 = (f32) sp1D0 * var_f3_4748;
    spE8 = (f32) sp1D8 * var_f3_4748;
    sp200 = (f64) spE0;
    sp208 = (f64) spE8;
    M2C_STRUCT_COPY((s32) &sp350.unk3C + 4, (s32) &sp310.unk3C + 4, 0x40);
    sp390 = (f32) sp200;
    sp394 = (*(f32 *) ((u8 *) &sp200 + 0x4));
    sp90 = ((*(f32 *) ((u8 *) &sp200 + 0x4)) * sp3B8) - ((f32) sp208 * sp3B4);
    sp94 = ((f32) sp208 * sp3B0) - ((f32) sp200 * sp3B8);
    sp98 = ((f32) sp200 * sp3B4) - ((*(f32 *) ((u8 *) &sp200 + 0x4)) * sp3B0);
    sp1C0 = (f64) sp90;
    sp1C8 = (f64) sp98;
    sp398 = (f32) sp208;
    sp39C = 0.0f;
    sp88 = ((f32) sp200 * (*(f32 *) ((u8 *) &sp1C0 + 0x4))) - ((*(f32 *) ((u8 *) &sp200 + 0x4)) * (f32) sp1C0);
    sp80 = ((*(f32 *) ((u8 *) &sp200 + 0x4)) * (f32) sp1C8) - ((f32) sp208 * (*(f32 *) ((u8 *) &sp1C0 + 0x4)));
    sp84 = ((f32) sp208 * (f32) sp1C0) - ((f32) sp200 * (f32) sp1C8);
    sp1B8 = (f64) sp88;
    sp1B0 = (f64) sp80;
    sp3A0 = (f32) sp1C0;
    sp3A4 = (*(f32 *) ((u8 *) &sp1C0 + 0x4));
    sp3A8 = (f32) sp1C8;
    sp3AC = 0.0f;
    sp3B0 = (f32) sp1B0;
    sp3B4 = (*(f32 *) ((u8 *) &sp1B0 + 0x4));
    sp3B8 = (f32) sp1B8;
    sp3BC = 0.0f;
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &sp390));
    temp_r0_4828 = this->unk38C;
    switch (temp_r0_4828) {                         /* switch 2; irregular */
    case 3:                                         /* switch 2 */
        UpdateTarget();
        /* fallthrough */
    case 4:                                         /* switch 2 */
        temp_r0_4843 = this->unk364;
        sp1F0 = this->unk378;
        sp1F8 = this->unk380;
        if (temp_r0_4843 != 0) {
            if (temp_r0_4843 > 0) {
                var_r3_4854 = this->unk36C + (this->unk368 * 0x10);
            } else {
                var_r3_4854 = NULL;
            }
            sp1F0 = M2C_FIELD(var_r3_4854, f64 *, 0);
            sp1F8 = M2C_FIELD(var_r3_4854, f64 *, 8);
        }
        if ((s32) this->unk38C == 2) {
            sp1F0 = (f64) sp2D0.unk30;
            sp1F8 = (f64) sp2D0.unk38;
        }
        M2C_STRUCT_COPY((s32) &sp250.unk3C + 4, (s32) &sp350.unk3C + 4, 0x40);
        sp290.Inverse(&sp290);
        MKModel_CalculateNodeWorldMatrix(this->unk4, this->unk144, &sp250);
        spD0 = sp1F0 - sp250.unk30;
        sp180 = spD0;
        spD8 = (f32) sp1F8 - sp250.unk38;
        sp188 = (f64) spD8;
        var_f4_4909 = ((f32) sp188 * (f32) sp188) + (((f32) sp180 * (f32) sp180) + ((*(f32 *) ((u8 *) &sp180 + 0x4)) * (*(f32 *) ((u8 *) &sp180 + 0x4))));
        if (var_f4_4909 > 1e-12f) {
            if (var_f4_4909 > 0.0f) {
                temp_f1_4915 = __frsqrte(var_f4_4909);
                temp_f1_4921 = 0.5 * temp_f1_4915 * -(((f64) var_f4_4909 * (temp_f1_4915 * temp_f1_4915)) - 3.0);
                temp_f1_4925 = 0.5 * temp_f1_4921 * -(((f64) var_f4_4909 * (temp_f1_4921 * temp_f1_4921)) - 3.0);
                var_f4_4909 = (f32) ((f64) var_f4_4909 * (0.5 * temp_f1_4925 * -(((f64) var_f4_4909 * (temp_f1_4925 * temp_f1_4925)) - 3.0)));
            } else if (var_f4_4909 < M2C_BITWISE(f32, 0.0)) {
                var_f4_4909 = __float_nan;
            } else {
                sp14 = var_f4_4909;
                temp_r3_4944 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_4944) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_4954 = 1;
                    } else {
                        var_r0_4954 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_4954 = 5;
                    } else {
                        var_r0_4954 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_4954 = 4;
                    break;
                }
                if (var_r0_4954 == 1) {
                    var_f4_4909 = __float_nan;
                }
            }
            var_f4_4976 = 1.0f / var_f4_4909;
        } else {
            var_f4_4976 = 0.0f;
        }
        spB4 = (*(f32 *) ((u8 *) &sp180 + 0x4)) * var_f4_4976;
        spB0 = (f32) sp180 * var_f4_4976;
        spB8 = (f32) sp188 * var_f4_4976;
        sp190 = (f64) spB0;
        sp198 = (f64) spB8;
        spC0 = ((f32) sp198 * sp290.unk20) + (((f32) sp190 * M2C_BITWISE(f32, sp290)) + ((*(f32 *) ((u8 *) &sp190 + 0x4)) * sp290.unk10));
        spC4 = ((f32) sp198 * sp290.unk24) + (((f32) sp190 * sp290.unk4) + ((*(f32 *) ((u8 *) &sp190 + 0x4)) * sp290.unk14));
        spC8 = ((f32) sp198 * sp290.unk28) + (((f32) sp190 * sp290.unk8) + ((*(f32 *) ((u8 *) &sp190 + 0x4)) * sp290.unk18));
        sp1A0 = (f64) spC0;
        sp1A8 = (f64) spC8;
        var_f4_5027 = ((f32) sp1A8 * (f32) sp1A8) + (((f32) sp1A0 * (f32) sp1A0) + ((*(f32 *) ((u8 *) &sp1A0 + 0x4)) * (*(f32 *) ((u8 *) &sp1A0 + 0x4))));
        if (var_f4_5027 > 1e-12f) {
            if (var_f4_5027 > 0.0f) {
                temp_f1_5033 = __frsqrte(var_f4_5027);
                temp_f1_5039 = 0.5 * temp_f1_5033 * -(((f64) var_f4_5027 * (temp_f1_5033 * temp_f1_5033)) - 3.0);
                temp_f1_5043 = 0.5 * temp_f1_5039 * -(((f64) var_f4_5027 * (temp_f1_5039 * temp_f1_5039)) - 3.0);
                var_f4_5027 = (f32) ((f64) var_f4_5027 * (0.5 * temp_f1_5043 * -(((f64) var_f4_5027 * (temp_f1_5043 * temp_f1_5043)) - 3.0)));
            } else if (var_f4_5027 < M2C_BITWISE(f32, 0.0)) {
                var_f4_5027 = __float_nan;
            } else {
                sp10 = var_f4_5027;
                temp_r3_5062 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_5062) {             /* switch 4; irregular */
                case 0x7F800000:                    /* switch 4 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_5072 = 1;
                    } else {
                        var_r0_5072 = 2;
                    }
                    break;
                case 0x0:                           /* switch 4 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_5072 = 5;
                    } else {
                        var_r0_5072 = 3;
                    }
                    break;
                default:                            /* switch 4 */
                    var_r0_5072 = 4;
                    break;
                }
                if (var_r0_5072 == 1) {
                    var_f4_5027 = __float_nan;
                }
            }
            var_f9_5094 = 1.0f / var_f4_5027;
        } else {
            var_f9_5094 = 0.0f;
        }
        spA8 = (f32) sp1A8 * var_f9_5094;
        sp70 = (sp250.unk18 * sp290.unk20) + ((sp250.unk10 * M2C_BITWISE(f32, sp290)) + (sp250.unk14 * sp290.unk10));
        sp74 = (sp250.unk18 * sp290.unk24) + ((sp250.unk10 * sp290.unk4) + (sp250.unk14 * sp290.unk14));
        sp78 = (sp250.unk18 * sp290.unk28) + ((sp250.unk10 * sp290.unk8) + (sp250.unk14 * sp290.unk18));
        sp170 = (f64) sp70;
        sp178 = (f64) sp78;
        spA0 = (f32) sp1A0 * var_f9_5094;
        spA4 = (*(f32 *) ((u8 *) &sp1A0 + 0x4)) * var_f9_5094;
        sp68 = -(f32) sp178;
        sp1E0 = (f64) spA0;
        sp1E8 = (f64) spA8;
        temp_f10_5149 = M2C_FIELD(this, f32 *, 0xE0);
        sp148 = (f64) sp68;
        sp210 = temp_f10_5149;
        temp_f9_5153 = M2C_FIELD(this, f32 *, 0xE4);
        sp60 = -(f32) sp170;
        sp64 = -(*(f32 *) ((u8 *) &sp170 + 0x4));
        sp214 = temp_f9_5153;
        temp_f8_5159 = M2C_FIELD(this, f32 *, 0xE8);
        sp140 = (f64) sp60;
        sp218 = temp_f8_5159;
        sp21C = 0.0f;
        sp220 = (f32) sp170;
        sp58 = ((f32) sp140 * temp_f9_5153) - ((*(f32 *) ((u8 *) &sp140 + 0x4)) * temp_f10_5149);
        sp50 = ((*(f32 *) ((u8 *) &sp140 + 0x4)) * temp_f8_5159) - ((f32) sp148 * temp_f9_5153);
        sp54 = ((f32) sp148 * temp_f10_5149) - ((f32) sp140 * temp_f8_5159);
        sp224 = (*(f32 *) ((u8 *) &sp170 + 0x4));
        sp228 = (f32) sp178;
        sp22C = 0.0f;
        sp150 = (f64) sp50;
        sp158 = (f64) sp58;
        Normalise(sp160);
        sp230 = M2C_BITWISE(f32, sp160);
        sp234 = sp160.unk4;
        sp238 = sp160.unk8;
        sp23C = 0.0f;
        ((Matrix *) &sp210)->ZAxis3();
        sp30 = -*M2C_ERROR(/* Read from unset register $r3 */);
        sp34 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
        sp38 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
        sp110 = (f64) sp30;
        sp118 = (f64) sp38;
        ((Matrix *) &sp210)->XAxis3();
        sp20 = -*M2C_ERROR(/* Read from unset register $r3 */);
        sp24 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
        sp28 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
        sp120 = (f64) sp20;
        sp128 = (f64) sp28;
        sp22C = 0.0f;
        sp40 = ((*(f32 *) ((u8 *) &sp110 + 0x4)) * (f32) sp128) - ((f32) sp118 * (*(f32 *) ((u8 *) &sp120 + 0x4)));
        sp44 = ((f32) sp118 * (f32) sp120) - ((f32) sp110 * (f32) sp128);
        var_f1_5240 = 0.5f * (6.2831855f * gUpdateTimeDelta);
        sp48 = ((f32) sp110 * (*(f32 *) ((u8 *) &sp120 + 0x4))) - ((*(f32 *) ((u8 *) &sp110 + 0x4)) * (f32) sp120);
        sp130 = (f64) sp40;
        sp138 = (f64) sp48;
        sp220 = (f32) sp130;
        sp224 = (*(f32 *) ((u8 *) &sp130 + 0x4));
        sp228 = (f32) sp138;
        temp_r0_5252 = this->unk38C;
        if (temp_r0_5252 == 1) {
            var_f1_5240 = 6.2831855f;
        }
        if ((temp_r0_5252 == 4) || (temp_r0_5252 == 5)) {
            var_f1_5240 = 0.0f;
        }
        Tools_RotateMatrixToDirection((Matrix *) &sp210, *((MKVector3 *) &this->unkE0), *((MKVector3 *) &sp1E0), var_f1_5240);
        Normalise(sp100);
        this->unkE0 = M2C_BITWISE(f64, sp100);
        this->unkE8 = (f64) sp100.unk8;
        if (((s32) this->unk38C == 2) && ((((f32) sp1E8 * M2C_FIELD(this, f32 *, 0xE8)) + (((f32) sp1E0 * M2C_FIELD(this, f32 *, 0xE0)) + ((*(f32 *) ((u8 *) &sp1E0 + 0x4)) * M2C_FIELD(this, f32 *, 0xE4)))) >= 1.0f)) {
            this->unk38C = 0;
            this->unkE0 = sp1E0;
            this->unkE8 = sp1E8;
            ((EarthBoss *) this->unk370)->ShowFist(1U);
            Disable();
        }
        break;
    }
    temp_r0_5306 = this->unk38C;
    if (temp_r0_5306 == 4) {
        UpdateExtension();
    } else if (temp_r0_5306 == 1) {
        UpdateRetraction();
    }
    MKModel_SetColor(this->unk4, *(MKModel_GetColor(this->unk370->unk4)));
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void EarthBossArm::Deinit() {
    MKAnimScript *temp_r31_5346;
    MKAnimScript *temp_r31_5371;
    MKHeap *temp_r3_5349;
    MKHeap *temp_r3_5372;
    MKMaterial *temp_r3_5393;

    temp_r31_5346 = this->unk36C;
    if (temp_r31_5346 != NULL) {
        temp_r3_5349 = MKHeap::Current();
        if (temp_r3_5349 != NULL) {
            ((MKHeap *) (temp_r3_5349->Current()))->Free(temp_r31_5346, NULL, 0);
        } else {
            free(temp_r31_5346);
        }
        this->unk36C = NULL;
    }
    this->unk360 = 0;
    this->unk368 = 0;
    this->unk364 = 0;
    this->unk374->Deinit();
    temp_r31_5371 = this->unk374;
    temp_r3_5372 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_5372 != NULL) {
        ((MKHeap *) (temp_r3_5372->Current()))->Free(temp_r31_5371, NULL, 0);
    } else {
        free(temp_r31_5371);
    }
    this->unk374 = NULL;
    MKModel_Destroy(this->unk4);
    this->unk4 = NULL;
    this->unk3A0.Deinit();
    temp_r3_5393 = this->unk468;
    if (temp_r3_5393 != NULL) {
        MKMaterial_Destroy(temp_r3_5393);
        this->unk468 = NULL;
    }
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Animation *' to
void EarthBossArm::InitBoneData(int arg0, const char *arg1) {
    f64 sp8;
    s32 temp_r31_5421;
    void (*var_r29_5455)(EarthBossArm *, MKDynamicBone *, void *);
    void *temp_r30_5423;

    temp_r31_5421 = arg0 << 7;
    temp_r30_5423 = this + temp_r31_5421;
    M2C_FIELD(temp_r30_5423, s32 *, 0xC4) = (s32) Tools_GetMatchingNodeIndex(this->unk4, arg1);
    M2C_FIELD(temp_r30_5423, Enemy **, 0xC0) = (Enemy *) this->unk370;
    ((Animation *) &sp8)->GetNodeOrigin(MKModel_GetAnimation(this->unk4));
    M2C_FIELD(temp_r30_5423, f64 *, 0x70) = sp8;
    M2C_FIELD(temp_r30_5423, f64 *, 0x78) = sp10;
    M2C_FIELD(temp_r30_5423, f32 *, 0x60) = 0.0f;
    M2C_FIELD(temp_r30_5423, f32 *, 0x64) = 0.0f;
    M2C_FIELD(temp_r30_5423, f32 *, 0x68) = 0.0f;
    M2C_FIELD(temp_r30_5423, f32 *, 0xC8) = 0.0f;
    M2C_FIELD(temp_r30_5423, f32 *, 0xCC) = 0.0f;
    M2C_FIELD(temp_r30_5423, f32 *, 0xD4) = 0.0f;
    M2C_FIELD(temp_r30_5423, s8 *, 0xD8) = 1;
    switch (arg0) {                                 /* irregular */
    case 0:
        var_r29_5455 = &EarthBossArm::UpdateShoulderBone;
        break;
    case 1:
        var_r29_5455 = &EarthBossArm::UpdateElbowBone;
        break;
    default:
        var_r29_5455 = &EarthBossArm::UpdateExtensionBone;
        break;
    }
    MKDynamicBone_SetUpdater(MKDynamicBone_GetDynamicBone(this->unk4, M2C_FIELD(temp_r30_5423, s32 *, 0xC4)), (void (*)(MKDynamicBone *, void *)) var_r29_5455, this + (temp_r31_5421 + 0x60));
}
#endif

void EarthBossArm::Init2(EarthBoss *arg0) {
    this->unk370 = (Enemy *) arg0;
    InitBoneData(5, "Vine06");
    InitBoneData(4, "Vine05");
    InitBoneData(3, "Vine04");
    InitBoneData(2, "Vine03");
    InitBoneData(1, "Vine02");
    InitBoneData(0, "Vine01");
    SetRetracted();
}

#if 0 // DRAFT: function call 'MKModel_Create(MKHeap *, signed char *, int, int)' does not
void EarthBossArm::LoadDone() {
    MKCollisionInfo *var_r3_5565;
    MKHeap *temp_r31_5547;
    MKHeap *temp_r3_5556;
    MKHeap *temp_r3_5558;

    MKProp::LoadDone();
    temp_r31_5547 = ((Animation *) (M2C_FIELD(this->unk0, Animation **, 0x30)))->GetName();
    this->unk4 = MKModel_Create(MKModel_GetName(M2C_FIELD(this->unk0, MKModel **, 0x2C)), (s8 *) temp_r31_5547, 2, NULL);
    temp_r3_5556 = MKModel_GetWorldMatrix(this->unk4);
    this->unk8 = temp_r3_5556;
    temp_r3_5558 = temp_r3_5556->Current();
    if (temp_r3_5558 != NULL) {
        var_r3_5565 = ((MKHeap *) (temp_r3_5558->Current()))->Alloc(0x58, NULL, 0);
    } else {
        var_r3_5565 = malloc(0x58);
    }
    this->unk374 = (MKAnimScript *) var_r3_5565;
    this->unk374->Init(M2C_FIELD(this->unk0, MKAnimScript **, 0x34), this->unk4);
    this->unk374->SetAnimation(MKModel_GetAnimation(this->unk4));
    this->unk38C = 0;
    this->unk3A0.Init(this->unk4, 0.75f, 0.25f);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void EarthBossArm::Init() {
    MKCollisionInfo *var_r3_5620;
    MKHeap *temp_r3_5613;

    MKProp::Init();
    this->unk370 = NULL;
    this->unk374 = NULL;
    this->unk390 = 0;
    M2C_FIELD(this, f32 *, 0x378) = 0.0f;
    M2C_FIELD(this, f32 *, 0x37C) = 0.0f;
    M2C_FIELD(this, f32 *, 0x380) = 0.0f;
    temp_r3_5613 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_5613 != NULL) {
        var_r3_5620 = ((MKHeap *) (temp_r3_5613->Current()))->Alloc(0x140, NULL, 0);
    } else {
        var_r3_5620 = malloc(0x140);
    }
    this->unk36C = (MKAnimScript *) var_r3_5620;
    this->unk360 = 0x14;
    this->unk468 = MKMaterial_Create("fx_HDRGLowOverlay");
    this->unk450 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void (EarthBossArm::*)(MKDynamicBone *,
void EarthBossArmDescriptor::LoadDone() {
    s32 var_r29_5657;
    s8 temp_r30_5655;

    MKPropDescriptor::LoadDone();
    temp_r30_5655 = ((Animation *) this->unk30)->GetNmbrOfNodes();
    var_r29_5657 = 0;
loop_2:
    if (var_r29_5657 < temp_r30_5655) {
        MKDynamicBone_SetUpdater(MKDynamicBone_GetDynamicBone(this->unk2C, var_r29_5657), (void (*)(MKDynamicBone *, void *)) &EarthBossArm::UpdateShoulderBone, NULL);
        var_r29_5657 += 1;
        goto loop_2;
    }
}
#endif
