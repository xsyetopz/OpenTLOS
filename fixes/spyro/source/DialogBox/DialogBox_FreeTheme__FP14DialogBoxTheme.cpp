void DialogBox_FreeTheme(DialogBoxTheme *arg0) {
    MKFont *temp_r3_584;
    MKMaterial *temp_r3_589;
    MKMaterial *temp_r3_594;
    MKMaterial *temp_r3_602;
    s32 var_r30_599;
    s32 var_r31_600;

    temp_r3_584 = arg0->unk1C;
    if (temp_r3_584 != NULL) {
        temp_r3_584->Destroy();
    }
    temp_r3_589 = arg0->unk10;
    if (temp_r3_589 != NULL) {
        MKMaterial_Destroy(temp_r3_589);
    }
    temp_r3_594 = arg0->unkC;
    if (temp_r3_594 != NULL) {
        MKMaterial_Destroy(temp_r3_594);
    }
    var_r30_599 = 2;
    var_r31_600 = 8;
    do {
        temp_r3_602 = *(MKMaterial **) ((s8 *) arg0 + var_r31_600);
        if (temp_r3_602 != NULL) {
            MKMaterial_Destroy(temp_r3_602);
        }
        var_r30_599 -= 1;
        var_r31_600 -= 4;
    } while (var_r30_599 >= 0);
    memset(arg0, 0, 0x20U);
}
