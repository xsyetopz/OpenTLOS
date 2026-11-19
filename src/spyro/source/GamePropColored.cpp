#include "spyro/source/GamePropColored.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

void GamePropColored::Draw() {
    f64 sp10;
    f64 sp8;
    MKMaterial *temp_r3_19;
    f64 *temp_r3_22;
    void *temp_r3_17;

    temp_r3_17 = checked_cast<GamePropColoredDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r3_19 = M2C_FIELD(temp_r3_17, MKMaterial **, 0xE4);
    if (temp_r3_19 != NULL) {
        temp_r3_22 = MKMaterial_GetColor(temp_r3_19);
        sp8 = M2C_FIELD(temp_r3_22, f64 *, 0);
        sp10 = M2C_FIELD(temp_r3_22, f64 *, 8);
        MKMaterial_SetColor(M2C_FIELD(temp_r3_17, MKMaterial **, 0xE4), this->unkC8);
        GameProp::Draw();
        MKMaterial_SetColor(M2C_FIELD(temp_r3_17, MKMaterial **, 0xE4), *((MKVector4 *) &sp8));
        return;
    }
    GameProp::Draw();
}

s32 GamePropColored::LoadLine(MKIniLine *arg0) {
    s32 var_r31_56;

    var_r31_56 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadVector4("MaterialColor", &this->unkC8, 0) != 0)) {
        var_r31_56 = 1;
    }
    return var_r31_56;
}

void GamePropColored::Init() {
    GameProp::Init();
    this->unkC8.unk0 = 1.0f;
    this->unkC8.unk4 = 1.0f;
    this->unkC8.unk8 = 1.0f;
    this->unkC8.unkC = 1.0f;
}

#if 0 // DRAFT: undefined identifier 'unkE4'
void GamePropColoredDescriptor::Deinit() {
    MKMaterial *temp_r3_108;

    temp_r3_108 = this->unkE4;
    if (temp_r3_108 != NULL) {
        MKMaterial_Destroy(temp_r3_108);
    }
    KDPropExDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 GamePropColoredDescriptor::LoadLine(MKIniLine *arg0) {
    s8 *sp8;

    if (GamePropDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->LoadString("ColoredMaterial", &sp8, 0) != 0) {
        this->unkE4 = MKMaterial_Create(sp8);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkE4'
void GamePropColoredDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unkE4 = NULL;
}
#endif
