#include "spyro/source/Enemies_Elec.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/ElecTier2Goals.h"
#include "spyro/source/ElecTier3Goals.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_Think.h"
#include "spyro/source/SlimeTrailFX.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(u16 *);                                /* extern */
u16 *malloc(M2C_UNK);                               /* extern */
extern s32 GS_ConduitAlert;
extern s32 GS_ConduitSplit;
extern s32 GS_ELElecTrailLP;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
extern void *gpTranslation_StringArray;
#if 0 // DRAFT: ';' expected
static CharacterBodyFxInit elecTier1BodyFXInit;     /* unable to generate initializer: confusing struct layout */

s32 ElecTier3::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    if (Enemy::Spawn(arg0, arg1) != 0) {
        KDSound_Play3d(GS_ConduitSplit, (MKVector3 *) &arg0->unk30, 0U, -1, 0.0f, 0U);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkspDC'
void ElecTier3::DrawScan() {
    M2C_UNK spE8;
    f64 spE0;                                       /* compiler-managed */
    f64 spD8;                                       /* compiler-managed */
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
    f64 sp80;
    f64 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_137;
    f32 temp_f24_135;
    f32 var_f29_94;
    s32 var_r29_126;
    s32 var_r29_165;
    s32 var_r31_128;
    s32 var_r31_167;
    void *temp_r30_176;
    void *temp_r3_139;

    var_f29_94 = 0.0f;
    sp68 = 0.01f;
    sp6C = 0.01f;
    sp70 = 0.01f;
    sp74 = 1.0f;
    sp18 = 0.1f;
    sp1C = 0.0f;
    spD8 = (f64) sp68;
    sp20 = 0.0f;
    sp24 = 1.0f;
    spE0 = (f64) sp70;
    spD8 = (f64) sp18;
    spE0 = (f64) sp20;
    spC8 = (f64) sp18;
    spD0 = (f64) sp20;
    if ((u8) M2C_FIELD(this, u8 *, 0xB55) != 0) {
        spE0 = 0.1f;
        spD8 = 0.7f;
        unkspDC = 0.7f;
        unkspE4 = 1.0f;
    }
    var_r29_126 = 0;
    var_r31_128 = 0;
    do {
        temp_f24_135 = 525.0f * -_table_sinf(1.5707964f + var_f29_94);
        temp_f1_137 = 525.0f * _table_sinf(var_f29_94);
        sp10 = 0.0f;
        temp_r3_139 = &spE8 + var_r31_128;
        var_r29_126 += 1;
        sp8 = temp_f1_137;
        var_f29_94 += 0.8975979f;
        var_r31_128 += 0x10;
        spC = temp_f24_135;
        spC0 = (f64) sp10;
        M2C_FIELD(temp_r3_139, f64 *, 0) = (f64) sp8;
        spB8 = (f64) sp8;
        M2C_FIELD(temp_r3_139, f64 *, 8) = (f64) sp10;
    } while (var_r29_126 < 8);
    MKMaterial_SetMaterial(M2C_FIELD(checked_cast<ElecTier3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x2C0));
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(*((Matrix *) &this->unkAF8));
    MKBegin(0x10);
    var_r29_165 = 0;
    var_r31_167 = 0;
    do {
        MKSetColorV(*((MKVector4 *) &spD8));
        MKSetTexCoord1F(0.0f, 0.0f);
        temp_r30_176 = &spE8 + var_r31_167;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        spA8 = sp58;
        sp60 = M2C_FIELD(temp_r30_176, f32 *, 8) * 0.1f;
        spB0 = (f64) sp60;
        MKSetPositionV(*((MKVector3 *) &spA8));
        MKSetColorV(*((MKVector4 *) &spD8));
        MKSetTexCoord1F(0.0f, 0.0f);
        sp40 = 2500.0f;
        sp38 = 0.0f;
        sp3C = 0.0f;
        sp80 = (f64) sp40;
        sp78 = (f64) sp38;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp88 = sp48;
        sp50 = M2C_FIELD(temp_r30_176, f32 *, 8) * 1.0f;
        sp90 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp98 = sp28;
        sp30 = (f32) sp90 + (f32) sp80;
        spA0 = (f64) sp30;
        MKSetPositionV(*((MKVector3 *) &sp98));
        var_r29_165 += 1;
        var_r31_167 += 0x10;
    } while (var_r29_165 < 8);
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: ')' expected
void ElecTier3::UpdateScan() {
    u8 var_r31_382;
    MKModel_CalculateNodeWorldMatrix(this->unk4, M2C_FIELD(checked_cast<ElecTier3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2B8), (Matrix *) &arg_sp120);
    arg_sp30 = -arg_sp140;
    arg_sp34 = -arg_sp144;
    arg_sp38 = -arg_sp148;
    arg_spF0 = (f64) arg_sp30;
    arg_spF8 = (f64) arg_sp38;
    arg_spE0 = (f64) arg_sp30;
    arg_spE8 = (f64) arg_sp38;
    arg_sp20 = (MKVector3::up.unk4 * (f32) arg_spF8) - (MKVector3::up.unk8 * arg_spF4);
    arg_sp24 = (MKVector3::up.unk8 * (f32) arg_spF0) - (MKVector3::up.unk0 * (f32) arg_spF8);
    arg_sp28 = (MKVector3::up.unk0 * arg_spF4) - (MKVector3::up.unk4 * (f32) arg_spF0);
    arg_spC0 = (f64) arg_sp20;
    arg_spC8 = (f64) arg_sp28;
    Normalise(*((MKVector3 *) &arg_spD0));
    arg_sp110 = arg_spD0;
    arg_sp118 = arg_spD8;
    this->unkAF8 = (f32) arg_sp110;
    this->unkAFC = arg_sp114;
    M2C_FIELD(this, f32 *, 0xB18) = (f32) arg_sp118;
    arg_sp18 = ((f32) arg_spF0 * arg_sp114) - (arg_spF4 * (f32) arg_sp110);
    arg_sp10 = (arg_spF4 * (f32) arg_sp118) - ((f32) arg_spF8 * arg_sp114);
    arg_sp14 = ((f32) arg_spF8 * (f32) arg_sp110) - ((f32) arg_spF0 * (f32) arg_sp118);
    arg_sp108 = (f64) arg_sp18;
    arg_sp100 = (f64) arg_sp10;
    this->unkB04 = 0.0f;
    M2C_FIELD(this, f32 *, 0xB20) = (f32) arg_sp100;
    this->unkB24 = arg_sp104;
    this->unkB10.unk0 = (f32) arg_sp108;
    this->unkB10.unk4 = 0.0f;
    arg_sp68 = 0.0f;
    this->unkB10.unk8 = (f32) arg_spF0;
    arg_sp60 = 0.0f;
    this->unkB10.unkC = arg_spF4;
    arg_sp64 = 1.0f;
    this->unkB10.unk10 = (f32) arg_spF8;
    this->unkB10.unk14 = 0.0f;
    arg_spB0 = (f64) arg_sp10;
    this->unkB10.unk18 = arg_sp150;
    arg_spB8 = (f64) arg_sp18;
    this->unkB10.unk1C = arg_sp154;
    this->unkB10.unk20 = arg_sp158;
    this->unkB10.unk24 = 1.0f;
    arg_spA0 = (f64) arg_sp60;
    arg_spA8 = (f64) arg_sp68;
    Tools_RotateMatrixToDirection((Matrix *) &this->unkAF8, *((MKVector3 *) &arg_spF0), *((MKVector3 *) &arg_spA0), -0.3926991f);
    if ((u8) M2C_FIELD(this, u8 *, 0xB55) == 0) {
        var_r31_382 = 0;
        if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk30.Get() != NULL)) {
            var_r31_382 = 1;
        }
        if (var_r31_382 != 0) {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_sp80 = arg_sp50;
            arg_sp58 = this->unkB10.unk10 * 2500.0f;
            arg_sp88 = (f64) arg_sp58;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp90 = arg_sp40;
            arg_sp48 = this->unkB10.unk20 + (f32) arg_sp88;
            arg_sp98 = (f64) arg_sp48;
            arg_sp70.GetPos();
            M2C_FIELD(this, u8 *, 0xB55) = (u8) (Tools_CylinderTest(*((MKVector3 *) &this->unkB10.unk18), *((MKVector3 *) &arg_sp90), 525.0f, *((MKVector3 *) &arg_sp70)) > 0.0f);
            if ((u8) M2C_FIELD(this, u8 *, 0xB55) != 0) {
                KDSound_Play3d(GS_ConduitAlert, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
    }
}
#endif

void ElecTier3::EnableScan(bool arg0) {
    s8 temp_r31_480;
    u8 var_r0_465;
    void *temp_r31_473;

    M2C_FIELD(this, u8 *, 0xB54) = arg0;
    if (arg0 != 0) {
        var_r0_465 = 0;
    } else {
        var_r0_465 = M2C_FIELD(this, u8 *, 0xB55);
    }
    M2C_FIELD(this, u8 *, 0xB55) = var_r0_465;
    temp_r31_473 = checked_cast<ElecTier3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r31_480 = ((Animation *) (MKModel_GetAnimation(this->unk4)))->GetNodeParentIndex(M2C_FIELD(temp_r31_473, s32 *, 0x2B8));
    ((Animation *) (MKModel_GetAnimation(this->unk4)))->SetCustomMatrix((s32) temp_r31_480, NULL, (AnimationMatrixPosition) 4, 0U);
}

void ElecTier3::Draw() {
    Enemy::Draw();
    if ((u8) M2C_FIELD(this, u8 *, 0xB54) != 0) {
        DrawScan();
    }
}

void ElecTier3::Update() {
    Enemy::Update();
    if ((u8) M2C_FIELD(this, u8 *, 0xB54) != 0) {
        UpdateScan();
    }
}

#if 0 // DRAFT: undefined identifier 'arg_spC'
void ElecTier3::UpdateMovementCustom() {
    UpdateRotation();
    UpdateModel();
    M2C_STRUCT_COPY((s32) &arg_spC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    arg_sp10.Scale3x3((Matrix *) &arg_sp10, this->unkB10.unk28);
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp10));
}
#endif

#if 0 // DRAFT: ')' expected
s32 ElecTier3::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    if (arg1 != NULL) {
        MKModel_CalculateNodeWorldPosition(this->unk4, M2C_FIELD(checked_cast<ElecTier3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2B8), arg1);
    }
    return 1;
}
#endif

#if 0 // DRAFT: ')' expected
s32 ElecTier3::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    if (arg1 != NULL) {
        MKModel_CalculateNodeWorldPosition(this->unk4, M2C_FIELD(checked_cast<ElecTier3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2B8), arg1);
    }
    return 1;
}
#endif

#if 0 // DRAFT: ')' expected
void ElecTier3::UpdateCollisionItems() {
    MKModel_CalculateNodeWorldPosition(this->unk4, M2C_FIELD(checked_cast<ElecTier3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2B4), (MKVector3 *) &this->unk60);
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
void ElecTier3::GetCharacterName() {
    return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x374);
}
#endif

#if 0 // DRAFT: expression syntax error
void ElecTier3::SetDefaults() {
    Enemy::SetDefaults();
    this->unkB10.unk28 = 1.0f;
    M2C_FIELD(this, s8 *, 0xB54) = 0;
    M2C_FIELD(this, s8 *, 0xB55) = 0;
    this->unkAF8.SetIdentity();
}
#endif

void ElecTier3::Deinit() {
    Enemy::Deinit();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ElecTier3::Init() {
    ElecTier3Goal_Think *temp_r31_713;

    Enemy::Init();
    operator new(0x58U, NULL, 0);
    temp_r31_713 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_713 != NULL) {
        temp_r31_713->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_713->unk4 = 0;
        temp_r31_713->unk8 = 1;
        temp_r31_713->unk9 = 0;
        temp_r31_713->unkC = NULL;
        temp_r31_713->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_713->unk1C = NULL;
        temp_r31_713->unk18 = 0;
        temp_r31_713->unk10 = 0;
        temp_r31_713->unk14 = 0;
        temp_r31_713->__vptr = &__vt;
    }
    temp_r31_713->Init((Enemy *) this);
    this->unkA24 = (EnemyAttack *) temp_r31_713;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ElecTier3Descriptor::Deinit() {
    MKHeap *temp_r3_757;
    MKMaterial *temp_r3_770;
    u16 *temp_r31_754;

    temp_r31_754 = this->unk28C;
    if (temp_r31_754 != NULL) {
        temp_r3_757 = MKHeap::Current();
        if (temp_r3_757 != NULL) {
            ((MKHeap *) (temp_r3_757->Current()))->Free(temp_r31_754, NULL, 0);
        } else {
            free(temp_r31_754);
        }
    }
    temp_r3_770 = this->unk2C0;
    if (temp_r3_770 != NULL) {
        MKMaterial_Destroy(temp_r3_770);
        this->unk2C0 = NULL;
    }
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource * (const char *)' to
void ElecTier3Descriptor::LoadDone() {
    MKHeap *temp_r3_822;
    MKMaterial *temp_r3_820;
    u16 *var_r3_829;

    EnemyDescriptor::LoadDone();
    this->unk2B4 = (s32) Tools_GetMatchingNodeIndex(this->unk2C, "body");
    this->unk2B8 = (s32) Tools_GetMatchingNodeIndex(this->unk2C, "eye");
    this->unk2BC = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "body");
    temp_r3_820 = MKMaterial_Create"teslaLight";
    this->unk2C0 = temp_r3_820;
    temp_r3_822 = temp_r3_820->Current();
    if (temp_r3_822 != NULL) {
        var_r3_829 = ((MKHeap *) (temp_r3_822->Current()))->Alloc(4, NULL, 0);
    } else {
        var_r3_829 = malloc(4);
    }
    this->unk28C = var_r3_829;
    M2C_FIELD(this->unk28C, u16 *, 0) = 1;
    M2C_FIELD(this->unk28C, s16 *, 2) = (s16) this->unk2BC;
    M2C_FIELD(this->unk28C, s16 *, 4) = 0xFF;
    this->unk16C = 600.0f;
}
#endif

#if 0 // DRAFT: ')' expected
s32 ElecTier2::FindLandingPos(MKVector3 *arg0) {
    MKCollisionResult sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f31_884;

    MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<ElecTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2BC), &sp58);
    sp18 = 0.0f;
    sp1C = 4000.0f;
    sp20 = 0.0f;
    sp48 = M2C_FIELD(this, f64 *, 0x588);
    temp_f31_884 = this->unk588.unk0 - sp58.unk4;
    sp28 = (f64) sp18;
    sp50 = M2C_FIELD(this, f64 *, 0x590);
    sp30 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp38 = sp8;
    sp10 = (f32) sp50 - (f32) sp30;
    sp40 = (f64) sp10;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp48), *((MKVector3 *) &sp38), &sp68, (MKCollisionMode) 7, M2C_FIELD(this->unk110.unk460, s32 *, 0x18) | 0x0C000000) != 0) {
        sp58 = M2C_BITWISE(f64, sp68);
        sp58.unk8 = (f64) sp68.unk8;
        sp58.unk4 += temp_f31_884;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp58.unk8 -= M2C_FIELD((this->unkA20->GetAnimSequence(0xA, 0xDD, M2C_BITWISE(s32, this->unkACC), NULL) + 8), f32 *, 8);
        M2C_FIELD(arg0, f64 *, 0) = M2C_BITWISE(f64, sp58);
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp58.unk8;
        return 1;
    }
    return 0;
}
#endif

void ElecTier2::UpdateMovementCustom() {
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r4, 0x0, qr0 */);
    this->unk588.unk4 += this->unk59C;
    UpdateRotation();
    UpdateModel();
}

#if 0 // DRAFT: expression syntax error
void ElecTier2::Update() {
    f64 sp8;
    f32 temp_f1_1007;
    f32 temp_f1_1018;

    this->unkB10.BeginUpdate();
    Enemy::Update();
    MKModel_GetWorldMatrix(this->unk4);
    sp8.GetRotationPYR();
    M2C_FIELD(this, f64 *, 0xB30) = sp8;
    this->unkB38 = sp10;
    this->unkB10.EndUpdate();
    if ((u8) M2C_FIELD(this, u8 *, 0xB12) != 0) {
        temp_f1_1007 = M2C_FIELD(this, f32 *, 0xB18);
        if (temp_f1_1007 > 0.0f) {
            M2C_FIELD(this, f32 *, 0xB18) = (f32) (temp_f1_1007 - gUpdateTimeDelta);
        }
    }
    if ((u8) M2C_FIELD(this, u8 *, 0xB12) == 0) {
        temp_f1_1018 = M2C_BITWISE(f32, this->unkB04);
        if (temp_f1_1018 > 0.0f) {
            this->unkB04 = temp_f1_1018 - gUpdateTimeDelta;
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void ElecTier2::Message(MKMessage *arg0) {
    this->unkB10.Message(arg0);
    Enemy::Message(arg0);
}
#endif

#if 0 // DRAFT: expression syntax error
void ElecTier2::Despawn(bool arg0) {
    Enemy::Despawn(arg0);
    this->unkB10.Reset();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp12C'
s32 ElecTier2::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    u8 var_r3_1112;
    void *temp_r4_1117;
    M2C_STRUCT_COPY((s32) &arg_sp12C + 4, (s32) (arg0 - 4) + 4, 0x40);
    MKModel_SetWorldMatrix(this->unk4, Matrix::identity);
    MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<ElecTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2B8), (MKVector3 *) &arg_sp120);
    MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<ElecTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2BC), (MKVector3 *) &arg_sp110);
    var_r3_1112 = 0;
    arg_sp120 = 0.0f;
    arg_sp128 = 0.0f;
    arg_sp110 = 0.0f;
    arg_sp118 = 0.0f;
    temp_r4_1117 = this->unkA2C;
    if ((temp_r4_1117 != NULL) && (M2C_FIELD(temp_r4_1117, s32 *, 4) & 0x200)) {
        var_r3_1112 = 1;
    }
    arg_sp80 = 0.0f;
    arg_sp84 = 100.0f;
    arg_sp88 = 0.0f;
    M2C_FIELD(this, u8 *, 0xB10) = var_r3_1112;
    arg_spE0 = (f64) arg_sp80;
    arg_spE8 = (f64) arg_sp88;
    M2C_ERROR(/* unknown instruction: psq_lx $f3, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
    arg_sp100 = arg_sp70;
    arg_sp78 = arg_sp168 + (f32) arg_spE8;
    arg_sp108 = (f64) arg_sp78;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
    arg_spF0 = arg_sp60;
    arg_sp68 = arg_sp168 + arg_sp128;
    arg_spF8 = (f64) arg_sp68;
    if (MKCollision_RayCollide(*((MKVector3 *) &arg_sp100), *((MKVector3 *) &arg_spF0), (MKCollisionResult *) &arg_sp170, (MKCollisionMode) 7, M2C_FIELD(this->unk110.unk460, s32 *, 0x18) | 0x0C000000) != 0) {
        if ((u8) M2C_FIELD(this, u8 *, 0xB10) != 0) {
            arg_sp20 = -arg_sp110;
            arg_sp24 = -arg_sp114;
            arg_sp28 = -arg_sp118;
            arg_spC0 = (f64) arg_sp20;
            arg_spC8 = (f64) arg_sp28;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spD0 = arg_sp40;
            arg_sp48 = arg_sp178 + (f32) arg_spC8;
            arg_spD8 = (f64) arg_sp48;
            arg_sp160 = (f32) arg_spD0;
            arg_sp164 = arg_spD4;
            arg_sp168 = (f32) arg_spD8;
            arg_sp16C = 1.0f;
        } else {
            arg_sp10 = -arg_sp120;
            arg_sp14 = -arg_sp124;
            arg_sp18 = -arg_sp128;
            arg_spA0 = (f64) arg_sp10;
            arg_spA8 = (f64) arg_sp18;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spB0 = arg_sp30;
            arg_sp38 = arg_sp178 + (f32) arg_spA8;
            arg_spB8 = (f64) arg_sp38;
            arg_sp160 = (f32) arg_spB0;
            arg_sp164 = arg_spB4;
            arg_sp168 = (f32) arg_spB8;
            arg_sp16C = 1.0f;
        }
        M2C_FIELD(this, s8 *, 0xB13) = 1;
    } else {
        M2C_FIELD(this, u8 *, 0xB10) = 0U;
        M2C_FIELD(this, s8 *, 0xB13) = 0;
    }
    if (Enemy::Spawn((Matrix *) &arg_sp130, NULL) != 0) {
        this->unk6B5 |= 0x10;
        this->unk6B5 &= ~0x20;
        M2C_FIELD(this, s8 *, 0xB12) = 1;
        M2C_FIELD(this, f32 *, 0xB18) = 0.0f;
        this->unkB04 = 0.0f;
        M2C_FIELD(this, u8 *, 0xB11) = (u8) M2C_FIELD(this, u8 *, 0xB10);
        if ((u8) M2C_FIELD(this, u8 *, 0xB11) != 0) {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp90 = arg_sp50;
            arg_sp58 = arg_sp118 + arg_sp168;
            arg_sp98 = (f64) arg_sp58;
            SetupEnemyRegion(*((MKVector3 *) &arg_sp90), 1500.0f);
        }
        this->unkAFC = 0;
        this->unkB10.Reset();
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: ')' expected
s32 ElecTier2::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    if (arg1 != NULL) {
        MKModel_CalculateNodeWorldPosition(this->unk4, M2C_FIELD(checked_cast<ElecTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2B4), arg1);
    }
    return 1;
}
#endif

#if 0 // DRAFT: ')' expected
s32 ElecTier2::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    if (arg1 != NULL) {
        MKModel_CalculateNodeWorldPosition(this->unk4, M2C_FIELD(checked_cast<ElecTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2B4), arg1);
    }
    return 1;
}
#endif

void ElecTier2::UpdateCollisionItems() {

}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void ElecTier2::SetupCollision() {
    u16 temp_r31_1380;
    void *temp_r30_1374;

    temp_r30_1374 = checked_cast<ElecTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r31_1380 = Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, "collision");
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddModel(this->unk4, (s32) temp_r31_1380, (MKCollisionMode) 2, this->unk634, M2C_FIELD(temp_r30_1374, u32 *, 0x70));
}
#endif

#if 0 // DRAFT: expression syntax error
void ElecTier2::LoadDone() {
    Enemy::LoadDone();
    this->unkB10.Init(checked_cast<P19ElecTier2Descriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0) + 0x2CC, this->unk634);
    this->unkB10.LoadDone((MKProp *) this, NULL);
    this->unkA28 = (void **) this->unkA24;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 ElecTier2::LoadLine(MKIniLine *arg0) {
    u8 sp8;

    sp8 = 0;
    if (Enemy::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->LoadBool("bStartGrounded", &sp8, 0) != 0) {
        M2C_FIELD(this, u8 *, 0xB10) = sp8;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: expression syntax error
void ElecTier2::Deinit() {
    this->unkB10.DetachAll();
    this->unkB10.Deinit();
    Enemy::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void ElecTier2::Init() {
    ElecTier2Goal_Think *temp_r31_1504;

    Enemy::Init();
    operator new(0x38U, NULL, 0);
    temp_r31_1504 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_1504 != NULL) {
        temp_r31_1504->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_1504->unk4 = 0;
        temp_r31_1504->unk8 = 1;
        temp_r31_1504->unk9 = 0;
        temp_r31_1504->unkC = NULL;
        temp_r31_1504->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_1504->unk1C = NULL;
        temp_r31_1504->unk18 = 0;
        temp_r31_1504->unk10 = 0;
        temp_r31_1504->unk14 = 0;
        temp_r31_1504->__vptr = &__vt;
    }
    temp_r31_1504->Init((Enemy *) this);
    this->unkA24 = (EnemyAttack *) temp_r31_1504;
    M2C_FIELD(this, s8 *, 0xB10) = 0;
    M2C_FIELD(this, s8 *, 0xB13) = 0;
}
#endif

void ElecTier2Descriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk70 = 0x08000000;
    this->unkC |= 0x4000;
    this->unkC &= 0xFFFFFFF7;
    this->unk1D4 = 0;
    this->unk2B4 = (s32) Tools_GetMatchingNodeIndex(this->unk2C, "head_03");
    this->unk2B8 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "ground");
    this->unk2BC = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "claw01_F");
    this->unk2C0 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "claw01_B");
    this->unk2C4 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "claw01_L");
    this->unk2C8 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "claw01_R");
    this->unk2D0 = 500.0f;
    this->unk2D4 = 0.1f * this->unk2D0;
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 ElecTier2Descriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1623;

    var_r31_1623 = 0;
    if ((EnemyDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("maxTilt", &this->unk2CC, 0) != 0) || (arg0->LoadBool("bUpdateRotationMatrix", &this->unk2DD, 0) != 0)) {
        var_r31_1623 = 1;
    }
    return var_r31_1623;
}
#endif

void ElecTier2Descriptor::Init() {
    EnemyDescriptor::Init();
    this->unk2CC = 0.5f;
    this->unk2D0 = 0.0f;
    this->unk2D4 = 0.0f;
    this->unk2D8 = 6.0f;
    this->unk2DC = 0;
    this->unk2DD = 1;
}

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void ElecTier1::Despawn(bool arg0) {
    s32 temp_r4_1692;

    temp_r4_1692 = this->unkAF8;
    if ((u32) temp_r4_1692 != 0U) {
        ((SlimeTrailFXManager *) (&gb + 0x2B8))->FreeTrail((SlimeTrailFX *) temp_r4_1692);
        this->unkAF8 = 0;
    }
    KDSound_Stop((s32 *) &this->unkB10);
    Enemy::Despawn(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp18'
void ElecTier1::CheckAnimEvents() {
    MKCollisionResult spC8;
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
    M2C_UNK sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp10;

    if ((((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(0x16) != 0) && ((u32) this->unkAF8 != 0U)) {
        sp28 = 0.0f;
        sp2C = -100.0f;
        sp30 = 0.0f;
        spB8 = M2C_FIELD(this, f64 *, 0xB18);
        sp78 = (f64) sp28;
        spC0 = M2C_FIELD(this, f64 *, 0xB20);
        sp80 = (f64) sp30;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
        sp50 = 0.0f;
        sp48 = 0.0f;
        sp4C = 100.0f;
        sp20 = (f32) spC0 + (f32) sp80;
        sp98 = (f64) sp48;
        sp88 = sp18;
        sp90 = (f64) sp20;
        spA0 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
        spA8 = sp38;
        sp40 = (f32) spC0 + (f32) spA0;
        spB0 = (f64) sp40;
        if (MKCollision_RayCollide(*((MKVector3 *) &spA8), *((MKVector3 *) &sp88), &spC8, (MKCollisionMode) 7, 0x08000000) != 0) {
            MKVector(0.0f, 5.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp68 = sp8;
            sp10 = spC8.unk8 + sp60;
            spB8 = sp8;
            sp70 = (f64) sp10;
            spC0 = (f64) sp10;
        }
        M2C_FIELD(this, f64 *, 0xB18) = spB8;
        M2C_FIELD(this, f64 *, 0xB20) = spC0;
        this->unkAF8->UpdatePos((MKVector3 *) &this->unkB00, *(this->unk8 + 0x10));
    }
    Enemy::CheckAnimEvents();
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
void ElecTier1::GetCharacterName() {
    return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x370);
}
#endif

#if 0 // DRAFT: ')' expected
void ElecTier1::Message(MKMessage *arg0) {
    s32 temp_r0_1837;
    s32 temp_r4_1845;

    temp_r0_1837 = arg0->unk0;
    switch (temp_r0_1837) {                         /* irregular */
    case -4:
        temp_r4_1845 = this->unkAF8;
        if ((u32) temp_r4_1845 != 0U) {
            ((SlimeTrailFXManager *) (&gb + 0x2B8))->FreeTrail((SlimeTrailFX *) temp_r4_1845);
            this->unkAF8 = 0;
        }
        break;
    case -3:
        if ((u32) this->unkAF8 == 0U) {
            this->unkAF8 = ((SlimeTrailFXManager *) (&gb + 0x2B8))->AllocTrail(M2C_FIELD(checked_cast<ElecTier1Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x2B4));
        }
        break;
    }
    this->unkB10.Message(arg0);
    Enemy::Message(arg0);
}
#endif

#if 0 // DRAFT: expression syntax error
void ElecTier1::Update() {
    s32 sp8;
    void *temp_r3_1907;

    Enemy::Update();
    sp8 = 1;
    this->unkB10.Update(GS_ELElecTrailLP, 1U, this->unkAF8 != 0, NULL, (MKVector3 *) &this->unkB00, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if (IsKnockedUp() == 0) {
        temp_r3_1907 = this->unk8;
        M2C_FIELD(this, f64 *, 0xB18) = (f64) M2C_FIELD(temp_r3_1907, f64 *, 0x30);
        M2C_FIELD(this, f64 *, 0xB20) = (f64) M2C_FIELD(temp_r3_1907, f64 *, 0x38);
    }
}
#endif

#if 0 // DRAFT: ')' expected
s32 ElecTier1::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    if ((u32) this->unkAF8 == 0U) {
        this->unkAF8 = ((SlimeTrailFXManager *) (&gb + 0x2B8))->AllocTrail(M2C_FIELD(checked_cast<ElecTier1Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x2B4));
    }
    Enemy::Spawn(arg0, arg1);
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void ElecTier1::Deinit() {
    Enemy::Deinit();
    KDSound_Stop((s32 *) &this->unkB10);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void ElecTier1::Init() {
    EnemyGoal_Think *temp_r31_1984;

    Enemy::Init();
    operator new(0x74U, NULL, 0);
    temp_r31_1984 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_1984 != NULL) {
        temp_r31_1984->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_1984->unk4 = 0;
        temp_r31_1984->unk8 = 1;
        temp_r31_1984->unk9 = 0;
        temp_r31_1984->unkC = 0;
        temp_r31_1984->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_1984->unk1C = 0;
        temp_r31_1984->unk18 = 0;
        temp_r31_1984->unk10 = 0;
        temp_r31_1984->unk14 = 0;
        temp_r31_1984->__vptr = &__vt;
    }
    temp_r31_1984->Init((Enemy *) this);
    this->unkA24 = (EnemyAttack *) temp_r31_1984;
    this->unkAF8 = 0;
    this->unkB10.Init(0.25f, 0.25f);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void ElecTier1Descriptor::Deinit() {
    MKMaterial_Destroy(this->unk2B4);
    this->unk244.Deinit();
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void ElecTier1Descriptor::LoadDone() {
    BoundingVolume *temp_r3_2059;
    BoundingVolume *temp_r3_2068;

    EnemyDescriptor::LoadDone();
    this->unk244.Init(&elecTier1BodyFXInit, 8, (MKAnimScript *) this->unk34);
    temp_r3_2059 = this->unk1C;
    temp_r3_2059->unk0 = -100.0f;
    temp_r3_2059->unk4 = 0.0f;
    temp_r3_2059->unk8 = -300.0f;
    temp_r3_2068 = this->unk1C;
    temp_r3_2068->unk10 = 200.0f;
    temp_r3_2068->unk14 = 200.0f;
    temp_r3_2068->unk18 = 500.0f;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource * (const char *)' to
void ElecTier1Descriptor::Init() {
    EnemyDescriptor::Init();
    this->unk2B4 = MKMaterial_Create"fx_slimetrail";
}
#endif

#if 0 // DRAFT: undefined identifier 'elecTier1BodyFXInit'
void Enemies_Elec_cpp::__sinit() {
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

    sp100 = 2.0f;
    spF0 = 0.0f;
    spE0 = 2.0f;
    spD0 = 0.0f;
    spC0 = 2.0f;
    spB0 = 0.0f;
    spA0 = 2.0f;
    sp90 = 0.0f;
    spF8 = 2.0f;
    spFC = 2.0f;
    spE8 = 0.0f;
    spEC = 0.0f;
    spD8 = 2.0f;
    spDC = 2.0f;
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
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x10) = (f64) spF8;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x18) = (f64) sp100;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x20) = (f64) spE8;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x28) = (f64) spF0;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x40) = (f64) spD8;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x48) = (f64) spE0;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x50) = (f64) spC8;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x58) = (f64) spD0;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x70) = (f64) spB8;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x78) = (f64) spC0;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x80) = (f64) spA8;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x88) = (f64) spB0;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0xA0) = (f64) sp98;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0xA8) = (f64) spA0;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0xB0) = (f64) sp88;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0xB8) = (f64) sp90;
    sp78 = 2.0f;
    sp7C = 2.0f;
    sp80 = 2.0f;
    sp70 = 0.0f;
    sp60 = 2.0f;
    sp50 = 0.0f;
    sp40 = 2.0f;
    sp30 = 0.0f;
    sp20 = 2.0f;
    sp10 = 0.0f;
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
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0xD0) = (f64) sp78;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0xD8) = (f64) sp80;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0xE0) = (f64) sp68;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0xE8) = (f64) sp70;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x100) = (f64) sp58;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x108) = (f64) sp60;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x110) = (f64) sp48;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x118) = (f64) sp50;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x130) = (f64) sp38;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x138) = (f64) sp40;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x140) = (f64) sp28;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x148) = (f64) sp30;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x160) = (f64) sp18;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x168) = (f64) sp20;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x170) = (f64) sp8;
    M2C_FIELD(&elecTier1BodyFXInit, f64 *, 0x178) = (f64) sp10;
}
#endif
