void ShotgunWarpFX::Draw() {
    Matrix spC0;
    MKVector3 spB0;
    MKVector3 pos;
    MKVector4 col;
    f32 alpha;
    f32 t;
    f32 temp;
    s32 count;
    s32 i;
    s32 j;
    s32 k;
    s32 row;
    s32 c;
    s32 a;
    s32 b;
    s32 n;
    s32 lo;
    u8 *vtx;

    if (!(this->unk68 <= 0.0f)) {
        MKMaterial_SetMaterial(this->unk60);
        MKPrimitive(0xC, 0x10);
        MKSetMatrix(Matrix::identity);
        t = this->unk68;
        count = this->unkC * this->unk10;
        alpha = 1.0f;
        if (t < 0.325f) {
            alpha = t / 0.325f;
        }
        spC0 = *MKView_GetWorldToScreenMatrix();
        i = 0;
        j = 0;
        k = 0;
        for (i = 0; i < count; i++) {
            Xform3D2D(&spB0, *(MKVector3 *) ((u8 *) this->unk4 + k), &spC0);
            temp = spB0.unk0;
            if (temp < 1.0f) {

            } else {
                temp = 1.0f;
            }
            if (temp > 0.0f) {

            } else {
                temp = 0.0f;
            }
            *(f32 *) ((u8 *) this->unk8 + j) = temp;
            temp = spB0.unk4;
            if (temp < 1.0f) {

            } else {
                temp = 1.0f;
            }
            if (temp > 0.0f) {

            } else {
                temp = 0.0f;
            }
            k += 0x30;
            j += 8;
            *(f32 *) ((u8 *) this->unk8 + (j - 8 + 4)) = temp;
        }
        for (row = 0; row < (s32) (this->unkC - 1); row++) {
            MKBegin(this->unk10 * 2);
            for (c = 0; c < this->unk10; c++) {
                a = c + (row * this->unk10);
                b = c + ((row + 1) * this->unk10);
                MKSetColorF(1.0f, 1.0f, 1.0f, alpha);
                MKSetTexCoord1F(*(f32 *) ((u8 *) this->unk8 + (a * 8)), *(f32 *) ((u8 *) this->unk8 + (a * 8) + 4));
                vtx = (u8 *) this->unk4 + (a * 0x30);
                pos.unk0 = M2C_FIELD(vtx, f32 *, 0) + M2C_FIELD(vtx, f32 *, 0x10);
                pos.unk4 = M2C_FIELD(vtx, f32 *, 4) + M2C_FIELD(vtx, f32 *, 0x14);
                pos.unk8 = M2C_FIELD(vtx, f32 *, 8) + M2C_FIELD(vtx, f32 *, 0x18);
                MKSetPositionV(pos);
                MKSetColorF(1.0f, 1.0f, 1.0f, alpha);
                MKSetTexCoord1F(*(f32 *) ((u8 *) this->unk8 + (b * 8)), *(f32 *) ((u8 *) this->unk8 + (b * 8) + 4));
                vtx = (u8 *) this->unk4 + (b * 0x30);
                pos.unk0 = M2C_FIELD(vtx, f32 *, 0) + M2C_FIELD(vtx, f32 *, 0x10);
                pos.unk4 = M2C_FIELD(vtx, f32 *, 4) + M2C_FIELD(vtx, f32 *, 0x14);
                pos.unk8 = M2C_FIELD(vtx, f32 *, 8) + M2C_FIELD(vtx, f32 *, 0x18);
                MKSetPositionV(pos);
            }
            MKEnd();
        }
        MKEndPrimitive();
        temp = this->unk6C;
        if ((temp > 0.0f) || ((u8) this->unk70 != 0)) {
            if (temp <= 0.0f) {
                this->unk70 = 0;
            }
            MKMaterial_SetMaterial(this->unk64);
            MKPrimitive(0xC, 0x10);
            MKSetMatrix(Matrix::identity);
            col.unk0 = this->unk78 * alpha;
            col.unk4 = this->unk7C * alpha;
            col.unk8 = this->unk80 * alpha;
            col.unkC = alpha;
            n = this->unkC - 2;
            lo = (s32) ((f32) n * (1.0f - (this->unk6C / 0.175f)));
            if (lo < n) {
                n = lo;
            }
            lo = lit_555;
            if (n > lo) {
                lo = n;
            }
            MKBegin(this->unk10 * 2);
            for (k = 0; k < this->unk10; k++) {
                t = 6.0f * ((f32) k / (f32) this->unk10);
                MKSetColorV(col);
                MKSetTexCoord1F(t, 0.95f);
                vtx = (u8 *) this->unk4 + ((k + (lo * this->unk10)) * 0x30);
                pos.unk0 = M2C_FIELD(vtx, f32 *, 0) + M2C_FIELD(vtx, f32 *, 0x10);
                pos.unk4 = M2C_FIELD(vtx, f32 *, 4) + M2C_FIELD(vtx, f32 *, 0x14);
                pos.unk8 = M2C_FIELD(vtx, f32 *, 8) + M2C_FIELD(vtx, f32 *, 0x18);
                MKSetPositionV(pos);
                MKSetColorV(col);
                MKSetTexCoord1F(t, 0.05f);
                vtx = (u8 *) this->unk4 + ((k + ((lo + 1) * this->unk10)) * 0x30);
                pos.unk0 = M2C_FIELD(vtx, f32 *, 0) + M2C_FIELD(vtx, f32 *, 0x10);
                pos.unk4 = M2C_FIELD(vtx, f32 *, 4) + M2C_FIELD(vtx, f32 *, 0x14);
                pos.unk8 = M2C_FIELD(vtx, f32 *, 8) + M2C_FIELD(vtx, f32 *, 0x18);
                MKSetPositionV(pos);
            }
            MKEnd();
            MKEndPrimitive();
        }
    }
}
