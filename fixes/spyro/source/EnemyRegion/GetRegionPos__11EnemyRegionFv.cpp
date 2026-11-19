MKVector3 EnemyRegion::GetRegionPos(void) {
    MKVector3 result;
    f32 *m;
    f32 x;
    f32 y;
    f32 z;

    if ((u8) this->unk31 != 0) {
        m = M2C_FIELD(this->unk10, f32 **, 0x30);
        if (m != NULL) {
            x = M2C_FIELD(this, f32 *, 0);
            y = M2C_FIELD(this, f32 *, 4);
            z = M2C_FIELD(this, f32 *, 8);
            result.unk0 = M2C_FIELD(m, f32 *, 0x30) + ((z * M2C_FIELD(m, f32 *, 0x20)) + ((x * M2C_FIELD(m, f32 *, 0)) + (y * M2C_FIELD(m, f32 *, 0x10))));
            result.unk4 = M2C_FIELD(m, f32 *, 0x34) + ((z * M2C_FIELD(m, f32 *, 0x24)) + ((x * M2C_FIELD(m, f32 *, 4)) + (y * M2C_FIELD(m, f32 *, 0x14))));
            result.unk8 = M2C_FIELD(m, f32 *, 0x38) + ((z * M2C_FIELD(m, f32 *, 0x28)) + ((x * M2C_FIELD(m, f32 *, 8)) + (y * M2C_FIELD(m, f32 *, 0x18))));
            return result;
        }
    }
    M2C_FIELD(&result, f64 *, 0) = this->unk0;
    M2C_FIELD(&result, f64 *, 8) = this->unk8;
    return result;
}
