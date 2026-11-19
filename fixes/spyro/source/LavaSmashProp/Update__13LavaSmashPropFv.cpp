void *LavaSmashProp::Update() {
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f1_612;
    LavaSmashPropDescriptor *desc;
    LavaSmashPropDescriptor *desc2;

    Shatterable::Update();
    desc = checked_cast<LavaSmashPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (desc->unk17C != 0) {
        desc2 = checked_cast<LavaSmashPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        ((KDSoundFader *) &this->unk1A8)->Update(desc2->unk17C, 1, this->unk1D0, (MKProp *) this, NULL, 0U, -1, 1);
    }
    if (M2C_FIELD(this, s32 *, 0x17C) == 3) {
        this->unk1FC += gUpdateTimeDelta;
        temp_f1_612 = 0.5f * (this->unk204 * (1.0f + _table_sinf(0.5f * (6.2831855f * (f32) fmod(this->unk1FC, 2.0)))));
        sp10 = M2C_FIELD(this, f32 *, 0x108) + temp_f1_612;
        sp14 = M2C_FIELD(this, f32 *, 0x10C) - temp_f1_612;
        sp18 = M2C_FIELD(this, f32 *, 0x110) - temp_f1_612;
        sp1C = M2C_FIELD(this, f32 *, 0x114);
        MKModel_SetColor(this->unk4, *((MKVector4 *) &sp10));
    }
}
