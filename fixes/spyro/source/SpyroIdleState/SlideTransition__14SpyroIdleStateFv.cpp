u8 SpyroIdleState::SlideTransition() {
    Spyro *spyro;
    void *base;
    s32 count;
    u32 flags;
    f32 sum;
    u8 flag;
    u8 result;

    result = AnyToBreathingTranistion();
    if (result != 0) {
        return result;
    }
    spyro = this->unk10;
    count = M2C_FIELD(spyro->unk27C, s32 *, 0x16C);
    flags = 0;
    if (count > 0) {
        base = (u8 *) spyro->unk27C + 8 + ((count - 1) * 0x58);
        flags = M2C_FIELD(base, u32 *, 0x44);
    }
    flag = ((flags >> 3U) & 1U) ^ 1U;
    if (flag == 0) {
        sum = spyro->unk340 * spyro->unk340 + (spyro->unk338 * spyro->unk338 + spyro->unk33C * spyro->unk33C);
        flag = sum < 10000.0f;
    }
    if (flag == 0) {
        return 0;
    }
    if (M2C_FIELD(&this->unk14, s32 *, 0) == 0) {
        return 0;
    }
    this->unk14.SetState(this, 0, 0U);
    return 1;
}
