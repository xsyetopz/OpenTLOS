void GroundFire::Emit(const MKVector3 &arg0, float arg1, bool arg2) {
    KDSoundFader *temp_r31_22;
    MKHeap *temp_r6_16;
    s32 var_r0_40;

    temp_r6_16 = this->unk0;
    if ((KDSoundFader *) M2C_FIELD(temp_r6_16, KDSoundFader **, -4) != NULL) {
        this->unk0 = (MKHeap *) ((u8 *) temp_r6_16 - 4);
        temp_r31_22 = M2C_FIELD(temp_r6_16, KDSoundFader **, -4);
        if (temp_r31_22 != NULL) {
            temp_r31_22->unk28 = M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r31_22, f64 *, 0x30) = M2C_FIELD(&arg0, f64 *, 8);
            temp_r31_22->unk40 = arg1;
            temp_r31_22->unk38 = arg1;
            M2C_FIELD(temp_r31_22, f32 *, 0x3C) = 0.0f;
            temp_r31_22->Init(0.5f, 0.25f);
            M2C_FIELD(temp_r31_22, s8 *, 0x48) = 1;
            var_r0_40 = GS_SpyroFireBurnGroundLP;
            if (arg2 != 0) {
                var_r0_40 = GS_SpyroFuryStepsBurnLP;
            }
            M2C_FIELD(temp_r31_22, s32 *, 0x44) = var_r0_40;
        }
    }
}
