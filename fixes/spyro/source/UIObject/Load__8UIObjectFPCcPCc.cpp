s32 UIObject::Load(const char *arg0, const char *arg1) {
    MKIni sp8;
    MKIniLine *temp_r3_260;
    MKIniLine *var_r31_264;
    s32 temp_r31_255;

    if (arg0 == NULL) {
        return 0;
    }
    MKHeap::ActivateTempMemOverride();
    temp_r31_255 = sp8.Init(arg0, 1, arg1);
    MKHeap::DeactivateTempMemOverride();
    if ((u8) temp_r31_255 != 0) {
        temp_r3_260 = sp8.GetFirstLine();
        var_r31_264 = temp_r3_260->unkC->GetSubLine(temp_r3_260);
        while (var_r31_264 != NULL) {
            LoadLine((UIDataLine *) var_r31_264);
            var_r31_264 = var_r31_264->unkC->GetNextLine(var_r31_264);
        }
        sp8.Deinit();
        return 1;
    }
    return 0;
}
