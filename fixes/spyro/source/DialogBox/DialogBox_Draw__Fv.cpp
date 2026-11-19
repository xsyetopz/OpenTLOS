void DialogBox_DrawBackground(DialogBoxContext *);
void DialogBox_DrawBorder(DialogBoxContext *);
void DialogBox_DrawTab(DialogBoxContext *);
void DialogBox_DrawText(DialogBoxContext *);

void DialogBox_Draw() {
    DialogBoxContext *temp_r27_35;
    s32 var_r28_31;
    s32 var_r31_33;

    if ((u8) bDrawnThisFrame == 0) {
        if ((u8) Dialog_bEnableDraw == 0) {
            return;
        }
        bDrawnThisFrame = 1;
        if ((s32) contextCount != 0) {
            var_r28_31 = 0;
            var_r31_33 = 0;
            do {
                temp_r27_35 = (DialogBoxContext *) ((s8 *) &contexts + var_r31_33);
                if ((temp_r27_35->unk30 != NULL) && ((u8) temp_r27_35->unkAC == (u8) M2C_FIELD(&gb, u8 *, 0x395))) {
                    if (temp_r27_35->unk0 != 0) {
                        DialogBox_DrawBackground(temp_r27_35);
                        DialogBox_DrawBorder(temp_r27_35);
                        DialogBox_DrawTab(temp_r27_35);
                    }
                    DialogBox_DrawText(temp_r27_35);
                }
                var_r28_31 += 1;
                var_r31_33 += 0xB0;
            } while (var_r28_31 < 0xA);
        }
    }
}
