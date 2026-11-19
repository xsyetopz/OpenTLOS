void TriggerProp::Deinit() {
    MKPropDescriptor *temp_r3_1349;
    TriggerObject *temp_r3_1366;
    TriggerProp *temp_r3_1355;

    if (*(TriggerProp **) TriggerProp::pFirstTrigger == this) {
        *(TriggerProp **) TriggerProp::pFirstTrigger = (TriggerProp *) this->unk98;
    }
    temp_r3_1349 = this->unk98;
    if (temp_r3_1349 != NULL) {
        M2C_FIELD(temp_r3_1349, TriggerProp **, 0x9C) = (TriggerProp *) this->unk9C;
    }
    temp_r3_1355 = this->unk9C;
    if (temp_r3_1355 != NULL) {
        temp_r3_1355->unk98 = this->unk98;
    }
    this->unk98 = NULL;
    this->unk9C = NULL;
    TriggerProp::RemoveFromActiveList(this);
    temp_r3_1366 = this->unkA8;
    temp_r3_1366->Deinit();
    MKProp::Deinit();
}
