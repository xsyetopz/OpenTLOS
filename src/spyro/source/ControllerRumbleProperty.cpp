#include "spyro/source/ControllerRumbleProperty.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDProperty.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern void **gb;

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void ControllerRumbleProperty::DoRumble() {
    void **temp_r3_49;
    void *temp_r31_45;
    void *temp_r31_60;
    temp_r31_45 = *KDProperty::pInstanceMem + this->unk8;
    if ((u8) M2C_FIELD(temp_r31_45, u8 *, 0x10) != 0) {
        temp_r3_49 = this->unk14;
        M2C_FIELD(*temp_r3_49, M2C_UNK (**)(void **, M2C_UNK *), 0x58)(temp_r3_49, &arg_sp10);
        temp_r31_60 = *KDProperty::pInstanceMem + this->unk8;
        ((KDInput *) (M2C_FIELD(*gb, KDInput *(**)(void **, s32), 0x40)(gb, *KDProperty::pInstanceMem)))->RumblePlay3D(M2C_FIELD(temp_r31_60, f32 *, 0), M2C_FIELD(temp_r31_60, f32 *, 4), M2C_FIELD(temp_r31_60, f32 *, 8), (MKVector3 *) &arg_sp40, M2C_FIELD(temp_r31_60, f32 *, 0xC), 0, 4.0f, 0U);
        return;
    }
    ((KDInput *) (M2C_FIELD(*gb, KDInput *(**)(void **), 0x40)(gb)))->RumblePlay(M2C_FIELD(temp_r31_45, f32 *, 0), M2C_FIELD(temp_r31_45, f32 *, 4), M2C_FIELD(temp_r31_45, f32 *, 8), 0, 4.0f, 0U);
}
#endif

void ControllerRumbleProperty::Command(int arg0) {
    if (arg0 != 1) {
        return;
    }
    DoRumble();
}

#if 0 // DRAFT: function call 'stricmp(const char *, const char[6])' does not match
s32 ControllerRumbleProperty::ResolveCommand(const char *arg0) const {
    return stricmp(arg0, "Burst") == 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
s32 ControllerRumbleProperty::LoadLineInstance(MKIniLine *arg0) {
    s32 var_r31_148;

    var_r31_148 = 0;
    if ((arg0->LoadFloat("LargeAct", *KDProperty::pInstanceMem + this->unk8, 0) != 0) || (arg0->LoadFloat("SmallAct", *KDProperty::pInstanceMem + (this->unk8 + 4), 0) != 0) || (arg0->LoadFloat("Duration", *KDProperty::pInstanceMem + (this->unk8 + 8), 0) != 0) || (arg0->LoadFloat("DropOffDistance", *KDProperty::pInstanceMem + (this->unk8 + 0xC), 0) != 0) || (arg0->LoadBool("CameraSensitive", *KDProperty::pInstanceMem + (this->unk8 + 0x10), 0) != 0)) {
        var_r31_148 = 1;
    }
    return var_r31_148;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void ControllerRumbleProperty::InitInstance() {
    MKIniLine *var_r31_235;
    void *temp_r3_229;

    temp_r3_229 = *KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(temp_r3_229, f32 *, 0) = 0.5f;
    M2C_FIELD(temp_r3_229, f32 *, 4) = 0.5f;
    M2C_FIELD(temp_r3_229, f32 *, 8) = 0.5f;
    M2C_FIELD(temp_r3_229, s8 *, 0x10) = 1;
    M2C_FIELD(temp_r3_229, f32 *, 0xC) = 37.0f;
    var_r31_235 = this->unk18;
loop_2:
    if (var_r31_235 != NULL) {
        LoadLineInstance(var_r31_235);
        var_r31_235 = var_r31_235->unkC->GetNextLine(var_r31_235);
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void ControllerRumbleProperty::Resolve(KDPropertySet *arg0) {
    s8 *temp_r0_269;

    if ((void **) this->unk14 == NULL) {
        temp_r0_269 = this->unk10;
        if (temp_r0_269 != NULL) {
            this->unk14 = property_cast<KDMatrixProperty *, KDProperty *>(arg0->Find(temp_r0_269));
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 ControllerRumbleProperty::LoadLine(MKIniLine *arg0) {
    if ((MKIniLine *) this->unk18 == NULL) {
        this->unk18 = arg0;
    }
    return (u8) (arg0->LoadString("origin", &this->unk10, 0) != 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[13]' to
ControllerRumbleProperty::ControllerRumbleProperty() {
    this->unk4 = 0;
    this->unkC = NULL;
    this->unk8 = 0;
    this->unk18 = NULL;
    this->unk10 = "localToWorld";
    this->unk14 = NULL;
    return this;
}
#endif
