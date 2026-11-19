#include "spyro/source/Enemies_DreadWing.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/DropBox.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_Think.h"
#include "spyro/source/SpawnerObject.h"
#include "unplaced_templates.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern void **gMK;
extern void *gpTranslation_StringArray;
#if 0 // DRAFT: ';' expected
static CharacterBodyFxInit dreadWingBodyFXInit;     /* unable to generate initializer: confusing struct layout */

void DreadWing::DropDropBox() {
    s32 temp_r3_67;

    temp_r3_67 = this->unkAFC;
    if ((u32) temp_r3_67 != 0U) {
        temp_r3_67->Drop();
        this->unkAFC = 0;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
s32 DreadWing::PickUpDropBox(int arg0) {
    AttackSweepData *temp_r4_117;
    AttackSweepData *temp_r4_224;
    s32 temp_r0_136;
    s32 temp_r3_102;
    s32 temp_r3_108;
    s32 temp_r3_209;
    s32 temp_r3_215;
    s32 temp_r4_90;

    temp_r4_90 = this->unkAFC;
    if ((u32) temp_r4_90 != 0U) {
        M2C_FIELD(temp_r4_90, s32 *, 0x18) = (s32) this->unk18;
        M2C_FIELD(this->unkAFC, SpawnerObject **, 0x1D4)->unk18 = this->unk18;
        return 0;
    }
    temp_r3_102 = this->unkAF8;
    if ((u32) temp_r3_102 != 0U) {
        this->unkAFC = checked_cast<DropBox *, MKProp>(temp_r3_102->CreateInstance());
        temp_r3_108 = this->unkAFC;
        if ((u32) temp_r3_108 != 0U) {
            temp_r3_108->SetDefaults();
            M2C_FIELD(this->unkAFC, s32 *, 0x210) = arg0;
            M2C_FIELD(this->unkAFC, SpawnerObject **, 0x1D4)->unk24 = arg0;
            temp_r4_117 = this->unkA30;
            if (temp_r4_117 != NULL) {
                ((SpawnerObject *) (M2C_FIELD(this->unkAFC, SpawnerObject **, 0x1D4)))->SetParentSpawner((SpawnerObject *) temp_r4_117->unk0);
            }
        }
        M2C_FIELD(this->unkAFC, s32 *, 0x18) = (s32) this->unk18;
        M2C_FIELD(this->unkAFC, SpawnerObject **, 0x1D4)->unk18 = this->unk18;
        return 1;
    }
    temp_r0_136 = M2C_FIELD(this->unkA20, s32 *, 0xF4);
    switch (temp_r0_136) {                          /* irregular */
    case 35:
        this->unkAF8 = checked_cast<DropBoxDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "P3020_IceDropBox"));
        break;
    case 36:
        this->unkAF8 = checked_cast<DropBoxDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "P4008_EarthDropBox"));
        break;
    case 37:
        this->unkAF8 = checked_cast<DropBoxDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "P0086_DropBox"));
        break;
    case 38:
        this->unkAF8 = checked_cast<DropBoxDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "P5003_DropBox"));
        break;
    case 39:
        this->unkAF8 = checked_cast<DropBoxDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "P0086_DropBox"));
        break;
    }
    temp_r3_209 = this->unkAF8;
    if ((u32) temp_r3_209 != 0U) {
        this->unkAFC = checked_cast<DropBox *, MKProp>(temp_r3_209->CreateInstance());
        temp_r3_215 = this->unkAFC;
        if ((u32) temp_r3_215 != 0U) {
            temp_r3_215->SetDefaults();
            M2C_FIELD(this->unkAFC, s32 *, 0x210) = arg0;
            M2C_FIELD(this->unkAFC, SpawnerObject **, 0x1D4)->unk24 = arg0;
            temp_r4_224 = this->unkA30;
            if (temp_r4_224 != NULL) {
                ((SpawnerObject *) (M2C_FIELD(this->unkAFC, SpawnerObject **, 0x1D4)))->SetParentSpawner((SpawnerObject *) temp_r4_224->unk0);
            }
        }
        M2C_FIELD(this->unkAFC, SpawnerObject **, 0x1D4)->unk18 = this->unk18;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void DreadWing::UpdateDropBox() {
    Matrix sp100;
    M2C_UNK spFC;
    MKVector3 spE8;
    MKVector3 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;                                       /* compiler-managed */
    f64 spA8;                                       /* compiler-managed */
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 var_f7_335;
    f32 var_f8_319;
    f64 temp_f1_348;
    f64 temp_f1_354;
    f64 temp_f1_358;
    s32 temp_r3_377;
    s32 var_r0_387;
    void *temp_r4_315;

    if ((u32) this->unkAFC != 0U) {
        M2C_STRUCT_COPY((s32) &spFC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        MKModel_CalculateNodeWorldPosition(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "R_Foot"), &spE8);
        MKModel_CalculateNodeWorldPosition(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "L_Foot"), &spD8);
        sp38 = M2C_BITWISE(f64, spE8) - M2C_BITWISE(f64, spD8);
        sp88 = sp38;
        sp40 = spE8.unk8 - spD8.unk8;
        spC8 = sp38;
        sp90 = (f64) sp40;
        spD0 = (f64) sp40;
        sp68.operator/(2.0f);
        sp28 = M2C_BITWISE(f64, spD8) + M2C_BITWISE(f64, sp68);
        temp_r4_315 = this->unk8;
        var_f8_319 = 0.0f;
        spA8 = M2C_FIELD(temp_r4_315, f64 *, 0x20);
        spB0 = M2C_FIELD(temp_r4_315, f64 *, 0x28);
        sp30 = spD8.unk8 + sp68.unk8;
        var_f7_335 = ((f32) spB0 * (f32) spB0) + (((f32) spA8 * (f32) spA8) + (0.0f * 0.0f));
        sp78 = sp28;
        spB8 = sp28;
        sp80 = (f64) sp30;
        spC0 = (f64) sp30;
        sp98 = M2C_FIELD(&MKVector3::up, f64 *, 0);
        spA0 = M2C_FIELD(&MKVector3::up, f64 *, 8);
        unkspAC = 0.0f;
        if (var_f7_335 > 0.000001f) {
            if (var_f7_335 > 0.0f) {
                temp_f1_348 = __frsqrte(var_f7_335);
                temp_f1_354 = 0.5 * temp_f1_348 * -(((f64) var_f7_335 * (temp_f1_348 * temp_f1_348)) - 3.0);
                temp_f1_358 = 0.5 * temp_f1_354 * -(((f64) var_f7_335 * (temp_f1_354 * temp_f1_354)) - 3.0);
                var_f7_335 = (f32) ((f64) var_f7_335 * (0.5 * temp_f1_358 * -(((f64) var_f7_335 * (temp_f1_358 * temp_f1_358)) - 3.0)));
            } else if (var_f7_335 < M2C_BITWISE(f32, 0.0)) {
                var_f7_335 = __float_nan;
            } else {
                sp10 = var_f7_335;
                temp_r3_377 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_377) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_387 = 1;
                    } else {
                        var_r0_387 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_387 = 5;
                    } else {
                        var_r0_387 = 3;
                    }
                    break;
                default:
                    var_r0_387 = 4;
                    break;
                }
                if (var_r0_387 == 1) {
                    var_f7_335 = __float_nan;
                }
            }
            var_f8_319 = 1.0f / var_f7_335;
        }
        spA8 = (f32) spA8 * var_f8_319;
        unkspAC *= var_f8_319;
        spB0 = (f32) spB0 * var_f8_319;
        KDMath_BuildMatrixFromFwd(&sp100, *((MKVector3 *) &spA8), (MKVector3 *) &sp98);
        MKVector(0.0f, -860.00006f, 0.0f);
        sp18 = spB8 + sp48;
        sp58 = sp18;
        sp20 = (f32) spC0 + sp50;
        sp60 = (f64) sp20;
        sp100.unk30 = (f32) sp58;
        sp100.unk34 = unksp5C;
        sp100.unk38 = (f32) sp60;
        sp100.unk3C = 1.0f;
        MKModel_SetWorldMatrix(M2C_FIELD(this->unkAFC, MKModel **, 4), sp100);
    }
}
#endif

void DreadWing::CheckAnimEvents() {
    if (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(0) != 0) {
        DropDropBox();
    }
    Enemy::CheckAnimEvents();
}

#if 0 // DRAFT: ')' expected
void DreadWing::Message(MKMessage *arg0) {
    s32 temp_r31_499;

    if ((s32) arg0->unk0 == 0x8D) {
        temp_r31_499 = M2C_FIELD(gpTranslation_StringArray, s32 *, 0x34C);
        M2C_FIELD(checked_cast<GetNameMsg *, MKMessage>(arg0), s32 *, 8) = temp_r31_499;
        return;
    }
    Enemy::Message(arg0);
}
#endif

#if 0 // DRAFT: pointer/array required
void DreadWing::Despawn(bool arg0) {
    s32 temp_r3_522;

    Enemy::Despawn(arg0);
    temp_r3_522 = this->unkAFC;
    if ((u32) temp_r3_522 != 0U) {
        temp_r3_522->Drop();
    }
}
#endif

void DreadWing::Update() {
    Enemy::Update();
    UpdateDropBox();
}

#if 0 // DRAFT: illegal implicit conversion from 'const char[17]' to
void DreadWing::Resolve() {
    s32 temp_r0_561;

    temp_r0_561 = M2C_FIELD(this->unkA20, s32 *, 0xF4);
    switch (temp_r0_561) {                          /* irregular */
    case 35:
        this->unkAF8 = checked_cast<DropBoxDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "P3020_IceDropBox"));
        break;
    case 36:
        this->unkAF8 = checked_cast<DropBoxDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "P4008_EarthDropBox"));
        break;
    case 37:
        this->unkAF8 = checked_cast<DropBoxDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "P0086_DropBox"));
        break;
    case 38:
        this->unkAF8 = checked_cast<DropBoxDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "5003_DropBox"));
        break;
    case 39:
        this->unkAF8 = checked_cast<DropBoxDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "P0086_DropBox"));
        break;
    }
    Enemy::Resolve();
}
#endif

#if 0 // DRAFT: function call 'operator new(unsigned int, int, int)' does not match
void DreadWing::Init() {
    EnemyGoal_Think *temp_r31_656;

    Enemy::Init();
    operator new(0x74U, NULL, 0);
    temp_r31_656 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_656 != NULL) {
        temp_r31_656->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_656->unk4 = 0;
        temp_r31_656->unk8 = 1;
        temp_r31_656->unk9 = 0;
        temp_r31_656->unkC = 0;
        temp_r31_656->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_656->unk1C = 0;
        temp_r31_656->unk18 = 0;
        temp_r31_656->unk10 = 0;
        temp_r31_656->unk14 = 0;
        temp_r31_656->__vptr = &__vt;
    }
    temp_r31_656->Init((Enemy *) this);
    this->unkA24 = (EnemyAttack *) temp_r31_656;
    this->unkAFC = 0;
    this->unkAF8 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void DreadWingDescriptor::Deinit() {
    this->unk244.Deinit();
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void DreadWingDescriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk244.Init(&dreadWingBodyFXInit, 0xE, (MKAnimScript *) this->unk34);
}
#endif

#if 0 // DRAFT: undefined identifier 'dreadWingBodyFXInit'
void Enemies_DreadWing_cpp::__sinit() {
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

    sp1C0 = 3.0f;
    sp1B0 = 0.0f;
    sp1A0 = 2.0f;
    sp190 = 0.0f;
    sp180 = 2.0f;
    sp170 = 0.0f;
    sp160 = 3.0f;
    sp150 = 0.0f;
    sp1B8 = 3.0f;
    sp1BC = 3.0f;
    sp1A8 = 0.0f;
    sp1AC = 0.0f;
    sp198 = 2.0f;
    sp19C = 2.0f;
    sp188 = 0.0f;
    sp18C = 0.0f;
    sp178 = 2.0f;
    sp17C = 2.0f;
    sp168 = 0.0f;
    sp16C = 0.0f;
    sp158 = 3.0f;
    sp15C = 3.0f;
    sp148 = 0.0f;
    sp14C = 0.0f;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x10) = (f64) sp1B8;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x18) = (f64) sp1C0;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x20) = (f64) sp1A8;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x28) = (f64) sp1B0;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x40) = (f64) sp198;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x48) = (f64) sp1A0;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x50) = (f64) sp188;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x58) = (f64) sp190;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x70) = (f64) sp178;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x78) = (f64) sp180;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x80) = (f64) sp168;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x88) = (f64) sp170;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0xA0) = (f64) sp158;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0xA8) = (f64) sp160;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0xB0) = (f64) sp148;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0xB8) = (f64) sp150;
    sp138 = 3.0f;
    sp13C = 3.0f;
    sp140 = 3.0f;
    sp130 = 0.0f;
    sp120 = 2.0f;
    sp110 = 0.0f;
    sp100 = 2.0f;
    spF0 = 0.0f;
    spE0 = 2.0f;
    spD0 = 0.0f;
    spC0 = 3.0f;
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
    spC8 = 0.0f;
    spCC = 0.0f;
    spB8 = 3.0f;
    spBC = 3.0f;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0xD0) = (f64) sp138;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0xD8) = (f64) sp140;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0xE0) = (f64) sp128;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0xE8) = (f64) sp130;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x100) = (f64) sp118;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x108) = (f64) sp120;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x110) = (f64) sp108;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x118) = (f64) sp110;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x130) = (f64) spF8;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x138) = (f64) sp100;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x140) = (f64) spE8;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x148) = (f64) spF0;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x160) = (f64) spD8;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x168) = (f64) spE0;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x170) = (f64) spC8;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x178) = (f64) spD0;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x190) = (f64) spB8;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x198) = (f64) spC0;
    spB0 = 0.0f;
    spA0 = 2.0f;
    sp90 = 0.0f;
    sp80 = 2.0f;
    sp70 = 0.0f;
    sp60 = 2.0f;
    sp50 = 0.0f;
    sp40 = 2.5f;
    sp30 = 0.0f;
    sp20 = 2.5f;
    sp10 = 0.0f;
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
    sp38 = 2.5f;
    sp3C = 2.5f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp18 = 2.5f;
    sp1C = 2.5f;
    sp8 = 0.0f;
    spC = 0.0f;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x1A0) = (f64) spA8;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x1A8) = (f64) spB0;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x1C0) = (f64) sp98;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x1C8) = (f64) spA0;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x1D0) = (f64) sp88;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x1D8) = (f64) sp90;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x1F0) = (f64) sp78;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x1F8) = (f64) sp80;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x200) = (f64) sp68;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x208) = (f64) sp70;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x220) = (f64) sp58;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x228) = (f64) sp60;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x230) = (f64) sp48;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x238) = (f64) sp50;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x250) = (f64) sp38;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x258) = (f64) sp40;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x260) = (f64) sp28;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x268) = (f64) sp30;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x280) = (f64) sp18;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x288) = (f64) sp20;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x290) = (f64) sp8;
    M2C_FIELD(&dreadWingBodyFXInit, f64 *, 0x298) = (f64) sp10;
}
#endif
