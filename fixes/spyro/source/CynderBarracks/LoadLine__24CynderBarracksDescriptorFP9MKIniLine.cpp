s32 CynderBarracksDescriptor::LoadLine(MKIniLine *arg0) {
    EnemyGeneratorDescriptor *temp_r3;
    s32 var_r31_301;

    var_r31_301 = 0;
    temp_r3 = (EnemyGeneratorDescriptor *) ((s8 *) this + 0x16C);
    if (((u8) ShatterableDescriptor::LoadLine(arg0) != 0) || ((u8) temp_r3->LoadLine(arg0) != 0)) {
        var_r31_301 = 1;
    }
    return var_r31_301;
}
