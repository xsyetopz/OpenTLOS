void FuryFXEarth2::ResetFury() {
    ManagedLight *temp_r4_73;
    u32 temp_r4_61;
    void *temp_r3_58;
    void *var_r5_55;

    SetDefaults();
    var_r5_55 = this->unkC0;
loop_2:
    if ((var_r5_55 != NULL) && ((u32) *(u32 *) var_r5_55 != 0U)) {
        temp_r3_58 = this->unkC0;
        this->unkC0 = ((u8 *) temp_r3_58) + 4;
        temp_r4_61 = *(u32 *) temp_r3_58;
        *(u32 *) temp_r3_58 = *(u32 *) var_r5_55;
        *(u32 *) var_r5_55 = temp_r4_61;
        var_r5_55 = ((u8 *) var_r5_55) + 4;
        goto loop_2;
    }
    temp_r4_73 = (ManagedLight *) this->unkCC;
    if (temp_r4_73 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_73, 0U);
    }
    ExplodeVortex();
}
