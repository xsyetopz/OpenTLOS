extern "C" s32 stricmp(const char *, const char *);
s32 ShatterableBoat::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;
    MKIniLine *var_r30_2160;
    s32 temp_r3_2147;

    if ((Shatterable::LoadLine(arg0) != 0) || (arg0->LoadFloat("speed", &this->unk230, 0) != 0) || (arg0->LoadFloat("waterheight", &this->unk314, 0) != 0)) {
        return 1;
    }
    if (stricmp((const char *) arg0->GetFieldName(), "waypoints") == 0) {
        if ((u32) this->unk224 != 0U) {
            return 0;
        }
        temp_r3_2147 = arg0->GetNmbrOfSubLines();
        if (temp_r3_2147 == 0) {
            return 0;
        }
        ((KDUniformSpline *) &this->unk218)->Init(temp_r3_2147, 0U);
        var_r30_2160 = arg0->unkC->GetSubLine(arg0);
        while (var_r30_2160 != NULL) {
            var_r30_2160->AsVector3(0, &sp8);
            ((KDUniformSpline *) &this->unk218)->AddNode(sp8);
            var_r30_2160 = var_r30_2160->unkC->GetNextLine(var_r30_2160);
        }
        return 1;
    }
    return 0;
}
