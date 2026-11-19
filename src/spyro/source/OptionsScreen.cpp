#include "spyro/source/OptionsScreen.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerCamera.h"
#include "spyro/source/KDSynkerPlayerEvents.h"
#include "spyro/source/KDSynkerPlayerSounds.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIButton.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/gc/Sound_GC.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

extern s32 GS_MenuSelect;
extern M2C_UNK gb;

#include "spyro/source/KDStateMachine.h"
class CutsceneSystem;
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

#include "spyro/source/KDStateMachine.h"
class CutsceneSystem;
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

void OptionsScreen::Resolve() {
    UIMessage msg;
    UIContainer *temp_r3_418;
    UIObject *temp_r3_457;
    UIObject *var_r3_479;
    void **temp_r3_435;

    UIScreen::Resolve();
    this->unkD0 = ui_cast<UIButtonGroup *, UIObject *>(FindChild("OptionsButtons"));
    temp_r3_418 = this->unkD0;
    if (temp_r3_418 != NULL) {
        this->unkD4 = (void **) (ui_cast<UIButton *, UIObject *>(temp_r3_418->FindChild("Position")));
    }
    this->unkD8 = (void **) (ui_cast<UIContainer *, UIObject *>(FindChild("PromptGroup")));
    temp_r3_435 = this->unkD8;
    if (temp_r3_435 != NULL) {
        this->unkDC = (void **) (((UIContainer *) temp_r3_435)->FindChild("LeftRight"));
        this->unkE0 = (void **) (((UIContainer *) this->unkD8)->FindChild("Forward"));
    }
    if (Sound_GetSystemAudioMode() == 0) {
        temp_r3_457 = this->unkD0->FindChild("Output");
        if (temp_r3_457 != NULL) {
            msg.unk0 = 5;
            msg.unk4 = 0;
            temp_r3_457->Message(&msg);
            msg.unk0 = 3;
            msg.unk4 = 0;
            temp_r3_457->Message(&msg);
            var_r3_479 = temp_r3_457->unk10;
loop_8:
            if (var_r3_479 != NULL) {
                var_r3_479->unk18.unk10.unk4 -= 40.0f;
                var_r3_479 = var_r3_479->unk10;
                goto loop_8;
            }
        }
    }
}

void OptionsScreen::Init() {
    UIContainer::Init();
    this->unkC8 = 0;
    this->unkCC = 0;
    this->unkD0 = NULL;
    this->unkD4 = NULL;
    this->unkD8 = NULL;
    this->unkDC = NULL;
    this->unkE0 = NULL;
}
