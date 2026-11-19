#include "spyro/source/Enemies_IceBoss.h"
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
#include "spyro/source/EarthShockwave.h"
#include "spyro/source/ElementalShield.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/IceBossGoals.h"
#include "spyro/source/IceBossStalactite.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/ZapArcFX.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/PhrasePlayer.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 atoi(s8 *);                                     /* extern */
M2C_UNK free(MKCollisionInfo *);                    /* extern */
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
#if 0 // DRAFT: identifier 'IceBoss::GetCharacterName()' redeclared
static M2C_UNK lit_752;                                /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_753;                                /* unable to generate initializer: unknown type; const */

static s32 lit_959 = 0x10000;                          /* const */

s32 IceBoss::GetCharacterName() {
    if (IsIceKing() != 0) {
        return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x328);
    }
    return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x368);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA08'
void IceBoss::UpdateWeaponCollisionCapsule() {
    CalcSubObjWorldMatrix(M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s32 *, 0xE44), (Matrix *) &arg_sp70);
    arg_sp50.operator*(M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), f32 *, 0xE64));
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unkEE0.unk80 = arg_sp20;
    arg_sp28 = arg_spA8 + arg_sp58;
    arg_sp60 = arg_sp20;
    M2C_FIELD(this, f64 *, 0xF68) = (f64) arg_sp28;
    arg_sp68 = (f64) arg_sp28;
    arg_sp30.operator*(M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), f32 *, 0xE68));
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    this->unkF70 = arg_sp10;
    arg_sp18 = arg_spA8 - arg_sp38;
    arg_sp40 = arg_sp10;
    arg_sp48 = (f64) arg_sp18;
    this->unkF78 = (f64) arg_sp18;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void IceBoss::CalcSubObjWorldMatrix(int arg0, Matrix *arg1) {
    void *temp_r3_185;
    MKModel_CalculateSubObjectLocalToWorldMatrix(this->unk4, (SubObjectType) 0, M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s32 *, 0xE44), (Matrix *) &arg_sp40);
    temp_r3_185 = MKModel_GetSubObjectOrigin(this->unk4, (SubObjectType) 0, M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s32 *, 0xE44));
    arg_sp30 = M2C_FIELD(temp_r3_185, f64 *, 0);
    arg_sp38 = M2C_FIELD(temp_r3_185, f64 *, 8);
    arg_sp10 = ((f32) arg_sp38 * arg_sp60) + (((f32) arg_sp30 * arg_sp40) + (arg_sp34 * arg_sp50));
    arg_sp14 = ((f32) arg_sp38 * arg_sp64) + (((f32) arg_sp30 * arg_sp44) + (arg_sp34 * arg_sp54));
    arg_sp18 = ((f32) arg_sp38 * arg_sp68) + (((f32) arg_sp30 * arg_sp48) + (arg_sp34 * arg_sp58));
    arg_sp20 = (f64) arg_sp10;
    arg_sp28 = (f64) arg_sp18;
    arg_sp30 = (f64) arg_sp10;
    arg_sp38 = (f64) arg_sp18;
    arg_sp40.Translate((Matrix *) &arg_sp40, *((MKVector3 *) &arg_sp30));
    M2C_STRUCT_COPY((s32) (arg1 - 4) + 4, (s32) &arg_sp3C + 4, 0x40);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkFB8'
s32 IceBoss::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    if (((u8) this->unkFB8 != 0) && (arg1 != NULL)) {
        CalcSubObjWorldMatrix(M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s32 *, 0xE44), (Matrix *) &arg_sp50);
        M2C_FIELD(arg1, f64 *, 0) = arg_sp80;
        M2C_FIELD(arg1, f64 *, 8) = arg_sp88;
        return 1;
    }
    if (arg1 != NULL) {
        MKVector(0.0f, 0.75f * GetCollisionHeight(), 0.0f);
        arg_sp30.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(arg1, f64 *, 0) = arg_sp10;
        arg_sp18 = arg_sp38 + arg_sp28;
        arg_sp40 = arg_sp10;
        arg_sp48 = (f64) arg_sp18;
        M2C_FIELD(arg1, f64 *, 8) = (f64) arg_sp18;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkFB8'
s32 IceBoss::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    if (((u8) this->unkFB8 != 0) && (arg1 != NULL)) {
        CalcSubObjWorldMatrix(M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s32 *, 0xE44), (Matrix *) &arg_sp10);
        M2C_FIELD(arg1, f64 *, 0) = arg_sp40;
        M2C_FIELD(arg1, f64 *, 8) = arg_sp48;
        return 1;
    }
    return Enemy::GetLookToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA10'
void IceBoss::UpdateBreathingFx() {
    CharacterBreathFX *temp_r3_382;

    if (((u8) this->unk110.unkA10 != 0) || ((u8) this->unkFBB != 0)) {
        this->unk110.unk8FC->unk8 = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float(&gViewSeed, 1.75f, 2.0f);
        temp_r3_382 = this->unk110.unk8FC;
        temp_r3_382->unk10 &= ~0x80;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkFB8'
void IceBoss::EnableWeaponCollision(bool arg0) {
    this->unkFB8 = arg0;
    if (arg0 != 0) {
        this->unkF90->unk4 = 1;
        return;
    }
    this->unkF90->unk4 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk520'
void IceBoss::UpdateSummonWeapon() {
    MKProp *temp_r3_438;
    MKProp *temp_r3_539;
    f32 temp_f3_489;
    f32 var_f0_467;
    f32 var_f31_477;
    s32 temp_r3_530;
    if (this->unk110.unk520->CheckEvent(7) != 0) {
        *(this + ((this->unk110.unkA08 * 0x28) + 0xE58)) = M2C_FIELD(&gb, f32 *, 0x30C) + 1.0f;
        temp_r3_438 = this->unkF94;
        temp_r3_438->Enable(M2C_FIELD(&gb, f32 *, 0x30C));
        this->unkFBB = 1;
    }
    if ((u8) this->unkFBB != 0) {
        CalcSubObjWorldMatrix(M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s32 *, 0xE44), (Matrix *) &arg_sp70);
        var_f0_467 = 1.0f - ((*(this + ((this->unk110.unkA08 * 0x28) + 0xE58)) - M2C_FIELD(&gb, f32 *, 0x30C)) / 1.0f);
        if (var_f0_467 < 1.0f) {

        } else {
            var_f0_467 = 1.0f;
        }
        if (var_f0_467 > 0.0f) {
            var_f31_477 = var_f0_467;
        } else {
            var_f31_477 = 0.0f;
        }
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
        temp_f3_489 = this->unkEE0.unk38;
        arg_sp50 = arg_sp30;
        arg_sp38 = arg_spA8 - temp_f3_489;
        arg_sp58 = (f64) arg_sp38;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        arg_sp40 = arg_sp20;
        arg_sp28 = (f32) arg_sp58 * var_f31_477;
        arg_sp48 = (f64) arg_sp28;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
        arg_sp60 = arg_sp10;
        arg_sp18 = temp_f3_489 + (f32) arg_sp48;
        this->unkEE0.unk70 = (f32) arg_sp60;
        arg_sp68 = (f64) arg_sp18;
        this->unkEE0.unk74 = arg_sp64;
        this->unkEE0.unk78 = (f32) arg_sp68;
        this->unkEE0.unk7C = 1.0f;
        MKModel_SetWorldMatrix(this->unkF94->unk4, *((Matrix *) &this->unkEE0.unk40));
        temp_r3_530 = this->unk110.unkA08 * 0x28;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (M2C_FIELD(&gb, f32 *, 0x30C) == *(this + (temp_r3_530 + 0xE58))) {
            M2C_FIELD((this + temp_r3_530), s8 *, 0xE54) = 0;
            temp_r3_539 = this->unkF94;
            temp_r3_539->Disable();
            this->unkFBB = 0;
        }
    }
    if (HasAnimFinished() != 0) {
        SetAnim((AnimSequenceType) 1, 0, 0, 0.15f, 0U, 0U);
        M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s8 *, 0xE55) = 0;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void IceBoss::SummonWeapon() {
    Matrix *temp_r3_635;
    void *temp_r3_607;
    SetAnim((AnimSequenceType) 0x12, 0xCD, 0, 0.15f, 4U, 0U);
    M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s8 *, 0xE55) = 1;
    CalcSubObjWorldMatrix(M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s32 *, 0xE44), (Matrix *) &arg_sp50);
    temp_r3_607 = this->unk8;
    arg_sp20 = -M2C_FIELD(temp_r3_607, f32 *, 0);
    arg_sp24 = -M2C_FIELD(temp_r3_607, f32 *, 4);
    arg_sp28 = -M2C_FIELD(temp_r3_607, f32 *, 8);
    arg_sp40 = (f64) arg_sp20;
    arg_sp48 = (f64) arg_sp28;
    M2C_STRUCT_COPY((s32) &this->unkEDC + 4, (s32) &arg_sp4C + 4, 0x40);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_r3_635 = &this->unkEE0;
    arg_sp30 = arg_sp10;
    arg_sp18 = (f32) arg_sp48 * 5000.0f;
    arg_sp38 = (f64) arg_sp18;
    temp_r3_635->Translate(temp_r3_635, *((MKVector3 *) &arg_sp30));
    M2C_STRUCT_COPY((s32) &this->unkEE0.unk3C + 4, (s32) &this->unkEDC + 4, 0x40);
    this->unkFBB = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkEC8'
void IceBoss::DestroyShield() {
    u32 temp_r5_715;

    this->unkEC8 = 1;
    this->unkECA = 1;
    this->unkEC9 = 0;
    ShatterSubObj((s32) this->unkEBC, this->unkED0);
    if (IsIceKing() != 0) {
        KDSound_Play3d(GS_IceBossShieldSmash, this->unkED0->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    } else {
        KDSound_Play3d(GS_ElecBossShieldSmash, this->unkED0->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    }
    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, (s32) this->unkEBC, 0U, 1U);
    temp_r5_715 = this->unkEC0;
    if (temp_r5_715 != -1U) {
        MKModel_EnableSubObject(this->unk4, (SubObjectType) 1, (s32) temp_r5_715, 0U, 1U);
    }
    this->unkED0->unk84 = this->unkFA8;
    this->unkFCC = M2C_FIELD(&gb, f32 *, 0x30C) + 5.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk520'
void IceBoss::UpdateFormShield() {
    f32 temp_f1_782;
    f32 temp_f2_781;
    f32 var_f0_786;
    if (this->unk110.unk520->CheckEvent(7) != 0) {
        this->unkFBA = 1;
        this->unk110.unkA10 = 1;
    }
    if (this->unk110.unk520->CheckEvent(8) != 0) {
        this->unk110.unkA10 = 0;
        this->unkFBA = 0;
        this->unkEC8 = 0;
        this->unk110.unk9C0 = this->unk110.unk928->unkEC;
        this->unkFB0 = this->unkFA8;
    }
    if ((u8) this->unkFBA != 0) {
        temp_f2_781 = this->unkFAC;
        temp_f1_782 = this->unkFA8;
        if (temp_f2_781 < temp_f1_782) {
            var_f0_786 = (gUpdateTimeDelta * temp_f1_782) + temp_f2_781;
            if (var_f0_786 < temp_f1_782) {

            } else {
                var_f0_786 = temp_f1_782;
            }
            this->unkFAC = var_f0_786;
        }
    }
    this->unkFB0 = this->unkFAC;
    if ((u8) this->unk110.unkA10 != 0) {
        if (IsIceKing() != 0) {
            this->unk110.unk8FC->EmitBreathFx(2, 1000.0f, 0.2f, 0.5f, 0.0f, 0.5235987f);
            return;
        }
        if (IsIceKing() == 0) {
            MKModel_GetRefPointMatrix(this->unk4, *this->unk110.unk8FC->unk0, (Matrix *) &arg_spF0, 1U);
            arg_sp70 = -1.0f;
            arg_sp40 = -arg_sp118;
            arg_sp60 = 1.0f;
            arg_sp38 = -arg_sp110;
            arg_sp3C = -arg_sp114;
            arg_sp68 = -1.0f;
            arg_sp6C = -1.0f;
            arg_sp58 = 1.0f;
            arg_sp5C = 1.0f;
            arg_sp88 = (f64) arg_sp38;
            arg_sp90 = (f64) arg_sp40;
            arg_spA8 = (f64) arg_sp68;
            arg_spB0 = (f64) arg_sp70;
            arg_sp98 = (f64) arg_sp58;
            arg_spA0 = (f64) arg_sp60;
            KDRand_Vector(*((MKVector3 *) &arg_spB8), *((MKVector3 *) &arg_spA8));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_spC8 = arg_sp48;
            arg_sp50 = arg_spC0 * 0.5f;
            arg_spD0 = (f64) arg_sp50;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp18 = 1.0f;
            arg_sp1C = 0.0f;
            arg_sp30 = (f32) arg_spD0 + (f32) arg_sp90;
            arg_sp20 = 0.5f;
            arg_sp24 = 1.0f;
            arg_spD8 = arg_sp28;
            arg_spE0 = (f64) arg_sp30;
            arg_sp78 = (f64) arg_sp18;
            arg_sp80 = (f64) arg_sp20;
            arg_sp10 = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
            ((ZapArcFX *) (M2C_FIELD(&gb, ZapArcFX **, 0x94)))->Trigger(*((MKVector3 *) &arg_sp120), *((MKVector3 *) &arg_spD8), arg_sp10, lit_1266, (MKVector4) &arg_sp78);
            this->unk1064 = 1;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkEC9'
void IceBoss::FormShield() {
    this->unkEC9 = 1;
    this->unkFBA = 0;
    this->unkFAC = 0.0f;
    this->unkFB0 = 0.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA08'
void IceBoss::DestroyWeapon() {
    s32 temp_r0_939;
    u32 temp_r5_1061;
    void *temp_r5_1039;

    temp_r0_939 = this->unk110.unkA08;
    switch (temp_r0_939) {                          /* irregular */
    case 2:
        if ((u8) M2C_FIELD((this + (temp_r0_939 * 0x28)), u8 *, 0xE54) == 0) {
            if (IsIceKing() != 0) {
                KDSound_Play3d(GS_IceBossSwordSmash, M2C_FIELD(M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), void **, 0xE60), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
            } else {
                KDSound_Play3d(GS_ElecBossWeaponSmash, M2C_FIELD(M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), void **, 0xE60), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
        break;
    case 1:
        if ((u8) M2C_FIELD((this + (temp_r0_939 * 0x28)), u8 *, 0xE54) == 0) {
            if (IsIceKing() != 0) {
                KDSound_Play3d(GS_IceBossAxeSmash, M2C_FIELD(M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), void **, 0xE60), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
            } else {
                KDSound_Play3d(GS_ElecBossWeaponSmash, M2C_FIELD(M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), void **, 0xE60), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
        break;
    }
    M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s8 *, 0xE54) = 1;
    M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s8 *, 0xE56) = 1;
    M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s8 *, 0xE55) = 0;
    temp_r5_1039 = this + (this->unk110.unkA08 * 0x28);
    ShatterSubObj(M2C_FIELD(temp_r5_1039, s32 *, 0xE44), M2C_FIELD(temp_r5_1039, Shatterable **, 0xE60));
    M2C_FIELD(M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), void **, 0xE60), f32 *, 0x84) = (f32) this->unkFA8;
    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s32 *, 0xE44), 0U, 1U);
    temp_r5_1061 = M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), u32 *, 0xE48);
    if (temp_r5_1061 != -1U) {
        MKModel_EnableSubObject(this->unk4, (SubObjectType) 1, (s32) temp_r5_1061, 0U, 1U);
    }
    this->unkFC8 = M2C_FIELD(&gb, f32 *, 0x30C) + 5.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk928'
void IceBoss::UpdatePhrasesAndSounds() {
    EnemyDescriptor *temp_r3_1099;
    f32 temp_f1_1193;
    f32 temp_f30_1110;
    f32 temp_f30_1125;
    f32 temp_f31_1106;
    s32 var_r29_1131;
    s32 var_r30_1132;

    temp_r3_1099 = this->unk110.unk928;
    temp_f31_1106 = this->unk110.unk9B8;
    temp_f30_1110 = (f32) temp_r3_1099->unk11C * this->unk110.unk928->GetEnemySetting((EnemySettingType) 0);
    temp_f30_1125 = ((temp_f30_1110 - ((f32) (this->unk110.unk9D8 + 1) * temp_r3_1099->GetEnemySetting((EnemySettingType) 0))) + temp_f31_1106) / temp_f30_1110;
    if (temp_f30_1125 > this->unk1008) {
        this->unk1008 = temp_f30_1125;
    }
    var_r29_1131 = 0;
    var_r30_1132 = 0;
loop_3:
    if ((temp_f30_1125 != 0.0f) && (*(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_1132 + 0x300)) != 0.0f) && (this->unk1008 > *(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_1132 + 0x300))) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f30_1125 == *(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_1132 + 0x300))) != 0))) {
        this->unk100C = M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x34C);
        this->unk1004 = checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_1132 + 0x2E0);
    } else {
        var_r29_1131 += 1;
        var_r30_1132 += 0x24;
        if (var_r29_1131 < 3) {
            goto loop_3;
        }
    }
    if ((this->unk100C < 0.0f) && ((s8 *) this->unk1004 != NULL) && (PhrasePlayer_IsAnyEventPlaying() == 0)) {
        this->unk1000 = PhrasePlayer_PlayEvent(this->unk1004);
        this->unk100C = 0.0f;
        this->unk1004 = NULL;
    }
    this->unk1008 = temp_f30_1125;
    temp_f1_1193 = this->unk100C;
    if (temp_f1_1193 > 0.0f) {
        this->unk100C = temp_f1_1193 - gUpdateTimeDelta;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk520'
void IceBoss::CheckAnimEvents() {
    f32 var_f1_1321;
    f64 temp_f0_1345;
    f64 temp_f2_1344;
    s32 temp_r0_1328;
    s32 temp_r0_1355;
    s32 var_r30_1267;
    void *temp_r3_1320;
    void *temp_r3_1342;
    void *temp_r4_1326;
    if (this->unk110.unk520->CheckEvent(0xD) != 0) {
        CalcSubObjWorldMatrix(M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s32 *, 0xE44), (Matrix *) &arg_sp160);
        arg_sp78 = -arg_sp180;
        arg_sp7C = -arg_sp184;
        arg_sp80 = -arg_sp188;
        arg_spF8 = (f64) arg_sp78;
        arg_sp100 = (f64) arg_sp80;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        arg_sp108 = arg_sp68;
        arg_sp70 = (f32) arg_sp100 * 200.0f;
        arg_sp110 = (f64) arg_sp70;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        var_r30_1267 = 0;
        arg_sp148 = arg_sp58;
        arg_sp60 = arg_sp198 + (f32) arg_sp110;
        arg_sp150 = (f64) arg_sp60;
        do {
            KDRand_UnitVectorXZ();
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_spE8 = arg_sp48;
            arg_sp50 = arg_spE0 * 300.0f;
            arg_sp138 = arg_sp48;
            arg_spF0 = (f64) arg_sp50;
            arg_sp140 = (f64) arg_sp50;
            arg_sp13C = 100.0f * MKRand_Float(&gViewSeed, 10.0f, 17.0f);
            arg_sp10 = MKRand_Float(&gViewSeed, 1.0f, 3.0f);
            this->unk1068->Emit(*((MKVector3 *) &arg_sp148), *((MKVector3 *) &arg_sp138), arg_sp10);
            var_r30_1267 += 1;
        } while (var_r30_1267 < 0x14);
        return;
    }
    if (this->unk110.unk520->CheckEvent(0xB) != 0) {
        temp_r3_1320 = this->unk8;
        var_f1_1321 = 0.5f;
        arg_sp128 = M2C_FIELD(temp_r3_1320, f64 *, 0x30);
        arg_sp130 = M2C_FIELD(temp_r3_1320, f64 *, 0x38);
        temp_r4_1326 = this->unk110.unk910;
        temp_r0_1328 = M2C_FIELD(M2C_FIELD(temp_r4_1326, void **, 0), s32 *, 0x68);
        switch (temp_r0_1328) {                     /* switch 1; irregular */
        case 0x3E:                                  /* switch 1 */
            MKModel_CalculateRefPointWorldPosition(this->unk4, *M2C_FIELD(temp_r4_1326, s32 **, 0x7C), (MKVector3 *) &arg_sp128);
            /* fallthrough */
        case 0x97:                                  /* switch 1 */
            temp_r3_1342 = this->unk8;
            var_f1_1321 = 2.0f;
            temp_f2_1344 = M2C_FIELD(temp_r3_1342, f64 *, 0x30);
            temp_f0_1345 = M2C_FIELD(temp_r3_1342, f64 *, 0x38);
            arg_spC8 = temp_f2_1344;
            arg_spD0 = temp_f0_1345;
            arg_sp128 = temp_f2_1344;
            arg_sp130 = temp_f0_1345;
            break;
        }
        arg_sp38 = 0.5f;
        temp_r0_1355 = this->unk110.unk928->unk1D0;
        arg_sp3C = 0.5f;
        arg_sp40 = 1.0f;
        arg_sp44 = 1.0f;
        arg_spB8 = (f64) arg_sp38;
        arg_spC0 = (f64) arg_sp40;
        arg_sp118 = (f64) arg_sp38;
        arg_sp120 = (f64) arg_sp40;
        switch (temp_r0_1355) {                     /* switch 2; irregular */
        case 2:                                     /* switch 2 */
            arg_sp28 = 0.5f;
            arg_sp2C = 0.5f;
            arg_sp30 = 1.0f;
            arg_sp34 = 1.0f;
            arg_spA8 = (f64) arg_sp28;
            arg_spB0 = (f64) arg_sp30;
            arg_sp118 = (f64) arg_sp28;
            arg_sp120 = (f64) arg_sp30;
            break;
        case 1:                                     /* switch 2 */
            arg_sp18 = 1.0f;
            arg_sp1C = 0.1f;
            arg_sp20 = 0.5f;
            arg_sp24 = 1.0f;
            arg_sp98 = (f64) arg_sp18;
            arg_spA0 = (f64) arg_sp20;
            arg_sp118 = (f64) arg_sp18;
            arg_sp120 = (f64) arg_sp20;
            break;
        }
        arg_sp88 = arg_sp118;
        arg_sp90 = arg_sp120;
        this->unkFF4->Trigger(*((MKVector3 *) &arg_sp128), var_f1_1321, 0U, (MKVector4) &arg_sp88);
        return;
    }
    Enemy::CheckAnimEvents();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk520'
void IceBoss::UpdateFormWeapon() {
    f32 temp_f1_1466;
    f32 temp_f2_1465;
    f32 var_f0_1470;
    if (this->unk110.unk520->CheckEvent(7) != 0) {
        this->unkFB9 = 1;
        this->unk110.unkA10 = 1;
        M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s8 *, 0xE54) = 0;
        this->unkFB4 = 0.0f;
    }
    if (this->unk110.unk520->CheckEvent(8) != 0) {
        this->unk110.unkA10 = 0;
        this->unkFB9 = 0;
        this->unkFB4 = this->unkFA8;
    }
    if ((u8) this->unkFB9 != 0) {
        temp_f2_1465 = this->unkFAC;
        temp_f1_1466 = this->unkFA8;
        if (temp_f2_1465 < temp_f1_1466) {
            var_f0_1470 = (gUpdateTimeDelta * temp_f1_1466) + temp_f2_1465;
            if (var_f0_1470 < temp_f1_1466) {

            } else {
                var_f0_1470 = temp_f1_1466;
            }
            this->unkFAC = var_f0_1470;
        }
    }
    this->unkFB4 = this->unkFAC;
    if ((u8) this->unk110.unkA10 != 0) {
        if (IsIceKing() != 0) {
            this->unk110.unk8FC->EmitBreathFx(2, 1000.0f, 0.2f, 0.5f, 0.0f, 0.5235987f);
            return;
        }
        if (IsIceKing() == 0) {
            MKModel_GetRefPointMatrix(this->unk4, *this->unk110.unk8FC->unk0, (Matrix *) &arg_spF0, 1U);
            arg_sp70 = -1.0f;
            arg_sp40 = -arg_sp118;
            arg_sp60 = 1.0f;
            arg_sp38 = -arg_sp110;
            arg_sp3C = -arg_sp114;
            arg_sp68 = -1.0f;
            arg_sp6C = -1.0f;
            arg_sp58 = 1.0f;
            arg_sp5C = 1.0f;
            arg_sp88 = (f64) arg_sp38;
            arg_sp90 = (f64) arg_sp40;
            arg_spA8 = (f64) arg_sp68;
            arg_spB0 = (f64) arg_sp70;
            arg_sp98 = (f64) arg_sp58;
            arg_spA0 = (f64) arg_sp60;
            KDRand_Vector(*((MKVector3 *) &arg_spB8), *((MKVector3 *) &arg_spA8));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_spC8 = arg_sp48;
            arg_sp50 = arg_spC0 * 0.5f;
            arg_spD0 = (f64) arg_sp50;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp18 = 1.0f;
            arg_sp1C = 0.0f;
            arg_sp30 = (f32) arg_spD0 + (f32) arg_sp90;
            arg_sp20 = 0.5f;
            arg_sp24 = 1.0f;
            arg_spD8 = arg_sp28;
            arg_spE0 = (f64) arg_sp30;
            arg_sp78 = (f64) arg_sp18;
            arg_sp80 = (f64) arg_sp20;
            arg_sp10 = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
            ((ZapArcFX *) (M2C_FIELD(&gb, ZapArcFX **, 0x94)))->Trigger(*((MKVector3 *) &arg_sp120), *((MKVector3 *) &arg_spD8), arg_sp10, lit_1160, (MKVector4) &arg_sp78);
            this->unk1064 = 1;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA08'
void IceBoss::FormWeapon() {
    M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s8 *, 0xE55) = 1;
    this->unkFB9 = 0;
    this->unkFAC = 0.0f;
    this->unkFB4 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
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
        if (((s32) this->unk110.unkA08 == var_r29_1626) && ((u8) M2C_FIELD(temp_r30_1629, u8 *, 0xE54) == 0)) {
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
        MKModel_EnableSubObject(this->unk4, (SubObjectType) 1, (s32) temp_r5_1660, this->unkEC8 == 0, 1U);
    }
    if ((u8) this->unkFB8 != 0) {
        this->unkF90->unk4 = 1;
        UpdateWeaponCollisionCapsule();
        return;
    }
    this->unkF90->unk4 = 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void IceBoss::ShatterSubObj(int arg0, Shatterable *arg1) {
    void *temp_r3_1714;
    MKModel_CalculateSubObjectLocalToWorldMatrix(this->unk4, (SubObjectType) 0, arg0, (Matrix *) &arg_sp40);
    temp_r3_1714 = MKModel_GetSubObjectOrigin(this->unk4, (SubObjectType) 0, arg0);
    arg_sp30 = M2C_FIELD(temp_r3_1714, f64 *, 0);
    arg_sp38 = M2C_FIELD(temp_r3_1714, f64 *, 8);
    arg_sp10 = ((f32) arg_sp38 * arg_sp60) + (((f32) arg_sp30 * arg_sp40) + (arg_sp34 * arg_sp50));
    arg_sp14 = ((f32) arg_sp38 * arg_sp64) + (((f32) arg_sp30 * arg_sp44) + (arg_sp34 * arg_sp54));
    arg_sp18 = ((f32) arg_sp38 * arg_sp68) + (((f32) arg_sp30 * arg_sp48) + (arg_sp34 * arg_sp58));
    arg_sp20 = (f64) arg_sp10;
    arg_sp28 = (f64) arg_sp18;
    arg_sp30 = (f64) arg_sp10;
    arg_sp38 = (f64) arg_sp18;
    arg_sp40.Translate((Matrix *) &arg_sp40, *((MKVector3 *) &arg_sp30));
    arg1->Enable();
    MKModel_SetWorldMatrix(arg1->unk4, *((Matrix *) &arg_sp40));
    arg1->Reset();
    arg1->Shatter(0, 0, -1, 0, 1, 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA04'
void IceBoss::ShatterBodyParts() {
    Shatterable *temp_r5_1804;
    s32 var_r29_1793;
    s32 var_r31_1794;
    void *temp_r30_1796;

    var_r29_1793 = 0;
    var_r31_1794 = 0;
    do {
        temp_r30_1796 = this + var_r31_1794;
        if (((s32) this->unk110.unkA04 >= (s32) M2C_FIELD(temp_r30_1796, s32 *, 0xB50)) && ((u8) M2C_FIELD(temp_r30_1796, u8 *, 0xB58) == 0)) {
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
    if (((s32) this->unk110.unkA04 >= (s32) this->unkEC4) && ((u8) this->unkECA == 0) && ((u8) this->unkEC8 == 0)) {
        ShatterSubObj((s32) this->unkEBC, this->unkED0);
        this->unkEC8 = 1;
        this->unkECA = 1;
        if (IsIceKing() != 0) {
            KDSound_Play3d(GS_IceBossShieldSmash, this->unkED0->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            return;
        }
        KDSound_Play3d(GS_ElecBossShieldSmash, this->unkED0->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA24'
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
        MKModel_EnableOnlySubObject(temp_r3_1896, (SubObjectType) this->unk110.unkA24, this->unk110.unkA14, 1U, 1U);
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 1, this->unk110.unkA18, 1U, 1U);
        var_r29_1910 = 0;
        var_r31_1911 = 0;
        do {
            temp_r30_1913 = this + var_r31_1911;
            temp_r5_1914 = M2C_FIELD(temp_r30_1913, u32 *, 0xB44);
            if (temp_r5_1914 != -1U) {
                temp_r4_1918 = this->unk110.unkA04;
                var_r3_1919 = 0;
                if ((temp_r4_1918 >= (s32) M2C_FIELD(temp_r30_1913, s32 *, 0xB4C)) && (temp_r4_1918 < (s32) M2C_FIELD(temp_r30_1913, s32 *, 0xB50))) {
                    var_r3_1919 = 1;
                }
                var_r28_1929 = var_r3_1919;
                if ((var_r29_1910 == 0) && (temp_r4_1918 == (s32) M2C_FIELD(temp_r30_1913, s32 *, 0xB50)) && ((u8) this->unkFBE != 0)) {
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
#endif

#if 0 // DRAFT: undefined identifier 'unkFBE'
void IceBoss::InterceptDamage(bool *arg0) {
    s32 temp_r0_2012;
    s32 temp_r5_1988;
    s32 var_r0_1989;
    s32 var_r7_1976;
    void *var_r6_1984;

    if ((u8) this->unkFBE != 0) {
        this->unk110.unk8C8 = 0;
        this->unk110.unk8C4 = 0;
    }
    var_r7_1976 = 0;
loop_13:
    temp_r0_2012 = this->unk110.unk8C4;
    if (var_r7_1976 < temp_r0_2012) {
        if ((var_r7_1976 < 0) || (var_r7_1976 >= temp_r0_2012)) {
            var_r6_1984 = NULL;
        } else {
            temp_r5_1988 = this->unk110.unk8C0;
            var_r0_1989 = this->unk110.unk8C8 + var_r7_1976;
            if (var_r0_1989 >= temp_r5_1988) {
                var_r0_1989 -= temp_r5_1988;
            }
            var_r6_1984 = this->unk110.unk8CC + (var_r0_1989 * 0x38);
        }
        M2C_FIELD(var_r6_1984, u8 *, 0x34) = (u8) (M2C_FIELD(var_r6_1984, u8 *, 0x34) & ~0x80);
        if ((arg0 != NULL) && ((u8) this->unkFB8 != 0)) {
            *arg0 = 1;
        }
        var_r7_1976 += 1;
        goto loop_13;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA04'
s32 IceBoss::TryChangeStage() {
    f32 temp_f1_2026;
    s32 temp_r0_2049;
    s32 temp_r0_2125;
    s32 temp_r31_2027;

    temp_f1_2026 = GetHealthPercentage();
    temp_r31_2027 = this->unk110.unkA04;
    if ((temp_r31_2027 != 4) && (temp_r31_2027 != 9) && (temp_r31_2027 != 0xE)) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f1_2026 == M2C_FIELD(&fIceBossStageHealth[temp_r31_2027], f32 *, 4)) {
            this->unk110.unkA04 = temp_r31_2027 + 1;
        }
    }
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (temp_f1_2026 == 0.0f) {
        temp_r0_2049 = this->unk110.unk9D8;
        switch (temp_r0_2049) {                     /* irregular */
        case 0:
            if ((u8) M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), u8 *, 0xE54) == 0) {
                DestroyWeapon();
            }
            if ((u8) this->unkEC8 == 0) {
                DestroyShield();
            }
            if (IsIceKing() != 0) {
                this->unkFBE = 1;
            }
            this->unkFE4.Send(NULL);
            StartPhase2();
            break;
        case 1:
            if (IsIceKing() == 0) {
                if ((u8) M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), u8 *, 0xE54) == 0) {
                    DestroyWeapon();
                }
                StartPhase3();
            } else {
                GetMaxHealth();
                SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
                this->unkFBE = 1;
                this->unk110.unkA04 = 0xA;
                this->unk110.unk9D8 = 2;
            }
            this->unkFE8.Send(NULL);
            break;
        case 2:
            if (IsIceKing() != 0) {
                this->unkFBE = 1;
            }
            break;
        }
    }
    temp_r0_2125 = this->unk110.unkA04;
    if ((temp_r0_2125 != temp_r31_2027) && (temp_r0_2125 != 5)) {
        UpdateBodyParts();
        ShatterBodyParts();
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9B8'
void IceBoss::UpdateEnemyHud() {
    EnemyHudData sp8;
    f32 temp_f31_2158;

    sp8.EnemyHudData();
    temp_f31_2158 = this->unk110.unk9B8;
    GetMaxHealth();
    sp8.Init((Enemy *) this, temp_f31_2158, M2C_ERROR(/* Read from unset register $f1 */));
    EnemyHud_Modified(sp8);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA08'
void IceBoss::StartPhase3() {
    ElementalShield *temp_r3_2197;

    this->unk110.unkA08 = 2;
    this->unk110.unkA04 = 0xA;
    this->unk110.unk9D8 = 2;
    GetMaxHealth();
    SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
    UpdateEnemyHud();
    UpdateBodyParts();
    temp_r3_2197 = this->unkFF8;
    temp_r3_2197->Disable();
    this->unkFD4 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2BC);
    this->unkFD8 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2C0);
    this->unkFD0 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2C4);
    this->unk110.unkA10 = 0;
    this->unkFB9 = 0;
    this->unkFB4 = 1.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA08'
void IceBoss::StartPhase2() {
    CharacterBreathFX *temp_r4_2256;
    ElementalShield *temp_r3_2260;

    this->unk110.unkA08 = 1;
    this->unk110.unkA04 = 5;
    this->unk110.unk9D8 = 1;
    GetMaxHealth();
    SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
    UpdateEnemyHud();
    UpdateBodyParts();
    temp_r4_2256 = this->unk110.unk8FC;
    temp_r4_2256->unk10 = (temp_r4_2256->unk10 & ~0x40) | ((IsIceKing() << 6) & 0x40);
    temp_r3_2260 = this->unkFF8;
    temp_r3_2260->Disable(temp_r4_2256);
    this->unkFD4 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2BC);
    this->unkFD8 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2C0);
    this->unk110.unkA10 = 0;
    this->unkFB9 = 0;
    this->unkFB4 = 1.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA08'
void IceBoss::StartPhase1() {
    CharacterBreathFX *temp_r3_2313;
    ElementalShield *temp_r3_2318;

    this->unk110.unkA08 = 0;
    this->unk110.unkA04 = 0;
    this->unk110.unk9D8 = 0;
    GetMaxHealth();
    SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
    this->unk110.unk9C0 = this->unk110.unk928->unkEC;
    UpdateEnemyHud();
    UpdateBodyParts();
    temp_r3_2313 = this->unk110.unk8FC;
    temp_r3_2313->unk10 &= ~0x40;
    temp_r3_2318 = this->unkFF8;
    temp_r3_2318->Disable(0);
    this->unkFD4 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2BC);
    this->unkFD8 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2C0);
    this->unk110.unkA10 = 0;
    this->unkFB9 = 0;
    this->unkFB4 = 1.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9D8'
s32 IceBoss::GetPhase() {
    return this->unk110.unk9D8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk928'
u8 IceBoss::IsIceKing() {
    return this->unk110.unk928->unk1D0 == 2;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1014'
void IceBoss::Message(MKMessage *arg0) {
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
    this->unk1014.Message(arg0);
    this->unk103C.Message(arg0);
    temp_r0_2386 = arg0->unk0;
    switch (temp_r0_2386) {                         /* switch 1; irregular */
    case 181:                                       /* switch 1 */
        Enable();
    default:                                        /* switch 1 */
block_41:
        Enemy::Message(arg0);
        return;
    case 224:                                       /* switch 1 */
        this->unk110.unkA04 = 0xE;
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
        this->unkFE0->Reset();
        M2C_STRUCT_COPY((s32) &arg_sp2C + 4, (s32) (&identity - 4) + 4, 0x40);
        temp_f6_2468 = this->unk110.unk4B8;
        arg_sp50 = temp_f6_2468;
        temp_f1_2476 = this->unk110.unk4BC;
        arg_sp54 = temp_f1_2476;
        temp_f5_2482 = this->unk110.unk4C0;
        arg_sp58 = temp_f5_2482;
        arg_sp18 = (up.unk0 * temp_f1_2476) - (up.unk4 * temp_f6_2468);
        arg_sp10 = (up.unk4 * temp_f5_2482) - (up.unk8 * temp_f1_2476);
        arg_sp14 = (up.unk8 * temp_f6_2468) - (up.unk0 * temp_f5_2482);
        arg_sp28 = (f64) arg_sp18;
        arg_sp20 = (f64) arg_sp10;
        arg_sp5C = 0.0f;
        arg_sp30 = (f32) arg_sp20;
        arg_sp34 = arg_sp24;
        arg_sp38 = (f32) arg_sp28;
        arg_sp3C = 0.0f;
        arg_sp60 = this->unk110.unk4A8;
        arg_sp64 = this->unk110.unk4AC;
        temp_f1_2508 = this->unk110.unk4B0;
        arg_sp68 = temp_f1_2508;
        arg_sp6C = 1.0f;
        Teleport(&arg_sp30, &up, temp_f1_2508, arg_sp24, (f32) arg_sp20, 0.0f, temp_f5_2482, temp_f6_2468, up.unk8, up.unk4);
        goto block_41;
    case 4:                                         /* switch 1 */
        temp_r29_2520 = checked_cast<MeleeAttackHitMsg *, MKMessage>(arg0);
        if (((u8) this->unkFB8 != 0) && ((u32) M2C_FIELD(temp_r29_2520, u32 *, 0x38) == (MKCollisionInfo *) this->unkF90)) {
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
            if (((u8) this->unkFB8 != 0) && ((u32) M2C_FIELD(temp_r3_2540, u32 *, 0x30) == (MKCollisionInfo *) this->unkF90)) {
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
        if (!(((u8) this->unk110.unk9F9 >> 7U) & 1)) {
            Enemy::Message(arg0);
            Deactivate();
            return;
        }
        temp_f31_2602 = this->unk110.unk9B8;
        Enemy::Message(arg0);
        SetHealth(temp_f31_2602);
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkFFC'
void IceBoss::Despawn(bool arg0) {
    MKProp *temp_r3_2650;
    MKProp *temp_r3_2655;
    ManagedLight *temp_r4_2638;
    Shatterable *temp_r3_2662;
    void *temp_r3_2667;
    void *temp_r3_2672;
    void *temp_r3_2677;

    Enemy::Despawn(arg0);
    M2C_FIELD(&gb, s32 *, 0x360) = 0;
    temp_r4_2638 = this->unkFFC;
    if (temp_r4_2638 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_2638, 0U);
    }
    Disable();
    temp_r3_2650 = this->unkF94;
    temp_r3_2650->Disable();
    temp_r3_2655 = this->unkFDC;
    temp_r3_2655->Disable();
    this->unkFE0->Reset();
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

#if 0 // DRAFT: undefined identifier 'unk1010'
s32 IceBoss::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    if (Enemy::Spawn(arg0, arg1) != 0) {
        M2C_FIELD(&gb, IceBoss **, 0x360) = this;
        StartPhase1();
        KDSound_Stop(&this->unk1010);
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

#if 0 // DRAFT: undefined identifier 'unkEC8'
void IceBoss::Draw() {
    u8 var_r30_2779;
    void *temp_r3_2811;
    void *temp_r3_2862;
    void *temp_r3_2949;
    void *temp_r3_2977;
    void *temp_r5_2784;
    void *temp_r7_2799;
    Enemy::Draw();
    var_r30_2779 = 0;
    if (((u8) this->unkEC8 != 0) || (temp_r5_2784 = this + (this->unk110.unkA08 * 0x28), (((u8) M2C_FIELD(temp_r5_2784, u8 *, 0xE54) == 0) == 0))) {
        var_r30_2779 = 1;
    } else {
        temp_r7_2799 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        arg_spA0 = M2C_FIELD(temp_r7_2799, f64 *, 0x30);
        arg_spA8 = M2C_FIELD(temp_r7_2799, f64 *, 0x38);
        MKModel_CalculateSubObjectLocalToWorldMatrix(this->unk4, (SubObjectType) 0, M2C_FIELD(temp_r5_2784, s32 *, 0xE44), (Matrix *) &arg_spD0);
        temp_r3_2811 = MKModel_GetSubObjectOrigin(this->unk4, (SubObjectType) 0, M2C_FIELD((this + (this->unk110.unkA08 * 0x28)), s32 *, 0xE44));
        arg_sp90 = M2C_FIELD(temp_r3_2811, f64 *, 0);
        arg_sp98 = M2C_FIELD(temp_r3_2811, f64 *, 8);
        arg_sp20 = ((f32) arg_sp98 * arg_spF0) + (((f32) arg_sp90 * arg_spD0) + (arg_sp94 * arg_spE0));
        arg_sp24 = ((f32) arg_sp98 * arg_spF4) + (((f32) arg_sp90 * arg_spD4) + (arg_sp94 * arg_spE4));
        arg_sp28 = ((f32) arg_sp98 * arg_spF8) + (((f32) arg_sp90 * arg_spD8) + (arg_sp94 * arg_spE8));
        arg_sp80 = (f64) arg_sp20;
        arg_sp88 = (f64) arg_sp28;
        arg_sp90 = (f64) arg_sp20;
        arg_sp98 = (f64) arg_sp28;
        arg_spD0.Translate((Matrix *) &arg_spD0, *((MKVector3 *) &arg_sp90));
        arg_spC0 = arg_sp100;
        arg_spC8 = arg_sp108;
        MKModel_CalculateSubObjectLocalToWorldMatrix(this->unk4, (SubObjectType) 0, (s32) this->unkEBC, (Matrix *) &arg_spD0);
        temp_r3_2862 = MKModel_GetSubObjectOrigin(this->unk4, (SubObjectType) 0, (s32) this->unkEBC);
        arg_sp90 = M2C_FIELD(temp_r3_2862, f64 *, 0);
        arg_sp98 = M2C_FIELD(temp_r3_2862, f64 *, 8);
        arg_sp10 = ((f32) arg_sp98 * arg_spF0) + (((f32) arg_sp90 * arg_spD0) + (arg_sp94 * arg_spE0));
        arg_sp14 = ((f32) arg_sp98 * arg_spF4) + (((f32) arg_sp90 * arg_spD4) + (arg_sp94 * arg_spE4));
        arg_sp18 = ((f32) arg_sp98 * arg_spF8) + (((f32) arg_sp90 * arg_spD8) + (arg_sp94 * arg_spE8));
        arg_sp70 = (f64) arg_sp10;
        arg_sp78 = (f64) arg_sp18;
        arg_sp90 = (f64) arg_sp10;
        arg_sp98 = (f64) arg_sp18;
        arg_spD0.Translate((Matrix *) &arg_spD0, *((MKVector3 *) &arg_sp90));
        arg_spB0 = arg_sp100;
        arg_spB8 = arg_sp108;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f3 */);
        arg_sp60 = arg_sp40;
        arg_sp48 = (f32) arg_spC8 - (f32) arg_spA8;
        arg_sp68 = (f64) arg_sp48;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f3 */);
        arg_sp50 = arg_sp30;
        arg_sp38 = (f32) arg_spB8 - (f32) arg_spA8;
        arg_sp58 = (f64) arg_sp38;
        if ((((f32) arg_sp68 * (f32) arg_sp68) + (((f32) arg_sp60 * (f32) arg_sp60) + (arg_sp64 * arg_sp64))) > (((f32) arg_sp58 * (f32) arg_sp58) + (((f32) arg_sp50 * (f32) arg_sp50) + (arg_sp54 * arg_sp54)))) {
            var_r30_2779 = 1;
        }
    }
    if (var_r30_2779 != 0) {
        temp_r3_2949 = this + (this->unk110.unkA08 * 0x28);
        if ((u8) M2C_FIELD(temp_r3_2949, u8 *, 0xE54) == 0) {
            DrawSubObject(M2C_FIELD(temp_r3_2949, s32 *, 0xE44), this->unkFB4);
        }
        if ((u8) this->unkEC8 == 0) {
            DrawSubObject((s32) this->unkEBC, this->unkFB0);
        }
    } else {
        if ((u8) this->unkEC8 == 0) {
            DrawSubObject((s32) this->unkEBC, this->unkFB0);
        }
        temp_r3_2977 = this + (this->unk110.unkA08 * 0x28);
        if ((u8) M2C_FIELD(temp_r3_2977, u8 *, 0xE54) == 0) {
            DrawSubObject(M2C_FIELD(temp_r3_2977, s32 *, 0xE44), this->unkFB4);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1014'
void IceBoss::Update() {
    f64 sp48;
    f64 sp40;
    M2C_UNK sp30;
    M2C_UNK sp20;
    f32 sp18;
    s32 sp8;

    Enemy::Update();
    if (IsIceKing() == 0) {
        sp8 = 1;
        this->unk1014.Update(GS_ElecBossExtra1, 1U, 1U, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        sp8 = 1;
        this->unk103C.Update(GS_ElecBossExtra3, 1U, this->unk1064, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        this->unk1064 = 0;
    }
    UpdateWeapons();
    if ((s32) this->unk110.unkA04 >= 5) {
        UpdateBreathingFx();
    }
    if (IsIceKing() != 0) {
        UpdatePhrasesAndSounds();
    }
    MKVector(0.0f, 400.0f, 0.0f);
    sp30.GetPos();
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unkF80 = sp10;
    sp18 = sp38 + sp28;
    sp40 = sp10;
    sp48 = (f64) sp18;
    this->unkF88 = (f64) sp18;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkF90'
void IceBoss::EnableCollision(bool arg0) {
    MKCollisionInfo *temp_r5_3083;

    temp_r5_3083 = this->unkF90;
    if (temp_r5_3083 != NULL) {
        if (arg0 != 0) {
            temp_r5_3083->unk4 = 1;
        } else {
            temp_r5_3083->unk4 = 0;
        }
    }
    Enemy::EnableCollision(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA04'
void IceBoss::SetDefaults() {
    Enemy::SetDefaults();
    this->unk110.unkA04 = 0;
    this->unk110.unkA08 = 0;
    this->unk110.unkA10 = 0;
    this->unkFB8 = 0;
    this->unkFBC = 0;
    this->unkFB9 = 0;
    this->unkFBA = 0;
    this->unkFBB = 0;
    this->unkFAC = 0.0f;
    this->unkFA8 = 0.65f;
    if (IsIceKing() == 0) {
        this->unkFA8 = 1.0f;
    }
    this->unkFB0 = this->unkFA8;
    this->unkFB4 = this->unkFA8;
    this->unkFC0 = 0.0f;
    this->unkFC4 = 0.0f;
    this->unkFC8 = 0.0f;
    this->unkFCC = 0.0f;
    this->unkFD4 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2BC);
    this->unkFD8 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2C0);
    this->unkFD0 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x2C4);
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
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKSceneManager *temp_r3_3547;
    Matrix *temp_r30_3306;
    f32 temp_f30_3360;
    f32 temp_f4_3200;
    f32 temp_f5_3206;
    f32 temp_f8_3202;
    f32 temp_r31_3217;
    f32 var_f0_3329;
    f32 var_f5_3233;
    f32 var_f5_3300;
    f64 temp_f1_3239;
    f64 temp_f1_3245;
    f64 temp_f1_3249;
    s32 temp_r3_3268;
    s32 var_r0_3278;
    s32 var_r23_3477;
    s32 var_r29_3308;
    u8 var_r24_3318;
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
        sp7C = (up.unk8 * temp_f5_3206) - (up.unk0 * temp_f4_3200);
        sp78 = (up.unk4 * temp_f4_3200) - (up.unk8 * temp_f8_3202);
        temp_r31_3217 = this->unk110.unkA00->unkB0;
        sp80 = (up.unk0 * temp_f8_3202) - (up.unk4 * temp_f5_3206);
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
        temp_r30_3306 = M2C_BITWISE(s32, temp_r31_3217) + 0x7C;
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
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_r6_3375 = M2C_FIELD(temp_r31_3217, void **, 0x70);
            sp178 = sp68;
            sp70 = (f32) sp1C0 + sp168.unk8;
            M2C_FIELD(temp_r6_3375, f64 *, 0) = sp68;
            sp180 = (f64) sp70;
            M2C_FIELD(temp_r6_3375, f64 *, 8) = (f64) sp70;
            KDMath_Slerp(sp138, *((MKVector3 *) arg2), 0.7853982f);
            sp148.operator*(temp_f30_3360);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp60 = (f32) sp1C0 + sp148.unk8;
            temp_r5_3401 = M2C_FIELD(temp_r31_3217, void **, 0x70) + M2C_FIELD(temp_r31_3217, s32 *, 0x68);
            M2C_FIELD(temp_r5_3401, f64 *, 0) = sp58;
            sp158 = sp58;
            sp160 = (f64) sp60;
            M2C_FIELD(temp_r5_3401, f64 *, 8) = (f64) sp60;
            sp118.operator*(temp_f30_3360);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_r6_3421 = M2C_FIELD(temp_r31_3217, void **, 0x70) + (M2C_FIELD(temp_r31_3217, s32 *, 0x68) * 2);
            sp50 = (f32) sp1C0 + sp118.unk8;
            M2C_FIELD(temp_r6_3421, f64 *, 0) = sp48;
            sp128 = sp48;
            sp130 = (f64) sp50;
            M2C_FIELD(temp_r6_3421, f64 *, 8) = (f64) sp50;
            KDMath_Slerp(spE8, *((MKVector3 *) arg2), -0.7853982f);
            spF8.operator*(temp_f30_3360);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp40 = (f32) sp1C0 + spF8.unk8;
            temp_r5_3448 = M2C_FIELD(temp_r31_3217, void **, 0x70) + (M2C_FIELD(temp_r31_3217, s32 *, 0x68) * 3);
            M2C_FIELD(temp_r5_3448, f64 *, 0) = sp38;
            sp108 = sp38;
            sp110 = (f64) sp40;
            M2C_FIELD(temp_r5_3448, f64 *, 8) = (f64) sp40;
            spC8.operator*(temp_f30_3360);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            temp_r4_3466 = M2C_FIELD(temp_r31_3217, void **, 0x70) + (M2C_FIELD(temp_r31_3217, s32 *, 0x68) * 4);
            sp30 = (f32) sp1C0 - spC8.unk8;
            M2C_FIELD(temp_r4_3466, f64 *, 0) = sp28;
            spD8 = sp28;
            spE0 = (f64) sp30;
            M2C_FIELD(temp_r4_3466, f64 *, 8) = (f64) sp30;
            ((KDUniformSpline *) (M2C_BITWISE(s32, temp_r31_3217) + 0x7C))->Smooth();
            ((KDUniformSpline *) (M2C_BITWISE(s32, temp_r31_3217) + 0x7C))->Smooth();
            var_r24_3318 = 1;
            var_r23_3477 = 0;
            do {
                spC = 0.0f;
                spB8.GetMeasure(0.1f * (f32) var_r23_3477, temp_r30_3306, KDSpline_PositionMixer);
                sp198 = spB8;
                sp1A0 = spC0;
                sp8 = 0.0f;
                spA8.GetMeasure(0.1f * (f32) (var_r23_3477 + 1), temp_r30_3306, KDSpline_PositionMixer);
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
        sp88 = M2C_FIELD(temp_r3_3533, f64 *, 0x30);
        sp90 = M2C_FIELD(temp_r3_3533, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_r3_3547 = this->unk110.unkA00;
        sp98 = sp18;
        sp20 = (f32) sp90 + M2C_FIELD(arg3, f32 *, 8);
        temp_r3_3547->unk60 = sp18;
        temp_r3_3547->unk68 = (f64) sp20;
        spA0 = (f64) sp20;
        M2C_FIELD(temp_r3_3547, s8 *, 0xF5) = 1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkEC8'
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
    this->unkEC8 = 0;
    this->unkEC9 = 0;
    this->unkECA = 0;
    this->unkECC = 0.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkEBC'
void IceBoss::InitShield() {
    s8 *var_r4_3636;

    this->unkEBC = (u32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, "shield");
    this->unkEC0 = (u32) Tools_GetMatchingSubObjectIndex((SubObjectType) 1, this->unk4, "shield");
    this->unkEC4 = 5;
    this->unkEC8 = 0;
    this->unkEC9 = 0;
    this->unkECC = 0.0f;
    var_r4_3636 = "ElecKingArmour_Shield";
    if (IsIceKing() != 0) {
        var_r4_3636 = "IceBossArmour_Shield";
    }
    this->unkED0 = checked_cast<Shatterable *, MKProp>(gMK->CreateProp(var_r4_3636));
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
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

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'SubObjectType'
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
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'SubObjectType'
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

#if 0 // DRAFT: undefined identifier 'unkA00'
void IceBoss::Resolve() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKSceneManager *temp_ret_3875;
    ManagedLight *temp_r4_3915;
    Shatterable *temp_r3_3891;
    Shatterable *temp_ret_3879;
    Shatterable *temp_ret_3883;
    Shatterable *temp_ret_3887;

    Enemy::Resolve();
    temp_ret_3875 = checked_cast<EventCamera *, MKProp>(this->unk110.unkA00->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    this->unk110.unkA00 = temp_ret_3875;
    temp_ret_3879 = checked_cast<Shatterable *, MKProp>(this->unkF98->PropResolver_Resolve((s32) (u32) (u64) temp_ret_3875));
    this->unkF98 = temp_ret_3879;
    temp_ret_3883 = checked_cast<Shatterable *, MKProp>(this->unkF9C->PropResolver_Resolve((s32) (u32) (u64) temp_ret_3879));
    this->unkF9C = temp_ret_3883;
    temp_ret_3887 = checked_cast<Shatterable *, MKProp>(this->unkFA0->PropResolver_Resolve((s32) (u32) (u64) temp_ret_3883));
    this->unkFA0 = temp_ret_3887;
    temp_r3_3891 = checked_cast<Shatterable *, MKProp>(this->unkFA4->PropResolver_Resolve((s32) (u32) (u64) temp_ret_3887));
    sp8 = 0.5f;
    spC = 0.5f;
    this->unkFA4 = (MKSceneManager *) temp_r3_3891;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unkFFC = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(zero, zero, *((MKVector4 *) &sp18), 1000.0f, lit_248, lit_249);
    temp_r4_3915 = this->unkFFC;
    if (temp_r4_3915 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_3915, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk930'
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
    MKCollisionInfo *temp_r4_4269;
    MKHeap *temp_r3_4253;
    MKProp *temp_r3_4244;
    MKProp *temp_r3_4335;
    MKProp *temp_r3_4342;
    s32 temp_r0_4312;
    s8 *var_r3_4260;
    s8 *var_r4_4237;
    void *temp_r30_4277;

    Enemy::LoadDone();
    this->unk110.unk930 = this->unk110.unk92C;
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
    InitBodyPart((IceBossBodyPart *) &this->unk110.unkA14, 0, "Main", 0, 0xF, (SubObjectType) 0, 0U);
    InitBodyPart(0x16, "Energy", 0, 0xF, (SubObjectType) 0, 0U);
    InitBodyPart(0x17, "Glow", 0, 0xF, (SubObjectType) 0, 0U);
    InitWeapon(0, "Sword", 0, 5);
    InitWeapon(1, "Axe", 5, 0xB);
    InitWeapon(2, "Sword", 0xB, 0xF);
    InitShield();
    SetAnim((AnimSequenceType) 1, 0, 0, 0.15f, 0U, 0U);
    this->unk110.unkA0C = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "breath");
    var_r4_4237 = "ElecKingSword";
    if (IsIceKing() != 0) {
        var_r4_4237 = "IceBossSword";
    }
    this->unkF94 = gMK->CreateProp(var_r4_4237);
    temp_r3_4244 = this->unkF94;
    temp_r3_4244->Disable();
    UpdateWeaponCollisionCapsule();
    this->unkF90 = NULL;
    temp_r3_4253 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4253 != NULL) {
        var_r3_4260 = ((MKHeap *) (temp_r3_4253->Current()))->Alloc(0x10, NULL, 0);
    } else {
        var_r3_4260 = malloc(0x10);
    }
    this->unkF90 = (MKCollisionInfo *) var_r3_4260;
    temp_r4_4269 = this->unkF90;
    temp_r4_4269->unk0 = 0;
    temp_r4_4269->unk4 = 1;
    temp_r4_4269->unk8 = (MKProp *) this;
    temp_r4_4269->unkC = 0;
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
    ((MKCollisionManager *) (gMK->GetCollisionManager((f64) sp18, (f64) sp10, (f64) sp8, 1.0f)))->AddCapsule((MKVector3 *) &this->unkEE0.unk80, (MKVector3 *) &this->unkF70, 80.0f, *((MKVector4 *) &sp38), *((MKVector4 *) &sp28), (MKCollisionMode) 2, this->unkF90, M2C_FIELD(temp_r30_4277, u32 *, 0x70));
    temp_r0_4312 = this->unk110.unk928->unk1D0;
    switch (temp_r0_4312) {                         /* irregular */
    case 2:
        this->unkFDC = gMK->CreateProp("IceBossStomp");
        break;
    case 1:
        this->unkFDC = gMK->CreateProp("ElecBossStomp");
        break;
    }
    temp_r3_4335 = this->unkFDC;
    if (temp_r3_4335 != NULL) {
        M2C_FIELD(temp_r3_4335->__vptr, M2C_UNK (**)(), 0x34)();
        temp_r3_4342 = this->unkFDC;
        M2C_FIELD(temp_r3_4342->__vptr, M2C_UNK (**)(MKProp *), 0x44)(temp_r3_4342);
    }
    this->unkFE0->LoadDone();
    if (!(this->unk110.unk570 & 0x160000)) {
        Disable();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkFE4'
s32 IceBoss::LoadLine(MKIniLine *arg0) {
    s32 var_r31_4375;

    var_r31_4375 = 0;
    if ((Enemy::LoadLine(arg0) != 0) || (this->unkFE4.LoadLine(arg0, "OnPhase1End") != 0) || (this->unkFE8.LoadLine(arg0, "OnPhase2End") != 0) || (this->unkFEC.LoadLine(arg0, "OnPhase3End") != 0) || (arg0->LoadInt("PhaseCameraID", (s32 *) &this->unk110.unkA00, 0) != 0) || (arg0->LoadInt("Stalactite1ID", (s32 *) &this->unkF98, 0) != 0) || (arg0->LoadInt("Stalactite2ID", (s32 *) &this->unkF9C, 0) != 0) || (arg0->LoadInt("Stalactite3ID", (s32 *) &this->unkFA0, 0) != 0) || (arg0->LoadInt("Stalactite4ID", (s32 *) &this->unkFA4, 0) != 0)) {
        var_r31_4375 = 1;
    }
    return var_r31_4375;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1014'
void IceBoss::Deinit() {
    IceBossStalactiteSpawner *temp_r29_4496;
    MKCollisionInfo *temp_r27_4542;
    MKCollisionInfo *temp_r28_4515;
    MKCollisionInfo *temp_r29_4476;
    MKHeap *temp_r3_4479;
    MKHeap *temp_r3_4497;
    MKHeap *temp_r3_4518;
    MKHeap *temp_r3_4545;
    ManagedLight *temp_r4_4564;
    s32 temp_r27_4514;
    s32 temp_r28_4541;
    s32 var_r26_4511;
    s32 var_r26_4537;
    s32 var_r30_4510;
    s32 var_r30_4538;

    Enemy::Deinit();
    KDSound_Stop(&this->unk1014);
    KDSound_Stop(&this->unk103C);
    KDSound_Stop(&this->unk1010);
    PhrasePlayer_StopEvent(this->unk1000);
    temp_r29_4476 = this->unkF90;
    if (temp_r29_4476 != NULL) {
        temp_r3_4479 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_4479 != NULL) {
            ((MKHeap *) (temp_r3_4479->Current()))->Free(temp_r29_4476, NULL, 0);
        } else {
            free(temp_r29_4476);
        }
    }
    this->unkF90 = NULL;
    this->unkFE0->Deinit();
    temp_r29_4496 = this->unkFE0;
    temp_r3_4497 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4497 != NULL) {
        ((MKHeap *) (temp_r3_4497->Current()))->Free(temp_r29_4496, NULL, 0);
    } else {
        free((MKCollisionInfo *) temp_r29_4496);
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
    temp_r4_4564 = this->unkFFC;
    if (temp_r4_4564 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_4564, 0U);
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(this->unkFFC);
        this->unkFFC = NULL;
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
    this->unk110.unk92C = temp_r30_4598;
    this->unkFDC = NULL;
    temp_r3_4626 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4626 != NULL) {
        var_r3_4633 = ((MKHeap *) (temp_r3_4626->Current()))->Alloc(0x28, NULL, 0);
    } else {
        var_r3_4633 = malloc(0x28);
    }
    this->unkFE0 = (IceBossStalactiteSpawner *) var_r3_4633;
    this->unkFE0->Init((MKProp *) this, 0xA, this->unk110.unk928->unk1D0);
    this->unk1000 = 0;
    this->unk1010 = 0;
    this->unk1004 = NULL;
    this->unk1008 = 0.0f;
    this->unk100C = 0.0f;
    this->unk1014.Init(0.75f, 0.75f);
    this->unk103C.Init(0.75f, 0.75f);
    this->unk1068 = checked_cast<IceBitsPS *, MKProp>(gMK->CreateProp("IceBitsPS"));
    this->unkFE4.Init();
    this->unkFE8.Init();
    this->unkFEC.Init();
    this->unk110.unkA00 = NULL;
    this->unkFBD = 0;
    this->unk1064 = 0;
    this->unkFF4 = checked_cast<EarthShockwave *, MKProp>(gMK->CreateProp("EarthShockwave"));
    this->unkFF8 = checked_cast<ElementalShield *, MKProp>(gMK->CreateProp("ElementalShield"));
    M2C_FIELD(this, f32 *, 0xF80) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF84) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF88) = 0.0f;
    this->unkFF8->SetElement(this->unk110.unk928->unk1D0);
    this->unkFFC = NULL;
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

#if 0 // DRAFT: undefined identifier 'lit_1720lit_GetAimPoint'
void IceBoss::lit_1720lit_GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((IceBoss *) (this - 0x6B8))->IceBoss::GetAimPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_1720lit_GetLookToPoint'
void IceBoss::lit_1720lit_GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((IceBoss *) (this - 0x6B8))->IceBoss::GetLookToPoint(arg0, arg1);
}
#endif
