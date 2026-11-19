void KDSynkerPlayer3::Init(const char *arg0, bool arg1, bool arg2, MKIni *arg3) {
    u32 temp_r3_1176;

    this->unk50 = 0;
    if (arg1 != 0) {
        this->unk50 |= 8;
    } else {
        this->unk50 &= 0xFFFFFFF7;
    }
    if (arg2 != 0) {
        this->unk50 |= 0x10;
    } else {
        this->unk50 &= 0xFFFFFFEF;
    }
    strcpy((char *) &this->unk28, arg0);
    strtok(&this->unk28, (s8 *) ".");
    this->unk58 = arg3 != NULL;
    this->unk54 = arg3;
    this->unk4.unk8 = 0x40;
    this->unk4.unk4 = 0;
    this->unk4.unk0 = 0;
    this->unk4.unk14 = 0x10;
    this->unk4.unk10 = 0;
    this->unk4.unkC = NULL;
    this->unk4.unk20 = 4;
    this->unk4.unk1C = 0;
    this->unk4.unk18 = NULL;
    this->unk60.Init();
    this->unk100.Init();
    this->unk114.Init();
    this->unk120.Init(this, *(KDSynkerPlayerEventCreationTable **) KDSynkerPlayer3::pEventCreationTable);
    this->unk148.Init();
    this->unk170.Init();
    this->unk234 = 0;
    this->unk23C = 0;
    this->unk244 = 0.0f;
    this->unk24C = 0;
    this->unk248 = 0.0f;
    this->unk48 = 1.0f;
    this->unk240 = 0;
    this->unk238 = NULL;
    temp_r3_1176 = this->unk50;
    if ((temp_r3_1176 & 8) || (temp_r3_1176 & 0x10)) {
        this->unk250 = 0;
        this->unk4C = 2;
        Update();
        return;
    }
    this->unk4C = 1;
    this->unk250 = MKPackage_QLoad((const char *) Str_Printf("%s.sc2", &this->unk28), 0);
}
