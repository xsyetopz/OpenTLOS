s32 MaterialEditor::MaterialEditorHook(MKWidget *arg0, unsigned int arg1, unsigned int arg2, void *arg3) {
    switch ((u32) arg0) {
    case 0x3E8:
        M2C_FIELD(arg2, MKMaterial **, 0) = (MKMaterial *) arg1;
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 8), 0x46U, (u32) M2C_FIELD(arg2, MKMaterial **, 0));
        MKWidget_SendMessage(M2C_FIELD(arg2, MKWidget **, 0xC), 0x64U, (u32) ((u8 *) M2C_FIELD(arg2, MKMaterial **, 0)->unk24 + 0x30));
        break;
    case 0x39:
        if (((u32) M2C_FIELD(arg1, u32 *, 0) == (u32) M2C_FIELD(arg2, MKWidget **, 0xC)) && ((u16) M2C_FIELD(arg1, u16 *, 4) == 1)) {
            MKMaterial_SetColor(M2C_FIELD(arg2, MKMaterial **, 0), *(M2C_FIELD(arg1, MKVector4 **, 8)));
        }
        break;
    }
    return 1;
}
