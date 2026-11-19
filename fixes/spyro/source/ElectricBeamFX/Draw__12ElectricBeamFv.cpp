void ElectricBeam::Draw() {
    MKVector4 color;
    f32 r;
    f32 v;

    if ((u8) this->unk1F4 != 0) {
        MKModel_SetWorldMatrix(this->unk44, *(Matrix *) ((s8 *) this + 0x1A0));
        r = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        v = (0.25f * r) + 0.75f;
        color.unk0 = v;
        color.unk4 = v;
        color.unk8 = 0.75f * r;
        color.unkC = 1.0f;
        MKMaterial_SetColor(this->unk1F0, color);
        MKModel_Draw(this->unk44, NULL);
    }
}
