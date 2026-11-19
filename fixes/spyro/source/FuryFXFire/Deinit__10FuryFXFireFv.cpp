#include "spyro/source/TimeDeltaModifier.h"

void FuryFXFire::Deinit() {
    Corona *temp_r4_396;
    MKMaterial *temp_r3_417;
    ManagedLight *temp_r4_382;
    s32 var_r29_368;
    s32 var_r31_369;
    u8 *temp_r30_371;

    var_r29_368 = 0;
    var_r31_369 = 0;
    do {
        temp_r30_371 = (u8 *) this + var_r31_369;
        KDSound_Stop((int *) (temp_r30_371 + 0x134));
        KDSound_Stop((int *) (temp_r30_371 + 0x15C));
        var_r29_368 += 1;
        var_r31_369 += 0x80;
    } while (var_r29_368 < 3);
    MKMaterial_Destroy(this->unkE0);
    temp_r4_382 = this->unkE8;
    if (temp_r4_382 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_382, 0U);
        ((LightManager *) gb.unk80)->FreeManagedLight(this->unkE8);
        this->unkE8 = NULL;
    }
    temp_r4_396 = this->unkF4;
    if (temp_r4_396 != NULL) {
        ((Coronas *) gb.unk64)->Free(temp_r4_396);
        this->unkF4 = NULL;
    }
    MKModel_Destroy(this->unkEC);
    MKModel_Destroy(this->unkF0);
    M2C_FIELD(&gb, TimeDeltaModifier *, 0x2CC).Disable(this->unk2E8);
    this->unk2E8 = -1;
    temp_r3_417 = this->unkE4;
    if (temp_r3_417 != NULL) {
        MKMaterial_Destroy(temp_r3_417);
    }
    ((FuryFX *) this)->FuryFX::Deinit();
}
