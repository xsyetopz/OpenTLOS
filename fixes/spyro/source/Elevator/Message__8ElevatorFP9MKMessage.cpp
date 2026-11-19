void Elevator::Message(MKMessage *arg0) {
    struct {
        s32 unk0;
        s32 unk4;
    } sp8;
    s32 temp_r0_333;
    u32 *temp_r3_421;
    void ***temp_r3_362;
    void **temp_r3_379;
    void **temp_r5_376;
    void *temp_r4_384;
    void *var_r26_388;

    temp_r0_333 = arg0->unk0;
    switch (temp_r0_333) {
    case -3:
        if (this->unk140 >= this->unk128) {
            this->unk154 = 1;
        }
        this->unk150 = 0;
        this->unk14C = this->unkB8;
        break;
    case 35:
        temp_r3_362 = M2C_FIELD(arg0, void ****, 8);
        if ((temp_r3_362 != NULL) && ((void **) *temp_r3_362 != NULL)) {
            temp_r5_376 = *M2C_FIELD(arg0, void ****, 8);
            if ((u32) temp_r5_376 != M2C_FIELD(*gb, u32 (**)(void **), 0xC)(gb)) {
                temp_r3_379 = this->unk120;
                if (temp_r3_379 != NULL) {
                    temp_r4_384 = M2C_FIELD(*temp_r3_379, void **, 0x28);
                    if ((u32) temp_r4_384 != (u32) M2C_FIELD(*temp_r5_376, u32 *, 0x28)) {
                        var_r26_388 = temp_r4_384;
                        while (var_r26_388 != NULL) {
                            sp8.unk0 = 0x24;
                            sp8.unk4 = 0;
                            M2C_FIELD(M2C_FIELD(var_r26_388, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(var_r26_388, (s32 *) &sp8);
                            var_r26_388 = M2C_FIELD(var_r26_388, void **, 0x38);
                        }
                        this->unk124 = 0;
                    }
                }
                this->unk124 += 1;
                this->unk120 = *M2C_FIELD(arg0, void ****, 8);
                M2C_FIELD(arg0, s8 *, 0xC) = 1;
            }
        }
        break;
    case 36:
        temp_r3_421 = M2C_FIELD(arg0, u32 **, 8);
        if ((temp_r3_421 != NULL) && ((u32) *temp_r3_421 != 0U) && ((u32) *M2C_FIELD(arg0, u32 **, 8) != M2C_FIELD(*gb, u32 (**)(void **), 0xC)(gb))) {
            this->unk124 -= 1;
            if ((s32) this->unk124 <= 0) {
                this->unk120 = NULL;
            }
        }
        break;
    }
    GameProp::Message(arg0);
}
