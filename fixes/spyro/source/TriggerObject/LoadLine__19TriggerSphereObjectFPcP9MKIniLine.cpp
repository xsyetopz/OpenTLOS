extern "C" s32 stricmp(const char *, const char *);

s32 TriggerSphereObject::LoadLine(char *arg0, MKIniLine *arg1) {
    MKVector3 sp10;
    f32 spC;
    u8 sp9;
    u8 sp8;
    MKIniLine *var_r29_918;
    u8 var_r30_991;

    if (arg1->IsField(arg0) != 0) {
        var_r29_918 = arg1->unkC->GetSubLine(arg1);
        while (var_r29_918 != NULL) {
            spC = 0.0f;
            sp9 = 1;
            if (var_r29_918->LoadFloat("radius", &spC, 0) != 0) {
                if (spC > 0.0f) {
                    this->unk80 = spC;
                }
            } else if (var_r29_918->LoadBool("bUseTrigger", (bool *) &sp9, 0) != 0) {
                if (sp9 == 0) {
                    this->unk50 &= 0xFFFFFFFE;
                }
            } else if (stricmp((const char *) var_r29_918->GetFieldName(), "pos") == 0) {
                sp10 = *(MKVector3 *) &this->unk10.unk30;
                var_r29_918->AsVector3(0, &sp10);
                this->unk10.unk30 = sp10.unk0;
                this->unk10.unk34 = sp10.unk4;
                this->unk10.unk38 = sp10.unk8;
                this->unk10.unk3C = 1.0f;
            }
            var_r29_918 = var_r29_918->unkC->GetNextLine(var_r29_918);
        }
        return 1;
    }
    var_r30_991 = 0;
    sp8 = 0;
    if ((TriggerObject::LoadLine(arg1) != 0) || (arg1->LoadFloat("radius", &this->unk80, 0) != 0) || (arg1->LoadBool("bUseTrigger", (bool *) &sp8, 0) != 0)) {
        var_r30_991 = 1;
    }
    if (var_r30_991 != 0) {
        if (sp8 == 0) {
            this->unk50 &= 1;
        }
        return 1;
    }
    return 0;
}
