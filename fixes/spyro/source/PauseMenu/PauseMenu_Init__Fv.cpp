void PauseMenu_Init() {
    MCLoadCheckScreen *temp_r3_554;
    MCLoadCheckScreen *temp_r3_572;
    MCLoadCheckScreen *temp_r3_590;
    MCLoadCheckScreen *temp_r3_608;
    MCLoadCheckScreen *temp_r3_626;
    MCLoadCheckScreen *temp_r3_644;
    UIObject *var_r30_521;
    UIObjectDescriptor *var_r4_547;
    UIObjectDescriptor *var_r4_564;
    UIObjectDescriptor *var_r4_582;
    UIObjectDescriptor *var_r4_600;
    UIObjectDescriptor *var_r4_618;
    UIObjectDescriptor *var_r4_636;
    UIStringTable *temp_r31_510;
    s32 temp_r30_512;

    strings.Init(0x1000);
    temp_r31_510 = UIStringTable_SetCurrent(&strings);
    temp_r30_512 = M2C_FIELD(NoisySystem::descriptor, s32 *, 8);
    if (MKHeap::Current() != NULL) {
        var_r30_521 = (UIObject *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_512, NULL, 0));
    } else {
        var_r30_521 = malloc(temp_r30_512);
    }
    M2C_FIELD(NoisySystem::descriptor, void (**)(UIObject *), 0xC)(var_r30_521);
    var_r30_521->unk8 = NoisySystem::descriptor;
    var_r30_521->Init();
    pSystem = checked_cast<NoisySystem *, UIObject>(var_r30_521);
    var_r4_547 = &UIObjectDescriptor::list;
loop_6:
    temp_r3_554 = var_r4_547->unk0;
    if (temp_r3_554 == NULL) {
        var_r4_547->unk0 = (MCLoadCheckScreen *) PauseMainScreen::descriptor;
        M2C_FIELD(PauseMainScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_554 != (MCLoadCheckScreen *) PauseMainScreen::descriptor) {
        var_r4_547 = (UIObjectDescriptor *) ((s8 *) temp_r3_554 + 0x10);
        goto loop_6;
    }
    var_r4_564 = &UIObjectDescriptor::list;
loop_11:
    temp_r3_572 = var_r4_564->unk0;
    if (temp_r3_572 == NULL) {
        var_r4_564->unk0 = (MCLoadCheckScreen *) ExitConfirmScreen::descriptor;
        M2C_FIELD(ExitConfirmScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_572 != (MCLoadCheckScreen *) ExitConfirmScreen::descriptor) {
        var_r4_564 = (UIObjectDescriptor *) ((s8 *) temp_r3_572 + 0x10);
        goto loop_11;
    }
    var_r4_582 = &UIObjectDescriptor::list;
loop_16:
    temp_r3_590 = var_r4_582->unk0;
    if (temp_r3_590 == NULL) {
        var_r4_582->unk0 = (MCLoadCheckScreen *) LevelSelectButtons::descriptor;
        M2C_FIELD(LevelSelectButtons::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_590 != (MCLoadCheckScreen *) LevelSelectButtons::descriptor) {
        var_r4_582 = (UIObjectDescriptor *) ((s8 *) temp_r3_590 + 0x10);
        goto loop_16;
    }
    var_r4_600 = &UIObjectDescriptor::list;
loop_21:
    temp_r3_608 = var_r4_600->unk0;
    if (temp_r3_608 == NULL) {
        var_r4_600->unk0 = (MCLoadCheckScreen *) LevelSelectScreen::descriptor;
        M2C_FIELD(LevelSelectScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_608 != (MCLoadCheckScreen *) LevelSelectScreen::descriptor) {
        var_r4_600 = (UIObjectDescriptor *) ((s8 *) temp_r3_608 + 0x10);
        goto loop_21;
    }
    var_r4_618 = &UIObjectDescriptor::list;
loop_26:
    temp_r3_626 = var_r4_618->unk0;
    if (temp_r3_626 == NULL) {
        var_r4_618->unk0 = (MCLoadCheckScreen *) OptionsScreen::descriptor;
        M2C_FIELD(OptionsScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_626 != (MCLoadCheckScreen *) OptionsScreen::descriptor) {
        var_r4_618 = (UIObjectDescriptor *) ((s8 *) temp_r3_626 + 0x10);
        goto loop_26;
    }
    var_r4_636 = &UIObjectDescriptor::list;
loop_31:
    temp_r3_644 = var_r4_636->unk0;
    if (temp_r3_644 == NULL) {
        var_r4_636->unk0 = (MCLoadCheckScreen *) LevelUpScreen::descriptor;
        M2C_FIELD(LevelUpScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_644 != (MCLoadCheckScreen *) LevelUpScreen::descriptor) {
        var_r4_636 = (UIObjectDescriptor *) ((s8 *) temp_r3_644 + 0x10);
        goto loop_31;
    }
    UITools_RegisterAll();
    if (((UIObject *) pSystem)->Load("pause.ui", NULL) != 0) {
        pSystem->Resolve();
        pSystem->LoadResources();
    }
    UIStringTable_SetCurrent(temp_r31_510);
    M2C_FIELD(&pBackground, MKResource **, 0) = MKMaterial_Create("ui_pause_bg1");
    M2C_FIELD(&pBackground, MKResource **, 4) = MKMaterial_Create("ui_pause_bg2");
}
