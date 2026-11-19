void EarthBombFXDescriptor::Init() {
    FallingLeaves *leaves;

    GamePropDescriptor::Init();
    leaves = checked_cast<FallingLeaves *, MKProp>(((MKSceneManager *) gMK)->CreateProp("FallingGlowLeaves"));
    M2C_FIELD(this, FallingLeaves **, 0xE4) = leaves;
    this->unkE8 = (long) (checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("EarthBeamBlastPS")));
    this->unkEC = (MKMaterial *) (MKMaterial_Create("fx_EarthBomb"));
}
