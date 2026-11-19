#include "spyro/source/MemoryCard.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/KDMemoryCard.h"
#include "spyro/source/LoadLevel.h"
#include "spyro/source/MCLoadCheckScreen.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UISystem.h"
#include "spyro/source/UIText.h"
#include "unplaced_templates.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/system_extras.h"
#include "spyro/source/Autosave.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/PauseMenu.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

extern GameStateMachine gGMState;
extern void *gpTranslation_StringArray;
static MCSaveScreen descriptor__12MCSaveScreen;     /* type too large by 0xC4; unable to generate initializer: not enough data */
static MCText descriptor__6MCText;                  /* type too large by 0x6C; unable to generate initializer: not enough data */
static s32 memCardSlotSizes;
static s8 gameNameBuffer[0x20];
#if 0 // DRAFT: illegal implicit conversion from 'const char[16]' to
static s8 *pDirectoryName = "BASLUS-21372s06";
#endif
#if 0 // DRAFT: declaration syntax error
static MemoryCardScreen operation__16MemoryCardScreen; /* type too large by 0xD4; unable to generate initializer: not enough data */

static M2C_UNK .L_8035CDF0;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035CDFD;                         /* unable to generate initializer: unknown type; const */

void MCText::Draw(const RenderContext &arg0) {
    MKFont *temp_r4_123;
    f32 temp_f3_134;
    s32 temp_r3_93;
    s32 temp_r4_72;
    arg_sp58 = M2C_FIELD(&zero, f64 *, 8);
    arg_sp50 = M2C_FIELD(&zero, f64 *, 0);
    arg_sp5C = 1.0f;
    if (((MKFont *) this->unk64 >= 0) && ((MKFont *) this->unk64 != NULL) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((this->unk18.unk34 == 0.0f) == 0))) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk18.unk38 == 0.0f) {
            return;
        }
        arg_spA0.RenderContext();
        arg_spA0.AddState(arg0, this->unk18);
        temp_r4_72 = this->unk18.unk3C;
        if (!(temp_r4_72 & 3)) {
            arg_sp50 = this->unk18.unk34 * 0.5f;
        } else if (temp_r4_72 & 1) {
            arg_sp50 = 0.0f;
        } else {
            arg_sp50 = this->unk18.unk34 / -2.0f;
        }
        temp_r3_93 = this->unk18.unk3C;
        if (!(temp_r3_93 & 0xC)) {
            arg_sp54 = this->unk18.unk38 * 0.5f;
        } else if (temp_r3_93 & 4) {
            arg_sp54 = 0.0f;
        } else {
            arg_sp54 = this->unk18.unk38 / -2.0f;
        }
        arg_sp60.SetIdentity();
        arg_sp60.Translate((Matrix *) &arg_sp60, *((MKVector3 *) &arg_sp50));
        arg_spA0.Multiply((Matrix *) &arg_sp60, (Matrix *) &arg_spA0);
        temp_r4_123 = this->unk64;
        if ((temp_r4_123 >= 0) && ((u32) *(gpTranslation_StringArray + ((s32) temp_r4_123 * 4)) != 0U)) {
            MemoryCard_String(&arg_spF0, (s32) temp_r4_123);
            temp_f3_134 = M2C_BITWISE(f32, this->unk68);
            if ((temp_f3_134 != 0.0f) || (M2C_BITWISE(f32, this->unk6C) != 0.0f)) {
                arg_sp28 = arg_spD8;
                arg_sp20 = arg_spD0 + temp_f3_134;
                arg_sp24 = arg_spD4 + M2C_BITWISE(f32, this->unk6C);
                arg_sp48 = (f64) arg_sp28;
                arg_sp40 = (f64) arg_sp20;
                arg_spD0 = (f32) arg_sp40;
                arg_spD4 = arg_sp44;
                arg_spD8 = (f32) arg_sp48;
                arg_spDC = 1.0f;
                this->unk64->DrawString(&arg_spF0, this->unk18.unk34, this->unk18.unk38, (Matrix *) &arg_spA0, this->unk18.unk3C, 0x80000000U, 1.0f, 1.0f, NULL, 1U);
                arg_sp18 = arg_spD8;
                arg_sp10 = arg_spD0 - M2C_BITWISE(f32, this->unk68);
                arg_sp14 = arg_spD4 - M2C_BITWISE(f32, this->unk6C);
                arg_sp38 = (f64) arg_sp18;
                arg_sp30 = (f64) arg_sp10;
                arg_spD0 = (f32) arg_sp30;
                arg_spD4 = arg_sp34;
                arg_spD8 = (f32) arg_sp38;
                arg_spDC = 1.0f;
            }
            this->unk64->DrawString(&arg_spF0, this->unk18.unk34, this->unk18.unk38, (Matrix *) &arg_spA0, this->unk18.unk3C, (u32) (128.0f * arg_spE0) | (((u32) (128.0f * arg_spE4) << 8) | (((u32) (128.0f * arg_spEC) << 0x18) | ((u32) (128.0f * arg_spE8) << 0x10))), 1.0f, 1.0f, NULL, 1U);
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void MemoryCardScreen::ExamineCard() {
    s32 temp_r30_344;
    s32 var_ctr_319;
    s32 var_r3_318;

    if ((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 0xC) != 0) {
        query.__vptr = (void *)5;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    if ((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 0xD) != 0) {
        query.__vptr = (void *)1;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    if ((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 0xA) != 0) {
        query.__vptr = (void *)2;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    if ((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 0xB) != 0) {
        query.__vptr = (void *)9;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    if ((s32) M2C_FIELD(selectedCard.__vptr, s32 *, 0x1C) == 0) {
        query.__vptr = (void *)8;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    if ((s32) M2C_FIELD(selectedCard.__vptr, s32 *, 0x20) == 0) {
        if ((void *) operation.__vptr == NULL) {
            query.__vptr = (void *)7;
            ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
            return;
        }
        action.__vptr = (void *)2;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    var_r3_318 = 0;
    var_ctr_319 = 3;
loop_15:
    if ((s8) *(selectedCard.__vptr + (var_r3_318 + 0xE5)) != 0) {
        action.__vptr = (void *)5;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
        return;
    }
    var_r3_318 += 0xC0;
    var_ctr_319 -= 1;
    if (var_ctr_319 == 0) {
        if (((void *) operation.__vptr == (void *)1) && ((s32) M2C_FIELD(selectedCard.__vptr, s32 *, 0x24) == 0) && ((temp_r30_344 = M2C_FIELD(selectedCard.__vptr, s32 *, 0x18), ((temp_r30_344 < MemoryCard_GetSaveGameBlockSize()) != 0)) || ((s32) M2C_FIELD(selectedCard.__vptr, s32 *, 0x14) < 1))) {
            query.__vptr = (void *)6;
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
    UIObject *temp_r0_391;

    UIScreen::OnExit();
    temp_r0_391 = ui_cast<UISystem *, UIContainer *>(GetRoot())->unk60;
    if ((temp_r0_391 == (UIObject *)3) || (temp_r0_391 == (UIObject *)4)) {
        Autosave_EnableRemovalCheck(1U);
        if ((s32) *gGMState.GetCurrState() == 7) {
            PauseMenu_AllowStartToQuit(1U);
        }
    }
    FrontEnd_SetFade(0.0f);
}
#endif

#if 0 // DRAFT: expression syntax error
void MemoryCardScreen::OnEnter() {
    UIObject *var_r30_429;
    s32 temp_r3_426;
    s8 *temp_r3_439;
    s8 *temp_r3_450;
    void *temp_r3_433;

    UIScreen::OnEnter();
    temp_r3_426 = this->unkBC.unk4;
    if ((u32) temp_r3_426 != 0U) {
        var_r30_429 = M2C_FIELD(temp_r3_426, UIObject **, 0x60);
loop_11:
        if (var_r30_429 == NULL) {

        } else {
            temp_r3_433 = ui_cast<UIText *, UIObject *>(var_r30_429);
            if (temp_r3_433 != NULL) {
                if ((void *) operation.__vptr == (void *)1) {
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

#if 0 // DRAFT: illegal implicit conversion from 'UIContainer *' to
void MemoryCardScreen::Resolve() {
    UIScreen::Resolve();
    this->unkBC.unk4 = ui_cast<UIContainer *, UIObject *>(FindChild(""));
}
#endif

void MemoryCardScreen::Init() {
    UIContainer::Init();
    this->unkBC.unk4 = 0;
}

#if 0 // DRAFT: undefined identifier 'P8UISystem'
void MCSaveScreen::Update() {
    UIContainer *temp_r3_534;
    s8 *temp_r3_560;
    s8 *temp_r3_584;
    s8 *temp_r3_607;
    void *var_r31_527;

    UIScreen::Update();
    if (((KDMemoryCard *) (M2C_ERROR(/* Read from unset register $r3 */)))->Update() == 0) {
        var_r31_527 = NULL;
        temp_r3_534 = ui_cast<UIContainer *, UIObject *>(((UIContainer *) (ui_cast<P8UISystem))->FindChild(P11UIContainer>__FP11UIContainer(GetRoot()), ""));
        if (temp_r3_534 != NULL) {
            var_r31_527 = ui_cast<UIText *, UIObject *>(temp_r3_534->FindChild(""));
        }
        operation.__vptr = (void *)-1;
        bNewGame = 0;
        if (strnicmp((s8 *) this->unk4, "", 4) == 0) {
            operation.__vptr = (void *)1;
            if (var_r31_527 != NULL) {
                temp_r3_560 = M2C_FIELD(var_r31_527, s8 **, 0x68);
                if (temp_r3_560 != NULL) {
                    UIStringTable_Remove(temp_r3_560);
                }
                M2C_FIELD(var_r31_527, s8 **, 0x68) = NULL;
                M2C_FIELD(var_r31_527, s32 *, 0x6C) = 0x83;
            }
        } else if (strnicmp((s8 *) this->unk4, "", 3) == 0) {
            operation.__vptr = (void *)1;
            bNewGame = 1;
            if (var_r31_527 != NULL) {
                temp_r3_584 = M2C_FIELD(var_r31_527, s8 **, 0x68);
                if (temp_r3_584 != NULL) {
                    UIStringTable_Remove(temp_r3_584);
                }
                M2C_FIELD(var_r31_527, s8 **, 0x68) = NULL;
                M2C_FIELD(var_r31_527, s32 *, 0x6C) = 0x82;
            }
        } else if (strnicmp((s8 *) this->unk4, "", 4) == 0) {
            operation.__vptr = NULL;
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
    temp_r3_704 = gameData.GetGameDataSize();
    M2C_FIELD(&memCardSlotSizes, s32 *, 0xC) = temp_r3_704;
    M2C_FIELD(&memCardSlotSizes, s32 *, 8) = temp_r3_704;
    M2C_FIELD(&memCardSlotSizes, s32 *, 4) = temp_r3_704;
    MKMemoryCard_SetAppInfo(pDirectoryName, gameNameBuffer, &memCardSlotSizes);
    ((KDMemoryCard *) (M2C_ERROR(/* Read from unset register $r3 */)))->InitModule();
    Autosave_InitModule();
    var_r4_717 = &list;
loop_3:
    temp_r3_725 = var_r4_717->unk0;
    if (temp_r3_725 == NULL) {
        var_r4_717->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_725 != &descriptor) {
        var_r4_717 = (UIObjectDescriptor *) &temp_r3_725->unk10;
        goto loop_3;
    }
    var_r4_735 = &list;
loop_8:
    temp_r3_743 = var_r4_735->unk0;
    if (temp_r3_743 == NULL) {
        var_r4_735->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_743 != &descriptor) {
        var_r4_735 = (UIObjectDescriptor *) &temp_r3_743->unk10;
        goto loop_8;
    }
    var_r4_753 = &list;
loop_13:
    temp_r3_761 = var_r4_753->unk0;
    if (temp_r3_761 == NULL) {
        var_r4_753->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_761 != &descriptor) {
        var_r4_753 = (UIObjectDescriptor *) &temp_r3_761->unk10;
        goto loop_13;
    }
    var_r4_771 = &list;
loop_18:
    temp_r3_779 = var_r4_771->unk0;
    if (temp_r3_779 == NULL) {
        var_r4_771->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_779 != &descriptor) {
        var_r4_771 = (UIObjectDescriptor *) &temp_r3_779->unk10;
        goto loop_18;
    }
    var_r4_789 = &list;
loop_23:
    temp_r3_797 = var_r4_789->unk0;
    if (temp_r3_797 == NULL) {
        var_r4_789->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_797 != &descriptor) {
        var_r4_789 = (UIObjectDescriptor *) &temp_r3_797->unk10;
        goto loop_23;
    }
    var_r4_807 = &list;
loop_28:
    temp_r3_815 = var_r4_807->unk0;
    if (temp_r3_815 == NULL) {
        var_r4_807->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_815 != &descriptor) {
        var_r4_807 = (UIObjectDescriptor *) &temp_r3_815->unk10;
        goto loop_28;
    }
    var_r4_825 = &list;
loop_33:
    temp_r3_833 = var_r4_825->unk0;
    if (temp_r3_833 == NULL) {
        var_r4_825->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_833 != &descriptor) {
        var_r4_825 = (UIObjectDescriptor *) &temp_r3_833->unk10;
        goto loop_33;
    }
    var_r4_843 = &list;
loop_38:
    temp_r3_851 = var_r4_843->unk0;
    if (temp_r3_851 == NULL) {
        var_r4_843->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_851 != &descriptor) {
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
                if ((u32) selectedCard.__vptr != 0U) {
                    var_r4_978 = *(gpTranslation_StringArray + ((*selectedCard.__vptr * 4) + 0x11C));
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
