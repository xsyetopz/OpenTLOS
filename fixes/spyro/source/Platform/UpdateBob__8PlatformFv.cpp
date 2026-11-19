void Platform::UpdateBob() {
    PlatformDescriptor *desc;
    f64 sp10;
    f64 sp8;
    f32 temp_f2_237;

    desc = checked_cast<PlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (desc->unk118 != 0) {
        sp8 = M2C_FIELD(this->unk8, f64 *, 0x30);
        sp10 = M2C_FIELD(this->unk8, f64 *, 0x38);
        temp_f2_237 = desc->unk11C;
        (*(f32 *) ((u8 *) &sp8 + 0x4)) += temp_f2_237 * _table_sinf(6.2831855f * (this->unkB8 * desc->unk120));
        SetPos(*(MKVector3 *) &sp8);
    }
}
