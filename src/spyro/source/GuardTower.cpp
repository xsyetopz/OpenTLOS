#include "spyro/source/GuardTower.h"
#include "common/Source/MKProp.h"
#include "spyro/source/GuardTowerDescriptor.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/LavaSmashProp.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern void **gb;

void GuardTower::Update() {
    f32 temp_f1_62;
    f32 temp_f1_69;
    f32 temp_f31_97;
    void *temp_r3_50;

    LavaSmashProp::Update();
    temp_r3_50 = checked_cast<GuardTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (((s32) this->unk17C == 2) && (M2C_FIELD(temp_r3_50, f32 *, 0x16C) != 0.0f) && (this->unk1F8 > M2C_FIELD(temp_r3_50, f32 *, 0x174))) {
        temp_f1_62 = this->unk208;
        if ((temp_f1_62 < 8.0f) && (((this->unk208 = temp_f1_62 + gUpdateTimeDelta, temp_f1_69 = this->unk208, ((temp_f1_69 >= 0.0f) != 0)) && (temp_f1_69 <= 1.0f)) || ((temp_f1_69 >= 2.0f) && (temp_f1_69 <= 3.0f)) || ((temp_f1_69 >= 4.0f) && (temp_f1_69 <= 8.0f)))) {
            temp_f31_97 = this->unk200;
            ((KDInput *) (M2C_FIELD(*gb, KDInput *(**)(void **), 0x40)(gb)))->RumblePlay(0.01f * temp_f31_97, 0.1f * temp_f31_97, 0.033f, 0, 4.0f, 0U);
        }
    }
}

void GuardTower::Init() {
    LavaSmashProp::Init();
    this->unk208 = 0.0f;
}
