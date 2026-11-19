#include "spyro/source/HurtProperty.h"
#include "common/Source/MKIni.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'arg_sp80'
void HurtProperty::DoHurt() {
    TargetManager ***var_r31_109;
    TargetManager **temp_r3_157;
    f32 temp_f2_130;
    void **temp_r3_46;
    void *temp_r3_115;
    void *temp_r4_118;
    temp_r3_46 = this->unk14;
    M2C_FIELD(*temp_r3_46, M2C_UNK (**)(void **, M2C_UNK *), 0x58)(temp_r3_46, &arg_sp80);
    arg_sp18 = 0.0f;
    arg_sp10 = 0.0f;
    arg_sp14 = 0.0f;
    arg_sp70 = arg_spB0;
    arg_sp78 = arg_spB8;
    arg_spC4 = 0;
    arg_sp60 = (f64) arg_sp10;
    arg_sp68 = (f64) arg_sp18;
    arg_spC0 = 7;
    arg_spE8 = 1;
    arg_spEC = pInstanceMem.__vptr;
    arg_spC8 = (f64) arg_sp10;
    arg_spD0 = (f64) arg_sp18;
    arg_sp100 = 0;
    arg_sp10C = 2;
    arg_sp108 = 10.0f;
    arg_sp100 = 0;
    (s16) arg_sp100 = 1;
    arg_sp104 = -1;
    arg_spD8 = M2C_FIELD(&one, f64 *, 0);
    arg_spE0 = M2C_FIELD(&one, f64 *, 8);
    arg_sp110 = 0;
    if ((void *) pInstanceMem.__vptr != NULL) {
        arg_sp30.GetPos();
        arg_spF0 = arg_sp30;
        arg_spF8 = arg_sp38;
    } else {
        arg_spF0 = 0.0f;
        arg_spF4 = 0.0f;
        arg_spF8 = 0.0f;
    }
    arg_sp110 = 0;
    var_r31_109 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
loop_8:
    if (var_r31_109 != NULL) {
        temp_r3_157 = *var_r31_109;
        if (temp_r3_157 != NULL) {
            temp_r3_115 = (*temp_r3_157)->unk8.unk0();
            if (temp_r3_115 != NULL) {
                temp_r4_118 = M2C_FIELD(temp_r3_115, void **, 8);
                arg_sp40 = M2C_FIELD(temp_r4_118, f64 *, 0x30);
                arg_sp48 = M2C_FIELD(temp_r4_118, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                temp_f2_130 = this->unk1C;
                arg_sp50 = arg_sp20;
                arg_sp28 = (f32) arg_sp48 - (f32) arg_sp78;
                arg_sp58 = (f64) arg_sp28;
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if ((((f32) arg_sp58 * (f32) arg_sp58) + (((f32) arg_sp50 * (f32) arg_sp50) + (arg_sp54 * arg_sp54))) == (temp_f2_130 * temp_f2_130)) {
                    M2C_FIELD(M2C_FIELD(temp_r3_115, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_spC0);
                }
            }
            var_r31_109 += 4;
            goto loop_8;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void HurtProperty::Command(int arg0) {
    switch (arg0) {                                 /* irregular */
    case 1:
        *(pInstanceMem.__vptr + this->unk8) = 1;
        DoHurt();
        return;
    case 2:
        *(pInstanceMem.__vptr + this->unk8) = 0;
        return;
    case 3:
        DoHurt();
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[9])' does not match
s32 HurtProperty::ResolveCommand(const char *arg0) const {
    s32 temp_r3_241;

    if (stricmp(arg0, "Activate") == 0) {
        return 1;
    }
    if (stricmp(arg0, "Deactivate") == 0) {
        return 2;
    }
    temp_r3_241 = stricmp(arg0, "Burst") - 1;
    return 3 & ((temp_r3_241 - temp_r3_241) - !M2C_CARRY);
}
#endif

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void HurtProperty::Update() {
    if ((u8) *(pInstanceMem.__vptr + this->unk8) != 0) {
        DoHurt();
    }
}
#endif

void HurtProperty::ResolveInstance() {

}

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void HurtProperty::LoadDoneInstance() {
    *(pInstanceMem.__vptr + this->unk8) = this->unk20;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 HurtProperty::LoadLineInstance(MKIniLine *arg0) {
    s32 var_r31_300;

    var_r31_300 = 0;
    if ((arg0->LoadFloat("HurtRadius", &this->unk1C, 0) != 0) || (arg0->LoadBool("Enabled", &this->unk20, 0) != 0)) {
        var_r31_300 = 1;
    }
    return var_r31_300;
}
#endif

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void HurtProperty::InitInstance() {
    MKIniLine *var_r31_339;

    *(pInstanceMem.__vptr + this->unk8) = 0;
    var_r31_339 = this->unk18;
loop_2:
    if (var_r31_339 != NULL) {
        LoadLineInstance(var_r31_339);
        var_r31_339 = var_r31_339->unkC->GetNextLine(var_r31_339);
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void HurtProperty::Resolve(KDPropertySet *arg0) {
    s8 *temp_r0_373;

    if ((void **) this->unk14 == NULL) {
        temp_r0_373 = this->unk10;
        if (temp_r0_373 != NULL) {
            this->unk14 = property_cast<KDMatrixProperty *, KDProperty *>(arg0->Find(temp_r0_373));
        }
    }
}
#endif

#if 0 // DRAFT: identifier 'HurtProperty::LoadLine(MKIniLine *)' redeclared
u8 HurtProperty::LoadLine(MKIniLine *arg0) {
    if ((MKIniLine *) this->unk18 == NULL) {
        this->unk18 = arg0;
    }
    return (u8) (arg0->LoadString("origin", &this->unk10, 0) != 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[13]' to
HurtProperty::HurtProperty() {
    this->unk4 = 0;
    this->unkC = NULL;
    this->unk8 = 0;
    this->unk18 = NULL;
    this->unk10 = "localToWorld";
    this->unk14 = NULL;
    this->unk1C = 0.0f;
    this->unk20 = 0;
    return this;
}
#endif

#if 0 // DRAFT: identifier 'property_cast<...>(T1)' redeclared
void **property_cast<KDMatrixProperty *, KDProperty *>(KDProperty *arg0) {
    KDMatrixProperty *sp8;

    sp8 = NULL;
    property_cast_ptr<KDMatrixProperty, KDProperty>(sp8, arg0);
    return &sp8->__vptr;
}
#endif

#if 0 // DRAFT: identifier 'property_cast_ptr<...>(T0 *&, T1 *)' redeclared
void property_cast_ptr<KDMatrixProperty, KDProperty>(KDMatrixProperty *&arg0, KDProperty *arg1) {
    if ((arg1 != NULL) && (arg1->IsOfType((KDPropertyClassInfo *) &classInfo) != 0)) {
        &arg0 = checked_cast<KDMatrixProperty *, KDProperty>(arg1);
    }
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<KDMatrixProperty *, KDProperty>(KDProperty *arg0) {

}
#endif
