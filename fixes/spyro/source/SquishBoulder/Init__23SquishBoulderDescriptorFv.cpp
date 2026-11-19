void SquishBoulderDescriptor::Init() {
    KDEnvParticleSystem *beam;
    FallingLeaves *leaves;

    ShatterableDescriptor::Init();
    beam = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("EarthBeamBlastPS"));
    M2C_FIELD(this, KDEnvParticleSystem **, 0x16C) = beam;
    leaves = checked_cast<FallingLeaves *, MKProp>(gMK->CreateProp("FallingGlowLeaves"));
    M2C_FIELD(this, FallingLeaves **, 0x170) = leaves;
    M2C_FIELD(this, FallingLeaves **, 0x170)->Reset();
    M2C_FIELD(this, FallingLeaves **, 0x170)->Enable();
}
