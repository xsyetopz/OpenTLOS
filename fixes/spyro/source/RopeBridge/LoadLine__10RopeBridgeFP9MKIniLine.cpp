s32 RopeBridge::LoadLine(MKIniLine *arg0) {
    s32 var_r31_3702;

    var_r31_3702 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (LoadStartAndEnd(arg0) != 0) || (arg0->LoadString("plankModel", (const char **) &this->unk198, 1) != 0) || (arg0->LoadFloat("plankSpacing", &this->unk18C, 0) != 0) || (arg0->LoadFloat("sagAmount", &this->unk194, 0) != 0)) {
        var_r31_3702 = 1;
    }
    return var_r31_3702;
}
