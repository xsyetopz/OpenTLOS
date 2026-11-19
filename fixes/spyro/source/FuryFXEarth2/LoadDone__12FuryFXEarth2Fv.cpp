s32 FuryFXEarth2::LoadDone() {
    void **temp_r6_2089;
    void *temp_r31_2091;

    KDProp::LoadDone();
loop_2:
    if ((u32) M2C_FIELD(this->unkC0, u32 *, -4) != 0U) {
        temp_r6_2089 = (void **) (((u8 *) this->unkC0) - 4);
        this->unkC0 = temp_r6_2089;
        temp_r31_2091 = *temp_r6_2089;
        M2C_FIELD(temp_r31_2091, s32 *, 0x40) = MKRand_Int((int *) &gViewSeed, 0, 4);
        goto loop_2;
    }
loop_5:
    if ((u32) M2C_FIELD(this->unkC0, u32 *, 0) != 0U) {
        this->unkC0 = ((u8 *) this->unkC0) + 4;
        goto loop_5;
    }
    return (s32) this->unkC0;
}
