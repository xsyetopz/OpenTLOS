s32 TogglePropDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_217;

    var_r31_217 = 0;
    if (((u8) KDPropDescriptor::LoadLine(arg0) != 0) || ((u8) arg0->LoadString("SubobjectOn", (const char **) &this->unk70, 0) != 0) || ((u8) arg0->LoadString("SubobjectOff", (const char **) &this->unk74, 0) != 0) || ((u8) arg0->LoadBool("bStartOn", (bool *) ((s8 *) this + 0x80), 0) != 0) || ((u8) arg0->LoadBool("bToggle", (bool *) ((s8 *) this + 0x81), 0) != 0)) {
        var_r31_217 = 1;
    }
    return var_r31_217;
}
