void MKInput_SendEvent(MKInputEvent *arg0) {
    typedef bool (*MKInputCallback)(MKInputEvent *, void *);
    u8 var_r3_427;
    MKInputReceiver *var_r5_423;
    MKInputReceiver *temp_r4_428;
    MKInputReceiver *var_r31_430;
    s32 temp_r0_442;
    u8 var_r3_443;

    var_r5_423 = pReceiverChain;
    while (var_r5_423 != NULL) {
        var_r3_427 = 0;
        temp_r4_428 = var_r5_423->unk14;
        var_r31_430 = temp_r4_428;
        if ((var_r5_423->unk10 != NULL) || (temp_r4_428 != NULL) || (pReceiverChain == var_r5_423)) {
            var_r3_427 = 1;
        }
        if (var_r3_427 != 0) {
            temp_r0_442 = arg0->unk0;
            var_r3_443 = 0;
            switch (temp_r0_442) {
            case 0:
                var_r3_443 = 1;
                break;
            case 1:
                var_r3_443 = (var_r5_423->unk4 & (4 << arg0->unk4)) != 0;
                break;
            case 2:
                var_r3_443 = (var_r5_423->unk4 & (4 << arg0->unk4)) != 0;
                break;
            case 6:
                var_r3_443 = var_r5_423->unk4 & 1;
                break;
            default:
                var_r3_443 = 0;
                if ((temp_r0_442 >= 3) && (temp_r0_442 <= 5)) {
                    var_r3_443 = ((u32) var_r5_423->unk4 >> 1U) & 1;
                }
                break;
            }
            if ((var_r3_443 != 0) && !M2C_FIELD(var_r5_423, MKInputCallback *, 0x0)(arg0, var_r5_423->unkC)) {
                var_r31_430 = NULL;
            }
        }
        var_r5_423 = var_r31_430;
    }
}
