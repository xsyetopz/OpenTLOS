s32 DragonBustDoor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_215;

    var_r31_215 = 0;
    if ((Trap::LoadLine(arg0) != 0) || (arg0->LoadInt("YellowSwitchID", (int *) &this->unkE8, 0) != 0) || (arg0->LoadInt("RedSwitchID", (int *) &this->unkF0, 0) != 0) || (arg0->LoadInt("GreenSwitchID", (int *) &this->unkF8, 0) != 0) || (arg0->LoadInt("BlueSwitchID", (int *) &this->unk100, 0) != 0)) {
        var_r31_215 = 1;
    }
    return var_r31_215;
}
