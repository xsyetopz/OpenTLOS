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
static s8 *pDirectoryName = (signed char *) ("BASLUS-21372s06");
u8 operation__16MemoryCardScreen[4] = { 0xFF, 0xFF, 0xFF, 0xFF };

s8 *MemoryCard_String(char *arg0, int arg1);
void MCText::Draw(const RenderContext &arg0) {
    char spF0[0x20];
    Matrix sp60;
    f64 sp58;
    f64 sp50;
    f64 sp40;
    f64 sp48;
    f64 sp30;
    f64 sp38;
    f64 sp20;
    f64 sp28;
    f64 sp10;
    f64 sp18;
    f32 temp_f3_134;
    s32 temp_r3_93;
    s32 temp_r4_123;
    s32 temp_r4_72;
    u32 color;
    Attributes &attr = M2C_FIELD(this, Attributes *, 0x18);

    sp58 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp50 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(&sp58, f32 *, 0x4) = 1.0f;
    if ((M2C_FIELD(this, s32 *, 0x6C) >= 0) && (M2C_FIELD(this, MKFont **, 0x64) != NULL) && !(attr.unk34 <= 0.0f)) {
        if (attr.unk38 <= 0.0f) {
            return;
        }
        RenderContext spA0;
        spA0.AddState(arg0, attr);
        color = (u32) (128.0f * M2C_FIELD(&spA0, f32 *, 0x48)) << 16;
        color = ((u32) (128.0f * M2C_FIELD(&spA0, f32 *, 0x4C)) << 24) | color;
        color = ((u32) (128.0f * M2C_FIELD(&spA0, f32 *, 0x44)) << 8) | color;
        color = ((u32) (128.0f * M2C_FIELD(&spA0, f32 *, 0x40))) | color;
        temp_r4_72 = attr.unk3C;
        if (!(temp_r4_72 & 3)) {
            M2C_FIELD(&sp50, f32 *, 0x0) = attr.unk34 * 0.5f;
        } else if (temp_r4_72 & 1) {
            M2C_FIELD(&sp50, f32 *, 0x0) = 0.0f;
        } else {
            M2C_FIELD(&sp50, f32 *, 0x0) = attr.unk34 / -2.0f;
        }
        temp_r3_93 = attr.unk3C;
        if (!(temp_r3_93 & 0xC)) {
            M2C_FIELD(&sp50, f32 *, 0x4) = attr.unk38 * 0.5f;
        } else if (temp_r3_93 & 4) {
            M2C_FIELD(&sp50, f32 *, 0x4) = 0.0f;
        } else {
            M2C_FIELD(&sp50, f32 *, 0x4) = attr.unk38 / -2.0f;
        }
        sp60.SetIdentity();
        sp60.Translate(&sp60, *((MKVector3 *) &sp50));
        ((Matrix *) &spA0)->Multiply(&sp60, (Matrix *) &spA0);
        temp_r4_123 = M2C_FIELD(this, s32 *, 0x6C);
        if ((temp_r4_123 >= 0) && (((u32 *) gpTranslation_StringArray)[temp_r4_123] != 0U)) {
            MemoryCard_String(spF0, temp_r4_123);
            temp_f3_134 = M2C_FIELD(this, f32 *, 0x70);
            if ((temp_f3_134 != 0.0f) || (M2C_FIELD(this, f32 *, 0x74) != 0.0f)) {
                M2C_FIELD(&sp20, f32 *, 0x0) = spA0.unk30 + temp_f3_134;
                M2C_FIELD(&sp20, f32 *, 0x4) = spA0.unk34 + M2C_FIELD(this, f32 *, 0x74);
                M2C_FIELD(&sp28, f32 *, 0x0) = spA0.unk38;
                sp48 = sp28;
                sp40 = sp20;
                spA0.unk30 = M2C_FIELD(&sp40, f32 *, 0x0);
                spA0.unk34 = M2C_FIELD(&sp40, f32 *, 0x4);
                spA0.unk38 = M2C_FIELD(&sp48, f32 *, 0x0);
                spA0.unk3C = 1.0f;
                M2C_FIELD(this, MKFont **, 0x64)->DrawString(spF0, attr.unk34, attr.unk38, (Matrix *) &spA0, attr.unk3C, 0x80000000U, 1.0f, 1.0f, NULL, 1U);
                M2C_FIELD(&sp18, f32 *, 0x0) = spA0.unk38;
                M2C_FIELD(&sp10, f32 *, 0x0) = spA0.unk30 - M2C_FIELD(this, f32 *, 0x70);
                M2C_FIELD(&sp10, f32 *, 0x4) = spA0.unk34 - M2C_FIELD(this, f32 *, 0x74);
                sp38 = sp18;
                sp30 = sp10;
                spA0.unk30 = M2C_FIELD(&sp30, f32 *, 0x0);
                spA0.unk34 = M2C_FIELD(&sp30, f32 *, 0x4);
                spA0.unk38 = M2C_FIELD(&sp38, f32 *, 0x0);
                spA0.unk3C = 1.0f;
            }
            M2C_FIELD(this, MKFont **, 0x64)->DrawString(spF0, attr.unk34, attr.unk38, (Matrix *) &spA0, attr.unk3C, color, 1.0f, 1.0f, NULL, 1U);
        }
    }
}

void MemoryCardScreen::ExamineCard() {
    s32 temp_r30_344;
    s32 var_ctr_319;
    s32 var_r3_318;

    if ((u8) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, u8 *, 0xC) != 0) {
        *(s32 *) MCQueryScreen::query = 5;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
        return;
    }
    if ((u8) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, u8 *, 0xD) != 0) {
        *(s32 *) MCQueryScreen::query = 1;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
        return;
    }
    if ((u8) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, u8 *, 0xA) != 0) {
        *(s32 *) MCQueryScreen::query = 2;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
        return;
    }
    if ((u8) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, u8 *, 0xB) != 0) {
        *(s32 *) MCQueryScreen::query = 9;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
        return;
    }
    if ((s32) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, s32 *, 0x1C) == 0) {
        *(s32 *) MCQueryScreen::query = 8;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
        return;
    }
    if ((s32) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, s32 *, 0x20) == 0) {
        if (*(s32 *) MemoryCardScreen::operation == 0) {
            *(s32 *) MCQueryScreen::query = 7;
            ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
            return;
        }
        *(s32 *) MCActionScreen::action = 2;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCAction");
        return;
    }
    var_r3_318 = 0;
    var_ctr_319 = 3;
loop_15:
    if ((s8) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, u8 *, var_r3_318 + 0xE5) != 0) {
        *(s32 *) MCActionScreen::action = 5;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCAction");
        return;
    }
    var_r3_318 += 0xC0;
    var_ctr_319 -= 1;
    if (var_ctr_319 == 0) {
        temp_r30_344 = M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, s32 *, 0x18);
        if (*(s32 *) MemoryCardScreen::operation == 1 && (s32) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, s32 *, 0x24) == 0
                && ((temp_r30_344 < MemoryCard_GetSaveGameBlockSize()) || (s32) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, s32 *, 0x14) < 1)) {
            *(s32 *) MCQueryScreen::query = 6;
            ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
            return;
        }
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectFile");
        return;
    }
    goto loop_15;
}

void MemoryCardScreen::OnExit() {
    s32 temp_r0_391;

    UIScreen::OnExit();
    temp_r0_391 = ui_cast<UISystem *, UIContainer *>(GetRoot())->unk68;
    if ((temp_r0_391 == 3) || (temp_r0_391 == 4)) {
        Autosave_EnableRemovalCheck(1U);
        if (*(s32 *) gGMState.GetCurrState() == 7) {
            PauseMenu_AllowStartToQuit(1U);
        }
    }
    FrontEnd_SetFade(0.0f);
}

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
                if (*(s32 *) MemoryCardScreen::operation == 1) {
                    temp_r3_439 = M2C_FIELD(temp_r3_433, s8 **, 0x68);
                    if (temp_r3_439 != NULL) {
                        UIStringTable_Remove((const char *) temp_r3_439);
                    }
                    M2C_FIELD(temp_r3_433, s8 **, 0x68) = NULL;
                    M2C_FIELD(temp_r3_433, s32 *, 0x6C) = 0x4C;
                    return;
                }
                temp_r3_450 = M2C_FIELD(temp_r3_433, s8 **, 0x68);
                if (temp_r3_450 != NULL) {
                    UIStringTable_Remove((const char *) temp_r3_450);
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

void MemoryCardScreen::Resolve() {
    UIScreen::Resolve();
    this->unkC8 = ui_cast<UIContainer *, UIObject *>(FindChild(""));
}

void MemoryCardScreen::Init() {
    UIContainer::Init();
    this->unkC8 = NULL;
}

void MCSaveScreen::Update() {
    UIContainer *temp_r3_534;
    s8 *temp_r3_560;
    s8 *temp_r3_584;
    s8 *temp_r3_607;
    void *var_r31_527;

    UIScreen::Update();
    if ((u8) KDMemoryCard::Update() == 0) {
        var_r31_527 = NULL;
        temp_r3_534 = ui_cast<UIContainer *, UIObject *>(ui_cast<UISystem *, UIContainer *>(GetRoot())->FindChild("mc_default"));
        if (temp_r3_534 != NULL) {
            var_r31_527 = ui_cast<UIText *, UIObject *>(temp_r3_534->FindChild("Heading"));
        }
        *(s32 *) MemoryCardScreen::operation = -1;
        *MemoryCardScreen::bNewGame = 0;
        if (strnicmp((const char *) this->unk4, "Save", 4) == 0) {
            *(s32 *) MemoryCardScreen::operation = 1;
            if (var_r31_527 != NULL) {
                temp_r3_560 = M2C_FIELD(var_r31_527, s8 **, 0x68);
                if (temp_r3_560 != NULL) {
                    UIStringTable_Remove((const char *) temp_r3_560);
                }
                M2C_FIELD(var_r31_527, s8 **, 0x68) = NULL;
                M2C_FIELD(var_r31_527, s32 *, 0x6C) = 0x83;
            }
        } else if (strnicmp((const char *) this->unk4, "New", 3) == 0) {
            *(s32 *) MemoryCardScreen::operation = 1;
            *MemoryCardScreen::bNewGame = 1;
            if (var_r31_527 != NULL) {
                temp_r3_584 = M2C_FIELD(var_r31_527, s8 **, 0x68);
                if (temp_r3_584 != NULL) {
                    UIStringTable_Remove((const char *) temp_r3_584);
                }
                M2C_FIELD(var_r31_527, s8 **, 0x68) = NULL;
                M2C_FIELD(var_r31_527, s32 *, 0x6C) = 0x82;
            }
        } else if (strnicmp((const char *) this->unk4, "Load", 4) == 0) {
            *(s32 *) MemoryCardScreen::operation = 0;
            if (var_r31_527 != NULL) {
                temp_r3_607 = M2C_FIELD(var_r31_527, s8 **, 0x68);
                if (temp_r3_607 != NULL) {
                    UIStringTable_Remove((const char *) temp_r3_607);
                }
                M2C_FIELD(var_r31_527, s8 **, 0x68) = NULL;
                M2C_FIELD(var_r31_527, s32 *, 0x6C) = 0x81;
            }
        }
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectCard");
    }
}

void MCSaveScreen::OnEnter() {
    MemoryCardScreen::OnEnter();
    Autosave_EnableRemovalCheck(0U);
    if (*(s32 *) gGMState.GetCurrState() == 7) {
        PauseMenu_AllowStartToQuit(0U);
    }
}

s32 MemoryCard_GetSaveGameBlockSize() {
    return ((s32) (M2C_FIELD(&memCardSlotSizes, s32 *, 4) + MKMemoryCard_CalculateFileSize()) / 8192) + 1;
}

void MemoryCard_DeinitModule() {
    Autosave_DeinitModule();
}

s8 *MemoryCard_String(char *, int);
void MemoryCard_InitModule() {
    MCLoadCheckScreen **slot;
    MCLoadCheckScreen *cur;
    s32 gdSize;

    MemoryCard_String((char *) gameNameBuffer, 3);
    M2C_FIELD(&memCardSlotSizes, s32 *, 0) = 3;
    gdSize = ((GameData *) GameData::gameData)->GetGameDataSize();
    M2C_FIELD(&memCardSlotSizes, s32 *, 0xC) = gdSize;
    M2C_FIELD(&memCardSlotSizes, s32 *, 8) = gdSize;
    M2C_FIELD(&memCardSlotSizes, s32 *, 4) = gdSize;
    MKMemoryCard_SetAppInfo((const char *) pDirectoryName, (const char *) gameNameBuffer, (int *) &memCardSlotSizes);
    KDMemoryCard::InitModule();
    Autosave_InitModule();

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCSaveScreen::descriptor;
            M2C_FIELD(MCSaveScreen::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCSaveScreen::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCSelectCardScreen::descriptor;
            M2C_FIELD(MCSelectCardScreen::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCSelectCardScreen::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCSelectFileScreen::descriptor;
            M2C_FIELD(MCSelectFileScreen::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCSelectFileScreen::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCActionScreen::descriptor;
            M2C_FIELD(MCActionScreen::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCActionScreen::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCQueryScreen::descriptor;
            M2C_FIELD(MCQueryScreen::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCQueryScreen::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCText::descriptor;
            M2C_FIELD(MCText::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCText::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCFileInfo::descriptor;
            M2C_FIELD(MCFileInfo::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCFileInfo::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) AutosaveWarningScreen::descriptor;
            M2C_FIELD(AutosaveWarningScreen::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) AutosaveWarningScreen::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }
}

s8 *MemoryCard_String(char *arg0, int arg1) {
    s32 digit = 0;
    s8 *dst = (s8 *) arg0;
    s8 *src = *(s8 **) ((s8 *) gpTranslation_StringArray + arg1 * 4);

    for (; *src != 0; src++) {
        s8 c = *src;
        if (c == '<' && (src[1] == 'P' || src[1] == 'p') && src[3] == '>') {
            digit = src[2] - 0x30;
        }
        if (c == '\\') {
            src++;
            if (*src == 'n') {
                *dst++ = 0x0A;
            } else if (*src == 'r') {
                *dst++ = 0x0D;
            } else if (*src == '\\') {
                *dst++ = 0x5C;
            }
        } else if (c == '%' && digit == 0) {
            s8 t;

            src++;
            t = *src;
            if (t == 't') {
                if (src[1] == '2') {
                    dst += sprintf((char *) dst, "%s", *(char **) gpTranslation_StringArray);
                    src++;
                } else {
                    s8 *p = *(s8 **) ((s8 *) gpTranslation_StringArray + 0xC);
                    for (;;) {
                        s8 ch = *p++;
                        *dst = ch;
                        if (ch == 0) {
                            break;
                        }
                        if (ch == '\\' && *p == 'n') {
                            *dst = ' ';
                            p++;
                        }
                        dst++;
                    }
                }
            } else if (t == 's') {
                s8 *str = NULL;
                void *card = *(void **) MemoryCardScreen::selectedCard;

                if (card != NULL) {
                    str = *(s8 **) ((s8 *) gpTranslation_StringArray + (*(s32 *) card * 4) + 0x11C);
                }
                if (str != NULL) {
                    s8 ch;
                    do {
                        ch = *str++;
                        *dst++ = ch;
                    } while (ch != 0);
                    dst--;
                }
            } else if (t == 'x') {
                dst += sprintf((char *) dst, "%d", MemoryCard_GetSaveGameBlockSize());
            } else if (t == 'y') {
                dst += sprintf((char *) dst, "%d", 1);
            } else if (t == '%') {
                *dst++ = '%';
            }
        } else {
            *dst++ = c;
        }
    }
    *dst = 0;
    return (s8 *) arg0;
}
