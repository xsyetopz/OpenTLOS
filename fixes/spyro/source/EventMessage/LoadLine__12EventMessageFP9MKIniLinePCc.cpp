s32 EventMessage::LoadLine(MKIniLine *arg0, const char *arg1) {
    MKIniLine *var_r30_48;
    const char *temp_r3_59;

    if (arg0->IsField(arg1) != 0) {
        var_r30_48 = arg0->unkC->GetSubLine(arg0);
        while (var_r30_48 != NULL) {
            if (var_r30_48->IsField("ScriptCommand") != 0) {
                temp_r3_59 = (const char *) var_r30_48->GetString(0);
                if (*temp_r3_59 != 0) {
                    this->unk0 = (*(UIStringTable **) ChunkData::pCurrentEventStrings)->Add(temp_r3_59);
                }
                return 1;
            }
            var_r30_48 = var_r30_48->unkC->GetNextLine(var_r30_48);
        }
    }
    return 0;
}
