void *TeslaTower::Update() {
    MKVector3 sp58;
    MKVector3 sp48;
    MKVector4 sp38;
    TeslaTowerDescriptor *desc;
    f32 sp10;
    u8 found;
    bool alarm;
    s32 mode;

    ((KDSoundFader *) &this->unk18C)->Update(GS_TeslaTowerExtra1, true, true, (MKProp *) this, NULL, 0U, -1, true);
    ((KDSoundFader *) &this->unk114)->Update(GS_TeslaTowerBeamLP, true, *(s32 *) &this->unk90.unk24 == 0, (MKProp *) this, NULL, 0U, -1, true);
    alarm = false;
    mode = *(s32 *) &this->unk90.unk24;
    if ((mode == 1) || (mode == 2)) {
        alarm = true;
    }
    ((KDSoundFader *) &this->unk13C)->Update(GS_TeslaTowerAlarm, true, alarm, (MKProp *) this, NULL, 0U, -1, true);
    ((KDSoundFader *) &this->unk164)->Update(GS_TeslaTowerZapSpyro1, true, *(s32 *) &this->unk90.unk24 == 2, (MKProp *) this, NULL, 0U, -1, true);
    if (this->unk90.unk2C > 0.0f) {
        this->unk90.unk2C -= gUpdateTimeDelta;
    }
    switch (*(s32 *) &this->unk90.unk24) {
    case 0:
        this->unk90.unk14 += this->unk90.unk18 * gUpdateTimeDelta;
        if (this->unk90.unk18 > 0.0f) {
            if (this->unk90.unk14 >= 1.0f) {
                this->unk90.unk14 = 1.0f;
                this->unk90.unk18 = -this->unk90.unk18;
            }
        } else if (this->unk90.unk14 <= 0.0f) {
            this->unk90.unk14 = 0.0f;
            this->unk90.unk18 = -this->unk90.unk18;
        }
        if (FindZapTargets(false) != 0) {
            *(s32 *) &this->unk90.unk24 = 1;
            this->unk90.unk28 = 0.0f;
        }
        break;
    case 1:
        MKModel_CalculateRefPointWorldPosition(this->unk4, *(s32 *) &this->unk90.unk20, &sp58);
        sp38.unk0 = 1.0f;
        sp38.unk4 = 1.0f;
        sp38.unk8 = 1.0f;
        sp38.unkC = 1.0f;
        sp10 = MKRand_Float((int *) &gViewSeed, 16.0f, 20.0f);
        sp48.unk0 = 0.0f;
        sp48.unk4 = 0.0f;
        sp48.unk8 = 0.0f;
        desc = checked_cast<TeslaTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        M2C_FIELD(desc, ZapPS **, 0x78)->Emit(sp58, sp48, sp10, sp38);
        found = FindZapTargets(false);
        this->unk90.unk28 -= gUpdateTimeDelta;
        if ((this->unk90.unk28 <= 0.0f) || (found == 0)) {
            if (found != 0) {
                this->unk90.unk28 = 1.5f;
                *(s32 *) &this->unk90.unk24 = 2;
            } else {
                this->unk90.unk28 = 0.0f;
                *(s32 *) &this->unk90.unk24 = 0;
            }
        }
        break;
    case 2:
        found = FindZapTargets(true);
        this->unk90.unk28 -= gUpdateTimeDelta;
        if ((this->unk90.unk28 <= 0.0f) || (found == 0)) {
            this->unk90.unk28 = 0.0f;
            *(s32 *) &this->unk90.unk24 = 0;
            desc = checked_cast<TeslaTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            ((EnergyBeam *) desc->unk70)->FreeEnergyBeam(this->unk110);
            this->unk110 = NULL;
        }
        break;
    }
    UpdateTurretTurning();
}
