s32 SolidSlugDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_461;

    var_r31_461 = 0;
    if ((ProjectileDescriptor::LoadLine(arg0) != 0) || (arg0->LoadBool("PlayHitMissSounds", (bool *) &this->unkF0, 0) != 0) || (KDSound_LoadLine(arg0, "sndMiss", (int *) &this->unkF4) != 0)) {
        var_r31_461 = 1;
    }
    return var_r31_461;
}
