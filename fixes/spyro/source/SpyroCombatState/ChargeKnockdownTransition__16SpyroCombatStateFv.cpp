u8 SpyroCombatState::ChargeKnockdownTransition() {
    s8 sp2D;
    s8 sp2C;
    f32 sp28;
    f32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    MKVector3 sp8;
    Spyro *temp_r3_388;
    Spyro *temp_r3_417;
    u8 var_r31_416;
    u8 var_r4_389;
    u8 var_r4_418;
    void *temp_r5_393;

    sp1C = 0;
    sp20 = -1;
    sp18 = 0x187;
    sp24 = 0.0f;
    sp28 = 0.2f;
    sp2C = 1;
    sp2D = 1;
    if (this->unk10->OnFloor() == 0) {
        temp_r3_388 = this->unk10;
        var_r4_389 = 1;
        if ((u8) temp_r3_388->unk2F0 != 0) {
            temp_r5_393 = temp_r3_388->unk8;
            sp8 = *(MKVector3 *) ((u8 *) temp_r5_393 + 0x30);
            if (!((sp8.unk4 - temp_r3_388->unk2A4) > 33.0f)) {
                var_r4_389 = 0;
            }
        }
        if (temp_r3_388->TryChangeState(var_r4_389, 6U, NULL, 0U) != 0) {
            return 1U;
        }
        goto block_6;
    }
block_6:
    var_r31_416 = 1;
    temp_r3_417 = this->unk10;
    var_r4_418 = 0;
    if (((u8) this->unk2E != 0) && ((s32) M2C_FIELD(temp_r3_417->unk27C, s32 *, 0x16C) > 0)) {
        var_r4_418 = 1;
    }
    if ((temp_r3_417->TryChangeState(var_r4_418, 4U, (MKMessage *) &sp18, 0U) == 0) && (this->unk10->TryChangeState(this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1, 4U, NULL, 0U) == 0)) {
        var_r31_416 = 0;
    }
    return var_r31_416;
}
