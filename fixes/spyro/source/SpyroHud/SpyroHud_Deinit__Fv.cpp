void SpyroHud_Deinit() {
    s32 var_r29_234;
    s32 var_r31_236;

    var_r29_234 = 1;
    var_r31_236 = 0x20;
    do {
        Hud_Remove((HudItem *) ((s8 *) &hudItem + var_r31_236));
        var_r29_234 -= 1;
        var_r31_236 -= 0x20;
    } while (var_r29_234 >= 0);
}
