void TrainChaseSpawnPool::Destroy(Enemy *arg0) {
    s32 sp8[2];
    Enemy ***temp_r3_80;
    Enemy ***var_r31_59;
    Enemy **temp_r3_93;
    Enemy **temp_r4_83;

    var_r31_59 = this->unk0;
    while (var_r31_59 != NULL) {
        temp_r3_93 = *var_r31_59;
        if (temp_r3_93 == NULL) {
            return;
        }
        if (*temp_r3_93 == arg0) {
            sp8[1] = 0;
            sp8[0] = 0x15F;
            arg0->Message((MKMessage *) sp8);
            arg0->Disable();
            temp_r3_80 = this->unk0;
            this->unk0 = temp_r3_80 + 1;
            temp_r4_83 = *temp_r3_80;
            *temp_r3_80 = *var_r31_59;
            *var_r31_59 = temp_r4_83;
            return;
        }
        var_r31_59 += 1;
    }
}
