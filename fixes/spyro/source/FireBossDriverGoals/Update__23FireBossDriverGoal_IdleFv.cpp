u8 FireBossDriverGoal_Idle::Update() {
    AnimSequence *temp_r4_233;
    AnimSequence *temp_r4_246;
    AnimSequence *temp_r4_257;
    Character *temp_r29_227;
    Character *temp_r3_245;
    Character *temp_r3_256;
    s32 var_r5_277;
    u8 var_r30_228;
    void *temp_r6_261;

    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() != 0) {
        temp_r29_227 = this->unkC;
        var_r30_228 = 0;
        if (temp_r29_227->HasAnimFinished() != 0) {
            temp_r4_233 = ((Enemy *) temp_r29_227)->unkA50;
            if ((temp_r4_233 != NULL) && ((u32) temp_r4_233->unk0 == (u32) M2C_FIELD(temp_r29_227->unk630, u32 *, 0x20))) {
                var_r30_228 = 1;
            }
        }
        if ((var_r30_228 != 0) && (temp_r3_245 = this->unkC, temp_r4_246 = ((Enemy *) temp_r3_245)->unkA50, (((u32) temp_r4_246->unk20 == 0) == 0))) {
            ((Enemy *) temp_r3_245)->SetAnim(temp_r4_246, (AnimTransition *) &temp_r4_246->unk20, 0.15f, 0U);
        } else {
            temp_r3_256 = this->unkC;
            temp_r4_257 = ((Enemy *) temp_r3_256)->unkA50;
            if (((u32) temp_r4_257->unk40 != 0) && (temp_r6_261 = temp_r3_256->unk630, (((u32) M2C_FIELD(temp_r6_261, u32 *, 0x20) == (u32) temp_r4_257->unk20) != 0))) {
                if ((s32) M2C_FIELD(temp_r6_261, s32 *, 0x44) >= 3) {
                    ((Enemy *) temp_r3_256)->SetAnim(temp_r4_257, (AnimTransition *) &temp_r4_257->unk40, 0.15f, 0U);
                }
            } else {
                var_r5_277 = 0x5F;
                if ((u8) M2C_FIELD(this->unk10, u8 *, 0xB14) != 0) {
                    var_r5_277 = 0x60;
                }
                ((Enemy *) temp_r3_256)->SetAnim((AnimSequenceType) 1, var_r5_277, 0, 0.15f, 0U, 0U);
            }
        }
    }
    return this->unk8;
}
