#include "spyro/source/LoadLevel.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/CutsceneSystem.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/MCLoadCheckScreen.h"
#include "spyro/source/Tools.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/UISystem.h"
#include "spyro/source/UIText.h"
#include "spyro/source/checkpoint.h"
#include "unplaced_templates.h"
#include "common/Source/MKPackage.h"
#include "common/Source/Str.h"
#include "spyro/source/Autosave.h"
#include "spyro/source/ConnectingProps.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/GameLanguage.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Music.h"
#include "spyro/source/PauseMenu.h"
#include "spyro/source/PhrasePlayer.h"
#include <m2c_macros.h>

M2C_UNK free(void **);                              /* extern */
UIObject *malloc(s32);                              /* extern */
extern u8 bCheckedConnectors;
extern M2C_UNK enableChunkMessage;
extern GameStateMachine gGMState;
extern void *gMK;
extern M2C_UNK gMKDefaults;
extern f32 gUpdateTimeDelta;
extern GameGlobals gb;
extern void *gpTranslation_StringArray;
extern s32 loadState;
extern ChunkInfo *pChunk;
extern ChunkInfo *pLoadChunkInfo;
extern void **pLoadingScreenSystem;
extern void **pResidentLSSystem;
extern void *pText;
extern UIStringTable residentLSStrings;
#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
static M2C_UNK *pDots[4] = { "<p0><colour=0,0,0,1>...</colour>", &.L_8035BDC1, &.L_8035BDE2, &.L_8035BE03 };
#endif
u8 descriptor__13LoadingScreen[0x14];               /* unable to generate initializer: cannot parse .L_8035BE0B as integer */
static s32 hPackage = -1;

#if 0 // DRAFT: declaration syntax error
static M2C_UNK .L_8035BDC1;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BDE2;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BE03;                         /* unable to generate initializer: unknown type; const */

void LoadLevel_Draw() {
    RenderContext sp20;
    Tools_Ortho sp10;

    if ((void **) pLoadingScreenSystem != NULL) {
        sp10.Tools_Ortho();
        sp20.RenderContext();
        M2C_FIELD(*pLoadingScreenSystem, M2C_UNK (**)(void **, RenderContext *), 0x1C)(pLoadingScreenSystem, &sp20);
        sp10.~Tools_Ortho(-1);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp18'
void LoadLevel_UpdateLoading() {
    f64 sp10;
    f64 sp8;
    s32 var_r30_131;
    u32 temp_r3_133;

    Autosave_Update();
    switch ((s32) loadState) {                      /* irregular */
    case 0:
        if ((s32) hPackage < 0) {
            hPackage = MKPackage_QLoad("GlobalInit", 0);
        }
        if (MKPackage_QIsLoaded(hPackage, NULL, NULL) != 0) {
            GameData::gameData[0x168] |= (u8) pLoadChunkInfo->unk28;
            GameData::gameData[0x169] |= (u8) pLoadChunkInfo->unk2C;
            ((GameStats *) &GameData::gameData[0x70])->SetAttacksAvailable(pLoadChunkInfo->unk30);
            gb.ResetInGameData();
            gb.unk32C->Init(pLoadChunkInfo);
            gb.unk32C->LoadGlobalResources();
            PauseMenu_Init();
            MKPackage_QFree(hPackage);
            hPackage = -1;
            loadState = 1;
            return;
        }
    case 4:
        return;
    case 1:
        gb.unk32C->CreateNormalResources();
        loadState = 2;
        return;
    case 2:
        bCheckedConnectors = 0;
        ((Level *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetWorldInfo();
        M2C_FIELD(&sp18[0], ChunkInfo **, 0) = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), ChunkInfo **, 0x18);
        var_r30_131 = 1;
        temp_r3_133 = M2C_FIELD(pLoadChunkInfo->unk4, u32 *, 0x118);
        if (temp_r3_133 != 0U) {
            var_r30_131 = 2;
            M2C_FIELD(&sp18[0], u32 *, 4) = temp_r3_133;
        }
        (&sp18[0])[var_r30_131] = pLoadChunkInfo;
        gb.unk32C->SetDesiredChunks(&sp18[0], var_r30_131 + 1);
        gb.unk32C->unk8 = 1;
        loadState = 3;
        return;
    case 3:
        if (((u32) gb.unk32C->unk1C == 0) && (((u8) bCheckedConnectors != 0) || ((void *) *CheckPoint::pCurrentCheckPoint == NULL) || (bCheckedConnectors = 1, sp8 = M2C_FIELD(*CheckPoint::pCurrentCheckPoint, f64 *, 0xF0), sp10 = M2C_FIELD(*CheckPoint::pCurrentCheckPoint, f64 *, 0xF8), ((Connector_Update(*((MKVector3 *) &sp8)) == 0) == 0)))) {
            gb.unk32C->FinaliseResources();
            loadState = 4;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: function call 'MKPackage_QLoad(signed char *, int)' does not match
void LoadFrontEnd_UpdateLoading() {
    switch ((s32) loadState) {                      /* irregular */
    case 0:
        if ((s32) hPackage < 0) {
            GameLanguage_GetCode(-1);
            hPackage = MKPackage_QLoad(Str_Printf("frontend%s", M2C_ERROR(/* Read from unset register $r3 */), "<p0><colour=0, 0, 0, 1>...</colour>"), 0);
        }
        if (MKPackage_QIsLoaded(hPackage, NULL, NULL) != 0) {
            FrontEnd_Init();
            MKPackage_QFree(hPackage);
            hPackage = -1;
            loadState = 4;
        }
        /* fallthrough */
    case 4:
        return;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void LoadLevel_Update() {
    if ((s32) *gGMState.GetCurrState() == 4) {
        LoadFrontEnd_UpdateLoading();
    } else {
        LoadLevel_UpdateLoading();
    }
    if (((void **) pLoadingScreenSystem != NULL) && (M2C_FIELD(M2C_FIELD(pLoadingScreenSystem, void **, 0), M2C_UNK (**)(), 0x18)(), (((u32) M2C_FIELD(&pLoadingScreenSystem[M2C_FIELD(pLoadingScreenSystem, s32 *, 0x6C)], u32 *, 0x70) == 0U) != 0))) {
        if ((s32) *gGMState.GetCurrState() == 4) {
            gGMState.SwitchState(5, 0, 0U);
            return;
        }
        gGMState.SwitchState(7, 0, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HeroInterface'
void LoadLevel_Deactivate(bool arg0) {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r3_316;
    void *temp_r3_332;
    void *temp_r3_348;

    if (arg0 == 0) {
        loadState = 4;
        return;
    }
    temp_r3_316 = gb.unk0->GetProp();
    sp1C = 0;
    sp18 = 0xAC;
    M2C_FIELD(M2C_FIELD(temp_r3_316, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp18);
    temp_r3_332 = gb.unk0->GetProp();
    sp14 = 0;
    sp10 = 0xAA;
    M2C_FIELD(M2C_FIELD(temp_r3_332, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    temp_r3_348 = gb.unk0->GetProp();
    spC = 0;
    sp8 = 0xB1;
    M2C_FIELD(M2C_FIELD(temp_r3_348, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    LoadLevel_Deinit();
    gb.unk396 = 0;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HeroInterface'
void LoadLevel_Activate(ChunkInfo *arg0) {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r3_383;
    void *temp_r3_399;
    void *temp_r3_415;

    pChunk = arg0;
    temp_r3_383 = gb.unk0->GetProp(&gb);
    sp1C = 0;
    sp18 = 0xAB;
    M2C_FIELD(M2C_FIELD(temp_r3_383, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp18);
    temp_r3_399 = gb.unk0->GetProp();
    sp14 = 0;
    sp10 = 0xA9;
    M2C_FIELD(M2C_FIELD(temp_r3_399, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    temp_r3_415 = gb.unk0->GetProp();
    spC = 0;
    sp8 = 0xB0;
    M2C_FIELD(M2C_FIELD(temp_r3_415, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    gb.unk396 = 1;
    if (PhrasePlayer_IsAnyEventPlaying() != 0) {
        PhrasePlayer_StopAnyEvent();
    }
    KDSound_SoundDucking_Deinit();
    if ((void **) pLoadingScreenSystem == NULL) {
        LoadLevel_Init();
        M2C_FIELD(&enableChunkMessage, s32 *, 0) = 0;
        M2C_FIELD(&enableChunkMessage, s32 *, 4) = 0;
        KDSound_StopAll();
        Music_Stop(0.0f);
        Music_ClearDelayedPlayBuffer();
    }
}
#endif

s32 LoadLevel_GetState() {
    return loadState;
}

#if 0 // DRAFT: undefined identifier 'unk340'
void LoadLevel_Deinit() {
    s32 spC;
    s32 sp8;
    f32 var_f0_475;

    pLoadingScreenSystem = NULL;
    if ((s32) gb.unk340 != 0) {
        var_f0_475 = 2.0f;
    } else {
        ((Level *) &gb)->GetWorldInfo();
        var_f0_475 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x1C);
    }
    M2C_FIELD(gMK, f32 *, 0xB0) = var_f0_475;
    M2C_FIELD(&gMKDefaults, s8 *, 0x1C) = 1;
    if ((void *) M2C_FIELD(&enableChunkMessage, void **, 4) != NULL) {
        spC = 0;
        sp8 = M2C_FIELD(&enableChunkMessage, s32 *, 0);
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&enableChunkMessage, void **, 4), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    M2C_FIELD(&enableChunkMessage, s32 *, 0) = 0;
    M2C_FIELD(&enableChunkMessage, void **, 4) = NULL;
    pChunk = NULL;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void LoadLevel_Init() {
    s32 spC;
    s32 sp8;

    sp8 = 1;
    pLoadingScreenSystem = pResidentLSSystem;
    spC = 0;
    M2C_FIELD(*pResidentLSSystem, M2C_UNK (**)(void **, s32 *), 0x2C)(pResidentLSSystem, &sp8);
    ((UISystem *) pLoadingScreenSystem)->PushScreen("LoadLevelScreen");
    M2C_FIELD(gMK, f32 *, 0xB0) = 2.0f;
    M2C_FIELD(&gMKDefaults, s8 *, 0x1C) = 0;
    if ((s32) *gGMState.GetCurrState() != 4) {
        UIObject_MenuStringsInit(0x800);
    }
    loadState = 0;
    hPackage = -1;
}
#endif

void LoadLevel_FreeResources() {
    MKHeap *temp_r3_584;
    UIStringTable *temp_r30_570;
    void **temp_r31_580;

    temp_r30_570 = UIStringTable_SetCurrent(&residentLSStrings);
    if ((void **) pResidentLSSystem != NULL) {
        M2C_FIELD(*pResidentLSSystem, M2C_UNK (**)(void **), 0x24)(pResidentLSSystem);
        temp_r31_580 = pResidentLSSystem;
        temp_r3_584 = ((MKHeap *) (M2C_FIELD(*pResidentLSSystem, MKHeap *(**)(void **), 0xC)(pResidentLSSystem)))->Current();
        if (temp_r3_584 != NULL) {
            ((MKHeap *) (temp_r3_584->Current()))->Free(temp_r31_580, NULL, 0);
        } else {
            free(temp_r31_580);
        }
        pResidentLSSystem = NULL;
    }
    UIStringTable_SetCurrent(temp_r30_570);
    residentLSStrings.Deinit();
}

#if 0 // DRAFT: type mismatch
void LoadLevel_LoadResources() {
    s32 spC;
    s32 sp8;
    MCLoadCheckScreen *temp_r3_627;
    MKHeap *temp_r3_640;
    MKHeap *temp_r3_645;
    UIObject *var_r31_653;
    UIObjectDescriptor *var_r4_617;
    s32 temp_r31_644;
    void **temp_r3_675;

    var_r4_617 = &UIObjectDescriptor::list;
loop_3:
    temp_r3_627 = var_r4_617->unk0;
    if (temp_r3_627 == NULL) {
        var_r4_617->unk0 = (MCLoadCheckScreen *) LoadingScreen::descriptor;
        M2C_FIELD(LoadingScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_627 != LoadingScreen::descriptor) {
        var_r4_617 = (UIObjectDescriptor *) &temp_r3_627->unk10;
        goto loop_3;
    }
    residentLSStrings.Init(0xC0);
    temp_r3_640 = UIStringTable_SetCurrent(&residentLSStrings);
    temp_r31_644 = M2C_FIELD(UISystem::descriptor, s32 *, 8);
    temp_r3_645 = temp_r3_640->Current();
    if (temp_r3_645 != NULL) {
        var_r31_653 = ((MKHeap *) (temp_r3_645->Current()))->Alloc(temp_r31_644, NULL, 0);
    } else {
        var_r31_653 = malloc(temp_r31_644);
    }
    M2C_FIELD(UISystem::descriptor, M2C_UNK (**)(UIObject *, u8 *), 0xC)(var_r31_653, UISystem::descriptor);
    var_r31_653->unk8 = UISystem::descriptor;
    var_r31_653->Init(UISystem::descriptor);
    temp_r3_675 = ui_cast<UISystem *, UIObject *>(var_r31_653);
    pResidentLSSystem = temp_r3_675;
    if (((UIObject *) temp_r3_675)->Load("LoadLevel.ui", NULL) != 0) {
        M2C_FIELD(*pResidentLSSystem, M2C_UNK (**)(void **), 0x28)(pResidentLSSystem);
        M2C_FIELD(*pResidentLSSystem, M2C_UNK (**)(void **), 0x20)(pResidentLSSystem);
        sp8 = 1;
        spC = 0;
        M2C_FIELD(*pResidentLSSystem, M2C_UNK (**)(void **, s32 *), 0x2C)(pResidentLSSystem, &sp8);
    }
    UIStringTable_SetCurrent((UIStringTable *) temp_r3_640);
}
#endif

void LoadingScreen::OnExit() {
    M2C_FIELD(this, s8 *, 0xC8) = 1;
}

#if 0 // DRAFT: expression syntax error
void LoadingScreen::OnEnter() {
    UIScreen::OnEnter();
    this->unk18.unk40 |= 1;
    this->unk18.unk0 = 0.0f;
    this->unk18.unk4 = 0.0f;
    M2C_FIELD(this, f32 *, 0x20) = 0.0f;
    M2C_FIELD(this, f32 *, 0x24) = 1.0f;
    M2C_FIELD(this, s8 *, 0xC8) = 0;
    this->unkBC.unk8 = 0.0f;
    KDSound_SetMusicNotInterrupt(0U);
    KDSound_StopAll();
    Music_Stop(0.0f);
    Music_ClearDelayedPlayBuffer();
}
#endif

#if 0 // DRAFT: expression syntax error
void LoadingScreen::Draw(const RenderContext &arg0) {
    s32 temp_r6_775;
    u32 temp_r0_778;
    u32 temp_r6_777;

    temp_r6_775 = (s32) M2C_BITWISE(f32, this->unkBC.unk8);
    temp_r6_777 = (u32) temp_r6_775 >> 0x1FU;
    temp_r0_778 = (temp_r6_775 << 0x1E) - temp_r6_777;
    M2C_FIELD(pText, s8 **, 0x68) = Str_Printf("%s\n%s", M2C_FIELD(gpTranslation_StringArray, s32 *, 0xE8), pDots[((temp_r0_778 << 2) | (temp_r0_778 >> 0x1EU)) + temp_r6_777], temp_r6_777, "<p0><colour=0, 0, 0, 1>...</colour>");
    UIContainer::Draw(arg0);
    M2C_FIELD(pText, s8 **, 0x68) = NULL;
}
#endif

#if 0 // DRAFT: expression syntax error
void LoadingScreen::Update() {
    s32 sp8;
    f32 temp_f0_829;
    f32 temp_f0_880;
    f32 var_f3_828;
    f32 var_f3_879;
    u8 var_r31_850;
    void **temp_r3_867;

    UIScreen::Update();
    this->unkBC.unk8 = (4.0f * gUpdateTimeDelta) + M2C_BITWISE(f32, this->unkBC.unk8);
    if ((u8) M2C_FIELD(this, u8 *, 0xC8) != 0) {
        if (this->unk18.unk0 <= 0.0f) {
            UIScreen::OnExit();
        }
        var_f3_828 = 0.0f;
        temp_f0_829 = -((3.0f * gUpdateTimeDelta) - this->unk18.unk0);
        if (var_f3_828 > temp_f0_829) {

        } else {
            var_f3_828 = temp_f0_829;
        }
        M2C_FIELD(this, f32 *, 0x20) = var_f3_828;
        this->unk18.unk4 = var_f3_828;
        this->unk18.unk0 = var_f3_828;
        return;
    }
    if (LoadLevel_GetState() == 4) {
        if ((CutsceneSystem *) gb.unkC != NULL) {
            var_r31_850 = 0;
            if (((MKVector3 *) gb.unkC->unk78 != NULL) && (gb.unkC->unk24.GetState() == 1)) {
                var_r31_850 = 1;
            }
            if (var_r31_850 != 0) {
                gb.unkC->Update();
            } else {
                goto block_14;
            }
        } else {
block_14:
            temp_r3_867 = ui_cast<UISystem *, UIContainer *>(GetRoot());
            sp8 = 0xF;
            M2C_FIELD(*temp_r3_867, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
    }
    var_f3_879 = 1.0f;
    temp_f0_880 = (3.0f * gUpdateTimeDelta) + this->unk18.unk0;
    if (var_f3_879 < temp_f0_880) {

    } else {
        var_f3_879 = temp_f0_880;
    }
    M2C_FIELD(this, f32 *, 0x20) = var_f3_879;
    this->unk18.unk4 = var_f3_879;
    this->unk18.unk0 = var_f3_879;
}
#endif

void LoadingScreen::Resolve() {
    UIScreen::Resolve();
    pText = ui_cast<UIText *, UIObject *>(FindChild("Text"));
}

void LoadLevel_cpp::__sinit() {
    residentLSStrings.UIStringTable();
}
