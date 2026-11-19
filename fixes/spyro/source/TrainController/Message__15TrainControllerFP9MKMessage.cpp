void TrainController::Message(MKMessage *arg0) {
    s32 sp50[2];
    s32 sp48[2];
    s32 sp40[2];
    s32 sp38[2];
    s32 sp30[2];
    s32 sp28[2];
    s32 sp20[2];
    s32 sp18[2];
    s32 sp10[2];
    s32 sp8[2];
    SteamTrain *temp_r3_306;
    SteamTrain *temp_r3_334;
    SteamTrain *temp_r3_402;
    SteamTrain *temp_r3_411;
    s32 temp_r0_104;
    MKProp *temp_r3_166;
    MKProp *temp_r3_180;
    MKProp *temp_r3_194;
    MKProp *temp_r3_208;
    MKProp *temp_r3_227;
    MKProp *temp_r3_241;
    MKProp *temp_r3_255;
    MKProp *temp_r3_269;
    MKProp *temp_r3_355;
    MKProp *temp_r3_369;
    MKProp *temp_r3_379;
    MKProp *temp_r3_390;
    MKProp *temp_r3_419;

    MKProp::Message(arg0);
    temp_r0_104 = arg0->unk0;
    switch (temp_r0_104) {
    case 0xB5:
        Enable();
        Reset();
        temp_r3_166 = MKSceneManager::PropResolver_Resolve((s32) this->unk50);
        if (temp_r3_166 != NULL) {
            sp48[1] = 0;
            sp48[0] = 0xB5;
            temp_r3_166->Message((MKMessage *) sp48);
        }
        temp_r3_180 = MKSceneManager::PropResolver_Resolve((s32) this->unk4C);
        if (temp_r3_180 != NULL) {
            sp40[1] = 0;
            sp40[0] = 0xB5;
            temp_r3_180->Message((MKMessage *) sp40);
        }
        temp_r3_194 = MKSceneManager::PropResolver_Resolve((s32) this->unk54);
        if (temp_r3_194 != NULL) {
            sp38[1] = 0;
            sp38[0] = 0xB5;
            temp_r3_194->Message((MKMessage *) sp38);
        }
        temp_r3_208 = MKSceneManager::PropResolver_Resolve((s32) this->unk58);
        if (temp_r3_208 != NULL) {
            sp30[1] = 0;
            sp30[0] = 0xB5;
            temp_r3_208->Message((MKMessage *) sp30);
        }
        this->unk68.Send(this);
        return;
    case 0xB4:
        temp_r3_227 = MKSceneManager::PropResolver_Resolve((s32) this->unk50);
        if (temp_r3_227 != NULL) {
            sp28[1] = 0;
            sp28[0] = 0xB4;
            temp_r3_227->Message((MKMessage *) sp28);
        }
        temp_r3_241 = MKSceneManager::PropResolver_Resolve((s32) this->unk4C);
        if (temp_r3_241 != NULL) {
            sp20[1] = 0;
            sp20[0] = 0xB4;
            temp_r3_241->Message((MKMessage *) sp20);
        }
        temp_r3_255 = MKSceneManager::PropResolver_Resolve((s32) this->unk54);
        if (temp_r3_255 != NULL) {
            sp18[1] = 0;
            sp18[0] = 0xB4;
            temp_r3_255->Message((MKMessage *) sp18);
        }
        temp_r3_269 = MKSceneManager::PropResolver_Resolve((s32) this->unk58);
        if (temp_r3_269 != NULL) {
            sp10[1] = 0;
            sp10[0] = 0xB4;
            temp_r3_269->Message((MKMessage *) sp10);
        }
        Disable();
        return;
    case 0x138:
        SetStage(0);
        return;
    case 0x139:
        SetStage(1);
        return;
    case 0x13A:
        SetStage(2);
        return;
    case 0x13B:
        temp_r3_306 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk50));
        if (temp_r3_306 != NULL) {
            temp_r3_306->unk131 = 0;
        }
        SetStage(3);
        return;
    case 0x13C:
        SetStage(4);
        return;
    case 0x13D:
        SetStage(5);
        return;
    case 0x13E:
        SetStage(6);
        return;
    case 0x13F:
        temp_r3_334 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk50));
        if (temp_r3_334 != NULL) {
            temp_r3_334->Stop(false);
        }
        SetStage(7);
        return;
    case 0x140:
        this->unk64.Send(this);
        return;
    case 0x148:
        this->unk6C = 1;
        return;
    case 0x149:
        temp_r3_355 = MKSceneManager::PropResolver_Resolve((s32) this->unk58);
        if (temp_r3_355 != NULL) {
            temp_r3_355->Message(arg0);
        }
        this->unk6C = 0;
        return;
    case 0x14A:
        temp_r3_369 = MKSceneManager::PropResolver_Resolve((s32) this->unk50);
        if (temp_r3_369 != NULL) {
            temp_r3_369->Message(arg0);
        }
        temp_r3_379 = MKSceneManager::PropResolver_Resolve((s32) this->unk58);
        if (temp_r3_379 != NULL) {
            temp_r3_379->Message(arg0);
            return;
        }
        return;
    case 0x14B:
        temp_r3_390 = MKSceneManager::PropResolver_Resolve((s32) this->unk58);
        if (temp_r3_390 != NULL) {
            temp_r3_390->Message(arg0);
            return;
        }
        break;
    case 0x142:
        temp_r3_402 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk50));
        if (temp_r3_402 != NULL) {
            temp_r3_402->unk131 = 1;
            return;
        }
        break;
    case 0x141:
        temp_r3_411 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk50));
        if (temp_r3_411 != NULL) {
            temp_r3_411->Stop(true);
            return;
        }
        break;
    case 0x143:
        temp_r3_419 = MKSceneManager::PropResolver_Resolve((s32) this->unk58);
        if (temp_r3_419 != NULL) {
            sp50[1] = 0;
            sp50[0] = 0x148;
            temp_r3_419->Message((MKMessage *) sp50);
            return;
        }
        break;
    case 0x1C:
        sp8[1] = 0;
        sp8[0] = 0xB4;
        Message((MKMessage *) sp8);
        break;
    }
}
