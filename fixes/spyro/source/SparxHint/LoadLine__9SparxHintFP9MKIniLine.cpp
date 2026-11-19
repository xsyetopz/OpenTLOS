s32 SparxHint::LoadLine(MKIniLine *arg0) {
    s32 var_r31_394;

    var_r31_394 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("Priority", (int *) &this->unk94, 0) != 0) || (arg0->LoadFloat("RadiusNotify", &this->unkA0, 0) != 0) || (arg0->LoadFloat("RadiusdeActivate", &this->unkA4, 0) != 0) || (arg0->LoadInt("NumUses", (int *) &this->unk98, 0) != 0) || (arg0->LoadInt("SpeechMode", (int *) &this->unkAC, 0) != 0) || (arg0->LoadBool("Snap", (bool *) &this->unkAB, 0) != 0) || (this->unk90.LoadLine(arg0, "OnReleaseSparx") != 0)) {
        var_r31_394 = 1;
    }
    return var_r31_394;
}
