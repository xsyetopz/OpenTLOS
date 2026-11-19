void ElectricFence::FreeBeams() {
    s32 temp_r28_158;
    s32 var_r27_156;
    s32 var_r31_153;
    ElectricFenceDescriptor *desc;

    var_r31_153 = 0;
    desc = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r27_156 = 0;
    do {
        temp_r28_158 = var_r31_153 + 0xD0;
        ((EnergyBeam *) desc->unk80)->FreeEnergyBeam(M2C_FIELD(this, EnergyBeam::Beam **, temp_r28_158));
        var_r27_156 += 1;
        M2C_FIELD(this, EnergyBeam::Beam **, temp_r28_158) = NULL;
        var_r31_153 += 0x18;
    } while (var_r27_156 < 2);
}
