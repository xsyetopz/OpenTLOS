void Credits_Init(MKProp *arg0) {
    MKIni *var_r3_1176;

    if (arg0 == NULL) {
        MKHeap::ActivateTempMemOverride();
    }
    if (MKHeap::Current() != NULL) {
        var_r3_1176 = (MKIni *) (((MKHeap *) (MKHeap::Current()))->Alloc(0xF4, NULL, 0));
    } else {
        var_r3_1176 = malloc(0xF4);
    }
    pCredits = var_r3_1176;
    memset(var_r3_1176, 0, 0xF4U);
    M2C_FIELD(pCredits, f32 *, 0xAC) = 1.0f;
    M2C_FIELD(pCredits, f32 *, 0xB0) = 1.0f;
    M2C_FIELD(pCredits, f32 *, 0xB4) = 1.0f;
    M2C_FIELD(pCredits, f32 *, 0xB8) = 1.0f;
    pCredits->Init("credits.ini", 0, (const char *) platformCode);
    if ((s32) gDisplay == 0) {
        ((MKIni *) ((s8 *) pCredits + 0x50))->Init("credits-pal.ini", 0, (const char *) platformCode);
    }
    M2C_FIELD(pCredits, MKProp **, 0xA4) = arg0;
    if (*(s32 *) MKHeap::tempMemOverride > 0) {
        MKHeap::DeactivateTempMemOverride();
    }
    DialogBox_bAllowOverCutscene = 1;
}
