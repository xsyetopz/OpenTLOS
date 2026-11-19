void Dynamite::Collided(MKCollisionResult &arg0) {
    MKVector3 sp58;
    f32 unk14;
    f32 unk18;
    f32 temp_f28;
    f32 temp_f30;

    unk14 = M2C_FIELD(&arg0, f32 *, 0x14);
    if ((this->unk185 == 0) || !((f32) __fabsf(unk14) <= 0.25f)) {
        Projectile::Collided(arg0);
        if (((u8) this->unk184 >> 7U) & 1) {
            this->unk14C &= ~0x40;
            return;
        }
        unk18 = M2C_FIELD(&arg0, f32 *, 0x18);
        temp_f28 = (M2C_FIELD(this, f32 *, 0xD0) * unk18) + ((M2C_FIELD(this, f32 *, 0xC8) * M2C_FIELD(&arg0, f32 *, 0x10)) + (M2C_FIELD(this, f32 *, 0xCC) * unk14));
        if (temp_f28 < 0.0f) {
            sp58.unk0 = M2C_FIELD(&arg0, f32 *, 0x0) + (M2C_FIELD(&arg0, f32 *, 0x10) * 10.0f);
            sp58.unk4 = M2C_FIELD(&arg0, f32 *, 0x4) + (unk14 * 10.0f);
            sp58.unk8 = M2C_FIELD(&arg0, f32 *, 0x8) + (unk18 * 10.0f);
            MKModel_SetPosition(this->unk4, sp58);
            temp_f30 = 2.0f * temp_f28;
            M2C_FIELD(this, f32 *, 0xC8) = M2C_FIELD(this, f32 *, 0xC8) - (M2C_FIELD(&arg0, f32 *, 0x10) * temp_f30);
            M2C_FIELD(this, f32 *, 0xCC) = M2C_FIELD(this, f32 *, 0xCC) - (unk14 * temp_f30);
            M2C_FIELD(this, f32 *, 0xD0) = M2C_FIELD(this, f32 *, 0xD0) - (unk18 * temp_f30);
            M2C_FIELD(this, f32 *, 0xC8) = M2C_FIELD(this, f32 *, 0xC8) * 0.5f;
            M2C_FIELD(this, f32 *, 0xCC) = M2C_FIELD(this, f32 *, 0xCC) * 0.5f;
            M2C_FIELD(this, f32 *, 0xD0) = M2C_FIELD(this, f32 *, 0xD0) * 0.5f;
            this->unk170 = 0.75f * -this->unk170;
            this->unk180 += 1;
            KDSound_Play3d(GS_TNTBounce, (const MKVector3 *) (((u8 *) this->unk8) + 0x30), M2C_FIELD(&arg0, u32 *, 0x44), -1, 0.0f, false);
        }
    }
}
