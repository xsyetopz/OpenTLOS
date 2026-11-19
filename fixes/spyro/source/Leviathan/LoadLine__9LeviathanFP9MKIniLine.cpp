extern "C" s32 stricmp(s8 *, s8 *);

s32 Leviathan::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;
    MKIniLine *var_r30;
    s32 temp_r3;

    if (((u8) Platform::LoadLine(arg0) != 0) || ((u8) arg0->LoadFloat("speed", &this->unk198, 0) != 0) || ((u8) arg0->LoadFloat("waterheight", &this->unk1BC, 0) != 0)) {
        return 1;
    }
    if (stricmp(arg0->GetFieldName(), (s8 *) "waypoints") == 0) {
        if ((u32) this->unk18C != 0U) {
            return 0;
        }
        temp_r3 = arg0->GetNmbrOfSubLines();
        if (temp_r3 == 0) {
            return 0;
        }
        ((KDUniformSpline *) &this->unk180)->Init(temp_r3, 0U);
        var_r30 = arg0->unkC->GetSubLine(arg0);
        while (var_r30 != NULL) {
            var_r30->AsVector3(0, &sp8);
            ((KDUniformSpline *) &this->unk180)->AddNode(sp8);
            var_r30 = var_r30->unkC->GetNextLine(var_r30);
        }
        return 1;
    }
    return 0;
}
