void FootStepFX::Draw() {
    f32 proj;
    f32 alpha;
    MKVector4 color;
    s32 pass;
    s32 idx;
    s32 count;
    s32 first;
    s32 prev;
    s32 n;
    s32 k;
    s32 off;

    if ((u8) this->unk60 != 0) {
        MKView_Push();
        MKView_GetProjection(NULL, &proj, NULL);
        proj = proj + 0.05f;
        MKView_SetProjection(0.0f, proj, 0.0f);
        MKSetMatrix(Matrix::identity);
        alpha = 1.0f;
        pass = 0;
        first = this->unk54;
        do {
            if (pass == 0) {
                MKMaterial_SetMaterial(this->unk5C);
            } else {
                MKMaterial_SetMaterial(this->unk58);
            }
            MKPrimitive(0xC, 0x10);
            idx = first;
            count = 0;
            while (idx != this->unk50) {
                prev = this->unk54 - 1;
                if (prev < 0) {
                    prev = 0x1D;
                }
                if (this->unk50 == prev) {
                    n = lit_523;
                    if (count < n) {
                        n = count;
                    }
                    k = lit_522;
                    if (n > k) {
                        k = n;
                    }
                    alpha = 0.5f * ((f32) k / 15.0f);
                }
                MKBegin(4);
                color.unk0 = alpha;
                color.unk4 = alpha;
                color.unk8 = alpha;
                color.unkC = 1.0f;
                MKSetColorV(color);
                MKSetTexCoord1F(0.0f, 1.0f);
                off = idx << 6;
                MKSetPositionV(*(MKVector3 *) ((u8 *) this->unk4C + off));
                MKSetTexCoord1F(1.0f, 1.0f);
                MKSetPositionV(*(MKVector3 *) ((u8 *) this->unk4C + off + 0x10));
                MKSetTexCoord1F(0.0f, 0.0f);
                MKSetPositionV(*(MKVector3 *) ((u8 *) this->unk4C + off + 0x20));
                MKSetTexCoord1F(1.0f, 0.0f);
                MKSetPositionV(*(MKVector3 *) ((u8 *) this->unk4C + off + 0x30));
                MKEnd();
                idx += 1;
                if (idx >= 0x1E) {
                    idx = 0;
                }
                count += 1;
            }
            MKEndPrimitive();
            pass += 1;
        } while (pass < 2);
        MKView_Pop();
    }
}
