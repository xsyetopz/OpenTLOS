#include "spyro/source/EnemyDataTypes.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
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
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(u32 *);                                /* extern */
u32 *malloc(s32);                                   /* extern */
extern DataMap attackHitTypeDataMap;
extern DataMap dataMapAnimSequence;
extern DataMap heroHurtReactionTypeDataMap;
extern DataMap heroRumbleTypeDataMap;
extern DataMap projectileTypeDataMap;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'DataMap'
static DataMap dataMapEAP[0x13] = {
    { 1, "Melee" },
    { 2, "Projectile" },
    { 4, "Flying" },
    { 8, "Charge" },
    { 0x10, "Run" },
    { 0x20, "Stationary" },
    { 0x40, "Leap" },
    { 0x80, "Shockwave" },
    { 0x100, "Special1" },
    { 0x200, "Special2" },
    { 0x400, "Special3" },
    { 0x800, "Looping" },
    { 0x1000, "MagicDrain" },
    { 0x2000, "MagicWall" },
    { 0x10000, "Block" },
    { 0x20000, "ShieldBlock" },
    { 0x40000, "ShieldCharge" },
    { 0x40000000, "Uninterruptable" },
    { 0, NULL },
};
#endif

void EnemyMovementManager::SetExitingAnim() {
    AnimSequence *temp_r4_19;
    Enemy *temp_r3_18;

    this->unk14 |= 0x40;
    temp_r3_18 = this->unk0;
    temp_r4_19 = temp_r3_18->unkA50;
    if ((temp_r4_19 != NULL) && ((u32) temp_r4_19->unk40 != 0)) {
        temp_r3_18->SetAnim(temp_r4_19, (AnimTransition *) &temp_r4_19->unk40, 0.15f, 0U);
    }
}

s32 **EnemyMovementManager::SelectAnim() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    AnimSequence *temp_r8_45;
    Enemy *temp_r11_44;
    EnemyDescriptor *temp_r5_46;
    f32 temp_f1_84;
    f32 temp_f2_116;
    f32 temp_f3_55;
    f32 temp_f6_64;
    f32 temp_f8_57;
    s32 **temp_r31_89;
    s32 **temp_r9_159;
    s32 **var_r4_40;
    s32 *temp_r9_115;
    s32 temp_r12_91;
    s32 temp_r5_49;
    s32 temp_r7_190;
    s32 temp_r8_161;
    s32 var_ctr_155;
    s32 var_ctr_85;
    s32 var_r6_154;
    s32 var_r6_41;
    s32 var_r7_42;
    s32 var_r8_59;
    u32 temp_r8_178;
    void *temp_r0_48;

    var_r4_40 = NULL;
    var_r6_41 = 0;
    var_r7_42 = 0;
    temp_r11_44 = this->unk0;
    temp_r8_45 = temp_r11_44->unkA50;
    temp_r5_46 = temp_r11_44->unkA38;
    temp_r0_48 = temp_r5_46->unk204;
    temp_r5_49 = temp_r5_46->unk208;
    if (temp_r8_45 != NULL) {
        var_r6_41 = temp_r8_45->unk6C;
        var_r7_42 = temp_r8_45->unk68;
    }
    temp_f3_55 = temp_r11_44->unkC8;
    temp_f8_57 = temp_r11_44->unkC4;
    var_r8_59 = 0;
    temp_f6_64 = temp_r11_44->unkC0;
    sp8 = (MKVector3::up.unk4 * temp_f3_55) - (MKVector3::up.unk8 * temp_f8_57);
    spC = (MKVector3::up.unk8 * temp_f6_64) - (MKVector3::up.unk0 * temp_f3_55);
    sp10 = (MKVector3::up.unk0 * temp_f8_57) - (MKVector3::up.unk4 * temp_f6_64);
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    temp_f1_84 = ((f32) sp20 * temp_r11_44->unkE8) + (((f32) sp18 * temp_r11_44->unkE0) + ((*(f32 *) ((u8 *) &sp18 + 0x4)) * temp_r11_44->unkE4));
    var_ctr_85 = temp_r5_49;
    if (temp_r5_49 > 0) {
        do {
            temp_r31_89 = (long **) (((u8 *) temp_r0_48) + var_r8_59);
            temp_r12_91 = M2C_FIELD(temp_r31_89, s32 *, 4);
            if ((this->unk4 & temp_r12_91) && (!(temp_r12_91 & 1) || ((s32) this->unk8 == (s32) M2C_FIELD(temp_r31_89, s32 *, 0xC))) && (!(temp_r12_91 & 2) || ((s32) this->unkC == (s32) M2C_FIELD(temp_r31_89, s32 *, 0xC))) && (!(temp_r12_91 & 4) || ((s32) this->unk10 == (s32) M2C_FIELD(temp_r31_89, s32 *, 0xC)))) {
                temp_r9_115 = M2C_FIELD(temp_r31_89, s32 **, 0);
                temp_f2_116 = temp_r11_44->unk69C;
                if ((temp_f2_116 >= M2C_FIELD(temp_r9_115, f32 *, 4)) && (temp_f2_116 <= M2C_FIELD(temp_r9_115, f32 *, 8)) && (temp_f1_84 >= M2C_FIELD(temp_r9_115, f32 *, 0xC)) && (temp_f1_84 <= M2C_FIELD(temp_r9_115, f32 *, 0x10)) && ((var_r4_40 == NULL) || ((s32) **var_r4_40 < (s32) M2C_FIELD(temp_r9_115, s32 *, 0)) || ((var_r6_41 == (s32) M2C_FIELD(temp_r31_89, s32 *, 8)) && (var_r7_42 == (s32) M2C_FIELD(temp_r31_89, s32 *, 0xC))))) {
                    var_r4_40 = temp_r31_89;
                }
            }
            var_r8_59 += 0x14;
            var_ctr_85 -= 1;
        } while (var_ctr_85 != 0);
    }
    if (var_r4_40 == NULL) {
        var_r6_154 = 0;
        var_ctr_155 = temp_r5_49;
        if (temp_r5_49 > 0) {
            do {
                temp_r9_159 = (long **) (((u8 *) temp_r0_48) + var_r6_154);
                temp_r8_161 = M2C_FIELD(temp_r9_159, s32 *, 4);
                if ((this->unk4 & temp_r8_161) && (!(temp_r8_161 & 1) || ((s32) this->unk8 == (s32) M2C_FIELD(temp_r9_159, s32 *, 0xC))) && (!(temp_r8_161 & 2) || ((s32) this->unkC == (s32) M2C_FIELD(temp_r9_159, s32 *, 0xC))) && ((temp_r8_178 = temp_r8_161 & 4, ((temp_r8_178 == 0) != 0)) || ((s32) this->unk10 == (s32) M2C_FIELD(temp_r9_159, s32 *, 0xC)))) {
                    if (var_r4_40 == NULL) {
                        var_r4_40 = temp_r9_159;
                    } else {
                        temp_r7_190 = M2C_FIELD(var_r4_40, s32 *, 4);
                        if (temp_r7_190 & 9) {
                            var_r4_40 = temp_r9_159;
                        } else if ((temp_r7_190 & 2) && (temp_r8_178 != 0)) {
                            var_r4_40 = temp_r9_159;
                        }
                    }
                }
                var_r6_154 += 0x14;
                var_ctr_155 -= 1;
            } while (var_ctr_155 != 0);
        }
    }
    return var_r4_40;
}

void EnemyMovementManager::Update() {
    AnimSequence *temp_r3_224;
    AnimSequence *temp_r3_260;
    AnimSequence *temp_r4_316;
    AnimSequence *temp_r4_331;
    Enemy *temp_r28_310;
    Enemy *temp_r3_328;
    Enemy *temp_r4_284;
    Enemy *temp_r4_290;
    Enemy *temp_r4_296;
    Enemy *temp_r4_302;
    Enemy *temp_r4_348;
    f32 temp_f2_349;
    f32 temp_f3_352;
    f32 var_f0_357;
    s32 **temp_r31_233;
    s32 *temp_r3_347;
    s32 temp_r0_271;
    s32 temp_r4_238;
    s32 var_r28_219;
    s32 var_r29_220;
    u8 temp_r3_339;
    u8 var_r29_311;

    var_r28_219 = 0;
    var_r29_220 = 0;
    ((Character *) this->unk0)->UpdateSpeed();
    temp_r3_224 = this->unk0->unkA50;
    if (temp_r3_224 != NULL) {
        var_r28_219 = temp_r3_224->unk6C;
        var_r29_220 = temp_r3_224->unk68;
    }
    temp_r31_233 = SelectAnim();
    if (!(((u8) this->unk14 >> 6U) & 1) && (temp_r31_233 != NULL)) {
        temp_r4_238 = M2C_FIELD(temp_r31_233, s32 *, 8);
        if ((var_r28_219 != temp_r4_238) || (var_r29_220 != (s32) M2C_FIELD(temp_r31_233, s32 *, 0xC))) {
            this->unk0->SetAnim((AnimSequenceType) temp_r4_238, M2C_FIELD(temp_r31_233, s32 *, 0xC), 0, 0.15f, 0U, 0U);
            this->unk14 &= ~0x80;
            this->unk14 &= ~0x40;
            temp_r3_260 = this->unk0->unkA50;
            if ((temp_r3_260 != NULL) && ((u32) temp_r3_260->unk20 != 0)) {
                this->unk14 |= 0x80;
            }
        }
        temp_r0_271 = M2C_FIELD(temp_r31_233, s32 *, 8);
        switch (temp_r0_271) {                      /* irregular */
        case 4:
        case 1:
            temp_r4_284 = this->unk0;
            temp_r4_284->unk68C = temp_r4_284->unkA38->unk154;
            break;
        case 5:
            temp_r4_290 = this->unk0;
            temp_r4_290->unk68C = temp_r4_290->unkA38->unk158;
            break;
        case 6:
            temp_r4_296 = this->unk0;
            temp_r4_296->unk68C = temp_r4_296->unkA38->unk15C;
            break;
        default:
            temp_r4_302 = this->unk0;
            temp_r4_302->unk68C = temp_r4_302->unkA38->unk15C;
            break;
        }
        if (((u8) this->unk14 >> 7U) & 1) {
            temp_r28_310 = this->unk0;
            var_r29_311 = 0;
            if (((Character *) temp_r28_310)->HasAnimFinished() != 0) {
                temp_r4_316 = temp_r28_310->unkA50;
                if ((temp_r4_316 != NULL) && ((u32) temp_r4_316->unk0 == (u32) M2C_FIELD(temp_r28_310->unk630, u32 *, 0x20))) {
                    var_r29_311 = 1;
                }
            }
            if (var_r29_311 != 0) {
                temp_r3_328 = this->unk0;
                temp_r4_331 = temp_r3_328->unkA50;
                temp_r3_328->SetAnim(temp_r4_331, (AnimTransition *) &temp_r4_331->unk20, 0.15f, 0U);
                this->unk14 &= ~0x80;
            }
        }
        temp_r3_339 = this->unk14;
        if (!((temp_r3_339 >> 7U) & 1) && !((temp_r3_339 >> 6U) & 1) && ((u8) M2C_FIELD(temp_r31_233, u8 *, 0x10) != 0)) {
            temp_r3_347 = M2C_FIELD(temp_r31_233, s32 **, 0);
            temp_r4_348 = this->unk0;
            temp_f2_349 = M2C_FIELD(temp_r3_347, f32 *, 4);
            temp_f3_352 = temp_r4_348->unk69C - temp_f2_349;
            var_f0_357 = ((temp_f3_352 / (M2C_FIELD(temp_r3_347, f32 *, 8) - temp_f2_349)) * temp_f3_352) + 0.5f;
            if (var_f0_357 < 1.0f) {

            } else {
                var_f0_357 = 1.0f;
            }
            M2C_FIELD(temp_r4_348->unk630, f32 *, 0x38) = var_f0_357;
        }
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyMovementManager::Set(unsigned int arg0, int arg1, int arg2, int arg3) {
    Enemy *temp_r3_393;

    this->unk4 = arg0;
    this->unk8 = arg1;
    this->unkC = arg2;
    this->unk10 = arg3;
    this->unk14 &= ~0x80;
    this->unk14 &= ~0x40;
    temp_r3_393 = this->unk0;
    if ((temp_r3_393 != NULL) && (M2C_FIELD(temp_r3_393->__vptr, u8 (**)(), 0x148)() == 0)) {
        this->unk4 &= 0xFFFFFFF7;
    }
}
#endif

void EnemyMovementManager::Deinit() {
    this->unk0 = NULL;
}

void EnemyMovementManager::Init(Enemy *arg0) {
    this->unk0 = arg0;
    this->unk4 = 0;
    this->unk8 = 0;
    this->unkC = 0;
    this->unk10 = 0;
    this->unk14 &= ~0x80;
    this->unk14 &= ~0x40;
}

s32 EnemyMovementType_GetMask(int arg0) {
    switch (arg0) {                                 /* irregular */
    default:
    case 1:
        return 1;
    case 5:
        return 2;
    case 6:
        return 4;
    case 4:
        return 8;
    }
}

void EnemySpawnGraphData::SetDefaults() {
    this->unk0 = 0;
    this->unk4 = 0;
    this->unk8 = 0;
    this->unkC = 0;
    this->unk10 = 0;
}

void AttackSweepData::SetDefaults() {
    s32 var_r4_486;
    s32 var_r6_485;
    void *temp_r5_491;

    this->unk5 = 1;
    var_r6_485 = 0;
    var_r4_486 = 0;
loop_2:
    if (var_r6_485 < (s32) this->unk4) {
        var_r6_485 += 1;
        temp_r5_491 = (void *) (this->unk0 + var_r4_486);
        var_r4_486 += 0x10;
        M2C_FIELD(temp_r5_491, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r5_491, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r5_491, f32 *, 8) = 0.0f;
        goto loop_2;
    }
}

void EnemyDamageFeedback::Init(float arg0, bool arg1, const MKVector3 &arg2, int arg3, int arg4, bool arg5, bool arg6, MKCollisionInfo *arg7, float arg8, float arg9) {
    this->unk24 = arg0;
    this->unk34 = (this->unk34 & ~0x80) | ((arg1 << 7) & 0x80);
    this->unk0 = M2C_FIELD(&arg2, f64 *, 0);
    this->unk8 = M2C_FIELD(&arg2, f64 *, 8);
    this->unk20 = arg3;
    this->unk28 = arg4;
    this->unk34 = (this->unk34 & ~0x40) | ((arg5 << 6) & 0x40);
    this->unk34 = (this->unk34 & ~0x20) | ((arg6 << 5) & 0x20);
    this->unk34 &= ~0x10;
    this->unk34 &= ~8;
    this->unk14 = 0;
    this->unk10 = (s32) arg7;
    this->unk18 = arg8;
    this->unk1C = arg9;
    this->unk2C = 0;
    this->unk30 = 0;
}

void EnemyDamageFeedback::Init() {
    this->unk24 = 0.0f;
    this->unk28 = 0xE;
    this->unk20 = 0x10;
    this->unk34 &= ~0x10;
    this->unk34 &= ~0x20;
    this->unk34 &= ~0x80;
    this->unk34 &= ~0x40;
    this->unk34 &= ~8;
    M2C_FIELD(this, f32 *, 0) = 0.0f;
    M2C_FIELD(this, f32 *, 4) = 0.0f;
    M2C_FIELD(this, f32 *, 8) = 0.0f;
    this->unk10 = 0;
    this->unk14 = 0;
    this->unk18 = 0.0f;
    this->unk1C = 1.0f;
    this->unk2C = 0;
    this->unk30 = 0;
}

void EnemyAttack::LoadDone() {
    if ((u8) this->unk8C == 0) {
        this->unk24 = this->unk14;
    }
    if ((u8) this->unk8D == 0) {
        this->unk28 = this->unk18;
    }
    if ((u8) this->unk8E == 0) {
        this->unk2C = this->unk1C;
    }
    if ((u8) this->unk8F == 0) {
        this->unk30 = this->unk20;
    }
}

#if 0 // DRAFT: function call 'DataMap_GetValue(DataMap *, long)' does not match 'DataMap_GetValue(const DataMap *, const char *)'
s32 EnemyAttack::LoadLine(MKIniLine *arg0, EnemyDescriptor *arg1) {
    s8 *sp8;
    f32 var_f0_805;
    f32 var_f0_835;
    f32 var_f0_944;
    f32 var_f0_976;
    s32 temp_r0_866;
    s32 temp_r28_633;
    s32 temp_r28_659;
    s32 temp_r5_637;
    s32 var_r27_674;
    s32 var_r28_675;
    s32 var_r30_999;
    u16 temp_r0_685;
    u32 *var_r3_667;

    sp8 = NULL;
    if (arg0->IsField("AnimSequence") != 0) {
        temp_r28_633 = DataMap_GetValue(&dataMapAnimSequence, arg0->GetString(0));
        temp_r5_637 = arg0->GetInt(1);
        if (temp_r28_633 != 0) {
            this->unk0 = (AnimSequence *) (arg1->GetAnimSequence(temp_r28_633, temp_r5_637, this->unk3C, NULL));
        }
        return 1;
    }
    if (arg0->IsField("RefPoints") != 0) {
        this->unk78 = (s32) arg0->unk0;
        temp_r28_659 = this->unk78 * 4;
        if (MKHeap::Current() != NULL) {
            var_r3_667 = (unsigned long *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r28_659, NULL, 0));
        } else {
            var_r3_667 = malloc(temp_r28_659);
        }
        this->unk7C = var_r3_667;
        var_r27_674 = 0;
        var_r28_675 = 0;
loop_10:
        if (var_r27_674 < (s32) this->unk78) {
            temp_r0_685 = Tools_GetMatchingRefPointIndex(arg1->unk2C, arg0->GetString(var_r27_674));
            var_r27_674 += 1;
            *(this->unk7C + var_r28_675) = (s32) temp_r0_685;
            var_r28_675 += 4;
            goto loop_10;
        }
        return 1;
    }
    if (arg0->IsField("EnemySettings") != 0) {
        this->unk54.LoadLine(arg0->unkC->GetSubLine(arg0));
        return 1;
    }
    if (arg0->LoadString("ProjectileNode", &sp8, 0) != 0) {
        this->unk84 = (s32) Tools_GetMatchingRefPointIndex(arg1->unk2C, sp8);
        if ((u32) this->unk84 == -1U) {
            this->unk84 = (s32) Tools_GetMatchingNodeIndex(arg1->unk2C, sp8);
        }
        return 1;
    }
    if (arg0->IsField("HeroHurtType") != 0) {
        this->unk48 = DataMap_GetValue(&heroHurtReactionTypeDataMap, arg0->GetString(0));
        return 1;
    }
    if (arg0->IsField("HeroRumbleType") != 0) {
        this->unk4C = DataMap_GetValue(&heroRumbleTypeDataMap, arg0->GetString(0));
        return 1;
    }
    if (arg0->IsField("EnemyHitType") != 0) {
        this->unk50 = DataMap_GetValue(&attackHitTypeDataMap, arg0->GetString(0));
        return 1;
    }
    if (arg0->LoadFloat("fAngleMin", &this->unk1C, 0) != 0) {
        var_f0_805 = 0.017453292f * this->unk1C;
        if (var_f0_805 < 6.2830853f) {

        } else {
            var_f0_805 = 6.2830853f;
        }
        if (var_f0_805 > 0.0f) {

        } else {
            var_f0_805 = 0.0f;
        }
        this->unk1C = var_f0_805;
        return 1;
    }
    if (arg0->LoadFloat("fAngleMax", &this->unk20, 0) != 0) {
        var_f0_835 = 0.017453292f * this->unk20;
        if (var_f0_835 < 6.2830853f) {

        } else {
            var_f0_835 = 6.2830853f;
        }
        if (var_f0_835 > 0.0f) {

        } else {
            var_f0_835 = 0.0f;
        }
        this->unk20 = var_f0_835;
        return 1;
    }
    if (DataMap_LoadLine(arg0, "ProjectileType", &projectileTypeDataMap, (unsigned int *) &this->unk80) != 0) {
        if ((s32) this->unk80 == 0) {
            temp_r0_866 = arg1->unk1D0;
            switch (temp_r0_866) {                  /* irregular */
            case 4:
            case 0:
                this->unk80 = 1;
                break;
            case 1:
                this->unk80 = 2;
                break;
            case 2:
                this->unk80 = 3;
                break;
            case 3:
                this->unk80 = 4;
                break;
            default:
                this->unk80 = 1;
                break;
            }
        }
        return 1;
    }
    if (arg0->LoadFloat("fSelectRangeMin", &this->unk24, 0) != 0) {
        this->unk8C = 1;
        return 1;
    }
    if (arg0->LoadFloat("fSelectRangeMax", &this->unk28, 0) != 0) {
        this->unk8D = 1;
        return 1;
    }
    if (arg0->LoadFloat("fSelectAngleMin", &this->unk2C, 0) != 0) {
        this->unk8E = 1;
        var_f0_944 = 0.017453292f * this->unk2C;
        if (var_f0_944 < 6.2830853f) {

        } else {
            var_f0_944 = 6.2830853f;
        }
        if (var_f0_944 > 0.0f) {

        } else {
            var_f0_944 = 0.0f;
        }
        this->unk2C = var_f0_944;
        return 1;
    }
    if (arg0->LoadFloat("fSelectAngleMax", &this->unk30, 0) != 0) {
        this->unk8F = 1;
        var_f0_976 = 0.017453292f * this->unk30;
        if (var_f0_976 < 6.2830853f) {

        } else {
            var_f0_976 = 6.2830853f;
        }
        if (var_f0_976 > 0.0f) {

        } else {
            var_f0_976 = 0.0f;
        }
        this->unk30 = var_f0_976;
        return 1;
    }
    var_r30_999 = 0;
    if ((arg0->LoadFloat("fAttackDelay", &this->unk8, 0) != 0) || (arg0->LoadFloat("fRangeMin", &this->unk14, 0) != 0) || (arg0->LoadFloat("fRangeMax", &this->unk18, 0) != 0) || (arg0->LoadFloat("iDamage", &this->unk4, 0) != 0) || (arg0->LoadInt("iAnimSet", (int *) &this->unk3C, 0) != 0) || (arg0->LoadInt("iAttackChance", (int *) &this->unk40, 0) != 0) || (arg0->LoadInt("iRunASV", (int *) &this->unk44, 0) != 0) || (arg0->LoadFloat("fProjectileSpeed", &this->unk88, 0) != 0) || (arg0->LoadFloat("fKnockbackForce", &this->unk34, 0) != 0) || (arg0->LoadFloat("fDefensiveThreshold", &this->unkC, 0) != 0) || (arg0->LoadFloat("fDefensivePenalty", &this->unk10, 0) != 0) || (DataMap_LoadLineBitfield(arg0, "uProperties", dataMapEAP, (unsigned int *) &this->unk38) != 0)) {
        var_r30_999 = 1;
    }
    return var_r30_999;
}
#endif

void EnemyAttack::Deinit() {
    u32 *temp_r31_1124;

    temp_r31_1124 = this->unk7C;
    if (temp_r31_1124 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1124, NULL, 0);
        } else {
            free(temp_r31_1124);
        }
    }
    this->unk78 = 0;
    this->unk7C = NULL;
}

void EnemyAttack::Init() {
    this->unk0 = NULL;
    this->unk8 = 0.0f;
    this->unk14 = 0.0f;
    this->unk18 = 0.0f;
    this->unk4 = 0.0f;
    this->unk3C = 0;
    this->unk40 = 0;
    this->unk44 = 0;
    this->unk48 = 1;
    this->unk4C = 2;
    this->unk50 = 0xE;
    this->unk34 = 220.0f;
    this->unk38 = 0;
    this->unk78 = 0;
    this->unk7C = NULL;
    this->unk80 = 0;
    this->unk84 = 0xFFFF;
    this->unk88 = 1000.0f;
    this->unk1C = 0.0f;
    this->unk20 = 6.2830853f;
    this->unkC = 0.0f;
    this->unk10 = 0.0f;
    this->unk24 = 0.0f;
    this->unk28 = 0.0f;
    this->unk2C = 0.0f;
    this->unk30 = 0.0f;
    this->unk8C = 0;
    this->unk8D = 0;
    this->unk8E = 0;
    this->unk8F = 0;
    this->unk54.InitToOne();
}
