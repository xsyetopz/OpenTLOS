void TriggerProp::RemoveFromActiveList(TriggerProp *arg0) {
    MKPropDescriptor *temp_r4_467;
    TriggerProp *temp_r4_473;

    if (*(TriggerProp **) TriggerProp::pFirstActiveTrigger == arg0) {
        *(TriggerProp **) TriggerProp::pFirstActiveTrigger = (TriggerProp *) arg0->unk90;
    }
    temp_r4_467 = arg0->unk90;
    if (temp_r4_467 != NULL) {
        M2C_FIELD(temp_r4_467, TriggerProp **, 0x94) = arg0->unk94;
    }
    temp_r4_473 = arg0->unk94;
    if (temp_r4_473 != NULL) {
        temp_r4_473->unk90 = arg0->unk90;
    }
    arg0->unk90 = NULL;
    arg0->unk94 = NULL;
}
