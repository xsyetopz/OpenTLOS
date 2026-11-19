void KDCameraSimpleDelta::OverrideUpdate() {
    MKVector3 sp48;
    MKVector3 sp38;
    MKVector3 sp28;
    f32 temp_f0_287;
    f32 temp_f0_295;
    f32 temp_f0_356;
    f32 temp_f0_363;
    f32 temp_f1_335;
    f32 temp_f1_344;
    f32 temp_f4_334;
    f32 var_f0_337;
    f32 var_f1_311;
    f32 var_f2_324;
    f32 var_f31_286;
    f32 var_f3_309;

    if (this->unk54 & 1) {
        var_f31_286 = this->unk14;
        temp_f0_287 = *this->unk24;
        if (var_f31_286 < temp_f0_287) {

        } else {
            var_f31_286 = temp_f0_287;
        }
        temp_f0_295 = *this->unk20;
        if (var_f31_286 > temp_f0_295) {

        } else {
            var_f31_286 = temp_f0_295;
        }
        if ((u8) this->unk44 != 0) {
            this->unk48 = GetIdealPitch();
        }
        var_f3_309 = this->unk48;
        var_f1_311 = var_f31_286 - var_f3_309;
        if (var_f1_311 < 0.0f) {
            var_f1_311 = -var_f1_311;
        }
        if (var_f1_311 > 0.0005f) {
            var_f2_324 = 0.5f * (this->unk4C * gUpdateTimeDelta);
            if (var_f2_324 < 1.0f) {

            } else {
                var_f2_324 = 1.0f;
            }
            temp_f4_334 = *this->unk24;
            temp_f1_335 = (var_f2_324 * (var_f3_309 - var_f31_286)) + var_f31_286;
            var_f0_337 = (var_f2_324 * (var_f3_309 - temp_f1_335)) + temp_f1_335;
            if (var_f0_337 < temp_f4_334) {

            } else {
                var_f0_337 = temp_f4_334;
            }
            temp_f1_344 = *this->unk20;
            if (var_f0_337 > temp_f1_344) {

            } else {
                var_f0_337 = temp_f1_344;
            }
            this->unk14 = var_f0_337;
        } else {
            temp_f0_356 = *this->unk24;
            if (var_f3_309 < temp_f0_356) {

            } else {
                var_f3_309 = temp_f0_356;
            }
            temp_f0_363 = *this->unk20;
            if (var_f3_309 > temp_f0_363) {

            } else {
                var_f3_309 = temp_f0_363;
            }
            this->unk14 = var_f3_309;
            ((KDCameraSimpleDelta::Override *) &this->unk44)->DisableSmoothPitch();
        }
    }
    if (this->unk54 & 2) {
        sp48.unk0 = 0.0f;
        sp48.unk4 = this->unk18;
        sp48.unk8 = this->unk1C;
        sp38.unk0 = 0.0f;
        sp38.unk4 = this->unk4;
        sp38.unk8 = this->unk8;
        KDMath_CriticalDamp<MKVector3>(sp28, sp48, sp38, this->unk50, gUpdateTimeDelta);
        sp48.unk0 += sp28.unk0;
        sp48.unk4 += sp28.unk4;
        sp48.unk8 += sp28.unk8;
        this->unk18 = sp48.unk4;
        this->unk1C = sp48.unk8;
        if (IsUsingIdealDelta() != 0) {
            ((KDCameraSimpleDelta::Override *) &this->unk44)->DisableSmoothDelta();
        }
    }
}
