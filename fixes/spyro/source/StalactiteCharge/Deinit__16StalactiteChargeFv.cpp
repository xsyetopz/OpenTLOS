void StalactiteCharge::Deinit() {
    IceBossStalactiteSpawner *temp_r31_1841;
    KDSplinePathSegment *temp_r3_1855;
    StalactiteChargeDescriptor *desc;

    this->unk50.Deinit(this);
    this->unk4C->Deinit();
    temp_r31_1841 = this->unk4C;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1841, NULL, 0);
    } else {
        free(temp_r31_1841);
    }
    temp_r3_1855 = this->unkEC;
    if (temp_r3_1855 != NULL) {
        temp_r3_1855->Deinit();
        operator delete(this->unkEC);
    }
    desc = checked_cast<StalactiteChargeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (desc->unk60 != 0) {
        KDSound_Stop((int *) &this->unk144);
    }
    MKProp::Deinit();
}
