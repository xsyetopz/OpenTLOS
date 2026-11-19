s32 GondolaDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1711;

    var_r31_1711 = 0;
    if ((PlatformDescriptor::LoadLine(arg0) != 0) || (((EnemyGeneratorDescriptor *) ((u8 *) this + 0x124))->LoadLine(arg0) != 0)) {
        var_r31_1711 = 1;
    }
    return var_r31_1711;
}
