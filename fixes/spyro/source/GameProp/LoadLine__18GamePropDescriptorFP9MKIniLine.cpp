s32 GamePropDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_794;

    var_r31_794 = 0;
    if ((KDPropExDescriptor::LoadLine(arg0) != 0) || (PropTypes_LoadLine(arg0, (char *) "searchMask", (int *) &this->unkC) != 0) || (arg0->LoadString("animHit", (const char **) &this->unkC0, 0) != 0) || (KDSound_LoadLine(arg0, "sndHitHero", (int *) &this->unkDC) != 0) || (arg0->LoadString("animEnable", (const char **) &this->unkC4, 0) != 0) || (arg0->LoadString("animDisable", (const char **) &this->unkC8, 0) != 0) || (KDSound_LoadLine(arg0, "soundLoop01", (int *) &this->unkD0.unk0) != 0) || (KDSound_LoadLine(arg0, "soundLoop02", (int *) &this->unkD4) != 0) || (KDSound_LoadLine(arg0, "soundLoop03", (int *) &this->unkD8) != 0) || (arg0->LoadBool("CanFreeze", (bool *) ((u8 *) this + 0xE1), 0) != 0) || (arg0->LoadBool("CanBurn", (bool *) &this->unkE0, 0) != 0) || (arg0->LoadFloat("pointLightRadius", (f32 *) &this->unkCC, 0) != 0)) {
        var_r31_794 = 1;
    }
    return var_r31_794;
}
