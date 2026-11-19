void MKInputReceiver_Destroy(MKInputReceiver *arg0) {
    MKInputReceiver **var_r4_517;
    MKInputReceiver **temp_r3_522;
    MKInputReceiver *temp_r0_533;
    MKInputReceiver *temp_r5_525;

    void UnlinkReceiver(MKInputReceiver *);
    UnlinkReceiver(arg0);
    var_r4_517 = receivers;
    while ((temp_r0_533 = *var_r4_517) != NULL) {
        if (temp_r0_533 == arg0) {
            temp_r3_522 = receivers;
            receivers = temp_r3_522 + 1;
            temp_r5_525 = *temp_r3_522;
            *temp_r3_522 = *var_r4_517;
            *var_r4_517 = temp_r5_525;
            return;
        }
        var_r4_517 += 1;
    }
}
