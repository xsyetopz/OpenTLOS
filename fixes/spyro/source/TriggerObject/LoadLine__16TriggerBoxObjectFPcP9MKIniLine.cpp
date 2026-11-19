extern "C" s32 stricmp(const char *, const char *);

s32 TriggerBoxObject::LoadLine(char *arg0, MKIniLine *arg1) {
    MKVector3 sp10;
    u8 sp8;
    MKIniLine *var_r30_786;

    if (arg1->IsField(arg0) != 0) {
        var_r30_786 = arg1->unkC->GetSubLine(arg1);
        while (var_r30_786 != NULL) {
            if (stricmp((const char *) var_r30_786->GetFieldName(), "pos") == 0) {
                sp10 = *(MKVector3 *) &this->unk10.unk30;
                var_r30_786->AsVector3(0, &sp10);
                this->unk10.unk30 = sp10.unk0;
                this->unk10.unk34 = sp10.unk4;
                this->unk10.unk38 = sp10.unk8;
                this->unk10.unk3C = 1.0f;
            } else if ((var_r30_786->LoadVector3("rot", (MKVector3 *) TriggerBoxObject::tempBoxRot, 0) == 0) && (var_r30_786->LoadVector3("scale", (MKVector3 *) &this->unk70, 0) == 0) && (var_r30_786->LoadBool("bUseTrigger", (bool *) &sp8, 0) != 0) && (sp8 == 0)) {
                this->unk50 &= 0xFFFFFFFE;
            }
            var_r30_786 = var_r30_786->unkC->GetNextLine(var_r30_786);
        }
        return 1;
    }
    return 0;
}
