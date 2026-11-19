void SpyroIdleState::Update() {
    Spyro *temp_r3_839;

    temp_r3_839 = this->unk10;
    if ((s32) M2C_FIELD(temp_r3_839->unk27C, s32 *, 0x16C) > 0) {
        temp_r3_839->SetDesiredVelocity(MKVector3::zero, 540000.0f);
        if (((ContextInfo *) ((u8 *) this->unk10->unk27C + 8))->HitID(2U) != 0) {
            this->unk44 = 1;
        } else {
            this->unk44 = 0;
        }
    }
    this->unk14.Update(this, 0);
}
