void KDCameraJumpTargetOffset::Enter(KDCameraHeroData &arg0) {
    f64 sp10;
    f64 sp8;

    this->unk0 |= 0x40;
    sp8 = M2C_FIELD(&arg0, f64 *, 0xC8);
    sp10 = M2C_FIELD(&arg0, f64 *, 0xD0);
    this->unk14 = (*(f32 *) ((u8 *) &sp8 + 0x4));
}
