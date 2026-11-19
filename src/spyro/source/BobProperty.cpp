#include "spyro/source/BobProperty.h"
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
#include "common/Source/StdMath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern f32 gUpdateTimeDelta;

void BobProperty::UpdateDynamicBone(MKDynamicBone *arg0, void *arg1) {
    s16 temp_r31_45;

    if ((u8) M2C_FIELD(arg0, u8 *, 0x14) != 0) {
        temp_r31_45 = M2C_FIELD(this->unk20, s16 *, 0x70);
        ((Animation *) (MKModel_GetAnimation(this->unk24)))->SetCustomMatrix((s32) temp_r31_45, (Matrix *) &arg0->unk20, (AnimationMatrixPosition) 4, 0U);
    }
}

#if 0 // DRAFT: pointer/array required
void BobProperty::Command(int arg0) {
    switch (arg0) {                                 /* irregular */
    case 1:
        *(*KDProperty::pInstanceMem + (this->unk8 + 0x14)) = 1;
        return;
    case 2:
        *(*KDProperty::pInstanceMem + (this->unk8 + 0x14)) = 0;
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[9])' does not match
s32 BobProperty::ResolveCommand(const char *arg0) const {
    s32 temp_r3_105;

    if (stricmp(arg0, "Activate") == 0) {
        return 1;
    }
    temp_r3_105 = stricmp(arg0, "Deactivate") - 1;
    return 2 & ((temp_r3_105 - temp_r3_105) - !M2C_CARRY);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void BobProperty::Update() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_137;
    f32 var_f0_140;
    f64 temp_f0_154;
    f64 temp_f0_165;
    f64 temp_f1_150;
    void *temp_r31_148;
    void *temp_r3_129;
    void *temp_r3_193;

    temp_r3_129 = *KDProperty::pInstanceMem + this->unk8;
    if ((u8) M2C_FIELD(temp_r3_129, u8 *, 0x14) != 0) {
        temp_f1_137 = (gUpdateTimeDelta * this->unk30) + M2C_FIELD(temp_r3_129, f32 *, 0x10);
        if (temp_f1_137 > 6.2831855f) {
            var_f0_140 = 0.0f;
        } else {
            var_f0_140 = temp_f1_137;
        }
        M2C_FIELD(temp_r3_129, f32 *, 0x10) = var_f0_140;
        temp_r31_148 = *KDProperty::pInstanceMem + this->unk8;
        temp_f1_150 = _table_sinf(M2C_FIELD(temp_r31_148, f32 *, 0x10));
        temp_f0_154 = M2C_FIELD(this, f64 *, 0x20) * temp_f1_150;
        sp18 = temp_f0_154;
        sp28 = temp_f0_154;
        sp20 = this->unk28 * (f32) temp_f1_150;
        sp30 = (f64) sp20;
        temp_f0_165 = sp28 + M2C_FIELD(temp_r31_148, f64 *, 0);
        sp8 = temp_f0_165;
        sp38 = temp_f0_165;
        sp10 = (f32) sp30 + M2C_FIELD(temp_r31_148, f32 *, 8);
        sp40 = (f64) sp10;
        if ((s32) this->unk34 < 0) {
            MKModel_SetPosition(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), *((MKVector3 *) &sp38));
            return;
        }
        ((Matrix *) (*KDProperty::pInstanceMem + (this->unk8 + 0x20)))->SetIdentity();
        temp_r3_193 = *KDProperty::pInstanceMem + (this->unk8 + 0x20);
        M2C_FIELD(temp_r3_193, f32 *, 0x30) = (f32) sp38;
        M2C_FIELD(temp_r3_193, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp38 + 0x4));
        M2C_FIELD(temp_r3_193, f32 *, 0x38) = (f32) sp40;
        M2C_FIELD(temp_r3_193, f32 *, 0x3C) = 1.0f;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void BobProperty::ResolveInstance() {
    f64 sp8;
    u16 temp_r30_252;
    void *temp_r30_270;
    void *temp_r3_235;
    void *temp_r3_264;
    void *temp_r5_277;

    if (((s8 *) this->unk10 != NULL) && (stricmp"localToWorld" == 0)) {
        MKModel_GetPosition(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4));
        temp_r3_235 = *KDProperty::pInstanceMem + this->unk8;
        M2C_FIELD(temp_r3_235, f64 *, 0) = (f64) *M2C_ERROR(/* Read from unset register $r3 */);
        M2C_FIELD(temp_r3_235, f64 *, 8) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f64 *, 8);
        return;
    }
    this->unk34 = MKModel_GetSubObjectIndex(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), (SubObjectType) 0, this->unk10);
    temp_r30_252 = Tools_GetMatchingNodeIndex(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), this->unk10 + 2);
    ((Animation *) &sp8)->GetNodeOrigin(MKModel_GetAnimation(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4)));
    temp_r3_264 = *KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(temp_r3_264, f64 *, 0) = sp8;
    M2C_FIELD(temp_r3_264, f64 *, 8) = sp10;
    temp_r30_270 = *KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(temp_r30_270, void **, 0x60) = MKDynamicBone_AddDynamicBone(M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4), (s32) temp_r30_252);
    temp_r5_277 = *KDProperty::pInstanceMem + this->unk8;
    MKDynamicBone_SetUpdater(M2C_FIELD(temp_r5_277, MKDynamicBone **, 0x60), (void (*)(MKDynamicBone *, void *)) &BobProperty::UpdateDynamicBone, temp_r5_277);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
s32 BobProperty::LoadLineInstance(MKIniLine *arg0) {
    arg0->LoadBool("Enabled", *KDProperty::pInstanceMem + (this->unk8 + 0x14), 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void BobProperty::InitInstance() {
    MKIniLine *var_r31_329;
    void *temp_r3_322;

    temp_r3_322 = *KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(temp_r3_322, s8 *, 0x14) = 0;
    M2C_FIELD(temp_r3_322, f32 *, 0) = 0.0f;
    M2C_FIELD(temp_r3_322, f32 *, 4) = 0.0f;
    M2C_FIELD(temp_r3_322, f32 *, 8) = 0.0f;
    M2C_FIELD(temp_r3_322, f32 *, 0x10) = 0.0f;
    M2C_FIELD(temp_r3_322, s32 *, 0x60) = 0;
    var_r31_329 = this->unk18;
loop_2:
    if (var_r31_329 != NULL) {
        LoadLineInstance(var_r31_329);
        var_r31_329 = var_r31_329->unkC->GetNextLine(var_r31_329);
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void BobProperty::Resolve(KDPropertySet *arg0) {
    if (((u32) this->unk14 == 0) && ((s8 *) this->unk10 != NULL) && (stricmp"localToWorld" == 0)) {
        this->unk14 = property_cast<KDMatrixProperty *, KDProperty *>(arg0->Find(this->unk10));
    }
    this->unk30 = 6.2831855f / this->unk30;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 BobProperty::LoadLine(MKIniLine *arg0) {
    u8 var_r31_409;

    if ((MKIniLine *) this->unk18 == NULL) {
        this->unk18 = arg0;
    }
    var_r31_409 = 0;
    if ((arg0->LoadString("subObject", &this->unk10, 0) != 0) || (arg0->LoadVector3("Range", (MKVector3 *) &this->unk20, 0) != 0) || (arg0->LoadFloat("Period", &this->unk30, 0) != 0)) {
        var_r31_409 = 1;
    }
    return var_r31_409;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[13]' to
BobProperty::BobProperty() {
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
    sp10 = 100.0f;
    sp8 = 100.0f;
    spC = 100.0f;
    this->unk14 = 0;
    M2C_FIELD(this, f64 *, 0x20) = (f64) sp8;
    M2C_FIELD(this, f64 *, 0x28) = (f64) sp10;
    this->unk30 = 1.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk34 = -1;
}
#endif
