s32 TrainControllerDescriptor::LoadLine(MKIniLine *arg0) {
    s8 *name;
    MKIniLine *var_r22;
    f32 *var_r23;
    f32 *var_r24;
    f32 *var_r25;
    s32 var_r26;
    MKIniLine *var_r28;
    u8 var_r29;
    s32 var_r30;

    var_r28 = arg0;
    if (MKPropDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (var_r28->IsField("Stage_01") == 0) {
        return 0;
    }
    var_r30 = 0;
    var_r26 = 0;
    var_r29 = 0;
    while (var_r29 == 0) {
        var_r22 = var_r28->unkC->GetSubLine(var_r28);
        var_r25 = (f32 *) ((u8 *) this + var_r26 + 0x60);
        var_r24 = (f32 *) ((u8 *) this + var_r26 + 0x64);
        var_r23 = (f32 *) ((u8 *) this + var_r26 + 0x68);
        while (var_r22 != NULL) {
            name = var_r22->GetFieldName();
            if (stricmp(name, (s8 *) "SpyroMaxSpeed") == 0) {
                var_r22->AsFloat(0, var_r25);
                *var_r25 = *var_r25 * 100.0f;
            } else if (stricmp(name, (s8 *) "TrainMaxSpeed") == 0) {
                var_r22->AsFloat(0, var_r24);
                *var_r24 = *var_r24 * 100.0f;
            } else if (stricmp(name, (s8 *) "DestroyCaboose") == 0) {
                var_r22->AsFloat(0, var_r23);
            }
            var_r22 = var_r22->unkC->GetNextLine(var_r22);
        }
        var_r30 += 1;
        var_r26 += 0xC;
        var_r28 = var_r28->unkC->GetNextLine(var_r28);
        if (var_r28->IsField((const char *) Str_Printf("Stage_%02d", var_r30 + 1)) == 0) {
            var_r29 = 1;
        }
    }
    return 1;
}
