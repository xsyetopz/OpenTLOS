s32 TriggerProp::LoadLine(MKIniLine *arg0) {
    TriggerObject *temp_r3_1155;
    s32 temp_r3_1188;
    s32 temp_r3_1209;
    s32 temp_r3_1230;
    s32 temp_r3_1251;
    s32 temp_r3_1272;
    u8 var_r29_1290;

    if ((MKProp::LoadLine(arg0) != 0) || (temp_r3_1155 = this->unkA8, ((temp_r3_1155->LoadLine(arg0) == 0) == 0)) || (arg0->LoadInt("textID", (int *) &this->unkBC, 0) != 0)) {
        return 1U;
    }
    if (arg0->IsField("bEnterOnceOnly") != 0) {
        temp_r3_1188 = 0 - arg0->GetBool(0);
        this->unk10 |= 0x09000000 & ((temp_r3_1188 - temp_r3_1188) - !M2C_CARRY);
        return 1U;
    }
    if (arg0->IsField("bExitOnceOnly") != 0) {
        temp_r3_1209 = 0 - arg0->GetBool(0);
        this->unk10 |= 0x22000000 & ((temp_r3_1209 - temp_r3_1209) - !M2C_CARRY);
        return 1U;
    }
    if (arg0->IsField("bActionOnceOnly") != 0) {
        temp_r3_1230 = 0 - arg0->GetBool(0);
        this->unk10 |= 0x14000000 & ((temp_r3_1230 - temp_r3_1230) - !M2C_CARRY);
        return 1U;
    }
    if (arg0->IsField("bSaveEnterOnceOnly") != 0) {
        temp_r3_1251 = 0 - arg0->GetBool(0);
        this->unk10 |= 0x49000000 & ((temp_r3_1251 - temp_r3_1251) - !M2C_CARRY);
        return 1U;
    }
    if (arg0->IsField("bExclaim") != 0) {
        temp_r3_1272 = 0 - arg0->GetBool(0);
        this->unk10 |= 0x80000000 & ((temp_r3_1272 - temp_r3_1272) - !M2C_CARRY);
        return 1U;
    }
    if (arg0->LoadBool("bAllowQueuedActions", (bool *) &this->unkC0, 0) != 0) {
        var_r29_1290 = 1;
    } else {
        var_r29_1290 = 0;
        if ((this->unkAC.LoadLine(arg0, "OnEnter") != 0) || (this->unkB0.LoadLine(arg0, "OnAction") != 0) || (this->unkB4.LoadLine(arg0, "OnExit") != 0) || (PropFlagsLoadLine((unsigned int *) &this->unk10, arg0) != 0)) {
            var_r29_1290 = 1;
        }
    }
    return var_r29_1290;
}
