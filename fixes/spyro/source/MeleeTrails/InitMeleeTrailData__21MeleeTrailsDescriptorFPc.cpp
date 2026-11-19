void MeleeTrailsDescriptor::InitMeleeTrailData(char *arg0) {
    MKIni spC;
    const char *sp8;
    u8 *temp_r27;
    u8 *temp_r5;
    MKIniLine *var_r26;
    MKIniLine *var_r30;

    spC.Init((const char *) Str_Printf("%s.ini", arg0), 0, NULL);
    var_r30 = spC.GetFirstLine();
    while (var_r30 != NULL) {
        if (var_r30->IsSection("Anim") != 0) {
            var_r26 = var_r30->unkC->GetSubLine(var_r30);
            temp_r5 = M2C_FIELD(this, u8 **, 0xE4) - 4;
            M2C_FIELD(this, u8 **, 0xE4) = temp_r5;
            temp_r27 = M2C_FIELD(temp_r5, u8 **, 0);
            M2C_FIELD(temp_r27, u8 **, 0x10) = NULL;
            M2C_FIELD(temp_r27, u8 **, 0x14) = NULL;
            temp_r27[0xC] = 0;
            while (var_r26 != NULL) {
                if (var_r26->IsField("Name") != 0) {
                    var_r26->AsString(0, (const char **) (temp_r27 + 0x10));
                }
                if (var_r26->IsField("EventName") != 0) {
                    var_r26->AsString(0, (const char **) (temp_r27 + 0x14));
                }
                var_r26->LoadFloat("ScrollSpeed", (f32 *) (temp_r27 + 4), 0);
                var_r26->LoadFloat("TrailLife", (f32 *) (temp_r27 + 8), 0);
                if (var_r26->IsField("Subobject") != 0) {
                    var_r26->AsString(0, &sp8);
                    M2C_FIELD(temp_r27, s32 *, 0) = MKModel_GetSubObjectIndex(M2C_FIELD(this, MKModel **, 0x2C), (SubObjectType) 0, sp8);
                }
                var_r26->LoadBool("Follow", (bool *) (temp_r27 + 0xC), 0);
                var_r26 = var_r26->unkC->GetNextLine(var_r26);
            }
        }
        var_r30 = var_r30->unkC->GetNextLine(var_r30);
    }
    spC.Deinit();
}
