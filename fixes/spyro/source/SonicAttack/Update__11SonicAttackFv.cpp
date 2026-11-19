void *SonicAttack::Update() {
    MKVector3 dir;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 lenSq;
    f32 inv;
    f32 sp8;
    f64 guess1;
    f64 guess2;
    f64 guess3;
    s32 bits;
    s32 cls;

    Projectile::Update();
    if (((u8) this->unk158 != 0) && (this->unk150 != NULL) && (this->unk154 != NULL)) {
        inv = 0.0f;
        this->unk164 -= gUpdateTimeDelta;
        if (this->unk164 <= 0.0f) {
            dx = this->unk154->unk0 - this->unk150->unk0;
            dy = this->unk154->unk4 - this->unk150->unk4;
            dz = this->unk154->unk8 - this->unk150->unk8;
            lenSq = (dz * dz) + ((dx * dx) + (dy * dy));
            if (lenSq > 1e-12f) {
                if (lenSq > 0.0f) {
                    guess1 = __frsqrte(lenSq);
                    guess2 = 0.5 * guess1 * -(((f64) lenSq * (guess1 * guess1)) - 3.0);
                    guess3 = 0.5 * guess2 * -(((f64) lenSq * (guess2 * guess2)) - 3.0);
                    lenSq = (f32) ((f64) lenSq * (0.5 * guess3 * -(((f64) lenSq * (guess3 * guess3)) - 3.0)));
                } else if (lenSq < M2C_BITWISE(f32, 0.0)) {
                    lenSq = __float_nan;
                } else {
                    sp8 = lenSq;
                    bits = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (bits) {
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            cls = 1;
                        } else {
                            cls = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            cls = 5;
                        } else {
                            cls = 3;
                        }
                        break;
                    default:
                        cls = 4;
                        break;
                    }
                    if (cls == 1) {
                        lenSq = __float_nan;
                    }
                }
                inv = 1.0f / lenSq;
            }
            dir.unk0 = dx * inv;
            dir.unk4 = dy * inv;
            dir.unk8 = dz * inv;
            SpawnSonicRing(*this->unk150, dir);
            this->unk164 = 0.075f;
        }
    }
    UpdateSonicRings();
}
