void *LightProp::Update() {
    f64 sp20;
    f64 sp18;
    MKVector4 sp8;
    ManagedLight *temp_r3_142;
    ManagedLight *temp_r4_125;
    void *temp_r3_145;

    temp_r4_125 = this->unkC8;
    if (temp_r4_125 != NULL) {
        sp18 = temp_r4_125->unk20;
        sp20 = temp_r4_125->unk28;
        KDMath_Smooth<MKVector4>(sp8, *((MKVector4 *) &sp18), 0.25f, 1.0f);
        sp18 = M2C_FIELD(&sp8, f64 *, 0);
        sp20 = M2C_FIELD(&sp8, f64 *, 8);
        temp_r3_142 = this->unkC8;
        temp_r3_142->unk20 = sp18;
        temp_r3_142->unk28 = sp20;
        temp_r3_145 = temp_r3_142->unk3C;
        if (temp_r3_145 != NULL) {
            M2C_FIELD(temp_r3_145, f64 *, 0) = sp18;
            M2C_FIELD(temp_r3_145, f64 *, 8) = sp20;
        }
    }
}
