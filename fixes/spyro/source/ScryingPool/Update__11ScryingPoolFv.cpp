class CutsceneSystem;

void *ScryingPool::Update() {
    s32 temp_r4_104;
    u8 var_r30_154;
    u8 var_r30_184;

    KDPropEx::Update();
    temp_r4_104 = this->unk94;
    if (temp_r4_104 != 0) {
        ((KDSoundFader *) &this->unk98)->Update(temp_r4_104, true, temp_r4_104 == this->unk90, (MKProp *) this, NULL, 0U, -1, true);
    }
    if ((this->unk94 != this->unk90) && ((u8) KDSound_IsVoicePlaying(this->unk98) == 0)) {
        this->unk94 = this->unk90;
    }
    if ((this->unk94 == 0) && (this->unk90 == 0) && (checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC0 != 0)) {
        this->unk90 = checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC0;
    }
    if (M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r30_154 = 0;
        if ((M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U || M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U) && (((KDStateMachine<CutsceneSystem> *) ((u8 *) M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r30_154 = 1;
        }
        if ((var_r30_154 != 0) && (this->unk90 != checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC4)) {
            this->unk90 = checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC4;
        }
    }
    if (M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r30_184 = 0;
        if ((M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U || M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U) && (((KDStateMachine<CutsceneSystem> *) ((u8 *) M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r30_184 = 1;
        }
        if (var_r30_184 == 0) {
            goto block_unk90;
        }
    } else {
block_unk90:
        if (this->unk90 != checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC0) {
            this->unk90 = checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC0;
        }
    }
}
