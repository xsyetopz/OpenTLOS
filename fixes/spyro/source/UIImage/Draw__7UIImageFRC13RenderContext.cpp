void UIImage::Draw(const RenderContext &arg0) {
    RenderContext sp90;
    f32 sp20[3];
    f32 sp30[3];
    f32 sp40[3];
    f32 sp50[3];
    f32 sp60[3];
    f32 sp70[3];
    f32 sp80[3];
    f32 var_f1_32;
    f32 var_f1_51;
    s32 temp_r3_29;
    s32 temp_r3_48;

    sp90.AddState(arg0, this->unk18);
    if (this->unk18.unk40 & 0x20) {
        temp_r3_29 = this->unk18.unk3C;
        if (!(temp_r3_29 & 0xC)) {
            var_f1_32 = 0.0f;
        } else if (temp_r3_29 & 4) {
            var_f1_32 = -0.5f * this->unk18.unk38;
        } else {
            var_f1_32 = -this->unk18.unk38;
        }
        sp20[0] = M2C_FIELD(&sp90, f32 *, 0x10) * var_f1_32;
        sp20[1] = M2C_FIELD(&sp90, f32 *, 0x14) * var_f1_32;
        sp20[2] = M2C_FIELD(&sp90, f32 *, 0x18) * var_f1_32;
        temp_r3_48 = this->unk18.unk3C;
        if (!(temp_r3_48 & 3)) {
            var_f1_51 = 0.0f;
        } else if (temp_r3_48 & 1) {
            var_f1_51 = -0.5f * this->unk18.unk34;
        } else {
            var_f1_51 = -this->unk18.unk34;
        }
        sp30[0] = M2C_FIELD(&sp90, f32 *, 0x0) * var_f1_51;
        sp30[1] = M2C_FIELD(&sp90, f32 *, 0x4) * var_f1_51;
        sp30[2] = M2C_FIELD(&sp90, f32 *, 0x8) * var_f1_51;
        sp40[0] = sp30[0] + sp20[0];
        sp40[1] = sp30[1] + sp20[1];
        sp40[2] = sp30[2] + sp20[2];
        ((Matrix *) &sp90)->Translate((Matrix *) &sp90, *((MKVector3 *) sp40));
    }
    sp50[0] = 0.0f;
    sp50[1] = 0.0f;
    sp50[2] = 0.0f;
    sp60[0] = this->unk18.unk34;
    sp60[1] = 0.0f;
    sp60[2] = 0.0f;
    sp70[0] = 0.0f;
    sp70[1] = this->unk18.unk38;
    sp70[2] = 0.0f;
    sp80[0] = this->unk18.unk34;
    sp80[1] = this->unk18.unk38;
    sp80[2] = 0.0f;
    if (this->unk64 != NULL) {
        MKMaterial_SetMaterial(this->unk64);
    } else {
        MKMaterial_SetMaterial(gpMKWhiteMaterial);
    }
    MKPrimitive(0xC, 1);
    MKSetMatrix(*((Matrix *) &sp90));
    MKBegin(4);
    MKSetColorV(*((MKVector4 *) &sp90.unk40));
    MKSetTexCoord1F(this->unk68, this->unk6C);
    MKSetPositionV(*((MKVector3 *) sp50));
    MKSetTexCoord1F(this->unk70, this->unk6C);
    MKSetPositionV(*((MKVector3 *) sp60));
    MKSetTexCoord1F(this->unk68, this->unk74);
    MKSetPositionV(*((MKVector3 *) sp70));
    MKSetTexCoord1F(this->unk70, this->unk74);
    MKSetPositionV(*((MKVector3 *) sp80));
    MKEnd();
    MKEndPrimitive();
}
