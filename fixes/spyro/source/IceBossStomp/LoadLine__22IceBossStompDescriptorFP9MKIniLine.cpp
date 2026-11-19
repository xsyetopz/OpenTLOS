s32 IceBossStompDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2685;

    var_r31_2685 = 0;
    if ((ProjectileDescriptor::LoadLine(arg0) != 0) || (arg0->LoadString("CrystalName", (const char **) &this->unkF8, 0) != 0) || (DataMap_LoadLine(arg0, "Element", &ElementTypeDataMap, (unsigned int *) &this->unkFC) != 0)) {
        var_r31_2685 = 1;
    }
    return var_r31_2685;
}
