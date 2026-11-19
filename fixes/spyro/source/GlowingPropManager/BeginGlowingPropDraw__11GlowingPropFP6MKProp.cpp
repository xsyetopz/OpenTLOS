void GlowingProp::BeginGlowingPropDraw(MKProp *arg0) {
    MKVector4 *color;
    MKVector4 sp10;
    MKVector4 sp20;
    f64 temp_f1_223;
    f64 temp_f1_229;
    f64 temp_f1_233;
    f32 sp8;
    f32 var_f0_308;
    f32 var_f1_292;
    f32 var_f30_219;
    f32 var_f31_318;
    s32 temp_r3_252;
    s32 var_r0_262;

    if ((u8) this->unk14 != 0) {
        var_f30_219 = arg0->unk24;
        if (var_f30_219 > 0.0f) {
            temp_f1_223 = __frsqrte(var_f30_219);
            temp_f1_229 = 0.5 * temp_f1_223 * -(((f64) var_f30_219 * (temp_f1_223 * temp_f1_223)) - 3.0);
            temp_f1_233 = 0.5 * temp_f1_229 * -(((f64) var_f30_219 * (temp_f1_229 * temp_f1_229)) - 3.0);
            var_f30_219 = (f32) ((f64) var_f30_219 * (0.5 * temp_f1_233 * -(((f64) var_f30_219 * (temp_f1_233 * temp_f1_233)) - 3.0)));
        } else if (var_f30_219 < 0.0f) {
            var_f30_219 = __float_nan;
        } else {
            sp8 = var_f30_219;
            temp_r3_252 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_252) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_262 = 1;
                } else {
                    var_r0_262 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_262 = 5;
                } else {
                    var_r0_262 = 3;
                }
                break;
            default:
                var_r0_262 = 4;
                break;
            }
            if (var_r0_262 == 1) {
                var_f30_219 = __float_nan;
            }
        }
        if ((var_f30_219 > 1500.0f) && (GlowingPropManager::AddProp((MKProp *) &gGlowingPropManager) != 0)) {
            var_f1_292 = var_f30_219 - 1500.0f;
            if (var_f1_292 < 1500.0f) {

            } else {
                var_f1_292 = 1500.0f;
            }
            if (var_f1_292 > 0.0f) {

            } else {
                var_f1_292 = 0.0f;
            }
            var_f0_308 = var_f1_292 / 1500.0f;
            if (var_f0_308 < 1.0f) {

            } else {
                var_f0_308 = 1.0f;
            }
            if (var_f0_308 > 0.0f) {
                var_f31_318 = var_f0_308;
            } else {
                var_f31_318 = 0.0f;
            }
            color = (MKVector4 *) MKMaterial_GetColor(this->unk10);
            *((MKVector4 *) this) = *color;
            sp10.unk0 = ((MKVector4 *) this)->unk0 * var_f31_318;
            sp10.unk4 = ((MKVector4 *) this)->unk4 * var_f31_318;
            sp10.unk8 = ((MKVector4 *) this)->unk8 * var_f31_318;
            sp10.unkC = ((MKVector4 *) this)->unkC * var_f31_318;
            sp20 = sp10;
            MKMaterial_SetColor(this->unk10, sp20);
            gRenderState = this->unk10;
        }
    }
}
