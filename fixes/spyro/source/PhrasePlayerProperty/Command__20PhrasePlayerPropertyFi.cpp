void PhrasePlayerProperty::Command(int arg0) {
    u8 *temp_r30_51;
    s32 temp_r31_52;

    switch (arg0) {
    case 1:
        temp_r30_51 = *(u8 **) KDProperty::pInstanceMem;
        temp_r31_52 = this->unk8;
        *(s32 *) (temp_r30_51 + temp_r31_52) = PhrasePlayer_PlayEvent((const char *) this->unk4);
        return;
    case 2:
        PhrasePlayer_StopEvent(*(s32 *) (*(u8 **) KDProperty::pInstanceMem + this->unk8));
        return;
    case 3:
        PhrasePlayer_StopEvent(*(s32 *) (*(u8 **) KDProperty::pInstanceMem + this->unk8));
        return;
    }
}
