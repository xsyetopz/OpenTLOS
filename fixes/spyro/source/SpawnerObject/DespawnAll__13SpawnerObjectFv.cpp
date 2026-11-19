void SpawnerObject::DespawnAll() {
    s32 spC;
    s32 sp8;
    MKProp ***var_r29_587;
    MKProp **temp_r4_606;
    MKProp *temp_r28_592;
    MKProp ***temp_r3_583;

    if (((u8) this->unk4C >> 6U) & 1) {
        temp_r3_583 = this->unk48;
        if (*temp_r3_583 != NULL) {
            var_r29_587 = temp_r3_583;
            temp_r4_606 = *var_r29_587;
            while (temp_r4_606 != NULL) {
                temp_r28_592 = *temp_r4_606;
                DespawnItem((SpawnItemObject *) temp_r4_606, 0);
                spC = 0;
                sp8 = 0x37;
                temp_r28_592->Message((MKMessage *) &sp8);
                var_r29_587 += 1;
                temp_r4_606 = *var_r29_587;
            }
            while (*this->unk48 != NULL) {
                this->unk48 += 1;
            }
        }
    }
}
