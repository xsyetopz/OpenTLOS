#include "spyro/source/SwayProperty.h"
#include "common/Source/Animation.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDProperty.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern f32 gUpdateTimeDelta;

void SwayProperty::UpdateDynamicBone(MKDynamicBone *arg0, void *arg1) {
    s16 temp_r31_45;

    if ((u8) M2C_FIELD(arg0, u8 *, 0x88) != 0) {
        temp_r31_45 = M2C_FIELD(this->unk20, s16 *, 0x70);
        ((Animation *) (MKModel_GetAnimation(this->unk24)))->SetCustomMatrix((s32) temp_r31_45, (Matrix *) arg0, (AnimationMatrixPosition) 4, 0U);
    }
}

#if 0 // DRAFT: pointer/array required
void SwayProperty::Command(int arg0) {
    switch (arg0) {                                 /* irregular */
    case 1:
        *(*KDProperty::pInstanceMem + (this->unk8 + 0x88)) = 1;
        return;
    case 2:
        *(*KDProperty::pInstanceMem + (this->unk8 + 0x88)) = 0;
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[9])' does not match
s32 SwayProperty::ResolveCommand(const char *arg0) const {
    s32 temp_r3_105;

    if (stricmp(arg0, "Activate") == 0) {
        return 1;
    }
    temp_r3_105 = stricmp(arg0, "Deactivate") - 1;
    return 2 & ((temp_r3_105 - temp_r3_105) - !M2C_CARRY);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void SwayProperty::Update() {
    Matrix sp60;
    f64 sp58;
    f64 sp50;
    MKVector3 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Matrix *temp_r3_270;
    Matrix *temp_r3_288;
    Matrix *temp_r3_294;
    f32 temp_f1_138;
    f32 temp_f2_178;
    f32 temp_f2_196;
    f32 temp_f2_213;
    f32 var_f0_141;
    s32 temp_r0_176;
    s32 temp_r0_194;
    s32 temp_r0_211;
    s32 temp_r3_265;
    void *temp_r3_130;
    void *temp_r3_149;
    void *temp_r3_170;
    void *temp_r6_269;

    temp_r3_130 = *KDProperty::pInstanceMem + this->unk8;
    if ((u8) M2C_FIELD(temp_r3_130, u8 *, 0x88) != 0) {
        temp_f1_138 = (gUpdateTimeDelta * this->unk30) + M2C_FIELD(temp_r3_130, f32 *, 0x80);
        if (temp_f1_138 > 6.2831855f) {
            var_f0_141 = 0.0f;
        } else {
            var_f0_141 = temp_f1_138;
        }
        M2C_FIELD(temp_r3_130, f32 *, 0x80) = var_f0_141;
        temp_r3_149 = *KDProperty::pInstanceMem + this->unk8;
        sp40.operator*(_table_sinf(M2C_FIELD(temp_r3_149, f32 *, 0x80)));
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp28 = sp40.unk8 + M2C_FIELD((temp_r3_149 + 0x40), f32 *, 8);
        temp_r3_170 = *KDProperty::pInstanceMem + (this->unk8 + 0x50);
        M2C_FIELD(temp_r3_170, f64 *, 0) = sp20;
        M2C_FIELD(temp_r3_170, f64 *, 8) = (f64) sp28;
        temp_r0_176 = this->unk8 + 0x50;
        sp50 = sp20;
        temp_f2_178 = *(*KDProperty::pInstanceMem + temp_r0_176);
        sp58 = (f64) sp28;
        if (temp_f2_178 > 6.2831855f) {
            *(*KDProperty::pInstanceMem + temp_r0_176) = temp_f2_178 - 6.2831855f;
        } else if (temp_f2_178 < 0.0f) {
            *(*KDProperty::pInstanceMem + temp_r0_176) = temp_f2_178 + 6.2831855f;
        }
        temp_r0_194 = this->unk8 + 0x54;
        temp_f2_196 = *(*KDProperty::pInstanceMem + temp_r0_194);
        if (temp_f2_196 > 6.2831855f) {
            *(*KDProperty::pInstanceMem + temp_r0_194) = temp_f2_196 - 6.2831855f;
        } else if (temp_f2_196 < 0.0f) {
            *(*KDProperty::pInstanceMem + temp_r0_194) = temp_f2_196 + 6.2831855f;
        }
        temp_r0_211 = this->unk8 + 0x58;
        temp_f2_213 = *(*KDProperty::pInstanceMem + temp_r0_211);
        if (temp_f2_213 > 6.2831855f) {
            *(*KDProperty::pInstanceMem + temp_r0_211) = temp_f2_213 - 6.2831855f;
        } else if (temp_f2_213 < 0.0f) {
            *(*KDProperty::pInstanceMem + temp_r0_211) = temp_f2_213 + 6.2831855f;
        }
        if ((s32) this->unk34 < 0) {
            MKModel_SetRotation(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), *(*KDProperty::pInstanceMem + (this->unk8 + 0x50)));
            M2C_STRUCT_COPY((s32) &unksp5C + 4, MKModel_GetWorldMatrix(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4)) - 4 + 4, 0x40);
            sp60.Scale3x3(&sp60, *(*KDProperty::pInstanceMem + (this->unk8 + 0x60)));
            MKModel_SetWorldMatrix(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), sp60);
            return;
        }
        ((Matrix *) (*KDProperty::pInstanceMem + this->unk8))->SetIdentity();
        temp_r3_265 = this->unk8;
        temp_r6_269 = *KDProperty::pInstanceMem + (temp_r3_265 + 0x70);
        temp_r3_270 = *KDProperty::pInstanceMem + temp_r3_265;
        sp10 = -M2C_FIELD(temp_r6_269, f32 *, 0);
        sp14 = -M2C_FIELD(temp_r6_269, f32 *, 4);
        sp18 = -M2C_FIELD(temp_r6_269, f32 *, 8);
        sp30 = (f64) sp10;
        sp38 = (f64) sp18;
        temp_r3_270->Translate(temp_r3_270, *((MKVector3 *) &sp30));
        temp_r3_288 = *KDProperty::pInstanceMem + this->unk8;
        temp_r3_288->RotatePYR(temp_r3_288, *(temp_r3_288 + 0x50));
        temp_r3_294 = *KDProperty::pInstanceMem + this->unk8;
        temp_r3_294->Translate(temp_r3_294, *(temp_r3_294 + 0x70));
    }
}
#endif

#if 0 // DRAFT: ')' expected
void SwayProperty::ResolveInstance() {
    Matrix sp60;
    f64 sp50;
    f64 sp48;
    f64 sp38;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    u16 sp10;
    Animation *temp_r3_402;
    f32 temp_f30_338;
    f32 temp_f31_342;
    u16 temp_r30_387;
    void *temp_r30_424;
    void *temp_r3_351;
    void *temp_r3_370;
    void *temp_r3_391;
    void *temp_r3_397;
    void *temp_r3_418;
    void *temp_r5_431;

    if (((u32) this->unk14 != 0) && ((s8 *) this->unk10 != NULL) && (stricmp"localToWorld" == 0)) {
        temp_f30_338 = M2C_FIELD(MKModel_GetWorldMatrix(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4)), f32 *, 0x28);
        temp_f31_342 = M2C_FIELD(MKModel_GetWorldMatrix(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4)), f32 *, 0x14);
        sp18 = *MKModel_GetWorldMatrix(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4));
        sp1C = temp_f31_342;
        temp_r3_351 = *KDProperty::pInstanceMem + (this->unk8 + 0x60);
        sp20 = temp_f30_338;
        M2C_FIELD(temp_r3_351, f64 *, 0) = (f64) sp18;
        M2C_FIELD(temp_r3_351, f64 *, 8) = (f64) sp20;
        sp48 = (f64) sp18;
        sp50 = (f64) sp20;
        MKModel_GetWorldMatrix(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4));
        sp38.GetRotationPYR();
        temp_r3_370 = *KDProperty::pInstanceMem + (this->unk8 + 0x40);
        M2C_FIELD(temp_r3_370, f64 *, 0) = sp38;
        M2C_FIELD(temp_r3_370, f64 *, 8) = sp40;
        return;
    }
    this->unk34 = MKModel_GetSubObjectIndex(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), (SubObjectType) 0, this->unk10);
    temp_r30_387 = Tools_GetMatchingNodeIndex(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), this->unk10 + 2);
    temp_r3_391 = MKModel_GetSubObjectOrigin(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), (SubObjectType) 0, this->unk34);
    temp_r3_397 = *KDProperty::pInstanceMem + (this->unk8 + 0x70);
    M2C_FIELD(temp_r3_397, f64 *, 0) = (f64) M2C_FIELD(temp_r3_391, f64 *, 0);
    M2C_FIELD(temp_r3_397, f64 *, 8) = (f64) M2C_FIELD(temp_r3_391, f64 *, 8);
    temp_r3_402 = MKModel_GetAnimation(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4));
    sp10 = temp_r30_387;
    temp_r3_402->CalculateMatrices(&sp60, 1, (s16 *) &sp10, NULL);
    sp28.GetRotationPYR();
    temp_r3_418 = *KDProperty::pInstanceMem + (this->unk8 + 0x40);
    M2C_FIELD(temp_r3_418, f64 *, 0) = sp28;
    M2C_FIELD(temp_r3_418, f64 *, 8) = sp30;
    temp_r30_424 = *KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(temp_r30_424, void **, 0x84) = MKDynamicBone_AddDynamicBone(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), (s32) temp_r30_387);
    temp_r5_431 = *KDProperty::pInstanceMem + this->unk8;
    MKDynamicBone_SetUpdater(M2C_FIELD(temp_r5_431, MKDynamicBone **, 0x84), (void (*)(MKDynamicBone *, void *)) &SwayProperty::UpdateDynamicBone, temp_r5_431);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
s32 SwayProperty::LoadLineInstance(MKIniLine *arg0) {
    arg0->LoadBool("Enabled", *KDProperty::pInstanceMem + (this->unk8 + 0x88), 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void SwayProperty::InitInstance() {
    MKIniLine *var_r31_496;
    void *temp_r3_481;

    temp_r3_481 = *KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(temp_r3_481, s8 *, 0x88) = 0;
    M2C_FIELD(temp_r3_481, f32 *, 0x40) = 0.0f;
    M2C_FIELD(temp_r3_481, f32 *, 0x44) = 0.0f;
    M2C_FIELD(temp_r3_481, f32 *, 0x48) = 0.0f;
    M2C_FIELD(temp_r3_481, f32 *, 0x80) = 0.0f;
    M2C_FIELD(temp_r3_481, f32 *, 0x50) = 0.0f;
    M2C_FIELD(temp_r3_481, f32 *, 0x54) = 0.0f;
    M2C_FIELD(temp_r3_481, f32 *, 0x58) = 0.0f;
    M2C_FIELD(temp_r3_481, f32 *, 0x60) = 0.0f;
    M2C_FIELD(temp_r3_481, f32 *, 0x64) = 0.0f;
    M2C_FIELD(temp_r3_481, f32 *, 0x68) = 0.0f;
    M2C_FIELD(temp_r3_481, f32 *, 0x70) = 0.0f;
    M2C_FIELD(temp_r3_481, f32 *, 0x74) = 0.0f;
    M2C_FIELD(temp_r3_481, f32 *, 0x78) = 0.0f;
    var_r31_496 = this->unk18;
loop_2:
    if (var_r31_496 != NULL) {
        LoadLineInstance(var_r31_496);
        var_r31_496 = var_r31_496->unkC->GetNextLine(var_r31_496);
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void SwayProperty::Resolve(KDPropertySet *arg0) {
    if (((u32) this->unk14 == 0) && ((s8 *) this->unk10 != NULL) && (stricmp"localToWorld" == 0)) {
        this->unk14 = property_cast<KDMatrixProperty *, KDProperty *>(arg0->Find(this->unk10));
    }
    this->unk30 = 6.2831855f / this->unk30;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 SwayProperty::LoadLine(MKIniLine *arg0) {
    u8 var_r31_576;

    if ((MKIniLine *) this->unk18 == NULL) {
        this->unk18 = arg0;
    }
    var_r31_576 = 0;
    if ((arg0->LoadString("subObject", &this->unk10, 0) != 0) || (arg0->LoadVector3("Range", (MKVector3 *) &this->unk20, 0) != 0) || (arg0->LoadFloat("Period", &this->unk30, 0) != 0)) {
        var_r31_576 = 1;
    }
    return var_r31_576;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[13]' to
SwayProperty::SwayProperty() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    this->unk4 = NULL;
    this->unkC = NULL;
    this->unk8 = 0;
    this->unk18 = NULL;
    this->unk10 = "localToWorld";
    sp10 = 2.0f;
    sp8 = 2.0f;
    spC = 2.0f;
    this->unk14 = 0;
    M2C_FIELD(this, f64 *, 0x20) = (f64) sp8;
    this->unk28 = (f64) sp10;
    this->unk30 = 1.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk34 = -1;
    return this;
}
#endif
