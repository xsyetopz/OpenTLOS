#include "spyro/source/KDStateMachine.h"
class CutsceneSystem;
void OptionsScreen::OnEnter() {
    UIMessage msg;
    UIContainer *temp_r3_263;
    UIButton *temp_r3_270;
    UIButtonGroup *temp_r3_314;
    UIObject *temp_r3_356;
    UIObject *temp_r3_369;
    UIObject *temp_r3_382;
    void *temp_r3_gb;
    u8 var_r30_279;

    UIScreen::OnEnter();
    if (KDSound_IsMusicPaused() != 0) {
        this->unkC8 = 0;
    } else {
        this->unkC8 = 1;
    }
    msg.unk0 = 1;
    msg.unk4 = 0;
    Message(&msg);
    temp_r3_263 = this->unkD0;
    if (temp_r3_263 != NULL) {
        temp_r3_270 = ui_cast<UIButton *, UIObject *>(temp_r3_263->FindChild("Sound"));
        if (temp_r3_270 != NULL) {
            temp_r3_gb = M2C_FIELD(&gb, void **, 0xC);
            if (temp_r3_gb != NULL) {
                var_r30_279 = 0;
                if ((((u32) M2C_FIELD(temp_r3_gb, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(temp_r3_gb, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r3_gb) + 0x24))->GetState() != 0)) {
                    var_r30_279 = 1;
                }
                if (var_r30_279 != 0) {
                    msg.unk0 = 5;
                    msg.unk4 = 0;
                    temp_r3_270->Message(&msg);
                    msg.unk0 = 3;
                    msg.unk4 = 0;
                    temp_r3_270->Message(&msg);
                    temp_r3_314 = (UIButtonGroup *) this->unkD0;
                    if (temp_r3_314->unk68 == 0) {
                        temp_r3_314->SetSelection(1);
                        msg.unk0 = 1;
                        msg.unk4 = 0;
                        this->unkD0->Message(&msg);
                    }
                } else {
                    goto block_13;
                }
            } else {
block_13:
                msg.unk0 = 4;
                msg.unk4 = 0;
                temp_r3_270->Message(&msg);
                msg.unk0 = 2;
                msg.unk4 = 0;
                temp_r3_270->Message(&msg);
            }
        }
    }
    temp_r3_356 = (UIObject *) this->unkDC;
    if (temp_r3_356 != NULL) {
        msg.unk0 = 2;
        msg.unk4 = 0;
        temp_r3_356->Message(&msg);
    }
    temp_r3_369 = (UIObject *) this->unkE0;
    if (temp_r3_369 != NULL) {
        msg.unk0 = 3;
        msg.unk4 = 0;
        temp_r3_369->Message(&msg);
    }
    temp_r3_382 = (UIObject *) this->unkD8;
    if (temp_r3_382 != NULL) {
        msg.unk0 = 1;
        msg.unk4 = 0;
        temp_r3_382->Message(&msg);
    }
}
