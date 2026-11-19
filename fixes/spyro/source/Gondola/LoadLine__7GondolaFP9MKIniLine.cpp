extern "C" s32 stricmp(s8 *, s8 *);

s32 Gondola::LoadLine(MKIniLine *arg0) {
    MKVector3 sp18;
    MKVector3 sp8;
    MKIniLine *var_r30_1539;
    MKIniLine *var_r30_1587;
    s32 temp_r3_1526;
    s32 temp_r3_1574;

    if ((Platform::LoadLine(arg0) != 0) || (this->unk1B0.LoadLine(arg0) != 0)) {
        return 1;
    }
    if (stricmp(arg0->GetFieldName(), (s8 *) "waypoints") == 0) {
        if ((u32) this->unk18C != 0U) {
            return 0;
        }
        temp_r3_1526 = arg0->GetNmbrOfSubLines();
        if (temp_r3_1526 == 0) {
            return 0;
        }
        ((KDUniformSpline *) &this->unk180)->Init(temp_r3_1526, 0U);
        var_r30_1539 = arg0->unkC->GetSubLine(arg0);
loop_10:
        if (var_r30_1539 != NULL) {
            var_r30_1539->AsVector3(0, &sp18);
            ((KDUniformSpline *) &this->unk180)->AddNode(sp18);
            var_r30_1539 = var_r30_1539->unkC->GetNextLine(var_r30_1539);
            goto loop_10;
        }
        return 1;
    }
    if (stricmp(arg0->GetFieldName(), (s8 *) "returnwaypoints") == 0) {
        if ((u32) this->unk1A0 != 0U) {
            return 0;
        }
        temp_r3_1574 = arg0->GetNmbrOfSubLines();
        if (temp_r3_1574 == 0) {
            return 0;
        }
        ((KDUniformSpline *) &this->unk194)->Init(temp_r3_1574, 0U);
        var_r30_1587 = arg0->unkC->GetSubLine(arg0);
loop_19:
        if (var_r30_1587 != NULL) {
            var_r30_1587->AsVector3(0, &sp8);
            ((KDUniformSpline *) &this->unk194)->AddNode(sp8);
            var_r30_1587 = var_r30_1587->unkC->GetNextLine(var_r30_1587);
            goto loop_19;
        }
        return 1;
    }
    return 0;
}
