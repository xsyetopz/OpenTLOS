void FuryFXFire::Init() {
    s32 var_r29_3123;
    s32 var_r31_3124;

    ((FuryFX *) this)->FuryFX::Init();
    SetDefaults();
    this->unkE0 = (MKMaterial *) (MKMaterial_Create("FX_FlameWall"));
    this->unkE8 = NULL;
    this->unkF0 = MKModel_Create("Fx0019_FireFuryBlast", NULL, 2, NULL);
    this->unkF8 = -1.0f;
    this->unkFC = 0.0f;
    this->unkEC = MKModel_Create("IceShard", NULL, 2, NULL);
    var_r29_3123 = 0;
    var_r31_3124 = 0;
    do {
        ((MKSceneManager *) gMK)->CreatePropDeferred("ShapedTrailFX", (MKProp **) ((u8 *) this + var_r31_3124 + 0x130));
        var_r29_3123 += 1;
        var_r31_3124 += 0x80;
    } while (var_r29_3123 < 3);
    this->unk2E8 = -1;
    this->unkE4 = (MKMaterial *) (MKMaterial_Create("fx_cynderFuryFlame"));
}
