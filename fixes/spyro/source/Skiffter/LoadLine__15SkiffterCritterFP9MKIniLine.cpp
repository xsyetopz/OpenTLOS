s32 SkiffterCritter::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r28_1883;
    s32 temp_r29_1863;
    s32 var_r30_1879;
    void *var_r3_1871;

    if (Critters::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("Waypoints") != 0) {
        this->unk178 = arg0->GetNmbrOfSubLines();
        temp_r29_1863 = this->unk178 * 0x10;
        if (MKHeap::Current() != NULL) {
            var_r3_1871 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r29_1863, NULL, 0);
        } else {
            var_r3_1871 = malloc(temp_r29_1863);
        }
        this->unk174 = var_r3_1871;
        var_r30_1879 = 0;
        var_r28_1883 = arg0->unkC->GetSubLine(arg0);
loop_8:
        if (var_r28_1883 != NULL) {
            var_r28_1883->LoadVector3("waypoint", (MKVector3 *) (((u8 *) this->unk174) + var_r30_1879), 0);
            var_r30_1879 += 0x10;
            var_r28_1883 = var_r28_1883->unkC->GetNextLine(var_r28_1883);
            goto loop_8;
        }
        return 1;
    }
    return 0;
}
