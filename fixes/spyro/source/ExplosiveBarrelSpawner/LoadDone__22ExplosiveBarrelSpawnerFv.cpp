void ExplosiveBarrelSpawner::LoadDone() {
    MKProp *temp_r3_87;
    s32 var_r30_81;

    GameProp::LoadDone();
    var_r30_81 = 0;
    while (var_r30_81 < *(s32 *) ((s8 *) checked_cast<ExplosiveBarrelSpawnerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + 0xE4)) {
        temp_r3_87 = gMK->CreateProp("ExplosiveBarrel");
        this->unkC8 = checked_cast<ExplosiveBarrel *, MKProp>(temp_r3_87);
        temp_r3_87->Enable();
        var_r30_81 += 1;
    }
}
