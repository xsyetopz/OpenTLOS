s32 TriggerBoxProp::LoadLine(MKIniLine *arg0) {
    s32 result;

    result = 0;
    if ((TriggerProp::LoadLine(arg0) != 0) || (((TriggerBoxObject *) ((u8 *) this + 0xD0))->LoadLine("box", arg0) != 0)) {
        result = 1;
    }
    return result;
}
