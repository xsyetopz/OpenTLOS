s32 CynderPortcullisDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_247;

    var_r31_247 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (M2C_FIELD(this, EnemyGeneratorDescriptor *, 0xE4).LoadLine(arg0) != 0)) {
        var_r31_247 = 1;
    }
    return var_r31_247;
}
