void CharacterFireFX::EmitSmoke() {
    f32 vel[3];
    f32 radius;
    void **temp_r3;

    this->unk18 -= gUpdateTimeDelta;
    if (this->unk18 <= 0.0f) {
        this->unk18 = 0.1f;
        temp_r3 = (void **) (GetRandomNode(NULL));
        if (temp_r3 != NULL) {
            radius = 0.5f * M2C_FIELD(*temp_r3, f32 *, 0x10);
            vel[0] = 0.0f;
            vel[1] = 100.0f * MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
            vel[2] = 0.0f;
            gb.EmitDust(*((MKVector3 *) ((u8 *) temp_r3 + 8)), *((MKVector3 *) vel), radius, 0.0f);
        }
    }
}
