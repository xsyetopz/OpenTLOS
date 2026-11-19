void KDDropShadow::Draw() {
    KDDropShadowDescriptor *desc;
    Matrix *var_r31_61;
    Matrix *var_r3_104;
    Matrix *var_r3_53;
    f32 temp_f1_70;
    f32 temp_f1_84;
    f32 temp_f1_91;
    f32 temp_f3_98;

    desc = checked_cast<KDDropShadowDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    MKMaterial_SetMaterial(M2C_FIELD(desc, MKMaterial **, 0x38));
    MKPrimitive(0xC, 0x10);
    var_r3_53 = this->unk50;
    if (var_r3_53 != (Matrix *) this->unk54) {

    } else {
        var_r3_53 = NULL;
    }
    var_r31_61 = var_r3_53;
    while (var_r31_61 != NULL) {
        MKSetMatrix(*var_r31_61);
        MKBegin(4);
        temp_f1_70 = -M2C_FIELD(var_r31_61, f32 *, 0x40);
        MKSetPositionF(temp_f1_70, 1.0f, temp_f1_70);
        MKSetTexCoord1F(1.0f, 0.0f);
        MKSetColorF(1.0f, 1.0f, 1.0f, M2C_FIELD(var_r31_61, f32 *, 0x44));
        MKSetTexCoord1F(0.0f, 0.0f);
        temp_f1_84 = M2C_FIELD(var_r31_61, f32 *, 0x40);
        MKSetPositionF(temp_f1_84, 1.0f, -temp_f1_84);
        MKSetTexCoord1F(1.0f, 1.0f);
        temp_f1_91 = M2C_FIELD(var_r31_61, f32 *, 0x40);
        MKSetPositionF(temp_f1_91, 1.0f, temp_f1_91);
        MKSetTexCoord1F(0.0f, 1.0f);
        temp_f3_98 = M2C_FIELD(var_r31_61, f32 *, 0x40);
        MKSetPositionF(-temp_f3_98, 1.0f, temp_f3_98);
        MKEnd();
        var_r3_104 = (Matrix *) ((u8 *) var_r31_61 + 0x50);
        if (var_r3_104 >= (Matrix *) this->unk54) {
            var_r3_104 = NULL;
        }
        var_r31_61 = var_r3_104;
    }
    this->unk50 = this->unk54;
    MKEndPrimitive();
}
