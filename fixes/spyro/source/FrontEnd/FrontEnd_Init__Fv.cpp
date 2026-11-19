void FrontEnd_Init() {
    s32 sp8[2];
    MCLoadCheckScreen *temp_r3_666;
    MCLoadCheckScreen *temp_r3_684;
    MCLoadCheckScreen *temp_r3_702;
    MCLoadCheckScreen *temp_r3_720;
    MCLoadCheckScreen *temp_r3_738;
    MCLoadCheckScreen *temp_r3_756;
    MCLoadCheckScreen *temp_r3_774;
    MCLoadCheckScreen *temp_r3_792;
    MCLoadCheckScreen *temp_r3_810;
    UIObject *var_r29_633;
    UIObjectDescriptor *var_r4_659;
    UIObjectDescriptor *var_r4_676;
    UIObjectDescriptor *var_r4_694;
    UIObjectDescriptor *var_r4_712;
    UIObjectDescriptor *var_r4_730;
    UIObjectDescriptor *var_r4_748;
    UIObjectDescriptor *var_r4_766;
    UIObjectDescriptor *var_r4_784;
    UIObjectDescriptor *var_r4_802;
    UIStringTable *temp_r30_619;
    s32 temp_r29_624;
    s32 var_r31_582;

    if (*(s32 *) gGMState.GetLastState() != 4) {
        var_r31_582 = -1;
        if (*(s32 *) gGMState.GetCurrState() != 4) {
            gGMState.unk38.HeapMarkPush();
            /* GameLanguage_GetCode is declared void, but its asm tail-calls Translation_GetLanguageCode and the caller reads r3. */
            var_r31_582 = MKPackage_QLoad((const char *) Str_Printf("frontend%s", ((const char *(*)(int)) GameLanguage_GetCode)(-1)), 0);
loop_4:
            if (MKPackage_QIsLoaded(var_r31_582, NULL, NULL) == 0) {
                MKPackage_Update();
                goto loop_4;
            }
        }
        frontEndStrings.Init(0x1000);
        temp_r30_619 = UIStringTable_SetCurrent(&frontEndStrings);
        Hud_InitModule();
        Autosave_Reset();
        temp_r29_624 = M2C_FIELD(NoisySystem::descriptor, s32 *, 8);
        if (MKHeap::Current() != NULL) {
            var_r29_633 = (UIObject *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r29_624, NULL, 0));
        } else {
            var_r29_633 = (UIObject *) malloc(temp_r29_624);
        }
        M2C_FIELD(NoisySystem::descriptor, M2C_UNK (**)(UIObject *, u8 *), 0xC)(var_r29_633, NoisySystem::descriptor);
        var_r29_633->unk8 = NoisySystem::descriptor;
        /* Slot 8 takes only the object in r3; the asm sets no second argument. */
        M2C_FIELD(*(void ***) var_r29_633, M2C_UNK (**)(void **), 0x8)((void **) var_r29_633);
        pFrontEndSystem = (void **) (checked_cast<NoisySystem *, UIObject>(var_r29_633));
        var_r4_659 = &UIObjectDescriptor::list;
loop_11:
        temp_r3_666 = var_r4_659->unk0;
        if (temp_r3_666 == NULL) {
            var_r4_659->unk0 = (MCLoadCheckScreen *) MCLoadCheckScreen::descriptor;
            M2C_FIELD(MCLoadCheckScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_666 != (MCLoadCheckScreen *) MCLoadCheckScreen::descriptor) {
            var_r4_659 = (UIObjectDescriptor *) &temp_r3_666->unk10;
            goto loop_11;
        }
        var_r4_676 = &UIObjectDescriptor::list;
loop_16:
        temp_r3_684 = var_r4_676->unk0;
        if (temp_r3_684 == NULL) {
            var_r4_676->unk0 = (MCLoadCheckScreen *) CopyrightScreen::descriptor;
            M2C_FIELD(CopyrightScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_684 != (MCLoadCheckScreen *) CopyrightScreen::descriptor) {
            var_r4_676 = (UIObjectDescriptor *) &temp_r3_684->unk10;
            goto loop_16;
        }
        var_r4_694 = &UIObjectDescriptor::list;
loop_21:
        temp_r3_702 = var_r4_694->unk0;
        if (temp_r3_702 == NULL) {
            var_r4_694->unk0 = (MCLoadCheckScreen *) TitleScreen::descriptor;
            M2C_FIELD(TitleScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_702 != (MCLoadCheckScreen *) TitleScreen::descriptor) {
            var_r4_694 = (UIObjectDescriptor *) &temp_r3_702->unk10;
            goto loop_21;
        }
        var_r4_712 = &UIObjectDescriptor::list;
loop_26:
        temp_r3_720 = var_r4_712->unk0;
        if (temp_r3_720 == NULL) {
            var_r4_712->unk0 = (MCLoadCheckScreen *) MainMenuScreen::descriptor;
            M2C_FIELD(MainMenuScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_720 != (MCLoadCheckScreen *) MainMenuScreen::descriptor) {
            var_r4_712 = (UIObjectDescriptor *) &temp_r3_720->unk10;
            goto loop_26;
        }
        var_r4_730 = &UIObjectDescriptor::list;
loop_31:
        temp_r3_738 = var_r4_730->unk0;
        if (temp_r3_738 == NULL) {
            var_r4_730->unk0 = (MCLoadCheckScreen *) LevelSelectButtons::descriptor;
            M2C_FIELD(LevelSelectButtons::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_738 != (MCLoadCheckScreen *) LevelSelectButtons::descriptor) {
            var_r4_730 = (UIObjectDescriptor *) &temp_r3_738->unk10;
            goto loop_31;
        }
        var_r4_748 = &UIObjectDescriptor::list;
loop_36:
        temp_r3_756 = var_r4_748->unk0;
        if (temp_r3_756 == NULL) {
            var_r4_748->unk0 = (MCLoadCheckScreen *) LevelSelectScreen::descriptor;
            M2C_FIELD(LevelSelectScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_756 != (MCLoadCheckScreen *) LevelSelectScreen::descriptor) {
            var_r4_748 = (UIObjectDescriptor *) &temp_r3_756->unk10;
            goto loop_36;
        }
        var_r4_766 = &UIObjectDescriptor::list;
loop_41:
        temp_r3_774 = var_r4_766->unk0;
        if (temp_r3_774 == NULL) {
            var_r4_766->unk0 = (MCLoadCheckScreen *) LanguageSelectScreen::descriptor;
            M2C_FIELD(LanguageSelectScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_774 != (MCLoadCheckScreen *) LanguageSelectScreen::descriptor) {
            var_r4_766 = (UIObjectDescriptor *) &temp_r3_774->unk10;
            goto loop_41;
        }
        var_r4_784 = &UIObjectDescriptor::list;
loop_46:
        temp_r3_792 = var_r4_784->unk0;
        if (temp_r3_792 == NULL) {
            var_r4_784->unk0 = (MCLoadCheckScreen *) OptionsScreen::descriptor;
            M2C_FIELD(OptionsScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_792 != (MCLoadCheckScreen *) OptionsScreen::descriptor) {
            var_r4_784 = (UIObjectDescriptor *) &temp_r3_792->unk10;
            goto loop_46;
        }
        var_r4_802 = &UIObjectDescriptor::list;
loop_51:
        temp_r3_810 = var_r4_802->unk0;
        if (temp_r3_810 == NULL) {
            var_r4_802->unk0 = (MCLoadCheckScreen *) CreditsScreen::descriptor;
            M2C_FIELD(CreditsScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_810 != (MCLoadCheckScreen *) CreditsScreen::descriptor) {
            var_r4_802 = (UIObjectDescriptor *) &temp_r3_810->unk10;
            goto loop_51;
        }
        KDSound_Init("mainmenu");
        if (((UIObject *) pFrontEndSystem)->Load("frontend.ui", NULL) != 0) {
            M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **), 0x28)(pFrontEndSystem);
            M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **), 0x20)(pFrontEndSystem);
            sp8[0] = 1;
            sp8[1] = 0;
            M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **, s32 *), 0x2C)(pFrontEndSystem, sp8);
            if (((s32) M2C_FIELD(&gb, s32 *, 0x338) != 0) && ((s32) menuLoadingState == 0)) {
                menuLoadingState = 2;
            }
            switch ((s32) menuLoadingState) {
            case 0:
                ((UISystem *) pFrontEndSystem)->PushScreen("MainMenu");
                ((UISystem *) pFrontEndSystem)->PushScreen("Title");
                ((UISystem *) pFrontEndSystem)->PushScreen("VideoMaker");
                ((UISystem *) pFrontEndSystem)->PushScreen("Developer");
                ((UISystem *) pFrontEndSystem)->PushScreen("Publisher");
                ((UISystem *) pFrontEndSystem)->PushScreen("Copyright");
                ((UISystem *) pFrontEndSystem)->PushScreen("HealthSafety");
                break;
            case 1:
                ((GameData *) GameData::gameData)->ClearData();
                ((UISystem *) pFrontEndSystem)->PushScreen("LevelScreen");
                break;
            case 2:
                ((UISystem *) pFrontEndSystem)->PushScreen("Title");
                ((UISystem *) pFrontEndSystem)->PushScreen("MainMenu");
                break;
            case 3:
                ((UISystem *) pFrontEndSystem)->PushScreen("Title");
                ((UISystem *) pFrontEndSystem)->PushScreen("MainMenu");
                ((UISystem *) pFrontEndSystem)->PushScreen("ExtrasScreen");
                break;
            default:
                ((UISystem *) pFrontEndSystem)->PushScreen("Title");
                break;
            }
        }
        menuLoadingState = 4;
        if (var_r31_582 >= 0) {
            MKPackage_QFree(var_r31_582);
        }
        UIStringTable_SetCurrent(temp_r30_619);
        startTime = 2.0f;
        bGoToNewGame = 0;
        if ((s32 *) M2C_FIELD(&gb, s32 **, 0x354) != NULL) {
            UIControls_SetDevice((MKInputDevices) *M2C_FIELD(&gb, s32 **, 0x354));
        }
    }
}
