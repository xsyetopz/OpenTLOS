void SpyroIdleState::SelectAnimation() {
    Spyro *spyro;
    void *base;
    s32 count;
    u32 flags;

    if ((this->unk3C == 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk28) && ((u8) M2C_FIELD(&gb, u8 *, 0x35D) == 0)) {
        if ((s32) this->unk2C == 5) {
            this->unk3C = 2;
            this->unk2C = 0;
        } else {
            this->unk3C = 1;
            this->unk2C += 1;
        }
        this->unk28 = M2C_FIELD(&gb, f32 *, 0x30C) + 10.0f;
    } else if ((this->unk3C != 0) && ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) || ((s32) this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk44 > 1))) {
        this->unk3C = 0;
        this->unk28 = M2C_FIELD(&gb, f32 *, 0x30C) + 10.0f;
    }
    spyro = this->unk10;
    count = M2C_FIELD(spyro->unk27C, s32 *, 0x16C);
    flags = 0;
    if (count > 0) {
        base = (u8 *) spyro->unk27C + 8 + ((count - 1) * 0x58);
        flags = M2C_FIELD(base, u32 *, 0x44);
    }
    this->unk30.Update(spyro, 1U, flags, (IdleAnimNumber) this->unk3C, 0.0f);
}
