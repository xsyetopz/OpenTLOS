#include "spyro/source/Autosave.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMemoryCard.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/KDMemoryCard.h"
#include "spyro/source/MemoryCard.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIImage.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/Source/Timer.h"
#include "spyro/source/GameVideo.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern KDMemoryCard *autosaveCard;
extern f32 autosaveIconOffset;
extern f32 autosaveIconThrob;
extern GameStateMachine gGMState;
extern f32 gUpdateTimeDelta;
extern s32 gameDataSize;
extern M2C_UNK gb;
extern void *pGameDataCopy;
static TimerInfo autosaveTimeStamp = { 0, 0, 0, 0, 0, 0, 0 };
static UIImage autosaveIcon;                        /* type too large by 8 */
static s32 autosaveFile = -1;
static s32 autosave_state = -1;
static u8 bRemovalCheck = 1;

s32 Autosave_GetGameDataSize() {
    return gameDataSize;
}

void *Autosave_GetGameDataCopy() {
    return pGameDataCopy;
}

void Autosave_CopyGameData() {
    ((GameData *) ((GameData *) GameData::gameData))->UpdateDataHeader(NULL);
    ((GameData *) ((GameData *) GameData::gameData))->CopyFromGameData(pGameDataCopy);
}

void Autosave_Draw() {
    RenderContext sp10;
    f32 var_f0_66;

    if (!(autosaveIconOffset <= 0.0f)) {
        ((GameData *) ((GameData *) GameData::gameData))->GetGameSettings();
        if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x11) != 0) {
            var_f0_66 = 60.0f;
        } else {
            var_f0_66 = 0.0f;
        }
        autosaveIcon.unk18.unk10.unk0 = ((128.0f * autosaveIconOffset) - 24.0f) - var_f0_66;
        autosaveIcon.unk18.unk30 = (0.25f * _table_sinf(autosaveIconThrob)) + 0.75f;
        sp10.RenderContext();
        autosaveIcon.UIImage::Draw(sp10);
    }
}

#if 0 // DRAFT: undefined identifier 'Autosave_Abort'
void Autosave_ConfirmCard() {
    TimerInfo sp8;
    void *temp_r5_139;

    if (((u8) autosaveCard->unk9 == 0) || ((u8) autosaveCard->unkC != 0) || ((u8) autosaveCard->unkD != 0)) {
        Autosave_Abort();
        return;
    }
    if ((u8) autosaveCard->unkA != 0) {
        Autosave_Error();
        return;
    }
    if (((u8) autosaveCard->unkB != 0) || ((s32) autosaveCard->unk1C == 0) || ((s32) autosaveCard->unk20 == 0)) {
        Autosave_Abort();
        return;
    }
    temp_r5_139 = autosaveCard + ((autosaveFile * 0xC0) + 0x40);
    if ((s8) M2C_FIELD(temp_r5_139, u8 *, 0xA4) == 0) {
        Autosave_Abort();
        return;
    }
    Timer_GetDifference(&sp8, &autosaveTimeStamp, temp_r5_139 + 0x80);
    if ((sp8.unk18 != 0) || (sp8.unk14 != 0) || (sp8.unk10 != 0) || ((s32) sp8 != 0) || (sp8.unk4 != 0) || (sp8.unk8 != 0) || (sp8.unkC != 0)) {
        Autosave_Abort();
        return;
    }
    ((GameData *) ((GameData *) GameData::gameData))->GetSaveGameDescription();
    autosaveCard->SaveData(autosaveFile, pGameDataCopy, gameDataSize, M2C_ERROR(/* Read from unset register $r3 */));
    M2C_FIELD(&gb, s8 *, 0x382) = 1;
    autosave_state = 3;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void Autosave_Update() {
    f32 temp_f1_236;
    f32 temp_f1_307;
    u8 temp_r3_243;
    void *temp_r7_341;

    if ((s32) autosave_state == 4) {
        if (autosaveIconThrob <= 0.0f) {
            autosaveIconOffset = -((3.0f * gUpdateTimeDelta) - autosaveIconOffset);
        }
        if (autosaveIconOffset <= 0.0f) {
            autosaveIconOffset = 0.0f;
            autosave_state = 0;
        }
    }
    if (autosaveIconOffset >= 1.0f) {
        temp_f1_236 = (6.2831855f * gUpdateTimeDelta) + autosaveIconThrob;
        autosaveIconThrob = temp_f1_236;
        if (temp_f1_236 > 3.1415927f) {
            autosaveIconThrob = 0.0f;
        }
    }
    temp_r3_243 = ((KDMemoryCard *) (M2C_ERROR(/* Read from unset register $r3 */)))->Update();
    if (temp_r3_243 == 0) {
        switch ((s32) autosave_state) {             /* irregular */
        case 4:
        case 0:
            if (((KDMemoryCard *) autosaveCard != NULL) && ((u8) bRemovalCheck != 0) && (GameVideo_Active() == 0)) {
                if (((u8) autosaveCard->unk9 == 0) || ((u8) autosaveCard->unk8 != 0)) {
                    if (((s32) *gGMState.GetCurrState() == 7) && ((u8) M2C_FIELD(&gb, u8 *, 0x396) == 0)) {
                        Autosave_Abort();
                        return;
                    }
                } else {
                    autosaveCard->SetState((KDMCState) 2);
                    return;
                }
            }
            break;
        case 1:
            Autosave_CopyGameData();
            if ((KDMemoryCard *) autosaveCard == NULL) {
                autosave_state = 0;
                return;
            }
            temp_f1_307 = (6.0f * gUpdateTimeDelta) + autosaveIconOffset;
            autosaveIconOffset = temp_f1_307;
            if (!(temp_f1_307 < 1.0f)) {
                autosaveIconOffset = 1.0f;
                if ((u8) autosaveCard->unk9 == 0) {
                    Autosave_Abort();
                    return;
                }
                autosaveCard->SetState((KDMCState) 3);
                autosave_state = 2;
                return;
            }
            break;
        case 2:
            Autosave_ConfirmCard();
            return;
        case 3:
            if (temp_r3_243->WasErrorDuringLast() != 0) {
                Autosave_Error();
                return;
            }
            temp_r7_341 = autosaveCard + ((autosaveFile * 0xC0) + 0xC0);
            autosaveTimeStamp.unk0 = M2C_FIELD(temp_r7_341, s32 *, 0);
            autosaveTimeStamp.unk4 = M2C_FIELD(temp_r7_341, s32 *, 4);
            autosaveTimeStamp.unk8 = M2C_FIELD(temp_r7_341, s32 *, 8);
            autosaveTimeStamp.unkC = M2C_FIELD(temp_r7_341, s32 *, 0xC);
            autosaveTimeStamp.unk10 = M2C_FIELD(temp_r7_341, s32 *, 0x10);
            autosaveTimeStamp.unk14 = M2C_FIELD(temp_r7_341, s32 *, 0x14);
            autosaveTimeStamp.unk18 = M2C_FIELD(temp_r7_341, s32 *, 0x18);
            bRemovalCheck = 1;
            autosave_state = 4;
            break;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'KDMemoryCard *' to
void Autosave_Abort() {
    *MemoryCardScreen::selectedCard = autosaveCard;
    Autosave_Reset();
    autosave_state = 0;
    PauseMenu_AutosaveScreen"AutosaveCardRemoved";
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'KDMemoryCard *' to
void Autosave_Error() {
    *MemoryCardScreen::selectedCard = autosaveCard;
    Autosave_Reset();
    autosave_state = 0;
    PauseMenu_AutosaveScreen"AutosaveError";
}
#endif

void Autosave_Reset() {
    autosaveCard = NULL;
    autosaveFile = -1;
    autosaveTimeStamp.unk18 = 0;
    autosaveTimeStamp.unk14 = 0;
    autosaveTimeStamp.unk10 = 0;
    autosaveTimeStamp.unk0 = 0;
    autosaveTimeStamp.unk4 = 0;
    autosaveTimeStamp.unk8 = 0;
    autosaveTimeStamp.unkC = 0;
    autosaveIconThrob = 0.0f;
    autosaveIconOffset = 0.0f;
    bRemovalCheck = 1;
}

void Autosave_FreeResources() {
    autosaveIcon.UIImage::FreeResources();
    autosaveIcon.UIImage::Deinit();
}

#if 0 // DRAFT: function call 'UIStringTable_Remove(signed char *)' does not match
void Autosave_LoadResources() {
    autosaveIcon.UIImage::Init();
    autosaveIcon.unk18.unk40 = 0x3A;
    autosaveIcon.unk18.unk10.unk0 = -32.0f;
    autosaveIcon.unk18.unk10.unk4 = 128.0f;
    autosaveIcon.unk18.unk10.unk8 = 0.0f;
    autosaveIcon.unk18.unk34 = 64.0f;
    autosaveIcon.unk18.unk38 = 64.0f;
    autosaveIcon.unk18.unk3C = 5;
    autosaveIcon.unk18.unk30 = 0.75f;
    if ((s8 *) autosaveIcon.unk60 != NULL) {
        UIStringTable_Remove(autosaveIcon.unk60);
    }
    UIStringTable_Add"ui_autosave";
    autosaveIcon.unk60 = M2C_ERROR(/* Read from unset register $r3 */);
    autosaveIcon.UIImage::LoadResources();
    autosaveIconThrob = 0.0f;
    autosaveIconOffset = 0.0f;
}
#endif

void Autosave_DeinitModule() {
    MKHeap *temp_r3_507;
    void *temp_r31_506;

    temp_r31_506 = pGameDataCopy;
    temp_r3_507 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_507 != NULL) {
        ((MKHeap *) (temp_r3_507->Current()))->Free(temp_r31_506, NULL, 0);
    } else {
        free(temp_r31_506);
    }
    pGameDataCopy = NULL;
    gameDataSize = 0;
}

#if 0 // DRAFT: pointer/array required
void Autosave_InitModule() {
    MKHeap *temp_r3_548;
    s32 temp_r3_545;
    void *var_r3_555;

    Autosave_Reset();
    autosave_state = 0;
    autosaveIconThrob = 0.0f;
    autosaveIconOffset = 0.0f;
    temp_r3_545 = ((GameData *) ((GameData *) GameData::gameData))->GetGameDataSize();
    gameDataSize = temp_r3_545;
    temp_r3_548 = temp_r3_545->Current();
    if (temp_r3_548 != NULL) {
        var_r3_555 = ((MKHeap *) (temp_r3_548->Current()))->Alloc(temp_r3_545, NULL, 0);
    } else {
        var_r3_555 = malloc(temp_r3_545);
    }
    pGameDataCopy = var_r3_555;
}
#endif

void Autosave_EnableRemovalCheck(bool arg0) {
    bRemovalCheck = arg0;
}

u8 Autosave_IsActive() {
    return autosave_state != 0;
}

void Autosave_Activate() {
    if (Autosave_IsActive() == 0) {
        autosave_state = 1;
    }
}

void Autosave_SetTarget(KDMemoryCard *arg0, int arg1, const TimerInfo &arg2) {
    autosaveCard = arg0;
    autosaveFile = arg1;
    autosaveTimeStamp.unk0 = arg2.unk0;
    autosaveTimeStamp.unk4 = arg2.unk4;
    autosaveTimeStamp.unk8 = arg2.unk8;
    autosaveTimeStamp.unkC = arg2.unkC;
    autosaveTimeStamp.unk10 = arg2.unk10;
    autosaveTimeStamp.unk14 = arg2.unk14;
    autosaveTimeStamp.unk18 = arg2.unk18;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void Autosave_cpp::__sinit() {
    autosaveIcon.__vptr = &__vt;
    autosaveIcon.__vptr = &__vt;
}
#endif
