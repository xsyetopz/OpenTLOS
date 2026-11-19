void SwampTier3Goal_Cower::Terminate() {
    M2C_FIELD(this->unkC, u8 *, 0x6F8) = 0;
    this->unk8 = 1;
}
