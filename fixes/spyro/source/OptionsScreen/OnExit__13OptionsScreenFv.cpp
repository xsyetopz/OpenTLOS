#include "spyro/source/KDStateMachine.h"
class CutsceneSystem;
void OptionsScreen::OnExit() {
    KDSynkerPlayer3 *temp_r3_49;
    u8 var_r31_46;
    void *temp_r30_48;

    UIScreen::OnExit();
    if (KDSound_IsVoicePlaying(this->unkCC) != 0) {
        KDSound_Stop((int *) &this->unkCC);
    }
    if ((u8) this->unkC8 != 0) {
        KDSound_PauseMusic(0U, 0U);
        return;
    }
    var_r31_46 = 0;
    temp_r30_48 = M2C_FIELD(&gb, void **, 0xC);
    temp_r3_49 = M2C_FIELD(temp_r30_48, KDSynkerPlayer3 **, 0x78);
    if (((temp_r3_49 != NULL) && (temp_r3_49->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r30_48, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r30_48) + 0x24))->GetState() == 2))) {
        var_r31_46 = 1;
    }
    KDSound_PauseMusic(1U, var_r31_46);
}
