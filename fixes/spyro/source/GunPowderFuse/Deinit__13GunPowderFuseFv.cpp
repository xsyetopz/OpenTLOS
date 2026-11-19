void GunPowderFuse::Deinit() {
    Corona *temp_r4;
    s32 i;
    u8 *p;

    if (this->unk2A4 != NULL) {
        MKMaterial_Destroy(this->unk2A4);
    }
    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        KDSound_Stop((int *) (p + 0xD8));
        temp_r4 = M2C_FIELD(p, Corona **, 0xC4);
        if (temp_r4 != NULL) {
            ((Coronas *) gb.unk64)->Free(temp_r4);
        }
    }
    SplineProp::Deinit();
}
