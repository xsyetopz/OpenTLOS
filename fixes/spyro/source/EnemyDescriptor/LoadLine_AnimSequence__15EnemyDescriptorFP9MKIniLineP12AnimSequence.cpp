void EnemyDescriptor::LoadLine_AnimSequence(MKIniLine *arg0, AnimSequence *arg1) {
    MKIniLine *var_r29_1030;
    const char *temp_r3_1069;
    const char *temp_r3_1096;
    const char *temp_r3_1123;
    void *var_r3_1079;
    void *var_r3_1106;
    void *var_r3_1133;

    var_r29_1030 = arg0;
    arg1->unk68 = 0;
    while (var_r29_1030 != NULL) {
        if ((var_r29_1030->LoadInt("iVariation", (int *) &arg1->unk68, 0) == 0) && (var_r29_1030->LoadFloat("fWeighting", &arg1->unk60, 0) == 0) && (var_r29_1030->LoadFloat("fAnimSpeed", &arg1->unk64, 0) == 0)) {
            if (var_r29_1030->IsField("pEnter") != 0) {
                temp_r3_1069 = (const char *) (var_r29_1030->GetString(0));
                if (((MKAnimScript *) this->unk34)->Exists(temp_r3_1069) != 0) {
                    var_r3_1079 = ((MKAnimScript *) this->unk34)->GetAnim(temp_r3_1069);
                } else {
                    var_r3_1079 = NULL;
                }
                arg1->unk0 = (u32) var_r3_1079;
            } else if (var_r29_1030->IsField("pLoop") != 0) {
                temp_r3_1096 = (const char *) (var_r29_1030->GetString(0));
                if (((MKAnimScript *) this->unk34)->Exists(temp_r3_1096) != 0) {
                    var_r3_1106 = ((MKAnimScript *) this->unk34)->GetAnim(temp_r3_1096);
                } else {
                    var_r3_1106 = NULL;
                }
                arg1->unk20 = (u32) var_r3_1106;
            } else if (var_r29_1030->IsField("pExit") != 0) {
                temp_r3_1123 = (const char *) (var_r29_1030->GetString(0));
                if (((MKAnimScript *) this->unk34)->Exists(temp_r3_1123) != 0) {
                    var_r3_1133 = ((MKAnimScript *) this->unk34)->GetAnim(temp_r3_1123);
                } else {
                    var_r3_1133 = NULL;
                }
                arg1->unk40 = (u32) var_r3_1133;
            }
        }
        var_r29_1030 = var_r29_1030->unkC->GetNextLine(var_r29_1030);
    }
}
