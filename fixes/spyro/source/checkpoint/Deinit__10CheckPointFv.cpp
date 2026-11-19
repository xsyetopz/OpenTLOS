void CheckPoint::Deinit() {
    s32 temp_r3_722;

    KDSound_Stop((int *) &this->unk190);
    temp_r3_722 = this->unk1BC;
    if ((temp_r3_722 != 0) && (KDSound_IsVoicePlaying(temp_r3_722) != 0)) {
        KDSound_Stop((int *) &this->unk1BC);
    }
    if (*(CheckPoint **) CheckPoint::pCurrentCheckPoint == this) {
        CheckPoint::SetCurrentCheckPoint(NULL);
    }
    KDProp::Deinit();
}
