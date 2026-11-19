#include "spyro/source/KDCloth.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/KDModelProperty.h"
#include "spyro/source/KDProperty.h"
#include "unplaced_templates.h"
#include "common/Source/MKWind.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
static s8 lit_stringBase0[0x44] = {
    0x6D,
    0x6F,
    0x64,
    0x65,
    0x6C,
    0,
    0x6C,
    0x69,
    0x74,
    0,
    0x67,
    0x72,
    0x61,
    0x76,
    0x69,
    0x74,
    0x79,
    0,
    0x66,
    0x72,
    0x69,
    0x63,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0,
    0x77,
    0x69,
    0x6E,
    0x64,
    0x4D,
    0x75,
    0x6C,
    0x74,
    0x69,
    0x70,
    0x6C,
    0x69,
    0x65,
    0x72,
    0,
    0x69,
    0x74,
    0x65,
    0x72,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0,
    0x63,
    0x6C,
    0x6F,
    0x74,
    0x68,
    0x53,
    0x75,
    0x62,
    0x4F,
    0x62,
    0x6A,
    0x65,
    0x63,
    0x74,
    0,
}; /* const */

void KDClothProperty::Resolve(KDPropertySet *arg0) {
    MKModel *temp_r4_81;
    s8 *temp_r0_69;
    s8 *temp_r3_78;

    temp_r0_69 = this->unk10;
    if (temp_r0_69 != NULL) {
        this->unk10 = property_cast<KDModelProperty *, KDProperty *>(arg0->Find(temp_r0_69));
    }
    temp_r3_78 = this->unk10;
    if (temp_r3_78 != NULL) {
        temp_r4_81 = M2C_FIELD(temp_r3_78, MKModel **, 0x10);
        if (temp_r4_81 != NULL) {
            this->unk14.Resolve(temp_r4_81);
        }
    }
}
#endif

#if 0 // DRAFT: identifier 'KDClothProperty::LoadLine(MKIniLine *)' redeclared
u8 KDClothProperty::LoadLine(MKIniLine *arg0) {
    u8 var_r31_103;

    var_r31_103 = 0;
    if ((this->unk14.LoadLine(arg0) != 0) || (arg0->LoadString(lit_stringBase0, &this->unk10, 0) != 0)) {
        var_r31_103 = 1;
    }
    return var_r31_103;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDClothDescriptor::Update(MKModel *arg0) {
    MKVector3 sp18;
    MKVector3 sp8;
    s32 var_r31_153;

    if ((s32) this->unk18 >= 0) {
        MKModel_GetPosition(arg0);
        MKWind_GetVelocity(sp18);
        ((MKCloth *) (MKModel_GetClothSubObject(arg0, this->unk18)))->SetForce(1, sp18, 1);
        return;
    }
    var_r31_153 = 0;
loop_4:
    if (var_r31_153 < MKModel_GetNmbrOfSubObjects(arg0, (SubObjectType) 2)) {
        MKModel_GetPosition(arg0);
        MKWind_GetVelocity(sp8);
        ((MKCloth *) (MKModel_GetClothSubObject(arg0, var_r31_153)))->SetForce(1, sp8, 1);
        var_r31_153 += 1;
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDClothDescriptor::Apply(MKModel *arg0) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKCloth *temp_r30_232;
    MKCloth *temp_r31_200;
    MKCloth *temp_r3_198;
    MKCloth *temp_r3_230;
    s32 temp_r4_194;
    s32 var_r31_225;

    temp_r4_194 = this->unk18;
    if (temp_r4_194 >= 0) {
        temp_r3_198 = MKModel_GetClothSubObject(arg0, temp_r4_194);
        temp_r31_200 = temp_r3_198;
        sp20 = 0.0f;
        sp18 = 0.0f;
        sp1C = -this->unk0;
        sp40 = (f64) sp20;
        sp38 = (f64) sp18;
        temp_r3_198->SetForce(0, *((MKVector3 *) &sp38), 0);
        temp_r31_200->SetFriction(this->unk4);
        temp_r31_200->SetIterations(this->unkC);
        temp_r31_200->unkDC = this->unk10;
        return;
    }
    var_r31_225 = 0;
loop_4:
    if (var_r31_225 < MKModel_GetNmbrOfSubObjects(arg0, (SubObjectType) 2)) {
        temp_r3_230 = MKModel_GetClothSubObject(arg0, var_r31_225);
        temp_r30_232 = temp_r3_230;
        sp10 = 0.0f;
        sp8 = 0.0f;
        spC = -this->unk0;
        sp30 = (f64) sp10;
        sp28 = (f64) sp8;
        temp_r3_230->SetForce(0, *((MKVector3 *) &sp28), 0);
        temp_r30_232->SetFriction(this->unk4);
        temp_r30_232->SetIterations(this->unkC);
        var_r31_225 += 1;
        temp_r30_232->unkDC = this->unk10;
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDClothDescriptor::Resolve(MKModel *arg0) {
    s8 *temp_r5_278;

    temp_r5_278 = this->unk14;
    if (temp_r5_278 != NULL) {
        this->unk18 = MKModel_GetSubObjectIndex(arg0, (SubObjectType) 2, temp_r5_278);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
u8 KDClothDescriptor::LoadLine(MKIniLine *arg0) {
    u8 var_r31_305;

    var_r31_305 = 0;
    if ((arg0->LoadInt(&lit_stringBase0[6], &this->unk10, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0xA], &this->unk0, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x12], &this->unk4, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x1B], &this->unk8, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x2A], &this->unkC, 0) != 0) || (arg0->LoadString(&lit_stringBase0[0x35], &this->unk14, 0) != 0)) {
        var_r31_305 = 1;
    }
    return var_r31_305;
}
#endif

void KDClothDescriptor::Init() {
    this->unk0 = 9810.0f;
    this->unk4 = 1.0f;
    this->unk8 = 1.0f;
    this->unkC = 3;
    this->unk14 = NULL;
    this->unk18 = -1;
    this->unk10 = -1;
}

#if 0 // DRAFT: identifier 'property_cast<...>(T1)' redeclared
s8 *property_cast<KDModelProperty *, KDProperty *>(KDProperty *arg0) {
    KDModelProperty *sp8;

    sp8 = NULL;
    property_cast_ptr<KDModelProperty, KDProperty>(sp8, arg0);
    return (s8 *) sp8;
}
#endif

#if 0 // DRAFT: identifier 'property_cast_ptr<...>(T0 *&, T1 *)' redeclared
void property_cast_ptr<KDModelProperty, KDProperty>(KDModelProperty *&arg0, KDProperty *arg1) {
    if ((arg1 != NULL) && (arg1->IsOfType((KDPropertyClassInfo *) &classInfo) != 0)) {
        &arg0 = checked_cast<KDModelProperty *, KDProperty>(arg1);
    }
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<KDModelProperty *, KDProperty>(KDProperty *arg0) {

}
#endif
