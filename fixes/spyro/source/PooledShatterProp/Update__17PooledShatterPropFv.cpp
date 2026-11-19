void *PooledShatterProp::Update() {
    s32 temp_r4_133;
    ShatterableDescriptor *temp_r3_129;

    Shatterable::Update();
    temp_r3_129 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (((s32) this->unk16C == 0) || ((temp_r4_133 = this->unk180, ((temp_r4_133 == (s32) M2C_FIELD(temp_r3_129, s32 *, 0x160)) != 0)) && ((s32) *(s32 *) ((u8 *) this->unk168 + (((temp_r4_133 - 1) << 7) + 0x44)) == 2))) {
        Reset();
        Disable();
    }
}
