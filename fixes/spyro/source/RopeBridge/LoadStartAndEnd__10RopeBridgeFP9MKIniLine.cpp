extern "C" s32 stricmp(s8 *, const char *);
u8 RopeBridge::LoadStartAndEnd(MKIniLine *arg0) {
    MKIniLine *temp_r3_3651;
    MKIniLine *temp_r3_3667;

    if (stricmp(arg0->GetFieldName(), "waypoints") == 0) {
        temp_r3_3651 = arg0->unkC->GetSubLine(arg0);
        if (stricmp(temp_r3_3651->GetFieldName(), "waypoint") == 0) {
            temp_r3_3651->AsVector3(0, (MKVector3 *) &this->unk150);
        }
        temp_r3_3667 = temp_r3_3651->unkC->GetNextLine(temp_r3_3651);
        if (stricmp(temp_r3_3667->GetFieldName(), "waypoint") == 0) {
            temp_r3_3667->AsVector3(0, (MKVector3 *) &this->unk160);
        }
        return 1U;
    }
    return 0U;
}
