extern "C" s32 strcmpi(s8 *, const char *);
void KDSynkerPlayer3::ParseHeader() {
    MKIniLine *temp_r3_230;
    MKIniLine *var_r30_236;

    temp_r3_230 = this->unk54->GotoLine("GENERAL", NULL);
    if (temp_r3_230 != NULL) {
        var_r30_236 = temp_r3_230->unkC->GetSubLine(temp_r3_230);
loop_5:
        if (var_r30_236 == NULL) {

        } else {
            if (strcmpi(var_r30_236->GetFieldName(), "Version") == 0) {
                var_r30_236->GetInt(0);
                return;
            }
            var_r30_236 = var_r30_236->unkC->GetNextLine(var_r30_236);
            goto loop_5;
        }
    }
}
