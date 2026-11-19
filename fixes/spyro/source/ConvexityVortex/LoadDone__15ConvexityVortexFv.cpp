s32 ConvexityVortex::LoadDone() {
    MKProp::LoadDone();
    {
        u32 *dst = (u32 *) &this->unk60;
        u32 *src = (u32 *) &Matrix::identity;
        s32 i;

        for (i = 0; i < 8; i++) {
            dst[0] = src[0];
            dst[1] = src[1];
            dst += 2;
            src += 2;
        }
    }
    this->unk90 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x40);
    this->unk94 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x44);
    this->unk98 = MKProp::loadInfo.unk48;
    this->unk9C = 1.0f;
    /* r3 still holds &MKProp::loadInfo at blr. */
    return (s32) &MKProp::loadInfo;
}
