s32 TriggerSphereProp::LoadLine(MKIniLine *arg0) {
    s32 result;

    result = 0;
    if ((TriggerProp::LoadLine(arg0) != 0) || (((TriggerSphereObject *) ((u8 *) this + 0xD0))->LoadLine("sphere", arg0) != 0)) {
        result = 1;
    }
    return result;
}
