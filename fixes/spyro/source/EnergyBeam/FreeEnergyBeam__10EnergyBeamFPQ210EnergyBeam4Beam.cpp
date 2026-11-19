void EnergyBeam::FreeEnergyBeam(EnergyBeam::Beam *arg1) {
    MKHeap *temp_r0_873;
    MKHeap *temp_r3_863;
    MKHeap *temp_r4_860;
    MKHeap *var_r5_855;

    var_r5_855 = this->unk90;
    while (var_r5_855 != NULL) {
        temp_r0_873 = var_r5_855->unk0;
        if (temp_r0_873 == NULL) {
            return;
        }
        if ((MKHeap *) arg1 == temp_r0_873) {
            temp_r4_860 = this->unk90;
            this->unk90 = (MKHeap *) ((u8 *) temp_r4_860 + 4);
            temp_r3_863 = temp_r4_860->unk0;
            temp_r4_860->unk0 = var_r5_855->unk0;
            var_r5_855->unk0 = temp_r3_863;
            return;
        }
        var_r5_855 = (MKHeap *) ((u8 *) var_r5_855 + 4);
    }
}
