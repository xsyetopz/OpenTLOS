void UIVideoScreen::OnEnter() {
    f32 var_f0_480;
    u8 var_r3_469;

    UIScreen::OnEnter();
    M2C_FIELD(&gb, s8 *, 9) = 0;
    this->unkE4 = (GameVideo *) GameVideo_Create((const char *) this->unkE0, (this->unkF8 != 0) | ((this->unkF9 != 0) ? 2 : 0), (this->unkFA != 0) ? -1 : 0);
    var_r3_469 = 0;
    if (((u8) this->unkF4 != 0) && ((GameVideo *) this->unkE4 != NULL)) {
        var_r3_469 = 1;
    }
    if (var_r3_469 != 0) {
        var_f0_480 = 1.0f;
    } else {
        var_f0_480 = 0.0f;
    }
    this->unkEC = var_f0_480;
    this->unkE8 = 0.0f;
    this->unkF0 = 0;
    this->unkFB = 0;
}
