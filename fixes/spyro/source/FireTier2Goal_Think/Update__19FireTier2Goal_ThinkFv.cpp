u8 FireTier2Goal_Think::Update() {
    f64 sp18;
    f64 sp10;
    s32 sp8;
    u8 temp_r30_39;
    u8 var_r31_35;
    void *temp_r6_40;

    var_r31_35 = 0;
    sp8 = 0;
    temp_r30_39 = this->unk7C;
    temp_r6_40 = M2C_FIELD(this->unkC, void **, 8);
    sp10 = M2C_FIELD(temp_r6_40, f64 *, 0x30);
    sp18 = M2C_FIELD(temp_r6_40, f64 *, 0x38);
    if ((((Enemy *) this->unkC)->InWaterVolume(*((MKVector3 *) &sp10), (int *) &sp8) != 0) && (sp8 & 1)) {
        var_r31_35 = 1;
    }
    this->unk7C = var_r31_35;
    if (((u8) this->unk7C != 0) && (temp_r30_39 == 0)) {
        KDSound_Play3d(GS_MWHit1, (const MKVector3 *) ((s8 *) M2C_FIELD(this->unkC, void **, 8) + 0x30), 0U, -1, 0.0f, false);
    }
    return EnemyGoal_Think::Update();
}
