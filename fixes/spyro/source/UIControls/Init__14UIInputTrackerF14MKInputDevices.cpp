void UIInputTracker::Init(MKInputDevices arg0) {
    s8 *base;
    s32 temp_r0_597;
    s32 var_ctr_594;
    s32 var_r4_591;
    s32 var_r7_592;

    this->unk0 = (s32) arg0;
    this->unk4 = 0;
    var_r4_591 = 0;
    var_r7_592 = 0;
    this->unk5 = 0;
    base = (s8 *) this;
    for (var_ctr_594 = 0; var_ctr_594 < 4; var_ctr_594++) {
        temp_r0_597 = var_r7_592 + 0x18;
        *(f32 *) (base + (var_r4_591 + 8)) = 0.0f;
        var_r7_592 += 1;
        var_r4_591 += 4;
        M2C_FIELD(base + temp_r0_597, u8 *, 0) = 0;
    }
    this->unk1C = 0;
    M2C_FIELD(base, u8 *, 0x1D) = 0;
}
