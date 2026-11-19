void SpawnerObject::RemoveItem(MKProp *arg0) {
    s32 spC;
    s32 sp8;
    MKProp ***temp_r3_1049;
    MKProp ***var_r31_1033;
    MKProp **temp_r3_1060;
    MKProp **temp_r4_1052;

    if (((u8) this->unk4C >> 6U) & 1) {
        var_r31_1033 = this->unk48;
loop_5:
        temp_r3_1060 = *var_r31_1033;
        if (temp_r3_1060 == NULL) {

        } else {
            if ((MKProp *) *temp_r3_1060 == arg0) {
                spC = 0;
                sp8 = 0x37;
                arg0->Message((MKMessage *) &sp8);
                temp_r3_1049 = this->unk48;
                this->unk48 = temp_r3_1049 + 1;
                temp_r4_1052 = *temp_r3_1049;
                *temp_r3_1049 = *var_r31_1033;
                *var_r31_1033 = temp_r4_1052;
                return;
            }
            var_r31_1033 += 1;
            goto loop_5;
        }
    }
}
