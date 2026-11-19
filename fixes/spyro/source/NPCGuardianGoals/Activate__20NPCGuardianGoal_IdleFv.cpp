void NPCGuardianGoal_Idle::Activate() {
    u32 temp_r3_257;
    void **temp_r3_262;
    u8 (*temp_r12_263)(void **, MKVector3 *, M2C_UNK *);

    this->unk8 = 0;
    temp_r3_257 = this->unk10;
    if ((temp_r3_257 != 0) && (((TargetContext *) (temp_r3_257 + 0x40))->Get() != NULL)) {
        temp_r3_262 = (void **) ((TargetContext *) (this->unk10 + 0x40))->Get();
        temp_r12_263 = M2C_FIELD(*temp_r3_262, u8 (**)(void **, MKVector3 *, M2C_UNK *), 0x28);
        if (temp_r12_263(temp_r3_262, &this->unkC->unk588, (M2C_UNK *) ((u8 *) this->unkC + 0x700)) != 0) {
            M2C_FIELD(this->unkC, u8 *, 0x6F8) = 1;
        }
    }
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 0U, 0U);
}
