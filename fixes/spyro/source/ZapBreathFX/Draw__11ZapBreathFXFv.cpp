void ZapBreathFX::Draw() {
    s32 var_r30;
    s32 var_r31;

    if (EventCamera_GetCurrent() == NULL) {
        var_r30 = 0;
        var_r31 = 0;
        while (var_r30 < this->unk9FC) {
            ((ElectricBeam *) ((u8 *) this + var_r31 + 0x1C0))->Draw();
            var_r30 += 1;
            var_r31 += 0x200;
        }
    }
}
