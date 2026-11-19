s32 UIProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_271;

    var_r31_271 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("stringTableSize", (int *) &this->unk4C, 0) != 0) || (arg0->LoadString("fileName", (const char **) &this->unk50, 0) != 0)) {
        var_r31_271 = 1;
    }
    return var_r31_271;
}
