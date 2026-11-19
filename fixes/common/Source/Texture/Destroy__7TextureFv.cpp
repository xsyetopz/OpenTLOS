void Texture::Destroy() {
    GXTexRegion *temp_r3_1155;
    s32 temp_r0_1152;
    s8 *temp_r3_1180;
    void *temp_r3_1174;

    temp_r0_1152 = this->unk2C - 1;
    this->unk2C = temp_r0_1152;
    if (temp_r0_1152 == 0) {
        temp_r3_1155 = this->unk48;
        if (temp_r3_1155 != NULL) {
            if ((u8) this->unk38 != 0) {
                ((MKHeap *) temp_r3_1155)->FreeFromAnyHeap(NULL, NULL, 0);
            } else if ((u8) M2C_FIELD(this, u8 *, 0x3C) != 0) {
                ReleasePreloadedTextureRegion(temp_r3_1155);
            }
            this->unk48 = NULL;
        }
        temp_r3_1174 = this->unk84;
        if (temp_r3_1174 != NULL) {
            M2C_FIELD(temp_r3_1174, s8 **, 0x80) = this->unk80;
        }
        temp_r3_1180 = this->unk80;
        if (temp_r3_1180 != NULL) {
            M2C_FIELD(temp_r3_1180, void **, 0x84) = this->unk84;
        }
        if ((s8 *) this == Texture_pTextures) {
            Texture_pTextures = this->unk80;
        }
        ((MKHeap *) this)->FreeFromAnyHeap(NULL, NULL, 0);
    }
}
