void *ShatterablePlatform::Update() {
    ShatterableDescriptor *temp_r3;
    ShatterableDescriptor *temp_r31;
    u8 *temp_r3_2;

    temp_r3 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((s32) this->unk180 == (s32) M2C_FIELD(temp_r3, s32 *, 0x160)) {
        temp_r31 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r3 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r3_2 = (u8 *) M2C_FIELD(temp_r3, u8 **, 0x11C) + (M2C_FIELD(temp_r31, s32 *, 0x160) * 0x17C);
        if ((u8) temp_r3_2[-4] != 0) {
            return Shatterable::Update();
        }
    }
    this->unk1C0.unk4 = (MKCollisionInfo *) (((u8 *) this->unk168) + ((this->unk180 << 7) + 0x68));
    this->unk1C0.BeginUpdate();
    this->unk1C0.UpdateTilt();
    UpdateMove();
    this->unk1C0.EndUpdate();
    return Shatterable::Update();
}
