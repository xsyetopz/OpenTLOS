#include "spyro/source/TimeDeltaModifier.h"
void FuryFXEarth::Deinit() {
    Corona *temp_r4_711;
    ManagedLight *temp_r4_728;

    temp_r4_711 = this->unk164;
    if (temp_r4_711 != NULL) {
        ((Coronas *) gb.unk64)->Free(temp_r4_711);
        this->unk164 = NULL;
    }
    ((TimeDeltaModifier *) ((s8 *) &gb + 0x2CC))->Disable(this->unk1C4);
    this->unk1C4 = -1;
    temp_r4_728 = this->unk1CC;
    if (temp_r4_728 != NULL) {
        ((LightManager *) gb.unk80)->FreeManagedLight(temp_r4_728);
    }
    FuryFX::Deinit();
}
