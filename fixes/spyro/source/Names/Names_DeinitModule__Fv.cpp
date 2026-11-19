static Names firstNames[6];
static Names lastNames[6];

void Names_DeinitModule() {
    s32 var_r28_228;
    s32 var_r31_230;

    var_r28_228 = 5;
    var_r31_230 = 0x28;
    do {
        ((Names *) ((s8 *) lastNames + var_r31_230))->Deinit();
        ((Names *) ((s8 *) firstNames + var_r31_230))->Deinit();
        var_r28_228 -= 1;
        var_r31_230 -= 8;
    } while (var_r28_228 >= 0);
}
