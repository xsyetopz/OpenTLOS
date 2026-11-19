void Lever::Deinit() {
    KDSoundPlayer *temp_r31_579;
    KDSoundPlayer *temp_r3_575;

    ((Targetable *) ((s8 *) this + 0xC8))->UnregisterTargetable();
    temp_r3_575 = this->unk100;
    if (temp_r3_575 != NULL) {
        KDSound_Stop((int *) &temp_r3_575->unk0);
        temp_r31_579 = this->unk100;
        if (temp_r31_579 != NULL) {
            KDSound_Stop((int *) &temp_r31_579->unk0);
            operator delete(temp_r31_579);
        }
    }
    GameProp::Deinit();
}
