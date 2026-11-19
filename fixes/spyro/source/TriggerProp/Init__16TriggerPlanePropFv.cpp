void TriggerPlaneProp::Init() {
    TriggerObject *temp_r3;

    TriggerProp::Init();
    this->unkA8 = (TriggerObject *) ((u8 *) this + 0xD0);
    temp_r3 = this->unkA8;
    temp_r3->Init();
    this->unk1A0 = NULL;
    this->unk1A4 = NULL;
}
