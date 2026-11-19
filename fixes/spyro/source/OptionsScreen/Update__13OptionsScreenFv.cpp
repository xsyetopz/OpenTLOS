#include "spyro/source/KDStateMachine.h"
class CutsceneSystem;
void OptionsScreen::Update() {
    UIMessage msg;
    UIButton *temp_r3_91;
    UIButton *temp_r3_118;
    KDSynkerPlayer3 *temp_r3_146;
    UIObject *temp_r3_177;
    UIObject *temp_r3_195;
    UIObject *temp_r3_214;
    s32 var_r4_181;
    s32 var_r5_199;
    u8 var_r28_142;
    u8 var_r30_144;
    void **temp_r4_174;
    void *temp_r29_145;

    UIScreen::Update();
    temp_r3_91 = ui_cast<UIButton *, UIObject *>(this->unkD0->FindChild("SoundVolume"));
    if ((temp_r3_91 != NULL) && ((u8) M2C_FIELD(temp_r3_91, u8 *, 0x16) != 0) && ((UIControls_DirectionPressed((FrontEndControls) 7, -1) != 0) || (UIControls_DirectionPressed((FrontEndControls) 5, -1) != 0))) {
        KDSound_Play(GS_MenuSelect, 0U, -1);
    }
    temp_r3_118 = ui_cast<UIButton *, UIObject *>(this->unkD0->FindChild("MusicVolume"));
    if (temp_r3_118 != NULL) {
        if (((u8) M2C_FIELD(temp_r3_118, u8 *, 0x16) != 0) && (KDSound_IsMusicPaused() != 0)) {
            KDSound_PauseMusic(0U, 0U);
        } else if (((u8) M2C_FIELD(temp_r3_118, u8 *, 0x16) == 0) && (KDSound_IsMusicPaused() == 0) && ((u8) this->unkC8 == 0)) {
            var_r28_142 = 1;
            var_r30_144 = 0;
            temp_r29_145 = M2C_FIELD(&gb, void **, 0xC);
            temp_r3_146 = M2C_FIELD(temp_r29_145, KDSynkerPlayer3 **, 0x78);
            if (((temp_r3_146 != NULL) && (temp_r3_146->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r29_145, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r29_145) + 0x24))->GetState() == 2))) {
                var_r30_144 = 1;
            }
            if ((var_r30_144 == 0) && (KDSound_IsChronoSoundWarpActive() == 0)) {
                var_r28_142 = 0;
            }
            KDSound_PauseMusic(1U, var_r28_142);
        }
    }
    temp_r4_174 = this->unkD4;
    if (temp_r4_174 != NULL) {
        temp_r3_177 = (UIObject *) this->unkDC;
        if (temp_r3_177 != NULL) {
            var_r4_181 = 3;
            if ((u8) M2C_FIELD(temp_r4_174, u8 *, 0x16) == 0) {
                var_r4_181 = 2;
            }
            msg.unk0 = var_r4_181;
            msg.unk4 = 0;
            temp_r3_177->Message(&msg);
        }
        temp_r3_195 = (UIObject *) this->unkE0;
        if (temp_r3_195 != NULL) {
            var_r5_199 = 3;
            if ((u8) M2C_FIELD(this->unkD4, u8 *, 0x16) != 0) {
                var_r5_199 = 2;
            }
            msg.unk0 = var_r5_199;
            msg.unk4 = 0;
            temp_r3_195->Message(&msg);
        }
        temp_r3_214 = (UIObject *) this->unkD8;
        if (temp_r3_214 != NULL) {
            msg.unk0 = 1;
            msg.unk4 = 0;
            temp_r3_214->Message(&msg);
        }
    }
}
