#include "spyro/source/HurtProperty.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'spB0'
void HurtProperty::DoHurt() {
    s8 sp111;
    s8 sp110;
    s32 sp10C;
    f32 sp108;
    s32 sp104;
    s8 sp102;
    s8 sp101;
    s8 sp100;
    f64 spF8;                                       /* compiler-managed */
    f64 spF0;                                       /* compiler-managed */
    u32 spEC;
    s32 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    s32 spC4;
    s32 spC0;
    M2C_UNK sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    TargetManager ***var_r31_109;
    TargetManager **temp_r3_157;
    f32 temp_f2_130;
    f64 temp_f0_125;
    f64 temp_f1_119;
    void **temp_r3_46;
    void *temp_r3_115;
    void *temp_r4_118;

    temp_r3_46 = this->unk14;
    M2C_FIELD(*temp_r3_46, M2C_UNK (**)(void **, M2C_UNK *), 0x58)(temp_r3_46, &sp80);
    sp18 = 0.0f;
    sp10 = 0.0f;
    sp14 = 0.0f;
    sp70 = spB0;
    sp78 = spB8;
    spC4 = 0;
    sp60 = (f64) sp10;
    sp68 = (f64) sp18;
    spC0 = 7;
    spE8 = 1;
    spEC = *KDProperty::pInstanceMem;
    spC8 = (f64) sp10;
    spD0 = (f64) sp18;
    sp100 = 0;
    sp10C = 2;
    sp108 = 10.0f;
    sp101 = 0;
    sp102 = 1;
    sp104 = -1;
    spD8 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    spE0 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    sp110 = 0;
    if ((u32) *KDProperty::pInstanceMem != 0U) {
        ((MKProp *) &sp30)->GetPos();
        spF0 = sp30;
        spF8 = sp38;
    } else {
        spF0 = 0.0f;
        (*(f32 *) ((u8 *) &spEC + 0x8)) = 0.0f;
        spF8 = 0.0f;
    }
    sp111 = 0;
    var_r31_109 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
loop_8:
    if (var_r31_109 != NULL) {
        temp_r3_157 = *var_r31_109;
        if (temp_r3_157 != NULL) {
            temp_r3_115 = (*temp_r3_157)->unk8.unk0();
            if (temp_r3_115 != NULL) {
                temp_r4_118 = M2C_FIELD(temp_r3_115, void **, 8);
                temp_f1_119 = M2C_FIELD(temp_r4_118, f64 *, 0x30);
                sp40 = temp_f1_119;
                sp48 = M2C_FIELD(temp_r4_118, f64 *, 0x38);
                temp_f0_125 = temp_f1_119 - sp70;
                sp20 = temp_f0_125;
                temp_f2_130 = this->unk1C;
                sp50 = temp_f0_125;
                sp28 = (f32) sp48 - (f32) sp78;
                sp58 = (f64) sp28;
                if ((((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + ((*(f32 *) ((u8 *) &sp50 + 0x4)) * (*(f32 *) ((u8 *) &sp50 + 0x4))))) <= (temp_f2_130 * temp_f2_130)) {
                    M2C_FIELD(M2C_FIELD(temp_r3_115, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&spC0);
                }
            }
            var_r31_109 += 4;
            goto loop_8;
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void HurtProperty::Command(int arg0) {
    switch (arg0) {                                 /* irregular */
    case 1:
        *(*KDProperty::pInstanceMem + this->unk8) = 1;
        DoHurt();
        return;
    case 2:
        *(*KDProperty::pInstanceMem + this->unk8) = 0;
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

#if 0 // DRAFT: pointer/array required
void HurtProperty::Update() {
    if ((u8) *(*KDProperty::pInstanceMem + this->unk8) != 0) {
        DoHurt();
    }
}
#endif

void HurtProperty::ResolveInstance() {

}

#if 0 // DRAFT: pointer/array required
void HurtProperty::LoadDoneInstance() {
    *(*KDProperty::pInstanceMem + this->unk8) = this->unk20;
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

#if 0 // DRAFT: pointer/array required
void HurtProperty::InitInstance() {
    MKIniLine *var_r31_339;

    *(*KDProperty::pInstanceMem + this->unk8) = 0;
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

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 HurtProperty::LoadLine(MKIniLine *arg0) {
    if ((MKIniLine *) this->unk18 == NULL) {
        this->unk18 = arg0;
    }
    return (u8) (arg0->LoadString("origin", &this->unk10, 0) != 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[13]' to
HurtProperty::HurtProperty() {
    this->unk4 = NULL;
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
