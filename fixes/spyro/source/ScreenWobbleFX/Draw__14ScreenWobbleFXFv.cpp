void ScreenWobbleFX::Draw() {
    f32 *rect;
    f32 ox;
    f32 oy;
    f32 ow;
    f32 oh;
    MKVector3 pos;
    void *node;
    s32 i;
    s32 j;
    s32 base;
    s32 next;

    if (((u8) this->unk18 != 0) && ((this->unk4 > 0.0f) || ((u8) this->unk8 != 0))) {
        Tools_Ortho ortho;

        rect = MKView_GetOrthoRect();
        ox = rect[0];
        oy = rect[1];
        ow = rect[2];
        oh = rect[3];
        MKMaterial_SetMaterial(this->unkC);
        MKPrimitive(0xC, 0x10);
        MKSetMatrix(Matrix::identity);
        j = 0;
        base = 0;
        do {
            MKBegin(0x1E);
            next = (j + 1) * 0xF;
            i = 0;
            do {
                node = ((u8 *) this->unk0) + ((i + base) * 0x38);
                MKSetColorF(1.0f, 1.0f, 1.0f, this->unk4 * M2C_FIELD(node, f32 *, 0x34));
                MKSetTexCoord1F(M2C_FIELD(node, f32 *, 0x0), M2C_FIELD(node, f32 *, 0x4));
                pos.unk0 = (M2C_FIELD(node, f32 *, 0x10) * ow) + ox;
                pos.unk4 = (M2C_FIELD(node, f32 *, 0x14) * oh) + oy;
                pos.unk8 = 0.0f;
                MKSetPositionV(pos);

                node = ((u8 *) this->unk0) + ((i + next) * 0x38);
                MKSetColorF(1.0f, 1.0f, 1.0f, this->unk4 * M2C_FIELD(node, f32 *, 0x34));
                MKSetTexCoord1F(M2C_FIELD(node, f32 *, 0x0), M2C_FIELD(node, f32 *, 0x4));
                pos.unk0 = (M2C_FIELD(node, f32 *, 0x10) * ow) + ox;
                pos.unk4 = (M2C_FIELD(node, f32 *, 0x14) * oh) + oy;
                pos.unk8 = 0.0f;
                MKSetPositionV(pos);
                i += 1;
            } while (i < 0xF);
            MKEnd();
            j += 1;
            base += 0xF;
        } while (j < 0xE);
        MKEndPrimitive();
    }
    DrawScreenFlash();
}
