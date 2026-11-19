s32 WobblePropDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_472;

    var_r31_472 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("HitSoundSensitivity", &M2C_FIELD(this, f32 *, 0xE8), 0) != 0) || (arg0->LoadString("LampFlickerMatName", (const char **) &M2C_FIELD(this, s8 **, 0xEC), 0) != 0) || (KDSound_LoadLine(arg0, "hitSound", (int *) &M2C_FIELD(this, s32 *, 0xE4)) != 0)) {
        var_r31_472 = 1;
    }
    return var_r31_472;
}
