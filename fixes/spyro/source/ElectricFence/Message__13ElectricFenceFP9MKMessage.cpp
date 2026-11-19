void ElectricFence::Message(MKMessage *arg0) {
    ElectricFenceDescriptor *desc;
    HitHeroSndMsg *hit;
    MKVector3 *pos;
    s32 var_r3_376;
    s32 var_ctr_378;
    s32 var_r3_391;
    s32 var_ctr_393;
    void *temp_r5_381;
    void *temp_r5_396;

    ((KDSoundPlayer *) &this->unk114)->Message(arg0);
    switch (arg0->unk0) {
    case 181:
        this->unk54 = 1;
        EnableFenceCollision(this->unk54);
        AllocBeams();
        return;
    case 22:
        hit = checked_cast<HitHeroSndMsg *, MKMessage>(arg0);
        M2C_FIELD(hit, s32 *, 8) = (s32) GS_SpyroZapBurn;
        MKProp::Message(arg0);
        return;
    case 180:
        desc = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        if ((desc->unk88 != 0) && ((u8) this->unk54 != 0)) {
            pos = (MKVector3 *) ((u8 *) this->unk8 + 0x30);
            desc = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            KDSound_Play3d(desc->unk88, pos, 0U, -1, 0.0f, false);
        }
        this->unk54 = 0;
        EnableFenceCollision(this->unk54);
        FreeBeams();
        return;
    case -3:
        var_r3_376 = 0;
        var_ctr_378 = 2;
        do {
            temp_r5_381 = M2C_FIELD(this, void **, var_r3_376 + 0xD0);
            if (temp_r5_381 != NULL) {
                M2C_FIELD(temp_r5_381, u8 *, 0x10) = 1;
            }
            var_r3_376 += 0x18;
            var_ctr_378 -= 1;
        } while (var_ctr_378 != 0);
        MKProp::Message(arg0);
        return;
    case -4:
        var_r3_391 = 0;
        var_ctr_393 = 2;
        do {
            temp_r5_396 = M2C_FIELD(this, void **, var_r3_391 + 0xD0);
            if (temp_r5_396 != NULL) {
                M2C_FIELD(temp_r5_396, u8 *, 0x10) = 0;
            }
            var_r3_391 += 0x18;
            var_ctr_393 -= 1;
        } while (var_ctr_393 != 0);
        MKProp::Message(arg0);
        return;
    default:
        MKProp::Message(arg0);
        return;
    }
}
