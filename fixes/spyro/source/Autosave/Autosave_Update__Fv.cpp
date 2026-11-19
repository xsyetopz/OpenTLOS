void Autosave_Abort();
void Autosave_Error();

void Autosave_Update() {
    f32 temp_f1_236;
    f32 temp_f1_307;
    u8 *temp_r7_341;

    if ((s32) autosave_state == 4) {
        if (autosaveIconThrob <= 0.0f) {
            autosaveIconOffset = -((3.0f * gUpdateTimeDelta) - autosaveIconOffset);
        }
        if (autosaveIconOffset <= 0.0f) {
            autosaveIconOffset = 0.0f;
            autosave_state = 0;
        }
    }
    if (autosaveIconOffset >= 1.0f) {
        temp_f1_236 = (6.2831855f * gUpdateTimeDelta) + autosaveIconThrob;
        autosaveIconThrob = temp_f1_236;
        if (temp_f1_236 > 3.1415927f) {
            autosaveIconThrob = 0.0f;
        }
    }
    if ((u8) KDMemoryCard::Update() == 0) {
        switch ((s32) autosave_state) {
        case 4:
        case 0:
            if ((autosaveCard != NULL) && ((u8) bRemovalCheck != 0) && ((u8) GameVideo_Active() == 0)) {
                if (((u8) autosaveCard->unk9 == 0) || ((u8) autosaveCard->unk8 != 0)) {
                    if (((s32) *(s32 *) gGMState.GetCurrState() == 7) && ((u8) M2C_FIELD(&gb, u8 *, 0x396) == 0)) {
                        Autosave_Abort();
                        return;
                    }
                } else {
                    autosaveCard->SetState((KDMCState) 2);
                    return;
                }
            }
            break;
        case 1:
            Autosave_CopyGameData();
            if (autosaveCard == NULL) {
                autosave_state = 0;
                return;
            }
            temp_f1_307 = (6.0f * gUpdateTimeDelta) + autosaveIconOffset;
            autosaveIconOffset = temp_f1_307;
            if (!(temp_f1_307 < 1.0f)) {
                autosaveIconOffset = 1.0f;
                if ((u8) autosaveCard->unk9 == 0) {
                    Autosave_Abort();
                    return;
                }
                autosaveCard->SetState((KDMCState) 3);
                autosave_state = 2;
                return;
            }
            break;
        case 2:
            Autosave_ConfirmCard();
            return;
        case 3:
            if ((u8) KDMemoryCard::WasErrorDuringLast() != 0) {
                Autosave_Error();
                return;
            }
            temp_r7_341 = (u8 *) autosaveCard + ((autosaveFile * 0xC0) + 0xC0);
            autosaveTimeStamp.unk0 = M2C_FIELD(temp_r7_341, s32 *, 0);
            autosaveTimeStamp.unk4 = M2C_FIELD(temp_r7_341, s32 *, 4);
            autosaveTimeStamp.unk8 = M2C_FIELD(temp_r7_341, s32 *, 8);
            autosaveTimeStamp.unkC = M2C_FIELD(temp_r7_341, s32 *, 0xC);
            autosaveTimeStamp.unk10 = M2C_FIELD(temp_r7_341, s32 *, 0x10);
            autosaveTimeStamp.unk14 = M2C_FIELD(temp_r7_341, s32 *, 0x14);
            autosaveTimeStamp.unk18 = M2C_FIELD(temp_r7_341, s32 *, 0x18);
            bRemovalCheck = 1;
            autosave_state = 4;
            break;
        }
    }
}
