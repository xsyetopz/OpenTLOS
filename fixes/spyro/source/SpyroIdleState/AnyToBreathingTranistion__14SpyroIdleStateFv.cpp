u8 SpyroIdleState::AnyToBreathingTranistion() {
    EventCamera *camera;
    u8 flag;

    camera = EventCamera_GetCurrent();
    flag = 0;
    if (camera == NULL) {
        flag = this->unk10->unk3D3;
    }
    if (flag != 0) {
        flag = M2C_FIELD(this->unk10->unk260, u8 *, 0x14);
    }
    if (flag != 0) {
        flag = M2C_FIELD(GameData::gameData, s32 *, 0x158) != 2;
    }
    if ((flag != 0) && (M2C_FIELD(&this->unk14, s32 *, 0) != 4)) {
        this->unk14.SetState(this, 4, 0U);
        return 1;
    }
    camera = EventCamera_GetCurrent();
    flag = 0;
    if (camera == NULL) {
        flag = this->unk10->unk3D3;
    }
    if ((flag != 0) && (M2C_FIELD(&this->unk14, s32 *, 0) != 3)) {
        this->unk14.SetState(this, 3, 0U);
        return 1;
    }
    return 0;
}
