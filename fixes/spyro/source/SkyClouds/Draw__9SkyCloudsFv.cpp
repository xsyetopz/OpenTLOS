s32 CloudParticleCompare(const void *, const void *);
void SkyClouds::Draw() {
    typedef struct { s32 w[16]; } Words16;
    Matrix sp10 __attribute__((aligned(16)));
    Matrix *camera;
    s32 off;
    s32 i;

    qsort(this->unk54, this->unk4C, 4, (s32 (*)(void *, void *)) CloudParticleCompare);
    camera = MKView_GetCameraMatrix();
    *(Words16 *) &sp10 = *(Words16 *) camera;
    MKMaterial_SetMaterial(this->unk58);
    MKPrimitive(0xC, 0);
    i = 0;
    off = 0;
    while (i < (s32) this->unk4C) {
        DrawCloudlet(*(SkyClouds::CloudParticle **) ((u8 *) this->unk54 + off), &sp10);
        i += 1;
        off += 4;
    }
    MKEndPrimitive();
}
