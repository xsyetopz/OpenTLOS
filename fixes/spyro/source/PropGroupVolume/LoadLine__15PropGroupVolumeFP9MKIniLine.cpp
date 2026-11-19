s32 PropGroupVolume::LoadLine(MKIniLine *arg0) {
    s32 var_r31_445;

    var_r31_445 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("enableZone", (int *) &this->unkA0, 0) != 0) || (this->unk50.LoadLine((char *) "region", arg0) != 0) || (arg0->LoadFloat("distanceMultiplier", &this->unk2A8, 0) != 0) || (arg0->LoadBool("bShowEnvDome", (bool *) &this->unk2AC, 0) != 0) || (arg0->LoadBool("bEnabled", (bool *) &this->unk2AD, 0) != 0) || (LoadOverlayName(arg0) != 0)) {
        var_r31_445 = 1;
    }
    return var_r31_445;
}
