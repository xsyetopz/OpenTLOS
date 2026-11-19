void SparxHint::Message(MKMessage *arg0) {
    SparxHintMsg msg;
    SparxHintMsg *temp_r3_hint;
    s32 temp_r0_54;
    void *spyro;
    void *temp_r3_90;
    void *temp_r3_126;
    void *temp_r3_153;
    void *temp_r3_191;

    temp_r0_54 = arg0->unk0;
    switch (temp_r0_54) {
    case 0x18:
        temp_r3_hint = checked_cast<SparxHintMsg *, MKMessage>(arg0);
        if (temp_r3_hint->unk14 != NULL) {
            this->unkA9 = 1;
        } else {
            this->unkA9 = 0;
            this->unk90.Send(NULL);
        }
        break;
    case 0xB5:
        spyro = gb.GetSpyro();
        temp_r3_90 = checked_cast<Sparx *, Sparx>(M2C_FIELD(spyro, Sparx **, 0xB70));
        if ((u8) this->unkA9 == 0) {
            M2C_FIELD(&msg, s32 *, 0) = 0x18;
            M2C_FIELD(&msg, s32 *, 4) = 0;
            msg.unk8 = this->unk94;
            msg.unkC = 0;
            msg.unkD = 1;
            msg.unkE = this->unkAB;
            msg.unk10 = this->unkAC;
            msg.unk14 = this;
            M2C_FIELD(M2C_FIELD(temp_r3_90, void **, 0x44), void (**)(void *, void *, s32, s32), 0x2C)(temp_r3_90, &msg, this->unk94, 0);
            this->unkAA = 1;
        }
        break;
    case 0xB4:
        spyro = gb.GetSpyro();
        temp_r3_126 = checked_cast<Sparx *, Sparx>(M2C_FIELD(spyro, Sparx **, 0xB70));
        M2C_FIELD(&msg, s32 *, 0) = 0x18;
        M2C_FIELD(&msg, s32 *, 4) = 0;
        msg.unk8 = 0;
        msg.unkC = 0;
        msg.unkD = 0;
        msg.unkE = 0;
        msg.unk10 = 0;
        msg.unk14 = NULL;
        M2C_FIELD(M2C_FIELD(temp_r3_126, void **, 0x44), void (**)(void *, void *, s32), 0x2C)(temp_r3_126, &msg, 0);
        this->unkAA = 0;
        this->unkA9 = 0;
        this->unkA8 = 0;
        break;
    case 0xB7:
        spyro = gb.GetSpyro();
        temp_r3_153 = checked_cast<Sparx *, Sparx>(M2C_FIELD(spyro, Sparx **, 0xB70));
        if ((u8) this->unkA9 == 0) {
            M2C_FIELD(&msg, s32 *, 0) = 0x18;
            M2C_FIELD(&msg, s32 *, 4) = 0;
            msg.unk8 = this->unk94;
            msg.unkC = 1;
            msg.unkD = 0;
            msg.unkE = this->unkAB;
            msg.unk10 = this->unkAC;
            msg.unk14 = this;
            M2C_FIELD(M2C_FIELD(temp_r3_153, void **, 0x44), void (**)(void *, void *, s32, s32), 0x2C)(temp_r3_153, &msg, 1, 0);
            this->unkAA = 1;
        }
        break;
    case 0xB6:
        spyro = gb.GetSpyro();
        temp_r3_191 = checked_cast<Sparx *, Sparx>(M2C_FIELD(spyro, Sparx **, 0xB70));
        M2C_FIELD(&msg, s32 *, 0) = 0x18;
        M2C_FIELD(&msg, s32 *, 4) = 0;
        msg.unk8 = 0;
        msg.unkC = 0;
        msg.unkD = 0;
        msg.unkE = 0;
        msg.unk10 = 0;
        msg.unk14 = NULL;
        M2C_FIELD(M2C_FIELD(temp_r3_191, void **, 0x44), void (**)(void *, void *, s32), 0x2C)(temp_r3_191, &msg, 0);
        this->unkAA = 0;
        this->unkA9 = 0;
        this->unkA8 = 0;
        break;
    }
    MKProp::Message(arg0);
}
