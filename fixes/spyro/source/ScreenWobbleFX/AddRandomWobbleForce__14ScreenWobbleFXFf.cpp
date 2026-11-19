void ScreenWobbleFX::AddRandomWobbleForce(float arg0) {
    MKVector3 lo;
    MKVector3 hi;
    MKVector3 rnd;
    void *node;
    f32 mx;
    f32 my;
    f32 mz;
    s32 i;
    s32 j;
    s32 base;

    j = 0;
    base = 0;
    do {
        i = 0;
        do {
            lo.unk0 = -1.0f;
            lo.unk4 = -1.0f;
            lo.unk8 = 0.0f;
            hi.unk0 = 1.0f;
            hi.unk4 = 1.0f;
            hi.unk8 = 0.0f;
            rnd = KDRand_Vector(lo, hi);
            mx = gUpdateTimeDelta * rnd.unk0;
            my = gUpdateTimeDelta * rnd.unk4;
            mz = gUpdateTimeDelta * rnd.unk8;
            node = ((u8 *) this->unk0) + (((i + base) * 0x38) + 0x20);
            M2C_FIELD(node, f32 *, 0) = M2C_FIELD(node, f32 *, 0) + mx;
            M2C_FIELD(node, f32 *, 4) = M2C_FIELD(node, f32 *, 4) + my;
            M2C_FIELD(node, f32 *, 8) = M2C_FIELD(node, f32 *, 8) + mz;
            i += 1;
        } while (i < 0xF);
        j += 1;
        base += 0xF;
    } while (j < 0xF);
}
