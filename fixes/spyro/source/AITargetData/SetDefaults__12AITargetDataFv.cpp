void AITargetData::SetDefaults() {
    this->unk40.Set((Targetable *) NULL);
    M2C_FIELD(this, f32 *, 0) = 0.0f;
    M2C_FIELD(this, f32 *, 4) = 0.0f;
    this->unk8 = 0.0f;
    M2C_FIELD(this, f32 *, 0x20) = 0.0f;
    M2C_FIELD(this, f32 *, 0x24) = 0.0f;
    M2C_FIELD(this, f32 *, 0x28) = 0.0f;
    M2C_FIELD(this, f32 *, 0x10) = 0.0f;
    M2C_FIELD(this, f32 *, 0x14) = 0.0f;
    M2C_FIELD(this, f32 *, 0x18) = 0.0f;
    this->unk30 = 0.0f;
    this->unk34 = 0.0f;
    this->unk38 = 0.0f;
    this->unk3C = 0.0f;
    M2C_FIELD(this, s8 *, 0x48) = 0;
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) | 0x80);
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) & ~0x40);
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) & ~0x10);
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) & ~8);
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) & ~4);
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) & ~0x20);
}
