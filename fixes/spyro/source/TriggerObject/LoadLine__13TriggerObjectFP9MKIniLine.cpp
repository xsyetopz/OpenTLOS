extern "C" s32 stricmp(const char *, const char *);

u8 TriggerObject::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;

    if (stricmp((const char *) arg0->GetFieldName(), "pos") == 0) {
        sp8 = *(MKVector3 *) &this->unk10.unk30;
        arg0->AsVector3(0, &sp8);
        this->unk10.unk30 = sp8.unk0;
        this->unk10.unk34 = sp8.unk4;
        this->unk10.unk38 = sp8.unk8;
        this->unk10.unk3C = 1.0f;
        return 1U;
    }
    return arg0->LoadInt("targetID", (int *) &this->unk54, 0);
}
