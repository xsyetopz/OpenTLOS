s32 TrainController::LoadDone() {
    void *temp_r4_577;

    MKProp::LoadDone();
    temp_r4_577 = this->unk0;
    M2C_FIELD(temp_r4_577, s32 *, 0xC) = (s32) (M2C_FIELD(temp_r4_577, s32 *, 0xC) | 0x20);
    Disable();
}
