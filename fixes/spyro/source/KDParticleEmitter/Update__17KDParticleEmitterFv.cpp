void KDParticleEmitter::Update() {
    MKVector3 sp48;
    f32 inv;
    f32 dx;
    f32 dy;
    f32 dz;
    f64 *temp_r3_510;

    if (((u8) this->unk40 == 0) && ((MKBaseParticleSystem *) this->unk28 == NULL)) {
        this->unk30 = 0.0f;
        return;
    }
    if (this->unk34 > 0.0f) {
        temp_r3_510 = this->unk6C;
        dx = M2C_FIELD(temp_r3_510, f32 *, 0) - M2C_FIELD(this, f32 *, 0x18);
        dy = M2C_FIELD(temp_r3_510, f32 *, 4) - M2C_FIELD(this, f32 *, 0x1C);
        dz = M2C_FIELD(temp_r3_510, f32 *, 8) - this->unk20;
        inv = 1.0f / this->unk34;
        sp48.unk0 = dx * inv;
        sp48.unk4 = dy * inv;
        sp48.unk8 = dz * inv;
    } else {
        sp48.unk0 = 0.0f;
        sp48.unk4 = 0.0f;
        sp48.unk8 = 0.0f;
    }
    *(MKVector3 *) &this->unk18 = *(MKVector3 *) this->unk6C;
    this->unk34 = gUpdateTimeDelta;
    this->unk30 += M2C_FIELD(this, f32 *, 0x2C) * gUpdateTimeDelta;
    {
        s32 count = (s32) this->unk30;
        Emit(count, &sp48);
        this->unk30 -= (f32) count;
    }
}
