void Steam::UpdateParticles() {
    f64 fmod(f64, f64); /* libm fmod(double, double), as the asm calls it */
    u8 sp8[0x8];
    MKParticleChunk *var_r30;
    void *temp_r29;
    MKParticleSystem::Envelope *lo;
    SteamDescriptor *desc;
    f32 dt;
    f32 age;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 wx;
    f32 wy;
    f32 wz;
    f32 t;
    f32 frac;
    f32 span;
    s32 cur;
    s32 prev;

    this->unk128 += gUpdateTimeDelta;
    var_r30 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    while (var_r30 != NULL) {
        temp_r29 = var_r30->unk2C;
        age = this->unk128 - M2C_FIELD(temp_r29, f32 *, 0x10);
        if (age > this->unk12C) {
            var_r30 = DestroyParticle((MKBaseParticleSystem::ParticleRec *) sp8);
            continue;
        }
        dt = gUpdateTimeDelta;
        M2C_FIELD(temp_r29, f32 *, 4) = (500.0f * dt) + M2C_FIELD(temp_r29, f32 *, 4);

        /* MKVector3::operator*(1.5f) per lane, then scale by dt; velocity -= that. */
        tx = M2C_FIELD(temp_r29, f32 *, 0) * 1.5f;
        ty = M2C_FIELD(temp_r29, f32 *, 4) * 1.5f;
        tz = M2C_FIELD(temp_r29, f32 *, 8) * 1.5f;
        vx = tx * dt;
        vy = ty * dt;
        vz = tz * dt;
        M2C_FIELD(temp_r29, f32 *, 0) = M2C_FIELD(temp_r29, f32 *, 0) - vx;
        M2C_FIELD(temp_r29, f32 *, 4) = M2C_FIELD(temp_r29, f32 *, 4) - vy;
        M2C_FIELD(temp_r29, f32 *, 8) = M2C_FIELD(temp_r29, f32 *, 8) - vz;

        /* position += velocity * dt */
        wx = M2C_FIELD(temp_r29, f32 *, 0) * dt;
        wy = M2C_FIELD(temp_r29, f32 *, 4) * dt;
        wz = M2C_FIELD(temp_r29, f32 *, 8) * dt;
        M2C_FIELD(var_r30, f32 *, 0) = M2C_FIELD(var_r30, f32 *, 0) + wx;
        M2C_FIELD(var_r30, f32 *, 4) = M2C_FIELD(var_r30, f32 *, 4) + wy;
        M2C_FIELD(var_r30, f32 *, 8) = M2C_FIELD(var_r30, f32 *, 8) + wz;
        var_r30->unk24 += dt * M2C_FIELD(temp_r29, f32 *, 0x18);

        desc = checked_cast<SteamDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_r30->unk20 = (f32) fmod((f64) (var_r30->unk20 + this->unkF0), (f64) desc->unk80);

        cur = M2C_FIELD(temp_r29, s32 *, 0x14);
        if (age > (this->unk12C * this->unk134[cur].unk0)) {
            M2C_FIELD(temp_r29, s32 *, 0x14) = cur + 1;
        }
        cur = M2C_FIELD(temp_r29, s32 *, 0x14);
        prev = cur - 1;
        lo = &this->unk134[prev];
        span = this->unk12C * (this->unk134[cur].unk0 - lo->unk0);
        t = (age - (this->unk12C * lo->unk0)) / span;

        var_r30->unk1C = M2C_FIELD(temp_r29, f32 *, 0x20) * ((t * lo->unkC) + lo->unk4);
        if (var_r30->unk1C < 1.0f) {
        } else {
            var_r30->unk1C = 1.0f;
        }
        if (var_r30->unk1C > 0.0f) {
        } else {
            var_r30->unk1C = 0.0f;
        }

        var_r30->unk28 = M2C_FIELD(temp_r29, f32 *, 0x1C) * ((t * lo->unk10) + lo->unk8);

        frac = age / this->unk12C;
        var_r30->unk10 = (0.35f * frac) + 0.75f;
        var_r30->unk14 = (0.35f * frac) + 0.75f;
        var_r30->unk18 = (0.9f * frac) + 0.1f;
        var_r30 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    }
}
