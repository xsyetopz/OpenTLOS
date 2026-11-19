#include "spyro/source/AssaultCannon.h"
#include "common/Source/Animation.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EnemyDeathFX.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/ExplodeMsg.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Projectile.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
s32 stricmp(s8 *, s8 *);                            /* extern */
extern s32 GS_EarthTurrentFire;
extern s32 GS_SpyroZapBurn;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
extern void *gpTranslation_StringArray;
static M2C_UNK lit_723;                                /* unable to generate initializer: unknown type */
u8 states__13AssaultCannon[0xB4] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
#if 0 // DRAFT: illegal implicit conversion from 'const char[5]' to
static s8 *pTurretAnimEvents = "Fire";
#endif

#if 0 // DRAFT: illegal implicit conversion from 'AssaultCannonDescriptor *' to
void AssaultCannon::CalcSpikeBeamPositions() {
    ShatterableDescriptor *temp_r3_153;

    temp_r3_153 = checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((s32) M2C_FIELD(temp_r3_153, s32 *, 0x174) == 2) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, *(M2C_FIELD(temp_r3_153, s32 *, 0x17C) + (MKRand_Int(&gViewSeed, 0, 5) * 4)), (MKVector3 *) &this->unk2F0);
        MKModel_CalculateRefPointWorldPosition(this->unk4, *(M2C_FIELD(temp_r3_153, s32 *, 0x17C) + (MKRand_Int(&gViewSeed, 0, 5) * 4)), (MKVector3 *) &this->unk300);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'AssaultCannonDescriptor *' to
void AssaultCannon::CalcBarrelBeamPositions() {
    MKVector3 spB8;
    MKVector3 spA8;
    f64 spA0;
    f64 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    ShatterableDescriptor *temp_r3_195;
    f32 temp_f1_211;
    f32 temp_f1_252;
    f64 temp_f0_214;
    f64 temp_f0_255;

    temp_r3_195 = checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((s32) M2C_FIELD(temp_r3_195, s32 *, 0x174) == 2) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r3_195, s32 *, 0x180), &spB8);
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r3_195, s32 *, 0x184), &spA8);
        temp_f1_211 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        temp_f0_214 = M2C_BITWISE(f64, spA8) - M2C_BITWISE(f64, spB8);
        sp18 = temp_f0_214;
        sp78 = temp_f0_214;
        sp20 = spA8.unk8 - spB8.unk8;
        sp80 = (f64) sp20;
        sp88.operator*(temp_f1_211);
        sp38 = M2C_BITWISE(f64, spB8) + M2C_BITWISE(f64, sp88);
        M2C_FIELD(this, f64 *, 0x328) = sp38;
        sp40 = spB8.unk8 + sp88.unk8;
        sp98 = sp38;
        M2C_FIELD(this, f64 *, 0x330) = (f64) sp40;
        spA0 = (f64) sp40;
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r3_195, s32 *, 0x188), &spB8);
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r3_195, s32 *, 0x18C), &spA8);
        temp_f1_252 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        temp_f0_255 = M2C_BITWISE(f64, spA8) - M2C_BITWISE(f64, spB8);
        sp8 = temp_f0_255;
        sp48 = temp_f0_255;
        sp10 = spA8.unk8 - spB8.unk8;
        sp50 = (f64) sp10;
        sp58.operator*(temp_f1_252);
        sp28 = M2C_BITWISE(f64, spB8) + M2C_BITWISE(f64, sp58);
        M2C_FIELD(this, f64 *, 0x338) = sp28;
        sp30 = spB8.unk8 + sp58.unk8;
        sp68 = sp28;
        sp70 = (f64) sp30;
        this->unk328 = (f64) sp30;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'AssaultCannonDescriptor *' to
void AssaultCannon::FreeElecBeams() {
    ShatterableDescriptor *temp_r3_299;

    temp_r3_299 = checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((s32) M2C_FIELD(temp_r3_299, s32 *, 0x174) == 2) {
        ((EnergyBeam *) (M2C_FIELD(temp_r3_299, EnergyBeam **, 0x178)))->FreeEnergyBeam(M2C_BITWISE(EnergyBeam::Beam *, this->unk2E4));
        this->unk2E4 = 0.0f;
        ((EnergyBeam *) (M2C_FIELD(temp_r3_299, EnergyBeam **, 0x178)))->FreeEnergyBeam((EnergyBeam::Beam *) this->unk2E8);
        this->unk2E8 = 0;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'AssaultCannonDescriptor *' to
void AssaultCannon::AllocElecBeams() {
    ShatterableDescriptor *temp_r3_331;

    temp_r3_331 = checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((s32) M2C_FIELD(temp_r3_331, s32 *, 0x174) == 2) {
        ((EnergyBeam *) (M2C_FIELD(temp_r3_331, EnergyBeam **, 0x178)))->SpawnEnergyBeam((MKVector3 *) &this->unk2F0, (MKVector3 *) &this->unk300, 0.25f);
        this->unk2E4 = M2C_ERROR(/* Read from unset register $r3 */);
        ((EnergyBeam *) (M2C_FIELD(temp_r3_331, EnergyBeam **, 0x178)))->SpawnEnergyBeam((MKVector3 *) &this->unk308.unk8, (MKVector3 *) &this->unk318.unk8, 0.25f);
        this->unk2E8 = M2C_ERROR(/* Read from unset register $r3 */);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'AssaultCannonDescriptor *' to
void AssaultCannon::EmitShootingFX() {
    MKVector3 sp70;
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;                                       /* compiler-managed */
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
    f32 spC;
    f32 sp8;
    ShatterableDescriptor *temp_r31_369;
    f32 temp_f0_484;
    f32 var_f3_473;
    f32 var_f4_406;
    f64 temp_f1_412;
    f64 temp_f1_418;
    f64 temp_f1_422;
    s32 temp_r0_483;
    s32 temp_r3_441;
    s32 var_r0_451;
    u32 temp_r4_368;
    void *temp_r30_533;
    void *temp_r3_378;
    void *temp_r3_385;
    void *temp_r3_530;

    temp_r4_368 = this->unk2BC;
    temp_r31_369 = checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (temp_r4_368 != -1U) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_368, &sp70);
    } else {
        temp_r3_378 = this->unk8;
        sp70 = M2C_FIELD(temp_r3_378, f64 *, 0x30);
        sp70.unk8 = M2C_FIELD(temp_r3_378, f64 *, 0x38);
    }
    temp_r3_385 = ((u8 *) this->unk8) + 0x30;
    sp30 = M2C_BITWISE(f64, sp70) - M2C_FIELD(temp_r3_385, f64 *, 0);
    sp60 = sp30;
    sp38 = sp70.unk8 - M2C_FIELD(temp_r3_385, f32 *, 8);
    sp68 = (f64) sp38;
    var_f4_406 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + ((*(f32 *) ((u8 *) &sp58 + 0xc)) * (*(f32 *) ((u8 *) &sp58 + 0xc))));
    if (var_f4_406 > 0.000001f) {
        if (var_f4_406 > 0.0f) {
            temp_f1_412 = __frsqrte(var_f4_406);
            temp_f1_418 = 0.5 * temp_f1_412 * -(((f64) var_f4_406 * (temp_f1_412 * temp_f1_412)) - 3.0);
            temp_f1_422 = 0.5 * temp_f1_418 * -(((f64) var_f4_406 * (temp_f1_418 * temp_f1_418)) - 3.0);
            var_f4_406 = (f32) ((f64) var_f4_406 * (0.5 * temp_f1_422 * -(((f64) var_f4_406 * (temp_f1_422 * temp_f1_422)) - 3.0)));
        } else if (var_f4_406 < M2C_BITWISE(f32, 0.0)) {
            var_f4_406 = __float_nan;
        } else {
            sp8 = var_f4_406;
            temp_r3_441 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_441) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_451 = 1;
                } else {
                    var_r0_451 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_451 = 5;
                } else {
                    var_r0_451 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_451 = 4;
                break;
            }
            if (var_r0_451 == 1) {
                var_f4_406 = __float_nan;
            }
        }
        var_f3_473 = 1.0f / var_f4_406;
    } else {
        var_f3_473 = 0.0f;
    }
    temp_r0_483 = M2C_FIELD(temp_r31_369, s32 *, 0x174);
    temp_f0_484 = (f32) sp68 * var_f3_473;
    sp60 = (f32) sp60 * var_f3_473;
    (*(f32 *) ((u8 *) &sp58 + 0xc)) *= var_f3_473;
    sp68 = temp_f0_484;
    switch (temp_r0_483) {                          /* switch 2; irregular */
    case 1:                                         /* switch 2 */
        sp20 = (f64) sp60 * 5.634608575e-315;
        sp28 = temp_f0_484 * 500.0f;
        sp50 = sp20;
        sp58 = (f64) sp28;
        spC = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
        gb.EmitDust(sp70, *((MKVector3 *) &sp50), spC, 0.0f);
        return;
    case 3:                                         /* switch 2 */
        temp_r3_530 = M2C_FIELD(M2C_FIELD(gb.unk2A0, void **, 0x44), void *(**)(void *), 0x3C)(gb.unk2A0);
        if (temp_r3_530 != NULL) {
            temp_r30_533 = M2C_FIELD(temp_r3_530, void **, 0x2C);
            M2C_FIELD(temp_r3_530, f64 *, 0) = M2C_BITWISE(f64, sp70);
            M2C_FIELD(temp_r3_530, f64 *, 8) = (f64) sp70.unk8;
            M2C_FIELD(temp_r3_530, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_530, f32 *, 0x28) = 0.0f;
            sp10 = (f64) sp60 * 5.634608575e-315;
            M2C_FIELD(temp_r30_533, f64 *, 0) = sp10;
            sp18 = sp68 * 500.0f;
            sp40 = sp10;
            M2C_FIELD(temp_r30_533, f64 *, 8) = (f64) sp18;
            sp48 = (f64) sp18;
            M2C_FIELD(temp_r30_533, f32 *, 0x18) = 0.6f;
            M2C_FIELD(temp_r30_533, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
            M2C_FIELD(temp_r30_533, f32 *, 0x14) = (f32) M2C_FIELD(gb.unk2A0, f32 *, 0xF4);
        }
        /* fallthrough */
    case 2:                                         /* switch 2 */
    case 0:                                         /* switch 2 */
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void AssaultCannon::UpdateTurretBone(MKDynamicBone *arg0, void *arg1) {
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s16 temp_r31_625;

    M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp10 = -arg0->unk0;
    sp14 = -arg0->unk4;
    sp18 = -arg0->unk8;
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    sp30.Translate(&sp30, *((MKVector3 *) &sp20));
    sp30.RotateYaw(&sp30, arg0->unk10);
    sp30.Translate(&sp30, *((MKVector3 *) arg0));
    temp_r31_625 = M2C_FIELD(this->unk20, s16 *, 0x70);
    ((Animation *) (MKModel_GetAnimation(M2C_BITWISE(MKModel *, this->unk24))))->SetCustomMatrix((s32) temp_r31_625, &sp30, (AnimationMatrixPosition) 4, 0U);
}
#endif

void AssaultCannon::StateDeadExit() {

}

#if 0 // DRAFT: function call 'MKRand_Int(long *, int, int)' does not match
void AssaultCannon::StateDeadUpdate() {
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f64 temp_f0_694;
    f64 temp_f0_707;
    f64 temp_f0_719;
    void *temp_r3_701;

    if (MKRand_Int(&gViewSeed, 0, 3) == 0) {
        sp38 = 0.0f;
        sp78 = -1.0f;
        sp68 = 1.0f;
        sp30 = 0.0f;
        sp34 = -50.0f;
        sp70 = -1.0f;
        sp74 = 0.0f;
        sp60 = 1.0f;
        sp64 = 0.0f;
        sp90 = (f64) sp30;
        sp98 = (f64) sp38;
        spB0 = (f64) sp70;
        spB8 = (f64) sp78;
        spA0 = (f64) sp60;
        spA8 = (f64) sp68;
        KDRand_Vector(spC0, *((MKVector3 *) &spB0));
        temp_f0_694 = spC0 * 5.51933903e-315;
        sp50 = temp_f0_694;
        spD0 = temp_f0_694;
        temp_r3_701 = ((u8 *) this->unk8) + 0x30;
        sp58 = spC0.unk8 * 75.0f;
        spD8 = (f64) sp58;
        temp_f0_707 = M2C_FIELD(temp_r3_701, f64 *, 0) + temp_f0_694;
        sp40 = temp_f0_707;
        spE0 = temp_f0_707;
        sp48 = M2C_FIELD(temp_r3_701, f32 *, 8) + (f32) spD8;
        spE8 = (f64) sp48;
        temp_f0_719 = spE0 + sp90;
        sp20 = temp_f0_719;
        spF0 = temp_f0_719;
        sp28 = (f32) spE8 + (f32) sp98;
        spF8 = (f64) sp28;
        sp14 = MKRand_Float(&gViewSeed, 1300.0f, 2000.0f);
        sp10 = 0.0f;
        sp18 = 0.0f;
        sp80 = (f64) sp10;
        sp88 = (f64) sp18;
        sp8 = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
        gb.EmitDust(*((MKVector3 *) &spF0), *((MKVector3 *) &sp80), sp8, 0.0f);
    }
    if ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0) {
        this->unk2D4 = M2C_BITWISE(f32, this->unk2D4) - gUpdateTimeDelta;
        if (M2C_BITWISE(f32, this->unk2D4) <= 0.0f) {
            M2C_FIELD(this, u8 *, 0x2F1) = 1U;
            ((EnemyDeathFX *) gb.unk98)->Trigger(NULL, *(this->unk8 + 0x30), 2.0f, 0);
            if ((s32) M2C_FIELD(checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x1A8) != 0) {
                SpawnGems(M2C_FIELD(checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x1A8));
            }
        }
    }
}
#endif

void AssaultCannon::StateDeadEnter() {
    SetAnim(5, 0, 1.0f);
    this->unk2D4 = 3.0f;
}

#if 0 // DRAFT: ')' expected
void AssaultCannon::StateFireExit() {
    s32 temp_r0_829;
    u32 temp_r3_845;
    u32 temp_r3_867;
    u32 temp_r3_876;

    temp_r0_829 = M2C_FIELD(checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x174);
    switch (temp_r0_829) {                          /* irregular */
    case 0:
        temp_r3_845 = this->unk2C8;
        if (temp_r3_845 != 0) {
            M2C_FIELD(M2C_FIELD(temp_r3_845, void **, 0x44), M2C_UNK (**)(), 0x54)();
        }
        this->unk2C0 = 5.0f;
        M2C_FIELD(this, s8 *, 0x2F0) = 0;
        break;
    case 1:
        this->unk2C0 = 5.0f;
        break;
    case 2:
        M2C_FIELD(this, s8 *, 0x2F0) = 0;
        this->unk2C0 = 5.0f;
        temp_r3_867 = this->unk2C8;
        if (temp_r3_867 != 0) {
            M2C_FIELD(M2C_FIELD(temp_r3_867, void **, 0x44), M2C_UNK (**)(), 0x54)();
        }
        break;
    case 3:
        temp_r3_876 = this->unk2C8;
        if (temp_r3_876 != 0) {
            M2C_FIELD(M2C_FIELD(temp_r3_876, void **, 0x44), M2C_UNK (**)(), 0x54)();
        }
        this->unk2C0 = 5.0f;
        M2C_FIELD(this, s8 *, 0x2F0) = 0;
        break;
    case 4:
        this->unk2C0 = 4.0f;
        break;
    case 5:
        this->unk2C0 = 3.0f;
        break;
    }
    SetAnim(1, 0, 1.0f);
}
#endif

#if 0 // DRAFT: illegal use of abstract class ('HeroInterface::GetHeroType()')
void AssaultCannon::StateFireUpdate() {
    f64 sp558;
    f64 sp550;
    f32 sp548;
    AssaultCannon *sp544;
    s32 sp540;
    f64 sp538;                                      /* compiler-managed */
    f64 sp530;                                      /* compiler-managed */
    f64 sp528;                                      /* compiler-managed */
    f64 sp520;                                      /* compiler-managed */
    f64 sp518;                                      /* compiler-managed */
    f64 sp510;                                      /* compiler-managed */
    f64 sp508;                                      /* compiler-managed */
    f64 sp500;                                      /* compiler-managed */
    f64 sp4F8;                                      /* compiler-managed */
    f64 sp4F0;                                      /* compiler-managed */
    f64 sp4E8;                                      /* compiler-managed */
    f64 sp4E0;                                      /* compiler-managed */
    f64 sp4D8;                                      /* compiler-managed */
    f64 sp4D0;                                      /* compiler-managed */
    f64 sp4C8;                                      /* compiler-managed */
    f64 sp4C0;                                      /* compiler-managed */
    f64 sp4B8;
    f64 sp4B0;
    f64 sp4A8;
    f64 sp4A0;
    f64 sp498;
    f64 sp490;
    f64 sp480;
    f64 sp478;
    f64 sp470;
    f64 sp468;
    f64 sp460;
    f64 sp458;
    f64 sp450;
    f64 sp448;
    f64 sp440;
    MKVector3 sp430;
    MKVector3 sp420;
    f64 sp418;
    f64 sp410;
    f64 sp408;
    f64 sp400;
    f64 sp3F0;
    f64 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    f64 sp3B0;
    MKVector3 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    HeroInterface sp330;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    MKVector3 sp2A0;
    MKVector3 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    MKVector3 sp200;
    MKVector3 sp1F0;
    f32 sp1E8;
    f64 sp1E0;
    f32 sp1D8;
    f64 sp1D0;
    f32 sp1C8;
    f64 sp1C0;
    f32 sp1B8;
    f64 sp1B0;
    f32 sp1A8;
    f64 sp1A0;
    f32 sp198;
    f64 sp190;
    f32 sp188;
    f64 sp180;
    f32 sp178;
    f64 sp170;
    f32 sp168;
    f64 sp160;
    f32 sp158;
    f64 sp150;
    f32 sp148;
    f64 sp140;
    f32 sp138;
    f64 sp130;
    f32 sp128;
    f64 sp120;
    f32 sp118;
    f64 sp110;
    f32 sp108;
    f64 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
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
    f32 temp_f28_2878;
    f32 temp_f29_2633;
    f32 temp_f2_1835;
    f32 var_f2_1119;
    f32 var_f2_2241;
    f32 var_f31_1237;
    f32 var_f31_1668;
    f32 var_f31_2359;
    f32 var_f31_2677;
    f32 var_f3_2966;
    f32 var_f4_1019;
    f32 var_f4_1172;
    f32 var_f4_1277;
    f32 var_f4_1449;
    f32 var_f4_1603;
    f32 var_f4_1708;
    f32 var_f4_1927;
    f32 var_f4_2141;
    f32 var_f4_2294;
    f32 var_f4_2399;
    f32 var_f4_2566;
    f32 var_f4_2751;
    f32 var_f4_2899;
    f32 var_f5_1032;
    f32 var_f5_1290;
    f32 var_f5_1462;
    f32 var_f5_1721;
    f32 var_f5_1940;
    f32 var_f5_2154;
    f32 var_f5_2412;
    f32 var_f5_2764;
    f64 temp_f0_1001;
    f64 temp_f0_1013;
    f64 temp_f0_1271;
    f64 temp_f0_1431;
    f64 temp_f0_1443;
    f64 temp_f0_1702;
    f64 temp_f0_1819;
    f64 temp_f0_1909;
    f64 temp_f0_1921;
    f64 temp_f0_2123;
    f64 temp_f0_2135;
    f64 temp_f0_2393;
    f64 temp_f0_2514;
    f64 temp_f0_2745;
    f64 temp_f0_2983;
    f64 temp_f0_2998;
    f64 temp_f1_1037;
    f64 temp_f1_1043;
    f64 temp_f1_1047;
    f64 temp_f1_1149;
    f64 temp_f1_1175;
    f64 temp_f1_1181;
    f64 temp_f1_1185;
    f64 temp_f1_1295;
    f64 temp_f1_1301;
    f64 temp_f1_1305;
    f64 temp_f1_1425;
    f64 temp_f1_1467;
    f64 temp_f1_1473;
    f64 temp_f1_1477;
    f64 temp_f1_1580;
    f64 temp_f1_1606;
    f64 temp_f1_1612;
    f64 temp_f1_1616;
    f64 temp_f1_1726;
    f64 temp_f1_1732;
    f64 temp_f1_1736;
    f64 temp_f1_1903;
    f64 temp_f1_1945;
    f64 temp_f1_1951;
    f64 temp_f1_1955;
    f64 temp_f1_2117;
    f64 temp_f1_2159;
    f64 temp_f1_2165;
    f64 temp_f1_2169;
    f64 temp_f1_2271;
    f64 temp_f1_2297;
    f64 temp_f1_2303;
    f64 temp_f1_2307;
    f64 temp_f1_2417;
    f64 temp_f1_2423;
    f64 temp_f1_2427;
    f64 temp_f1_2543;
    f64 temp_f1_2569;
    f64 temp_f1_2575;
    f64 temp_f1_2579;
    f64 temp_f1_2680;
    f64 temp_f1_2686;
    f64 temp_f1_2690;
    f64 temp_f1_2769;
    f64 temp_f1_2775;
    f64 temp_f1_2779;
    f64 temp_f1_2905;
    f64 temp_f1_2911;
    f64 temp_f1_2915;
    f64 temp_f1_3022;
    f64 temp_f1_995;
    s32 temp_r0_931;
    s32 temp_r3_1066;
    s32 temp_r3_1204;
    s32 temp_r3_1324;
    s32 temp_r3_1496;
    s32 temp_r3_1635;
    s32 temp_r3_1755;
    s32 temp_r3_1974;
    s32 temp_r3_2188;
    s32 temp_r3_2326;
    s32 temp_r3_2446;
    s32 temp_r3_2598;
    s32 temp_r3_2709;
    s32 temp_r3_2798;
    s32 temp_r3_2934;
    s32 var_r0_1076;
    s32 var_r0_1214;
    s32 var_r0_1334;
    s32 var_r0_1506;
    s32 var_r0_1645;
    s32 var_r0_1765;
    s32 var_r0_1984;
    s32 var_r0_2198;
    s32 var_r0_2336;
    s32 var_r0_2456;
    s32 var_r0_2608;
    s32 var_r0_2719;
    s32 var_r0_2808;
    s32 var_r0_2944;
    u32 temp_r3_1556;
    u32 temp_r3_1566;
    u32 temp_r3_1842;
    u32 temp_r3_1855;
    u32 temp_r3_2848;
    u32 temp_r3_2858;
    u32 temp_r3_3031;
    u32 temp_r3_3036;
    u32 temp_r4_1251;
    u32 temp_r4_1545;
    u32 temp_r4_1682;
    u32 temp_r4_2027;
    u32 temp_r4_2373;
    u32 temp_r4_2847;
    u32 temp_r4_2862;
    void **temp_r3_1410;
    void **temp_r3_1888;
    void **temp_r3_2102;
    void **temp_r3_980;
    void *temp_r30_1139;
    void *temp_r30_1406;
    void *temp_r30_1575;
    void *temp_r30_1884;
    void *temp_r30_2098;
    void *temp_r30_2261;
    void *temp_r30_2537;
    void *temp_r30_976;
    void *temp_r3_1148;
    void *temp_r3_1260;
    void *temp_r3_1268;
    void *temp_r3_1424;
    void *temp_r3_1579;
    void *temp_r3_1691;
    void *temp_r3_1699;
    void *temp_r3_1902;
    void *temp_r3_2036;
    void *temp_r3_2116;
    void *temp_r3_2270;
    void *temp_r3_2382;
    void *temp_r3_2390;
    void *temp_r3_2542;
    void *temp_r3_2657;
    void *temp_r3_2742;
    void *temp_r3_2871;
    void *temp_r3_994;
    void *temp_r4_1135;
    void *temp_r4_1403;
    void *temp_r4_1573;
    void *temp_r4_1881;
    void *temp_r4_2095;
    void *temp_r4_2257;
    void *temp_r4_2534;
    void *temp_r4_973;

    this->unk2DC -= gUpdateTimeDelta;
    temp_r0_931 = M2C_FIELD(checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x174);
    switch (temp_r0_931) {                          /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        this->unk2CC = M2C_BITWISE(f32, this->unk2CC) - gUpdateTimeDelta;
        if (M2C_BITWISE(f32, this->unk2CC) <= 0.0f) {
            this->unk218.SetState(this, 1, 0U);
            return;
        }
        if (gb.unk0->GetTargetable() != 0U) {
            temp_r4_973 = this->unk8;
            temp_r30_976 = ((u8 *) temp_r4_973) + 0x30;
            temp_r3_980 = gb.unk0->GetTargetable(temp_r4_973);
            M2C_FIELD(*temp_r3_980, M2C_UNK (**)(f64 *, void **), 0x30)(&sp480, temp_r3_980);
            temp_r3_994 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
            temp_f1_995 = M2C_FIELD(temp_r3_994, f64 *, 0x30);
            sp490 = temp_f1_995;
            sp498 = M2C_FIELD(temp_r3_994, f64 *, 0x38);
            temp_f0_1001 = temp_f1_995 + sp480;
            sp1E0 = temp_f0_1001;
            sp4A0 = temp_f0_1001;
            sp1E8 = (f32) sp498 + sp488;
            sp4A8 = (f64) sp1E8;
            temp_f0_1013 = sp4A0 - M2C_FIELD(temp_r30_976, f64 *, 0);
            sp1D0 = temp_f0_1013;
            var_f4_1019 = 0.0f;
            sp530 = temp_f0_1013;
            sp1D8 = (f32) sp4A8 - M2C_FIELD(temp_r30_976, f32 *, 8);
            (*(f32 *) ((u8 *) &sp4B8 + 0x7c)) = 0.0f;
            sp538 = (f64) sp1D8;
            var_f5_1032 = ((f32) sp538 * (f32) sp538) + (((f32) sp530 * (f32) sp530) + (0.0f * 0.0f));
            if (var_f5_1032 > 0.000001f) {
                if (var_f5_1032 > 0.0f) {
                    temp_f1_1037 = __frsqrte(var_f5_1032);
                    temp_f1_1043 = 0.5 * temp_f1_1037 * -(((f64) var_f5_1032 * (temp_f1_1037 * temp_f1_1037)) - 3.0);
                    temp_f1_1047 = 0.5 * temp_f1_1043 * -(((f64) var_f5_1032 * (temp_f1_1043 * temp_f1_1043)) - 3.0);
                    var_f5_1032 = (f32) ((f64) var_f5_1032 * (0.5 * temp_f1_1047 * -(((f64) var_f5_1032 * (temp_f1_1047 * temp_f1_1047)) - 3.0)));
                } else if (var_f5_1032 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_1032 = __float_nan;
                } else {
                    sp3C = var_f5_1032;
                    temp_r3_1066 = M2C_BITWISE(s32, sp3C) & 0x7F800000;
                    switch (temp_r3_1066) {         /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp3C) & 0x7FFFFF) {
                            var_r0_1076 = 1;
                        } else {
                            var_r0_1076 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp3C) & 0x7FFFFF) {
                            var_r0_1076 = 5;
                        } else {
                            var_r0_1076 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_1076 = 4;
                        break;
                    }
                    if (var_r0_1076 == 1) {
                        var_f5_1032 = __float_nan;
                    }
                }
                var_f4_1019 = 1.0f / var_f5_1032;
            }
            sp530 = (f32) sp530 * var_f4_1019;
            (*(f32 *) ((u8 *) &sp4B8 + 0x7c)) *= var_f4_1019;
            sp538 = (f32) sp538 * var_f4_1019;
            sp470 = (f64) sp530;
            sp478 = (f64) sp538;
            UpdateTurning((MKVector3) &sp470);
            if ((u32) this->unk2C8 != 0) {
                var_f2_1119 = M2C_BITWISE(f32, this->unk2CC);
                if (var_f2_1119 < 2.0f) {

                } else {
                    var_f2_1119 = 2.0f;
                }
                if (var_f2_1119 > 0.0f) {

                } else {
                    var_f2_1119 = 0.0f;
                }
                temp_r4_1135 = this->unk8;
                temp_r30_1139 = ((u8 *) temp_r4_1135) + 0x30;
                temp_r3_1148 = M2C_FIELD(gb.unk0->GetProp(temp_r4_1135, 0.05f), void **, 8);
                temp_f1_1149 = M2C_FIELD(temp_r3_1148, f64 *, 0x30);
                sp450 = temp_f1_1149;
                sp458 = M2C_FIELD(temp_r3_1148, f64 *, 0x38);
                sp1C0 = temp_f1_1149 - M2C_FIELD(temp_r30_1139, f64 *, 0);
                sp460 = sp1C0;
                sp1C8 = (f32) sp458 - M2C_FIELD(temp_r30_1139, f32 *, 8);
                sp468 = (f64) sp1C8;
                var_f4_1172 = ((f32) sp468 * (f32) sp468) + (((f32) sp460 * (f32) sp460) + ((*(f32 *) ((u8 *) &sp460 + 0x4)) * (*(f32 *) ((u8 *) &sp460 + 0x4))));
                if (var_f4_1172 > 0.0f) {
                    temp_f1_1175 = __frsqrte(var_f4_1172);
                    temp_f1_1181 = 0.5 * temp_f1_1175 * -(((f64) var_f4_1172 * (temp_f1_1175 * temp_f1_1175)) - 3.0);
                    temp_f1_1185 = 0.5 * temp_f1_1181 * -(((f64) var_f4_1172 * (temp_f1_1181 * temp_f1_1181)) - 3.0);
                    var_f4_1172 = (f32) ((f64) var_f4_1172 * (0.5 * temp_f1_1185 * -(((f64) var_f4_1172 * (temp_f1_1185 * temp_f1_1185)) - 3.0)));
                } else if (var_f4_1172 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1172 = __float_nan;
                } else {
                    sp38 = var_f4_1172;
                    temp_r3_1204 = M2C_BITWISE(s32, sp38) & 0x7F800000;
                    switch (temp_r3_1204) {         /* switch 3; irregular */
                    case 0x7F800000:                /* switch 3 */
                        if (M2C_BITWISE(s32, sp38) & 0x7FFFFF) {
                            var_r0_1214 = 1;
                        } else {
                            var_r0_1214 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 3 */
                        if (M2C_BITWISE(s32, sp38) & 0x7FFFFF) {
                            var_r0_1214 = 5;
                        } else {
                            var_r0_1214 = 3;
                        }
                        break;
                    default:                        /* switch 3 */
                        var_r0_1214 = 4;
                        break;
                    }
                    if (var_r0_1214 == 1) {
                        var_f4_1172 = __float_nan;
                    }
                }
                var_f31_1237 = var_f4_1172 - 500.0f;
                if (var_f31_1237 < 20000.0f) {

                } else {
                    var_f31_1237 = 20000.0f;
                }
                if (var_f31_1237 > 500.0f) {

                } else {
                    var_f31_1237 = 500.0f;
                }
                temp_r4_1251 = this->unk2BC;
                if (temp_r4_1251 != -1U) {
                    MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_1251, &this->unk230);
                } else {
                    temp_r3_1260 = this->unk8;
                    M2C_FIELD(this, f64 *, 0x230) = (f64) M2C_FIELD(temp_r3_1260, f64 *, 0x30);
                    M2C_FIELD(this, f64 *, 0x238) = (f64) M2C_FIELD(temp_r3_1260, f64 *, 0x38);
                }
                temp_r3_1268 = ((u8 *) this->unk8) + 0x30;
                temp_f0_1271 = M2C_FIELD(this, f64 *, 0x230) - M2C_FIELD(temp_r3_1268, f64 *, 0);
                sp1B0 = temp_f0_1271;
                var_f4_1277 = 0.0f;
                sp520 = temp_f0_1271;
                sp1B8 = this->unk230.unk8 - M2C_FIELD(temp_r3_1268, f32 *, 8);
                (*(f32 *) ((u8 *) &sp4B8 + 0x6c)) = 0.0f;
                sp528 = (f64) sp1B8;
                var_f5_1290 = ((f32) sp528 * (f32) sp528) + (((f32) sp520 * (f32) sp520) + (0.0f * 0.0f));
                if (var_f5_1290 > 0.000001f) {
                    if (var_f5_1290 > 0.0f) {
                        temp_f1_1295 = __frsqrte(var_f5_1290);
                        temp_f1_1301 = 0.5 * temp_f1_1295 * -(((f64) var_f5_1290 * (temp_f1_1295 * temp_f1_1295)) - 3.0);
                        temp_f1_1305 = 0.5 * temp_f1_1301 * -(((f64) var_f5_1290 * (temp_f1_1301 * temp_f1_1301)) - 3.0);
                        var_f5_1290 = (f32) ((f64) var_f5_1290 * (0.5 * temp_f1_1305 * -(((f64) var_f5_1290 * (temp_f1_1305 * temp_f1_1305)) - 3.0)));
                    } else if (var_f5_1290 < M2C_BITWISE(f32, 0.0)) {
                        var_f5_1290 = __float_nan;
                    } else {
                        sp34 = var_f5_1290;
                        temp_r3_1324 = M2C_BITWISE(s32, sp34) & 0x7F800000;
                        switch (temp_r3_1324) {     /* switch 4; irregular */
                        case 0x7F800000:            /* switch 4 */
                            if (M2C_BITWISE(s32, sp34) & 0x7FFFFF) {
                                var_r0_1334 = 1;
                            } else {
                                var_r0_1334 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 4 */
                            if (M2C_BITWISE(s32, sp34) & 0x7FFFFF) {
                                var_r0_1334 = 5;
                            } else {
                                var_r0_1334 = 3;
                            }
                            break;
                        default:                    /* switch 4 */
                            var_r0_1334 = 4;
                            break;
                        }
                        if (var_r0_1334 == 1) {
                            var_f5_1290 = __float_nan;
                        }
                    }
                    var_f4_1277 = 1.0f / var_f5_1290;
                }
                sp520 = (f32) sp520 * var_f4_1277;
                (*(f32 *) ((u8 *) &sp4B8 + 0x6c)) *= var_f4_1277;
                sp528 = (f32) sp528 * var_f4_1277;
                sp420.operator*(var_f31_1237);
                sp430.operator*(0.05f + -((var_f2_1119 * 0.5f) - 1.0f));
                spA0 = M2C_FIELD(this, f64 *, 0x230) + M2C_BITWISE(f64, sp430);
                this->unk240 = spA0;
                spA8 = this->unk230.unk8 + sp430.unk8;
                sp440 = spA0;
                sp448 = (f64) spA8;
                M2C_FIELD(this, f64 *, 0x248) = (f64) spA8;
                return;
            }
        } else {
            return;
        }
        break;
    case 1:                                         /* switch 1 */
        if ((void *) this->unk2E0 >= 6) {
            this->unk218.SetState(this, 1, 0U);
            return;
        }
        temp_r4_1403 = this->unk8;
        temp_r30_1406 = ((u8 *) temp_r4_1403) + 0x30;
        temp_r3_1410 = gb.unk0->GetTargetable(temp_r4_1403);
        M2C_FIELD(*temp_r3_1410, M2C_UNK (**)(f64 *, void **), 0x30)(&sp3F0, temp_r3_1410);
        temp_r3_1424 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
        temp_f1_1425 = M2C_FIELD(temp_r3_1424, f64 *, 0x30);
        sp400 = temp_f1_1425;
        sp408 = M2C_FIELD(temp_r3_1424, f64 *, 0x38);
        temp_f0_1431 = temp_f1_1425 + sp3F0;
        sp1A0 = temp_f0_1431;
        sp410 = temp_f0_1431;
        sp1A8 = (f32) sp408 + sp3F8;
        sp418 = (f64) sp1A8;
        temp_f0_1443 = sp410 - M2C_FIELD(temp_r30_1406, f64 *, 0);
        sp190 = temp_f0_1443;
        var_f4_1449 = 0.0f;
        sp510 = temp_f0_1443;
        sp198 = (f32) sp418 - M2C_FIELD(temp_r30_1406, f32 *, 8);
        (*(f32 *) ((u8 *) &sp4B8 + 0x5c)) = 0.0f;
        sp518 = (f64) sp198;
        var_f5_1462 = ((f32) sp518 * (f32) sp518) + (((f32) sp510 * (f32) sp510) + (0.0f * 0.0f));
        if (var_f5_1462 > 0.000001f) {
            if (var_f5_1462 > 0.0f) {
                temp_f1_1467 = __frsqrte(var_f5_1462);
                temp_f1_1473 = 0.5 * temp_f1_1467 * -(((f64) var_f5_1462 * (temp_f1_1467 * temp_f1_1467)) - 3.0);
                temp_f1_1477 = 0.5 * temp_f1_1473 * -(((f64) var_f5_1462 * (temp_f1_1473 * temp_f1_1473)) - 3.0);
                var_f5_1462 = (f32) ((f64) var_f5_1462 * (0.5 * temp_f1_1477 * -(((f64) var_f5_1462 * (temp_f1_1477 * temp_f1_1477)) - 3.0)));
            } else if (var_f5_1462 < M2C_BITWISE(f32, 0.0)) {
                var_f5_1462 = __float_nan;
            } else {
                sp30 = var_f5_1462;
                temp_r3_1496 = M2C_BITWISE(s32, sp30) & 0x7F800000;
                switch (temp_r3_1496) {             /* switch 5; irregular */
                case 0x7F800000:                    /* switch 5 */
                    if (M2C_BITWISE(s32, sp30) & 0x7FFFFF) {
                        var_r0_1506 = 1;
                    } else {
                        var_r0_1506 = 2;
                    }
                    break;
                case 0x0:                           /* switch 5 */
                    if (M2C_BITWISE(s32, sp30) & 0x7FFFFF) {
                        var_r0_1506 = 5;
                    } else {
                        var_r0_1506 = 3;
                    }
                    break;
                default:                            /* switch 5 */
                    var_r0_1506 = 4;
                    break;
                }
                if (var_r0_1506 == 1) {
                    var_f5_1462 = __float_nan;
                }
            }
            var_f4_1449 = 1.0f / var_f5_1462;
        }
        sp510 = (f32) sp510 * var_f4_1449;
        (*(f32 *) ((u8 *) &sp4B8 + 0x5c)) *= var_f4_1449;
        sp518 = (f32) sp518 * var_f4_1449;
        sp3E0 = (f64) sp510;
        sp3E8 = (f64) sp518;
        temp_r4_1545 = (u32) UpdateTurning((MKVector3) &sp3E0);
        if (this->unk2DC <= 0.0f) {
            this->unk2DC = 0.2f;
            this->unk2E0 += 1;
            temp_r3_1556 = this->unk2C8;
            if (temp_r3_1556 != 0) {
                M2C_FIELD(temp_r3_1556, AssaultCannon **, 0x130) = NULL;
                this->unk2C8 = 0;
            }
            this->unk2C8 = ((Projectile *)0xE)->CreateInstance((ProjectileType) temp_r4_1545);
            temp_r3_1566 = this->unk2C8;
            if (temp_r3_1566 != 0) {
                M2C_FIELD(temp_r3_1566, AssaultCannon **, 0x130) = this;
                temp_r4_1573 = this->unk8;
                temp_r30_1575 = ((u8 *) temp_r4_1573) + 0x30;
                temp_r3_1579 = M2C_FIELD(gb.unk0->GetProp(temp_r4_1573), void **, 8);
                temp_f1_1580 = M2C_FIELD(temp_r3_1579, f64 *, 0x30);
                sp3C0 = temp_f1_1580;
                sp3C8 = M2C_FIELD(temp_r3_1579, f64 *, 0x38);
                sp180 = temp_f1_1580 - M2C_FIELD(temp_r30_1575, f64 *, 0);
                sp3D0 = sp180;
                sp188 = (f32) sp3C8 - M2C_FIELD(temp_r30_1575, f32 *, 8);
                sp3D8 = (f64) sp188;
                var_f4_1603 = ((f32) sp3D8 * (f32) sp3D8) + (((f32) sp3D0 * (f32) sp3D0) + ((*(f32 *) ((u8 *) &sp3D0 + 0x4)) * (*(f32 *) ((u8 *) &sp3D0 + 0x4))));
                if (var_f4_1603 > 0.0f) {
                    temp_f1_1606 = __frsqrte(var_f4_1603);
                    temp_f1_1612 = 0.5 * temp_f1_1606 * -(((f64) var_f4_1603 * (temp_f1_1606 * temp_f1_1606)) - 3.0);
                    temp_f1_1616 = 0.5 * temp_f1_1612 * -(((f64) var_f4_1603 * (temp_f1_1612 * temp_f1_1612)) - 3.0);
                    var_f4_1603 = (f32) ((f64) var_f4_1603 * (0.5 * temp_f1_1616 * -(((f64) var_f4_1603 * (temp_f1_1616 * temp_f1_1616)) - 3.0)));
                } else if (var_f4_1603 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1603 = __float_nan;
                } else {
                    sp2C = var_f4_1603;
                    temp_r3_1635 = M2C_BITWISE(s32, sp2C) & 0x7F800000;
                    switch (temp_r3_1635) {         /* switch 6; irregular */
                    case 0x7F800000:                /* switch 6 */
                        if (M2C_BITWISE(s32, sp2C) & 0x7FFFFF) {
                            var_r0_1645 = 1;
                        } else {
                            var_r0_1645 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 6 */
                        if (M2C_BITWISE(s32, sp2C) & 0x7FFFFF) {
                            var_r0_1645 = 5;
                        } else {
                            var_r0_1645 = 3;
                        }
                        break;
                    default:                        /* switch 6 */
                        var_r0_1645 = 4;
                        break;
                    }
                    if (var_r0_1645 == 1) {
                        var_f4_1603 = __float_nan;
                    }
                }
                var_f31_1668 = var_f4_1603 - 500.0f;
                if (var_f31_1668 < 20000.0f) {

                } else {
                    var_f31_1668 = 20000.0f;
                }
                if (var_f31_1668 > 500.0f) {

                } else {
                    var_f31_1668 = 500.0f;
                }
                temp_r4_1682 = this->unk2BC;
                if (temp_r4_1682 != -1U) {
                    MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_1682, &this->unk230);
                } else {
                    temp_r3_1691 = this->unk8;
                    M2C_FIELD(this, f64 *, 0x230) = (f64) M2C_FIELD(temp_r3_1691, f64 *, 0x30);
                    M2C_FIELD(this, f64 *, 0x238) = (f64) M2C_FIELD(temp_r3_1691, f64 *, 0x38);
                }
                temp_r3_1699 = ((u8 *) this->unk8) + 0x30;
                temp_f0_1702 = M2C_FIELD(this, f64 *, 0x230) - M2C_FIELD(temp_r3_1699, f64 *, 0);
                sp170 = temp_f0_1702;
                var_f4_1708 = 0.0f;
                sp500 = temp_f0_1702;
                sp178 = this->unk230.unk8 - M2C_FIELD(temp_r3_1699, f32 *, 8);
                (*(f32 *) ((u8 *) &sp4B8 + 0x4c)) = 0.0f;
                sp508 = (f64) sp178;
                var_f5_1721 = ((f32) sp508 * (f32) sp508) + (((f32) sp500 * (f32) sp500) + (0.0f * 0.0f));
                if (var_f5_1721 > 0.000001f) {
                    if (var_f5_1721 > 0.0f) {
                        temp_f1_1726 = __frsqrte(var_f5_1721);
                        temp_f1_1732 = 0.5 * temp_f1_1726 * -(((f64) var_f5_1721 * (temp_f1_1726 * temp_f1_1726)) - 3.0);
                        temp_f1_1736 = 0.5 * temp_f1_1732 * -(((f64) var_f5_1721 * (temp_f1_1732 * temp_f1_1732)) - 3.0);
                        var_f5_1721 = (f32) ((f64) var_f5_1721 * (0.5 * temp_f1_1736 * -(((f64) var_f5_1721 * (temp_f1_1736 * temp_f1_1736)) - 3.0)));
                    } else if (var_f5_1721 < M2C_BITWISE(f32, 0.0)) {
                        var_f5_1721 = __float_nan;
                    } else {
                        sp28 = var_f5_1721;
                        temp_r3_1755 = M2C_BITWISE(s32, sp28) & 0x7F800000;
                        switch (temp_r3_1755) {     /* switch 7; irregular */
                        case 0x7F800000:            /* switch 7 */
                            if (M2C_BITWISE(s32, sp28) & 0x7FFFFF) {
                                var_r0_1765 = 1;
                            } else {
                                var_r0_1765 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 7 */
                            if (M2C_BITWISE(s32, sp28) & 0x7FFFFF) {
                                var_r0_1765 = 5;
                            } else {
                                var_r0_1765 = 3;
                            }
                            break;
                        default:                    /* switch 7 */
                            var_r0_1765 = 4;
                            break;
                        }
                        if (var_r0_1765 == 1) {
                            var_f5_1721 = __float_nan;
                        }
                    }
                    var_f4_1708 = 1.0f / var_f5_1721;
                }
                sp500 = (f32) sp500 * var_f4_1708;
                (*(f32 *) ((u8 *) &sp4B8 + 0x4c)) *= var_f4_1708;
                sp508 = (f32) sp508 * var_f4_1708;
                sp3A0.operator*(var_f31_1668);
                sp90 = M2C_FIELD(this, f64 *, 0x230) + M2C_BITWISE(f64, sp3A0);
                this->unk240 = sp90;
                sp98 = this->unk230.unk8 + sp3A0.unk8;
                sp3B0 = sp90;
                M2C_FIELD(this, f64 *, 0x248) = (f64) sp98;
                sp3B8 = (f64) sp98;
                temp_f0_1819 = (f64) sp500 * 5.439686476e-315;
                sp80 = temp_f0_1819;
                sp390 = temp_f0_1819;
                sp88 = sp508 * 20.0f;
                sp398 = (f64) sp88;
                M2C_FIELD(this, f64 *, 0x230) = (f64) (M2C_FIELD(this, f64 *, 0x230) + temp_f0_1819);
                temp_f2_1835 = this->unk230.unk8;
                this->unk230.unk8 = temp_f2_1835 + (f32) sp398;
                temp_r3_1842 = this->unk2C8;
                M2C_FIELD(M2C_FIELD(temp_r3_1842, void **, 0x44), M2C_UNK (**)(u32, MKVector3 *, f64 *, AssaultCannon *, M2C_UNK, M2C_UNK, f32, f32), 0x4C)(temp_r3_1842, &this->unk230, &this->unk240, this, 0, 0, 2000.0f, temp_f2_1835);
                KDSound_Play3d(GS_EarthTurrentFire, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
                temp_r3_1855 = this->unk2C8;
                M2C_FIELD(M2C_FIELD(temp_r3_1855, void **, 0x44), M2C_UNK (**)(u32), 0x24)(temp_r3_1855);
                EmitShootingFX();
                return;
            }
        }
        break;
    case 2:                                         /* switch 1 */
        this->unk2CC = M2C_BITWISE(f32, this->unk2CC) - gUpdateTimeDelta;
        if (M2C_BITWISE(f32, this->unk2CC) <= 0.0f) {
            this->unk218.SetState(this, 1, 0U);
            return;
        }
        temp_r4_1881 = this->unk8;
        temp_r30_1884 = ((u8 *) temp_r4_1881) + 0x30;
        temp_r3_1888 = gb.unk0->GetTargetable(temp_r4_1881);
        M2C_FIELD(*temp_r3_1888, M2C_UNK (**)(f64 *, void **), 0x30)(&sp360, temp_r3_1888);
        temp_r3_1902 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
        temp_f1_1903 = M2C_FIELD(temp_r3_1902, f64 *, 0x30);
        sp370 = temp_f1_1903;
        sp378 = M2C_FIELD(temp_r3_1902, f64 *, 0x38);
        temp_f0_1909 = temp_f1_1903 + sp360;
        sp160 = temp_f0_1909;
        sp380 = temp_f0_1909;
        sp168 = (f32) sp378 + sp368;
        sp388 = (f64) sp168;
        temp_f0_1921 = sp380 - M2C_FIELD(temp_r30_1884, f64 *, 0);
        sp150 = temp_f0_1921;
        var_f4_1927 = 0.0f;
        sp4F0 = temp_f0_1921;
        sp158 = (f32) sp388 - M2C_FIELD(temp_r30_1884, f32 *, 8);
        (*(f32 *) ((u8 *) &sp4B8 + 0x3c)) = 0.0f;
        sp4F8 = (f64) sp158;
        var_f5_1940 = ((f32) sp4F8 * (f32) sp4F8) + (((f32) sp4F0 * (f32) sp4F0) + (0.0f * 0.0f));
        if (var_f5_1940 > 0.000001f) {
            if (var_f5_1940 > 0.0f) {
                temp_f1_1945 = __frsqrte(var_f5_1940);
                temp_f1_1951 = 0.5 * temp_f1_1945 * -(((f64) var_f5_1940 * (temp_f1_1945 * temp_f1_1945)) - 3.0);
                temp_f1_1955 = 0.5 * temp_f1_1951 * -(((f64) var_f5_1940 * (temp_f1_1951 * temp_f1_1951)) - 3.0);
                var_f5_1940 = (f32) ((f64) var_f5_1940 * (0.5 * temp_f1_1955 * -(((f64) var_f5_1940 * (temp_f1_1955 * temp_f1_1955)) - 3.0)));
            } else if (var_f5_1940 < M2C_BITWISE(f32, 0.0)) {
                var_f5_1940 = __float_nan;
            } else {
                sp24 = var_f5_1940;
                temp_r3_1974 = M2C_BITWISE(s32, sp24) & 0x7F800000;
                switch (temp_r3_1974) {             /* switch 8; irregular */
                case 0x7F800000:                    /* switch 8 */
                    if (M2C_BITWISE(s32, sp24) & 0x7FFFFF) {
                        var_r0_1984 = 1;
                    } else {
                        var_r0_1984 = 2;
                    }
                    break;
                case 0x0:                           /* switch 8 */
                    if (M2C_BITWISE(s32, sp24) & 0x7FFFFF) {
                        var_r0_1984 = 5;
                    } else {
                        var_r0_1984 = 3;
                    }
                    break;
                default:                            /* switch 8 */
                    var_r0_1984 = 4;
                    break;
                }
                if (var_r0_1984 == 1) {
                    var_f5_1940 = __float_nan;
                }
            }
            var_f4_1927 = 1.0f / var_f5_1940;
        }
        sp4F0 = (f32) sp4F0 * var_f4_1927;
        (*(f32 *) ((u8 *) &sp4B8 + 0x3c)) *= var_f4_1927;
        sp4F8 = (f32) sp4F8 * var_f4_1927;
        sp350 = (f64) sp4F0;
        sp358 = (f64) sp4F8;
        UpdateTurning((MKVector3) &sp350);
        if ((u32) this->unk2C8 != 0) {
            temp_r4_2027 = this->unk2BC;
            if (temp_r4_2027 != -1U) {
                MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_2027, &this->unk230);
            } else {
                temp_r3_2036 = this->unk8;
                M2C_FIELD(this, f64 *, 0x230) = (f64) M2C_FIELD(temp_r3_2036, f64 *, 0x30);
                M2C_FIELD(this, f64 *, 0x238) = (f64) M2C_FIELD(temp_r3_2036, f64 *, 0x38);
            }
            MKVector(0.0f, 100.0f, 0.0f);
            sp330.GetPos();
            sp70 = sp330 + sp320;
            this->unk240 = sp70;
            sp78 = sp338 + sp328;
            sp340 = sp70;
            sp348 = (f64) sp78;
            M2C_FIELD(this, f64 *, 0x248) = (f64) sp78;
            return;
        }
        break;
    case 3:                                         /* switch 1 */
        this->unk2CC = M2C_BITWISE(f32, this->unk2CC) - gUpdateTimeDelta;
        if (M2C_BITWISE(f32, this->unk2CC) <= 0.0f) {
            this->unk218.SetState(this, 1, 0U);
            return;
        }
        if (gb.unk0->GetTargetable() != 0U) {
            temp_r4_2095 = this->unk8;
            temp_r30_2098 = ((u8 *) temp_r4_2095) + 0x30;
            temp_r3_2102 = gb.unk0->GetTargetable(temp_r4_2095);
            M2C_FIELD(*temp_r3_2102, M2C_UNK (**)(f64 *, void **), 0x30)(&sp2F0, temp_r3_2102);
            temp_r3_2116 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
            temp_f1_2117 = M2C_FIELD(temp_r3_2116, f64 *, 0x30);
            sp300 = temp_f1_2117;
            sp308 = M2C_FIELD(temp_r3_2116, f64 *, 0x38);
            temp_f0_2123 = temp_f1_2117 + sp2F0;
            sp140 = temp_f0_2123;
            sp310 = temp_f0_2123;
            sp148 = (f32) sp308 + sp2F8;
            sp318 = (f64) sp148;
            temp_f0_2135 = sp310 - M2C_FIELD(temp_r30_2098, f64 *, 0);
            sp130 = temp_f0_2135;
            var_f4_2141 = 0.0f;
            sp4E0 = temp_f0_2135;
            sp138 = (f32) sp318 - M2C_FIELD(temp_r30_2098, f32 *, 8);
            (*(f32 *) ((u8 *) &sp4B8 + 0x2c)) = 0.0f;
            sp4E8 = (f64) sp138;
            var_f5_2154 = ((f32) sp4E8 * (f32) sp4E8) + (((f32) sp4E0 * (f32) sp4E0) + (0.0f * 0.0f));
            if (var_f5_2154 > 0.000001f) {
                if (var_f5_2154 > 0.0f) {
                    temp_f1_2159 = __frsqrte(var_f5_2154);
                    temp_f1_2165 = 0.5 * temp_f1_2159 * -(((f64) var_f5_2154 * (temp_f1_2159 * temp_f1_2159)) - 3.0);
                    temp_f1_2169 = 0.5 * temp_f1_2165 * -(((f64) var_f5_2154 * (temp_f1_2165 * temp_f1_2165)) - 3.0);
                    var_f5_2154 = (f32) ((f64) var_f5_2154 * (0.5 * temp_f1_2169 * -(((f64) var_f5_2154 * (temp_f1_2169 * temp_f1_2169)) - 3.0)));
                } else if (var_f5_2154 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_2154 = __float_nan;
                } else {
                    sp20 = var_f5_2154;
                    temp_r3_2188 = M2C_BITWISE(s32, sp20) & 0x7F800000;
                    switch (temp_r3_2188) {         /* switch 9; irregular */
                    case 0x7F800000:                /* switch 9 */
                        if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
                            var_r0_2198 = 1;
                        } else {
                            var_r0_2198 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 9 */
                        if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
                            var_r0_2198 = 5;
                        } else {
                            var_r0_2198 = 3;
                        }
                        break;
                    default:                        /* switch 9 */
                        var_r0_2198 = 4;
                        break;
                    }
                    if (var_r0_2198 == 1) {
                        var_f5_2154 = __float_nan;
                    }
                }
                var_f4_2141 = 1.0f / var_f5_2154;
            }
            sp4E0 = (f32) sp4E0 * var_f4_2141;
            (*(f32 *) ((u8 *) &sp4B8 + 0x2c)) *= var_f4_2141;
            sp4E8 = (f32) sp4E8 * var_f4_2141;
            sp2E0 = (f64) sp4E0;
            sp2E8 = (f64) sp4E8;
            UpdateTurning((MKVector3) &sp2E0);
            if ((u32) this->unk2C8 != 0) {
                var_f2_2241 = M2C_BITWISE(f32, this->unk2CC);
                if (var_f2_2241 < 2.0f) {

                } else {
                    var_f2_2241 = 2.0f;
                }
                if (var_f2_2241 > 0.0f) {

                } else {
                    var_f2_2241 = 0.0f;
                }
                temp_r4_2257 = this->unk8;
                temp_r30_2261 = ((u8 *) temp_r4_2257) + 0x30;
                temp_r3_2270 = M2C_FIELD(gb.unk0->GetProp(temp_r4_2257, 0.05f), void **, 8);
                temp_f1_2271 = M2C_FIELD(temp_r3_2270, f64 *, 0x30);
                sp2C0 = temp_f1_2271;
                sp2C8 = M2C_FIELD(temp_r3_2270, f64 *, 0x38);
                sp120 = temp_f1_2271 - M2C_FIELD(temp_r30_2261, f64 *, 0);
                sp2D0 = sp120;
                sp128 = (f32) sp2C8 - M2C_FIELD(temp_r30_2261, f32 *, 8);
                sp2D8 = (f64) sp128;
                var_f4_2294 = ((f32) sp2D8 * (f32) sp2D8) + (((f32) sp2D0 * (f32) sp2D0) + ((*(f32 *) ((u8 *) &sp2D0 + 0x4)) * (*(f32 *) ((u8 *) &sp2D0 + 0x4))));
                if (var_f4_2294 > 0.0f) {
                    temp_f1_2297 = __frsqrte(var_f4_2294);
                    temp_f1_2303 = 0.5 * temp_f1_2297 * -(((f64) var_f4_2294 * (temp_f1_2297 * temp_f1_2297)) - 3.0);
                    temp_f1_2307 = 0.5 * temp_f1_2303 * -(((f64) var_f4_2294 * (temp_f1_2303 * temp_f1_2303)) - 3.0);
                    var_f4_2294 = (f32) ((f64) var_f4_2294 * (0.5 * temp_f1_2307 * -(((f64) var_f4_2294 * (temp_f1_2307 * temp_f1_2307)) - 3.0)));
                } else if (var_f4_2294 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_2294 = __float_nan;
                } else {
                    sp1C = var_f4_2294;
                    temp_r3_2326 = M2C_BITWISE(s32, sp1C) & 0x7F800000;
                    switch (temp_r3_2326) {         /* switch 10; irregular */
                    case 0x7F800000:                /* switch 10 */
                        if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                            var_r0_2336 = 1;
                        } else {
                            var_r0_2336 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 10 */
                        if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                            var_r0_2336 = 5;
                        } else {
                            var_r0_2336 = 3;
                        }
                        break;
                    default:                        /* switch 10 */
                        var_r0_2336 = 4;
                        break;
                    }
                    if (var_r0_2336 == 1) {
                        var_f4_2294 = __float_nan;
                    }
                }
                var_f31_2359 = var_f4_2294 - 500.0f;
                if (var_f31_2359 < 20000.0f) {

                } else {
                    var_f31_2359 = 20000.0f;
                }
                if (var_f31_2359 > 500.0f) {

                } else {
                    var_f31_2359 = 500.0f;
                }
                temp_r4_2373 = this->unk2BC;
                if (temp_r4_2373 != -1U) {
                    MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_2373, &this->unk230);
                } else {
                    temp_r3_2382 = this->unk8;
                    M2C_FIELD(this, f64 *, 0x230) = (f64) M2C_FIELD(temp_r3_2382, f64 *, 0x30);
                    M2C_FIELD(this, f64 *, 0x238) = (f64) M2C_FIELD(temp_r3_2382, f64 *, 0x38);
                }
                temp_r3_2390 = ((u8 *) this->unk8) + 0x30;
                temp_f0_2393 = M2C_FIELD(this, f64 *, 0x230) - M2C_FIELD(temp_r3_2390, f64 *, 0);
                sp110 = temp_f0_2393;
                var_f4_2399 = 0.0f;
                sp4D0 = temp_f0_2393;
                sp118 = this->unk230.unk8 - M2C_FIELD(temp_r3_2390, f32 *, 8);
                (*(f32 *) ((u8 *) &sp4B8 + 0x1c)) = 0.0f;
                sp4D8 = (f64) sp118;
                var_f5_2412 = ((f32) sp4D8 * (f32) sp4D8) + (((f32) sp4D0 * (f32) sp4D0) + (0.0f * 0.0f));
                if (var_f5_2412 > 0.000001f) {
                    if (var_f5_2412 > 0.0f) {
                        temp_f1_2417 = __frsqrte(var_f5_2412);
                        temp_f1_2423 = 0.5 * temp_f1_2417 * -(((f64) var_f5_2412 * (temp_f1_2417 * temp_f1_2417)) - 3.0);
                        temp_f1_2427 = 0.5 * temp_f1_2423 * -(((f64) var_f5_2412 * (temp_f1_2423 * temp_f1_2423)) - 3.0);
                        var_f5_2412 = (f32) ((f64) var_f5_2412 * (0.5 * temp_f1_2427 * -(((f64) var_f5_2412 * (temp_f1_2427 * temp_f1_2427)) - 3.0)));
                    } else if (var_f5_2412 < M2C_BITWISE(f32, 0.0)) {
                        var_f5_2412 = __float_nan;
                    } else {
                        sp18 = var_f5_2412;
                        temp_r3_2446 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                        switch (temp_r3_2446) {     /* switch 11; irregular */
                        case 0x7F800000:            /* switch 11 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_2456 = 1;
                            } else {
                                var_r0_2456 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 11 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_2456 = 5;
                            } else {
                                var_r0_2456 = 3;
                            }
                            break;
                        default:                    /* switch 11 */
                            var_r0_2456 = 4;
                            break;
                        }
                        if (var_r0_2456 == 1) {
                            var_f5_2412 = __float_nan;
                        }
                    }
                    var_f4_2399 = 1.0f / var_f5_2412;
                }
                sp4D0 = (f32) sp4D0 * var_f4_2399;
                (*(f32 *) ((u8 *) &sp4B8 + 0x1c)) *= var_f4_2399;
                sp4D8 = (f32) sp4D8 * var_f4_2399;
                sp290.operator*(var_f31_2359);
                sp2A0.operator*(0.05f + -((var_f2_2241 * 0.5f) - 1.0f));
                sp60 = M2C_FIELD(this, f64 *, 0x230) + M2C_BITWISE(f64, sp2A0);
                this->unk240 = sp60;
                sp68 = this->unk230.unk8 + sp2A0.unk8;
                sp2B0 = sp60;
                M2C_FIELD(this, f64 *, 0x248) = (f64) sp68;
                sp2B8 = (f64) sp68;
                temp_f0_2514 = (f64) sp4D0 * 5.45263811e-315;
                sp50 = temp_f0_2514;
                sp280 = temp_f0_2514;
                sp58 = sp4D8 * 25.0f;
                sp288 = (f64) sp58;
                M2C_FIELD(this, f64 *, 0x230) = (f64) (M2C_FIELD(this, f64 *, 0x230) + temp_f0_2514);
                this->unk230.unk8 += (f32) sp288;
                return;
            }
        }
        break;
    case 4:                                         /* switch 1 */
        temp_r4_2534 = this->unk8;
        temp_r30_2537 = ((u8 *) temp_r4_2534) + 0x30;
        temp_r3_2542 = M2C_FIELD(gb.unk0->GetProp(temp_r4_2534), void **, 8);
        temp_f1_2543 = M2C_FIELD(temp_r3_2542, f64 *, 0x30);
        sp260 = temp_f1_2543;
        sp268 = M2C_FIELD(temp_r3_2542, f64 *, 0x38);
        sp100 = temp_f1_2543 - M2C_FIELD(temp_r30_2537, f64 *, 0);
        sp270 = sp100;
        sp108 = (f32) sp268 - M2C_FIELD(temp_r30_2537, f32 *, 8);
        sp278 = (f64) sp108;
        var_f4_2566 = ((f32) sp278 * (f32) sp278) + (((f32) sp270 * (f32) sp270) + ((*(f32 *) ((u8 *) &sp270 + 0x4)) * (*(f32 *) ((u8 *) &sp270 + 0x4))));
        if (var_f4_2566 > 0.0f) {
            temp_f1_2569 = __frsqrte(var_f4_2566);
            temp_f1_2575 = 0.5 * temp_f1_2569 * -(((f64) var_f4_2566 * (temp_f1_2569 * temp_f1_2569)) - 3.0);
            temp_f1_2579 = 0.5 * temp_f1_2575 * -(((f64) var_f4_2566 * (temp_f1_2575 * temp_f1_2575)) - 3.0);
            var_f4_2566 = (f32) ((f64) var_f4_2566 * (0.5 * temp_f1_2579 * -(((f64) var_f4_2566 * (temp_f1_2579 * temp_f1_2579)) - 3.0)));
        } else if (var_f4_2566 < M2C_BITWISE(f32, 0.0)) {
            var_f4_2566 = __float_nan;
        } else {
            sp14 = var_f4_2566;
            temp_r3_2598 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_2598) {                 /* switch 12; irregular */
            case 0x7F800000:                        /* switch 12 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_2608 = 1;
                } else {
                    var_r0_2608 = 2;
                }
                break;
            case 0x0:                               /* switch 12 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_2608 = 5;
                } else {
                    var_r0_2608 = 3;
                }
                break;
            default:                                /* switch 12 */
                var_r0_2608 = 4;
                break;
            }
            if (var_r0_2608 == 1) {
                var_f4_2566 = __float_nan;
            }
        }
        temp_f29_2633 = var_f4_2566 / 12000.0f;
        sp544 = NULL;
        sp548 = temp_f29_2633;
        sp540 = 0x62;
        sp544 = this;
        sp550 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        sp558 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        gb.unk0->Message(&sp540, M2C_FIELD(&MKVector3::zero, f64 *, 0));
        this->unk240 = sp550;
        M2C_FIELD(this, f64 *, 0x248) = sp558;
        temp_r3_2657 = ((u8 *) this->unk8) + 0x30;
        spF0 = this->unk240 - M2C_FIELD(temp_r3_2657, f64 *, 0);
        sp250 = spF0;
        spF8 = this->unk230.unk0 - M2C_FIELD(temp_r3_2657, f32 *, 8);
        sp258 = (f64) spF8;
        var_f31_2677 = ((f32) sp258 * (f32) sp258) + (((f32) sp250 * (f32) sp250) + ((*(f32 *) ((u8 *) &sp250 + 0x4)) * (*(f32 *) ((u8 *) &sp250 + 0x4))));
        if (var_f31_2677 > 0.0f) {
            temp_f1_2680 = __frsqrte(var_f31_2677);
            temp_f1_2686 = 0.5 * temp_f1_2680 * -(((f64) var_f31_2677 * (temp_f1_2680 * temp_f1_2680)) - 3.0);
            temp_f1_2690 = 0.5 * temp_f1_2686 * -(((f64) var_f31_2677 * (temp_f1_2686 * temp_f1_2686)) - 3.0);
            var_f31_2677 = (f32) ((f64) var_f31_2677 * (0.5 * temp_f1_2690 * -(((f64) var_f31_2677 * (temp_f1_2690 * temp_f1_2690)) - 3.0)));
        } else if (var_f31_2677 < M2C_BITWISE(f32, 0.0)) {
            var_f31_2677 = __float_nan;
        } else {
            sp10 = var_f31_2677;
            temp_r3_2709 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_2709) {                 /* switch 13; irregular */
            case 0x7F800000:                        /* switch 13 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_2719 = 1;
                } else {
                    var_r0_2719 = 2;
                }
                break;
            case 0x0:                               /* switch 13 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_2719 = 5;
                } else {
                    var_r0_2719 = 3;
                }
                break;
            default:                                /* switch 13 */
                var_r0_2719 = 4;
                break;
            }
            if (var_r0_2719 == 1) {
                var_f31_2677 = __float_nan;
            }
        }
        temp_r3_2742 = ((u8 *) this->unk8) + 0x30;
        temp_f0_2745 = this->unk240 - M2C_FIELD(temp_r3_2742, f64 *, 0);
        spE0 = temp_f0_2745;
        var_f4_2751 = 0.0f;
        sp4C0 = temp_f0_2745;
        spE8 = this->unk230.unk0 - M2C_FIELD(temp_r3_2742, f32 *, 8);
        (*(f32 *) ((u8 *) &sp4B8 + 0xc)) = 0.0f;
        sp4C8 = (f64) spE8;
        var_f5_2764 = ((f32) sp4C8 * (f32) sp4C8) + (((f32) sp4C0 * (f32) sp4C0) + (0.0f * 0.0f));
        if (var_f5_2764 > 0.000001f) {
            if (var_f5_2764 > 0.0f) {
                temp_f1_2769 = __frsqrte(var_f5_2764);
                temp_f1_2775 = 0.5 * temp_f1_2769 * -(((f64) var_f5_2764 * (temp_f1_2769 * temp_f1_2769)) - 3.0);
                temp_f1_2779 = 0.5 * temp_f1_2775 * -(((f64) var_f5_2764 * (temp_f1_2775 * temp_f1_2775)) - 3.0);
                var_f5_2764 = (f32) ((f64) var_f5_2764 * (0.5 * temp_f1_2779 * -(((f64) var_f5_2764 * (temp_f1_2779 * temp_f1_2779)) - 3.0)));
            } else if (var_f5_2764 < M2C_BITWISE(f32, 0.0)) {
                var_f5_2764 = __float_nan;
            } else {
                spC = var_f5_2764;
                temp_r3_2798 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_2798) {             /* switch 14; irregular */
                case 0x7F800000:                    /* switch 14 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_2808 = 1;
                    } else {
                        var_r0_2808 = 2;
                    }
                    break;
                case 0x0:                           /* switch 14 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_2808 = 5;
                    } else {
                        var_r0_2808 = 3;
                    }
                    break;
                default:                            /* switch 14 */
                    var_r0_2808 = 4;
                    break;
                }
                if (var_r0_2808 == 1) {
                    var_f5_2764 = __float_nan;
                }
            }
            var_f4_2751 = 1.0f / var_f5_2764;
        }
        sp4C0 = (f32) sp4C0 * var_f4_2751;
        (*(f32 *) ((u8 *) &sp4B8 + 0xc)) *= var_f4_2751;
        sp4C8 = (f32) sp4C8 * var_f4_2751;
        sp240 = (f64) sp4C0;
        sp248 = (f64) sp4C8;
        temp_r4_2847 = (u32) UpdateTurning((MKVector3) &sp240);
        temp_r3_2848 = this->unk2C8;
        if (temp_r3_2848 != 0) {
            M2C_FIELD(temp_r3_2848, AssaultCannon **, 0x130) = NULL;
            this->unk2C8 = 0;
        }
        this->unk2C8 = ((Projectile *)0x15)->CreateInstance((ProjectileType) temp_r4_2847);
        temp_r3_2858 = this->unk2C8;
        if (temp_r3_2858 != 0) {
            M2C_FIELD(temp_r3_2858, AssaultCannon **, 0x130) = this;
            temp_r4_2862 = this->unk2BC;
            if (temp_r4_2862 != -1U) {
                MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_2862, &this->unk230);
            } else {
                temp_r3_2871 = this->unk8;
                M2C_FIELD(this, f64 *, 0x230) = (f64) M2C_FIELD(temp_r3_2871, f64 *, 0x30);
                M2C_FIELD(this, f64 *, 0x238) = (f64) M2C_FIELD(temp_r3_2871, f64 *, 0x38);
            }
            temp_f28_2878 = var_f31_2677 / temp_f29_2633;
            spD0 = this->unk240 - M2C_FIELD(this, f64 *, 0x230);
            sp220 = spD0;
            spD8 = this->unk230.unk0 - this->unk230.unk8;
            sp228 = (f64) spD8;
            var_f4_2899 = ((f32) sp228 * (f32) sp228) + (((f32) sp220 * (f32) sp220) + ((*(f32 *) ((u8 *) &sp220 + 0x4)) * (*(f32 *) ((u8 *) &sp220 + 0x4))));
            if (var_f4_2899 > 1e-12f) {
                if (var_f4_2899 > 0.0f) {
                    temp_f1_2905 = __frsqrte(var_f4_2899);
                    temp_f1_2911 = 0.5 * temp_f1_2905 * -(((f64) var_f4_2899 * (temp_f1_2905 * temp_f1_2905)) - 3.0);
                    temp_f1_2915 = 0.5 * temp_f1_2911 * -(((f64) var_f4_2899 * (temp_f1_2911 * temp_f1_2911)) - 3.0);
                    var_f4_2899 = (f32) ((f64) var_f4_2899 * (0.5 * temp_f1_2915 * -(((f64) var_f4_2899 * (temp_f1_2915 * temp_f1_2915)) - 3.0)));
                } else if (var_f4_2899 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_2899 = __float_nan;
                } else {
                    sp8 = var_f4_2899;
                    temp_r3_2934 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_2934) {         /* switch 15; irregular */
                    case 0x7F800000:                /* switch 15 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_2944 = 1;
                        } else {
                            var_r0_2944 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 15 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_2944 = 5;
                        } else {
                            var_r0_2944 = 3;
                        }
                        break;
                    default:                        /* switch 15 */
                        var_r0_2944 = 4;
                        break;
                    }
                    if (var_r0_2944 == 1) {
                        var_f4_2899 = __float_nan;
                    }
                }
                var_f3_2966 = 1.0f / var_f4_2899;
            } else {
                var_f3_2966 = 0.0f;
            }
            spB4 = (*(f32 *) ((u8 *) &sp220 + 0x4)) * var_f3_2966;
            spB0 = (f32) sp220 * var_f3_2966;
            spB8 = (f32) sp228 * var_f3_2966;
            sp230 = (f64) spB0;
            sp238 = (f64) spB8;
            temp_f0_2983 = sp230 * (f64) temp_f28_2878;
            spC0 = temp_f0_2983;
            sp4B0 = temp_f0_2983;
            spC8 = (f32) sp238 * temp_f28_2878;
            sp4B8 = (f64) spC8;
            Normalise(sp200);
            temp_f0_2998 = sp200 * 5.439686476e-315;
            sp40 = temp_f0_2998;
            sp210 = temp_f0_2998;
            sp48 = sp200.unk8 * 20.0f;
            sp218 = (f64) sp48;
            M2C_FIELD(this, f64 *, 0x230) = (f64) (M2C_FIELD(this, f64 *, 0x230) + temp_f0_2998);
            this->unk230.unk8 += (f32) sp218;
            Tools_CalculateVelocity(sp1F0, this->unk230, temp_f28_2878, -1960.0f);
            temp_f1_3022 = M2C_BITWISE(f64, sp1F0);
            sp4B0 = temp_f1_3022;
            sp4B8 = (f64) sp1F0.unk8;
            temp_r3_3031 = this->unk2C8;
            M2C_FIELD(M2C_FIELD(temp_r3_3031, void **, 0x44), M2C_UNK (**)(u32, MKVector3 *, f64 *, AssaultCannon *, M2C_UNK, M2C_UNK, f64), 0x48)(temp_r3_3031, &this->unk230, &sp4B0, this, 0, 0, temp_f1_3022);
            temp_r3_3036 = this->unk2C8;
            M2C_FIELD(M2C_FIELD(temp_r3_3036, void **, 0x44), M2C_UNK (**)(u32), 0x24)(temp_r3_3036);
            EmitShootingFX();
        }
        this->unk218.SetState(this, 1, 0U);
        break;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'AssaultCannonDescriptor *' to
void AssaultCannon::StateFireEnter() {
    s8 sp271;
    s8 sp270;
    s32 sp26C;
    f32 sp268;
    s32 sp264;
    s8 sp262;
    s8 sp261;
    s8 sp260;
    f64 sp258;                                      /* compiler-managed */
    f64 sp250;                                      /* compiler-managed */
    AssaultCannon *sp24C;
    s32 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    s32 sp224;
    s32 sp220;
    f64 sp218;                                      /* compiler-managed */
    f64 sp210;                                      /* compiler-managed */
    f64 sp208;                                      /* compiler-managed */
    f64 sp200;                                      /* compiler-managed */
    f64 sp1F8;                                      /* compiler-managed */
    f64 sp1F0;                                      /* compiler-managed */
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    MKVector3 sp1B0;
    MKVector3 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    MKVector3 sp160;
    MKVector3 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    MKVector3 sp100;
    MKVector3 spF0;
    f64 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ShatterableDescriptor *temp_r3_3080;
    f32 temp_f1_4060;
    f32 temp_f2_3376;
    f32 temp_f2_3681;
    f32 temp_f2_4032;
    f32 var_f1_3419;
    f32 var_f2_3115;
    f32 var_f2_3772;
    f32 var_f31_3232;
    f32 var_f31_3537;
    f32 var_f31_3889;
    f32 var_f4_3167;
    f32 var_f4_3272;
    f32 var_f4_3472;
    f32 var_f4_3577;
    f32 var_f4_3824;
    f32 var_f4_3929;
    f32 var_f5_3285;
    f32 var_f5_3590;
    f32 var_f5_3942;
    f64 temp_f0_3266;
    f64 temp_f0_3571;
    f64 temp_f0_3923;
    f64 temp_f0_4044;
    f64 temp_f1_3144;
    f64 temp_f1_3170;
    f64 temp_f1_3176;
    f64 temp_f1_3180;
    f64 temp_f1_3290;
    f64 temp_f1_3296;
    f64 temp_f1_3300;
    f64 temp_f1_3449;
    f64 temp_f1_3475;
    f64 temp_f1_3481;
    f64 temp_f1_3485;
    f64 temp_f1_3595;
    f64 temp_f1_3601;
    f64 temp_f1_3605;
    f64 temp_f1_3801;
    f64 temp_f1_3827;
    f64 temp_f1_3833;
    f64 temp_f1_3837;
    f64 temp_f1_3947;
    f64 temp_f1_3953;
    f64 temp_f1_3957;
    s32 temp_r0_3088;
    s32 temp_r3_3199;
    s32 temp_r3_3319;
    s32 temp_r3_3504;
    s32 temp_r3_3624;
    s32 temp_r3_3856;
    s32 temp_r3_3976;
    s32 var_r0_3209;
    s32 var_r0_3329;
    s32 var_r0_3514;
    s32 var_r0_3634;
    s32 var_r0_3866;
    s32 var_r0_3986;
    u32 temp_r3_3110;
    u32 temp_r3_3388;
    u32 temp_r3_3414;
    u32 temp_r3_3693;
    u32 temp_r3_3767;
    u32 temp_r3_4065;
    u32 temp_r4_3081;
    u32 temp_r4_3246;
    u32 temp_r4_3551;
    u32 temp_r4_3903;
    void *temp_r30_3134;
    void *temp_r30_3440;
    void *temp_r30_3791;
    void *temp_r3_3143;
    void *temp_r3_3255;
    void *temp_r3_3263;
    void *temp_r3_3448;
    void *temp_r3_3560;
    void *temp_r3_3568;
    void *temp_r3_3800;
    void *temp_r3_3912;
    void *temp_r3_3920;
    void *temp_r4_3130;
    void *temp_r4_3436;
    void *temp_r4_3787;

    temp_r3_3080 = checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r4_3081 = this->unk2C8;
    if (temp_r4_3081 != 0) {
        M2C_FIELD(temp_r4_3081, AssaultCannon **, 0x130) = NULL;
        this->unk2C8 = 0;
    }
    temp_r0_3088 = M2C_FIELD(temp_r3_3080, s32 *, 0x174);
    switch (temp_r0_3088) {                         /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        this->unk2CC = 2.0f;
        M2C_FIELD(this, s8 *, 0x2F0) = 1;
        this->unk2C8 = ((Projectile *)5)->CreateInstance((ProjectileType) temp_r4_3081);
        temp_r3_3110 = this->unk2C8;
        if (temp_r3_3110 != 0) {
            M2C_FIELD(temp_r3_3110, AssaultCannon **, 0x130) = this;
            var_f2_3115 = M2C_BITWISE(f32, this->unk2CC);
            if (var_f2_3115 < 2.0f) {

            } else {
                var_f2_3115 = 2.0f;
            }
            if (var_f2_3115 > 0.0f) {

            } else {
                var_f2_3115 = 0.0f;
            }
            temp_r4_3130 = this->unk8;
            temp_r30_3134 = ((u8 *) temp_r4_3130) + 0x30;
            temp_r3_3143 = M2C_FIELD(gb.unk0->GetProp(temp_r4_3130, 0.05f), void **, 8);
            temp_f1_3144 = M2C_FIELD(temp_r3_3143, f64 *, 0x30);
            sp1D0 = temp_f1_3144;
            sp1D8 = M2C_FIELD(temp_r3_3143, f64 *, 0x38);
            spD0 = temp_f1_3144 - M2C_FIELD(temp_r30_3134, f64 *, 0);
            sp1E0 = spD0;
            spD8 = (f32) sp1D8 - M2C_FIELD(temp_r30_3134, f32 *, 8);
            sp1E8 = (f64) spD8;
            var_f4_3167 = ((f32) sp1E8 * (f32) sp1E8) + (((f32) sp1E0 * (f32) sp1E0) + ((*(f32 *) ((u8 *) &sp1E0 + 0x4)) * (*(f32 *) ((u8 *) &sp1E0 + 0x4))));
            if (var_f4_3167 > 0.0f) {
                temp_f1_3170 = __frsqrte(var_f4_3167);
                temp_f1_3176 = 0.5 * temp_f1_3170 * -(((f64) var_f4_3167 * (temp_f1_3170 * temp_f1_3170)) - 3.0);
                temp_f1_3180 = 0.5 * temp_f1_3176 * -(((f64) var_f4_3167 * (temp_f1_3176 * temp_f1_3176)) - 3.0);
                var_f4_3167 = (f32) ((f64) var_f4_3167 * (0.5 * temp_f1_3180 * -(((f64) var_f4_3167 * (temp_f1_3180 * temp_f1_3180)) - 3.0)));
            } else if (var_f4_3167 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3167 = __float_nan;
            } else {
                sp1C = var_f4_3167;
                temp_r3_3199 = M2C_BITWISE(s32, sp1C) & 0x7F800000;
                switch (temp_r3_3199) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                        var_r0_3209 = 1;
                    } else {
                        var_r0_3209 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                        var_r0_3209 = 5;
                    } else {
                        var_r0_3209 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_3209 = 4;
                    break;
                }
                if (var_r0_3209 == 1) {
                    var_f4_3167 = __float_nan;
                }
            }
            var_f31_3232 = var_f4_3167 - 500.0f;
            if (var_f31_3232 < 20000.0f) {

            } else {
                var_f31_3232 = 20000.0f;
            }
            if (var_f31_3232 > 500.0f) {

            } else {
                var_f31_3232 = 500.0f;
            }
            temp_r4_3246 = this->unk2BC;
            if (temp_r4_3246 != -1U) {
                MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_3246, &this->unk230);
            } else {
                temp_r3_3255 = this->unk8;
                M2C_FIELD(this, f64 *, 0x230) = (f64) M2C_FIELD(temp_r3_3255, f64 *, 0x30);
                M2C_FIELD(this, f64 *, 0x238) = (f64) M2C_FIELD(temp_r3_3255, f64 *, 0x38);
            }
            temp_r3_3263 = ((u8 *) this->unk8) + 0x30;
            temp_f0_3266 = M2C_FIELD(this, f64 *, 0x230) - M2C_FIELD(temp_r3_3263, f64 *, 0);
            spC0 = temp_f0_3266;
            var_f4_3272 = 0.0f;
            sp210 = temp_f0_3266;
            spC8 = this->unk230.unk8 - M2C_FIELD(temp_r3_3263, f32 *, 8);
            (*(f32 *) ((u8 *) &sp1E8 + 0x2c)) = 0.0f;
            sp218 = (f64) spC8;
            var_f5_3285 = ((f32) sp218 * (f32) sp218) + (((f32) sp210 * (f32) sp210) + (0.0f * 0.0f));
            if (var_f5_3285 > 0.000001f) {
                if (var_f5_3285 > 0.0f) {
                    temp_f1_3290 = __frsqrte(var_f5_3285);
                    temp_f1_3296 = 0.5 * temp_f1_3290 * -(((f64) var_f5_3285 * (temp_f1_3290 * temp_f1_3290)) - 3.0);
                    temp_f1_3300 = 0.5 * temp_f1_3296 * -(((f64) var_f5_3285 * (temp_f1_3296 * temp_f1_3296)) - 3.0);
                    var_f5_3285 = (f32) ((f64) var_f5_3285 * (0.5 * temp_f1_3300 * -(((f64) var_f5_3285 * (temp_f1_3300 * temp_f1_3300)) - 3.0)));
                } else if (var_f5_3285 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_3285 = __float_nan;
                } else {
                    sp18 = var_f5_3285;
                    temp_r3_3319 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                    switch (temp_r3_3319) {         /* switch 3; irregular */
                    case 0x7F800000:                /* switch 3 */
                        if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                            var_r0_3329 = 1;
                        } else {
                            var_r0_3329 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 3 */
                        if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                            var_r0_3329 = 5;
                        } else {
                            var_r0_3329 = 3;
                        }
                        break;
                    default:                        /* switch 3 */
                        var_r0_3329 = 4;
                        break;
                    }
                    if (var_r0_3329 == 1) {
                        var_f5_3285 = __float_nan;
                    }
                }
                var_f4_3272 = 1.0f / var_f5_3285;
            }
            sp210 = (f32) sp210 * var_f4_3272;
            (*(f32 *) ((u8 *) &sp1E8 + 0x2c)) *= var_f4_3272;
            sp218 = (f32) sp218 * var_f4_3272;
            sp1A0.operator*(var_f31_3232);
            sp1B0.operator*(0.05f + -((var_f2_3115 * 0.5f) - 1.0f));
            sp60 = M2C_FIELD(this, f64 *, 0x230) + M2C_BITWISE(f64, sp1B0);
            temp_f2_3376 = this->unk230.unk8;
            this->unk240 = sp60;
            sp68 = temp_f2_3376 + sp1B0.unk8;
            sp1C0 = sp60;
            M2C_FIELD(this, f64 *, 0x248) = (f64) sp68;
            temp_r3_3388 = this->unk2C8;
            sp1C8 = (f64) sp68;
            M2C_FIELD(M2C_FIELD(temp_r3_3388, void **, 0x44), M2C_UNK (**)(u32, MKVector3 *, f64 *, M2C_UNK, M2C_UNK, f64, f32), 0x50)(temp_r3_3388, &this->unk230, &this->unk240, 0, 0, sp60, temp_f2_3376);
            return;
        }
        return;
    case 1:                                         /* switch 1 */
        SetAnim(4, 0, 1.0f);
        this->unk2E0 = NULL;
        this->unk2DC = 0.0f;
        return;
    case 2:                                         /* switch 1 */
        this->unk2CC = 0.5f;
        M2C_FIELD(this, s8 *, 0x2F0) = 1;
        this->unk2C8 = ((Projectile *)0x11)->CreateInstance((ProjectileType) temp_r4_3081);
        temp_r3_3414 = this->unk2C8;
        if (temp_r3_3414 != 0) {
            M2C_FIELD(temp_r3_3414, AssaultCannon **, 0x130) = this;
            var_f1_3419 = M2C_BITWISE(f32, this->unk2CC);
            if (var_f1_3419 < 0.5f) {

            } else {
                var_f1_3419 = 0.5f;
            }
            if (var_f1_3419 > 0.0f) {

            } else {
                var_f1_3419 = 0.0f;
            }
            temp_r4_3436 = this->unk8;
            temp_r30_3440 = ((u8 *) temp_r4_3436) + 0x30;
            temp_r3_3448 = M2C_FIELD(gb.unk0->GetProp(temp_r4_3436, 1.0f, 0.05f), void **, 8);
            temp_f1_3449 = M2C_FIELD(temp_r3_3448, f64 *, 0x30);
            sp180 = temp_f1_3449;
            sp188 = M2C_FIELD(temp_r3_3448, f64 *, 0x38);
            spB0 = temp_f1_3449 - M2C_FIELD(temp_r30_3440, f64 *, 0);
            sp190 = spB0;
            spB8 = (f32) sp188 - M2C_FIELD(temp_r30_3440, f32 *, 8);
            sp198 = (f64) spB8;
            var_f4_3472 = ((f32) sp198 * (f32) sp198) + (((f32) sp190 * (f32) sp190) + ((*(f32 *) ((u8 *) &sp190 + 0x4)) * (*(f32 *) ((u8 *) &sp190 + 0x4))));
            if (var_f4_3472 > 0.0f) {
                temp_f1_3475 = __frsqrte(var_f4_3472);
                temp_f1_3481 = 0.5 * temp_f1_3475 * -(((f64) var_f4_3472 * (temp_f1_3475 * temp_f1_3475)) - 3.0);
                temp_f1_3485 = 0.5 * temp_f1_3481 * -(((f64) var_f4_3472 * (temp_f1_3481 * temp_f1_3481)) - 3.0);
                var_f4_3472 = (f32) ((f64) var_f4_3472 * (0.5 * temp_f1_3485 * -(((f64) var_f4_3472 * (temp_f1_3485 * temp_f1_3485)) - 3.0)));
            } else if (var_f4_3472 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3472 = __float_nan;
            } else {
                sp14 = var_f4_3472;
                temp_r3_3504 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_3504) {             /* switch 4; irregular */
                case 0x7F800000:                    /* switch 4 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_3514 = 1;
                    } else {
                        var_r0_3514 = 2;
                    }
                    break;
                case 0x0:                           /* switch 4 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_3514 = 5;
                    } else {
                        var_r0_3514 = 3;
                    }
                    break;
                default:                            /* switch 4 */
                    var_r0_3514 = 4;
                    break;
                }
                if (var_r0_3514 == 1) {
                    var_f4_3472 = __float_nan;
                }
            }
            var_f31_3537 = var_f4_3472 - 500.0f;
            if (var_f31_3537 < 20000.0f) {

            } else {
                var_f31_3537 = 20000.0f;
            }
            if (var_f31_3537 > 500.0f) {

            } else {
                var_f31_3537 = 500.0f;
            }
            temp_r4_3551 = this->unk2BC;
            if (temp_r4_3551 != -1U) {
                MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_3551, &this->unk230);
            } else {
                temp_r3_3560 = this->unk8;
                M2C_FIELD(this, f64 *, 0x230) = (f64) M2C_FIELD(temp_r3_3560, f64 *, 0x30);
                M2C_FIELD(this, f64 *, 0x238) = (f64) M2C_FIELD(temp_r3_3560, f64 *, 0x38);
            }
            temp_r3_3568 = ((u8 *) this->unk8) + 0x30;
            temp_f0_3571 = M2C_FIELD(this, f64 *, 0x230) - M2C_FIELD(temp_r3_3568, f64 *, 0);
            spA0 = temp_f0_3571;
            var_f4_3577 = 0.0f;
            sp200 = temp_f0_3571;
            spA8 = this->unk230.unk8 - M2C_FIELD(temp_r3_3568, f32 *, 8);
            (*(f32 *) ((u8 *) &sp1E8 + 0x1c)) = 0.0f;
            sp208 = (f64) spA8;
            var_f5_3590 = ((f32) sp208 * (f32) sp208) + (((f32) sp200 * (f32) sp200) + (0.0f * 0.0f));
            if (var_f5_3590 > 0.000001f) {
                if (var_f5_3590 > 0.0f) {
                    temp_f1_3595 = __frsqrte(var_f5_3590);
                    temp_f1_3601 = 0.5 * temp_f1_3595 * -(((f64) var_f5_3590 * (temp_f1_3595 * temp_f1_3595)) - 3.0);
                    temp_f1_3605 = 0.5 * temp_f1_3601 * -(((f64) var_f5_3590 * (temp_f1_3601 * temp_f1_3601)) - 3.0);
                    var_f5_3590 = (f32) ((f64) var_f5_3590 * (0.5 * temp_f1_3605 * -(((f64) var_f5_3590 * (temp_f1_3605 * temp_f1_3605)) - 3.0)));
                } else if (var_f5_3590 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_3590 = __float_nan;
                } else {
                    sp10 = var_f5_3590;
                    temp_r3_3624 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_3624) {         /* switch 5; irregular */
                    case 0x7F800000:                /* switch 5 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_3634 = 1;
                        } else {
                            var_r0_3634 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 5 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_3634 = 5;
                        } else {
                            var_r0_3634 = 3;
                        }
                        break;
                    default:                        /* switch 5 */
                        var_r0_3634 = 4;
                        break;
                    }
                    if (var_r0_3634 == 1) {
                        var_f5_3590 = __float_nan;
                    }
                }
                var_f4_3577 = 1.0f / var_f5_3590;
            }
            sp200 = (f32) sp200 * var_f4_3577;
            (*(f32 *) ((u8 *) &sp1E8 + 0x1c)) *= var_f4_3577;
            sp208 = (f32) sp208 * var_f4_3577;
            sp150.operator*(var_f31_3537);
            sp160.operator*(0.05f + (1.0f - (var_f1_3419 / 0.5f)));
            sp50 = M2C_FIELD(this, f64 *, 0x230) + M2C_BITWISE(f64, sp160);
            temp_f2_3681 = this->unk230.unk8;
            this->unk240 = sp50;
            sp58 = temp_f2_3681 + sp160.unk8;
            sp170 = sp50;
            M2C_FIELD(this, f64 *, 0x248) = (f64) sp58;
            temp_r3_3693 = this->unk2C8;
            sp178 = (f64) sp58;
            M2C_FIELD(M2C_FIELD(temp_r3_3693, void **, 0x44), M2C_UNK (**)(u32, MKVector3 *, f64 *, M2C_UNK, M2C_UNK, f64, f32), 0x50)(temp_r3_3693, &this->unk230, &this->unk240, 0, 0, sp50, temp_f2_3681);
            sp48 = 0.0f;
            sp40 = 0.0f;
            sp44 = 0.0f;
            sp224 = 0;
            sp140 = (f64) sp40;
            sp148 = (f64) sp48;
            sp220 = 7;
            sp248 = 1;
            sp24C = this;
            sp228 = (f64) sp40;
            sp230 = (f64) sp48;
            sp260 = 1;
            sp26C = 2;
            sp268 = 10.0f;
            sp261 = 0;
            sp262 = 1;
            sp264 = -1;
            sp238 = M2C_FIELD(&MKVector3::one, f64 *, 0);
            sp240 = M2C_FIELD(&MKVector3::one, f64 *, 8);
            sp270 = 0;
            if (this != NULL) {
                ((MKProp *) &sp90)->GetPos();
                sp250 = sp90;
                sp258 = sp98;
            } else {
                sp250 = 0.0f;
                (*(f32 *) ((u8 *) &sp24C + 0x8)) = 0.0f;
                sp258 = 0.0f;
            }
            sp271 = 0;
            sp264 = GS_SpyroZapBurn;
            gb.unk0->Message(&sp220);
            return;
        }
        break;
    case 3:                                         /* switch 1 */
        this->unk2CC = 2.0f;
        M2C_FIELD(this, s8 *, 0x2F0) = 1;
        this->unk2C8 = ((Projectile *)0x12)->CreateInstance((ProjectileType) temp_r4_3081);
        temp_r3_3767 = this->unk2C8;
        if (temp_r3_3767 != 0) {
            M2C_FIELD(temp_r3_3767, AssaultCannon **, 0x130) = this;
            var_f2_3772 = M2C_BITWISE(f32, this->unk2CC);
            if (var_f2_3772 < 2.0f) {

            } else {
                var_f2_3772 = 2.0f;
            }
            if (var_f2_3772 > 0.0f) {

            } else {
                var_f2_3772 = 0.0f;
            }
            temp_r4_3787 = this->unk8;
            temp_r30_3791 = ((u8 *) temp_r4_3787) + 0x30;
            temp_r3_3800 = M2C_FIELD(gb.unk0->GetProp(temp_r4_3787, 0.05f), void **, 8);
            temp_f1_3801 = M2C_FIELD(temp_r3_3800, f64 *, 0x30);
            sp120 = temp_f1_3801;
            sp128 = M2C_FIELD(temp_r3_3800, f64 *, 0x38);
            sp80 = temp_f1_3801 - M2C_FIELD(temp_r30_3791, f64 *, 0);
            sp130 = sp80;
            sp88 = (f32) sp128 - M2C_FIELD(temp_r30_3791, f32 *, 8);
            sp138 = (f64) sp88;
            var_f4_3824 = ((f32) sp138 * (f32) sp138) + (((f32) sp130 * (f32) sp130) + ((*(f32 *) ((u8 *) &sp130 + 0x4)) * (*(f32 *) ((u8 *) &sp130 + 0x4))));
            if (var_f4_3824 > 0.0f) {
                temp_f1_3827 = __frsqrte(var_f4_3824);
                temp_f1_3833 = 0.5 * temp_f1_3827 * -(((f64) var_f4_3824 * (temp_f1_3827 * temp_f1_3827)) - 3.0);
                temp_f1_3837 = 0.5 * temp_f1_3833 * -(((f64) var_f4_3824 * (temp_f1_3833 * temp_f1_3833)) - 3.0);
                var_f4_3824 = (f32) ((f64) var_f4_3824 * (0.5 * temp_f1_3837 * -(((f64) var_f4_3824 * (temp_f1_3837 * temp_f1_3837)) - 3.0)));
            } else if (var_f4_3824 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3824 = __float_nan;
            } else {
                spC = var_f4_3824;
                temp_r3_3856 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_3856) {             /* switch 6; irregular */
                case 0x7F800000:                    /* switch 6 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_3866 = 1;
                    } else {
                        var_r0_3866 = 2;
                    }
                    break;
                case 0x0:                           /* switch 6 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_3866 = 5;
                    } else {
                        var_r0_3866 = 3;
                    }
                    break;
                default:                            /* switch 6 */
                    var_r0_3866 = 4;
                    break;
                }
                if (var_r0_3866 == 1) {
                    var_f4_3824 = __float_nan;
                }
            }
            var_f31_3889 = var_f4_3824 - 500.0f;
            if (var_f31_3889 < 20000.0f) {

            } else {
                var_f31_3889 = 20000.0f;
            }
            if (var_f31_3889 > 500.0f) {

            } else {
                var_f31_3889 = 500.0f;
            }
            temp_r4_3903 = this->unk2BC;
            if (temp_r4_3903 != -1U) {
                MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_3903, &this->unk230);
            } else {
                temp_r3_3912 = this->unk8;
                M2C_FIELD(this, f64 *, 0x230) = (f64) M2C_FIELD(temp_r3_3912, f64 *, 0x30);
                M2C_FIELD(this, f64 *, 0x238) = (f64) M2C_FIELD(temp_r3_3912, f64 *, 0x38);
            }
            temp_r3_3920 = ((u8 *) this->unk8) + 0x30;
            temp_f0_3923 = M2C_FIELD(this, f64 *, 0x230) - M2C_FIELD(temp_r3_3920, f64 *, 0);
            sp70 = temp_f0_3923;
            var_f4_3929 = 0.0f;
            sp1F0 = temp_f0_3923;
            sp78 = this->unk230.unk8 - M2C_FIELD(temp_r3_3920, f32 *, 8);
            (*(f32 *) ((u8 *) &sp1E8 + 0xc)) = 0.0f;
            sp1F8 = (f64) sp78;
            var_f5_3942 = ((f32) sp1F8 * (f32) sp1F8) + (((f32) sp1F0 * (f32) sp1F0) + (0.0f * 0.0f));
            if (var_f5_3942 > 0.000001f) {
                if (var_f5_3942 > 0.0f) {
                    temp_f1_3947 = __frsqrte(var_f5_3942);
                    temp_f1_3953 = 0.5 * temp_f1_3947 * -(((f64) var_f5_3942 * (temp_f1_3947 * temp_f1_3947)) - 3.0);
                    temp_f1_3957 = 0.5 * temp_f1_3953 * -(((f64) var_f5_3942 * (temp_f1_3953 * temp_f1_3953)) - 3.0);
                    var_f5_3942 = (f32) ((f64) var_f5_3942 * (0.5 * temp_f1_3957 * -(((f64) var_f5_3942 * (temp_f1_3957 * temp_f1_3957)) - 3.0)));
                } else if (var_f5_3942 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_3942 = __float_nan;
                } else {
                    sp8 = var_f5_3942;
                    temp_r3_3976 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_3976) {         /* switch 7; irregular */
                    case 0x7F800000:                /* switch 7 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_3986 = 1;
                        } else {
                            var_r0_3986 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 7 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_3986 = 5;
                        } else {
                            var_r0_3986 = 3;
                        }
                        break;
                    default:                        /* switch 7 */
                        var_r0_3986 = 4;
                        break;
                    }
                    if (var_r0_3986 == 1) {
                        var_f5_3942 = __float_nan;
                    }
                }
                var_f4_3929 = 1.0f / var_f5_3942;
            }
            sp1F0 = (f32) sp1F0 * var_f4_3929;
            (*(f32 *) ((u8 *) &sp1E8 + 0xc)) *= var_f4_3929;
            sp1F8 = (f32) sp1F8 * var_f4_3929;
            spF0.operator*(var_f31_3889);
            sp100.operator*(0.05f + -((var_f2_3772 * 0.5f) - 1.0f));
            sp30 = M2C_FIELD(this, f64 *, 0x230) + M2C_BITWISE(f64, sp100);
            temp_f2_4032 = this->unk230.unk8;
            this->unk240 = sp30;
            sp38 = temp_f2_4032 + sp100.unk8;
            sp110 = sp30;
            M2C_FIELD(this, f64 *, 0x248) = (f64) sp38;
            sp118 = (f64) sp38;
            temp_f0_4044 = (f64) sp1F0 * 5.45263811e-315;
            sp20 = temp_f0_4044;
            spE0 = temp_f0_4044;
            sp28 = sp1F8 * 25.0f;
            spE8 = (f64) sp28;
            M2C_FIELD(this, f64 *, 0x230) = (f64) (M2C_FIELD(this, f64 *, 0x230) + temp_f0_4044);
            temp_f1_4060 = this->unk230.unk8;
            this->unk230.unk8 = temp_f1_4060 + (f32) spE8;
            temp_r3_4065 = this->unk2C8;
            M2C_FIELD(M2C_FIELD(temp_r3_4065, void **, 0x44), M2C_UNK (**)(u32, MKVector3 *, f64 *, M2C_UNK, M2C_UNK, f32, f32), 0x50)(temp_r3_4065, &this->unk230, &this->unk240, 0, 0, temp_f1_4060, temp_f2_4032);
        }
        break;
    }
}
#endif

void AssaultCannon::StateTurnToFaceExit() {

}

#if 0 // DRAFT: function call 'GetTargetable(HeroInterface *, GameGlobals *, double)' does
void AssaultCannon::StateTurnToFaceUpdate() {
    f64 sp98;
    f64 sp90;
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;                                       /* compiler-managed */
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
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
    f32 sp8;
    Frustum *temp_r30_4361;
    ShatterableDescriptor *temp_r3_4262;
    f32 temp_f1_4314;
    f32 var_f0_4264;
    f32 var_f0_4316;
    f32 var_f31_4181;
    f32 var_f4_4168;
    f64 temp_f0_4150;
    f64 temp_f0_4162;
    f64 temp_f1_4144;
    f64 temp_f1_4186;
    f64 temp_f1_4192;
    f64 temp_f1_4196;
    s32 temp_r0_4265;
    s32 temp_r0_4315;
    s32 temp_r3_4215;
    s32 var_r0_4225;
    void **temp_r3_4122;
    void *temp_r30_4138;
    void *temp_r3_4143;
    void *temp_r4_4135;

    sp38 = 0.0f;
    sp30 = 0.0f;
    sp34 = 0.0f;
    sp98 = (f64) sp38;
    sp90 = (f64) sp30;
    if (gb.unk0->GetTargetable(&gb, (f64) sp30) != 0U) {
        temp_r3_4122 = gb.unk0->GetTargetable();
        M2C_FIELD(*temp_r3_4122, M2C_UNK (**)(f64 *, void **), 0x30)(&sp70, temp_r3_4122);
        sp90 = sp70;
        sp98 = sp78;
    }
    temp_r4_4135 = this->unk8;
    temp_r30_4138 = ((u8 *) temp_r4_4135) + 0x30;
    temp_r3_4143 = M2C_FIELD(gb.unk0->GetProp(temp_r4_4135), void **, 8);
    temp_f1_4144 = M2C_FIELD(temp_r3_4143, f64 *, 0x30);
    sp50 = temp_f1_4144;
    sp58 = M2C_FIELD(temp_r3_4143, f64 *, 0x38);
    temp_f0_4150 = temp_f1_4144 + sp90;
    sp20 = temp_f0_4150;
    sp60 = temp_f0_4150;
    sp28 = (f32) sp58 + (f32) sp98;
    sp68 = (f64) sp28;
    temp_f0_4162 = sp60 - M2C_FIELD(temp_r30_4138, f64 *, 0);
    sp10 = temp_f0_4162;
    var_f4_4168 = 0.0f;
    sp80 = temp_f0_4162;
    sp18 = (f32) sp68 - M2C_FIELD(temp_r30_4138, f32 *, 8);
    (*(f32 *) ((u8 *) &sp70 + 0x14)) = 0.0f;
    sp88 = (f64) sp18;
    var_f31_4181 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + (0.0f * 0.0f));
    if (var_f31_4181 > 0.000001f) {
        if (var_f31_4181 > 0.0f) {
            temp_f1_4186 = __frsqrte(var_f31_4181);
            temp_f1_4192 = 0.5 * temp_f1_4186 * -(((f64) var_f31_4181 * (temp_f1_4186 * temp_f1_4186)) - 3.0);
            temp_f1_4196 = 0.5 * temp_f1_4192 * -(((f64) var_f31_4181 * (temp_f1_4192 * temp_f1_4192)) - 3.0);
            var_f31_4181 = (f32) ((f64) var_f31_4181 * (0.5 * temp_f1_4196 * -(((f64) var_f31_4181 * (temp_f1_4196 * temp_f1_4196)) - 3.0)));
        } else if (var_f31_4181 < M2C_BITWISE(f32, 0.0)) {
            var_f31_4181 = __float_nan;
        } else {
            sp8 = var_f31_4181;
            temp_r3_4215 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_4215) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_4225 = 1;
                } else {
                    var_r0_4225 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_4225 = 5;
                } else {
                    var_r0_4225 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_4225 = 4;
                break;
            }
            if (var_r0_4225 == 1) {
                var_f31_4181 = __float_nan;
            }
        }
        var_f4_4168 = 1.0f / var_f31_4181;
    } else {
        var_f31_4181 = 0.0f;
    }
    sp80 = (f32) sp80 * var_f4_4168;
    (*(f32 *) ((u8 *) &sp70 + 0x14)) *= var_f4_4168;
    sp88 = (f32) sp88 * var_f4_4168;
    temp_r3_4262 = checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_f0_4264 = 3500.0f;
    temp_r0_4265 = M2C_FIELD(temp_r3_4262, s32 *, 0x174);
    switch (temp_r0_4265) {                         /* switch 2; irregular */
    case 1:                                         /* switch 2 */
        break;
    case 2:                                         /* switch 2 */
        var_f0_4264 = 2000.0f;
        break;
    case 3:                                         /* switch 2 */
        var_f0_4264 = 5000.0f;
        break;
    case 4:                                         /* switch 2 */
        var_f0_4264 = 50000.0f;
        break;
    case 5:                                         /* switch 2 */
        var_f0_4264 = 50000.0f;
        break;
    }
    if (var_f31_4181 > var_f0_4264) {
        SetAnim(1, 0, 1.0f);
        this->unk218.SetState(this, 1, 0U);
        return;
    }
    sp40 = (f64) sp80;
    sp48 = (f64) sp88;
    temp_f1_4314 = M2C_BITWISE(f32, UpdateTurning((MKVector3) &sp40));
    temp_r0_4315 = M2C_FIELD(temp_r3_4262, s32 *, 0x174);
    var_f0_4316 = 0.1f;
    switch (temp_r0_4315) {                         /* switch 3; irregular */
    case 1:                                         /* switch 3 */
        var_f0_4316 = 0.02f;
        break;
    case 2:                                         /* switch 3 */
        var_f0_4316 = 0.01f;
        break;
    case 3:                                         /* switch 3 */
        var_f0_4316 = 0.02f;
        break;
    case 4:                                         /* switch 3 */
        var_f0_4316 = 10.0f;
        break;
    case 5:                                         /* switch 3 */
        var_f0_4316 = 10.0f;
        break;
    }
    if ((temp_f1_4314 <= var_f0_4316) && (M2C_BITWISE(f32, this->unk2C0) <= 0.0f)) {
        temp_r30_4361 = M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0;
        if (temp_r30_4361->IsVisible((Matrix *) this->unk8, MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1)) != 0) {
            this->unk218.SetState(this, 3, 0U);
            return;
        }
        this->unk218.SetState(this, 1, 0U);
    }
}
#endif

void AssaultCannon::StateTurnToFaceEnter() {

}

void AssaultCannon::StateIdleExit() {

}

#if 0 // DRAFT: illegal implicit conversion from 'AssaultCannonDescriptor *' to
void AssaultCannon::StateIdleUpdate() {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKAnimScript *temp_r4_4417;
    ShatterableDescriptor *temp_r31_4418;
    f32 var_f30_4446;
    f32 var_f31_4448;
    f32 var_f4_4504;
    f64 temp_f1_4489;
    s32 temp_r0_4434;
    s32 temp_r0_4445;
    u8 var_r5_4420;
    void *temp_r31_4483;
    void *temp_r3_4488;
    void *temp_r4_4480;

    temp_r4_4417 = this->unk80;
    temp_r31_4418 = checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r5_4420 = 0;
    if ((u32) temp_r4_4417->unk20 == (void *) this->unk2C0) {
        if (temp_r4_4417->unk2C & 1) {
            SetAnim(0, 0, 1.0f);
            var_r5_4420 = 1;
        }
        temp_r0_4434 = M2C_FIELD(temp_r31_4418, s32 *, 0x174);
        if ((temp_r0_4434 == 4) || (temp_r0_4434 == 5)) {
            var_r5_4420 = 1;
        }
    } else {
        var_r5_4420 = 1;
    }
    temp_r0_4445 = M2C_FIELD(temp_r31_4418, s32 *, 0x174);
    var_f30_4446 = 3500.0f;
    var_f31_4448 = 400.0f;
    switch (temp_r0_4445) {                         /* irregular */
    case 1:
        break;
    case 3:
        var_f30_4446 = 5000.0f;
        var_f31_4448 = 2000.0f;
        break;
    case 4:
        var_f30_4446 = 50000.0f;
        var_f31_4448 = 1e7f;
        break;
    case 5:
        var_f30_4446 = 50000.0f;
        var_f31_4448 = 1e7f;
        break;
    }
    if (var_r5_4420 != 0) {
        temp_r4_4480 = this->unk8;
        temp_r31_4483 = ((u8 *) temp_r4_4480) + 0x30;
        temp_r3_4488 = M2C_FIELD(gb.unk0->GetProp(temp_r4_4480), void **, 8);
        temp_f1_4489 = M2C_FIELD(temp_r3_4488, f64 *, 0x30);
        sp18 = temp_f1_4489;
        sp20 = M2C_FIELD(temp_r3_4488, f64 *, 0x38);
        sp8 = temp_f1_4489 - M2C_FIELD(temp_r31_4483, f64 *, 0);
        sp28 = sp8;
        sp10 = (f32) sp20 - M2C_FIELD(temp_r31_4483, f32 *, 8);
        var_f4_4504 = (*(f32 *) ((u8 *) &sp28 + 0x4));
        sp30 = (f64) sp10;
        if ((((f32) sp30 * (f32) sp30) + (((f32) sp28 * (f32) sp28) + (var_f4_4504 * var_f4_4504))) <= (var_f30_4446 * var_f30_4446)) {
            if (var_f4_4504 < 0.0f) {
                var_f4_4504 = -var_f4_4504;
            }
            if (var_f4_4504 <= var_f31_4448) {
                this->unk218.SetState(this, 2, 0U);
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal operand
void AssaultCannon::StateIdleEnter() {
    if ((u32) this->unk80->unk20 != (void *) this->unk2C0) {
        SetAnim(0, 0, 1.0f);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
u64 AssaultCannon::UpdateTurning(MKVector3 arg0) {
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;                                       /* compiler-managed */
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    MKVector3 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f0_4704;
    f32 temp_f10_4705;
    f32 temp_f1_4709;
    f32 temp_f2_4712;
    f32 temp_f31_4721;
    f32 temp_f8_4711;
    f32 temp_f9_4701;
    f32 var_f0_4774;
    f32 var_f0_4792;
    f32 var_f30_4760;
    f32 var_f4_4630;
    f32 var_f6_4617;
    f32 var_f7_4725;
    f64 temp_f0_4611;
    f64 temp_f1_4635;
    f64 temp_f1_4641;
    f64 temp_f1_4645;
    s32 temp_r0_4802;
    s32 temp_r3_4664;
    s32 var_r0_4674;
    u32 temp_r4_4577;
    void *temp_r5_4576;

    temp_r5_4576 = this->unk8;
    temp_r4_4577 = this->unk2BC;
    spA0 = M2C_FIELD(temp_r5_4576, f64 *, 0x30);
    spA8 = M2C_FIELD(temp_r5_4576, f64 *, 0x38);
    if (temp_r4_4577 != -1U) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_4577, &spB0);
    } else {
        sp60.operator*(100.0f);
        sp10 = spA0 + M2C_BITWISE(f64, sp60);
        sp70 = sp10;
        sp18 = (f32) spA8 + sp60.unk8;
        spB0 = sp10;
        sp78 = (f64) sp18;
        spB0.unk8 = (f64) sp18;
    }
    temp_f0_4611 = M2C_BITWISE(f64, spB0) - spA0;
    sp40 = temp_f0_4611;
    var_f6_4617 = 0.0f;
    sp90 = temp_f0_4611;
    sp48 = spB0.unk8 - (f32) spA8;
    (*(f32 *) ((u8 *) &sp88 + 0xc)) = 0.0f;
    sp98 = (f64) sp48;
    var_f4_4630 = ((f32) sp98 * (f32) sp98) + (((f32) sp90 * (f32) sp90) + (0.0f * 0.0f));
    if (var_f4_4630 > 0.000001f) {
        if (var_f4_4630 > 0.0f) {
            temp_f1_4635 = __frsqrte(var_f4_4630);
            temp_f1_4641 = 0.5 * temp_f1_4635 * -(((f64) var_f4_4630 * (temp_f1_4635 * temp_f1_4635)) - 3.0);
            temp_f1_4645 = 0.5 * temp_f1_4641 * -(((f64) var_f4_4630 * (temp_f1_4641 * temp_f1_4641)) - 3.0);
            var_f4_4630 = (f32) ((f64) var_f4_4630 * (0.5 * temp_f1_4645 * -(((f64) var_f4_4630 * (temp_f1_4645 * temp_f1_4645)) - 3.0)));
        } else if (var_f4_4630 < M2C_BITWISE(f32, 0.0)) {
            var_f4_4630 = __float_nan;
        } else {
            sp8 = var_f4_4630;
            temp_r3_4664 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_4664) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_4674 = 1;
                } else {
                    var_r0_4674 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_4674 = 5;
                } else {
                    var_r0_4674 = 3;
                }
                break;
            default:
                var_r0_4674 = 4;
                break;
            }
            if (var_r0_4674 == 1) {
                var_f4_4630 = __float_nan;
            }
        }
        var_f6_4617 = 1.0f / var_f4_4630;
    }
    temp_f9_4701 = (*(f32 *) ((u8 *) &sp88 + 0xc)) * var_f6_4617;
    sp38 = 0.0f;
    temp_f0_4704 = M2C_FIELD(arg0, f32 *, 4);
    temp_f10_4705 = (f32) sp90 * var_f6_4617;
    temp_f1_4709 = M2C_FIELD(arg0, f32 *, 0);
    sp58 = (f64) sp38;
    temp_f8_4711 = (f32) sp98 * var_f6_4617;
    temp_f2_4712 = M2C_FIELD(arg0, f32 *, 8);
    sp30 = 0.0f;
    sp34 = 1.0f;
    temp_f31_4721 = 1.0f - ((temp_f2_4712 * temp_f8_4711) + ((temp_f1_4709 * temp_f10_4705) + (temp_f0_4704 * temp_f9_4701)));
    sp50 = (f64) sp30;
    var_f7_4725 = 15.0f * temp_f31_4721;
    sp90 = temp_f10_4705;
    (*(f32 *) ((u8 *) &sp88 + 0xc)) = temp_f9_4701;
    sp98 = temp_f8_4711;
    sp28 = ((f32) sp50 * temp_f9_4701) - ((*(f32 *) ((u8 *) &sp50 + 0x4)) * temp_f10_4705);
    sp20 = ((*(f32 *) ((u8 *) &sp50 + 0x4)) * temp_f8_4711) - ((f32) sp58 * temp_f9_4701);
    sp24 = ((f32) sp58 * temp_f10_4705) - ((f32) sp50 * temp_f8_4711);
    sp88 = (f64) sp28;
    sp80 = (f64) sp20;
    if (var_f7_4725 < 1.0f) {

    } else {
        var_f7_4725 = 1.0f;
    }
    if (var_f7_4725 > -1.0f) {

    } else {
        var_f7_4725 = -1.0f;
    }
    var_f30_4760 = 1.5f * var_f7_4725;
    if (((temp_f2_4712 * (f32) sp88) + ((temp_f1_4709 * (f32) sp80) + (temp_f0_4704 * (*(f32 *) ((u8 *) &sp80 + 0x4))))) > 0.0f) {
        SetAnim(3, 1, 1.0f);
        if (var_f30_4760 < 0.0f) {
            var_f0_4774 = -var_f30_4760;
        } else {
            var_f0_4774 = var_f30_4760;
        }
        var_f30_4760 = -var_f30_4760;
        this->unk80->unk38 = var_f0_4774;
    } else {
        SetAnim(2, 1, 1.0f);
        if (var_f30_4760 < 0.0f) {
            var_f0_4792 = -var_f30_4760;
        } else {
            var_f0_4792 = var_f30_4760;
        }
        this->unk80->unk38 = var_f0_4792;
    }
    temp_r0_4802 = M2C_FIELD(checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x174);
    if ((temp_r0_4802 == 4) || (temp_r0_4802 == 5)) {
        M2C_FIELD(this, f32 *, 0x260) = (f32) ((10.0f * var_f30_4760 * gUpdateTimeDelta) + M2C_FIELD(this, f32 *, 0x260));
    } else {
        M2C_FIELD(this, f32 *, 0x260) = (f32) ((var_f30_4760 * gUpdateTimeDelta) + M2C_FIELD(this, f32 *, 0x260));
    }
    return M2C_BITWISE(u64, temp_f31_4721);
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
s32 AssaultCannon::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    void *temp_r4_4848;

    MKVector(0.0f, 100.0f, 0.0f);
    temp_r4_4848 = ((u8 *) this->unk8) + 0x30;
    sp8 = M2C_FIELD(temp_r4_4848, f64 *, 0) + sp18;
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = M2C_FIELD(temp_r4_4848, f32 *, 8) + sp20;
    sp28 = sp8;
    sp30 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
s32 AssaultCannon::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    void *temp_r4_4886;

    MKVector(0.0f, 100.0f, 0.0f);
    temp_r4_4886 = ((u8 *) this->unk8) + 0x30;
    sp8 = M2C_FIELD(temp_r4_4886, f64 *, 0) + sp18;
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = M2C_FIELD(temp_r4_4886, f32 *, 8) + sp20;
    sp28 = sp8;
    sp30 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

void AssaultCannon::SetAnim(int arg0, int arg1, float arg2) {
    this->unk80->SetAnim(M2C_FIELD((this + (arg0 * 4)), MKAnim **, 0x2BC), arg2, 0.0f, arg1, -1);
}

#if 0 // DRAFT: illegal implicit conversion from 'AssaultCannonDescriptor *' to
void AssaultCannon::TakeDamage(float arg0, const MKVector3 &arg1) {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 spC;
    s32 sp8;
    MKVector3 *temp_r31_4996;
    ShatterableDescriptor *temp_r31_4955;
    f32 temp_f30_4965;
    f32 var_f31_4968;

    sp18 = 0.0f;
    sp10 = 0.0f;
    sp14 = 1.0f;
    sp28 = (f64) sp18;
    sp20 = (f64) sp10;
    temp_r31_4955 = checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r31_4955->EmitHitEffects(arg1, *((MKVector3 *) &sp20), *(MKModel_GetColor(this->unk4)), (MKProp *) this, 5);
    temp_f30_4965 = M2C_BITWISE(f32, this->unk2C4);
    this->unk2C4 = temp_f30_4965 - arg0;
    var_f31_4968 = M2C_BITWISE(f32, this->unk2C4);
    if (var_f31_4968 < 20.0f) {

    } else {
        var_f31_4968 = 20.0f;
    }
    if (var_f31_4968 > 0.0f) {

    } else {
        var_f31_4968 = 0.0f;
    }
    if (((s32) checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk100 != 0) && (arg0 != 0.0f) && (M2C_BITWISE(f32, this->unk2C4) > 0.0f)) {
        temp_r31_4996 = ((u8 *) this->unk8) + 0x30;
        M2C_FIELD(this, s32 *, 0x268) = KDSound_Play3d(checked_cast<P23AssaultCannonDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unk100, temp_r31_4996, 0U, -1, 0.0f, 0U);
    }
    ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.6f, 0.4f, 0.1f, 0, 4.0f, 0U);
    EnemyHud_Modified((MKProp *) this, temp_f30_4965, var_f31_4968, 20.0f);
    if (M2C_BITWISE(f32, this->unk2C4) <= 0.0f) {
        this->unk218.SetState(this, 4, 0U);
        spC = 0;
        sp8 = 0xBA;
        Message(&sp8);
        FreeElecBeams();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk218'
void AssaultCannon::Deinit() {
    u32 temp_r3_5070;

    temp_r3_5070 = this->unk2C8;
    if (temp_r3_5070 != 0) {
        M2C_FIELD(temp_r3_5070, s32 *, 0x130) = 0;
        this->unk2C8 = 0;
    }
    this->unk218.Deinit();
    KDSound_Stop(this + 0x26C);
    KDSound_Stop(&this->unk294);
    M2C_FIELD(this, s8 *, 0x2F0) = 0;
    if (EnemyHud_GetEnemy() == this) {
        EnemyHud_Modified(NULL, 0.0f, 0.0f, 0.0f);
    }
    ShatterablePlatform::Deinit();
}
#endif

void AssaultCannon::Draw() {
    Shatterable::Draw();
    if ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0) {
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, (s32) this->unk2D0, 1U, 1U);
        MKModel_Draw(this->unk4, NULL);
    }
}

#if 0 // DRAFT: undefined identifier 'unk218'
void AssaultCannon::Message(MKMessage *arg0) {
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp218;
    f64 sp210;
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
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f32 sp130;
    f64 sp128;
    f32 sp120;
    f64 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    s32 sp10;
    s32 spC;
    f32 sp8;
    AssaultCannon ***temp_r4_5253;
    AssaultCannon **temp_r3_5275;
    AssaultCannon **temp_r3_5279;
    AssaultCannon **var_r3_5256;
    AssaultCannon *temp_r0_5265;
    f32 temp_r3_5583;
    f32 temp_r3_5596;
    f32 var_f4_5283;
    f32 var_f5_5316;
    f64 temp_f0_5208;
    f64 temp_f0_5221;
    f64 temp_f0_5233;
    f64 temp_f0_5396;
    f64 temp_f0_5409;
    f64 temp_f0_5421;
    f64 temp_f0_5457;
    f64 temp_f0_5493;
    f64 temp_f0_5525;
    f64 temp_f0_5556;
    f64 temp_f1_5321;
    f64 temp_f1_5327;
    f64 temp_f1_5331;
    s32 temp_r0_5148;
    s32 temp_r0_5611;
    s32 temp_r29_5629;
    s32 temp_r29_5636;
    s32 temp_r29_5643;
    s32 temp_r29_5650;
    s32 temp_r29_5657;
    s32 temp_r29_5664;
    s32 temp_r3_5350;
    s32 temp_r3_5589;
    s32 temp_r3_5602;
    s32 var_r4_5284;
    void *temp_r29_5512;
    void *temp_r29_5574;
    void *temp_r3_5215;
    void *temp_r3_5292;
    void *temp_r3_5403;
    void *temp_r4_5449;
    void *temp_r4_5485;
    void *temp_r4_5517;
    void *temp_r4_5548;
    void *temp_r5_5444;
    void *temp_r5_5480;

    ((KDSoundPlayer *) (this + 0x26C))->Message(arg0);
    ((KDSoundPlayer *) &this->unk294)->Message(arg0);
    temp_r0_5148 = arg0->unk0;
    switch (temp_r0_5148) {                         /* switch 1; irregular */
    case 49:                                        /* switch 1 */
        if (this->unk218.GetState() != 4) {
            sp110 = 0.0f;
            sp108 = 0.0f;
            sp10C = 200.0f;
            sp210 = (f64) sp110;
            sp208 = (f64) sp108;
            KDRand_UnitVectorXZ();
            temp_f0_5208 = sp218 * 5.5769738e-315;
            sp128 = temp_f0_5208;
            sp228 = temp_f0_5208;
            temp_r3_5215 = ((u8 *) this->unk8) + 0x30;
            sp130 = sp220 * 200.0f;
            sp230 = (f64) sp130;
            temp_f0_5221 = M2C_FIELD(temp_r3_5215, f64 *, 0) + temp_f0_5208;
            sp118 = temp_f0_5221;
            sp238 = temp_f0_5221;
            sp120 = M2C_FIELD(temp_r3_5215, f32 *, 8) + (f32) sp230;
            sp240 = (f64) sp120;
            temp_f0_5233 = sp238 + sp208;
            spF8 = temp_f0_5233;
            sp258 = temp_f0_5233;
            sp100 = (f32) sp240 + (f32) sp210;
            sp260 = (f64) sp100;
            TakeDamage(1.0f, *((MKVector3 *) &sp258));
            return;
        }
        return;
    case 4:                                         /* switch 1 */
        if (this->unk218.GetState() != 4) {
            temp_r4_5253 = arg0->unk34;
            if (temp_r4_5253 != NULL) {
                var_r3_5256 = *temp_r4_5253;
loop_32:
                temp_r0_5265 = *var_r3_5256;
                if (temp_r0_5265 == NULL) {
                    var_r3_5256 = NULL;
                } else if (temp_r0_5265 == this) {

                } else {
                    var_r3_5256 += 4;
                    goto loop_32;
                }
                if (var_r3_5256 == NULL) {
                    goto block_35;
                }
            } else {
block_35:
                if (temp_r4_5253 != NULL) {
                    temp_r3_5275 = *temp_r4_5253;
                    if ((u32) M2C_FIELD(temp_r3_5275, u32 *, -4) != 0U) {
                        temp_r3_5279 = temp_r3_5275 - 4;
                        *temp_r4_5253 = temp_r3_5279;
                        *temp_r3_5279 = this;
                    }
                }
                var_f4_5283 = 0.0f;
                var_r4_5284 = 1;
                M2C_FIELD(arg0, s8 *, 0x3E) = 1;
                spC0 = 0.0f;
                spB8 = 0.0f;
                temp_r3_5292 = ((u8 *) this->unk8) + 0x30;
                spBC = 200.0f;
                sp1C0 = (f64) spC0;
                sp1B8 = (f64) spB8;
                spE8 = arg0->unk10 - M2C_FIELD(temp_r3_5292, f64 *, 0);
                sp1C8 = spE8;
                spF0 = arg0->unk18 - M2C_FIELD(temp_r3_5292, f32 *, 8);
                sp1D0 = (f64) spF0;
                var_f5_5316 = ((f32) sp1D0 * (f32) sp1D0) + (((f32) sp1C8 * (f32) sp1C8) + ((*(f32 *) ((u8 *) &sp1C8 + 0x4)) * (*(f32 *) ((u8 *) &sp1C8 + 0x4))));
                if (var_f5_5316 > 1e-12f) {
                    if (var_f5_5316 > 0.0f) {
                        temp_f1_5321 = __frsqrte(var_f5_5316);
                        temp_f1_5327 = 0.5 * temp_f1_5321 * -(((f64) var_f5_5316 * (temp_f1_5321 * temp_f1_5321)) - 3.0);
                        temp_f1_5331 = 0.5 * temp_f1_5327 * -(((f64) var_f5_5316 * (temp_f1_5327 * temp_f1_5327)) - 3.0);
                        var_f5_5316 = (f32) ((f64) var_f5_5316 * (0.5 * temp_f1_5331 * -(((f64) var_f5_5316 * (temp_f1_5331 * temp_f1_5331)) - 3.0)));
                    } else if (var_f5_5316 < M2C_BITWISE(f32, 0.0)) {
                        var_f5_5316 = __float_nan;
                    } else {
                        sp8 = var_f5_5316;
                        temp_r3_5350 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_5350) {     /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {

                            } else {
                                var_r4_5284 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r4_5284 = 5;
                            } else {
                                var_r4_5284 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r4_5284 = 4;
                            break;
                        }
                        if (var_r4_5284 == 1) {
                            var_f5_5316 = __float_nan;
                        }
                    }
                    var_f4_5283 = 1.0f / var_f5_5316;
                }
                sp9C = (*(f32 *) ((u8 *) &sp1C8 + 0x4)) * var_f4_5283;
                sp98 = (f32) sp1C8 * var_f4_5283;
                spA0 = (f32) sp1D0 * var_f4_5283;
                sp1D8 = (f64) sp98;
                sp1E0 = (f64) spA0;
                temp_f0_5396 = sp1D8 * 5.5769738e-315;
                spD8 = temp_f0_5396;
                sp1E8 = temp_f0_5396;
                temp_r3_5403 = ((u8 *) this->unk8) + 0x30;
                spE0 = (f32) sp1E0 * 200.0f;
                sp1F0 = (f64) spE0;
                temp_f0_5409 = M2C_FIELD(temp_r3_5403, f64 *, 0) + temp_f0_5396;
                spC8 = temp_f0_5409;
                sp1F8 = temp_f0_5409;
                spD0 = M2C_FIELD(temp_r3_5403, f32 *, 8) + (f32) sp1F0;
                sp200 = (f64) spD0;
                temp_f0_5421 = sp1F8 + sp1B8;
                spA8 = temp_f0_5421;
                sp248 = temp_f0_5421;
                spB0 = (f32) sp200 + (f32) sp1C0;
                sp250 = (f64) spB0;
                TakeDamage(arg0->unk20, *((MKVector3 *) &sp248));
                return;
            }
        }
        break;
    case 5:                                         /* switch 1 */
        if (this->unk218.GetState() != 4) {
            temp_r5_5444 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
            sp88 = 0.0f;
            sp8C = 400.0f;
            temp_r4_5449 = ((u8 *) this->unk8) + 0x30;
            sp90 = 0.0f;
            sp198 = (f64) sp88;
            sp1A0 = (f64) sp90;
            temp_f0_5457 = M2C_FIELD(temp_r4_5449, f64 *, 0) + sp198;
            sp78 = temp_f0_5457;
            sp1A8 = temp_f0_5457;
            sp80 = M2C_FIELD(temp_r4_5449, f32 *, 8) + (f32) sp1A0;
            sp1B0 = (f64) sp80;
            TakeDamage(M2C_FIELD(temp_r5_5444, f32 *, 0x34), *((MKVector3 *) &sp1A8));
            return;
        }
        break;
    case 1:                                         /* switch 1 */
        if (this->unk218.GetState() != 4) {
            temp_r5_5480 = checked_cast<ExplodeMsg *, MKMessage>(arg0);
            sp68 = 0.0f;
            sp6C = 400.0f;
            temp_r4_5485 = ((u8 *) this->unk8) + 0x30;
            sp70 = 0.0f;
            sp178 = (f64) sp68;
            sp180 = (f64) sp70;
            temp_f0_5493 = M2C_FIELD(temp_r4_5485, f64 *, 0) + sp178;
            sp58 = temp_f0_5493;
            sp188 = temp_f0_5493;
            sp60 = M2C_FIELD(temp_r4_5485, f32 *, 8) + (f32) sp180;
            sp190 = (f64) sp60;
            TakeDamage(M2C_FIELD(temp_r5_5480, f32 *, 0x2C), *((MKVector3 *) &sp188));
            return;
        }
        break;
    case 95:                                        /* switch 1 */
        temp_r29_5512 = checked_cast<BallHitMessage *, MKMessage>(arg0);
        sp48 = 0.0f;
        sp4C = 400.0f;
        temp_r4_5517 = ((u8 *) this->unk8) + 0x30;
        sp50 = 0.0f;
        sp158 = (f64) sp48;
        sp160 = (f64) sp50;
        temp_f0_5525 = M2C_FIELD(temp_r4_5517, f64 *, 0) + sp158;
        sp38 = temp_f0_5525;
        sp168 = temp_f0_5525;
        sp40 = M2C_FIELD(temp_r4_5517, f32 *, 8) + (f32) sp160;
        sp170 = (f64) sp40;
        TakeDamage(10.0f, *((MKVector3 *) &sp168));
        M2C_FIELD(temp_r29_5512, s8 *, 0x14) = 0;
    default:                                        /* switch 1 */
block_91:
        ShatterablePlatform::Message(arg0);
        break;
    case 224:                                       /* switch 1 */
        sp28 = 0.0f;
        sp2C = 400.0f;
        temp_r4_5548 = ((u8 *) this->unk8) + 0x30;
        sp30 = 0.0f;
        sp138 = (f64) sp28;
        sp140 = (f64) sp30;
        temp_f0_5556 = M2C_FIELD(temp_r4_5548, f64 *, 0) + sp138;
        sp18 = temp_f0_5556;
        sp148 = temp_f0_5556;
        sp20 = M2C_FIELD(temp_r4_5548, f32 *, 8) + (f32) sp140;
        sp150 = (f64) sp20;
        TakeDamage(20.0f, *((MKVector3 *) &sp148));
        goto block_91;
    case 136:                                       /* switch 1 */
        temp_r29_5574 = checked_cast<CanHeroHurtYouMsg *, MKMessage>(arg0);
        M2C_FIELD(temp_r29_5574, s8 *, 8) = (s8) (this->unk218.GetState() != 4);
        return;
    case -3:                                        /* switch 1 */
        temp_r3_5583 = this->unk2E4;
        if (M2C_BITWISE(u32, temp_r3_5583) != 0U) {
            M2C_FIELD(temp_r3_5583, s8 *, 0x10) = 1;
        }
        temp_r3_5589 = this->unk2E8;
        if ((u32) temp_r3_5589 != 0U) {
            M2C_FIELD(temp_r3_5589, s8 *, 0x10) = 1;
        }
        goto block_91;
    case -4:                                        /* switch 1 */
        temp_r3_5596 = this->unk2E4;
        if (M2C_BITWISE(u32, temp_r3_5596) != 0U) {
            M2C_FIELD(temp_r3_5596, s8 *, 0x10) = 0;
        }
        temp_r3_5602 = this->unk2E8;
        if ((u32) temp_r3_5602 != 0U) {
            M2C_FIELD(temp_r3_5602, s8 *, 0x10) = 0;
        }
        goto block_91;
    case 141:                                       /* switch 1 */
        temp_r0_5611 = M2C_FIELD(checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x174);
        switch (temp_r0_5611) {                     /* switch 3; irregular */
        case 0:                                     /* switch 3 */
            temp_r29_5629 = M2C_FIELD(gpTranslation_StringArray, s32 *, 0x334);
            M2C_FIELD(checked_cast<GetNameMsg *, MKMessage>(arg0), s32 *, 8) = temp_r29_5629;
            break;
        case 1:                                     /* switch 3 */
            temp_r29_5636 = M2C_FIELD(gpTranslation_StringArray, s32 *, 0x338);
            M2C_FIELD(checked_cast<GetNameMsg *, MKMessage>(arg0), s32 *, 8) = temp_r29_5636;
            break;
        case 2:                                     /* switch 3 */
            temp_r29_5643 = M2C_FIELD(gpTranslation_StringArray, s32 *, 0x33C);
            M2C_FIELD(checked_cast<GetNameMsg *, MKMessage>(arg0), s32 *, 8) = temp_r29_5643;
            break;
        case 3:                                     /* switch 3 */
            temp_r29_5650 = M2C_FIELD(gpTranslation_StringArray, s32 *, 0x340);
            M2C_FIELD(checked_cast<GetNameMsg *, MKMessage>(arg0), s32 *, 8) = temp_r29_5650;
            break;
        case 4:                                     /* switch 3 */
            temp_r29_5657 = M2C_FIELD(gpTranslation_StringArray, s32 *, 0x344);
            M2C_FIELD(checked_cast<GetNameMsg *, MKMessage>(arg0), s32 *, 8) = temp_r29_5657;
            break;
        case 5:                                     /* switch 3 */
            temp_r29_5664 = M2C_FIELD(gpTranslation_StringArray, s32 *, 0x348);
            M2C_FIELD(checked_cast<GetNameMsg *, MKMessage>(arg0), s32 *, 8) = temp_r29_5664;
            break;
        }
        goto block_91;
    case 78:                                        /* switch 1 */
        if ((u32) this->unk2C8 == (u32) arg0->unk4) {
            this->unk2C8 = 0;
        }
        goto block_91;
    case 213:                                       /* switch 1 */
        SetDefaults();
        sp10 = 0;
        spC = 0xBE;
        Message(&spC);
        goto block_91;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk218'
void AssaultCannon::Update() {
    f64 sp48;
    f64 sp40;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 sp8;
    ShatterableDescriptor *temp_r4_5728;
    ShatterableDescriptor *temp_r4_5748;
    f64 temp_f0_5785;
    f64 temp_f1_5784;
    void *temp_r3_5782;

    ShatterablePlatform::Update();
    this->unk218.Update(this, 0);
    this->unk2C0 = M2C_BITWISE(f32, this->unk2C0) - gUpdateTimeDelta;
    if ((s32) M2C_FIELD(checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x190) != 0) {
        temp_r4_5728 = checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) (this + 0x26C))->Update(M2C_FIELD(temp_r4_5728, s32 *, 0x190), 1U, M2C_FIELD(this, u8 *, 0x2F0), NULL, &this->unk230, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((s32) M2C_FIELD(checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x194) != 0) {
        temp_r4_5748 = checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) &this->unk294)->Update(M2C_FIELD(temp_r4_5748, s32 *, 0x194), 1U, M2C_FIELD(this, u8 *, 0x2F0), NULL, (MKVector3 *) &this->unk240, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    CalcBarrelBeamPositions();
    CalcSpikeBeamPositions();
    ((MKProp *) &sp30)->GetPos();
    sp10 = sp30 - this->unk330;
    this->unk340 = sp10;
    sp18 = sp38 - M2C_FIELD(this, f32 *, 0x350);
    sp40 = sp10;
    this->unk348 = (f64) sp18;
    temp_r3_5782 = this->unk8;
    sp48 = (f64) sp18;
    temp_f1_5784 = M2C_FIELD(temp_r3_5782, f64 *, 0x30);
    temp_f0_5785 = M2C_FIELD(temp_r3_5782, f64 *, 0x38);
    sp20 = temp_f1_5784;
    this->unk330 = temp_f1_5784;
    sp28 = temp_f0_5785;
    this->unk338 = temp_f0_5785;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void AssaultCannon::LoadDone() {
    f64 sp18;
    f64 sp10;
    f64 sp8;
    MKAnimScript *temp_r30_5806;
    MKAnimScript *temp_r30_5826;
    MKAnimScript *temp_r30_5844;
    MKAnimScript *temp_r30_5862;
    MKAnimScript *temp_r30_5880;
    MKAnimScript *temp_r30_5896;
    f64 temp_f0_5989;
    f64 temp_f1_5988;
    s8 *temp_r4_5934;
    u16 var_r30_5939;
    void *temp_r3_5987;
    void *var_r3_5818;
    void *var_r3_5836;
    void *var_r3_5854;
    void *var_r3_5872;
    void *var_r3_5888;
    void *var_r3_5906;

    ShatterablePlatform::LoadDone();
    temp_r30_5806 = this->unk80;
    if (temp_r30_5806->Exists("Idle01") != 0) {
        var_r3_5818 = temp_r30_5806->GetAnim("Idle01");
    } else {
        var_r3_5818 = NULL;
    }
    this->unk2BC = var_r3_5818;
    temp_r30_5826 = this->unk80;
    if (temp_r30_5826->Exists("Idle02") != 0) {
        var_r3_5836 = temp_r30_5826->GetAnim("Idle02");
    } else {
        var_r3_5836 = NULL;
    }
    this->unk2C0 = var_r3_5836;
    temp_r30_5844 = this->unk80;
    if (temp_r30_5844->Exists("TurnLeft") != 0) {
        var_r3_5854 = temp_r30_5844->GetAnim("TurnLeft");
    } else {
        var_r3_5854 = NULL;
    }
    this->unk2C4 = var_r3_5854;
    temp_r30_5862 = this->unk80;
    if (temp_r30_5862->Exists("TurnRight") != 0) {
        var_r3_5872 = temp_r30_5862->GetAnim("TurnRight");
    } else {
        var_r3_5872 = NULL;
    }
    this->unk2C8 = var_r3_5872;
    temp_r30_5880 = this->unk80;
    if (temp_r30_5880->Exists("Fire") != 0) {
        var_r3_5888 = temp_r30_5880->GetAnim("Fire");
    } else {
        var_r3_5888 = NULL;
    }
    this->unk2CC = var_r3_5888;
    temp_r30_5896 = this->unk80;
    if (temp_r30_5896->Exists("Death") != 0) {
        var_r3_5906 = temp_r30_5896->GetAnim("Death");
    } else {
        var_r3_5906 = NULL;
    }
    this->unk2D0 = var_r3_5906;
    this->unk80->InitEvents(&pTurretAnimEvents);
    Init__31KDStateMachine<13AssaultCannon>FPQ231KDStateMachine<13AssaultCannon>5StateP31KDStateMachine<13AssaultCannon>(&this->unk218, (KDStateMachine<AssaultCannon>::State *) AssaultCannon::states, NULL);
    this->unk218.SetState(this, 1, 0U);
    this->unk2BC = (u32) Tools_GetMatchingRefPointIndex(this->unk4, "r_ammo");
    temp_r4_5934 = M2C_FIELD(checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s8 **, 0x16C);
    if (temp_r4_5934 != NULL) {
        var_r30_5939 = Tools_GetMatchingNodeIndex(this->unk4, temp_r4_5934);
    } else {
        var_r30_5939 = Tools_GetMatchingNodeIndex(this->unk4, "turret");
    }
    ((Animation *) &sp18)->GetNodeOrigin(MKModel_GetAnimation(this->unk4));
    M2C_FIELD(this, f64 *, 0x250) = sp18;
    this->unk240 = sp20;
    MKDynamicBone_SetUpdater(MKDynamicBone_AddDynamicBone(this->unk4, (s32) var_r30_5939), (void (*)(MKDynamicBone *, void *)) &AssaultCannon::UpdateTurretBone, &this->unk230.unk8);
    M2C_FIELD(this, f32 *, 0x260) = 0.0f;
    SetAnim(0, 0, 1.0f);
    this->unk2D0 = (u32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, "Rider");
    CalcBarrelBeamPositions();
    CalcSpikeBeamPositions();
    AllocElecBeams();
    temp_r3_5987 = this->unk8;
    temp_f1_5988 = M2C_FIELD(temp_r3_5987, f64 *, 0x30);
    temp_f0_5989 = M2C_FIELD(temp_r3_5987, f64 *, 0x38);
    sp8 = temp_f1_5988;
    this->unk330 = temp_f1_5988;
    sp10 = temp_f0_5989;
    this->unk338 = temp_f0_5989;
}
#endif

void AssaultCannon::SetDefaults() {
    this->unk2C4 = 20.0f;
    this->unk2C0 = 0.0f;
    this->unk2CC = 0.0f;
    M2C_FIELD(this, s8 *, 0x2F0) = 0;
    M2C_FIELD(this, s8 *, 0x2F1) = 0;
    this->unk2D4 = 0.0f;
    this->unk2C8 = 0;
    this->unk2E4 = 0.0f;
    this->unk2E8 = 0;
    M2C_FIELD(this, f32 *, 0x358) = 0.0f;
    M2C_FIELD(this, f32 *, 0x35C) = 0.0f;
    M2C_FIELD(this, f32 *, 0x360) = 0.0f;
}

#if 0 // DRAFT: illegal implicit conversion from 'AssaultCannonDescriptor *' to
void AssaultCannon::Init() {
    ShatterableDescriptor *temp_r31_6038;
    ShatterableDescriptor *temp_r31_6047;

    ShatterablePlatform::Init();
    SetDefaults();
    M2C_FIELD(this, s8 *, 0x2F0) = 0;
    M2C_FIELD(this, s32 *, 0x268) = 0;
    temp_r31_6038 = checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) (this + 0x26C))->Init(M2C_FIELD(checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x198), M2C_FIELD(temp_r31_6038, f32 *, 0x19C));
    temp_r31_6047 = checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unk294)->Init(M2C_FIELD(checked_cast<AssaultCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x1A0), M2C_FIELD(temp_r31_6047, f32 *, 0x1A4));
    M2C_FIELD(this, f32 *, 0x358) = 0.0f;
    M2C_FIELD(this, f32 *, 0x35C) = 0.0f;
    M2C_FIELD(this, f32 *, 0x360) = 0.0f;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void AssaultCannonDescriptor::Deinit() {
    MKHeap *temp_r3_6076;
    void *temp_r31_6073;

    temp_r31_6073 = this->unk17C;
    if (temp_r31_6073 != NULL) {
        temp_r3_6076 = MKHeap::Current();
        if (temp_r3_6076 != NULL) {
            ((MKHeap *) (temp_r3_6076->Current()))->Free(temp_r31_6073, NULL, 0);
        } else {
            free(temp_r31_6073);
        }
    }
    ShatterableDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void AssaultCannonDescriptor::LoadDone() {
    MKHeap *temp_r3_6118;
    f32 var_f1_6125;
    s32 var_r28_6134;
    s32 var_r30_6135;
    u16 temp_ret_6143;
    void *temp_ret_6125;
    void *temp_ret_6129;
    void *var_r3_6125;

    ShatterableDescriptor::LoadDone();
    if ((s32) this->unk174 == 2) {
        this->unk178 = checked_cast<EnergyBeam *, MKProp>(gMK->CreateProp("EnergyBeam"));
    }
    temp_r3_6118 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_6118 != NULL) {
        temp_ret_6125 = ((MKHeap *) (temp_r3_6118->Current()))->Alloc(0x14, NULL, 0);
        var_f1_6125 = M2C_BITWISE(f32, temp_ret_6125);
        var_r3_6125 = temp_ret_6125;
    } else {
        temp_ret_6129 = malloc(0x14);
        var_f1_6125 = M2C_BITWISE(f32, temp_ret_6129);
        var_r3_6125 = temp_ret_6129;
    }
    this->unk17C = var_r3_6125;
    var_r28_6134 = 0;
    var_r30_6135 = 0;
    do {
        temp_ret_6143 = Tools_GetMatchingRefPointIndex(this->unk2C, Str_Printf("elec%d", var_r28_6134 + 1, var_f1_6125));
        var_f1_6125 = M2C_BITWISE(f32, temp_ret_6143);
        var_r28_6134 += 1;
        *(this->unk17C + var_r30_6135) = (s32) temp_ret_6143;
        var_r30_6135 += 4;
    } while (var_r28_6134 < 5);
    this->unk180 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "ammo1");
    this->unk184 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "ammo3");
    this->unk188 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "ammo2");
    this->unk18C = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "ammo4");
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 AssaultCannonDescriptor::LoadLine(MKIniLine *arg0) {
    s8 *sp8;

    if ((ShatterableDescriptor::LoadLine(arg0) != 0) || (arg0->LoadString("turretSubObject", &this->unk16C, 0) != 0) || (arg0->LoadInt("GemsOnDeath", &this->unk1A8, 0) != 0) || (arg0->LoadFloat("spitFadeIn", &this->unk198, 0) != 0) || (arg0->LoadFloat("spitFadeOut", &this->unk19C, 0) != 0) || (arg0->LoadFloat("splatFadeIn", &this->unk1A0, 0) != 0) || (arg0->LoadFloat("splatFadeOut", &this->unk1A4, 0) != 0) || (KDSound_LoadLine(arg0, "spitSound", &this->unk190) != 0) || (KDSound_LoadLine(arg0, "splatSound", &this->unk194) != 0)) {
        return 1;
    }
    if (arg0->IsField("TurretType") != 0) {
        arg0->AsString(0, &sp8);
        if (stricmp(sp8, "Fire") == 0) {
            this->unk174 = 0;
        } else if (stricmp(sp8, "Earth") == 0) {
            this->unk174 = 1;
        } else if (stricmp(sp8, "Elec") == 0) {
            this->unk174 = 2;
        } else if (stricmp(sp8, "Ice") == 0) {
            this->unk174 = 3;
        } else if (stricmp(sp8, "SWFire") == 0) {
            this->unk174 = 4;
        } else if (stricmp(sp8, "SWIce") == 0) {
            this->unk174 = 5;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void AssaultCannonDescriptor::Init() {
    ShatterableDescriptor::Init();
    this->unk16C = NULL;
    this->unk174 = 1;
    this->unk190 = 0;
    this->unk194 = 0;
    this->unk198 = 0.25f;
    this->unk19C = 0.25f;
    this->unk1A0 = 0.25f;
    this->unk1A4 = 0.25f;
    this->unk1A8 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__ptmf_null'
void AssaultCannon_cpp::__sinit() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f1_6600;
    f64 temp_f1_6618;
    f64 temp_f3_6584;
    f64 temp_f3_6621;
    f64 temp_f4_6599;
    f64 temp_f4_6615;
    f64 temp_f8_6586;
    void *temp_r3_6593;

    temp_f3_6584 = __frsqrte(2014000.0);
    temp_f8_6586 = __frsqrte(380000.0);
    temp_r3_6593 = &lit_723 + 0x90;
    temp_f4_6599 = 0.5 * temp_f3_6584 * -((2014000.0 * (temp_f3_6584 * temp_f3_6584)) - 3.0);
    temp_f1_6600 = 0.5 * temp_f8_6586 * -((380000.0 * (temp_f8_6586 * temp_f8_6586)) - 3.0);
    temp_f4_6615 = 0.5 * temp_f4_6599 * -((2014000.0 * (temp_f4_6599 * temp_f4_6599)) - 3.0);
    temp_f1_6618 = 0.5 * temp_f1_6600 * -((380000.0 * (temp_f1_6600 * temp_f1_6600)) - 3.0);
    temp_f3_6621 = temp_f4_6615 * temp_f4_6615;
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(&lit_723, s32 *, 0x90) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(&lit_723, s32 *, 0x94) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(&lit_723, s32 *, 0x98) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_6593, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_6593, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_6593, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_6593, s32 *, 0x18) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_6593, s32 *, 0x1C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_6593, s32 *, 0x20) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_6593, s32 *, 0x24) = (s32) M2C_FIELD(&lit_723, s32 *, 0);
    M2C_FIELD(temp_r3_6593, s32 *, 0x28) = (s32) M2C_FIELD(&lit_723, s32 *, 4);
    M2C_FIELD(temp_r3_6593, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_723, s32 *, 8);
    M2C_FIELD(temp_r3_6593, s32 *, 0x30) = (s32) M2C_FIELD(&lit_723, s32 *, 0xC);
    M2C_FIELD(temp_r3_6593, s32 *, 0x34) = (s32) M2C_FIELD(&lit_723, s32 *, 0x10);
    M2C_FIELD(temp_r3_6593, s32 *, 0x38) = (s32) M2C_FIELD(&lit_723, s32 *, 0x14);
    M2C_FIELD(temp_r3_6593, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_723, s32 *, 0x18);
    M2C_FIELD(temp_r3_6593, s32 *, 0x40) = (s32) M2C_FIELD(&lit_723, s32 *, 0x1C);
    M2C_FIELD(temp_r3_6593, s32 *, 0x44) = (s32) M2C_FIELD(&lit_723, s32 *, 0x20);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_6615 * -((2014000.0 * temp_f3_6621) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_6618 * -((380000.0 * (temp_f1_6618 * temp_f1_6618)) - 3.0)));
    M2C_FIELD(temp_r3_6593, s32 *, 0x48) = (s32) M2C_FIELD(&lit_723, s32 *, 0x24);
    M2C_FIELD(temp_r3_6593, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_723, s32 *, 0x28);
    M2C_FIELD(temp_r3_6593, s32 *, 0x50) = (s32) M2C_FIELD(&lit_723, s32 *, 0x2C);
    M2C_FIELD(temp_r3_6593, s32 *, 0x54) = (s32) M2C_FIELD(&lit_723, s32 *, 0x30);
    M2C_FIELD(temp_r3_6593, s32 *, 0x58) = (s32) M2C_FIELD(&lit_723, s32 *, 0x34);
    M2C_FIELD(temp_r3_6593, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_723, s32 *, 0x38);
    M2C_FIELD(temp_r3_6593, s32 *, 0x60) = (s32) M2C_FIELD(&lit_723, s32 *, 0x3C);
    M2C_FIELD(temp_r3_6593, s32 *, 0x64) = (s32) M2C_FIELD(&lit_723, s32 *, 0x40);
    M2C_FIELD(temp_r3_6593, s32 *, 0x68) = (s32) M2C_FIELD(&lit_723, s32 *, 0x44);
    M2C_FIELD(temp_r3_6593, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_723, s32 *, 0x48);
    M2C_FIELD(temp_r3_6593, s32 *, 0x70) = (s32) M2C_FIELD(&lit_723, s32 *, 0x4C);
    M2C_FIELD(temp_r3_6593, s32 *, 0x74) = (s32) M2C_FIELD(&lit_723, s32 *, 0x50);
    M2C_FIELD(temp_r3_6593, s32 *, 0x78) = (s32) M2C_FIELD(&lit_723, s32 *, 0x54);
    M2C_FIELD(temp_r3_6593, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_723, s32 *, 0x58);
    M2C_FIELD(temp_r3_6593, s32 *, 0x80) = (s32) M2C_FIELD(&lit_723, s32 *, 0x5C);
    M2C_FIELD(temp_r3_6593, s32 *, 0x84) = (s32) M2C_FIELD(&lit_723, s32 *, 0x60);
    M2C_FIELD(temp_r3_6593, s32 *, 0x88) = (s32) M2C_FIELD(&lit_723, s32 *, 0x64);
    M2C_FIELD(temp_r3_6593, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_723, s32 *, 0x68);
    M2C_FIELD(temp_r3_6593, s32 *, 0x90) = (s32) M2C_FIELD(&lit_723, s32 *, 0x6C);
    M2C_FIELD(temp_r3_6593, s32 *, 0x94) = (s32) M2C_FIELD(&lit_723, s32 *, 0x70);
    M2C_FIELD(temp_r3_6593, s32 *, 0x98) = (s32) M2C_FIELD(&lit_723, s32 *, 0x74);
    M2C_FIELD(temp_r3_6593, s32 *, 0x9C) = (s32) M2C_FIELD(&lit_723, s32 *, 0x78);
    M2C_FIELD(temp_r3_6593, s32 *, 0xA0) = (s32) M2C_FIELD(&lit_723, s32 *, 0x7C);
    M2C_FIELD(temp_r3_6593, s32 *, 0xA4) = (s32) M2C_FIELD(&lit_723, s32 *, 0x80);
    M2C_FIELD(temp_r3_6593, s32 *, 0xA8) = (s32) M2C_FIELD(&lit_723, s32 *, 0x84);
    M2C_FIELD(temp_r3_6593, s32 *, 0xAC) = (s32) M2C_FIELD(&lit_723, s32 *, 0x88);
    M2C_FIELD(temp_r3_6593, s32 *, 0xB0) = (s32) M2C_FIELD(&lit_723, s32 *, 0x8C);
}
#endif
