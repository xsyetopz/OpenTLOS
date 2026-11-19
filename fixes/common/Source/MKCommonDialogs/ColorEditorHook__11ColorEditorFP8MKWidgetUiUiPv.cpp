s32 ColorEditor::ColorEditorHook(MKWidget *arg0, unsigned int arg1, unsigned int arg2, void *arg3) {
    MKWidget *temp_r3_813;
    u16 temp_r6_804;
    u32 temp_r3_825;

    switch ((u32) arg0) {
    case 0x3E8:
        M2C_STRUCT_COPY(&gColorEditor, (void *) arg1, 16);
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x1C), 0x64U, arg2);
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x20), 0x64U, arg2 + 4);
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x24), 0x64U, arg2 + 8);
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x28), 0x64U, arg2 + 0xC);
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x18), 0x64U, arg2);
        return 0;
    case 0x39:
        temp_r6_804 = M2C_FIELD(arg1, u16 *, 4);
        if ((temp_r6_804 == 6) && ((u32) M2C_FIELD(arg1, u32 *, 0) == (u32) M2C_FIELD(arg2, u32 *, 0x2C))) {
            MKWidget_Show((MKWidget *) this, 0);
            temp_r3_813 = M2C_FIELD(arg2, MKWidget **, 0x30);
            if (temp_r3_813 != NULL) {
                MKWidget_SendMessage(temp_r3_813, 0x64U, arg2);
                MKWidget_SetFocus(M2C_FIELD(arg2, MKWidget **, 0x30));
            }
        } else if (temp_r6_804 == 1) {
            temp_r3_825 = M2C_FIELD(arg1, u32 *, 0);
            if (temp_r3_825 == (u32) M2C_FIELD(arg2, MKWidget **, 0x1C)) {
                M2C_FIELD(arg2, f32 *, 0) = (f32) *M2C_FIELD(arg1, f32 **, 8);
                MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x18), 0x64U, arg2);
            } else if (temp_r3_825 == (u32) M2C_FIELD(arg2, MKWidget **, 0x20)) {
                M2C_FIELD(arg2, f32 *, 4) = (f32) *M2C_FIELD(arg1, f32 **, 8);
                MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x18), 0x64U, arg2);
            } else if (temp_r3_825 == (u32) M2C_FIELD(arg2, MKWidget **, 0x24)) {
                M2C_FIELD(arg2, f32 *, 8) = (f32) *M2C_FIELD(arg1, f32 **, 8);
                MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x18), 0x64U, arg2);
            } else if (temp_r3_825 == (u32) M2C_FIELD(arg2, MKWidget **, 0x28)) {
                M2C_FIELD(arg2, f32 *, 0xC) = (f32) *M2C_FIELD(arg1, f32 **, 8);
                MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0x18), 0x64U, arg2);
            }
        }
        /* fallthrough */
    default:
        return 1;
    }
}
