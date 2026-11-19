s32 SpyroCombatState::KnockupTransition() {
    s8 sp1D;
    s8 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    Spyro *temp_r3_836;
    s32 var_r31_814;
    u8 var_r28_800;
    u8 var_r29_816;
    u8 var_r4_835;

    var_r28_800 = 0;
    if (((u8) this->unk2D != 0) && ((u8) this->unk31 != 0) && (this->unk10->SelectBestKnockedUpEnemy() != 0)) {
        var_r28_800 = 1;
    }
    var_r31_814 = 1;
    var_r29_816 = 0;
    spC = 0;
    sp10 = -1;
    sp8 = 0x187;
    sp14 = 0.0f;
    sp18 = 0.2f;
    sp1C = 1;
    sp1D = 1;
    if (this->unk10->TryChangeState(var_r28_800, 0xCU, NULL, 0U) == 0) {
        var_r4_835 = 0;
        temp_r3_836 = this->unk10;
        if (((u8) this->unk2E != 0) && ((s32) M2C_FIELD(temp_r3_836->unk27C, s32 *, 0x16C) > 0)) {
            var_r4_835 = 1;
        }
        if (temp_r3_836->TryChangeState(var_r4_835, 4U, (MKMessage *) &sp8, 0U) != 0) {
            goto block_9;
        }
    } else {
block_9:
        var_r29_816 = 1;
    }
    if ((var_r29_816 == 0) && (this->unk10->TryChangeState(this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1, 4U, NULL, 0U) == 0)) {
        var_r31_814 = 0;
    }
    return var_r31_814;
}
