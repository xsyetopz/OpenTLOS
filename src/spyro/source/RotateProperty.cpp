#include "spyro/source/RotateProperty.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/Level.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern f32 gUpdateTimeDelta;

void RotateProperty::UpdateDynamicBone(MKDynamicBone *arg0, void *arg1) {
    s16 temp_r31_45;

    if ((u8) M2C_FIELD(arg0, u8 *, 0x84) != 0) {
        temp_r31_45 = M2C_FIELD(this->unk20, s16 *, 0x70);
        ((Animation *) (MKModel_GetAnimation(this->unk24)))->SetCustomMatrix((s32) temp_r31_45, (Matrix *) arg0, (AnimationMatrixPosition) 4, 0U);
    }
}

#if 0 // DRAFT: pointer/array required
void RotateProperty::Command(int arg0) {
    switch (arg0) {                                 /* irregular */
    case 1:
        *(*KDProperty::pInstanceMem + (this->unk8 + 0x84)) = 1;
        return;
    case 2:
        *(*KDProperty::pInstanceMem + (this->unk8 + 0x84)) = 0;
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[9])' does not match 'stricmp(signed char *, long *)'
s32 RotateProperty::ResolveCommand(const char *arg0) const {
    s32 temp_r3_105;

    if (stricmp(arg0, "Activate") == 0) {
        return 1;
    }
    temp_r3_105 = stricmp(arg0, "Deactivate") - 1;
    return 2 & ((temp_r3_105 - temp_r3_105) - !M2C_CARRY);
}
#endif

#if 0 // DRAFT: pointer/array required
void RotateProperty::Update() {
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
    f32 sp14;
    f32 sp10;
    Matrix *temp_r3_265;
    Matrix *temp_r3_283;
    Matrix *temp_r3_289;
    f32 temp_f2_160;
    f32 temp_f2_177;
    f32 temp_f2_194;
    f64 temp_f0_217;
    s32 temp_r0_159;
    s32 temp_r0_175;
    s32 temp_r0_192;
    s32 temp_r3_212;
    s32 temp_r3_260;
    void *temp_r3_130;
    void *temp_r3_140;
    void *temp_r3_214;
    void *temp_r5_213;
    void *temp_r6_264;

    temp_r3_130 = (void *) (*KDProperty::pInstanceMem + this->unk8);
    if ((u8) M2C_FIELD(temp_r3_130, u8 *, 0x84) != 0) {
        sp20 = M2C_FIELD(this, f64 *, 0x20) * (f64) gUpdateTimeDelta;
        temp_r3_140 = ((u8 *) temp_r3_130) + 0x40;
        sp60 = sp20;
        sp28 = this->unk28 * gUpdateTimeDelta;
        sp68 = (f64) sp28;
        M2C_FIELD(temp_r3_140, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_140, f64 *, 0) + sp20);
        M2C_FIELD(temp_r3_140, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_140, f32 *, 8) + (f32) sp68);
        temp_r0_159 = this->unk8 + 0x40;
        temp_f2_160 = *(*KDProperty::pInstanceMem + temp_r0_159);
        if (temp_f2_160 > 6.2831855f) {
            *(*KDProperty::pInstanceMem + temp_r0_159) = temp_f2_160 - 6.2831855f;
        } else if (temp_f2_160 < 0.0f) {
            *(*KDProperty::pInstanceMem + temp_r0_159) = temp_f2_160 + 6.2831855f;
        }
        temp_r0_175 = this->unk8 + 0x44;
        temp_f2_177 = *(*KDProperty::pInstanceMem + temp_r0_175);
        if (temp_f2_177 > 6.2831855f) {
            *(*KDProperty::pInstanceMem + temp_r0_175) = temp_f2_177 - 6.2831855f;
        } else if (temp_f2_177 < 0.0f) {
            *(*KDProperty::pInstanceMem + temp_r0_175) = temp_f2_177 + 6.2831855f;
        }
        temp_r0_192 = this->unk8 + 0x48;
        temp_f2_194 = *(*KDProperty::pInstanceMem + temp_r0_192);
        if (temp_f2_194 > 6.2831855f) {
            *(*KDProperty::pInstanceMem + temp_r0_192) = temp_f2_194 - 6.2831855f;
        } else if (temp_f2_194 < 0.0f) {
            *(*KDProperty::pInstanceMem + temp_r0_192) = temp_f2_194 + 6.2831855f;
        }
        if ((s32) this->unk30 < 0) {
            temp_r3_212 = *KDProperty::pInstanceMem + this->unk8;
            temp_r5_213 = (void *) (temp_r3_212 + 0x40);
            temp_r3_214 = (void *) (temp_r3_212 + 0x50);
            temp_f0_217 = M2C_FIELD(temp_r3_214, f64 *, 0) + M2C_FIELD(temp_r5_213, f64 *, 0);
            sp30 = temp_f0_217;
            sp50 = temp_f0_217;
            sp38 = M2C_FIELD(temp_r3_214, f32 *, 8) + M2C_FIELD(temp_r5_213, f32 *, 8);
            sp58 = (f64) sp38;
            MKModel_SetRotation(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), *((MKVector3 *) &sp50));
            M2C_STRUCT_COPY((s32) &unksp6C + 4, MKModel_GetWorldMatrix(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4)) - 4 + 4, 0x40);
            sp70.Scale3x3(&sp70, *(*KDProperty::pInstanceMem + (this->unk8 + 0x60)));
            MKModel_SetWorldMatrix(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), sp70);
            return;
        }
        ((Matrix *) (*KDProperty::pInstanceMem + this->unk8))->SetIdentity();
        temp_r3_260 = this->unk8;
        temp_r6_264 = (void *) (*KDProperty::pInstanceMem + (temp_r3_260 + 0x70));
        temp_r3_265 = (Matrix *) (*KDProperty::pInstanceMem + temp_r3_260);
        sp10 = -M2C_FIELD(temp_r6_264, f32 *, 0);
        sp14 = -M2C_FIELD(temp_r6_264, f32 *, 4);
        sp18 = -M2C_FIELD(temp_r6_264, f32 *, 8);
        sp40 = (f64) sp10;
        sp48 = (f64) sp18;
        temp_r3_265->Translate(temp_r3_265, *((MKVector3 *) &sp40));
        temp_r3_283 = (Matrix *) (*KDProperty::pInstanceMem + this->unk8);
        temp_r3_283->RotatePYR(temp_r3_283, *(temp_r3_283 + 0x40));
        temp_r3_289 = (Matrix *) (*KDProperty::pInstanceMem + this->unk8);
        temp_r3_289->Translate(temp_r3_289, *(temp_r3_289 + 0x70));
    }
}
#endif

#if 0 // DRAFT: ')' expected
void RotateProperty::ResolveInstance() {
    Matrix sp60;
    f64 sp50;
    f64 sp48;
    f64 sp38;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    u16 sp10;
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
        temp_f30_333 = M2C_FIELD(MKModel_GetWorldMatrix(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4)), f32 *, 0x28);
        temp_f31_337 = M2C_FIELD(MKModel_GetWorldMatrix(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4)), f32 *, 0x14);
        sp18 = *MKModel_GetWorldMatrix(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4));
        sp1C = temp_f31_337;
        temp_r3_346 = (void *) (*KDProperty::pInstanceMem + (this->unk8 + 0x60));
        sp20 = temp_f30_333;
        M2C_FIELD(temp_r3_346, f64 *, 0) = (f64) sp18;
        M2C_FIELD(temp_r3_346, f64 *, 8) = (f64) sp20;
        sp48 = (f64) sp18;
        sp50 = (f64) sp20;
        MKModel_GetWorldMatrix(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4));
        ((Matrix *) &sp38)->GetRotationPYR();
        temp_r3_365 = (void *) (*KDProperty::pInstanceMem + (this->unk8 + 0x50));
        M2C_FIELD(temp_r3_365, f64 *, 0) = sp38;
        M2C_FIELD(temp_r3_365, f64 *, 8) = sp40;
        return;
    }
    this->unk30 = MKModel_GetSubObjectIndex(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), (SubObjectType) 0, this->unk10);
    temp_r30_382 = Tools_GetMatchingNodeIndex(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), this->unk10 + 2);
    temp_r3_384 = MKModel_GetAnimation(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4));
    sp10 = temp_r30_382;
    temp_r3_384->CalculateMatrices(&sp60, 1, (s16 *) &sp10, NULL);
    temp_r3_395 = MKModel_GetSubObjectOrigin(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), (SubObjectType) 0, this->unk30);
    temp_r5_402 = *KDProperty::pInstanceMem + (this->unk8 + 0x70);
    M2C_FIELD(temp_r5_402, f64 *, 0) = (f64) M2C_FIELD(temp_r3_395, f64 *, 0);
    M2C_FIELD(temp_r5_402, f64 *, 8) = (f64) M2C_FIELD(temp_r3_395, f64 *, 8);
    ((Matrix *) &sp28)->GetRotationPYR();
    temp_r3_413 = *KDProperty::pInstanceMem + (this->unk8 + 0x50);
    M2C_FIELD(temp_r3_413, f64 *, 0) = sp28;
    M2C_FIELD(temp_r3_413, f64 *, 8) = sp30;
    temp_r30_419 = *KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(temp_r30_419, void **, 0x80) = MKDynamicBone_AddDynamicBone(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), (s32) temp_r30_382);
    temp_r5_426 = *KDProperty::pInstanceMem + this->unk8;
    MKDynamicBone_SetUpdater(M2C_FIELD(temp_r5_426, MKDynamicBone **, 0x80), (void (*)(MKDynamicBone *, void *)) &RotateProperty::UpdateDynamicBone, temp_r5_426);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to 'bool *'
s32 RotateProperty::LoadLineInstance(MKIniLine *arg0) {
    arg0->LoadBool("Enabled", *KDProperty::pInstanceMem + (this->unk8 + 0x84), 0);
}
#endif

void RotateProperty::InitInstance() {
    MKIniLine *var_r31_491;
    void *temp_r3_476;

    temp_r3_476 = (void *) (*KDProperty::pInstanceMem + this->unk8);
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

#if 0 // DRAFT: ')' expected
void RotateProperty::Resolve(KDPropertySet *arg0) {
    if (((u32) this->unk14 == 0) && ((s8 *) this->unk10 != NULL) && (stricmp"localToWorld" == 0)) {
        this->unk14 = property_cast<KDMatrixProperty *, KDProperty *>(arg0->Find(this->unk10));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to 'const char **'
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

#if 0 // DRAFT: illegal implicit conversion from 'float' to 'void *'
RotateProperty::RotateProperty() {
    this->unk4 = NULL;
    this->unkC = NULL;
    this->unk8 = 0;
    this->unk18 = NULL;
    this->unk10 = (signed char *) ("localToWorld");
    this->unk14 = 0;
    this->unk20 = 0.0f;
    this->unk24 = 0.0f;
    this->unk28 = 0.0f;
    this->unk30 = -1;
}
#endif
