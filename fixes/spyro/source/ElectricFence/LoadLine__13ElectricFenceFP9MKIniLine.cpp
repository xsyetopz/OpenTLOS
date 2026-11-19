s32 ElectricFence::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;
    MKIniLine *var_r27_1234;
    s32 temp_r28_1214;
    s32 var_r29_1235;
    s32 result_1274;
    s8 *temp_r5_1248;
    void *var_r3_1222;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("waypoints") != 0) {
        this->unk50 = arg0->GetNmbrOfSubLines();
        temp_r28_1214 = this->unk50 * 0x70;
        if (MKHeap::Current() != NULL) {
            var_r3_1222 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r28_1214, NULL, 0);
        } else {
            var_r3_1222 = malloc(temp_r28_1214);
        }
        this->unk4C = var_r3_1222;
        var_r27_1234 = arg0->unkC->GetSubLine(arg0);
        var_r29_1235 = 0;
        while (var_r27_1234 != NULL) {
            var_r27_1234->LoadVector3("waypoint", &sp8, 0);
            temp_r5_1248 = (s8 *) this->unk4C + var_r29_1235;
            M2C_FIELD(temp_r5_1248, f32 *, 0x30) = sp8.unk0;
            M2C_FIELD(temp_r5_1248, f32 *, 0x34) = sp8.unk4;
            M2C_FIELD(temp_r5_1248, f32 *, 0x38) = sp8.unk8;
            M2C_FIELD(temp_r5_1248, f32 *, 0x3C) = 1.0f;
            M2C_FIELD(temp_r5_1248, s32 *, 0x40) = 0;
            M2C_FIELD(temp_r5_1248, s32 *, 0x54) = 0;
            var_r29_1235 += 0x70;
            var_r27_1234 = var_r27_1234->unkC->GetNextLine(var_r27_1234);
        }
    }
    result_1274 = 0;
    if ((arg0->LoadBool("StartOn", (bool *) &this->unk54, 0) != 0) || (arg0->LoadInt("JellyFishID", (int *) &this->unk110, 0) != 0)) {
        result_1274 = 1;
    }
    return result_1274;
}
