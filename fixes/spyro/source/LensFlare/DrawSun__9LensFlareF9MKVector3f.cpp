void LensFlare::DrawSun(MKVector3 arg0, float arg1) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;
    f32 intensity;
    f32 radius;
    f32 halfSize;
    f32 size;

    dy = arg0.unk4 - this->unk44;
    dx = arg0.unk0 - this->unk40;
    dz = arg0.unk8 - this->unk48;
    dist = (dz * dz) + ((dx * dx) + (dy * dy));
    radius = 102.4f;
    intensity = 0.0f;
    MKMaterial_SetMaterial(this->unk4);
    MKPrimitive(0xC, 0);
    if (dist < 102400.0f) {
        halfSize = 640.0f * this->unk90;
        intensity = arg1 * (1.0f - (dist / 102400.0f));
        radius = (64.0f * intensity) + 102.4f;
        MKBegin(4);
        MKSetColorF(intensity, intensity, intensity, 1.0f);
        MKSetTexCoord1F(0.0f, 0.0f);
        MKSetPositionF(arg0.unk0 - halfSize, arg0.unk4 - halfSize, 0.0f);
        MKSetTexCoord1F(0.0f, 1.0f);
        MKSetPositionF(arg0.unk0 - halfSize, arg0.unk4 + halfSize, 0.0f);
        MKSetTexCoord1F(1.0f, 0.0f);
        MKSetPositionF(arg0.unk0 + halfSize, arg0.unk4 - halfSize, 0.0f);
        MKSetTexCoord1F(1.0f, 1.0f);
        MKSetPositionF(arg0.unk0 + halfSize, arg0.unk4 + halfSize, 0.0f);
        MKEnd();
    }
    size = radius * this->unk8C;
    MKBegin(4);
    MKSetColorF(intensity, intensity, intensity, 1.0f);
    MKSetTexCoord1F(0.0f, 0.0f);
    MKSetPositionF(arg0.unk0 - size, arg0.unk4 - size, 0.0f);
    MKSetTexCoord1F(0.0f, 1.0f);
    MKSetPositionF(arg0.unk0 - size, arg0.unk4 + size, 0.0f);
    MKSetTexCoord1F(1.0f, 0.0f);
    MKSetPositionF(arg0.unk0 + size, arg0.unk4 - size, 0.0f);
    MKSetTexCoord1F(1.0f, 1.0f);
    MKSetPositionF(arg0.unk0 + size, arg0.unk4 + size, 0.0f);
    MKEnd();
    MKEndPrimitive();
}
