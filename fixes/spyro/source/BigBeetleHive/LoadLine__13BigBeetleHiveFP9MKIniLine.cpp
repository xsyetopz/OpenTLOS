s32 BigBeetleHive::LoadLine(MKIniLine *arg0) {
    s32 temp_ret_654;
    s32 temp_ret_674;
    s32 var_r29_661;
    s32 var_r31_663;

    temp_ret_654 = Shatterable::LoadLine(arg0);
    if ((u8) temp_ret_654 != 0) {
        return 1;
    }
    var_r29_661 = 0;
    var_r31_663 = 0;
    do {
        temp_ret_674 = arg0->LoadInt((const char *) Str_Printf("NestID%d", var_r29_661), (int *) ((u8 *) this + (var_r31_663 + 0x1B0)), 0);
        if ((u8) temp_ret_674 != 0) {
            return 1;
        }
        var_r29_661 += 1;
        var_r31_663 += 0xC;
    } while (var_r29_661 < 5);
    return 0;
}
