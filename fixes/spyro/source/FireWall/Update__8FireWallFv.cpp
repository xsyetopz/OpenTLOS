void *FireWall::Update() {
    MKVector3 delta;
    MKVector3 scaled;
    MKVector3 pos;
    MKVector3 vel;
    f32 life;
    f32 rnd;
    f32 t;
    f32 *a;
    f32 *b;
    f32 *cur;
    f32 *p;
    u8 *rec;
    s32 off;
    s32 i;
    s32 idx;
    s32 aOff;
    s32 bOff;
    s32 k;

    t = this->unk60 + gUpdateTimeDelta;
    if (t < 0.0175f) {
    } else {
        t = 0.0175f;
    }
    if (t > 0.0f) {
    } else {
        t = 0.0f;
    }
    this->unk60 = t;
    if (this->unk60 >= 0.0175f) {
        off = 0;
        i = 0;
        this->unk60 = 0.0f;
        while (i < (s32) this->unk4C) {
            M2C_FIELD(this->unk50, s32 *, off + 0x28) += 1;
            if (M2C_FIELD(this->unk50, s32 *, off + 0x28) > 0x3F) {
                M2C_FIELD(this->unk50, s32 *, off + 0x28) = 0;
            }
            i += 1;
            off += 0x30;
        }
    }

    i = 0;
    off = 0;
    while (i < (s32) this->unk4C) {
        if (M2C_FIELD(this->unk50, u32 *, off + 0x2C) != 0U) {
            rec = M2C_FIELD(this->unk50, u8 **, off + 0x2C);
            *(f32 *) (rec + 0x24) = 1.5f * MKRand_Float((int *) &gViewSeed, 0.9f, 1.0f);
            *(f32 *) (rec + 0x2C) = MKRand_Float((int *) &gViewSeed, -6.2831855f, 6.2831855f);
        }
        rnd = MKRand_Float((int *) &gViewSeed, 0.1f, 0.75f);
        p = (f32 *) ((u8 *) this->unk50 + (off + 0x24));
        *p = *p + gUpdateTimeDelta * rnd;
        i += 1;
        off += 0x30;
    }

    t = this->unk64 + gUpdateTimeDelta;
    if (t < 0.0015f) {
    } else {
        t = 0.0015f;
    }
    if (t > 0.0f) {
    } else {
        t = 0.0f;
    }
    this->unk64 = t;
    if (this->unk64 >= 0.0015f) {
        this->unk64 = 0.0f;
        idx = MKRand_Int((int *) &gViewSeed, 0, this->unk4C - 1);
        aOff = idx * 0x30;
        bOff = (idx + 1) * 0x30;
        a = (f32 *) ((u8 *) this->unk50 + aOff);
        b = (f32 *) ((u8 *) this->unk50 + bOff);
        delta.unk0 = b[0] - a[0];
        delta.unk4 = b[1] - a[1];
        delta.unk8 = b[2] - a[2];

        k = 0;
        do {
            cur = (f32 *) ((u8 *) this->unk50 + aOff);
            pos.unk0 = cur[0];
            pos.unk4 = cur[1];
            pos.unk8 = cur[2];
            rnd = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
            scaled.unk0 = delta.unk0 * rnd;
            scaled.unk4 = delta.unk4 * rnd;
            scaled.unk8 = delta.unk8 * rnd;
            pos.unk0 = cur[0] + scaled.unk0;
            pos.unk4 = cur[1] + scaled.unk4;
            pos.unk8 = cur[2] + scaled.unk8;
            life = MKRand_Float((int *) &gViewSeed, 3.0f, 4.0f);
            vel.unk0 = 0.0f;
            vel.unk4 = 100.0f * MKRand_Float((int *) &gViewSeed, 0.0f, 0.1f);
            vel.unk8 = 0.0f;
            M2C_FIELD(&gb, CrashFirePS **, 0x68)->Emit(pos, vel, life);
            k += 1;
        } while (k < 3);
        MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
    }
}
