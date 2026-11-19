#include "spyro/source/EnemyGoal_RangeAttackMode.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Projectile.h"
#include "spyro/source/TargetManager.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/GameEnums.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'GetEnemyAttackSetting'
void EnemyGoal_AttackProjectile::Terminate() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    AttackerManager *var_r3_75;
    CharacterFireFX *temp_r5_22;
    Enemy *temp_r3_17;
    Enemy *temp_r3_21;
    Enemy *temp_r3_38;
    Enemy *temp_r3_55;
    Enemy *var_r4_82;
    u8 var_r30_56;

    temp_r3_17 = this->unkC;
    M2C_FIELD(temp_r3_17, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_17, u8 *, 0xB08) & ~0x10);
    temp_r3_21 = this->unkC;
    temp_r5_22 = temp_r3_21->unkA08;
    if (temp_r5_22 != NULL) {
        this->unkC->unkA7C = M2C_FIELD(&gb, f32 *, 0x30C) + temp_r3_21->unkA20->GetEnemyAttackSetting((EnemySettingType) 6, (EnemyAttack *) temp_r5_22);
        this->unkC->unkA08 = NULL;
    }
    temp_r3_38 = this->unkC;
    if ((MeleeTrails *) temp_r3_38->unkA14 != NULL) {
        sp10 = 0.0f;
        sp8 = 0.0f;
        spC = -500.0f;
        sp20 = (f64) sp10;
        sp18 = (f64) sp8;
        temp_r3_38->DisableCurrentProjectile(1U, *((MKVector3 *) &sp18));
    }
    temp_r3_55 = this->unkC;
    var_r30_56 = 0;
    if (((u8) M2C_FIELD(temp_r3_55, u8 *, 0x8B8) == 2) || (temp_r3_55->unk870.unk30.Get() != NULL)) {
        var_r30_56 = 1;
    }
    if (var_r30_56 != 0) {
        var_r3_75 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_75 = NULL;
    }
    if (var_r3_75 != NULL) {
        var_r4_82 = this->unkC;
        if (var_r4_82 != NULL) {
            var_r4_82 += 0x6B8;
        }
        var_r3_75->Remove((Targetable *) var_r4_82, 8);
    }
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
u8 EnemyGoal_AttackProjectile::Update() {
    AITargetData sp228;
    f64 sp218;
    f64 sp208;
    MKVector3 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    MKProp sp168;
    f64 sp160;
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
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    M2C_UNK spD8;
    MKVector3 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spA0;
    f32 sp90;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    CharacterFireFX *temp_r31_125;
    Enemy *temp_r29_634;
    Enemy *temp_r3_122;
    Enemy *temp_r3_127;
    Enemy *temp_r3_209;
    Enemy *temp_r3_300;
    Enemy *temp_r3_313;
    Enemy *temp_r3_390;
    Enemy *temp_r3_415;
    Enemy *temp_r3_420;
    Enemy *temp_r3_601;
    Enemy *temp_r3_627;
    Enemy *temp_r4_140;
    Enemy *temp_r4_164;
    Enemy *temp_r4_202;
    Enemy *temp_r5_451;
    Enemy *temp_r6_278;
    Enemy *temp_r6_575;
    EnemyAttack *temp_r7_282;
    EnemyDescriptor *temp_r4_630;
    EnemyDescriptor *temp_r4_640;
    EnemyDescriptor *temp_r5_603;
    MeleeTrails *temp_r3_230;
    MeleeTrails *temp_r3_237;
    MeleeTrails *temp_r3_243;
    MeleeTrails *temp_r3_281;
    MeleeTrails *temp_r3_291;
    MeleeTrails *temp_r3_400;
    MeleeTrails *temp_r3_408;
    MeleeTrails *temp_r3_498;
    MeleeTrails *temp_r3_563;
    MeleeTrails *temp_r3_570;
    MeleeTrails *temp_r3_579;
    MeleeTrails *temp_r3_588;
    f32 temp_f1_441;
    f32 temp_f1_449;
    f32 temp_f1_522;
    f32 temp_f2_425;
    f32 temp_f30_305;
    f32 temp_f31_421;
    f64 temp_f1_197;
    u32 temp_r4_352;
    u32 temp_r4_488;
    u8 var_r29_118;
    u8 var_r31_635;
    u8 var_r6_602;
    void *temp_r3_177;
    void *temp_r3_453;
    void *temp_r4_422;

    ActivateIfInactive();
    var_r29_118 = 0;
    sp228.unk20 = M2C_FIELD(&zero, f64 *, 0);
    sp228.unk28 = M2C_FIELD(&zero, f64 *, 8);
    temp_r3_122 = this->unkC;
    temp_r31_125 = temp_r3_122->unkA08;
    M2C_FIELD(temp_r3_122, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_122, u8 *, 0xB08) & ~0x10);
    temp_r3_127 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_127, u8 *, 0x8B8) == 2) || (temp_r3_127->unk870.unk30.Get() != NULL)) {
        var_r29_118 = 1;
    }
    if (var_r29_118 != 0) {
        temp_r4_140 = this->unkC;
        temp_r4_140->unk838.unk28.Update(*((MKVector3 *) &temp_r4_140->unk588));
        sp228.GetPos();
        M2C_FIELD(this, f64 *, 0x38) = M2C_BITWISE(f64, sp228);
        this->unk38 = (f64) sp228.unk8;
        sp218.GetDir();
        sp228.unk20 = sp218;
        sp228.unk28 = sp220;
        sp208.GetDir();
        temp_r4_164 = this->unkC;
        M2C_FIELD(temp_r4_164, f64 *, 0xE0) = sp208;
        M2C_FIELD(temp_r4_164, f64 *, 0xE8) = sp210;
        temp_r4_164->unk6B5 |= 0x40;
    } else {
        temp_r3_177 = this->unkC->unk8;
        sp1D8 = M2C_FIELD(temp_r3_177, f64 *, 0x30);
        sp1E0 = M2C_FIELD(temp_r3_177, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp1E8 = sp78;
        sp80 = (f32) M2C_FIELD(this, f64 *, 0x40) - (f32) sp1E0;
        sp1F0 = (f64) sp80;
        Normalise(sp1F8);
        temp_f1_197 = M2C_BITWISE(f64, sp1F8);
        sp228.unk20 = temp_f1_197;
        sp228.unk28 = (f64) sp1F8.unk8;
        temp_r4_202 = this->unkC;
        M2C_FIELD(temp_r4_202, f64 *, 0xE0) = temp_f1_197;
        M2C_FIELD(temp_r4_202, f64 *, 0xE8) = (f64) sp1F8.unk8;
        temp_r4_202->unk6B5 |= 0x40;
    }
    temp_r3_209 = this->unkC;
    if (((MeleeTrails *) temp_r3_209->unkA14 != NULL) && (((MKAnimScript *) (M2C_FIELD(temp_r3_209, MKAnimScript **, 0x630)))->CheckEvent(0) != 0)) {
        if ((ProjectileType_IsDynamite(M2C_FIELD(temp_r31_125, s32 *, 0x80)) == 0) && !(M2C_FIELD(temp_r31_125, s32 *, 0x38) & 0x1000)) {
            this->unkC->unk684 = 0.0f;
        }
        temp_r3_230 = this->unkC->unkA14;
        temp_r3_230->Activate();
        temp_r3_237 = this->unkC->unkA14;
        M2C_FIELD(temp_r3_237->__vptr, M2C_UNK (**)(MeleeTrails *, MKAttachment *), 0x74)(temp_r3_237, &this->unk10);
        temp_r3_243 = this->unkC->unkA14;
        if (M2C_FIELD(temp_r3_243->__vptr, u8 (**)(MeleeTrails *), 0x58)(temp_r3_243) != 0) {
            if ((s32) M2C_FIELD(temp_r31_125, s32 *, 0x80) == 5) {
                this->unk18 = M2C_FIELD(this, f64 *, 0x38);
                this->unk18 = this->unk38;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                sp1C8 = sp68;
                sp70 = (f32) sp228.unk28 * 200.0f;
                sp1D0 = (f64) sp70;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
                M2C_FIELD(this, f64 *, 0x20) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x20) + (f32) sp1D0);
            }
            temp_r6_278 = this->unkC;
            temp_r3_281 = temp_r6_278->unkA14;
            temp_r7_282 = temp_r6_278->unkA20;
            M2C_FIELD(temp_r3_281->__vptr, M2C_UNK (**)(MeleeTrails *, f64 *, f64 *, s32, s32), 0x50)(temp_r3_281, &this->unk20, &this->unk18, M2C_FIELD(temp_r7_282, s32 *, 0x1B8), M2C_FIELD(temp_r7_282, s32 *, 0x1BC));
        }
    }
    temp_r3_291 = this->unkC->unkA14;
    if ((temp_r3_291 != NULL) && (M2C_FIELD(temp_r3_291->__vptr, u8 (**)(), 0x58)() != 0)) {
        temp_r3_300 = this->unkC;
        temp_f30_305 = temp_r3_300->GetCollisionRadius();
        sp168.GetDir();
        sp168.unk10.operator*(temp_f30_305);
        temp_r3_313 = this->unkC;
        MKVector(0.0f, temp_r3_313->GetCollisionHeight(), 0.0f);
        sp168.unk30.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp168.unk40 = sp8;
        sp10 = M2C_BITWISE(f32, sp168.unk38) + M2C_BITWISE(f32, sp168.unk28);
        sp168.unk48 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        this->unk20 = sp58;
        sp60 = sp168.unk48 + M2C_BITWISE(f32, sp168.unk18);
        sp1B8 = sp58;
        M2C_FIELD(this, f64 *, 0x30) = (f64) sp60;
        temp_r4_352 = M2C_FIELD(temp_r31_125, u32 *, 0x84);
        sp1C0 = (f64) sp60;
        if (temp_r4_352 != -1U) {
            MKModel_CalculateRefPointWorldPosition(this->unkC->unk4, (s32) temp_r4_352, (MKVector3 *) &this->unk20);
        }
        this->unk18 = M2C_FIELD(this, f64 *, 0x38);
        this->unk18 = this->unk38;
        if ((s32) M2C_FIELD(temp_r31_125, s32 *, 0x80) == 5) {
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            sp158 = sp48;
            sp50 = (f32) sp228.unk28 * 200.0f;
            sp160 = (f64) sp50;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
            M2C_FIELD(this, f64 *, 0x20) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x20) + (f32) sp160);
        }
    }
    temp_r3_390 = this->unkC;
    if (((MeleeTrails *) temp_r3_390->unkA14 != NULL) && (((MKAnimScript *) (M2C_FIELD(temp_r3_390, MKAnimScript **, 0x630)))->CheckEvent(1) != 0)) {
        temp_r3_400 = this->unkC->unkA14;
        if (M2C_FIELD(temp_r3_400->__vptr, u8 (**)(MeleeTrails *), 0x58)(temp_r3_400) != 0) {
            temp_r3_408 = this->unkC->unkA14;
            M2C_FIELD(temp_r3_408->__vptr, M2C_UNK (**)(MeleeTrails *), 0x54)(temp_r3_408);
        } else {
            temp_r3_415 = this->unkC;
            temp_r3_420 = this->unkC;
            temp_f31_421 = temp_r3_415->GetCollisionRadius();
            temp_r4_422 = temp_r3_420->unk8;
            temp_f2_425 = -M2C_FIELD(temp_r4_422, f32 *, 0x20);
            sp38 = temp_f2_425;
            sp3C = -M2C_FIELD(temp_r4_422, f32 *, 0x24);
            sp40 = -M2C_FIELD(temp_r4_422, f32 *, 0x28);
            sp108 = (f64) sp38;
            sp110 = (f64) sp40;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            temp_f1_441 = (f32) sp110 * temp_f31_421;
            sp118 = sp98;
            spA0 = temp_f1_441;
            sp120 = (f64) spA0;
            temp_f1_449 = temp_r3_420->GetCollisionHeight(temp_r4_422, temp_f1_441, temp_f2_425);
            temp_r5_451 = this->unkC;
            spB8 = 0.0f;
            temp_r3_453 = temp_r5_451->unk8;
            spBC = temp_f1_449;
            spC0 = 0.0f;
            sp128 = (f64) spB8;
            sp138 = M2C_FIELD(temp_r3_453, f64 *, 0x30);
            sp130 = (f64) spC0;
            sp140 = M2C_FIELD(temp_r3_453, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp148 = spA8;
            spB0 = (f32) sp140 + (f32) sp130;
            sp150 = (f64) spB0;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp228.unk10 = sp88;
            sp90 = (f32) sp150 + (f32) sp120;
            sp228.unk18 = (f64) sp90;
            temp_r4_488 = M2C_FIELD(temp_r31_125, u32 *, 0x84);
            if (temp_r4_488 != -1U) {
                MKModel_CalculateRefPointWorldPosition(temp_r5_451->unk4, (s32) temp_r4_488, (MKVector3 *) &sp228.unk10);
            }
            temp_r3_498 = this->unkC->unkA14;
            M2C_FIELD(temp_r3_498->__vptr, M2C_UNK (**)(MeleeTrails *, M2C_UNK), 0x74)(temp_r3_498, 0);
            if (ProjectileType_IsDynamite(M2C_FIELD(temp_r31_125, s32 *, 0x80)) != 0) {
                this->unk18 = M2C_FIELD(this, f64 *, 0x38);
                this->unk18 = this->unk38;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                temp_f1_522 = (f32) sp228.unk28 * MKRand_Float(&gViewSeed, 100.0f, 200.0f);
                spF8 = sp28;
                sp30 = temp_f1_522;
                sp100 = (f64) sp30;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
                M2C_FIELD(this, f64 *, 0x20) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x20) - (f32) sp100);
            }
            if ((u8) M2C_FIELD(this, u8 *, 0x48) != 0) {
                spC8.operator*(300.0f);
                spD8.GetPos();
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                this->unk18 = sp18;
                sp20 = spE0 + spC8.unk8;
                spE8 = sp18;
                this->unk18 = (f64) sp20;
                spF0 = (f64) sp20;
                temp_r3_563 = this->unkC->unkA14;
                M2C_FIELD(temp_r3_563->__vptr, M2C_UNK (**)(MeleeTrails *, f32, f64), 0x68)(temp_r3_563, 0.35f, sp18);
            }
            temp_r3_570 = this->unkC->unkA14;
            temp_r3_570->Activate();
            temp_r6_575 = this->unkC;
            temp_r3_579 = temp_r6_575->unkA14;
            M2C_FIELD(temp_r3_579->__vptr, M2C_UNK (**)(MeleeTrails *, f64 *, f64 *, Enemy *, M2C_UNK, M2C_UNK, f32), 0x4C)(temp_r3_579, &sp228.unk10, &this->unk18, temp_r6_575, 0, 0, M2C_FIELD(temp_r31_125, f32 *, 0x88));
        }
        temp_r3_588 = this->unkC->unkA14;
        if (temp_r3_588 != NULL) {
            M2C_FIELD(temp_r3_588, s32 *, 0x130) = 0;
            this->unkC->unkA14 = NULL;
        }
    }
    if ((temp_r31_125 != NULL) && (M2C_FIELD(temp_r31_125, s32 *, 0x38) & 0x1000)) {
        temp_r3_601 = this->unkC;
        var_r6_602 = 0;
        temp_r5_603 = temp_r3_601->unkA38;
        if ((temp_r5_603 != NULL) && ((s8 *) temp_r5_603->unk0 == (u32) M2C_FIELD(temp_r3_601, MKAnimScript **, 0x630)->unk20)) {
            var_r6_602 = 1;
        }
        if (((var_r6_602 != 0) && ((s32) M2C_FIELD(temp_r3_601, MKAnimScript **, 0x630)->unk44 >= 2)) || (M2C_FIELD(temp_r3_601->__vptr, u8 (**)(), 0x114)() != 0)) {
            temp_r3_627 = this->unkC;
            temp_r4_630 = temp_r3_627->unkA38;
            temp_r3_627->SetAnim((AnimSequence *) temp_r4_630, (AnimTransition *) &temp_r4_630->__vptr, 0.0f, 0U);
        }
        temp_r29_634 = this->unkC;
        var_r31_635 = 0;
        if (temp_r29_634->HasAnimFinished() != 0) {
            temp_r4_640 = temp_r29_634->unkA38;
            if ((temp_r4_640 != NULL) && ((void *) temp_r4_640->__vptr == (u32) M2C_FIELD(temp_r29_634, MKAnimScript **, 0x630)->unk20)) {
                var_r31_635 = 1;
            }
        }
        if (var_r31_635 != 0) {
            this->unkC->SetHitTarget(1U);
            this->unk8 = 2;
        }
        return this->unk8;
    }
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_AttackProjectile::Activate() {
    f64 sp90;
    f64 sp88;
    f64 sp78;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    M2C_UNK sp48;
    MKVector3 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    AttackerManager *var_r3_915;
    CharacterFireFX *temp_r31_696;
    Enemy *temp_r3_695;
    Enemy *temp_r3_732;
    Enemy *temp_r3_790;
    Enemy *temp_r3_862;
    Enemy *temp_r3_896;
    Enemy *temp_r4_717;
    Enemy *temp_r4_721;
    Enemy *temp_r4_746;
    Enemy *temp_r4_808;
    Enemy *temp_r4_832;
    Enemy *temp_r4_851;
    Enemy *var_r4_922;
    MeleeTrails *temp_r3_798;
    MeleeTrails *temp_r3_809;
    MeleeTrails *temp_r3_819;
    MeleeTrails *temp_r3_826;
    MeleeTrails *temp_r3_845;
    f32 temp_f1_882;
    u32 temp_r6_835;
    u8 var_r29_733;
    u8 var_r31_891;
    void *temp_r4_864;

    temp_r3_695 = this->unkC;
    temp_r31_696 = temp_r3_695->unkA08;
    if ((temp_r31_696 != NULL) && (M2C_FIELD(temp_r31_696, s32 *, 0x38) & 0x1000) && (M2C_FIELD(temp_r3_695->__vptr, u8 (**)(), 0x114)() != 0)) {
        this->unk8 = 3;
        return;
    }
    this->unk8 = 0;
    this->unkC->SetIdleMovementSpeed(1U);
    temp_r4_717 = this->unkC;
    temp_r4_717->unk684 = M2C_FIELD(temp_r4_717->unkA20, f32 *, 0x15C);
    temp_r4_721 = this->unkC;
loop_6:
    if ((void *) temp_r4_721->unkA04->__vptr != NULL) {
        temp_r4_721->unkA04 = (CharacterZapFX *) &temp_r4_721->unkA04->unk4;
        goto loop_6;
    }
    temp_r3_732 = this->unkC;
    var_r29_733 = 0;
    if (((u8) M2C_FIELD(temp_r3_732, u8 *, 0x8B8) == 2) || (temp_r3_732->unk870.unk30.Get() != NULL)) {
        var_r29_733 = 1;
    }
    if (var_r29_733 != 0) {
        temp_r4_746 = this->unkC;
        temp_r4_746->unk838.unk28.Update(*((MKVector3 *) &temp_r4_746->unk588));
        sp78.GetPos();
        M2C_FIELD(this, f64 *, 0x38) = sp78;
        this->unk38 = sp80;
        sp68.GetDir();
        sp88 = sp68;
        sp90 = sp70;
    } else {
        sp38.operator*(1500.0f);
        sp48.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(this, f64 *, 0x38) = sp18;
        sp20 = sp50 + sp38.unk8;
        sp58 = sp18;
        this->unk38 = (f64) sp20;
        temp_r3_790 = this->unkC;
        sp60 = (f64) sp20;
        sp88 = M2C_FIELD(temp_r3_790, f64 *, 0xC0);
        sp90 = M2C_FIELD(temp_r3_790, f64 *, 0xC8);
    }
    temp_r3_798 = this->unkC->unkA14;
    if (temp_r3_798 != NULL) {
        M2C_FIELD(temp_r3_798, s32 *, 0x130) = 0;
    }
    this->unkC->unkA14 = ((Projectile *) (M2C_FIELD(temp_r31_696, Projectile **, 0x80)))->CreateInstance((ProjectileType) M2C_ERROR(/* Read from unset register $r4 */));
    temp_r4_808 = this->unkC;
    temp_r3_809 = temp_r4_808->unkA14;
    if (temp_r3_809 != NULL) {
        M2C_FIELD(temp_r3_809->__vptr, M2C_UNK (**)(CharacterZapFX **), 0x70)(&temp_r4_808->unkA04);
        temp_r3_819 = this->unkC->unkA14;
        M2C_FIELD(temp_r3_819->__vptr, M2C_UNK (**)(MeleeTrails *, s32), 0x6C)(temp_r3_819, M2C_FIELD(temp_r31_696, s32 *, 0x48));
        temp_r3_826 = this->unkC->unkA14;
        M2C_FIELD(temp_r3_826->__vptr, M2C_UNK (**)(MeleeTrails *, u8, f32), 0x64)(temp_r3_826, M2C_FIELD(this, u8 *, 0x48), 400.0f);
        temp_r4_832 = this->unkC;
        M2C_FIELD(temp_r4_832->unkA14, Enemy **, 0x130) = temp_r4_832;
        temp_r6_835 = M2C_FIELD(temp_r31_696, u32 *, 0x84);
        if (temp_r6_835 != -1U) {
            MKAttachment_Init(&this->unk10, this->unkC->unk4, (MKAttachmentType) 3, (s32) temp_r6_835);
            temp_r3_845 = this->unkC->unkA14;
            temp_r3_845->Deactivate();
        }
        temp_r4_851 = this->unkC;
        M2C_FIELD(temp_r4_851, f64 *, 0xE0) = sp88;
        M2C_FIELD(temp_r4_851, f64 *, 0xE8) = sp90;
        temp_r4_851->unk6B5 |= 0x40;
        temp_r3_862 = this->unkC;
        temp_r4_864 = temp_r3_862->unkA08->__vptr;
        temp_r3_862->SetAnim((AnimSequence *) temp_r4_864, (AnimTransition *) temp_r4_864, 0.15f, 0U);
        this->unk18 = M2C_FIELD(this, f64 *, 0x38);
        this->unk18 = this->unk38;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_f1_882 = (f32) sp90 * MKRand_Float(&gViewSeed, 300.0f, 500.0f);
        sp28 = sp8;
        sp10 = temp_f1_882;
        sp30 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
        var_r31_891 = 0;
        M2C_FIELD(this, f64 *, 0x20) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x20) - (f32) sp30);
        temp_r3_896 = this->unkC;
        if (((u8) M2C_FIELD(temp_r3_896, u8 *, 0x8B8) == 2) || (temp_r3_896->unk870.unk30.Get() != NULL)) {
            var_r31_891 = 1;
        }
        if (var_r31_891 != 0) {
            var_r3_915 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
        } else {
            var_r3_915 = NULL;
        }
        if (var_r3_915 != NULL) {
            var_r4_922 = this->unkC;
            if (var_r4_922 != NULL) {
                var_r4_922 += 0x6B8;
            }
            var_r3_915->Add((Targetable *) var_r4_922, 8);
        }
    } else {
        temp_r4_808->SetAnim((AnimSequenceType) 1, 0xA, 0, 0.15f, 0U, 0U);
    }
}
#endif

void EnemyGoal_AttackProjectile::Reset() {
    this->unk8 = 1;
    this->unk10.unk0 = 0;
    M2C_FIELD(this, f32 *, 0x18) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1C) = 0.0f;
    M2C_FIELD(this, f32 *, 0x20) = 0.0f;
    this->unk28.unk8 = 0.0f;
    this->unk28.unkC = 0.0f;
    M2C_FIELD(this, f32 *, 0x40) = 0.0f;
    M2C_FIELD(this, s8 *, 0x48) = 0;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_RangeAttackMode::Terminate() {
    AttackerManager *var_r3_999;
    Targetable *temp_r3_980;
    Targetable *var_r4_1006;
    u8 var_r31_975;

    var_r31_975 = 0;
    M2C_FIELD(this->unkC, s32 *, 0xA20) = 0;
    M2C_FIELD(this->unkC, s8 *, 0x6F8) = 0;
    temp_r3_980 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_980, u8 *, 0x8B8) == 2) || (((TargetContext *) ((TargetContext *) (temp_r3_980 + 0x8B0)))->Get() != NULL)) {
        var_r31_975 = 1;
    }
    if (var_r31_975 != 0) {
        var_r3_999 = M2C_FIELD(((TargetContext *) ((TargetContext *) (this->unkC + 0x8B0)))->Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_999 = NULL;
    }
    if (var_r3_999 != NULL) {
        var_r4_1006 = this->unkC;
        if (var_r4_1006 != NULL) {
            var_r4_1006 += 0x6B8;
        }
        var_r3_999->Remove(var_r4_1006, 4);
    }
    this->unk8 = 1;
    RemoveAllSubgoals();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EnemyGoal_RangeAttackMode::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void EnemyGoal_RangeAttackMode::Activate() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    AITargetData *temp_r3_1058;
    AttackerManager *temp_r3_1186;
    AttackerManager *var_r3_1146;
    Frustum *temp_r28_1085;
    Goal<Enemy> *temp_r4_1224;
    Targetable *temp_r3_1079;
    Targetable *temp_r3_1088;
    Targetable *temp_r4_1125;
    Targetable *var_r4_1153;
    f32 temp_f1_1113;
    f32 temp_f1_1202;
    s32 temp_r31_1126;
    s32 var_r29_1191;
    u8 var_r28_1062;
    u8 var_r28_1127;
    void *temp_r4_1095;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_1058 = this->unk20;
    if (temp_r3_1058 != NULL) {
        var_r28_1062 = 0;
        if (((u8) M2C_FIELD(temp_r3_1058, u8 *, 0x48) == 2) || (temp_r3_1058->unk40.Get() != NULL)) {
            var_r28_1062 = 1;
        }
        if (var_r28_1062 == 0) {
            goto block_5;
        }
        temp_r3_1079 = this->unkC;
        temp_r28_1085 = M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0;
        temp_r3_1088 = this->unkC;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_r4_1095 = M2C_FIELD(temp_r3_1088, void **, 8);
        sp20 = M2C_FIELD(temp_r3_1088, f32 *, 0xD8) * M2C_FIELD(M2C_FIELD(temp_r3_1079, void **, 0x44), f32 (**)(Targetable *, s32), 0x100)(temp_r3_1079, M2C_FIELD(&gb, s32 *, 0x3B8));
        sp28 = sp18;
        sp38 = M2C_FIELD(temp_r4_1095, f64 *, 0x30);
        sp30 = (f64) sp20;
        sp40 = M2C_FIELD(temp_r4_1095, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_f1_1113 = (f32) sp40 + (f32) sp30;
        sp48 = sp8;
        sp10 = temp_f1_1113;
        sp50 = (f64) sp10;
        temp_r4_1125 = this->unkC;
        temp_r31_1126 = temp_r28_1085->IsVisible(*((MKVector3 *) &sp48), M2C_FIELD(M2C_FIELD(temp_r3_1088, void **, 0x44), f32 (**)(Targetable *, void *, f32, f32, f64), 0x100)(temp_r3_1088, temp_r4_1095, temp_f1_1113, (f32) sp40, sp18));
        var_r28_1127 = 0;
        if (((u8) M2C_FIELD(temp_r4_1125, u8 *, 0x8B8) == 2) || (((TargetContext *) ((TargetContext *) (temp_r4_1125 + 0x8B0)))->Get() != NULL)) {
            var_r28_1127 = 1;
        }
        if (var_r28_1127 != 0) {
            var_r3_1146 = M2C_FIELD(((TargetContext *) ((TargetContext *) (this->unkC + 0x8B0)))->Get()->__vptr, AttackerManager *(**)(), 0x48)();
        } else {
            var_r3_1146 = NULL;
        }
        if (var_r3_1146 != NULL) {
            var_r4_1153 = this->unkC;
            if (var_r4_1153 != NULL) {
                var_r4_1153 += 0x6B8;
            }
            var_r3_1146->Add(var_r4_1153, 4);
        }
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (M2C_FIELD(&gb, f32 *, 0x30C) == M2C_FIELD(this->unkC, f32 *, 0xA7C)) {
            this->unkC->SelectAttack(this->unk20->GetDist(), 2U, 0U, 0U);
            if ((u32) M2C_FIELD(this->unkC, u32 *, 0xA20) != 0U) {
                temp_r3_1186 = M2C_FIELD(this->unk20->unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
                if (temp_r3_1186 != NULL) {
                    var_r29_1191 = temp_r3_1186->GetAttackerCount(8);
                } else {
                    var_r29_1191 = 0;
                }
                temp_f1_1202 = M2C_FIELD(this->unk20->unk40.Get()->__vptr, f32 (**)(), 0x40)();
                if (((var_r29_1191 > 3) && !(M2C_FIELD(this->unkC, u8 *, 0xB00) & 1)) || (((3.0f + temp_f1_1202) > M2C_FIELD(&gb, f32 *, 0x30C)) && (M2C_FIELD(&gb, f32 *, 0x30C) > 3.0f)) || ((u8) temp_r31_1126 == 0)) {
                    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
                    temp_r4_1224 = this->unk24;
                    M2C_FIELD(temp_r4_1224, s32 *, 0x10) = 1;
                    M2C_FIELD(temp_r4_1224, s32 *, 0x14) = 0xA;
                    return;
                }
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
            }
        } else {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
        }
    } else {
block_5:
        this->unk8 = 2;
    }
}
#endif

void EnemyGoal_RangeAttackMode::Deinit() {
    Goal<Enemy> *temp_r3_1260;
    Goal<Enemy> *temp_r3_1265;
    MKHeap *temp_r3_1277;
    void *temp_r31_1274;

    temp_r3_1260 = this->unk24;
    temp_r3_1260->Deinit();
    temp_r3_1265 = this->unk28;
    temp_r3_1265->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    temp_r31_1274 = this->unk1C;
    if (temp_r31_1274 != NULL) {
        temp_r3_1277 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1277 != NULL) {
            ((MKHeap *) (temp_r3_1277->Current()))->Free(temp_r31_1274, NULL, 0);
        } else {
            free(temp_r31_1274);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void EnemyGoal_RangeAttackMode::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_1391;
    Goal<Enemy> *temp_r4_1401;
    MKHeap *temp_r3_1364;
    void *var_r3_1371;

    if ((u8) this->unk9 == 0) {
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x50U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_1364 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1364 != NULL) {
            var_r3_1371 = ((MKHeap *) (temp_r3_1364->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_1371 = malloc(8);
        }
        this->unk1C = var_r3_1371;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (Targetable *) arg0;
    this->unk4 = 0x56;
    if ((Targetable *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_1391 = this->unk24;
    M2C_FIELD(temp_r4_1391, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1391, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1391, s32 *, 4) = 1;
    if ((Enemy *) M2C_FIELD(temp_r4_1391, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1391, s8 *, 9) = 1;
    }
    temp_r4_1401 = this->unk28;
    M2C_FIELD(temp_r4_1401, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1401, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1401, s32 *, 4) = 0x3B;
    if ((Enemy *) M2C_FIELD(temp_r4_1401, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1401, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_1401, f32 *, 0x28) = 0.0f;
    M2C_FIELD(temp_r4_1401, f32 *, 0x2C) = 0.0f;
    M2C_FIELD(temp_r4_1401, f32 *, 0x30) = 0.0f;
    M2C_FIELD(temp_r4_1401, f32 *, 0x18) = 0.0f;
    M2C_FIELD(temp_r4_1401, f32 *, 0x1C) = 0.0f;
    M2C_FIELD(temp_r4_1401, f32 *, 0x20) = 0.0f;
}
#endif
