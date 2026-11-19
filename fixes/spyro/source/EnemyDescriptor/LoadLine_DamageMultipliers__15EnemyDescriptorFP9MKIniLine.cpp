s32 EnemyDescriptor::LoadLine_DamageMultipliers(MKIniLine *arg0) {
    MKHeap *var_r3_747;
    MKIniLine *var_r26_789;
    MKIniLine *var_r30_780;
    s32 temp_r0_736;
    s32 temp_r27_739;
    s32 var_r4_753;
    s32 var_r8_758;
    s32 var_r28_777;

    this->unk2B0 = arg0->GetNmbrOfSubLines();
    temp_r0_736 = this->unk2B0;
    if (temp_r0_736 > 0) {
        temp_r27_739 = temp_r0_736 * 0xC;
        if (MKHeap::Current() != NULL) {
            var_r3_747 = (MKHeap *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r27_739, NULL, 0));
        } else {
            var_r3_747 = (MKHeap *) (malloc(temp_r27_739));
        }
        this->unk2AC = var_r3_747;
        var_r4_753 = 0;
        var_r8_758 = 0;
        while (var_r8_758 < this->unk2B0) {
            var_r8_758 += 1;
            *(s32 *) ((u8 *) this->unk2AC + var_r4_753) = 0;
            *(s32 *) ((u8 *) this->unk2AC + var_r4_753 + 4) = 0;
            *(f32 *) ((u8 *) this->unk2AC + var_r4_753 + 8) = 1.0f;
            var_r4_753 += 0xC;
        }
        var_r28_777 = 0;
        var_r30_780 = arg0->unkC->GetSubLine(arg0);
        while (var_r30_780 != NULL) {
            var_r26_789 = var_r30_780->unkC->GetSubLine(var_r30_780);
            *(s32 *) ((u8 *) this->unk2AC + var_r28_777) = DataMap_GetValue(&enemyDamageTypesDataMap, (const char *) var_r30_780->GetFieldName());
            if (*(u32 *) ((u8 *) this->unk2AC + var_r28_777) != 0U) {
                while (var_r26_789 != NULL) {
                    if (var_r26_789->LoadInt("iAttackLevel", (int *) ((u8 *) this->unk2AC + (var_r28_777 + 4)), 0) == 0) {
                        var_r26_789->LoadFloat("value", (float *) ((u8 *) this->unk2AC + (var_r28_777 + 8)), 0);
                    }
                    var_r26_789 = var_r26_789->unkC->GetNextLine(var_r26_789);
                }
            }
            var_r30_780 = var_r30_780->unkC->GetNextLine(var_r30_780);
            var_r28_777 += 0xC;
        }
    }
    return 1;
}
