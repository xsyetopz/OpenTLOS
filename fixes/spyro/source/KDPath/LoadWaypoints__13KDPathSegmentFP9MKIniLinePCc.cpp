u8 KDPathSegment::LoadWaypoints(MKIniLine *arg0, const char *arg1) {
    MKIniLine *var_r29_1815;
    s32 temp_r30_1795;
    s32 temp_r3_1788;
    s32 var_r28_1814;
    void *var_r3_1803;

    if (arg0->IsField(arg1) != 0) {
        this->unk20 = arg0->GetNmbrOfSubLines();
        temp_r3_1788 = this->unk20;
        if (temp_r3_1788 == 0) {
            return 1U;
        }
        temp_r30_1795 = temp_r3_1788 * this->unk1C;
        if (MKHeap::Current() != NULL) {
            var_r3_1803 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1795, NULL, 0);
        } else {
            var_r3_1803 = malloc(temp_r30_1795);
        }
        this->unk24 = var_r3_1803;
        var_r28_1814 = 0;
        var_r29_1815 = arg0->unkC->GetSubLine(arg0);
loop_10:
        if (var_r29_1815 != NULL) {
            if (var_r29_1815->LoadVector3("waypoint", (MKVector3 *) (((u8 *) this->unk24) + (var_r28_1814 * this->unk1C)), 0) != 0) {
                var_r28_1814 += 1;
            }
            var_r29_1815 = var_r29_1815->unkC->GetNextLine(var_r29_1815);
            goto loop_10;
        }
        return 1U;
    }
    if (arg0->LoadVector3("waypoint", &waypointLoadInfo[this->unk20], 0) != 0) {
        this->unk20 += 1;
        return 1U;
    }
    return 0U;
}
