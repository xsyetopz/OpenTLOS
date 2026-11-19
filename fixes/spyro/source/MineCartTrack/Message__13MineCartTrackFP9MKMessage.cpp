void MineCartTrack::Message(MKMessage *arg0) {
    s32 temp_r0_54;
    s32 var_r29_52;
    s32 var_r31_47;
    void *temp_r3_67;

    var_r31_47 = 0;
    var_r29_52 = 0;
loop_1:
    temp_r0_54 = arg0->unk0;
    if (temp_r0_54 == 0xBF) {
        this->unk144 = 1;
        return;
    }
    if (temp_r0_54 == 0xBE) {
        this->unk50.unk38 = 0.0f;
        this->unk144 = 0;
    }
    temp_r3_67 = M2C_FIELD(this, void **, var_r31_47 + 0x78);
    if (temp_r3_67 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r3_67, void **, 0x44), M2C_UNK (**)(void *, MKMessage *), 0x2C)(temp_r3_67, arg0);
    }
    var_r29_52 += 1;
    var_r31_47 += 4;
    if (var_r29_52 >= 4) {
        MKProp::Message(arg0);
        return;
    }
    goto loop_1;
}
