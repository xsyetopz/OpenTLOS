s32 ShatterWaypointSpawn::LoadWaypoints(MKIniLine *arg0, const char *arg1) {
    MKIniLine *var_r28_229;
    s32 temp_r0_199;
    s32 temp_r29_205;
    s32 var_r30_231;
    void *var_r3_213;

    if (arg0->IsField(arg1) != 0) {
        this->unk1FC = arg0->GetNmbrOfSubLines();
        temp_r0_199 = this->unk1FC;
        if (temp_r0_199 == 0) {
            return 1;
        }
        temp_r29_205 = temp_r0_199 * 0x10;
        if (MKHeap::Current() != NULL) {
            var_r3_213 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r29_205, NULL, 0);
        } else {
            var_r3_213 = malloc(temp_r29_205);
        }
        this->unk1F8 = var_r3_213;
        memset(this->unk1F8, 0, this->unk1FC * 0x10);
        var_r28_229 = arg0->unkC->GetSubLine(arg0);
        var_r30_231 = 0;
loop_8:
        if (var_r28_229 != NULL) {
            var_r28_229->LoadVector3("waypoint", (MKVector3 *) (((u8 *) this->unk1F8) + var_r30_231), 0);
            var_r28_229 = var_r28_229->unkC->GetNextLine(var_r28_229);
            var_r30_231 += 0x10;
            goto loop_8;
        }
        return 1;
    }
    return 0;
}
