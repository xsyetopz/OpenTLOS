#include "spyro/source/RotateProperty.h"
#include "common/Source/Animation.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDProperty.h"
#include "unplaced_templates.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void RotateProperty::UpdateDynamicBone(MKDynamicBone *arg0, void *arg1) {
    s16 temp_r31_45;

    if ((u8) M2C_FIELD(arg0, u8 *, 0x84) != 0) {
        temp_r31_45 = M2C_FIELD(this->unk20, s16 *, 0x70);
        ((Animation *) (MKModel_GetAnimation(this->unk24)))->SetCustomMatrix((s32) temp_r31_45, (Matrix *) arg0, (AnimationMatrixPosition) 4, 0U);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void RotateProperty::Command(int arg0) {
    switch (arg0) {                                 /* irregular */
    case 1:
        *(pInstanceMem.__vptr + (this->unk8 + 0x84)) = 1;
        return;
    case 2:
        *(pInstanceMem.__vptr + (this->unk8 + 0x84)) = 0;
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[9])' does not match
s32 RotateProperty::ResolveCommand(const char *arg0) const {
    s32 temp_r3_105;

    if (stricmp(arg0, "Activate") == 0) {
        return 1;
    }
    temp_r3_105 = stricmp(arg0, "Deactivate") - 1;
    return 2 & ((temp_r3_105 - temp_r3_105) - !M2C_CARRY);
}
#endif

#if 0 // DRAFT: expression syntax error
void RotateProperty::Update() {
    Matrix *temp_r3_265;
    Matrix *temp_r3_283;
    Matrix *temp_r3_289;
    f32 temp_f2_160;
    f32 temp_f2_177;
    f32 temp_f2_194;
    s32 temp_r0_159;
    s32 temp_r0_175;
    s32 temp_r0_192;
    s32 temp_r3_260;
    void *temp_r3_130;
    void *temp_r3_140;
    void *temp_r3_212;
    void *temp_r6_264;
    temp_r3_130 = pInstanceMem.__vptr + this->unk8;
    if ((u8) M2C_FIELD(temp_r3_130, u8 *, 0x84) != 0) {
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
        temp_r3_140 = temp_r3_130 + 0x40;
        arg_sp60 = arg_sp20;
        arg_sp28 = this->unk28 * gUpdateTimeDelta;
        arg_sp68 = (f64) arg_sp28;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_FIELD(temp_r3_140, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_140, f32 *, 8) + (f32) arg_sp68);
        temp_r0_159 = this->unk8 + 0x40;
        temp_f2_160 = *(pInstanceMem.__vptr + temp_r0_159);
        if (temp_f2_160 > 6.2831855f) {
            *(pInstanceMem.__vptr + temp_r0_159) = temp_f2_160 - 6.2831855f;
        } else if (temp_f2_160 < 0.0f) {
            *(pInstanceMem.__vptr + temp_r0_159) = temp_f2_160 + 6.2831855f;
        }
        temp_r0_175 = this->unk8 + 0x44;
        temp_f2_177 = *(pInstanceMem.__vptr + temp_r0_175);
        if (temp_f2_177 > 6.2831855f) {
            *(pInstanceMem.__vptr + temp_r0_175) = temp_f2_177 - 6.2831855f;
        } else if (temp_f2_177 < 0.0f) {
            *(pInstanceMem.__vptr + temp_r0_175) = temp_f2_177 + 6.2831855f;
        }
        temp_r0_192 = this->unk8 + 0x48;
        temp_f2_194 = *(pInstanceMem.__vptr + temp_r0_192);
        if (temp_f2_194 > 6.2831855f) {
            *(pInstanceMem.__vptr + temp_r0_192) = temp_f2_194 - 6.2831855f;
        } else if (temp_f2_194 < 0.0f) {
            *(pInstanceMem.__vptr + temp_r0_192) = temp_f2_194 + 6.2831855f;
        }
        if ((s32) this->unk30 < 0) {
            temp_r3_212 = pInstanceMem.__vptr + this->unk8;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r5, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp50 = arg_sp30;
            arg_sp38 = M2C_FIELD((temp_r3_212 + 0x50), f32 *, 8) + M2C_FIELD((temp_r3_212 + 0x40), f32 *, 8);
            arg_sp58 = (f64) arg_sp38;
            MKModel_SetRotation(M2C_FIELD(pInstanceMem.__vptr, MKModel **, 4), *((MKVector3 *) &arg_sp50));
            M2C_STRUCT_COPY((s32) &arg_sp6C + 4, MKModel_GetWorldMatrix(M2C_FIELD(pInstanceMem.__vptr, MKModel **, 4)) - 4 + 4, 0x40);
            arg_sp70.Scale3x3((Matrix *) &arg_sp70, *(pInstanceMem.__vptr + (this->unk8 + 0x60)));
            MKModel_SetWorldMatrix(M2C_FIELD(pInstanceMem.__vptr, MKModel **, 4), *((Matrix *) &arg_sp70));
            return;
        }
        ((Matrix *) (pInstanceMem.__vptr + this->unk8))->SetIdentity();
        temp_r3_260 = this->unk8;
        temp_r6_264 = pInstanceMem.__vptr + (temp_r3_260 + 0x70);
        temp_r3_265 = pInstanceMem.__vptr + temp_r3_260;
        arg_sp10 = -M2C_FIELD(temp_r6_264, f32 *, 0);
        arg_sp14 = -M2C_FIELD(temp_r6_264, f32 *, 4);
        arg_sp18 = -M2C_FIELD(temp_r6_264, f32 *, 8);
        arg_sp40 = (f64) arg_sp10;
        arg_sp48 = (f64) arg_sp18;
        temp_r3_265->Translate(temp_r3_265, *((MKVector3 *) &arg_sp40));
        temp_r3_283 = pInstanceMem.__vptr + this->unk8;
        temp_r3_283->RotatePYR(temp_r3_283, *(temp_r3_283 + 0x40));
        temp_r3_289 = pInstanceMem.__vptr + this->unk8;
        temp_r3_289->Translate(temp_r3_289, *(temp_r3_289 + 0x70));
    }
}
#endif

#if 0 // DRAFT: ')' expected
void RotateProperty::ResolveInstance() {
    Animation *temp_r3_384;
    f32 temp_f30_333;
    f32 temp_f31_337;
    u16 temp_r30_382;
    void *temp_r30_419;
    void *temp_r3_346;
    void *temp_r3_365;
    void *temp_r3_395;
    void *temp_r3_413;
    void *temp_r5_402;
    void *temp_r5_426;
    if (((u32) this->unk14 != 0) && ((s8 *) this->unk10 != NULL) && (stricmp"localToWorld" == 0)) {
        temp_f30_333 = M2C_FIELD(MKModel_GetWorldMatrix(M2C_FIELD(pInstanceMem.__vptr, MKModel **, 4)), f32 *, 0x28);
        temp_f31_337 = M2C_FIELD(MKModel_GetWorldMatrix(M2C_FIELD(pInstanceMem.__vptr, MKModel **, 4)), f32 *, 0x14);
        arg_sp18 = *MKModel_GetWorldMatrix(M2C_FIELD(pInstanceMem.__vptr, MKModel **, 4));
        arg_sp1C = temp_f31_337;
        temp_r3_346 = pInstanceMem.__vptr + (this->unk8 + 0x60);
        arg_sp20 = temp_f30_333;
        M2C_FIELD(temp_r3_346, f64 *, 0) = (f64) arg_sp18;
        M2C_FIELD(temp_r3_346, f64 *, 8) = (f64) arg_sp20;
        arg_sp48 = (f64) arg_sp18;
        arg_sp50 = (f64) arg_sp20;
        MKModel_GetWorldMatrix(M2C_FIELD(pInstanceMem.__vptr, MKModel **, 4));
        arg_sp38.GetRotationPYR();
        temp_r3_365 = pInstanceMem.__vptr + (this->unk8 + 0x50);
        M2C_FIELD(temp_r3_365, f64 *, 0) = arg_sp38;
        M2C_FIELD(temp_r3_365, f64 *, 8) = arg_sp40;
        return;
    }
    this->unk30 = MKModel_GetSubObjectIndex(M2C_FIELD(pInstanceMem.__vptr, MKModel **, 4), (SubObjectType) 0, this->unk10);
    temp_r30_382 = Tools_GetMatchingNodeIndex(M2C_FIELD(pInstanceMem.__vptr, MKModel **, 4), this->unk10 + 2);
    temp_r3_384 = MKModel_GetAnimation(M2C_FIELD(pInstanceMem.__vptr, MKModel **, 4));
    arg_sp10 = temp_r30_382;
    temp_r3_384->CalculateMatrices((Matrix *) &arg_sp60, 1, (s16 *) &arg_sp10, NULL);
    temp_r3_395 = MKModel_GetSubObjectOrigin(M2C_FIELD(pInstanceMem.__vptr, MKModel **, 4), (SubObjectType) 0, this->unk30);
    temp_r5_402 = pInstanceMem.__vptr + (this->unk8 + 0x70);
    M2C_FIELD(temp_r5_402, f64 *, 0) = (f64) M2C_FIELD(temp_r3_395, f64 *, 0);
    M2C_FIELD(temp_r5_402, f64 *, 8) = (f64) M2C_FIELD(temp_r3_395, f64 *, 8);
    arg_sp28.GetRotationPYR();
    temp_r3_413 = pInstanceMem.__vptr + (this->unk8 + 0x50);
    M2C_FIELD(temp_r3_413, f64 *, 0) = arg_sp28;
    M2C_FIELD(temp_r3_413, f64 *, 8) = arg_sp30;
    temp_r30_419 = pInstanceMem.__vptr + this->unk8;
    M2C_FIELD(temp_r30_419, void **, 0x80) = MKDynamicBone_AddDynamicBone(M2C_FIELD(pInstanceMem.__vptr, MKModel **, 4), (s32) temp_r30_382);
    temp_r5_426 = pInstanceMem.__vptr + this->unk8;
    MKDynamicBone_SetUpdater(M2C_FIELD(temp_r5_426, MKDynamicBone **, 0x80), (void (*)(MKDynamicBone *, void *)) &RotateProperty::UpdateDynamicBone, temp_r5_426);
}
#endif

#if 0 // DRAFT: expression syntax error
s32 RotateProperty::LoadLineInstance(MKIniLine *arg0) {
    arg0->LoadBool("Enabled", pInstanceMem.__vptr + (this->unk8 + 0x84), 0);
}
#endif

#if 0 // DRAFT: expression syntax error
void RotateProperty::InitInstance() {
    MKIniLine *var_r31_491;
    void *temp_r3_476;

    temp_r3_476 = pInstanceMem.__vptr + this->unk8;
    M2C_FIELD(temp_r3_476, s8 *, 0x84) = 0;
    M2C_FIELD(temp_r3_476, f32 *, 0x40) = 0.0f;
    M2C_FIELD(temp_r3_476, f32 *, 0x44) = 0.0f;
    M2C_FIELD(temp_r3_476, f32 *, 0x48) = 0.0f;
    M2C_FIELD(temp_r3_476, f32 *, 0x50) = 0.0f;
    M2C_FIELD(temp_r3_476, f32 *, 0x54) = 0.0f;
    M2C_FIELD(temp_r3_476, f32 *, 0x58) = 0.0f;
    M2C_FIELD(temp_r3_476, f32 *, 0x60) = 0.0f;
    M2C_FIELD(temp_r3_476, f32 *, 0x64) = 0.0f;
    M2C_FIELD(temp_r3_476, f32 *, 0x68) = 0.0f;
    M2C_FIELD(temp_r3_476, s32 *, 0x80) = 0;
    M2C_FIELD(temp_r3_476, f32 *, 0x70) = 0.0f;
    M2C_FIELD(temp_r3_476, f32 *, 0x74) = 0.0f;
    M2C_FIELD(temp_r3_476, f32 *, 0x78) = 0.0f;
    var_r31_491 = this->unk18;
loop_2:
    if (var_r31_491 != NULL) {
        LoadLineInstance(var_r31_491);
        var_r31_491 = var_r31_491->unkC->GetNextLine(var_r31_491);
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void RotateProperty::Resolve(KDPropertySet *arg0) {
    if (((u32) this->unk14 == 0) && ((s8 *) this->unk10 != NULL) && (stricmp"localToWorld" == 0)) {
        this->unk14 = property_cast<KDMatrixProperty *, KDProperty *>(arg0->Find(this->unk10));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 RotateProperty::LoadLine(MKIniLine *arg0) {
    u8 var_r31_567;

    if ((MKIniLine *) this->unk18 == NULL) {
        this->unk18 = arg0;
    }
    var_r31_567 = 0;
    if ((arg0->LoadString("subObject", &this->unk10, 0) != 0) || (arg0->LoadVector3("Rotation", (MKVector3 *) &this->unk20, 0) != 0)) {
        var_r31_567 = 1;
    }
    return var_r31_567;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[13]' to
RotateProperty::RotateProperty() {
    this->unk4 = 0;
    this->unkC = NULL;
    this->unk8 = 0;
    this->unk18 = NULL;
    this->unk10 = "localToWorld";
    this->unk14 = 0;
    this->unk20 = 0.0f;
    this->unk24 = 0.0f;
    this->unk28 = 0.0f;
    this->unk30 = -1;
    return this;
}
#endif
