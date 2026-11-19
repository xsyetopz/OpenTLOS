extern "C" s32 stricmp(const char *, const char *);

void MKPropDescriptor::ParseGMSection(MKIni *arg0, MKIniLine *arg1) {
    MKIniLine *temp_r3_58;
    MKIniLine *var_r31_54;

    var_r31_54 = arg1;
loop_1:
    temp_r3_58 = arg0->GetNextLine(var_r31_54);
    var_r31_54 = temp_r3_58;
    if ((var_r31_54 != NULL) && (temp_r3_58->GetFieldName() != NULL)) {
        if (stricmp((const char *) var_r31_54->GetFieldName(), "alias") != 0) {
            this->LoadLine(var_r31_54);
        }
    }
    if ((var_r31_54 != NULL) && (var_r31_54->GetSectionName() == NULL)) {
        goto loop_1;
    }
}
