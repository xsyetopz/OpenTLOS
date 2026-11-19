s32 TrapSpawnPoolDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_669;

    var_r31_669 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadBool("bRoll", (bool *) &this->unk64, 0) != 0) || (arg0->LoadString("propName", (const char **) &this->unk60, 0) != 0)) {
        var_r31_669 = 1;
    }
    return var_r31_669;
}
