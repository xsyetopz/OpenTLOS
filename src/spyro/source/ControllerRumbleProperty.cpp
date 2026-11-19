#include "spyro/source/ControllerRumbleProperty.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProperty.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern void **gb;

void ControllerRumbleProperty::DoRumble() {
    MKVector3 sp40;
    M2C_UNK sp10;
    void **temp_r3_49;
    void *temp_r31_45;
    void *temp_r31_60;

    temp_r31_45 = (void *) (*KDProperty::pInstanceMem + this->unk8);
    if ((u8) M2C_FIELD(temp_r31_45, u8 *, 0x10) != 0) {
        temp_r3_49 = this->unk14;
        M2C_FIELD(*temp_r3_49, M2C_UNK (**)(void **, M2C_UNK *), 0x58)(temp_r3_49, &sp10);
        temp_r31_60 = (void *) (*KDProperty::pInstanceMem + this->unk8);
        ((KDInput *) (M2C_FIELD(*gb, KDInput *(**)(void **, s32), 0x40)(gb, *KDProperty::pInstanceMem)))->RumblePlay3D(M2C_FIELD(temp_r31_60, f32 *, 0), M2C_FIELD(temp_r31_60, f32 *, 4), M2C_FIELD(temp_r31_60, f32 *, 8), &sp40, M2C_FIELD(temp_r31_60, f32 *, 0xC), 0, 4.0f, 0U);
        return;
    }
    ((KDInput *) (M2C_FIELD(*gb, KDInput *(**)(void **), 0x40)(gb)))->RumblePlay(M2C_FIELD(temp_r31_45, f32 *, 0), M2C_FIELD(temp_r31_45, f32 *, 4), M2C_FIELD(temp_r31_45, f32 *, 8), 0, 4.0f, 0U);
}

void ControllerRumbleProperty::Command(int arg0) {
    if (arg0 != 1) {
        return;
    }
    DoRumble();
}

s32 ControllerRumbleProperty::ResolveCommand(const char *arg0) const {
    return stricmp((s8 *) arg0, (M2C_UNK *) "Burst") == 0;
}

s32 ControllerRumbleProperty::LoadLineInstance(MKIniLine *arg0) {
    s32 result;

    result = 0;
    if (((u8) arg0->LoadFloat("LargeAct", (f32 *) (*(u8 **) KDProperty::pInstanceMem + this->unk8), 0) != 0) || ((u8) arg0->LoadFloat("SmallAct", (f32 *) (*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 4)), 0) != 0) || ((u8) arg0->LoadFloat("Duration", (f32 *) (*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 8)), 0) != 0) || ((u8) arg0->LoadFloat("DropOffDistance", (f32 *) (*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 0xC)), 0) != 0) || ((u8) arg0->LoadBool("CameraSensitive", (bool *) (*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 0x10)), 0) != 0)) {
        result = 1;
    }
    return result;
}

void ControllerRumbleProperty::InitInstance() {
    MKIniLine *var_r31_235;
    void *temp_r3_229;

    temp_r3_229 = (void *) (*KDProperty::pInstanceMem + this->unk8);
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

void ControllerRumbleProperty::Resolve(KDPropertySet *arg0) {
    s8 *temp_r0_269;

    if (this->unk14 == NULL) {
        temp_r0_269 = this->unk10;
        if (temp_r0_269 != NULL) {
            this->unk14 = (void **) (property_cast<KDMatrixProperty *, KDProperty *>((KDProperty *) arg0->Find((const char *) temp_r0_269)));
        }
    }
}

s32 ControllerRumbleProperty::LoadLine(MKIniLine *arg0) {
    if (this->unk18 == NULL) {
        this->unk18 = arg0;
    }
    return (u8) arg0->LoadString("origin", (const char **) &this->unk10, 0) != 0;
}

ControllerRumbleProperty::ControllerRumbleProperty() {
    this->unk4 = NULL;
    this->unkC = NULL;
    this->unk8 = 0;
    this->unk18 = NULL;
    this->unk10 = (signed char *) ("localToWorld");
    this->unk14 = NULL;
}
