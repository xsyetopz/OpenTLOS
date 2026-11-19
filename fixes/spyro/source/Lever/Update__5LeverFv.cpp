class CutsceneSystem;
void *Lever::Update() {
    KDSoundPlayer *temp_r3_388;
    KDSynkerPlayer3 *temp_r3_354;
    LeverDescriptor *desc;
    s32 temp_r0_404;
    s32 var_r4_381;
    u8 var_r27_350;
    u8 var_r30_353;
    void *temp_r28_352;

    GameProp::Update();
    var_r27_350 = 0;
    temp_r28_352 = M2C_FIELD(&gb, void **, 0xC);
    var_r30_353 = 0;
    temp_r3_354 = M2C_FIELD(temp_r28_352, KDSynkerPlayer3 **, 0x78);
    if (((temp_r3_354 != NULL) && (temp_r3_354->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r28_352, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r28_352) + 0x24))->GetState() == 2))) {
        var_r30_353 = 1;
    }
    if ((var_r30_353 != 0) && ((s32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), s32 *, 0x74) == 0)) {
        var_r27_350 = 1;
    }
    if (var_r27_350 != 0) {
        var_r4_381 = GS_LavaLeverPullStart;
    } else {
        desc = checked_cast<LeverDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_r4_381 = M2C_FIELD(desc, s32 *, 0xE4);
    }
    temp_r3_388 = this->unk100;
    if (temp_r3_388 != NULL) {
        ((KDSoundFader *) temp_r3_388)->Update(var_r4_381, 1U, this->unkD0 == 2, (MKProp *) this, NULL, 0U, -1, 1);
    }
    temp_r0_404 = this->unkD0;
    switch (temp_r0_404) {
    case 1:
        if (this->unk80->unk2C & 1) {
            this->unkF8.Send((MKProp *) this);
            SetState(2);
            return;
        }
    case 2:
        return;
    case 3:
        if (this->unk80->unk2C & 1) {
            this->unkFC.Send((MKProp *) this);
            SetState(0);
        }
        break;
    }
}
