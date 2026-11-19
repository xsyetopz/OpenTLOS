s32 Button::LoadLine(MKIniLine *arg0) {
    bool sp8;
    s32 var_r31_261;

    if (arg0->LoadBool("Charge", &sp8, 0) != 0) {
        this->unkEC = (this->unkEC & ~0x40) | ((sp8 << 6) & 0x40);
    }
    var_r31_261 = 0;
    if ((Trap::LoadLine(arg0) != 0) || (this->unkE4.LoadLine(arg0, "OnPressed") != 0) || (this->unkE8.LoadLine(arg0, "OnReleased") != 0)) {
        var_r31_261 = 1;
    }
    return var_r31_261;
}
