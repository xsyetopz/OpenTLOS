void TrainController::Reset() {
    s32 sp8[2];
    TrainChaseSpyro *temp_r3_522;
    SteamTrain *temp_r3_532;

    MKProp::Reset();
    if ((u8) ((MKSceneManager *) gMK)->IsEnabled(this, *(s32 *) MKResource::sWorkingChunkID) != 0) {
        temp_r3_522 = checked_cast<TrainChaseSpyro *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk58));
        if (temp_r3_522 != NULL) {
            temp_r3_522->Reset();
        }
        temp_r3_532 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk50));
        if (temp_r3_532 != NULL) {
            temp_r3_532->Reset();
        }
        SetStage(0);
        sp8[0] = 0xD5;
        sp8[1] = 0;
        ((MKSceneManager *) gMK)->SendMessage((MKMessage *) sp8, 0x40000, true, NULL, 0.0f, true);
    }
    this->unk6C = 0;
}
