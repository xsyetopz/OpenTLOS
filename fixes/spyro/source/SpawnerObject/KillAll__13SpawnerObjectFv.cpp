void SpawnerObject::KillAll() {
    s32 spC;
    s32 sp8;
    MKProp ***var_r29_548;
    MKProp **temp_r3_561;
    MKProp *temp_r3_551;

    if (((u8) this->unk4C >> 6U) & 1) {
        this->unk10.unk0 = 1;
        var_r29_548 = this->unk48;
        temp_r3_561 = *var_r29_548;
        while (temp_r3_561 != NULL) {
            temp_r3_551 = *temp_r3_561;
            spC = 0;
            sp8 = 0xE0;
            temp_r3_551->Message((MKMessage *) &sp8);
            var_r29_548 += 1;
            temp_r3_561 = *var_r29_548;
        }
    }
}
