extern "C" f64 fmod(f64, f64);

void Updater_Scroll(MKMaterial *arg0, void *arg1) {
    f32 temp_f0_485;
    f32 temp_f1_474;
    f32 temp_f28_500;
    f32 temp_f29_498;
    f32 temp_f30_481;
    f32 temp_f31_480;
    f32 var_f2_484;
    void *temp_r3_475;

    temp_f1_474 = M2C_FIELD(arg1, f32 *, 8);
    temp_r3_475 = arg0->unk24;
    temp_f31_480 = M2C_FIELD(temp_r3_475, f32 *, 0x148);
    temp_f30_481 = M2C_FIELD(temp_r3_475, f32 *, 0x14C);
    if (temp_f1_474 > 0.0f) {
        var_f2_484 = 0.0f;
        temp_f0_485 = temp_f1_474 - gUpdateTimeDelta;
        if (var_f2_484 > temp_f0_485) {

        } else {
            var_f2_484 = temp_f0_485;
        }
        M2C_FIELD(arg1, f32 *, 8) = var_f2_484;
    } else {
        temp_f29_498 = (M2C_FIELD(temp_r3_475, f32 *, 0x140) * gUpdateTimeDelta) + M2C_FIELD(arg1, f32 *, 0);
        temp_f28_500 = (M2C_FIELD(temp_r3_475, f32 *, 0x144) * gUpdateTimeDelta) + M2C_FIELD(arg1, f32 *, 4);
        M2C_FIELD(arg1, f32 *, 0) = (f32) fmod(temp_f29_498, 1.0);
        M2C_FIELD(arg1, f32 *, 4) = (f32) fmod(temp_f28_500, 1.0);
        if (temp_f29_498 != M2C_FIELD(arg1, f32 *, 0)) {
            M2C_FIELD(arg1, f32 *, 8) = temp_f31_480;
        } else if (temp_f28_500 != M2C_FIELD(arg1, f32 *, 4)) {
            M2C_FIELD(arg1, f32 *, 8) = temp_f30_481;
        }
    }
    ((Matrix *) ((u8 *) arg0->unk24 + 0x40))->SetIdentity();
    M2C_FIELD(arg0->unk24, f32 *, 0x70) = (f32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0->unk24, f32 *, 0x74) = (f32) M2C_FIELD(arg1, f32 *, 4);
}
