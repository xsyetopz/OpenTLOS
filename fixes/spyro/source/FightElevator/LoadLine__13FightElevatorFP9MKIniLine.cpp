extern "C" s32 stricmp(s8 *, const char *);

s32 FightElevator::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;
    MKIniLine *line;
    s32 count;

    if ((Platform::LoadLine(arg0) != 0) || (arg0->LoadFloat("MoveSpeed", &this->unk1A8, 0) != 0) || (arg0->LoadBool("ResetOnHeroDeath", (bool *) &this->unk1B0, 0) != 0) || (this->unk2B4.LoadLine(arg0, "OnFirstAttach") != 0)) {
        return 1;
    }
    if (stricmp(arg0->GetFieldName(), "waypoints") == 0) {
        if ((u32) this->unk18C != 0U) {
            return 0;
        }
        count = arg0->GetNmbrOfSubLines();
        if (count == 0) {
            return 0;
        }
        ((KDUniformSpline *) &this->unk180)->Init(count, 0U);
        line = arg0->unkC->GetSubLine(arg0);
loop_12:
        if (line != NULL) {
            line->AsVector3(0, &sp8);
            ((KDUniformSpline *) &this->unk180)->AddNode(sp8);
            line = line->unkC->GetNextLine(line);
            goto loop_12;
        }
        return 1;
    }
    return 0;
}
