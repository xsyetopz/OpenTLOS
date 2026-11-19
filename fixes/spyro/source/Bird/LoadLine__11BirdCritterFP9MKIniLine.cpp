extern "C" void *malloc(u32);
s32 BirdCritter::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r30_1689;
    MKVector3 *temp_r5_1690;
    s32 temp_r31_1670;
    s32 var_r31_1688;
    void *var_r3_1678;

    if ((u8) Critters::LoadLine(arg0) != 0) {
        return 1;
    }
    if ((u8) arg0->IsField("Waypoints") != 0) {
        this->unk178 = arg0->GetNmbrOfSubLines();
        temp_r31_1670 = this->unk178 * 0x10;
        if (MKHeap::Current() != NULL) {
            var_r3_1678 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r31_1670, NULL, 0);
        } else {
            var_r3_1678 = malloc(temp_r31_1670);
        }
        this->unk174 = var_r3_1678;
        var_r30_1689 = arg0->unkC->GetSubLine(arg0);
        var_r31_1688 = 0;
        while (var_r30_1689 != NULL) {
            temp_r5_1690 = (MKVector3 *) (((u8 *) this->unk174) + var_r31_1688);
            var_r30_1689->AsVector3(0, temp_r5_1690);
            var_r31_1688 += 0x10;
            var_r30_1689 = var_r30_1689->unkC->GetNextLine(var_r30_1689);
        }
        return 1;
    }
    return 0;
}
