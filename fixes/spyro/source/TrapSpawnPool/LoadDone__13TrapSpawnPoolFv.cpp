s32 TrapSpawnPool::LoadDone() {
    s32 temp_r31_411;
    s32 var_r30_426;
    s32 var_r31_427;
    void **var_r3_419;
    TrapSpawnPoolDescriptor *temp_r4_desc;

    MKProp::LoadDone();
    temp_r31_411 = this->unk90 * 4;
    if (MKHeap::Current() != NULL) {
        var_r3_419 = (void **) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r31_411, NULL, 0));
    } else {
        var_r3_419 = malloc(temp_r31_411);
    }
    this->unk9C = var_r3_419;
    var_r30_426 = 0;
    var_r31_427 = 0;
    while (var_r30_426 < (s32) this->unk90) {
        temp_r4_desc = checked_cast<TrapSpawnPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        gMK->CreatePropDeferred((const char *) temp_r4_desc->unk60,(MKProp **) ((u8 *) this->unk9C + var_r31_427));
        var_r30_426 += 1;
        var_r31_427 += 4;
    }
    this->unkB4.LoadDone();
}
