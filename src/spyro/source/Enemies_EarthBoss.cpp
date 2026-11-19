#include "spyro/source/Enemies_EarthBoss.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EarthBossGoals.h"
#include "spyro/source/EarthShockwave.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/SpyroHud.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
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

#if 0 // DRAFT: undefined identifier 'unk8C4'
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
    temp_r0_101 = this->unk110.unk8C4;
    if (var_r8_56 < temp_r0_101) {
        if ((var_r8_56 < 0) || (var_r8_56 >= temp_r0_101)) {
            var_r6_64 = NULL;
        } else {
            temp_r4_68 = this->unk110.unk8C0;
            var_r0_69 = this->unk110.unk8C8 + var_r8_56;
            if (var_r0_69 >= temp_r4_68) {
                var_r0_69 -= temp_r4_68;
            }
            var_r6_64 = this->unk110.unk8CC + (var_r0_69 * 0x38);
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

#if 0 // DRAFT: undefined identifier 'unkCC0'
void EarthBoss::RestartStage() {
    EarthBossArm *temp_r4_216;
    s32 var_r0_222;

    GetMaxHealth();
    SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
    UpdateEnemyHud();
    temp_r4_216 = this->unkCC0;
    if (temp_r4_216 != NULL) {
        var_r0_222 = 0xA - (this->unk110.unk9D8 * 4);
        if ((s32) lit_1334 > var_r0_222) {
            var_r0_222 = lit_1334;
        }
        temp_r4_216->unk388 = var_r0_222;
    }
    this->unkCC8 = (0.5f * (f32) (this->unk110.unk928->unk11C - this->unk110.unk9D8)) + 1.0f;
}
#endif

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

#if 0 // DRAFT: undefined identifier 'unkCC0'
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
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
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
            temp_f1_485 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
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

#if 0 // DRAFT: illegal explicit conversion from 'int' to
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
#endif

#if 0 // DRAFT: undefined identifier 'unk928'
void EarthBoss::UpdatePhrasesAndSounds() {
    EnemyDescriptor *temp_r3_749;
    f32 temp_f1_851;
    f32 temp_f30_760;
    f32 temp_f30_775;
    f32 temp_f31_756;
    f32 temp_f31_812;
    s32 var_r29_781;
    s32 var_r30_782;

    temp_r3_749 = this->unk110.unk928;
    temp_f31_756 = this->unk110.unk9B8;
    temp_f30_760 = (f32) temp_r3_749->unk11C * this->unk110.unk928->GetEnemySetting((EnemySettingType) 0);
    temp_f30_775 = ((temp_f30_760 - ((f32) (this->unk110.unk9D8 + 1) * temp_r3_749->GetEnemySetting((EnemySettingType) 0))) + temp_f31_756) / temp_f30_760;
    if (temp_f30_775 > this->unkCEC) {
        this->unkCEC = temp_f30_775;
    }
    var_r29_781 = 0;
    var_r30_782 = 0;
loop_3:
    if ((temp_f30_775 != 0.0f) && (*(checked_cast<EarthBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_782 + 0x2D4)) != 0.0f) && (this->unkCEC > *(checked_cast<EarthBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_782 + 0x2D4))) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f30_775 == *(checked_cast<EarthBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_782 + 0x2D4))) != 0))) {
        temp_f31_812 = 2.0f * M2C_FIELD(checked_cast<EarthBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2FC);
        this->unkCF0 = MKRand_Float(&gViewSeed, M2C_FIELD(checked_cast<EarthBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2FC), temp_f31_812);
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

#if 0 // DRAFT: undefined identifier 'arg_sp10C'
void EarthBoss::UpdateCollisionItems() {
    Animation *temp_r29_887;
    EarthBossArm *temp_r4_1013;
    f32 temp_f30_949;
    f32 temp_f31_957;
    f32 temp_f3_915;
    f32 temp_f6_922;
    f32 temp_f8_928;
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
            M2C_STRUCT_COPY((s32) &arg_sp10C + 4, (s32) (&identity - 4) + 4, 0x40);
            MKModel_CalculateNodeWorldMatrix(this->unk4, temp_r25_900, (Matrix *) &arg_sp110);
            arg_sp110.Inverse((Matrix *) &arg_sp110);
            temp_f3_915 = M2C_FIELD(temp_r30_891, f32 *, 0xB3C);
            temp_f6_922 = M2C_FIELD(temp_r30_891, f32 *, 0xB38);
            temp_f8_928 = M2C_FIELD(temp_r30_891, f32 *, 0xB40);
            arg_sp50 = (temp_f8_928 * arg_sp130) + ((temp_f6_922 * arg_sp110) + (temp_f3_915 * arg_sp120));
            arg_sp54 = (temp_f8_928 * arg_sp134) + ((temp_f6_922 * arg_sp114) + (temp_f3_915 * arg_sp124));
            arg_sp58 = (temp_f8_928 * arg_sp138) + ((temp_f6_922 * arg_sp118) + (temp_f3_915 * arg_sp128));
            arg_spC0 = (f64) arg_sp50;
            arg_spC8 = (f64) arg_sp58;
            temp_f30_949 = 50.0f * (1.0f - (M2C_FIELD(temp_r30_891, f32 *, 0xB48) / 1.0f));
            arg_spD0.SetIdentity();
            temp_f31_957 = _table_sinf(8.0f * (3.1415927f * M2C_FIELD(temp_r30_891, f32 *, 0xB48)));
            arg_spA0.operator*(temp_f30_949);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_spB0 = arg_sp40;
            arg_sp48 = arg_spA8 * temp_f31_957;
            arg_spB8 = (f64) arg_sp48;
            arg_sp100 = (f32) arg_spB0;
            arg_sp104 = arg_spB4;
            arg_sp108 = (f32) arg_spB8;
            arg_sp10C = 1.0f;
            temp_r29_887->SetCustomMatrix(temp_r25_900, (Matrix *) &arg_spD0, (AnimationMatrixPosition) 2, 0U);
            M2C_FIELD(temp_r30_891, f32 *, 0xB48) = (f32) (M2C_FIELD(temp_r30_891, f32 *, 0xB48) + gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (M2C_FIELD(temp_r30_891, f32 *, 0xB48) == 1.0f) {
                M2C_FIELD(temp_r30_891, u8 *, 0xB55) = 0U;
                ((Animation *) (MKModel_GetAnimation(this->unk4)))->SetCustomMatrix(temp_r25_900, NULL, (AnimationMatrixPosition) 2, 0U);
            }
        }
        if ((u8) M2C_FIELD(temp_r30_891, u8 *, 0xB54) != 0) {
            arg_sp150.SetIdentity();
            if ((var_r28_888 == 2) && (temp_r4_1013 = this->unkCC0, (((s32) temp_r4_1013->unk38C == 0) == 0))) {
                MKModel_CalculateNodeWorldMatrix(temp_r4_1013->unk4, temp_r4_1013->unk344, (Matrix *) &arg_sp150);
                arg_sp80.operator*(200.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_FIELD(temp_r30_891, f64 *, 0xB18) = arg_sp30;
                arg_sp38 = arg_sp188 + arg_sp88;
                arg_sp90 = arg_sp30;
                arg_sp98 = (f64) arg_sp38;
                M2C_FIELD(temp_r30_891, f64 *, 0xB20) = (f64) arg_sp38;
            } else {
                MKModel_CalculateNodeWorldMatrix(this->unk4, M2C_FIELD(temp_r30_891, s32 *, 0xB4C), (Matrix *) &arg_sp150);
                arg_sp150.YAxis3();
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_mul $f0, $f1, $f0 */);
                arg_sp60 = arg_sp10;
                arg_sp18 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8) * M2C_FIELD(temp_r30_891, f32 *, 0xB30);
                arg_sp68 = (f64) arg_sp18;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_FIELD(temp_r30_891, f64 *, 0xB18) = arg_sp20;
                arg_sp70 = arg_sp20;
                arg_sp28 = arg_sp188 + (f32) arg_sp68;
                arg_sp78 = (f64) arg_sp28;
                M2C_FIELD(temp_r30_891, f64 *, 0xB20) = (f64) arg_sp28;
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

#if 0 // DRAFT: undefined identifier 'unkCDD'
void EarthBoss::UpdateEnemyHud() {
    EnemyHudData sp8;
    f32 temp_f31_1143;

    if ((u8) this->unkCDD != 0) {
        sp8.EnemyHudData();
        temp_f31_1143 = this->unk110.unk9B8;
        GetMaxHealth();
        sp8.Init((Enemy *) this, temp_f31_1143, M2C_ERROR(/* Read from unset register $f1 */));
        EnemyHud_Modified(sp8);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkCC0'
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

#if 0 // DRAFT: undefined identifier 'unkCE0'
s32 EarthBoss::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    if (Enemy::Spawn(arg0, arg1) != 0) {
        UpdateEnemyHud();
        KDSound_Stop(&this->unkCE0);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: ')' expected
void EarthBoss::Message(MKMessage *arg0) {
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
        if (!(((u8) this->unk110.unk9F9 >> 7U) & 1)) {
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
            M2C_STRUCT_COPY((s32) &arg_sp2C + 4, (s32) (&identity - 4) + 4, 0x40);
            temp_f6_1347 = this->unk110.unk4B8;
            arg_sp50 = temp_f6_1347;
            temp_f1_1355 = this->unk110.unk4BC;
            arg_sp54 = temp_f1_1355;
            temp_f5_1361 = this->unk110.unk4C0;
            arg_sp58 = temp_f5_1361;
            arg_sp18 = (up.unk0 * temp_f1_1355) - (up.unk4 * temp_f6_1347);
            arg_sp10 = (up.unk4 * temp_f5_1361) - (up.unk8 * temp_f1_1355);
            arg_sp14 = (up.unk8 * temp_f6_1347) - (up.unk0 * temp_f5_1361);
            arg_sp28 = (f64) arg_sp18;
            arg_sp20 = (f64) arg_sp10;
            arg_sp5C = 0.0f;
            arg_sp30 = (f32) arg_sp20;
            arg_sp34 = arg_sp24;
            arg_sp38 = (f32) arg_sp28;
            arg_sp3C = 0.0f;
            arg_sp60 = this->unk110.unk4A8;
            arg_sp64 = this->unk110.unk4AC;
            arg_sp68 = this->unk110.unk4B0;
            arg_sp6C = 1.0f;
            TempDisableCollision(1U);
            Teleport(&arg_sp30);
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

#if 0 // DRAFT: undefined identifier 'unk520'
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
    f32 temp_f31_1466;
    s32 temp_r0_1516;
    void *temp_r30_1514;
    void *temp_r3_1509;

    if (this->unk110.unk520->CheckEvent(4) != 0) {
        temp_f31_1466 = ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.025f, 0.2f, 0.2f, this->unk8 + 0x30, 80.0f, 0, 4.0f, 0U);
        sp7C = 0;
        MKVector(0.025f, 0.4f, 0.025f);
        sp48.operator*(500.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp78 = 0x417;
        sp10 = sp48.unk8 * temp_f31_1466;
        sp80 = sp8;
        sp88 = (f64) sp10;
        sp90 = 1;
        sp58 = sp8;
        sp60 = (f64) sp10;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp78, sp8);
    }
    if (this->unk110.unk520->CheckEvent(0xB) != 0) {
        temp_r3_1509 = this->unk8;
        sp68 = M2C_FIELD(temp_r3_1509, f64 *, 0x30);
        sp70 = M2C_FIELD(temp_r3_1509, f64 *, 0x38);
        temp_r30_1514 = this->unk110.unk910;
        temp_r0_1516 = M2C_FIELD(M2C_FIELD(temp_r30_1514, void **, 0), s32 *, 0x68);
        switch (temp_r0_1516) {                     /* irregular */
        case 0x3D:
            MKModel_CalculateRefPointWorldPosition(this->unk4, *M2C_FIELD(temp_r30_1514, s32 **, 0x7C), (MKVector3 *) &sp68);
            /* fallthrough */
        case 0x3E:
            MKModel_CalculateRefPointWorldPosition(this->unk4, *M2C_FIELD(temp_r30_1514, s32 **, 0x7C), (MKVector3 *) &sp68);
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

#if 0 // DRAFT: undefined identifier 'unkCC0'
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
#endif

#if 0 // DRAFT: undefined identifier 'unkCDC'
void EarthBoss::SetDefaults() {
    Enemy::SetDefaults();
    this->unkCDC = 0;
    this->unkCDD = 0;
    this->unkCC8 = 0.0f;
    RestartStage();
}
#endif

#if 0 // DRAFT: ')' expected
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
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **, M2C_UNK, f64, f32), 0x84)(gMK, 0, (f64) sp8, 1.0f)))->AddSphere(this + (temp_r30_1628 + 0xB18), arg3, 0.0f, *((MKVector4 *) &sp18), (MKCollisionMode) 2, M2C_FIELD(temp_r29_1669, MKCollisionInfo **, 0xB10), (u32) this->unk110.unk928->unk70);
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

#if 0 // DRAFT: undefined identifier 'unk930'
void EarthBoss::LoadDone() {
    Enemy::LoadDone();
    this->unk110.unk930 = this->unk110.unk92C;
    this->unkCCC = (s32) Tools_GetMatchingNodeIndex(this->unk4, "L_Bicep");
    this->unkCD0 = (s32) Tools_GetMatchingNodeIndex(this->unk4, "L_Forearm");
    this->unkCD4 = (s32) Tools_GetMatchingNodeIndex(this->unk4, "L_Hand");
    this->unkCD8 = (u32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, "rubble05");
    ShowFist(1U);
    this->unkCC0 = checked_cast<EarthBossArm *, MKProp>(gMK->CreateProp("EarthBossArm"));
    this->unkCC0->Init2(this);
    if (!(this->unk110.unk570 & 0x160000)) {
        Disable();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkCF4'
s32 EarthBoss::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1913;

    var_r31_1913 = 0;
    if ((Enemy::LoadLine(arg0) != 0) || (this->unkCF4.LoadLine(arg0, "OnReset") != 0)) {
        var_r31_1913 = 1;
    }
    return var_r31_1913;
}
#endif

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
    KDSound_Stop(&this->unkCE0);
    PhrasePlayer_StopEvent(this->unkCE4);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkCC0'
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
    this->unk110.unk92C = temp_r31_1993;
    this->unkCE0 = 0;
    this->unkCE4 = 0;
    this->unkCE8 = NULL;
    this->unkCEC = 0.0f;
    this->unkCF0 = 0.0f;
    this->unkCC4 = checked_cast<EarthShockwave *, MKProp>(gMK->CreateProp("EarthShockwave"));
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
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
    sp10 = 500.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    temp_r3_2065->unk8 -= (f32) sp40;
    temp_r3_2085 = this->unk1C;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
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

#if 0 // DRAFT: illegal type
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
        strcpy(temp_r29_2281 + 0x2B4, "");
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

#if 0 // DRAFT: undefined identifier 'unkBA0'
void *EarthBossArm::GetCollisionInfo() {
    return this->unk370->unkBA0;
}
#endif

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

#if 0 // DRAFT: undefined identifier 'arg_spF0'
s32 EarthBossArm::CheckMeleeHit(EnemyAttack *arg0) {
    Enemy *temp_r3_2806;
    Enemy *temp_r4_2861;
    MKProp **temp_r3_2863;
    MKProp **var_r4_2807;
    MKProp *temp_r0_2816;
    MKProp *var_r0_2687;
    MKProp *var_r31_2701;
    f32 var_f4_2716;
    f32 var_f5_2729;
    f64 temp_f1_2734;
    f64 temp_f1_2740;
    f64 temp_f1_2744;
    s32 temp_r3_2763;
    s32 var_r0_2773;
    MKModel_CalculateNodeWorldMatrix(this->unk4, this->unk344, (Matrix *) &arg_spF0);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_sp78 = arg_sp58;
    arg_sp60 = arg_spF8 * 200.0f;
    arg_sp80 = (f64) arg_sp60;
    M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
    arg_spA8 = arg_sp48;
    arg_sp50 = arg_sp128 + (f32) arg_sp80;
    arg_spB0 = (f64) arg_sp50;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp40 = arg_spF8 * 450.0f;
    arg_sp68 = arg_sp38;
    arg_sp70 = (f64) arg_sp40;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
    arg_sp98 = arg_sp28;
    arg_sp30 = arg_sp128 + (f32) arg_sp70;
    arg_sp130 = 0.0f;
    arg_spA0 = (f64) arg_sp30;
    arg_sp134 = 0.0f;
    arg_sp138 = 0.0f;
    arg_sp140 = 0.0f;
    arg_sp144 = 0.0f;
    arg_sp148 = 0.0f;
    arg_sp150 = 0.0f;
    arg_sp154 = 0.0f;
    arg_sp158 = 0.0f;
    arg_sp15C = 1.0f;
    arg_sp160 = 0.0f;
    arg_sp164 = 0.0f;
    arg_sp168 = 0;
    arg_sp168 = 0;
    (s8) arg_sp168 = 0;
    arg_sp16C = 0;
    arg_sp170 = 3.4028235e38f;
    arg_sp174 = 0;
    arg_sp178 = NULL;
    arg_sp17C = -1;
    arg_sp180 = 0U;
    if (MKCollision_SweepSphereCollide(*((MKVector3 *) &arg_spA8), *((MKVector3 *) &arg_sp98), M2C_ERROR(/* unknown instruction: ps_mr $f1, $f31 */), (MKCollisionResult *) &arg_sp130, (MKCollisionMode) 2, (M2C_FIELD(this->unk370->unk110.unk460, s32 *, 0x18) & 0xFBFFFFFF) | 0x08000000) != 0) {
        if ((arg_sp180 != 0) && (arg_sp178 != NULL) && (var_r0_2687 = M2C_FIELD(arg_sp178, MKProp **, 8), ((var_r0_2687 == NULL) == 0))) {

        } else {
            var_r0_2687 = NULL;
        }
        if (var_r0_2687 != NULL) {
            if ((arg_sp180 != 0) && (arg_sp178 != NULL) && (var_r31_2701 = M2C_FIELD(arg_sp178, MKProp **, 8), ((var_r31_2701 == NULL) == 0))) {

            } else {
                var_r31_2701 = NULL;
            }
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            var_f4_2716 = 0.0f;
            arg_sp88 = arg_sp18;
            arg_sp20 = arg_sp138 - (f32) arg_spA0;
            arg_sp8C = 0.0f;
            arg_sp90 = (f64) arg_sp20;
            var_f5_2729 = ((f32) arg_sp90 * (f32) arg_sp90) + (((f32) arg_sp88 * (f32) arg_sp88) + (0.0f * 0.0f));
            if (var_f5_2729 > 0.000001f) {
                if (var_f5_2729 > 0.0f) {
                    temp_f1_2734 = __frsqrte(var_f5_2729);
                    temp_f1_2740 = 0.5 * temp_f1_2734 * -(((f64) var_f5_2729 * (temp_f1_2734 * temp_f1_2734)) - 3.0);
                    temp_f1_2744 = 0.5 * temp_f1_2740 * -(((f64) var_f5_2729 * (temp_f1_2740 * temp_f1_2740)) - 3.0);
                    var_f5_2729 = (f32) ((f64) var_f5_2729 * (0.5 * temp_f1_2744 * -(((f64) var_f5_2729 * (temp_f1_2744 * temp_f1_2744)) - 3.0)));
                } else if (var_f5_2729 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_2729 = __float_nan;
                } else {
                    arg_sp10 = var_f5_2729;
                    temp_r3_2763 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                    switch (temp_r3_2763) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_2773 = 1;
                        } else {
                            var_r0_2773 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
            arg_sp88 = (f32) arg_sp88 * var_f4_2716;
            arg_sp8C *= var_f4_2716;
            arg_sp90 = (f32) arg_sp90 * var_f4_2716;
            temp_r3_2806 = this->unk370;
            var_r4_2807 = temp_r3_2806->unk110.unk90C;
loop_35:
            temp_r0_2816 = *var_r4_2807;
            if (temp_r0_2816 == NULL) {
                var_r4_2807 = NULL;
            } else if (temp_r0_2816 == var_r31_2701) {

            } else {
                var_r4_2807 += 4;
                goto loop_35;
            }
            if (var_r4_2807 == NULL) {
                if (temp_r3_2806->MeleeDamageTarget(var_r31_2701, arg0, *((MKVector3 *) &arg_sp88), -1) != 0) {
                    return 1;
                }
                arg_spE4 = &__vt;
                arg_spB8 = 0x30;
                arg_spBC = 0;
                arg_spE4 = &__vt;
                arg_spC0 = 0.0f;
                arg_spC4 = 0.0f;
                arg_spC8 = 0.0f;
                arg_spD0 = 0;
                arg_spD4 = -1;
                arg_spD8 = 0;
                arg_spDC = 0;
                arg_spE0 = 0;
                arg_spB8 = 0x31;
                var_r31_2701->Message(&arg_spB8, -1, &__vt, 0);
                temp_r4_2861 = this->unk370;
                temp_r3_2863 = temp_r4_2861->unk110.unk90C - 4;
                temp_r4_2861->unk110.unk90C = temp_r3_2863;
                *temp_r3_2863 = var_r31_2701;
                goto block_41;
            }
            goto block_41;
        }
        goto block_41;
    }
block_41:
    arg_sp130 = 0.0f;
    arg_sp134 = 0.0f;
    arg_sp138 = 0.0f;
    arg_sp140 = 0.0f;
    arg_sp144 = 0.0f;
    arg_sp148 = 0.0f;
    arg_sp150 = 0.0f;
    arg_sp154 = 0.0f;
    arg_sp158 = 0.0f;
    arg_sp15C = 1.0f;
    arg_sp160 = 0.0f;
    arg_sp164 = 0.0f;
    arg_sp168 = 0;
    arg_sp168 = 0;
    (s8) arg_sp168 = 0;
    arg_sp16C = 0;
    arg_sp170 = 3.4028235e38f;
    arg_sp174 = 0;
    arg_sp178 = NULL;
    arg_sp17C = -1;
    arg_sp180 = 0U;
    if (((u8) this->unk390 == 0) && (MKCollision_SweepSphereCollide(*((MKVector3 *) &arg_spA8), *((MKVector3 *) &arg_sp98), 200.0f, (MKCollisionResult *) &arg_sp130, (MKCollisionMode) 4, 0) != 0)) {
        this->unk390 = 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp58'
void EarthBossArm::Extend() {
    Animation *temp_r4_2936;
    f32 temp_f6_3070;
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
    arg_sp58.GetNodeOrigin((s32) temp_r4_2936);
    arg_sp88 = arg_sp58;
    arg_sp90 = arg_sp60;
    MKModel_CalculateNodeWorldMatrix(this->unk4, temp_r30_2939, (Matrix *) &arg_spA0);
    if ((s32) this->unk364 > 0) {
        var_r3_2957 = this->unk36C + (this->unk368 * 0x10);
    } else {
        var_r3_2957 = NULL;
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp78 = arg_sp28;
    arg_sp30 = M2C_FIELD(var_r3_2957, f32 *, 8) - arg_spD8;
    arg_sp80 = (f64) arg_sp30;
    arg_sp48 = arg_sp28;
    arg_sp50 = (f64) arg_sp30;
    var_f4_2983 = ((f32) arg_sp80 * (f32) arg_sp80) + (((f32) arg_sp78 * (f32) arg_sp78) + (arg_sp7C * arg_sp7C));
    if (var_f4_2983 > 0.0f) {
        temp_f1_2986 = __frsqrte(var_f4_2983);
        temp_f1_2992 = 0.5 * temp_f1_2986 * -(((f64) var_f4_2983 * (temp_f1_2986 * temp_f1_2986)) - 3.0);
        temp_f1_2996 = 0.5 * temp_f1_2992 * -(((f64) var_f4_2983 * (temp_f1_2992 * temp_f1_2992)) - 3.0);
        var_f4_2983 = (f32) ((f64) var_f4_2983 * (0.5 * temp_f1_2996 * -(((f64) var_f4_2983 * (temp_f1_2996 * temp_f1_2996)) - 3.0)));
    } else if (var_f4_2983 < M2C_BITWISE(f32, 0.0)) {
        var_f4_2983 = __float_nan;
    } else {
        arg_sp10 = var_f4_2983;
        temp_r3_3015 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
        switch (temp_r3_3015) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                var_r0_3025 = 1;
            } else {
                var_r0_3025 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r6, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f2, $f1 */);
        temp_r0_3065 = var_r7_3049 - 1;
        temp_f6_3070 = (f32) arg_sp90 - M2C_FIELD(temp_r6_3060, f32 *, 0x78);
        var_r7_3049 += 1;
        var_r3_3053 += 0x80;
        arg_sp68 = arg_sp18;
        arg_sp20 = temp_f6_3070;
        arg_sp38 = arg_sp18;
        M2C_FIELD(temp_r6_3060, f32 *, 0xCC) = (f32) (((var_f4_2983 - 400.0f) * 0.25f * (f32) temp_r0_3065) + (f32) arg_sp68);
        arg_sp40 = (f64) arg_sp20;
        M2C_FIELD(temp_r6_3060, f32 *, 0xD0) = (f32) M2C_FIELD(temp_r6_3060, f32 *, 0xC8);
        M2C_FIELD(temp_r6_3060, f32 *, 0xD4) = 0.0f;
        arg_sp70 = (f64) arg_sp20;
        M2C_FIELD(temp_r6_3060, s8 *, 0xD8) = 0;
        var_ctr_3057 -= 1;
    } while (var_ctr_3057 != 0);
    this->unk38C = 4;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp5C'
void EarthBossArm::Aim(const MKVector3 &arg0) {
    Enemy *temp_r4_3136;
    Enemy *temp_r4_3141;
    f32 temp_f2_3183;
    f32 temp_f4_3181;
    this->unk38C = 3;
    this->unk378 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk380 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk368 = 0;
    this->unk364 = 0;
    M2C_STRUCT_COPY((s32) &arg_sp5C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    arg_sp60.Inverse((Matrix *) &arg_sp60);
    temp_r4_3136 = this->unk370;
    MKModel_CalculateNodeWorldMatrix(temp_r4_3136->unk4, temp_r4_3136->unkCD0, (Matrix *) &arg_spE0);
    temp_r4_3141 = this->unk370;
    MKModel_CalculateNodeWorldMatrix(temp_r4_3141->unk4, temp_r4_3141->unkCD4, (Matrix *) &arg_spA0);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp30 = arg_sp10;
    arg_sp18 = arg_spD8 - arg_sp118;
    arg_sp38 = (f64) arg_sp18;
    Normalise(*((MKVector3 *) &arg_sp40));
    temp_f4_3181 = (arg_sp48 * arg_sp80) + ((arg_sp40 * arg_sp60) + (arg_sp44 * arg_sp70));
    temp_f2_3183 = (arg_sp48 * arg_sp84) + ((arg_sp40 * arg_sp64) + (arg_sp44 * arg_sp74));
    arg_sp20 = temp_f4_3181;
    arg_sp24 = temp_f2_3183;
    arg_sp28 = (arg_sp48 * arg_sp88) + ((arg_sp40 * arg_sp68) + (arg_sp44 * arg_sp78));
    this->unkE0 = (f64) arg_sp20;
    this->unkE8 = (f64) arg_sp28;
    arg_sp50 = (f64) arg_sp20;
    arg_sp58 = (f64) arg_sp28;
    Enable((f64) arg_sp20, temp_f2_3183, arg_sp84, temp_f4_3181, arg_sp80, arg_sp40, arg_sp48);
    this->unk370->ShowFist(0U);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'Animation' to
void EarthBossArm::Retract() {
    Animation sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
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
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r5, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f1, $f2, $f1 */);
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
        KDSound_Play3d(GS_SSAlert, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spCC'
void EarthBossArm::SetRetracted() {
    Animation *temp_r28_3296;
    Enemy *temp_r4_3311;
    Enemy *temp_r4_3316;
    s32 var_r27_3337;
    s32 var_r30_3339;
    void *temp_r29_3370;
    temp_r28_3296 = MKModel_GetAnimation(this->unk4);
    M2C_STRUCT_COPY((s32) &arg_spCC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    arg_spD0.Inverse((Matrix *) &arg_spD0);
    temp_r4_3311 = this->unk370;
    MKModel_CalculateNodeWorldPosition(temp_r4_3311->unk4, temp_r4_3311->unkCD0, (MKVector3 *) &arg_sp90);
    temp_r4_3316 = this->unk370;
    MKModel_CalculateNodeWorldPosition(temp_r4_3316->unk4, temp_r4_3316->unkCD4, (MKVector3 *) &arg_spA0);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp60 = arg_sp10;
    arg_sp18 = arg_spA8 - arg_sp98;
    arg_sp68 = (f64) arg_sp18;
    Normalise(*((MKVector3 *) &arg_sp70));
    var_r27_3337 = 2;
    var_r30_3339 = 0x100;
    arg_sp30 = (arg_sp78 * arg_spF0) + ((arg_sp70 * arg_spD0) + (arg_sp74 * arg_spE0));
    arg_sp34 = (arg_sp78 * arg_spF4) + ((arg_sp70 * arg_spD4) + (arg_sp74 * arg_spE4));
    arg_sp38 = (arg_sp78 * arg_spF8) + ((arg_sp70 * arg_spD8) + (arg_sp74 * arg_spE8));
    this->unkE0 = (f64) arg_sp30;
    arg_sp80 = (f64) arg_sp30;
    arg_sp88 = (f64) arg_sp38;
    this->unkE8 = (f64) arg_sp38;
    do {
        temp_r29_3370 = this + var_r30_3339;
        temp_r28_3296->GetNodeParentIndex(M2C_FIELD(temp_r29_3370, s32 *, 0xC4));
        arg_sp50.GetNodeOrigin((s32) temp_r28_3296);
        arg_spC0 = arg_sp50;
        arg_spC8 = arg_sp58;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        var_r27_3337 += 1;
        var_r30_3339 += 0x80;
        arg_spB0 = arg_sp20;
        arg_sp40 = arg_sp20;
        M2C_FIELD(temp_r29_3370, f32 *, 0xC8) = (f32) arg_spB0;
        arg_sp28 = (f32) arg_spC8 - M2C_FIELD(temp_r29_3370, f32 *, 0x78);
        M2C_FIELD(temp_r29_3370, f32 *, 0xCC) = (f32) arg_spB0;
        M2C_FIELD(temp_r29_3370, f32 *, 0xD4) = 0.0f;
        arg_sp48 = (f64) arg_sp28;
        arg_spB8 = (f64) arg_sp28;
        M2C_FIELD(temp_r29_3370, s8 *, 0xD8) = 1;
    } while (var_r27_3337 <= 5);
    this->unk38C = 0;
    this->unk390 = 0;
    Disable();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void EarthBossArm::UpdateExtensionBone(MKDynamicBone *arg0, void *arg1) {
    Animation *temp_r3_3437;
    temp_r3_3437 = MKModel_GetAnimation(M2C_BITWISE(MKModel *, this->unk24));
    arg_sp18 = 0.0f;
    arg_sp10 = arg0->unk68;
    arg_sp14 = 0.0f;
    arg_sp28 = (f64) arg_sp18;
    arg_sp20 = (f64) arg_sp10;
    M2C_STRUCT_COPY((s32) &arg_sp2C + 4, (s32) (&identity - 4) + 4, 0x40);
    arg_sp60 = (f32) arg_sp20;
    arg_sp64 = arg_sp24;
    arg_sp68 = (f32) arg_sp28;
    arg_sp6C = 1.0f;
    temp_r3_3437->SetCustomMatrix(arg0->unk64, (Matrix *) &arg_sp30, (AnimationMatrixPosition) 4, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp1CC'
void EarthBossArm::UpdateElbowBone(MKDynamicBone *arg0, void *arg1) {
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
    M2C_STRUCT_COPY((s32) &arg_sp1CC + 4, MKModel_GetWorldMatrix(M2C_BITWISE(MKModel *, this->unk24)) - 4 + 4, 0x40);
    M2C_STRUCT_COPY((s32) &arg_sp18C + 4, (s32) &arg_sp1CC + 4, 0x40);
    arg_sp190.Inverse((Matrix *) &arg_sp190);
    temp_r29_3519 = arg0->unk64;
    ((Animation *) (MKModel_GetAnimation(M2C_BITWISE(MKModel *, this->unk24))))->SetCustomMatrix(temp_r29_3519, NULL, (AnimationMatrixPosition) 2, 0U);
    temp_r29_3527 = arg0->unk64;
    temp_r3_3529 = MKModel_GetAnimation(M2C_BITWISE(MKModel *, this->unk24));
    arg_sp10 = (s16) temp_r29_3527;
    temp_r3_3529->CalculateMatrices((Matrix *) &arg_sp210, 1, &arg_sp10, NULL);
    arg_sp250.Multiply((Matrix *) &arg_sp210, (Matrix *) &arg_sp1D0);
    temp_f3_3540 = arg0->unk14;
    temp_f6_3549 = arg0->unk10;
    temp_f7_3555 = arg0->unk18;
    arg_sp98 = (temp_f7_3555 * arg_sp270) + ((temp_f6_3549 * arg_sp250) + (temp_f3_3540 * arg_sp260));
    arg_sp9C = (temp_f7_3555 * arg_sp274) + ((temp_f6_3549 * arg_sp254) + (temp_f3_3540 * arg_sp264));
    arg_spA0 = (temp_f7_3555 * arg_sp278) + ((temp_f6_3549 * arg_sp258) + (temp_f3_3540 * arg_sp268));
    arg_sp138 = (f64) arg_sp98;
    arg_sp140 = (f64) arg_spA0;
    arg_sp250.Translate((Matrix *) &arg_sp250, *((MKVector3 *) &arg_sp138));
    arg_sp88 = (arg_sp268 * arg_sp1B0) + ((arg_sp260 * arg_sp190) + (arg_sp264 * arg_sp1A0));
    arg_sp8C = (arg_sp268 * arg_sp1B4) + ((arg_sp260 * arg_sp194) + (arg_sp264 * arg_sp1A4));
    arg_sp90 = (arg_sp268 * arg_sp1B8) + ((arg_sp260 * arg_sp198) + (arg_sp264 * arg_sp1A8));
    arg_sp118 = (f64) arg_sp88;
    arg_sp120 = (f64) arg_sp90;
    arg_sp128 = M2C_FIELD(arg0, f64 *, 0);
    arg_sp130 = M2C_FIELD(arg0, f64 *, 8);
    arg_sp78 = -(f32) arg_sp118;
    arg_sp7C = -arg_sp11C;
    arg_sp80 = -(f32) arg_sp120;
    arg_spE8 = (f64) arg_sp78;
    arg_spF0 = (f64) arg_sp80;
    arg_sp6C = ((f32) arg_spF0 * (f32) arg_sp128) - ((f32) arg_spE8 * (f32) arg_sp130);
    arg_sp68 = (arg_spEC * (f32) arg_sp130) - ((f32) arg_spF0 * arg_sp12C);
    arg_sp70 = ((f32) arg_spE8 * arg_sp12C) - (arg_spEC * (f32) arg_sp128);
    arg_spF8 = (f64) arg_sp68;
    arg_sp100 = (f64) arg_sp70;
    var_f4_3643 = ((f32) arg_sp100 * (f32) arg_sp100) + (((f32) arg_spF8 * (f32) arg_spF8) + (arg_spFC * arg_spFC));
    if (var_f4_3643 > 1e-12f) {
        if (var_f4_3643 > 0.0f) {
            temp_f1_3649 = __frsqrte(var_f4_3643);
            temp_f1_3655 = 0.5 * temp_f1_3649 * -(((f64) var_f4_3643 * (temp_f1_3649 * temp_f1_3649)) - 3.0);
            temp_f1_3659 = 0.5 * temp_f1_3655 * -(((f64) var_f4_3643 * (temp_f1_3655 * temp_f1_3655)) - 3.0);
            var_f4_3643 = (f32) ((f64) var_f4_3643 * (0.5 * temp_f1_3659 * -(((f64) var_f4_3643 * (temp_f1_3659 * temp_f1_3659)) - 3.0)));
        } else if (var_f4_3643 < M2C_BITWISE(f32, 0.0)) {
            var_f4_3643 = __float_nan;
        } else {
            arg_sp14 = var_f4_3643;
            temp_r3_3678 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
            switch (temp_r3_3678) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                    var_r0_3688 = 1;
                } else {
                    var_r0_3688 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
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
    arg_sp60 = (f32) arg_sp100 * var_f2_3710;
    arg_sp58 = (f32) arg_spF8 * var_f2_3710;
    arg_sp5C = arg_spFC * var_f2_3710;
    arg_sp110 = (f64) arg_sp60;
    arg_sp108 = (f64) arg_sp58;
    arg_sp20 = -(f32) arg_sp130;
    arg_sp30 = -(f32) arg_sp110;
    arg_spD0 = (f64) arg_sp20;
    arg_spC0 = (f64) arg_sp30;
    arg_sp28 = -(f32) arg_sp108;
    arg_sp2C = -arg_sp10C;
    arg_sp18 = -(f32) arg_sp128;
    arg_spB8 = (f64) arg_sp28;
    arg_sp1C = -arg_sp12C;
    arg_spC8 = (f64) arg_sp18;
    arg_sp210 = (f32) arg_sp128;
    arg_sp214 = arg_sp12C;
    arg_sp218 = (f32) arg_sp130;
    arg_sp50 = ((f32) arg_spB8 * arg_spCC) - (arg_spBC * (f32) arg_spC8);
    arg_sp48 = (arg_spBC * (f32) arg_spD0) - ((f32) arg_spC0 * arg_spCC);
    arg_sp4C = ((f32) arg_spC0 * (f32) arg_spC8) - ((f32) arg_spB8 * (f32) arg_spD0);
    arg_sp120 = (f64) arg_sp50;
    arg_sp118 = (f64) arg_sp48;
    arg_spD8 = (f64) arg_sp48;
    arg_spE0 = (f64) arg_sp50;
    arg_sp21C = 0.0f;
    arg_sp220 = (f32) arg_sp118;
    arg_sp224 = arg_sp11C;
    arg_sp228 = (f32) arg_sp120;
    arg_sp22C = 0.0f;
    arg_sp230 = (f32) arg_sp108;
    arg_sp234 = arg_sp10C;
    arg_sp238 = (f32) arg_sp110;
    arg_sp23C = 0.0f;
    M2C_STRUCT_COPY((s32) &arg_sp14C + 4, (s32) (&identity - 4) + 4, 0x40);
    arg_sp38 = -arg0->unk10;
    arg_sp3C = -arg0->unk14;
    arg_sp40 = -arg0->unk18;
    arg_spA8 = (f64) arg_sp38;
    arg_spB0 = (f64) arg_sp40;
    arg_sp150.Translate((Matrix *) &arg_sp150, *((MKVector3 *) &arg_spA8));
    arg_sp210.Multiply((Matrix *) &arg_sp150, (Matrix *) &arg_sp210);
    arg_sp210.Translate((Matrix *) &arg_sp210, *((MKVector3 *) &arg0->unk10));
    temp_r29_3826 = arg0->unk64;
    ((Animation *) (MKModel_GetAnimation(M2C_BITWISE(MKModel *, this->unk24))))->SetCustomMatrix(temp_r29_3826, (Matrix *) &arg_sp210, (AnimationMatrixPosition) 4, 0U);
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
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if ((M2C_FIELD(temp_r5_3857, f32 *, 0xD4) == 1.0f) || ((f32) fabs(M2C_FIELD(temp_r5_3857, f32 *, 0xCC) - M2C_FIELD(temp_r5_3857, f32 *, 0xC8)) < 0.01f)) {
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
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if ((M2C_FIELD(temp_r3_3926, f32 *, 0xD4) == 1.0f) || ((f32) fabs(M2C_FIELD(temp_r3_3926, f32 *, 0xCC) - M2C_FIELD(temp_r3_3926, f32 *, 0xC8)) < 0.01f)) {
                M2C_FIELD(temp_r3_3926, u8 *, 0xD8) = 1U;
                if (((s32) this->unk38C == 4) && ((u8) this->unk390 != 0)) {
                    temp_f31_3987 = ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.05f, 0.4f, 0.2f, this->unk8 + 0x30, 80.0f, 0, 4.0f, 0U);
                    arg_sp74 = 0;
                    MKVector(0.05f, 0.8f, 0.05f);
                    arg_sp50.operator*(500.0f);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                    arg_sp70 = 0x417;
                    arg_sp78 = arg_sp10;
                    arg_sp18 = arg_sp58 * temp_f31_3987;
                    arg_sp88 = 1;
                    arg_sp80 = (f64) arg_sp18;
                    arg_sp60 = arg_sp10;
                    arg_sp68 = (f64) arg_sp18;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp70, arg_sp10);
                    KDSound_Play3d(GS_SSAttack3, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                    MKModel_CalculateNodeWorldMatrix(this->unk4, this->unk344, (Matrix *) &arg_sp90);
                    arg_sp20 = 0.0f;
                    arg_sp24 = 1.0f;
                    arg_sp28 = 0.0f;
                    arg_sp2C = 1.0f;
                    arg_sp30 = (f64) arg_sp20;
                    arg_sp38 = (f64) arg_sp28;
                    this->unk370->unkCC4->Trigger(*((MKVector3 *) &arg_spC0), 0.75f, 1U, (MKVector4) &arg_sp30);
                }
                this->unk38C = 5;
            }
        }
        var_r29_3923 += 1;
        var_r27_3924 += 0x80;
    } while (var_r29_3923 <= 5);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk7A8'
void EarthBossArm::UpdateTarget() {
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
    f64 temp_f1_4561;
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
    if (((u8) temp_r3_4087->unk110.unk7A8 == 2) || (temp_r3_4087->unk110.unk7A0.Get() != NULL)) {
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
        arg_sp198.GetPos();
        this->unk378 = arg_sp198;
        this->unk380 = arg_sp1A0;
        temp_r4_4133 = this->unk370;
        MKModel_CalculateNodeWorldPosition(temp_r4_4133->unk4, temp_r4_4133->unkCD4, (MKVector3 *) &arg_sp1E8);
        arg_sp188.GetDir();
        temp_r3_4141 = this->unk370;
        temp_f29_4151 = (temp_r3_4141->unkC8 * arg_sp190) + ((temp_r3_4141->unkC0 * arg_sp188) + (temp_r3_4141->unkC4 * arg_sp18C));
        if (temp_f29_4151 < _table_sinf(2.6179938f)) {
            temp_r4_4155 = this->unk370;
            temp_f5_4161 = temp_r4_4155->unkC0;
            temp_f3_4163 = temp_r4_4155->unkC8;
            temp_f2_4167 = temp_r4_4155->unkC4;
            arg_spB0 = (up.unk0 * temp_f2_4167) - (up.unk4 * temp_f5_4161);
            arg_spAC = (up.unk8 * temp_f5_4161) - (up.unk0 * temp_f3_4163);
            arg_spA8 = (up.unk4 * temp_f3_4163) - (up.unk8 * temp_f2_4167);
            arg_sp1E0 = (f64) arg_spB0;
            arg_sp1D8 = (f64) arg_spA8;
            M2C_STRUCT_COPY((s32) &arg_sp1FC + 4, (s32) (&identity - 4) + 4, 0x40);
            arg_sp200 = (f32) arg_sp1D8;
            arg_sp204 = arg_sp1DC;
            arg_sp208 = (f32) arg_sp1E0;
            arg_sp20C = 0.0f;
            temp_r5_4199 = this->unk370;
            arg_sp220 = temp_r5_4199->unkC0;
            arg_sp224 = temp_r5_4199->unkC4;
            arg_sp228 = temp_r5_4199->unkC8;
            arg_sp22C = 0.0f;
            arg_sp178.GetDir();
            if (((arg_sp180 * (f32) arg_sp1E0) + ((arg_sp178 * (f32) arg_sp1D8) + (arg_sp17C * arg_sp1DC))) > 0.0f) {
                arg_sp200.RotateYaw((Matrix *) &arg_sp200, -1.0471976f);
            } else {
                arg_sp200.RotateYaw((Matrix *) &arg_sp200, 1.0471976f);
            }
            arg_sp148.operator*(this->unk370->unk110.unk760.GetDist());
            arg_sp158.GetPos();
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            this->unk378 = arg_sp48;
            arg_sp50 = arg_sp160 + arg_sp150;
            arg_sp80 = 0.0f;
            this->unk380 = (f64) arg_sp50;
            arg_sp78 = 0.0f;
            arg_sp7C = 500.0f;
            arg_sp240 = 0.0f;
            arg_sp244 = 0.0f;
            arg_sp248 = 0.0f;
            arg_sp250 = 0.0f;
            arg_sp254 = 0.0f;
            arg_sp258 = 0.0f;
            arg_sp260 = 0.0f;
            arg_sp264 = 0.0f;
            arg_sp268 = 0.0f;
            arg_sp26C = 1.0f;
            arg_sp270 = 0.0f;
            arg_sp274 = 0.0f;
            arg_sp278 = 0;
            arg_sp278 = 0;
            (s8) arg_sp278 = 0;
            arg_sp27C = 0;
            arg_sp280 = 3.4028235e38f;
            arg_sp284 = 0;
            arg_sp288 = NULL;
            arg_sp28C = -1;
            arg_sp290 = 0U;
            arg_sp108 = (f64) arg_sp78;
            arg_sp168 = arg_sp48;
            arg_sp170 = (f64) arg_sp50;
            arg_sp110 = (f64) arg_sp80;
            M2C_ERROR(/* unknown instruction: psq_lx $f5, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f0 */);
            arg_spA0 = 0.0f;
            temp_f4_4298 = (f32) M2C_FIELD(this, f64 *, 0x380);
            arg_sp98 = 0.0f;
            arg_sp9C = 300.0f;
            arg_sp70 = temp_f4_4298 - (f32) arg_sp110;
            arg_sp128 = (f64) arg_sp98;
            arg_sp118 = arg_sp68;
            arg_sp120 = (f64) arg_sp70;
            arg_sp130 = (f64) arg_spA0;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
            arg_sp90 = temp_f4_4298 + (f32) arg_sp130;
            arg_sp138 = arg_sp88;
            arg_sp140 = (f64) arg_sp90;
            if (MKCollision_RayCollide(*((MKVector3 *) &arg_sp138), *((MKVector3 *) &arg_sp118), (MKCollisionResult *) &arg_sp240, (MKCollisionMode) 4, 0) != 0) {
                M2C_FIELD(this, f32 *, 0x37C) = arg_sp244;
            }
        }
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp1C8 = arg_sp58;
        arg_sp60 = (f32) M2C_FIELD(this, f64 *, 0x380) - arg_sp1F0;
        arg_sp1D0 = (f64) arg_sp60;
        var_f29_4354 = ((f32) arg_sp1D0 * (f32) arg_sp1D0) + (((f32) arg_sp1C8 * (f32) arg_sp1C8) + (arg_sp1CC * arg_sp1CC));
        if (var_f29_4354 > 0.000001f) {
            if (var_f29_4354 > 0.0f) {
                temp_f1_4360 = __frsqrte(var_f29_4354);
                temp_f1_4366 = 0.5 * temp_f1_4360 * -(((f64) var_f29_4354 * (temp_f1_4360 * temp_f1_4360)) - 3.0);
                temp_f1_4370 = 0.5 * temp_f1_4366 * -(((f64) var_f29_4354 * (temp_f1_4366 * temp_f1_4366)) - 3.0);
                var_f29_4354 = (f32) ((f64) var_f29_4354 * (0.5 * temp_f1_4370 * -(((f64) var_f29_4354 * (temp_f1_4370 * temp_f1_4370)) - 3.0)));
            } else if (var_f29_4354 < M2C_BITWISE(f32, 0.0)) {
                var_f29_4354 = __float_nan;
            } else {
                arg_sp10 = var_f29_4354;
                temp_r3_4389 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_4389) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_4399 = 1;
                    } else {
                        var_r0_4399 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
        var_r28_4434 = 0;
        arg_sp1C8 = (f32) arg_sp1C8 * var_f8_4421;
        arg_sp1CC *= var_f8_4421;
        arg_sp1D0 = (f32) arg_sp1D0 * var_f8_4421;
        arg_sp240 = 0.0f;
        arg_sp244 = 0.0f;
        arg_sp248 = 0.0f;
        arg_sp250 = 0.0f;
        arg_sp254 = 0.0f;
        arg_sp258 = 0.0f;
        arg_sp260 = 0.0f;
        arg_sp264 = 0.0f;
        arg_sp268 = 0.0f;
        arg_sp26C = 1.0f;
        arg_sp270 = 0.0f;
        arg_sp274 = 0.0f;
        arg_sp278 = 0;
        arg_sp278 = 0;
        (s8) arg_sp278 = 0;
        arg_sp27C = 0;
        arg_sp280 = 3.4028235e38f;
        arg_sp284 = 0;
        arg_sp288 = NULL;
        arg_sp28C = -1;
        arg_sp290 = 0U;
        arg_sp18 = arg_sp1E8;
        arg_sp20 = (f64) arg_sp1F0;
        arg_sp1B8 = arg_sp1E8;
        arg_sp1C0 = (f64) arg_sp1F0;
        arg_sp1A8 = arg_sp1E8;
        arg_sp1B0 = (f64) arg_sp1F0;
loop_49:
        if (var_r28_4434 < (s32) (var_f29_4354 / 500.0f)) {
            arg_spE8.operator*((f32) var_r28_4434 * 500.0f);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spF8 = arg_sp38;
            arg_sp40 = arg_sp1F0 + arg_spF0;
            var_f1_4508 = (f32) (var_r28_4434 + 1) * 500.0f;
            arg_sp1B8 = arg_sp38;
            arg_sp100 = (f64) arg_sp40;
            arg_sp1C0 = (f64) arg_sp40;
            if (var_f1_4508 < var_f29_4354) {

            } else {
                var_f1_4508 = var_f29_4354;
            }
            arg_spC8.operator*(var_f1_4508);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spD8 = arg_sp28;
            arg_sp30 = arg_sp1F0 + arg_spD0;
            arg_sp1A8 = arg_sp28;
            arg_spE0 = (f64) arg_sp30;
            arg_sp1B0 = (f64) arg_sp30;
            if (MKCollision_SweepSphereCollide(*((MKVector3 *) &arg_sp1B8), *((MKVector3 *) &arg_sp1A8), 200.0f, (MKCollisionResult *) &arg_sp240, (MKCollisionMode) 7, 0x0C000000) != 0) {
                if ((arg_sp290 != 0) && (arg_sp288 != NULL) && (var_r0_4548 = M2C_FIELD(arg_sp288, u32 *, 8), ((var_r0_4548 == 0U) == 0))) {

                } else {
                    var_r0_4548 = 0U;
                }
                if (var_r0_4548 != 0U) {
                    temp_r3_4559 = M2C_FIELD(arg_sp240.GetProp(), void **, 8);
                    temp_f1_4561 = M2C_FIELD(temp_r3_4559, f64 *, 0x30);
                    temp_f0_4562 = M2C_FIELD(temp_r3_4559, f64 *, 0x38);
                    arg_spB8 = temp_f1_4561;
                    this->unk378 = temp_f1_4561;
                    this->unk380 = temp_f0_4562;
                    this->unk368 = 0;
                    arg_spC0 = temp_f0_4562;
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

#if 0 // DRAFT: undefined identifier 'unkCCC'
void EarthBossArm::Update() {
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
    MKModel_CalculateNodeWorldMatrix(temp_r4_4645->unk4, temp_r4_4645->unkCCC, (Matrix *) &arg_sp350);
    temp_r4_4650 = this->unk370;
    MKModel_CalculateNodeWorldMatrix(temp_r4_4650->unk4, temp_r4_4650->unkCD0, (Matrix *) &arg_sp310);
    temp_r4_4655 = this->unk370;
    MKModel_CalculateNodeWorldMatrix(temp_r4_4655->unk4, temp_r4_4655->unkCD4, (Matrix *) &arg_sp2D0);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp1D0 = arg_spF0;
    arg_spF8 = arg_sp348 - arg_sp388;
    arg_sp1D8 = (f64) arg_spF8;
    var_f4_4681 = ((f32) arg_sp1D8 * (f32) arg_sp1D8) + (((f32) arg_sp1D0 * (f32) arg_sp1D0) + (arg_sp1D4 * arg_sp1D4));
    if (var_f4_4681 > 1e-12f) {
        if (var_f4_4681 > 0.0f) {
            temp_f1_4687 = __frsqrte(var_f4_4681);
            temp_f1_4693 = 0.5 * temp_f1_4687 * -(((f64) var_f4_4681 * (temp_f1_4687 * temp_f1_4687)) - 3.0);
            temp_f1_4697 = 0.5 * temp_f1_4693 * -(((f64) var_f4_4681 * (temp_f1_4693 * temp_f1_4693)) - 3.0);
            var_f4_4681 = (f32) ((f64) var_f4_4681 * (0.5 * temp_f1_4697 * -(((f64) var_f4_4681 * (temp_f1_4697 * temp_f1_4697)) - 3.0)));
        } else if (var_f4_4681 < M2C_BITWISE(f32, 0.0)) {
            var_f4_4681 = __float_nan;
        } else {
            arg_sp18 = var_f4_4681;
            temp_r3_4716 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
            switch (temp_r3_4716) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                    var_r0_4726 = 1;
                } else {
                    var_r0_4726 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
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
    arg_spE4 = arg_sp1D4 * var_f3_4748;
    arg_spE0 = (f32) arg_sp1D0 * var_f3_4748;
    arg_spE8 = (f32) arg_sp1D8 * var_f3_4748;
    arg_sp200 = (f64) arg_spE0;
    arg_sp208 = (f64) arg_spE8;
    M2C_STRUCT_COPY((s32) &arg_sp38C + 4, (s32) &arg_sp34C + 4, 0x40);
    arg_sp390 = (f32) arg_sp200;
    arg_sp394 = arg_sp204;
    arg_sp90 = (arg_sp204 * arg_sp3B8) - ((f32) arg_sp208 * arg_sp3B4);
    arg_sp94 = ((f32) arg_sp208 * arg_sp3B0) - ((f32) arg_sp200 * arg_sp3B8);
    arg_sp98 = ((f32) arg_sp200 * arg_sp3B4) - (arg_sp204 * arg_sp3B0);
    arg_sp1C0 = (f64) arg_sp90;
    arg_sp1C8 = (f64) arg_sp98;
    arg_sp398 = (f32) arg_sp208;
    arg_sp39C = 0.0f;
    arg_sp88 = ((f32) arg_sp200 * arg_sp1C4) - (arg_sp204 * (f32) arg_sp1C0);
    arg_sp80 = (arg_sp204 * (f32) arg_sp1C8) - ((f32) arg_sp208 * arg_sp1C4);
    arg_sp84 = ((f32) arg_sp208 * (f32) arg_sp1C0) - ((f32) arg_sp200 * (f32) arg_sp1C8);
    arg_sp1B8 = (f64) arg_sp88;
    arg_sp1B0 = (f64) arg_sp80;
    arg_sp3A0 = (f32) arg_sp1C0;
    arg_sp3A4 = arg_sp1C4;
    arg_sp3A8 = (f32) arg_sp1C8;
    arg_sp3AC = 0.0f;
    arg_sp3B0 = (f32) arg_sp1B0;
    arg_sp3B4 = arg_sp1B4;
    arg_sp3B8 = (f32) arg_sp1B8;
    arg_sp3BC = 0.0f;
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp390));
    temp_r0_4828 = this->unk38C;
    switch (temp_r0_4828) {                         /* switch 2; irregular */
    case 3:                                         /* switch 2 */
        UpdateTarget();
        /* fallthrough */
    case 4:                                         /* switch 2 */
        temp_r0_4843 = this->unk364;
        arg_sp1F0 = this->unk378;
        arg_sp1F8 = this->unk380;
        if (temp_r0_4843 != 0) {
            if (temp_r0_4843 > 0) {
                var_r3_4854 = this->unk36C + (this->unk368 * 0x10);
            } else {
                var_r3_4854 = NULL;
            }
            arg_sp1F0 = M2C_FIELD(var_r3_4854, f64 *, 0);
            arg_sp1F8 = M2C_FIELD(var_r3_4854, f64 *, 8);
        }
        if ((s32) this->unk38C == 2) {
            arg_sp1F0 = arg_sp300;
            arg_sp1F8 = arg_sp308;
        }
        M2C_STRUCT_COPY((s32) &arg_sp28C + 4, (s32) &arg_sp38C + 4, 0x40);
        arg_sp290.Inverse((Matrix *) &arg_sp290);
        MKModel_CalculateNodeWorldMatrix(this->unk4, this->unk144, (Matrix *) &arg_sp250);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp180 = arg_spD0;
        arg_spD8 = (f32) arg_sp1F8 - arg_sp288;
        arg_sp188 = (f64) arg_spD8;
        var_f4_4909 = ((f32) arg_sp188 * (f32) arg_sp188) + (((f32) arg_sp180 * (f32) arg_sp180) + (arg_sp184 * arg_sp184));
        if (var_f4_4909 > 1e-12f) {
            if (var_f4_4909 > 0.0f) {
                temp_f1_4915 = __frsqrte(var_f4_4909);
                temp_f1_4921 = 0.5 * temp_f1_4915 * -(((f64) var_f4_4909 * (temp_f1_4915 * temp_f1_4915)) - 3.0);
                temp_f1_4925 = 0.5 * temp_f1_4921 * -(((f64) var_f4_4909 * (temp_f1_4921 * temp_f1_4921)) - 3.0);
                var_f4_4909 = (f32) ((f64) var_f4_4909 * (0.5 * temp_f1_4925 * -(((f64) var_f4_4909 * (temp_f1_4925 * temp_f1_4925)) - 3.0)));
            } else if (var_f4_4909 < M2C_BITWISE(f32, 0.0)) {
                var_f4_4909 = __float_nan;
            } else {
                arg_sp14 = var_f4_4909;
                temp_r3_4944 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                switch (temp_r3_4944) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_4954 = 1;
                    } else {
                        var_r0_4954 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
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
        arg_spB4 = arg_sp184 * var_f4_4976;
        arg_spB0 = (f32) arg_sp180 * var_f4_4976;
        arg_spB8 = (f32) arg_sp188 * var_f4_4976;
        arg_sp190 = (f64) arg_spB0;
        arg_sp198 = (f64) arg_spB8;
        arg_spC0 = ((f32) arg_sp198 * arg_sp2B0) + (((f32) arg_sp190 * arg_sp290) + (arg_sp194 * arg_sp2A0));
        arg_spC4 = ((f32) arg_sp198 * arg_sp2B4) + (((f32) arg_sp190 * arg_sp294) + (arg_sp194 * arg_sp2A4));
        arg_spC8 = ((f32) arg_sp198 * arg_sp2B8) + (((f32) arg_sp190 * arg_sp298) + (arg_sp194 * arg_sp2A8));
        arg_sp1A0 = (f64) arg_spC0;
        arg_sp1A8 = (f64) arg_spC8;
        var_f4_5027 = ((f32) arg_sp1A8 * (f32) arg_sp1A8) + (((f32) arg_sp1A0 * (f32) arg_sp1A0) + (arg_sp1A4 * arg_sp1A4));
        if (var_f4_5027 > 1e-12f) {
            if (var_f4_5027 > 0.0f) {
                temp_f1_5033 = __frsqrte(var_f4_5027);
                temp_f1_5039 = 0.5 * temp_f1_5033 * -(((f64) var_f4_5027 * (temp_f1_5033 * temp_f1_5033)) - 3.0);
                temp_f1_5043 = 0.5 * temp_f1_5039 * -(((f64) var_f4_5027 * (temp_f1_5039 * temp_f1_5039)) - 3.0);
                var_f4_5027 = (f32) ((f64) var_f4_5027 * (0.5 * temp_f1_5043 * -(((f64) var_f4_5027 * (temp_f1_5043 * temp_f1_5043)) - 3.0)));
            } else if (var_f4_5027 < M2C_BITWISE(f32, 0.0)) {
                var_f4_5027 = __float_nan;
            } else {
                arg_sp10 = var_f4_5027;
                temp_r3_5062 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_5062) {             /* switch 4; irregular */
                case 0x7F800000:                    /* switch 4 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_5072 = 1;
                    } else {
                        var_r0_5072 = 2;
                    }
                    break;
                case 0x0:                           /* switch 4 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
        arg_spA8 = (f32) arg_sp1A8 * var_f9_5094;
        arg_sp70 = (arg_sp268 * arg_sp2B0) + ((arg_sp260 * arg_sp290) + (arg_sp264 * arg_sp2A0));
        arg_sp74 = (arg_sp268 * arg_sp2B4) + ((arg_sp260 * arg_sp294) + (arg_sp264 * arg_sp2A4));
        arg_sp78 = (arg_sp268 * arg_sp2B8) + ((arg_sp260 * arg_sp298) + (arg_sp264 * arg_sp2A8));
        arg_sp170 = (f64) arg_sp70;
        arg_sp178 = (f64) arg_sp78;
        arg_spA0 = (f32) arg_sp1A0 * var_f9_5094;
        arg_spA4 = arg_sp1A4 * var_f9_5094;
        arg_sp68 = -(f32) arg_sp178;
        arg_sp1E0 = (f64) arg_spA0;
        arg_sp1E8 = (f64) arg_spA8;
        temp_f10_5149 = M2C_FIELD(this, f32 *, 0xE0);
        arg_sp148 = (f64) arg_sp68;
        arg_sp210 = temp_f10_5149;
        temp_f9_5153 = M2C_FIELD(this, f32 *, 0xE4);
        arg_sp60 = -(f32) arg_sp170;
        arg_sp64 = -arg_sp174;
        arg_sp214 = temp_f9_5153;
        temp_f8_5159 = M2C_FIELD(this, f32 *, 0xE8);
        arg_sp140 = (f64) arg_sp60;
        arg_sp218 = temp_f8_5159;
        arg_sp21C = 0.0f;
        arg_sp220 = (f32) arg_sp170;
        arg_sp58 = ((f32) arg_sp140 * temp_f9_5153) - (arg_sp144 * temp_f10_5149);
        arg_sp50 = (arg_sp144 * temp_f8_5159) - ((f32) arg_sp148 * temp_f9_5153);
        arg_sp54 = ((f32) arg_sp148 * temp_f10_5149) - ((f32) arg_sp140 * temp_f8_5159);
        arg_sp224 = arg_sp174;
        arg_sp228 = (f32) arg_sp178;
        arg_sp22C = 0.0f;
        arg_sp150 = (f64) arg_sp50;
        arg_sp158 = (f64) arg_sp58;
        Normalise(*((MKVector3 *) &arg_sp160));
        arg_sp230 = arg_sp160;
        arg_sp234 = arg_sp164;
        arg_sp238 = arg_sp168;
        arg_sp23C = 0.0f;
        arg_sp210.ZAxis3();
        arg_sp30 = -*M2C_ERROR(/* Read from unset register $r3 */);
        arg_sp34 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
        arg_sp38 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
        arg_sp110 = (f64) arg_sp30;
        arg_sp118 = (f64) arg_sp38;
        arg_sp210.XAxis3();
        arg_sp20 = -*M2C_ERROR(/* Read from unset register $r3 */);
        arg_sp24 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
        arg_sp28 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
        arg_sp120 = (f64) arg_sp20;
        arg_sp128 = (f64) arg_sp28;
        arg_sp22C = 0.0f;
        arg_sp40 = (arg_sp114 * (f32) arg_sp128) - ((f32) arg_sp118 * arg_sp124);
        arg_sp44 = ((f32) arg_sp118 * (f32) arg_sp120) - ((f32) arg_sp110 * (f32) arg_sp128);
        var_f1_5240 = 0.5f * (6.2831855f * gUpdateTimeDelta);
        arg_sp48 = ((f32) arg_sp110 * arg_sp124) - (arg_sp114 * (f32) arg_sp120);
        arg_sp130 = (f64) arg_sp40;
        arg_sp138 = (f64) arg_sp48;
        arg_sp220 = (f32) arg_sp130;
        arg_sp224 = arg_sp134;
        arg_sp228 = (f32) arg_sp138;
        temp_r0_5252 = this->unk38C;
        if (temp_r0_5252 == 1) {
            var_f1_5240 = 6.2831855f;
        }
        if ((temp_r0_5252 == 4) || (temp_r0_5252 == 5)) {
            var_f1_5240 = 0.0f;
        }
        Tools_RotateMatrixToDirection((Matrix *) &arg_sp210, *((MKVector3 *) &this->unkE0), *((MKVector3 *) &arg_sp1E0), var_f1_5240);
        Normalise(*((MKVector3 *) &arg_sp100));
        this->unkE0 = arg_sp100;
        this->unkE8 = arg_sp108;
        if ((s32) this->unk38C == 2) {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if ((((f32) arg_sp1E8 * M2C_FIELD(this, f32 *, 0xE8)) + (((f32) arg_sp1E0 * M2C_FIELD(this, f32 *, 0xE0)) + (arg_sp1E4 * M2C_FIELD(this, f32 *, 0xE4)))) == 1.0f) {
                this->unk38C = 0;
                this->unkE0 = arg_sp1E0;
                this->unkE8 = arg_sp1E8;
                this->unk370->ShowFist(1U);
                Disable();
            }
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

#if 0 // DRAFT: expression syntax error
void EarthBossArm::InitBoneData(int arg0, const char *arg1) {
    f64 sp8;
    s32 temp_r31_5421;
    void (*var_r29_5455)(EarthBossArm *, MKDynamicBone *, void *);
    void *temp_r30_5423;

    temp_r31_5421 = arg0 << 7;
    temp_r30_5423 = this + temp_r31_5421;
    M2C_FIELD(temp_r30_5423, s32 *, 0xC4) = (s32) Tools_GetMatchingNodeIndex(this->unk4, arg1);
    M2C_FIELD(temp_r30_5423, Enemy **, 0xC0) = (Enemy *) this->unk370;
    sp8.GetNodeOrigin(MKModel_GetAnimation(this->unk4));
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

#if 0 // DRAFT: expression syntax error
void EarthBossArmDescriptor::LoadDone() {
    s32 var_r29_5657;
    s8 temp_r30_5655;

    MKPropDescriptor::LoadDone();
    temp_r30_5655 = this->unk30->GetNmbrOfNodes();
    var_r29_5657 = 0;
loop_2:
    if (var_r29_5657 < temp_r30_5655) {
        MKDynamicBone_SetUpdater(MKDynamicBone_GetDynamicBone(this->unk2C, var_r29_5657), (void (*)(MKDynamicBone *, void *)) &EarthBossArm::UpdateShoulderBone, NULL);
        var_r29_5657 += 1;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetAttackerManager'
void EarthBossArm::lit_76lit_GetAttackerManager() {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::GetAttackerManager();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_IsAttacking'
void EarthBossArm::lit_76lit_IsAttacking() {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::IsAttacking();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetTimeLastHit'
void EarthBossArm::lit_76lit_GetTimeLastHit() {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::GetTimeLastHit();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetCollisionHeight'
void EarthBossArm::lit_76lit_GetCollisionHeight() {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::GetCollisionHeight();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetCollisionRadius'
void EarthBossArm::lit_76lit_GetCollisionRadius() {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::GetCollisionRadius();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetCollisionInfo'
void EarthBossArm::lit_76lit_GetCollisionInfo() {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::GetCollisionInfo();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetVel'
void EarthBossArm::lit_76lit_GetVel() {
    EarthBossArm::GetVel();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetAimPoint'
void EarthBossArm::lit_76lit_GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::GetAimPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetLookToPoint'
void EarthBossArm::lit_76lit_GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::GetLookToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetMoveToPoint'
void EarthBossArm::lit_76lit_GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::GetMoveToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_IsDead'
void EarthBossArm::lit_76lit_IsDead() {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::IsDead();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_IsShatterable'
void EarthBossArm::lit_76lit_IsShatterable() {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::IsShatterable();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_IsEnemy'
void EarthBossArm::lit_76lit_IsEnemy() {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::IsEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_IsFriend'
void EarthBossArm::lit_76lit_IsFriend() {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::IsFriend();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_IsHero'
void EarthBossArm::lit_76lit_IsHero() {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::IsHero();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetEnemy'
void EarthBossArm::lit_76lit_GetEnemy() {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::GetEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetProp'
void EarthBossArm::lit_76lit_GetProp() {
    ((EarthBossArm *) (this - 0x4C))->EarthBossArm::GetProp();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_1720lit_GetAimPoint'
void EarthBoss::lit_1720lit_GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((EarthBoss *) (this - 0x6B8))->EarthBoss::GetAimPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_1720lit_GetLookToPoint'
void EarthBoss::lit_1720lit_GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((EarthBoss *) (this - 0x6B8))->EarthBoss::GetLookToPoint(arg0, arg1);
}
#endif
