void SpyroFallState::Exit() {
    KDCamera *camera;
    s32 spC;
    s32 sp8;
    Spyro *temp_r5_2159;

    this->unk10->SetMeleeButtonStateTimeout(0U);
    camera = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x450;
    camera->Message((MKMessage *) &sp8);
    this->unk14.Exit(this);
    this->unk10->unk388 = 0.0f;
    temp_r5_2159 = this->unk10;
    temp_r5_2159->unk428 |= 0x80;
    SetStrafeJump(0U);
    ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this->unk10->unk260, void **, 4), LineSegmentTrail **, 0xC8)))->EndTrail();
    ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this->unk10->unk260, void **, 4), LineSegmentTrail **, 0xCC)))->EndTrail();
}
