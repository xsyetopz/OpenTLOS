#include "spyro/source/Enemies_IceBoss.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/EarthShockwave.h"
#include "spyro/source/ElementalShield.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/IceBossGoals.h"
#include "spyro/source/IceBossStalactite.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/ZapArcFX.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/PhrasePlayer.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 atoi(s8 *);                                     /* extern */
M2C_UNK free(s8 *);                                 /* extern */
s8 *malloc(s32);                                    /* extern */
extern s32 GS_ElecBossArmorSmash;
extern s32 GS_ElecBossExtra1;
extern s32 GS_ElecBossExtra3;
extern s32 GS_ElecBossShieldSmash;
extern s32 GS_ElecBossWeaponSmash;
extern s32 GS_IceBossArmorSmash1;
extern s32 GS_IceBossAxeSmash;
extern s32 GS_IceBossShieldSmash;
extern s32 GS_IceBossSwordSmash;
extern f32 *KDSpline_PositionMixer;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern u32 gb;
extern void *gpTranslation_StringArray;
extern IceBossDescriptor *pIceBossDesc;
static s32 fIceBossStageHealth[0xF] = {
    0x3F800000,
    0x3F4CCCCD,
    0x3F19999A,
    0x3ECCCCCD,
    0x3E4CCCCD,
    0x3F800000,
    0x3F4CCCCD,
    0x3F19999A,
    0x3ECCCCCD,
    0x3E4CCCCD,
    0x3F800000,
    0x3F4CCCCD,
    0x3F19999A,
    0x3ECCCCCD,
    0x3E4CCCCD,
};
static s32 lit_248 = 0;
static u8 lit_249 = 0;

static f32 fWeaponVulMult = 5.0f;
static f32 fSwordStuckDelay = 2.0f;
static f32 fStalactiteDelay = 10.0f;
static f32 fStalactiteHeight = 15.0f;
static f32 fIceWaveDelay = 10.0f;
static f32 fIceBreathDelay = 10.0f;
static f32 fIceWaveSpeed = 10.0f;
static s32 iStalactiteGemsH = 1;
static s32 iStalactiteGemsM = 1;
static s32 iStalactiteGemsS = 1;
static s32 iStalactiteGemsF = 1;

static u8 lit_1160 = 1;
static u8 lit_1266 = 1;
#if 0 // DRAFT: illegal return value in void/constructor/destructor function
static M2C_UNK lit_752;                                /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_753;                                /* unable to generate initializer: unknown type; const */

static s32 lit_959 = 0x10000;                          /* const */

void IceBoss::GetCharacterName() {
    if (IsIceKing() != 0) {
        return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x328);
    }
    return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x368);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void IceBoss::UpdateWeaponCollisionCapsule() {
    Matrix sp70;
    f64 sp68;
    f64 sp60;
    MKVector3 sp50;
    f64 sp48;
    f64 sp40;
    MKVector3 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;

    CalcSubObjWorldMatrix(M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s32 *, 0xE44), &sp70);
    sp50.operator*(M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), f32 *, 0xE64));
    sp20 = sp70.unk30 + M2C_BITWISE(f64, sp50);
    M2C_FIELD(this, f64 *, 0xF60) = sp20;
    sp28 = sp70.unk38 + sp50.unk8;
    sp60 = sp20;
    M2C_FIELD(this, f64 *, 0xF68) = (f64) sp28;
    sp68 = (f64) sp28;
    sp30.operator*(M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), f32 *, 0xE68));
    sp10 = sp70.unk30 - M2C_BITWISE(f64, sp30);
    M2C_FIELD(this, f64 *, 0xF70) = sp10;
    sp18 = sp70.unk38 - sp30.unk8;
    sp40 = sp10;
    sp48 = (f64) sp18;
    this->unkF60 = (f64) sp18;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void IceBoss::CalcSubObjWorldMatrix(int arg0, Matrix *arg1) {
    Matrix sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    void *temp_r3_185;

    MKModel_CalculateSubObjectLocalToWorldMatrix(this->unk4, (SubObjectType) 0, M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s32 *, 0xE44), &sp40);
    temp_r3_185 = MKModel_GetSubObjectOrigin(this->unk4, (SubObjectType) 0, M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s32 *, 0xE44));
    sp30 = M2C_FIELD(temp_r3_185, f64 *, 0);
    sp38 = M2C_FIELD(temp_r3_185, f64 *, 8);
    sp10 = ((f32) sp38 * sp40.unk20) + (((f32) sp30 * M2C_BITWISE(f32, sp40)) + (unksp34 * sp40.unk10));
    sp14 = ((f32) sp38 * sp40.unk24) + (((f32) sp30 * sp40.unk4) + (unksp34 * sp40.unk14));
    sp18 = ((f32) sp38 * sp40.unk28) + (((f32) sp30 * sp40.unk8) + (unksp34 * sp40.unk18));
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40.Translate(&sp40, *((MKVector3 *) &sp30));
    M2C_STRUCT_COPY((s32) (arg1 - 4) + 4, (s32) &unksp3C + 4, 0x40);
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
s32 IceBoss::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    Matrix sp50;
    f64 sp48;
    f64 sp40;
    f64 sp30;
    f64 sp20;
    f32 sp18;
    f64 sp10;

    if (((u8) M2C_FIELD(this, u8 *, 0xFB8) != 0) && (arg1 != NULL)) {
        CalcSubObjWorldMatrix(M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s32 *, 0xE44), &sp50);
        M2C_FIELD(arg1, f64 *, 0) = (f64) sp50.unk30;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp50.unk38;
        return 1;
    }
    if (arg1 != NULL) {
        MKVector(0.0f, 0.75f * GetCollisionHeight(), 0.0f);
        ((MKProp *) &sp30)->GetPos();
        sp10 = sp30 + sp20;
        M2C_FIELD(arg1, f64 *, 0) = sp10;
        sp18 = sp38 + sp28;
        sp40 = sp10;
        sp48 = (f64) sp18;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp18;
        return 1;
    }
    return 0;
}
#endif

s32 IceBoss::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    Matrix sp10;

    if (((u8) M2C_FIELD(this, u8 *, 0xFB8) != 0) && (arg1 != NULL)) {
        CalcSubObjWorldMatrix(M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s32 *, 0xE44), &sp10);
        M2C_FIELD(arg1, f64 *, 0) = (f64) sp10.unk30;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp10.unk38;
        return 1;
    }
    return Enemy::GetLookToPoint(arg0, arg1);
}

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void IceBoss::UpdateBreathingFx() {
    s32 temp_r3_382;

    if (((u8) this->unkB08 != 0) || ((u8) M2C_FIELD(this, u8 *, 0xFBB) != 0)) {
        M2C_FIELD(this->unk9E8.unk10, f32 *, 8) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float(&gViewSeed, 1.75f, 2.0f));
        temp_r3_382 = this->unk9E8.unk10;
        M2C_FIELD(temp_r3_382, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r3_382, u8 *, 0x10) & ~0x80);
    }
}
#endif

void IceBoss::EnableWeaponCollision(bool arg0) {
    M2C_FIELD(this, u8 *, 0xFB8) = arg0;
    if (arg0 != 0) {
        M2C_FIELD(M2C_FIELD(this, void **, 0xF90), s8 *, 4) = 1;
        return;
    }
    M2C_FIELD(M2C_FIELD(this, void **, 0xF90), s8 *, 4) = 0;
}

#if 0 // DRAFT: illegal operand
void IceBoss::UpdateSummonWeapon() {
    Matrix sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f3_489;
    f32 var_f0_467;
    f32 var_f31_477;
    f64 temp_f0_486;
    f64 temp_f0_497;
    f64 temp_f2_485;
    s32 temp_r3_530;
    void *temp_r3_438;
    void *temp_r3_539;

    if (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(7) != 0) {
        *(this + ((M2C_FIELD(this, s32 *, 0xB18) * 0x28) + 0xE58)) = M2C_FIELD(&gb, f32 *, 0x30C) + 1.0f;
        temp_r3_438 = M2C_FIELD(this, void **, 0xF94);
        M2C_FIELD(M2C_FIELD(temp_r3_438, void **, 0x44), M2C_UNK (**)(void *, f32), 0x30)(temp_r3_438, M2C_FIELD(&gb, f32 *, 0x30C));
        M2C_FIELD(this, u8 *, 0xFBB) = 1U;
    }
    if ((u8) M2C_FIELD(this, u8 *, 0xFBB) != 0) {
        CalcSubObjWorldMatrix(M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s32 *, 0xE44), &sp70);
        var_f0_467 = 1.0f - ((*(this + ((M2C_FIELD(this, s32 *, 0xB18) * 0x28) + 0xE58)) - M2C_FIELD(&gb, f32 *, 0x30C)) / 1.0f);
        if (var_f0_467 < 1.0f) {

        } else {
            var_f0_467 = 1.0f;
        }
        if (var_f0_467 > 0.0f) {
            var_f31_477 = var_f0_467;
        } else {
            var_f31_477 = 0.0f;
        }
        temp_f2_485 = M2C_FIELD(this, f64 *, 0xF10);
        temp_f0_486 = sp70.unk30 - temp_f2_485;
        sp30 = temp_f0_486;
        temp_f3_489 = this->unkEE0.unk20;
        sp50 = temp_f0_486;
        sp38 = sp70.unk38 - temp_f3_489;
        sp58 = (f64) sp38;
        temp_f0_497 = temp_f0_486 * (f64) var_f31_477;
        sp20 = temp_f0_497;
        sp40 = temp_f0_497;
        sp28 = (f32) sp58 * var_f31_477;
        sp48 = (f64) sp28;
        sp10 = temp_f2_485 + temp_f0_497;
        sp60 = sp10;
        sp18 = temp_f3_489 + (f32) sp48;
        this->unkF20.unk18 = (f32) sp60;
        sp68 = (f64) sp18;
        this->unkF20.unk1C = unksp64;
        this->unkF20.unk20 = (f32) sp68;
        this->unkF20.unk24 = 1.0f;
        MKModel_SetWorldMatrix(M2C_FIELD(M2C_FIELD(this, void **, 0xF94), MKModel **, 4), *((Matrix *) &this->unkEE0.unk28));
        temp_r3_530 = M2C_FIELD(this, s32 *, 0xB18) * 0x28;
        if (M2C_FIELD(&gb, f32 *, 0x30C) >= *(this + (temp_r3_530 + 0xE58))) {
            M2C_FIELD((this + temp_r3_530), s8 *, 0xE54) = 0;
            temp_r3_539 = M2C_FIELD(this, void **, 0xF94);
            M2C_FIELD(M2C_FIELD(temp_r3_539, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_539);
            M2C_FIELD(this, u8 *, 0xFBB) = 0U;
        }
    }
    if (HasAnimFinished() != 0) {
        SetAnim((AnimSequenceType) 1, 0, 0, 0.15f, 0U, 0U);
        M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s8 *, 0xE55) = 0;
    }
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void IceBoss::SummonWeapon() {
    Matrix sp50;
    M2C_UNK sp4C;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f64 temp_f0_633;
    u8 *temp_r3_635;
    void *temp_r3_607;

    SetAnim((AnimSequenceType) 0x12, 0xCD, 0, 0.15f, 4U, 0U);
    M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s8 *, 0xE55) = 1;
    CalcSubObjWorldMatrix(M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s32 *, 0xE44), &sp50);
    temp_r3_607 = this->unk8;
    sp20 = -M2C_FIELD(temp_r3_607, f32 *, 0);
    sp24 = -M2C_FIELD(temp_r3_607, f32 *, 4);
    sp28 = -M2C_FIELD(temp_r3_607, f32 *, 8);
    sp40 = (f64) sp20;
    sp48 = (f64) sp28;
    M2C_STRUCT_COPY((s32) &this->unkEC4 + 4, (s32) &sp4C + 4, 0x40);
    temp_f0_633 = sp40 * 5.7700341e-315;
    sp10 = temp_f0_633;
    temp_r3_635 = &this->unkEC8;
    sp30 = temp_f0_633;
    sp18 = (f32) sp48 * 5000.0f;
    sp38 = (f64) sp18;
    ((Matrix *) temp_r3_635)->Translate((Matrix *) temp_r3_635, *((MKVector3 *) &sp30));
    M2C_STRUCT_COPY((s32) &this->unkEE0.unk24 + 4, (s32) &this->unkEC4 + 4, 0x40);
    M2C_FIELD(this, s8 *, 0xFBB) = 0;
}
#endif

#if 0 // DRAFT: illegal type
void IceBoss::DestroyShield() {
    u32 temp_r5_715;

    M2C_FIELD(this, s8 *, 0xEC8) = 1;
    M2C_FIELD(this, s8 *, 0xECA) = 1;
    M2C_FIELD(this, s8 *, 0xEC9) = 0;
    ShatterSubObj(this->unkEBC, this->unkED0);
    if (IsIceKing() != 0) {
        KDSound_Play3d(GS_IceBossShieldSmash, this->unkED0->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    } else {
        KDSound_Play3d(GS_ElecBossShieldSmash, this->unkED0->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    }
    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, this->unkEBC, 0U, 1U);
    temp_r5_715 = this->unkEC0;
    if (temp_r5_715 != -1U) {
        MKModel_EnableSubObject(this->unk4, (SubObjectType) 1, (s32) temp_r5_715, 0U, 1U);
    }
    this->unkED0->unk84 = M2C_BITWISE(f32, this->unkF90);
    this->unkFB4 = M2C_FIELD(&gb, f32 *, 0x30C) + 5.0f;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKCollisionInfo *' to
void IceBoss::UpdateFormShield() {
    Matrix spF0;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f1_782;
    f32 temp_f2_781;
    f32 var_f0_786;
    f64 temp_f0_861;

    if (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(7) != 0) {
        M2C_FIELD(this, u8 *, 0xFBA) = 1U;
        this->unkB08 = 1;
    }
    if (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(8) != 0) {
        this->unkB08 = 0;
        M2C_FIELD(this, u8 *, 0xFBA) = 0U;
        M2C_FIELD(this, s8 *, 0xEC8) = 0;
        this->unkAB8 = M2C_FIELD(this->unkA20, f32 *, 0xEC);
        this->unkF98 = M2C_BITWISE(f32, this->unkF90);
    }
    if ((u8) M2C_FIELD(this, u8 *, 0xFBA) != 0) {
        temp_f2_781 = M2C_BITWISE(f32, this->unkF94);
        temp_f1_782 = M2C_BITWISE(f32, this->unkF90);
        if (temp_f2_781 < temp_f1_782) {
            var_f0_786 = (gUpdateTimeDelta * temp_f1_782) + temp_f2_781;
            if (var_f0_786 < temp_f1_782) {

            } else {
                var_f0_786 = temp_f1_782;
            }
            this->unkF94 = var_f0_786;
        }
    }
    this->unkF98 = M2C_BITWISE(f32, this->unkF94);
    if ((u8) this->unkB08 != 0) {
        if (IsIceKing() != 0) {
            ((CharacterBreathFX *) this->unk9E8.unk10)->EmitBreathFx(2, 1000.0f, 0.2f, 0.5f, 0.0f, 0.5235987f);
            return;
        }
        if (IsIceKing() == 0) {
            MKModel_GetRefPointMatrix(this->unk4, **this->unk9E8.unk10, &spF0, 1U);
            sp70 = -1.0f;
            sp40 = -spF0.unk28;
            sp60 = 1.0f;
            sp38 = -spF0.unk20;
            sp3C = -spF0.unk24;
            sp68 = -1.0f;
            sp6C = -1.0f;
            sp58 = 1.0f;
            sp5C = 1.0f;
            sp88 = (f64) sp38;
            sp90 = (f64) sp40;
            spA8 = (f64) sp68;
            spB0 = (f64) sp70;
            sp98 = (f64) sp58;
            spA0 = (f64) sp60;
            KDRand_Vector(spB8, *((MKVector3 *) &spA8));
            temp_f0_861 = spB8 * 5.222099017e-315;
            sp48 = temp_f0_861;
            spC8 = temp_f0_861;
            sp50 = spB8.unk8 * 0.5f;
            spD0 = (f64) sp50;
            sp28 = spC8 + sp88;
            sp18 = 1.0f;
            sp1C = 0.0f;
            sp30 = (f32) spD0 + (f32) sp90;
            sp20 = 0.5f;
            sp24 = 1.0f;
            spD8 = sp28;
            spE0 = (f64) sp30;
            sp78 = (f64) sp18;
            sp80 = (f64) sp20;
            sp10 = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
            ((ZapArcFX *) (M2C_FIELD(&gb, ZapArcFX **, 0x94)))->Trigger(*((MKVector3 *) &spF0.unk30), *((MKVector3 *) &spD8), sp10, lit_1266, (MKVector4) &sp78);
            this->unk1064 = 1;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void IceBoss::FormShield() {
    M2C_FIELD(this, s8 *, 0xEC9) = 1;
    M2C_FIELD(this, s8 *, 0xFBA) = 0;
    this->unkF94 = 0.0f;
    this->unkF98 = 0.0f;
}
#endif

#if 0 // DRAFT: function call 'KDSound_Play3d(long, long, unsigned int, int, float,
void IceBoss::DestroyWeapon() {
    s32 temp_r0_939;
    u32 temp_r5_1061;
    void *temp_r5_1039;

    temp_r0_939 = M2C_FIELD(this, s32 *, 0xB18);
    switch (temp_r0_939) {                          /* irregular */
    case 2:
        if ((u8) M2C_FIELD((this + (temp_r0_939 * 0x28)), u8 *, 0xE54) == 0) {
            if (IsIceKing() != 0) {
                KDSound_Play3d(GS_IceBossSwordSmash, M2C_FIELD(M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), void **, 0xE60), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
            } else {
                KDSound_Play3d(GS_ElecBossWeaponSmash, M2C_FIELD(M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), void **, 0xE60), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
        break;
    case 1:
        if ((u8) M2C_FIELD((this + (temp_r0_939 * 0x28)), u8 *, 0xE54) == 0) {
            if (IsIceKing() != 0) {
                KDSound_Play3d(GS_IceBossAxeSmash, M2C_FIELD(M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), void **, 0xE60), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
            } else {
                KDSound_Play3d(GS_ElecBossWeaponSmash, M2C_FIELD(M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), void **, 0xE60), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
        break;
    }
    M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s8 *, 0xE54) = 1;
    M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s8 *, 0xE56) = 1;
    M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s8 *, 0xE55) = 0;
    temp_r5_1039 = this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28);
    ShatterSubObj(M2C_FIELD(temp_r5_1039, s32 *, 0xE44), M2C_FIELD(temp_r5_1039, Shatterable **, 0xE60));
    M2C_FIELD(M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), void **, 0xE60), f32 *, 0x84) = M2C_BITWISE(f32, this->unkF90);
    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s32 *, 0xE44), 0U, 1U);
    temp_r5_1061 = M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), u32 *, 0xE48);
    if (temp_r5_1061 != -1U) {
        MKModel_EnableSubObject(this->unk4, (SubObjectType) 1, (s32) temp_r5_1061, 0U, 1U);
    }
    this->unkFB0 = M2C_FIELD(&gb, f32 *, 0x30C) + 5.0f;
}
#endif

#if 0 // DRAFT: illegal operands 'IceBossDescriptor' != 'float'
void IceBoss::UpdatePhrasesAndSounds() {
    EnemyAttack *temp_r3_1099;
    f32 temp_f1_1193;
    f32 temp_f30_1110;
    f32 temp_f30_1125;
    f32 temp_f31_1106;
    s32 var_r29_1131;
    s32 var_r30_1132;

    temp_r3_1099 = this->unkA20;
    temp_f31_1106 = this->unkAB0;
    temp_f30_1110 = (f32) M2C_FIELD(temp_r3_1099, s32 *, 0x11C) * ((EnemyDescriptor *) this->unkA20)->GetEnemySetting((EnemySettingType) 0);
    temp_f30_1125 = ((temp_f30_1110 - ((f32) (M2C_BITWISE(s32, this->unkAD0) + 1) * ((EnemyDescriptor *) temp_r3_1099)->GetEnemySetting((EnemySettingType) 0))) + temp_f31_1106) / temp_f30_1110;
    if (temp_f30_1125 > this->unk1008) {
        this->unk1008 = temp_f30_1125;
    }
    var_r29_1131 = 0;
    var_r30_1132 = 0;
loop_3:
    if ((temp_f30_1125 != 0.0f) && (*(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_1132 + 0x300)) != 0.0f) && (this->unk1008 > *(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_1132 + 0x300))) && (temp_f30_1125 <= *(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_1132 + 0x300)))) {
        this->unkFF4 = M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x34C);
        this->unkFEC.unk0 = checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_1132 + 0x2E0);
    } else {
        var_r29_1131 += 1;
        var_r30_1132 += 0x24;
        if (var_r29_1131 < 3) {
            goto loop_3;
        }
    }
    if ((M2C_BITWISE(f32, this->unkFF4) < 0.0f) && ((u32) this->unkFEC.unk0 != 0U) && (PhrasePlayer_IsAnyEventPlaying() == 0)) {
        this->unkFE8.unk0 = PhrasePlayer_PlayEvent((s8 *) this->unkFEC.unk0);
        this->unkFF4 = 0.0f;
        this->unkFEC.unk0 = 0;
    }
    this->unk1008 = temp_f30_1125;
    temp_f1_1193 = M2C_BITWISE(f32, this->unkFF4);
    if (temp_f1_1193 > 0.0f) {
        this->unkFF4 = temp_f1_1193 - gUpdateTimeDelta;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'spE0'
void IceBoss::CheckAnimEvents() {
    Matrix sp160;
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
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
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
    f32 sp10;
    CharacterFireFX *temp_r4_1326;
    f32 var_f1_1321;
    f64 temp_f0_1253;
    f64 temp_f0_1265;
    f64 temp_f0_1345;
    f64 temp_f2_1344;
    s32 temp_r0_1328;
    s32 temp_r0_1355;
    s32 var_r30_1267;
    void *temp_r3_1320;
    void *temp_r3_1342;

    if (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(0xD) != 0) {
        CalcSubObjWorldMatrix(M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s32 *, 0xE44), &sp160);
        sp78 = -sp160.unk20;
        sp7C = -sp160.unk24;
        sp80 = -sp160.unk28;
        spF8 = (f64) sp78;
        sp100 = (f64) sp80;
        temp_f0_1253 = spF8 * 5.5769738e-315;
        sp68 = temp_f0_1253;
        sp108 = temp_f0_1253;
        sp70 = (f32) sp100 * 200.0f;
        sp110 = (f64) sp70;
        temp_f0_1265 = sp160.unk30 + temp_f0_1253;
        sp58 = temp_f0_1265;
        var_r30_1267 = 0;
        sp148 = temp_f0_1265;
        sp60 = sp160.unk38 + (f32) sp110;
        sp150 = (f64) sp60;
        do {
            KDRand_UnitVectorXZ();
            sp48 = spD8 * 5.60222949e-315;
            spE8 = sp48;
            sp50 = spE0 * 300.0f;
            sp138 = sp48;
            spF0 = (f64) sp50;
            sp140 = (f64) sp50;
            unksp13C = 100.0f * MKRand_Float(&gViewSeed, 10.0f, 17.0f);
            sp10 = MKRand_Float(&gViewSeed, 1.0f, 3.0f);
            this->unk1068->Emit(*((MKVector3 *) &sp148), *((MKVector3 *) &sp138), sp10);
            var_r30_1267 += 1;
        } while (var_r30_1267 < 0x14);
        return;
    }
    if (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(0xB) != 0) {
        temp_r3_1320 = this->unk8;
        var_f1_1321 = 0.5f;
        sp128 = M2C_FIELD(temp_r3_1320, f64 *, 0x30);
        sp130 = M2C_FIELD(temp_r3_1320, f64 *, 0x38);
        temp_r4_1326 = this->unkA08;
        temp_r0_1328 = M2C_FIELD(temp_r4_1326->__vptr, s32 *, 0x68);
        switch (temp_r0_1328) {                     /* switch 1; irregular */
        case 0x3E:                                  /* switch 1 */
            MKModel_CalculateRefPointWorldPosition(this->unk4, *M2C_FIELD(temp_r4_1326, s32 **, 0x7C), (MKVector3 *) &sp128);
            /* fallthrough */
        case 0x97:                                  /* switch 1 */
            temp_r3_1342 = this->unk8;
            var_f1_1321 = 2.0f;
            temp_f2_1344 = M2C_FIELD(temp_r3_1342, f64 *, 0x30);
            temp_f0_1345 = M2C_FIELD(temp_r3_1342, f64 *, 0x38);
            spC8 = temp_f2_1344;
            spD0 = temp_f0_1345;
            sp128 = temp_f2_1344;
            sp130 = temp_f0_1345;
            break;
        }
        sp38 = 0.5f;
        temp_r0_1355 = M2C_FIELD(this->unkA20, s32 *, 0x1D0);
        sp3C = 0.5f;
        sp40 = 1.0f;
        sp44 = 1.0f;
        spB8 = (f64) sp38;
        spC0 = (f64) sp40;
        sp118 = (f64) sp38;
        sp120 = (f64) sp40;
        switch (temp_r0_1355) {                     /* switch 2; irregular */
        case 2:                                     /* switch 2 */
            sp28 = 0.5f;
            sp2C = 0.5f;
            sp30 = 1.0f;
            sp34 = 1.0f;
            spA8 = (f64) sp28;
            spB0 = (f64) sp30;
            sp118 = (f64) sp28;
            sp120 = (f64) sp30;
            break;
        case 1:                                     /* switch 2 */
            sp18 = 1.0f;
            sp1C = 0.1f;
            sp20 = 0.5f;
            sp24 = 1.0f;
            sp98 = (f64) sp18;
            spA0 = (f64) sp20;
            sp118 = (f64) sp18;
            sp120 = (f64) sp20;
            break;
        }
        sp88 = sp118;
        sp90 = sp120;
        ((EarthShockwave *) this->unkFDC)->Trigger(*((MKVector3 *) &sp128), var_f1_1321, 0U, (MKVector4) &sp88);
        return;
    }
    Enemy::CheckAnimEvents();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void IceBoss::UpdateFormWeapon() {
    Matrix spF0;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f1_1466;
    f32 temp_f2_1465;
    f32 var_f0_1470;
    f64 temp_f0_1545;

    if (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(7) != 0) {
        M2C_FIELD(this, u8 *, 0xFB9) = 1U;
        this->unkB08 = 1;
        M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s8 *, 0xE54) = 0;
        this->unkF9C = 0.0f;
    }
    if (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(8) != 0) {
        this->unkB08 = 0;
        M2C_FIELD(this, u8 *, 0xFB9) = 0U;
        this->unkF9C = M2C_BITWISE(f32, this->unkF90);
    }
    if ((u8) M2C_FIELD(this, u8 *, 0xFB9) != 0) {
        temp_f2_1465 = M2C_BITWISE(f32, this->unkF94);
        temp_f1_1466 = M2C_BITWISE(f32, this->unkF90);
        if (temp_f2_1465 < temp_f1_1466) {
            var_f0_1470 = (gUpdateTimeDelta * temp_f1_1466) + temp_f2_1465;
            if (var_f0_1470 < temp_f1_1466) {

            } else {
                var_f0_1470 = temp_f1_1466;
            }
            this->unkF94 = var_f0_1470;
        }
    }
    this->unkF9C = M2C_BITWISE(f32, this->unkF94);
    if ((u8) this->unkB08 != 0) {
        if (IsIceKing() != 0) {
            ((CharacterBreathFX *) this->unk9E8.unk10)->EmitBreathFx(2, 1000.0f, 0.2f, 0.5f, 0.0f, 0.5235987f);
            return;
        }
        if (IsIceKing() == 0) {
            MKModel_GetRefPointMatrix(this->unk4, **this->unk9E8.unk10, &spF0, 1U);
            sp70 = -1.0f;
            sp40 = -spF0.unk28;
            sp60 = 1.0f;
            sp38 = -spF0.unk20;
            sp3C = -spF0.unk24;
            sp68 = -1.0f;
            sp6C = -1.0f;
            sp58 = 1.0f;
            sp5C = 1.0f;
            sp88 = (f64) sp38;
            sp90 = (f64) sp40;
            spA8 = (f64) sp68;
            spB0 = (f64) sp70;
            sp98 = (f64) sp58;
            spA0 = (f64) sp60;
            KDRand_Vector(spB8, *((MKVector3 *) &spA8));
            temp_f0_1545 = spB8 * 5.222099017e-315;
            sp48 = temp_f0_1545;
            spC8 = temp_f0_1545;
            sp50 = spB8.unk8 * 0.5f;
            spD0 = (f64) sp50;
            sp28 = spC8 + sp88;
            sp18 = 1.0f;
            sp1C = 0.0f;
            sp30 = (f32) spD0 + (f32) sp90;
            sp20 = 0.5f;
            sp24 = 1.0f;
            spD8 = sp28;
            spE0 = (f64) sp30;
            sp78 = (f64) sp18;
            sp80 = (f64) sp20;
            sp10 = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
            ((ZapArcFX *) (M2C_FIELD(&gb, ZapArcFX **, 0x94)))->Trigger(*((MKVector3 *) &spF0.unk30), *((MKVector3 *) &spD8), sp10, lit_1160, (MKVector4) &sp78);
            this->unk1064 = 1;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void IceBoss::FormWeapon() {
    M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s8 *, 0xE55) = 1;
    M2C_FIELD(this, s8 *, 0xFB9) = 0;
    this->unkF94 = 0.0f;
    this->unkF9C = 0.0f;
}
#endif

void IceBoss::UpdateWeapons() {
    s32 var_r29_1626;
    s32 var_r31_1627;
    u32 temp_r5_1630;
    u32 temp_r5_1646;
    u32 temp_r5_1660;
    void *temp_r30_1629;

    var_r29_1626 = 0;
    var_r31_1627 = 0;
    do {
        temp_r30_1629 = this + var_r31_1627;
        temp_r5_1630 = M2C_FIELD(temp_r30_1629, u32 *, 0xE48);
        if (temp_r5_1630 != -1U) {
            MKModel_EnableSubObject(this->unk4, (SubObjectType) 1, (s32) temp_r5_1630, 0U, 1U);
        }
        if (((s32) M2C_FIELD(this, s32 *, 0xB18) == var_r29_1626) && ((u8) M2C_FIELD(temp_r30_1629, u8 *, 0xE54) == 0)) {
            temp_r5_1646 = M2C_FIELD(temp_r30_1629, u32 *, 0xE48);
            if (temp_r5_1646 != -1U) {
                MKModel_EnableSubObject(this->unk4, (SubObjectType) 1, (s32) temp_r5_1646, 1U, 1U);
            }
        }
        var_r29_1626 += 1;
        var_r31_1627 += 0x28;
    } while (var_r29_1626 < 3);
    temp_r5_1660 = this->unkEC0;
    if (temp_r5_1660 != -1U) {
        MKModel_EnableSubObject(this->unk4, (SubObjectType) 1, (s32) temp_r5_1660, M2C_FIELD(this, u8 *, 0xEC8) == 0, 1U);
    }
    if ((u8) M2C_FIELD(this, u8 *, 0xFB8) != 0) {
        M2C_FIELD(M2C_FIELD(this, void **, 0xF90), s8 *, 4) = 1;
        UpdateWeaponCollisionCapsule();
        return;
    }
    M2C_FIELD(M2C_FIELD(this, void **, 0xF90), s8 *, 4) = 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void IceBoss::ShatterSubObj(int arg0, Shatterable *arg1) {
    Matrix sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    void *temp_r3_1714;

    MKModel_CalculateSubObjectLocalToWorldMatrix(this->unk4, (SubObjectType) 0, arg0, &sp40);
    temp_r3_1714 = MKModel_GetSubObjectOrigin(this->unk4, (SubObjectType) 0, arg0);
    sp30 = M2C_FIELD(temp_r3_1714, f64 *, 0);
    sp38 = M2C_FIELD(temp_r3_1714, f64 *, 8);
    sp10 = ((f32) sp38 * sp40.unk20) + (((f32) sp30 * M2C_BITWISE(f32, sp40)) + (unksp34 * sp40.unk10));
    sp14 = ((f32) sp38 * sp40.unk24) + (((f32) sp30 * sp40.unk4) + (unksp34 * sp40.unk14));
    sp18 = ((f32) sp38 * sp40.unk28) + (((f32) sp30 * sp40.unk8) + (unksp34 * sp40.unk18));
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40.Translate(&sp40, *((MKVector3 *) &sp30));
    arg1->Enable();
    MKModel_SetWorldMatrix(arg1->unk4, sp40);
    arg1->Reset();
    arg1->Shatter(0, 0, -1, 0, 1, 0);
}
#endif

#if 0 // DRAFT: illegal type
void IceBoss::ShatterBodyParts() {
    Shatterable *temp_r5_1804;
    s32 var_r29_1793;
    s32 var_r31_1794;
    void *temp_r30_1796;

    var_r29_1793 = 0;
    var_r31_1794 = 0;
    do {
        temp_r30_1796 = this + var_r31_1794;
        if (((s32) this->unkAFC >= (s32) M2C_FIELD(temp_r30_1796, s32 *, 0xB50)) && ((u8) M2C_FIELD(temp_r30_1796, u8 *, 0xB58) == 0)) {
            temp_r5_1804 = M2C_FIELD(temp_r30_1796, Shatterable **, 0xB60);
            if (temp_r5_1804 != NULL) {
                ShatterSubObj(M2C_FIELD(temp_r30_1796, s32 *, 0xB44), temp_r5_1804);
                M2C_FIELD(temp_r30_1796, u8 *, 0xB58) = 1U;
                if (IsIceKing() != 0) {
                    KDSound_Play3d(GS_IceBossArmorSmash1, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                } else {
                    KDSound_Play3d(GS_ElecBossArmorSmash, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                }
            }
        }
        var_r29_1793 += 1;
        var_r31_1794 += 0x20;
    } while (var_r29_1793 < 0x18);
    if (((s32) this->unkAFC >= (s32) this->unkEC4) && ((u8) M2C_FIELD(this, u8 *, 0xECA) == 0) && ((u8) M2C_FIELD(this, u8 *, 0xEC8) == 0)) {
        ShatterSubObj(this->unkEBC, this->unkED0);
        M2C_FIELD(this, u8 *, 0xEC8) = 1U;
        M2C_FIELD(this, u8 *, 0xECA) = 1U;
        if (IsIceKing() != 0) {
            KDSound_Play3d(GS_IceBossShieldSmash, this->unkED0->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            return;
        }
        KDSound_Play3d(GS_ElecBossShieldSmash, this->unkED0->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    }
}
#endif

void IceBoss::UpdateBodyParts() {
    MKModel *temp_r3_1896;
    s32 temp_r4_1918;
    s32 var_r29_1910;
    s32 var_r31_1911;
    u32 temp_r5_1914;
    u32 temp_r5_1944;
    u8 var_r28_1929;
    u8 var_r3_1919;
    void *temp_r30_1913;

    temp_r3_1896 = this->unk4;
    if (temp_r3_1896 != NULL) {
        MKModel_EnableOnlySubObject(temp_r3_1896, (SubObjectType) this->unkB1C, this->unkB24, 1U, 1U);
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 1, (s32) this->unkB10, 1U, 1U);
        var_r29_1910 = 0;
        var_r31_1911 = 0;
        do {
            temp_r30_1913 = this + var_r31_1911;
            temp_r5_1914 = M2C_FIELD(temp_r30_1913, u32 *, 0xB44);
            if (temp_r5_1914 != -1U) {
                temp_r4_1918 = this->unkAFC;
                var_r3_1919 = 0;
                if ((temp_r4_1918 >= (s32) M2C_FIELD(temp_r30_1913, s32 *, 0xB4C)) && (temp_r4_1918 < (s32) M2C_FIELD(temp_r30_1913, s32 *, 0xB50))) {
                    var_r3_1919 = 1;
                }
                var_r28_1929 = var_r3_1919;
                if ((var_r29_1910 == 0) && (temp_r4_1918 == (s32) M2C_FIELD(temp_r30_1913, s32 *, 0xB50)) && ((u8) M2C_FIELD(this, u8 *, 0xFBE) != 0)) {
                    var_r28_1929 = 1;
                }
                MKModel_EnableSubObject(this->unk4, (SubObjectType) M2C_FIELD(temp_r30_1913, s32 *, 0xB54), (s32) temp_r5_1914, var_r28_1929, 1U);
                temp_r5_1944 = M2C_FIELD(temp_r30_1913, u32 *, 0xB48);
                if (temp_r5_1944 != -1U) {
                    MKModel_EnableSubObject(this->unk4, (SubObjectType) 1, (s32) temp_r5_1944, var_r28_1929, 1U);
                }
            }
            var_r29_1910 += 1;
            var_r31_1911 += 0x20;
        } while (var_r29_1910 < 0x18);
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void IceBoss::InterceptDamage(bool *arg0) {
    s32 temp_r0_2012;
    s32 temp_r5_1988;
    s32 var_r0_1989;
    s32 var_r7_1976;
    void *var_r6_1984;

    if ((u8) M2C_FIELD(this, u8 *, 0xFBE) != 0) {
        this->unk9D8 = 0;
        this->unk9D4 = 0;
    }
    var_r7_1976 = 0;
loop_13:
    temp_r0_2012 = this->unk9D4;
    if (var_r7_1976 < temp_r0_2012) {
        if ((var_r7_1976 < 0) || (var_r7_1976 >= temp_r0_2012)) {
            var_r6_1984 = NULL;
        } else {
            temp_r5_1988 = this->unk9D0;
            var_r0_1989 = this->unk9D8 + var_r7_1976;
            if (var_r0_1989 >= temp_r5_1988) {
                var_r0_1989 -= temp_r5_1988;
            }
            var_r6_1984 = this->unk9DC + (var_r0_1989 * 0x38);
        }
        M2C_FIELD(var_r6_1984, u8 *, 0x34) = (u8) (M2C_FIELD(var_r6_1984, u8 *, 0x34) & ~0x80);
        if ((arg0 != NULL) && ((u8) M2C_FIELD(this, u8 *, 0xFB8) != 0)) {
            *arg0 = 1;
        }
        var_r7_1976 += 1;
        goto loop_13;
    }
}
#endif

s32 IceBoss::TryChangeStage() {
    f32 temp_f1_2026;
    f32 temp_r0_2049;
    s32 temp_r0_2125;
    s32 temp_r31_2027;

    temp_f1_2026 = GetHealthPercentage();
    temp_r31_2027 = this->unkAFC;
    if ((temp_r31_2027 != 4) && (temp_r31_2027 != 9) && (temp_r31_2027 != 0xE) && (temp_f1_2026 <= M2C_FIELD(&fIceBossStageHealth[temp_r31_2027], f32 *, 4))) {
        this->unkAFC = temp_r31_2027 + 1;
    }
    if (temp_f1_2026 <= 0.0f) {
        temp_r0_2049 = this->unkAD0;
        switch (M2C_BITWISE(s32, temp_r0_2049)) {   /* irregular */
        case 0:
            if ((u8) M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), u8 *, 0xE54) == 0) {
                DestroyWeapon();
            }
            if ((u8) M2C_FIELD(this, u8 *, 0xEC8) == 0) {
                DestroyShield();
            }
            if (IsIceKing() != 0) {
                M2C_FIELD(this, s8 *, 0xFBE) = 1;
            }
            ((EventMessage *) &this->unkFCC)->Send(NULL);
            StartPhase2();
            break;
        case 1:
            if (IsIceKing() == 0) {
                if ((u8) M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), u8 *, 0xE54) == 0) {
                    DestroyWeapon();
                }
                StartPhase3();
            } else {
                GetMaxHealth();
                SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
                M2C_FIELD(this, s8 *, 0xFBE) = 1;
                this->unkAFC = 0xA;
                this->unkAD0 = 3e-45f;
            }
            ((EventMessage *) &this->unkFD0)->Send(NULL);
            break;
        case 2:
            if (IsIceKing() != 0) {
                M2C_FIELD(this, s8 *, 0xFBE) = 1;
            }
            break;
        }
    }
    temp_r0_2125 = this->unkAFC;
    if ((temp_r0_2125 != temp_r31_2027) && (temp_r0_2125 != 5)) {
        UpdateBodyParts();
        ShatterBodyParts();
        return 1;
    }
    return 0;
}

void IceBoss::UpdateEnemyHud() {
    EnemyHudData sp8;
    f32 temp_f31_2158;

    sp8.EnemyHudData();
    temp_f31_2158 = this->unkAB0;
    GetMaxHealth();
    sp8.Init((Enemy *) this, temp_f31_2158, M2C_ERROR(/* Read from unset register $f1 */));
    EnemyHud_Modified(sp8);
}

#if 0 // DRAFT: ')' expected
void IceBoss::StartPhase3() {
    IceBossStalactiteSpawner *temp_r3_2197;

    M2C_FIELD(this, s32 *, 0xB18) = 2;
    this->unkAFC = 0xA;
    this->unkAD0 = 3e-45f;
    GetMaxHealth();
    SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
    UpdateEnemyHud();
    UpdateBodyParts();
    temp_r3_2197 = this->unkFE0;
    M2C_FIELD(M2C_FIELD(temp_r3_2197, void **, 0x44), M2C_UNK (**)(IceBossStalactiteSpawner *), 0x34)(temp_r3_2197);
    M2C_FIELD(this, f32 *, 0xFD4) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2BC));
    this->unkFC0 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2C0);
    M2C_FIELD(this, f32 *, 0xFD0) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2C4));
    this->unkB08 = 0;
    M2C_FIELD(this, s8 *, 0xFB9) = 0;
    this->unkF9C = 1.0f;
}
#endif

#if 0 // DRAFT: ')' expected
void IceBoss::StartPhase2() {
    IceBossStalactiteSpawner *temp_r3_2260;
    s32 temp_r4_2256;

    M2C_FIELD(this, s32 *, 0xB18) = 1;
    this->unkAFC = 5;
    this->unkAD0 = 1e-45f;
    GetMaxHealth();
    SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
    UpdateEnemyHud();
    UpdateBodyParts();
    temp_r4_2256 = this->unk9E8.unk10;
    M2C_FIELD(temp_r4_2256, u8 *, 0x10) = (u8) ((M2C_FIELD(temp_r4_2256, u8 *, 0x10) & ~0x40) | ((IsIceKing() << 6) & 0x40));
    temp_r3_2260 = this->unkFE0;
    M2C_FIELD(M2C_FIELD(temp_r3_2260, void **, 0x44), M2C_UNK (**)(IceBossStalactiteSpawner *, s32), 0x34)(temp_r3_2260, temp_r4_2256);
    M2C_FIELD(this, f32 *, 0xFD4) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2BC));
    this->unkFC0 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2C0);
    this->unkB08 = 0;
    M2C_FIELD(this, s8 *, 0xFB9) = 0;
    this->unkF9C = 1.0f;
}
#endif

#if 0 // DRAFT: ')' expected
void IceBoss::StartPhase1() {
    IceBossStalactiteSpawner *temp_r3_2318;
    s32 temp_r3_2313;

    M2C_FIELD(this, s32 *, 0xB18) = 0;
    this->unkAFC = 0;
    this->unkAD0 = 0.0f;
    GetMaxHealth();
    SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
    this->unkAB8 = M2C_FIELD(this->unkA20, f32 *, 0xEC);
    UpdateEnemyHud();
    UpdateBodyParts();
    temp_r3_2313 = this->unk9E8.unk10;
    M2C_FIELD(temp_r3_2313, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r3_2313, u8 *, 0x10) & ~0x40);
    temp_r3_2318 = this->unkFE0;
    M2C_FIELD(M2C_FIELD(temp_r3_2318, void **, 0x44), M2C_UNK (**)(IceBossStalactiteSpawner *, M2C_UNK), 0x34)(temp_r3_2318, 0);
    M2C_FIELD(this, f32 *, 0xFD4) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2BC));
    this->unkFC0 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2C0);
    this->unkB08 = 0;
    M2C_FIELD(this, s8 *, 0xFB9) = 0;
    this->unkF9C = 1.0f;
}
#endif

s32 IceBoss::GetPhase() {
    return M2C_BITWISE(s32, this->unkAD0);
}

u8 IceBoss::IsIceKing() {
    return M2C_FIELD(this->unkA20, s32 *, 0x1D0) == 2;
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void IceBoss::Message(MKMessage *arg0) {
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
    f32 temp_f1_2476;
    f32 temp_f1_2508;
    f32 temp_f31_2527;
    f32 temp_f31_2579;
    f32 temp_f31_2602;
    f32 temp_f5_2482;
    f32 temp_f6_2468;
    s32 temp_r0_2386;
    s32 temp_r3_2431;
    void *temp_r29_2520;
    void *temp_r3_2540;

    ((KDSoundPlayer *) &this->unkFFC)->Message(arg0);
    ((KDSoundPlayer *) &this->unk103C)->Message(arg0);
    temp_r0_2386 = arg0->unk0;
    switch (temp_r0_2386) {                         /* switch 1; irregular */
    case 181:                                       /* switch 1 */
        Enable();
    default:                                        /* switch 1 */
block_41:
        Enemy::Message(arg0);
        return;
    case 224:                                       /* switch 1 */
        this->unkAFC = 0xE;
        goto block_41;
    case 21:                                        /* switch 1 */
        if ((IsDying() == 0) && (IsDead() == 0)) {
            temp_r3_2431 = GetPhase();
            switch (temp_r3_2431) {                 /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                StartPhase1();
                break;
            case 1:                                 /* switch 2 */
                StartPhase2();
                break;
            case 2:                                 /* switch 2 */
                StartPhase3();
                break;
            }
        }
        ((IceBossStalactiteSpawner *) (M2C_BITWISE(IceBossStalactiteSpawner *, this->unkFC8)))->Reset();
        M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        temp_f6_2468 = this->unk5C8;
        sp50 = temp_f6_2468;
        temp_f1_2476 = this->unk5C8;
        sp54 = temp_f1_2476;
        temp_f5_2482 = this->unk5CC;
        sp58 = temp_f5_2482;
        sp18 = (MKVector3::up.unk0 * temp_f1_2476) - (MKVector3::up.unk4 * temp_f6_2468);
        sp10 = (MKVector3::up.unk4 * temp_f5_2482) - (MKVector3::up.unk8 * temp_f1_2476);
        sp14 = (MKVector3::up.unk8 * temp_f6_2468) - (MKVector3::up.unk0 * temp_f5_2482);
        sp28 = (f64) sp18;
        sp20 = (f64) sp10;
        sp5C = 0.0f;
        sp30 = (f32) sp20;
        sp34 = unksp24;
        sp38 = (f32) sp28;
        sp3C = 0.0f;
        sp60 = this->unk5B8;
        sp64 = this->unk5B8;
        temp_f1_2508 = this->unk5BC;
        sp68 = temp_f1_2508;
        sp6C = 1.0f;
        Teleport(&sp30, &MKVector3::up, temp_f1_2508, unksp24, (f32) sp20, 0.0f, temp_f5_2482, temp_f6_2468, MKVector3::up.unk8, MKVector3::up.unk4);
        goto block_41;
    case 4:                                         /* switch 1 */
        temp_r29_2520 = checked_cast<MeleeAttackHitMsg *, MKMessage>(arg0);
        if (((u8) M2C_FIELD(this, u8 *, 0xFB8) != 0) && ((u32) M2C_FIELD(temp_r29_2520, u32 *, 0x38) == (u32) M2C_FIELD(this, u32 *, 0xF90))) {
            temp_f31_2527 = M2C_FIELD(temp_r29_2520, f32 *, 0x20);
            GetMaxHealth();
            M2C_FIELD(temp_r29_2520, f32 *, 0x20) = (f32) (0.25f * M2C_ERROR(/* Read from unset register $f1 */));
            Enemy::Message(arg0);
            M2C_FIELD(temp_r29_2520, f32 *, 0x20) = temp_f31_2527;
            return;
        }
        goto block_41;
    case 5:                                         /* switch 1 */
        temp_r3_2540 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
        if ((s32) M2C_FIELD(temp_r3_2540, s32 *, 0x38) == 3) {
            if (M2C_FIELD(temp_r3_2540, f32 *, 0x34) > 0.0f) {
                if ((s32) M2C_FIELD(temp_r3_2540, s32 *, 0x48) != 0) {
                    M2C_FIELD(temp_r3_2540, f32 *, 0x34) = 0.1f;
                } else {
                    M2C_FIELD(temp_r3_2540, f32 *, 0x34) = (f32) M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xF8);
                    M2C_FIELD(temp_r3_2540, s32 *, 0x38) = 0;
                }
                goto block_35;
            }
        } else {
block_35:
            if (((u8) M2C_FIELD(this, u8 *, 0xFB8) != 0) && ((u32) M2C_FIELD(temp_r3_2540, u32 *, 0x30) == (u32) M2C_FIELD(this, u32 *, 0xF90))) {
                temp_f31_2579 = M2C_FIELD(temp_r3_2540, f32 *, 0x34);
                M2C_FIELD(temp_r3_2540, f32 *, 0x34) = (f32) (temp_f31_2579 * fWeaponVulMult);
                Enemy::Message(arg0);
                M2C_FIELD(temp_r3_2540, f32 *, 0x34) = temp_f31_2579;
                return;
            }
            goto block_41;
        }
        break;
    case -3:                                        /* switch 1 */
        if (!(((u8) M2C_FIELD(this, u8 *, 0xB09) >> 7U) & 1)) {
            Enemy::Message(arg0);
            Deactivate();
            return;
        }
        temp_f31_2602 = this->unkAB0;
        Enemy::Message(arg0);
        SetHealth(temp_f31_2602);
        return;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void IceBoss::Despawn(bool arg0) {
    Shatterable *temp_r3_2662;
    f32 temp_r3_2655;
    s32 temp_r4_2638;
    void *temp_r3_2650;
    void *temp_r3_2667;
    void *temp_r3_2672;
    void *temp_r3_2677;

    Enemy::Despawn(arg0);
    M2C_FIELD(&gb, s32 *, 0x360) = 0;
    temp_r4_2638 = this->unkFE4.unk0;
    if ((u32) temp_r4_2638 != 0U) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight((ManagedLight *) temp_r4_2638, 0U);
    }
    Disable();
    temp_r3_2650 = M2C_FIELD(this, void **, 0xF94);
    M2C_FIELD(M2C_FIELD(temp_r3_2650, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_2650);
    temp_r3_2655 = this->unkFC4;
    M2C_FIELD(M2C_FIELD(temp_r3_2655, void **, 0x44), M2C_UNK (**)(f32), 0x34)(temp_r3_2655);
    ((IceBossStalactiteSpawner *) (M2C_BITWISE(IceBossStalactiteSpawner *, this->unkFC8)))->Reset();
    temp_r3_2662 = this->unkED0;
    temp_r3_2662->Disable();
    temp_r3_2667 = this->unkE60;
    M2C_FIELD(M2C_FIELD(temp_r3_2667, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_2667);
    temp_r3_2672 = this->unkE88;
    M2C_FIELD(M2C_FIELD(temp_r3_2672, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_2672);
    temp_r3_2677 = this->unkEB0;
    M2C_FIELD(M2C_FIELD(temp_r3_2677, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_2677);
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
s32 IceBoss::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    if (Enemy::Spawn(arg0, arg1) != 0) {
        M2C_FIELD(&gb, IceBoss **, 0x360) = this;
        StartPhase1();
        KDSound_Stop((s32 *) &this->unkFF8);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_959'
void IceBoss::DrawSubObject(int arg0, float arg1) {
    s32 sp8;
    f32 temp_f31_2738;

    sp8 = lit_959;
    unkspA = (s16) arg0;
    temp_f31_2738 = MKModel_GetAlpha(this->unk4);
    MKModel_SetAlpha(this->unk4, arg1);
    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, arg0, 1U, 1U);
    MKModel_Draw(this->unk4, (u16 *) &sp8);
    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, arg0, 0U, 1U);
    MKModel_SetAlpha(this->unk4, temp_f31_2738);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void IceBoss::Draw() {
    Matrix spD0;
    f64 spC8;
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
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f64 temp_f0_2907;
    f64 temp_f0_2925;
    u8 var_r30_2779;
    void *temp_r3_2811;
    void *temp_r3_2862;
    void *temp_r3_2949;
    void *temp_r3_2977;
    void *temp_r5_2784;
    void *temp_r7_2799;

    Enemy::Draw();
    var_r30_2779 = 0;
    if (((u8) M2C_FIELD(this, u8 *, 0xEC8) != 0) || (temp_r5_2784 = this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28), (((u8) M2C_FIELD(temp_r5_2784, u8 *, 0xE54) == 0) == 0))) {
        var_r30_2779 = 1;
    } else {
        temp_r7_2799 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        spA0 = M2C_FIELD(temp_r7_2799, f64 *, 0x30);
        spA8 = M2C_FIELD(temp_r7_2799, f64 *, 0x38);
        MKModel_CalculateSubObjectLocalToWorldMatrix(this->unk4, (SubObjectType) 0, M2C_FIELD(temp_r5_2784, s32 *, 0xE44), &spD0);
        temp_r3_2811 = MKModel_GetSubObjectOrigin(this->unk4, (SubObjectType) 0, M2C_FIELD((this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28)), s32 *, 0xE44));
        sp90 = M2C_FIELD(temp_r3_2811, f64 *, 0);
        sp98 = M2C_FIELD(temp_r3_2811, f64 *, 8);
        sp20 = ((f32) sp98 * spD0.unk20) + (((f32) sp90 * M2C_BITWISE(f32, spD0)) + (unksp94 * spD0.unk10));
        sp24 = ((f32) sp98 * spD0.unk24) + (((f32) sp90 * spD0.unk4) + (unksp94 * spD0.unk14));
        sp28 = ((f32) sp98 * spD0.unk28) + (((f32) sp90 * spD0.unk8) + (unksp94 * spD0.unk18));
        sp80 = (f64) sp20;
        sp88 = (f64) sp28;
        sp90 = (f64) sp20;
        sp98 = (f64) sp28;
        spD0.Translate(&spD0, *((MKVector3 *) &sp90));
        spC0 = (f64) spD0.unk30;
        spC8 = (f64) spD0.unk38;
        MKModel_CalculateSubObjectLocalToWorldMatrix(this->unk4, (SubObjectType) 0, this->unkEBC, &spD0);
        temp_r3_2862 = MKModel_GetSubObjectOrigin(this->unk4, (SubObjectType) 0, this->unkEBC);
        sp90 = M2C_FIELD(temp_r3_2862, f64 *, 0);
        sp98 = M2C_FIELD(temp_r3_2862, f64 *, 8);
        sp10 = ((f32) sp98 * spD0.unk20) + (((f32) sp90 * M2C_BITWISE(f32, spD0)) + (unksp94 * spD0.unk10));
        sp14 = ((f32) sp98 * spD0.unk24) + (((f32) sp90 * spD0.unk4) + (unksp94 * spD0.unk14));
        sp18 = ((f32) sp98 * spD0.unk28) + (((f32) sp90 * spD0.unk8) + (unksp94 * spD0.unk18));
        sp70 = (f64) sp10;
        sp78 = (f64) sp18;
        sp90 = (f64) sp10;
        sp98 = (f64) sp18;
        spD0.Translate(&spD0, *((MKVector3 *) &sp90));
        spB0 = (f64) spD0.unk30;
        spB8 = (f64) spD0.unk38;
        temp_f0_2907 = spC0 - spA0;
        sp40 = temp_f0_2907;
        sp60 = temp_f0_2907;
        sp48 = (f32) spC8 - (f32) spA8;
        sp68 = (f64) sp48;
        temp_f0_2925 = spB0 - spA0;
        sp30 = temp_f0_2925;
        sp50 = temp_f0_2925;
        sp38 = (f32) spB8 - (f32) spA8;
        sp58 = (f64) sp38;
        if ((((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (unksp64 * unksp64))) > (((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + (unksp54 * unksp54)))) {
            var_r30_2779 = 1;
        }
    }
    if (var_r30_2779 != 0) {
        temp_r3_2949 = this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28);
        if ((u8) M2C_FIELD(temp_r3_2949, u8 *, 0xE54) == 0) {
            DrawSubObject(M2C_FIELD(temp_r3_2949, s32 *, 0xE44), M2C_BITWISE(f32, this->unkF9C));
        }
        if ((u8) M2C_FIELD(this, u8 *, 0xEC8) == 0) {
            DrawSubObject(this->unkEBC, M2C_BITWISE(f32, this->unkF98));
        }
    } else {
        if ((u8) M2C_FIELD(this, u8 *, 0xEC8) == 0) {
            DrawSubObject(this->unkEBC, M2C_BITWISE(f32, this->unkF98));
        }
        temp_r3_2977 = this + (M2C_FIELD(this, s32 *, 0xB18) * 0x28);
        if ((u8) M2C_FIELD(temp_r3_2977, u8 *, 0xE54) == 0) {
            DrawSubObject(M2C_FIELD(temp_r3_2977, s32 *, 0xE44), M2C_BITWISE(f32, this->unkF9C));
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void IceBoss::Update() {
    f64 sp48;
    f64 sp40;
    f64 sp30;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 sp8;

    Enemy::Update();
    if (IsIceKing() == 0) {
        sp8 = 1;
        ((KDSoundFader *) &this->unkFFC)->Update(GS_ElecBossExtra1, 1U, 1U, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        sp8 = 1;
        ((KDSoundFader *) &this->unk103C)->Update(GS_ElecBossExtra3, 1U, this->unk1064, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        this->unk1064 = 0;
    }
    UpdateWeapons();
    if ((s32) this->unkAFC >= 5) {
        UpdateBreathingFx();
    }
    if (IsIceKing() != 0) {
        UpdatePhrasesAndSounds();
    }
    MKVector(0.0f, 400.0f, 0.0f);
    ((MKProp *) &sp30)->GetPos();
    sp10 = sp30 + sp20;
    this->unkF68 = sp10;
    sp18 = sp38 + sp28;
    sp40 = sp10;
    sp48 = (f64) sp18;
    this->unkF70 = (f64) sp18;
}
#endif

void IceBoss::EnableCollision(bool arg0) {
    void *temp_r5_3083;

    temp_r5_3083 = M2C_FIELD(this, void **, 0xF90);
    if (temp_r5_3083 != NULL) {
        if (arg0 != 0) {
            M2C_FIELD(temp_r5_3083, s8 *, 4) = 1;
        } else {
            M2C_FIELD(temp_r5_3083, s8 *, 4) = 0;
        }
    }
    Enemy::EnableCollision(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void IceBoss::SetDefaults() {
    Enemy::SetDefaults();
    this->unkAFC = 0;
    M2C_FIELD(this, s32 *, 0xB18) = 0;
    this->unkB08 = 0;
    M2C_FIELD(this, s8 *, 0xFB8) = 0;
    M2C_FIELD(this, s8 *, 0xFBC) = 0;
    M2C_FIELD(this, s8 *, 0xFB9) = 0;
    M2C_FIELD(this, s8 *, 0xFBA) = 0;
    M2C_FIELD(this, s8 *, 0xFBB) = 0;
    this->unkF94 = 0.0f;
    this->unkF90 = 0.65f;
    if (IsIceKing() == 0) {
        this->unkF90 = 1.0f;
    }
    this->unkF98 = M2C_BITWISE(f32, this->unkF90);
    this->unkF9C = M2C_BITWISE(f32, this->unkF90);
    this->unkFA8 = 0.0f;
    this->unkFAC = 0.0f;
    this->unkFB0 = 0.0f;
    this->unkFB4 = 0.0f;
    M2C_FIELD(this, f32 *, 0xFD4) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2BC));
    this->unkFC0 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2C0);
    M2C_FIELD(this, f32 *, 0xFD0) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2C4));
    UpdateBodyParts();
    ResetWeapons();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void IceBoss::SetupCameraSpline(float arg0, float arg1, MKVector3 arg2, MKVector3 arg3) {
    MKCollisionResult sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;                                      /* compiler-managed */
    f64 sp1A8;                                      /* compiler-managed */
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    MKVector3 sp168;
    f64 sp160;
    f64 sp158;
    MKVector3 sp148;
    MKVector3 sp138;
    f64 sp130;
    f64 sp128;
    MKVector3 sp118;
    f64 sp110;
    f64 sp108;
    MKVector3 spF8;
    MKVector3 spE8;
    f64 spE0;
    f64 spD8;
    MKVector3 spC8;
    f64 spB8;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
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
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix *temp_r30_3306;
    f32 temp_f30_3360;
    f32 temp_f4_3200;
    f32 temp_f5_3206;
    f32 temp_f8_3202;
    f32 var_f0_3329;
    f32 var_f5_3233;
    f32 var_f5_3300;
    f64 temp_f1_3239;
    f64 temp_f1_3245;
    f64 temp_f1_3249;
    f64 temp_f1_3534;
    s32 temp_r3_3268;
    s32 temp_r3_3547;
    s32 var_r0_3278;
    s32 var_r23_3477;
    s32 var_r29_3308;
    u8 var_r24_3318;
    void *temp_r31_3217;
    void *temp_r3_3533;
    void *temp_r4_3204;
    void *temp_r4_3466;
    void *temp_r5_3401;
    void *temp_r5_3448;
    void *temp_r6_3375;
    void *temp_r6_3421;

    if ((u32) gb != 0U) {
        temp_f4_3200 = M2C_FIELD(arg2, f32 *, 8);
        temp_f8_3202 = M2C_FIELD(arg2, f32 *, 4);
        temp_r4_3204 = this->unk8;
        temp_f5_3206 = M2C_FIELD(arg2, f32 *, 0);
        sp7C = (MKVector3::up.unk8 * temp_f5_3206) - (MKVector3::up.unk0 * temp_f4_3200);
        sp78 = (MKVector3::up.unk4 * temp_f4_3200) - (MKVector3::up.unk8 * temp_f8_3202);
        temp_r31_3217 = M2C_FIELD(this->unkAF8, void **, 0xB0);
        sp80 = (MKVector3::up.unk0 * temp_f8_3202) - (MKVector3::up.unk4 * temp_f5_3206);
        sp1A8 = (f64) sp78;
        sp1B0 = (f64) sp80;
        sp1C0 = M2C_FIELD(temp_r4_3204, f64 *, 0x38);
        sp1B8 = M2C_FIELD(temp_r4_3204, f64 *, 0x30);
        var_f5_3233 = ((f32) sp1B0 * (f32) sp1B0) + (((f32) sp1A8 * (f32) sp1A8) + (unksp1AC * unksp1AC));
        if (var_f5_3233 > 0.000001f) {
            if (var_f5_3233 > 0.0f) {
                temp_f1_3239 = __frsqrte(var_f5_3233);
                temp_f1_3245 = 0.5 * temp_f1_3239 * -(((f64) var_f5_3233 * (temp_f1_3239 * temp_f1_3239)) - 3.0);
                temp_f1_3249 = 0.5 * temp_f1_3245 * -(((f64) var_f5_3233 * (temp_f1_3245 * temp_f1_3245)) - 3.0);
                var_f5_3233 = (f32) ((f64) var_f5_3233 * (0.5 * temp_f1_3249 * -(((f64) var_f5_3233 * (temp_f1_3249 * temp_f1_3249)) - 3.0)));
            } else if (var_f5_3233 < M2C_BITWISE(f32, 0.0)) {
                var_f5_3233 = __float_nan;
            } else {
                sp10 = var_f5_3233;
                temp_r3_3268 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_3268) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_3278 = 1;
                    } else {
                        var_r0_3278 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_3278 = 5;
                    } else {
                        var_r0_3278 = 3;
                    }
                    break;
                default:
                    var_r0_3278 = 4;
                    break;
                }
                if (var_r0_3278 == 1) {
                    var_f5_3233 = __float_nan;
                }
            }
            var_f5_3300 = 1.0f / var_f5_3233;
        } else {
            var_f5_3300 = 0.0f;
        }
        temp_r30_3306 = temp_r31_3217 + 0x7C;
        var_r29_3308 = 1;
        sp1A8 = (f32) sp1A8 * var_f5_3300;
        var_r24_3318 = 0;
        unksp1AC *= var_f5_3300;
        sp1B0 = (f32) sp1B0 * var_f5_3300;
        unksp1BC += arg1;
loop_32:
        if ((var_r29_3308 < 0xA) && (var_r24_3318 == 0)) {
            if (var_r29_3308 == 0) {
                var_f0_3329 = 0.0f;
            } else if (var_r29_3308 & 1) {
                var_f0_3329 = 200.0f * -(f32) (var_r29_3308 / 2);
            } else {
                var_f0_3329 = 200.0f * (f32) (var_r29_3308 / 2);
            }
            temp_f30_3360 = arg0 + var_f0_3329;
            sp168.operator*(temp_f30_3360);
            sp68 = sp1B8 + M2C_BITWISE(f64, sp168);
            temp_r6_3375 = M2C_FIELD(temp_r31_3217, void **, 0x70);
            sp178 = sp68;
            sp70 = (f32) sp1C0 + sp168.unk8;
            M2C_FIELD(temp_r6_3375, f64 *, 0) = sp68;
            sp180 = (f64) sp70;
            M2C_FIELD(temp_r6_3375, f64 *, 8) = (f64) sp70;
            KDMath_Slerp(sp138, *((MKVector3 *) arg2), 0.7853982f);
            sp148.operator*(temp_f30_3360);
            sp58 = sp1B8 + M2C_BITWISE(f64, sp148);
            sp60 = (f32) sp1C0 + sp148.unk8;
            temp_r5_3401 = M2C_FIELD(temp_r31_3217, void **, 0x70) + M2C_FIELD(temp_r31_3217, s32 *, 0x68);
            M2C_FIELD(temp_r5_3401, f64 *, 0) = sp58;
            sp158 = sp58;
            sp160 = (f64) sp60;
            M2C_FIELD(temp_r5_3401, f64 *, 8) = (f64) sp60;
            sp118.operator*(temp_f30_3360);
            sp48 = sp1B8 + M2C_BITWISE(f64, sp118);
            temp_r6_3421 = M2C_FIELD(temp_r31_3217, void **, 0x70) + (M2C_FIELD(temp_r31_3217, s32 *, 0x68) * 2);
            sp50 = (f32) sp1C0 + sp118.unk8;
            M2C_FIELD(temp_r6_3421, f64 *, 0) = sp48;
            sp128 = sp48;
            sp130 = (f64) sp50;
            M2C_FIELD(temp_r6_3421, f64 *, 8) = (f64) sp50;
            KDMath_Slerp(spE8, *((MKVector3 *) arg2), -0.7853982f);
            spF8.operator*(temp_f30_3360);
            sp38 = sp1B8 + M2C_BITWISE(f64, spF8);
            sp40 = (f32) sp1C0 + spF8.unk8;
            temp_r5_3448 = M2C_FIELD(temp_r31_3217, void **, 0x70) + (M2C_FIELD(temp_r31_3217, s32 *, 0x68) * 3);
            M2C_FIELD(temp_r5_3448, f64 *, 0) = sp38;
            sp108 = sp38;
            sp110 = (f64) sp40;
            M2C_FIELD(temp_r5_3448, f64 *, 8) = (f64) sp40;
            spC8.operator*(temp_f30_3360);
            sp28 = sp1B8 - M2C_BITWISE(f64, spC8);
            temp_r4_3466 = M2C_FIELD(temp_r31_3217, void **, 0x70) + (M2C_FIELD(temp_r31_3217, s32 *, 0x68) * 4);
            sp30 = (f32) sp1C0 - spC8.unk8;
            M2C_FIELD(temp_r4_3466, f64 *, 0) = sp28;
            spD8 = sp28;
            spE0 = (f64) sp30;
            M2C_FIELD(temp_r4_3466, f64 *, 8) = (f64) sp30;
            ((KDUniformSpline *) (temp_r31_3217 + 0x7C))->Smooth();
            ((KDUniformSpline *) (temp_r31_3217 + 0x7C))->Smooth();
            var_r24_3318 = 1;
            var_r23_3477 = 0;
            do {
                spC = 0.0f;
                ((KDUniformSpline *) &spB8)->GetMeasure(0.1f * (f32) var_r23_3477, temp_r30_3306, KDSpline_PositionMixer);
                sp198 = spB8;
                sp1A0 = spC0;
                sp8 = 0.0f;
                ((KDUniformSpline *) &spA8)->GetMeasure(0.1f * (f32) (var_r23_3477 + 1), temp_r30_3306, KDSpline_PositionMixer);
                sp188 = spA8;
                sp190 = spB0;
                if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp198), *((MKVector3 *) &sp188), 100.0f, &sp1C8, (MKCollisionMode) 5, 0) != 0) {
                    var_r24_3318 = 0;
                }
                var_r23_3477 += 1;
            } while (var_r23_3477 < 0xA);
            var_r29_3308 += 1;
            goto loop_32;
        }
        temp_r3_3533 = this->unk8;
        temp_f1_3534 = M2C_FIELD(temp_r3_3533, f64 *, 0x30);
        sp88 = temp_f1_3534;
        sp90 = M2C_FIELD(temp_r3_3533, f64 *, 0x38);
        sp18 = temp_f1_3534 + *(f64 *) arg3;
        temp_r3_3547 = this->unkAF8;
        sp98 = sp18;
        sp20 = (f32) sp90 + M2C_FIELD(arg3, f32 *, 8);
        M2C_FIELD(temp_r3_3547, f64 *, 0x60) = sp18;
        M2C_FIELD(temp_r3_3547, f64 *, 0x68) = (f64) sp20;
        spA0 = (f64) sp20;
        M2C_FIELD(temp_r3_3547, s8 *, 0xF5) = 1;
    }
}
#endif

void IceBoss::ResetWeapons() {
    s32 var_ctr_3584;
    s32 var_r4_3578;
    void *temp_r8_3586;

    var_r4_3578 = 0;
    var_ctr_3584 = 3;
    do {
        temp_r8_3586 = this + var_r4_3578;
        var_r4_3578 += 0x28;
        M2C_FIELD(temp_r8_3586, s8 *, 0xE54) = 1;
        M2C_FIELD(temp_r8_3586, s8 *, 0xE55) = 0;
        M2C_FIELD(temp_r8_3586, s8 *, 0xE56) = 0;
        M2C_FIELD(temp_r8_3586, f32 *, 0xE58) = 0.0f;
        var_ctr_3584 -= 1;
    } while (var_ctr_3584 != 0);
    M2C_FIELD(this, s8 *, 0xEC8) = 0;
    M2C_FIELD(this, s8 *, 0xEC9) = 0;
    M2C_FIELD(this, s8 *, 0xECA) = 0;
    this->unkECC = 0.0f;
}

#if 0 // DRAFT: illegal implicit conversion from 'const char[22]' to
void IceBoss::InitShield() {
    s8 *var_r4_3636;

    this->unkEBC = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, "shield");
    this->unkEC0 = (u32) Tools_GetMatchingSubObjectIndex((SubObjectType) 1, this->unk4, "shield");
    this->unkEC4 = 5;
    M2C_FIELD(this, s8 *, 0xEC8) = 0;
    M2C_FIELD(this, s8 *, 0xEC9) = 0;
    this->unkECC = 0.0f;
    var_r4_3636 = "ElecKingArmour_Shield";
    if (IsIceKing() != 0) {
        var_r4_3636 = "IceBossArmour_Shield";
    }
    this->unkED0 = checked_cast<Shatterable *, MKProp>(gMK->CreateProp(var_r4_3636));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[9]' to
void IceBoss::InitWeapon(int arg0, const char *arg1, int arg2, int arg3) {
    MKHeap *temp_r3_3706;
    MKHeap *temp_r3_3708;
    s32 temp_r30_3666;
    s32 temp_r30_3707;
    s8 *temp_r3_3704;
    s8 *var_r3_3715;
    s8 *var_r4_3695;
    u8 temp_ret_3691;
    void *temp_r31_3675;

    temp_r30_3666 = arg0 * 0x28;
    M2C_FIELD((this + temp_r30_3666), s32 *, 0xE44) = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, arg1);
    temp_r31_3675 = this + temp_r30_3666;
    M2C_FIELD(temp_r31_3675, s32 *, 0xE48) = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 1, this->unk4, arg1);
    M2C_FIELD(temp_r31_3675, s32 *, 0xE4C) = arg2;
    M2C_FIELD(temp_r31_3675, s32 *, 0xE50) = arg3;
    M2C_FIELD(temp_r31_3675, s8 *, 0xE54) = 0;
    M2C_FIELD(temp_r31_3675, s8 *, 0xE55) = 0;
    M2C_FIELD(temp_r31_3675, f32 *, 0xE58) = 0.0f;
    M2C_FIELD(temp_r31_3675, Shatterable **, 0xE60) = NULL;
    M2C_FIELD(temp_r31_3675, s8 **, 0xE5C) = NULL;
    M2C_FIELD(temp_r31_3675, f32 *, 0xE64) = 120.00001f;
    M2C_FIELD(temp_r31_3675, f32 *, 0xE68) = 180.0f;
    temp_ret_3691 = IsIceKing();
    var_r4_3695 = "ElecKing";
    if (temp_ret_3691 != 0) {
        var_r4_3695 = "IceBoss";
    }
    temp_r3_3704 = Str_Printf("%sArmour_%s", var_r4_3695, arg1, M2C_BITWISE(f32, temp_ret_3691));
    temp_r3_3706 = strlen(temp_r3_3704);
    temp_r30_3707 = temp_r3_3706 + 1;
    temp_r3_3708 = temp_r3_3706->Current();
    if (temp_r3_3708 != NULL) {
        var_r3_3715 = ((MKHeap *) (temp_r3_3708->Current()))->Alloc(temp_r30_3707, NULL, 0);
    } else {
        var_r3_3715 = malloc(temp_r30_3707);
    }
    M2C_FIELD(temp_r31_3675, s8 **, 0xE5C) = var_r3_3715;
    strcpy(M2C_FIELD(temp_r31_3675, s8 **, 0xE5C), temp_r3_3704);
    M2C_FIELD(temp_r31_3675, Shatterable **, 0xE60) = checked_cast<Shatterable *, MKProp>(gMK->CreateProp(M2C_FIELD(temp_r31_3675, s8 **, 0xE5C)));
}
#endif

void IceBoss::InitBodyPart(IceBossBodyPart *arg0, int arg1, const char *arg2, int arg3, int arg4, SubObjectType arg5, bool arg6) {
    arg0->unk0 = (s32) Tools_GetMatchingSubObjectIndex(arg5, this->unk4, arg2);
    arg0->unk4 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 1, this->unk4, "body");
    arg0->unk8 = arg3;
    arg0->unkC = arg4;
    arg0->unk10 = (s32) arg5;
    arg0->unk14 = 0;
    arg0->unk1C = 0;
    arg0->unk18 = 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'const char[9]' to
void IceBoss::InitBodyPart(int arg0, const char *arg1, int arg2, int arg3, SubObjectType arg4, bool arg5) {
    MKHeap *temp_r3_3832;
    MKHeap *temp_r3_3834;
    s32 temp_r30_3794;
    s32 temp_r30_3833;
    s8 *temp_r3_3830;
    s8 *var_r3_3841;
    s8 *var_r4_3817;
    u8 temp_ret_3813;
    void *temp_r31_3803;

    temp_r30_3794 = arg0 << 5;
    M2C_FIELD((this + temp_r30_3794), s32 *, 0xB44) = (s32) Tools_GetMatchingSubObjectIndex(arg4, this->unk4, arg1);
    temp_r31_3803 = this + temp_r30_3794;
    M2C_FIELD(temp_r31_3803, s32 *, 0xB48) = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 1, this->unk4, arg1);
    M2C_FIELD(temp_r31_3803, s32 *, 0xB4C) = arg2;
    M2C_FIELD(temp_r31_3803, s32 *, 0xB50) = arg3;
    M2C_FIELD(temp_r31_3803, s32 *, 0xB54) = (s32) arg4;
    M2C_FIELD(temp_r31_3803, s8 *, 0xB58) = 0;
    M2C_FIELD(temp_r31_3803, Shatterable **, 0xB60) = NULL;
    M2C_FIELD(temp_r31_3803, s8 **, 0xB5C) = NULL;
    temp_ret_3813 = IsIceKing();
    var_r4_3817 = "ElecKing";
    if (temp_ret_3813 != 0) {
        var_r4_3817 = "IceBoss";
    }
    if ((arg2 == 0) && (arg5 != 0)) {
        temp_r3_3830 = Str_Printf("%sArmour_%s", var_r4_3817, arg1, M2C_BITWISE(f32, temp_ret_3813));
        temp_r3_3832 = strlen(temp_r3_3830);
        temp_r30_3833 = temp_r3_3832 + 1;
        temp_r3_3834 = temp_r3_3832->Current();
        if (temp_r3_3834 != NULL) {
            var_r3_3841 = ((MKHeap *) (temp_r3_3834->Current()))->Alloc(temp_r30_3833, NULL, 0);
        } else {
            var_r3_3841 = malloc(temp_r30_3833);
        }
        M2C_FIELD(temp_r31_3803, s8 **, 0xB5C) = var_r3_3841;
        strcpy(M2C_FIELD(temp_r31_3803, s8 **, 0xB5C), temp_r3_3830);
        M2C_FIELD(temp_r31_3803, Shatterable **, 0xB60) = checked_cast<Shatterable *, MKProp>(gMK->CreateProp(M2C_FIELD(temp_r31_3803, s8 **, 0xB5C)));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'EventCamera *' to
void IceBoss::Resolve() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Shatterable *temp_r3_3891;
    Shatterable *temp_ret_3879;
    Shatterable *temp_ret_3883;
    Shatterable *temp_ret_3887;
    s32 temp_r4_3915;
    s32 temp_ret_3875;

    Enemy::Resolve();
    temp_ret_3875 = checked_cast<EventCamera *, MKProp>(((MKSceneManager *) this->unkAF8)->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    this->unkAF8 = temp_ret_3875;
    temp_ret_3879 = checked_cast<Shatterable *, MKProp>(((MKSceneManager *) (M2C_FIELD(this, MKSceneManager **, 0xF98)))->PropResolver_Resolve((s32) (u32) (u64) temp_ret_3875));
    M2C_FIELD(this, MKSceneManager **, 0xF98) = temp_ret_3879;
    temp_ret_3883 = checked_cast<Shatterable *, MKProp>(((MKSceneManager *) (M2C_FIELD(this, MKSceneManager **, 0xF9C)))->PropResolver_Resolve((s32) (u32) (u64) temp_ret_3879));
    M2C_FIELD(this, MKSceneManager **, 0xF9C) = temp_ret_3883;
    temp_ret_3887 = checked_cast<Shatterable *, MKProp>(((MKSceneManager *) (M2C_FIELD(this, MKSceneManager **, 0xFA0)))->PropResolver_Resolve((s32) (u32) (u64) temp_ret_3883));
    M2C_FIELD(this, MKSceneManager **, 0xFA0) = temp_ret_3887;
    temp_r3_3891 = checked_cast<Shatterable *, MKProp>(((MKSceneManager *) (M2C_FIELD(this, MKSceneManager **, 0xFA4)))->PropResolver_Resolve((s32) (u32) (u64) temp_ret_3887));
    sp8 = 0.5f;
    spC = 0.5f;
    M2C_FIELD(this, MKSceneManager **, 0xFA4) = (MKSceneManager *) temp_r3_3891;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unkFE4.unk0 = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(MKVector3::zero, MKVector3::zero, *((MKVector4 *) &sp18), 1000.0f, lit_248, lit_249);
    temp_r4_3915 = this->unkFE4.unk0;
    if ((u32) temp_r4_3915 != 0U) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight((ManagedLight *) temp_r4_3915, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[14]' to
void IceBoss::LoadDone() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_4253;
    f32 temp_r3_4335;
    f32 temp_r3_4342;
    s32 temp_r0_4312;
    s8 *temp_r4_4269;
    s8 *var_r3_4260;
    s8 *var_r4_4237;
    void *temp_r30_4277;
    void *temp_r3_4244;

    Enemy::LoadDone();
    this->unkA28 = (void **) this->unkA24;
    InitBodyPart(0xE, "R_Arm_01", 0, 1, (SubObjectType) 0, 1U);
    InitBodyPart(0xF, "R_Arm_02", 1, 0xF, (SubObjectType) 0, 0U);
    InitBodyPart(0x10, "R_Glove_01", 0, 2, (SubObjectType) 0, 1U);
    InitBodyPart(0x11, "R_Glove_02", 2, 0xF, (SubObjectType) 0, 0U);
    InitBodyPart(1, "FacePlate", 0, 4, (SubObjectType) 0, 1U);
    InitBodyPart(0, "Cape", 0, 5, (SubObjectType) 2, 0U);
    InitBodyPart(5, "L_Arm_01", 0, 6, (SubObjectType) 0, 1U);
    InitBodyPart(6, "L_Arm_02", 6, 0xF, (SubObjectType) 0, 0U);
    InitBodyPart(7, "L_Glove_01", 0, 7, (SubObjectType) 0, 1U);
    InitBodyPart(8, "L_Glove_02", 7, 0xF, (SubObjectType) 0, 0U);
    InitBodyPart(3, "Torso_01", 0, 8, (SubObjectType) 0, 1U);
    InitBodyPart(4, "Torso_02", 8, 0xF, (SubObjectType) 0, 0U);
    InitBodyPart(0xD, "L_Shoulder", 0, 9, (SubObjectType) 0, 1U);
    InitBodyPart(0xB, "L_Leg_01", 0, 0xA, (SubObjectType) 0, 1U);
    InitBodyPart(0xC, "L_Leg_02", 0xA, 0xF, (SubObjectType) 0, 0U);
    InitBodyPart(2, "Skirt", 0, 0xB, (SubObjectType) 0, 1U);
    InitBodyPart(0x14, "R_Leg_01", 0, 0xC, (SubObjectType) 0, 1U);
    InitBodyPart(0x15, "R_Leg_02", 0xC, 0xF, (SubObjectType) 0, 0U);
    InitBodyPart(0x12, "R_Horn_01", 0, 0xD, (SubObjectType) 0, 1U);
    InitBodyPart(0x13, "R_Horn_02", 0xD, 0xF, (SubObjectType) 0, 0U);
    InitBodyPart(9, "L_Horn_01", 0, 0xE, (SubObjectType) 0, 1U);
    InitBodyPart(0xA, "L_Horn_02", 0xE, 0xF, (SubObjectType) 0, 0U);
    InitBodyPart((IceBossBodyPart *) &this->unkB24, 0, "Main", 0, 0xF, (SubObjectType) 0, 0U);
    InitBodyPart(0x16, "Energy", 0, 0xF, (SubObjectType) 0, 0U);
    InitBodyPart(0x17, "Glow", 0, 0xF, (SubObjectType) 0, 0U);
    InitWeapon(0, "Sword", 0, 5);
    InitWeapon(1, "Axe", 5, 0xB);
    InitWeapon(2, "Sword", 0xB, 0xF);
    InitShield();
    SetAnim((AnimSequenceType) 1, 0, 0, 0.15f, 0U, 0U);
    this->unkB04 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "breath");
    var_r4_4237 = "ElecKingSword";
    if (IsIceKing() != 0) {
        var_r4_4237 = "IceBossSword";
    }
    M2C_FIELD(this, void **, 0xF94) = gMK->CreateProp(var_r4_4237);
    temp_r3_4244 = M2C_FIELD(this, void **, 0xF94);
    M2C_FIELD(M2C_FIELD(temp_r3_4244, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_4244);
    UpdateWeaponCollisionCapsule();
    M2C_FIELD(this, s8 **, 0xF90) = NULL;
    temp_r3_4253 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4253 != NULL) {
        var_r3_4260 = ((MKHeap *) (temp_r3_4253->Current()))->Alloc(0x10, NULL, 0);
    } else {
        var_r3_4260 = malloc(0x10);
    }
    M2C_FIELD(this, s8 **, 0xF90) = var_r3_4260;
    temp_r4_4269 = M2C_FIELD(this, s8 **, 0xF90);
    M2C_FIELD(temp_r4_4269, s32 *, 0) = 0;
    M2C_FIELD(temp_r4_4269, s8 *, 4) = 1;
    M2C_FIELD(temp_r4_4269, IceBoss **, 8) = this;
    M2C_FIELD(temp_r4_4269, s32 *, 0xC) = 0;
    temp_r30_4277 = checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = 0.8f;
    sp1C = 0.8f;
    sp20 = 0.1f;
    sp24 = 1.0f;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    ((MKCollisionManager *) (gMK->GetCollisionManager((f64) sp18, (f64) sp10, (f64) sp8, 1.0f)))->AddCapsule((MKVector3 *) &this->unkF20.unk28, (MKVector3 *) &this->unkF20.unk38, 80.0f, *((MKVector4 *) &sp38), *((MKVector4 *) &sp28), (MKCollisionMode) 2, (MKCollisionInfo *) M2C_FIELD(this, s8 **, 0xF90), M2C_FIELD(temp_r30_4277, u32 *, 0x70));
    temp_r0_4312 = M2C_FIELD(this->unkA20, s32 *, 0x1D0);
    switch (temp_r0_4312) {                         /* irregular */
    case 2:
        this->unkFC4 = M2C_BITWISE(f32, gMK->CreateProp("IceBossStomp"));
        break;
    case 1:
        this->unkFC4 = M2C_BITWISE(f32, gMK->CreateProp("ElecBossStomp"));
        break;
    }
    temp_r3_4335 = this->unkFC4;
    if (M2C_BITWISE(u32, temp_r3_4335) != 0U) {
        M2C_FIELD(M2C_FIELD(temp_r3_4335, void **, 0x44), M2C_UNK (**)(), 0x34)();
        temp_r3_4342 = this->unkFC4;
        M2C_FIELD(M2C_FIELD(temp_r3_4342, void **, 0x44), M2C_UNK (**)(f32), 0x44)(temp_r3_4342);
    }
    ((IceBossStalactiteSpawner *) (M2C_BITWISE(IceBossStalactiteSpawner *, this->unkFC8)))->LoadDone();
    if (!(this->unk680 & 0x160000)) {
        Disable();
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 IceBoss::LoadLine(MKIniLine *arg0) {
    s32 var_r31_4375;

    var_r31_4375 = 0;
    if ((Enemy::LoadLine(arg0) != 0) || (((EventMessage *) &this->unkFCC)->LoadLine(arg0, "OnPhase1End") != 0) || (((EventMessage *) &this->unkFD0)->LoadLine(arg0, "OnPhase2End") != 0) || (((EventMessage *) &this->unkFD4)->LoadLine(arg0, "OnPhase3End") != 0) || (arg0->LoadInt("PhaseCameraID", &this->unkAF8, 0) != 0) || (arg0->LoadInt("Stalactite1ID", (s32 *) &this->unkF80, 0) != 0) || (arg0->LoadInt("Stalactite2ID", this + 0xF9C, 0) != 0) || (arg0->LoadInt("Stalactite3ID", (s32 *) &this->unkF88, 0) != 0) || (arg0->LoadInt("Stalactite4ID", this + 0xFA4, 0) != 0)) {
        var_r31_4375 = 1;
    }
    return var_r31_4375;
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void IceBoss::Deinit() {
    MKHeap *temp_r3_4479;
    MKHeap *temp_r3_4497;
    MKHeap *temp_r3_4518;
    MKHeap *temp_r3_4545;
    f32 temp_r29_4496;
    s32 temp_r27_4514;
    s32 temp_r28_4541;
    s32 temp_r4_4564;
    s32 var_r26_4511;
    s32 var_r26_4537;
    s32 var_r30_4510;
    s32 var_r30_4538;
    s8 *temp_r27_4542;
    s8 *temp_r28_4515;
    s8 *temp_r29_4476;

    Enemy::Deinit();
    KDSound_Stop((s32 *) &this->unkFFC);
    KDSound_Stop(&this->unk103C);
    KDSound_Stop((s32 *) &this->unkFF8);
    PhrasePlayer_StopEvent(this->unkFE8.unk0);
    temp_r29_4476 = M2C_FIELD(this, s8 **, 0xF90);
    if (temp_r29_4476 != NULL) {
        temp_r3_4479 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_4479 != NULL) {
            ((MKHeap *) (temp_r3_4479->Current()))->Free(temp_r29_4476, NULL, 0);
        } else {
            free(temp_r29_4476);
        }
    }
    M2C_FIELD(this, s8 **, 0xF90) = NULL;
    ((IceBossStalactiteSpawner *) (M2C_BITWISE(IceBossStalactiteSpawner *, this->unkFC8)))->Deinit();
    temp_r29_4496 = this->unkFC8;
    temp_r3_4497 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4497 != NULL) {
        ((MKHeap *) (temp_r3_4497->Current()))->Free(M2C_BITWISE(void *, temp_r29_4496), NULL, 0);
    } else {
        free(M2C_BITWISE(s8 *, temp_r29_4496));
    }
    var_r30_4510 = 0;
    var_r26_4511 = 0;
    do {
        temp_r27_4514 = var_r30_4510 + 0xB5C;
        temp_r28_4515 = *(this + temp_r27_4514);
        if (temp_r28_4515 != NULL) {
            temp_r3_4518 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
            if (temp_r3_4518 != NULL) {
                ((MKHeap *) (temp_r3_4518->Current()))->Free(temp_r28_4515, NULL, 0);
            } else {
                free(temp_r28_4515);
            }
            *(this + temp_r27_4514) = 0;
        }
        var_r26_4511 += 1;
        var_r30_4510 += 0x20;
    } while (var_r26_4511 < 0x18);
    var_r26_4537 = 0;
    var_r30_4538 = 0;
    do {
        temp_r28_4541 = var_r30_4538 + 0xE5C;
        temp_r27_4542 = *(this + temp_r28_4541);
        if (temp_r27_4542 != NULL) {
            temp_r3_4545 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
            if (temp_r3_4545 != NULL) {
                ((MKHeap *) (temp_r3_4545->Current()))->Free(temp_r27_4542, NULL, 0);
            } else {
                free(temp_r27_4542);
            }
            *(this + temp_r28_4541) = 0;
        }
        var_r26_4537 += 1;
        var_r30_4538 += 0x28;
    } while (var_r26_4537 < 3);
    temp_r4_4564 = this->unkFE4.unk0;
    if ((u32) temp_r4_4564 != 0U) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight((ManagedLight *) temp_r4_4564, 0U);
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight((ManagedLight *) this->unkFE4.unk0);
        this->unkFE4.unk0 = 0;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void IceBoss::Init() {
    IceBossGoal_Think *temp_r30_4598;
    MKHeap *temp_r3_4626;
    s8 *var_r3_4633;

    Enemy::Init();
    operator new(0x6CU, NULL, 0);
    temp_r30_4598 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r30_4598 != NULL) {
        temp_r30_4598->__vptr = &__vt__14Goal<7IceBoss>;
        temp_r30_4598->unk4 = 0;
        temp_r30_4598->unk8 = 1;
        temp_r30_4598->unk9 = 0;
        temp_r30_4598->unkC = 0;
        temp_r30_4598->__vptr = (struct __vt__14Goal<7IceBoss> *) &__vt__23CompositeGoal<7IceBoss>;
        temp_r30_4598->unk1C = 0;
        temp_r30_4598->unk18 = 0;
        temp_r30_4598->unk10 = 0;
        temp_r30_4598->unk14 = 0;
        temp_r30_4598->__vptr = &__vt;
    }
    temp_r30_4598->Init(this);
    this->unkA24 = (EnemyAttack *) temp_r30_4598;
    this->unkFC4 = 0.0f;
    temp_r3_4626 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4626 != NULL) {
        var_r3_4633 = ((MKHeap *) (temp_r3_4626->Current()))->Alloc(0x28, NULL, 0);
    } else {
        var_r3_4633 = malloc(0x28);
    }
    this->unkFC8 = M2C_BITWISE(f32, var_r3_4633);
    ((IceBossStalactiteSpawner *) (M2C_BITWISE(IceBossStalactiteSpawner *, this->unkFC8)))->Init((MKProp *) this, 0xA, M2C_FIELD(this->unkA20, s32 *, 0x1D0));
    this->unkFE8.unk0 = 0;
    this->unkFF8 = NULL;
    this->unkFEC.unk0 = 0;
    this->unk1008 = 0.0f;
    this->unkFF4 = 0.0f;
    ((KDSoundFader *) &this->unkFFC)->Init(0.75f, 0.75f);
    ((KDSoundFader *) &this->unk103C)->Init(0.75f, 0.75f);
    this->unk1068 = checked_cast<IceBitsPS *, MKProp>(gMK->CreateProp("IceBitsPS"));
    ((EventMessage *) &this->unkFCC)->Init();
    ((EventMessage *) &this->unkFD0)->Init();
    ((EventMessage *) &this->unkFD4)->Init();
    this->unkAF8 = 0;
    M2C_FIELD(this, s8 *, 0xFBD) = 0;
    this->unk1064 = 0;
    this->unkFDC = checked_cast<EarthShockwave *, MKProp>(gMK->CreateProp("EarthShockwave"));
    this->unkFE0 = checked_cast<ElementalShield *, MKProp>(gMK->CreateProp("ElementalShield"));
    M2C_FIELD(this, f32 *, 0xF80) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF84) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF88) = 0.0f;
    ((ElementalShield *) this->unkFE0)->SetElement(M2C_FIELD(this->unkA20, s32 *, 0x1D0));
    this->unkFE4.unk0 = 0;
}
#endif

#if 0 // DRAFT: illegal operand
void IceBossDescriptor::LoadDone() {
    s32 temp_r0_4723;
    s32 var_ctr_4721;
    s32 var_r3_4720;

    EnemyDescriptor::LoadDone();
    var_r3_4720 = 0;
    var_ctr_4721 = 3;
    do {
        temp_r0_4723 = var_r3_4720 + 0x300;
        var_r3_4720 += 0x24;
        *(this + temp_r0_4723) = *(this + temp_r0_4723) / 100.0f;
        var_ctr_4721 -= 1;
    } while (var_ctr_4721 != 0);
    this->unk123 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_752'
s32 IceBossDescriptor::LoadLine(MKIniLine *arg0) {
    s8 sp36;
    s8 sp2C;
    M2C_UNK sp28;
    s8 spC;
    s8 *sp8;
    MKIniLine *var_r29_4790;
    s32 temp_r5_4853;
    s32 temp_ret_4810;
    s32 temp_ret_4850;

    M2C_STRUCT_COPY((s32) &sp28 + 4, (s32) (&lit_752 - 4) + 4, 0x20);
    M2C_STRUCT_COPY((s32) &sp8 + 4, (s32) (&lit_753 - 4) + 4, 0x20);
    if (EnemyDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("HurtPhrases") != 0) {
        var_r29_4790 = arg0->unkC->GetSubLine(arg0);
loop_11:
        if (var_r29_4790 != NULL) {
            strcpy(&sp2C, var_r29_4790->GetFieldName());
            if (strnicmp("hurtPhrase", &sp2C, 0xA) == 0) {
                strcpy(&spC, &sp36);
                temp_ret_4810 = atoi(&spC);
                if (temp_ret_4810 <= 3) {
                    var_r29_4790->LoadString(Str_Printf("hurtPhrase%s", &spC, M2C_BITWISE(f32, temp_ret_4810)), &sp8, 0);
                    strcpy(this + (((atoi(&spC) - 1) * 0x24) + 0x2E0), sp8);
                }
            } else if (strnicmp("Percentage", &sp2C, 0xA) == 0) {
                strcpy(&spC, &sp36);
                if (atoi(&spC) <= 3) {
                    temp_ret_4850 = atoi(&spC);
                    temp_r5_4853 = (temp_ret_4850 - 1) * 0x24;
                    var_r29_4790->LoadFloat(Str_Printf("percentage%s", &spC, temp_r5_4853, M2C_BITWISE(f32, temp_ret_4850)), this + (temp_r5_4853 + 0x300), 0);
                }
            }
            var_r29_4790 = var_r29_4790->unkC->GetNextLine(var_r29_4790);
            goto loop_11;
        }
        return 1;
    }
    return arg0->LoadFloat("phraseDelay", &this->unk34C, 0);
}
#endif

void IceBossDescriptor::Deinit() {
    EnemyDescriptor::Deinit();
    pIceBossDesc = NULL;
}

#if 0 // DRAFT: illegal type
void IceBossDescriptor::Init() {
    s32 var_r28_4929;
    s32 var_r31_4930;
    void *temp_r29_4932;

    EnemyDescriptor::Init();
    this->unk1D4 = 0;
    this->unk264 = 1;
    pIceBossDesc = this;
    IceBoss_UpdateParams(NULL);
    this->unk34C = 1.0f;
    var_r28_4929 = 0;
    var_r31_4930 = 0;
    do {
        temp_r29_4932 = this + var_r31_4930;
        strcpy(temp_r29_4932 + 0x2E0, "");
        var_r28_4929 += 1;
        M2C_FIELD(temp_r29_4932, f32 *, 0x300) = 0.0f;
        var_r31_4930 += 0x24;
    } while (var_r28_4929 < 3);
}
#endif

void IceBoss_UpdateParams(void *arg0) {
    if ((IceBossDescriptor *) pIceBossDesc != NULL) {
        pIceBossDesc->unk2B4 = fWeaponVulMult;
        pIceBossDesc->unk2B8 = fSwordStuckDelay;
        pIceBossDesc->unk2C8 = fStalactiteHeight;
        pIceBossDesc->unk2BC = fStalactiteDelay;
        pIceBossDesc->unk2C0 = fIceWaveDelay;
        pIceBossDesc->unk2C4 = fIceBreathDelay;
        pIceBossDesc->unk2CC = fIceWaveSpeed;
        pIceBossDesc->unk2D0 = iStalactiteGemsH;
        pIceBossDesc->unk2D4 = iStalactiteGemsM;
        pIceBossDesc->unk2D8 = iStalactiteGemsS;
        pIceBossDesc->unk2DC = iStalactiteGemsF;
    }
}
