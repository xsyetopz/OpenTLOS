s32 ScriptedCounterProp::LoadLine(MKIniLine *arg0) {
    s32 var_r29_105;
    s32 var_r31_107;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    var_r29_105 = 0;
    var_r31_107 = 0;
loop_3:
    if (((EventMessage *) ((u8 *) this + (var_r31_107 + 0x4C)))->LoadLine(arg0, (const char *) Str_Printf("OnEventCount%d", var_r29_105 + 1)) != 0) {
        return 1;
    }
    var_r29_105 += 1;
    var_r31_107 += 4;
    if (var_r29_105 >= 0x14) {
        return 0;
    }
    goto loop_3;
}
