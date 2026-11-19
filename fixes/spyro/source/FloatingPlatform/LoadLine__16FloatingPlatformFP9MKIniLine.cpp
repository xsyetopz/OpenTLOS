s32 FloatingPlatform::LoadLine(MKIniLine *arg0) {
    s32 stricmp(s8 *, const char *);
    MKVector3 sp8;
    MKIniLine *var_r30_463;
    s32 temp_r3_450;
    s32 var_r30_488;

    if (Platform::LoadLine(arg0) != 0) {
        return 1;
    }
    if (stricmp(arg0->GetFieldName(), "waypoints") == 0) {
        if ((u32) this->unk1A4 != 0U) {
            return 0;
        }
        temp_r3_450 = arg0->GetNmbrOfSubLines();
        if (temp_r3_450 == 0) {
            return 0;
        }
        ((KDUniformSpline *) &this->unk198)->Init(temp_r3_450, 0U);
        var_r30_463 = arg0->unkC->GetSubLine(arg0);
loop_9:
        if (var_r30_463 != NULL) {
            var_r30_463->AsVector3(0, &sp8);
            ((KDUniformSpline *) &this->unk198)->AddNode(sp8);
            var_r30_463 = var_r30_463->unkC->GetNextLine(var_r30_463);
            goto loop_9;
        }
        return 1;
    }
    var_r30_488 = 0;
    if ((arg0->LoadFloat("Floor", &this->unk188, 0) != 0) || (arg0->LoadFloat("Ceiling", &this->unk18C, 0) != 0) || (arg0->LoadBool("StartAtPathEnd", (bool *) &this->unk194, 0) != 0)) {
        var_r30_488 = 1;
    }
    return var_r30_488;
}
