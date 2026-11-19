void SpawnerObject::DespawnItem(MKProp *arg0, bool arg1) {
    s32 spC;
    s32 sp8;
    MKProp ***temp_r3_756;
    MKProp ***var_r31_738;
    MKProp **temp_r4_759;
    MKProp **temp_r4_767;

    var_r31_738 = this->unk48;
    temp_r4_767 = *var_r31_738;
    while (temp_r4_767 != NULL) {
        if (*temp_r4_767 == arg0) {
            DespawnItem((SpawnItemObject *) temp_r4_767, arg1);
            spC = 0;
            sp8 = 0x37;
            arg0->Message((MKMessage *) &sp8);
            temp_r3_756 = this->unk48;
            this->unk48 = temp_r3_756 + 1;
            temp_r4_759 = *temp_r3_756;
            *temp_r3_756 = *var_r31_738;
            *var_r31_738 = temp_r4_759;
            return;
        }
        var_r31_738 += 1;
        temp_r4_767 = *var_r31_738;
    }
}
