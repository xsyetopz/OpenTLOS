#include "spyro/source/Enemies_Earth.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_Think.h"
#include "unplaced_enums.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 stricmp(s32, void *);                           /* extern */
extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: ';' expected
static CharacterBodyFxInit earthTier1BodyFXInit;    /* unable to generate initializer: confusing struct layout */
static CharacterBodyFxInit earthTier3BodyFXInit;    /* unable to generate initializer: confusing struct layout */

void EarthTier3::Update() {
    Enemy::Update();
    TestForSpikes();
}
#endif

#if 0 // DRAFT: pointer/array required
void EarthTier3::Deinit() {
    s32 temp_r3_64;

    temp_r3_64 = this->unkAF8;
    if ((u32) temp_r3_64 != 0U) {
        M2C_FIELD(*temp_r3_64, M2C_UNK (**)(), 0xC)();
        operator delete((void *) this->unkAF8);
    }
    Enemy::Deinit();
}
#endif

#if 0 // DRAFT: function call 'operator new(unsigned int, int, int)' does not match
void EarthTier3::Init() {
    EnemyGoal_Think *temp_r31_96;
    s32 temp_r4_144;

    Enemy::Init();
    operator new(0x74U, NULL, 0);
    temp_r31_96 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_96 != NULL) {
        temp_r31_96->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_96->unk4 = 0;
        temp_r31_96->unk8 = 1;
        temp_r31_96->unk9 = 0;
        temp_r31_96->unkC = 0;
        temp_r31_96->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_96->unk1C = 0;
        temp_r31_96->unk18 = 0;
        temp_r31_96->unk10 = 0;
        temp_r31_96->unk14 = 0;
        temp_r31_96->__vptr = &__vt;
    }
    temp_r31_96->Init((Enemy *) this);
    this->unkA24 = (EnemyAttack *) temp_r31_96;
    operator new(0x10U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unkAF8 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r4_144 = this->unkAF8;
    M2C_FIELD(temp_r4_144, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_144, EarthTier3 **, 0xC) = this;
    M2C_FIELD(temp_r4_144, s32 *, 4) = 0x38;
    if ((EarthTier3 *) M2C_FIELD(temp_r4_144, EarthTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_144, s8 *, 9) = 1;
    }
    SetSpawnGoal__15EnemyGoal_ThinkFP12Goal<5Enemy>(temp_r31_96, (Goal<Enemy> *) this->unkAF8);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void EarthTier3Descriptor::Deinit() {
    this->unk244.Deinit();
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void EarthTier3Descriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk244.Init(&earthTier3BodyFXInit, 0xC, (MKAnimScript *) this->unk34);
}
#endif

void EarthTier2::Update() {
    Enemy::Update();
    TestForSpikes();
}

#if 0 // DRAFT: function call 'operator new(unsigned int, int, int)' does not match
void EarthTier2::Init() {
    EnemyGoal_Think *temp_r31_235;

    Enemy::Init();
    operator new(0x74U, NULL, 0);
    temp_r31_235 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_235 != NULL) {
        temp_r31_235->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_235->unk4 = 0;
        temp_r31_235->unk8 = 1;
        temp_r31_235->unk9 = 0;
        temp_r31_235->unkC = 0;
        temp_r31_235->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_235->unk1C = 0;
        temp_r31_235->unk18 = 0;
        temp_r31_235->unk10 = 0;
        temp_r31_235->unk14 = 0;
        temp_r31_235->__vptr = &__vt;
    }
    temp_r31_235->Init((Enemy *) this);
    this->unkA24 = (EnemyAttack *) temp_r31_235;
}
#endif

#if 0 // DRAFT: pointer/array required
void EarthTier1::Update() {
    f64 sp38;                                       /* compiler-managed */
    f64 sp30;                                       /* compiler-managed */
    f64 sp28;
    f64 sp20;
    MKVector3 sp10;
    f32 sp8;
    f32 temp_r3_291;
    f32 var_f0_422;
    f32 var_f3_383;
    f32 var_f4_316;
    f64 temp_f1_322;
    f64 temp_f1_328;
    f64 temp_f1_332;
    s32 temp_r3_351;
    s32 var_r0_361;
    void **temp_r3_280;

    Enemy::Update();
    if ((EnemyDescriptor *) this->unkA38 != NULL) {
        temp_r3_280 = this->unkA28;
        if ((temp_r3_280 != NULL) && (M2C_FIELD(*temp_r3_280, u8 (**)(M2C_UNK), 0x38)(0x14) == 0)) {
            temp_r3_291 = this->unkA38->unk20;
            if (M2C_BITWISE(u32, temp_r3_291) != 0U) {
                if ((stricmp(*temp_r3_291, "Roll_Cycle") == 0) && ((s32) this->unk110.unk16C > 0)) {
                    sp30 = this->unk110.unk18;
                    sp38 = this->unk110.unk20;
                    var_f4_316 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + ((*(f32 *) ((u8 *) &sp28 + 0xc)) * (*(f32 *) ((u8 *) &sp28 + 0xc))));
                    if (var_f4_316 > 0.000001f) {
                        if (var_f4_316 > 0.0f) {
                            temp_f1_322 = __frsqrte(var_f4_316);
                            temp_f1_328 = 0.5 * temp_f1_322 * -(((f64) var_f4_316 * (temp_f1_322 * temp_f1_322)) - 3.0);
                            temp_f1_332 = 0.5 * temp_f1_328 * -(((f64) var_f4_316 * (temp_f1_328 * temp_f1_328)) - 3.0);
                            var_f4_316 = (f32) ((f64) var_f4_316 * (0.5 * temp_f1_332 * -(((f64) var_f4_316 * (temp_f1_332 * temp_f1_332)) - 3.0)));
                        } else if (var_f4_316 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_316 = __float_nan;
                        } else {
                            sp8 = var_f4_316;
                            temp_r3_351 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_351) {  /* irregular */
                            case 0x7F800000:
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_361 = 1;
                                } else {
                                    var_r0_361 = 2;
                                }
                                break;
                            case 0x0:
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_361 = 5;
                                } else {
                                    var_r0_361 = 3;
                                }
                                break;
                            default:
                                var_r0_361 = 4;
                                break;
                            }
                            if (var_r0_361 == 1) {
                                var_f4_316 = __float_nan;
                            }
                        }
                        var_f3_383 = 1.0f / var_f4_316;
                    } else {
                        var_f3_383 = 0.0f;
                    }
                    sp30 = (f32) sp30 * var_f3_383;
                    (*(f32 *) ((u8 *) &sp28 + 0xc)) *= var_f3_383;
                    sp38 = (f32) sp38 * var_f3_383;
                    Tools_GetGradient(sp10);
                    sp20 = M2C_BITWISE(f64, sp10);
                    sp28 = (f64) sp10.unk8;
                    this->unkAF8 = M2C_BITWISE(f32, this->unkAF8) + (gUpdateTimeDelta * (-(((f32) sp28 * MKVector3::up.unk8) + (((f32) sp20 * MKVector3::up.unk0) + ((*(f32 *) ((u8 *) &sp20 + 0x4)) * MKVector3::up.unk4))) * gUpdateTimeDelta));
                    var_f0_422 = M2C_BITWISE(f32, this->unkAF8);
                    if (var_f0_422 < 2.0f) {

                    } else {
                        var_f0_422 = 2.0f;
                    }
                    if (var_f0_422 > 1.0f) {

                    } else {
                        var_f0_422 = 1.0f;
                    }
                    this->unkAF8 = var_f0_422;
                    M2C_FIELD(M2C_FIELD(this, void **, 0x630), f32 *, 0x38) = M2C_BITWISE(f32, this->unkAF8);
                }
            } else {
                this->unkAF8 = 1.0f;
                M2C_FIELD(M2C_FIELD(this, void **, 0x630), f32 *, 0x38) = M2C_BITWISE(f32, this->unkAF8);
            }
        }
    }
    TestForSpikes();
}
#endif

#if 0 // DRAFT: function call 'operator new(unsigned int, int, int)' does not match
void EarthTier1::Init() {
    EnemyGoal_Think *temp_r31_471;

    Enemy::Init();
    operator new(0x74U, NULL, 0);
    temp_r31_471 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_471 != NULL) {
        temp_r31_471->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_471->unk4 = 0;
        temp_r31_471->unk8 = 1;
        temp_r31_471->unk9 = 0;
        temp_r31_471->unkC = 0;
        temp_r31_471->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_471->unk1C = 0;
        temp_r31_471->unk18 = 0;
        temp_r31_471->unk10 = 0;
        temp_r31_471->unk14 = 0;
        temp_r31_471->__vptr = &__vt;
    }
    temp_r31_471->Init((Enemy *) this);
    this->unkA24 = (EnemyAttack *) temp_r31_471;
    temp_r31_471->SetFollowSpawnPathParams((AnimSequenceType) 6, 0x13);
    this->unkAF8 = 1.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void EarthTier1Descriptor::Deinit() {
    this->unk244.Deinit();
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void EarthTier1Descriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk244.Init(&earthTier1BodyFXInit, 3, (MKAnimScript *) this->unk34);
}
#endif

#if 0 // DRAFT: undefined identifier 'earthTier1BodyFXInit'
void Enemies_Earth_cpp::__sinit() {
    f32 sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
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
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp1E0 = 2.5f;
    sp1D0 = 0.0f;
    sp1C0 = 2.5f;
    sp1B0 = 0.0f;
    sp1A0 = 2.5f;
    sp190 = 0.0f;
    sp180 = 2.0f;
    sp170 = 0.0f;
    sp1D8 = 2.5f;
    sp1DC = 2.5f;
    sp1C8 = 0.0f;
    sp1CC = 0.0f;
    sp1B8 = 2.5f;
    sp1BC = 2.5f;
    sp1A8 = 0.0f;
    sp1AC = 0.0f;
    sp198 = 2.5f;
    sp19C = 2.5f;
    sp188 = 0.0f;
    sp18C = 0.0f;
    sp178 = 2.0f;
    sp17C = 2.0f;
    sp168 = 0.0f;
    sp16C = 0.0f;
    M2C_FIELD(&earthTier1BodyFXInit, f64 *, 0x10) = (f64) sp1D8;
    M2C_FIELD(&earthTier1BodyFXInit, f64 *, 0x18) = (f64) sp1E0;
    M2C_FIELD(&earthTier1BodyFXInit, f64 *, 0x20) = (f64) sp1C8;
    M2C_FIELD(&earthTier1BodyFXInit, f64 *, 0x28) = (f64) sp1D0;
    M2C_FIELD(&earthTier1BodyFXInit, f64 *, 0x40) = (f64) sp1B8;
    M2C_FIELD(&earthTier1BodyFXInit, f64 *, 0x48) = (f64) sp1C0;
    M2C_FIELD(&earthTier1BodyFXInit, f64 *, 0x50) = (f64) sp1A8;
    M2C_FIELD(&earthTier1BodyFXInit, f64 *, 0x58) = (f64) sp1B0;
    M2C_FIELD(&earthTier1BodyFXInit, f64 *, 0x70) = (f64) sp198;
    M2C_FIELD(&earthTier1BodyFXInit, f64 *, 0x78) = (f64) sp1A0;
    M2C_FIELD(&earthTier1BodyFXInit, f64 *, 0x80) = (f64) sp188;
    M2C_FIELD(&earthTier1BodyFXInit, f64 *, 0x88) = (f64) sp190;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x10) = (f64) sp178;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x18) = (f64) sp180;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x20) = (f64) sp168;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x28) = (f64) sp170;
    sp158 = 2.0f;
    sp15C = 2.0f;
    sp160 = 2.0f;
    sp150 = 0.0f;
    sp140 = 2.0f;
    sp130 = 0.0f;
    sp120 = 2.0f;
    sp110 = 0.0f;
    sp100 = 2.0f;
    spF0 = 0.0f;
    spE0 = 2.0f;
    sp148 = 0.0f;
    sp14C = 0.0f;
    sp138 = 2.0f;
    sp13C = 2.0f;
    sp128 = 0.0f;
    sp12C = 0.0f;
    sp118 = 2.0f;
    sp11C = 2.0f;
    sp108 = 0.0f;
    sp10C = 0.0f;
    spF8 = 2.0f;
    spFC = 2.0f;
    spE8 = 0.0f;
    spEC = 0.0f;
    spD8 = 2.0f;
    spDC = 2.0f;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x40) = (f64) sp158;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x48) = (f64) sp160;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x50) = (f64) sp148;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x58) = (f64) sp150;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x70) = (f64) sp138;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x78) = (f64) sp140;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x80) = (f64) sp128;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x88) = (f64) sp130;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0xA0) = (f64) sp118;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0xA8) = (f64) sp120;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0xB0) = (f64) sp108;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0xB8) = (f64) sp110;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0xD0) = (f64) spF8;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0xD8) = (f64) sp100;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0xE0) = (f64) spE8;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0xE8) = (f64) spF0;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x100) = (f64) spD8;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x108) = (f64) spE0;
    spD0 = 0.0f;
    spC0 = 2.0f;
    spB0 = 0.0f;
    spA0 = 2.0f;
    sp90 = 0.0f;
    sp80 = 2.0f;
    sp70 = 0.0f;
    sp60 = 2.0f;
    sp50 = 0.0f;
    sp40 = 2.0f;
    sp30 = 0.0f;
    sp20 = 2.0f;
    sp10 = 0.0f;
    spC8 = 0.0f;
    spCC = 0.0f;
    spB8 = 2.0f;
    spBC = 2.0f;
    spA8 = 0.0f;
    spAC = 0.0f;
    sp98 = 2.0f;
    sp9C = 2.0f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp78 = 2.0f;
    sp7C = 2.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp58 = 2.0f;
    sp5C = 2.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp38 = 2.0f;
    sp3C = 2.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp18 = 2.0f;
    sp1C = 2.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x110) = (f64) spC8;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x118) = (f64) spD0;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x130) = (f64) spB8;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x138) = (f64) spC0;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x140) = (f64) spA8;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x148) = (f64) spB0;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x160) = (f64) sp98;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x168) = (f64) spA0;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x170) = (f64) sp88;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x178) = (f64) sp90;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x190) = (f64) sp78;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x198) = (f64) sp80;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x1A0) = (f64) sp68;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x1A8) = (f64) sp70;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x1C0) = (f64) sp58;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x1C8) = (f64) sp60;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x1D0) = (f64) sp48;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x1D8) = (f64) sp50;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x1F0) = (f64) sp38;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x1F8) = (f64) sp40;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x200) = (f64) sp28;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x208) = (f64) sp30;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x220) = (f64) sp18;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x228) = (f64) sp20;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x230) = (f64) sp8;
    M2C_FIELD(&earthTier3BodyFXInit, f64 *, 0x238) = (f64) sp10;
}
#endif
