#include "spyro/source/Cynder.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/CynderBossGoals.h"
#include "spyro/source/CynderBreathFX.h"
#include "spyro/source/CynderConcurrentGoals.h"
#include "spyro/source/EarthShockwave.h"
#include "spyro/source/ElectricSparks.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireBombFX.h"
#include "spyro/source/FuryFXFire.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/ScreenWobbleFX.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/SuckeyPS.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/PhrasePlayer.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

f64 acos(f32);                                      /* extern */
s32 atoi(s8 *);                                     /* extern */
f64 fmod(f32, f64, f64, f32);                       /* extern */
M2C_UNK free(u16 *);                                /* extern */
u16 *malloc(s32);                                   /* extern */
extern s32 GS_CynderExtra1;
extern s32 GS_CynderFlinch1;
extern s32 GS_CynderFuryBuildUp;
extern s32 GS_CynderFuryPurpleLP;
extern s32 GS_CynderMelee2;
extern s32 GS_CynderTaunt;
extern s32 GS_SWCynderFireball1;
extern f32 *KDSpline_PositionMixer;
extern f32 *KDSpline_VelocityMixer;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;
extern void *gpTranslation_StringArray;

static s32 lit_897 = 0;
static u8 lit_898 = 0;

#if 0 // DRAFT: illegal explicit conversion from 'float' to
static M2C_UNK lit_780;                                /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_781;                                /* unable to generate initializer: unknown type; const */

void Cynder::ResetFury() {
    f32 temp_r4_161;
    s32 temp_r3_179;

    this->unkD94 = 0;
    this->unkF74 = 0.0f;
    this->unkF70 = 0.0f;
    M2C_FIELD(this, s8 *, 0xF1F) = 0;
    M2C_FIELD(this, s8 *, 0xF1E) = 0;
    temp_r4_161 = this->unkF14;
    if (M2C_BITWISE(u32, temp_r4_161) != 0U) {
        M2C_FIELD(temp_r4_161, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_161, u8 *, 0x31) & ~0x40);
    }
    ((FuryFXFire *) (M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0x3C)(gb), void **, 4), void **, 0x14), FuryFXFire **, 0x260)))->ResetFury();
    temp_r3_179 = this->unkF10.unk0;
    M2C_FIELD(M2C_FIELD(temp_r3_179, void **, 0x44), M2C_UNK (**)(s32), 0x34)(temp_r3_179);
}
#endif

void Cynder::TriggerFury() {
    f64 sp10;
    f64 sp8;
    f64 temp_f1_203;
    void *temp_r4_200;

    temp_r4_200 = this->unk8;
    temp_f1_203 = M2C_FIELD(temp_r4_200, f64 *, 0x30);
    sp8 = temp_f1_203;
    sp10 = M2C_FIELD(temp_r4_200, f64 *, 0x38);
    ((FuryFXFire *) (M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, void *, f64), 0x3C)(gb, temp_r4_200, temp_f1_203), void **, 4), void **, 0x14), FuryFXFire **, 0x260)))->Trigger(*((MKVector3 *) &sp8), 0U, 1U, (HeroHurtReactionType) this->unkF0C.unk0);
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void Cynder::UpdateFuryPowerUp() {
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    M2C_UNK spD0;
    f64 spC8;
    f64 spC0;
    M2C_UNK spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f28_354;
    f32 temp_f29_355;
    f32 temp_r3_412;
    f32 temp_r3_419;
    f32 temp_r4_266;
    f32 var_f0_278;
    s32 temp_r3_259;
    s32 var_r30_348;

    if ((u8) M2C_FIELD(this, u8 *, 0xF1F) == 0) {
        this->unkD94 = 0;
        return;
    }
    this->unkD94 = 1;
    if (((u8) M2C_FIELD(this, u8 *, 0xF1F) != 0) && ((u8) M2C_FIELD(&gb, u8 *, 0xD0) != 0)) {
        temp_r3_259 = this->unkF10.unk0;
        M2C_FIELD(M2C_FIELD(temp_r3_259, void **, 0x44), M2C_UNK (**)(s32), 0x34)(temp_r3_259);
        M2C_FIELD(this, u8 *, 0xF1F) = 0U;
        temp_r4_266 = this->unkF14;
        if (M2C_BITWISE(u32, temp_r4_266) != 0U) {
            M2C_FIELD(temp_r4_266, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_266, u8 *, 0x31) & ~0x40);
        }
    } else {
        this->unkF70 -= gUpdateTimeDelta;
        var_f0_278 = this->unkF70;
        if (var_f0_278 > 0.0f) {

        } else {
            var_f0_278 = 0.0f;
        }
        this->unkF70 = var_f0_278;
        if ((s32) this->unkF0C.unk0 == 8) {
            MKVector(0.0f, 300.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            spE0 = sp20;
            sp28 = this->unk588.unk4 + spD8;
            this->unkF60 = (f32) spE0;
            spE8 = (f64) sp28;
            this->unkF64 = unkspE4;
            this->unkF68 = (f32) spE8;
            this->unkF6C = 1.0f;
        } else {
            MKVector(0.0f, 300.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            spC0 = sp10;
            sp18 = this->unk588.unk4 + spB8;
            this->unkF60 = (f32) spC0;
            spC8 = (f64) sp18;
            this->unkF64 = unkspC4;
            this->unkF68 = (f32) spC8;
            this->unkF6C = 1.0f;
        }
        var_r30_348 = 0;
        temp_f28_354 = 1.0f - (this->unkF70 / this->unkF74);
        temp_f29_355 = (750.0f * temp_f28_354) + 900.0f;
        do {
            sp68 = -1.0f;
            sp58 = 1.0f;
            sp60 = -1.0f;
            sp64 = -1.0f;
            sp50 = 1.0f;
            sp54 = 1.0f;
            sp90 = (f64) sp60;
            sp98 = (f64) sp68;
            sp80 = (f64) sp50;
            sp88 = (f64) sp58;
            KDRand_Vector(spA0, *((MKVector3 *) &sp90));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            spF0 = sp40;
            sp48 = spA0.unk8 * temp_f29_355;
            spF8 = (f64) sp48;
            sp8 = MKRand_Float(&gViewSeed, 10.0f, 15.0f);
            sp30 = -(f32) spF0;
            sp34 = -unkspF4;
            sp38 = -(f32) spF8;
            sp70 = (f64) sp30;
            sp78 = (f64) sp38;
            this->unkF10.unk0->Emit(*((MKVector3 *) &spF0), *((MKVector3 *) &sp70), sp8, 2.0f);
            var_r30_348 += 1;
        } while (var_r30_348 < 5);
        temp_r3_412 = this->unkF14;
        if (M2C_BITWISE(u32, temp_r3_412) != 0U) {
            M2C_FIELD(temp_r3_412, f32 *, 0x24) = (f32) ((15.0f * temp_f28_354) + 1.0f);
            temp_r3_419 = this->unkF14;
            M2C_FIELD(temp_r3_419, f64 *, 0) = (f64) M2C_FIELD(this, f32 *, 0xF60);
            M2C_FIELD(temp_r3_419, f64 *, 8) = (f64) M2C_FIELD(this, f32 *, 0xF68);
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void Cynder::TriggerFuryPowerUp(float arg0, HeroHurtReactionType arg1) {
    f32 temp_r3_490;
    f32 temp_r3_500;
    f32 temp_r3_505;
    s32 temp_r3_470;
    s32 temp_r3_475;
    void *temp_r3_458;

    this->unkF74 = arg0;
    this->unkF70 = arg0;
    M2C_FIELD(this, s8 *, 0xF1F) = 1;
    this->unkF0C.unk0 = (s32) arg1;
    temp_r3_458 = this->unk8;
    this->unkF60 = M2C_FIELD(temp_r3_458, f32 *, 0x30);
    this->unkF64 = M2C_FIELD(temp_r3_458, f32 *, 0x34);
    this->unkF68 = M2C_FIELD(temp_r3_458, f32 *, 0x38);
    this->unkF6C = 1.0f;
    KDSound_Play3d(GS_CynderFuryBuildUp, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    temp_r3_470 = this->unkF10.unk0;
    M2C_FIELD(M2C_FIELD(temp_r3_470, void **, 0x44), M2C_UNK (**)(s32), 0x20)(temp_r3_470);
    temp_r3_475 = this->unkF10.unk0;
    M2C_FIELD(M2C_FIELD(temp_r3_475, void **, 0x44), M2C_UNK (**)(s32), 0x30)(temp_r3_475);
    if ((s32) this->unkF0C.unk0 == 8) {
        gb.GetSpyro();
        ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->UseCynderStrafeState(1U, 0U);
    }
    temp_r3_490 = this->unkF14;
    if (M2C_BITWISE(u32, temp_r3_490) != 0U) {
        M2C_FIELD(temp_r3_490, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r3_490, u8 *, 0x31) | 0x40);
        M2C_FIELD(this->unkF14, f32 *, 0x24) = 1.0f;
        temp_r3_500 = this->unkF14;
        M2C_FIELD(temp_r3_500, f64 *, 0) = (f64) M2C_FIELD(this, f32 *, 0xF60);
        M2C_FIELD(temp_r3_500, f64 *, 8) = (f64) M2C_FIELD(this, f32 *, 0xF68);
        temp_r3_505 = this->unkF14;
        M2C_FIELD(temp_r3_505, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r3_505, u8 *, 0x31) | 0x10);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void Cynder::CalcLandingFlightPathData() {
    f32 temp_f3_848;
    f32 temp_f6_854;
    f32 temp_f7_860;
    f32 var_f27_574;
    f32 var_f28_602;
    f32 var_f29_580;
    f32 var_f30_541;
    f32 var_f30_615;
    u8 var_r31_547;
    void *temp_r3_847;
    void *temp_r5_559;
    void *temp_r6_583;
    if (((u8) M2C_FIELD(this, u8 *, 0xB08) >> 7U) & 1) {
        var_f30_541 = -1.0f;
    } else {
        var_f30_541 = 1.0f;
    }
    var_r31_547 = 0;
    if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk30.Get() != NULL)) {
        var_r31_547 = 1;
    }
    if (var_r31_547 != 0) {
        temp_r5_559 = this->unk8;
        arg_sp1D0 = M2C_FIELD(temp_r5_559, f64 *, 0x30);
        arg_sp1D8 = M2C_FIELD(temp_r5_559, f64 *, 0x38);
        this->unk838.unk28.Update(*((MKVector3 *) &arg_sp1D0));
        arg_sp1C0.GetPos();
        Tools_GetClosestSplineTimeXZ(&this->unkCC0, *((MKVector3 *) &arg_sp1C0), 0x14);
        var_f27_574 = M2C_ERROR(/* Read from unset register $f1 */);
        var_f29_580 = (f32) fmod(0.5f + var_f27_574, 1.0);
    } else {
        temp_r6_583 = this->unk8;
        arg_sp1B0 = M2C_FIELD(temp_r6_583, f64 *, 0x30);
        arg_sp1B8 = M2C_FIELD(temp_r6_583, f64 *, 0x38);
        Tools_GetClosestSplineTimeXZ(&this->unkCC0, *((MKVector3 *) &arg_sp1B0), 0x14);
        var_f29_580 = M2C_ERROR(/* Read from unset register $f1 */);
        var_f27_574 = (f32) fmod(0.5f + var_f29_580, 1.0);
    }
    var_f28_602 = (0.2f * var_f30_541) + var_f29_580;
    if (var_f28_602 > 1.0f) {
        var_f28_602 -= 1.0f;
    } else if (var_f28_602 < 0.0f) {
        var_f28_602 += 1.0f;
    }
    var_f30_615 = -((0.05f * var_f30_541) - var_f27_574);
    if (var_f30_615 > 1.0f) {
        var_f30_615 -= 1.0f;
    } else if (var_f30_615 < 0.0f) {
        var_f30_615 += 1.0f;
    }
    arg_sp18 = 0.0f;
    arg_sp1A0.GetMeasure(var_f29_580, (Matrix *) &this->unkCC0, KDSpline_PositionMixer);
    arg_sp200 = arg_sp1A0;
    arg_sp208 = arg_sp1A8;
    arg_sp14 = 0.0f;
    arg_sp190.GetMeasure(var_f28_602, (Matrix *) &this->unkCC0, KDSpline_PositionMixer);
    arg_sp1F0 = arg_sp190;
    arg_sp1F8 = arg_sp198;
    arg_sp10 = 0.0f;
    arg_sp180.GetMeasure(var_f30_615, (Matrix *) &this->unkCC0, KDSpline_PositionMixer);
    arg_sp1E0 = arg_sp180;
    arg_sp1E8 = arg_sp188;
    arg_sp160.GetVelocity(var_f28_602);
    Normalise(*((MKVector3 *) &arg_sp170));
    arg_sp210 = arg_sp170;
    arg_sp218 = arg_sp178;
    arg_sp30 = (MKVector3::up.unk4 * (f32) arg_sp218) - (MKVector3::up.unk8 * arg_sp214);
    arg_sp34 = (MKVector3::up.unk8 * (f32) arg_sp210) - (MKVector3::up.unk0 * (f32) arg_sp218);
    arg_sp38 = (MKVector3::up.unk0 * arg_sp214) - (MKVector3::up.unk4 * (f32) arg_sp210);
    arg_sp140 = (f64) arg_sp30;
    arg_sp148 = (f64) arg_sp38;
    arg_sp90 = -(f32) arg_sp140;
    arg_sp94 = -arg_sp144;
    arg_sp98 = -(f32) arg_sp148;
    arg_sp210 = (f64) arg_sp90;
    arg_sp150 = (f64) arg_sp90;
    arg_sp158 = (f64) arg_sp98;
    arg_sp218 = (f64) arg_sp98;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_sp130 = arg_sp80;
    arg_sp88 = (f32) arg_sp218 * 3000.0f;
    arg_sp138 = (f64) arg_sp88;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spB8 = 0.0f;
    arg_spB0 = 0.0f;
    arg_spB4 = 1500.0f;
    arg_sp1F8 = (f32) arg_sp1F8 + (f32) arg_sp138;
    arg_sp110 = (f64) arg_spB0;
    arg_sp118 = (f64) arg_spB8;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp120 = arg_spA0;
    arg_spA8 = (f32) arg_sp1E8 - (f32) arg_sp118;
    arg_sp128 = (f64) arg_spA8;
    if (MKCollision_RayCollide(*((MKVector3 *) &arg_sp1E0), *((MKVector3 *) &arg_sp120), (MKCollisionResult *) &arg_sp270, (MKCollisionMode) 4, 0) != 0) {
        arg_sp1E0 = arg_sp270;
        arg_sp1E8 = arg_sp278;
    }
    arg_sp78 = -(f32) arg_sp218;
    arg_sp70 = -(f32) arg_sp210;
    arg_sp74 = -arg_sp214;
    arg_sp108 = (f64) arg_sp78;
    arg_sp100 = (f64) arg_sp70;
    arg_sp220 = (f64) arg_sp70;
    arg_sp228 = (f64) arg_sp78;
    arg_sp230.SetIdentity();
    arg_sp68 = -(f32) arg_sp228;
    arg_sp24 = (MKVector3::up.unk8 * (f32) arg_sp220) - (MKVector3::up.unk0 * (f32) arg_sp228);
    arg_sp20 = (MKVector3::up.unk4 * (f32) arg_sp228) - (MKVector3::up.unk8 * arg_sp224);
    arg_sp28 = (MKVector3::up.unk0 * arg_sp224) - (MKVector3::up.unk4 * (f32) arg_sp220);
    arg_spD0 = (f64) arg_sp20;
    arg_spD8 = (f64) arg_sp28;
    arg_spF8 = (f64) arg_sp68;
    arg_sp60 = -(f32) arg_sp220;
    arg_sp64 = -arg_sp224;
    arg_sp58 = -(f32) arg_spD8;
    arg_spF0 = (f64) arg_sp60;
    arg_spE8 = (f64) arg_sp58;
    arg_sp50 = -(f32) arg_spD0;
    arg_sp54 = -arg_spD4;
    arg_sp250 = (f32) arg_spF0;
    arg_spE0 = (f64) arg_sp50;
    arg_sp254 = arg_spF4;
    arg_sp258 = (f32) arg_spF8;
    arg_sp25C = 0.0f;
    arg_sp240 = MKVector3::up.unk0;
    arg_sp244 = MKVector3::up.unk4;
    arg_sp248 = MKVector3::up.unk8;
    arg_sp24C = 0.0f;
    arg_sp230 = (f32) arg_spE0;
    arg_sp234 = arg_spE4;
    arg_sp238 = (f32) arg_spE8;
    arg_sp23C = 0.0f;
    temp_r3_847 = this->unkA20->GetAnimSequence(0xA, 0xDD, 0, NULL);
    temp_f3_848 = M2C_FIELD(temp_r3_847, f32 *, 0xC);
    temp_f6_854 = M2C_FIELD(temp_r3_847, f32 *, 8);
    temp_f7_860 = M2C_FIELD(temp_r3_847, f32 *, 0x10);
    arg_sp40 = (temp_f7_860 * arg_sp250) + ((temp_f6_854 * arg_sp230) + (temp_f3_848 * arg_sp240));
    arg_sp44 = (temp_f7_860 * arg_sp254) + ((temp_f6_854 * arg_sp234) + (temp_f3_848 * arg_sp244));
    arg_sp48 = (temp_f7_860 * arg_sp258) + ((temp_f6_854 * arg_sp238) + (temp_f3_848 * arg_sp248));
    arg_spC0 = (f64) arg_sp40;
    arg_spC8 = (f64) arg_sp48;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp1E8 = (f32) arg_sp1E8 - (f32) arg_spC8;
    this->unkFF8 = var_f29_580;
    this->unkCC4 = 0.0f;
    this->unkCC0 = 0;
    this->unkCD4.AddNode(*((MKVector3 *) &arg_sp200));
    this->unkCD4.AddNode(*((MKVector3 *) &arg_sp1F0));
    this->unkCD4.AddNode(*((MKVector3 *) &arg_sp1E0));
}
#endif

#if 0 // DRAFT: function call 'Tools_GetClosestSplineTimeXZ(long *, MKVector3, int)' does
void Cynder::CalcFlightPathData2() {
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;                                      /* compiler-managed */
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;                                      /* compiler-managed */
    f64 sp238;
    f64 sp230;                                      /* compiler-managed */
    f64 sp228;
    f64 sp220;                                      /* compiler-managed */
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp1F8;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    MKVector3 sp1A8;
    f64 sp1A0;
    f64 sp198;
    MKVector3 sp188;
    f64 sp180;
    f64 sp178;
    MKVector3 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    KDUniformSpline sp118;
    f64 sp110;
    f64 sp108;
    f32 sp100;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spC0;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f24_949;
    f32 temp_f25_955;
    f32 temp_f28_1296;
    f32 var_f3_1215;
    f32 var_f4_1148;
    f32 var_f5_1081;
    f32 var_f6_1014;
    f32 var_f8_1309;
    f32 var_f9_1331;
    f64 temp_f1_1154;
    f64 temp_f1_1160;
    f64 temp_f1_1164;
    f64 temp_f3_1020;
    f64 temp_f3_1026;
    f64 temp_f3_1030;
    f64 temp_f3_1339;
    f64 temp_f3_1345;
    f64 temp_f3_1349;
    s32 temp_r3_1049;
    s32 temp_r3_1183;
    s32 temp_r3_1368;
    s32 var_r0_1059;
    s32 var_r0_1193;
    s32 var_r0_1378;
    void *temp_r6_941;

    temp_r6_941 = this->unk8;
    sp208 = M2C_FIELD(temp_r6_941, f64 *, 0x30);
    sp210 = M2C_FIELD(temp_r6_941, f64 *, 0x38);
    Tools_GetClosestSplineTimeXZ(&this->unkCC0, *((MKVector3 *) &sp208), 0x14);
    temp_f24_949 = M2C_ERROR(/* Read from unset register $f1 */);
    temp_f25_955 = (f32) fmod(0.5f + temp_f24_949, 1.0);
    sp20 = 0.0f;
    sp1F8.GetMeasure(temp_f24_949, (Matrix *) &this->unkCC0, KDSpline_PositionMixer);
    sp298 = sp1F8;
    sp2A0 = sp200;
    sp1C = 0.0f;
    sp1E8.GetMeasure(temp_f25_955, (Matrix *) &this->unkCC0, KDSpline_PositionMixer);
    sp288 = sp1E8;
    sp290 = sp1F0;
    sp248 = M2C_FIELD(this, f64 *, 0xC0);
    sp250 = M2C_FIELD(this, f64 *, 0xC8);
    sp18 = 0.0f;
    sp118.GetMeasure(temp_f24_949, (Matrix *) &this->unkCC0, KDSpline_VelocityMixer);
    sp108 = M2C_BITWISE(f64, sp118);
    sp110 = (f64) sp118.unk8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp1D8 = spF8;
    sp100 = (f32) sp110 * sp18;
    sp1E0 = (f64) sp100;
    var_f6_1014 = ((f32) sp1E0 * (f32) sp1E0) + (((f32) sp1D8 * (f32) sp1D8) + (unksp1DC * unksp1DC));
    if (var_f6_1014 > 1e-12f) {
        if (var_f6_1014 > 0.0f) {
            temp_f3_1020 = __frsqrte(var_f6_1014);
            temp_f3_1026 = 0.5 * temp_f3_1020 * -(((f64) var_f6_1014 * (temp_f3_1020 * temp_f3_1020)) - 3.0);
            temp_f3_1030 = 0.5 * temp_f3_1026 * -(((f64) var_f6_1014 * (temp_f3_1026 * temp_f3_1026)) - 3.0);
            var_f6_1014 = (f32) ((f64) var_f6_1014 * (0.5 * temp_f3_1030 * -(((f64) var_f6_1014 * (temp_f3_1030 * temp_f3_1030)) - 3.0)));
        } else if (var_f6_1014 < M2C_BITWISE(f32, 0.0)) {
            var_f6_1014 = __float_nan;
        } else {
            sp10 = var_f6_1014;
            temp_r3_1049 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_1049) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1059 = 1;
                } else {
                    var_r0_1059 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1059 = 5;
                } else {
                    var_r0_1059 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1059 = 4;
                break;
            }
            if (var_r0_1059 == 1) {
                var_f6_1014 = __float_nan;
            }
        }
        var_f5_1081 = 1.0f / var_f6_1014;
    } else {
        var_f5_1081 = 0.0f;
    }
    spEC = unksp1DC * var_f5_1081;
    spE8 = (f32) sp1D8 * var_f5_1081;
    spF0 = (f32) sp1E0 * var_f5_1081;
    sp238 = (f64) spE8;
    sp240 = (f64) spF0;
    if ((((f32) sp250 * (f32) sp240) + (((f32) sp248 * (f32) sp238) + (unksp24C * unksp23C))) < 0.0f) {
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp240 = (f32) sp240 * -1.0f;
    }
    sp14 = 0.0f;
    spD8.GetMeasure(temp_f25_955, (Matrix *) &this->unkCC0, KDSpline_VelocityMixer);
    spC8 = spD8;
    spD0 = spE0;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    sp1C8 = spB8;
    spC0 = (f32) spD0 * sp14;
    sp1D0 = (f64) spC0;
    var_f4_1148 = ((f32) sp1D0 * (f32) sp1D0) + (((f32) sp1C8 * (f32) sp1C8) + (unksp1CC * unksp1CC));
    if (var_f4_1148 > 1e-12f) {
        if (var_f4_1148 > 0.0f) {
            temp_f1_1154 = __frsqrte(var_f4_1148);
            temp_f1_1160 = 0.5 * temp_f1_1154 * -(((f64) var_f4_1148 * (temp_f1_1154 * temp_f1_1154)) - 3.0);
            temp_f1_1164 = 0.5 * temp_f1_1160 * -(((f64) var_f4_1148 * (temp_f1_1160 * temp_f1_1160)) - 3.0);
            var_f4_1148 = (f32) ((f64) var_f4_1148 * (0.5 * temp_f1_1164 * -(((f64) var_f4_1148 * (temp_f1_1164 * temp_f1_1164)) - 3.0)));
        } else if (var_f4_1148 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1148 = __float_nan;
        } else {
            spC = var_f4_1148;
            temp_r3_1183 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_1183) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1193 = 1;
                } else {
                    var_r0_1193 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1193 = 5;
                } else {
                    var_r0_1193 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_1193 = 4;
                break;
            }
            if (var_r0_1193 == 1) {
                var_f4_1148 = __float_nan;
            }
        }
        var_f3_1215 = 1.0f / var_f4_1148;
    } else {
        var_f3_1215 = 0.0f;
    }
    spAC = unksp1CC * var_f3_1215;
    spA8 = (f32) sp1C8 * var_f3_1215;
    spB0 = (f32) sp1D0 * var_f3_1215;
    sp228 = (f64) spA8;
    sp230 = (f64) spB0;
    if (((sp240 * (f32) sp230) + (((f32) sp238 * (f32) sp228) + (unksp23C * unksp22C))) < 0.0f) {
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        sp230 = (f32) sp230 * -1.0f;
    }
    sp1A8.operator*(4000.0f);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp1B8 = sp78;
    sp80 = (f32) sp2A0 + sp1A8.unk8;
    sp278 = sp78;
    sp1C0 = (f64) sp80;
    sp280 = (f64) sp80;
    sp188.operator*(4000.0f);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp258 = sp68;
    sp70 = (f32) sp290 + sp188.unk8;
    sp198 = sp68;
    sp1A0 = (f64) sp70;
    sp260 = (f64) sp70;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    temp_f28_1296 = (f32) sp260 - (f32) sp280;
    sp158 = sp28;
    sp30 = temp_f28_1296;
    sp160 = (f64) sp30;
    sp168.operator*(0.5f);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    var_f8_1309 = 0.0f;
    sp9C = 0.0f;
    sp98 = (f32) sp258 - (f32) sp278;
    spA0 = temp_f28_1296;
    sp148 = (f64) sp98;
    sp150 = (f64) spA0;
    sp60 = (f32) sp280 + sp168.unk8;
    sp178 = sp58;
    var_f9_1331 = ((f32) sp150 * (f32) sp150) + (((f32) sp148 * (f32) sp148) + (unksp14C * unksp14C));
    sp180 = (f64) sp60;
    sp268 = sp58;
    sp270 = (f64) sp60;
    if (var_f9_1331 > 1e-12f) {
        if (var_f9_1331 > 0.0f) {
            temp_f3_1339 = __frsqrte(var_f9_1331);
            temp_f3_1345 = 0.5 * temp_f3_1339 * -(((f64) var_f9_1331 * (temp_f3_1339 * temp_f3_1339)) - 3.0);
            temp_f3_1349 = 0.5 * temp_f3_1345 * -(((f64) var_f9_1331 * (temp_f3_1345 * temp_f3_1345)) - 3.0);
            var_f9_1331 = (f32) ((f64) var_f9_1331 * (0.5 * temp_f3_1349 * -(((f64) var_f9_1331 * (temp_f3_1349 * temp_f3_1349)) - 3.0)));
        } else if (var_f9_1331 < M2C_BITWISE(f32, 0.0)) {
            var_f9_1331 = __float_nan;
        } else {
            sp8 = var_f9_1331;
            temp_r3_1368 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1368) {                 /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1378 = 1;
                } else {
                    var_r0_1378 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1378 = 5;
                } else {
                    var_r0_1378 = 3;
                }
                break;
            default:                                /* switch 3 */
                var_r0_1378 = 4;
                break;
            }
            if (var_r0_1378 == 1) {
                var_f9_1331 = __float_nan;
            }
        }
        var_f8_1309 = 1.0f / var_f9_1331;
    }
    sp8C = unksp14C * var_f8_1309;
    sp88 = (f32) sp148 * var_f8_1309;
    sp90 = (f32) sp150 * var_f8_1309;
    sp218 = (f64) sp88;
    sp220 = (f64) sp90;
    sp48 = (MKVector3::up.unk4 * (f32) sp220) - (MKVector3::up.unk8 * unksp21C);
    sp4C = (MKVector3::up.unk8 * (f32) sp218) - (MKVector3::up.unk0 * (f32) sp220);
    sp50 = (MKVector3::up.unk0 * unksp21C) - (MKVector3::up.unk4 * (f32) sp218);
    sp218 = (f64) sp48;
    sp220 = (f64) sp50;
    sp138 = (f64) sp48;
    sp140 = (f64) sp50;
    if (((sp240 * (f32) sp220) + (((f32) sp238 * (f32) sp218) + (unksp23C * unksp21C))) < 0.0f) {
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
        sp220 = (f32) sp220 * -1.0f;
    }
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
    sp118.unk10 = sp38;
    sp40 = sp220 * 2000.0f;
    sp130 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unkFFC = 3;
    M2C_FIELD(this, f64 *, 0xFA0) = sp278;
    sp270 = (f32) sp270 + (f32) sp130;
    M2C_FIELD(this, f64 *, 0xFA8) = sp280;
    M2C_FIELD(this, f64 *, 0xFB0) = sp268;
    this->unkFA0 = (f64) sp270;
    this->unkFA8 = sp258;
    this->unkFB0 = sp260;
    this->unkFF0 = &this->unkCC0;
    this->unkFF4 = temp_f25_955;
}
#endif

#if 0 // DRAFT: expression syntax error
s32 Cynder::FollowPathToTarget(AITargetData *arg0) {
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
    M2C_UNK spC8;
    f64 spC0;
    f64 spB8;
    M2C_UNK spA8;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    M2C_UNK sp78;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp48;
    f64 sp38;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_1697;
    f32 temp_f1_1657;
    f32 temp_f1_1696;
    f32 temp_f28_1719;
    f32 temp_f30_1652;
    f32 temp_f31_1646;
    f32 temp_f3_1691;
    f32 temp_f4_1694;
    f32 temp_r3_1645;
    f32 var_f24_1714;
    f32 var_f25_1655;
    f32 var_f29_1715;
    u8 temp_r30_1556;
    u8 temp_r3_1562;
    u8 var_r30_1564;
    void *temp_r3_1635;
    void *temp_r5_1582;
    void *temp_r5_1608;

    sp18 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp20 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp128 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp130 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp118 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp120 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp108 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp110 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    spD8.GetPos();
    temp_r30_1556 = this->unk750.unkA0.IsPointWithin(*((MKVector3 *) &spD8));
    spC8.GetPos();
    temp_r3_1562 = this->unk800.unk28.IsPointWithin(*((MKVector3 *) &spC8));
    var_r30_1564 = 0;
    if ((temp_r30_1556 == 0) || (temp_r3_1562 != 0)) {
        if (CalculateRegionEdgeMoveTarget(arg0, (MKVector3 *) &sp128) != 0) {
            var_r30_1564 = 1;
            sp108 = sp128;
            sp110 = sp130;
        }
    } else {
        temp_r5_1582 = this->unk8;
        spB8 = M2C_FIELD(temp_r5_1582, f64 *, 0x30);
        spC0 = M2C_FIELD(temp_r5_1582, f64 *, 0x38);
        spA8.GetPos();
        if (this->unk750.unkA0.GetFirstIntersectionPlane(*((MKVector3 *) &spB8), *((MKVector3 *) &spA8), (MKVector3 *) &sp128, (MKVector3 *) &sp118) != 0) {
            sp98.GetPos();
            var_r30_1564 = 1;
            sp108 = sp98;
            sp110 = spA0;
        } else {
            temp_r5_1608 = this->unk8;
            sp88 = M2C_FIELD(temp_r5_1608, f64 *, 0x30);
            sp90 = M2C_FIELD(temp_r5_1608, f64 *, 0x38);
            sp78.GetPos();
            if (this->unk800.unk28.GetFirstIntersectionPlane(*((MKVector3 *) &sp88), *((MKVector3 *) &sp78), (MKVector3 *) &sp128, (MKVector3 *) &sp118) != 0) {
                sp68.GetPos();
                var_r30_1564 = 1;
                sp108 = sp68;
                sp110 = sp70;
            }
        }
    }
    if (var_r30_1564 != 0) {
        temp_r3_1635 = this->unk8;
        sp58 = M2C_FIELD(temp_r3_1635, f64 *, 0x30);
        sp60 = M2C_FIELD(temp_r3_1635, f64 *, 0x38);
        Tools_GetClosestSplineTimeXZ(M2C_BITWISE(s32, this->unkF64) + 0x30, *((MKVector3 *) &sp58), 0x14);
        temp_r3_1645 = this->unkF64;
        temp_f31_1646 = M2C_ERROR(/* Read from unset register $f1 */);
        temp_f30_1652 = 300.0f * (1.0f / M2C_FIELD(temp_r3_1645, f32 *, 0x38));
        var_f25_1655 = temp_f31_1646 - temp_f30_1652;
        temp_f1_1657 = (f32) fmod(temp_r3_1645, M2C_BITWISE(f64, (temp_f31_1646 + temp_f30_1652)), 1.0, 300.0f);
        if (var_f25_1655 < 0.0f) {
            var_f25_1655 += 1.0f;
        }
        sp10 = 0.0f;
        sp48.GetMeasure(temp_f1_1657, M2C_BITWISE(s32, this->unkF64) + 0x30, KDSpline_PositionMixer);
        spF8 = sp48;
        sp100 = sp50;
        spC = 0.0f;
        sp38.GetMeasure(var_f25_1655, M2C_BITWISE(s32, this->unkF64) + 0x30, KDSpline_PositionMixer);
        spE8 = sp38;
        spF0 = sp40;
        temp_f3_1691 = (f32) sp100 - (f32) sp110;
        temp_f4_1694 = (f32) spF0 - (f32) sp110;
        temp_f1_1696 = (f32) spE8 - (f32) sp108;
        temp_f0_1697 = (f32) spF8 - (f32) sp108;
        if (((temp_f0_1697 * temp_f0_1697) + (temp_f3_1691 * temp_f3_1691)) < ((temp_f1_1696 * temp_f1_1696) + (temp_f4_1694 * temp_f4_1694))) {
            this->unkF78 = 1.0f;
        } else {
            this->unkF78 = -1.0f;
        }
        var_f24_1714 = 0.0f;
        var_f29_1715 = temp_f31_1646;
        temp_f28_1719 = (f32) fabs(temp_f30_1652);
loop_31:
        if (!(var_f24_1714 < 1.0f)) {
            goto block_32;
        }
        sp8 = 0.0f;
        sp28.GetMeasure(var_f29_1715, M2C_BITWISE(s32, this->unkF64) + 0x30, KDSpline_PositionMixer);
        spF8 = sp28;
        sp100 = sp30;
        if ((this->unk750.unkA0.GetFirstIntersectionPlane(*((MKVector3 *) &spF8), *((MKVector3 *) &sp108), (MKVector3 *) &sp128, (MKVector3 *) &sp118) == 0) && (this->unk800.unk28.GetFirstIntersectionPlane(*((MKVector3 *) &spF8), *((MKVector3 *) &sp108), (MKVector3 *) &sp128, (MKVector3 *) &sp118) == 0)) {
            M2C_FIELD(this, f64 *, 0xF80) = spF8;
            M2C_FIELD(this, f64 *, 0xF88) = sp100;
            this->unk870.unk40.Set(*((MKVector3 *) &sp108), 0U);
            if (temp_f31_1646 > var_f29_1715) {
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if ((temp_f31_1646 - var_f29_1715) == 0.5f) {
                    this->unkF78 = 1.0f;
                } else {
                    this->unkF78 = -1.0f;
                }
            }
            if (temp_f31_1646 < var_f29_1715) {
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if ((var_f29_1715 - temp_f31_1646) == 0.5f) {
                    this->unkF78 = -1.0f;
                } else {
                    this->unkF78 = 1.0f;
                }
            }
            return 1;
        }
        var_f29_1715 += temp_f30_1652 * M2C_BITWISE(f32, this->unkF78);
        if (var_f29_1715 > 1.0f) {
            var_f29_1715 -= 1.0f;
        }
        if (var_f29_1715 < 0.0f) {
            var_f29_1715 += 1.0f;
        }
        var_f24_1714 += temp_f28_1719;
        goto loop_31;
    }
block_32:
    return 0;
}
#endif

#if 0 // DRAFT: expression syntax error
u8 Cynder::CalculateRegionEdgeMoveTarget(AITargetData *arg0, MKVector3 *arg1) {
    AITargetData sp138;
    M2C_UNK sp128;
    M2C_UNK sp118;
    f64 sp110;
    f64 sp108;
    MKVector3 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    M2C_UNK spA8;
    f64 spA0;
    f64 sp98;
    MKVector3 sp88;
    f32 sp80;
    f32 sp70;
    M2C_UNK sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f64 sp10;
    f64 sp8;
    f32 temp_f3_1905;
    u8 temp_r30_1866;
    u8 temp_r31_1876;
    u8 var_r29_1979;
    u8 var_r30_1845;

    var_r30_1845 = 0;
    if (((u8) M2C_FIELD(arg0, u8 *, 0x48) == 2) || (arg0->unk40.Get() != NULL)) {
        var_r30_1845 = 1;
    }
    if (var_r30_1845 == 0) {
        return 0U;
    }
    sp138.GetPos();
    temp_r30_1866 = this->unk750.unkA0.IsPointWithin(*((MKVector3 *) &sp138));
    sp128.GetPos();
    temp_r31_1876 = this->unk800.unk28.IsPointWithin(*((MKVector3 *) &sp128));
    sp8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp10 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp138.unk40 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp138.unk40.unk8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp138.unk30 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp138.unk38 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp138.unk20 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp138.unk28 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp138.unk10 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp138.unk18 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    if (temp_r30_1866 == 0) {
        sp118.GetPos();
        this->unk750.unkA0.GetNearestPointOnBoundingRegion(*((MKVector3 *) &sp118), (MKVector3 *) &sp138.unk40, (MKVector3 *) &sp138.unk20);
        spF8.operator*(600.0f);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
        temp_f3_1905 = M2C_BITWISE(f32, sp138.unk40.unk8);
        sp108 = sp48;
        sp50 = temp_f3_1905 + spF8.unk8;
        sp138.unk30 = sp48;
        sp110 = (f64) sp50;
        sp138.unk38 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        spD8 = sp78;
        sp80 = (f32) sp138.unk28 * 1.0f;
        spE0 = (f64) sp80;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
        spE8 = sp68;
        sp70 = temp_f3_1905 + (f32) spE0;
        spF0 = (f64) sp70;
        if (this->unk750.unkA0.GetFirstIntersectionPlane(*((MKVector3 *) &spE8), *((MKVector3 *) &sp138.unk30), (MKVector3 *) &sp138.unk30, (MKVector3 *) &sp138.unk10) != 0) {
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spB8 = sp18;
            sp20 = (f32) sp138.unk38 - M2C_BITWISE(f32, sp138.unk40.unk8);
            spC0 = (f64) sp20;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            spC8 = sp38;
            sp40 = (f32) spC0 * 0.5f;
            spD0 = (f64) sp40;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp138.unk40.unk8 = M2C_BITWISE(f32, sp138.unk40.unk8) + (f32) spD0;
        } else {
            var_r29_1979 = 0;
            if (this->unk750.unkA0.IsPointWithin(*((MKVector3 *) &sp138.unk30)) != 0) {
                sp58.GetRegionPos();
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if ((f32) fabs(sp5C - sp138.unk34) == 500.0f) {
                    var_r29_1979 = 1;
                }
            }
            if (var_r29_1979 != 0) {
                sp138.unk40 = sp138.unk30;
                sp138.unk40.unk8 = sp138.unk38;
            }
        }
    } else if (temp_r31_1876 != 0) {
        spA8.GetPos();
        this->unk800.unk28.GetNearestPointOnBoundingRegion(*((MKVector3 *) &spA8), (MKVector3 *) &sp138.unk40, (MKVector3 *) &sp138.unk20);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp138.unk28 = (f32) sp138.unk28 * -1.0f;
        sp88.operator*(600.0f);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp98 = sp28;
        sp30 = (f32) sp138.unk40.unk8 + sp88.unk8;
        sp138.unk30 = sp28;
        spA0 = (f64) sp30;
        sp138.unk38 = (f64) sp30;
        sp138.unk40 = sp28;
        sp138.unk40.unk8 = (f64) sp30;
    }
    if ((temp_r30_1866 == 0) || (temp_r31_1876 != 0)) {
        M2C_FIELD(arg1, f64 *, 0) = sp138.unk40;
        M2C_FIELD(arg1, f64 *, 8) = sp138.unk40.unk8;
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: identifier 'Cynder::ShootFireBomb(const MKVector3 &, const MKVector3 &,
s32 Cynder::ShootFireBomb(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2) {
    FireBombFX *temp_r3_2081;

    temp_r3_2081 = checked_cast<FireBombFX *, MKProp>(this->unkCD8->CreateInstance());
    if (temp_r3_2081 == NULL) {
        return 0;
    }
    M2C_FIELD(temp_r3_2081->__vptr, M2C_UNK (**)(), 0x30)();
    temp_r3_2081->Fire(arg0, arg1, 0.4f, (MKProp *) this, 1U, 0U, 2, arg2);
    if (M2C_FIELD(*gb, s32 (**)(void **), 8)(gb) == 1) {
        KDSound_Play3d(GS_SWCynderFireball1, &arg0, 0U, -1, 0.0f, 0U);
    }
    return 1;
}
#endif

void Cynder::UpdateEffects() {
    UpdateFuryPowerUp();
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
void Cynder::GetCharacterName() {
    return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x330);
}
#endif

void Cynder::UpdateEnemyHud() {
    EnemyHudData sp8;
    f32 temp_f31_2160;

    sp8.EnemyHudData();
    temp_f31_2160 = this->unkAB0;
    GetMaxHealth();
    sp8.Init((Enemy *) this, temp_f31_2160, M2C_ERROR(/* Read from unset register $f1 */));
    EnemyHud_Modified(sp8);
}

#if 0 // DRAFT: undefined identifier 'GetAnimSequence'
s32 Cynder::CanLeap(bool arg0) {
    f32 temp_f10_2300;
    f32 temp_f11_2302;
    f32 temp_f9_2299;
    s32 var_r5_2187;
    u8 var_r30_2326;
    void *temp_r3_2199;
    var_r5_2187 = 0x1B;
    if (arg0 != 0) {
        var_r5_2187 = 0x1C;
    }
    temp_r3_2199 = this->unkA20->GetAnimSequence(9, var_r5_2187, M2C_BITWISE(s32, this->unkACC), NULL);
    if (temp_r3_2199 != NULL) {
        M2C_STRUCT_COPY((s32) &arg_sp15C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        arg_sp130.GetDir();
        arg_sp30 = -arg_sp130;
        arg_sp34 = -arg_sp134;
        arg_sp38 = -arg_sp138;
        arg_sp140 = (f64) arg_sp30;
        arg_sp148 = (f64) arg_sp38;
        arg_sp180 = (f32) arg_sp140;
        arg_sp184 = arg_sp144;
        arg_sp188 = (f32) arg_sp148;
        arg_sp18C = 0.0f;
        arg_sp170 = MKVector3::up.unk0;
        arg_sp174 = MKVector3::up.unk4;
        arg_sp178 = MKVector3::up.unk8;
        arg_sp17C = 0.0f;
        arg_sp100.GetDir();
        arg_sp10 = -arg_sp100;
        arg_sp14 = -arg_sp104;
        arg_sp18 = -arg_sp108;
        arg_sp110 = (f64) arg_sp10;
        arg_sp118 = (f64) arg_sp18;
        arg_sp16C = 0.0f;
        arg_sp20 = (MKVector3::up.unk4 * (f32) arg_sp118) - (MKVector3::up.unk8 * arg_sp114);
        arg_sp24 = (MKVector3::up.unk8 * (f32) arg_sp110) - (MKVector3::up.unk0 * (f32) arg_sp118);
        arg_sp28 = (MKVector3::up.unk0 * arg_sp114) - (MKVector3::up.unk4 * (f32) arg_sp110);
        arg_sp120 = (f64) arg_sp20;
        arg_sp128 = (f64) arg_sp28;
        arg_sp160 = (f32) arg_sp120;
        arg_sp164 = arg_sp124;
        arg_sp168 = (f32) arg_sp128;
        temp_f9_2299 = M2C_FIELD(temp_r3_2199, f32 *, 0xC);
        temp_f10_2300 = M2C_FIELD(temp_r3_2199, f32 *, 8);
        temp_f11_2302 = M2C_FIELD(temp_r3_2199, f32 *, 0x10);
        arg_spA0 = (temp_f11_2302 * arg_sp180) + ((temp_f10_2300 * (f32) arg_sp120) + (temp_f9_2299 * arg_sp170));
        arg_spA4 = (temp_f11_2302 * arg_sp184) + ((temp_f10_2300 * arg_sp124) + (temp_f9_2299 * arg_sp174));
        arg_spA8 = (temp_f11_2302 * arg_sp188) + ((temp_f10_2300 * (f32) arg_sp128) + (temp_f9_2299 * arg_sp178));
        arg_spF0 = (f64) arg_spA0;
        arg_spF8 = (f64) arg_spA8;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        var_r30_2326 = 0;
        arg_sp150 = arg_sp90;
        arg_sp98 = this->unk588.unk4 + (f32) arg_spF8;
        arg_sp158 = (f64) arg_sp98;
        if (this->unk750.unkA0.IsPointWithin(*((MKVector3 *) &arg_sp150)) != 0) {
            arg_sp80.GetRegionPos();
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if ((f32) fabs(arg_sp84 - arg_sp154) == 500.0f) {
                var_r30_2326 = 1;
            }
        }
        if ((var_r30_2326 != 0) && (this->unk800.unk28.IsPointWithin(*((MKVector3 *) &arg_sp150)) == 0)) {
            arg_sp50 = 0.0f;
            arg_sp54 = 500.0f;
            arg_sp58 = 0.0f;
            arg_spB0 = (f64) arg_sp50;
            arg_spB8 = (f64) arg_sp58;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f0 */);
            arg_sp78 = 0.0f;
            arg_sp70 = 0.0f;
            arg_sp74 = 100.0f;
            arg_sp48 = (f32) arg_sp158 - (f32) arg_spB8;
            arg_spD0 = (f64) arg_sp70;
            arg_spC0 = arg_sp40;
            arg_spC8 = (f64) arg_sp48;
            arg_spD8 = (f64) arg_sp78;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
            arg_spE0 = arg_sp60;
            arg_sp68 = (f32) arg_sp158 + (f32) arg_spD8;
            arg_spE8 = (f64) arg_sp68;
            if (MKCollision_RayCollide(*((MKVector3 *) &arg_spE0), *((MKVector3 *) &arg_spC0), (MKCollisionResult *) &arg_sp1A0, (MKCollisionMode) 7, M2C_FIELD(this->unk110.unk460, s32 *, 0x18) | 0x08000000) != 0) {
                return 1;
            }
        }
        goto block_10;
    }
block_10:
    return 0;
}
#endif

#if 0 // DRAFT: expression syntax error
s32 Cynder::GetAttackHeading(EnemyAttack *arg0, MKVector3 *arg1) {
    AITargetData sp18;
    f64 sp8;
    f32 temp_f0_2480;
    f32 temp_f28_2466;
    f32 temp_f29_2456;
    f32 temp_f30_2469;
    f32 temp_f31_2472;
    f32 var_f1_2506;
    u8 var_r0_2479;
    u8 var_r31_2441;

    if ((arg0 != NULL) && (arg1 != NULL)) {
        var_r31_2441 = 0;
        if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk30.Get() != NULL)) {
            var_r31_2441 = 1;
        }
        if (var_r31_2441 != 0) {
            temp_f29_2456 = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &this->unkC0)));
            sp18.GetDir();
            temp_f28_2466 = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &sp18)));
            temp_f30_2469 = NormaliseAngle(temp_f29_2456 + arg0->unk1C);
            temp_f31_2472 = NormaliseAngle(temp_f29_2456 + arg0->unk20);
            this->unk838.unk28.GetDist();
            if (temp_f30_2469 > temp_f31_2472) {
                var_r0_2479 = 0;
                temp_f0_2480 = 6.2831855f - temp_f30_2469;
                if ((temp_f28_2466 > temp_f30_2469) || ((temp_f28_2466 + temp_f0_2480) < (temp_f31_2472 + temp_f0_2480))) {
                    var_r0_2479 = 1;
                }
            } else {
                var_r0_2479 = 0;
                if ((temp_f28_2466 > temp_f30_2469) && ((temp_f28_2466 - temp_f30_2469) < (temp_f31_2472 - temp_f30_2469))) {
                    var_r0_2479 = 1;
                }
            }
            if (var_r0_2479 == 0) {
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if (temp_f31_2472 == temp_f30_2469) {
                    var_f1_2506 = 0.5f * (temp_f30_2469 + temp_f31_2472);
                } else {
                    var_f1_2506 = (0.5f * (temp_f31_2472 + (6.2831855f - temp_f30_2469))) + temp_f30_2469;
                    if (var_f1_2506 > 6.2831855f) {
                        var_f1_2506 -= 6.2831855f;
                    }
                }
                KDMath_GetDirection(temp_f29_2456 + KDMath_GetSmallestAngle(var_f1_2506, temp_f28_2466));
                M2C_FIELD(arg1, f64 *, 0) = sp8;
                M2C_FIELD(arg1, f64 *, 8) = sp10;
                return 1;
            }
            goto block_19;
        }
        goto block_19;
    }
block_19:
    return 0;
}
#endif

s32 Cynder::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    MKModel_CalculateNodeWorldPosition(this->unk4, this->unkCF8, arg1);
    return 1;
}

void Cynder::Despawn(bool arg0) {
    Enemy::Despawn(arg0);
    M2C_FIELD(&gb, s32 *, 0x360) = 0;
    UpdateEnemyHud();
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
s32 Cynder::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    M2C_UNK *temp_r5_2702;
    f32 temp_r3_2602;
    s32 temp_r3_2672;
    s32 temp_r3_2686;
    s32 var_r28_2679;
    s32 var_r29_2613;
    s32 var_r29_2681;
    s32 var_r30_2620;
    s32 var_r30_2680;
    u32 temp_r3_2606;
    void *temp_r4_2703;

    this->unkF64 = 0.0f;
    temp_r3_2602 = this->unkF60;
    if (M2C_BITWISE(s32, temp_r3_2602) != 0) {
        temp_r3_2606 = checked_cast<KDSplinePathSegmentProp *, MKProp>(((MKSceneManager *) (M2C_BITWISE(MKSceneManager *, temp_r3_2602)))->PropResolver_Resolve((s32) arg0));
        if (temp_r3_2606 != 0U) {
            this->unkF64 = M2C_BITWISE(f32, (temp_r3_2606 + 0x4C));
        }
        var_r29_2613 = 0;
        this->unkCC0.unk8 = 0.0f;
        this->unkCC0.unk4 = 0;
        if (M2C_BITWISE(u32, this->unkF64) != 0U) {
            var_r30_2620 = 0;
loop_6:
            if (var_r30_2620 < (s32) M2C_FIELD(this->unkF64, s32 *, 0x34)) {
                sp18 = 0.0f;
                sp1C = 800.0f;
                sp20 = 0.0f;
                sp28 = (f64) sp18;
                sp30 = (f64) sp20;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp38 = sp8;
                sp10 = M2C_FIELD((M2C_FIELD(this->unkF64, s32 *, 0x3C) + var_r29_2613), f32 *, 8) + (f32) sp30;
                sp40 = (f64) sp10;
                this->unkCC0.AddNode(*((MKVector3 *) &sp38));
                var_r30_2620 += 1;
                var_r29_2613 += 0x20;
                goto loop_6;
            }
        }
    }
    if (Enemy::Spawn(arg0, arg1) != 0) {
        M2C_FIELD(&gb, Cynder **, 0x360) = this;
        UpdateEnemyHud();
        if ((u8) M2C_FIELD(this, u8 *, 0xD01) == 0) {
            temp_r3_2672 = checked_cast<KDLocalPathSegmentProp *, MKProp>(this->unkDA0->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
            if (temp_r3_2672 != 0) {
                this->unk800.unk28.SetupRegion(temp_r3_2672 + 0x4C);
            }
            var_r28_2679 = 0;
            var_r30_2680 = 0;
            var_r29_2681 = 0;
            do {
                temp_r3_2686 = checked_cast<KDLocalPathSegmentProp *, MKProp>(((MKSceneManager *) (*(this + (var_r29_2681 + 0xDA4))))->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
                if (temp_r3_2686 != 0) {
                    ((EnemyRegion *) (this + (var_r30_2680 + 0xDB8)))->SetupRegion(temp_r3_2686 + 0x4C);
                }
                var_r28_2679 += 1;
                var_r29_2681 += 4;
                var_r30_2680 += 0x38;
            } while (var_r28_2679 < 4);
            temp_r5_2702 = &this->unk80C;
            temp_r4_2703 = this + 0xDC4;
            M2C_FIELD(this, f64 *, 0x800) = (f64) M2C_FIELD(this, f64 *, 0xDB8);
            M2C_FIELD(this, f64 *, 0x808) = (f64) this->unkDC0;
            M2C_STRUCT_COPY((s32) temp_r5_2702 + 4, (s32) temp_r4_2703 + 4, 0x18);
            M2C_FIELD((temp_r5_2702 + 0x18), s32 *, 4) = (s32) M2C_FIELD((temp_r4_2703 + 0x18), s32 *, 4);
            this->unk800.unk1C = this->unkDE4;
            M2C_FIELD(this, u8 *, 0x830) = (u8) this->unkDE8;
            M2C_FIELD(this, u8 *, 0x831) = (u8) this->unkDE9;
            SetupExclusionRegion();
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: expression syntax error
void Cynder::Message(MKMessage *arg0) {
    f32 temp_f1_2861;
    f32 temp_f1_2893;
    f32 temp_f1_2922;
    f32 temp_f4_2928;
    f32 temp_f5_2867;
    f32 temp_f5_2915;
    f32 temp_f6_2853;
    s32 temp_cr0_eq_2839;
    s32 temp_r0_2754;
    s32 temp_r31_3016;
    void *temp_r29_2982;
    void *temp_r3_2996;
    ((KDSoundPlayer *) (this + 0xD6C))->Message(arg0);
    temp_r0_2754 = arg0->unk0;
    switch (temp_r0_2754) {                         /* irregular */
    case 181:
        Enable();
    default:
block_34:
        Enemy::Message(arg0);
        return;
    case 211:
        if ((u8) M2C_FIELD(this, u8 *, 0xF19) != 0) {
            M2C_FIELD(this, s8 *, 0xF1A) = 1;
        }
        goto block_34;
    case -3:
        if (!(((u8) M2C_FIELD(this, u8 *, 0xB09) >> 7U) & 1)) {
            Enemy::Message(arg0);
            Deactivate();
            return;
        }
        goto block_34;
    case 21:
        if ((IsDying() == 0) && (IsDead() == 0)) {
            GetMaxHealth();
            SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
            UpdateEnemyHud();
            M2C_FIELD(this, s8 *, 0xF18) = 1;
            M2C_FIELD(this, s8 *, 0xF1B) = 1;
            M2C_FIELD(this, s8 *, 0xF1E) = 0;
            this->unkEFC.unk0 = 0.0f;
            if (M2C_BITWISE(s32, this->unkAD0) <= 2) {
                this->unkEB0.Send(NULL);
            }
            temp_cr0_eq_2839 = M2C_BITWISE(s32, this->unkAD0) == 3;
            if (temp_cr0_eq_2839 == 0) {
                M2C_STRUCT_COPY((s32) &arg_spBC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                temp_f6_2853 = this->unk5C8;
                arg_spE0 = temp_f6_2853;
                temp_f1_2861 = this->unk5C8;
                arg_spE4 = temp_f1_2861;
                temp_f5_2867 = this->unk5CC;
                arg_spE8 = temp_f5_2867;
                arg_sp38 = (MKVector3::up.unk0 * temp_f1_2861) - (MKVector3::up.unk4 * temp_f6_2853);
                arg_sp30 = (MKVector3::up.unk4 * temp_f5_2867) - (MKVector3::up.unk8 * temp_f1_2861);
                arg_sp34 = (MKVector3::up.unk8 * temp_f6_2853) - (MKVector3::up.unk0 * temp_f5_2867);
                arg_sp68 = (f64) arg_sp38;
                arg_sp60 = (f64) arg_sp30;
                arg_spEC = 0.0f;
                arg_spC0 = (f32) arg_sp60;
                arg_spC4 = arg_sp64;
                arg_spC8 = (f32) arg_sp68;
                arg_spCC = 0.0f;
                arg_spF0 = this->unk5B8;
                arg_spF4 = this->unk5B8;
                temp_f1_2893 = this->unk5BC;
                arg_spF8 = temp_f1_2893;
                arg_spFC = 1.0f;
                Teleport(&arg_spC0, &MKVector3::up, temp_f1_2893, arg_sp64, (f32) arg_sp60, 0.0f, temp_f5_2867, temp_f6_2853, MKVector3::up.unk8, MKVector3::up.unk4);
            } else if (temp_cr0_eq_2839 != 0) {
                M2C_STRUCT_COPY((s32) &arg_sp7C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                temp_f5_2915 = this->unkEA8;
                arg_spA0 = temp_f5_2915;
                temp_f1_2922 = this->unkEAC;
                arg_spA4 = temp_f1_2922;
                temp_f4_2928 = this->unkE98.unk0;
                arg_spA8 = temp_f4_2928;
                arg_sp28 = (MKVector3::up.unk0 * temp_f1_2922) - (MKVector3::up.unk4 * temp_f5_2915);
                arg_sp20 = (MKVector3::up.unk4 * temp_f4_2928) - (MKVector3::up.unk8 * temp_f1_2922);
                arg_sp24 = (MKVector3::up.unk8 * temp_f5_2915) - (MKVector3::up.unk0 * temp_f4_2928);
                arg_sp58 = (f64) arg_sp28;
                arg_sp50 = (f64) arg_sp20;
                arg_spAC = 0.0f;
                arg_sp80 = (f32) arg_sp50;
                arg_sp84 = arg_sp54;
                arg_sp88 = (f32) arg_sp58;
                arg_sp8C = 0.0f;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp40 = arg_sp10;
                arg_sp18 = this->unkE98.unk8 + this->unkEA8;
                arg_sp48 = (f64) arg_sp18;
                arg_spB0 = (f32) arg_sp40;
                arg_spB4 = arg_sp44;
                arg_spB8 = (f32) arg_sp48;
                arg_spBC = 1.0f;
                Teleport(&arg_sp80, &arg_sp7C + 0x40, (f32) arg_sp48, arg_sp44, (f32) arg_sp40, temp_f4_2928, temp_f5_2915, MKVector3::up.unk8, MKVector3::up.unk4, MKVector3::up.unk0);
                ResetFury();
            }
        }
        goto block_34;
    case 1089:
        temp_r29_2982 = checked_cast<CameraLockOnTargetableGetTarget *, MKMessage>(arg0);
        MKModel_CalculateNodeWorldPosition(this->unk4, this->unkD9C, (MKVector3 *) &arg_sp70);
        M2C_FIELD(temp_r29_2982, s8 *, 0x18) = 1;
        M2C_FIELD(temp_r29_2982, f64 *, 8) = arg_sp70;
        M2C_FIELD(temp_r29_2982, f64 *, 0x10) = arg_sp78;
        goto block_34;
    case 5:
        temp_r3_2996 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
        if ((s32) M2C_FIELD(temp_r3_2996, s32 *, 0x38) == 3) {
            if ((s32) M2C_FIELD(temp_r3_2996, s32 *, 0x48) != 0) {
                M2C_FIELD(temp_r3_2996, f32 *, 0x34) = 0.1f;
                goto block_34;
            }
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_FIELD(temp_r3_2996, f32 *, 0x34) == 0.0f) {
                return;
            }
            goto block_34;
        }
        goto block_34;
    case 166:
        temp_r31_3016 = checked_cast<GetConvexFuryTargetPosMsg *, MKMessage>(arg0);
        MKModel_CalculateNodeWorldPosition(this->unk4, M2C_FIELD(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x3B8), temp_r31_3016 + 8);
        return;
    }
}
#endif

void Cynder::Draw() {
    Enemy::Draw();
}

#if 0 // DRAFT: undefined identifier 'GetAnimSequence'
void Cynder::CalculateDiveTrajectory() {
    f32 temp_f10_3206;
    f32 temp_f10_3253;
    f32 temp_f11_3254;
    f32 temp_f12_3256;
    f32 temp_f4_3597;
    f32 temp_f8_3202;
    f32 temp_f9_3204;
    f32 temp_r0_3068;
    f32 var_f0_3185;
    f32 var_f4_3096;
    f32 var_f4_3307;
    f32 var_f4_3473;
    f32 var_f5_3115;
    f32 var_f5_3492;
    f64 temp_f1_3120;
    f64 temp_f1_3126;
    f64 temp_f1_3130;
    f64 temp_f1_3312;
    f64 temp_f1_3318;
    f64 temp_f1_3322;
    f64 temp_f1_3497;
    f64 temp_f1_3503;
    f64 temp_f1_3507;
    f64 temp_f1_3582;
    s32 temp_r3_3341;
    s32 temp_r3_3526;
    s32 temp_r4_3149;
    s32 var_r0_3159;
    s32 var_r0_3351;
    s32 var_r0_3536;
    void *temp_r3_3081;
    temp_r0_3068 = this->unkCDC;
    switch (M2C_BITWISE(s32, temp_r0_3068)) {       /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        temp_r3_3081 = this->unkA20->GetAnimSequence(0xA, 0xDD, M2C_BITWISE(s32, this->unkACC), NULL);
        M2C_STRUCT_COPY((s32) &arg_sp31C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        var_f4_3096 = 0.0f;
        arg_sp164 = 0.0f;
        arg_sp160 = this->unk5B8 - this->unk588;
        arg_sp168 = this->unk5BC - this->unk588.unk4;
        arg_sp2A0 = (f64) arg_sp160;
        arg_sp2A8 = (f64) arg_sp168;
        var_f5_3115 = ((f32) arg_sp2A8 * (f32) arg_sp2A8) + (((f32) arg_sp2A0 * (f32) arg_sp2A0) + (arg_sp2A4 * arg_sp2A4));
        if (var_f5_3115 > 1e-12f) {
            if (var_f5_3115 > 0.0f) {
                temp_f1_3120 = __frsqrte(var_f5_3115);
                temp_f1_3126 = 0.5 * temp_f1_3120 * -(((f64) var_f5_3115 * (temp_f1_3120 * temp_f1_3120)) - 3.0);
                temp_f1_3130 = 0.5 * temp_f1_3126 * -(((f64) var_f5_3115 * (temp_f1_3126 * temp_f1_3126)) - 3.0);
                var_f5_3115 = (f32) ((f64) var_f5_3115 * (0.5 * temp_f1_3130 * -(((f64) var_f5_3115 * (temp_f1_3130 * temp_f1_3130)) - 3.0)));
            } else if (var_f5_3115 < M2C_BITWISE(f32, 0.0)) {
                var_f5_3115 = __float_nan;
            } else {
                arg_sp18 = var_f5_3115;
                temp_r4_3149 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
                switch (temp_r4_3149) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                        var_r0_3159 = 1;
                    } else {
                        var_r0_3159 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                        var_r0_3159 = 5;
                    } else {
                        var_r0_3159 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_3159 = 4;
                    break;
                }
                if (var_r0_3159 == 1) {
                    var_f5_3115 = __float_nan;
                }
            }
            var_f4_3096 = 1.0f / var_f5_3115;
        }
        var_f0_3185 = 0.0f;
        arg_sp158 = (f32) arg_sp2A8 * var_f4_3096;
        arg_sp150 = (f32) arg_sp2A0 * var_f4_3096;
        arg_sp154 = arg_sp2A4 * var_f4_3096;
        arg_sp318 = (f64) arg_sp158;
        arg_sp310 = (f64) arg_sp150;
        temp_f8_3202 = -(f32) arg_sp318;
        temp_f9_3204 = -(f32) arg_sp310;
        arg_sp34C = 0.0f;
        temp_f10_3206 = -arg_sp314;
        arg_sp38 = temp_f8_3202;
        arg_sp30 = temp_f9_3204;
        arg_sp34 = temp_f10_3206;
        arg_sp278 = (f64) arg_sp38;
        arg_sp270 = (f64) arg_sp30;
        arg_sp98 = temp_f8_3202;
        arg_sp298 = (f64) arg_sp98;
        arg_sp88 = (MKVector3::up.unk0 * arg_sp274) - (MKVector3::up.unk4 * (f32) arg_sp270);
        arg_sp90 = temp_f9_3204;
        arg_sp94 = temp_f10_3206;
        arg_sp288 = (f64) arg_sp88;
        arg_sp290 = (f64) arg_sp90;
        arg_sp80 = (MKVector3::up.unk4 * (f32) arg_sp278) - (MKVector3::up.unk8 * arg_sp274);
        arg_sp84 = (MKVector3::up.unk8 * (f32) arg_sp270) - (MKVector3::up.unk0 * (f32) arg_sp278);
        arg_sp340 = (f32) arg_sp290;
        arg_sp280 = (f64) arg_sp80;
        arg_sp344 = arg_sp294;
        arg_sp348 = (f32) arg_sp298;
        arg_sp320 = (f32) arg_sp280;
        arg_sp324 = arg_sp284;
        arg_sp328 = (f32) arg_sp288;
        arg_sp32C = 0.0f;
        temp_f10_3253 = M2C_FIELD(temp_r3_3081, f32 *, 0xC);
        temp_f11_3254 = M2C_FIELD(temp_r3_3081, f32 *, 8);
        temp_f12_3256 = M2C_FIELD(temp_r3_3081, f32 *, 0x10);
        arg_sp140 = (temp_f12_3256 * (f32) arg_sp290) + ((temp_f11_3254 * (f32) arg_sp280) + (temp_f10_3253 * arg_sp330));
        arg_sp144 = (temp_f12_3256 * arg_sp294) + ((temp_f11_3254 * arg_sp284) + (temp_f10_3253 * arg_sp334));
        arg_sp148 = (temp_f12_3256 * (f32) arg_sp298) + ((temp_f11_3254 * (f32) arg_sp288) + (temp_f10_3253 * arg_sp338));
        arg_sp300 = (f64) arg_sp140;
        arg_sp308 = (f64) arg_sp148;
        M2C_ERROR(/* unknown instruction: psq_lx $f2, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f2, $f1 */);
        arg_sp134 = 0.0f;
        this->unkD30 = arg_sp70;
        arg_sp78 = this->unk5BC - (f32) arg_sp308;
        arg_sp260 = arg_sp70;
        this->unkD38 = (f64) arg_sp78;
        arg_sp268 = (f64) arg_sp78;
        arg_sp130 = (f32) M2C_FIELD(this, f64 *, 0xD48) - this->unk588;
        arg_sp138 = (f32) M2C_FIELD(this, f64 *, 0xD50) - this->unk588.unk4;
        arg_sp250 = (f64) arg_sp130;
        arg_sp258 = (f64) arg_sp138;
        var_f4_3307 = ((f32) arg_sp258 * (f32) arg_sp258) + (((f32) arg_sp250 * (f32) arg_sp250) + (arg_sp254 * arg_sp254));
        if (var_f4_3307 > 1e-12f) {
            if (var_f4_3307 > 0.0f) {
                temp_f1_3312 = __frsqrte(var_f4_3307);
                temp_f1_3318 = 0.5 * temp_f1_3312 * -(((f64) var_f4_3307 * (temp_f1_3312 * temp_f1_3312)) - 3.0);
                temp_f1_3322 = 0.5 * temp_f1_3318 * -(((f64) var_f4_3307 * (temp_f1_3318 * temp_f1_3318)) - 3.0);
                var_f4_3307 = (f32) ((f64) var_f4_3307 * (0.5 * temp_f1_3322 * -(((f64) var_f4_3307 * (temp_f1_3322 * temp_f1_3322)) - 3.0)));
            } else if (var_f4_3307 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3307 = __float_nan;
            } else {
                arg_sp14 = var_f4_3307;
                temp_r3_3341 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                switch (temp_r3_3341) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_3351 = 1;
                    } else {
                        var_r0_3351 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_3351 = 5;
                    } else {
                        var_r0_3351 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_3351 = 4;
                    break;
                }
                if (var_r0_3351 == 1) {
                    var_f4_3307 = __float_nan;
                }
            }
            var_f0_3185 = 1.0f / var_f4_3307;
        }
        arg_sp124 = arg_sp254 * var_f0_3185;
        arg_sp120 = (f32) arg_sp250 * var_f0_3185;
        arg_sp128 = (f32) arg_sp258 * var_f0_3185;
        arg_sp2F0 = (f64) arg_sp120;
        arg_sp2F8 = (f64) arg_sp128;
        arg_sp230.operator*(2000.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        this->unkD20 = arg_sp60;
        arg_sp68 = (f32) M2C_FIELD(this, f64 *, 0xD50) - arg_sp238;
        arg_sp240 = arg_sp60;
        this->unkD28 = (f64) arg_sp68;
        arg_sp248 = (f64) arg_sp68;
        M2C_FIELD(this, f32 *, 0xD3C) = (f32) (M2C_FIELD(this, f32 *, 0xD3C) + 200.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp1F0 = arg_sp20;
        arg_sp28 = this->unk588.unk4 - (f32) M2C_FIELD(this, f64 *, 0xD40);
        arg_sp1F8 = (f64) arg_sp28;
        Normalise(*((MKVector3 *) &arg_sp200));
        arg_sp210.operator*(2000.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        this->unkD10 = arg_sp50;
        arg_sp58 = (f32) M2C_FIELD(this, f64 *, 0xD40) + arg_sp218;
        arg_sp220 = arg_sp50;
        this->unkD18 = (f64) arg_sp58;
        arg_sp228 = (f64) arg_sp58;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp1D0 = arg_sp40;
        arg_sp48 = (f32) M2C_FIELD(this, f64 *, 0xD30) - this->unk588.unk4;
        arg_sp1D8 = (f64) arg_sp48;
        Normalise(*((MKVector3 *) &arg_sp1E0));
        M2C_FIELD(this, f64 *, 0xD18) = arg_sp1E0;
        this->unkD08 = arg_sp1E8;
        return;
    case 0:                                         /* switch 1 */
        arg_sp1B0.GetPos();
        var_f4_3473 = 0.0f;
        arg_sp114 = 0.0f;
        arg_sp110 = arg_sp1B0 - this->unk588;
        arg_sp118 = arg_sp1B8 - this->unk588.unk4;
        arg_sp1C0 = (f64) arg_sp110;
        arg_sp1C8 = (f64) arg_sp118;
        var_f5_3492 = ((f32) arg_sp1C8 * (f32) arg_sp1C8) + (((f32) arg_sp1C0 * (f32) arg_sp1C0) + (arg_sp1C4 * arg_sp1C4));
        if (var_f5_3492 > 1e-12f) {
            if (var_f5_3492 > 0.0f) {
                temp_f1_3497 = __frsqrte(var_f5_3492);
                temp_f1_3503 = 0.5 * temp_f1_3497 * -(((f64) var_f5_3492 * (temp_f1_3497 * temp_f1_3497)) - 3.0);
                temp_f1_3507 = 0.5 * temp_f1_3503 * -(((f64) var_f5_3492 * (temp_f1_3503 * temp_f1_3503)) - 3.0);
                var_f5_3492 = (f32) ((f64) var_f5_3492 * (0.5 * temp_f1_3507 * -(((f64) var_f5_3492 * (temp_f1_3507 * temp_f1_3507)) - 3.0)));
            } else if (var_f5_3492 < M2C_BITWISE(f32, 0.0)) {
                var_f5_3492 = __float_nan;
            } else {
                arg_sp10 = var_f5_3492;
                temp_r3_3526 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_3526) {             /* switch 4; irregular */
                case 0x7F800000:                    /* switch 4 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_3536 = 1;
                    } else {
                        var_r0_3536 = 2;
                    }
                    break;
                case 0x0:                           /* switch 4 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_3536 = 5;
                    } else {
                        var_r0_3536 = 3;
                    }
                    break;
                default:                            /* switch 4 */
                    var_r0_3536 = 4;
                    break;
                }
                if (var_r0_3536 == 1) {
                    var_f5_3492 = __float_nan;
                }
            }
            var_f4_3473 = 1.0f / var_f5_3492;
        }
        arg_sp104 = arg_sp1C4 * var_f4_3473;
        arg_sp100 = (f32) arg_sp1C0 * var_f4_3473;
        arg_sp108 = (f32) arg_sp1C8 * var_f4_3473;
        arg_sp2E0 = (f64) arg_sp100;
        arg_sp2E8 = (f64) arg_sp108;
        arg_sp1C = 0.0f;
        if (Tools_Line2DToCircleIntersect(*((MKVector3 *) &this->unk588), *((MKVector3 *) &arg_sp2E0), *((MKVector3 *) &this->unk5B8), 2750.0f, arg_sp1C) != 0) {
            temp_f1_3582 = (f64) M2C_FIELD(this, f32 *, 0x590);
            arg_spF0 = (f64) M2C_FIELD(this, f32 *, 0x588);
            arg_spF4 = this->unk5B8;
            arg_spF8 = temp_f1_3582;
            arg_sp2D0 = arg_spF0;
            arg_sp2D8 = temp_f1_3582;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f3, $f31 */);
            temp_f4_3597 = (f32) arg_sp2E8 * arg_sp1C;
            arg_sp190 = arg_spE0;
            arg_spE8 = temp_f4_3597;
            arg_sp198 = (f64) arg_spE8;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            arg_sp1A0 = arg_spD0;
            arg_spD8 = (f32) arg_sp198 * 0.35f;
            arg_sp1A8 = (f64) arg_spD8;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f3, $f3, $f29 */);
            arg_sp2C0 = arg_spC0;
            arg_spC8 = (f32) arg_sp2D8 + (f32) arg_sp1A8;
            arg_sp2C8 = (f64) arg_spC8;
            arg_spB8 = temp_f4_3597;
            arg_sp180 = arg_spB0;
            arg_sp188 = (f64) arg_spB8;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            arg_sp2B0 = arg_spA0;
            arg_spA8 = (f32) arg_sp2D8 + (f32) arg_sp188;
            arg_sp2C4 += 650.0f;
            arg_sp2B8 = (f64) arg_spA8;
            arg_sp2B4 += 500.0f;
            arg_sp170.GetPos();
            this->unkD30 = arg_sp170;
            this->unkD38 = arg_sp178;
            M2C_FIELD(this, f32 *, 0xD4C) = (f32) (M2C_FIELD(this, f32 *, 0xD4C) + 300.0f);
            this->unkD10 = arg_sp2C0;
            this->unkD18 = arg_sp2C8;
            this->unkD20 = arg_sp2B0;
            this->unkD28 = arg_sp2B8;
        }
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp38'
void Cynder::CheckAnimEvents() {
    MKCollisionResult sp108;
    MKVector3 spF8;
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
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    s32 var_r29_3762;

    if (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(0xD) != 0) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unkD98, &spF8);
        sp48 = 0.0f;
        sp4C = -200.0f;
        sp50 = 0.0f;
        spB8 = (f64) sp48;
        spC0 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
        sp70 = 0.0f;
        sp68 = 0.0f;
        sp6C = 200.0f;
        sp40 = spF8.unk8 + (f32) spC0;
        spD8 = (f64) sp68;
        spC8 = sp38;
        spD0 = (f64) sp40;
        spE0 = (f64) sp70;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
        spE8 = sp58;
        sp60 = spF8.unk8 + (f32) spE0;
        spF0 = (f64) sp60;
        if (MKCollision_RayCollide(*((MKVector3 *) &spE8), *((MKVector3 *) &spC8), &sp108, (MKCollisionMode) 7, 0x0C000000) != 0) {
            var_r29_3762 = 0;
            do {
                sp30 = -1.0f;
                sp20 = 1.0f;
                sp28 = -1.0f;
                sp2C = 1.0f;
                sp18 = 1.0f;
                sp1C = 2.0f;
                sp88 = (f64) sp28;
                sp90 = (f64) sp30;
                sp78 = (f64) sp18;
                sp80 = (f64) sp20;
                KDRand_Vector(sp98, *((MKVector3 *) &sp88));
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                spA8 = sp8;
                sp10 = sp98.unk8 * 1000.0f;
                spB0 = (f64) sp10;
                ((ElectricSparks *) (M2C_FIELD(&gb, ElectricSparks **, 0x230)))->Emit(*((MKVector3 *) &sp108), *((MKVector3 *) &spA8), MKRand_Float(&gViewSeed, 0.5f, 1.0f), 0U);
                var_r29_3762 += 1;
            } while (var_r29_3762 < 0xA);
        }
    } else {
        Enemy::CheckAnimEvents();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'GetEnemySetting'
void Cynder::UpdatePhrasesAndSounds() {
    EnemyAttack *temp_r3_3840;
    MKVector3 *temp_r30_4010;
    f32 temp_f1_3977;
    f32 temp_f1_4045;
    f32 temp_f1_4099;
    f32 temp_f30_3847;
    f32 temp_f31_3851;
    f32 temp_f31_3866;
    s32 var_r29_3872;
    s32 var_r30_3873;
    void **temp_r3_3928;
    void **temp_r3_3936;
    void **temp_r3_3944;
    void **temp_r3_3984;
    void **temp_r3_3992;
    void **temp_r3_4000;

    temp_r3_3840 = this->unkA20;
    temp_f30_3847 = this->unkAB0;
    temp_f31_3851 = (f32) M2C_FIELD(temp_r3_3840, s32 *, 0x11C) * this->unkA20->GetEnemySetting((EnemySettingType) 0);
    temp_f31_3866 = ((temp_f31_3851 - ((f32) (M2C_BITWISE(s32, this->unkAD0) + 1) * temp_r3_3840->GetEnemySetting((EnemySettingType) 0))) + temp_f30_3847) / temp_f31_3851;
    if (temp_f31_3866 > M2C_FIELD(this, f32 *, 0xD64)) {
        M2C_FIELD(this, f32 *, 0xD64) = temp_f31_3866;
    }
    var_r29_3872 = 0;
    var_r30_3873 = 0;
loop_3:
    if ((temp_f31_3866 != 0.0f) && (*(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_3873 + 0x2D4)) != 0.0f) && (M2C_FIELD(this, f32 *, 0xD64) > *(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_3873 + 0x2D4))) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f31_3866 == *(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_3873 + 0x2D4))) != 0))) {
        M2C_FIELD(this, f32 *, 0xD68) = (f32) M2C_FIELD(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x3B4);
        M2C_FIELD(this, s8 **, 0xD60) = (s8 *) (checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_3873 + 0x2B4));
    } else {
        var_r29_3872 += 1;
        var_r30_3873 += 0x24;
        if (var_r29_3872 < 7) {
            goto loop_3;
        }
    }
    if ((M2C_FIELD(this, f32 *, 0xD68) < 0.0f) && ((s8 *) M2C_FIELD(this, s8 **, 0xD60) != NULL) && (KDSound_IsVoicePlaying(M2C_FIELD(this, s32 *, 0xD5C)) == 0) && (PhrasePlayer_IsAnyEventPlaying() == 0)) {
        temp_r3_3928 = this->unkA28;
        if ((M2C_FIELD(*temp_r3_3928, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3928, 0xA4) == 0) && (temp_r3_3936 = this->unkA28, ((M2C_FIELD(*temp_r3_3936, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3936, 0xAC) == 0) != 0)) && (temp_r3_3944 = this->unkA28, ((M2C_FIELD(*temp_r3_3944, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3944, 0xC2) == 0) != 0))) {
            M2C_FIELD(this, s32 *, 0xD58) = PhrasePlayer_PlayEvent(M2C_FIELD(this, s8 **, 0xD60));
            M2C_FIELD(this, f32 *, 0xD68) = 0.0f;
            M2C_FIELD(this, s8 **, 0xD60) = NULL;
        } else {
            M2C_FIELD(this, f32 *, 0xD68) = (f32) M2C_FIELD(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x3B4);
        }
    }
    if ((PhrasePlayer_IsAnyEventPlaying() == 0) && (temp_f31_3866 < M2C_FIELD(this, f32 *, 0xD64)) && (KDSound_IsVoicePlaying(M2C_FIELD(this, s32 *, 0xD5C)) == 0) && ((temp_f1_3977 = M2C_FIELD(this, f32 *, 0xD68), ((temp_f1_3977 == 0.0f) != 0)) || (temp_f1_3977 > 0.85f))) {
        temp_r3_3984 = this->unkA28;
        if (M2C_FIELD(*temp_r3_3984, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3984, 0xA4) == 0) {
            temp_r3_3992 = this->unkA28;
            if (M2C_FIELD(*temp_r3_3992, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3992, 0xAC) == 0) {
                temp_r3_4000 = this->unkA28;
                if (M2C_FIELD(*temp_r3_4000, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4000, 0xC2) == 0) {
                    temp_r30_4010 = this->unk8 + 0x30;
                    M2C_FIELD(this, s32 *, 0xD5C) = KDSound_Play3d(M2C_FIELD(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x3B0), temp_r30_4010, 0U, -1, 0.0f, 0U);
                }
            }
        }
    }
    if (((((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(0x10) != 0) || (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(0x16) != 0) || (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(0x14) != 0)) && (KDSound_IsVoicePlaying(M2C_FIELD(this, s32 *, 0xD5C)) == 0) && (PhrasePlayer_IsAnyEventPlaying() == 0) && ((temp_f1_4045 = M2C_FIELD(this, f32 *, 0xD68), ((temp_f1_4045 == 0.0f) != 0)) || (temp_f1_4045 > 0.85f))) {
        if (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(0x10) != 0) {
            M2C_FIELD(this, s32 *, 0xD5C) = KDSound_Play3d(GS_CynderTaunt, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        }
        if (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(0x16) != 0) {
            M2C_FIELD(this, s32 *, 0xD5C) = KDSound_Play3d(GS_CynderMelee2, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        }
        if (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(0x14) != 0) {
            M2C_FIELD(this, s32 *, 0xD5C) = KDSound_Play3d(GS_CynderExtra1, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        }
    }
    M2C_FIELD(this, f32 *, 0xD64) = temp_f31_3866;
    temp_f1_4099 = M2C_FIELD(this, f32 *, 0xD68);
    if (temp_f1_4099 > 0.0f) {
        M2C_FIELD(this, f32 *, 0xD68) = (f32) (temp_f1_4099 - gUpdateTimeDelta);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp30'
void Cynder::UpdateMovementCustom() {
    f64 temp_f2_4130;
    f64 temp_f3_4129;
    temp_f3_4129 = M2C_FIELD(this, f64 *, 0x598);
    temp_f2_4130 = M2C_FIELD(this, f64 *, 0x5A0);
    arg_sp30 = temp_f3_4129;
    arg_sp38 = temp_f2_4130;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
    this->unk588.unk4 += (f32) arg_sp38;
    this->unk100 = temp_f3_4129;
    this->unk108 = temp_f2_4130;
    M2C_STRUCT_COPY((s32) &arg_sp3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    if ((u8) M2C_FIELD(this, u8 *, 0xD02) != 0) {
        UpdateFlyingRotation((Matrix *) &arg_sp40);
        arg_sp10 = -arg_sp60;
        arg_sp14 = -arg_sp64;
        arg_sp18 = -arg_sp68;
        M2C_FIELD(this, f64 *, 0xE0) = (f64) arg_sp10;
        M2C_FIELD(this, f64 *, 0xE8) = (f64) arg_sp18;
        arg_sp20 = (f64) arg_sp10;
        M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(this, f64 *, 0xE0);
        M2C_FIELD(this, f64 *, 0xC8) = (f64) M2C_FIELD(this, f64 *, 0xE8);
        arg_sp28 = (f64) arg_sp18;
        this->unk6B5 &= ~0x40;
        M2C_FIELD(this, f64 *, 0xF0) = arg_sp50;
        M2C_FIELD(this, f64 *, 0xF8) = arg_sp58;
        M2C_FIELD(this, f64 *, 0xD0) = (f64) M2C_FIELD(this, f64 *, 0xF0);
        M2C_FIELD(this, f64 *, 0xD8) = (f64) M2C_FIELD(this, f64 *, 0xF8);
        this->unk6B5 &= ~0x40;
        arg_sp70 = this->unk588;
        arg_sp74 = this->unk588.unk0;
        arg_sp78 = this->unk588.unk4;
        arg_sp7C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp40));
        return;
    }
    UpdateRotation();
    UpdateModel();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp5C'
void Cynder::EnableFlyingRotation(bool arg0) {
    M2C_FIELD(this, u8 *, 0xD02) = arg0;
    if ((u8) M2C_FIELD(this, u8 *, 0xD02) != 0) {
        M2C_STRUCT_COPY((s32) &arg_sp5C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        arg_sp20 = -arg_sp60;
        arg_sp24 = -arg_sp64;
        arg_sp28 = -arg_sp68;
        arg_sp18 = -arg_sp88;
        arg_sp50 = (f64) arg_sp20;
        arg_sp58 = (f64) arg_sp28;
        arg_sp48 = (f64) arg_sp18;
        arg_sp10 = -arg_sp80;
        arg_sp14 = -arg_sp84;
        arg_sp60 = (f32) arg_sp50;
        arg_sp40 = (f64) arg_sp10;
        arg_sp64 = arg_sp54;
        arg_sp68 = (f32) arg_sp58;
        arg_sp6C = 0.0f;
        arg_sp80 = (f32) arg_sp40;
        arg_sp84 = arg_sp44;
        arg_sp88 = (f32) arg_sp48;
        arg_sp8C = 0.0f;
        arg_sp30.GetRotationRPY();
        M2C_FIELD(this, f64 *, 0xD08) = arg_sp30;
        M2C_FIELD(this, f64 *, 0xD10) = arg_sp38;
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void Cynder::UpdateFlyingRotation(Matrix *arg0) {
    f32 temp_f0_4767;
    f32 temp_f26_4723;
    f32 temp_f6_4738;
    f32 temp_f7_4729;
    f32 var_f0_4369;
    f32 var_f25_4705;
    f32 var_f25_4766;
    f32 var_f3_4642;
    f32 var_f3_4743;
    f32 var_f4_4575;
    f32 var_f6_4417;
    f64 temp_f1_4581;
    f64 temp_f1_4587;
    f64 temp_f1_4591;
    f64 temp_f3_4433;
    f64 temp_f3_4439;
    f64 temp_f3_4443;
    s32 temp_r3_4462;
    s32 temp_r3_4610;
    s32 var_r0_4472;
    s32 var_r0_4620;
    u8 var_r31_4335;
    var_r31_4335 = 0;
    if (((u8) M2C_FIELD(this, u8 *, 0x908) == 2) || (this->unk8C0.unk30.Get() != NULL)) {
        var_r31_4335 = 1;
    }
    if (var_r31_4335 != 0) {
        this->unk870.unk40.Update(*((MKVector3 *) &this->unk588));
        M2C_STRUCT_COPY((s32) &arg_sp2CC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        var_f0_4369 = 0.0f;
        arg_sp68 = -arg_sp2F0;
        arg_sp6C = -arg_sp2F4;
        arg_sp70 = -arg_sp2F8;
        arg_sp168 = (f64) arg_sp68;
        arg_sp170 = (f64) arg_sp70;
        arg_sp80 = -arg_sp2D8;
        arg_spD8 = (MKVector3::up.unk4 * (f32) arg_sp170) - (MKVector3::up.unk8 * arg_sp16C);
        arg_sp180 = (f64) arg_sp80;
        arg_spDC = (MKVector3::up.unk8 * (f32) arg_sp168) - (MKVector3::up.unk0 * (f32) arg_sp170);
        arg_spE0 = (MKVector3::up.unk0 * arg_sp16C) - (MKVector3::up.unk4 * (f32) arg_sp168);
        arg_sp158 = (f64) arg_spD8;
        arg_sp160 = (f64) arg_spE0;
        arg_sp78 = -arg_sp2D0;
        arg_sp7C = -arg_sp2D4;
        var_f6_4417 = ((f32) arg_sp160 * (f32) arg_sp160) + (((f32) arg_sp158 * (f32) arg_sp158) + (arg_sp15C * arg_sp15C));
        arg_sp2D8 = (f32) arg_sp180;
        arg_sp178 = (f64) arg_sp78;
        arg_sp2D0 = (f32) arg_sp178;
        arg_sp2D4 = arg_sp17C;
        arg_sp2DC = 0.0f;
        arg_sp2F0 = (f32) arg_sp168;
        arg_sp2F4 = arg_sp16C;
        arg_sp2F8 = (f32) arg_sp170;
        arg_sp2FC = 0.0f;
        if (var_f6_4417 > 1e-12f) {
            if (var_f6_4417 > 0.0f) {
                temp_f3_4433 = __frsqrte(var_f6_4417);
                temp_f3_4439 = 0.5 * temp_f3_4433 * -(((f64) var_f6_4417 * (temp_f3_4433 * temp_f3_4433)) - 3.0);
                temp_f3_4443 = 0.5 * temp_f3_4439 * -(((f64) var_f6_4417 * (temp_f3_4439 * temp_f3_4439)) - 3.0);
                var_f6_4417 = (f32) ((f64) var_f6_4417 * (0.5 * temp_f3_4443 * -(((f64) var_f6_4417 * (temp_f3_4443 * temp_f3_4443)) - 3.0)));
            } else if (var_f6_4417 < M2C_BITWISE(f32, 0.0)) {
                var_f6_4417 = __float_nan;
            } else {
                arg_sp14 = var_f6_4417;
                temp_r3_4462 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                switch (temp_r3_4462) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_4472 = 1;
                    } else {
                        var_r0_4472 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_4472 = 5;
                    } else {
                        var_r0_4472 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_4472 = 4;
                    break;
                }
                if (var_r0_4472 == 1) {
                    var_f6_4417 = __float_nan;
                }
            }
            var_f0_4369 = 1.0f / var_f6_4417;
        }
        arg_spCC = arg_sp15C * var_f0_4369;
        arg_spC8 = (f32) arg_sp158 * var_f0_4369;
        arg_spD0 = (f32) arg_sp160 * var_f0_4369;
        arg_sp1B8 = (f64) arg_spC8;
        arg_sp1C0 = (f64) arg_spD0;
        arg_spB8 = -(f32) arg_sp1B8;
        arg_spBC = -arg_sp1BC;
        arg_spC0 = -(f32) arg_sp1C0;
        arg_sp148 = (f64) arg_spB8;
        arg_sp150 = (f64) arg_spC0;
        arg_spA8 = (MKVector3::up.unk4 * (f32) arg_sp150) - (MKVector3::up.unk8 * arg_sp14C);
        arg_spAC = (MKVector3::up.unk8 * (f32) arg_sp148) - (MKVector3::up.unk0 * (f32) arg_sp150);
        arg_spB0 = (MKVector3::up.unk0 * arg_sp14C) - (MKVector3::up.unk4 * (f32) arg_sp148);
        arg_sp1A8 = (f64) arg_spA8;
        arg_sp1B0 = (f64) arg_spB0;
        arg_sp138.GetDir();
        arg_sp198 = arg_sp138;
        arg_sp1A0 = arg_sp140;
        arg_sp98 = (MKVector3::up.unk4 * (f32) arg_sp1A0) - (MKVector3::up.unk8 * arg_sp19C);
        arg_sp9C = (MKVector3::up.unk8 * (f32) arg_sp198) - (MKVector3::up.unk0 * (f32) arg_sp1A0);
        arg_spA0 = (MKVector3::up.unk0 * arg_sp19C) - (MKVector3::up.unk4 * (f32) arg_sp198);
        arg_sp128 = (f64) arg_sp98;
        arg_sp130 = (f64) arg_spA0;
        var_f4_4575 = ((f32) arg_sp130 * (f32) arg_sp130) + (((f32) arg_sp128 * (f32) arg_sp128) + (arg_sp12C * arg_sp12C));
        if (var_f4_4575 > 1e-12f) {
            if (var_f4_4575 > 0.0f) {
                temp_f1_4581 = __frsqrte(var_f4_4575);
                temp_f1_4587 = 0.5 * temp_f1_4581 * -(((f64) var_f4_4575 * (temp_f1_4581 * temp_f1_4581)) - 3.0);
                temp_f1_4591 = 0.5 * temp_f1_4587 * -(((f64) var_f4_4575 * (temp_f1_4587 * temp_f1_4587)) - 3.0);
                var_f4_4575 = (f32) ((f64) var_f4_4575 * (0.5 * temp_f1_4591 * -(((f64) var_f4_4575 * (temp_f1_4591 * temp_f1_4591)) - 3.0)));
            } else if (var_f4_4575 < M2C_BITWISE(f32, 0.0)) {
                var_f4_4575 = __float_nan;
            } else {
                arg_sp10 = var_f4_4575;
                temp_r3_4610 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_4610) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_4620 = 1;
                    } else {
                        var_r0_4620 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_4620 = 5;
                    } else {
                        var_r0_4620 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_4620 = 4;
                    break;
                }
                if (var_r0_4620 == 1) {
                    var_f4_4575 = __float_nan;
                }
            }
            var_f3_4642 = 1.0f / var_f4_4575;
        } else {
            var_f3_4642 = 0.0f;
        }
        arg_sp8C = arg_sp12C * var_f3_4642;
        arg_sp88 = (f32) arg_sp128 * var_f3_4642;
        arg_sp90 = (f32) arg_sp130 * var_f3_4642;
        arg_sp188 = (f64) arg_sp88;
        arg_sp190 = (f64) arg_sp90;
        arg_sp28 = -(f32) arg_sp188;
        arg_sp2C = -arg_sp18C;
        arg_sp30 = -(f32) arg_sp190;
        arg_sp108 = (f64) arg_sp28;
        arg_sp110 = (f64) arg_sp30;
        arg_sp58 = (MKVector3::up.unk4 * (f32) arg_sp110) - (MKVector3::up.unk8 * arg_sp10C);
        arg_sp5C = (MKVector3::up.unk8 * (f32) arg_sp108) - (MKVector3::up.unk0 * (f32) arg_sp110);
        arg_sp60 = (MKVector3::up.unk0 * arg_sp10C) - (MKVector3::up.unk4 * (f32) arg_sp108);
        arg_sp188 = (f64) arg_sp58;
        arg_sp190 = (f64) arg_sp60;
        arg_sp118 = (f64) arg_sp58;
        arg_sp120 = (f64) arg_sp60;
        var_f25_4705 = ((f32) arg_sp190 * (f32) arg_sp1A0) + (((f32) arg_sp188 * (f32) arg_sp198) + (arg_sp18C * arg_sp19C));
        if (var_f25_4705 < 1.0f) {

        } else {
            var_f25_4705 = 1.0f;
        }
        if (var_f25_4705 > -1.0f) {

        } else {
            var_f25_4705 = -1.0f;
        }
        temp_f26_4723 = KDMath_GetYaw(*((MKVector3 *) &arg_sp188)) - 3.1415927f;
        temp_f7_4729 = (f32) acos(var_f25_4705);
        temp_f6_4738 = 1.0f - (((f32) arg_sp1B0 * (f32) arg_sp190) + (((f32) arg_sp1A8 * (f32) arg_sp188) + (arg_sp1AC * arg_sp18C)));
        var_f3_4743 = 1.0f;
        arg_sp20 = ((f32) arg_sp1A0 * MKVector3::up.unk8) + (((f32) arg_sp198 * MKVector3::up.unk0) + (arg_sp19C * MKVector3::up.unk4));
        arg_sp18 = ((f32) arg_sp1C0 * (f32) arg_sp190) + (((f32) arg_sp1B8 * (f32) arg_sp188) + (arg_sp1BC * arg_sp18C));
        arg_sp24 = (M2C_BITWISE(s32, arg_sp20) & 0x80000000) | 0x3F800000;
        arg_sp1C = (M2C_BITWISE(s32, arg_sp18) & 0x80000000) | 0x3F800000;
        if (var_f3_4743 < temp_f6_4738) {

        } else {
            var_f3_4743 = temp_f6_4738;
        }
        var_f25_4766 = 1.0f;
        temp_f0_4767 = 1.570796f * var_f3_4743;
        if (var_f25_4766 < temp_f0_4767) {

        } else {
            var_f25_4766 = temp_f0_4767;
        }
        KDMath_SmoothToAngle(M2C_BITWISE(f32, this->unkCF4), temp_f26_4723, 2.1991148f * gUpdateTimeDelta);
        this->unkCF4 = M2C_ERROR(/* Read from unset register $f1 */);
        KDMath_SmoothToAngle(M2C_BITWISE(f32, this->unkCF0), temp_f7_4729 * M2C_BITWISE(f32, arg_sp24), 2.1991148f * gUpdateTimeDelta);
        this->unkCF0 = M2C_ERROR(/* Read from unset register $f1 */);
        KDMath_SmoothToAngle(M2C_BITWISE(f32, this->unkCF8), -M2C_BITWISE(f32, arg_sp1C) * (1.5707964f * var_f25_4766), 2.1991148f * gUpdateTimeDelta);
        this->unkCF8 = M2C_ERROR(/* Read from unset register $f1 */);
        M2C_STRUCT_COPY((s32) &arg_sp1CC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        M2C_STRUCT_COPY((s32) &arg_sp28C + 4, (s32) &arg_sp1CC + 4, 0x40);
        M2C_STRUCT_COPY((s32) &arg_sp24C + 4, (s32) &arg_sp1CC + 4, 0x40);
        M2C_STRUCT_COPY((s32) &arg_sp20C + 4, (s32) &arg_sp1CC + 4, 0x40);
        arg_sp290.RotatePitch((Matrix *) &arg_sp290, M2C_BITWISE(f32, this->unkCF0));
        arg_sp250.RotateRoll((Matrix *) &arg_sp250, -M2C_BITWISE(f32, this->unkCF8));
        arg_sp210.RotateYaw((Matrix *) &arg_sp210, M2C_BITWISE(f32, this->unkCF4));
        arg_sp210.Multiply3x3((Matrix *) &arg_sp290, (Matrix *) &arg_sp210);
        arg_sp210.Multiply3x3((Matrix *) &arg_sp250, (Matrix *) &arg_sp210);
        arg_sp48 = -arg_sp210;
        arg_sp4C = -arg_sp214;
        arg_sp50 = -arg_sp218;
        arg_sp40 = -arg_sp238;
        arg_spF8 = (f64) arg_sp48;
        arg_sp100 = (f64) arg_sp50;
        arg_spF0 = (f64) arg_sp40;
        arg_sp38 = -arg_sp230;
        arg_sp3C = -arg_sp234;
        arg_sp210 = (f32) arg_spF8;
        arg_spE8 = (f64) arg_sp38;
        arg_sp214 = arg_spFC;
        arg_sp218 = (f32) arg_sp100;
        arg_sp21C = 0.0f;
        arg_sp230 = (f32) arg_spE8;
        arg_sp234 = arg_spEC;
        arg_sp238 = (f32) arg_spF0;
        arg_sp23C = 0.0f;
        M2C_STRUCT_COPY((s32) (arg0 - 4) + 4, (s32) &arg_sp20C + 4, 0x40);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void Cynder::UpdateLookAtNodes() {
    EnemyDescriptor *temp_r3_5003;
    s32 var_r30_5019;
    s32 var_r30_5031;
    s32 var_r31_5020;
    s32 var_r31_5032;
    u8 var_r31_4946;
    u8 var_r31_4963;

    if (M2C_BITWISE(s32, this->unkAD0) == 2) {
        var_r31_4946 = 0;
        if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk30.Get() != NULL)) {
            var_r31_4946 = 1;
        }
        if (var_r31_4946 == 0) {
            goto block_5;
        }
        goto block_12;
    }
block_5:
    if ((u8) M2C_FIELD(this, u8 *, 0xD00) == 0) {
        var_r31_4963 = 0;
        if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk30.Get() != NULL)) {
            var_r31_4963 = 1;
        }
        if ((var_r31_4963 != 0) && (this->unk838.unk28.GetDist() < 4000.0f) && !(((u8) this->unk6B5 >> 4U) & 1)) {
            goto block_12;
        }
        var_r30_5031 = 0;
        var_r31_5032 = 0;
        do {
            ((NodeLookAtIK *) (this + (var_r31_5032 + 0xB10)))->Update(NULL);
            var_r30_5031 += 1;
            var_r31_5032 += 0x48;
        } while (var_r30_5031 < 6);
        return;
    }
block_12:
    if ((u8) M2C_FIELD(this, u8 *, 0xD00) != 0) {
        this->unkC30.unk30 = 10.0f;
        this->unkC30.unk3C = 0.0f;
    } else {
        this->unkC30.unk30 = 5.0f;
        M2C_FIELD(this->unk870.unk30.Get()->__vptr, M2C_UNK (**)(f32 *, u8 *), 0x28)(&this->unk588, &this->unk6C0.unk38);
        temp_r3_5003 = this->unkA38;
        if ((temp_r3_5003 != NULL) && ((s32) temp_r3_5003->unk6C == 5)) {
            this->unkC30.unk3C = 0.0f;
        } else {
            this->unkC30.unk3C = 0.5235987f;
        }
    }
    this->unkC30.unk30.Update((MKVector3 *) &this->unk6C0.unk38);
    var_r30_5019 = 4;
    var_r31_5020 = 0x120;
    do {
        ((NodeLookAtIK *) (this + (var_r31_5020 + 0xB10)))->Update(NULL);
        var_r30_5019 -= 1;
        var_r31_5020 -= 0x48;
    } while (var_r30_5019 >= 0);
}
#endif

void Cynder::Update() {
    s32 sp8;

    Enemy::Update();
    UpdateLookAtNodes();
    UpdateEffects();
    UpdatePhrasesAndSounds();
    sp8 = 1;
    ((KDSoundFader *) (this + 0xD6C))->Update(GS_CynderFuryPurpleLP, 1U, this->unkD94, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if (((u8) M2C_FIELD(&gb, u8 *, 0x35D) != 0) && ((u8) M2C_FIELD(this, u8 *, 0xF20) == 0) && ((void **) M2C_FIELD(&gb, void ***, 0) != NULL) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(), 0x70)() != 0)) {
        M2C_FIELD(this, u8 *, 0xF20) = 1U;
        this->unkEE8.Send((MKProp *) this);
    }
}

#if 0 // DRAFT: undefined identifier 'unkD1C'
void Cynder::SetDefaults() {
    Enemy::SetDefaults();
    if ((u8) M2C_FIELD(this, u8 *, 0xD01) != 0) {
        this->unkAD0 = 0.0f;
    } else {
        this->unkAD0 = 1e-45f;
    }
    this->unkCDC = 0.0f;
    this->unkCFC = 0;
    M2C_FIELD(this, s8 *, 0xD00) = 0;
    M2C_FIELD(this, f32 *, 0xD18) = 0.0f;
    this->unkD1C = 0.0f;
    M2C_FIELD(this, f32 *, 0xD20) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD28) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD2C) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD30) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD38) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD3C) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD40) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD48) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD4C) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD50) = 0.0f;
    memset(&this->unkF88, 0, 0x60U);
    this->unkF7C = 0.0f;
    M2C_FIELD(this, f32 *, 0xF98) = 0.0f;
    M2C_FIELD(this, s8 *, 0xF18) = 0;
    M2C_FIELD(this, s8 *, 0xF19) = 1;
    M2C_FIELD(this, s8 *, 0xF1A) = 0;
    M2C_FIELD(this, s8 *, 0xF1B) = 1;
    M2C_FIELD(this, s8 *, 0xF1C) = 1;
    M2C_FIELD(this, s8 *, 0xF1D) = 0;
    M2C_FIELD(this, s8 *, 0xF1E) = 0;
    M2C_FIELD(this, s8 *, 0xF1F) = 0;
    M2C_FIELD(this, s8 *, 0xF20) = 0;
    this->unkF74 = 0.0f;
    this->unkF70 = 0.0f;
    this->unkF0C.unk0 = 8;
    this->unkEFC.unk0 = 0.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp18'
void Cynder::UpdateCollisionItems() {
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp20;
    f32 sp10;
    f32 temp_f2_5190;
    f32 temp_f2_5217;

    sp48.operator*(300.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    temp_f2_5190 = this->unk588.unk4;
    this->unk60 = sp18;
    sp20 = temp_f2_5190 + sp48.unk8;
    sp58 = sp18;
    this->unk68 = (f64) sp20;
    sp60 = (f64) sp20;
    M2C_FIELD(this, f32 *, 0x64) = (f32) (M2C_FIELD(this, f32 *, 0x64) + GetCollisionRadius(sp18, temp_f2_5190));
    sp28.operator*(300.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    temp_f2_5217 = this->unk588.unk4;
    this->unk70 = sp8;
    sp10 = temp_f2_5217 - sp28.unk8;
    sp38 = sp8;
    this->unk78 = (f64) sp10;
    sp40 = (f64) sp10;
    M2C_FIELD(this, f32 *, 0x74) = (f32) (M2C_FIELD(this, f32 *, 0x74) + GetCollisionRadius(sp8, temp_f2_5217));
}
#endif

#if 0 // DRAFT: function call 'GetCollisionRadius(Enemy *, double, double, double)' does
void Cynder::SetupCollision() {
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
    f32 temp_f31_5281;
    void *temp_r31_5258;

    UpdateCollisionItems();
    temp_r31_5258 = checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp20 = 1.0f;
    sp24 = 1.0f;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    temp_f31_5281 = GetCollisionRadius((f64) sp18, (f64) sp10, (f64) sp8);
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddCapsule((MKVector3 *) &this->unk60, (MKVector3 *) &this->unk70, temp_f31_5281, *((MKVector4 *) &sp38), *((MKVector4 *) &sp28), (MKCollisionMode) 2, this->unk634, M2C_FIELD(temp_r31_5258, u32 *, 0x70));
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void *' to
void Cynder::Resolve() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    FireBombFX *temp_r3_5356;
    f32 temp_r4_5341;
    s32 var_r30_5350;

    Enemy::Resolve();
    sp20 = 0.0f;
    sp8 = 1.0f;
    spC = 0.0f;
    sp10 = 0.5f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    this->unkF14 = M2C_BITWISE(f32, ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(*((MKVector3 *) &sp38), *((MKVector4 *) &sp28), 1.0f, lit_897, lit_898));
    temp_r4_5341 = this->unkF14;
    if (M2C_BITWISE(u32, temp_r4_5341) != 0U) {
        M2C_FIELD(temp_r4_5341, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_5341, u8 *, 0x31) & ~0x40);
    }
    var_r30_5350 = 0;
    do {
        temp_r3_5356 = checked_cast<FireBombFX *, MKProp>(gMK->CreateProp("CynderFireBomb"));
        if (temp_r3_5356 != NULL) {
            M2C_FIELD(temp_r3_5356->__vptr, M2C_UNK (**)(), 0x34)();
        }
        var_r30_5350 += 1;
    } while (var_r30_5350 < 8);
    this->unkCD8 = checked_cast<FireBombFXDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, s8 *), 0x5C)(gMK, "CynderFireBomb"));
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Cynder::LoadDone() {
    f64 sp8;
    CynderBossGoal_Think *temp_r30_5434;
    CynderConcurrentGoal_Think *temp_r30_5399;
    s32 temp_r0_5578;
    s32 temp_r0_5583;
    s32 temp_r0_5601;
    s32 temp_r4_5579;
    s32 var_ctr_5549;
    s32 var_ctr_5576;
    s32 var_ctr_5599;
    s32 var_r3_5547;
    s32 var_r3_5574;
    s32 var_r3_5598;
    s32 var_r7_5546;
    s32 var_r7_5573;
    void *temp_r3_5635;
    void *temp_r4_5552;
    void *temp_r4_5562;
    void *temp_r6_5551;

    Enemy::LoadDone();
    if ((u8) M2C_FIELD(this, u8 *, 0xD01) != 0) {
        operator new(0x30U, NULL, 0);
        temp_r30_5399 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r30_5399 != NULL) {
            temp_r30_5399->__vptr = &__vt__13Goal<6Cynder>;
            temp_r30_5399->unk4 = 0;
            temp_r30_5399->unk8 = 1;
            temp_r30_5399->unk9 = 0;
            temp_r30_5399->unkC = 0;
            temp_r30_5399->__vptr = (struct __vt__13Goal<6Cynder> *) &__vt__22CompositeGoal<6Cynder>;
            temp_r30_5399->unk1C = 0;
            temp_r30_5399->unk18 = 0;
            temp_r30_5399->unk10 = 0;
            temp_r30_5399->unk14 = 0;
            temp_r30_5399->__vptr = &__vt;
        }
        temp_r30_5399->Init(this);
        this->unkA24 = (EnemyAttack *) temp_r30_5399;
        M2C_FIELD(this->unkA20, f32 *, 0xE8) = 200.0f;
    } else {
        operator new(0x4CU, NULL, 0);
        temp_r30_5434 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r30_5434 != NULL) {
            temp_r30_5434->__vptr = &__vt__13Goal<6Cynder>;
            temp_r30_5434->unk4 = 0;
            temp_r30_5434->unk8 = 1;
            temp_r30_5434->unk9 = 0;
            temp_r30_5434->unkC = NULL;
            temp_r30_5434->__vptr = (struct __vt__13Goal<6Cynder> *) &__vt__22CompositeGoal<6Cynder>;
            temp_r30_5434->unk1C = NULL;
            temp_r30_5434->unk18 = 0;
            temp_r30_5434->unk10 = 0;
            temp_r30_5434->unk14 = 0;
            temp_r30_5434->__vptr = &__vt;
        }
        temp_r30_5434->Init(this);
        this->unkA24 = (EnemyAttack *) temp_r30_5434;
    }
    this->unkA28 = (void **) this->unkA24;
    if (!(this->unk680 & 0x160000)) {
        Disable();
    }
    this->unkCE8 = checked_cast<EarthShockwave *, MKProp>(gMK->CreateProp("EarthShockwave"));
    this->unkCD4 = checked_cast<CynderBreathFX *, MKProp>(gMK->CreateProp("CynderBreathFX"));
    SetHitList__14CynderBreathFXFP18MKPtrList<6MKProp>((CynderBreathFX *) this->unkCD4, (MKPtrList<MKProp> *) &this->unkA04);
    this->unkCF8 = (s32) Tools_GetMatchingNodeIndex(this->unk4, "Head");
    this->unkAF8.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck01"));
    this->unkB10.unk30.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck02"));
    this->unkB58.unk30.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck03"));
    this->unkBA0.unk30.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck04"));
    this->unkBE8.unk30.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck05"));
    this->unkC30.unk30.Init(this->unk4, this->unkCF8);
    var_r7_5546 = 1;
    var_r3_5547 = 0x48;
    var_ctr_5549 = 5;
    do {
        temp_r6_5551 = this + var_r3_5547;
        temp_r4_5552 = M2C_FIELD(temp_r6_5551, void **, 0xB50);
        if (temp_r4_5552 != NULL) {
            M2C_FIELD(temp_r4_5552, void **, 0x44) = NULL;
        }
        M2C_FIELD(temp_r6_5551, void **, 0xB50) = (void *) (this + (((var_r7_5546 - 1) * 0x48) + 0xB10));
        temp_r4_5562 = M2C_FIELD(temp_r6_5551, void **, 0xB50);
        if (temp_r4_5562 != NULL) {
            M2C_FIELD(temp_r4_5562, void **, 0x44) = (void *) (temp_r6_5551 + 0xB10);
        }
        var_r7_5546 += 1;
        var_r3_5547 += 0x48;
        var_ctr_5549 -= 1;
    } while (var_ctr_5549 != 0);
    var_r7_5573 = 0;
    var_r3_5574 = 0;
    var_ctr_5576 = 5;
    do {
        temp_r0_5578 = var_r7_5573 + 1;
        temp_r4_5579 = var_r7_5573 + 2;
        temp_r0_5583 = var_r3_5574 + 0xB28;
        var_r7_5573 += 1;
        var_r3_5574 += 0x48;
        *(this + temp_r0_5583) = (f32) temp_r0_5578 / (f32) temp_r4_5579;
        var_ctr_5576 -= 1;
    } while (var_ctr_5576 != 0);
    var_r3_5598 = 0;
    var_ctr_5599 = 6;
    do {
        temp_r0_5601 = var_r3_5598 + 0xB10;
        var_r3_5598 += 0x48;
        *(this + temp_r0_5601) = 5.0f;
        var_ctr_5599 -= 1;
    } while (var_ctr_5599 != 0);
    this->unkC30.unk3C = 0.5235987f;
    this->unkC30.unk40 = 2.8274333f;
    this->unkD98 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "Weapon06");
    this->unkD9C = (s32) Tools_GetMatchingNodeIndex(this->unk4, "Spine03");
    KDMath_GetDirection(this->unkEAC);
    M2C_FIELD(this, f64 *, 0xEA8) = sp8;
    M2C_FIELD(this, f64 *, 0xEB0) = sp10;
    temp_r3_5635 = this->unkA20->GetAnimSequence(0xA, 0x140, 0, NULL);
    if (temp_r3_5635 != NULL) {
        M2C_FIELD(this, f64 *, 0xEB8) = (f64) M2C_FIELD(temp_r3_5635, f64 *, 8);
        M2C_FIELD(this, f64 *, 0xEC0) = (f64) M2C_FIELD(temp_r3_5635, f64 *, 0x10);
    }
    this->unkF10.unk0 = checked_cast<SuckeyPS *, MKProp>(gMK->CreateProp("cynderFuryPowerupPS"));
    M2C_FIELD(this->unkF10.unk0, s8 **, 0x140) = &this->unkF18;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Cynder *' to
s32 Cynder::LoadLine(MKIniLine *arg0) {
    f32 var_f1_5865;
    s32 temp_ret_5865;
    s32 temp_ret_5886;
    s32 var_r27_5873;
    s32 var_r29_5875;

    if ((Enemy::LoadLine(arg0) != 0) || (arg0->LoadBool("bConcurrentSkies", this + 0xD01, 0) != 0) || (arg0->LoadInt("iNavPathID", (s32 *) &this->unkF60, 0) != 0) || (arg0->LoadVector3("vStage3StartPos", &this->unkE98, 0) != 0) || (arg0->LoadVector3("vStage3StartRot", (MKVector3 *) &this->unkEA8, 0) != 0) || (this->unkECC.LoadLine(arg0, "OnStage1End") != 0) || (this->unkEB8.LoadLine(arg0, "OnStage2End") != 0) || (((EventMessage *) (this + 0xED4))->LoadLine(arg0, "OnStage3End") != 0) || (this->unk1000.LoadLine(arg0, "OnConcurrentSkiesEnd") != 0) || (this->unkEB0.LoadLine(arg0, "OnReset") != 0) || (this->unkEC0.LoadLine(arg0, "Fury1a") != 0) || (this->unkEDC.LoadLine(arg0, "Fury1b") != 0) || (this->unkEC8.LoadLine(arg0, "Fury1c") != 0) || (this->unkECC.LoadLine(arg0, "Fury1d") != 0) || (this->unkED0.LoadLine(arg0, "Fury1e") != 0) || (this->unkED4.LoadLine(arg0, "Fury2a") != 0) || (this->unkED8.LoadLine(arg0, "Fury2b") != 0) || (this->unkEDC.LoadLine(arg0, "Fury2c") != 0) || (this->unkEE0.LoadLine(arg0, "Fury2d") != 0) || (this->unkEE4.LoadLine(arg0, "Fury2e") != 0) || (this->unkEE8.LoadLine(arg0, "SpyroFury1a") != 0) || (this->unkEEC.LoadLine(arg0, "SpyroFury1b") != 0) || (this->unkEF0.LoadLine(arg0, "SpyroFury1c") != 0) || (this->unkEF4.LoadLine(arg0, "SpyroFury1d") != 0) || (temp_ret_5865 = this->unkEF8.LoadLine(arg0, "SpyroFury1e"), var_f1_5865 = M2C_BITWISE(f32, temp_ret_5865), ((temp_ret_5865 == 0) == 0))) {
        return 1;
    }
    var_r27_5873 = 0;
    var_r29_5875 = 0;
loop_27:
    temp_ret_5886 = arg0->LoadInt(Str_Printf("iRegionID_0%d", var_r27_5873 + 1, var_f1_5865), this + (var_r29_5875 + 0xDA4), 0);
    var_f1_5865 = M2C_BITWISE(f32, temp_ret_5886);
    if (temp_ret_5886 != 0) {
        return 1;
    }
    var_r27_5873 += 1;
    var_r29_5875 += 4;
    if (var_r27_5873 >= 4) {
        return 0;
    }
    goto loop_27;
}
#endif

#if 0 // DRAFT: expression syntax error
void Cynder::Deinit() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    f32 temp_r4_5928;

    this->unkCC0.Deinit();
    this->unkCD4.Deinit();
    PhrasePlayer_StopEvent(M2C_FIELD(this, s32 *, 0xD58));
    KDSound_Stop(this + 0xD6C);
    ((ScreenWobbleFX *) ((ScreenWobbleFX *) (&gb + 0xB8)))->EnableSpeedEffect(0U, 1.0f, 1.0f);
    temp_r4_5928 = this->unkF14;
    if (M2C_BITWISE(u32, temp_r4_5928) != 0U) {
        ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(M2C_BITWISE(Corona *, temp_r4_5928));
        this->unkF14 = 0.0f;
    }
    if ((u8) M2C_FIELD(this, u8 *, 0xD01) == 0) {
        gb.GetSpyro();
        sp14 = 0;
        sp10 = 0xAA;
        M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x44), M2C_UNK (**)(), 0x2C)();
        gb.GetSpyro();
        spC = 0;
        sp8 = 0xAC;
        M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x44), M2C_UNK (**)(), 0x2C)();
        gb.GetSpyro();
        ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->UseCynderStrafeState(0U, 1U);
        gb.GetSpyro();
        ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetForceLookAtTarget(NULL);
        gb.GetSpyro();
        ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetAutoHealthRegen(0U);
    }
    Enemy::Deinit();
}
#endif

#if 0 // DRAFT: expression syntax error
void Cynder::Init() {
    s32 var_r28_6025;
    s32 var_r30_6027;
    s32 var_r31_6028;

    Enemy::Init();
    this->unkCC0.Init(0x21, 0U);
    this->unkCD4.Init(0xA, 0U);
    this->unkCD4 = 0;
    M2C_FIELD(this, s8 *, 0xD01) = 0;
    M2C_FIELD(this, s32 *, 0xD58) = 0;
    M2C_FIELD(this, s32 *, 0xD5C) = 0;
    M2C_FIELD(this, s32 *, 0xD60) = 0;
    M2C_FIELD(this, f32 *, 0xD64) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD68) = 0.0f;
    this->unkCF8 = 0xFFFF;
    ((KDSoundFader *) (this + 0xD6C))->Init(0.25f, 0.25f);
    var_r28_6025 = 0;
    this->unkD94 = 0;
    var_r30_6027 = 0;
    var_r31_6028 = 0;
    this->unkF60 = 0.0f;
    this->unkF64 = 0.0f;
    do {
        *(this + (var_r30_6027 + 0xDA4)) = 0;
        ((EnemyRegion *) (this + (var_r31_6028 + 0xDB8)))->Init();
        var_r28_6025 += 1;
        var_r30_6027 += 4;
        var_r31_6028 += 0x38;
    } while (var_r28_6025 < 4);
    this->unk1000.Init();
    this->unkE98.unk0 = 0.0f;
    this->unkE98.unk4 = 0.0f;
    this->unkE98.unk8 = 0.0f;
    this->unkEA8 = 0.0f;
    this->unkEAC = 0.0f;
    this->unkE98.unk0 = 0.0f;
    this->unkE98.unk8 = 0.0f;
    this->unkE98.unkC = 0.0f;
    this->unkEA8 = 0.0f;
    this->unkEB0.Init();
    this->unkECC.Init();
    this->unkEB8.Init();
    ((EventMessage *) (this + 0xED4))->Init();
    this->unkEC0.Init();
    this->unkEDC.Init();
    this->unkEC8.Init();
    this->unkECC.Init();
    this->unkED0.Init();
    this->unkED4.Init();
    this->unkED8.Init();
    this->unkEDC.Init();
    this->unkEE0.Init();
    this->unkEE4.Init();
    this->unkEE8.Init();
    this->unkEEC.Init();
    this->unkEF0.Init();
    this->unkEF4.Init();
    this->unkEF8.Init();
    this->unkF10.unk0 = 0;
    M2C_STRUCT_COPY((s32) &this->unkF14 + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    this->unkF74 = 0.0f;
    this->unkF70 = 0.0f;
    M2C_FIELD(this, s8 *, 0xF1F) = 0;
    this->unkCD8 = 0;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CynderDescriptor::Deinit() {
    MKHeap *temp_r3_6130;
    u16 *temp_r31_6127;

    temp_r31_6127 = this->unk28C;
    if (temp_r31_6127 != NULL) {
        temp_r3_6130 = MKHeap::Current();
        if (temp_r3_6130 != NULL) {
            ((MKHeap *) (temp_r3_6130->Current()))->Free(temp_r31_6127, NULL, 0);
        } else {
            free(temp_r31_6127);
        }
        this->unk28C = NULL;
    }
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
void CynderDescriptor::LoadDone() {
    MKHeap *temp_r3_6178;
    MKHeap *var_r3_6169;
    s32 temp_r0_6172;
    s32 var_ctr_6170;
    u16 *var_r3_6185;

    EnemyDescriptor::LoadDone();
    this->unk270 = 0xFFFF;
    var_r3_6169 = NULL;
    var_ctr_6170 = 7;
    do {
        temp_r0_6172 = var_r3_6169 + 0x2D4;
        var_r3_6169 += 0x24;
        *(this + temp_r0_6172) = *(this + temp_r0_6172) / 100.0f;
        var_ctr_6170 -= 1;
    } while (var_ctr_6170 != 0);
    temp_r3_6178 = var_r3_6169->Current();
    if (temp_r3_6178 != NULL) {
        var_r3_6185 = ((MKHeap *) (temp_r3_6178->Current()))->Alloc(4, NULL, 0);
    } else {
        var_r3_6185 = malloc(4);
    }
    this->unk28C = var_r3_6185;
    M2C_FIELD(this->unk28C, u16 *, 0) = 1;
    M2C_FIELD(this->unk28C, u16 *, 2) = Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "body");
    M2C_FIELD(this->unk28C, s16 *, 4) = 0xFF;
    this->unk128 = 0.0f;
    this->unk3B8 = (s32) Tools_GetMatchingNodeIndex(this->unk2C, "spine03");
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_780'
s32 CynderDescriptor::LoadLine(MKIniLine *arg0) {
    s8 sp36;
    s8 sp2C;
    M2C_UNK sp28;
    s8 spC;
    s8 *sp8;
    MKIniLine *var_r29_6274;
    s32 temp_r5_6337;
    s32 temp_ret_6294;
    s32 temp_ret_6334;
    s32 var_r30_6365;

    M2C_STRUCT_COPY((s32) &sp28 + 4, (s32) (&lit_780 - 4) + 4, 0x20);
    M2C_STRUCT_COPY((s32) &sp8 + 4, (s32) (&lit_781 - 4) + 4, 0x20);
    if (EnemyDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("HurtPhrases") != 0) {
        var_r29_6274 = arg0->unkC->GetSubLine(arg0);
loop_11:
        if (var_r29_6274 != NULL) {
            strcpy(&sp2C, var_r29_6274->GetFieldName());
            if (strnicmp("hurtPhrase", &sp2C, 0xA) == 0) {
                strcpy(&spC, &sp36);
                temp_ret_6294 = atoi(&spC);
                if (temp_ret_6294 <= 7) {
                    var_r29_6274->LoadString(Str_Printf("hurtPhrase%s", &spC, M2C_BITWISE(f32, temp_ret_6294)), &sp8, 0);
                    strcpy(this + (((atoi(&spC) - 1) * 0x24) + 0x2B4), sp8);
                }
            } else if (strnicmp("Percentage", &sp2C, 0xA) == 0) {
                strcpy(&spC, &sp36);
                if (atoi(&spC) <= 7) {
                    temp_ret_6334 = atoi(&spC);
                    temp_r5_6337 = (temp_ret_6334 - 1) * 0x24;
                    var_r29_6274->LoadFloat(Str_Printf("percentage%s", &spC, temp_r5_6337, M2C_BITWISE(f32, temp_ret_6334)), this + (temp_r5_6337 + 0x2D4), 0);
                }
            }
            var_r29_6274 = var_r29_6274->unkC->GetNextLine(var_r29_6274);
            goto loop_11;
        }
        return 1;
    }
    var_r30_6365 = 0;
    if ((arg0->LoadFloat("phraseDelay", &this->unk3B4, 0) != 0) || (KDSound_LoadLine(arg0, "phraseFlinchSound", &this->unk3B0) != 0)) {
        var_r30_6365 = 1;
    }
    return var_r30_6365;
}
#endif

#if 0 // DRAFT: illegal type
void CynderDescriptor::Init() {
    s32 var_r28_6409;
    s32 var_r30_6403;
    void *temp_r29_6416;

    EnemyDescriptor::Init();
    var_r30_6403 = 0;
    this->unk7C.unk18 |= 0x04000000;
    var_r28_6409 = 0;
    this->unk123 = 0;
    this->unk1D4 = 0;
    this->unk3B4 = 1.0f;
    this->unk3B0 = GS_CynderFlinch1;
    do {
        temp_r29_6416 = this + var_r30_6403;
        strcpy(temp_r29_6416 + 0x2B4, "");
        var_r28_6409 += 1;
        M2C_FIELD(temp_r29_6416, f32 *, 0x2D4) = 0.0f;
        var_r30_6403 += 0x24;
    } while (var_r28_6409 < 7);
}
#endif

void Cynder_cpp::__sinit() {
    f32 temp_f0_6951;
    f64 temp_f1_6932;
    f64 temp_f1_6940;
    f64 temp_f3_6920;
    f64 temp_f4_6929;
    f64 temp_f4_6937;
    f64 temp_f8_6922;

    temp_f3_6920 = __frsqrte(2014000.0);
    temp_f8_6922 = __frsqrte(380000.0);
    temp_f4_6929 = 0.5 * temp_f3_6920 * -((2014000.0 * (temp_f3_6920 * temp_f3_6920)) - 3.0);
    temp_f1_6932 = 0.5 * temp_f8_6922 * -((380000.0 * (temp_f8_6922 * temp_f8_6922)) - 3.0);
    temp_f4_6937 = 0.5 * temp_f4_6929 * -((2014000.0 * (temp_f4_6929 * temp_f4_6929)) - 3.0);
    temp_f1_6940 = 0.5 * temp_f1_6932 * -((380000.0 * (temp_f1_6932 * temp_f1_6932)) - 3.0);
    temp_f0_6951 = (f32) (380000.0 * (0.5 * temp_f1_6940 * -((380000.0 * (temp_f1_6940 * temp_f1_6940)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_6937 * -((2014000.0 * (temp_f4_6937 * temp_f4_6937)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_6951;
}
