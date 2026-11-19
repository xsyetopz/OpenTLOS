void RumbleTimer_Update() {
    u8 StopRumbling(void);

    ((GameData *) GameData::gameData)->GetGameSettings();
    if ((u8) M2C_FIELD(GameData::gameData, u8 *, 0x52) != 0) {
        timer -= gUpdateTimeDelta;
        if (StopRumbling() != 0) {
            if ((u8) bStopped == 0) {
                MKRumble_Reset();
                MKRumble_Enable(0U);
                bStopped = 1;
            }
        } else if (((u8) bStopped != 0) && ((s32) M2C_FIELD(&gb, s32 *, 0x350) != 0)) {
            MKRumble_Enable(1U);
            bStopped = 0;
        }
    }
}
