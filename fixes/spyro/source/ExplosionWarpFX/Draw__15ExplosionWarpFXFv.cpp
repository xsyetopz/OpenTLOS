void ExplosionWarpFX::Draw() {
    Matrix worldToScreen;
    MKVector3 local;
    MKVector3 pa;
    MKVector3 pb;
    MKVector4 col;
    f32 fade;
    f32 x;
    f32 y;
    s32 count;
    s32 i;
    s32 row;
    s32 j;
    s32 ia;
    s32 ib;
    u8 *p;
    u8 *uv;

    if (this->unk64 <= 0.0f) {
        return;
    }

    MKMaterial_SetMaterial(this->unk60);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(Matrix::identity);

    fade = 1.0f;
    if (this->unk64 < 0.325f) {
        fade = this->unk64 / 0.325f;
    }

    count = this->unkC * this->unk10;
    M2C_STRUCT_COPY(&worldToScreen, MKView_GetWorldToScreenMatrix(), 0x40);

    /* Project each point to screen space and clamp x and y to [0, 1]. */
    for (i = 0; i < count; i++) {
        p = (u8 *) this->unk4 + i * 0x30;
        Xform3D2D(&local, *(MKVector3 *) p, &worldToScreen);

        x = local.unk0;
        if (x < 1.0f) {
        } else {
            x = 1.0f;
        }
        if (x > 0.0f) {
        } else {
            x = 0.0f;
        }
        y = local.unk4;
        if (y < 1.0f) {
        } else {
            y = 1.0f;
        }
        if (y > 0.0f) {
        } else {
            y = 0.0f;
        }
        uv = (u8 *) this->unk8 + i * 8;
        M2C_FIELD(uv, f32 *, 0) = x;
        M2C_FIELD(uv, f32 *, 4) = y;
    }

    /* Each row of the grid is one strip of 2 * unk10 vertices. The last row is drawn with alpha 0. */
    for (row = 0; row < this->unkC - 1; row++) {
        col.unk0 = 1.0f;
        col.unk4 = 1.0f;
        col.unk8 = 1.0f;
        if (row == this->unkC - 2) {
            col.unkC = 0.0f;
        } else {
            col.unkC = fade;
        }

        MKBegin(this->unk10 * 2);
        for (j = 0; j < this->unk10; j++) {
            ia = j + row * this->unk10;
            ib = j + (row + 1) * this->unk10;

            MKSetColorV(col);
            uv = (u8 *) this->unk8 + ia * 8;
            MKSetTexCoord1F(M2C_FIELD(uv, f32 *, 0), M2C_FIELD(uv, f32 *, 4));
            p = (u8 *) this->unk4 + ia * 0x30;
            pa.unk0 = M2C_FIELD(p, f32 *, 0) + M2C_FIELD(p, f32 *, 0x10);
            pa.unk4 = M2C_FIELD(p, f32 *, 4) + M2C_FIELD(p, f32 *, 0x14);
            pa.unk8 = M2C_FIELD(p, f32 *, 8) + M2C_FIELD(p, f32 *, 0x18);
            MKSetPositionV(pa);

            MKSetColorV(col);
            uv = (u8 *) this->unk8 + ib * 8;
            MKSetTexCoord1F(M2C_FIELD(uv, f32 *, 0), M2C_FIELD(uv, f32 *, 4));
            p = (u8 *) this->unk4 + ib * 0x30;
            pb.unk0 = M2C_FIELD(p, f32 *, 0) + M2C_FIELD(p, f32 *, 0x10);
            pb.unk4 = M2C_FIELD(p, f32 *, 4) + M2C_FIELD(p, f32 *, 0x14);
            pb.unk8 = M2C_FIELD(p, f32 *, 8) + M2C_FIELD(p, f32 *, 0x18);
            MKSetPositionV(pb);
        }
        MKEnd();
    }
    MKEndPrimitive();
}
