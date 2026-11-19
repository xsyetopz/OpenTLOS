#include "spyro/source/MemoryCard.h"
#include "common/Source/Font.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AutosaveWarningScreen.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/KDMemoryCard.h"
#include "spyro/source/Level.h"
#include "spyro/source/LoadLevel.h"
#include "spyro/source/MCActionScreen.h"
#include "spyro/source/MCFileInfo.h"
#include "spyro/source/MCLoadCheckScreen.h"
#include "spyro/source/MCQueryScreen.h"
#include "spyro/source/MCSelectCardScreen.h"
#include "spyro/source/MCSelectFileScreen.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UISystem.h"
#include "spyro/source/UIText.h"
#include "unplaced_templates.h"
#include "common/Source/system_extras.h"
#include "spyro/source/Autosave.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/PauseMenu.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

extern GameStateMachine gGMState;
extern void *gpTranslation_StringArray;
u8 descriptor__12MCSaveScreen[0x14];                /* unable to generate initializer: cannot parse .L_8035CDF0 as integer */
u8 descriptor__6MCText[0x14];                       /* unable to generate initializer: cannot parse .L_8035CDFD as integer */
static s32 memCardSlotSizes;
static s8 gameNameBuffer[0x20];
#if 0 // DRAFT: illegal implicit conversion from 'const char[16]' to
static s8 *pDirectoryName = "BASLUS-21372s06";
#endif
u8 operation__16MemoryCardScreen[4] = { 0xFF, 0xFF, 0xFF, 0xFF };

#if 0 // DRAFT: illegal type
void MCText::Draw(const RenderContext &arg0) {
    s8 spF0;
    RenderContext spA0;
    Matrix sp60;
    f64 sp58;
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f3_134;
    s32 temp_r3_93;
    s32 temp_r4_123;
    s32 temp_r4_72;

    sp58 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp50 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    (*(f32 *) ((u8 *) &sp58 + 0x4)) = 1.0f;
    if (((s32) this->unk6C >= 0) && ((MKFont *) this->unk64 != NULL) && !(this->unk18.unk34 <= 0.0f)) {
        if (this->unk18.unk38 <= 0.0f) {
            return;
        }
        spA0.RenderContext();
        spA0.AddState(arg0, this->unk18);
        temp_r4_72 = this->unk18.unk3C;
        if (!(temp_r4_72 & 3)) {
            sp50 = this->unk18.unk34 * 0.5f;
        } else if (temp_r4_72 & 1) {
            sp50 = 0.0f;
        } else {
            sp50 = this->unk18.unk34 / -2.0f;
        }
        temp_r3_93 = this->unk18.unk3C;
        if (!(temp_r3_93 & 0xC)) {
            (*(f32 *) ((u8 *) &sp48 + 0xc)) = this->unk18.unk38 * 0.5f;
        } else if (temp_r3_93 & 4) {
            (*(f32 *) ((u8 *) &sp48 + 0xc)) = 0.0f;
        } else {
            (*(f32 *) ((u8 *) &sp48 + 0xc)) = this->unk18.unk38 / -2.0f;
        }
        sp60.SetIdentity();
        sp60.Translate(&sp60, *((MKVector3 *) &sp50));
        ((Matrix *) &spA0)->Multiply(&sp60, (Matrix *) &spA0);
        temp_r4_123 = this->unk6C;
        if ((temp_r4_123 >= 0) && ((u32) *(gpTranslation_StringArray + (temp_r4_123 * 4)) != 0U)) {
            MemoryCard_String(&spF0, temp_r4_123);
            temp_f3_134 = this->unk70;
            if ((temp_f3_134 != 0.0f) || (this->unk74 != 0.0f)) {
                sp28 = spA0.unk38;
                sp20 = spA0.unk30 + temp_f3_134;
                sp24 = spA0.unk34 + this->unk74;
                sp48 = (f64) sp28;
                sp40 = (f64) sp20;
                spA0.unk30 = (f32) sp40;
                spA0.unk34 = (*(f32 *) ((u8 *) &sp40 + 0x4));
                spA0.unk38 = (f32) sp48;
                spA0.unk3C = 1.0f;
                this->unk64->DrawString(&spF0, this->unk18.unk34, this->unk18.unk38, (Matrix *) &spA0, this->unk18.unk3C, 0x80000000U, 1.0f, 1.0f, NULL, 1U);
                sp18 = spA0.unk38;
                sp10 = spA0.unk30 - this->unk70;
                sp14 = spA0.unk34 - this->unk74;
                sp38 = (f64) sp18;
                sp30 = (f64) sp10;
                spA0.unk30 = (f32) sp30;
                spA0.unk34 = (*(f32 *) ((u8 *) &sp30 + 0x4));
                spA0.unk38 = (f32) sp38;
                spA0.unk3C = 1.0f;
            }
            this->unk64->DrawString(&spF0, this->unk18.unk34, this->unk18.unk38, (Matrix *) &spA0, this->unk18.unk3C, (u32) (128.0f * (f32) spA0.unk40) | (((u32) (128.0f * (*(f32 *) ((u8 *) &spA0 + 0x44))) << 8) | (((u32) (128.0f * (*(f32 *) ((u8 *) &spA0 + 0x4c))) << 0x18) | ((u32) (128.0f * (f32) spA0.unk48) << 0x10))), 1.0f, 1.0f, NULL, 1U);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'P8UISystem'
void MemoryCardScreen::ExamineCard() {
    s32 temp_r30_344;
    s32 var_ctr_319;
    s32 var_r3_318;

    if ((u8) M2C_FIELD(*MemoryCardScreen::selectedCard, u8 *, 0xC) != 0) {
        *MCQueryScreen::query = 5;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    if ((u8) M2C_FIELD(*MemoryCardScreen::selectedCard, u8 *, 0xD) != 0) {
        *MCQueryScreen::query = 1;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    if ((u8) M2C_FIELD(*MemoryCardScreen::selectedCard, u8 *, 0xA) != 0) {
        *MCQueryScreen::query = 2;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    if ((u8) M2C_FIELD(*MemoryCardScreen::selectedCard, u8 *, 0xB) != 0) {
        *MCQueryScreen::query = 9;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    if ((s32) M2C_FIELD(*MemoryCardScreen::selectedCard, s32 *, 0x1C) == 0) {
        *MCQueryScreen::query = 8;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    if ((s32) M2C_FIELD(*MemoryCardScreen::selectedCard, s32 *, 0x20) == 0) {
        if ((s32) *MemoryCardScreen::operation == 0) {
            *MCQueryScreen::query = 7;
            ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
            return;
        }
        *MCActionScreen::action = 2;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    var_r3_318 = 0;
    var_ctr_319 = 3;
loop_15:
    if ((s8) *(*MemoryCardScreen::selectedCard + (var_r3_318 + 0xE5)) != 0) {
        *MCActionScreen::action = 5;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    var_r3_318 += 0xC0;
    var_ctr_319 -= 1;
    if (var_ctr_319 == 0) {
        if (((s32) *MemoryCardScreen::operation == 1) && ((s32) M2C_FIELD(*MemoryCardScreen::selectedCard, s32 *, 0x24) == 0) && ((temp_r30_344 = M2C_FIELD(*MemoryCardScreen::selectedCard, s32 *, 0x18), ((temp_r30_344 < MemoryCard_GetSaveGameBlockSize()) != 0)) || ((s32) M2C_FIELD(*MemoryCardScreen::selectedCard, s32 *, 0x14) < 1))) {
            *MCQueryScreen::query = 6;
            ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
            return;
        }
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    goto loop_15;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void MemoryCardScreen::OnExit() {
    s32 temp_r0_391;

    UIScreen::OnExit();
    temp_r0_391 = ui_cast<UISystem *, UIContainer *>(GetRoot())->unk68;
    if ((temp_r0_391 == 3) || (temp_r0_391 == 4)) {
        Autosave_EnableRemovalCheck(1U);
        if ((s32) *gGMState.GetCurrState() == 7) {
            PauseMenu_AllowStartToQuit(1U);
        }
    }
    FrontEnd_SetFade(0.0f);
}
#endif

#if 0 // DRAFT: function call 'UIStringTable_Remove(signed char *)' does not match
void MemoryCardScreen::OnEnter() {
    UIContainer *temp_r3_426;
    UIObject *var_r30_429;
    s8 *temp_r3_439;
    s8 *temp_r3_450;
    void *temp_r3_433;

    UIScreen::OnEnter();
    temp_r3_426 = this->unkC8;
    if (temp_r3_426 != NULL) {
        var_r30_429 = temp_r3_426->unk60;
loop_11:
        if (var_r30_429 == NULL) {

        } else {
            temp_r3_433 = ui_cast<UIText *, UIObject *>(var_r30_429);
            if (temp_r3_433 != NULL) {
                if ((s32) *MemoryCardScreen::operation == 1) {
                    temp_r3_439 = M2C_FIELD(temp_r3_433, s8 **, 0x68);
                    if (temp_r3_439 != NULL) {
                        UIStringTable_Remove(temp_r3_439);
                    }
                    M2C_FIELD(temp_r3_433, s8 **, 0x68) = NULL;
                    M2C_FIELD(temp_r3_433, s32 *, 0x6C) = 0x4C;
                    return;
                }
                temp_r3_450 = M2C_FIELD(temp_r3_433, s8 **, 0x68);
                if (temp_r3_450 != NULL) {
                    UIStringTable_Remove(temp_r3_450);
                }
                M2C_FIELD(temp_r3_433, s8 **, 0x68) = NULL;
                M2C_FIELD(temp_r3_433, s32 *, 0x6C) = 0x73;
                return;
            }
            var_r30_429 = var_r30_429->unk10;
            goto loop_11;
        }
    }
}
#endif

void MemoryCardScreen::Resolve() {
    UIScreen::Resolve();
    this->unkC8 = ui_cast<UIContainer *, UIObject *>(FindChild(""));
}

void MemoryCardScreen::Init() {
    UIContainer::Init();
    this->unkC8 = NULL;
}

#if 0 // DRAFT: undefined identifier 'P8UISystem'
void MCSaveScreen::Update() {
    UIContainer *temp_r3_534;
    s8 *temp_r3_560;
    s8 *temp_r3_584;
    s8 *temp_r3_607;
    void *var_r31_527;

    UIScreen::Update();
    if (KDMemoryCard::Update() == 0) {
        var_r31_527 = NULL;
        temp_r3_534 = ui_cast<UIContainer *, UIObject *>(((UIContainer *) (ui_cast<P8UISystem))->FindChild(P11UIContainer>__FP11UIContainer(GetRoot()), ""));
        if (temp_r3_534 != NULL) {
            var_r31_527 = ui_cast<UIText *, UIObject *>(temp_r3_534->FindChild(""));
        }
        *MemoryCardScreen::operation = -1;
        *MemoryCardScreen::bNewGame = 0;
        if (strnicmp((s8 *) this->unk4, "", 4) == 0) {
            *MemoryCardScreen::operation = 1;
            if (var_r31_527 != NULL) {
                temp_r3_560 = M2C_FIELD(var_r31_527, s8 **, 0x68);
                if (temp_r3_560 != NULL) {
                    UIStringTable_Remove(temp_r3_560);
                }
                M2C_FIELD(var_r31_527, s8 **, 0x68) = NULL;
                M2C_FIELD(var_r31_527, s32 *, 0x6C) = 0x83;
            }
        } else if (strnicmp((s8 *) this->unk4, "", 3) == 0) {
            *MemoryCardScreen::operation = 1;
            *MemoryCardScreen::bNewGame = 1;
            if (var_r31_527 != NULL) {
                temp_r3_584 = M2C_FIELD(var_r31_527, s8 **, 0x68);
                if (temp_r3_584 != NULL) {
                    UIStringTable_Remove(temp_r3_584);
                }
                M2C_FIELD(var_r31_527, s8 **, 0x68) = NULL;
                M2C_FIELD(var_r31_527, s32 *, 0x6C) = 0x82;
            }
        } else if (strnicmp((s8 *) this->unk4, "", 4) == 0) {
            *MemoryCardScreen::operation = 0;
            if (var_r31_527 != NULL) {
                temp_r3_607 = M2C_FIELD(var_r31_527, s8 **, 0x68);
                if (temp_r3_607 != NULL) {
                    UIStringTable_Remove(temp_r3_607);
                }
                M2C_FIELD(var_r31_527, s8 **, 0x68) = NULL;
                M2C_FIELD(var_r31_527, s32 *, 0x6C) = 0x81;
            }
        }
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void MCSaveScreen::OnEnter() {
    MemoryCardScreen::OnEnter();
    Autosave_EnableRemovalCheck(0U);
    if ((s32) *gGMState.GetCurrState() == 7) {
        PauseMenu_AllowStartToQuit(0U);
    }
}
#endif

s32 MemoryCard_GetSaveGameBlockSize() {
    return ((s32) (M2C_FIELD(&memCardSlotSizes, s32 *, 4) + MKMemoryCard_CalculateFileSize()) / 8192) + 1;
}

void MemoryCard_DeinitModule() {
    Autosave_DeinitModule();
}

#if 0 // DRAFT: undefined identifier 'MemoryCard_String'
void MemoryCard_InitModule() {
    MCLoadCheckScreen *temp_r3_725;
    MCLoadCheckScreen *temp_r3_743;
    MCLoadCheckScreen *temp_r3_761;
    MCLoadCheckScreen *temp_r3_779;
    MCLoadCheckScreen *temp_r3_797;
    MCLoadCheckScreen *temp_r3_815;
    MCLoadCheckScreen *temp_r3_833;
    MCLoadCheckScreen *temp_r3_851;
    UIObjectDescriptor *var_r4_717;
    UIObjectDescriptor *var_r4_735;
    UIObjectDescriptor *var_r4_753;
    UIObjectDescriptor *var_r4_771;
    UIObjectDescriptor *var_r4_789;
    UIObjectDescriptor *var_r4_807;
    UIObjectDescriptor *var_r4_825;
    UIObjectDescriptor *var_r4_843;
    s32 temp_r3_704;

    MemoryCard_String(gameNameBuffer, 3);
    M2C_FIELD(&memCardSlotSizes, s32 *, 0) = 3;
    temp_r3_704 = ((GameData *) GameData::gameData)->GetGameDataSize();
    M2C_FIELD(&memCardSlotSizes, s32 *, 0xC) = temp_r3_704;
    M2C_FIELD(&memCardSlotSizes, s32 *, 8) = temp_r3_704;
    M2C_FIELD(&memCardSlotSizes, s32 *, 4) = temp_r3_704;
    MKMemoryCard_SetAppInfo(pDirectoryName, gameNameBuffer, (int *) &memCardSlotSizes);
    KDMemoryCard::InitModule();
    Autosave_InitModule();
    var_r4_717 = &UIObjectDescriptor::list;
loop_3:
    temp_r3_725 = var_r4_717->unk0;
    if (temp_r3_725 == NULL) {
        var_r4_717->unk0 = (MCLoadCheckScreen *) MCSaveScreen::descriptor;
        M2C_FIELD(MCSaveScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_725 != MCSaveScreen::descriptor) {
        var_r4_717 = (UIObjectDescriptor *) &temp_r3_725->unk10;
        goto loop_3;
    }
    var_r4_735 = &UIObjectDescriptor::list;
loop_8:
    temp_r3_743 = var_r4_735->unk0;
    if (temp_r3_743 == NULL) {
        var_r4_735->unk0 = (MCLoadCheckScreen *) MCSelectCardScreen::descriptor;
        M2C_FIELD(MCSelectCardScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_743 != MCSelectCardScreen::descriptor) {
        var_r4_735 = (UIObjectDescriptor *) &temp_r3_743->unk10;
        goto loop_8;
    }
    var_r4_753 = &UIObjectDescriptor::list;
loop_13:
    temp_r3_761 = var_r4_753->unk0;
    if (temp_r3_761 == NULL) {
        var_r4_753->unk0 = (MCLoadCheckScreen *) MCSelectFileScreen::descriptor;
        M2C_FIELD(MCSelectFileScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_761 != MCSelectFileScreen::descriptor) {
        var_r4_753 = (UIObjectDescriptor *) &temp_r3_761->unk10;
        goto loop_13;
    }
    var_r4_771 = &UIObjectDescriptor::list;
loop_18:
    temp_r3_779 = var_r4_771->unk0;
    if (temp_r3_779 == NULL) {
        var_r4_771->unk0 = (MCLoadCheckScreen *) MCActionScreen::descriptor;
        M2C_FIELD(MCActionScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_779 != MCActionScreen::descriptor) {
        var_r4_771 = (UIObjectDescriptor *) &temp_r3_779->unk10;
        goto loop_18;
    }
    var_r4_789 = &UIObjectDescriptor::list;
loop_23:
    temp_r3_797 = var_r4_789->unk0;
    if (temp_r3_797 == NULL) {
        var_r4_789->unk0 = (MCLoadCheckScreen *) MCQueryScreen::descriptor;
        M2C_FIELD(MCQueryScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_797 != MCQueryScreen::descriptor) {
        var_r4_789 = (UIObjectDescriptor *) &temp_r3_797->unk10;
        goto loop_23;
    }
    var_r4_807 = &UIObjectDescriptor::list;
loop_28:
    temp_r3_815 = var_r4_807->unk0;
    if (temp_r3_815 == NULL) {
        var_r4_807->unk0 = (MCLoadCheckScreen *) MCText::descriptor;
        M2C_FIELD(MCText::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_815 != MCText::descriptor) {
        var_r4_807 = (UIObjectDescriptor *) &temp_r3_815->unk10;
        goto loop_28;
    }
    var_r4_825 = &UIObjectDescriptor::list;
loop_33:
    temp_r3_833 = var_r4_825->unk0;
    if (temp_r3_833 == NULL) {
        var_r4_825->unk0 = (MCLoadCheckScreen *) MCFileInfo::descriptor;
        M2C_FIELD(MCFileInfo::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_833 != MCFileInfo::descriptor) {
        var_r4_825 = (UIObjectDescriptor *) &temp_r3_833->unk10;
        goto loop_33;
    }
    var_r4_843 = &UIObjectDescriptor::list;
loop_38:
    temp_r3_851 = var_r4_843->unk0;
    if (temp_r3_851 == NULL) {
        var_r4_843->unk0 = (MCLoadCheckScreen *) AutosaveWarningScreen::descriptor;
        M2C_FIELD(AutosaveWarningScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_851 != AutosaveWarningScreen::descriptor) {
        var_r4_843 = (UIObjectDescriptor *) &temp_r3_851->unk10;
        goto loop_38;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'char *' to
s8 *MemoryCard_String(char *arg0, int arg1) {
    s32 temp_ret_1001;
    s32 var_r29_875;
    s8 *var_r30_876;
    u8 *var_r4_978;
    u8 *var_r5_942;
    u8 temp_r0_884;
    u8 temp_r0_901;
    u8 temp_r0_933;
    u8 temp_r3_956;
    u8 temp_r3_990;
    u8 temp_r4_1036;
    void *var_r31_878;

    var_r29_875 = 0;
    var_r30_876 = arg0;
    var_r31_878 = *(gpTranslation_StringArray + (arg1 * 4));
loop_42:
    temp_r4_1036 = M2C_FIELD(var_r31_878, u8 *, 0);
    switch ((s8) temp_r4_1036) {                    /* switch 3; irregular */
    case 0x0:                                       /* switch 3 */
        break;
    case 0x3C:                                      /* switch 3 */
        temp_r0_884 = M2C_FIELD(var_r31_878, u8 *, 1);
        if ((((s8) temp_r0_884 == 0x50) || ((s8) temp_r0_884 == 0x70)) && ((s32) M2C_FIELD(var_r31_878, u8 *, 3) == 0x3E)) {
            var_r29_875 = (s8) M2C_FIELD(var_r31_878, u8 *, 2) - 0x30;
        }
        if ((s8) temp_r4_1036 == 0x5C) {
        case 0x5C:                                  /* switch 3 */
            temp_r0_901 = M2C_FIELD(var_r31_878, u8 *, 1);
            var_r31_878 += 1;
            switch ((s8) temp_r0_901) {             /* switch 1; irregular */
            case 0x6E:                              /* switch 1 */
                *var_r30_876 = 0xA;
                var_r30_876 += 1;
                break;
            case 0x72:                              /* switch 1 */
                *var_r30_876 = 0xD;
                var_r30_876 += 1;
                break;
            case 0x5C:                              /* switch 1 */
                *var_r30_876 = 0x5C;
                var_r30_876 += 1;
                break;
            }
        } else if (((s8) temp_r4_1036 == 0x25) && (var_r29_875 == 0)) {
            temp_r0_933 = M2C_FIELD(var_r31_878, u8 *, 1);
            var_r31_878 += 1;
            switch ((s8) temp_r0_933) {             /* switch 2; irregular */
            case 0x74:                              /* switch 2 */
                if ((s32) M2C_FIELD(var_r31_878, u8 *, 1) != 0x32) {
                    var_r5_942 = M2C_FIELD(gpTranslation_StringArray, u8 **, 0xC);
loop_25:
                    temp_r3_956 = *var_r5_942;
                    var_r5_942 += 1;
                    *var_r30_876 = (s8) temp_r3_956;
                    if ((s8) temp_r3_956 != 0) {
                        if (((s32) (u8) *var_r30_876 == 0x5C) && ((s32) *var_r5_942 == 0x6E)) {
                            *var_r30_876 = 0x20;
                            var_r5_942 += 1;
                        }
                        var_r30_876 += 1;
                        goto loop_25;
                    }
                } else {
                    var_r30_876 = &var_r30_876[sprintf(var_r30_876, "", M2C_FIELD(gpTranslation_StringArray, s32 *, 0), "BASLUS-21372s06")];
                    var_r31_878 += 1;
                }
                break;
            case 0x73:                              /* switch 2 */
                var_r4_978 = NULL;
                if ((s32 *) *MemoryCardScreen::selectedCard != NULL) {
                    var_r4_978 = *(gpTranslation_StringArray + ((**MemoryCardScreen::selectedCard * 4) + 0x11C));
                }
                if (var_r4_978 != NULL) {
                    do {
                        temp_r3_990 = *var_r4_978;
                        var_r4_978 += 1;
                        *var_r30_876 = (s8) temp_r3_990;
                        var_r30_876 += 1;
                    } while ((s8) temp_r3_990 != 0);
                    var_r30_876 -= 1;
                }
                break;
            case 0x78:                              /* switch 2 */
                temp_ret_1001 = MemoryCard_GetSaveGameBlockSize();
                var_r30_876 = &var_r30_876[sprintf(var_r30_876, "", temp_ret_1001, M2C_BITWISE(f32, temp_ret_1001))];
                break;
            case 0x79:                              /* switch 2 */
                var_r30_876 = &var_r30_876[sprintf(var_r30_876, "", 1)];
                break;
            case 0x25:                              /* switch 2 */
                *var_r30_876 = 0x25;
                var_r30_876 += 1;
                break;
            }
        } else {
        default:                                    /* switch 3 */
            *var_r30_876 = (s8) temp_r4_1036;
            var_r30_876 += 1;
        }
        var_r31_878 += 1;
        goto loop_42;
    }
    *var_r30_876 = 0;
    return arg0;
}
#endif
