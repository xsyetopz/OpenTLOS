s32 KDClothProperty::LoadLine(MKIniLine *arg0) {
    u8 var_r31_103;

    var_r31_103 = 0;
    if ((this->unk14.LoadLine(arg0) != 0) || (arg0->LoadString("model", (const char **) &this->unk10, 0) != 0)) {
        var_r31_103 = 1;
    }
    return var_r31_103;
}
