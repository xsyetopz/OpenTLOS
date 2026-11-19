void MainMenuScreen::OnEnter() {
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    UIObject *obj;
    s32 var_r29;
    s32 var_r30;
    s32 var_extras_a;
    s32 var_extras_b;

    UIScreen::OnEnter();
    KDSound_SetMusicNotInterrupt(false);
    M2C_FIELD(&gb, s8 *, 9) = 1;
    if (*(s32 *) selectedIndex < 0) {
        *(s32 *) selectedIndex = M2C_FIELD(&gb, u8 *, 0x382) == 0;
    }
    this->unkD8 = ui_cast<UIButtonGroup *, UIObject *>(FindChild("MainMenuButtons"));
    sp38 = 1;
    sp3C = *(s32 *) selectedIndex;
    this->unkD8->Message((UIMessage *) &sp38);
    var_r29 = 5;
    if (M2C_FIELD(&gb, u8 *, 0x382) != 0) {
        var_r29 = 4;
    }
    obj = this->unkD8->GetChild(0);
    sp30 = var_r29;
    sp34 = 0;
    obj->Message((UIMessage *) &sp30);
    var_r30 = 3;
    if (M2C_FIELD(&gb, u8 *, 0x382) != 0) {
        var_r30 = 2;
    }
    obj = this->unkD8->GetChild(0);
    sp28 = var_r30;
    sp2C = 0;
    obj->Message((UIMessage *) &sp28);
    this->unkC8 = 0;
    this->unkD4 = 0.0f;
    obj = this->unkD8->FindChild("LevelSelect");
    if (obj != NULL) {
        sp20 = 5;
        sp24 = 0;
        obj->Message((UIMessage *) &sp20);
        sp18 = 3;
        sp1C = 0;
        obj->Message((UIMessage *) &sp18);
    }
    obj = this->unkD8->FindChild("Extras");
    if (obj != NULL) {
        var_extras_a = 5;
        if (((u8) GameData::gameData[0x18A] >> 6U) & 1) {
            var_extras_a = 4;
        }
        sp10 = var_extras_a;
        sp14 = 0;
        obj->Message((UIMessage *) &sp10);
        var_extras_b = 3;
        if (((u8) GameData::gameData[0x18A] >> 6U) & 1) {
            var_extras_b = 2;
        }
        sp8 = var_extras_b;
        spC = 0;
        obj->Message((UIMessage *) &sp8);
    }
    FrontEnd_PlayBackgroundVideo(true);
}
