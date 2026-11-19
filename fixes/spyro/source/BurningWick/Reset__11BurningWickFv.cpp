void BurningWick::Reset() {
    f32 sp90[16];
    f32 vx;
    f32 vy;
    f32 vz;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 sum28;
    f32 sum18;

    MKProp::Reset();
    this->unk74 = 0.0f;
    this->unk80 = this->unk78;
    this->unk84 = 0;
    MKModel_CalculateRefPointWorldPosition(this->unk70, this->unk4C, &this->unk88);
    M2C_STRUCT_COPY(sp90, MKModel_GetWorldMatrix(this->unk70), 0x40);
    sp90[12] = 0.0f;
    sp90[13] = 0.0f;
    sp90[14] = 0.0f;
    sp90[15] = 1.0f;
    vx = 0.0f + ((this->unkC0 * sp90[8]) + ((this->unkB8 * sp90[0]) + (this->unkBC * sp90[4])));
    vy = 0.0f + ((this->unkC0 * sp90[9]) + ((this->unkB8 * sp90[1]) + (this->unkBC * sp90[5])));
    vz = 0.0f + ((this->unkC0 * sp90[10]) + ((this->unkB8 * sp90[2]) + (this->unkBC * sp90[6])));
    sx = vx * this->unk80;
    sy = vy * this->unk80;
    sz = vz * this->unk80;
    M2C_FIELD(this, f32 *, 0x98) = this->unk88.unk0 + sx;
    M2C_FIELD(this, f32 *, 0x9C) = this->unk88.unk4 + sy;
    sum28 = this->unk88.unk8 + sz;
    M2C_FIELD(this, f32 *, 0xA0) = sum28;
    M2C_FIELD(this, f32 *, 0x50) = M2C_FIELD(this, f32 *, 0x98) + sx;
    M2C_FIELD(this, f32 *, 0x54) = M2C_FIELD(this, f32 *, 0x9C) + sy;
    sum18 = M2C_FIELD(this, f32 *, 0xA0) + sz;
    this->unk58 = sum18;
    this->unk60 = 0.0f;
    this->unk64 = 0.0f;
    this->unk68 = 0.0f;
}
