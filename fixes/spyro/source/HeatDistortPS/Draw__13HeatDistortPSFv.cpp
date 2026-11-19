f32 Xform3D2D(MKVector3 *, const MKVector3 &, Matrix *);
s32 DistortParticleCompare(const void *, const void *);
extern "C" M2C_UNK qsort(void *, M2C_UNK, M2C_UNK, s32 (*)(const void *, const void *));

void HeatDistortPS::Draw() {
    Matrix worldToScreen;
    Matrix camera;
    Matrix particle;
    MKVector3 sp50;
    void *p;
    f32 sp20;
    f32 sp24;
    f32 sp28;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 posX;
    f32 posY;
    f32 posZ;
    s32 i;
    s32 off;

    M2C_STRUCT_COPY(&camera, MKView_GetCameraMatrix(), 0x40);
    M2C_STRUCT_COPY(&worldToScreen, MKView_GetWorldToScreenMatrix(), 0x40);
    i = 0;
    off = 0;
    while (i < (s32) this->unkC) {
        M2C_STRUCT_COPY(&particle, &camera, 0x40);
        particle.Scale3x3(&particle, M2C_FIELD(M2C_FIELD(this->unk8, void **, off), f32 *, 0x50));
        p = M2C_FIELD(this->unk8, void **, off);
        posX = M2C_FIELD(p, f32 *, 0x0);
        particle.unk30 = posX;
        posY = M2C_FIELD(p, f32 *, 0x4);
        particle.unk34 = posY;
        posZ = M2C_FIELD(p, f32 *, 0x8);
        particle.unk38 = posZ;
        particle.unk3C = 1.0f;

        sp20 = posX + ((this->unk10.unk8 * particle.unk20) + ((this->unk10.unk0 * particle.unk0) + (this->unk10.unk4 * particle.unk10)));
        sp24 = posY + ((this->unk10.unk8 * particle.unk24) + ((this->unk10.unk0 * particle.unk4) + (this->unk10.unk4 * particle.unk14)));
        sp28 = posZ + ((this->unk10.unk8 * particle.unk28) + ((this->unk10.unk0 * particle.unk8) + (this->unk10.unk4 * particle.unk18)));
        sp50.unk0 = sp20;
        sp50.unk4 = sp24;
        sp50.unk8 = sp28;
        M2C_FIELD(p, f32 *, 0x5C) = Xform3D2D((MKVector3 *) ((s8 *) p + 0x10), sp50, &worldToScreen);

        sp10 = particle.unk30 + ((this->unk40.unk8 * particle.unk20) + ((this->unk40.unk0 * particle.unk0) + (this->unk40.unk4 * particle.unk10)));
        sp14 = particle.unk34 + ((this->unk40.unk8 * particle.unk24) + ((this->unk40.unk0 * particle.unk4) + (this->unk40.unk4 * particle.unk14)));
        sp18 = particle.unk38 + ((this->unk40.unk8 * particle.unk28) + ((this->unk40.unk0 * particle.unk8) + (this->unk40.unk4 * particle.unk18)));
        sp50.unk0 = sp10;
        sp50.unk4 = sp14;
        sp50.unk8 = sp18;
        Xform3D2D((MKVector3 *) ((s8 *) p + 0x20), sp50, &worldToScreen);

        i += 1;
        off += 4;
    }
    qsort(this->unk8, this->unkC, 4, DistortParticleCompare);
    MKMaterial_SetMaterial(this->unk0);
    MKPrimitive(0xC, 0x10);
    i = 0;
    off = 0;
    while (i < (s32) this->unkC) {
        p = M2C_FIELD(this->unk8, void **, off);
        if (M2C_FIELD(p, f32 *, 0x5C) > 800.0f) {
            DrawParticle((HeatDistortPS::DistortParticle *) p, &camera);
        }
        i += 1;
        off += 4;
    }
    MKEndPrimitive();
}
