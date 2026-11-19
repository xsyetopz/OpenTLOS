extern "C" f64 fabs(f64);
extern "C" f64 acos(f64);
void KDParticleEmitter::InitPointParticleParameters(KDParticleEmitter *arg0, MKParticle *arg1) {
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix *temp_r3_176;
    f32 temp_f0_303;
    f32 temp_f1_178;
    f32 temp_f29_274;
    f32 temp_f2_177;
    f32 temp_f2_287;
    f32 temp_f30_269;
    f32 temp_f31_263;
    f32 temp_f3_180;
    f32 var_f4_184;
    f64 temp_f1_187;
    f64 temp_f1_193;
    f64 temp_f1_197;
    f64 temp_f31_247;
    s32 temp_r3_216;
    s32 var_r0_226;
    void *temp_r31_164;

    arg0->unk24 = MKRand_Float((int *) &gViewSeed, this->unk58, this->unk54);
    temp_r31_164 = arg0->unk2C;
    M2C_FIELD(temp_r31_164, f32 *, 0x14) = M2C_FIELD(this->unk28, f32 *, 0xF4);
    M2C_FIELD(temp_r31_164, f32 *, 0) = 0.0f;
    M2C_FIELD(temp_r31_164, f32 *, 4) = 0.0f;
    M2C_FIELD(temp_r31_164, f32 *, 8) = 0.0f;
    M2C_FIELD(temp_r31_164, f32 *, 0x10) = 0.0f;
    M2C_FIELD(temp_r31_164, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, this->unk60, this->unk5C);
    temp_r3_176 = this->unk70;
    temp_f2_177 = temp_r3_176->unk0;
    temp_f1_178 = temp_r3_176->unk4;
    temp_f3_180 = temp_r3_176->unk8;
    var_f4_184 = (temp_f3_180 * temp_f3_180) + ((temp_f2_177 * temp_f2_177) + (temp_f1_178 * temp_f1_178));
    if (var_f4_184 > 0.0f) {
        temp_f1_187 = __frsqrte(var_f4_184);
        temp_f1_193 = 0.5 * temp_f1_187 * -(((f64) var_f4_184 * (temp_f1_187 * temp_f1_187)) - 3.0);
        temp_f1_197 = 0.5 * temp_f1_193 * -(((f64) var_f4_184 * (temp_f1_193 * temp_f1_193)) - 3.0);
        var_f4_184 = (f32) ((f64) var_f4_184 * (0.5 * temp_f1_197 * -(((f64) var_f4_184 * (temp_f1_197 * temp_f1_197)) - 3.0)));
    } else if (var_f4_184 < M2C_BITWISE(f32, 0.0)) {
        var_f4_184 = __float_nan;
    } else {
        sp8 = var_f4_184;
        temp_r3_216 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_216) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_226 = 1;
            } else {
                var_r0_226 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_226 = 5;
            } else {
                var_r0_226 = 3;
            }
            break;
        default:
            var_r0_226 = 4;
            break;
        }
        if (var_r0_226 == 1) {
            var_f4_184 = __float_nan;
        }
    }
    temp_f31_247 = fabs(var_f4_184);
    M2C_FIELD(temp_r31_164, f32 *, 0x18) = (f32) ((f32) temp_f31_247 * MKRand_Float((int *) &gViewSeed, this->unk68, this->unk64));
    if (this->unk38 > 0.0f) {
        temp_f31_263 = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        temp_f30_269 = (f32) acos(MKRand_Float((int *) &gViewSeed, this->unk3C, 1.0f));
        temp_f29_274 = -MKRand_Float((int *) &gViewSeed, this->unk50, this->unk4C);
        _table_sincosf(temp_f30_269, sp18, sp14);
        _table_sincosf(temp_f31_263, sp10, spC);
        temp_f2_287 = sp18 * temp_f29_274;
        M2C_FIELD(temp_r31_164, f32 *, 8) = (f32) (sp14 * temp_f29_274);
        M2C_FIELD(temp_r31_164, f32 *, 4) = (f32) (sp10 * temp_f2_287);
        M2C_FIELD(temp_r31_164, f32 *, 0) = (f32) (spC * temp_f2_287);
        M2C_FIELD(temp_r31_164, f32 *, 0xC) = 0.0f;
        return;
    }
    temp_f0_303 = -MKRand_Float((int *) &gViewSeed, this->unk50, this->unk4C);
    M2C_FIELD(temp_r31_164, f32 *, 0) = 0.0f;
    M2C_FIELD(temp_r31_164, f32 *, 4) = 0.0f;
    M2C_FIELD(temp_r31_164, f32 *, 8) = temp_f0_303;
}
