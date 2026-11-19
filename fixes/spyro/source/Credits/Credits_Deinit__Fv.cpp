void Credits_Deinit() {
    DialogBoxContext *temp_r3_1128;
    MKIni *temp_r30_1134;
    s32 temp_r0_1119;
    s32 var_r29_1112;
    s32 var_r31_1114;

    if ((MKIni *) pCredits != NULL) {
        var_r29_1112 = 0;
        DialogBox_bAllowOverCutscene = 0;
        var_r31_1114 = 0;
loop_3:
        if (var_r29_1112 < 0xA) {
            temp_r3_1128 = M2C_FIELD(pCredits, DialogBoxContext **, var_r31_1114 + 0xBC);
            if (temp_r3_1128 != NULL) {
                DialogBox_ReleaseContext(temp_r3_1128);
                temp_r0_1119 = var_r31_1114 + 0xBC;
                var_r29_1112 += 1;
                var_r31_1114 += 4;
                M2C_FIELD(pCredits, DialogBoxContext **, temp_r0_1119) = NULL;
                goto loop_3;
            }
        }
        pCredits->Deinit();
        temp_r30_1134 = pCredits;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r30_1134, NULL, 0);
        } else {
            free(temp_r30_1134);
        }
        pCredits = NULL;
    }
}
