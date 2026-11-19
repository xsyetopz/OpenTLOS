MKInputReceiver *MKInputReceiver_Create(bool (*arg0)(MKInputEvent *, void *), int arg1, int arg2, void *arg3) {
    typedef bool (*MKInputCallback)(MKInputEvent *, void *);
    void LinkReceiver(MKInputReceiver *);
    MKInputReceiver **temp_r7_552;
    MKInputReceiver *temp_r31_554;
    s32 var_r5_0;

    var_r5_0 = arg2;
    temp_r7_552 = receivers - 1;
    receivers = temp_r7_552;
    temp_r31_554 = *temp_r7_552;
    if (temp_r31_554 == NULL) {
        return NULL;
    }
    if ((var_r5_0 < 0) || (var_r5_0 > 6)) {
        var_r5_0 = 3;
    }
    M2C_FIELD(temp_r31_554, MKInputCallback *, 0x0) = arg0;
    temp_r31_554->unk4 = (u32) arg1;
    temp_r31_554->unk8 = var_r5_0;
    temp_r31_554->unkC = arg3;
    temp_r31_554->unk10 = NULL;
    temp_r31_554->unk14 = NULL;
    if (var_r5_0 != 0) {
        LinkReceiver(temp_r31_554);
    }
    return temp_r31_554;
}
